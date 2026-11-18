#!/usr/bin/env python3
"""Generate a region config (GFZP01 / GFZJ01) that links the USA C from GFZE01.

  python3 tools/region_config.py --version GFZP01

Inputs (all local, nothing is committed from them):
  orig/GFZE01 and orig/<VERSION>   extracted files (tools/prepare_orig.py)
  build/GFZE01                     a completed USA build (its C objects)
  build/tools/dtk                  decomp-toolkit, from configure.py

Hand-maintained and left alone: config/<VERSION>/config.yml and build.sha1.
Rewritten: config/<VERSION>/**/symbols.txt, the section headers in
config/<VERSION>/**/splits.txt, ldscript.tpl, and <VERSION> in the `matching_for` lists of
config/GFZE01/units.json (configure.py derives the region's unit splits from those).

How a USA unit qualifies for the region:
  1. Function names: every USA function >= 16 bytes whose code (immediates and
     branch targets masked) occurs exactly once in the region module is named
     there, keeping only hits in address order with their neighbours.
  2. dtk splits both versions with only those names; instructions of each
     same-named function are compared. A function is "identical" when its
     instructions are equal apart from symbol operands, and every symbol
     operand pairs consistently (US name -> one region symbol) across all
     identical functions. Those pairs name the region's data and labels.
  3. A USA C function unit links in the region when its function is
     identical, its literal-pool targets are named, and every symbol its USA
     object leaves undefined is named in the region or defined by another
     linked unit (fixpoint).
Region auto-generated names that equal a USA name used elsewhere are renamed
`rgn_<name>` so the two never collide.
"""

from __future__ import annotations

import argparse
import bisect
import collections
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
US = "GFZE01"
REL_PREFIX = {"GFZE01": "fze", "GFZP01": "fzp", "GFZJ01": "fz"}
RELS = ["car_colchg", "customize", "interview", "movie", "movie_module", "option", "pilotpoint",
        "profile", "replay", "sample", "sel", "story", "title", "winning"]
MODS = ["main", "main_rel"] + RELS
DTK = ROOT / "build" / "tools" / "dtk"
NM = ROOT / "build" / "binutils" / "powerpc-eabi-nm"

FUNC_LINE = re.compile(r"(\S+) = \.text:0x([0-9A-F]+); // type:function size:0x([0-9A-F]+)(.*)")
SYM_LINE = re.compile(r"(\S+) = (\.\w+):0x([0-9A-F]+);")
# dtk auto names: lbl_<mod>_<sec>_<off>, fn_<mod>_<off>, <anything>_<8-hex address> (main)
AUTO = re.compile(r"^(?:(?:lbl|jumptable|gap)_(\d+)_(\w+?)_([0-9A-F]+)|fn_(\d+)_([0-9A-F]+)|\w+?_([0-9A-F]{8}))$")
SEC = {s.strip("."): s for s in (".init", ".text", ".ctors", ".dtors", ".rodata", ".data", ".bss",
                                 ".sdata", ".sbss", ".sdata2", ".sbss2")}


def cfg(ver: str, mod: str, name: str) -> Path:
    return ROOT / "config" / ver / name if mod == "main" else ROOT / "config" / ver / mod / name


def orig_file(ver: str, mod: str) -> Path:
    base = ROOT / "orig" / ver
    if mod == "main":
        return base / "sys" / "main.dol"
    if mod == "main_rel":
        return base / "files" / "enemy_line" / "main.rel"
    return base / "files" / f"{REL_PREFIX[ver]}.{mod}.rel"


def be32(d: bytes, o: int) -> int:
    return struct.unpack_from(">I", d, o)[0]


# ---------------------------------------------------------------- 1. function names

def text_sections(data: bytes, mod: str) -> list[tuple[int, bytes]]:
    if mod == "main":
        return [(be32(data, 0x48 + k * 4), data[be32(data, k * 4):be32(data, k * 4) + be32(data, 0x90 + k * 4)])
                for k in range(7) if be32(data, k * 4)]
    n, tab = be32(data, 0x0C), be32(data, 0x10)
    secs = []
    for k in range(n):
        off, size = be32(data, tab + k * 8), be32(data, tab + k * 8 + 4)
        if off & 1 and size:
            secs.append((0, data[off & ~1:(off & ~1) + size]))
    return [max(secs, key=lambda s: len(s[1]))]  # .text


