#!/usr/bin/env python3
"""Extend the draft DOL TU map over the GX library's unassigned functions.

The ranges follow the Dolphin SDK's GX file order, anchored by functions the map already places
and by what the newly assigned functions do:
  GXFifo      ends with the __GXFifo*/__GXWriteFifoInt* helpers and the two FIFO getters
  GXMisc      starts at GXSetMisc and GXFlush, ends before the dirty-state flush GXFlush calls
  GXGeometry  starts at that dirty-state flush (fn_8003458C), followed by the primitive setup
  GXLight     starts at the spot-light setup fn_80035420, ends with the channel setters
  GXPixel     starts at GXSetFog (fn_800377F8), which precedes GXSetFogRangeAdj
  GXPerf      starts at GXSetGPMetric
A function already mapped to another TU is an error. Usage: tumap_gx.py [--apply]
"""
import json, pathlib, re, sys

MAP = pathlib.Path('state/tumap/GFZE01_main.json')
RANGES = {
    'GXInit.c': (0x800307CC, 0x80031B50), 'GXFifo.c': (0x80031B50, 0x80032370),
    'GXAttr.c': (0x80032370, 0x80033D8C), 'GXMisc.c': (0x80033D8C, 0x8003458C),
    'GXGeometry.c': (0x8003458C, 0x8003493C), 'GXFrameBuf.c': (0x8003493C, 0x80035420),
    'GXLight.c': (0x80035420, 0x80035A2C), 'GXTexture.c': (0x80035A2C, 0x80036A28),
    'GXBump.c': (0x80036A28, 0x80037014), 'GXTev.c': (0x80037014, 0x800377F8),
    'GXPixel.c': (0x800377F8, 0x80037E30), 'GXDraw.c': (0x80037E30, 0x80038878),
    'GXStubs.c': (0x80038878, 0x8003887C), 'GXDisplayList.c': (0x8003887C, 0x80038A88),
    'GXTransform.c': (0x80038A88, 0x8003910C),
    'GXPerf.c': (0x8003910C, 0x80039C40),
}


def main():
    m = json.loads(MAP.read_text())
    syms = {}
    for line in open('config/GFZE01/symbols.txt'):
        x = re.match(r'(\S+) = \.text:0x(\w+); // type:function size:0x(\w+)', line)
        if x:
            syms[x[1]] = (int(x[2], 16), int(x[3], 16))
    placed = {f: t['file'] for t in m['tus'] for f in t['functions']}
    by_file = {t['file']: t for t in m['tus']}
    added = 0
    for file, (lo, hi) in RANGES.items():
        if file not in by_file:
            t = {'file': file, 'text': [f'{lo:08X}', f'{hi:08X}'], 'functions': [], 'how': {}, 'lib': 'gx'}
            m['tus'].append(t)
            by_file[file] = t
            m['summary']['tus'] = len(m['tus'])
        t = by_file[file]
        inside = sorted((a, n) for n, (a, _) in syms.items() if lo <= a < hi)
        wrong = [n for _, n in inside if placed.get(n, file) != file]
        lost = [f for f in t['functions'] if not lo <= syms[f][0] < hi]
        if wrong or lost:
            sys.exit(f'{file}: other TU owns {wrong}; outside the range {lost}')
        new = [n for _, n in inside if n not in placed]
        if new:
            t['how']['sdk-order'] = t['how'].get('sdk-order', 0) + len(new)
            added += len(new)
        t['functions'] = [n for _, n in inside]
        t['text'] = [f'{lo:08X}', f'{hi:08X}']
    m['tus'].sort(key=lambda t: int(t['text'][0], 16))
    now = {f for t in m['tus'] for f in t['functions']}
    moved = [u for u in m['unassigned'] if u['name'] in now]
    m['unassigned'] = [u for u in m['unassigned'] if u['name'] not in now]
    m['summary']['assigned'] += added
    m['summary']['assigned_bytes'] += sum(u['size'] for u in moved)
    print(f'{added} functions assigned; {m["summary"]["assigned"]}/{m["summary"]["functions"]}')
    if '--apply' in sys.argv:
        MAP.write_text(json.dumps(m, indent=1) + '\n')


if __name__ == '__main__':
    main()
