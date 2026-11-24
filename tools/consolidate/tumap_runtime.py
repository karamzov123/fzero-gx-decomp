#!/usr/bin/env python3
"""Assign runtime-library functions left between mapped DOL TUs in state/tumap/GFZE01_main.json.

Each row is a run of functions whose sizes equal, in order, the named donor TU between the same
neighboring TUs of the donor's link order (donors are the decomp configs under build/tools/), or
states its other evidence. heap.c is a descriptive placeholder name.

Usage: tumap_runtime.py [--apply]
"""
import json, pathlib, re, sys

MAP = pathlib.Path('state/tumap/GFZE01_main.json')
ROWS = [  # file, lib, lo, hi, ordered sizes, donors
    ('GCN_Mem_Alloc.c', 'runtime', 0x80079EF0, 0x8007A060, [184, 184], 'GQNE5D, G9SE8P'),
    ('ansi_files.c', 'runtime', 0x8007B1CC, 0x8007B338, [220, 144], 'GQNE5D, G9SE8P'),
    ('ctype.c', 'runtime', 0x8007ED90, 0x8007EDB4, [36], 'GQNE5D; body indexes the 0x8015B200 table'),
    ('direct_io.c', 'runtime', 0x8007F13C, 0x8007F508, [848, 124], 'GQNE5D'),
    ('file_io.c', 'runtime', 0x8007F508, 0x8007F684, [380], 'GQNE5D'),
    ('mem.c', 'runtime', 0x8008023C, 0x80080288, [76], 'six donors'),
    ('mem_funcs.c', 'runtime', 0x80080518, 0x8008067C, [168, 188], 'GQNE5D'),
    ('misc_io.c', 'runtime', 0x8008068C, 0x8008069C, [16], 'seven donors'),
    ('e_acos.c', 'runtime', 0x8008596C, 0x80085C7C, [784], 'GQNE5D'),
    ('k_sin.c', 'runtime', 0x80087BA4, 0x80087C44, [160], 'six donors'),
    ('k_tan.c', 'runtime', 0x80087C44, 0x80087E58, [532], 'six donors'),
    ('s_copysign.c', 'runtime', 0x80087E58, 0x80087E80, [40], 'six donors'),
    ('s_cos.c', 'runtime', 0x80087E80, 0x80087F54, [212], 'six donors'),
    ('math_ppc.c', 'runtime', 0x80088624, 0x80088648, [36], 'five donors'),
    ('msg.c', 'trk', 0x80088B00, 0x80088B44, [68], 'GQNE5D, MarioClub_us'),
    ('serpoll.c', 'trk', 0x80089380, 0x80089388, [8], 'seven donors; body is li r3, 0; blr'),
    ('usr_put.c', 'trk', 0x8008963C, 0x800896C4, [136], 'seven donors'),
    ('DebuggerDriver.c', 'odemuexi2', 0x8008F454, 0x8008F92C, [4, 4, 608, 140, 156, 84, 120, 64, 60],
     'GQNE5D, MarioClub_us, GZLE01, GMSE01'),
    ('DebuggerDriver.c', 'odemuexi2', 0x8008FC3C, 0x8008FED4, [664], 'GQNE5D, MarioClub_us, GZLE01, GMSE01'),
    ('heap.c', 'game', 0x80008E34, 0x80009FBC,
     [40, 40, 68, 152, 40, 40, 180, 64, 964, 180, 136, 120, 532, 632, 516, 40, 720, 16, 8],
     'no donor: a modified SDK OSAlloc with its OSCheckHeap failure strings, sharing the heap state at .sbss '
     '0x801A6730..0x801A6748 and .sdata 0x801A6410/0x801A6414. It ends at PPCArch.c. The sizes are this build\'s'),
    ('CARDStatEx.c', 'card', 0x80030380, 0x80030690, [188, 596],
     'no donor with these sizes: GQNE5D links CARDStatEx.o between CARDRename.o and CARDNet.o with the same two functions, '
     '__CARDGetStatusEx and __CARDSetStatusExAsync, and both here use the card control block calls'),
    ('lg_view.c', 'game', 0x8006CCC8, 0x8006CFF8, [88, 12, 20, 16, 88, 84, 32, 40, 436],
     'no donor: these nine functions share .sbss 0x801A6CA0..0x801A6CB0. Their .sdata2 run starts on the 8-byte TU boundary '
     '0x801A7398 and ends where mathutil.c starts at 0x801A73D0, which repeats 0.0. The file name is a placeholder'),
    ('alloc.c', 'runtime', 0x8007A150, 0x8007A2E8, [112, 124, 88, 84],
     'GQNE5D alloc.o has __pool_free (88) and __pool_alloc (84) immediately before deallocate_from_fixed_pools; the two '
     'functions before them are free and malloc, which call them and use the pool at .bss 0x801A3380'),
    ('arith.c', 'runtime', 0x8007E914, 0x8007E96C, [88], 'G9SE8P arith.c: div'),
    ('bsearch.c', 'runtime', 0x8007E96C, 0x8007EA58, [236],
     'no donor with this size: MarioClub_us links bsearch.c between arith.c and buffer_io.c, and this body is bsearch'),
    ('FILE_POS.c', 'runtime', 0x8007FC34, 0x8007FF18, [572, 168],
     'G9SE8P FILE_POS.c has _fseek (572) after fseek; the next function is ftell'),
    ('uart_console_io.c', 'runtime', 0x8008580C, 0x800858E4, [8, 208],
     'GMSE01 links uart_console_io.c between strtoul.c and wchar_io.c, with __close_console (8) first. The second '
     'function calls InitializeUART and WriteUARTN'),
    ('exi2.c', 'odemuexi2', 0x8008E770, 0x8008F454, [580, 408, 64, 108, 128, 104, 80, 64, 64, 64, 188, 44, 264, 700, 432, 4, 4],
     'no donor: the EXI2 debugger link used by the ddh callers, with the string "Can\'t select EXI2 port!" at .data '
     '0x8015B900. It lies between MWCriticalSection_gc.cpp and DebuggerDriver.c. The two 4-byte stubs at the end are placed '
     'by position. The file name is a placeholder'),
    ('render_clear.c', 'game', 0x80007A44, 0x80007CDC, [112, 180, 196, 52, 124],
     'no donor: these five functions share the clear color at .sdata 0x801A6408 and the flag at .sbss 0x801A6728. '
     'Their three .sdata2 color initializers end at 0x801A6F0C and the next TU starts on the 8-byte boundary '
     '0x801A6F10; one compile packs the next literal at 0x801A6F0C. The file name is a placeholder'),
    ('render_util.c', 'game', 0x80007CDC, 0x80008E34,
     [124, 536, 600, 60, 740, 780, 600, 348, 68, 52, 404, 124, 4],
     'no donor: unnamed .sdata2 literals are per TU, and 0x801A6F14 is shared by 0x80007F70, 0x80008204 and '
     '0x800084E8, 0x801A6F38 by 0x80008204 and 0x800084E8, 0x801A6F30 by 0x800084E8 and 0x80008C20. Only '
     '0x800081C8 calls 0x80007F70 and only 0x800084E8 calls 0x800087F4 and 0x80008A4C. 0x80008E30 is empty in USA, '
     'absent in Japan and a real function in PAL that reads this TU\'s literal 0x801A6F20. 0x80007CDC, 0x80007D58, '
     '0x80008BA8, 0x80008BEC and 0x80008DB4 have no data evidence and are placed by position. The file name is a '
     'placeholder'),
]