def masked(code: bytes) -> bytes:
    words = []
    for i in range(0, len(code) - 3, 4):
        w = be32(code, i)
        op = w >> 26
        if op == 18:
            w &= ~0x03FFFFFC
        elif op == 16:
            w &= ~0xFFFC
        elif op in (14, 15, 24, 25) or 32 <= op <= 55:
            w &= ~0xFFFF
        words.append(w)
    return struct.pack(f">{len(words)}I", *words)


def lis_keep(pairs: list[tuple[int, int]]) -> set[int]:
    """Indices of the longest subsequence increasing in both coordinates (pairs sorted by [0])."""
    tails, tail_vals, prev = [], [], [-1] * len(pairs)
    for i, (_, b) in enumerate(pairs):
        j = bisect.bisect_left(tail_vals, b)
        if j == len(tails):
            tails.append(i); tail_vals.append(b)
        else:
            tails[j] = i; tail_vals[j] = b
        prev[i] = tails[j - 1] if j else -1
    keep, k = set(), tails[-1] if tails else -1
    while k >= 0:
        keep.add(k); k = prev[k]
    return keep


def map_functions(ver: str) -> dict[str, dict[str, tuple[int, int, str]]]:
    """module -> {US name: (region addr, size, attribute tail)}."""
    out = {}
    for mod in MODS:
        us, rg = orig_file(US, mod).read_bytes(), orig_file(ver, mod).read_bytes()
        us_t, rg_t = text_sections(us, mod), text_sections(rg, mod)
        rg_m = [(v, masked(b)) for v, b in rg_t]
        hits = []
        for line in cfg(US, mod, "symbols.txt").read_text().splitlines():
            m = FUNC_LINE.match(line)
            if not m or int(m.group(3), 16) < 16:
                continue
            name, addr, size, tail = m.group(1), int(m.group(2), 16), int(m.group(3), 16), m.group(4)
            code = next((b[addr - v:addr - v + size] for v, b in us_t if v <= addr < v + len(b)), None)
            if not code or len(code) != size:
                continue
            pat, found = masked(code), []
            for v, mb in rg_m:
                i = mb.find(pat)
                while i >= 0 and len(found) < 2:
                    if i % 4 == 0:
                        found.append(v + i)
                    i = mb.find(pat, i + 1)
            if len(found) == 1:
                hits.append((addr, found[0], name, size, tail))
        hits.sort()
        seen = collections.Counter(h[1] for h in hits)
        hits = [h for h in hits if seen[h[1]] == 1]
        keep = lis_keep([(h[0], h[1]) for h in hits])
        out[mod] = {h[2]: (h[1], h[3], h[4]) for i, h in enumerate(hits) if i in keep}
    return out


# ---------------------------------------------------------------- 2. split and compare

