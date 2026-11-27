#!/usr/bin/env python3
"""Draft translation-unit map for main.dol (evidence only; used by DOL consolidation tooling).

Every retail TU is one contiguous block of .text. Anchors give a function's TU directly:
  - `sdkimport`: the donor source file recorded in state/sdkimports/*.json for a symbol that was
    reproduced from SDK/middleware source;
  - `string`: a function that references a `*.c` string (its __FILE__), read from the built
    objects' relocations and the retail DOL bytes.
Unanchored functions between two anchors of the same TU join it (`between`). A run between
anchors of different TUs is a boundary still to be found (`unassigned`, with both candidates).
A TU whose anchors are separated by another TU's anchor is reported as a conflict.

Usage: uv run tools/seeds/dol_tus.py [--version GFZE01] [--out state/tumap/GFZE01_main.json]
"""
from __future__ import annotations

import argparse
import glob
import json
import re
import struct
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))


def functions(version: str):
    out = []
    for line in (ROOT / "config" / version / "symbols.txt").read_text().splitlines():
        m = re.match(r"(\S+) = \.text:0x([0-9A-Fa-f]+); // type:function size:0x([0-9A-Fa-f]+)", line)
        if m:
            out.append((int(m.group(2), 16), int(m.group(3), 16), m.group(1)))
    return sorted(out)


def data_symbols(version: str):
    out = {}
    for line in (ROOT / "config" / version / "symbols.txt").read_text().splitlines():
        m = re.match(r"(\S+) = (\.\w+):0x([0-9A-Fa-f]+); // type:object size:0x([0-9A-Fa-f]+)", line)
        if m and m.group(2) != ".text":
            out[m.group(1)] = (m.group(2), int(m.group(3), 16), int(m.group(4), 16))
    return out


def sdk_sources():
    src = {}
    for f in glob.glob(str(ROOT / "state" / "sdkimports" / "*.json")):
        for k, v in json.loads(Path(f).read_text()).items():
            if isinstance(v, dict) and v.get("source"):
                p = v["source"].replace("\\", "/")
                parts = p.split("/")
                src[v.get("symbol", k)] = (parts[-1], parts[-2] if len(parts) >= 2 else "")
    return src


DONOR_ROOTS = ["build/tools/mkdd/libs/dolphin", "build/tools/mkdd/libs/PowerPC_EABI_Support",
               "build/tools/mkdd/libs/runtime_libs", "build/tools/mk-deception/src", "build/tools/sms",
               "build/tools/tww", "build/tools/sonicheroes"]
DEF_RE = re.compile(r"^(?:static\s+|inline\s+|asm\s+|extern\s+|const\s+|unsigned\s+|signed\s+|struct\s+|volatile\s+)*"
                    r"[A-Za-z_]\w*[\s*]+\**\s*([A-Za-z_]\w*)\s*\([^;{]*\)\s*\{", re.M)


def donor_files():
    """function name -> (basename, libdir) by majority vote over the donor source trees on disk
    (the same trees `fzgx sourcealign` compiles; their names are evidence, nothing is copied)."""
    votes = {}
    for r in DONOR_ROOTS:
        root = ROOT / r
        if not root.exists():
            continue
        for p in root.rglob("*.c"):
            try:
                text = p.read_text(errors="ignore")
            except OSError:
                continue
            for m in DEF_RE.finditer(text):
                c = votes.setdefault(m.group(1), Counter())
                c[(p.name, p.parent.name)] += 2 if "mkdd" in r else 1
    # only names every donor places in the same file: static helpers and callbacks reuse names
    out = {}
    for n, c in votes.items():
        if len({b for b, _ in c}) == 1 and n != "main":
            out[n] = c.most_common(1)[0][0]
    return out


POOL_SECTIONS = (".sdata2", ".rodata")


def pool_refs(version: str, funcs, dsyms):
    """function -> set of (section, address) of literal-pool/read-only objects it references,
    from the relocations of the built (matching) DOL objects. Pools are TU-private in MWCC."""
    import subprocess
    names = {n for _, _, n in funcs}
    out = {}
    for o in (ROOT / "build" / version / "src" / "dol").rglob("*.o"):
        syms = subprocess.run(["readelf", "-sW", str(o)], capture_output=True, text=True).stdout
        fn = []
        for ln in syms.splitlines():
            q = ln.split()
            if len(q) >= 8 and q[3] == "FUNC" and q[7] in names:
                fn.append((int(q[1], 16), int(q[2]), q[7]))
        if not fn:
            continue
        r = subprocess.run(["readelf", "-rW", str(o)], capture_output=True, text=True).stdout
        cur = None
        for ln in r.splitlines():
            if ln.startswith("Relocation section"):
                cur = ".text" if "'.rela.text'" in ln else None
                continue
            q = ln.split()
            if cur != ".text" or len(q) < 5:
                continue
            try:
                off = int(q[0], 16)
            except ValueError:
                continue
            d = dsyms.get(q[4])
            if not d or d[0] not in POOL_SECTIONS:
                continue
            for a, sz, n in fn:
                if a <= off < a + sz:
                    out.setdefault(n, set()).add((d[0], d[1]))
    return out


