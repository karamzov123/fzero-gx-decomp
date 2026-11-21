#!/usr/bin/env python3
"""Extend the DOL TU map over string-anchored Game DOL, Logitech lg, and CRI ADX ranges.

Evidence:
- Game DOL:
  * avfile.c   (0x80006B4C..0x800071B8): "avfile.c" (0x80122118), "open from DVD...", "reading from DVD..."
  * mmu.c      (0x800071B8..0x800075AC): "mmu.c" (0x801A6400), "MMU: can't allocate PTE."
  * arc.c      (0x8006A3DC..0x8006AA20): "arc.c" (0x801A6610), "ARCInitHandle", AX cluster 0x80204758..0x80204D30
  * lg.c       (0x8006AA20..0x8006CCC8): Logitech Speed Force wheel lib (GC/2.0p1, calls SI steering, absent in AX)
  * mathutil.c (0x8006CFF8..0x8006E5FC): Amusement Vision mathutil_init..mathutil_quat_mult (53 fns)
  * avsystem.c (0x80070158..0x80070F44): "avsystem.c" (0x8015AA78), "Not enough Locked Cache", "init_system: invalid TV format"
  * avload.c   (0x80070F44..0x80071C04): "avload.c" (0x8015ABFC), "alloc: <%s> not enough memory", "invalid texture!"
  * avdisp.c   (0x80071C04..0x80079654): "avdisp.c" (0x8015ADE8), "Warning: not effective model.", "Invalid Model"
- CRI ADX (string-anchored):
  * adx_stmc.c (0x8004A578..0x8004BA38): "E02110501 adxstmf_stat_exec"
  * adx_tlk.c  (0x8004BA38..0x8004D220): "ADXT_GetStatPause" .. "ADXT_StartFname"
  * adx_tsvr.c (0x8004D220..0x8004E098): "ADXT_ExecHndl", "adxt_stat_decinfo", "adxt_trap_entry"
  * adx_fs.c   (0x8004F74C..0x8004FC38): "'flid' is range outside", ADXF_*
  * gcci.c     (0x80055580..0x80056584): "E0092912:handl is null", gcCi*
  * lsc.c      (0x800566BC..0x800571EC): "E0003: Illigal parameter lsc=NULL"

Usage: tumap_game_adx.py [--apply]
"""
import json, pathlib, re, sys

MAP = pathlib.Path('state/tumap/GFZE01_main.json')

RANGES = [
    # Game DOL & Logitech lg
    ('game_main.c', 'av', 0x800055E0, 0x80006B4C, 'string-range'),
    ('avfile.c', 'av', 0x80006B4C, 0x800071B8, 'string-range'),
    ('mmu.c', 'av', 0x800071B8, 0x800075AC, 'string-range'),
    ('arc.c', 'arc', 0x8006A3DC, 0x8006AA20, 'string-range'),
    ('lg.c', 'lg', 0x8006AA20, 0x8006CCC8, 'sdk-order'),
    ('mathutil.c', 'av', 0x8006CFF8, 0x8006FCB4, 'donor-name'),
    ('avsystem.c', 'av', 0x8006FCB4, 0x80070F44, 'string-range'),
    ('avload.c', 'av', 0x80070F44, 0x80071C04, 'string-range'),
    ('avdisp.c', 'av', 0x80071C04, 0x80079654, 'string-range'),

    # CRI ADX (string-anchored)
    ('adx_stmc.c', 'adxt', 0x8004A578, 0x8004BA38, 'string-range'),
    ('adx_tlk.c', 'adxt', 0x8004BA38, 0x8004D220, 'string-range'),
    ('adx_tsvr.c', 'adxt', 0x8004D220, 0x8004E098, 'string-range'),
    ('adx_fs.c', 'adxf', 0x8004F74C, 0x8004FC38, 'string-range'),
    ('gcci.c', 'gcci', 0x80055580, 0x80056584, 'string-range'),
    ('lsc.c', 'lsc', 0x800566BC, 0x800571EC, 'string-range'),

    # MSL_C / fdlibm verified gaps
    ('scanf.c', 'runtime', 0x80082908, 0x80083B14, 'sdk-order'),
    ('e_pow.c', 'runtime', 0x80086008, 0x800868BC, 'sdk-order'),
]


def main():
    m = json.loads(MAP.read_text())
    syms = {}
    for line in open('config/GFZE01/symbols.txt'):
        x = re.match(r'(\S+) = \.text:0x(\w+); // type:function size:0x(\w+)', line)
        if x:
            syms[x[1]] = (int(x[2], 16), int(x[3], 16))
    # Note: adx_tlk.c has a historical conflict entry at 8004FC38; target the first run
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
