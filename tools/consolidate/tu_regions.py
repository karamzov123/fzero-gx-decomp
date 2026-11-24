#!/usr/bin/env python3
"""Compare a candidate TU with retail, function by function, in each region.

  tu_regions.py CANDIDATE UNIT [--extra "FLAGS"] [--mw GC/1.3.2] [--show fn,fn]

UNIT supplies the compiler and flags (for example dol/fn_80012345.c). Relocated words are masked, so
this is a shortlist: the link hash decides. --show prints a retail/candidate disassembly diff (USA).
"""
import argparse, difflib, pathlib, re, shlex, struct, subprocess, sys, tempfile
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, objsig

REGIONS = (('GFZE01', 0), ('GFZJ01', 2), ('GFZP01', 1))
OBJDUMP = 'build/binutils/powerpc-eabi-objdump'
WORK = pathlib.Path('.fzgx/tu_collapse/tmp').resolve()


def reader(version):
    data = open(f'orig/{version}/sys/main.dol', 'rb').read()
    off, addr, size = (struct.unpack('>18I', data[i:i + 72]) for i in (0, 72, 144))
    def read(a, n):
        for o, s, z in zip(off, addr, size):
            if z and s <= a < s + z:
                return data[o + a - s:o + a - s + n]
        return b''
    return read


def disassemble(code):
    with tempfile.NamedTemporaryFile(suffix='.bin', dir=WORK) as f:
        f.write(code); f.flush()
        out = subprocess.run([OBJDUMP, '-D', '-b', 'binary', '-m', 'powerpc:750', '-EB', '-Mgekko', f.name],
                             capture_output=True, text=True).stdout
    return [l.split('\t', 2)[-1].strip() for l in out.splitlines() if '\t' in l and ':' in l.split('\t')[0]]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('candidate'); ap.add_argument('unit'); ap.add_argument('--extra', default='')
    ap.add_argument('--mw'); ap.add_argument('--show', default='')
    a = ap.parse_args()
    WORK.mkdir(parents=True, exist_ok=True)
    mw, flags = d.ninja_units()['src/' + a.unit]
    mw = a.mw or mw
    show = set(filter(None, a.show.split(',')))
    for version, number in REGIONS:
        cflags = re.sub(r'-DBUILD_VERSION=\d+', f'-DBUILD_VERSION={number}', flags).replace('-DVERSION_GFZE01', f'-DVERSION_{version}')
        with tempfile.TemporaryDirectory(dir=WORK) as td:
            obj = pathlib.Path(td, 'c.o')
            r = subprocess.run(['build/tools/wibo', f'build/compilers/{mw}/mwcceppc.exe'] + shlex.split(cflags) +
                               shlex.split(a.extra) + ['-c', a.candidate, '-o', str(obj)], capture_output=True, text=True)
            if r.returncode:
                print(version, 'compile failed'); print(r.stdout[-900:]); return 1
            sig = objsig.sig(obj)
        text = sig['sections'].get('.text', b'')
        masked = {o & ~3 for o, _, _, _ in sig['relocs'].get('.text', [])}
        symbols = {}
        for line in open(f'config/{version}/symbols.txt'):
            m = re.match(r'(\S+) = \.text:0x([0-9A-Fa-f]+)', line)
            if m:
                symbols[m[1]] = int(m[2], 16)
        read = reader(version)
        total, bad, missing = 0, [], []
        for name, sec, at, size, _ in sorted(sig['defs'], key=lambda x: x[2]):
            if sec != '.text' or not size:
                continue
            if name not in symbols:
                missing.append(name); continue
            total += 1
            retail = read(symbols[name], size)
            words = [i for i in range(0, size, 4) if at + i not in masked and text[at + i:at + i + 4] != retail[i:i + 4]]
            if words:
                bad.append((name, len(words)))
            if name in show and version == 'GFZE01':
                for row in difflib.unified_diff(disassemble(retail), disassemble(text[at:at + size]), lineterm='', n=1):
                    if not row.startswith(('---', '+++')):
                        print('  ', row)
        print(version, 'functions', total, 'differ', bad, 'no symbol', missing)
    return 0


if __name__ == '__main__':
    sys.exit(main())
