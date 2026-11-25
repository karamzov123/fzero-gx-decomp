#!/usr/bin/env python3
"""Rewrite DOL standalone assembly units as CodeWarrior `asm` functions for a C TU.

  s2cw.py dol/NAME.s [dol/OTHER.s ...] > fragment.c

Each `.fn` of the dtk-style `.s` becomes `asm void NAME(void) { nofralloc ... }`, with the real
symbol name and scope from config/GFZE01/symbols.txt (dtk suffixes local names with their
address in the .s), `.L_ADDR` labels as `L_ADDR`, paired-single `qrN` operands as `N` and
condition-register bit names as numbers. Signatures are placeholders: give each function its
real prototype afterwards (parameter names may then replace registers). The output is a
draft. Compare the TU with tu_regions.py; its bytes, and then the link hash, are the proof.
"""
import re, sys, pathlib

CRBIT = {'lt': 0, 'gt': 1, 'eq': 2, 'so': 3, 'un': 3}


def symbols():
    out = {}
    for line in open('config/GFZE01/symbols.txt'):
        m = re.match(r'(\S+) = \.\w+:0x([0-9A-F]+); //.*?type:function(.*)', line)
        if m:
            out[int(m[2], 16)] = (m[1], 'scope:local' in m[3])
    return out


def operand(text):
    text = re.sub(r'\.L_([0-9A-F]+)', r'L_\1', text)
    text = re.sub(r'\bqr([0-7])\b', r'\1', text)
    text = re.sub(r'\bcr([0-7])(lt|gt|eq|so|un)\b', lambda m: str(4 * int(m[1]) + CRBIT[m[2]]), text)
    return text


def convert(path, syms):
    lines = pathlib.Path(path).read_text().splitlines()
    out, name, local = [], None, False
    for line in lines:
        if line.startswith('.fn '):
            raw = line.split()[1].rstrip(',')
            addr = None
            for nxt in lines[lines.index(line) + 1:]:
                m = re.match(r'/\* ([0-9A-F]{8}) ', nxt)
                if m:
                    addr = int(m[1], 16)
                    break
            name, local = syms.get(addr, (raw, False))
            out.append(f'{"static " if local else ""}asm void {name}(void) {{')
            out.append('    nofralloc')
        elif line.startswith('.endfn'):
            out.append('}')
            out.append('')
            name = None
        elif name and re.match(r'\.L_[0-9A-F]+:', line):
            out.append(operand(line.rstrip(':')) + ':')
        elif name and line.startswith('/*'):
            insn = line.split('*/', 1)[1].strip()
            out.append('    ' + operand(insn))
        elif name and line.strip() and not line.startswith('#'):
            raise SystemExit(f'{path}: unsupported line inside {name}: {line!r}')
    # function-name suffixes dtk gave local callees
    text = '\n'.join(out)
    for addr, (real, _) in syms.items():
        text = text.replace(f'{real}_{addr:08X}', real)
    return text


def main():
    syms = symbols()
    for p in sys.argv[1:]:
        print(convert(p if p.startswith('src/') else 'src/' + p, syms))


if __name__ == '__main__':
    main()
