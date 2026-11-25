#!/usr/bin/env python3
"""Print the .text function order (and sizes) a candidate compiles to, beside retail's order.

  tu_order.py CANDIDATE UNIT [--extra "FLAGS"] [--mw GC/1.3.2]

UNIT supplies the compiler and flags. A TU must emit its functions in retail address order;
tu_regions.py compares by name and cannot see the order (MSL's -inline deferred reverses it).
"""
import argparse, pathlib, re, shlex, subprocess, sys, tempfile
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig, tu_regions


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('candidate'); ap.add_argument('unit'); ap.add_argument('--extra', default=''); ap.add_argument('--mw')
    a = ap.parse_args()
    mw, flags = d.ninja_units()['src/' + a.unit]
    tu_regions.WORK.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(dir=tu_regions.WORK) as td:
        obj = pathlib.Path(td, 'c.o')
        r = subprocess.run(['build/tools/wibo', f'build/compilers/{a.mw or mw}/mwcceppc.exe'] + shlex.split(flags) +
                           shlex.split(a.extra) + ['-c', a.candidate, '-o', str(obj)], capture_output=True, text=True)
        if r.returncode:
            print(r.stdout[-900:]); return 1
        sig = objsig.sig(obj)
    retail = {m[1]: int(m[2], 16) for m in re.finditer(r'^(\S+) = \.text:0x(\w+);', open('config/GFZE01/symbols.txt').read(), re.M)}
    ours = sorted((v, n, sz) for n, s, v, sz, _ in sig['defs'] if s == '.text' and sz)
    want = sorted((retail[n], n) for _, n, _ in ours if n in retail)
    for (off, n, sz), w in zip(ours, want + [(0, '')] * len(ours)):
        print(f'  +0x{off:04X} {n:32} size 0x{sz:X}   retail order: {w[1]}{"" if n == w[1] else "   <-- differs"}')
    return 0


if __name__ == '__main__':
    sys.exit(main())
