"""Struct layout recovery for globals, from every access in a module's disassembly.

For a global G we look at each function that materialises G's address
(`lis rA, G@ha` / `addi rB, rA, G@l`, or a direct `lwz rB, G@l(rA)` when G
holds a pointer) and then follow the base register through memory accesses
`lwz/stw/lhz/lha/sth/lbz/stb/lfs/stfs/lfd/stfd rX, off(rB)` until rB is
overwritten. Two shapes emerge:

  object   G is the struct itself: fields at G+off
  pointer  G holds a pointer; fields are at (*G)+off

Output: {"kind": ..., "fields": {off: {"width": 4, "float": bool, "loads": n, "stores": n}},
         "users": [function names]}, plus a C typedef skeleton with fields
named by offset (`u32 unk_3C;`) that a librarian can rename.
"""

from __future__ import annotations

import json
import os

import re
from collections import defaultdict
from pathlib import Path
from typing import Dict, List, Optional, Tuple

from .project import Project

ACCESS_RE = re.compile(r"^(l|st)(wz|w|hz|ha|h|bz|b|fs|fd)(u|x)?\s+(r|f)(\d+),\s*(-?0x[0-9a-fA-F]+|-?\d+)\((r\d+)\)")
INDEXED_RE = re.compile(r"^(l|st)(wz|w|hz|ha|h|bz|b|fs|fd)x\s+(r|f)(\d+),\s*(r\d+),\s*(r\d+)$")
WIDTH = {"wz": 4, "w": 4, "hz": 2, "h": 2, "ha": 2, "bz": 1, "b": 1, "fs": 4, "fd": 8}
OP_WIDTH = {"lwz": 4, "lhz": 2, "lha": 2, "lbz": 1, "lfs": 4, "lfd": 8, "stw": 4, "sth": 2, "stb": 1, "stfs": 4, "stfd": 8}
DEF_RE = re.compile(r"^(\w+)\s+r(\d+)")  # first operand register is the destination for most ops
NO_DEF = {"stw", "sth", "stb", "stfs", "stfd", "stwu", "stwx", "sthx", "stbx", "stfsx", "cmpw", "cmpwi", "cmplw",
          "cmplwi", "b", "bl", "beq", "bne", "blt", "bgt", "ble", "bge", "bdnz", "blr", "bctr", "bctrl", "mtctr", "mtlr"}


def _insn(line: str) -> str:
    return line.split(": ", 1)[1] if ": " in line else line


