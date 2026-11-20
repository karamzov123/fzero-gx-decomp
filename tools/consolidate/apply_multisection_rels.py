import concurrent.futures, json, pathlib, re, subprocess, struct, sys, tempfile
import importlib.util

spec_pa = importlib.util.spec_from_file_location('pa', str(pathlib.Path(__file__).with_name('apply_pooled_all.py')))
pa = importlib.util.module_from_spec(spec_pa); spec_pa.loader.exec_module(pa)

VERSIONS = ['GFZE01', 'GFZJ01', 'GFZP01']
SEC_ORDER = ['.text', '.rodata', '.data', '.bss', '.sdata', '.sdata2', '.sbss']

def parse_split_secs(body):
    secs = {}
    for ln in body.splitlines():
        m = re.match(r'\s+(\.\w+)\s+start:0x([0-9A-Fa-f]+)\s+end:0x([0-9A-Fa-f]+)(?:\s+align:(\d+))?', ln)
        if m:
            secs[m.group(1)] = (int(m.group(2), 16), int(m.group(3), 16), int(m.group(4)) if m.group(4) else 4)
    return secs

def merge_sec_ranges(sec_dicts):
    # Returns merged {sec: (start, end, align)} if every section present across the run is contiguous (modulo alignment), else None
    merged = {}
    for sec in SEC_ORDER:
        present = [d[sec] for d in sec_dicts if sec in d]
        if not present: continue
        # Must be strictly ordered and contiguous (allowing alignment padding between consecutive ranges)
        cur_s, cur_e, cur_a = present[0]
        for s, e, a in present[1:]:
            if s < cur_e: return None
            # Check gap <= alignment
            pad_e = (cur_e + a - 1) & ~(a - 1) if a > 1 else cur_e
            if s != cur_e and s != pad_e:
                return None
            cur_e = e
            cur_a = max(cur_a, a)
        merged[sec] = (cur_s, cur_e, cur_a)
    # Check no unknown sections
    for d in sec_dicts:
        for k in d:
            if k not in SEC_ORDER: return None
    return merged

def test_merge_rel_ms(mod, tu, u_list, sym_lists, merged_secs, mv, cflags):
    tu_path = pathlib.Path(f'src/rel/{mod}/{tu}.c')
    if not tu_path.exists(): return None
    txt = tu_path.read_text()
    m0 = re.search(r'/\* fzgx:begin ', txt)
    if not m0: return None
    pro = txt[:m0.start()]
    blocks = []
    for fns in sym_lists:
        for fn in fns:
            mm = re.search(rf'/\* fzgx:begin {fn}(?: (\w+))? \*/\n(.*?)\n/\* fzgx:end {fn} \*/', txt, re.S)
            if not mm: return None
            if mm.group(1) == 'noprologue': return None
            blocks.append(mm.group(2))
    code = pro + '\n\n' + '\n\n'.join(blocks) + '\n'
    comp = f'build/compilers/{mv}/mwcceppc.exe'
    src_obj_root = 'build/GFZE01/src'
    all_tu_fns = set(fn for fns in sym_lists for fn in fns)

    with tempfile.TemporaryDirectory(prefix='fzgx_ms_') as td:
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
        secs, syms = pa.m.parse_elf(op)
        raw_relas = pa.parse_relas(op)

        # Verify section sizes match merged_secs (exact for .text, <= or exact for others)
        for sec, (s, e, a) in merged_secs.items():
            exp_sz = e - s
            got_sz = secs.get(sec, (0, b''))[0]
            if sec == '.text':
                if got_sz != exp_sz: return None
            else:
                # Allow exact match or alignment-rounded match
                pad_got = (got_sz + a - 1) & ~(a - 1) if a > 1 else got_sz
                if got_sz != exp_sz and pad_got != exp_sz:
                    return None
        # Ensure no unexpected non-empty data/rodata/bss sections were created that aren't in merged_secs
        for sec in SEC_ORDER[1:]:
            if sec not in merged_secs and secs.get(sec, (0, b''))[0] > 0:
                return None

        # Verify every function's .text bytes and non-local relocs
        for u, fns in zip(u_list, sym_lists):
            orig_p = pathlib.Path(f'{src_obj_root}/{u[:-2]}.o')
            if not orig_p.exists(): return None
            osecs, osyms = pa.m.parse_elf(orig_p)
            orelas = pa.parse_relas(orig_p)
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
                # Compare non-internal relocs (note: local .rodata/.data/.bss offsets shift on merge, so check external relocs + rely on full ninja SHA1 check!)
                or_ext = [(off, rt, sn, ra) for off, rt, sn, ra in orelas.get(fn, []) if not sn.startswith(('.', '@')) and not (rt == 10 and sn in all_tu_fns)]
                nr_ext = [(off, rt, sn, ra) for off, rt, sn, ra in raw_relas.get(fn, []) if not sn.startswith(('.', '@')) and not (rt == 10 and sn in all_tu_fns)]
                if or_ext != nr_ext: return None
        return True

