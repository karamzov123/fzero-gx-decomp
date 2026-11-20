import concurrent.futures, json, pathlib, re, subprocess, struct, sys, tempfile
import importlib.util

spec_pa = importlib.util.spec_from_file_location('pa', str(pathlib.Path(__file__).with_name('apply_pooled_all.py')))
pa = importlib.util.module_from_spec(spec_pa); spec_pa.loader.exec_module(pa)
spec_sm = importlib.util.spec_from_file_location('sm', str(pathlib.Path(__file__).with_name('apply_smart_dol_mm.py')))
sm = importlib.util.module_from_spec(spec_sm); spec_sm.loader.exec_module(sm)

VERSIONS = ['GFZE01', 'GFZJ01', 'GFZP01']
LOCAL_POOL_RE = re.compile(r'^(?:@\d+|\.\.\.(?:rodata|data|bss|sdata|sdata2|sbss)\.0)$')

def fmt_target(sym, addend):
    if addend == 0: return sym
    if addend > 0: return f'{sym}+0x{addend:X}'
    return None

def test_merge_file_rd(mod, u_list, sym_lists, mv, cflags, sdata):
    # Skip if >1 file has .fzgxpool
    if sum(1 for u in u_list if '.fzgxpool' in pathlib.Path('src/' + u).read_text()) > 1:
        return None
    code = sm.merge_c_files_smart(u_list)
    comp = f'build/compilers/{mv}/mwcceppc.exe'
    src_obj_root = 'build/GFZE01/src'
    all_tu_fns = set(fn for fns in sym_lists for fn in fns)
    with tempfile.TemporaryDirectory(prefix='fzgx_rddm_') as td:
        cp, op = pathlib.Path(td)/'u.c', pathlib.Path(td)/'u.o'
        cp.write_text(code)
        cmd = [
            'build/tools/wibo', comp,
            '-c', '-nodefaults', '-proc', 'gekko', '-align', 'powerpc', '-enum', 'int', '-fp', 'hardware',
            '-Cpp_exceptions', 'off', '-O4,p', '-inline', 'auto', '-pragma', 'cats off', '-pragma', 'warn_notinlined off',
            '-nosyspath', '-RTTI', 'off', '-fp_contract', 'on', '-str', 'reuse', '-multibyte',
            '-i', 'include', '-i', 'build/GFZE01/include', '-DBUILD_VERSION=0', '-DVERSION_GFZE01', '-DNDEBUG=1',
            '-sdata', str(sdata), '-sdata2', str(sdata), '-lang=c',
        ] + list(cflags) + ['-o', str(op), str(cp)]
        r = subprocess.run(cmd, capture_output=True, text=True)
        if r.returncode != 0: return None
        secs, syms = pa.m.parse_elf(op)
        raw_relas = pa.parse_relas(op)
        # Verify exact total .text size matches sum of original .text sizes!
        orig_text_tot = 0
        pmap = {}
        orig_cache = {}
        for u, fns in zip(u_list, sym_lists):
            orig_p = pathlib.Path(f'{src_obj_root}/{u[:-2]}.o')
            if not orig_p.exists(): return None
            osecs, osyms = pa.m.parse_elf(orig_p)
            orig_text_tot += osecs.get('.text', (0,))[0]
            orelas = pa.parse_relas(orig_p)
            orig_cache[u] = (osecs, osyms, orelas)
            for fn in fns:
                if fn not in syms or fn not in osyms: return None
                o_off, o_sz = osyms[fn]; n_off, n_sz = syms[fn]
                ob, nb = osecs['.text'][1][o_off:o_off+o_sz], secs['.text'][1][n_off:n_off+n_sz]
                if len(ob) != len(nb): return None
                for i in range(0, len(ob), 4):
                    if ob[i:i+4] != nb[i:i+4]:
                        ow, nw = struct.unpack('>I', ob[i:i+4])[0], struct.unpack('>I', nb[i:i+4])[0]
                        if (ow >> 26) == 18 and (nw >> 26) == 18 and (ow & 3) == (nw & 3): continue
                        return None
                omap = {(off, rt): (sn, ra) for off, rt, sn, ra in orelas.get(fn, [])}
                for off, rt, sn, ra in raw_relas.get(fn, []):
                    if rt == 10 and sn in all_tu_fns: continue
                    if LOCAL_POOL_RE.match(sn):
                        if (off, rt) not in omap: return None
                        osn, ora = omap[(off, rt)]
                        tgt = fmt_target(osn, ora - ra)
                        if tgt is None: return None
                        if sn in pmap and pmap[sn] != tgt: return None
                        pmap[sn] = tgt
                    else:
                        if omap.get((off, rt)) != (sn, ra): return None
        if secs.get('.text', (0,))[0] != orig_text_tot or not pmap:
            return None
        # Add unreferenced @N symbols in pool sections so poolfix can empty them
        sec_base = next((v.split('+')[0] for k, v in pmap.items() if k.startswith('...')), None) or next(iter(pmap.values())).split('+')[0]
        data = op.read_bytes()
        shoff = struct.unpack('>I', data[32:36])[0]
        shentsize, shnum, shstrndx = struct.unpack('>HHH', data[46:52])
        s_hdrs = [struct.unpack('>IIIIIIIIII', data[shoff+i*shentsize:shoff+(i+1)*shentsize]) for i in range(shnum)]
        shstr = data[s_hdrs[shstrndx][4]:s_hdrs[shstrndx][4]+s_hdrs[shstrndx][5]]
        sname = lambda idx: shstr[idx:shstr.index(0, idx)].decode()
        pool_sec_idxs = {i for i, s in enumerate(s_hdrs) if sname(s[0]) in ('.rodata', '.data', '.bss', '.sdata', '.sdata2', '.sbss')}
        for s in s_hdrs:
            if s[1] == 2:
                strtab = data[s_hdrs[s[6]][4]:s_hdrs[s[6]][4]+s_hdrs[s[6]][5]]
                for j in range(0, s[5], 16):
                    st_name, st_val, st_size, st_info, _, st_shndx = struct.unpack('>IIIBBH', data[s[4]+j:s[4]+j+16])
                    if st_shndx in pool_sec_idxs:
                        nm = strtab[st_name:strtab.index(0, st_name)].decode()
                        if nm.startswith('@') and nm not in pmap:
                            pmap[nm] = f'{sec_base}+0x{st_val:X}' if st_val else sec_base
        pf_args = ['python3', 'tools/fzgx/poolfix.py', str(op), ','.join(f'{k}={v}' for k, v in sorted(pmap.items()))]
        pr = subprocess.run(pf_args, capture_output=True, text=True)
        if pr.returncode != 0: return None
        final_relas = pa.parse_relas(op)
        for u, fns in zip(u_list, sym_lists):
            _, _, orelas = orig_cache[u]
            for fn in fns:
                or_f = [x for x in orelas.get(fn, []) if not (x[1] == 10 and x[2] in all_tu_fns)]
                nr_f = [x for x in final_relas.get(fn, []) if not (x[1] == 10 and x[2] in all_tu_fns)]
                if or_f != nr_f: return None
        return (pmap, code)

