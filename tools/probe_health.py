#!/usr/bin/env python3
"""Probe fzgx free-model candidates through their real endpoints + his hermes.
Drives health checks, then marshals a full-batch run through fzgx/check for each candidate."""
import json, os, sys, time, urllib.request, subprocess, shutil
from pathlib import Path

ROOT = Path("/home/armandofm/projects/fzgx")
OUT = ROOT / ".fzgx" / "harness" / "results.json"

# 3 functions, representative: varied size, a mix of matched/non-matched
SYMBOLS = [
    "car_colchg:_prolog",      # matched, ~700B, boot code
    "fn_10_12C14",             # middle range
    "car_colchg:_epilog",      # matched, ~1.2KB
]

def health_check(label, model, provider, base_url, keyless=False):
    payload = {"model": model, "messages":[{"role":"user","content":"Reply with exactly PROBE_OK_7F3A."}],"max_tokens":16,"temperature":0}
    url = base_url
    headers = {"Content-Type":"application/json"}
    if keyless:
        headers["X-Keyless-Token"] = "opencode-free"
    req = urllib.request.Request(url, data=json.dumps(payload).encode(), headers=headers)
    try:
        with urllib.request.urlopen(req, timeout=30) as r:
            j = json.loads(r.read())
            return {"ok":True,"status":r.status,"model":j.get("model")}
    except Exception as e:
        return {"ok":False,"error":str(e)[:120]}

def fzgx_check(symbol, model, provider, base_url, keyless, timeout_s=120):
    # one fzgx.py check round: claim then write stub then check
    env = {**os.environ,
           "FZGX_AGENT_ID": "probe-harness",
           "FZGX_SYMBOL": symbol,
           "FZGX_HARNESS": "codex",
           "FZGX_MODEL": model,
           "FZGX_RESULT_FILE": str(ROOT / ".fzgx" / "harness" / f"{symbol}.json")}
    cmd = [sys.executable, str(ROOT/"tools/fzgx.py"), "--json", "claim", symbol,
           "--agent", "probe-harness", "--check"]
    cp = subprocess.run(cmd, cwd=ROOT, env=env, text=True, capture_output=True, timeout=timeout_s)
    if cp.returncode != 0:
        return {"ok":False,"error":cp.stderr[-200:]}
    try:
        r = json.loads(cp.stdout)
    except ValueError:
        return {"ok":False,"error":"no json: "+cp.stdout[-200:]}
    if not r.get("ok"):
        return {"ok":False,"error":str(r.get("error"))}
    seed = r.get("seed") or {}
    path = ROOT / ".fzgx" / "work" / f"{r['symbol']}.c"
    # write small non-stub body for probing
    src = path.read_text()
    probe_body = src.replace("// " + r['symbol'] + "...", "// " + r['symbol'] + ": probe body")
    if len(probe_body) > 600:
        probe_body = probe_body[:600] + "\n// ...probe truncated"
    path.write_text(probe_body)
    # now check
    r2 = subprocess.run([sys.executable, str(ROOT/"tools/fzgx.py"), "--json", "check", symbol],
                        cwd=ROOT, env=env, text=True, capture_output=True, timeout=timeout_s)
    try:
        res = json.loads(r2.stdout)
    except ValueError:
        return {"ok":False,"error":"no json"}
    return {"ok":res.get("ok"),"percent":res.get("percent"),"checks":res.get("checks"),
            "error":(res.get("error") or "")[:100]}

def main():
    models = [
        # keyless free via openrouter (his opencode-free provider)
        ("muse-spark-1.2-contributor-free", "opencode-free", "https://openrouter.ai/api/v1/chat/completions", True),
        ("poolside/laguna-s-2.1:free", "openrouter", "https://openrouter.ai/api/v1/chat/completions", False),
        ("thinkingmachines/inkling:free", "openrouter", "https://openrouter.ai/api/v1/chat/completions", False),
        ("nvidia/nemotron-3.5-lightning:free", "openrouter", "https://openrouter.ai/api/v1/chat/completions", False),
        # keyless free via his inference API (nous portal)
        ("upstage/solar-pro4:free", "nous", "https://inference-api.nousresearch.com/v1/chat/completions", True),
    ]
    for label, provider, base_url, keyless in models:
        print(f"[health] {label}", file=sys.stderr)
        print(json.dumps(health_check(label, provider, base_url, keyless)), file=sys.stderr)

if __name__ == "__main__":
    main()
