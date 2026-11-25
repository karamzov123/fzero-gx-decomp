#!/usr/bin/env python3
"""Replace adjacent DOL units with new per-TU sources when the old units do not follow TU boundaries.

  tu_recut.py SPEC.json

SPEC: {"old": ["dol/a.c", ...],
       "new": [{"source": "dol/x/tu.c", "candidate": "path.c", "lo": "8007A150", "hi": "8007B028",
                "version": "GC/1.3.2", "flags": ["-inline", "on,noauto"], "regions": ["GFZE01"],
                "pool": {"@1": "lbl_x"}}, ...]}

The old units must hold only .text (an old asm unit's .s is removed), and the new ranges must cover exactly their functions. Compare each
candidate with tu_regions.py first. Afterwards run `ninja build/GFZE01/config.json`, configure again,
and gate.sh: the link hash is the proof.
"""
import json, pathlib, re, shutil, sys

VERSIONS = ['GFZE01', 'GFZJ01', 'GFZP01']


def main():
    spec = json.load(open(sys.argv[1]))
    old, new = spec['old'], spec['new']
    addr = {}
    for line in open('config/GFZE01/symbols.txt'):
        m = re.match(r'(\S+) = \.text:0x(\w+); // type:function', line)
        if m:
            addr[m[1]] = int(m[2], 16)
    units = json.load(open('config/GFZE01/units.json'))
    moved = [n for u in units if u['source'] in old for n in u['symbols']]
    if len({u['source'] for u in units} & set(old)) != len(old):
        raise SystemExit('an old unit is missing')
    entries = []
    for n in new:
        lo, hi = int(n['lo'], 16), int(n['hi'], 16)
        names = sorted((s for s in moved if lo <= addr[s] < hi), key=lambda name: addr[name])
        entry = {'module': 'main', 'source': n['source'], 'symbols': names, 'status': 'matching'}
        if n.get('regions') and n['regions'] != VERSIONS:
            entry['matching_for'] = n['regions']
        entry.update(mw_version=n['version'], extra_cflags=n.get('flags', []), collapsed=True)
        if n.get('pool'):
            entry['pool'] = n['pool']
        entries.append(entry)
    if sorted(s for e in entries for s in e['symbols']) != sorted(moved):
        raise SystemExit('the new ranges do not cover the old functions')
    at = min(i for i, u in enumerate(units) if u['source'] in old)
    kept = [u for u in units[:at] if u['source'] not in old] + entries + [u for u in units[at:] if u['source'] not in old]
    raw = json.dumps(kept, indent=2) + '\n'
    raw = re.sub(r'"matching_for": \[\n\s+([^\]]+?)\n\s+\]',
                 lambda x: '"matching_for": [' + ', '.join(y.strip() for y in x[1].split(',')) + ']', raw)
    text = open('config/GFZE01/splits.txt').read()
    first = None
    for source in old:
        m = re.search(rf'^{re.escape(source)}:\n((?:\t.*\n)*)\n?', text, re.M)
        if not m or m[1].count('\n') != 1 or '.text' not in m[1]:
            raise SystemExit(f'{source}: expected one .text split')
        first = m.start() if first is None else min(first, m.start())
        text = text[:m.start()] + text[m.end():]
    blocks = ''.join(f"{n['source']}:\n\t.text       start:0x{int(n['lo'], 16):08X} end:0x{int(n['hi'], 16):08X} align:4\n\n"
                     for n in new)
    text = text[:first] + blocks + text[first:]
    open('config/GFZE01/units.json', 'w').write(raw)
    open('config/GFZE01/splits.txt', 'w').write(text)
    asm = {u['source'] for u in units if u['source'] in old and u.get('asm')}
    for source in old:
        path = pathlib.Path('src', source)
        if source in asm and not path.exists():     # asm units build from the .s beside the .c name
            path = path.with_suffix('.s')
        path.unlink()
    for n in new:
        dest = pathlib.Path('src', n['source']); dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy(n['candidate'], dest)
    print('recut', [(e['source'], len(e['symbols'])) for e in entries])


if __name__ == '__main__':
    main()
