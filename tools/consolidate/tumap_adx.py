#!/usr/bin/env python3
"""Map the CRI ADX (libadxgca) TUs in state/tumap/GFZE01_main.json.

Matched by function-size sequence and link order against build/tools/mk-deception/config/GQNE5D/
(libadxgca.a//crimw/dev/adx/src/*) and existing string-anchored ADX TUs.
Also resolves the historical adx_bau.c duplicate conflict (0x8004342C..0x80043FA4 is adx_baif.c,
6/6 exact function-size match, 2936 B; 0x80043FA4..0x80044E7C is adx_bau.c, 7/7 exact, 3800 B).

Usage: tumap_adx.py [--apply]
"""
import json, pathlib, re, sys

MAP = pathlib.Path('state/tumap/GFZE01_main.json')

# Exact contiguous libadxgca TU ranges (file, lib, lo, hi, tag)
RANGES = [
    ('adx_inis.c', 'adxt', 0x80041164, 0x80041410, 'donor-size'),
    ('adx_sjd.c',  'adxt', 0x80041410, 0x8004251C, 'donor-size'),
    ('adx_bwav.c', 'adxt', 0x8004251C, 0x800433A4, 'donor-size'),
    ('adx_bahx.c', 'adxt', 0x800433A4, 0x8004342C, 'donor-size'),
    ('adx_baif.c', 'adxt', 0x8004342C, 0x80043FA4, 'donor-size'),
    ('adx_bau.c',  'adxt', 0x80043FA4, 0x80044E7C, 'donor-size'),
    ('adx_bsc.c',  'adxt', 0x80044E7C, 0x80045FEC, 'donor-size'),
    ('adx_bsps.c', 'adxt', 0x80045FEC, 0x80046508, 'donor-size'),
    ('adx_amp.c',  'adxt', 0x80046508, 0x80046718, 'donor-size'),
    ('adx_crs.c',  'adxt', 0x80046718, 0x80046768, 'donor-size'),
    ('adx_dcd.c',  'adxt', 0x80046768, 0x80046F88, 'donor-size'),
    ('adx_errs.c', 'adxt', 0x80046F88, 0x80047608, 'donor-size'),
    ('adx_fsvr.c', 'adxt', 0x80047608, 0x8004768C, 'donor-size'),
    ('adx_insh.c', 'adxt', 0x8004768C, 0x80047834, 'donor-size'),
    ('adx_sfa.c',  'adxt', 0x80047834, 0x80047864, 'donor-size'),
    ('adx_sje.c',  'adxt', 0x80047864, 0x8004A578, 'donor-size'),
    # adx_stmc.c (0x8004A578..0x8004BA38), adx_tlk.c (0x8004BA38..0x8004D220), adx_tsvr.c (0x8004D220..0x8004E098)
    ('adx_xpnd.c', 'adxt', 0x8004E098, 0x8004E4DC, 'donor-size'),
    ('adx_mgc.c',  'adxt', 0x8004E4DC, 0x8004EC34, 'donor-size'),
    ('adx_sugc.c', 'adxt', 0x8004EC34, 0x8004ED18, 'donor-size'),
    ('adx_gc.c',   'adxt', 0x8004ED18, 0x8004ED3C, 'donor-size'),
    ('adx_rnaa.c', 'adxt', 0x8004ED3C, 0x8004EFA8, 'donor-size'),
    ('adx_dcd5.c', 'adxt', 0x8004EFA8, 0x8004F6B0, 'donor-size'),
    ('adx_fini.c', 'adxf', 0x8004F6B0, 0x8004F7F8, 'donor-size'),
    ('adx_fcch.c', 'adxf', 0x8004F7F8, 0x8004F818, 'donor-size'),
    ('adx_fs.c',   'adxf', 0x8004F818, 0x8004FF68, 'donor-order'),
    # AHX is absent from the donor: these seven names are descriptive placeholders.
    ('ahx_bits.c',   'ahx', 0x8004FF68, 0x80050698, 'literal-dedupe+section-order'),
    ('ahx_decode.c', 'ahx', 0x80050698, 0x80051CC0, 'literal-dedupe+section-order'),
    ('ahx_adxt.c',   'ahx', 0x80051CC0, 0x80051F38, 'literal-dedupe+section-order'),
    ('ahx_transform.c', 'ahx', 0x80051F38, 0x80052430, 'literal-dedupe+section-order'),
    ('ahx_synth.c',  'ahx', 0x80052430, 0x80053A38, 'literal-dedupe+section-order'),
    ('ahx_synthobj.c', 'ahx', 0x80053A38, 0x80053EA0, 'literal-dedupe+section-order'),
    ('ahx_player.c', 'ahx', 0x80053EA0, 0x8005466C, 'literal-dedupe+section-order'),
    ('cri_cvfs.c', 'cvfs', 0x8005466C, 0x800555C0, 'donor-size'),
    ('gcci.c',     'gcci', 0x800555C0, 0x800565F0, 'donor-size'),
    ('gcci_sub.c', 'gcci', 0x800565F0, 0x800565FC, 'donor-size'),
    ('lsc_err.c',  'lsc',  0x800565FC, 0x800566F0, 'donor-size'),
    ('lsc_crs.c',  'lsc',  0x800566F0, 0x80056730, 'donor-size'),
    ('lsc.c',      'lsc',  0x80056730, 0x80057378, 'donor-size'),
    ('lsc_ini.c',  'lsc',  0x80057378, 0x80057494, 'donor-size'),
    ('lsc_svr.c',  'lsc',  0x80057494, 0x800576DC, 'donor-size'),
    ('sj_crs.c',   'sj',   0x800576DC, 0x80057774, 'donor-size'),
    ('sj_mem.c',   'sj',   0x80057774, 0x80057D88, 'donor-size'),
    ('sj_rbf.c',   'sj',   0x80057D88, 0x8005870C, 'donor-size'),
    ('sj_uni.c',   'sj',   0x8005870C, 0x800587A8, 'donor-size'),
    ('sj_utl.c',   'sj',   0x800587A8, 0x80058A20, 'donor-size'),
    ('sj_err.c',   'sj',   0x80058A20, 0x80058A40, 'donor-size'),
    ('svm.c',      'svm',  0x80058A40, 0x80059BAC, 'donor-size'),
    ('mfci.c',     'mfci', 0x80059BAC, 0x8005A5BC, 'donor-size'),
    ('rna_err.c',  'axrna',0x8005A5BC, 0x8005A628, 'donor-size'),
    ('rna_crs.c',  'axrna',0x8005A628, 0x8005A668, 'donor-size'),
    ('ax_rna.c',   'axrna',0x8005A668, 0x8005BE68, 'donor-size'),
    ('rna_res.c',  'axrna',0x8005BE68, 0x8005C298, 'donor-size'),
]


