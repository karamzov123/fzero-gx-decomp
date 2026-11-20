import concurrent.futures, json, pathlib, re, subprocess, struct, sys, tempfile
import importlib.util

spec = importlib.util.spec_from_file_location('m', str(pathlib.Path(__file__).with_name('apply_dol_and_mm.py')))
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)

def parse_relas(path):
    """Return dict: fn_name -> list of (offset_in_fn, r_type, sym_name, r_addend)."""
    data = pathlib.Path(path).read_bytes()
    shoff = struct.unpack('>I', data[32:36])[0]
    shentsize, shnum, shstrndx = struct.unpack('>HHH', data[46:52])
    secs = [struct.unpack('>IIIIIIIIII', data[shoff+i*shentsize:shoff+(i+1)*shentsize]) for i in range(shnum)]
    shstr = data[secs[shstrndx][4]:secs[shstrndx][4]+secs[shstrndx][5]]
    sname = lambda idx: shstr[idx:shstr.index(0, idx)].decode()
    sym_sec = [s for s in secs if s[1] == 2][0]
    strtab = data[secs[sym_sec[6]][4]:secs[sym_sec[6]][4]+secs[sym_sec[6]][5]]
    syms = []
    fn_ranges = []
    text_idx = [i for i, s in enumerate(secs) if sname(s[0]) == '.text'][0]
    for j in range(0, sym_sec[5], 16):
        st_name, st_val, st_size, st_info, _, st_shndx = struct.unpack('>IIIBBH', data[sym_sec[4]+j:sym_sec[4]+j+16])
        nm = strtab[st_name:strtab.index(0, st_name)].decode()
        syms.append((nm, st_val, st_shndx))
        if (st_info & 0xf) == 2 and st_size > 0 and st_shndx == text_idx:
            fn_ranges.append((st_val, st_val + st_size, nm))
    fn_ranges.sort()
    out = {nm: [] for _, _, nm in fn_ranges}
    for s in secs:
        if sname(s[0]) == '.rela.text':
            for j in range(0, s[5], 12):
                r_off, r_info, r_add = struct.unpack('>IIi', data[s[4]+j:s[4]+j+12])
                r_sym, r_type = r_info >> 8, r_info & 0xff
                sym_nm = syms[r_sym][0]
                for lo, hi, fn in fn_ranges:
                    if lo <= r_off < hi:
                        # Skip intra-TU branch relocs (R_PPC_REL24 = 10) if target is inside same TU
                        out[fn].append((r_off - lo, r_type, sym_nm, r_add))
                        break
    return out

def build_pool_map(op, base_sym, sec_name):
    dis = op.with_suffix('.s')
    r = subprocess.run(['build/tools/dtk', 'elf', 'disasm', str(op), str(dis)], capture_output=True, text=True)
    if r.returncode != 0: return None
    dtxt = dis.read_text()
    sec_tag = f'...{sec_name[1:]}.0'
    refs = set(re.findall(r'@\d+', dtxt))
    if sec_tag in dtxt:
        refs.add(sec_tag)
    data = op.read_bytes()
    shoff = struct.unpack('>I', data[32:36])[0]
    shentsize, shnum, shstrndx = struct.unpack('>HHH', data[46:52])
    s_hdrs = [struct.unpack('>IIIIIIIIII', data[shoff+i*shentsize:shoff+(i+1)*shentsize]) for i in range(shnum)]
    shstr = data[s_hdrs[shstrndx][4]:s_hdrs[shstrndx][4]+s_hdrs[shstrndx][5]]
    sname = lambda idx: shstr[idx:shstr.index(0, idx)].decode()
    sec_idxs = [i for i, s in enumerate(s_hdrs) if sname(s[0]) == sec_name]
    if not sec_idxs: return {}
    sec_idx = sec_idxs[0]
    pmap = {}
    for s in s_hdrs:
        if s[1] == 2:
            strtab = data[s_hdrs[s[6]][4]:s_hdrs[s[6]][4]+s_hdrs[s[6]][5]]
            for j in range(0, s[5], 16):
                st_name, st_val, st_size, st_info, _, st_shndx = struct.unpack('>IIIBBH', data[s[4]+j:s[4]+j+16])
                if st_shndx == sec_idx:
                    nm = strtab[st_name:strtab.index(0, st_name)].decode()
                    if nm in refs or nm == sec_tag:
                        pmap[nm] = f'{base_sym}+0x{st_val:X}' if st_val else base_sym
    if sec_tag in refs and sec_tag not in pmap:
        pmap[sec_tag] = base_sym
    return pmap

