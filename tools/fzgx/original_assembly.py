"""Reviewed original-assembly forms, independent of C/assembly file suffixes.

The registry pins individual assembly spans, not files. It is evidence metadata,
not authority to waive the compiler, relocation, ownership or retail-hash gates.
"""
from __future__ import annotations

import hashlib
import json
import re
from pathlib import Path

from .project import ROOT

REGISTRY = ROOT / 'config/original_assembly.json'
LEXICAL = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', re.S)
ASM = re.compile(r'\b(?:asm|__asm__)\b[^;{}]*\{')
FUNCTION = re.compile(r'\b([A-Za-z_]\w*)\s*\([^;{}]*\)\s*\{')


def masked(text: str) -> str:
    return LEXICAL.sub(lambda m: ''.join('\n' if c == '\n' else ' ' for c in m[0]), text)


def _end(code: str, opening: int) -> int:
    depth = 0
    for i in range(opening, len(code)):
        depth += (code[i] == '{') - (code[i] == '}')
        if depth == 0:
            return i + 1
    raise ValueError('unterminated assembly/function body')


def spans(text: str) -> list[dict]:
    code = masked(text)
    functions = [(m[1], m.start(), _end(code, m.end() - 1))
                 for m in FUNCTION.finditer(code)
                 if m[1] not in {'if', 'for', 'while', 'switch'}]
    out = []
    for m in ASM.finditer(code):
        end = _end(code, m.end() - 1)
        signature = FUNCTION.search(code, m.start(), m.end())
        if signature:
            symbol, form = signature[1], 'asm-function'
        else:
            enclosing = [(name, start) for name, start, stop in functions
                         if start < m.start() and end <= stop]
            symbol = min(enclosing, key=lambda item: item[1])[0] if enclosing else None
            form = 'inline-block'
        # Token boundaries matter; whitespace and comments do not change approval.
        tokens = re.findall(r'\w+|[^\s]', code[m.start():end])
        digest = hashlib.sha256('\0'.join(tokens).encode()).hexdigest()
        out.append(dict(symbol=symbol, form=form, start=m.start(), end=end,
                        line=text.count('\n', 0, m.start()) + 1, sha256=digest))
    return out


def registry() -> dict:
    return json.loads(REGISTRY.read_text()) if REGISTRY.exists() else {}


def source_form(source: str, symbol: str, standalone: bool = False) -> str:
    if standalone:
        return 'standalone-assembly'
    entries = registry().get('src/' + source, [])
    forms = {entry['form'] for entry in entries if entry['symbol'] == symbol}
    return 'original-assembly' if 'asm-function' in forms else 'mixed' if forms else 'c'


def findings(path: Path, text: str) -> list[tuple[str, int, str]]:
    try:
        relative = path.resolve().relative_to(ROOT).as_posix()
    except ValueError:
        relative = path.as_posix()
    entries = registry().get(relative, [])
    actual = spans(text)
    out = []
    used = set()
    for span in actual:
        key = (span['symbol'], span['form'], span['sha256'])
        matches = [i for i, entry in enumerate(entries)
                   if key == (entry['symbol'], entry['form'], entry['sha256'])]
        if len(matches) == 1 and matches[0] not in used:
            used.add(matches[0])
        else:
            out.append(('A3', span['line'], 'unreviewed or changed assembly body; see docs/ASM_POLICY.md'))
    for i, entry in enumerate(entries):
        if i not in used:
            out.append(('A3', 1, f"missing reviewed {entry['form']} for {entry['symbol']}"))
    return out
