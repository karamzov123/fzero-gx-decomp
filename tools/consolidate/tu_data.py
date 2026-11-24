#!/usr/bin/env python3
"""Compare a candidate TU's data section with retail before giving the unit ownership of it (USA).

  tu_data.py CANDIDATE UNIT SECTION LO [--extra "FLAGS"] [--mw GC/1.3.2]

UNIT supplies the compiler and flags. The compiled SECTION is laid against the retail bytes from LO;
relocated words are masked and listed with their targets. Prints the first differing offsets, or
`SAME n bytes`. tu_own_data.py applies the ownership once the unit is installed.
"""
import argparse, pathlib, shlex, subprocess, sys, tempfile
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig, tu_regions

WORK = tu_regions.WORK


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('candidate'); ap.add_argument('unit'); ap.add_argument('section'); ap.add_argument('lo')
    ap.add_argument('--extra', default=''); ap.add_argument('--mw')
    a = ap.parse_args()
    WORK.mkdir(parents=True, exist_ok=True)
    mw, flags = d.ninja_units()['src/' + a.unit]
    with tempfile.TemporaryDirectory(dir=WORK) as td:
        obj = pathlib.Path(td, 'c.o')
        r = subprocess.run(['build/tools/wibo', f'build/compilers/{a.mw or mw}/mwcceppc.exe'] + shlex.split(flags) +
                           shlex.split(a.extra) + ['-c', a.candidate, '-o', str(obj)], capture_output=True, text=True)
        if r.returncode:
            print(r.stdout[-900:]); return 1
        sig = objsig.sig(obj)
    got = sig['sections'].get(a.section, b'')
    lo = int(a.lo, 16)
    want = tu_regions.reader('GFZE01')(lo, len(got))
    relocs = {o & ~3: t for o, _, t, *_ in sig['relocs'].get(a.section, [])}
    for o in sorted(relocs):
        print(f'  reloc +0x{o:X} -> {relocs[o]}')
    bad = [o for o in range(0, len(got), 4) if o not in relocs and got[o:o + 4] != want[o:o + 4]]
    if not bad:
        print(f'SAME 0x{len(got):X} bytes ({len(relocs)} relocated words masked)')
        return 0
    print(f'{len(bad)} words differ of 0x{len(got):X}; first at +0x{bad[0]:X}')
    for o in bad[:8]:
        print(f'  +0x{o:X} ours {got[o:o + 4].hex()} retail {want[o:o + 4].hex()}')
    return 1


if __name__ == '__main__':
    sys.exit(main())
