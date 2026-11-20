"""For TU files that carry optimizer pragmas: strip every optimizer pragma, compile each unit of
the TU under each candidate compiler (and fp_contract on/off), and count units that stay
byte-identical in all their regions.  A version that keeps every unit is a whole-TU answer.
Usage: tuversion.py [FILE...]"""
import sys, re, json, tempfile, pathlib, collections, concurrent.futures
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d
from fzgx import tufile
KINDS = r'(?:opt_\w+|fp_contract|peephole|scheduling|optimization_level|optimize_for_size)'
VERS = ['GC/1.2.5n', 'GC/1.3', 'GC/1.3.2', 'GC/2.0', 'GC/2.5', 'GC/2.6', 'GC/2.7']

def run(task):
    path, u, mv, cf = task
    text = pathlib.Path(path).read_text()
    stripped = re.sub(rf'^[ \t]*#pragma\s+{KINDS}\b.*\n', '', text, flags=re.M)
    g = (lambda t: tufile.units_gen_text(tufile.parse(t), u['symbols'])) if u.get('tu') else (lambda t: t)
    res = []
    with tempfile.TemporaryDirectory() as td:
        base = d.compile_all(g(text), mv, cf, td, u)
        gs = g(stripped)
        if gs == g(text): return (path, u['source'], None)
        for v in VERS:
            for fp in ('on', 'off'):
                cf2 = re.sub(r'-fp_contract\s+\w+', f'-fp_contract {fp}', cf)
                if fp == 'off' and '-fp_contract off' not in cf2: cf2 += ' -fp_contract off'
                if d.compile_all(gs, v, cf2, td, u) == base: res.append((v, fp))
    return (path, u['source'], res)

def main():
    units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units()
    files = sys.argv[1:] or sorted(str(p) for p in pathlib.Path('src/rel').glob('**/*.c')
                                    if 'movie_module' not in str(p) and re.search(rf'#pragma\s+{KINDS}', p.read_text()))
    tasks = []
    for f in files:
        rel = str(pathlib.Path(f).relative_to('src'))
        for u in units:
            if u.get('tu') == rel or (not u.get('tu') and u['source'] == rel):
                key = f"build/GFZE01/gen/{u['source']}" if u.get('tu') else f"src/{u['source']}"
                if key in nu: tasks.append((f, u, *nu[key]))
    per = collections.defaultdict(lambda: [0, 0, collections.Counter()])
    with concurrent.futures.ProcessPoolExecutor(14) as ex:
        for path, src, res in ex.map(run, tasks, chunksize=2):
            if res is None: continue
            per[path][0] += 1
            if res: per[path][1] += 1
            for r in res: per[path][2][r] += 1
    for path, (n, ok, c) in sorted(per.items(), key=lambda x: -x[1][0]):
        best = c.most_common(1)
        print(f'{path}: {n} pragma-affected units, {ok} reproducible w/o pragmas; best {best}')

if __name__ == '__main__':
    main()