def process_tu(task):
    mod, tu, lst, units = task
    out = []
    n = len(lst)
    i = 0
    while i < n:
        u0, secs0 = lst[i]
        inf0 = units.get(u0)
        if not inf0 or inf0.get('pool') or '.text' not in secs0:
            i += 1; continue
        run = [(u0, secs0, (inf0.get('mw_version') or 'GC/1.3.2', tuple(inf0.get('extra_cflags') or [])))]
        prev_ea = secs0['.text'][1]
        for j in range(i + 1, min(i + 12, n)):
            u2, secs2 = lst[j]
            inf2 = units.get(u2)
            if not inf2 or inf2.get('pool') or '.text' not in secs2: break
            if secs2['.text'][0] != prev_ea: break
            run.append((u2, secs2, (inf2.get('mw_version') or 'GC/1.3.2', tuple(inf2.get('extra_cflags') or []))))
            prev_ea = secs2['.text'][1]
        if len(run) < 2:
            i += 1; continue
        # Must have at least one unit with non-.text sections (otherwise already handled by plain consolidator)
        if not any(len(x[1]) > 1 for x in run):
            i += 1; continue
        cands = []
        for x in run[:3]:
            if x[2] not in cands: cands.append(x[2])
        best_k, best_ms, best_prof = 1, None, None
        for mv, cf in cands:
            for k in range(len(run), 1, -1):
                if k <= best_k: break
                ms = merge_sec_ranges([x[1] for x in run[:k]])
                if ms is None: continue
                ul = [x[0] for x in run[:k]]
                sl = [units[x]['symbols'] for x in ul]
                if test_merge_rel_ms(mod, tu, ul, sl, ms, mv, cf):
                    best_k, best_ms, best_prof = k, ms, (mv, cf)
                    break
        if best_k >= 2:
            ul = [x[0] for x in run[:best_k]]
            out.append((mod, tu, ul, best_ms, best_prof[0], best_prof[1]))
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
    for mod_dir in sorted(pathlib.Path('config/GFZE01').iterdir()):
        sp = mod_dir / 'splits.txt'
        if not mod_dir.is_dir() or not sp.exists() or mod_dir.name == 'movie_module': continue
        mod = mod_dir.name
        txt = sp.read_text()
        splits_map[mod] = (sp, txt)
        by_tu = {}
        for mm in re.finditer(rf'(rel/{mod}/[^\s:]+\.c):\n((?:\t.*\n)*)', txt):
            u, body = mm.group(1), mm.group(2)
            tu = (units[u]['tu'].split('/')[-1][:-2] if u in units and units[u].get('tu') and units[u]['tu'].startswith(f'rel/{mod}/') else (u.split('/')[2] if len(u.split('/')) == 4 else None))
            if tu is None or tu == 'data' or '/data/' in u: continue
            secs = parse_split_secs(body)
            if '.text' in secs:
                by_tu.setdefault(tu, []).append((u, secs))
        for tu, lst in sorted(by_tu.items()):
            lst.sort(key=lambda x: x[1]['.text'][0])
            if len(lst) >= 2:
                tasks.append((mod, tu, lst, units))

    all_out = []
    with concurrent.futures.ProcessPoolExecutor(max_workers=8) as ex:
        for res in ex.map(process_tu, tasks):
            all_out.extend(res)
    tot_u = sum(len(r[2]) - 1 for r in all_out)
    print(f"MULTI-SECTION REL VERIFIED {len(all_out)} consolidations: -{tot_u} units!")
    for mod, tu, ul, ms, mv, cf in sorted(all_out, key=lambda x: -len(x[2]))[:30]:
        secs_str = ','.join(ms.keys())
        print(f"  {mod}/{tu:20s} {mv:8s}: {len(ul):2d}->1 [{secs_str}]: {ul[0].split('/')[-1]} .. {ul[-1].split('/')[-1]}")
    if dry or not all_out: return

    by_mod, rem_set, head_updates = {}, set(), {}
    for mod, tu, ul, ms, mv, cf in all_out:
        head = ul[0]
        by_mod.setdefault(mod, ({}, set()))
        by_mod[mod][0][head] = ms
        for u in ul[1:]:
            by_mod[mod][1].add(u)
            rem_set.add(u)
        inter_mf = set(VERSIONS)
        for u in ul: inter_mf &= set(units[u].get('matching_for', VERSIONS))
        head_updates[head] = ([s for x in ul for s in units[x]['symbols']], mv, list(cf), [v for v in VERSIONS if v in inter_mf])

    for mod, (head_map, mod_rem) in by_mod.items():
        sp, splits = splits_map[mod]
        out, pos = [], 0
        for mm in re.finditer(r'(\S+):\n((?:\t.*\n)*)', splits):
            unit = mm.group(1)
            if unit in head_map:
                out.append(splits[pos:mm.start()])
                ms = head_map[unit]
                lines = [f'{unit}:']
                for sec in SEC_ORDER:
                    if sec in ms:
                        s, e, a = ms[sec]
                        lines.append(f'\t{sec:<11s} start:0x{s:08X} end:0x{e:08X} align:{a}')
                out.append('\n'.join(lines) + '\n')
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
            syms, mv, cf, mf = head_updates[s]
            u['symbols'] = syms
            u['collapsed'] = True
            if mv != 'GC/1.3.2': u['mw_version'] = mv
            else: u.pop('mw_version', None)
            if cf: u['extra_cflags'] = cf
            else: u.pop('extra_cflags', None)
            if mf != VERSIONS: u['matching_for'] = mf
            else: u.pop('matching_for', None)
        new_units.append(u)
    raw = json.dumps(new_units, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', raw)
    units_path.write_text(raw)
    print(f"Applied multi-section RELs: {old_count} -> {len(new_units)} (-{old_count - len(new_units)})!")

if __name__ == '__main__':
    main()
