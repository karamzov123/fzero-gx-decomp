import concurrent.futures, json, pathlib, re, subprocess, struct, sys, tempfile
import importlib.util

spec = importlib.util.spec_from_file_location('m', str(pathlib.Path(__file__).with_name('apply_dol_and_mm.py')))
m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)

def _header_names(includes):
    import sys as _s
    _s.path.insert(0, str(pathlib.Path(__file__).parent))
    import steer_prune
    return steer_prune.header_names('\n'.join(includes))


def merge_c_files_smart(paths):
    includes, pragmas = [], []
    # names the union of the files' headers declares: a file's own redeclaration of one of them
    # (lifted per-file prototypes, typedefs and struct views) gives way to the header
    all_inc = []
    for p in paths:
        for ln in pathlib.Path('src/' + p).read_text().splitlines():
            if ln.strip().startswith('#include') and ln.strip() not in all_inc:
                all_inc.append(ln.strip())
    hdr = _header_names(all_inc) if len(paths) > 1 else set()
    seen_inc, seen_prag, seen_at, seen_ext, seen_inlines = set(), set(), set(), set(), set()
    # Map struct/typedef name -> canonical body text; if a later file defines the same name with a DIFFERENT body, rename it to <name>_u<idx>!
    seen_type_bodies = {}
    seen_fn_decls = set()
    chunks = []
    for fidx, p in enumerate(paths):
        txt = pathlib.Path('src/' + p).read_text()
        # First pass: find all local struct/typedef definitions in this file
        renames = {}
        lines = txt.splitlines()
        i = 0
        while i < len(lines):
            s = lines[i].strip()
            if (s.startswith('typedef struct') or s.startswith('struct ')) and '{' in s:
                blk = [lines[i]]
                depth = lines[i].count('{') - lines[i].count('}')
                while depth > 0 and i + 1 < len(lines):
                    i += 1; blk.append(lines[i]); depth += lines[i].count('{') - lines[i].count('}')
                full = '\n'.join(blk)
                norm = re.sub(r'\s+', ' ', full.strip())
                # Extract tag and typedef alias
                tag_m = re.match(r'(?:typedef\s+)?struct\s+(\w+)\s*\{', norm)
                alias_m = re.search(r'\}\s*(\w+)\s*;$', norm)
                names = []
                if tag_m: names.append(tag_m.group(1))
                if alias_m and alias_m.group(1) not in names: names.append(alias_m.group(1))
                conflict = False
                for nm in names:
                    if nm in seen_type_bodies and seen_type_bodies[nm] != norm:
                        conflict = True
                if conflict:
                    for nm in names:
                        renames[nm] = f'{nm}_u{fidx}'
                else:
                    for nm in names:
                        seen_type_bodies[nm] = norm
            elif s.startswith('typedef ') and s.endswith(';') and '{' not in s:
                # single-line typedef (scalar, pointer or function-pointer): rename a conflicting one
                norm = re.sub(r'\s+', ' ', s)
                fm = re.search(r'\(\s*\*\s*(\w+)\s*\)\s*\(', norm)
                nm = fm.group(1) if fm else (re.search(r'(\w+)\s*(?:\[[^\]]*\])*\s*;$', norm) or [None, None])[1]
                if nm:
                    if nm in seen_type_bodies and seen_type_bodies[nm] != norm:
                        renames[nm] = f'{nm}_u{fidx}'
                    else:
                        seen_type_bodies.setdefault(nm, norm)
            i += 1
        if renames:
            for old_nm, new_nm in sorted(renames.items(), key=lambda x: -len(x[0])):
                txt = re.sub(rf'\b{re.escape(old_nm)}\b', new_nm, txt)

        # Second pass: emit deduplicated lines
        lines = txt.splitlines()
        out = []
        i = 0
        seen_local_structs = set()
        while i < len(lines):
            l = lines[i]
            s = l.strip()
            if s.startswith('#include'):
                if s not in seen_inc: seen_inc.add(s); includes.append(l)
            elif s.startswith('#pragma'):
                if s not in seen_prag: seen_prag.add(s); pragmas.append(l)
            elif ': FZGX_ADDR_' in s:
                if out and out[-1].strip() and not out[-1].strip().endswith((';', '}', '{', '*/')) and not out[-1].strip().startswith(('//', '#')):
                    full = out.pop() + '\n' + l
                else:
                    full = l
                key = re.sub(r'\s+', ' ', full.strip())
                if key not in seen_at: seen_at.add(key); out.append(full)
            elif (re.match(r'^(?:static\s+)?[A-Za-z_][\w\s\*]*\b(\w+)\s*\([^;{}]*\)\s*;$', s)
                  and not s.startswith(('extern ', 'typedef ', 'return ', 'else ')) and l[:1].strip()):
                # a top-level prototype repeated by a later file: keep the first spelling
                fn_m = re.search(r'\b(\w+)\s*\([^;{}]*\)\s*;$', s)
                if fn_m and fn_m.group(1) in seen_fn_decls:
                    pass
                else:
                    if fn_m: seen_fn_decls.add(fn_m.group(1))
                    out.append(l)
            elif s.startswith('extern ') and s.endswith(';') and (lambda _m: bool(_m and _m.group(1) in hdr))(re.search(r'\b(\w+)\s*\([^;]*\)\s*;$', s) or re.search(r'\b(\w+)\s*(?:\[[^\]]*\])*\s*;$', s)):
                pass   # declared by an included header
            elif s.startswith('extern ') and s.endswith(';'):
                key = re.sub(r'\s+', ' ', s)
                if key not in seen_ext:
                    # Check if this is a function prototype whose name was already declared
                    fn_m = re.search(r'\b(\w+)\s*\([^)]*\)\s*;$', key)
                    if fn_m and fn_m.group(1) in seen_fn_decls:
                        pass # drop conflicting duplicate extern prototype
                    else:
                        if fn_m: seen_fn_decls.add(fn_m.group(1))
                        seen_ext.add(key); out.append(l)
            elif s.startswith('static inline ') or (s.startswith('static ') and '{' in s and not s.endswith(';')):
                blk = [l]
                depth = l.count('{') - l.count('}')
                while (depth > 0 or '{' not in ''.join(blk)) and i + 1 < len(lines):
                    i += 1; blk.append(lines[i]); depth += lines[i].count('{') - lines[i].count('}')
                fn_m = re.search(r'\b(\w+)\s*\(', blk[0])
                fn_nm = fn_m.group(1) if fn_m else '\n'.join(blk)
                if fn_nm not in seen_inlines: seen_inlines.add(fn_nm); out.append('\n'.join(blk))
            elif (s.startswith('typedef struct') or s.startswith('struct ')) and '{' in s:
                blk = [l]
                depth = l.count('{') - l.count('}')
                while depth > 0 and i + 1 < len(lines):
                    i += 1; blk.append(lines[i]); depth += lines[i].count('{') - lines[i].count('}')
                key = re.sub(r'\s+', ' ', '\n'.join(blk).strip())
                tag_m = re.match(r'(?:typedef\s+)?struct\s+(\w+)', key); al_m = re.search(r'\}\s*(\w+)\s*;$', key)
                if (tag_m and tag_m.group(1) in hdr) or (al_m and al_m.group(1) in hdr):
                    pass   # the header defines this type
                elif key not in seen_local_structs and key not in seen_ext:
                    seen_ext.add(key); seen_local_structs.add(key); out.append('\n'.join(blk))
            elif s.startswith('typedef ') and s.endswith(';'):
                key = re.sub(r'\s+', ' ', s)
                fm = re.search(r'\(\s*\*\s*(\w+)\s*\)\s*\(', key); nm = fm.group(1) if fm else (re.search(r'(\w+)\s*(?:\[[^\]]*\])*\s*;$', key) or [None, None])[1]
                if nm in hdr:
                    pass   # the header defines this typedef
                elif key not in seen_ext: seen_ext.add(key); out.append(l)
            else:
                # Track defined function names
                if not s.startswith(('//', '/*', '#')) and '(' in s and '{' in s and not s.startswith(('if', 'for', 'while', 'switch', 'else', 'return')):
                    fn_m = re.search(r'\b(\w+)\s*\(', s)
                    if fn_m: seen_fn_decls.add(fn_m.group(1))
                out.append(l)
            i += 1
        chunks.append(f'/* --- {p} --- */\n' + '\n'.join(out).strip())
    return '\n'.join(includes) + '\n' + '\n'.join(pragmas) + '\n\n' + '\n\n'.join(chunks) + '\n'

