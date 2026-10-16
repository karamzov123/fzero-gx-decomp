#!/usr/bin/env python3
"""Model decompilation test harness for fzfx.

Drives each free model the same way the fzgx fleet does:
  1. claim symbol  -- installs the fzfx work-copy stub / seed, returns context
  2. model-turn    -- the model rewrites the work copy via write_unit
  3. check         -- compile + objdiff against retail (the oracle)
  4. release       -- keep best candidate, record outcome

Runs the identical mechanics the fleet uses, so outcomes are comparable
across families (his keyless free tier, openrouter-free, fleet pins).
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
OUT_DIR = ROOT / ".fzgx" / "harness"
RESULTS = OUT_DIR / "results.json"


def log(msg):
    print(msg, file=sys.stderr, flush=True)


def run_fzfx(args, env_extra=None, timeout=900):
    """Run `fzfx.py --json <args...>` and return (parsed_json_or_dict, meta)."""
    env = {**os.environ}
    if env_extra:
        env.update(env_extra)
    cmd = [sys.executable, str(TOOLS / "fzgx.py"), "--json", *args]
    cp = subprocess.run(cmd, cwd=ROOT, env=env, text=True, capture_output=True, timeout=timeout)
    try:
        return json.loads(cp.stdout), {"rc": cp.returncode}
    except ValueError:
        return {"raw": cp.stdout, "stderr": cp.stderr, "rc": cp.returncode}, {"rc": cp.returncode}


def claim(symbol, agent, max_attempts=3):
    r, meta = run_fzfx(["claim", symbol, "--agent", agent, "--max-attempts",
                        str(max_attempts), "--check"])
    if "raw" in r or not r.get("ok"):
        return r, meta
    context = r.get("context", "")
    seed = r.get("seed") or {}
    return {
        "ok": True, "symbol": r["symbol"], "attempt": r["attempt"],
        "unit": r.get("unit"), "context_len": len(context),
        "source_len": len(r.get("source") or ""), "seed": seed,
        "context": context,
    }, meta


def write_unit(symbol, agent, source):
    r, meta = run_fzfx(["write_unit", symbol, "--agent", agent],
                       env_extra={"FZGX_SOURCE": source})
    return r, meta


def check(symbol, agent=None, max_checks=16):
    args = ["check", symbol, "--max-checks", str(max_checks)]
    if agent:
        args += ["--agent", agent]
    r, meta = run_fzfx(args)
    return r, meta


def release(symbol, agent, reason="test harness", save_only=False):
    args = ["release", symbol, "--agent", agent, "--reason", reason]
    if save_only:
        args.append("--save-only")
    r, meta = run_fzfx(args)
    return r, meta


def model_turn(model, prompt, timeout_s=600):
    cmd = ["hermes", "chat", "--oneshot", "-q", prompt, "--model", model]
    cp = subprocess.run(cmd, cwd="/home/armandofm", text=True,
                        capture_output=True, timeout=timeout_s)
    return (cp.stdout or "").strip(), {"rc": cp.returncode}


def extract_c(text):
    """Pull a single C code block out of model output (strips fences, explanations)."""
    lines = text.splitlines()
    out, in_block = [], False
    for ln in lines:
        if re.match(r"^```c\b", ln.strip()):
            in_block = True
            continue
        if in_block:
            if re.match(r"^```\s*$", ln.strip()):
                break
            out.append(ln)
    if out:
        return "\n".join(out)
    # fallback: grab the last balanced-brace region
    buf = []
    depth = 0
    started = False
    for ln in lines:
        d = ln.count("{") - ln.count("}")
        if not started and d > 0:
            started = True
            buf.append(ln)
            depth = d
            continue
        if started:
            buf.append(ln)
            depth += d
            if depth <= 0:
                return "\n".join(buf)
    return text[:1500]


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
    agent = f"mtest-{model.replace('/', '-').replace(':', '-')}"
    row = {"symbol": symbol, "model": model, "agent": agent,
           "started": time.time(), "attempts": 0, "checks": 0, "percent": 0.0,
           "cost": 0.0, "tokens_in": 0, "tokens_out": 0, "turns": 0, "outcome": "incomplete"}

    # 1. claim
    c, cmeta = claim(symbol, agent)
    if not c.get("ok"):
        row.update({"outcome": _label(c, cmeta), "result": c.get("raw") or c.get("error")})
        return row

    # 2. model turn
    prompt = c.get("context", "")
    if prompt:
        prompt += "\n\nYour task: write the COMPLETE C unit for this function. "
        prompt += "Output ONLY valid C source. No markdown fences, no prose, no explanations."
    try:
        out, mmeta = model_turn(model, prompt, timeout_s=600)
    except subprocess.TimeoutExpired:
        row["outcome"] = "timeout"
        return row
    except Exception as e:
        row["outcome"] = f"error:{e}"
        return row

    body = extract_c(out) if out else ""
    new_src = body if body else out
    w, wmeta = write_unit(symbol, agent, new_src)
    if "raw" in w or not w.get("ok"):
        row.update({"outcome": _label(w, wmeta), "result": w.get("raw") or w.get("error")})
        return row

    row["attempts"] = w.get("attempt", 1)
    if out:
        row["tokens_in"] = len(out)

    # 3. check
    ch, chmeta = check(symbol, agent)
    if "raw" in ch or not ch.get("ok"):
        row.update({"outcome": _label(ch, chmeta), "result": ch.get("raw") or ch.get("error")})
    else:
        row["checks"] = ch.get("checks", 0)
        row["percent"] = ch.get("percent", 0.0)
        row["outcome"] = ch.get("outcome", "incomplete")
        row["cost"] = ch.get("cost", 0.0)

    # 4. release
    rel, relmeta = release(symbol, agent, reason=f"mtest:{model}")
    if "raw" in rel or not rel.get("ok"):
        row["release_outcome"] = _label(rel, relmeta)

    row["finished"] = time.time()
    return row


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--models", nargs="+", required=True,
                    help="models; format 'family:model' (e.g. 'nous:upstage/solar-pro4:free') "
                         "or bare 'model' which uses the default provider")
    ap.add_argument("--symbols", nargs="+", default=[
        "car_colchg:_prolog",
        "fn_10_12C14",
        "car_colchg:_epilog",
    ])
    ap.add_argument("--parallel", type=int, default=1)
    ap.add_argument("--max-attempts", type=int, default=3)
    args = ap.parse_args()

    OUT_DIR.mkdir(parents=True, exist_ok=True)

    results = []
    for symbol in args.symbols:
        for mdef in args.models:
            if ":" in mdef:
                fam, model = mdef.split(":", 1)
            else:
                fam, model = "default", mdef
            for rep in range(1):
                rc = driver({"symbol": symbol, "model": model})
                results.append(rc)
                (OUT_DIR / f"{symbol}--{model}--rep{rep}.json").write_text(
                    json.dumps(rc, indent=2))
                log(f"  done {symbol} | {model} rep={rep}: outcome={rc['outcome']} pct={rc.get('percent',0)}")
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
            f"{dict(outcomes)}")


if __name__ == "__main__":
    main()
