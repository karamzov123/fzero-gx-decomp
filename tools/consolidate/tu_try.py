#!/usr/bin/env python3
"""Try a hand-written translation unit against the units it replaces (DOL).

  tu_try.py CANDIDATE.c --units dol/A.c,dol/B.c,...  [--apply --as dol/os/OSAlarm.c]

Compiles CANDIDATE.c with the first unit's compiler and flags (every region in the units'
common matching_for) and the current sources of the units with their own settings, then
requires every function to have identical instruction bytes and relocations (branch targets
between the TU's own functions excepted) and no other sections beyond what the units owned.
--apply writes the candidate to --as, deletes the replaced unit sources, merges their split
ranges into one (they must be contiguous) and replaces their units.json entries with one.
"""
import json, re, sys, tempfile, pathlib, argparse, collections
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig

VERSIONS = ('GFZE01', 'GFZJ01', 'GFZP01')


def funcs(obj, td, tag):
    p = pathlib.Path(td) / f'{tag}.o'; p.write_bytes(obj); sg = objsig.sig(p)
    t = sg['sections'].get('.text', b'')
    fn = {n: (v, sz) for n, s, v, sz, _ in sg['defs'] if s == '.text' and sz}
    rel = collections.defaultdict(list)
    for off, typ, nm, add in sg['relocs'].get('.text', []):
        for f, (v, sz) in fn.items():
            if v <= off < v + sz:
                rel[f].append((off - v, typ, nm, add))
    secs = {k: (len(v) if isinstance(v, bytes) else v) for k, v in sg['sections'].items() if k != '.comment'}
    return {f: (t[v:v + sz], rel[f]) for f, (v, sz) in fn.items()}, secs


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('candidate'); ap.add_argument('--units', required=True)
    ap.add_argument('--apply', action='store_true'); ap.add_argument('--as', dest='dest')
    a = ap.parse_args()
    srcs = a.units.split(',')
    units = json.load(open('config/GFZE01/units.json')); byu = {u['source']: u for u in units}
    us = [byu[s] for s in srcs]
    nu = d.ninja_units()
    mf = [v for v in VERSIONS if all(v in (u.get('matching_for') or VERSIONS) for u in us)]
    lead = dict(us[0], matching_for=mf)
    mv, cf = nu['src/' + srcs[0]]
    own = set(s for u in us for s in u['symbols'])
    cand = pathlib.Path(a.candidate).read_text()
    ok = True
    with tempfile.TemporaryDirectory() as td:
        new = d.compile_all(cand, mv, cf, td, lead)
        if None in new:
            print('candidate does not compile'); return 1
        for vi, obj in enumerate(new):
            nf, nsecs = funcs(obj, td, f'n{vi}')
            ref, rsecs = {}, collections.Counter()
            for u in us:
                o = d.compile_all(pathlib.Path('src', u['source']).read_text(), *nu['src/' + u['source']], td, dict(u, matching_for=mf))[vi]
                f, s = funcs(o, td, 'r')
                ref.update({k: v for k, v in f.items() if k in u['symbols']}); rsecs.update(s)
            for s in sorted(own):
                if s not in nf:
                    print(f'[{mf[vi]}] missing {s}'); ok = False; continue
                (b1, r1), (b2, r2) = ref[s], nf[s]
                if len(b1) != len(b2):
                    print(f'[{mf[vi]}] {s}: size {len(b1)} -> {len(b2)}'); ok = False; continue
                words = [i for i in range(0, len(b1), 4) if b1[i:i+4] != b2[i:i+4] and not (b1[i] >> 2 == 18 and b2[i] >> 2 == 18)]
                ext = lambda r: [x for x in r if not (x[1] == 10 and x[2] in own)]
                if words or ext(r1) != ext(r2):
                    print(f'[{mf[vi]}] {s}: {len(words)} words differ; relocs {"same" if ext(r1) == ext(r2) else "differ"}'); ok = False
            extra = [f for f in nf if f not in own]
            if extra: print(f'[{mf[vi]}] extra functions {extra}'); ok = False
            for k, v in nsecs.items():
                if k != '.text' and v and v != rsecs.get(k, 0):
                    print(f'[{mf[vi]}] section {k}: {rsecs.get(k, 0)} -> {v}'); ok = False
    print('IDENTICAL' if ok else 'DIFFERENT', f'({len(own)} functions, regions {mf})')
    if not ok or not a.apply:
        return 0 if ok else 1
    dest = a.dest or srcs[0]
    sp = pathlib.Path('config/GFZE01/splits.txt'); text = sp.read_text()
    rng = []
    for s in srcs:
        m = re.search(rf'^{re.escape(s)}:\n\t\.text\s+start:0x([0-9A-F]+) end:0x([0-9A-F]+) align:4\n(?=\n|\S|$)', text, re.M)
        if not m: print('unit has non-text splits or is missing:', s); return 1
        rng.append((int(m.group(1), 16), int(m.group(2), 16), s))
    rng.sort()
    if any(x[1] != y[0] for x, y in zip(rng, rng[1:])): print('split ranges not contiguous'); return 1
    first = rng[0][2]
    for lo, hi, s in rng:
        pat = re.compile(rf'^{re.escape(s)}:\n(?:\t.*\n)*\n?', re.M)
        if s == first:
            text = pat.sub(f'{dest}:\n\t.text       start:0x{rng[0][0]:08X} end:0x{rng[-1][1]:08X} align:4\n\n', text, count=1)
        else:
            text = pat.sub('', text, count=1)
    sp.write_text(text)
    syms = [s for _, _, src in rng for s in byu[src]['symbols']]
    merged = dict(byu[first], source=dest, symbols=syms, collapsed=True)
    merged['mw_version'] = mv
    if mf != list(VERSIONS): merged['matching_for'] = mf
    else: merged.pop('matching_for', None)
    out = []
    for u in units:
        if u['source'] in srcs:
            if u['source'] == first: out.append(merged)
            continue
        out.append(u)
    raw = json.dumps(out, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', raw)
    pathlib.Path('config/GFZE01/units.json').write_text(raw)
    for s in srcs:
        pathlib.Path('src', s).unlink()
    pathlib.Path('src', dest).parent.mkdir(parents=True, exist_ok=True)
    pathlib.Path('src', dest).write_text(cand)
    print('applied as', dest)
    return 0


if __name__ == '__main__':
    sys.exit(main())
