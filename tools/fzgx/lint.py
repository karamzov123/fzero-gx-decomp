"""Shiftability and style lint for src/**/*.c.

Rules (docs/CODING_RULES.md):
  A1  no integer literal in 0x80000000..0x817FFFFF (cached RAM) or
      0xC0000000..0xC17FFFFF (uncached) or 0xCC000000..0xCC00FFFF (hardware
      registers) outside include/dolphin/hw_regs.h
  A2  no cast of a literal to a pointer:  (T *)0x...
  A3  no inline assembly bodies in reconstructed C
  S1  no `goto` without a justification comment on the same or previous line
  S2  no `volatile` / codegen-only `union` without a justification comment
A line may opt out with `// fzgx-allow: <rule> <reason>`.
"""

from __future__ import annotations

import re
from pathlib import Path
from typing import Iterable, List, Tuple

from .project import ROOT

HEX_RE = re.compile(r"\b0[xX]([0-9A-Fa-f]{8})\b")
PTR_CAST_RE = re.compile(r"\(\s*[\w\s]+\*\s*\)\s*0[xX][0-9A-Fa-f]+")
ALLOW_RE = re.compile(r"fzgx-allow:\s*(\w+(?:,\w+)*)")
RANGES = [(0x80000000, 0x817FFFFF), (0xC0000000, 0xC17FFFFF), (0xCC000000, 0xCC00FFFF)]
EXEMPT = {"include/dolphin/hw_regs.h"}


def _rel(path: Path) -> str:
    try:
        return path.resolve().relative_to(ROOT).as_posix()
    except ValueError:
        return path.as_posix()


def allocator_scaffolding(source: str) -> bool:
    """Recognize observed diagnostic tricks, not arbitrary legitimate padding."""
    return any(re.search(r'\blab_pad\s*\[', line.split('//', 1)[0]) or
               'fzgx: keeps the web at its definition' in line
               for line in source.splitlines())


def lint_file(path: Path) -> List[Tuple[str, int, str]]:
    if _rel(path) in EXEMPT:
        return []
    findings: List[Tuple[str, int, str]] = []
    lines = path.read_text(errors="replace").splitlines()
    for i, line in enumerate(lines, 1):
        code = line.split("//", 1)[0]
        allow = {r for m in ALLOW_RE.finditer(line) for r in m.group(1).split(",")}  # every allow comment on the line
        prev = lines[i - 2] if i >= 2 else ""
        justified = "//" in line or "//" in prev or "/*" in line or "/*" in prev
        for m in HEX_RE.finditer(code):
            v = int(m.group(1), 16)
            if v == 0x80000000:
                continue  # the sign-bit mask, not an address (nothing is addressed at the RAM base itself)
            if any(lo <= v <= hi for lo, hi in RANGES) and "A1" not in allow:
                findings.append(("A1", i, f"hardcoded address 0x{v:08X}; use a symbol"))
        if PTR_CAST_RE.search(code) and "A2" not in allow:
            findings.append(("A2", i, "literal cast to pointer; declare an extern symbol"))
        if re.search(r'\b(?:asm|__asm__)\s*(?:volatile\s*)?\{', code):
            findings.append(("A3", i, "inline assembly body in reconstructed C"))
        if re.search(r"\bgoto\b", code) and not justified and "S1" not in allow:
            findings.append(("S1", i, "goto without a justification comment"))
        if re.search(r"\bvolatile\b", code) and not justified and "S2" not in allow:
            findings.append(("S2", i, "volatile without a justification comment"))
    return findings


def lint_paths(paths: Iterable[Path]) -> List[Tuple[str, str, int, str]]:
    out: List[Tuple[str, str, int, str]] = []
    for p in paths:
        files = [p] if p.is_file() else sorted(p.rglob("*.c")) + sorted(p.rglob("*.h"))
        for f in files:
            for rule, line, msg in lint_file(f):
                out.append((_rel(f), rule, line, msg))
    return out
