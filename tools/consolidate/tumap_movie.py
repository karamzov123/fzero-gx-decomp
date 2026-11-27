#!/usr/bin/env python3
"""Map the CRI Sofdec (libmwsfdg) TUs of movie_module into config/GFZE01/movie_module/tus.json.

GX's movie_module .text is libmwsfdg linked in the order of MK Deception's GQNE5D build
(build/tools/mk-deception/config/GQNE5D/, CC0): sud_lib, sfx_*, dct_*, mcp_not, mps_*, mpv_*,
sfd_*, sfh_main, uty, mwsfd*, cft*. The assignment is a global alignment of the two function
lists in address order:

- anchors: GX names equal to donor names, and donor names bound to GX symbols by the Sofdec
  imports (state/sdkimports/*.json `bindings`/`sdk_symbol`); every anchor lands on its object;
- function sizes (exact equal sizes score highest), gaps allowed on both sides (GX's Sofdec
  1.852 lacks some donor functions and has others the donor lacks);
- the three MPVABDEC block decoders keep the existing mpvabdec.c entry (GX links that object
  between mpv_umc and mpv_mcy, the donor after mpv_m2v).

Functions the alignment leaves between two different objects are decided in GAPS below, by
.rodata/.bss references in the linked REL's relocations (each TU's own literals and strings
are contiguous, in text order), the error strings (they name their function), and the static
call graph. Runs without any such evidence are tagged `unresolved`: they reference no data,
so either neighbour compiles them identically. The result is evidence for TU boundaries; the
16-target hash remains the proof of any unit built from it.

Usage: tumap_movie.py [--apply]
"""
import glob, json, pathlib, re, sys

DONOR = pathlib.Path('build/tools/mk-deception/config/GQNE5D')
MODULE = 'movie_module'
OUT = pathlib.Path(f'config/GFZE01/{MODULE}/tus.json')
PREFIX = ['_prolog', '_epilog']
FIXED = {n: 'mpvabdec.o' for n in ('MPVABDEC_NintraBlock', 'MPVABDEC_IntraBlock', 'MPVABDEC_IntraBlockDc11')}


def R(*xs):
    return ['fn_12_' + x for x in xs]


