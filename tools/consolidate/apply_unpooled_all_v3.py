import concurrent.futures, json, pathlib, re, subprocess, struct, sys, tempfile
import importlib.util

spec_pa = importlib.util.spec_from_file_location('pa', str(pathlib.Path(__file__).with_name('apply_pooled_all.py')))
pa = importlib.util.module_from_spec(spec_pa); spec_pa.loader.exec_module(pa)
spec_sm = importlib.util.spec_from_file_location('sm', str(pathlib.Path(__file__).with_name('apply_smart_dol_mm.py')))
sm = importlib.util.module_from_spec(spec_sm); spec_sm.loader.exec_module(sm)

VERSIONS = ['GFZE01', 'GFZJ01', 'GFZP01']

def test_merge_rel(mod, tu, u_list, sym_lists, mv, cflags):
    tu_path = pathlib.Path(f'src/rel/{mod}/{tu}.c')
    if not tu_path.exists(): return False
    txt = tu_path.read_text()
    m0 = re.search(r'/\* fzgx:begin ', txt)
    if not m0: return False
    pro = txt[:m0.start()]
    blocks = []
    for fns in sym_lists:
        for fn in fns:
            mm = re.search(rf'/\* fzgx:begin {fn}(?: (\w+))? \*/\n(.*?)\n/\* fzgx:end {fn} \*/', txt, re.S)
            if not mm or mm.group(1) == 'noprologue': return False
            blocks.append(mm.group(2))
    code = pro + '\n\n' + '\n\n'.join(blocks) + '\n'
    comp = f'build/compilers/{mv}/mwcceppc.exe'
    src_obj_root = 'build/GFZE01/src'
    all_tu_fns = set(fn for fns in sym_lists for fn in fns)
    with tempfile.TemporaryDirectory(prefix='fzgx_ur_') as td:
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
        if r.returncode != 0: return False
        secs, syms = pa.m.parse_elf(op)
        raw_relas = pa.parse_relas(op)
        for sec in ('.rodata', '.data', '.bss', '.sdata', '.sdata2', '.sbss'):
            if secs.get(sec, (0,))[0] > 0: return False
        orig_text_tot = 0
        for u, fns in zip(u_list, sym_lists):
            orig_p = pathlib.Path(f'{src_obj_root}/{u[:-2]}.o')
            if not orig_p.exists(): return False
            osecs, osyms = pa.m.parse_elf(orig_p)
            orig_text_tot += osecs.get('.text', (0,))[0]
            orelas = pa.parse_relas(orig_p)
            for fn in fns:
                if fn not in syms or fn not in osyms: return False
                o_off, o_sz = osyms[fn]; n_off, n_sz = syms[fn]
                ob, nb = osecs['.text'][1][o_off:o_off+o_sz], secs['.text'][1][n_off:n_off+n_sz]
                if len(ob) != len(nb): return False
                for i in range(0, len(ob), 4):
                    if ob[i:i+4] != nb[i:i+4]:
                        ow, nw = struct.unpack('>I', ob[i:i+4])[0], struct.unpack('>I', nb[i:i+4])[0]
                        if (ow >> 26) == 18 and (nw >> 26) == 18 and (ow & 3) == (nw & 3): continue
                        return False
                or_f = [x for x in orelas.get(fn, []) if not (x[1] == 10 and x[2] in all_tu_fns)]
                nr_f = [x for x in raw_relas.get(fn, []) if not (x[1] == 10 and x[2] in all_tu_fns)]
                if or_f != nr_f: return False
        return secs.get('.text', (0,))[0] == orig_text_tot

def test_merge_dm(mod, u_list, sym_lists, mv, cflags, sdata):
    code = sm.merge_c_files_smart(u_list)
    comp = f'build/compilers/{mv}/mwcceppc.exe'
    src_obj_root = 'build/GFZE01/src'
    all_tu_fns = set(fn for fns in sym_lists for fn in fns)
    with tempfile.TemporaryDirectory(prefix='fzgx_ud_') as td:
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
        for sec in ('.rodata', '.data', '.bss', '.sdata', '.sdata2', '.sbss'):
            if secs.get(sec, (0,))[0] > 0: return None
        orig_text_tot = 0
        for u, fns in zip(u_list, sym_lists):
            orig_p = pathlib.Path(f'{src_obj_root}/{u[:-2]}.o')
            if not orig_p.exists(): return None
            osecs, osyms = pa.m.parse_elf(orig_p)
            orig_text_tot += osecs.get('.text', (0,))[0]
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
                or_f = [x for x in orelas.get(fn, []) if not (x[1] == 10 and x[2] in all_tu_fns)]
                nr_f = [x for x in raw_relas.get(fn, []) if not (x[1] == 10 and x[2] in all_tu_fns)]
                if or_f != nr_f: return None
        if secs.get('.text', (0,))[0] != orig_text_tot: return None
        return code

