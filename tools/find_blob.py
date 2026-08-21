#!/usr/bin/env python3
"""Locate function byte-blobs (from MWCC .o probes) inside a linked DOL.

Relocation slots (bl targets) differ between object and linked image, so a
match tolerates up to --max-diff differing bytes, and only inside 32-bit
words whose top byte is an unconditional-branch opcode (0x48..0x4B =
b/bl/ba/bla) in BOTH the blob and the DOL. Tolerant scanning is done at
4-byte alignment (PowerPC code granularity); exact scanning covers every
offset.

Usage:
    python3 tools/find_blob.py <file.dol> <blob.bin> [<blob2.bin> ...]
                               [--prefix N] [--max-diff 12]

Prints one JSON object per blob:
    {"blob": "...", "results": [
        {"mode": "full"|"prefix16", "size": n,
         "exact": [hit...], "tolerant": [hit...]}]}
where hit = {"file_off": int, "vaddr": int|null, "diffs": n, "diff_pos": [...]}
(vaddr null when the hit falls outside all DOL sections).
"""
import json
import struct
import sys

BRANCH_TOP = frozenset(b"\x48\x49\x4a\x4b")


def dol_sections(dol):
    offs = struct.unpack(">18I", dol[0x00:0x48])
    addrs = struct.unpack(">18I", dol[0x48:0x90])
    sizes = struct.unpack(">18I", dol[0x90:0xD8])
    return [(offs[i], addrs[i], sizes[i]) for i in range(18) if sizes[i]]


def off_to_vaddr(secs, off):
    for o, a, s in secs:
        if o <= off < o + s:
            return a + (off - o)
    return None


def scan_exact(dol, needle):
    hits, start = [], 0
    while True:
        i = dol.find(needle, start)
        if i < 0:
            return hits
        hits.append(i)
        start = i + 1


def scan_tolerant(dol, blob, max_diff):
    n = len(blob)
    target = int.from_bytes(blob, "big")
    hits = []
    for pos in range(0, len(dol) - n + 1, 4):
        x = int.from_bytes(dol[pos:pos + n], "big") ^ target
        if x == 0:
            continue
        nb = x.to_bytes(n, "big")
        positions = [i for i, b in enumerate(nb) if b]
        if len(positions) > max_diff:
            continue
        if not all(blob[p & ~3] in BRANCH_TOP
                   and dol[pos + (p & ~3)] in BRANCH_TOP
                   for p in positions):
            continue
        hits.append((pos, len(positions), positions))
    return hits


def main():
    args = sys.argv[1:]
    prefix = 16
    max_diff = 12
    rest = []
    it = iter(args)
    for a in it:
        if a == "--prefix":
            prefix = int(next(it))
        elif a.startswith("--prefix="):
            prefix = int(a.split("=", 1)[1])
        elif a == "--max-diff":
            max_diff = int(next(it))
        elif a.startswith("--max-diff="):
            max_diff = int(a.split("=", 1)[1])
        else:
            rest.append(a)
    dol_path, blobs = rest[0], rest[1:]

    dol = open(dol_path, "rb").read()
    secs = dol_sections(dol)

    def pack(off, ndiff=0, positions=None):
        return {"file_off": off,
                "vaddr": off_to_vaddr(secs, off),
                "diffs": ndiff,
                "diff_pos": positions or []}

    out = []
    for path in blobs:
        blob = open(path, "rb").read()
        results = []
        for mode, needle in (("full", blob),
                             (f"prefix{prefix}", blob[:prefix])):
            ex = scan_exact(dol, needle)
            tol = scan_tolerant(dol, needle, max_diff)
            tol = [t for t in tol if t[0] not in ex]
            results.append({
                "mode": mode,
                "size": len(needle),
                "exact": [pack(o) for o in ex],
                "tolerant": [pack(o, d, ps) for o, d, ps in tol],
            })
        out.append({"blob": path, "results": results})
    print(json.dumps(out))


if __name__ == "__main__":
    main()
