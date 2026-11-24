#!/usr/bin/env python3
"""Extend the DOL TU map over verified Dolphin SDK, THP, PERF, AX/MIX, MSL, and TRK ranges.

Follows the exact Dolphin SDK / MSL / TRK archive link order anchored by existing
sdkimport, donor-name, string, and .sbss/.bss layout evidence in state/tumap/GFZE01_main.json.
Any function already mapped to a different TU is rejected as an error.

Usage: tumap_sdk.py [--apply]
"""
import json, pathlib, re, sys

MAP = pathlib.Path('state/tumap/GFZE01_main.json')

# (tu_file, lib, lo, hi, evidence_tag)
RANGES = [
    # --- Dolphin OS (0x8000A0FC..0x8001191C) ---
    ('OS.c', 'os', 0x8000A0FC, 0x8000ABE8, 'sdk-order'),
    ('OSCache.c', 'os', 0x8000B614, 0x8000BBAC, 'sdk-order'),
    ('OSContext.c', 'os', 0x8000BBAC, 0x8000C41C, 'sdk-order'),
    ('OSFont.c', 'os', 0x8000CAC8, 0x8000D4F4, 'sdk-order'),
    ('OSLink.c', 'os', 0x8000DD60, 0x8000E794, 'sdk-order'),
    ('OSMemory.c', 'os', 0x8000E794, 0x8000EA84, 'sdk-order'),
    ('OSReboot.c', 'os', 0x8000EAF4, 0x8000EE5C, 'sdk-order'),
    ('OSReset.c', 'os', 0x8000EE5C, 0x8000F264, 'sdk-order'),
    ('OSResetSW.c', 'os', 0x8000F264, 0x8000F610, 'sdk-order'),
    ('OSRtc.c', 'os', 0x8000F610, 0x800100BC, 'sdk-order'),
    ('OSSync.c', 'os', 0x800100BC, 0x80010144, 'sdk-order'),
    ('OSThread.c', 'os', 0x80010144, 0x8001140C, 'sdk-order'),

    # --- SI (0x8001191C..0x80013A88) ---
    ('SIBios.c', 'si', 0x8001191C, 0x800132D4, 'sdk-order'),
    ('SISteering.c', 'si', 0x800133DC, 0x800137C4, 'sdk-order'),
    ('SISteeringAuto.c', 'si', 0x800137C4, 0x80013A88, 'sdk-order'),

    # --- DVD / VI / PAD / AI (0x80016DC0..0x8001E828) ---
    ('dvdfs.c', 'dvd', 0x80016DC0, 0x8001776C, 'sdk-order'),
    ('vi.c', 'vi', 0x8001A55C, 0x8001C0C0, 'sdk-order'),
    ('Pad.c', 'pad', 0x8001C304, 0x8001DF44, 'sdk-order'),
    ('ai.c', 'ai', 0x8001DF44, 0x8001E828, 'sdk-order'),

    # --- AX / AXFX / MIX (0x800206FC..0x800289C0) ---
    ('AX.c', 'ax', 0x800206FC, 0x80020874, 'sdk-order'),
    ('AXAlloc.c', 'ax', 0x80020874, 0x80020D58, 'sdk-order'),
    ('AXAux.c', 'ax', 0x80020D58, 0x8002123C, 'sdk-order'),
    ('AXCL.c', 'ax', 0x8002123C, 0x800218EC, 'sdk-order'),
    ('AXOut.c', 'ax', 0x800218EC, 0x80021FBC, 'sdk-order'),
    ('AXSPB.c', 'ax', 0x80021FBC, 0x800224E4, 'sdk-order'),
    ('AXVPB.c', 'ax', 0x800224E4, 0x800235D4, 'sdk-order'),
    ('AXProf.c', 'ax', 0x800235D4, 0x80023684, 'sdk-order'),
    ('mix.c', 'mix', 0x80025EE4, 0x8002805C, 'sdk-order'),

    # --- DSP (0x800289C0..0x80029828) ---
    ('dsp.c', 'dsp', 0x800289C0, 0x80028F50, 'sdk-order'),
    ('dsp_debug.c', 'dsp', 0x80028F50, 0x80028FA0, 'sdk-order'),
    ('dsp_task.c', 'dsp', 0x80028FA0, 0x80029828, 'sdk-order'),

    # --- CARD (0x80029828..0x800307CC) ---
    ('CARDBios.c', 'card', 0x80029828, 0x8002ABC0, 'sdk-order'),
    ('CARDRdwr.c', 'card', 0x8002BE20, 0x8002C0C0, 'sdk-order'),
    ('CARDBlock.c', 'card', 0x8002C0C0, 0x8002C4C4, 'sdk-order'),
    ('CARDOpen.c', 'card', 0x8002E954, 0x8002EDA8, 'sdk-order'),
    ('CARDRead.c', 'card', 0x8002F140, 0x8002F5B8, 'sdk-order'),
    ('CARDWrite.c', 'card', 0x8002F5B8, 0x8002F934, 'sdk-order'),
    ('CARDDelete.c', 'card', 0x8002F934, 0x8002FC5C, 'sdk-order'),
    ('CARDStat.c', 'card', 0x8002FC5C, 0x8003013C, 'sdk-order'),
    ('CARDRename.c', 'card', 0x8003013C, 0x80030380, 'sdk-order'),
    ('CARDNet.c', 'card', 0x80030690, 0x800307CC, 'sdk-order'),

    # --- THP & PERF (0x80039C40..0x80041164) ---
    ('THPDec.c', 'thp', 0x80039C40, 0x8003D4E0, 'sdk-order'),
    ('perf.c', 'perf', 0x8003D4E0, 0x8003E9EC, 'sdk-order'),
    ('perfdraw.c', 'perf', 0x8003E9EC, 0x80041164, 'sdk-order'),  # 0x8003E9EC repeats perf.c's 2^52 at .sdata2 0x801A71D0

    # --- MSL_C (verified named gaps) ---
    ('buffer_io.c', 'runtime', 0x8007EA58, 0x8007ED84, 'sdk-order'),
    ('critical_regions.gamecube.c', 'PPC_EABI', 0x8007ED84, 0x8007ED90, 'sdk-order'),
    ('printf.c', 'runtime', 0x8008069C, 0x8008279C, 'sdk-order'),

    # --- MetroTRK & Stubs (verified named gaps) ---
    ('nubevent.c', 'Portable', 0x80088740, 0x80088968, 'sdk-order'),
    ('targimpl.c', 'TRK_MINNOW_DOLPHIN', 0x8008B0E0, 0x8008CB40, 'sdk-order'),
    ('dolphin_trk.c', 'trk', 0x8008CEB0, 0x8008D1CC, 'sdk-order'),
    ('main_TRK.c', 'Portable', 0x8008D1CC, 0x8008D224, 'sdk-order'),
    ('dolphin_trk_glue.c', 'trk_minnow_dolphin', 0x8008D224, 0x8008D77C, 'sdk-order'),
    ('UDP_Stubs.c', 'trk_minnow_dolphin', 0x8008D7B0, 0x8008DDD0, 'sdk-order'),
    ('AmcExi2Stubs.c', 'amcstubs', 0x8008FED4, 0x8008FEDC, 'sdk-order'),
    ('odenotstub.c', 'odenotstub', 0x8008FEDC, 0x8008FEE4, 'sdk-order'),
]


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
            for n in new:
                placed[n] = file
        t['functions'] = [n for _, n in inside]
        t['text'] = [f'{lo:08X}', f'{hi:08X}']
    m['tus'].sort(key=lambda t: int(t['text'][0], 16))
    m['summary']['tus'] = len(m['tus'])
    now = {f for t in m['tus'] for f in t['functions']}
    moved = [u for u in m['unassigned'] if u['name'] in now]
    m['unassigned'] = [u for u in m['unassigned'] if u['name'] not in now]
    m['summary']['assigned'] += added
    m['summary']['assigned_bytes'] += sum(u['size'] for u in moved)
    pct = 100.0 * m['summary']['assigned_bytes'] / m['summary']['bytes']
    print(f'{added} functions assigned; {m["summary"]["assigned"]}/{m["summary"]["functions"]} ({pct:.1f}% bytes) in {m["summary"]["tus"]} TUs')
    if '--apply' in sys.argv:
        MAP.write_text(json.dumps(m, indent=1) + '\n')


if __name__ == '__main__':
    main()
