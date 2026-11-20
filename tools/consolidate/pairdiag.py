"""For adjacent prologue-clean units of one TU that are still separate, compile them merged
(prologue + both units' blocks, first unit's profile) and classify the first failure."""
import json, re, pathlib, collections, sys, tempfile, struct, concurrent.futures
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig
from fzgx import tufile

def funcs(path):
    sg = objsig.sig(path)
    text = sg['sections'].get('.text', b'')
    fn = {n: (v, sz) for n, sec, v, sz, b in sg['defs'] if sec == '.text' and sz}
    rel = collections.defaultdict(list)
    for off, t, n, a in sg['relocs'].get('.text', []):
        for f, (v, sz) in fn.items():
            if v <= off < v + sz: rel[f].append((off - v, t, n if not re.match(r'^(@\d+|\.\w+|\.\.\.)', n) else '<local>', a if not re.match(r'^(@\d+|\.\w+|\.\.\.)', n) else 0))
    return sg, {f: text[v:v + sz] for f, (v, sz) in fn.items()}, rel

def diag(task):
    tu, a, b, mv, cf, pa, pb = task
    prof = {a['source']: pa, b['source']: pb}
    tf = tufile.parse(pathlib.Path('src', tu).read_text())
    with tempfile.TemporaryDirectory() as td:
        objs = []
        for u in (a, b):
            o = d.compile_text(tufile.units_gen_text(tf, u['symbols']), *prof[u['source']], td)
            if o is None: return 'base-fail'
            p = pathlib.Path(td) / (u['source'].split('/')[-1] + '.o'); p.write_bytes(o); objs.append(p)
        m = d.compile_text(tufile.units_gen_text(tf, a['symbols'] + b['symbols']), mv, cf, td)
        if m is None: return 'merged-compile-fail'
        mp = pathlib.Path(td) / 'm.o'; mp.write_bytes(m)
        msg, mt, mr = funcs(mp)
        secs = collections.Counter()
        for p in objs:
            sg, t, r = funcs(p)
            for f, bts in t.items():
                nb = mt.get(f)
                if nb is None: return 'missing-fn'
                if len(nb) != len(bts): return 'text-size'
                for i in range(0, len(bts), 4):
                    if bts[i:i+4] != nb[i:i+4] and not (bts[i] >> 2 == 18 and nb[i] >> 2 == 18):
                        return 'text-bytes'
                ext = lambda rr: [x for x in rr if not (x[1] == 10)]
                if ext(r[f]) != ext(mr[f]): return 'relocs'
            for s, v in sg['sections'].items():
                if s != '.text': secs[s] += len(v) if isinstance(v, bytes) else v
        for s, n in secs.items():
            mv_ = msg['sections'].get(s); ml = len(mv_) if isinstance(mv_, bytes) else (mv_ or 0)
            if ml != n: return f'section-size {s}'
        return 'OK-merged-equal (consolidator restriction)'

nu_lookup = {}
def main():
    units = json.load(open('config/GFZE01/units.json'))
    nu = d.ninja_units()
    for u in units:
        if u.get('tu'): nu_lookup[u['source']] = nu.get(f"build/GFZE01/gen/{u['source']}")
    by_tu = collections.defaultdict(list)
    for u in units:
        if u.get('tu') and nu_lookup.get(u['source']): by_tu[u['tu']].append(u)
    tasks = []
    for tu, us in by_tu.items():
        t = pathlib.Path('src', tu).read_text()
        pos = {m.group(1): m.start() for m in re.finditer(r'fzgx:begin (\w+)', t)}
        np = set(re.findall(r'fzgx:begin (\w+) noprologue', t))
        us.sort(key=lambda u: pos.get(u['symbols'][0], 0))
        for a, b in zip(us, us[1:]):
            if np & set(a['symbols'] + b['symbols']): continue
            if nu_lookup[a['source']] != nu_lookup[b['source']]: continue
            tasks.append((tu, a, b, *nu_lookup[a['source']], nu_lookup[a['source']], nu_lookup[b['source']]))
    c = collections.Counter(); ex_ = collections.defaultdict(list)
    with concurrent.futures.ProcessPoolExecutor(12) as ex:
        for t, r in zip(tasks, ex.map(diag, tasks)):
            c[r] += 1; ex_[r].append(f"{t[0]}:{t[1]['symbols'][-1]}|{t[2]['symbols'][0]}")
    for k, v in c.most_common(): print(v, k, ex_[k][:3])
    json.dump(ex_, open(sys.argv[1] if len(sys.argv) > 1 else '/dev/null', 'w'), indent=1)

if __name__ == '__main__':
    main()
