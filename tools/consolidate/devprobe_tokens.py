"""Probe token-level compiler-diff devices: drop `volatile` on the marker line and the two lines
after it, or unwrap one-member carriers `struct { T value; } x;` (and `x.value` uses in the
enclosing block), and report whether the owning unit's object is byte-identical."""
import re, sys, pathlib, tempfile, json, concurrent.futures
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d
from fzgx import tufile

def variants(text, i):
    lines = text.splitlines(keepends=True)
    seg = ''.join(lines[i:i + 3])
    if 'volatile' in seg:
        new = re.sub(r'\bvolatile\s*', '', seg)
        yield 'volatile', ''.join(lines[:i]) + new + ''.join(lines[i + 3:])
    for j in range(i, min(i + 5, len(lines))):
        for m in re.finditer(r'struct \{ *([A-Za-z_][\w ]*?\**) *value; *\} *(\w+);', lines[j]):
            t, name = m.group(1), m.group(2)
            nl = list(lines)
            nl[j] = nl[j].replace(m.group(0), f'{t} {name};', 1)
            rest = ''.join(nl[j + 1:])
            rest = re.sub(rf'\b{name}\.value\b', name, rest)
            yield f'carrier {name}', ''.join(nl[:j + 1]) + rest

def run(task):
    p, i, kind, unit, mv, cf = task
    text = p.read_text()
    def gen(t):
        return t if kind == 'file' else tufile.units_gen_text(tufile.parse(t), unit['symbols'])
    out = []
    with tempfile.TemporaryDirectory(prefix='dpt_') as td:
        base = d.compile_text(gen(text), mv, cf, td)
        for label, v in variants(text, i):
            o = d.compile_text(gen(v), mv, cf, td)
            out.append((label, 'SAME' if o == base else ('fail' if o is None else 'diff')))
    return (str(p), i + 1, out)

def main():
    units = json.load(open('config/GFZE01/units.json'))
    by_tu, by_src = {}, {}
    for u in units:
        (by_tu.setdefault(u['tu'], []).append(u)) if u.get('tu') else by_src.__setitem__(u['source'], u)
    nu = d.ninja_units(); tasks = []
    for p in sorted(pathlib.Path('src').glob('**/*.c')):
        lines = p.read_text().splitlines()
        for i, ln in enumerate(lines):
            if not d.MARK.search(ln): continue
            seg = '\n'.join(lines[i:i + 5])
            if 'volatile' not in '\n'.join(lines[i:i + 3]) and 'value; }' not in seg: continue
            r = d.unit_for(p, i, by_tu, by_src)
            if not r: continue
            kind, u = r[0], r[1]
            key = f"build/GFZE01/gen/{u['source']}" if kind == 'tu' else f"src/{u['source']}"
            if key in nu: tasks.append((p, i, kind, u, *nu[key]))
    with concurrent.futures.ProcessPoolExecutor(8) as ex:
        for r in ex.map(run, tasks): print(*r, flush=True)

if __name__ == '__main__':
    main()