def analyze(p: Project, module: str, symbol: str) -> Dict[str, object]:
    fields: Dict[Tuple[str, int], Dict[str, object]] = defaultdict(
        lambda: {"width": 0, "float": False, "fops": 0, "loads": 0, "stores": 0, "widths": {}, "signed": False})
    users: List[str] = []
    kinds = defaultdict(int)
    indexed: Dict[int, Dict[str, object]] = defaultdict(lambda: {"n": 0, "signed": False, "fops": 0})
    stride_seen: Dict[str, int] = {}
    for fn in p.function_asm(module).values():
        if symbol not in fn.refs:
            continue
        used = False
        base: Dict[str, tuple] = {}  # register -> (kind, delta): kind "object" | "pointer", delta added to offsets
        derived: Dict[str, tuple] = {}  # register -> ("field", kind, off): pointee of a pointer field
        pending_ha: Dict[str, bool] = {}
        strides: Dict[str, int] = {}    # register -> stride from `mulli rT, rIdx, S` (or slwi)
        for line in fn.asm:
            ins = _insn(line)
            m = re.match(rf"^lis r(\d+), {re.escape(symbol)}@ha", ins)
            if m:
                pending_ha[f"r{m.group(1)}"] = True
                continue
            m = re.match(rf"^addi r(\d+), r(\d+), {re.escape(symbol)}@l", ins)
            if m and f"r{m.group(2)}" in pending_ha:
                base[f"r{m.group(1)}"] = ("object", 0)
                continue
            m = re.match(r"^(addi|subi) r(\d+), r(\d+), (-?0x[0-9a-fA-F]+|-?\d+)$", ins)
            if m and f"r{m.group(3)}" in base:
                k, d = base[f"r{m.group(3)}"]
                imm = int(m.group(4), 0) * (-1 if m.group(1) == "subi" else 1)
                base[f"r{m.group(2)}"] = (k, d + imm)
                continue
            m = re.match(r"^mr r(\d+), r(\d+)$", ins)
            if m and f"r{m.group(2)}" in base:
                base[f"r{m.group(1)}"] = base[f"r{m.group(2)}"]
                continue
            if m and f"r{m.group(2)}" in derived:
                derived[f"r{m.group(1)}"] = derived[f"r{m.group(2)}"]
                continue
            m = re.match(r"^mulli r(\d+), r\d+, (-?0x[0-9a-fA-F]+|-?\d+)$", ins) or \
                re.match(r"^slwi r(\d+), r\d+, (\d+)$", ins)
            if m:
                v = int(m.group(2), 0)
                strides[f"r{m.group(1)}"] = (1 << v) if ins.startswith("slwi") else v
                continue
            m = re.match(r"^add\.? r(\d+), r(\d+), r(\d+)$", ins)
            if m:
                ra, rb, rd = f"r{m.group(2)}", f"r{m.group(3)}", f"r{m.group(1)}"
                pair = (ra, rb) if ra in base and rb in strides else ((rb, ra) if rb in base and ra in strides else None)
                if pair:
                    k, d = base[pair[0]]
                    base[rd] = (k, d)  # element [i]: same layout, offsets relative to the element
                    if d == 0:  # an index applied inside the record (delta != 0) is a sub-array, not the record stride
                        stride_seen[k] = stride_seen.get(k, 0) or strides[pair[1]]
                    continue
                # index applied to a pointer loaded from the materialised address: element [i] of the pointee
                pair = (ra, rb) if ra in derived and rb in strides else ((rb, ra) if rb in derived and ra in strides else None)
                if pair:
                    tag = derived[pair[0]]
                    derived[rd] = tag
                    if tag == ("field", "object", 0):
                        stride_seen["derived0"] = stride_seen.get("derived0", 0) or strides[pair[1]]
                    continue
            # direct access through the symbol, with an optional displacement: op rX, (sym+0x3c)@l(rA) or sym@l(rA)
            # the update forms (`stwu r0, sym@l(r3)`: the store that also materialises the address)
            # access the same field as their plain forms
            m = re.match(rf"^(lwz|lhz|lha|lbz|lfs|lfd|stw|sth|stb|stfs|stfd)u? [rf](\d+), \(?{re.escape(symbol)}(?:\s*\+\s*(0x[0-9a-fA-F]+|\d+))?\)?@l\(r(\d+)\)", ins)
            if m and f"r{m.group(4)}" in pending_ha:
                off = int(m.group(3), 0) if m.group(3) else 0
                f = fields[("object", off)]
                f["width"] = max(f["width"], OP_WIDTH[m.group(1)])
                f["widths"][OP_WIDTH[m.group(1)]] = f["widths"].get(OP_WIDTH[m.group(1)], 0) + 1
                f["signed"] = f["signed"] or m.group(1) == "lha"
                f["fops"] += m.group(1) in ("lfs", "lfd", "stfs", "stfd")
                f["loads" if m.group(1).startswith("l") else "stores"] += 1
                if m.group(1) == "lwz":
                    base[f"r{m.group(2)}"] = ("pointer", 0)
                kinds["object"] += 1
                used = True
                continue
            # register-indexed element of the object itself (`lhax r0, rBase, rIdx`): an array
            mx = INDEXED_RE.match(ins)
            if mx:
                op, w, _, _, ra, rb = mx.groups()
                hit = [r for r in (ra, rb) if base.get(r) == ("object", 0)]
                if len(hit) == 1:
                    e = indexed[WIDTH[w]]
                    e["n"] += 1
                    e["signed"] = e["signed"] or w == "ha"
                    e["fops"] += w in ("fs", "fd")
                    kinds["object"] += 1
                    used = True
            m = ACCESS_RE.match(ins)
            if m:
                op, w, _, rf, rn, off, rb = m.groups()
                if rb in base:
                    bk, bd = base[rb]
                    off = int(off, 0) + bd
                    key = (bk, off)
                    f = fields[key]
                    f["width"] = max(f["width"], WIDTH[w])
                    f["widths"][WIDTH[w]] = f["widths"].get(WIDTH[w], 0) + 1
                    f["signed"] = f["signed"] or w == "ha"
                    f["fops"] += w in ("fs", "fd")
                    f["loads" if op == "l" else "stores"] += 1
                    kinds[bk] += 1
                    used = True
                    if op == "l" and w in ("wz", "w") and rf == "r":
                        # pointer field: the loaded register now addresses the pointee; record its fields under ("field", off)
                        dest = f"r{rn}"
                        tag = ("field", bk, off)
                        base.pop(dest, None)  # a load into the base register itself replaces it
                        derived[dest] = tag
                        pending_ha.pop(dest, None)
                        continue
                elif rb in derived:
                    off = int(off, 0)
                    key = (derived[rb], off)
                    f = fields[key]
                    f["width"] = max(f["width"], WIDTH[w])
                    f["widths"][WIDTH[w]] = f["widths"].get(WIDTH[w], 0) + 1
                    f["signed"] = f["signed"] or w == "ha"
                    f["fops"] += w in ("fs", "fd")
                    f["loads" if op == "l" else "stores"] += 1
                    used = True
                if op == "l" and rf == "r":
                    dest = f"r{rn}"
                    if dest != rb or rb not in derived:
                        derived.pop(dest, None)
                    if dest in base and dest != rb:
                        base.pop(dest, None)
            d = DEF_RE.match(ins)
            if d and d.group(1) not in NO_DEF:
                reg = f"r{d.group(2)}"
                if reg in base:
                    base.pop(reg, None)
                if reg in derived and not (m and f"r{m.group(5)}" == reg and m.group(1) == "l" and m.group(7) in base):
                    derived.pop(reg, None)
                pending_ha.pop(reg, None)
        if used:
            users.append(fn.symbol.name)
    size = p.symbols(module)[symbol].size if symbol in p.symbols(module) else 0
    # a word-sized global whose loaded value is ever dereferenced is a pointer; the direct
    # loads/stores of the pointer itself must not outvote the accesses through it
    if size <= 8 and kinds.get("pointer", 0) > 0:
        kind = "pointer"
    else:
        kind = "pointer" if kinds.get("pointer", 0) > kinds.get("object", 0) else "object"
    # a slot touched through both integer and float ops (type punning, unions, the odd
    # zero-store) is typed by the majority of its accesses
    for f in fields.values():
        f["float"] = f["fops"] * 2 > f["loads"] + f["stores"]
    out = {}
    pointees: Dict[int, Dict[int, Dict]] = defaultdict(dict)
    # Only an index applied to the *loaded* pointer says anything about the element size; an
    # index on the materialised address of a word-sized variable belongs to some neighbour.
    stride = stride_seen.get(kind, 0) or (stride_seen.get("derived0", 0) if kind == "pointer" and size <= 8 else 0)

    def merge(off: int, f: Dict, into: Optional[Dict[int, Dict]] = None) -> None:
        tbl = out if into is None else into
        g = tbl.get(off)
        if g is None:
            tbl[off] = dict(f, widths=dict(f["widths"]))
            return
        g["width"] = max(g["width"], f["width"])
        for w, n in f["widths"].items():
            g["widths"][w] = g["widths"].get(w, 0) + n
        g["signed"] = g["signed"] or f["signed"]
        g["float"] = g["float"] or f["float"]
        g["loads"] += f["loads"]
        g["stores"] += f["stores"]
        g["fops"] += f["fops"]
        g["float"] = g["fops"] * 2 > g["loads"] + g["stores"]

    for key, f in fields.items():
        if isinstance(key[0], tuple):  # ("field", kind, off), pointee_off
            (_, k, poff), off = key
            if k == kind:
                pointees[poff][off] = f
            elif kind == "pointer" and size <= 8 and k == "object" and poff == 0 and off >= 0:
                # the pointer was loaded from its materialised address; what follows is the element
                merge(off, f)
        elif key[0] == kind or (key[0] == "object" and key[1] == 0):
            if key[1] < 0 or (kind == "object" and size and key[1] >= size):
                continue  # indexed neighbour or array stride, not a field of this object
            if kind == "pointer" and size <= 8 and key[0] == "object":
                continue  # the load of the pointer variable itself, not an element field
            merge(key[1], f)
    if os.environ.get("FZGX_DEBUG"):
        print("DEBUG", symbol, size, kind, sorted((str(k), f["width"], f["loads"], f["stores"]) for k, f in fields.items()))
    if stride and out:
        # Constant-indexed accesses (unrolled loops) land past the stride; fold them onto the
        # element only if that agrees with the fields already seen. A width clash means the
        # index step belonged to something else, so the stride is dropped.
        folded: Dict[int, Dict] = {o: dict(f, widths=dict(f["widths"])) for o, f in out.items() if o < stride}
        ok = all(o + (f["width"] or 1) <= stride for o, f in folded.items())
        for o, f in sorted(out.items()):
            if o < stride or not ok:
                continue
            t = o % stride
            w = f["width"] or 1
            for eo, ef in folded.items():
                ew = ef["width"] or 1
                if eo < t + w and t < eo + ew and (eo != t or ew != w):
                    ok = False
            if ok:
                merge(t, f, folded)
        if ok:
            out = folded
        else:
            stride = 0
    return {"symbol": symbol, "kind": kind, "fields": dict(sorted(out.items())), "users": users, "shapes": dict(kinds),
            "stride": stride, "indexed": {w: dict(e) for w, e in sorted(indexed.items())},
            "pointees": {poff: {o: f for o, f in sorted(fl.items()) if o >= 0}
                         for poff, fl in pointees.items() if sum(x["loads"] + x["stores"] for x in fl.values()) >= 3}}


