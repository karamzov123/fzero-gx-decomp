"""Try a source rewrite against the current unit object: optionally drop the pragma setter at
--drop LINE (and its reset), apply OLD=>NEW replacements (each must occur exactly once within
the function's block), and report SAME or the per-function differing words, all regions.
Usage: trysrc.py FILE FUNC [--drop LINE] [--rep OLD NEW]... [--show]"""
import sys, re, json, tempfile, pathlib, subprocess, difflib
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, pragma_prune as pp, objsig

def main(argv):
    path, fn = argv[0], argv[1]; drop = None; reps = []; show = '--show' in argv; i = 2
    while i < len(argv):
        if argv[i] == '--drop': drop = int(argv[i + 1]); i += 2
        elif argv[i] == '--rep': reps.append((argv[i + 1].encode().decode('unicode_escape'), argv[i + 2].encode().decode('unicode_escape'))); i += 3
        else: i += 1
    text = pathlib.Path(path).read_text(); cand = text
    if drop:
        lines = cand.splitlines(keepends=True); start = sum(len(l) for l in lines[:drop - 1])
        m = pp.SETTER.match(cand, start); assert m, lines[drop - 1]
        r = re.compile(rf'^[ \t]*#pragma\s+{m.group(1)}\s+reset[ \t]*\n', re.M).search(cand, m.end())
        cand = cand[:m.start()] + cand[m.end():r.start()] + cand[r.end():] if r else cand[:m.start()] + cand[m.end():]
    bm = re.search(rf'^/\* fzgx:begin {fn}\b.*?^/\* fzgx:end {fn} \*/', cand, re.S | re.M)
    lo, hi = (bm.start(), bm.end()) if bm else (0, len(cand))
    seg = cand[lo:hi]
    for old, new in reps:
        n = seg.count(old)
        if n != 1: print(f'replacement occurs {n} times in {fn}: {old[:60]!r}'); return 2
        seg = seg.replace(old, new)
    cand = cand[:lo] + seg + cand[hi:]
    units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units()
    u = next(u for u in pp.units_of(path, units) if fn in u['symbols'])
    key = f"build/GFZE01/gen/{u['source']}" if u.get('tu') else f"src/{u['source']}"
    mv, cf = nu[key]
    with tempfile.TemporaryDirectory() as td:
        a = d.compile_all(pp.gen(u, text), mv, cf, td, u); b = d.compile_all(pp.gen(u, cand), mv, cf, td, u)
        if None in b: print('COMPILE FAIL'); return 1
        if a == b:
            print('SAME'); 
            if '--write' in argv: pathlib.Path(path).write_text(cand); print('written')
            return 0
        pa = pathlib.Path(td) / 'a.o'; pb = pathlib.Path(td) / 'b.o'; pa.write_bytes(a[0]); pb.write_bytes(b[0])
        def fx(p):
            sg = objsig.sig(p); t = sg['sections'].get('.text', b'')
            return {n: t[v:v+sz] for n, s, v, sz, _ in sg['defs'] if s == '.text' and sz}
        fa, fb = fx(pa), fx(pb)
        for f in fa:
            if fa[f] != fb.get(f):
                x, y = fa[f], fb.get(f, b'')
                w = sum(1 for k in range(0, min(len(x), len(y)), 4) if x[k:k+4] != y[k:k+4]) if len(x) == len(y) else f'size {len(x)}->{len(y)}'
                print('DIFF', f, w)
        if a[0] == b[0] and len(a) > 1: print('(other region differs)')
        if show:
            def dis(p):
                out = subprocess.run(['build/binutils/powerpc-eabi-objdump', '-dr', f'--disassemble={fn}', str(p)], capture_output=True, text=True).stdout
                body = out[out.index(f'<{fn}>'):]
                return [re.sub(r'^\s*[0-9a-f]+:\s+(?:[0-9a-f]{2} ){4}\s*', '', l) for l in body.splitlines()[1:] if l.strip()]
            for l in difflib.unified_diff(dis(pa), dis(pb), 'retail', 'candidate', n=3, lineterm=''): print(l)
        return 1

if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
