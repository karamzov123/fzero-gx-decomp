"""Re-probe the recorded per-function optimisation levels against *current* bodies.

Current ranking uses an aligned, relocation-aware verdict in the unit's compiler
and extra-flag context. Positional word agreement can invert flag comparisons
when a prologue inserts a save-helper instruction. The historical positional
measurements below describe the earlier implementation, not the current metric.

`fzgx levelscan` (docs/LEVELSCAN.md) measured 269 functions whose saved body scores better
under a level other than the module default, and recorded the winning level in
`state/compiler_options.json`. `_compiler_options` already feeds that level to every check,
so the levels are not sitting unused -- but the measurement is a snapshot, and the fleet
rewrites bodies continuously. A level that was best for October's body can be wrong for
November's, and nothing in the tree notices.

So this reports the question the snapshot cannot: **for each recorded level, does the body
that exists right now actually score better at it?** Three outcomes per symbol:

  confirmed  the recorded level still wins against the current body
  stale      the current default now wins; the recorded level is wrong for this body
  gone       no body, or nothing compiles, so there is nothing to re-probe

Reports only. It never writes unit options and never reconfigures the build: applying a
level is `_set_unit_opts` plus `_reconfigure_and_split`, which mutates shared build state
and must not race the live fleet. Harvesting a confirmed level is `fzgx sweep --land`, and
submit already persists the level through the unit record (api.submit -> _set_unit_opts), so
a level-based match is link-stable rather than an object-only coincidence.

Read-only by construction: compiles into a temporary directory and touches nothing else.

**Measured result (2026-10-04), and a correction to the plan this came from.** All 269 recorded
levels were re-probed against the bodies that exist now:

    checked 269   confirmed 268   stale 1 (fn_4_B528, -O3 lost 2.7)   gone 0

So the levels are not stale and are being applied correctly -- `_compiler_options` already
feeds them to every check, and 268 of 269 still win against the current body. **But not one
of the 268 reaches a match.** The best is `fn_8003D42C` at 89.19% (from 7.89%), and the
whole confirmed set is under 90%.

The plan this answered predicted a cheap harvest here. That was wrong, and the reason is
worth recording so nobody re-runs it expecting matches:

- A better optimisation level moves a body *toward* a match; it is not one. The level was
  chosen because it maximises word agreement, and word agreement is not objdiff's verdict.
  These functions still need source work, which is the model's job.
- The ledger makes this look far better than it is. `fn_12_23410` reads `best_percent 100.0`,
  and its saved best body really is a preserved link-failure reconstruction (finding 272).
  Scored honestly it is 75.0% by objdiff and 22.1% by word score at its recorded `-O2`.
  Word score cannot see pool matches -- a body whose private literals retarget to shared
  retail symbols scores low on words and high on objdiff -- so the two figures are not
  interchangeable, and this tool reports the word figure by construction.

Conclusion recorded rather than acted on: the 269 recorded levels are correctly applied and
worth nothing as a match source. The real lever on this population is source repair, which is
`fzgx sweep` / `fzgx fixup` territory -- except that finding 282 then measured the repair
engine against the whole >=99% band and got 0 matches from 40,208 candidates, so this
population is source work for a model session and nothing cheaper. Keep this command as the
staleness check it genuinely is -- one stale level out of 269 -- and not as a harvest.
"""

from __future__ import annotations

import json
import tempfile
from pathlib import Path
from typing import Dict, List, Optional

from . import api, oracle
from .levelscan import LEVELS
from .project import ROOT

OPTIONS = ROOT / "state" / "compiler_options.json"


def recorded() -> Dict[str, str]:
    """symbol -> recorded winning level, from the levelscan snapshot."""
    if not OPTIONS.exists():
        return {}
    out: Dict[str, str] = {}
    try:
        data = json.loads(OPTIONS.read_text())
    except Exception:
        return {}
    for symbol, rec in data.items():
        flags = (rec or {}).get("flags") or []
        if flags:
            out[symbol] = flags[-1]
    return out