def indexed_array(p: Project, module: str, sd, info: Dict[str, object]) -> Optional[str]:
    """`extern T name[N];` for an object the code indexes by register at one element width, when
    every constant-offset access agrees with that element (a struct view would invent padding).
    A word array whose every retail element is a relocation to a string is a string table."""
    idx = info.get("indexed") or {}
    if len(idx) != 1 or info["kind"] != "object" or info.get("pointees") or sd.name.startswith("jumptable_"):
        return None
    (w, e), = idx.items()
    if sd.size <= w or sd.size % w or info.get("stride", 0) not in (0, w):
        return None
    fields = info["fields"]
    if any(off % w or set(f["widths"]) != {w} for off, f in fields.items()):
        return None
    signed = e["signed"] or any(f.get("signed") for f in fields.values())
    fops = e["fops"] + sum(f["fops"] for f in fields.values())
    accesses = e["n"] + sum(f["loads"] + f["stores"] for f in fields.values())
    ctype = {1: "u8", 2: "s16" if signed else "u16", 4: "f32" if fops * 2 > accesses else "u32", 8: "f64"}[w]
    if w == 4 and ctype == "u32" and sd.section != ".bss":
        from .dataimport import payload
        try:
            _, relocs = payload(p, sd)
        except ValueError:
            relocs = []
        targets = [p.find_symbol(r["symbol"], r["module"]) for r in relocs if not r["addend"]]
        if (len(targets) == sd.size // 4 and len({r["offset"] for r in relocs}) == len(targets)
                and all(t is not None and t.attrs.get("data") == "string" for t in targets)):
            ctype = "const char *"
    return f"extern {ctype}{'' if ctype.endswith('*') else ' '}{sd.name}[0x{sd.size // w:X}];"


