#!/usr/bin/env python3
"""Classify the differing rows of the near-miss band by *what kind* of difference they are.

`fzgx stuck --min-percent N` labels a plateaued body with a mode -- `regalloc`, `imm`,
`schedule`, `frame`, `reloc` -- and the >=99% band is 109/135 `regalloc`. That label is
the objdiff row category, not a source shape: parsing all 395 differing rows across the
60 closest functions shows 59% are the same mnemonic with a different register, and that
those split into at least three unrelated causes (a return value in the wrong register, a
calleee-saved pair swapped, an address base chosen differently). See
docs/findings/285.

This exists so the distribution can be re-measured as the band drains, instead of being
re-derived by hand -- and so the next person asking "is regalloc one shape?" gets the
split in one command rather than a wrong answer in one.

    python3 tools/fzgx/shapecensus.py --min-percent 99 --limit 60 [--json]

Read-only: compiles each saved best body with its saved compiler profile and reads
objdiff's rows.
Two traps this had to be written around, both of which look like real results:

  * `oracle.check(..., 0, ...)` returns **zero** diff rows, not unlimited ones. Passing
    0 yields an empty census that reads as "no differences", so a real limit is required.
  * a diff row contains *both* sides (`target | ours`). Grepping the whole row matches
    retail's text; only the text after the pipe is our output.
"""

from __future__ import annotations

import argparse
import collections
import json
import re
import sqlite3
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

from fzgx import oracle  # noqa: E402
from fzgx.project import STATE_DIR, Project  # noqa: E402
from fzgx.work_evidence import source_record  # noqa: E402

# A divergence row is "<flag> <addr>  <mnemonic> <operands>  |  <mnemonic> <operands>",
# where the flag is one of < > ? p ~ !. A row with NO flag character is a row objdiff
# shows as matching -- it starts with spaces -- and is not a divergence at all. Those are
# excluded deliberately rather than reported as "unparsed", because counting them as
# divergences would overstate the problem and counting them as differences would be a lie.
ROW = re.compile(r"^\s*[<>?p~!]\s+[0-9A-Fa-f]+\s+(.*?)\s*\|\s*(.*?)\s*$")
MATCHED_ROW = re.compile(r"^\s+[0-9A-Fa-f]+\s+")
# GPRs *and* FPRs. Matching only r\d+ made every floating-point row fall through to
# "operands textual only", which is how 59 of 395 rows were misfiled on the first run --
# and those rows are a real, separate shape: f6/f7, f1/f3 swaps are register choices in
# the float file, with their own idiom (docs/MWCC_IDIOMS.md, paired-scalar and the f31
# materialisation rules). Splitting the two files apart is also how they get ranked.
SPLIT = re.compile(r"[rf]\d+")
IMMEDIATE = re.compile(r"0x[0-9A-Fa-f]+|-?\b\d+\b")


def _side(text: str) -> tuple:
    parts = text.split()
    return (parts[0], " ".join(parts[1:])) if parts else ("", "")