def verify_smart(mod, mw_ver, cflags, sdata, u_list, sym_lists):
    code = merge_c_files_smart(u_list)
    comp = f'build/compilers/{mw_ver}/mwcceppc.exe'
    obj_root = 'build/GFZE01/obj' if mod == 'main' else f'build/GFZE01/{mod}/obj'
    with tempfile.TemporaryDirectory(prefix='fzgx_sm_') as td:
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
        secs, syms = m.parse_elf(op)
        if set(secs.keys()) - {'.text'}: return None
        for u, fns in zip(u_list, sym_lists):
            tsecs, tsyms = m.parse_elf(f'{obj_root}/{u[:-2]}.o')
            for fn in fns:
                if fn not in syms or fn not in tsyms: return None
                t_off, t_sz = tsyms[fn]; c_off, c_sz = syms[fn]
                tb, cb = tsecs['.text'][1][t_off:t_off+t_sz], secs['.text'][1][c_off:c_off+c_sz]
                if len(tb) != len(cb): return None
                for i in range(0, len(tb), 4):
                    if tb[i:i+4] != cb[i:i+4]:
                        tw, cw = struct.unpack('>I', tb[i:i+4])[0], struct.unpack('>I', cb[i:i+4])[0]
                        if (tw >> 26) == 18 and (cw >> 26) == 18 and (tw & 3) == (cw & 3):
                            continue
                        return None
        return code