def typedef_names(p, module: str) -> Dict[str, Dict[str, str]]:
    """Chosen typedef names per symbol: {symbol: {"self"|"target"|"at_<hex>": Name}}.
    Headers are generated, so names live here (config/<version>/<module>/typedefs.json)."""
    path = p.module_config_dir(module) / "typedefs.json"
    return json.loads(path.read_text()) if path.exists() else {}


def _tname(names: Dict[str, Dict[str, str]], symbol: str, role: str, default: str) -> str:
    return (names.get(symbol) or {}).get(role) or default


def typedef(info: Dict[str, object], name: Optional[str] = None, fields: Optional[Dict[int, Dict]] = None,
            ptr_types: Optional[Dict[int, str]] = None, size: int = 0) -> str:
    """C typedef skeleton. ptr_types maps a field offset to the typedef name its pointer targets;
    size pads the object out to the symbol's size so arrays of it index correctly."""
    fields = fields if fields is not None else info["fields"]
    ptr_types = ptr_types or {}
    name = name or f"{info['symbol'].replace('lbl_', 'Struct_')}"
    lines = [f"typedef struct {{"]
    cur = 0
    for off in sorted(fields):
        f = fields[off]
        if off < cur:
            continue  # overlaps the previous field: keep the earlier, wider view
        if off > cur:
            lines.append(f"    u8 pad_{cur:X}[0x{off - cur:X}];")
        w = f["width"] or 4
        widths = f.get("widths") or {w: 1}
        if len(widths) > 1:
            narrow = min(widths)
            # two narrow fields read once as one wide word: keep the narrow view when the
            # neighbouring narrow slot is itself accessed
            if any(o == off + narrow for o in fields) or widths[narrow] >= widths.get(w, 0):
                w = narrow
        # MWCC (-align powerpc) aligns each field naturally; a misaligned access is an
        # unaligned load into a wider field or a packed byte run, so emit bytes instead.
        if off % w:
            w = 1
        ctype = {1: "u8", 2: "s16" if f.get("signed") else "u16", 4: "f32" if f["float"] else "u32", 8: "f64"}[w]
        if off in ptr_types and w == 4:
            ctype = f"{ptr_types[off]} *"
        lines.append(f"    {ctype}{'' if ctype.endswith('*') else ' '}unk_{off:X};  // {f['loads']} loads, {f['stores']} stores")
        cur = off + w
    if len(lines) == 1:
        lines.append("    u8 unk_0;  // no field accesses recovered")
    if size and cur < size:
        lines.append(f"    u8 pad_{cur:X}[0x{size - cur:X}];")
    lines.append(f"}} {name};")
    return "\n".join(lines)


