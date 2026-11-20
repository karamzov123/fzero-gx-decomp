"""Prepare adjacent prologue-clean units of a TU for merging: reconcile the later unit's block
declarations against the earlier unit (drop duplicate/conflicting prototypes and externs,
retype TU-layout definitions; no cast views), accept when the merged compile keeps every
function's code and external relocations and the section sizes. Writes only block bodies;
run the consolidators afterwards and revert edits whose merge did not happen (--revert-unmerged).
Usage: merge_prep.py [--apply] | --revert-unmerged STATE.json"""
import json, re, pathlib, collections, sys, tempfile, concurrent.futures, subprocess
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, declfix, pairdiag
from fzgx import tufile

def try_pair(task):
    tu, a, b, mv, cf, pa, pb = task
    tf = tufile.parse(pathlib.Path('src', tu).read_text())
    prefix = tufile.units_gen_text(tf, a['symbols'])
    new = {}
    for fn in b['symbols']:
        blk = tf.get(fn)
        if blk is None or 'noprologue' in blk.flags: return None
        res = list(declfix.fix(prefix, blk.body, mv, cf))
        if not res: return None
        if res[0] != blk.body: new[fn] = res[0]
        blk.body = res[0]
        prefix = prefix + '\n' + blk.body
    if not new: return None
    # semantic check of the merged unit against the two current units
    pathlib.Path  # noqa
    orig = tufile.parse(pathlib.Path('src', tu).read_text())
    with tempfile.TemporaryDirectory() as td:
        objs = []
        for u, prof in ((a, pa), (b, pb)):
            o = d.compile_text(tufile.units_gen_text(orig, u['symbols']), *prof, td)
            if o is None: return None
            p = pathlib.Path(td) / (u['symbols'][0] + '.o'); p.write_bytes(o); objs.append(p)
        m = d.compile_text(tufile.units_gen_text(tf, a['symbols'] + b['symbols']), mv, cf, td)
        if m is None: return None
        mp = pathlib.Path(td) / 'm.o'; mp.write_bytes(m)
        msg, mt, mr = pairdiag.funcs(mp)
        secs = collections.Counter()
        for p in objs:
            sg, t, r = pairdiag.funcs(p)
            for f, bts in t.items():
                nb = mt.get(f)
                if nb is None or len(nb) != len(bts): return None
                for i in range(0, len(bts), 4):
                    if bts[i:i+4] != nb[i:i+4] and not (bts[i] >> 2 == 18 and nb[i] >> 2 == 18): return None
                ext = lambda rr: [x for x in rr if x[1] != 10]
                if ext(r[f]) != ext(mr[f]): return None
            for s, v in sg['sections'].items():
                if s != '.text': secs[s] += len(v) if isinstance(v, bytes) else v
        for s, n in secs.items():
            mv_ = msg['sections'].get(s); ml = len(mv_) if isinstance(mv_, bytes) else (mv_ or 0)
            if ml != n: return None
    return (tu, a['source'], b['source'], new)

def splice(txt, fn, body):
    pat = re.compile(rf'^(/\* fzgx:begin {fn}(?: [a-z]+)* \*/\n).*?^(/\* fzgx:end {fn} \*/)$', re.S | re.M)
    m = pat.search(txt); assert m, fn
    body = body if body.endswith('\n') else body + '\n'
    return txt[:m.start()] + m.group(1) + body + m.group(2) + txt[m.end():]

def main():
    state = pathlib.Path('.fzgx/merge_prep.json')
    if '--revert-unmerged' in sys.argv:
        st = json.loads(state.read_text())
        units = {u['source'] for u in json.load(open('config/GFZE01/units.json'))}
        n = 0
        for tu, asrc, bsrc, new, old in st:
            if bsrc in units:  # B still its own unit: its prepared declarations must come back
                p = pathlib.Path('src', tu); t = p.read_text()
                for fn, body in old.items(): t = splice(t, fn, body)
                p.write_text(t); n += 1
        print('reverted', n, 'of', len(st)); return
    units = json.load(open('config/GFZE01/units.json'))
    nu = d.ninja_units(); prof = {}
    for u in units:
        if u.get('tu'): prof[u['source']] = nu.get(f"build/GFZE01/gen/{u['source']}")
    by_tu = collections.defaultdict(list)
    for u in units:
        if u.get('tu') and prof.get(u['source']): by_tu[u['tu']].append(u)
    tasks = []
    for tu, us in by_tu.items():
        t = pathlib.Path('src', tu).read_text()
        pos = {m.group(1): m.start() for m in re.finditer(r'fzgx:begin (\w+)', t)}
        np_ = set(re.findall(r'fzgx:begin (\w+) noprologue', t))
        us.sort(key=lambda u: pos.get(u['symbols'][0], 0))
        for a, b in zip(us, us[1:]):
            if np_ & set(a['symbols'] + b['symbols']) or prof[a['source']] != prof[b['source']]: continue
            tasks.append((tu, a, b, *prof[a['source']], prof[a['source']], prof[b['source']]))
    hits = []
    with concurrent.futures.ProcessPoolExecutor(12) as ex:
        for r in ex.map(try_pair, tasks):
            if r: hits.append(r)
    print(len(tasks), 'pairs;', len(hits), 'prepared')
    # one edit per B unit; skip a B whose A is itself a prepared B (chains go to the next round)
    bset = set(); chosen = []
    for h in hits:
        if h[1] in bset: continue
        chosen.append(h); bset.add(h[2])
    for h in chosen[:20]: print('  ', h[0], h[2], list(h[3]))
    if '--apply' not in sys.argv: return
    st = []
    for tu, asrc, bsrc, new in chosen:
        p = pathlib.Path('src', tu); t = p.read_text(); tf = tufile.parse(t)
        old = {fn: tf.get(fn).body for fn in new}
        for fn, body in new.items(): t = splice(t, fn, body)
        p.write_text(t); st.append((tu, asrc, bsrc, new, old))
    state.write_text(json.dumps(st))
    print('applied', len(st), '(state in', state, ')')

if __name__ == '__main__':
    main()