NOTES = {
    'ahx_bits.c': 'The SJ bit reader. Its .bss 0x80186FA8..0x8018710C ends four bytes before the next TU on the 8-byte '
                  'boundary 0x80187110; one compile would place the next object at 0x8018710C. 0x80050670 reads the table '
                  'just before this TU\'s mask table in .data.',
    'ahx_decode.c': 'Subband decoding. Uses .bss 0x80187110..0x80187370 and .rodata 0x800912F0..0x80091300. Its end is inferred '
                    'from the change to the ADXT attach wrappers at 0x80051CC0.',
    'ahx_adxt.c': 'ADXT attach and detach wrappers; 0x80051E64 owns the "E1052501 ADXT_AttachAHX" strings at .rodata 0x80091300.',
    'ahx_transform.c': 'The 32-point transform. It reads its own 0.0f at .rodata 0x80091330; the next TU repeats that value '
                       'at 0x80091338, so the two cannot be one compile.',
    'ahx_synth.c': '16 generated synthesis routines over .rodata 0x80091338..0x80091350, which repeats the 2^52 conversion '
                   'constant of ahx_decode.c. The 8-byte 0x80053A30 has no data and stays with this run.',
    'ahx_synthobj.c': 'Creates and frees the synthesis objects. Uses .bss 0x80187370..0x801873D8 and the 2^31 literal at '
                      '.rodata 0x80091350, which repeats a value of ahx_synth.c. Its .rodata ends at 0x80091354.',
    'ahx_player.c': 'The AHX player. Its "AHX/GC Ver.1.24" string starts on the 8-byte TU boundary 0x80091358, and one compile '
                    'with the literal above packs it at 0x80091354. Uses .bss 0x801873D8..0x80187430. The two getters at '
                    '0x80053EA0 and 0x80053EA8 read player fields.',
    'cri_cvfs.c': 'GX sizes from 0x8005466C equal GQNE5D cri_cvfs.o in order, without cvFsGetFileSize (0x4A4), which GX does '
                  'not link. .bss 0x80187430 is first used at 0x8005466C.',
}