def header(p: Project, module: str, min_refs: int = 20, sections=(".data", ".bss", ".sdata", ".sbss")) -> str:
    """Generate a shared header for the most-referenced globals of a module."""
    from collections import Counter
    syms = p.symbols(module)
    cnt = Counter()
    for fn in p.function_asm(module).values():
        for r in fn.refs:
            sd = syms.get(r)
            if sd and sd.kind == "object" and sd.section in sections:
                cnt[r] += 1
    guard = f"REL_{module.upper()}_GLOBALS_H"
    out = [f"#ifndef {guard}", f"#define {guard}", "", '#include "types.h"', "",
           f"// Generated by `fzgx headers --module {module}`: layouts recovered from every access in the",
           "// module's disassembly (matched or not). Field names are offsets until the librarian names them;",
           "// offsets and widths are facts, names are not. Regenerate rather than hand-edit padding.", ""]
    names = typedef_names(p, module)
    for name, n in cnt.most_common():
        if n < min_refs:
            break
        sd = syms[name]
        info = analyze(p, module, name)
        tname = _tname(names, name, "self", name.replace("lbl_", "Obj_"))
        out.append(f"// {name}: {sd.section} size 0x{sd.size:X}, referenced by {n} functions, shape {info['shapes']}")
        nfields = info["fields"]
        pointee0 = info.get("pointees", {}).get(0) or {}
        scalar_size = sd.size in (1, 2, 4, 8)  # a 7-byte object with no accesses is a string, not a u32
        scalar_size &= sd.attrs.get("data") != "string"  # nor is a 4-byte one dtk typed string
        array = indexed_array(p, module, sd, info)
        if array:
            out.append(array)
        elif sd.size <= 8 and (info["kind"] == "pointer" or len(nfields) <= 1 and 0 in nfields or (not nfields and scalar_size)):
            elem = nfields if info["kind"] == "pointer" else pointee0
            if sd.size == 4 and elem and sum(x["loads"] + x["stores"] for x in elem.values()) >= 3:
                pt = _tname(names, name, "target", f"{tname}_Target")
                out.append(typedef(info, pt, elem, None, info.get("stride", 0)))
                out.append(f"extern {pt} *{name};" + (f"  // array of 0x{info['stride']:X}-byte records" if info.get("stride") else ""))
            else:
                f = nfields.get(0, {"width": min(sd.size, 4) or 4, "float": False})
                w = f.get("width", 4) or 4
                ctype = {1: "u8", 2: "s16" if f.get("signed") else "u16", 4: "f32" if f.get("float") else "u32", 8: "f64"}.get(w, "u32")
                out.append(f"extern {ctype} {name};")
        elif not nfields and sd.size:
            # no field access recovered: an array, not a struct with an invented field; a
            # printable string is char for modules whose TUs opted in (typedefs.json)
            text = p.string_at(module, name) if names.get("__char_strings__") else None
            out.append(f"extern char {name}[0x{sd.size:X}];  // {text!r}" if text else f"extern u8 {name}[0x{sd.size:X}];")
        else:
            ptr_types = {}
            for poff, fl in sorted(info.get("pointees", {}).items()):
                if poff in nfields and fl:
                    pt = _tname(names, name, f"at_{poff:X}", f"{tname}_At{poff:X}")
                    out.append(f"// object reached through {name}.unk_{poff:X}")
                    out.append(typedef(info, pt, fl))
                    ptr_types[poff] = pt
            out.append(typedef(info, tname, None, ptr_types, sd.size))
            out.append(f"extern {tname} {name};")
        out.append("")
    out.append(f"#endif  // {guard}")
    return "\n".join(out) + "\n"


def oversize(p: Project, module: str, min_refs: int = 5) -> List[Dict[str, object]]:
    """Globals whose code accesses reach past the symbol's size: dtk under-sized the object.

    Each row lists the symbol, its size, the furthest access, and the symbols that follow within
    that reach, so the librarian can merge them in symbols.txt (a size correction, no code change).
    """
    from collections import Counter
    syms = p.symbols(module)
    ordered = sorted((s for s in syms.values() if s.kind == "object"), key=lambda s: (s.section, s.addr))
    cnt = Counter()
    for fn in p.function_asm(module).values():
        for r in fn.refs:
            if r in syms and syms[r].kind == "object":
                cnt[r] += 1
    rows = []
    for name, n in cnt.most_common():
        if n < min_refs:
            break
        sd = syms[name]
        info = analyze(p, module, name)
        # unclamped: re-derive the furthest object-shape offset
        far = 0
        for fn in p.function_asm(module).values():
            if name not in fn.refs:
                continue
        # cheap proxy: analyze() clamps, so recompute from raw fields via a second pass
        raw = _raw_object_offsets(p, module, name)
        if not raw:
            continue
        far = max(raw)
        if far + 4 > sd.size:
            following = [s for s in ordered if s.section == sd.section and sd.addr < s.addr < sd.addr + far + 4]
            rows.append({"symbol": name, "section": sd.section, "size": sd.size, "furthest_access": far,
                         "refs": n, "swallows": [f.name for f in following][:12], "n_swallowed": len(following)})
    return rows