def process_rel_tu(task):
    mod, tu, lst, units = task
    out = []
    n, i = len(lst), 0
    while i < n:
        sa, ea, u, extra = lst[i]
        inf = units.get(u)
        if not inf or extra or inf.get('pool'): i += 1; continue
        run = [(sa, ea, u, (inf.get('mw_version') or 'GC/1.3.2', tuple(inf.get('extra_cflags') or [])))]
        prev_ea = ea
        for j in range(i + 1, min(i + 12, n)):
            sa2, ea2, u2, extra2 = lst[j]
            inf2 = units.get(u2)
            if sa2 != prev_ea or extra2 or not inf2 or inf2.get('pool'): break
            run.append((sa2, ea2, u2, (inf2.get('mw_version') or 'GC/1.3.2', tuple(inf2.get('extra_cflags') or []))))
            prev_ea = ea2
        if len(run) < 2: i += 1; continue
        cands = []
        for x in run[:3]:
            if x[3] not in cands: cands.append(x[3])
        best_k, best_prof = 1, None
        for mv, cf in cands:
            k_ok = 1
            for k in range(2, len(run) + 1):
                ul = [x[2] for x in run[:k]]
                sl = [units[x]['symbols'] for x in ul]
                if test_merge_rel(mod, tu, ul, sl, mv, cf): k_ok = k
                else: break
            if k_ok > best_k: best_k, best_prof = k_ok, (mv, cf)
        if best_k >= 2:
            ul = [x[2] for x in run[:best_k]]
            out.append(('rel', mod, ul, run[0][0], run[best_k-1][1], None, best_prof[0], best_prof[1]))
            i += best_k
        else: i += 1
    return out

def process_dm(task):
    mod, lst, units, def_mv, sdata = task
    out = []
    n, i = len(lst), 0
    while i < n:
        sa, ea, u, extra = lst[i]
        inf = units.get(u)
        if not inf or extra or inf.get('pool') or not pathlib.Path('src/' + u).exists(): i += 1; continue
        run = [(sa, ea, u, (inf.get('mw_version') or def_mv, tuple(inf.get('extra_cflags') or [])))]
        prev_ea = ea
        for j in range(i + 1, min(i + 10, n)):
            sa2, ea2, u2, extra2 = lst[j]
            inf2 = units.get(u2)
            if sa2 != prev_ea or extra2 or not inf2 or inf2.get('pool') or not pathlib.Path('src/' + u2).exists(): break
            run.append((sa2, ea2, u2, (inf2.get('mw_version') or def_mv, tuple(inf2.get('extra_cflags') or []))))
            prev_ea = ea2
        if len(run) < 2: i += 1; continue
        cands = []
        for x in run[:3]:
            if x[3] not in cands: cands.append(x[3])
        best_k, best_code, best_prof = 1, None, None
        for mv, cf in cands:
            k_ok, c_ok = 1, None
            for k in range(2, len(run) + 1):
                ul = [x[2] for x in run[:k]]
                sl = [units[x]['symbols'] for x in ul]
                res = test_merge_dm(mod, ul, sl, mv, cf, sdata)
                if res is not None: k_ok, c_ok = k, res
                else: break
            if k_ok > best_k: best_k, best_code, best_prof = k_ok, c_ok, (mv, cf)
        if best_k >= 2:
            ul = [x[2] for x in run[:best_k]]
            out.append(('dm', mod, ul, run[0][0], run[best_k-1][1], best_code, best_prof[0], best_prof[1]))
            i += best_k
        else: i += 1
    return out

