#!/usr/bin/env python3
"""Which source form is a function actually written in?

    python3 tools/natc_asmforms.py              # audit src/ at HEAD
    python3 tools/natc_asmforms.py --json

WHY (2026-08-31). The mission headline is `exact natural-C functions`, and
`natc_metrics.asm_symbols()` decides what is still asm by looking for an
`asm void f()` whole-function definition. That misses the OTHER way to write
a function entirely in assembly:

    void UnsetRun(register void* thread)
    {
        asm { lwz r4, 0x2e0(r3) ... blr }
    }

MWCC compiles that to the retail bytes, objdiff scores it 100%, the symbol
appears on the right-hand side of the diff, and `collect()` counts it as an
exact natural-C conversion. It contains no C. Fifteen functions in src/ were
being counted that way, plus eleven more that mix real C with a bounded asm
statement. All twenty-six were inside the published headline.

THREE FORMS, THREE VERDICTS

    asm void f() { ... }              asm body   -- unconverted (asm_symbols)
    void f() { asm { ... } }          WRAPPER    -- unconverted, no C at all
    void f() { C; asm { ... }; C }    HYBRID     -- complete source, not
                                                    natural C
    void f() { C only }               exact natural C -- the mission number

A wrapper is not progress: it is an asm body wearing a C signature, and it
belongs in the remaining-work denominator exactly like `asm void f()`.

A hybrid IS progress, and is the shape the Dolphin SDK itself used for PSMTX,
OSDisableInterrupts and the cache routines -- an irreducible instruction that
no C compiler will ever select, wrapped in real C control and data flow. It is
counted in its own additive lane (audit finding 257, "inline-asm completion
tranche"), never in the natural-C headline.

CONSERVATIVE BY CONSTRUCTION, in the same direction as natc_eligibility: a
function is only called a hybrid when C survives after every asm block is
removed. Signature text does not count as C, or every wrapper would look like
a hybrid. Being wrong here understates the headline, which is the safe way to
be wrong about the number this project publishes.
"""
from __future__ import annotations

import argparse
import json
import re
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent

# `asm void Foo(` / `static asm u32 Foo(` -- a DEFINITION, not `extern asm`.
# Shared by reporting, metrics, gate and splice; retain raw match offsets.
ASM_DEF_NAME = re.compile(
    r"(?m)^(?![ \t]*extern\b)[ \t]*(?:static\s+)?asm\s+"
    r"(?:(?:static\s+)|(?:__declspec\s*\([^)]*\)\s*))*"
    r"[A-Za-z_][\w \t*]*?\b(\w+)[ \t]*\(")

# A C function DEFINITION at top level: starts in column 0, ends in `{`, with
# the brace allowed on the next line (this codebase's style).
C_DEF_NAME = re.compile(
    r"(?m)^(?!\s)(?:[A-Za-z_][\w\* \t]*?)\b(\w+)[ \t]*\((?:[^;()]|\([^()]*\))*\)"
    r"[ \t]*(?:\r?\n)?[ \t]*\{")

_NOT_FUNCTIONS = {"if", "for", "while", "switch", "return", "sizeof", "do",
                  "else", "case", "typedef", "struct", "union", "enum"}

# `asm {`, `asm (`, `__asm volatile (` -- the opening of an inline asm
# statement. `asm void f(` does not match: `asm` is followed by a type there.
ASM_STMT = re.compile(
    r"(?<![A-Za-z0-9_])(?:__asm__|__asm|asm)\s*(?:volatile\b\s*)?[({]")


def strip_declspec(text):
    """Remove MWCC declaration annotations before classifying function bodies."""
    return re.sub(r"__declspec\s*\([^)]*\)\s*", "", text)


def asm_defs(text):
    return {m.group(1) for m in ASM_DEF_NAME.finditer(strip_declspec(text))}


def c_function_ranges(text):
    """(name, start, end) for C definitions with balanced braces."""
    out = []
    for m in C_DEF_NAME.finditer(text):
        brace = text.find("{", m.start(), m.end())
        if brace < 0:
            continue
        depth, end = 0, None
        for i in range(brace, len(text)):
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
                if depth == 0:
                    end = i + 1
                    break
        if end is not None:
            out.append((m.group(1), m.start(), end))
    return out


def _strip_comments(text):
    text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
    return re.sub(r"//[^\n]*", " ", text)


def _strip_asm_statements(body):
    """Remove every inline asm statement, returning what C is left."""
    out, i = [], 0
    for m in ASM_STMT.finditer(body):
        if m.start() < i:
            continue                      # inside an already-consumed block
        out.append(body[i:m.start()])
        j = m.end() - 1
        opener = body[j]
        closer = "}" if opener == "{" else ")"
        depth = 0
        while j < len(body):
            if body[j] == opener:
                depth += 1
            elif body[j] == closer:
                depth -= 1
                if depth == 0:
                    break
            j += 1
        i = j + 1
    out.append(body[i:])
    return "".join(out)


def classify_inline_asm(text):
    """(wrappers, hybrids) -- C definitions that contain an asm statement.

    wrappers: the body is nothing but asm. Not a conversion.
    hybrids:  real C survives once the asm statements are removed.
    """
    text = strip_declspec(_strip_comments(text))
    asm_bodied = asm_defs(text)
    wrappers, hybrids = set(), set()
    for name, start, end in c_function_ranges(text):
        if name in _NOT_FUNCTIONS or name in asm_bodied:
            continue                      # already counted as an asm body
        block = text[start:end]
        brace = block.find("{")
        if brace < 0:
            continue
        body = block[brace + 1:]
        if not ASM_STMT.search(body):
            continue
        residue = _strip_asm_statements(body)
        # Punctuation alone is not C. `{ asm {...} }` leaves only braces.
        if re.sub(r"[\s{}();]", "", residue):
            hybrids.add(name)
        else:
            wrappers.add(name)
    return wrappers, hybrids


def audit_tree(root=None):
    """Classify every .c file under src/. Returns {path: (wrappers, hybrids)}."""
    root = Path(root) if root else REPO / "src"
    out = {}
    for p in sorted(root.rglob("*.c")):
        w, h = classify_inline_asm(p.read_text(errors="replace"))
        if w or h:
            out[str(p.relative_to(REPO)) if p.is_relative_to(REPO) else str(p)] = (w, h)
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--json", action="store_true")
    ap.add_argument("--root", default=None)
    args = ap.parse_args()

    tree = audit_tree(args.root)
    wrap = sorted(n for w, _ in tree.values() for n in w)
    hyb = sorted(n for _, h in tree.values() for n in h)

    if args.json:
        json.dump({"wrappers": wrap, "hybrids": hyb,
                   "by_file": {f: {"wrappers": sorted(w), "hybrids": sorted(h)}
                               for f, (w, h) in tree.items()}},
                  sys.stdout, indent=2)
        print()
        return

    print(f"ASM WRAPPER  {len(wrap):>4}  C signature, asm-only body "
          f"-- NOT a conversion, belongs in the remaining denominator")
    for f, (w, _) in tree.items():
        for n in sorted(w):
            print(f"    {n:<32s} {f}")
    print(f"\nHYBRID       {len(hyb):>4}  real C + bounded asm statement "
          f"-- complete source, additive lane, never natural-C headline")
    for f, (_, h) in tree.items():
        for n in sorted(h):
            print(f"    {n:<32s} {f}")


if __name__ == "__main__":
    main()
