"""Rank optimizer-pragma setters by how much code changes without them: for each setter (and its
reset), compile the affected units (GFZE01) and count differing .text words per function.
Usage: pragma_rank.py OUT.json [FILE...]"""
import sys, re, json, tempfile, pathlib, collections, concurrent.futures
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig, pragma_prune as pp
from fzgx import tufile

def funcs(o, td):
    p = pathlib.Path(td) / 'r.o'; p.write_bytes(o); sg = objsig.sig(p)
    text = sg['sections'].get('.text', b'')
    return {n: text[v:v+sz] for n, sec, v, sz, b in sg['defs'] if sec == '.text' and sz}

def run(task):
    path, us, profs = task
    text = pathlib.Path(path).read_text(); out = []
    with tempfile.TemporaryDirectory(prefix='pr_') as td:
        base = {}; gens = {}
        for u in us:
            gens[u['source']] = pp.gen(u, text)
            o = d.compile_text(gens[u['source']], *profs[u['source']], td)
            if o is None: return []
            base[u['source']] = funcs(o, td)
        for m in pp.SETTER.finditer(text):
            kind = m.group(1)
            r = re.compile(rf'^[ \t]*#pragma\s+{kind}\s+reset[ \t]*\n', re.M).search(text, m.end())
            cand = text[:m.start()] + text[m.end():r.start()] + text[r.end():] if r else text[:m.start()] + text[m.end():]
            line = text.count('\n', 0, m.start()) + 1
            diffs = {}
            for u in us:
                g = pp.gen(u, cand)
                if g == gens[u['source']]: continue
                o = d.compile_text(g, *profs[u['source']], td)
                if o is None: diffs['<compile-fail>'] = 9999; continue
                nf = funcs(o, td)
                for f, b in base[u['source']].items():
                    nb = nf.get(f, b'')
                    if nb == b: continue
                    if len(nb) != len(b): diffs[f] = 1000 + abs(len(nb) - len(b)) // 4
                    else: diffs[f] = sum(1 for i in range(0, len(b), 4) if b[i:i+4] != nb[i:i+4])
            out.append((path, line, m.group(0).strip(), diffs))
    return out

def main():
    units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units()
    files = sys.argv[2:] or sorted(str(p) for p in pathlib.Path('src/rel').glob('**/*.c')
                                    if 'movie_module' not in str(p) and pp.SETTER.search(p.read_text()))
    tasks = []
    for f in files:
        us = [u for u in pp.units_of(f, units)]
        profs = {}
        for u in us:
            key = f"build/GFZE01/gen/{u['source']}" if u.get('tu') else f"src/{u['source']}"
            if key in nu: profs[u['source']] = nu[key]
        us = [u for u in us if u['source'] in profs]
        if us: tasks.append((f, us, profs))
    tasks.sort(key=lambda t: -len(pathlib.Path(t[0]).read_text()))
    res = []
    with concurrent.futures.ProcessPoolExecutor(14) as ex:
        for r in ex.map(run, tasks): res.extend(r)
    json.dump(res, open(sys.argv[1], 'w'), indent=0)
    tot = [(sum(dd.values()), p, l, s, dd) for p, l, s, dd in res]
    tot.sort()
    hist = collections.Counter(min(t[0], 50) // 5 * 5 for t in tot)
    print('setters', len(tot), 'diff-word histogram (bucket:count)', sorted(hist.items()))
    for t in tot[:40]: print(t[0], t[1], t[2], t[3], dict(list(t[4].items())[:3]))

if __name__ == '__main__':
    main()