def test_merge_pooled(mod, tu, base_sym, sec_name, u_list, sym_lists, mv, cflags, tu_txt):
    m0 = re.search(r'/\* fzgx:begin ', tu_txt)
    if not m0: return None
    pro = tu_txt[:m0.start()]
    blocks = []
    for u, fns in zip(u_list, sym_lists):
        for fn in fns:
            mm = re.search(rf'/\* fzgx:begin {fn}(?: (\w+))? \*/\n(.*?)\n/\* fzgx:end {fn} \*/', tu_txt, re.S)
            if not mm or mm.group(1) == 'noprologue': return None
            b = mm.group(2)
            if '.fzgxpool' in b: return None # keep primer-bearing units out of zero-edit pass
            blocks.append(b)
    code = pro + '\n\n' + '\n\n'.join(blocks) + '\n'
    comp = f'build/compilers/{mv}/mwcceppc.exe'
    src_obj_root = 'build/GFZE01/src'
    all_tu_fns = set(fn for fns in sym_lists for fn in fns)
    with tempfile.TemporaryDirectory(prefix='fzgx_mp_') as td:
        cp, op = pathlib.Path(td)/'u.c', pathlib.Path(td)/'u.o'
        cp.write_text(code)
        cmd = [
            'build/tools/wibo', comp,
            '-c', '-nodefaults', '-proc', 'gekko', '-align', 'powerpc', '-enum', 'int', '-fp', 'hardware',
            '-Cpp_exceptions', 'off', '-O4,p', '-inline', 'auto', '-pragma', 'cats off', '-pragma', 'warn_notinlined off',
            '-nosyspath', '-RTTI', 'off', '-fp_contract', 'on', '-str', 'reuse', '-multibyte',
            '-i', 'include', '-i', 'build/GFZE01/include', '-DBUILD_VERSION=0', '-DVERSION_GFZE01', '-DNDEBUG=1',
            '-sdata', '0', '-sdata2', '0', '-lang=c',
        ] + list(cflags) + ['-o', str(op), str(cp)]
        r = subprocess.run(cmd, capture_output=True, text=True)
        if r.returncode != 0: return None
        secs, syms = m.parse_elf(op)
        extra_secs = set(secs.keys()) - {'.text'}
        if extra_secs != {sec_name}: return None
        pmap = build_pool_map(op, base_sym, sec_name)
        if not pmap: return None
        pf_args = ['python3', 'tools/fzgx/poolfix.py', str(op)]
        for k, v in sorted(pmap.items()):
            pf_args.append(f'{k}={v}')
        pr = subprocess.run(pf_args, capture_output=True, text=True)
        if pr.returncode != 0: return None
        # Exact .text AND relocation comparison against already-verified compiled src/*.o!
        new_secs, new_syms = m.parse_elf(op)
        new_relas = parse_relas(op)
        for u, fns in zip(u_list, sym_lists):
            orig_p = pathlib.Path(f'{src_obj_root}/{u[:-2]}.o')
            if not orig_p.exists(): return None
            osecs, osyms = m.parse_elf(orig_p)
            orelas = parse_relas(orig_p)
            for fn in fns:
                if fn not in new_syms or fn not in osyms: return None
                o_off, o_sz = osyms[fn]; n_off, n_sz = new_syms[fn]
                ob, nb = osecs['.text'][1][o_off:o_off+o_sz], new_secs['.text'][1][n_off:n_off+n_sz]
                if len(ob) != len(nb): return None
                for i in range(0, len(ob), 4):
                    if ob[i:i+4] != nb[i:i+4]:
                        ow, nw = struct.unpack('>I', ob[i:i+4])[0], struct.unpack('>I', nb[i:i+4])[0]
                        if (ow >> 26) == 18 and (nw >> 26) == 18 and (ow & 3) == (nw & 3):
                            continue
                        return None
                # Compare non-intra-TU relocations!
                or_f = [x for x in orelas.get(fn, []) if not (x[1] == 10 and x[2] in all_tu_fns)]
                nr_f = [x for x in new_relas.get(fn, []) if not (x[1] == 10 and x[2] in all_tu_fns)]
                if or_f != nr_f:
                    return None
        return pmap