def _score(p, sym, words, body: str, flag: Optional[str]) -> Optional[float]:
    """Compile one body under one setting and score it, or None if it will not build."""
    unit = p.unit_of(sym)
    record = p.unit_record(unit) if unit else None
    record = record or {}
    # Compare against the unit's real build context, not an older module-only
    # measurement that silently discards its non-level options.
    extras = record.get('extra_cflags') or []
    base_flags = ' '.join(extras) if isinstance(extras, list) else extras
    flags = ' '.join(f for f in (base_flags, flag) if f) or None
    with tempfile.TemporaryDirectory() as td:
        src, obj = Path(td) / "b.c", Path(td) / "b.o"
        src.write_text(body)
        cp = oracle.compile_source(p, sym.module, src, obj, record.get('mw_version'), flags)
        if cp.returncode:
            return None
        result = oracle._diff(p, sym.module, sym.name, unit or '', 0,
                             target=p.target_object_for(sym), base=obj)
    # Positional words rank a single inserted save-helper instruction as a
    # whole-function mismatch. Use the aligned, binding-aware word verdict;
    # a raw fuzzy score is not a substitute when that verdict is unavailable.
    if not result.ok or result.percent_adjusted is None:
        return None
    return result.percent_adjusted


def recheck(p, symbols: Optional[List[str]] = None, module: Optional[str] = None,
            log=lambda *_: None) -> dict:
    """Compare each recorded level against the current body and the module default."""
    rec = recorded()
    if not rec:
        return {"ok": False, "error": "no recorded levels; run `fzgx levelscan` first"}
    todo = sorted(s for s in rec if not symbols or s in symbols)

    confirmed, stale, gone = [], [], []
    for i, symbol in enumerate(todo, 1):
        try:
            body = api._attempt_text(p, symbol)
            if not body:
                gone.append({"symbol": symbol, "why": "no saved body"})
                continue
            sym = p.resolve(symbol)
            if sym is None:
                gone.append({"symbol": symbol, "why": "unresolvable symbol"})
                continue
            if module and sym.module != module:
                continue
            words = oracle.words(Path(p.target_object_for(sym)), sym.name)
            if not words:
                gone.append({"symbol": symbol, "why": "no retail words"})
                continue
            base = _score(p, sym, words, body, None)
            if base is None:
                gone.append({"symbol": symbol, "why": "current body does not compile"})
                continue
            flag = rec[symbol]
            at_flag = _score(p, sym, words, body, flag)
            if at_flag is None:
                gone.append({"symbol": symbol, "why": f"{flag} does not compile"})
                continue
            row = {"symbol": symbol, "module": sym.module, "flag": flag,
                   "as_is": round(base, 3), "at_flag": round(at_flag, 3),
                   "gain": round(at_flag - base, 3), "size": sym.size}
            if at_flag > base + 1e-9:
                confirmed.append(row)
            else:
                stale.append(row)
            log("%-16s %-8s as_is %6.2f -> %6.2f" % (symbol, flag, base, at_flag))
        except Exception as e:                      # one bad symbol must not end the pass
            gone.append({"symbol": symbol, "why": repr(e)[:80]})
        if i % 10 == 0:
            log("... %d/%d" % (i, len(todo)))
    return {"ok": True, "checked": len(todo), "confirmed": confirmed,
            "stale": stale, "gone": gone}


def summary(result: dict) -> str:
    if not result.get("ok"):
        return "levelrecheck: %s" % result.get("error")
    c, s, g = result["confirmed"], result["stale"], result["gone"]
    out = ["levelrecheck checked=%d confirmed=%d stale=%d gone=%d"
           % (result["checked"], len(c), len(s), len(g))]
    for row in sorted(c, key=lambda r: -r["gain"])[:20]:
        out.append("  CONFIRMED %-16s %-4s %6.2f -> %6.2f (+%.2f)"
                   % (row["symbol"], row["flag"], row["as_is"], row["at_flag"], row["gain"]))
    return "\n".join(out)