def main():
    m = json.loads(MAP.read_text())
    syms = {}
    for line in open('config/GFZE01/symbols.txt'):
        x = re.match(r'(\S+) = \.text:0x(\w+); // type:function size:0x(\w+)', line)
        if x:
            syms[x[1]] = (int(x[2], 16), int(x[3], 16))

    range_files = {f for f, _, _, _, _ in RANGES}
    reviewed = {(t['file'], tuple(t['text'])): t for t in m['tus'] if t.get('notes')}
    # Remove any old TU entries whose file is in range_files (cleanly replacing partial/conflicted ADX stubs)
    # Keep non-range TUs intact (and trim any overlap with our new exact ranges if needed).
    old_placed = {f for t in m['tus'] for f in t['functions']}
    new_tus = []
    for t in m['tus']:
        if t['file'] in range_files:
            continue
        # Trim any functions now claimed by exact ranges
        a0 = int(t['text'][0], 16)
        claimed = {n for _, _, lo, hi, _ in RANGES for n, (a, _) in syms.items() if lo <= a < hi}
        kept = [f for f in t['functions'] if f not in claimed]
        if kept:
            t['functions'] = kept
            t['text'] = [f'{syms[kept[0]][0]:08X}', f'{syms[kept[-1]][0] + syms[kept[-1]][1]:08X}']
            new_tus.append(t)

    for file, lib, lo, hi, tag in RANGES:
        inside = sorted((a, n) for n, (a, _) in syms.items() if lo <= a < hi)
        assert inside, f'{file}: no functions in 0x{lo:08X}..0x{hi:08X}'
        text = [f'{lo:08X}', f'{hi:08X}']
        names = [n for _, n in inside]
        entry = reviewed.get((file, tuple(text)))
        if entry is not None:
            assert entry['functions'] == names, f'{file}: reviewed function list is stale'
            new_tus.append(entry)
            continue
        new_tus.append({
            'file': file,
            'text': text,
            'functions': names,
            'how': {tag: len(inside)},
            'lib': lib,
            **({'notes': NOTES[file]} if file in NOTES else {}),
        })

    new_tus.sort(key=lambda t: int(t['text'][0], 16))
    # Verify zero overlap
    seen = {}
    for t in new_tus:
        for f in t['functions']:
            assert f not in seen, f'overlap on {f}: {seen[f]} vs {t["file"]}'
            seen[f] = t['file']

    resolved = {('adx_bau.c', '80043FE8'), ('adx_tlk.c', '8004FC38')}
    m['conflicts'] = [c for c in m.get('conflicts', []) if (c['tu'], c['at']) not in resolved]
    m['tus'] = new_tus
    m['unassigned'] = [u for u in m['unassigned'] if u['name'] not in seen]
    assigned_bytes = sum(syms[f][1] for f in seen if f in syms)
    m['summary']['assigned'] = len(seen)
    m['summary']['assigned_bytes'] = assigned_bytes
    m['summary']['tus'] = len(new_tus)
    m['summary']['conflicts'] = len(m['conflicts'])
    pct = 100.0 * assigned_bytes / m['summary']['bytes']
    delta = len(seen) - len(old_placed)
    print(f'net +{delta} functions -> {len(seen)}/{m["summary"]["functions"]} '
          f'({assigned_bytes}/{m["summary"]["bytes"]} B = {pct:.1f}%), {len(new_tus)} TUs, '
          f'{len(m["unassigned"])} unassigned, {len(m["conflicts"])} conflicts')
    if '--apply' in sys.argv:
        MAP.write_text(json.dumps(m, indent=2) + '\n')
        print('wrote', MAP)


if __name__ == '__main__':
    main()
