#!/usr/bin/env python3
"""Model decompilation test harness for fzgx.

Drives each free model through the same mechanics as the fzgx fleet, on freshly
carved work that does not collide with fleet-held worker locks:

  2. context -- capture the module/scope/assembly hints the model receives
  3. model-turn -- hermes chat against the free tier replaces the unit's C
  4. check   -- compile + objdiff against retail (the oracle), returns %
  5. release -- keep the best candidate, record metadata

Targets all of his free model families with the exact identifiers from his
keyless free endpooints, and runs the identical oracle mechanics the fleet uses.
"""
import argparse
import json
import os
import re
import subprocess
import sys
import time
from collections import defaultdict
from pathlib import Path

ROOT = Path("/home/armandofm/projects/fzgx")
TOOLS = ROOT / "tools"
FRESH = ROOT / ".fzgx" / "harness"
RESULTS = FRESH / "results.json"

# family: keyless model identifier the free tier routes to
FREE_MODELS = {
    "nous:solar-pro4:free": "upstage/solar-pro4:free",
    "nous:poolside/laguna-s-2.1:free": "poolside/laguna-s-2.1:free",
    "nous:meituan/longcat-2.0:free": "meituan/longcat-2.0:free",
    "nous:poolside/laguna-xs-2.1:free": "poolside/laguna-xs-2.1:free",
    "opencode-free:muse-spark-1.2-contributor-free": "muse-spark-1.2-contributor-free",
    "opencode-free:nemotron-3.5-lightning-free": "nemotron-3.5-lightning-free",
    "openrouter:thinkingmachines/inkling:free": "thinkingmachines/inkling:free",
}

# fresh unclaimed, at most 1 prior attempt (so there's a seed body), non-trivial
DEFAULT_SYMBOLS = [
    "fn_3_1ADA4",
    "fn_3_1AEE4",
    "fn_3_1B008",
]


def log(msg):
    print(msg, file=sys.stderr, flush=True)


def fx(*args, timeout=180):
    return subprocess.run(
        [sys.executable, str(TOOLS / "fzgx.py"), "--json", *args],
        cwd=ROOT, text=True, capture_output=True, timeout=timeout)


def claim(symbol, agent, max_attempts=2):
    r = fx("claim", symbol, "--agent", agent,
           "--max-attempts", str(max_attempts), "--check")
    try:
        j = json.loads(r.stdout)
    except ValueError:
        return {"ok": False, "raw": r.stdout[:200], "stderr": r.stderr[:100]}, {"rc": r.returncode}
    ctx = j.get("context") or ""
    return {
        "ok": j.get("ok"),
        "symbol": j.get("symbol"),
        "attempt": j.get("attempt"),
        "context_len": len(ctx),
        "seed": j.get("seed") or {},
        "context": ctx,
    }, {"rc": r.returncode}


def carve(symbol, agent, max_attempts=2):
    r = fx("carve", symbol, "--agent", agent,
           "--max-attempts", str(max_attempts), "--check")
    try:
        j = json.loads(r.stdout)
    except ValueError:
        return {"ok": False, "raw": r.stdout[:200], "stderr": r.stderr[:100]}, {"rc": r.returncode}
    ctx = j.get("context") or ""
    return {
        "ok": j.get("ok"),
        "symbol": j.get("symbol"),
        "attempt": j.get("attempt"),
        "context_len": len(ctx),
        "seed": j.get("seed") or {},
        "context": ctx,
    }, {"rc": r.returncode}


def model_turn(model, prompt, timeout_s=300):
    cp = subprocess.run(
        ["hermes", "chat", "--oneshot", "-q", prompt, "--model", model],
        cwd="/home/armandofm", text=True, capture_output=True, timeout=timeout_s)
    return (cp.stdout or ""), {"rc": cp.returncode}


def extract_c(text):
    """Pull a single C code block out of model output (strips fences, explanations)."""
    m = re.search(r"```(?:c)?\s*\n(.*?)```", text, re.S)
    return (m.group(1).strip() if m else text.strip())


def check(symbol, agent, max_checks=4):
    r = fx("check", symbol, "--agent", agent, "--max-checks", str(max_checks))
    try:
        return json.loads(r.stdout), {"rc": r.returncode}
    except ValueError:
        return {"raw": r.stdout[:200], "stderr": r.stderr[:100]}, {"rc": r.returncode}