def process_mod_rd(task):
    mod, lst, units, def_mv, sdata = task
    out = []
    n = len(lst)
    i = 0
    while i < n:
        sa, ea, u, extra = lst[i]
        info = units.get(u)
        if not info or extra or not pathlib.Path('src/' + u).exists():
            i += 1; continue
        run = [(sa, ea, u, (info.get('mw_version') or def_mv, tuple(info.get('extra_cflags') or [])))]
        prev_ea = ea
        for j in range(i + 1, min(i + 10, n)):
            sa2, ea2, u2, extra2 = lst[j]
            if sa2 != prev_ea or extra2 or not pathlib.Path('src/' + u2).exists(): break
            inf2 = units.get(u2)
            if not inf2: break
            run.append((sa2, ea2, u2, (inf2.get('mw_version') or def_mv, tuple(inf2.get('extra_cflags') or []))))
            prev_ea = ea2
        if len(run) < 2 or not any(units[x[2]].get('pool') for x in run):
            i += 1; continue
        cands = []
        for x in run[:3]:
            if x[3] not in cands: cands.append(x[3])
        best_k, best_res, best_prof = 1, None, None
        for mv, cf in cands:
            k_ok, res_ok = 1, None
            for k in range(2, len(run) + 1):
                ul = [x[2] for x in run[:k]]
                if not any(units[x].get('pool') for x in ul): continue
                sl = [units[x]['symbols'] for x in ul]
                res = test_merge_file_rd(mod, ul, sl, mv, cf, sdata)
                if res is not None:
                    k_ok, res_ok = k, res
                else:
                    if k_ok >= 2: break
                    if any(units[x].get('pool') for x in ul): break
            if k_ok > best_k:
                best_k, best_res, best_prof = k_ok, res_ok, (mv, cf)
        if best_k >= 2:
            ul = [x[2] for x in run[:best_k]]
            pcnt = sum(1 for x in ul if units[x].get('pool'))
            out.append((mod, ul, run[0][0], run[best_k-1][1], best_res[0], best_res[1], pcnt, best_prof[0], best_prof[1]))
            i += best_k
        else:
            i += 1
    return out

