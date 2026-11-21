#!/usr/bin/env python3
"""Unify compiler profiles per translation unit (DOL, draft TU map).

A retail TU was built with one compiler and one flag set. When the units of one TU carry
different `mw_version` / `extra_cflags`, try each profile already used inside that TU: if every
unit of the TU compiles byte-identically under it (all regions of its matching_for), record that
profile on all of them. Identical objects make this a pure configuration change, and uniform
profiles unblock the TU-guarded merges.
Usage: tu_profile.py [--apply]
"""
import json, re, sys, tempfile, pathlib, collections, concurrent.futures
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d


def prof(u):
    return (u.get('mw_version') or None, tuple(u.get('extra_cflags') or []))


def run(task):
    tu, us, entries = task      # entries: source -> (mv, cflags) from build.ninja
    profiles = []
    for u in us:
        p = prof(u)
        if p not in [x[0] for x in profiles]:
            profiles.append((p, entries[u['source']]))
    if len(profiles) < 2:
        return (tu, None, 'uniform')
    with tempfile.TemporaryDirectory(prefix='tup_') as td:
        texts = {u['source']: pathlib.Path('src', u['source']).read_text() for u in us}
        base = {}
        for u in us:
            base[u['source']] = d.compile_all(texts[u['source']], *entries[u['source']], td, u)
            if None in base[u['source']]:
                return (tu, None, 'base-fail')
        # profile flags differ only in the unit's extra flags; build each candidate's command
        # from a unit that already uses it
        for p, (mv, cf) in sorted(profiles, key=lambda x: -sum(1 for u in us if prof(u) == x[0])):
            ok = True
            for u in us:
                if prof(u) == p:
                    continue
                if d.compile_all(texts[u['source']], mv, cf, td, u) != base[u['source']]:
                    ok = False; break
            if ok:
                return (tu, (mv, p[1]), 'ok')   # the compiler as built, never an implicit default
    return (tu, None, 'none')


def main():
    m = json.load(open('state/tumap/GFZE01_main.json'))
    tu_of = {f: t['file'] for t in m['tus'] for f in t['functions']}
    units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units()
    by_tu = collections.defaultdict(list)
    for u in units:
        if u['module'] != 'main' or u.get('data') or u.get('asm') or u.get('tu'):
            continue
        tus = {tu_of.get(s) for s in u['symbols']} - {None}
        if len(tus) == 1 and f"src/{u['source']}" in nu:
            by_tu[tus.pop()].append(u)
    tasks = [(tu, us, {u['source']: nu[f"src/{u['source']}"] for u in us}) for tu, us in by_tu.items() if len(us) > 1]
    res = []
    with concurrent.futures.ProcessPoolExecutor(12) as ex:
        res = list(ex.map(run, tasks))
    c = collections.Counter(r[2] for r in res); print(dict(c))
    chosen = {tu: p for tu, p, st in res if st == 'ok'}
    for tu, p in list(chosen.items())[:20]: print(f'  {tu}: {p}')
    if '--apply' not in sys.argv or not chosen:
        return
    n = 0
    for u in units:
        if u['module'] != 'main' or u.get('data') or u.get('asm'):
            continue
        tus = {tu_of.get(s) for s in u['symbols']} - {None}
        if len(tus) != 1:
            continue
        p = chosen.get(next(iter(tus)))
        if p is None or (u.get('mw_version'), tuple(u.get('extra_cflags') or [])) == p:
            continue
        mv, cf = p
        u['mw_version'] = mv
        if cf: u['extra_cflags'] = list(cf)
        else: u.pop('extra_cflags', None)
        n += 1
    raw = json.dumps(units, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda mm: '"matching_for": [' + ', '.join(x.strip() for x in mm.group(1).split(',')) + ']', raw)
    pathlib.Path('config/GFZE01/units.json').write_text(raw)
    print('re-profiled units', n)


if __name__ == '__main__':
    main()
