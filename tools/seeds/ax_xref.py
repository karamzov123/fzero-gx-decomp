#!/usr/bin/env python3
"""Cross-reference GX main.dol functions with the F-Zero AX reference build (evidence only).

AX (GFZJ8P) is a separate build of the same engine. A dtk split of its main.dol (a scratch
project outside the repository) gives function boundaries and relocations; AX functions that
reference a `*.c` string carry their source file. GX functions whose masked instruction
sequence equals an AX function's inherit that file as TU evidence. Only addresses, names and
counts are written; no AX bytes leave the scratch directory.

Masking keeps primary/extended opcodes and register fields, and clears 16-bit immediates and
branch displacements, so differences in data addresses, literal-pool offsets and link layout
do not matter while compiler output (same source, same compiler) still has to agree.

Usage: uv run tools/seeds/ax_xref.py --ax-split DIR [--version GFZE01]
       [--out state/tumap/GFZE01_main_ax.json]
DIR is a `dtk dol split` project of the AX main.dol (config.yml, symbols.txt, out/obj/*.o).
"""
from __future__ import annotations

import argparse
import hashlib
import json
import re
import struct
import subprocess
import sys
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
D_FORM = set(range(32, 56)) | {7, 8, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29}


def mask(word: int) -> int:
    op = word >> 26
    if op == 18:                      # b/bl: keep AA/LK only
        return (op << 26) | (word & 3)
    if op == 16:                      # bc: keep BO/BI/AA/LK
        return word & 0xFFFF0003
    if op in D_FORM:                  # D-form: keep opcode + registers, clear the immediate
        return word & 0xFFFF0000
    return word


class Dol:
    def __init__(self, path: Path):
        self.data = path.read_bytes()
        h = struct.unpack(">18I18I18I", self.data[:0xD8])
        self.segs = [(a, o, s) for o, a, s in zip(h[0:18], h[18:36], h[36:54]) if s]

    def read(self, addr: int, n: int) -> bytes:
        for a, o, s in self.segs:
            if a <= addr < a + s:
                return self.data[o + addr - a: o + min(addr - a + n, s)]
        return b""


def funcs(symbols: Path):
    out = []
    for line in symbols.read_text().splitlines():
        m = re.match(r"(\S+) = \.text:0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)", line)
        if m:
            out.append((int(m.group(2), 16), int(m.group(3), 16), m.group(1)))
    return sorted(out)


