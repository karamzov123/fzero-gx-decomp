#!/usr/bin/env python3
"""Extract function byte blobs from an MWCC-generated ELF32 big-endian object.

Usage: python3 tools/elf_func_bytes.py <object-file> [function-name ...]
Prints one JSON line per requested function (or all sized functions):
    {"name": ..., "offset": ..., "size": ..., "hex": "..."}
Also writes <obj>.<name>.bin next to the object for byte-diff workflows.
"""
import json
import struct
import sys


def sections(data):
    e_shoff = struct.unpack(">I", data[0x20:0x24])[0]
    ents = struct.unpack(">H", data[0x2E:0x30])[0]
    num = struct.unpack(">H", data[0x30:0x32])[0]
    strndx = struct.unpack(">H", data[0x32:0x34])[0]

    def sh(i):
        o = e_shoff + i * ents
        f = struct.unpack(">IIIIIIIIII", data[o:o + 40])
        return dict(name=f[0], type=f[1], off=f[4], size=f[5], link=f[6])

    strtab = sh(strndx)

    def nm(s):
        n = data[strtab["off"] + s["name"]:]
        return n[:n.index(b"\0")].decode()

    return {nm(sh(i)): sh(i) for i in range(num)}


def main():
    path = sys.argv[1]
    wanted = set(sys.argv[2:])
    data = open(path, "rb").read()
    secs_list = []
    e_shoff = struct.unpack(">I", data[0x20:0x24])[0]
    ents = struct.unpack(">H", data[0x2E:0x30])[0]
    num = struct.unpack(">H", data[0x30:0x32])[0]
    strndx = struct.unpack(">H", data[0x32:0x34])[0]
    for i in range(num):
        o = e_shoff + i * ents
        f = struct.unpack(">IIIIIIIIII", data[o:o + 40])
        secs_list.append(dict(name=f[0], type=f[1], off=f[4], size=f[5], link=f[6]))
    strtab = secs_list[strndx]

    def nm(s):
        n = data[strtab["off"] + s["name"]:]
        return n[:n.index(b"\0")].decode()

    secs = {nm(s): s for s in secs_list}
    text = secs[".text"]
    tb = data[text["off"]:text["off"] + text["size"]]
    symtab = secs[".symtab"]
    strt = secs_list[symtab["link"]]
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
        blob = tb[v:v + sz]
        open(f"{path}.{name}.bin", "wb").write(blob)
        out.append(dict(name=name, offset=v, size=sz, hex=blob.hex()))
    print(json.dumps(out))


if __name__ == "__main__":
    main()
