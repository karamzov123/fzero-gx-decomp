#!/usr/bin/env python3
"""Convert numeric lis/addi pairs to named @ha/@l where the retail target is a
scope:global symbol (GLOBAL-NAMED rows from docs/UNIT-STATUS.tsv).

Safety rules (findings/33):
  - only convert when the resolved 32-bit target matches a scope:global symbol
  - verify the @ha split: hi = (target + 0x8000) >> 16 signed-16 encoding
  - one unit at a time; caller runs fresh-build gate after

Usage: tools/convert_global_named.py <unit-name-from-TSV> ...
"""
import os, re, sys, glob

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)
TSV = "docs/UNIT-STATUS.tsv"

# symbols by va -> (name, scope)
by_va = {}
for line in open("config/GFZE01/symbols.txt"):
    m = re.match(r"(\S+)\s*=\s*\.(\w+):0x([0-9A-Fa-f]+);.*?scope:(\w+)", line)
    if m:
        by_va[int(m.group(3), 16)] = (m.group(1), m.group(4))

def sign16(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v

def conv_file(path, targets, addrs_of_interest):
    """targets: set of target VAs to convert. Returns number of conversions."""
    src = open(path).read()
    lines = src.split("\n")
    n = 0
    for i in range(len(lines) - 1):
        lis_m = re.match(r"(\s*)lis\s+(r\d+),\s*(-?0x[0-9a-fA-F]+|\d+)\s*(/\*.*)?$", lines[i])
        if not lis_m:
            continue
        addi_m = re.match(r"(\s*)addi\s+r\d+,\s*(r\d+),\s*(-?0x[0-9a-fA-F]+|\d+)\s*(?:/\*(.*?)\*/)?\s*$", lines[i + 1])
        if not addi_m or addi_m.group(2) != lis_m.group(2):
            continue
        try:
            hi = int(lis_m.group(3), 0) & 0xFFFF
            lo = int(addi_m.group(3), 0) & 0xFFFF
        except ValueError:
            continue
        target = ((hi << 16) + sign16(lo)) & 0xFFFFFFFF
        if target not in targets:
            continue
        name, scope = by_va[target]
        assert scope == "global", f"{path}:{i}: {name} is {scope}"
        # sanity: encoded hi must equal (target+0x8000)>>16
        want_hi = ((target + 0x8000) >> 16) & 0xFFFF
        if want_hi != hi:
            print(f"  SKIP ha-split mismatch {path}:{i+1} {hex(target)}")
            continue
        ind = lis_m.group(1)
        reg = lis_m.group(2)
        lines[i] = f"{ind}lis     {reg}, {name}@ha"
        # rebuild addi preserving dest/src regs
        m2 = re.match(r"(\s*addi\s+(r\d+),\s*(r\d+),)", lines[i + 1])
        lines[i + 1] = f"{m2.group(1)} {name}@l"
        n += 1
        targets.discard(target)
    open(path, "w").write("\n".join(lines))
    return n

def main():
    units = sys.argv[1:]
    rows = [l.split("\t") for l in open(TSV).read().splitlines()[1:]]
    total = 0
    for unit in units:
        targets = set()
        fn_files = {}
        for r in rows:
            if len(r) >= 7 and r[0] == unit and r[5] == "GLOBAL-NAMED":
                for t in r[6].split(";"):
                    t = t.split("@")
                    if len(t) == 2 and t[1].startswith("0x"):
                        va = int(t[1], 16)
                        hit = by_va.get(va)
                        if hit and hit[1] == "global":
                            targets.add(va)
        if not targets:
            print(f"{unit}: no global-named targets"); continue
        # find src file(s) for this unit from configure/splits
        cands = []
        for pat in [unit]:
            base = pat.split("/")[-1]
            cands += glob.glob(f"src/**/{base}.c", recursive=True)
        if not cands:
            # unit name like game/adxt_80055708 -> search splits.txt
            sp = open("config/GFZE01/splits.txt").read()
            m = re.search(rf"^({re.escape(unit)}\.c):", sp, re.M)
            if m:
                cands = ["src/" + m.group(1)]
        if not cands:
            print(f"{unit}: source file not found"); continue
        for path in cands:
            remaining = set(targets)
            n = conv_file(path, remaining, None)
            total += n
            print(f"{unit}: converted {n} sites in {path} ({len(targets)-len(remaining)} of {len(targets)})")
            targets = remaining
    print(f"TOTAL conversions: {total}")

if __name__ == "__main__":
    main()
