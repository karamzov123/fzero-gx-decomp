#!/usr/bin/env python3
"""Move the trailing blocks of a TU file, from FIRST to the end, into a new TU file.

  tu_split_file.py rel/story/story_mode.c fn_7_4108 story_mode_b.c [--apply]

For a draft-map TU that retail evidence shows is two TUs (a literal the compiler pools once per TU
repeated in each half, sections starting on their own alignment). The moved blocks must be whole
units. If every moved block is `noprologue`, the first block's declarations (the text before its
function definition) become the new file's prologue and the flags go: each unit compiles from the
same text as before. If none is, the old prologue is copied. Mixed flags are refused.
Updates units.json (tu, source path), splits.txt keys, tus.json and state/ledger.json unit paths.
The link hash is the proof: configure, ninja, `dtk shasum -c`.

  tu_split_file.py rel/sel/sel.c --reprologue [--apply]

In place, for a file that is one unit whose blocks are all `noprologue`: its prologue is never
compiled, so the first block's declarations replace it and the flags go (same compiled text).
"""
import json, pathlib, re, sys
sys.path.insert(0, 'tools')
from fzgx import tufile
from fzgx.project import dump_units

args = [a for a in sys.argv[1:] if not a.startswith('--')]
apply = '--apply' in sys.argv


def first_block_prologue(b0):
    """Split a self-contained block into (its declarations, its function definition onward)."""
    m = re.search(rf'^[A-Za-z_][^;{{}}\n]*\b{re.escape(b0.name)}\s*\([^;]*?\)\s*\{{', b0.body, re.M | re.S)
    if not m:
        raise SystemExit(f'no definition of {b0.name} in its block')
    return b0.body[:m.start()], b0.body[m.start():]


if '--reprologue' in sys.argv:
    (tu,) = args
    src = pathlib.Path('src', tu)
    tf = tufile.parse(src.read_text())
    units = json.loads(pathlib.Path('config/GFZE01/units.json').read_text())
    if len([u for u in units if u.get('tu') == tu and not u.get('data')]) != 1:
        raise SystemExit('not a single-unit file')
    if not all('noprologue' in b.flags for b in tf.blocks):
        raise SystemExit('a block takes the prologue')
    pro, tf.blocks[0].body = first_block_prologue(tf.blocks[0])
    tf.prologue = pro.strip('\n') + '\n'
    for b in tf.blocks:
        b.flags = [f for f in b.flags if f != 'noprologue']
    print(f'{tu}: {len(tf.blocks)} blocks take the prologue')
    if apply:
        src.write_text(tf.render())
    sys.exit()
tu, first, newname = args
module = tu.split('/')[1]
old_stem, new_stem = pathlib.Path(tu).stem, pathlib.Path(newname).stem
new_tu = str(pathlib.Path(tu).with_name(newname))
src = pathlib.Path('src', tu)
tf = tufile.parse(src.read_text())
names = [b.name for b in tf.blocks]
k = names.index(first)
moved = tf.blocks[k:]
mset = {b.name for b in moved}

units = json.loads(pathlib.Path('config/GFZE01/units.json').read_text())
tu_units = [u for u in units if u.get('tu') == tu and not u.get('data')]
mu = [u for u in tu_units if set(u['symbols']) & mset]
for u in mu:
    if not set(u['symbols']) <= mset:
        raise SystemExit(f"unit {u['source']} straddles {first}")
if not mu or len(mu) == len(tu_units):
    raise SystemExit('nothing to split')

flags = {'noprologue' in b.flags for b in moved}
if flags == {True}:
    prologue, moved[0].body = first_block_prologue(moved[0])
elif flags == {False}:
    prologue = tf.prologue
else:
    raise SystemExit('moved blocks mix noprologue and prologue blocks')
for b in moved:
    b.flags = [f for f in b.flags if f != 'noprologue']
new_tf = tufile.TuFile(prologue.strip('\n') + '\n', moved)
tf.blocks = tf.blocks[:k]

def resrc(s):
    return s.replace(f'rel/{module}/{old_stem}/', f'rel/{module}/{new_stem}/', 1)

ren = {u['source']: resrc(u['source']) for u in mu}
print('moves', len(moved), 'blocks,', len(mu), 'units:', ren)
if not apply:
    sys.exit()

pathlib.Path('src', new_tu).write_text(new_tf.render())
src.write_text(tf.render())
for u in mu:
    u['source'], u['tu'] = ren[u['source']], new_tu
pathlib.Path('config/GFZE01/units.json').write_text(dump_units(units))

sp = pathlib.Path(f'config/GFZE01/{module}/splits.txt')
st = sp.read_text()
data_lo = None
for a, b in ren.items():
    m = re.search(rf'^{re.escape(a)}:\n((?:\t.*\n)*)', st, re.M)
    if not m:
        raise SystemExit(f'no split for {a}')
    r = re.search(r'\t\.data\s+start:0x(\w+)', m[1])
    if r and data_lo is None:
        data_lo = int(r[1], 16)
    st = st.replace(f'{a}:\n', f'{b}:\n', 1)
sp.write_text(st)

lp = pathlib.Path('state/ledger.json')
lt = lp.read_text()
for a, b in ren.items():
    lt = lt.replace(f'"{a}"', f'"{b}"')
lp.write_text(lt)

tp = pathlib.Path(f'config/GFZE01/{module}/tus.json')
d = json.loads(tp.read_text())
i = next(i for i, t in enumerate(d['tus']) if t['file'] == pathlib.Path(tu).name)
e = d['tus'][i]
syms = {}
for ln in pathlib.Path(f'config/GFZE01/{module}/symbols.txt').read_text().splitlines():
    r = re.match(r'(\S+) = \.text:0x(\w+);', ln)
    if r:
        syms[r[1]] = int(r[2], 16)
j = e['functions'].index(first)
cut = syms[first]
nb = {'file': newname, 'text': [cut, e['text'][1]], 'data_sec': e.get('data_sec', 5),
      'data': [data_lo if data_lo is not None else e['data'][1], e['data'][1]], 'anchor_refs': [],
      'functions': e['functions'][j:],
      'confidence': {'text+data': len(e['functions'][j:]), 'text-range': 0, 'data-vote': 0}}
e['functions'], e['text'] = e['functions'][:j], [e['text'][0], cut]
if data_lo is not None:
    e['data'] = [e['data'][0], data_lo]
e['anchor_refs'] = [a for a in e.get('anchor_refs', []) if a < cut]
d['tus'].insert(i + 1, nb)
tp.write_text(json.dumps(d, indent=1) + '\n')
print('wrote', new_tu)
