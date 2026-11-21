#!/usr/bin/env python3
"""Extend the DOL TU map over donor-verified axfx, mix, axart, MSL_C, MetroTRK, and GDEV ranges.

Evidence:
- Dolphin axfx (matched against sonicheroes/src/dolphin/axfx/):
  * reverb_hi.c  (0x80023684..0x800244C8): ReverbHICreate..AXFXReverbHiCallback (7 fns)
  * reverb_std.c (0x800244C8..0x80024E6C): ReverbSTDCreate..AXFXReverbStdCallback (6 fns)
  * chorus.c     (0x80024E6C..0x80025854): do_src1..AXFXChorusCallback (6 fns)
  * delay.c      (0x80025854..0x80025D00): AXFXDelayCallback..AXFXDelayShutdown (4 fns)
  * axfx.c       (0x80025D00..0x80025D5C): __AXFXAllocFunction, __AXFXFreeFunction, AXFXSetHooks (3 fns, exact 92 B)
- Dolphin mix / axart:
  * mix.c        (0x80025D5C..0x8002805C): includes MIXInit (0x80025E18)
  * axart.c      (0x8002805C..0x800288C4): AXART runtime (17 fns)
  * axartcents.c (0x800288C4..0x800289C0): AXARTCents (1200 cents/octave table lookup)
- MSL_C (matched against mkdd/sonicheroes):
  * pool_alloc.c (0x8007A710..0x8007B124): MSL allocator pool between alloc.c and ansi_files.c (8 fns)
  * s_sin.c      (0x800883E8..0x800884C0): exact 216 B match to mkdd
  * s_tan.c      (0x800884C0..0x80088538): exact 120 B match to mkdd
  * w_asin.c     (0x80088538..0x80088558): 32 B wrapper
  * w_atan2.c    (0x80088558..0x80088578): 32 B wrapper
  * w_exp.c      (0x80088578..0x80088598): 32 B wrapper
  * w_pow.c      (0x80088598..0x800885B8): 32 B wrapper
  * math_ppc.c   (0x800885B8..0x80088624): powf/tanf/sinf float wrappers (3 x 36 B)
- MetroTRK / GDEV (matched against sonicheroes/mkdd):
  * support.c                (0x8008A5AC..0x8008AF40): TRK support (14 fns)
  * mutex_TRK.c              (0x8008AF40..0x8008AF58): exact 24 B (3 x 8 B)
  * notify.c                 (0x8008AF58..0x8008AFF0): TRKDoNotifyStopped (152 B)
  * flush_cache.c            (0x8008AFF0..0x8008B028): TRK_flush_cache (exact 56 B)
  * MWCriticalSection_gc.cpp (0x8008E718..0x8008E770): exact 88 B (36 + 48 + 4 B)

Usage: tumap_expand.py [--apply]
"""
import json, pathlib, re, sys

MAP = pathlib.Path('state/tumap/GFZE01_main.json')