def process_tu(task):
    mod, tu, lst, units = task
    tu_path = pathlib.Path(f'src/rel/{mod}/{tu}.c')
    if not tu_path.exists(): return []
    tu_txt = tu_path.read_text()
    out = []
    used = set()
    n = len(lst)
    i = 0
    while i < n:
        if i in used:
            i += 1; continue
        sa, ea, u, extra = lst[i]
        info = units.get(u)
        if not info or extra:
            i += 1; continue
        mv = info.get('mw_version') or 'GC/1.3.2'
        cf = tuple(info.get('extra_cflags') or [])
        # Collect contiguous same-profile run starting at i that has at most ONE base_sym across pooled units!
        base_sym = None
        if info.get('pool'):
            bases = set(str(v).split('+')[0] for v in info['pool'].values())
            if len(bases) != 1: i += 1; continue
            base_sym = next(iter(bases))
        run = [(sa, ea, u)]
        prev_ea = ea
        for j in range(i + 1, min(i + 16, n)):
            sa2, ea2, u2, extra2 = lst[j]
            if sa2 != prev_ea or extra2: break
            inf2 = units.get(u2)
            if not inf2: break
            if (inf2.get('mw_version') or 'GC/1.3.2') != mv or tuple(inf2.get('extra_cflags') or []) != cf: break
            if inf2.get('pool'):
                b2 = set(str(v).split('+')[0] for v in inf2['pool'].values())
                if len(b2) != 1: break
                b2s = next(iter(b2))
                if base_sym is None:
                    base_sym = b2s
                elif base_sym != b2s:
                    break
            run.append((sa2, ea2, u2))
            prev_ea = ea2
        if base_sym is None or len(run) < 2:
            i += 1; continue
        if '_rodata_' in base_sym: sec_name = '.rodata'
        elif '_data_' in base_sym: sec_name = '.data'
        elif '_bss_' in base_sym: sec_name = '.bss'
        else: i += 1; continue
        # Find longest valid prefix of run that includes at least 1 pooled unit!
        best_k, best_pmap = 1, None
        for k in range(2, len(run) + 1):
            ul = [x[2] for x in run[:k]]
            if not any(units[x].get('pool') for x in ul): continue
            sl = [units[x]['symbols'] for x in ul]
            pmap = test_merge_pooled(mod, tu, base_sym, sec_name, ul, sl, mv, cf, tu_txt)
            if pmap is not None:
                best_k, best_pmap = k, pmap
            else:
                if best_k >= 2: break
                # Don't break if we haven't even reached the first pooled unit yet
                if any(units[x].get('pool') for x in ul): break
        if best_k >= 2:
            ul = [x[2] for x in run[:best_k]]
            pcnt = sum(1 for x in ul if units[x].get('pool'))
            out.append((mod, tu, base_sym, ul, run[0][0], run[best_k-1][1], best_pmap, pcnt, mv))
            for idx in range(i, i + best_k): used.add(idx)
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
    for sp in sorted(pathlib.Path('config/GFZE01').glob('*/splits.txt')):
        mod = sp.parent.name
        if mod == 'movie_module': continue
        splits = sp.read_text()
        splits_map[mod] = (sp, splits)
        entries = []
        for mm in re.finditer(rf'(rel/{re.escape(mod)}/[^\s]+\.c):\n((?:\t.*\n)*)', splits):
            u = mm.group(1)
            lines = [l.strip() for l in mm.group(2).splitlines() if l.strip()]
            tm = re.search(r'\.text\s+start:0x([0-9A-Fa-f]+)\s+end:0x([0-9A-Fa-f]+)', lines[0]) if lines else None
            if tm:
                entries.append((int(tm.group(1), 16), int(tm.group(2), 16), u, len(lines) > 1))
        entries.sort()
        by_tu = {}
        for sa, ea, u, extra in entries:
            parts = u.split('/')
            if len(parts) != 4: continue
            by_tu.setdefault(parts[2], []).append((sa, ea, u, extra))
        for tu, lst in by_tu.items():
            tasks.append((mod, tu, lst, units))
    all_out = []
    with concurrent.futures.ProcessPoolExecutor(max_workers=8) as ex:
        for res in ex.map(process_tu, tasks):
            all_out.extend(res)
    tot_units = sum(len(r[3]) - 1 for r in all_out)
    tot_pools = sum(r[7] - 1 for r in all_out if r[7] >= 2)
    print(f"RELOC+TEXT+POOLFIX VERIFIED {len(all_out)} consolidations: -{tot_units} units, -{tot_pools} mwcc_pool maps!")
    for mod, tu, b, ul, sa, ea, pmap, pcnt, mv in sorted(all_out, key=lambda x: (-x[7], -len(x[3])))[:20]:
        print(f"  {mod}/{tu:16s} {b:18s}: {len(ul):2d}->1 (pool {pcnt}->1): {ul[0].split('/')[-1]} .. {ul[-1].split('/')[-1]}")
    if dry: return

    by_mod = {}
    remove_set = set()
    head_updates = {}
    for mod, tu, b, ul, sa, ea, pmap, pcnt, mv in all_out:
        head = ul[0]
        by_mod.setdefault(mod, ({}, set()))
        by_mod[mod][0][head] = (f'0x{sa:08X}', f'0x{ea:08X}')
        for u in ul[1:]:
            remove_set.add(u)
            by_mod[mod][1].add(u)
        head_updates[head] = ([s for x in ul for s in units[x]['symbols']], pmap, mv)

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
        if s in remove_set: continue
        if s in head_updates:
            syms, pmap, mv = head_updates[s]
            u['symbols'] = syms
            u['collapsed'] = True
            u['pool'] = pmap
            if mv != 'GC/1.3.2': u['mw_version'] = mv
        new_units.append(u)
    raw = json.dumps(new_units, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', raw)
    units_path.write_text(raw)
    print(f"Applied: {old_count} -> {len(new_units)} units (-{old_count - len(new_units)}), -{tot_pools} mwcc_pool maps!")

if __name__ == '__main__':
    main()
