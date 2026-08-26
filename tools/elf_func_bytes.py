#!/usr/bin/env python3
"""Extract function byte blobs from an MWCC-generated ELF32 big-endian object.

Usage: python3 tools/elf_func_bytes.py <object-file> [function-name ...]
Prints one JSON line per requested function (or all sized functions in an
executable section):
    {"name": ..., "offset": ..., "size": ..., "hex": "..."}
When function names are given, also writes <obj>.<name>.bin next to the object
for byte-diff workflows.

Three things this deliberately does NOT do, each of which it used to:

* It does not assume the code section is called `.text`. The `os/init/*` and
  `metrotrk/init_exceptions` units carry their code in `.init`, so a hardcoded
  `.text` lookup raised KeyError on 10 of the 195 units -- and every caller
  treats a crash as "no symbols", which silently removed those units from the
  mission metric.
* It does not report data as functions. Symbols were previously taken from the
  whole symbol table with their bytes sliced out of `.text` at the data
  symbol's own value, so `.data`/`.bss` symbols came back as functions holding
  unrelated bytes. `func_symbols()` in natc_metrics.py exists precisely to
  reject data symbols, and this defeated it. A symbol now counts only if its
  st_shndx names a section with SHF_EXECINSTR, and its bytes come from THAT
  section. Symbol type is not used as the filter: MWCC emits some real
  functions as STT_NOTYPE, and the section flag is the reliable signal.
* It does not spray .bin files. Called with no name filter -- which is how
  natc_metrics.py calls it, 195 times per run -- it used to write one .bin per
  symbol into build/GFZE01/obj/, the dtk-split ground truth the gate is not
  allowed to touch. That had reached 2,345 files. The blobs are only written
  when a caller actually asks for named functions.
"""
import json
import struct
import sys

SHF_EXECINSTR = 0x4


def read_sections(data):
    e_shoff = struct.unpack(">I", data[0x20:0x24])[0]
    ents = struct.unpack(">H", data[0x2E:0x30])[0]
    num = struct.unpack(">H", data[0x30:0x32])[0]
    strndx = struct.unpack(">H", data[0x32:0x34])[0]
    secs = []
    for i in range(num):
        o = e_shoff + i * ents
        f = struct.unpack(">IIIIIIIIII", data[o:o + 40])
        secs.append(dict(name=f[0], type=f[1], flags=f[2], off=f[4],
                         size=f[5], link=f[6]))
    shstr = secs[strndx]

    def nm(s):
        n = data[shstr["off"] + s["name"]:]
        return n[:n.index(b"\0")].decode()

    for s in secs:
        s["sname"] = nm(s)
    return secs


def main():
    path = sys.argv[1]
    wanted = set(sys.argv[2:])
    data = open(path, "rb").read()
    secs = read_sections(data)
    by_name = {s["sname"]: s for s in secs}

    symtab = by_name.get(".symtab")
    if symtab is None:
        print("[]")
        return
    strt = secs[symtab["link"]]

    out = []
    for i in range(symtab["size"] // 16):
        o = symtab["off"] + i * 16
        n, v, sz, info, other, shn = struct.unpack(">IIIBBH", data[o:o + 16])
        raw = data[strt["off"] + n:]
        name = raw[:raw.index(b"\0")].decode()
        if not name or sz == 0:
            continue
        if wanted and name not in wanted:
            continue
        # SHN_UNDEF/ABS/COMMON and any non-code section: not a function body.
        if shn == 0 or shn >= len(secs):
            continue
        host = secs[shn]
        if not (host["flags"] & SHF_EXECINSTR):
            continue
        blob = data[host["off"] + v:host["off"] + v + sz]
        if wanted:
            open(f"{path}.{name}.bin", "wb").write(blob)
        out.append(dict(name=name, offset=v, size=sz, hex=blob.hex()))
    print(json.dumps(out))


if __name__ == "__main__":
    main()
