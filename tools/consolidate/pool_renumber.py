"""Re-key units.json pool maps after a source edit renumbered MWCC's private @N literals.
For each pool-mapped unit whose source changed against git HEAD, compile both versions
(GFZE01 flags), match local literal symbols by (section, offset, size), and rename the map keys.
Usage: pool_renumber.py [--apply]"""
import sys, json, re, subprocess, tempfile, pathlib
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig
from fzgx import tufile

def locs(obj, td):
    p = pathlib.Path(td) / 'x.o'; p.write_bytes(obj)
    return {n: (s, v, sz) for n, s, v, sz, b in objsig.sig(p)['defs'] if re.match(r'^@\d+$', n)}

def main():
    raw = pathlib.Path('config/GFZE01/units.json').read_text(); units = json.loads(raw); nu = d.ninja_units()
    changed = set(subprocess.run(['git', 'diff', '--name-only', '--', 'src'], capture_output=True, text=True).stdout.split())
    edits = 0
    for u in units:
        if not isinstance(u.get('pool'), dict): continue
        src = 'src/' + (u.get('tu') or u['source'])
        if src not in changed: continue
        key = f"build/GFZE01/gen/{u['source']}" if u.get('tu') else f"src/{u['source']}"
        mv, cf = nu[key]
        g = (lambda t: tufile.units_gen_text(tufile.parse(t), u['symbols'])) if u.get('tu') else (lambda t: t)
        old = subprocess.run(['git', 'show', 'HEAD:' + src], capture_output=True, text=True).stdout
        with tempfile.TemporaryDirectory() as td:
            a = d.compile_text(g(old), mv, cf, td); la = locs(a, td)
            b = d.compile_text(g(pathlib.Path(src).read_text()), mv, cf, td); lb = locs(b, td)
        inv = {v: k for k, v in lb.items()}
        new = {}
        for k, v in u['pool'].items():
            if k in la and la[k] in inv: new[inv[la[k]]] = v
            else: new[k] = v
        if new != u['pool']:
            print(u['source'], {k: n for k, n in zip(u['pool'], new)})
            u['pool'] = new; edits += 1
    if edits and '--apply' in sys.argv:
        out = json.dumps(units, indent=2) + '\n'
        out = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', out)
        pathlib.Path('config/GFZE01/units.json').write_text(out)
    print('re-keyed units', edits)

if __name__ == '__main__':
    main()