RANGES = [
    # Dolphin axfx
    ('reverb_hi.c', 'axfx', 0x80023684, 0x800244C8, 'sdk-order'),
    ('reverb_std.c', 'axfx', 0x800244C8, 0x80024E6C, 'sdk-order'),
    ('chorus.c', 'axfx', 0x80024E6C, 0x80025854, 'sdk-order'),
    ('delay.c', 'axfx', 0x80025854, 0x80025D00, 'sdk-order'),
    ('axfx.c', 'axfx', 0x80025D00, 0x80025D5C, 'sdk-order'),
    # Dolphin mix / axart
    ('mix.c', 'mix', 0x80025D5C, 0x8002805C, 'sdk-order'),
    ('axart.c', 'axart', 0x8002805C, 0x800288C4, 'sdk-order'),
    ('axartcents.c', 'axart', 0x800288C4, 0x800289C0, 'sdk-order'),
    # MSL_C
    ('pool_alloc.c', 'runtime', 0x8007A710, 0x8007B124, 'sdk-order'),
    ('s_sin.c', 'runtime', 0x800883E8, 0x800884C0, 'sdk-order'),
    ('s_tan.c', 'runtime', 0x800884C0, 0x80088538, 'sdk-order'),
    ('w_asin.c', 'runtime', 0x80088538, 0x80088558, 'sdk-order'),
    ('w_atan2.c', 'runtime', 0x80088558, 0x80088578, 'sdk-order'),
    ('w_exp.c', 'runtime', 0x80088578, 0x80088598, 'sdk-order'),
    ('w_pow.c', 'runtime', 0x80088598, 0x800885B8, 'sdk-order'),
    ('math_ppc.c', 'runtime', 0x800885B8, 0x80088624, 'sdk-order'),
    # MetroTRK / GDEV
    ('support.c', 'trk', 0x8008A5AC, 0x8008AF40, 'sdk-order'),
    ('mutex_TRK.c', 'trk', 0x8008AF40, 0x8008AF58, 'sdk-order'),
    ('notify.c', 'trk', 0x8008AF58, 0x8008AFF0, 'sdk-order'),
    ('flush_cache.c', 'trk', 0x8008AFF0, 0x8008B028, 'sdk-order'),
    ('MWCriticalSection_gc.cpp', 'trk', 0x8008E718, 0x8008E770, 'sdk-order'),
]


def main():
    m = json.loads(MAP.read_text())
    syms = {}
    for line in open('config/GFZE01/symbols.txt'):
        x = re.match(r'(\S+) = \.text:0x(\w+); // type:function size:0x(\w+)', line)
        if x:
            syms[x[1]] = (int(x[2], 16), int(x[3], 16))
    by_file = {}
    for t in m['tus']:
        by_file.setdefault(t['file'], t)
    placed = {f: t['file'] for t in m['tus'] for f in t['functions']}
    added = 0
    for file, lib, lo, hi, tag in RANGES:
        if file not in by_file:
            t = {'file': file, 'text': [f'{lo:08X}', f'{hi:08X}'], 'functions': [], 'how': {}, 'lib': lib}
            m['tus'].append(t)
            by_file[file] = t
        t = by_file[file]
        inside = sorted((a, n) for n, (a, _) in syms.items() if lo <= a < hi)
        wrong = [n for _, n in inside if placed.get(n, file) != file]
        lost = [f for f in t['functions'] if not lo <= syms[f][0] < hi]
        if wrong or lost:
            sys.exit(f'{file}: other TU owns {wrong}; outside the range {lost}')
        new = [n for _, n in inside if n not in placed]
        if new:
            t['how'][tag] = t['how'].get(tag, 0) + len(new)
            added += len(new)
        t['functions'] = [n for _, n in inside]
        t['text'] = [f'{lo:08X}', f'{hi:08X}']
        t['lib'] = lib
        for n in t['functions']:
            placed[n] = file
    m['tus'].sort(key=lambda t: int(t['text'][0], 16))
    m['unassigned'] = [u for u in m['unassigned'] if u['name'] not in placed]
    assigned_bytes = sum(syms[f][1] for f in placed if f in syms)
    m['summary']['assigned'] = len(placed)
    m['summary']['assigned_bytes'] = assigned_bytes
    m['summary']['tus'] = len(m['tus'])
    pct = 100.0 * assigned_bytes / m['summary']['bytes']
    print(f'added {added} functions -> {len(placed)}/{m["summary"]["functions"]} '
          f'({assigned_bytes}/{m["summary"]["bytes"]} B = {pct:.1f}%), {len(m["tus"])} TUs, '
          f'{len(m["unassigned"])} unassigned')
    if '--apply' in sys.argv:
        MAP.write_text(json.dumps(m, indent=2) + '\n')
        print('wrote', MAP)


if __name__ == '__main__':
    main()