GAPS = [
    (R('68C', '6B8', '738', '740'), 'sfx_set.o', 'inferred: no data; called only from sfx_cnv; GX sud_lib already equals the donor object'),
    (R('8E4', 'A5C'), 'sfx_cnv.o', 'rodata: pool 0x194 inside sfx_cnv .rodata 0x60..0x448; called by sfx_cnv fn_12_C60'),
    (R('D88', 'F70', '11A8', '132C', '13D0', '147C', '1578', '1F84', '21C8', '2F04', '3054'), 'sfx_cnv.o',
     'rodata: sfx_cnv pool 0x60 (0xC0/0x28C/0x2BC inside its range); one static call chain'),
    (R('307C'), 'sfx_lib.o', 'bss: 0xC inside sfx_lib .bss 0x8..0x10'),
    (R('34A8', '34C4'), 'sfx_alp.o', 'inferred: SFXA setters called by the sfx_set wrappers 758/77C; the SFXZ setters 3630..3670 open sfx_zmv'),
    (R('3630', '365C', '3670'), 'sfx_zmv.o', 'rodata: 0x4E8..0x4F0 is the start of sfx_zmv .rodata; called by the sfx_set wrappers 7A0/7C4'),
    (R('670C'), 'mps_dec.o', 'calls: its only callers are mps_dec fn_12_5FA0 and fn_12_654C'),
    (R('77F4', '7870', '78C0', '7940', '7E58', '80BC', '8344', '847C', '86B8', '873C', '879C', '87FC', '8878', '89D4', '8A10'),
     'mpv_cdec.o', 'unresolved: no data, no named callers; mpv_cmc starts with the donor first function'),
    (R('11168', '11188', '11204', '11254'), 'mpv_vlc.o', 'unresolved: no data, no callers; mpv_umc starts at its donor second function'),
    (R('215F4'), 'sfd_adxt.o', 'rodata: 0xA78 ("(c)CRI") follows sfd_adxt .rodata 0xA50..0xA70'),
    (R('232DC', '23410', '23700', '2396C', '23BFC', '23E0C'), 'sfd_con.o',
     'inferred: one static call tree under fn_12_23E0C, tables 0xAB8..0xAEC before sfd_lib .rodata 0xB00; sfd_hds starts with the donor first function'),
    (R('2B138'), 'sfd_ply.o', 'inferred: GX sfd_ply getter before SFD_SetSupplySj'),
    (R('2D470'), 'sfd_see.o', 'inferred: called from mwsfdfrm; sfd_set starts with the donor first function'),
    (R('334FC'), 'muldiv.o', 'inferred: rodata 0x1108/0x1110; the GX analogue of donor muldivr.o, which follows muldiv.o'),
    (R('336CC'), 'uty_ppc.o', 'inferred: calls sfh_main; mwsfdfrm starts with its donor first function'),
    (R('341C4'), 'mwsfdrsc.o', 'inferred: 0x20 stub after mwPlySaveRsc'),
    (R('3496C', '349CC', '34AB0'), 'mwsfdsl.o', 'rodata: 0x12E0 is mwsfdsl .rodata (0x12E0..0x130C)'),
    (R('35018', '3503C'), 'mwsfdsee.o', 'inferred: wrappers called from mwsfdfrm'),
    (R('38680', '38704'), 'mwsfdcre.o', 'rodata: 0x2184 inside mwsfdcre .rodata 0x1D88..0x221C; 0x2240 before mwsfdlib 0x2270'),
    (R('39A68', '39CA4', '39CF8', '39DA0'), 'mwsfdset.o',
     'strings: mwsfdset error strings 0x2718 (mwPlyGetSfdHn, the donor last mwsfdset function), 0x287C, 0x28B0, 0x28E0'),
    (R('3A82C'), 'mwsfdset.o', 'strings: 0x2CF4 "mwPlySetAudioSw" inside mwsfdset .rodata 0x2718..0x2D28'),
    (R('3B65C'), 'mwsfdsst.o', 'inferred: called from sfx_alp fn_12_34E4; the donor mwsfdsbt/mwsfx objects are absent'),
    (R('3D730', '3D734', '3D738', '3D73C'), 'cftfx.o', 'inferred: 4-byte stubs before cftfx CFT_MakeArgb8888ColAdjTbl'),
]


def functions(path):
    out = []
    for line in open(path):
        m = re.match(r'(\S+) = \.text:0x(\w+); // type:function size:0x(\w+)', line)
        if m:
            out.append((int(m[2], 16), int(m[3], 16), m[1]))
    return sorted(out)


def donor_functions():
    ranges, cur = [], None
    for line in open(DONOR / 'splits.txt'):
        m = re.match(r'^(\S.*\.o):$', line.rstrip())
        if m:
            cur = m[1]
            continue
        m = re.match(r'\s+\.text\s+start:0x(\w+) end:0x(\w+)', line)
        if m and cur:
            ranges.append((int(m[1], 16), int(m[2], 16), cur))
    out = []
    for a, s, n in functions(DONOR / 'symbols.txt'):
        obj = next((o for lo, hi, o in ranges if lo <= a < hi), None)
        if obj and obj.startswith('libmwsfdg.a//'):
            out.append((s, n, obj))
    return out


def anchors(gx, donor):
    by_name = {n: o for _, n, o in donor}
    names = {n for _, _, n in gx}
    out = {n: by_name[n] for n in names if n in by_name}
    for f in sorted(glob.glob('state/sdkimports/*.json')):
        try:
            j = json.loads(pathlib.Path(f).read_text())
        except ValueError:
            continue
        for k, v in (j.items() if isinstance(j, dict) else ()):
            if not isinstance(v, dict):
                continue
            for d, g in (v.get('bindings') or {}).items():
                if d in by_name and g in names:
                    out.setdefault(g, by_name[d])
            sym = v.get('symbol') or k
            if v.get('sdk_symbol') in by_name and sym in names:
                out.setdefault(sym, by_name[v['sdk_symbol']])
    return out


