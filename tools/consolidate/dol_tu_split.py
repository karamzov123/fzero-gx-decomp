#!/usr/bin/env python3
"""Split DOL units that cross a translation-unit boundary of the draft TU map.

Earlier consolidations merged adjacent DOL files whenever the compiled code stayed identical;
code that shares no data compiles the same in either TU, so some units now span two or more
original TUs. For a unit whose every function has a TU in state/tumap/GFZE01_main.json, owns only
.text and has no pool map, the C file is cut after the last function of each TU run:

  first piece   the file up to the end of that function;
  later piece   the file's #include lines, the earlier text with the earlier TU's own function
                definitions reduced to prototypes, then the piece's own text.

Each piece must reproduce its functions' instruction bytes and relocations, and the pieces'
.text sizes must add up, before splits.txt and units.json are rewritten.
Usage: dol_tu_split.py [--apply] [UNIT_SOURCE...]
"""
import json, re, sys, tempfile, pathlib, subprocess
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig

TUMAP = 'state/tumap/GFZE01_main.json'


def func_spans(text, name):
    m = re.search(rf'^[^\n;#]*\b{re.escape(name)}\s*\([^;{{}}]*\)\s*\{{', text, re.M)
    if not m:
        return None
    i = text.index('{', m.end() - 1); depth = 0
    for k in range(i, len(text)):
        if text[k] == '{': depth += 1
        elif text[k] == '}':
            depth -= 1
            if depth == 0:
                end = text.find('\n', k); return (m.start(), (len(text) if end < 0 else end + 1), m.group(0)[:-1].rstrip())
    return None


def protoize(text, names):
    for n in names:
        sp = func_spans(text, n)
        if sp:
            s, e, head = sp
            text = text[:s] + head + ';\n' + text[e:]
    return text


def functions_of(obj_bytes, td):
    p = pathlib.Path(td) / 'f.o'; p.write_bytes(obj_bytes); sg = objsig.sig(p)
    t = sg['sections'].get('.text', b'')
    fn = {n: (v, sz) for n, s, v, sz, _ in sg['defs'] if s == '.text' and sz}
    rel = {}
    for off, typ, nm, add in sg['relocs'].get('.text', []):
        for f, (v, sz) in fn.items():
            if v <= off < v + sz:
                rel.setdefault(f, []).append((off - v, typ, nm if typ != 10 else '<b>', add))
    secs = {k: (len(v) if isinstance(v, bytes) else v) for k, v in sg['sections'].items()}
    return {f: (t[v:v + sz], sorted(rel.get(f, []))) for f, (v, sz) in fn.items()}, secs


def plan(src, u, tu_of):
    runs = []
    for s in u['symbols']:
        t = tu_of.get(s)
        if t is None:
            return None
        if runs and runs[-1][0] == t: runs[-1][1].append(s)
        else: runs.append([t, [s]])
    return runs if len(runs) > 1 else None


def try_split(src, u, runs, mv, cf):
    text = pathlib.Path('src', src).read_text()
    incs = ''.join(l for l in text.splitlines(keepends=True) if l.startswith('#include'))
    cuts = []
    for t, syms in runs[:-1]:
        sp = func_spans(text, syms[-1])
        if not sp: return None, 'no-span'
        cuts.append(sp[1])
    if cuts != sorted(cuts): return None, 'order'
    bounds = [0] + cuts + [len(text)]
    pieces, earlier = [], []
    for k, (t, syms) in enumerate(runs):
        own = text[bounds[k]:bounds[k + 1]]
        if k == 0:
            pieces.append(own)
        else:
            pre = protoize(text[:bounds[k]], earlier)
            pre = ''.join(l for l in pre.splitlines(keepends=True) if not l.startswith('#include'))
            pieces.append(incs + pre + own)
        earlier += syms
    with tempfile.TemporaryDirectory() as td:
        base = d.compile_all(text, mv, cf, td, u)
        if None in base: return None, 'base'
        bf, bsecs = functions_of(base[0], td)
        total = 0
        for (t, syms), code in zip(runs, pieces):
            o = d.compile_all(code, mv, cf, td, u)
            if None in o: return None, f'compile {t}'
            pf, psecs = functions_of(o[0], td)
            if set(pf) != set(syms): return None, f'functions {t}: {sorted(set(pf) ^ set(syms))[:4]}'
            for s in syms:
                if pf[s] != bf[s]: return None, f'differs {s}'
            if any(v for k, v in psecs.items() if k not in ('.text', '.comment') and v): return None, f'extra sections {t}'
            total += psecs.get('.text', 0)
        if total != bsecs.get('.text', 0): return None, 'text size'
    return pieces, 'ok'


def main():
    apply = '--apply' in sys.argv
    only = [a for a in sys.argv[1:] if not a.startswith('--')]
    m = json.load(open(TUMAP)); tu_of = {f: t['file'] for t in m['tus'] for f in t['functions']}
    units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units()
    sp_text = pathlib.Path('config/GFZE01/splits.txt').read_text()
    blocks = {mm.group(1): mm.group(2) for mm in re.finditer(r'(\S+\.c):\n((?:\t.*\n)*)', sp_text)}
    syms = {}
    for l in open('config/GFZE01/symbols.txt'):
        mm = re.match(r'(\S+) = \.text:0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)', l)
        if mm: syms[mm.group(1)] = (int(mm.group(2), 16), int(mm.group(3), 16))
    done = []
    for u in units:
        if u['module'] != 'main' or u.get('data') or u.get('tu') or u.get('pool') or u.get('asm'): continue
        if only and u['source'] not in only: continue
        secs = re.findall(r'(\.\w+)\s+start', blocks.get(u['source'], ''))
        if secs != ['.text']: continue
        runs = plan(u['source'], u, tu_of)
        if not runs: continue
        key = f"src/{u['source']}"
        if key not in nu: continue
        pieces, why = try_split(u['source'], u, runs, *nu[key])
        print(f"{'OK ' if pieces else 'no '} {u['source']}: {[ (t, len(s)) for t, s in runs]} {why}")
        if pieces: done.append((u, runs, pieces))
    print('splittable', len(done))
    if not apply or not done: return
    new_units = []
    by_src = {u['source']: (runs, pieces) for u, runs, pieces in done}
    for u in units:
        if u['source'] not in by_src: new_units.append(u); continue
        runs, pieces = by_src[u['source']]
        for k, ((t, ss), code) in enumerate(zip(runs, pieces)):
            src = u['source'] if k == 0 else f"dol/{ss[0]}.c"
            assert k == 0 or not pathlib.Path('src', src).exists(), src
            pathlib.Path('src', src).write_text(code)
            nu_ = dict(u, source=src, symbols=ss)
            new_units.append(nu_)
            lo = syms[ss[0]][0]; hi = syms[ss[-1]][0] + syms[ss[-1]][1]
            block = f"{src}:\n\t.text       start:0x{lo:08X} end:0x{hi:08X} align:4\n"
            if k == 0:
                sp_text = re.sub(rf'^{re.escape(u["source"])}:\n(?:\t.*\n)*', block, sp_text, count=1, flags=re.M)
                anchor = block
            else:
                sp_text = sp_text.replace(anchor, anchor + '\n' + block, 1); anchor = block
    pathlib.Path('config/GFZE01/splits.txt').write_text(sp_text)
    raw = json.dumps(new_units, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', raw)
    pathlib.Path('config/GFZE01/units.json').write_text(raw)
    print('applied', len(done))


if __name__ == '__main__':
    main()