def _raw_object_offsets(p: Project, module: str, symbol: str) -> List[int]:
    """Object-shape access offsets without size clamping (helper for oversize())."""
    offs = []
    for fn in p.function_asm(module).values():
        if symbol not in fn.refs:
            continue
        base = {}
        pending = set()
        for line in fn.asm:
            ins = _insn(line)
            m = re.match(rf"^lis r(\d+), {re.escape(symbol)}@ha", ins)
            if m:
                pending.add(f"r{m.group(1)}"); continue
            m = re.match(rf"^addi r(\d+), r(\d+), {re.escape(symbol)}@l", ins)
            if m and f"r{m.group(2)}" in pending:
                base[f"r{m.group(1)}"] = 0; continue
            m = re.match(r"^(addi|subi) r(\d+), r(\d+), (-?0x[0-9a-fA-F]+|-?\d+)$", ins)
            if m and f"r{m.group(3)}" in base:
                base[f"r{m.group(2)}"] = base[f"r{m.group(3)}"] + int(m.group(4), 0) * (-1 if m.group(1) == "subi" else 1); continue
            m = ACCESS_RE.match(ins)
            if m and m.group(7) in base:
                offs.append(int(m.group(6), 0) + base[m.group(7)])
            d = DEF_RE.match(ins)
            if d and d.group(1) not in NO_DEF:
                base.pop(f"r{d.group(2)}", None); pending.discard(f"r{d.group(2)}")
    return offs


def selfcheck(header_text: str, include_path: str) -> str:
    """C that fails to compile if any generated field is not at the offset its name claims."""
    lines = ['#include "types.h"', f'#include "{include_path}"', "#define OFF(T, f) ((u32)&(((T *)0)->f))", ""]
    cur = None
    for line in header_text.splitlines():
        m = re.match(r"^typedef struct \{", line)
        if m:
            fields = []
        m = re.match(r"^\} (\w+);", line)
        if m:
            for f, off in fields:
                lines.append(f"typedef char check_{m.group(1)}_{f}[OFF({m.group(1)}, {f}) == 0x{off:X} ? 1 : -1];")
            continue
        m = re.match(r"^\s+[\w ]+\*?\s*(unk_([0-9A-F]+));", line)
        if m:
            fields.append((m.group(1), int(m.group(2), 16)))
    return "\n".join(lines) + "\n"


