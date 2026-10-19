"""Exemplars of fixes: the (before, after) pairs of bodies where one check plateaued and the
next check matched, with the rows that changed. Mined from the per-check history that
`api.check` keeps (.fzgx/checks/<key>/NNN.c + index.jsonl). The context shows an agent the
nearest exemplars for its failure mode: the same kind of rows, and the edit that closed them.
"""

from __future__ import annotations

import difflib
import json
from pathlib import Path
from typing import Dict, List, Optional

from . import oracle, stuck
from .project import STATE_DIR, Project


def mine(p: Project, max_diff_lines: int = 40) -> List[Dict[str, object]]:
    out: List[Dict[str, object]] = []
    root = STATE_DIR / "checks"
    if not root.is_dir():
        return out
    for d in sorted(root.iterdir()):
        idx = d / "index.jsonl"
        if not idx.exists():
            continue
        recs = [json.loads(l) for l in idx.read_text().splitlines() if l.strip()]
        for prev, cur in zip(recs, recs[1:]):
            if cur.get("matched") and prev.get("ok") and not prev.get("matched") and (prev.get("percent") or 0) >= 60:
                a = (d / f"{prev['n']:03d}.c"); b = (d / f"{cur['n']:03d}.c")
                if not (a.exists() and b.exists()):
                    continue
                at, bt = a.read_text(), b.read_text()
                diff = [l for l in difflib.unified_diff(at.splitlines(), bt.splitlines(), lineterm="", n=1) if not l.startswith(("---", "+++"))]
                if not diff or len(diff) > max_diff_lines:
                    continue
                key = d.name.replace("__", ":")
                sym = p.resolve(key)
                mode, kinds = None, {}
                if sym is not None and (p.target_object_for(sym) or True):
                    # the failure mode of the plateaued body, from its object diff
                    try:
                        res = oracle.check(p, key, 0, source=a)
                        if res.ok:
                            lrows, rrows = res._rows
                            kinds = stuck.classify_rows(lrows, rrows); mode = stuck._pure(kinds, lrows, rrows)
                    except Exception:
                        pass
                out.append({"symbol": key, "from": prev.get("percent"), "mode": mode, "kinds": {k: v for k, v in kinds.items() if ":" not in k},
                            "diff": diff, "lines": len(diff)})
    (STATE_DIR / "exemplars.json").write_text(json.dumps(out, indent=1))
    return out


def nearest(mode: Optional[str], kinds: Dict[str, int], limit: int = 2) -> List[Dict[str, object]]:
    """Exemplars whose plateau looked like this one (same pure mode first, then shared kinds)."""
    path = STATE_DIR / "exemplars.json"
    if not path.exists():
        return []
    try:
        ex = json.loads(path.read_text())
    except ValueError:
        return []
    def score(e):
        s_ = 3 if mode and e.get("mode") == mode else 0
        s_ += len(set(kinds) & set(e.get("kinds") or {}))
        return (-s_, e.get("lines", 99))
    ranked = sorted((e for e in ex if e.get("diff")), key=score)
    return [e for e in ranked if score(e)[0] < 0][:limit]


def _instructions(lines):
    import re
    return [m[1].strip() for line in lines
            if (m := re.match(r'^[0-9a-fA-F]+:\s*(.+)', line))]


def _normal_pattern(instructions):
    """Normalize register allocation, retaining reuse, constants and operand order."""
    import re
    registers = {}
    def register(match):
        name = match[0]
        if name not in registers:
            registers[name] = name[0] + str(sum(k.startswith(name[0]) for k in registers))
        return registers[name]
    result = []
    for instruction in instructions:
        text = re.sub(r'\b(?:r|f|cr)\d+\b', register, instruction.lower())
        text = re.sub(r'(?<![\w])(-?0x[0-9a-f]+)(?!\w)', lambda m: str(int(m[0], 16)), text)
        result.append(re.sub(r'\s+', '', text))
    return tuple(result)


