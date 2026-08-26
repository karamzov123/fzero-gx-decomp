#!/usr/bin/env python3
"""Convert numeric lis/addi address pairs in src/**/*.c asm bodies to named
symbol @ha/@l relocations so objdiff relocation-shape scoring matches retail.

Usage: python3 tools/fix_reloc_pairs.py [--all | file.c ...]
  default: only units with >=99% fuzzy but <100% matched fns (near-miss)
  --all:   every unit in the repo

See findings + Session 19 ledger entry: numeric pairs link byte-identically but
objdiff scores relocation shape; mismatched shape caps fuzzy_match below 100.

After running: add missing extern decls (compiler errors name them), rebuild,
verify sha1 gate AND rm build/GFZE01/report.json to avoid stale per-unit counts.
"""
import re, sys, json, pathlib

ROOT = pathlib.Path(__file__).resolve().parent.parent
SYM = {}
for line in open(ROOT / 'config/GFZE01/symbols.txt'):
    m = re.match(r'(\S+) = \.(?:text|data|rodata|sdata|sdata2|bss|sbss):0x([0-9A-Fa-f]+)', line.strip())
    if m:
        SYM.setdefault(int(m.group(2), 16) & 0xFFFFFFFF, m.group(1))

REPORT = ROOT / 'build/GFZE01/report.json'


def near_miss_sources():
    srcs = set()
    if REPORT.exists():
        r = json.load(open(REPORT))
        for u in r['units']:
            src = u['metadata'].get('source_path')
            for f in u.get('functions', []):
                fp = f.get('fuzzy_match_percent') or 0
                if 99.0 <= fp < 100.0 and src:
                    srcs.add(src)
    return srcs


def fix_file(p):
    lines = p.read_text(errors='ignore').split('\n')
    out = lines[:]
    n = 0
    i = 0
    while i < len(lines):
        ma = re.match(r'(\s*)lis\s+(r\d+), (-?0x[0-9A-Fa-f]+|\d+)\s*(?:/\*.*\*/)?\s*$', lines[i])
        if not ma:
            i += 1
            continue
        reg = ma.group(2)
        try:
            base = (int(ma.group(3), 16) if ma.group(3).startswith(('0x', '-0x')) else int(ma.group(3))) & 0xFFFF
        except ValueError:
            i += 1
            continue
        done = False
        for j in range(i + 1, min(i + 12, len(lines))):
            mb = re.match(r'(\s*)addi\s+(r\d+), ' + reg + r', (-?0x[0-9a-fA-F]+|\d+)\s*(?:/\*.*)?\s*$', out[j])
            if mb:
                off_s = mb.group(3)
                off = int(off_s, 16) if off_s.startswith(('0x', '-0x')) else int(off_s)
                nm = SYM.get(((base << 16) + off) & 0xFFFFFFFF)
                if nm and not nm.startswith('fn_') and re.match(r'^[A-Za-z_][A-Za-z0-9_]*$', nm):
                    comment = ''
                    if '/*' in lines[j]:
                        comment = ' /*' + lines[j].split('/*', 1)[1]
                    out[i] = f'{ma.group(1)}lis     {reg}, {nm}@ha'
                    out[j] = f'{mb.group(1)}addi    {reg}, {reg}, {nm}@l{comment}'
                    n += 1
                done = True
                break
            # bail out if register is clobbered before the addi
            if re.search(r'\bmr\s+' + reg + r',', lines[j]) or re.match(r'\s*lis\s+' + reg + r',', lines[j]):
                break
        i += 1
    if n:
        p.write_text('\n'.join(out))
    return n


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('-')]
    if '--all' in sys.argv or args:
        files = [ROOT / a for a in args] if args else sorted(ROOT.glob('src/**/*.c'))
    else:
        files = sorted(near_miss_sources())
    total = 0
    for f in files:
        pp = pathlib.Path(f)
        p = pp if pp.is_absolute() else ROOT / pp
        if p.exists() and p.suffix == '.c':
            total += fix_file(p)
    print(f'converted {total} lis/addi pairs')


if __name__ == '__main__':
    main()
