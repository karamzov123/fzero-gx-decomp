#!/usr/bin/env python3
"""Safe symbol rename: updates config/GFZE01/symbols.txt + all caller src files.

Usage: tools/rename_sym.py fn_8005FDE0 SndDispatchCommand [fn_x Name ...]
Refuses if old name not found or new name already exists.
"""
import re, sys, subprocess, pathlib

ROOT = pathlib.Path(__file__).resolve().parent.parent
SYM = ROOT / 'config/GFZE01/symbols.txt'
SRC = ROOT / 'src'

def main():
    args = sys.argv[1:]
    assert len(args) % 2 == 0, 'need pairs old new'
    pairs = list(zip(args[::2], args[1::2]))
    symtxt = SYM.read_text()
    # collect files referencing any old name
    targets = {}
    for old, new in pairs:
        assert not re.search(rf'\b{re.escape(new)}\b', symtxt), f'{new} already exists'
        n = len(re.findall(rf'\b{re.escape(old)}\b', symtxt))
        assert n >= 1, f'{old} not in symbols.txt'
        for f in SRC.rglob('*.c'):
            t = f.read_text(errors='ignore')
            if re.search(rf'\b{re.escape(old)}\b', t):
                targets.setdefault(f, []).append((old, new))
    for f, prs in targets.items():
        t = f.read_text()
        for old, new in prs:
            t = re.sub(rf'\b{re.escape(old)}\b', new, t)
        f.write_text(t)
    for old, new in pairs:
        symtxt = re.sub(rf'\b{re.escape(old)}\b', new, symtxt)
    SYM.write_text(symtxt)
    print(f'renamed {len(pairs)} syms across {len(targets)} files')

if __name__ == '__main__':
    main()