def witnesses(p: Project, symbol: str, pattern: Optional[str] = None,
              limit: int = 3, max_gap: int = 4) -> dict:
    """Find native, linked witnesses for a retail instruction/dataflow pattern.

    This is evidence retrieval, never a source-realizability proof or acceptance
    gate. The ledger/build establishes provenance; a new compiler check is still
    required before adopting a witness's source idea in another function.
    """
    import re
    import subprocess
    from .ledger import Ledger
    from . import tufile, progress
    sym = p.resolve(symbol)
    if sym is None:
        raise ValueError('unknown or ambiguous symbol; use module:name')
    if not 1 <= limit <= 20 or not 0 <= max_gap <= 8:
        raise ValueError('limit must be 1..20 and max_gap 0..8')
    fn = p.function_asm(sym.module).get(sym.name)
    if fn is None:
        raise ValueError('retail assembly unavailable')
    if pattern is None:
        # Selected cached diff is only a locator into immutable retail asm.
        try:
            from . import checkview
            cached = checkview.read(p, p.key(sym))
            differing = next(line for line in cached.get('diff', [])
                             if line[:1] in '~?!+-' and ' | ' in line)
            first = differing.split(' | ')[0]
            first = re.sub(r'^.*?\s{2,}', '', first).strip()
            ins = _instructions(fn.asm)
            at = ins.index(first)
            pattern = '; '.join(ins[at:at + 2])
        except (OSError, ValueError, StopIteration, KeyError):
            # No residual exists yet: require an explicit meaningful query.
            return dict(symbol=p.key(sym), pattern=None, results=[],
                        note='No current residual locator. Supply --pattern "instruction; instruction".')
    query = [x.strip() for x in pattern.split(';') if x.strip()]
    if not 1 <= len(query) <= 4:
        raise ValueError('pattern must contain 1..4 semicolon-separated instructions')
    wanted = _normal_pattern(query)
    opcodes = [x.split()[0] for x in query]
    ledger = Ledger()
    verified = {r['symbol']: dict(r) for r in ledger.db.execute(
        "SELECT * FROM functions WHERE status='matched' AND link_state='verified'")}
    # Never present a source edited since its accepted revision as verified C.
    dirty = set(subprocess.run(['git', 'diff', '--name-only', 'HEAD', '--', 'src'],
                              text=True, capture_output=True, check=True).stdout.splitlines())
    hits, scanned = [], 0
    for unit in p.load_units():
        if unit.get('status') != 'matching' or unit.get('data'):
            continue
        source = 'src/' + (unit.get('tu') or unit['source'])
        if source in dirty or not progress.gen_built(unit):
            continue
        for name in unit.get('symbols', []):
            other = p.find_symbol(name, unit['module'])
            if other is None or p.key(other) not in verified or p.key(other) == p.key(sym):
                continue
            function = p.function_asm(other.module).get(name)
            if not function:
                continue
            instructions = _instructions(function.asm)
            scanned += 1
            found = None
            # Bounded subsequence search preserves register relationships across
            # intervening instructions. Gap zero gives contiguous windows.
            def match_at(indices):
                nonlocal found
                if len(indices) == len(query):
                    chosen = [instructions[i] for i in indices]
                    if _normal_pattern(chosen) == wanted:
                        # A register relationship is not a witness if a gap
                        # overwrites its value or crosses unknown control flow.
                        for left, right in zip(indices, indices[1:]):
                            live = set(re.findall(r'\b(?:r|f|cr)\d+\b', instructions[left])) & set(
                                re.findall(r'\b(?:r|f|cr)\d+\b', instructions[right]))
                            for gap in instructions[left + 1:right]:
                                op = gap.split()[0]
                                if op.startswith('b') or op in ('mtctr', 'mtlr', 'lmw', 'lswi', 'lswx') or (
                                        op.startswith(('l', 'st')) and op.endswith(('u', 'ux'))):
                                    return
                                dest = re.match(r'\w+\s+((?:r|f|cr)\d+)\b', gap)
                                if dest and dest[1] in live and not op.startswith(('st', 'cmp', 'mt')):
                                    return
                        found = indices
                    return
                lo = indices[-1] + 1 if indices else 0
                hi = min(len(instructions), lo + max_gap + 1) if indices else len(instructions)
                for i in range(lo, hi):
                    if instructions[i].split()[0] == opcodes[len(indices)]:
                        match_at(indices + [i])
                        if found is not None:
                            return
            match_at([])
            if found is None:
                continue
            body = tufile.unit_text(p, dict(unit, symbols=[name]))
            if not body or re.search(r'\b(?:asm|__asm)\b', body):
                continue
            mw, flags = oracle.version_for(p, other)
            _, default_mw = oracle.module_flags(p, other.module)
            hits.append(dict(symbol=p.key(other), module=other.module, source=source,
                compiler=dict(mw=mw or default_mw, flags=flags),
                same_module=other.module == sym.module,
                same_flags=flags == oracle.version_for(p, sym)[1],
                same_compiler=(mw or default_mw) == (oracle.version_for(p, sym)[0] or oracle.module_flags(p, sym.module)[1]),
                address_distance=abs(other.addr - sym.addr) if other.module == sym.module else 1 << 32,
                instruction_indices=found, instructions=[instructions[i] for i in found],
                native_c=body[:5000], source_truncated=len(body) > 5000,
                verified_native=True, matched_commit=verified[p.key(other)].get('matched_commit'),
                proof='ledger link-verified, native built unit, source not locally edited; not a fresh compile'))
    hits.sort(key=lambda r: (not r['same_module'], not r['same_compiler'], not r['same_flags'], r['address_distance'], len(r['native_c']), r['symbol']))
    return dict(symbol=p.key(sym), pattern=pattern, scanned=scanned, total_hits=len(hits),
                results=hits[:limit], note='Compiler-profile witnesses are leads; recompile the adapted natural C.')
