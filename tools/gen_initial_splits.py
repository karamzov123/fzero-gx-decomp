#!/usr/bin/env python3
"""Generate the coarse initial splits used by the M0 asm-only baseline.

The GC/1.3 linker reproduces the retail startup metadata exactly, but becomes
pathologically slow with one object per function (~2200 objects).  GC/2.7 can
link that layout quickly, but emits five different startup-table bytes.  M0
therefore groups each section into roughly 0x8000-byte units without cutting
through an analyzed symbol.  Real source files replace these coarse units as
decompilation progresses.
"""

import re
import sys
from collections import defaultdict

sym_path = sys.argv[1] if len(sys.argv) > 1 else "config/GFZE01/symbols.txt"
out_path = sys.argv[2] if len(sys.argv) > 2 else "config/GFZE01/splits.txt"

SYM_RE = re.compile(
    r"^(.*?) = (\.\w+):0x([0-9A-Fa-f]+);.*type:(\w+) size:0x([0-9A-Fa-f]+)"
)

# section -> (dtk type, alignment, DOL-backed start)
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
    ".sdata2": ("rodata", 32, 0x801A6E40),
    ".sbss2": ("bss", 4, 0x801A7900),
}
MAX_CHUNK = 0x8000
LINKER_GENERATED_SYMBOLS = {"_rom_copy_info", "_bss_init_info"}

symbols = defaultdict(list)
with open(sym_path) as f:
    for line in f:
        match = SYM_RE.match(line.strip())
        if not match:
            continue
        name, section, address, symbol_type, size = match.groups()
        size_int = int(size, 16)
        # MWLink synthesizes these startup tables from the final section set;
        # they must not become input ranges in splits.txt.
        if (
            section in SECTIONS
            and size_int > 0
            and name not in LINKER_GENERATED_SYMBOLS
        ):
            symbols[section].append(
                (name, int(address, 16), int(address, 16) + size_int, symbol_type)
            )


def align_up(value, alignment):
    return (value + alignment - 1) & ~(alignment - 1)


units = []
# dtk writes DOL input units in reverse section order for MWLink while keeping
# ranges within each section ascending; emit that stable order directly.
for section, (_, alignment, start) in reversed(SECTIONS.items()):
    section_symbols = symbols[section]
    end = max((symbol_end for _, _, symbol_end, _ in section_symbols), default=start)
    intervals = sorted((symbol_start, symbol_end) for _, symbol_start, symbol_end, _ in section_symbols)

    position = start
    while position < end:
        chunk_end = min(align_up(position + MAX_CHUNK, alignment), end)
        # Move a proposed boundary forward until it no longer intersects a
        # symbol. Some early data symbols are opaque and hundreds of KiB long.
        while chunk_end < end:
            containing = next(
                (
                    (symbol_start, symbol_end)
                    for symbol_start, symbol_end in intervals
                    if symbol_start < chunk_end < symbol_end
                ),
                None,
            )
            if containing is None:
                break
            chunk_end = min(align_up(containing[1], alignment), end)

        units.append((f"coarse/{section[1:]}_{position:X}.c", section, position, chunk_end))
        position = chunk_end

with open(out_path, "w") as f:
    f.write("Sections:\n")
    for section, (section_type, alignment, _) in SECTIONS.items():
        f.write(f"\t{section:<12}type:{section_type} align:{alignment}\n")
    f.write("\n")
    for index, (unit, section, start, end) in enumerate(units):
        f.write(f"{unit}:\n")
        f.write(f"\t{section:<12}start:0x{start:X} end:0x{end:X}\n")
        if index != len(units) - 1:
            f.write("\n")

print(f"wrote {out_path}: {len(units)} coarse units")
