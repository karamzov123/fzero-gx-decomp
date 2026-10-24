"""Retarget a compiled unit's private literal-pool constants to the retail pooled symbols.

MWCC gives every literal it needs (an int-to-double conversion constant, a float
written in the code) a private `@N` symbol in the unit's own .rodata. Retail
compiled whole translation units, so those literals were pooled once per TU
and functions reference the shared copy (`lbl_1_rodata_170`). A per-function
unit can never express that in C. So after compiling, when a private literal
has exactly the bytes of the pooled constant the retail code references at the
same instruction, this rewrites the object:

  - the `@N` symbol becomes a global undefined reference named after the pooled
    symbol (the relocation keeps pointing at the same symbol index, so the code
    now references the shared constant, exactly like retail);
  - the private .rodata bytes it occupied are dropped by shrinking the section
    when nothing else lives in it (otherwise the object is left alone and the
    function stays a pool match).

Minimal big-endian ELF32 surgery: the new name goes into a copy of .strtab
appended at the end of the file; only that section header, the symbol entry
and the .rodata size change. SDK string pools in .data use the same binding.
A compiler BSS section base may also bind to its named object; that object
stays defined and its BSS range remains owned by the C unit.
"""

from __future__ import annotations

import json
import re
import struct
import sys
from pathlib import Path
from typing import Dict, List, Optional, Tuple

SHN_UNDEF = 0
STB_GLOBAL = 1
STT_NOTYPE = 0
STT_OBJECT = 1
SHT_SYMTAB = 2
SHT_RELA = 4
SHT_STRTAB = 3


def binding_target(text):
    """A symbolic pool/entry binding, optionally with a byte addend."""
    match = re.fullmatch(r'(.+)\+(0x[0-9a-fA-F]+)', text)
    return (match[1], int(match[2], 0)) if match else (text, 0)

# Masks apply to the containing instruction, not the ELF relocation's byte offset.
# MWCC uses halfword offsets for SDA21; DTK uses word offsets for the same field.
CODE_RELOC_MASKS = {1: 0x00000000, 4: 0xFFFF0000, 5: 0xFFFF0000, 6: 0xFFFF0000,
                    10: 0xFC000003, 11: 0xFFFF0003, 109: 0xFFE00000}


def code_reloc_offset(offset: int, kind: int) -> int:
    return offset & ~3 if kind in (4, 5, 6, 109) else offset


def masked_code(elf, section: dict, start: int = 0, size: int | None = None) -> bytes:
    end = start + size if size is not None else section['size']
    buf = bytearray(elf.data[section['offset'] + start:section['offset'] + end])
    for reloc in elf.sections:
        if reloc['type'] != SHT_RELA or reloc['info'] != section['index']:
            continue
        for pos in range(reloc['offset'], reloc['offset'] + reloc['size'], 12):
            offset, info, _ = struct.unpack_from('>IIi', elf.data, pos)
            kind = info & 255
            offset = code_reloc_offset(offset, kind)
            if start <= offset and offset + 4 <= end:
                # Unknown relocation kinds must not erase arbitrary instructions.
                mask = CODE_RELOC_MASKS.get(kind, 0xFFFFFFFF)
                word = struct.unpack_from('>I', buf, offset - start)[0]
                struct.pack_into('>I', buf, offset - start, word & mask)
    return bytes(buf)