def word_diff(p, symbol, body: str, *, mw=None, flags=None):
    """Differing *words* between retail and our compiled object -- the honest defect count.

    objdiff's diff is row-aligned, so one divergence late in a function makes every following
    row report as flagged, and the `p` (relocation) flag then makes those rows look like
    binding problems. `fn_1_2D038` showed 26 differing rows for a single differing word.

    This returns the differing word indices and their decoded register/offset fields, which is
    what actually separates "one instruction away" from "structurally different" -- and that
    distinction decides whether a function is worth a model session or a generator.
    """
    sym = p.resolve(symbol)
    target = p.target_object_for(sym)
    theirs = oracle.words(target, sym.name)
    with tempfile.TemporaryDirectory() as td:
        src = Path(td) / "b.c"
        obj = Path(td) / "b.o"
        src.write_text(body)
        # Pin the effective default too: check() otherwise probes several compiler
        # profiles, which can make the word count and row count describe different code.
        mw = mw or oracle.module_flags(p, sym.module)[1]
        if oracle.compile_source(p, sym.module, src, obj, mw, flags).returncode:
            return None
        ours = oracle.words(obj, sym.name)
        # The same compile, read through objdiff, for the class the word count cannot see.
        check = oracle.check(p, symbol, 0, source=src, mw_version=mw, extra_cflags=flags)
        if not check.ok:
            return None
    if not theirs or not ours or len(theirs) != len(ours):
        return None
    rows = []
    for i, (a, b) in enumerate(zip(theirs, ours)):
        if a != b:
            rows.append({"index": i, "retail": "%08X" % a, "ours": "%08X" % b,
                         "opcode": (a >> 26) & 0x3F,
                         "retail_regs": ["r%d" % ((a >> 21) & 0x1F), "r%d" % ((a >> 16) & 0x1F)],
                         "our_regs": ["r%d" % ((b >> 21) & 0x1F), "r%d" % ((b >> 16) & 0x1F)],
                         "retail_disp": a & 0xFFFF, "our_disp": b & 0xFFFF})
    # A relocation difference does not change the instruction word, so `len(rows)` alone
    # reports ZERO for a body whose only defect is which symbol an instruction binds to --
    # the shared-pool case (`lis r4, lbl_10_rodata_158@ha` against `...rodata.0@ha`).
    # fn_10_1B2F4, fn_1_15EC40 and fn_1_9DB04 all read as "0 words differing" that way and
    # are not done, so the row count is reported alongside and the two are read together.
    left, right = check._rows
    flagged = sum((a.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE' or
                  (b.get('diff_kind') or 'DIFF_NONE') != 'DIFF_NONE'
                  for a, b in zip(left, right)) + abs(len(left) - len(right))
    return {"words": len(theirs), "differing": len(rows), "rows": rows,
            "flagged_rows": flagged,
            "note": "'differing' counts instruction words only; a relocation-only defect leaves "
                    "it at 0, so read flagged_rows too before calling a function finished"}


def classify(diff_lines) -> collections.Counter:
    """Row-level divergence classes. Kept separate from the data gathering so it can be
    unit-exercised against literal diff rows without compiling anything.

    Matching rows objdiff prints as context are skipped rather than counted: they are
    excluded from the totals so the classes sum to real divergences only. Use `word_diff` for
    a defect count -- this counts *rows*, which objdiff aligns, and that is not the same thing.
    """
    out: collections.Counter = collections.Counter()
    for line in diff_lines:
        m = ROW.match(line)
        if not m:
            if not MATCHED_ROW.match(line):
                out["unparsed divergence row"] += 1
            continue
        mnem_a, ops_a = _side(m.group(1))
        mnem_b, ops_b = _side(m.group(2))
        if not mnem_a or not mnem_b:
            out["insert/delete (one side empty)"] += 1
        elif mnem_a != mnem_b:
            out["different mnemonic: %s -> %s" % (mnem_a, mnem_b)] += 1
        else:
            ra, rb = SPLIT.findall(ops_a), SPLIT.findall(ops_b)
            ia, ib = IMMEDIATE.findall(ops_a), IMMEDIATE.findall(ops_b)
            if ra != rb and ia == ib:
                out["same mnemonic, register differs: %s -> %s" % (mnem_a, mb(ra, rb))] += 1
            elif ia != ib and ra == rb:
                out["same mnemonic, immediate differs"] += 1
            elif ra != rb:
                out["same mnemonic, register AND immediate differ"] += 1
            elif line.strip().startswith("p"):
                # Identical mnemonic, registers and immediates on both sides. objdiff's `p`
                # marks a row that differs only in relocation binding, so these carry no
                # codegen information at all -- 48 of 395 on the >=99% band, all of them `p`.
                # Counted separately so they cannot be mistaken for unfixed source, which is
                # what they look like if you only compare text.
                out["relocation-only (p flag, no codegen difference)"] += 1
            else:
                out["same mnemonic, operands textual only"] += 1
    return out


def mb(ra, rb) -> str:
    return "%s->%s" % (",".join(ra), ",".join(rb))


def main(argv=None) -> int:
    ap = argparse.ArgumentParser()
    ap.add_argument("--min-percent", type=float, default=99.0)
    ap.add_argument("--limit", type=int, default=60)
    ap.add_argument("--module")
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--words", action="store_true",
                    help="rank by differing WORD count instead of diff rows (the honest defect count)")
    ap.add_argument("--top", type=int, default=20, help="how many to show in --words mode")
    a = ap.parse_args(argv)
    p = Project()
    db = sqlite3.connect(str(STATE_DIR / "ledger.db"))
    q = "SELECT symbol,module FROM functions WHERE status='unmatched' AND best_percent>=?"
    args = [a.min_percent]
    if a.module:
        q += " AND module=?"
        args.append(a.module)
    rows = db.execute(q + " ORDER BY best_percent DESC LIMIT ?", (*args, a.limit)).fetchall()

    if a.words:
        scored = []
        for symbol, _module in rows:
            try:
                source = source_record(p, symbol)
                if not source['body']:
                    continue
                wd = word_diff(p, symbol, source['body'], mw=source['mw'], flags=source['flags'])
            except Exception:
                wd = None
            if wd:
                # `rows` is empty when the words are byte-identical, so the flagged-row count
                # (relocation-only defects) has to ride along in the tuple or it is lost.
                scored.append((wd["differing"], wd["words"], symbol, wd["rows"],
                               wd.get("flagged_rows", 0)))
        scored.sort(key=lambda t: (t[0], t[2]))
        if a.json:
            print(json.dumps([{"symbol": s, "differing": d, "words": w, "rows": r,
                               "flagged_rows": f}
                              for d, w, s, r, f in scored], indent=1))
            return 0
        print("ranked by differing words (%d functions)\n" % len(scored))
        print("%-20s %5s %6s %7s  first divergences" % ("symbol", "diff", "rows", "words"))
        for d, w, s, r, flagged in scored[:a.top]:
            first = "; ".join("w%d %s%s/%s%s" % (x["index"], x["retail"], x["retail_regs"],
                                                x["ours"], x["our_regs"]) for x in r[:2])
            print("%-20s %5d %6d %7d  %s" % (s, d, flagged, w, first[:52]))
        print()
        print("diff=instruction words differing; rows=objdiff flagged rows.")
        print("A relocation-only defect leaves diff at 0 with rows>0: that is a shared-pool")
        print("binding to fix, not a finished function.")
        return 0

    tally: collections.Counter = collections.Counter()
    seen = rows_ok = 0
    per_function = []
    for symbol, _module in rows:
        try:
            source = source_record(p, symbol)
            if not source['path']:
                continue
            sym = p.resolve(symbol)
            res = oracle.check(p, symbol, sym.size // 2 + 4, source=Path(source['path']),
                               mw_version=source['mw'] or oracle.module_flags(p, sym.module)[1],
                               extra_cflags=source['flags'])
        except Exception as error:                    # one bad body must not end the census
            tally["compile/resolve failed: %s" % type(error).__name__] += 1
            continue
        if not res.ok:
            continue
        rows_ok += 1
        classes = classify(res.diff or [])
        tally.update(classes)
        seen += sum(classes.values())
        per_function.append({"symbol": symbol, "percent": round(res.percent, 3),
                             "rows": sum(classes.values()),
                             "classes": dict(classes.most_common(4))})
    if a.json:
        print(json.dumps({"examined": len(rows), "with_diff": rows_ok, "rows": seen,
                          "classes": dict(tally.most_common()), "functions": per_function},
                         indent=1))
        return 0
    print("examined %d  with a diff %d  rows %d" % (len(rows), rows_ok, seen))
    print()
    for name, n in tally.most_common(24):
        print("  %-58s %4d" % (name[:58], n))
    if seen:
        print()
        print("rows per function: median-ish view of the closest few")
        for r in per_function[:10]:
            print("  %-22s %7.3f%%  %3d rows  %s"
                  % (r["symbol"], r["percent"], r["rows"], list(r["classes"])[:2]))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