def main():
    dry = '--dry-run' in sys.argv
    units_path = pathlib.Path('config/GFZE01/units.json')
    units_list = json.loads(units_path.read_text())
    units = {u['source']: u for u in units_list}
    rel_tasks, dm_tasks, splits_map = [], [], {}

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
            lines = [l.strip() for l in body.splitlines() if l.strip()]
            tm = re.search(r'\.text\s+start:0x([0-9A-Fa-f]+)\s+end:0x([0-9A-Fa-f]+)', lines[0]) if lines else None
            if tm: by_tu.setdefault(tu, []).append((int(tm.group(1), 16), int(tm.group(2), 16), u, len(lines) > 1))
        for tu, lst in sorted(by_tu.items()):
            lst.sort()
            if len(lst) >= 2: rel_tasks.append((mod, tu, lst, units))

    for mod, sp_str, pref, def_mv, sdata in [
        ('main', 'config/GFZE01/splits.txt', 'dol/', 'GC/1.3.2', 8),
        ('movie_module', 'config/GFZE01/movie_module/splits.txt', 'rel/movie_module/', 'GC/1.3.2', 0),
    ]:
        sp = pathlib.Path(sp_str)
        txt = sp.read_text()
        splits_map[mod] = (sp, txt)
        lst = []
        for mm in re.finditer(rf'({re.escape(pref)}[^/\s]+\.c):\n((?:\t.*\n)*)', txt):
            u, body = mm.group(1), mm.group(2)
            lines = [l.strip() for l in body.splitlines() if l.strip()]
            tm = re.search(r'\.text\s+start:0x([0-9A-Fa-f]+)\s+end:0x([0-9A-Fa-f]+)', lines[0]) if lines else None
            if tm: lst.append((int(tm.group(1), 16), int(tm.group(2), 16), u, len(lines) > 1))
        lst.sort()
        dm_tasks.append((mod, lst, units, def_mv, sdata))

    all_out = []
    with concurrent.futures.ProcessPoolExecutor(max_workers=8) as ex:
        for res in ex.map(process_rel_tu, rel_tasks): all_out.extend(res)
        for res in ex.map(process_dm, dm_tasks): all_out.extend(res)
    tot_u = sum(len(r[2]) - 1 for r in all_out)
    print(f"UNPOOLED ALL V3 VERIFIED {len(all_out)} consolidations: -{tot_u} units!")
    for kind, mod, ul, sa, ea, code, mv, cf in sorted(all_out, key=lambda x: -len(x[2]))[:25]:
        print(f"  {kind:3s} {mod:12s} {mv:9s}: {len(ul):2d}->1: {ul[0]} .. {ul[-1]}")
    if dry or not all_out: return

    by_mod, rem_set, head_updates = {}, set(), {}
    for kind, mod, ul, sa, ea, code, mv, cf in all_out:
        head = ul[0]
        if kind == 'dm':
            pathlib.Path('src/' + head).write_text(code)
            for u in ul[1:]: pathlib.Path('src/' + u).unlink()
        by_mod.setdefault(mod, ({}, set()))
        by_mod[mod][0][head] = (f'0x{sa:08X}', f'0x{ea:08X}')
        for u in ul[1:]:
            by_mod[mod][1].add(u)
            rem_set.add(u)
        inter_mf = set(VERSIONS)
        for u in ul: inter_mf &= set(units[u].get('matching_for', VERSIONS))
        head_updates[head] = (kind, [s for x in ul for s in units[x]['symbols']], mv, list(cf), [v for v in VERSIONS if v in inter_mf])

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
            kind, syms, mv, cf, mf = head_updates[s]
            u['symbols'] = syms
            u['collapsed'] = True
            if kind == 'dm' or mv != 'GC/1.3.2': u['mw_version'] = mv
            else: u.pop('mw_version', None)
            if cf: u['extra_cflags'] = cf
            else: u.pop('extra_cflags', None)
            if mf != VERSIONS: u['matching_for'] = mf
            else: u.pop('matching_for', None)
        new_units.append(u)
    raw = json.dumps(new_units, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', raw)
    units_path.write_text(raw)
    print(f"Applied unpooled ALL v3: {old_count} -> {len(new_units)} (-{old_count - len(new_units)})!")

if __name__ == '__main__':
    main()
