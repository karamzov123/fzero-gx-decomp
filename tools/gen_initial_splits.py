#!/usr/bin/env python3
"""Generate an initial per-unit splits.txt from the analyzed symbols.txt.

One unit per function (funcs/<name>.c) plus contiguous data chunks bounded by
alignment-rounded object starts. Section extents are derived from the symbol
table (max symbol end per section), which matches what dtk validates against.
This exists only to get the M0 asm-only link green with objects small enough
for mwld; units get regrouped into real source files as matching progresses.
"""
import re
import sys
from collections import defaultdict

sym_path = sys.argv[1] if len(sys.argv) > 1 else "config/GFZE01/symbols.txt"
out_path = sys.argv[2] if len(sys.argv) > 2 else "config/GFZE01/splits.txt"

SYM_RE = re.compile(r"^(.*?) = (\.\w+):0x([0-9A-Fa-f]+);.*type:(\w+) size:0x([0-9A-Fa-f]+)")

# section -> (dtk type, align, hard start). Starts are DOL-backed ranges;
# ends come from symbol extents below.
SECTIONS = {
    ".init": ("code", 4, 0x80003100),
    ".text": ("code", 32, 0x800055E0),
    ".ctors": ("rodata", 32, 0x8008FF00),
    ".dtors": ("rodata", 32, 0x8008FF20),
    ".rodata": ("rodata", 32, 0x8008FF40),
    ".data": ("data", 32, 0x80095EA0),
    ".bss": ("bss", 8, 0x8015B920),
    ".sdata": ("data", 32, 0x801A63C0),
    ".sbss": ("bss", 32, 0x801A66A0),
    ".sdata2": ("data", 32, 0x801A6E40),
    ".sbss2": ("bss", 4, 0x801A7900),
}

syms = []
with open(sym_path) as f:
    for line in f:
        m = SYM_RE.match(line.strip())
        if not m:
            continue
        name, sec, addr, typ, size = m.groups()
        syms.append((name, sec, int(addr, 16), typ, int(size, 16)))

extents = defaultdict(lambda: [1 << 62, 0])
for _, sec, addr, _, size in syms:
    e = extents[sec]
    e[0] = min(e[0], addr)
    e[1] = max(e[1], addr + size)

units = defaultdict(list)  # unit name -> [(sec, start, end)]

# Functions: one unit each.
for name, sec, addr, typ, size in sorted(
    (s for s in syms if s[3] == "function" and s[4] > 0), key=lambda s: (s[1], s[2])
):
    units[f"funcs/{name}.c"].append((sec, addr, addr + size))

# Data: one unit per contiguous NON-FUNCTION region ("gap") within each
# section's extent, split at aligned points so no unit exceeds MAX_CHUNK.
funcs_by_sec = defaultdict(list)
objs_by_sec = defaultdict(list)
for name, sec, addr, typ, size in syms:
    if sec not in SECTIONS or size <= 0:
        continue
    if typ == "function":
        funcs_by_sec[sec].append((addr, addr + size))
    else:
        objs_by_sec[sec].append((addr, size))

MAX_CHUNK = 0x8000


def align_dn(x, a):
    return x & ~(a - 1)


for sec, fintervals in funcs_by_sec.items():
    _, sec_align, hard_start = SECTIONS[sec]
    start = min(hard_start, extents[sec][0])
    end = extents[sec][1]
    if end <= start:
        continue
    fmerged = []
    for a, b in sorted(fintervals):
        if fmerged and a <= fmerged[-1][1]:
            fmerged[-1][1] = max(fmerged[-1][1], b)
        else:
            fmerged.append([a, b])
    # Gaps between functions within [start, end).
    gaps = []
    cur = start
    for a, b in fmerged:
        if a > cur:
            gaps.append((cur, min(a, end)))
        cur = max(cur, b)
        if cur >= end:
            break
    if cur < end:
        gaps.append((cur, end))
    # Split large gaps at aligned interior points.
    for g0, g1 in gaps:
        p = g0
        while p < g1:
            nxt = min(align_dn(p + MAX_CHUNK, sec_align) + sec_align, g1)
            if nxt <= p:
                nxt = g1
            units[f"data/{sec.lstrip('.')}_{p:X}.c"].append((sec, p, min(nxt, g1)))
            p = nxt

with open(out_path, "w") as f:
    f.write("Sections:\n")
    for sec, (typ, align, _) in SECTIONS.items():
        f.write(f"\t{sec:<12}type:{typ} align:{align}\n")
    f.write("\n")
    for unit in sorted(units):
        f.write(f"{unit}:\n")
        for sec, start, end in sorted(units[unit]):
            f.write(f"\t{sec:<12}start:0x{start:X} end:0x{end:X}\n")

print(f"wrote {out_path}: {len(units)} units")
