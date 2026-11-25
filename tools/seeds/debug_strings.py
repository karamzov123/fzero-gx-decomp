#!/usr/bin/env python3
"""Recover translation-unit anchors from __FILE__ strings embedded in a REL.

CodeWarrior emits each TU's string literals into that TU's own .data block, and
links TUs in one order for every section. So a `*.c` string's address orders
its TU in .data, and the functions that reference it (via lis/addi relocations
from .text) bound the TU in .text. Every TU has a contiguous block in each
section, so any function that references .data inside [anchor_k, anchor_k+1)
belongs to TU k, which resolves functions that never touch the __FILE__ string.

Usage: uv run tools/seeds/debug_strings.py [--module main_rel] [--write]
Writes config/<VERSION>/<module>/tus.json: ordered TUs with text/data ranges
and the list of functions assigned to each (with confidence).
"""

from __future__ import annotations

import argparse
import json
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
from fzgx.project import Project  # noqa: E402  (script in a subdir of tools/; scoped: sibling package on path)

FILE_RE = re.compile(rb"[A-Za-z0-9_]{2,30}\.c\x00")


def rel_sections(data: bytes):
    v = struct.unpack(">16I", data[:0x40])
    numsec, secoff = v[3], v[4]
    out = []
    for i in range(numsec):
        o, s = struct.unpack(">II", data[secoff + 8 * i: secoff + 8 * i + 8])
        out.append((i, o & ~3, s, o & 1))
    return out, v[10], v[11]  # sections, impoff, impsize