def tu_header(p: Project, module: str, tu: str, min_refs: int = 2) -> str:
    """Per-file header: globals referenced by the TU's functions (>= min_refs) or living in its data block,
    excluding those already declared in the module's globals.h. Includes globals.h."""
    import json
    from collections import Counter
    tus = json.loads((p.module_config_dir(module) / "tus.json").read_text())["tus"]
    tu_info = next(t for t in tus if t["file"] == tu)
    stem = tu.rsplit(".", 1)[0]
    fns = set(tu_info["functions"])
    d_lo, d_hi = tu_info["data"]
    syms = p.symbols(module)
    idx = p.function_asm(module)
    shared = (Path(__file__).resolve().parent.parent.parent / "include" / p.module_src_prefix(module) / "globals.h")
    shared_text = shared.read_text() if shared.exists() else ""
    cnt = Counter()
    for f in fns:
        for r in idx[f].refs:
            sd = syms.get(r)
            if sd and sd.kind == "object" and sd.section in (".data", ".bss", ".sdata", ".sbss"):
                cnt[r] += 1
    picks = []
    for name, n in cnt.most_common():
        sd = syms[name]
        own = sd.section == ".data" and d_lo <= sd.addr < d_hi
        if (n >= min_refs or own) and not re.search(rf"\b{re.escape(name)}\s*(?:\[[^\]]*\]\s*)*;", shared_text):
            picks.append((name, n, own))
    guard = f"REL_{module.upper()}_{stem.upper()}_H"
    out = [f"#ifndef {guard}", f"#define {guard}", "", '#include "types.h"', f'#include "{p.module_src_prefix(module)}/globals.h"', "",
           f"// Generated by `fzgx headers --module {module} --tu {tu}`: globals of {tu} (referenced by its",
           "// functions or living in its .data block), layouts recovered from every access in the module.", ""]
    names = typedef_names(p, module)
    for name, n, own in picks:
        sd = syms[name]
        info = analyze(p, module, name)
        tname = _tname(names, name, "self", name.replace("lbl_", "Obj_").replace("jumptable_", "Jt_"))
        out.append(f"// {name}: {sd.section} size 0x{sd.size:X}, {n} refs from {tu}{' (own data block)' if own else ''}")
        nfields = info["fields"]
        pointee0 = info.get("pointees", {}).get(0) or {}
        array = indexed_array(p, module, sd, info)
        scalar_size = sd.size in (1, 2, 4, 8)  # a 3-byte object with no accesses is a string, not a u32
        scalar_size &= sd.attrs.get("data") != "string"  # nor is a 4-byte one dtk typed string
        if array:
            out.append(array)
        elif sd.size <= 8 and (info["kind"] == "pointer" or len(nfields) <= 1 and 0 in nfields or (not nfields and scalar_size)):
            elem = nfields if info["kind"] == "pointer" else pointee0
            if sd.size == 4 and elem and sum(x["loads"] + x["stores"] for x in elem.values()) >= 3:
                pt = _tname(names, name, "target", f"{tname}_Target")
                out.append(typedef(info, pt, elem, None, info.get("stride", 0)))
                out.append(f"extern {pt} *{name};" + (f"  // array of 0x{info['stride']:X}-byte records" if info.get("stride") else ""))
            else:
                f = nfields.get(0, {"width": min(sd.size, 4) or 4, "float": False})
                w = f.get("width", 4) or 4
                ctype = {1: "u8", 2: "s16" if f.get("signed") else "u16", 4: "f32" if f.get("float") else "u32", 8: "f64"}.get(w, "u32")
                # size > width would suggest an array, but matched code reads such symbols as
                # scalars far more often than it indexes them; the block that indexes is revised
                out.append(f"extern {ctype} {name};")
        elif not nfields and sd.size:
            # strings are char only for TUs opted in (typedefs.json "__char_strings__"): the
            # switch breaks blocks that declared the string u8, so it is made per TU, when the
            # TU is being taken to a whole-unit compile and its blocks get revised
            opt = set(names.get("__char_strings__", []))
            text = p.string_at(module, name) if own and tu.rsplit(".", 1)[0] in opt else None
            out.append(f"extern char {name}[0x{sd.size:X}];  // {text!r}" if text else f"extern u8 {name}[0x{sd.size:X}];")
        else:
            ptr_types = {}
            for poff, fl in sorted(info.get("pointees", {}).items()):
                if poff in nfields:
                    pt = _tname(names, name, f"at_{poff:X}", f"{tname}_At{poff:X}")
                    out.append(typedef(info, pt, fl))
                    ptr_types[poff] = pt
            out.append(typedef(info, tname, None, ptr_types, sd.size))
            out.append(f"extern {tname} {name};")
        out.append("")
    out.append(f"#endif  // {guard}")
    return "\n".join(out) + "\n"


def write_header(p, module: str, tu: Optional[str] = None, min_refs: int = 20) -> str:
    """Generate one header (globals.h or the TU's), write it, and prove every field offset under
    MWCC. Returns "" on success or the self-check failure text."""
    import subprocess
    if tu and not (Path('include') / p.module_src_prefix(module) / 'globals.h').exists():
        error = write_header(p, module, min_refs=min_refs)
        if error:
            return error
    text = tu_header(p, module, tu) if tu else header(p, module, min_refs)
    out = Path("include") / p.module_src_prefix(module) / (f"{tu.rsplit('.', 1)[0]}.h" if tu else "globals.h")
    out.parent.mkdir(parents=True, exist_ok=True)
    previous = out.read_bytes() if out.exists() else None
    out.write_text(text)
    chk = Path(".fzgx") / "header_selfcheck.c"
    chk.write_text(selfcheck(text, f"{p.module_src_prefix(module)}/{out.name}"))
    cp = subprocess.run(["build/tools/wibo", "build/compilers/GC/1.3.2/mwcceppc.exe", "-nodefaults", "-proc", "gekko",
                         "-i", "include", "-c", str(chk), "-o", str(chk.with_suffix(".o"))], text=True, capture_output=True)
    if cp.returncode != 0:
        if previous is None:
            out.unlink()
        else:
            out.write_bytes(previous)
        return (cp.stdout + cp.stderr)[-3000:] or "self-check failed"
    return ""