def greedy_smart(task):
    mod, mw_ver, cflags, sdata, u_list, sym_lists, ranges = task
    n = len(u_list)
    out = []
    i = 0
    while i < n:
        if i + 1 >= n: break
        c2 = verify_smart(mod, mw_ver, cflags, sdata, u_list[i:i+2], sym_lists[i:i+2])
        if c2 is None:
            i += 1; continue
        lo, hi, best, best_code = i + 2, n, i + 2, c2
        while lo <= hi:
            mid = (lo + hi) // 2
            if mid == best: lo = mid + 1; continue
            cm = verify_smart(mod, mw_ver, cflags, sdata, u_list[i:mid], sym_lists[i:mid])
            if cm is not None:
                best, best_code = mid, cm
                lo = mid + 1
            else:
                hi = mid - 1
        out.append((mod, u_list[i:best], sym_lists[i:best], ranges[i][0], ranges[best-1][1], best_code))
        i = best
    return out

def main():
    dry = '--dry-run' in sys.argv
    units_path = pathlib.Path('config/GFZE01/units.json')
    units_list = json.loads(units_path.read_text())
    units = {u['source']: u for u in units_list}
    tasks = []
    splits_files = {}
    for mod, sp_str, prefix, def_mv, sdata in [
        ('main', 'config/GFZE01/splits.txt', 'dol/', 'GC/2.0p1', 8),
        ('movie_module', 'config/GFZE01/movie_module/splits.txt', 'rel/movie_module/', 'GC/1.3.2', 0),
    ]:
        sp = pathlib.Path(sp_str)
        splits = sp.read_text()
        splits_files[mod] = (sp, splits)
        entries = []
        for mm in re.finditer(rf'({re.escape(prefix)}[^/\s]+\.c):\n((?:\t.*\n)*)', splits):
            u = mm.group(1)
            lines = [l.strip() for l in mm.group(2).splitlines() if l.strip()]
            tm = re.search(r'\.text\s+start:0x([0-9A-Fa-f]+)\s+end:0x([0-9A-Fa-f]+)', lines[0]) if lines else None
            if tm: entries.append((int(tm.group(1), 16), int(tm.group(2), 16), u, len(lines) > 1))
        entries.sort()
        runs, cur, cur_prof = [], [], None
        for sa, ea, u, extra in entries:
            info = units.get(u)
            if not info or info.get('pool') or extra or not pathlib.Path('src/' + u).exists():
                if len(cur) >= 2: runs.append((cur_prof, cur))
                cur = []; cur_prof = None; continue
            mv = info.get('mw_version') or def_mv
            prof = (mv, tuple(info.get('extra_cflags') or []))
            if cur and (cur[-1][1] != sa or prof != cur_prof):
                if len(cur) >= 2: runs.append((cur_prof, cur))
                cur = []
            cur.append((sa, ea, u))
            cur_prof = prof
        if len(cur) >= 2: runs.append((cur_prof, cur))
        for prof, r in runs:
            tasks.append((mod, prof[0], prof[1], sdata, [e[2] for e in r], [units[e[2]]['symbols'] for e in r], [(e[0], e[1]) for e in r]))

    all_out = []
    with concurrent.futures.ProcessPoolExecutor(max_workers=8) as ex:
        for res in ex.map(greedy_smart, tasks):
            all_out.extend(res)
    dol_ret = sum(len(r[1]) - 1 for r in all_out if r[0] == 'main')
    mm_ret = sum(len(r[1]) - 1 for r in all_out if r[0] == 'movie_module')
    print(f"SMART MERGE VERIFIED {len(all_out)} runs (dol: -{dol_ret}, movie_module: -{mm_ret}; TOTAL -{dol_ret+mm_ret} units & files!)")
    for mod, ul, sl, sa, ea, _ in sorted(all_out, key=lambda x: -len(x[1]))[:15]:
        print(f"  {mod:12s} {len(ul):2d}->1: {ul[0]} .. {ul[-1]}")
    if dry: return

    by_mod = {}
    remove_set = set()
    head_syms = {}
    for mod, ul, sl, sa, ea, code in all_out:
        head = ul[0]
        pathlib.Path('src/' + head).write_text(code)
        for u in ul[1:]:
            pathlib.Path('src/' + u).unlink()
            remove_set.add(u)
        by_mod.setdefault(mod, ({}, set()))
        by_mod[mod][0][head] = (f'0x{sa:08X}', f'0x{ea:08X}')
        for u in ul[1:]: by_mod[mod][1].add(u)
        head_syms[head] = [s for l in sl for s in l]

    for mod, (head_map, mod_rem) in by_mod.items():
        sp, splits = splits_files[mod]
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
        if s in head_syms:
            u['symbols'] = head_syms[s]
            u['collapsed'] = True
        new_units.append(u)
    raw = json.dumps(new_units, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', raw)
    units_path.write_text(raw)
    print(f"Applied: {old_count} -> {len(new_units)} units (-{old_count - len(new_units)})")

if __name__ == '__main__':
    main()