def main():
    m = json.loads(MAP.read_text())
    syms = {}
    for line in open('config/GFZE01/symbols.txt'):
        x = re.match(r'(\S+) = \.text:0x(\w+); // type:function size:0x(\w+)', line)
        if x:
            syms[x[1]] = (int(x[2], 16), int(x[3], 16))
    open_names = {u['name'] for u in m['unassigned']}
    by_file = {t['file']: t for t in m['tus']}
    for file, lib, lo, hi, sizes, donors in ROWS:
        names = [n for _, n in sorted((a, n) for n, (a, _) in syms.items() if lo <= a < hi)]
        assert [syms[n][1] for n in names] == sizes, f'{file}: sizes differ'
        t = by_file.get(file)
        if t is not None and set(names) <= set(t['functions']):
            continue
        assert set(names) <= open_names, f'{file}: already assigned'
        if t is None:
            t = by_file[file] = {'file': file, 'text': [f'{lo:08X}', f'{hi:08X}'], 'functions': [],
                                 'how': {}, 'lib': lib}
            m['tus'].append(t)
        t['text'] = [f'{min(lo, int(t["text"][0], 16)):08X}', f'{max(hi, int(t["text"][1], 16)):08X}']
        t['functions'] = [n for _, n in sorted((syms[n][0], n) for n in t['functions'] + names)]
        how = 'data-evidence' if donors.startswith('no donor') else 'donor-size'
        t['how'][how] = t['how'].get(how, 0) + len(names)
        note = f'0x{lo:08X}..0x{hi:08X}: {donors}.' if donors.startswith('no donor') else f'0x{lo:08X}..0x{hi:08X}: ordered sizes equal {donors}.'
        t['notes'] = f'{t["notes"]} {note}' if t.get('notes') else note
        a = int(t['text'][0], 16)
        covered = sum(syms[n][1] for n in t['functions'])
        assert covered == int(t['text'][1], 16) - a, f'{file}: range has gaps'
        open_names -= set(names)
    m['tus'].sort(key=lambda t: int(t['text'][0], 16))
    m['unassigned'] = [u for u in m['unassigned'] if u['name'] in open_names]
    placed = {f for t in m['tus'] for f in t['functions']}
    m['summary'].update(assigned=len(placed), tus=len(m['tus']),
                        assigned_bytes=sum(syms[f][1] for f in placed if f in syms))
    s = m['summary']
    print(f"{s['assigned']}/{s['functions']} functions, {s['assigned_bytes']}/{s['bytes']} B "
          f"({100 * s['assigned_bytes'] / s['bytes']:.1f}%), {s['tus']} TUs, {len(m['unassigned'])} unassigned")
    if '--apply' in sys.argv:
        MAP.write_text(json.dumps(m, indent=2) + '\n')


if __name__ == '__main__':
    main()
