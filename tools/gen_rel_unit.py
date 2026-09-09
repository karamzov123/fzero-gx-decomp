#!/usr/bin/env python3
"""Convert a generated REL assembly aggregate into an asm-in-C unit.

The input is intentionally an aggregate section emitted by dtk.  Every
function block is copied in source order; this tool never selects a single
function or overwrites an existing output without an explicit --force.
"""
from __future__ import annotations

import argparse
import re
from pathlib import Path

FN_RE = re.compile(r"^\.fn\s+([^,\s]+)\s*,")
COMMENTED_INSN_RE = re.compile(r"^\s*/\*[^*]*\*/\s*(.*)$")
SYMBOL_RE = re.compile(r"\b(?:fn|lbl)_[A-Za-z0-9_]+\b")
GLOBAL_RE = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)@(?:ha|l)\b")
CALL_RE = re.compile(r"^\s*bl(?:a)?\s+([A-Za-z_][A-Za-z0-9_]*)\b")


def parse_functions(text: str) -> list[tuple[str, list[str]]]:
    """Return every .fn block, including linker prolog/epilog helpers."""
    result: list[tuple[str, list[str]]] = []
    current: tuple[str, list[str]] | None = None
    for raw in text.splitlines():
        match = FN_RE.match(raw.strip())
        if match:
            if current is not None:
                result.append(current)
            current = (match.group(1), [])
            continue
        if current is None:
            continue
        if raw.strip().startswith(".endfn"):
            continue
        instruction = COMMENTED_INSN_RE.match(raw)
        current[1].append(instruction.group(1) if instruction else raw)
    if current is not None:
        result.append(current)
    return result


def render(module: str, source: Path, functions: list[tuple[str, list[str]]]) -> str:
    names = {name for name, _ in functions}
    function_symbols = {
        match.group(1) for _, body in functions for line in body
        if (match := CALL_RE.match(line)) and not re.fullmatch(r"r\d+", match.group(1))
    }
    data_symbols = {
        symbol for _, body in functions for line in body
        for symbol in SYMBOL_RE.findall(line)
    }
    data_symbols.update(
        symbol for _, body in functions for line in body
        for symbol in GLOBAL_RE.findall(line)
    )
    data_symbols -= function_symbols | names
    symbols = function_symbols | data_symbols | names
    lines = [
        f"/* Generated from {source}; aggregate preserved in source order. */",
        f"/* Module: {module}. Do not edit; regenerate from the matching .s file. */",
        "#define qr0 0",
        "#define cr1eq 6",
        "",
    ]
    for symbol in sorted(symbols):
        kind = "void" if symbol in function_symbols or symbol in names else "unsigned char"
        suffix = "[]" if kind != "void" else "(void)"
        lines.append(f"extern {kind} {symbol}{suffix};")
    lines.append("")
    for name, body in functions:
        lines.append(f"asm void {name}(void)")
        lines.append("{")
        lines.append("    nofralloc")
        for line in body:
            stripped = line.strip()
            if not stripped or stripped.startswith("#"):
                continue
            stripped = stripped.replace(".L_", "L_")
            lines.append(f"    {stripped}")
        lines.append("}")
        lines.append("")
    return "\n".join(lines)


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("input", type=Path, help="dtk-generated aggregate .s file")
    parser.add_argument("output", type=Path, help="asm-in-C output path")
    parser.add_argument("--module", required=True, help="REL module name for the generated header")
    parser.add_argument("--force", action="store_true", help="replace an existing output")
    args = parser.parse_args()

    if not args.input.is_file():
        parser.error(f"input does not exist: {args.input}")
    if args.output.exists() and not args.force:
        parser.error(f"output exists (use --force to replace): {args.output}")
    functions = parse_functions(args.input.read_text())
    if not functions:
        parser.error(f"no .fn blocks found in {args.input}")
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(render(args.module, args.input, functions))
    print(f"wrote {len(functions)} functions to {args.output}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