class Dol:
    def __init__(self, path: Path):
        self.data = path.read_bytes()
        h = struct.unpack(">18I18I18I", self.data[:0xD8])
        offs, addrs, sizes = h[0:18], h[18:36], h[36:54]
        self.segs = [(a, o, s) for o, a, s in zip(offs, addrs, sizes) if s]

    def read(self, addr: int, n: int) -> bytes:
        for a, o, s in self.segs:
            if a <= addr < a + s:
                return self.data[o + addr - a: o + min(addr - a + n, s)]
        return b""


def string_anchors(version: str, funcs, dsyms):
    """function -> source-file name, from relocations in the built DOL objects to `*.c` strings."""
    dol = Dol(ROOT / "orig" / version / "sys" / "main.dol")
    cstr = {}
    for name, (sec, addr, size) in dsyms.items():
        if size > 64:
            continue
        b = dol.read(addr, size)
        m = re.match(rb"(?:[^\x00]*/)?([A-Za-z0-9_]{2,40}\.c)\x00", b)
        if m:
            cstr[name] = m.group(1).decode()
    if not cstr:
        return {}, {}
    names = {n for _, _, n in funcs}
    out, why = {}, {}
    objdir = ROOT / "build" / version / "src" / "dol"
    import subprocess
    for o in objdir.rglob("*.o"):
        r = subprocess.run(["readelf", "-rW", str(o)], capture_output=True, text=True).stdout
        if not any(s in r for s in cstr):
            continue
        syms = subprocess.run(["readelf", "-sW", str(o)], capture_output=True, text=True).stdout
        fn = []
        for ln in syms.splitlines():
            p = ln.split()
            if len(p) >= 8 and p[3] == "FUNC" and p[7] in names:
                fn.append((int(p[1], 16), int(p[2]), p[7]))
        cur = None
        for ln in r.splitlines():
            if ln.startswith("Relocation section"):
                cur = ".text" if "'.rela.text'" in ln else None
                continue
            p = ln.split()
            if cur != ".text" or len(p) < 5:
                continue
            try:
                off = int(p[0], 16)
            except ValueError:
                continue
            tgt = p[4]
            if tgt in cstr:
                for a, sz, n in fn:
                    if a <= off < a + sz:
                        out[n] = cstr[tgt]; why[n] = tgt
    return out, why


