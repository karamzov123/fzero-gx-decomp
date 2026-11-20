"""Is a pragma device really a TU-wide build flag?  For each source container (TU file or
standalone dol/ file) carrying device pragmas of a kind, strip every `#pragma KIND ...` line of
the file, add the equivalent command-line flag to every unit of the file, and report whether
all of them still compile byte-identically.  Usage: tuflag.py [--apply]"""
import sys, json, re, tempfile, pathlib, collections
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d
from fzgx import tufile
FLAGS = {'fp_contract': ['-fp_contract', 'off'], 'opt_propagation': ['-opt', 'nopropagation'],
         'opt_dead_assignments': ['-opt', 'nodeadstore'], 'opt_lifetimes': ['-opt', 'nolifetimes'],
         'opt_common_subs': ['-opt', 'nocse'], 'opt_loop_invariants': ['-opt', 'noloopinvariants']}

def main():
    units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units()
    files = collections.defaultdict(set)
    if '--all' in sys.argv:   # every REL game-code file using these pragmas, marked or not
        for p in pathlib.Path('src/rel').glob('**/*.c'):
            if 'movie_module' in str(p): continue
            for k in FLAGS:
                if re.search(rf'^[ \t]*#pragma\s+{k}\s+(off|on)\b', p.read_text(), re.M): files[str(p)].add(k)
    else:
        for p, i, opts in d.sites():
            for o in opts:
                if o in FLAGS: files[str(p)].add(o)
    results = []
    for path, kinds in sorted(files.items()):
        rel = str(pathlib.Path(path).relative_to('src')); text = pathlib.Path(path).read_text()
        us = [u for u in units if u.get('tu') == rel or (not u.get('tu') and u['source'] == rel)]
        for k in sorted(kinds):
            stripped = re.sub(rf'^[ \t]*#pragma\s+{k}\b.*\n', '', text, flags=re.M)
            ok = True
            for u in us:
                key = f"build/GFZE01/gen/{u['source']}" if u.get('tu') else f"src/{u['source']}"
                mv, cf = nu[key]
                g = (lambda t: tufile.units_gen_text(tufile.parse(t), u['symbols'])) if u.get('tu') else (lambda t: t)
                with tempfile.TemporaryDirectory() as td:
                    base = d.compile_all(g(text), mv, cf, td, u)
                    new = d.compile_all(g(stripped), mv, cf + ' ' + ' '.join(FLAGS[k]), td, u)
                if None in base or new != base: ok = False; break
            print(f"{'YES' if ok else 'no '} {path} {k} ({len(us)} units)", flush=True)
            if ok: results.append((path, k, [u['source'] for u in us]))
    json.dump(results, open('.fzgx/tuflag.json', 'w'), indent=1)

if __name__ == '__main__':
    main()
