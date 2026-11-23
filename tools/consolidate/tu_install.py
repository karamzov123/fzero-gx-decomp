#!/usr/bin/env python3
"""Replace adjacent DOL units with one verified source file.

  tu_install.py DEST CANDIDATE --units A,B,... --regions GFZE01,GFZJ01 [--version GC/1.3.2]
                [--cflags "-inline on,noauto"] [--pool @1=lbl_x,@2=lbl_y]

Use this after comparing CANDIDATE with retail when tu_try.py cannot express a unit's pool
selectors. Split ranges must be contiguous per section. Afterwards run
`ninja build/GFZE01/config.json`, configure again, and gate.sh: the link hash is the proof.
"""
import argparse, json, pathlib, re

ap = argparse.ArgumentParser()
ap.add_argument('dest'); ap.add_argument('candidate'); ap.add_argument('--units', required=True)
ap.add_argument('--regions', required=True); ap.add_argument('--version', default='GC/1.3.2')
ap.add_argument('--cflags', default=''); ap.add_argument('--pool', default='')
a = ap.parse_args()
srcs = a.units.split(',')
text = open('config/GFZE01/splits.txt').read(); secs = {}
for s in srcs:
    m = re.search(rf'^{re.escape(s)}:\n((?:\t.*\n)*)', text, re.M)
    if not m:
        raise SystemExit(f'no split for {s}')
    for line in m[1].splitlines():
        r = re.match(r'\t(\.\w+)\s+start:0x(\w+) end:0x(\w+)(?: align:(\d+))?', line)
        secs.setdefault(r[1], []).append((int(r[2], 16), int(r[3], 16), r[4]))
lines = ''
for name, rows in secs.items():
    rows.sort()
    if any(x[1] != y[0] for x, y in zip(rows, rows[1:])):
        raise SystemExit(f'{name} ranges are not contiguous')
    al = max((int(x[2]) for x in rows if x[2]), default=None)
    lines += f'\t{name:<11} start:0x{rows[0][0]:08X} end:0x{rows[-1][1]:08X}' + (f' align:{al}' if al else '') + '\n'
first = min(srcs, key=lambda s: secs['.text'] and min(
    int(x, 16) for x in re.findall(r'\.text\s+start:0x(\w+)', re.search(rf'^{re.escape(s)}:\n((?:\t.*\n)*)', text, re.M)[1])))
for s in sorted(srcs, key=lambda x: x == first):
    text = re.sub(rf'^{re.escape(s)}:\n(?:\t.*\n)*\n?', f'{a.dest}:\n{lines}\n' if s == first else '', text, count=1, flags=re.M)
units = json.load(open('config/GFZE01/units.json')); by = {u['source']: u for u in units}
merged = {'module': 'main', 'source': a.dest, 'symbols': [x for s in srcs for x in by[s]['symbols']], 'status': 'matching'}
regions = a.regions.split(',')
if len(regions) < 3:
    merged['matching_for'] = regions
merged.update(mw_version=a.version, extra_cflags=a.cflags.split(), collapsed=True)
if a.pool:
    merged['pool'] = dict(x.split('=') for x in a.pool.split(','))
out = []
for u in units:
    if u['source'] == first:
        out.append(merged)
    elif u['source'] not in srcs:
        out.append(u)
raw = json.dumps(out, indent=2) + '\n'
raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]', lambda m: '"matching_for": [' + ', '.join(x.strip() for x in m[1].split(',')) + ']', raw)
candidate = pathlib.Path(a.candidate).read_text()
open('config/GFZE01/splits.txt', 'w').write(text); open('config/GFZE01/units.json', 'w').write(raw)
for s in srcs:
    pathlib.Path('src', s).unlink()
dest = pathlib.Path('src', a.dest); dest.parent.mkdir(parents=True, exist_ok=True); dest.write_text(candidate)
print('installed', a.dest, len(merged['symbols']), 'functions')
