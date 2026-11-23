#!/usr/bin/env python3
"""Map the sasnd (Ver 1.13h) TUs of the DOL in state/tumap/GFZE01_main.json.

No retail string names these files, so the names are descriptive placeholders. Boundaries come
from data that a single TU could not have laid out: MWCC deduplicates literals per TU, so a value
repeated in .sdata2 or a table repeated in .rodata separates two TUs, and each TU's contribution
to a section is contiguous. Functions in the bands no evidence bounds stay unassigned:
0x80063EF4..0x800658B4, between the effect routine and the loader.

Usage: tumap_sasnd.py [--apply]
"""
import json, pathlib, re, sys

MAP = pathlib.Path('state/tumap/GFZE01_main.json')
RANGES = [
    ('sasnd_voice.c', 0x8005C298, 0x8006060C,
     '.sdata2 0x801A7218..0x801A7280 and .rodata 0x800929D8..0x80092B38. The pitch table at 0x800929D8 '
     'is repeated at 0x80092B38 by the next TU. 0x8005FBDC..0x8006060C hold no literals: they are placed '
     'here because the next TU\'s track array is first used at 0x8006060C.'),
    ('sasnd_track.c', 0x8006060C, 0x8006331C,
     'Every user of the 0x540-byte track array 0x80192D68 lies in this range. .sdata2 0x801A7280..0x801A7318 '
     'repeats the previous TU\'s literals.'),
    ('sasnd_fx.c', 0x8006331C, 0x80063EF4,
     '.sdata2 0x801A7318..0x801A7328 repeats the 2^52 conversion constant. It addresses the effect work areas at '
     '.bss 0x801932A8..0x80193B08 one symbol at a time, as externs of sasnd_core.c. The end of the TU is not bounded by data.'),
    ('sasnd_core.c', 0x800658B4, 0x80069B10,
     'Owns .bss 0x801932A8..0x80199670 and .sbss 0x801A6C78..0x801A6C88: 0x80067DE4 addresses the effect work areas off one '
     'section base, and 0x80068BFC initializes the state at 0x801A6C80 from .bss 0x80193B48. .rodata runs version string, loader '
     'strings, 0x80092C38 table (0x8006953C), wave table, so 0x80065F34..0x80069AE0 is one contribution. '
     '.sdata2 0x801A7328..0x801A7350.'),
    ('sasnd_mix.c', 0x80069B10, 0x8006A3DC,
     '.sdata2 0x801A7350..0x801A7370 repeats 20.0, 255.0, -960.0, 127.0, 10.0 and 2^52 from the earlier TUs. '
     '0x80069B10 and 0x80069FCC are called only by 0x80069CE4. Ends at arc.c.'),
]


def main():
    m = json.loads(MAP.read_text())
    syms = {}
    for line in open('config/GFZE01/symbols.txt'):
        x = re.match(r'(\S+) = \.text:0x(\w+); // type:function size:0x(\w+)', line)
        if x:
            syms[x[1]] = (int(x[2], 16), int(x[3], 16))
    files = {r[0] for r in RANGES}
    tus = [t for t in m['tus'] if t['file'] not in files]
    placed = {f for t in tus for f in t['functions']}
    for file, lo, hi, notes in RANGES:
        names = [n for a, n in sorted((a, n) for n, (a, _) in syms.items() if lo <= a < hi)]
        assert names and not placed & set(names), file
        assert sum(syms[n][1] for n in names) == hi - lo, f'{file}: range has gaps'
        tus.append({'file': file, 'text': [f'{lo:08X}', f'{hi:08X}'], 'functions': names,
                    'how': {'literal-dedupe+section-order': len(names)}, 'lib': 'sasnd', 'notes': notes})
        placed |= set(names)
    tus.sort(key=lambda t: int(t['text'][0], 16))
    m['tus'] = tus
    m['unassigned'] = [u for u in m['unassigned'] if u['name'] not in placed]
    m['summary'].update(assigned=len(placed), tus=len(tus),
                        assigned_bytes=sum(syms[f][1] for f in placed if f in syms))
    s = m['summary']
    print(f"{s['assigned']}/{s['functions']} functions, {s['assigned_bytes']}/{s['bytes']} B "
          f"({100 * s['assigned_bytes'] / s['bytes']:.1f}%), {s['tus']} TUs, {len(m['unassigned'])} unassigned")
    if '--apply' in sys.argv:
        MAP.write_text(json.dumps(m, indent=2) + '\n')


if __name__ == '__main__':
    main()