def regenerate_module(p, module: str, min_refs: int = 20) -> Dict[str, str]:
    """globals.h plus every TU header of the module; returns {header: failure} for any that failed."""
    failures: Dict[str, str] = {}
    err = write_header(p, module, None, min_refs)
    if err:
        failures["globals.h"] = err
    tus_path = p.module_config_dir(module) / "tus.json"
    if tus_path.exists():
        for t in json.loads(tus_path.read_text())["tus"]:
            err = write_header(p, module, t["file"])
            if err:
                failures[t["file"]] = err
    return failures


def u64_pairs(p, module: str):
    """Adjacent 4-byte data symbols retail's code moves as a register pair (r3:r4 from a
    u64-returning call, rN:rN+1 loads): one 8-byte object dtk split in two. Returns
    [(low, high, sightings, other_refs_to_high)]."""
    import re as _re
    syms = p.symbols(module)
    idx = p.function_asm(module)
    pairs = {}
    users_hi = {}
    for fn in idx.values():
        lines = [ln.split(": ", 1)[1] for ln in fn.asm if ": " in ln]
        for i, ln in enumerate(lines):
            m1 = _re.match(r"(stw|lwz) r(\d+), (\w+)(?:\+0x[0-9a-fA-F]+)?@(sda21|l)\b", ln)
            if not m1:
                continue
            for j in range(i + 1, min(i + 4, len(lines))):
                m2 = _re.match(r"(stw|lwz) r(\d+), (\w+)@(sda21|l)\b", lines[j])
                if not m2 or m2.group(1) != m1.group(1) or int(m2.group(2)) != int(m1.group(2)) + 1:
                    continue
                a, b = syms.get(m1.group(3)), syms.get(m2.group(3))
                if a and b and a.kind == "object" and b.kind == "object" and a.size == 4 and b.size == 4 \
                        and b.addr == a.addr + 4 and a.section == b.section:
                    pairs[(a.name, b.name)] = pairs.get((a.name, b.name), 0) + 1
    for (a, b), n in list(pairs.items()):
        users = [fn.symbol.name for fn in idx.values() if b in fn.refs]
        users_hi[(a, b)] = len(users)
    return [(a, b, n, users_hi[(a, b)]) for (a, b), n in sorted(pairs.items())]


def merge_u64(p, module: str, dry_run: bool = False):
    """Merge each u64 pair into the low symbol (size 8, data:8byte) and drop the high one, when
    every reference to the high symbol is the pair and no source names it. Re-splits and relinks
    under the build lock; restores symbols.txt if the tree no longer hashes."""
    import re as _re, shutil
    from . import oracle
    from .project import ROOT
    rows = u64_pairs(p, module)
    path = p.module_config_dir(module) / "symbols.txt"
    text = path.read_text()
    merged, skipped = [], []
    src_text = "\n".join(f.read_text() for f in (ROOT / "src").rglob("*.c"))
    hdr_text = "\n".join(f.read_text() for f in (ROOT / "include").rglob("*.h"))
    for a, b, n, users in rows:
        if _re.search(rf"\b{_re.escape(b)}\b", src_text) or _re.search(rf"\b{_re.escape(b)}\b", hdr_text):
            skipped.append((a, b, "named in src/ or include/")); continue
        ma = _re.search(rf"^{_re.escape(a)} = [^\n]*$", text, _re.M); mb = _re.search(rf"^{_re.escape(b)} = [^\n]*\n", text, _re.M)
        if not ma or not mb:
            skipped.append((a, b, "not in symbols.txt")); continue
        line = ma.group(0)
        line = _re.sub(r"size:0x4\b", "size:0x8", line)
        line = _re.sub(r"data:4byte", "data:8byte", line) if "data:" in line else line + " data:8byte"
        line = _re.sub(r"align:4\b", "align:8", line)
        text = text.replace(ma.group(0), line, 1).replace(mb.group(0), "", 1)
        merged.append((a, b))
    out = {"module": module, "pairs": rows, "merged": merged, "skipped": skipped, "ok": True}
    if dry_run or not merged:
        return out
    backup = path.with_suffix(".txt.bak")
    shutil.copy(path, backup)
    path.write_text(text)
    p._symbols.pop(module, None)
    with oracle.build_lock():
        cp = oracle.configure(p)
        ok = cp.returncode == 0 and oracle.relink(p).returncode == 0
        if not ok:
            shutil.copy(backup, path); p._symbols.pop(module, None)
            oracle.configure(p); oracle.relink(p)
    backup.unlink(missing_ok=True)
    out["ok"] = ok
    if not ok:
        out["error"] = "the tree no longer hashed with the merged symbols; symbols.txt restored"
    return out