def align(gx, donor, anchor):
    """Global alignment (Needleman-Wunsch) of GX functions against donor functions; anchors are forced."""
    n, m, GAP = len(gx), len(donor), -1

    def score(g, d):
        if g[2] in anchor:
            return 200 if anchor[g[2]] == d[2] else -500
        if g[1] == d[0]:
            return 6
        r = min(g[1], d[0]) / max(g[1], d[0])
        return 2 if r > 0.9 else (0 if r > 0.7 else -3)

    H = [[0] * (m + 1) for _ in range(n + 1)]
    P = [[2] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        H[i][0], P[i][0] = H[i - 1][0] + GAP, 1
        for j in range(1, m + 1):
            a = H[i - 1][j - 1] + score(gx[i - 1], donor[j - 1])
            b = H[i - 1][j] + GAP
            c = H[i][j - 1] + (GAP if i < n else 0)
            H[i][j], P[i][j] = max((a, 0), (b, 1), (c, 2), key=lambda t: (t[0], -t[1]))
    i, j, pairs = n, max(range(m + 1), key=lambda j: H[n][j]), {}
    while i > 0:
        p = P[i][j] if j > 0 else 1
        if p == 0:
            pairs[i - 1] = j - 1
        i, j = (i - 1, j - 1) if p == 0 else (i - 1, j) if p == 1 else (i, j - 1)
    return pairs


def main():
    gx = [g for g in functions(f'config/GFZE01/{MODULE}/symbols.txt')]
    donor = donor_functions()
    anchor = {k: v for k, v in anchors(gx, donor).items() if k not in FIXED}
    pairs = align(gx, donor, anchor)
    obj, how = {}, {}
    path = {x.split('/')[-1]: x for _, _, x in donor}
    for k, (_, s, n) in enumerate(gx):
        if n in FIXED:
            obj[n], how[n] = path[FIXED[n]], 'existing map'
        elif k in pairs:
            ds, _, do = donor[pairs[k]]
            obj[n], how[n] = do, ('name' if n in anchor else 'donor-size' if ds == s else 'donor-order')
    for fs, o, why in GAPS:
        for f in fs:
            assert f in {g[2] for g in gx} and f not in obj, f
            obj[f] = path[o]
            how[f] = why.split(':')[0]
    names = [g[2] for g in gx]
    for i, n in enumerate(names):
        if n in obj or n in PREFIX:
            continue
        p = next(obj[names[k]] for k in range(i - 1, -1, -1) if names[k] in obj)
        q = next(obj[names[k]] for k in range(i + 1, len(names)) if names[k] in obj)
        assert p == q, f'{n}: undecided between {p} and {q}; add a GAPS row'
        obj[n], how[n] = p, 'interior'
    order = []
    for n in names:
        if n in obj and (not order or order[-1] != obj[n]):
            order.append(obj[n])
    assert len(order) == len(set(order)), 'an object is not contiguous'
    end = {g[2]: g[0] + g[1] for g in gx}
    start = {g[2]: g[0] for g in gx}
    tus = []
    for k, o in enumerate(order):
        fs = [n for n in names if obj.get(n) == o]
        hi = start[next(n for n in names if obj.get(n) == order[k + 1])] if k + 1 < len(order) else end[fs[-1]]
        counts = {}
        for f in fs:
            counts[how[f]] = counts.get(how[f], 0) + 1
        stem = o.split('/')[-1][:-2]
        tu = {'file': f'{stem}.c', 'text': [start[fs[0]], hi], 'functions': fs,
              'source': 'CRI Sofdec ' + o.split('//')[1][:-2] + '.c', 'how': counts}
        gap_notes = [f'{", ".join(f for f in g if f in fs)}: {why}' for g, o2, why in GAPS if o2 == o.split('/')[-1]]
        if gap_notes:
            tu['notes'] = gap_notes
        tus.append(tu)
    doc = {'module': MODULE, 'donor': 'MK Deception GQNE5D (CC0) libmwsfdg.a link order',
           'unassigned_prefix': PREFIX, 'tus': tus}
    total = sum(len(t['functions']) for t in tus)
    print(f'{len(tus)} TUs, {total}/{len(gx)} functions ({len(PREFIX)} entry points unassigned); '
          f'evidence: {sorted({k for t in tus for k in t["how"]})}')
    if '--apply' in sys.argv:
        OUT.write_text(json.dumps(doc, indent=1) + '\n')
        print('wrote', OUT)


if __name__ == '__main__':
    main()