def rel_relocs(data: bytes, impoff: int, impsize: int, self_id: int):
    """Yield (from_sec, from_off, to_sec, to_off) for self-module relocations."""
    for k in range(impsize // 8):
        m, ro = struct.unpack(">II", data[impoff + 8 * k: impoff + 8 * k + 8])
        if m != self_id:
            continue
        p, cursec, pos = ro, None, 0
        while True:
            off, typ, sec, add = struct.unpack(">HBBI", data[p: p + 8])
            p += 8
            if typ == 203:
                break
            if typ == 202:
                cursec, pos = sec, 0
                continue
            pos += off
            yield cursec, pos, sec, add


def main(argv=None) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", default="main_rel")
    ap.add_argument("--version", default="GFZE01")
    ap.add_argument("--write", action="store_true")
    a = ap.parse_args(argv)
    p = Project(a.version)
    cfg = (p.config_dir / "config.yml").read_text().splitlines()
    obj = None
    for i, line in enumerate(cfg):
        if line.strip() == f"name: {a.module}":
            obj = next(l.split(":", 1)[1].strip() for l in reversed(cfg[:i]) if l.startswith("- object:"))
            break
    if obj is None:
        raise SystemExit(f"module {a.module} not in config.yml")
    data = (Path("orig") / a.version / obj).read_bytes()
    secs, impoff, impsize = rel_sections(data)
    self_id = struct.unpack(">I", data[:4])[0]
    by_index = {i: (o, s) for i, o, s, x in secs}
    text_i = 1
    data_secs = [i for i, o, s, x in secs if s and not x and i != text_i and o]  # rodata/data (file-backed)

    # 1. all *.c strings in file-backed non-code sections
    anchors = []
    for i in data_secs:
        o, s = by_index[i]
        for m in FILE_RE.finditer(data, o, o + s):
            anchors.append((i, m.start() - o, m.group().rstrip(b"\0").decode()))
    anchors.sort()
    # 2. code -> data relocations
    refs = defaultdict(list)  # (sec, off) -> [text offsets]
    for fs, fo, ts, to in rel_relocs(data, impoff, impsize, self_id):
        if fs == text_i and ts in by_index:
            refs[(ts, to)].append(fo)
    funcs = p.functions(a.module)
    def fn_at(off):
        lo, hi = 0, len(funcs) - 1
        while lo <= hi:
            mid = (lo + hi) // 2
            f = funcs[mid]
            if f.addr <= off < f.end:
                return f
            if off < f.addr:
                hi = mid - 1
            else:
                lo = mid + 1
        return None
    # The code references the *start* of the string object, which may sit a few bytes before
    # the regex match ("../sprite.c", "src/main.c") or a few bytes after it when the regex
    # swallowed stray non-string bytes ahead of the name. Anchor on the relocation target.
    PATH_RE = re.compile(rb"[A-Za-z0-9_./\\-]{2,60}\.c\x00")
    rows = []
    seen = set()
    for sec, off, name in anchors:
        end = off + len(name) + 1
        cands = [t for (ts, t) in refs if ts == sec and off - 24 <= t < end - 2]
        best = None
        for t in sorted(cands, key=lambda t: abs(t - off)):
            m = PATH_RE.match(data, by_index[sec][0] + t)
            if m and m.end() - by_index[sec][0] == end:
                best = t
                break
        if best is None:
            continue
        full = data[by_index[sec][0] + best:by_index[sec][0] + end - 1].decode()
        if (sec, best) in seen:
            continue
        seen.add((sec, best))
        users = sorted({fn_at(t).addr for t in refs.get((sec, best), []) if fn_at(t)})
        rows.append({"file": full.replace("\\", "/").rsplit("/", 1)[-1], "path": full, "sec": sec, "data_off": best, "refs": users})
    # 3. keep anchors in a consistent order: data order must agree with text order of first refs
    ordered = [r for r in rows if r["refs"]]
    ordered.sort(key=lambda r: (r["sec"], r["data_off"]))
    print(f"{len(rows)} file strings, {len(ordered)} with code references")
    bad = [(ordered[i]["file"], ordered[i + 1]["file"]) for i in range(len(ordered) - 1)
           if ordered[i]["refs"][0] > ordered[i + 1]["refs"][0]]
    print("order violations (data order vs text order):", bad)
    if not ordered:
        print("no anchored TUs; nothing written")
        return 0
    # 4. TU text ranges: [first ref of k, first ref of k+1); data ranges likewise (same section only)
    tus = []
    for i, r in enumerate(ordered):
        nxt = ordered[i + 1] if i + 1 < len(ordered) else None
        t_lo = r["refs"][0]
        t_hi = nxt["refs"][0] if nxt else funcs[-1].end
        d_lo = r["data_off"]
        d_hi = nxt["data_off"] if nxt and nxt["sec"] == r["sec"] else by_index[r["sec"]][1]
        tus.append({"file": r["file"], "text": [t_lo, t_hi], "data_sec": r["sec"], "data": [d_lo, d_hi],
                    "anchor_refs": r["refs"]})
    # 5. assign functions: inside a text range -> that TU; refine boundary zone by data refs
    fn_data = defaultdict(set)
    for (ts, to), users in refs.items():
        for t in users:
            f = fn_at(t)
            if f:
                fn_data[f.addr].add((ts, to))
    # only *private* data votes: a literal/static referenced by <= 3 functions cannot be another
    # file's global (shared globals are referenced from everywhere and would poison the vote)
    data_users = {key: len(set(fn_at(t).addr for t in users if fn_at(t))) for key, users in refs.items()}
    assigned = {}
    for f in funcs:
        k = None
        for i, tu in enumerate(tus):
            if tu["text"][0] <= f.addr < tu["text"][1]:
                k = i
                break
        if k is None:
            continue
        conf = "text-range"
        votes = defaultdict(int)
        for ts, to in fn_data.get(f.addr, ()):
            if data_users.get((ts, to), 99) > 3:
                continue
            for j, tu in enumerate(tus):
                if tu["data_sec"] == ts and tu["data"][0] <= to < tu["data"][1]:
                    votes[j] += 1
        if votes:
            best = max(votes, key=votes.get)
            if best != k:
                k, conf = best, "data-vote"
            else:
                conf = "text+data"
        assigned[f.name] = (k, conf)
    for i, tu in enumerate(tus):
        tu["functions"] = [f.name for f in funcs if assigned.get(f.name, (None,))[0] == i]
        tu["confidence"] = {c: sum(1 for f in tu["functions"] if assigned[f][1] == c) for c in ("text+data", "text-range", "data-vote")}
    before_first = [f.name for f in funcs if f.addr < tus[0]["text"][0]]
    print(f"functions before the first anchor (prolog/runtime, unassigned): {len(before_first)}")
    print(f"{'file':20s} {'text range':17s} {'fns':>4s} {'t+d':>4s} {'t':>4s} {'vote':>4s}")
    for tu in tus:
        c = tu["confidence"]
        print(f"{tu['file']:20s} {tu['text'][0]:06X}-{tu['text'][1]:06X} {len(tu['functions']):4d} {c['text+data']:4d} {c['text-range']:4d} {c['data-vote']:4d}")
    if a.write:
        out = p.module_config_dir(a.module) / "tus.json"
        out.write_text(json.dumps({"module": a.module, "unassigned_prefix": before_first, "tus": tus}, indent=1) + "\n")
        print("wrote", out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
