import concurrent.futures, json, pathlib, re, subprocess, struct, sys, tempfile
import importlib.util

spec_pa = importlib.util.spec_from_file_location('pa', str(pathlib.Path(__file__).with_name('apply_pooled_all.py')))
pa = importlib.util.module_from_spec(spec_pa); spec_pa.loader.exec_module(pa)

LOCAL_POOL_RE = re.compile(r'^(?:@\d+|\.\.\.(?:rodata|data|bss|sdata|sdata2|sbss)\.0)$')

def fmt_target(sym, addend):
    if addend == 0: return sym
    if addend > 0: return f'{sym}+0x{addend:X}'
    return None

def prologue_has_defs(pro):
    for line in pro.splitlines():
        s = line.strip()
        if not s or s.startswith(('#', '//', '/*', '*', 'extern ', 'typedef ', 'struct ', 'union ', 'enum ', 'static ', '}', '{', '0x')):
            continue
        if re.search(r'\blbl_\w+', s) and '(' not in s:
            return True
    return False

def parse_prologue_info(pro):
    incs = set(re.findall(r'^[ \t]*#include\s+[<"]([^>"]+)[>"]', pro, re.M))
    all_text = [pro]
    seen_hdrs = set()
    queue = list(incs)
    while queue:
        h = queue.pop()
        if h in seen_hdrs: continue
        seen_hdrs.add(h)
        hp = pathlib.Path('include') / h
        if hp.exists():
            htxt = hp.read_text(errors='ignore')
            all_text.append(htxt)
            for nh in re.findall(r'^[ \t]*#include\s+[<"]([^>"]+)[>"]', htxt, re.M):
                if nh not in seen_hdrs: queue.append(nh)
    combined = '\n'.join(all_text)
    tags = set(re.findall(r'\b(?:struct|union|enum)\s+(\w+)\s*\{', combined))
    tdefs = set(re.findall(r'\}\s*(\w+)\s*;', combined))
    exts = set()
    for m in re.finditer(r'^[ \t]*(?:extern\b)?[^;{}()\n]*?\b(\w+)\s*(?:\[[^\]]*\]|\([^;{}]*\))\s*;', combined, re.M):
        exts.add(m.group(1))
    for m in re.finditer(r'^[ \t]*extern\b[^;{}]+?(\b\w+)\s*;', combined, re.M):
        exts.add(m.group(1))
    return seen_hdrs, tags, tdefs, exts

def clean_block_for_prologue(fn, body, pro_incs, pro_tags, pro_tdefs, pro_exts):
    # 1. Strip #includes already in prologue
    lines = []
    for ln in body.splitlines(True):
        mi = re.match(r'^[ \t]*#include\s+[<"]([^>"]+)[>"]', ln)
        if mi and mi.group(1) in pro_incs:
            continue
        # 2. Strip simple single-line extern declarations whose symbol is already in prologue
        me = re.match(r'^[ \t]*extern\b[^;{}]+?(\b\w+)\s*(?:\[[^\]]*\]|\([^;]*\))?\s*;\s*$', ln)
        if me and me.group(1) in pro_exts:
            continue
        lines.append(ln)
    b = ''.join(lines)
    # 3. Rename any colliding struct/union/enum tag or typedef name defined in this block
    # Find typedef struct Tag { ... } Name; or struct Tag { ... };
    renames = {}
    for m in re.finditer(r'\b(struct|union|enum)\s+(\w+)\s*\{', b):
        tag = m.group(2)
        if tag in pro_tags or tag in pro_tdefs:
            renames[tag] = f'{tag}_np_{fn}'
    for m in re.finditer(r'\}\s*(\w+)\s*;', b):
        tn = m.group(1)
        if tn in pro_tdefs or tn in pro_tags:
            renames[tn] = f'{tn}_np_{fn}'
    for old, new in renames.items():
        b = re.sub(rf'\b{re.escape(old)}\b', new, b)
    return b.lstrip('\n')