def main():
    dry = '--dry-run' in sys.argv
    units_path = pathlib.Path('config/GFZE01/units.json')
    units_list = json.loads(units_path.read_text())
    units = {u['source']: u for u in units_list}
    tasks = []
    splits_map = {}
    for mod, sp_str, prefix, def_mv, sdata in [
        ('main', 'config/GFZE01/splits.txt', 'dol/', 'GC/1.3.2', 8),
        ('movie_module', 'config/GFZE01/movie_module/splits.txt', 'rel/movie_module/', 'GC/1.3.2', 0),
    ]:
        sp = pathlib.Path(sp_str)
        splits = sp.read_text()
        splits_map[mod] = (sp, splits)
        entries = []
        for mm in re.finditer(rf'({re.escape(prefix)}[^/\s]+\.c):\n((?:\t.*\n)*)', splits):
            u = mm.group(1)
            lines = [l.strip() for l in mm.group(2).splitlines() if l.strip()]
            tm = re.search(r'\.text\s+start:0x([0-9A-Fa-f]+)\s+end:0x([0-9A-Fa-f]+)', lines[0]) if lines else None
            if tm: entries.append((int(tm.group(1), 16), int(tm.group(2), 16), u, len(lines) > 1))
        entries.sort()
        tasks.append((mod, entries, units, def_mv, sdata))
    all_out = []
    with concurrent.futures.ProcessPoolExecutor(max_workers=2) as ex:
        for res in ex.map(process_mod_rd, tasks):
            all_out.extend(res)
    tot_u = sum(len(r[1]) - 1 for r in all_out)
    tot_p = sum(r[6] - 1 for r in all_out if r[6] >= 2)
    print(f"RELOC-DERIVED DOL+MM VERIFIED {len(all_out)} consolidations: -{tot_u} units & files, -{tot_p} mwcc_pool!")
    for mod, ul, sa, ea, pmap, code, pcnt, mv, cf in sorted(all_out, key=lambda x: (-x[6], -len(x[1])))[:25]:
        print(f"  {mod:12s} {mv:9s}: {len(ul):2d}->1 (pool {pcnt}->1): {ul[0]} .. {ul[-1]}")
    if dry: return

    by_mod, rem_set, head_updates = {}, set(), {}
    for mod, ul, sa, ea, pmap, code, pcnt, mv, cf in all_out:
        head = ul[0]
        pathlib.Path('src/' + head).write_text(code)
        for u in ul[1:]:
            pathlib.Path('src/' + u).unlink()
            rem_set.add(u)
        by_mod.setdefault(mod, ({}, set()))
        by_mod[mod][0][head] = (f'0x{sa:08X}', f'0x{ea:08X}')
        for u in ul[1:]: by_mod[mod][1].add(u)
        inter_mf = set(VERSIONS)
        for u in ul: inter_mf &= set(units[u].get('matching_for', VERSIONS))
        head_updates[head] = ([s for x in ul for s in units[x]['symbols']], pmap, mv, list(cf), [v for v in VERSIONS if v in inter_mf])

    for mod, (head_map, mod_rem) in by_mod.items():
        sp, splits = splits_map[mod]
        out, pos = [], 0
        for mm in re.finditer(r'(\S+):\n((?:\t.*\n)*)', splits):
            unit = mm.group(1)
            if unit in head_map:
                out.append(splits[pos:mm.start()])
                sh, eh = head_map[unit]
                out.append(f'{unit}:\n\t.text       start:{sh} end:{eh} align:4\n')
                pos = mm.end()
            elif unit in mod_rem:
                out.append(splits[pos:mm.start()])
                pos = mm.end()
                if pos < len(splits) and splits[pos] == '\n': pos += 1
        out.append(splits[pos:])
        sp.write_text(''.join(out))

    old_count = len(units_list)
    new_units = []
    for u in units_list:
        s = u['source']
        if s in rem_set: continue
        if s in head_updates:
            syms, pmap, mv, cf, mf = head_updates[s]
            u['symbols'] = syms
            u['collapsed'] = True
            u['pool'] = pmap
            u['mw_version'] = mv
            if cf: u['extra_cflags'] = cf
            else: u.pop('extra_cflags', None)
            if mf != VERSIONS: u['matching_for'] = mf
            else: u.pop('matching_for', None)
        new_units.append(u)
    raw = json.dumps(new_units, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', raw)
    units_path.write_text(raw)
    print(f"Applied reloc-derived DOL+MM: {old_count} -> {len(new_units)} (-{old_count - len(new_units)}), -{tot_p} mwcc_pool!")

if __name__ == '__main__':
    main()
