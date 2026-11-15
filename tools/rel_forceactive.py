#!/usr/bin/env python3
"""Write the linker command file of a REL partial link that dead-strips.

Usage: rel_forceactive.py IN.lcf OUT.lcf @OBJECTS.rsp

The retail RELs were linked with dead-stripping: a static function that the compiler inlined
at every call is not in the retail code, but the literals it created are still at the place of
its definition (replay .rodata 0x0, main_rel .data 0x1EF68). Every shipped MWCC emits the code
of such a function, so only the link can have removed it. A function with no caller is still
in retail (main_rel fn_1_8CA20). The roots of the original link are not known. This script
assumes that they were the global symbols, the smallest root set that keeps such functions
when they are global: the FORCEACTIVE block of IN.lcf is replaced by every global symbol that
the objects define. Local symbols with no reference are then removed by `-strip_partial`.
"""
import struct
import sys


def global_symbols(path):
    data = open(path, "rb").read()
    if data[:4] != b"\x7fELF":
        return []
    shoff, = struct.unpack_from(">I", data, 0x20)
    shentsize, shnum = struct.unpack_from(">HH", data, 0x2E)
    names = []
    for i in range(shnum):
        sh = struct.unpack_from(">IIIIIIIIII", data, shoff + i * shentsize)
        if sh[1] != 2:  # SHT_SYMTAB
            continue
        stroff = struct.unpack_from(">IIIIIIIIII", data, shoff + sh[6] * shentsize)[4]
        for off in range(sh[4] + 16, sh[4] + sh[5], 16):
            name, _value, _size, info, _other, shndx = struct.unpack_from(">IIIBBH", data, off)
            if info >> 4 == 0 or shndx == 0 or info & 0xF > 2:
                continue  # local, undefined, or a section/file symbol
            end = data.index(b"\0", stroff + name)
            names.append(data[stroff + name:end].decode())
    return names


def main():
    lcf_in, lcf_out, rsp = sys.argv[1], sys.argv[2], sys.argv[3]
    objects = open(rsp.lstrip("@")).read().split()
    head = open(lcf_in).read().split("FORCEACTIVE")[0]
    seen = set()
    lines = []
    for obj in objects:
        for name in global_symbols(obj):
            if name not in seen:
                seen.add(name)
                lines.append(f"    {name}\n")
    with open(lcf_out, "w", newline="\n") as f:
        f.write(head + "FORCEACTIVE\n{\n" + "".join(lines) + "}\n")


if __name__ == "__main__":
    main()