def test_tu_nopro(task):
    mod, tu, tu_path, u_infos = task
    txt = pathlib.Path(tu_path).read_text()
    m0 = re.search(r'/\* fzgx:begin ', txt)
    if not m0: return []
    pro = txt[:m0.start()]
    if prologue_has_defs(pro):
        return []
    pro_incs, pro_tags, pro_tdefs, pro_exts = parse_prologue_info(pro)

    hits = []
    for u, syms_list, mv, cf, has_pool in u_infos:
        if len(syms_list) != 1: continue
        fn = syms_list[0]
        mm = re.search(rf'/\* fzgx:begin {fn} noprologue \*/\n(.*?)\n/\* fzgx:end {fn} \*/', txt, re.S)
        if not mm: continue
        orig_o = pathlib.Path(f'build/GFZE01/src/{u[:-2]}.o')
        if not orig_o.exists(): continue
        osecs, osyms = pa.m.parse_elf(orig_o)
        if fn not in osyms: continue
        orelas = pa.parse_relas(orig_o)

        cleaned = clean_block_for_prologue(fn, mm.group(1), pro_incs, pro_tags, pro_tdefs, pro_exts)
        code = pro + '\n\n' + cleaned + '\n'
        comp = f'build/compilers/{mv}/mwcceppc.exe'
        with tempfile.TemporaryDirectory(prefix='fzgx_nps_') as td:
            cp, op = pathlib.Path(td)/'u.c', pathlib.Path(td)/'u.o'
            cp.write_text(code)
            cmd = [
                'build/tools/wibo', comp,
                '-c', '-nodefaults', '-proc', 'gekko', '-align', 'powerpc', '-enum', 'int', '-fp', 'hardware',
                '-Cpp_exceptions', 'off', '-O4,p', '-inline', 'auto', '-pragma', 'cats off', '-pragma', 'warn_notinlined off',
                '-nosyspath', '-RTTI', 'off', '-fp_contract', 'on', '-str', 'reuse', '-multibyte',
                '-i', 'include', '-i', 'build/GFZE01/include', '-DBUILD_VERSION=0', '-DVERSION_GFZE01', '-DNDEBUG=1',
                '-sdata', '0', '-sdata2', '0', '-lang=c',
            ] + list(cf) + ['-o', str(op), str(cp)]
            r = subprocess.run(cmd, capture_output=True, text=True)
            if r.returncode != 0: continue
            secs, syms = pa.m.parse_elf(op)
            if fn not in syms or secs.get('.text', (0,))[0] != osecs.get('.text', (0,))[0]: continue
            o_off, o_sz = osyms[fn]; n_off, n_sz = syms[fn]
            ob, nb = osecs['.text'][1][o_off:o_off+o_sz], secs['.text'][1][n_off:n_off+n_sz]
            if len(ob) != len(nb): continue
            ok = True
            for i in range(0, len(ob), 4):
                if ob[i:i+4] != nb[i:i+4]:
                    ow, nw = struct.unpack('>I', ob[i:i+4])[0], struct.unpack('>I', nb[i:i+4])[0]
                    if (ow >> 26) == 18 and (nw >> 26) == 18 and (ow & 3) == (nw & 3): continue
                    ok = False; break
            if not ok: continue

            raw_relas = pa.parse_relas(op)
            omap = {(off, rt): (sn, ra) for off, rt, sn, ra in orelas.get(fn, [])}
            pmap = {}
            for off, rt, sn, ra in raw_relas.get(fn, []):
                if LOCAL_POOL_RE.match(sn):
                    if not has_pool: ok = False; break
                    if (off, rt) not in omap: ok = False; break
                    osn, ora = omap[(off, rt)]
                    tgt = fmt_target(osn, ora - ra)
                    if tgt is None or (sn in pmap and pmap[sn] != tgt): ok = False; break
                    pmap[sn] = tgt
                else:
                    if omap.get((off, rt)) != (sn, ra): ok = False; break
            if not ok: continue

            if has_pool:
                if not pmap: continue
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
                pr = subprocess.run(['python3', 'tools/fzgx/poolfix.py', str(op), ','.join(f'{k}={v}' for k, v in sorted(pmap.items()))], capture_output=True, text=True)
                if pr.returncode != 0: continue
                # Verify zero remaining @N relocs anywhere in op!
                rr = subprocess.run(['readelf', '-r', str(op)], capture_output=True, text=True)
                if re.search(r'\s@\d+', rr.stdout): continue
                final_relas = pa.parse_relas(op)
                if final_relas.get(fn, []) != orelas.get(fn, []): continue
            else:
                # Ensure no non-empty data/rodata/bss was accidentally added if orig didn't have it
                for sec in ('.rodata', '.data', '.bss'):
                    if secs.get(sec, (0,))[0] != osecs.get(sec, (0,))[0]:
                        ok = False; break
                if not ok: continue
            hits.append((tu_path, u, fn, cleaned, pmap if has_pool else None))
    return hits

def main():
    apply = '--apply' in sys.argv
    units_path = pathlib.Path('config/GFZE01/units.json')
    units_list = json.loads(units_path.read_text())
    by_tu = {}
    for u in units_list:
        s = u['source']
        if not s.startswith('rel/') or '/data/' in s or s.startswith('rel/movie_module/'): continue
        parts = s.split('/')
        if len(parts) != 4 or len(u['symbols']) != 1: continue
        mod, tu = parts[1], parts[2]
        tu_p = f'src/rel/{mod}/{tu}.c'
        if not pathlib.Path(tu_p).exists(): continue
        by_tu.setdefault((mod, tu, tu_p), []).append((s, u['symbols'], u.get('mw_version') or 'GC/1.3.2', tuple(u.get('extra_cflags') or []), bool(u.get('pool'))))
    tasks = [(mod, tu, tu_p, lst) for (mod, tu, tu_p), lst in sorted(by_tu.items())]
    all_hits = []
    with concurrent.futures.ProcessPoolExecutor(max_workers=8) as ex:
        for res in ex.map(test_tu_nopro, tasks):
            all_hits.extend(res)
    print(f"SMART NOPROLOGUE VERIFIED {len(all_hits)} blocks ({sum(1 for h in all_hits if h[4])} pooled, {sum(1 for h in all_hits if not h[4])} unpooled)!")
    if not apply or not all_hits: return

    by_file = {}
    pmap_upd = {}
    for tu_p, u, fn, cleaned, pmap in all_hits:
        by_file.setdefault(tu_p, []).append((fn, cleaned))
        if pmap is not None: pmap_upd[u] = pmap
    for tu_p, edits in by_file.items():
        txt = pathlib.Path(tu_p).read_text()
        for fn, cleaned in edits:
            txt = re.sub(
                rf'/\* fzgx:begin {fn} noprologue \*/\n.*?\n/\* fzgx:end {fn} \*/',
                lambda m, f=fn, c=cleaned: f'/* fzgx:begin {f} */\n{c}\n/* fzgx:end {f} */',
                txt, count=1, flags=re.S
            )
        pathlib.Path(tu_p).write_text(txt)
    if pmap_upd:
        for u in units_list:
            if u['source'] in pmap_upd:
                u['pool'] = pmap_upd[u['source']]
        raw = json.dumps(units_list, indent=2) + '\n'
        raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', raw)
        units_path.write_text(raw)
    print(f"Retired {len(all_hits)} noprologue blocks across {len(by_file)} TU files!")

if __name__ == '__main__':
    main()
