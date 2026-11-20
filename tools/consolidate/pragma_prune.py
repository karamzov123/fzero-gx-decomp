"""Remove optimizer pragmas that do not change any compiled unit.  Per source container, each
`#pragma KIND off|on|N` setter is tried in order together with the next `#pragma KIND reset`
after it; the removal is kept when every unit compiled from the file stays byte-identical.
Usage: pragma_prune.py [--apply] [FILE...]"""
import sys, json, re, tempfile, pathlib, collections, concurrent.futures
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d
from fzgx import tufile
KINDS = r'(?:opt_\w+|fp_contract|peephole|scheduling|optimization_level|optimize_for_size)'
SETTER = re.compile(rf'^[ \t]*#pragma\s+({KINDS})\s+(?!reset\b)\S+[ \t]*\n', re.M)

def units_of(path, units):
    rel = str(pathlib.Path(path).relative_to('src'))
    return [u for u in units if u.get('tu') == rel or (not u.get('tu') and u['source'] == rel)]

def gen(u, text):
    return tufile.units_gen_text(tufile.parse(text), u['symbols']) if u.get('tu') else text

def prune(task):
    path, us, profs = task
    text = pathlib.Path(path).read_text()
    removed = []
    with tempfile.TemporaryDirectory(prefix='pp_') as td:
        base = {}
        gens = {u['source']: gen(u, text) for u in us}
        for u in us:
            base[u['source']] = d.compile_text(gens[u['source']], *profs[u['source']], td)
        if any(v is None for v in base.values()): return (path, text, [], 'base-fail')
        pos = 0
        while True:
            m = SETTER.search(text, pos)
            if not m: break
            kind = m.group(1)
            r = re.compile(rf'^[ \t]*#pragma\s+{kind}\s+reset[ \t]*\n', re.M).search(text, m.end())
            nxt = SETTER.search(text, m.end())
            # the reset belongs to this setter only if no other setter of the same kind comes first
            while nxt and r and nxt.start() < r.start() and nxt.group(1) != kind:
                nxt = SETTER.search(text, nxt.end())
            if r and nxt and nxt.group(1) == kind and nxt.start() < r.start(): r = None
            cand = text[:m.start()] + text[m.end():r.start()] + text[r.end():] if r else text[:m.start()] + text[m.end():]
            ok = True; newg = {}
            for u in us:
                g = gen(u, cand)
                if g == gens[u['source']]: continue
                o = d.compile_text(g, *profs[u['source']], td)
                if o != base[u['source']]: ok = False; break
                newg[u['source']] = g
            if ok:
                removed.append((kind, text.count('\n', 0, m.start()) + 1, bool(r)))
                text = cand; gens.update(newg); pos = m.start()
            else:
                pos = m.end()
    return (path, text, removed, 'ok')

def main():
    units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units()
    files = [a for a in sys.argv[1:] if not a.startswith('--')]
    if not files:
        files = sorted(str(p) for p in pathlib.Path('src').glob('**/*.c') if SETTER.search(p.read_text()))
    tasks = []
    for f in files:
        us = units_of(f, units)
        if not us: continue
        profs = {}
        for u in us:
            key = f"build/GFZE01/gen/{u['source']}" if u.get('tu') else f"src/{u['source']}"
            if key in nu: profs[u['source']] = nu[key]
        us = [u for u in us if u['source'] in profs]
        if us: tasks.append((f, us, profs))
    tasks.sort(key=lambda t: -len(pathlib.Path(t[0]).read_text()))
    tot = collections.Counter(); out = []
    with concurrent.futures.ProcessPoolExecutor(12) as ex:
        for path, text, removed, st in ex.map(prune, tasks):
            if removed:
                out.append((path, text)); print(f'{len(removed):4d} {path} {st}', flush=True)
                for k, _, _ in removed: tot[k] += 1
            elif st != 'ok': print('   ', path, st)
    print('removable pragma setters:', sum(tot.values()), dict(tot))
    if '--apply' in sys.argv:
        for path, text in out: pathlib.Path(path).write_text(text)
        print('applied to', len(out), 'files')

if __name__ == '__main__':
    main()
