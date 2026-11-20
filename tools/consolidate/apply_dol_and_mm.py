import concurrent.futures, json, pathlib, re, subprocess, struct, tempfile

def parse_elf(path):
    data = pathlib.Path(path).read_bytes()
    shoff = struct.unpack('>I', data[32:36])[0]
    shentsize, shnum, shstrndx = struct.unpack('>HHH', data[46:52])
    secs = [struct.unpack('>IIIIIIIIII', data[shoff+i*shentsize:shoff+(i+1)*shentsize]) for i in range(shnum)]
    shstr = data[secs[shstrndx][4]:secs[shstrndx][4]+secs[shstrndx][5]]
    sname = lambda idx: shstr[idx:shstr.index(0, idx)].decode()
    out = {sname(s[0]): (s[5], data[s[4]:s[4]+s[5]] if s[1] != 8 else b'') for s in secs if sname(s[0]) in ('.text', '.rodata', '.data', '.bss', '.sdata', '.sdata2', '.sbss')}
    syms = {}
    for s in secs:
        if s[1] == 2:
            strtab = data[secs[s[6]][4]:secs[s[6]][4]+secs[s[6]][5]]
            for j in range(0, s[5], 16):
                st_name, st_val, st_size, st_info, _, _ = struct.unpack('>IIIBBH', data[s[4]+j:s[4]+j+16])
                if (st_info & 0xf) == 2 and st_size > 0:
                    syms[strtab[st_name:strtab.index(0, st_name)].decode()] = (st_val, st_size)
    return out, syms

def merge_c_files(paths):
    includes, pragmas = [], []
    seen_inc, seen_prag, seen_at, seen_ext, seen_inlines, seen_structs = set(), set(), set(), set(), set(), set()
    chunks = []
    for p in paths:
        txt = pathlib.Path('src/' + p).read_text()
        lines = txt.splitlines()
        out = []
        i = 0
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
            elif s.startswith('extern ') and s.endswith(';'):
                key = re.sub(r'\s+', ' ', s)
                if key not in seen_ext: seen_ext.add(key); out.append(l)
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
                if key not in seen_structs: seen_structs.add(key); out.append('\n'.join(blk))
            elif s.startswith('typedef ') and s.endswith(';'):
                key = re.sub(r'\s+', ' ', s)
                if key not in seen_structs: seen_structs.add(key); out.append(l)
            else:
                out.append(l)
            i += 1
        chunks.append(f'/* --- {p} --- */\n' + '\n'.join(out).strip())
    return '\n'.join(includes) + '\n' + '\n'.join(pragmas) + '\n\n' + '\n\n'.join(chunks) + '\n'

def verify_run(task):
    mod, mw_ver, cflags, sdata, u_list, sym_lists, sa, ea = task
    code = merge_c_files(u_list)
    comp = f'build/compilers/{mw_ver}/mwcceppc.exe'
    obj_root = 'build/GFZE01/obj' if mod == 'main' else f'build/GFZE01/{mod}/obj'
    with tempfile.TemporaryDirectory(prefix='fzgx_dm_') as td:
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
        if r.returncode != 0: return (False, mod, u_list, sym_lists, sa, ea, None)
        secs, syms = parse_elf(op)
        if set(secs.keys()) - {'.text'}: return (False, mod, u_list, sym_lists, sa, ea, None)
        for u, fns in zip(u_list, sym_lists):
            tsecs, tsyms = parse_elf(f'{obj_root}/{u[:-2]}.o')
            for fn in fns:
                if fn not in syms or fn not in tsyms: return (False, mod, u_list, sym_lists, sa, ea, None)
                t_off, t_sz = tsyms[fn]; c_off, c_sz = syms[fn]
                tb, cb = tsecs['.text'][1][t_off:t_off+t_sz], secs['.text'][1][c_off:c_off+c_sz]
                if len(tb) != len(cb): return (False, mod, u_list, sym_lists, sa, ea, None)
                for i in range(0, len(tb), 4):
                    if tb[i:i+4] != cb[i:i+4]:
                        tw, cw = struct.unpack('>I', tb[i:i+4])[0], struct.unpack('>I', cb[i:i+4])[0]
                        if (tw >> 26) == 18 and (cw >> 26) == 18 and (tw & 3) == (cw & 3):
                            continue
                        return (False, mod, u_list, sym_lists, sa, ea, None)
        return (True, mod, u_list, sym_lists, sa, ea, code)