def dtk_split(config_yml: Path, out: Path) -> None:
    r = subprocess.run([str(DTK), "dol", "split", "--no-update", str(config_yml), str(out)],
                       cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        raise RuntimeError(r.stdout[-2000:] + r.stderr[-2000:])


def split_us_whole(tmp: Path) -> Path:
    """Split GFZE01 with symbols but no per-unit splits, so every function lands in dtk asm."""
    text = (ROOT / "config" / US / "config.yml").read_text()
    symfiles = {}

    def splits(m):
        p = ROOT / m.group(1)
        t = p.read_text()
        d = tmp / ("splits_" + m.group(1).replace("/", "_"))
        d.write_text(t.split("\n\n")[0] + "\n" if t.startswith("Sections:") else "")
        return f"splits: {d}"

    def symbols(m):
        d = tmp / ("symbols_" + m.group(1).replace("/", "_"))
        lines, seen = [], set()
        for line in (ROOT / m.group(1)).read_text().splitlines():
            n = line.split(" = ")[0]
            if n not in seen:
                seen.add(n); lines.append(line)
        d.write_text("\n".join(lines) + "\n")
        symfiles[m.group(1)] = d
        return f"symbols: {d}"

    text = re.sub(r"splits: (\S+)", splits, text)
    text = re.sub(r"symbols: (config\S+)", symbols, text)
    yml = tmp / "us.yml"
    yml.write_text(text)
    out = tmp / "us_split"
    for _ in range(20):  # a label that is also a split boundary in the full config: drop and retry
        try:
            dtk_split(yml, out)
            return out
        except RuntimeError as e:
            m = re.search(r'Duplicate symbols at [^\[]*\[\(\d+, ObjSymbol \{ name: "([^"]+)"', str(e))
            if not m:
                raise
            for d in symfiles.values():
                d.write_text("".join(l + "\n" for l in d.read_text().splitlines()
                                     if not l.startswith(m.group(1) + " = ")))
    raise RuntimeError("GFZE01 split did not converge")


FN_START = re.compile(r"^\.fn (\S+),")
FN_END = re.compile(r"^\.endfn ")
INS = re.compile(r"^/\* [0-9A-F]+ [0-9A-F]+  (?:[0-9A-F]{2} ){4}\*/\t(.*)$")
OPSYM = re.compile(r"([A-Za-z_@$.][\w@$.]*)@(ha|h|l|sda21)")
BRANCH = re.compile(r"^(?:b|bl|bc|beq|bne|blt|bgt|ble|bge|bdnz|bdz|bso|bns)[a-z+-]*\s+(?:cr\d,\s*)?([A-Za-z_@$.][\w@$.]*)$")
DEFS = re.compile(r"^\.(?:fn|obj|sym) (\S+?),")


def parse_asm(root: Path) -> tuple[dict[str, list[str]], collections.Counter]:
    fns, defined = {}, collections.Counter()
    for dp, _, files in os.walk(root):
        for f in files:
            if not f.endswith(".s"):
                continue
            cur = None
            for line in open(os.path.join(dp, f), errors="replace"):
                line = line.rstrip("\n")
                m = DEFS.match(line)
                if m:
                    defined[m.group(1)] += 1
                m = FN_START.match(line)
                if m:
                    cur = m.group(1); fns[cur] = []; continue
                if FN_END.match(line):
                    cur = None; continue
                if cur is not None:
                    m = INS.match(line)
                    if m:
                        fns[cur].append(m.group(1).split(" #")[0].strip())
    return fns, defined


def skeleton(ins: str) -> tuple[str, list[str]]:
    syms = [m.group(1) for m in OPSYM.finditer(ins)]
    skel = OPSYM.sub("S", ins)
    m = BRANCH.match(skel)
    if m and not m.group(1).startswith(".L_") and m.group(1) != "S":
        syms.append(m.group(1))
        skel = skel[:m.start(1)] + "S"
    return re.sub(r"\.L_[0-9A-F]+", "L", skel), syms


def pair_symbols(us_fns, rg_fns):
    votes = collections.defaultdict(collections.Counter)
    pairs = {}
    for name in us_fns.keys() & rg_fns.keys():
        a, b = us_fns[name], rg_fns[name]
        if len(a) != len(b):
            continue
        sa, sb = [skeleton(x) for x in a], [skeleton(x) for x in b]
        if any(x[0] != y[0] or len(x[1]) != len(y[1]) for x, y in zip(sa, sb)):
            continue
        p = [(s1, s2) for x, y in zip(sa, sb) for s1, s2 in zip(x[1], y[1])]
        pairs[name] = p
        for s1, s2 in p:
            votes[s1][s2] += 1
    mp = {s: next(iter(c)) for s, c in votes.items() if len(c) == 1}
    owners = collections.Counter(mp.values())
    mp = {s: t for s, t in mp.items() if owners[t] == 1}
    identical = {n for n, p in pairs.items() if all(mp.get(s1) == s2 for s1, s2 in p)}
    return mp, identical


# ---------------------------------------------------------------- 3. region symbol addresses

def region_sections(split_root: Path) -> list[tuple[int, int, str]]:
    secs = []
    for f in sorted((split_root / "asm").glob("*.s")):
        head = f.read_text(errors="replace")[:4096]
        r = re.search(r"# 0x([0-9A-F]+)\.\.0x([0-9A-F]+) \| size", head)
        s = re.search(r"\n(?:\.section )?(\.\w+)", head[r.end():]) if r else None
        if r and s:
            secs.append((int(r.group(1), 16), int(r.group(2), 16), s.group(1)))
    return secs


def module_ids(ver: str) -> dict[str, int]:
    ids = {m: be32(orig_file(ver, m).read_bytes(), 0) for m in RELS}
    ids["main_rel"] = 1
    return ids


def auto_addr(name: str, mod: str, mod_id: dict[str, int], main_secs) -> tuple[str, int] | None:
    m = AUTO.match(name)
    if not m:
        return None
    g = m.groups()
    if g[0] is not None:
        sec = SEC.get(g[1].lower())
        return (sec, int(g[2], 16)) if sec and mod != "main" and mod_id.get(mod) == int(g[0]) else None
    if g[3] is not None:
        return (".text", int(g[4], 16)) if mod != "main" and mod_id.get(mod) == int(g[3]) else None
    if mod != "main":
        return None
    a = int(g[5], 16)
    return next(((sec, a) for lo, hi, sec in main_secs if lo <= a < hi), None)


# ---------------------------------------------------------------- relocation pairing

REL_SECTIONS = [None, ".text", ".ctors", ".dtors", ".rodata", ".data", ".bss"]


def rel_relocations(data: bytes) -> dict[tuple[int, int, int], tuple[int, int, int]]:
    """(section, offset, type) -> (target module id, target section, addend) for a REL."""
    imp, size = be32(data, 0x28), be32(data, 0x2C)
    out = {}
    for i in range(imp, imp + size, 8):
        pos = be32(data, i + 4)
        mid, sec, addr = be32(data, i), 0, 0
        while True:
            off, typ, s, add = struct.unpack_from(">HBBI", data, pos)
            pos += 8
            if typ == 203:
                break
            if typ == 202:
                sec, addr = s, 0
                continue
            addr += off
            out[(sec, addr, typ)] = (mid, s, add)
    return out


def identical_module(ver: str, mod: str) -> bool:
    """Same section layout, same relocation sites and same bytes outside them."""
    if mod == "main":
        return False
    a, b = orig_file(US, mod).read_bytes(), orig_file(ver, mod).read_bytes()
    n = be32(a, 0x0C)
    if n != be32(b, 0x0C):
        return False
    ta, tb = be32(a, 0x10), be32(b, 0x10)
    secs = []
    for k in range(n):
        oa, sa, ob, sb = be32(a, ta + k * 8), be32(a, ta + k * 8 + 4), be32(b, tb + k * 8), be32(b, tb + k * 8 + 4)
        if sa != sb or (oa == 0) != (ob == 0):
            return False
        secs.append((oa & ~1, ob & ~1, sa))
    ra, rb = rel_relocations(a), rel_relocations(b)
    if ra.keys() != rb.keys():
        return False
    holes = collections.defaultdict(set)
    for sec, off, _ in ra:
        holes[sec].update(range(off & ~3, (off & ~3) + 4))
    for k, (oa, ob, size) in enumerate(secs):
        if not oa:
            continue
        ca, cb = bytearray(a[oa:oa + size]), bytearray(b[ob:ob + size])
        for x in holes[k]:
            if x < size:
                ca[x] = cb[x] = 0
        if ca != cb:
            return False
    return True


def pair_relocations(ver: str, mod: str, us_syms_all, main_secs, mod_id) -> dict[str, tuple[str, str, int]]:
    """USA name -> (region module, section, address) for every target an identical module references."""
    us_id = module_ids(US)
    us_mod = {i: m for m, i in us_id.items()} | {0: "main"}
    rg_mod = {i: m for m, i in mod_id.items()} | {0: "main"}
    by_addr = {}
    for m, table in us_syms_all.items():
        for n, (sec, a) in table.items():
            by_addr.setdefault((m, sec if m != "main" else None, a), n)
    ra = rel_relocations(orig_file(US, mod).read_bytes())
    rb = rel_relocations(orig_file(ver, mod).read_bytes())
    out = {}
    for key, (mid, s, add) in ra.items():
        tm = us_mod.get(mid)
        if tm is None or key not in rb:
            continue
        name = by_addr.get((tm, REL_SECTIONS[s] if tm != "main" else None, add))
        if not name:
            continue
        rmid, rs, radd = rb[key]
        rm = rg_mod.get(rmid)
        if rm == "main":
            sec = next((sc for lo, hi, sc in main_secs if lo <= radd < hi), None)
        else:
            sec = REL_SECTIONS[rs] if rs < len(REL_SECTIONS) else None
        if rm and sec:
            out[name] = (rm, sec, radd)
    return out

# ---------------------------------------------------------------- 4. units

def us_text_splits() -> dict[tuple[str, str], tuple[int, int]]:
    out = {}
    for mod in MODS:
        for block in cfg(US, mod, "splits.txt").read_text().split("\n\n")[1:]:
            lines = block.strip().splitlines()
            if len(lines) == 2 and lines[1].split()[0] == ".text":
                m = re.search(r"start:0x([0-9A-F]+) end:0x([0-9A-F]+)", lines[1])
                out[(mod, lines[0][:-1])] = (int(m.group(1), 16), int(m.group(2), 16))
    return out


def nm(obj: Path) -> tuple[set[str], set[str]]:
    r = subprocess.run([str(NM), str(obj)], capture_output=True, text=True, check=True)
    undef, defs = set(), set()
    for line in r.stdout.splitlines():
        p = line.split()
        if len(p) == 2 and p[0] == "U":
            undef.add(p[1])
        elif len(p) == 3 and p[1] in "TDBRSVWtdbrsvw" and p[1].isupper():
            defs.add(p[2])
    return undef, defs


VER_FOR_HEADER = [US]


def section_header(mod: str, main_secs=None) -> str:
    """USA section header; for main.dol, alignments raised to what the region's section addresses show."""
    us = cfg(US, mod, "splits.txt").read_text().split("\n\n")[0].strip()
    if not us.startswith("Sections:"):
        return ""
    starts = {}
    if mod == "main":
        if main_secs is None:
            return us
        for lo, _, sec in main_secs:
            starts[sec] = min(lo, starts.get(sec, lo))
    else:  # REL: file offsets of the region's sections, in header order (index 1..)
        d = orig_file(VER_FOR_HEADER[0], mod).read_bytes()
        tab = be32(d, 0x10)
        names = [l.split()[0] for l in us.splitlines()[1:]]
        for i, n in enumerate(names, start=1):
            off = be32(d, tab + i * 8) & ~1
            if off:
                starts[n] = off
    out = []
    for line in us.splitlines():
        m = re.match(r"\t(\.\w+)(\s+type:\w+ align:)(\d+)", line)
        if m and m.group(1) in starts:
            need = starts[m.group(1)] & -starts[m.group(1)]
            line = f"\t{m.group(1)}{m.group(2)}{max(int(m.group(3)), min(need, 32))}"
        out.append(line)
    return "\n".join(out)


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--version", required=True, choices=["GFZP01", "GFZJ01"])
    ap.add_argument("--units", nargs="*", metavar="SOURCE",
                    help="add <VERSION> to matching_for of these units only (default: every eligible unit, and remove it elsewhere)")
    args = ap.parse_args(argv)
    ver = args.version
    VER_FOR_HEADER[0] = ver
    for p in (DTK, NM, ROOT / "build" / US / "main.dol", orig_file(ver, "main_rel"), orig_file(US, "main_rel")):
        if not p.exists():
            raise SystemExit(f"missing {p.relative_to(ROOT)}: build GFZE01 and run prepare_orig.py for both versions")

    funcs = map_functions(ver)
    mod_id = module_ids(ver)
    with tempfile.TemporaryDirectory(prefix="region_config_") as td:
        tmp = Path(td)
        # base config: function names only, no units
        for mod in MODS:
            lines = [f"{n} = .text:0x{a:08X}; // type:function size:0x{s:X}{t}"
                     for n, (a, s, t) in sorted(funcs[mod].items(), key=lambda kv: kv[1][0])]
            cfg(ver, mod, "symbols.txt").write_text("\n".join(lines) + "\n" if lines else "")
            hdr = section_header(mod) if mod == "main_rel" else ""
            cfg(ver, mod, "splits.txt").write_text(hdr + "\n" if hdr else "")
        data_align = data_alignment(ver)
        append_symbols(ver, "main_rel", data_align)
        shutil.copy(ROOT / "config" / US / "ldscript.tpl", ROOT / "config" / ver / "ldscript.tpl")
        (ROOT / "config" / ver / "units.json").unlink(missing_ok=True)

        rg_split = tmp / "rg_split"
        dtk_split(ROOT / "config" / ver / "config.yml", rg_split)
        us_fns, _ = parse_asm(split_us_whole(tmp))
        rg_fns, rg_count = parse_asm(rg_split)
        # dtk renames functions it recognises (e.g. __StringWrite); such USA names never reach the region
        for mod in MODS:
            funcs[mod] = {n: v for n, v in funcs[mod].items() if rg_count[n]}
        symmap, identical = pair_symbols(us_fns, rg_fns)
        main_secs = region_sections(rg_split)

        # region names: US functions plus paired data/labels (explicit address known)
        named: dict[str, dict[str, tuple[str, int]]] = {}
        fn_kind: set[str] = set()
        for mod in MODS:
            named[mod] = {n: (".text", a) for n, (a, _, _) in funcs[mod].items()}
        us_id = module_ids(US)
        id_to_us_mod = {i: m for m, i in us_id.items()}

        def us_module(name: str) -> str | None:
            """Module a USA auto-style name belongs to (by the USA module id it carries)."""
            m = AUTO.match(name)
            if not m:
                return None
            if m.group(1) or m.group(4):
                return id_to_us_mod.get(int(m.group(1) or m.group(4)))
            return "main"

        for usn, rgn in symmap.items():
            if usn != rgn and not AUTO.match(rgn):
                continue  # dtk's own name for it wins; the USA alias cannot be given
            for mod in MODS:
                if us_module(usn) not in (None, mod):
                    continue  # module ids differ between versions (GFZJ01): never cross modules
                a = auto_addr(rgn, mod, mod_id, main_secs)
                if a:
                    named[mod].setdefault(usn, a)
                    if rgn in rg_fns:
                        fn_kind.add(usn)
                    break
        # USA .text labels referenced by source, at the same offset in an identical function
        us_syms = {mod: {m.group(1): (m.group(2), int(m.group(3), 16))
                         for m in map(SYM_LINE.match, cfg(US, mod, "symbols.txt").read_text().splitlines()) if m}
                   for mod in MODS}
        us_types = {}
        for mod in MODS:
            for line in cfg(US, mod, "symbols.txt").read_text().splitlines():
                m = re.match(r"(\S+) = \.\w+:0x[0-9A-F]+; // type:(\w+)", line)
                if m:
                    us_types.setdefault(m.group(1), m.group(2))
        us_sizes = {mod: {m.group(1): int(m.group(3), 16)
                          for m in map(FUNC_LINE.match, cfg(US, mod, "symbols.txt").read_text().splitlines()) if m}
                    for mod in MODS}
        tokens = set()
        for dp, _, files in os.walk(ROOT / "src"):
            for f in files:
                if f.endswith((".c", ".h", ".inc")):
                    tokens.update(re.findall(r"\b[A-Za-z_]\w*", open(os.path.join(dp, f), errors="replace").read()))
        for mod in MODS:
            fns = sorted((us_syms[mod][n][1], n) for n in funcs[mod] if n in identical and n in us_syms[mod])
            starts = [a for a, _ in fns]
            for n, (sec, a) in us_syms[mod].items():
                if sec != ".text" or n in named[mod] or n not in tokens:
                    continue
                i = bisect.bisect_right(starts, a) - 1
                if i >= 0 and a - fns[i][0] < us_sizes[mod].get(fns[i][1], 0):
                    named[mod][n] = (".text", funcs[mod][fns[i][1]][0] + a - fns[i][0])

        # modules whose code and data equal the USA ones: USA symbols as they are, and the
        # targets of their relocations named exactly from the region's relocation table
        same_mods = [m for m in MODS if identical_module(ver, m)]
        verbatim = {}
        for mod in same_mods:
            named[mod] = dict(us_syms[mod])
            verbatim[mod] = cfg(US, mod, "symbols.txt").read_text()
        for mod in same_mods:
            for name, (rmod, sec, addr) in pair_relocations(ver, mod, us_syms, main_secs, mod_id).items():
                if rmod in verbatim:
                    continue
                named[rmod][name] = (sec, addr)
                fn_kind.discard(name)
                if sec in (".text", ".init") and name in us_sizes.get(rmod, {}):
                    fn_kind.add(name)

        # units
        all_named = set().union(*(set(v) for v in named.values()))
        # names dtk gives the region itself (runtime helpers it recognises: memset, _savegpr_*, ...)
        dtk_named = {n for n in rg_count if rg_count[n] == 1 and not AUTO.match(n)}
        def resolvable(n: str) -> bool:  # compiler-local labels and pool primers stay inside the object
            return n.startswith("@") or n.startswith("fzgx_pool_")
        splits_us = us_text_splits()
        cand = []
        for u in json.loads((ROOT / "config" / US / "units.json").read_text()):
            if u.get("asm") or u["status"] != "matching":
                continue
            if u["module"] in same_mods and len(u["symbols"]) > 1:
                obj = ROOT / "build" / US / "src" / (u["source"][:-2] + ".o")
                if obj.exists():
                    undef, defs = nm(obj)
                    cand.append((u, u["module"], None, undef, defs))
                continue
            if u.get("data") or len(u["symbols"]) != 1:
                continue
            fn, mod = u["symbols"][0], u["module"]
            sp = splits_us.get((mod, u["source"]))
            if not sp or fn not in funcs.get(mod, {}) or fn not in identical:
                continue
            if any(t not in all_named for t in (u.get("pool") or {}).values()):
                continue
            obj = ROOT / "build" / US / "src" / (u["source"][:-2] + ".o")
            if not obj.exists():
                continue
            undef, defs = nm(obj)
            cand.append((u, mod, sp, undef, defs))
        if os.environ.get("REGION_DEBUG"):
            miss = collections.Counter()
            dd = set().union(*(c[4] for c in cand)) | all_named | dtk_named
            for c in cand:
                for x in c[3] - dd:
                    if resolvable(x) or x.split("__fzgx_offset_")[0] in dd:
                        continue
                    miss[x] += 1
            print("top unresolved:", miss.most_common(25), file=sys.stderr)
        while True:  # every undefined reference must resolve inside the region
            defined = set().union(*(c[4] for c in cand)) | all_named | dtk_named
            keep = [c for c in cand if all(x in defined or resolvable(x) or
                                           (x.split("__fzgx_offset_")[0] in defined and "__fzgx_offset_" in x)
                                           for x in c[3])]
            if len(keep) == len(cand):
                break
            cand = keep

        if args.units is not None:
            wanted = set(args.units)
            missing = wanted - {c[0]["source"] for c in cand}
            if missing:
                raise SystemExit(f"{ver}: not eligible: {', '.join(sorted(missing))}")
            cand = [c for c in cand if c[0]["source"] in wanted]

        # region auto names that would collide with a USA name in use
        explicit_addrs = {(mod, a) for mod in MODS for a in named[mod].values()}
        used = all_named | set().union(*(c[4] for c in cand))
        ours = set().union(*(set(f) for f in funcs.values()))
        renames = collections.defaultdict(dict)
        for name in used:
            if name in ours:
                if rg_count[name] < 2:
                    continue
            elif name not in rg_count:
                continue
            for mod in MODS:
                a = auto_addr(name, mod, mod_id, main_secs)
                if a and (mod, a) not in explicit_addrs and named[mod].get(name) != a:
                    renames[mod][f"rgn_{name}"] = a
                    break

        # write
        for mod in MODS:
            if mod in verbatim:
                cfg(ver, mod, "symbols.txt").write_text(verbatim[mod])
                continue
            lines = []
            for n, (sec, a) in sorted(named[mod].items(), key=lambda kv: (kv[1][1], kv[0])):
                if n in funcs[mod]:
                    _, size, tail = funcs[mod][n]
                    lines.append(f"{n} = .text:0x{a:08X}; // type:function size:0x{size:X}{tail}")
                else:
                    kind = ("function" if n in fn_kind else "label") if sec in (".text", ".init") else "object"
                    kind = us_types.get(n, kind)  # the USA declaration knows best (memset in .init is a function)
                    lines.append(f"{n} = {sec}:0x{a:08X}; // type:{kind}")
            for n, (sec, a) in sorted(renames[mod].items(), key=lambda kv: kv[1][1]):
                kind = ("function" if n.startswith("rgn_fn_") else "label") if sec in (".text", ".init") else "object"
                lines.append(f"{n} = {sec}:0x{a:08X}; // type:{kind}")
            cfg(ver, mod, "symbols.txt").write_text("\n".join(lines) + "\n" if lines else "")
        append_symbols(ver, "main_rel", data_align)
        blocks = collections.defaultdict(list)
        us_blocks = {}
        for mod in MODS:
            for block in cfg(US, mod, "splits.txt").read_text().split("\n\n")[1:]:
                lines = block.strip().splitlines()
                if lines:
                    us_blocks[(mod, lines[0][:-1])] = block.strip()
        for u, mod, sp, _, _ in cand:
            if sp is None:  # whole unit of an identical module: same addresses as USA
                blocks[mod].append((0, us_blocks[(mod, u["source"])]))
                continue
            s, e = sp
            a = funcs[mod][u["symbols"][0]][0]
            blocks[mod].append((a, f"{u['source']}:\n\t.text       start:0x{a:08X} end:0x{a + e - s:08X}"))
        # committed: section headers only (configure.py derives the unit splits)
        check_cfg = (ROOT / "config" / ver / "config.yml").read_text()
        for mod in MODS:
            hdr = section_header(mod, main_secs)
            cfg(ver, mod, "splits.txt").write_text(hdr + "\n" if hdr else "")
            body = [b for _, b in sorted(blocks[mod])]
            full = tmp / "check_splits" / cfg(ver, mod, "splits.txt").relative_to(ROOT)
            full.parent.mkdir(parents=True, exist_ok=True)
            full.write_text("\n\n".join(([hdr] if hdr else []) + body) + "\n" if hdr or body else "")
            check_cfg = check_cfg.replace(f"splits: {cfg(ver, mod, 'splits.txt').relative_to(ROOT).as_posix()}",
                                          f"splits: {full}")
        check_yml = tmp / "check.yml"
        check_yml.write_text(check_cfg)
        # dtk may still auto-name a region symbol after a USA name in use: split, rename, repeat
        for _ in range(10):
            check = tmp / "check_split"
            shutil.rmtree(check, ignore_errors=True)
            dtk_split(check_yml, check)
            dups = []
            for mod in MODS:
                _, counts = parse_asm(check / "asm" if mod == "main" else check / mod / "asm")
                dups += [(mod, n) for n, c in counts.items() if c > 1 and not n.startswith(("gap_", "pad_"))]
            if not dups:
                break
            for dmod, n in dups:
                a = auto_addr(n, dmod, mod_id, main_secs)
                if not a:
                    raise SystemExit(f"duplicate region symbol {n} has no derivable address")
                kind = ("function" if n.startswith("fn_") else "label") if a[0] in (".text", ".init") else "object"
                with open(cfg(ver, dmod, "symbols.txt"), "a") as f:
                    f.write(f"rgn_{n} = {a[0]}:0x{a[1]:08X}; // type:{kind}\n")
                renames[dmod][f"rgn_{n}"] = a
        # the shared unit list records where each unit matches (matching_for, as MatchingFor)
        sys.path.insert(0, str(ROOT / "tools"))
        from fzgx.project import VERSIONS, Project, unit_matches
        chosen = {c[0]["source"] for c in cand}
        proj = Project(US)
        all_units = proj.load_units()
        for u in all_units:
            if u.get("status") != "matching":
                continue
            have = {v for v in VERSIONS if unit_matches(u, v)}
            if u["source"] in chosen:
                have.add(ver)
            elif args.units is None:
                have.discard(ver)  # a full run states every unit that matches this version
            u["matching_for"] = [v for v in VERSIONS if v in have]
        proj.save_units(all_units)
        units = [c[0] for c in cand]
        n_named = sum(len(v) for v in named.values())
        print(f"{ver}: identical modules {', '.join(same_mods) or '-'}")
        print(f"{ver}: {sum(len(v) for v in funcs.values())} functions named, {len(symmap)} symbol pairs, "
              f"{len(identical)} identical functions, {n_named} region names, "
              f"{sum(len(v) for v in renames.values())} rgn_ renames, {len(units)} C units")
    return 0


def data_alignment(ver: str) -> int:
    """main_rel .data file offset alignment (32 on PAL and JPN; dtk otherwise uses 8)."""
    d = orig_file(ver, "main_rel").read_bytes()
    off = be32(d, be32(d, 0x10) + 5 * 8) & ~1
    return min(off & -off, 32)


def append_symbols(ver: str, mod: str, align: int) -> None:
    if align <= 8:
        return
    p = cfg(ver, mod, "symbols.txt")
    text = p.read_text()
    line = f"lbl_1_data_0 = .data:0x00000000; // type:object size:0x4 align:{align}"
    if not re.search(r"= \.data:0x00000000;", text):
        p.write_text(text + line + "\n")
    else:
        p.write_text(re.sub(r"^(\S+ = \.data:0x00000000; // type:object[^\n]*)$",
                            lambda m: m.group(1) if "align:" in m.group(1) else m.group(1) + f" align:{align}",
                            text, flags=re.M))


if __name__ == "__main__":
    sys.exit(main())