def main(argv=None) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--version", default="GFZE01")
    ap.add_argument("--out", default="state/tumap/GFZE01_main.json")
    a = ap.parse_args(argv)
    funcs = functions(a.version)
    dsyms = data_symbols(a.version)
    sdk = sdk_sources()
    strs, why = string_anchors(a.version, funcs, dsyms)
    donor = donor_files()
    anchor = {}
    for _, _, n in funcs:
        if n in sdk:
            anchor[n] = (sdk[n][0], "sdkimport")
        elif n in strs:
            anchor[n] = (strs[n], "string:" + why[n])
        elif not re.match(r"^(fn|lbl|func)_", n) and n in donor:
            anchor[n] = (donor[n][0], "donor-name")
    rows = []
    libdir = {f: d for f, d in donor.values()}
    libdir.update({f: d for f, d in sdk.values()})
    for addr, size, n in funcs:
        rows.append({"name": n, "addr": addr, "size": size, "tu": anchor.get(n, (None, None))[0],
                     "how": anchor.get(n, (None, None))[1]})
    # a TU in two runs: a run held only by donor-name anchors loses to one with stronger anchors
    # (static helpers and SDK version moves); its functions go back to the unassigned pool
    def runs_of():
        out, cur = [], None
        for i, r in enumerate(rows):
            if r["tu"] and (cur is None or cur[0] != r["tu"] or cur[2] != i - 1):
                cur = [r["tu"], i, i]; out.append(cur)
            elif r["tu"]:
                cur[2] = i
        return out
    by_tu = {}
    for tu, i, j in runs_of():
        by_tu.setdefault(tu, []).append((i, j))
    for tu, spans in by_tu.items():
        if len(spans) < 2:
            continue
        strong = [s for s in spans if any(rows[k]["how"] != "donor-name" for k in range(s[0], s[1] + 1))]
        if not strong:
            continue
        for s in spans:
            if s not in strong:
                for k in range(s[0], s[1] + 1):
                    rows[k]["weak_dropped"] = rows[k]["tu"]; rows[k]["tu"] = rows[k]["how"] = None
    # literal-pool vote: a function whose pool references fall inside exactly one assigned TU's
    # pool range (per section) joins that TU, when that TU is one of its neighbours; iterate
    prefs = pool_refs(a.version, funcs, dsyms)
    for _ in range(8):
        ranges = {}
        for r in rows:
            if r["tu"]:
                for sec, ad in prefs.get(r["name"], ()):
                    lo, hi = ranges.get((r["tu"], sec), (ad, ad))
                    ranges[(r["tu"], sec)] = (min(lo, ad), max(hi, ad))
        changed = 0
        assigned_idx = [i for i, r in enumerate(rows) if r["tu"]]
        for i, r in enumerate(rows):
            if r["tu"] or r["name"] not in prefs:
                continue
            prev = next((rows[k]["tu"] for k in range(i - 1, -1, -1) if rows[k]["tu"]), None)
            nxt = next((rows[k]["tu"] for k in range(i + 1, len(rows)) if rows[k]["tu"]), None)
            votes = set()
            for sec, ad in prefs[r["name"]]:
                hit = [tu for (tu, s), (lo, hi) in ranges.items() if s == sec and lo <= ad <= hi]
                if len(hit) == 1:
                    votes.add(hit[0])
                elif len(hit) > 1:
                    votes.add(None)
            if len(votes) == 1 and None not in votes:
                tu = votes.pop()
                if tu in (prev, nxt):
                    r["tu"], r["how"] = tu, "pool-vote"; changed += 1
        if not changed:
            break
    # contiguity fill
    idx = [i for i, r in enumerate(rows) if r["tu"]]
    for i, j in zip(idx, idx[1:]):
        if j - i < 2:
            continue
        a_tu, b_tu = rows[i]["tu"], rows[j]["tu"]
        for k in range(i + 1, j):
            if a_tu == b_tu:
                rows[k]["tu"], rows[k]["how"] = a_tu, "between"
            else:
                rows[k]["candidates"] = [a_tu, b_tu]
    # conflicts: a TU interrupted by another TU's function
    seen, conflicts, last = {}, [], None
    for r in rows:
        t = r["tu"]
        if t and t != last:
            if t in seen:
                conflicts.append({"tu": t, "at": f"{r['addr']:08X}", "first": f"{seen[t]:08X}"})
            seen.setdefault(t, r["addr"])
        if t:
            last = t
    # TU list in link order
    tus, cur = [], None
    for r in rows:
        if r["tu"] and (cur is None or cur["file"] != r["tu"]):
            cur = {"file": r["tu"], "text": [r["addr"], r["addr"] + r["size"]], "functions": [], "how": Counter()}
            tus.append(cur)
        if r["tu"]:
            cur["functions"].append(r["name"]); cur["text"][1] = r["addr"] + r["size"]; cur["how"][r["how"].split(":")[0]] += 1
    total = sum(r["size"] for r in rows)
    assigned = sum(r["size"] for r in rows if r["tu"])
    out = {"version": a.version, "module": "main",
           "note": "Draft DOL ownership evidence used by the consolidation tools. Unassigned entries and conflicts are not confirmed boundaries.",
           "summary": {"functions": len(rows), "assigned": sum(1 for r in rows if r["tu"]),
                       "bytes": total, "assigned_bytes": assigned, "tus": len(tus),
                       "conflicts": len(conflicts), "string_anchored": len(strs)},
           "tus": [dict(t, lib=libdir.get(t["file"], ""), how=dict(t["how"]), text=[f"{t['text'][0]:08X}", f"{t['text'][1]:08X}"]) for t in tus],
           "conflicts": conflicts,
           "unassigned": [{"name": r["name"], "addr": f"{r['addr']:08X}", "size": r["size"], "candidates": r.get("candidates")}
                          for r in rows if not r["tu"]]}
    p = ROOT / a.out
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(json.dumps(out, indent=1) + "\n")
    s = out["summary"]
    print(f"{s['assigned']}/{s['functions']} functions, {s['assigned_bytes'] / s['bytes']:.1%} of text bytes in "
          f"{s['tus']} TU runs; {s['conflicts']} conflicts; {s['string_anchored']} string-anchored -> {a.out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