def sig(dol: Dol, addr: int, size: int) -> str:
    b = dol.read(addr, size)
    words = [mask(w) for w in struct.unpack(f">{len(b) // 4}I", b[: len(b) // 4 * 4])]
    return hashlib.sha1(struct.pack(f">{len(words)}I", *words)).hexdigest()


def ax_file_refs(split: Path, dol: Dol, ax_funcs):
    """AX function name -> source file, from relocations of the split objects to `*.c` strings."""
    objs = list((split / "out" / "obj").rglob("*.o"))
    cstr = {}
    for o in objs:
        s = subprocess.run(["readelf", "-sW", str(o)], capture_output=True, text=True).stdout
        for ln in s.splitlines():
            p = ln.split()
            if len(p) >= 8 and p[3] == "OBJECT":
                pass
    # string objects by address: scan data segments for *.c strings, map address -> name
    for a, off, size in dol.segs:
        seg = dol.data[off: off + size]
        for m in re.finditer(rb"(?<=\x00)(?:[^\x00]{0,40}/)?([A-Za-z0-9_]{2,40}\.c)\x00", seg):
            cstr[a + m.start()] = m.group(1).decode()
    byname = {n: (a, s) for a, s, n in ax_funcs}
    out = defaultdict(set)
    for o in objs:
        syms = {}
        s = subprocess.run(["readelf", "-sW", str(o)], capture_output=True, text=True).stdout
        idx_name = {}
        for ln in s.splitlines():
            p = ln.split()
            if len(p) >= 8 and p[0].rstrip(":").isdigit():
                idx_name[int(p[0].rstrip(":"))] = p[7]
                syms[p[7]] = p
        r = subprocess.run(["readelf", "-rW", str(o)], capture_output=True, text=True).stdout
        cur = None
        for ln in r.splitlines():
            if ln.startswith("Relocation section"):
                cur = ".text" if "'.rela.text'" in ln else None
                continue
            p = ln.split()
            if cur != ".text" or len(p) < 5:
                continue
            tgt = p[4]
            m = re.match(r"lbl_([0-9A-F]{8})$", tgt)
            if not m:
                continue
            addr = int(m.group(1), 16)
            try:
                add = int(p[-1], 16) if len(p) > 6 and p[-2] == "+" else 0
            except ValueError:
                add = 0
            name = cstr.get(addr + add) or cstr.get(addr)
            if not name:
                continue
            off = int(p[0], 16)
            for fn, (fa, fs) in byname.items():
                pass
            out[(o.name, off)] .add(name)
    return out


def main(argv=None) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--ax-split", required=True)
    ap.add_argument("--version", default="GFZE01")
    ap.add_argument("--out", default="state/tumap/GFZE01_main_ax.json")
    a = ap.parse_args(argv)
    split = Path(a.ax_split)
    axdol = Dol(split / "main.dol")
    gxdol = Dol(ROOT / "orig" / a.version / "sys" / "main.dol")
    ax_funcs = funcs(split / "symbols.txt")
    gx_funcs = funcs(ROOT / "config" / a.version / "symbols.txt")
    ax_sig = defaultdict(list)
    for addr, size, n in ax_funcs:
        if size >= 16:
            ax_sig[sig(axdol, addr, size)].append(addr)
    # AX source-file references, by text address: scan AX text for lis/addi pairs is unreliable,
    # so use dtk's relocations from the split objects (offsets are per object; map via asm labels)
    file_at = ax_text_file_refs(split, axdol)
    matches, unique = {}, 0
    for addr, size, n in gx_funcs:
        if size < 16:
            continue
        hits = ax_sig.get(sig(gxdol, addr, size), [])
        if len(hits) == 1:
            unique += 1
            ax = hits[0]
            ax_size = next(s for a2, s, _ in ax_funcs if a2 == ax)
            files = sorted({f for (fa, f) in file_at if ax <= fa < ax + ax_size})
            matches[n] = {"gx": f"{addr:08X}", "ax": f"{ax:08X}", "files": files}
    with_file = {k: v for k, v in matches.items() if v["files"]}
    out = {"version": a.version, "reference": "F-Zero AX GFZJ8P main.dol (owner-supplied; not committed)",
           "summary": {"gx_functions": len(gx_funcs), "ax_functions": len(ax_funcs),
                       "unique_matches": unique, "with_source_file": len(with_file)},
           "matches": matches}
    p = ROOT / a.out
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(json.dumps(out, indent=1) + "\n")
    print(json.dumps(out["summary"]))
    return 0


def ax_text_file_refs(split: Path, dol: Dol):
    """(AX text address, file) for every instruction that references the data object containing
    a `*.c` string. A TU's .data block is private to it, and MWCC reaches strings through the
    block's base symbol plus an offset, so the containing object is the reliable handle."""
    objs = []
    for line in (split / "symbols.txt").read_text().splitlines():
        m = re.match(r"(lbl_[0-9A-F]{8}) = \.(?:data|rodata|sdata):0x([0-9A-Fa-f]+); // type:object size:0x([0-9A-Fa-f]+)", line)
        if m:
            objs.append((int(m.group(2), 16), int(m.group(3), 16), m.group(1)))
    objs.sort()
    import bisect
    starts = [o[0] for o in objs]
    holder = {}
    for a, off, size in dol.segs:
        seg = dol.data[off: off + size]
        for m in re.finditer(rb"([A-Za-z0-9_]{2,40}\.c)\x00", seg):
            addr = a + m.start(1)
            k = bisect.bisect_right(starts, addr) - 1
            if k >= 0 and objs[k][0] <= addr < objs[k][0] + objs[k][1]:
                holder.setdefault(objs[k][2], set()).add(m.group(1).decode())
    out = set()
    for s in (split / "out" / "asm").rglob("*.s"):
        for ln in s.read_text(errors="ignore").splitlines():
            m = re.match(r"\s*/\*\s*([0-9A-F]{8})\s", ln)
            if not m:
                continue
            for sym in re.findall(r"(lbl_[0-9A-F]{8})(?:\+0x[0-9A-F]+)?@", ln):
                for f in holder.get(sym, ()):
                    out.add((int(m.group(1), 16), f))
    return out


if __name__ == "__main__":
    sys.exit(main())