def main():
    units_path = pathlib.Path('config/GFZE01/units.json')
    units_list = json.loads(units_path.read_text())
    units = {u['source']: u for u in units_list}

    tasks = []
    splits_files = {}
    for mod, sp_str, prefix, allowed_mvs, def_mv, sdata in [
        ('main', 'config/GFZE01/splits.txt', 'dol/', ('GC/1.3.2', 'GC/2.0p1'), 'GC/2.0p1', 8),
        ('movie_module', 'config/GFZE01/movie_module/splits.txt', 'rel/movie_module/', ('GC/1.3.2',), 'GC/1.3.2', 0),
    ]:
        sp = pathlib.Path(sp_str)
        splits = sp.read_text()
        splits_files[mod] = (sp, splits)
        entries = []
        for m in re.finditer(rf'({re.escape(prefix)}[^/\s]+\.c):\n((?:\t.*\n)*)', splits):
            u = m.group(1)
            lines = [l.strip() for l in m.group(2).splitlines() if l.strip()]
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
            if mv not in allowed_mvs:
                if len(cur) >= 2: runs.append((cur_prof, cur))
                cur = []; cur_prof = None; continue
            prof = (mv, tuple(info.get('extra_cflags') or []))
            if cur and (cur[-1][1] != sa or prof != cur_prof):
                if len(cur) >= 2: runs.append((cur_prof, cur))
                cur = []
            cur.append((sa, ea, u))
            cur_prof = prof
        if len(cur) >= 2: runs.append((cur_prof, cur))
        for prof, r in runs:
            tasks.append((mod, prof[0], prof[1], sdata, [e[2] for e in r], [units[e[2]]['symbols'] for e in r], r[0][0], r[-1][1]))

    passed = []
    with concurrent.futures.ProcessPoolExecutor(max_workers=8) as ex:
        for res in ex.map(verify_run, tasks):
            if res[0]:
                passed.append(res)

    by_mod = {}
    remove_set = set()
    head_syms = {}
    for _, mod, u_list, sym_lists, sa, ea, code in passed:
        head = u_list[0]
        pathlib.Path('src/' + head).write_text(code)
        for u in u_list[1:]:
            pathlib.Path('src/' + u).unlink()
            remove_set.add(u)
        by_mod.setdefault(mod, ({}, set()))
        by_mod[mod][0][head] = (f'0x{sa:08X}', f'0x{ea:08X}')
        for u in u_list[1:]:
            by_mod[mod][1].add(u)
        head_syms[head] = [s for sl in sym_lists for s in sl]

    for mod, (head_map, mod_rem) in by_mod.items():
        sp, splits = splits_files[mod]
        out, pos = [], 0
        for m in re.finditer(r'(\S+):\n((?:\t.*\n)*)', splits):
            unit = m.group(1)
            if unit in head_map:
                out.append(splits[pos:m.start()])
                sh, eh = head_map[unit]
                out.append(f'{unit}:\n\t.text       start:{sh} end:{eh} align:4\n')
                pos = m.end()
            elif unit in mod_rem:
                out.append(splits[pos:m.start()])
                pos = m.end()
                if pos < len(splits) and splits[pos] == '\n':
                    pos += 1
        out.append(splits[pos:])
        sp.write_text(''.join(out))

    old_count = len(units_list)
    new_units = []
    for u in units_list:
        s = u['source']
        if s in remove_set:
            continue
        if s in head_syms:
            u['symbols'] = head_syms[s]
            u['collapsed'] = True
        new_units.append(u)
    raw = json.dumps(new_units, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda m: '"matching_for": [' + ', '.join(x.strip() for x in m.group(1).split(',')) + ']', raw)
    units_path.write_text(raw)
    dol_ret = sum(len(r[2])-1 for r in passed if r[1] == 'main')
    mm_ret = sum(len(r[2])-1 for r in passed if r[1] == 'movie_module')
    print(f"Applied {len(passed)} runs (dol: -{dol_ret}, movie_module: -{mm_ret}): {old_count} -> {len(new_units)} (retired {old_count - len(new_units)} units & files!)")

if __name__ == '__main__':
    main()