def release(symbol, agent, reason):
    r = fx("release", symbol, "--agent", agent, "--reason", reason)
    try:
        return json.loads(r.stdout), {"rc": r.returncode}
    except ValueError:
        return {"raw": r.stdout[:200]}, {"rc": r.returncode}


def _label(r, meta):
    if "raw" in r:
        return "crash"
    err = str(r.get("error") or "")
    if "failed" in err.lower() or "error" in err.lower():
        return "failed"
    return f"rc={meta.get('rc')}"


def driver(registry):
    symbol = registry["symbol"]
    model = registry["model"]
    agent = f"mth-{model.split(':')[0]}-{symbol.replace(':', '_')}"
    row = {"symbol": symbol, "model": model, "agent": agent,
           "started": time.time(), "attempts": 0, "checks": 0,
           "percent": 0.0, "cost": 0.0, "tokens_in": 0, "tokens_out": 0,
           "turns": 0, "outcome": "incomplete"}

    # 1 claim (verify engine mechanics with a fresh unclaimed symbol)
    c, cmeta = claim(symbol, agent)
    if not c.get("ok"):
        row.update({"outcome": _label(c, cmeta),
                    "result": c.get("raw") or c.get("stderr")})
        return row
    src = c.get("context") or ""

    # 2 model turn
    prompt = (
        f"Match the fzgx function `{symbol}` (module customize). The engine gave "
        f"these hints: {src[:600]}. Write the COMPLETE C source. Return C code "
        f"ONLY: no markdown fences, no prose, no explanations.")
    try:
        out, mmeta = model_turn(model, prompt)
    except subprocess.TimeoutExpired:
        row["outcome"] = "timeout"
        return row
    code = extract_c(out)
    if not code:
        row["outcome"] = "no-c"
        return row
    row["tokens_in"] = len(out)

    # 3 check oracle
    ch, chmeta = check(symbol, agent)
    if "raw" in ch or not ch.get("ok"):
        row.update({"outcome": _label(ch, chmeta),
                    "result": ch.get("raw") or ch.get("stderr")})
    else:
        row["checks"] = ch.get("checks", 0)
        row["percent"] = ch.get("percent", 0.0)
        row["outcome"] = ch.get("outcome", "incomplete")
        row["cost"] = ch.get("cost", 0.0)

    # 4 release keep best
    rel, relmeta = release(symbol, agent, f"mth:{model}")
    if "raw" in rel or not rel.get("ok"):
        row["release_outcome"] = _label(rel, relmeta)

    row["finished"] = time.time()
    return row


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--models", nargs="+", required=True,
                    help="family:model from FREE_MODELS")
    ap.add_argument("--symbols", nargs="*", default=DEFAULT_SYMBOLS)
    args = ap.parse_args()

    FRESH.mkdir(parents=True, exist_ok=True)
    results = []
    for symbol in args.symbols:
        for mk in args.models:
            model = FREE_MODELS.get(mk, mk)
            rc = driver({"symbol": symbol, "model": model})
            results.append(rc)
            fname = (symbol.replace(" ", "") + "--" + model).replace(":", "_").replace("/", "_") + ".json"
            (FRESH / fname).write_text(json.dumps(rc, indent=2))
            log(f"  done {symbol} | {model}: outcome={rc['outcome']} pct={rc.get('percent', 0)}")
            time.sleep(2)

    RESULTS.write_text(json.dumps(results, indent=2))
    log(f"\nWrote {len(results)} results to {RESULTS}")

    log("\n=== SUMMARY BY MODEL ===")
    by_model = defaultdict(list)
    for r in results:
        by_model[r["model"]].append(r)
    for m, rs in sorted(by_model.items()):
        pct = [r["percent"] for r in rs if r.get("percent", 0) > 0]
        outcomes = defaultdict(int)
        for r in rs:
            outcomes[r["outcome"]] += 1
        best = max(pct) if pct else 0.0
        log(f"{m:52s} n={len(rs)} best_pct={best:.1f}% mean={sum(pct)/len(pct) if pct else 0:.1f}% "
            f"matched={outcomes.get('matched', 0)} {dict(outcomes)}")


if __name__ == "__main__":
    main()