class Elf:
    def __init__(self, data: bytes):
        self.data = bytearray(data)
        if data[:4] != b"\x7fELF" or data[4] != 1 or data[5] != 2:
            raise ValueError("not a big-endian ELF32 object")
        (self.shoff,) = struct.unpack(">I", data[32:36])
        self.shentsize, self.shnum, self.shstrndx = struct.unpack(">HHH", data[46:52])
        self.sections: List[dict] = []
        for i in range(self.shnum):
            off = self.shoff + i * self.shentsize
            f = struct.unpack(">IIIIIIIIII", data[off:off + 40])
            self.sections.append(dict(index=i, name_off=f[0], type=f[1], flags=f[2], addr=f[3], offset=f[4],
                                      size=f[5], link=f[6], info=f[7], addralign=f[8], entsize=f[9]))
        shstr = self.sections[self.shstrndx]
        for s in self.sections:
            s["name"] = self._cstr(shstr["offset"] + s["name_off"])

    def _cstr(self, off: int) -> str:
        end = self.data.index(b"\0", off)
        return self.data[off:end].decode("ascii", "replace")

    def section(self, name: str) -> Optional[dict]:
        return next((s for s in self.sections if s["name"] == name), None)

    def symbols(self) -> List[dict]:
        symtab = next(s for s in self.sections if s["type"] == SHT_SYMTAB)
        strtab = self.sections[symtab["link"]]
        out = []
        for i in range(symtab["size"] // 16):
            off = symtab["offset"] + i * 16
            name_off, value, size, info, other, shndx = struct.unpack(">IIIBBH", self.data[off:off + 16])
            out.append(dict(index=i, off=off, name=self._cstr(strtab["offset"] + name_off), name_off=name_off,
                            value=value, size=size, info=info, other=other, shndx=shndx))
        return out

    def _write_shdr(self, s: dict) -> None:
        off = self.shoff + s["index"] * self.shentsize
        self.data[off:off + 40] = struct.pack(">IIIIIIIIII", s["name_off"], s["type"], s["flags"], s["addr"],
                                              s["offset"], s["size"], s["link"], s["info"], s["addralign"], s["entsize"])

    def add_string(self, strtab: dict, text: str) -> int:
        """Append `text` to a string table by moving the table to the end of the file."""
        old = bytes(self.data[strtab["offset"]:strtab["offset"] + strtab["size"]])
        new = old + text.encode("ascii") + b"\0"
        end = max(len(self.data), self.shoff + self.shnum * self.shentsize)
        self.data[end:] = b""
        self.data += b"\0" * ((4 - end % 4) % 4)
        strtab["offset"] = len(self.data)
        strtab["size"] = len(new)
        self.data += new
        self._write_shdr(strtab)
        return len(old)

    def retarget(self, mapping: Dict[str, str]) -> Tuple[List[str], List[str]]:
        """Rename private `@N` symbols to undefined globals; returns (done, skipped)."""
        symtab = next(s for s in self.sections if s["type"] == SHT_SYMTAB)
        strtab = self.sections[symtab["link"]]
        done, skipped = [], []
        by_name = {s["name"]: s for s in self.symbols()}
        for private, pooled in mapping.items():
            s = by_name.get(private)
            if s is None:
                skipped.append(f"{private}: no such symbol")
                continue
            name, addend = binding_target(pooled)
            if addend:
                # Adjust only ELF relocation addends. Instruction words and
                # initialized data are never patched to manufacture a match.
                for section in self.sections:
                    if section['type'] != SHT_RELA:
                        continue
                    for pos in range(section['offset'], section['offset'] + section['size'], 12):
                        _, info, old = struct.unpack_from('>IIi', self.data, pos)
                        if info >> 8 == s['index']:
                            struct.pack_into('>i', self.data, pos + 8, old + addend)
            name_off = self.add_string(strtab, name)
            self.data[s["off"]:s["off"] + 16] = struct.pack(">IIIBBH", name_off, 0, 0,
                                                            (STB_GLOBAL << 4) | STT_NOTYPE, 0, SHN_UNDEF)
            done.append(f"{private}->{pooled}")
            # locals must precede globals in a symbol table: sh_info is the first non-local index
            if symtab["info"] > s["index"]:
                symtab["info"] = s["index"]
                self._write_shdr(symtab)
        return done, skipped

    def rename_defined(self, mapping: Dict[str, str]) -> Tuple[List[str], List[str]]:
        """Rename private symbols in place (they stay defined in this object): a switch jump
        table whose retail range the unit owns takes the retail name."""
        symtab = next(s for s in self.sections if s["type"] == SHT_SYMTAB)
        strtab = self.sections[symtab["link"]]
        done, skipped = [], []
        by_name = {s["name"]: s for s in self.symbols()}
        for private, retail in mapping.items():
            s = by_name.get(private)
            if s is None:
                skipped.append(f"{private}: no such symbol")
                continue
            name_off = self.add_string(strtab, retail)
            self.data[s["off"]:s["off"] + 4] = struct.pack(">I", name_off)
            done.append(f"{private}->{retail}")
        return done, skipped

    def drop_private_data(self, private_names: List[str]) -> bool:
        """Discard retargeted tables and unused compiler-private string copies.

        Like rodata, the entire section must have no surviving incoming
        relocation, including references through its anonymous section base.
        A bound string need not be named ...data for that proof to hold.
        """
        return self.drop_private_rodata(private_names, '.data')

    def drop_section(self, name: str) -> bool:
        """Empty a section and the relocations applied to it (the pool primer's code section:
        mwld ignores it, but its relocations must not reach the private pool it references)."""
        sec = self.section(name)
        if sec is None:
            return False
        for s in self.symbols():
            if s["shndx"] == sec["index"]:
                self.data[s['off'] + 4:s['off'] + 16] = struct.pack('>IIBBH', 0, 0, 0, 0, SHN_UNDEF)
        sec["size"] = 0
        sec["addralign"] = 1
        sec["flags"] = 0
        self._write_shdr(sec)
        for rs in self.sections:
            if rs["type"] == SHT_RELA and rs["info"] == sec["index"]:
                rs["size"] = 0
                self._write_shdr(rs)
        return True

    def drop_private_rodata(self, private_names: List[str], section_name: str = '.rodata') -> bool:
        """Empty .rodata when every object symbol in it was retargeted; else leave it."""
        ro = self.section(section_name)
        if ro is None:
            return True
        others = [s for s in self.symbols()
                  if s["shndx"] == ro["index"] and (s["info"] & 0xF) == STT_OBJECT and s["name"] not in private_names]
        # the pool primer's tables (fzgx_pool_table*) are private pool bytes like the `@` literals
        if any(not s['name'].startswith(('@', 'fzgx_pool_')) for s in others):
            return False
        # MWCC can retain unused initializer objects after optimizing their
        # consumers away. Drop them only when no relocation (including one via
        # the section symbol) can still reach this section.
        indices = {s['index'] for s in self.symbols() if s['shndx'] == ro['index']}
        if any((struct.unpack_from('>I', self.data, off + 4)[0] >> 8) in indices
               for rs in self.sections if rs['type'] == SHT_RELA and rs['info'] != ro['index']
               for off in range(rs['offset'], rs['offset'] + rs['size'], 12)):
            return False
        # Unreferenced labels go too: an anonymous section base (`...bss.0`) left
        # defined in the emptied section makes mwld fail without a message.
        for s in self.symbols():
            if s['shndx'] == ro['index'] and (s['info'] & 0xF) in (STT_NOTYPE, STT_OBJECT):
                self.data[s['off'] + 4:s['off'] + 16] = struct.pack('>IIBBH', 0, 0, 0, 0, SHN_UNDEF)
        # an empty but allocatable section still makes the linker align before placing it;
        # strip ALLOC so it is not placed at all
        ro["size"] = 0
        ro["addralign"] = 1
        ro["flags"] = 0
        self._write_shdr(ro)
        for rs in self.sections:
            if rs["type"] == SHT_RELA and rs["info"] == ro["index"]:
                rs["size"] = 0
                self._write_shdr(rs)
        return True


def drop_primer(obj: Path) -> bool:
    """Drop only the `.fzgxpool` layout primer from `obj`, in place.

    The primer pins anonymous-section layout order so the *per-object* oracle can match,
    but the module linker rejects it: mwld reports the primer's private copies of BSS as
    `multiply-defined`. `apply()` drops it too, but only on the pool-retarget path, so a
    body that matches with no private literals to retarget (`pool_rows: 0`) never reaches
    it and reaches the link still carrying its primer. See docs/findings/279.

    Dropping the section cannot change matched code: it is a separate section holding
    primer code, and the linker ignored it anyway. Returns True when a section was
    present and emptied.
    """
    if not obj.exists():
        return False
    elf = Elf(obj.read_bytes())
    if elf.section('.fzgxpool') is None:
        return False
    dropped = elf.drop_section('.fzgxpool')
    if dropped:
        obj.write_bytes(bytes(elf.data))
    return dropped


def apply(obj: Path, mapping: Dict[str, str]) -> Dict[str, object]:
    """Rewrite `obj` in place. mapping: private literal symbol -> pooled retail symbol."""
    elf = Elf(obj.read_bytes())
    tables = {k: v for k, v in mapping.items() if v.startswith("jumptable_")}
    pooled = {k: v for k, v in mapping.items() if k not in tables}
    data_section = elf.section('.data')
    data_names = [s['name'] for s in elf.symbols() if data_section and s['shndx'] == data_section['index'] and s['name'] in mapping]
    small_sections = {elf.sections[s['shndx']]['name'] for s in elf.symbols()
                      if s['name'] in mapping and 0 < s['shndx'] < len(elf.sections)
                      and elf.sections[s['shndx']]['name'] in ('.sdata', '.sdata2', '.bss', '.sbss')}
    # both kinds become references to the retail symbol (the data unit that owns the retail
    # range keeps the bytes); our private copies are dropped with their section
    elf.drop_section('.fzgxpool')  # the pool primer (see fixup_evidence.shared_pool_primer)
    done, skipped = elf.retarget(mapping)
    emptied = (elf.drop_private_rodata(list(pooled)) if pooled else True) and (elf.drop_private_data(data_names) if data_names else True)
    for name in sorted(small_sections):
        if name in ('.bss', '.sbss'):
            section = elf.section(name)
            defined = [s for s in elf.symbols() if s['shndx'] == section['index'] and s['size']]
            # A section-base alias may point back to BSS this unit already
            # owns. Keep those definitions; only externalized copies disappear.
            if defined and all(s['name'] in mapping.values() for s in defined):
                continue
        emptied = elf.drop_private_rodata(list(pooled), name) and emptied
    obj.write_bytes(bytes(elf.data))
    return {"retargeted": done, "skipped": skipped, "rodata_emptied": emptied}


def parse_mapping(text: str) -> Dict[str, str]:
    """`@17=lbl_1_rodata_170,@18=lbl_1_rodata_178` (ninja-friendly) or a JSON object."""
    text = text.strip()
    if text.startswith("{"):
        return dict(json.loads(text))
    return dict(item.split("=", 1) for item in text.split(",") if item)


def format_mapping(mapping: Dict[str, str]) -> str:
    return ",".join(f"{k}={v}" for k, v in sorted(mapping.items()))


if __name__ == "__main__":
    r = apply(Path(sys.argv[1]), parse_mapping(sys.argv[2]))
    if r["skipped"] or not r["rodata_emptied"]:
        print(json.dumps(r), file=sys.stderr)
        sys.exit(1)
