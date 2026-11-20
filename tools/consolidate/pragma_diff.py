"""Show the disassembly diff of FUNC's unit with and without the pragma setter at FILE:LINE.
Usage: pragma_diff.py FILE LINE FUNC [--body]"""
import sys, re, json, tempfile, pathlib, subprocess, difflib
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, pragma_prune as pp
path, line, fn = sys.argv[1], int(sys.argv[2]), sys.argv[3]
text = pathlib.Path(path).read_text(); lines = text.splitlines(keepends=True)
start = sum(len(l) for l in lines[:line - 1]); m = pp.SETTER.match(text, start); assert m, lines[line - 1]
kind = m.group(1)
r = re.compile(rf'^[ \t]*#pragma\s+{kind}\s+reset[ \t]*\n', re.M).search(text, m.end())
cand = text[:m.start()] + text[m.end():r.start()] + text[r.end():] if r else text[:m.start()] + text[m.end():]
units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units()
u = next(u for u in pp.units_of(path, units) if fn in u['symbols'])
key = f"build/GFZE01/gen/{u['source']}" if u.get('tu') else f"src/{u['source']}"
mv, cf = nu[key]
def dis(t, td, tag):
    o = d.compile_text(pp.gen(u, t), mv, cf, td); p = pathlib.Path(td) / f'{tag}.o'; p.write_bytes(o)
    out = subprocess.run(['build/binutils/powerpc-eabi-objdump', '-dr', f'--disassemble={fn}', str(p)], capture_output=True, text=True).stdout
    body = out[out.index(f'<{fn}>'):]
    return [re.sub(r'^\s*[0-9a-f]+:\s+(?:[0-9a-f]{2} ){4}\s*', '', l) for l in body.splitlines()[1:] if l.strip()]
with tempfile.TemporaryDirectory() as td:
    a, b = dis(text, td, 'a'), dis(cand, td, 'b')
for l in difflib.unified_diff(a, b, 'with-pragma', 'without', n=4, lineterm=''): print(l)
