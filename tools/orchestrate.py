#!/usr/bin/env python3
"""Headless matching batches: shared Codex app server, bounded local tool workers.

    uv run tools/orchestrate.py --provider deepseek --parallel 128 --seeds MANIFEST

Codex sessions share one app-server process. The runner assigns functions,
serves bound dynamic tools, enforces attempt limits, and stops completed turns.
Local compiler concurrency is independent of the number of model sessions.
Claude's legacy CLI transport remains available with --harness claude.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import signal
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from fleet_provider import ProcessDrainError
from datetime import datetime, timezone
from pathlib import Path
from typing import Dict, List, Optional

from fzgx import api, oracle, reuse, trivial
from fzgx.ledger import Ledger
from fzgx.project import ROOT, STATE_DIR, Project

MATCHER_TOOLS = ["Read", "mcp__fzgx__write_unit", "mcp__fzgx__patch_unit", "mcp__fzgx__check", "mcp__fzgx__read_evidence", "mcp__fzgx__release"]
# Explicit fleet policy. No silent cheaper-model or lower-effort fallback.
BOUND_HARNESS = ("cline", "agy", "opencode", "hermes")
EXPECTED_MODEL = {"claude": "claude-opus-5-5", "codex": "gpt-6.1-sol", "cline": "stealth/space-bunny-alpha", "agy": "gemini-3.8-flash-high", "opencode": "opencode/space-bunny-free", "hermes": "stepfun/step-5-preview:free"}
CLAUDE_MODELS = {"haiku": "claude-haiku-4-5", "sonnet": "claude-sonnet-5", "opus": "claude-opus-5-5"}
# $/M tokens from platform.openai.com/docs/pricing (2026-09-08): input, cached input, cache write, output.
# Codex reports usage but no cost; Claude Code reports total_cost_usd itself.
CODEX_PRICES = {"gpt-5.6-luna": (0.20, 0.02, 0.25, 1.20), "gpt-5.6-terra": (2.00, 0.20, 2.50, 12.00),
                "gpt-5.6-sol": (4.00, 0.40, 5.00, 20.00), "gpt-6-astra": (10.00, 1.00, 12.50, 50.00)}
# DeepSeek peak rates; weekday UTC 01-04 and 06-10, otherwise half price.
# https://api-docs.deepseek.com/quick_start/pricing/ (2026-09-10)
DEEPSEEK_PRICES = {"deepseek-flash": (0.30, 0.006, 0.0, 1.20)}
FAST_MULTIPLIER = 2.0  # "Fast mode" (formerly priority processing) is 2x standard on every line
CODEX_INSTRUCTIONS = ROOT / "tools" / "codex_matcher.md"  # replaces Codex's 17.7k-char default persona prompt
CODEX_REVISE_INSTRUCTIONS = ROOT / "tools" / "codex_revise.md"
CODEX_DISABLE = ["plugins", "recommended_plugins", "plugin_sharing", "remote_plugin", "apps", "browser_use",
                 "browser_use_external", "in_app_browser", "computer_use", "skill_search", "skill_mcp_dependency_install",
                 "multi_agent", "multi_agent_v2", "goals", "hooks", "memories",
                 "shell_snapshot", "shell_snapshot_v2"]


def _pct(value) -> str:
    return "-" if value is None else f"{value:.5g}"


def _num(value) -> str:
    return "-" if value is None else str(value)


def _refusal(out: str) -> Optional[str]:
    """'rate-limited' when the harness output shows the provider refused the request.

    A quota or rate refusal exits rc=1 like any other harness failure, so every one of
    them was recorded as a crash: 58 of 127 crashes in one day were refusals, including
    every claude attempt (its weekly limit, `rateLimitType: seven_day`). That hid the
    real cause in batch reports and in any crash-rate measurement. The refusal text is
    only inspected here, when no tool already produced a terminal outcome.
    """
    try:
        from fleet import provider_error_text  # scoped: fleet imports this module
    except Exception:
        return None
    try:
        errors = provider_error_text(out or "")
    except Exception:
        return None
    if not errors:
        return None
    blob = str(errors).lower()  # provider_error_text returns joined text, not a list
    if any(word in blob for word in ("rate_limit", "rate limit", "quota", "credit", "billing",
                                     "usage limit", "overage", "429", "too many requests")):
        return "rate-limited"
    return None


def select(p: Project, spec: str) -> List[str]:
    """module:min:max:count — untouched, uncarved functions spread across sizes."""
    module, lo, hi, n = spec.split(":")
    rows = [r for r in api.inventory(p, module=module, status="unmatched")
            if r["attempts"] == 0 and not r["unit"] and int(lo) <= r["size"] <= int(hi)]
    rows.sort(key=lambda r: (r["size"], r["symbol"]))
    step = max(1, len(rows) // int(n))
    return [r["symbol"] for r in rows[::step][: int(n)]]


def select_tu(p: Project, module: str, tu_files: List[str], max_size: int = 0, revise: bool = False,
              retry: int = 0) -> List[str]:
    """Every unmatched, unattempted function of the given TUs (whole-file matching); with
    retry=N also those with fewer than N attempts; with revise=True every matched one instead."""
    import json as _json
    d = _json.loads((p.module_config_dir(module) / "tus.json").read_text())
    want = {t["file"]: t["functions"] for t in d["tus"] if t["file"] in tu_files}
    inv = {r["symbol"]: r for r in api.inventory(p, module=module, status="matched" if revise else "unmatched")}
    units = {u["symbols"][0] for u in p.load_units() if u["module"] == module}
    out = []
    for f in tu_files:
        for fn in want.get(f, []):
            r = inv.get(fn)
            if not r or (max_size and r["size"] > max_size):
                continue
            if (fn in units) if revise else (r["attempts"] == 0 or 0 < r["attempts"] < retry):
                out.append(fn)
    return out


def claude_cmd(symbol: str, agent_id: str, model: str) -> List[str]:
    prompt = f"SYMBOL={symbol}  AGENT_ID={agent_id}. Match this function following your loop."
    return ["claude", "-p", prompt, "--agent", "matcher", "--model", model,
            "--output-format", "json", "--no-session-persistence",
            "--mcp-config", ".mcp.json", "--strict-mcp-config", "--disable-slash-commands",
            "--allowedTools", ",".join(MATCHER_TOOLS)]


def codex_server_cmd(model: str, provider: str, effort: Optional[str], fast: bool = False) -> List[str]:
    """Process-local overrides only; never change personal Codex config/auth."""
    overrides = {
        'model': model, 'model_provider': provider, 'approval_policy': 'never',
        'sandbox_mode': 'read-only', 'skills.include_instructions': False,
        'notify': [],  # Legacy turn-end notification commands are separate from hooks.
        'project_doc_max_bytes': 0, 'web_search': 'disabled',
        'tools.web_search': False, 'model_reasoning_summary': 'none',
        'tools.experimental_request_user_input.enabled': False,
        'features.apply_patch_freeform': False,
        'orchestrator.skills.enabled': False,
        'include_environment_context': False, 'include_apps_instructions': False,
        'include_collaboration_mode_instructions': False, 'thread_unload_delay_secs': 0,
    }
    for feature in CODEX_DISABLE + ['shell_tool', 'unified_exec', 'view_image']:
        overrides['features.' + feature] = False
    if effort:
        overrides['model_reasoning_effort'] = effort
    if fast:
        overrides['service_tier'] = 'fast'
    if provider == 'deepseek':
        overrides.update({
            'model_providers.deepseek.name': 'DeepSeek',
            'model_providers.deepseek.base_url': 'https://api.deepseek.com',
            'model_providers.deepseek.wire_api': 'responses',
            'model_providers.deepseek.env_key': 'DEEPSEEK_API_KEY',
            'model_providers.deepseek.requires_openai_auth': False,
            'model_catalog_json': str(ROOT / 'tools/codex_models.json'),
        })
    command = ['codex', 'app-server']
    for key, value in overrides.items():
        command += ['-c', key + '=' + json.dumps(value)]
    return command


def parse_claude(out: str) -> Dict:
    result = None
    model = ''
    for line in out.splitlines():
        try:
            row = json.loads(line)
        except ValueError:
            continue
        if not isinstance(row, dict):
            continue
        if isinstance(row.get('model'), str):
            model = row['model']
        if row.get('type') == 'result' or 'modelUsage' in row:
            result = row
    if result is None:
        return {'text': out, 'cost': 0.0, 'turns': None, 'tokens_in': 0, 'tokens_out': 0, 'model': model}
    u = result.get('usage') or {}
    return {'text': result.get('result', ''), 'cost': result.get('total_cost_usd', 0.0) or 0.0,
            'turns': result.get('num_turns', result.get('turns')),
            'tokens_in': (u.get('input_tokens', u.get('inputTokens', 0)) + u.get('cache_read_input_tokens', 0)
                          + u.get('cache_creation_input_tokens', 0)),
            'tokens_out': u.get('output_tokens', u.get('outputTokens', 0)),
            'model': next(iter(result.get('modelUsage') or {model: None}), model)}


def deepseek_rate_multiplier(timestamp: Optional[str]) -> float:
    if not timestamp:
        return 1.0  # missing timestamps cannot establish eligibility for the discount
    when = datetime.fromisoformat(timestamp.replace("Z", "+00:00")).astimezone(timezone.utc)
    peak = when.weekday() < 5 and (1 <= when.hour < 4 or 6 <= when.hour < 10)
    return 1.0 if peak else 0.5


def price_usage(model: str, samples: List, provider: str, fast: bool = False) -> Dict:
    prices = DEEPSEEK_PRICES if provider == 'deepseek' else CODEX_PRICES
    pi, pc, pw, po = prices.get(model, (0.0, 0.0, 0.0, 0.0))
    cost = 0.0
    for timestamp, usage in samples:
        multiplier = deepseek_rate_multiplier(timestamp) if provider == 'deepseek' else (FAST_MULTIPLIER if fast else 1.0)
        cost += ((usage.get('input_tokens', 0) - usage.get('cached_input_tokens', 0)) * pi
                 + usage.get('cached_input_tokens', 0) * pc + usage.get('cache_write_input_tokens', 0) * pw
                 + usage.get('output_tokens', 0) * po) / 1e6 * multiplier
    return dict(cost=round(cost, 6), tokens_in=sum(u.get('input_tokens', 0) for _, u in samples),
                tokens_out=sum(u.get('output_tokens', 0) for _, u in samples),
                cost_basis=('DeepSeek peak/off-peak estimate by UTC usage event timestamp' if provider == 'deepseek'
                            else 'OpenAI fast-rate estimate' if fast else 'OpenAI standard-rate estimate'))


def run_one(p: Project, harness: str, model: str, symbol: str, idx: int, timeout: int, batch: str,
            shadow: bool = False, fast: bool = False, revise: bool = False, provider: str = "openai") -> Dict:
    prefix = "revise-" if revise else ("shadow-" if shadow else "")
    agent_id = f"{prefix}{batch}-{harness}-{idx}"
    if harness == "claude" and revise:
        raise SystemExit("--revise is implemented for the codex harness only")
    t0 = time.time()
    directory = STATE_DIR / 'runs' / batch
    directory.mkdir(parents=True, exist_ok=True)
    result_file = directory / f'{symbol}.terminal.json'
    if result_file.exists():
        raise ValueError(f'{result_file}: worker already completed; use a new batch name')
    env = {**os.environ, 'CLAUDE_CODE_DISABLE_TERMINAL_TITLE': '1', 'FZGX_AGENT_ID': agent_id,
           'FZGX_SYMBOL': symbol, 'FZGX_HARNESS': harness, 'FZGX_MODEL': model,
           'FZGX_RESULT_FILE': str(result_file)}
    # Tool-progress watchdog is owned by fleet_provider; retain an explicit
    # operator override but do not silently stretch Hermes silence to 900 seconds.

    def worker_cli(*args, timeout_s=900):
        cp = subprocess.run([sys.executable, str(ROOT / 'tools/fzgx.py'), '--json', *args],
                            cwd=ROOT, env=env, text=True, capture_output=True, timeout=timeout_s)
        try:
            return json.loads(cp.stdout)
        except ValueError:
            raise RuntimeError((cp.stderr or cp.stdout or 'worker CLI returned no result')[-2000:])

    out, rc, proc, setup_secs = '', 0, None, 0.0
    bound = os.environ.get('FZGX_BOUND_TRANSPORT') == '1' or harness in BOUND_HARNESS
    try:
        # Bound fleet retries first run the deterministic search on the best saved body;
        # a match ends the assignment here, before any model request.
        assignment = worker_cli('claim', symbol, '--agent', agent_id,
                                *([] if revise else ['--check']),
                                *(['--repair'] if bound and not revise and not shadow else []), timeout_s=max(timeout, 1200))
        if not assignment.get('ok'):
            raise RuntimeError('assignment failed: ' + json.dumps(assignment))
        seed = assignment.get('seed') or {}
        if assignment.get('initial_check'):
            seed['instruction'] = 'Your work copy contains this C. Continue from initial_check with patch_unit.'
        elif revise:
            assignment['source'] = p.work_path(api._key(p, symbol)).read_text()
        (directory / f'{symbol}.assignment.json').write_text(json.dumps(assignment, indent=2) + '\n')
        setup_secs = round(time.time() - t0, 3)
        if not result_file.exists():
            task = {'context': assignment['context']}
            if seed:
                task['seed'] = {k: seed[k] for k in ('source', 'kind', 'instruction', 'prior_attempt') if k in seed}
            if assignment.get('source'):
                task['source'] = assignment['source']
            if assignment.get('initial_check'):
                task['initial_check'] = assignment['initial_check']
            # An unseeded claim installs a stub: a check before the first write only
            # reports the function missing and spends a check and a stale slot.
            start = ('installed its work copy. Continue from the supplied C and initial diff.'
                     if task.get('initial_check') or task.get('source') or task.get('seed') else
                     'installed an empty stub as its work copy; there is no initial diff. Your first call must be '
                     'write_unit with a complete unit, built from the best prior attempt or mechanical draft in the '
                     'context when present. A check or read_evidence before that write returns nothing and spends '
                     'one of your limited checks.')
            prompt = (f'SYMBOL={symbol} AGENT_ID={agent_id} MODEL={model}. The runner has already assigned '
                      f'this function and {start}\n'
                      + json.dumps(task))
            (directory / f'{symbol}.prompt.txt').write_text(prompt + '\n')
            if bound:
                from fleet_provider import run as run_provider
                out, rc = run_provider(harness, prompt, model, directory, env, timeout)
            else:
                cmd = claude_cmd(symbol, agent_id, model)
                cmd[cmd.index('-p') + 1] = prompt
                proc = subprocess.Popen(cmd, cwd=ROOT, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                        stdin=subprocess.DEVNULL, start_new_session=True, env=env)
                while True:
                    remaining = timeout - (time.time() - t0)
                    if remaining <= 0:
                        raise subprocess.TimeoutExpired(cmd, timeout)
                    try:
                        so, se = proc.communicate(timeout=min(0.25, remaining))
                        out, rc = (so or '') + '\n' + (se or ''), proc.returncode
                        break
                    except subprocess.TimeoutExpired:
                        if result_file.exists():
                            try:
                                os.killpg(proc.pid, signal.SIGTERM)
                            except ProcessLookupError:
                                pass
                            try:
                                so, se = proc.communicate(timeout=5)
                            except subprocess.TimeoutExpired:
                                os.killpg(proc.pid, signal.SIGKILL)
                                so, se = proc.communicate()
                            out, rc = (so or '') + '\n' + (se or ''), proc.returncode
                            break
        else:
            out = 'Completed during deterministic preflight; no model request.\n'
    except ProcessDrainError:
        # A surviving bound tool still owns its work copy. Never enter cleanup.
        raise
    except subprocess.TimeoutExpired:
        if proc:
            try:
                os.killpg(proc.pid, signal.SIGKILL)
            except ProcessLookupError:
                pass
            so, se = proc.communicate()
            out = (so or '') + '\n' + (se or '')
        rc = -9
    except Exception as error:
        if proc and proc.poll() is None:
            try:
                os.killpg(proc.pid, signal.SIGKILL)
            except ProcessLookupError:
                pass
            so, se = proc.communicate()
            out += (so or '') + '\n' + (se or '')
        out += '\nHarness error: ' + str(error)
        rc = 1
    info = parse_claude(out)
    usage_file = result_file.with_name(f'{symbol}.usage.json')
    if usage_file.exists():
        usage = json.loads(usage_file.read_text())
        info['tokens_in'], info['tokens_out'] = usage.get('inputTokens', 0), usage.get('outputTokens', 0)
        # Prefer the provider's own cost when it reports one. Every CLI harness
        # previously landed cost_usd=0 because the rate tables have no entry for
        # these models, which made cline look free and broke cost-per-match
        # comparisons (docs/findings/276). inputTokens is cache-inclusive, so the
        # cache split is carried alongside it and never added on top.
        info['cache_read_tokens'] = usage.get('cacheReadTokens', 0) or 0
        info['cache_write_tokens'] = usage.get('cacheWriteTokens', 0) or 0
        if usage.get('totalCost'):
            info['cost'] = usage['totalCost']
            info['cost_basis'] = 'provider-reported'
        elif harness == 'cline':
            # This provider reports no cost and no public rate exists, so a dollar
            # figure would be invented. Record the cache split and compare attempts
            # in effective tokens instead (docs/findings/276).
            info['cost'] = 0.0
            info['cost_basis'] = ('unpriced: no provider rate for stealth/space-bunny-alpha; '
                                  'use effective tokens (input - 0.9*cacheRead) to compare')
    key = api._key(p, symbol)
    l = Ledger()
    att = l.db.execute("SELECT * FROM attempts WHERE symbol=? AND agent=? ORDER BY id DESC LIMIT 1",
                       (key, agent_id)).fetchone()
    terminal = att and att["outcome"] in ("matched", "matched-pool", "released", "shadow-matched", "shadow-released")
    guard_path = result_file.with_name(f'{symbol}.guard.json')
    guard = json.loads(guard_path.read_text()) if bound and guard_path.exists() else {}
    # Tool outcomes and counters are authoritative; models sometimes misformat or miscount RESULT.
    outcome = att["outcome"].removeprefix("shadow-") if terminal else (
        "timeout" if rc == -9 or guard.get('reason') in ('tool-idle', 'deadline')
        # A clean exit (rc=0) that never called fzgx_check produced zero compiler evidence.
        # It is not "incomplete" (which reads as work-in-progress on a real body): the model
        # edited nothing the oracle ever saw, so nothing moved. Recording it distinctly keeps
        # it out of the productive-attempt rate and makes the no-tool pattern measurable
        # instead of hiding inside "incomplete" next to sessions that DID compile.
        else "no-tool" if rc == 0 and not (att["checks"] if att else 0) else "incomplete" if rc == 0
        else _refusal(out) or "crash")
    if outcome == "matched-pool":
        outcome = "matched"
    row = l.get(key)
    if not terminal and row and row["status"] == "claimed" and row["claimed_by"] == agent_id:
        try:
            # The release-time search can take minutes; on a supervisor stop save without it.
            stopping = False
            if bound:
                from fleet_provider import STOP
                stopping = STOP.is_set() or bool(guard)
            worker_cli('release', symbol, '--agent', agent_id,
                       '--reason', f'harness {outcome} (rc={rc}); saved best candidate automatically',
                       *(['--save-only'] if stopping else []), timeout_s=1200)
            att = l.db.execute('SELECT * FROM attempts WHERE symbol=? AND agent=? ORDER BY id DESC LIMIT 1',
                               (key, agent_id)).fetchone()
            if att and att['ended']:
                outcome = 'matched' if att['outcome'] in ('matched', 'matched-pool', 'shadow-matched') else outcome + '+released'
        except Exception as error:
            out += '\nAutomatic cleanup failed: ' + str(error)
    # AGY, opencode and hermes report no model string: AGY's transport masks it,
    # opencode's model is pinned by the session-local agent config rather than
    # self-reported, and hermes' stream events name the model only on the init event.
    # All are excluded so a future field cannot cause a false WRONG-MODEL abort.
    if harness not in ('agy', 'opencode', 'hermes') and info["model"] and not info["model"].startswith(EXPECTED_MODEL[harness]):
        outcome = f"WRONG-MODEL({info['model']})"
    pct = 100.0 if outcome == "matched" else (att["best_in_attempt"] if att else None)
    checks = att["checks"] if att else None
    # cost accounting onto the attempt this agent opened
    l.db.execute("UPDATE attempts SET tokens_in=?, tokens_out=?, cost_usd=?, harness=?, model=COALESCE(NULLIF(?, ''), model), "
                 "cache_read_tokens=?, cache_write_tokens=? "
                 "WHERE id=(SELECT id FROM attempts WHERE symbol=? AND agent=? ORDER BY id DESC LIMIT 1)",
                 (info["tokens_in"], info["tokens_out"], info["cost"], harness, info["model"],
                  info.get("cache_read_tokens", 0), info.get("cache_write_tokens", 0), key, agent_id))
    log = STATE_DIR / "runs" / batch / f"{symbol}.log"
    log.parent.mkdir(parents=True, exist_ok=True)
    log.write_text(out)
    return {"symbol": symbol, "outcome": outcome, "percent": pct, "checks": checks, "cost": info["cost"], "model": info["model"],
            "cost_basis": info.get("cost_basis", "provider-reported"),
            "cache_read_tokens": info.get("cache_read_tokens", 0),
            "cache_write_tokens": info.get("cache_write_tokens", 0),
            "tokens_in": info["tokens_in"], "tokens_out": info["tokens_out"], "turns": info["turns"],
            "secs": round(time.time() - t0, 1), "setup_secs": setup_secs, "model_started": proc is not None, "rc": rc}


def fan_out(p: Project, a, model: str, symbols: List[str], batch: str, revise: bool) -> tuple:
    if a.shadow or not a.verify_interval:
        return _fan_out(p, a, model, symbols, batch, revise)
    directory = STATE_DIR / 'runs' / batch
    directory.mkdir(parents=True, exist_ok=True)
    stop = directory / 'verify.stop'
    if stop.exists():
        raise ValueError(f'{batch}: batch already finished; use a new batch name')
    with (directory / 'verify.jsonl').open('a') as output, (directory / 'verify.stderr.log').open('a') as errors:
        watcher = subprocess.Popen([
            sys.executable, str(ROOT / 'tools/fzgx.py'), '--json', 'verify', '--watch',
            '--interval', str(a.verify_interval), '--until-pid', str(os.getpid()), '--stop-file', str(stop),
            '--message', f'Live matches from {batch}'], cwd=ROOT, stdout=output, stderr=errors)
        try:
            return _fan_out(p, a, model, symbols, batch, revise)
        finally:
            stop.touch()
            # Allow an active transaction to finish; never terminate a linker
            # or verifier halfway through updating source ownership.
            if watcher.wait():
                error = dict(timestamp=time.time(), ok=False, verified=[], rejected=[],
                             error=f'live verifier exited {watcher.returncode}; see verify.stderr.log')
                output.write(json.dumps(error) + '\n')
                output.flush()
                print(error['error'], file=sys.stderr, flush=True)


def _fan_out(p: Project, a, model: str, symbols: List[str], batch: str, revise: bool) -> tuple:
    """Run one agent per symbol, `a.parallel` at a time, within `a.budget_usd`."""
    if a.harness == 'codex':
        import asyncio
        from codex_server import fan_out as server_fan_out
        return asyncio.run(server_fan_out(p, a, model, symbols, batch, revise,
                           codex_server_cmd(model, a.provider, a.effort, a.fast), price_usage))
    results: List[Dict] = []
    spent = 0.0
    bound = os.environ.get('FZGX_BOUND_TRANSPORT') == '1' or a.harness in BOUND_HARNESS
    if bound:
        from fleet_provider import STOP
        signal.signal(signal.SIGTERM, lambda *_: STOP.set())
        signal.signal(signal.SIGINT, lambda *_: STOP.set())
    with ThreadPoolExecutor(max_workers=a.parallel) as ex:
        futs = {}
        queue = list(enumerate(symbols, 1))
        while queue or futs:
            if bound and STOP.is_set():
                queue.clear()
            while queue and len(futs) < a.parallel and (a.budget_usd is None or spent < a.budget_usd):
                i, s = queue.pop(0)
                futs[ex.submit(run_one, p, a.harness, model, s, i, a.timeout, batch, a.shadow, a.fast, revise, a.provider)] = s
            if not futs:
                break
            done = next(as_completed(list(futs)))
            futs.pop(done)
            r = done.result()
            results.append(r)
            spent += r["cost"] or 0.0
            if r["outcome"].startswith("WRONG-MODEL"):
                print(f"ABORT: {r['symbol']} ran on {r['outcome']}; expected {EXPECTED_MODEL[a.harness]}", flush=True)
                queue.clear()
            elif bound and r['outcome'].startswith(('crash', 'timeout', 'rate-limited')):
                # Stop queued launches until the supervisor applies backoff.
                queue.clear()
            print(f"  {r['outcome']:16s} {r['symbol']:14s} {'' if r['percent'] is None else f'{r['percent']:.1f}%':7s} "
                  f"checks={r['checks'] if r['checks'] is not None else '-'} turns={r['turns'] or '-'} "
                  f"${r['cost']:.3f} {r['secs']}s", flush=True)
    return results, spent


def finish_round(p: Project, a, model: str, module: str) -> Dict:
    """The TU-finish pass, a revise round on its queue, the pass again. No hands."""
    from fzgx import finish  # scoped: only when --finish is used
    # The same batched deterministic engine used by release and the fixup CLI.
    sw = api.fixup(p, module, 60.0, 2000)
    print(f"fixup {module}: {len(sw['matches'])} matched from {sw['functions']} functions, "
          f"{sw['compiled']} compiles, {sw['cached']} cache hits", flush=True)
    from fzgx.ledger import Ledger  # scoped: same
    out = {"passes": [], "revise": None}
    r = finish.finish(p, module)
    out["passes"].append({k: r[k] for k in ("ok", "tus", "hoisted", "renamed", "contested", "collapsed", "queue")})
    print(f"tu-finish {module}: ok={r['ok']} hoisted={r['hoisted']} renamed={r['renamed']} contested={r['contested']} "
          f"collapsed={r['collapsed']} unresolved={len(r['queue'])} ({r.get('secs')}s)", flush=True)
    queue = r["queue"]
    if queue and a.harness == "codex":
        l = Ledger()  # blocks released twice by revise agents are the librarian's, not the loop's
        capped = {row[0] for row in l.db.execute("SELECT symbol FROM attempts WHERE agent LIKE 'revise-%' AND outcome='released' "
                                                  "GROUP BY symbol HAVING COUNT(*) >= 2")}
        todo = [s for s in queue if s not in capped]
        print(f"revise round: {len(todo)} blocks ({len(queue) - len(todo)} at the revise cap)", flush=True)
        if todo:
            results, spent = fan_out(p, a, model, todo, f"{a.batch}-revise", True)
            api.verify_links(p, f"batch {a.batch}: revise round link-verified")
            out["revise"] = {"n": len(results), "kept": sum(1 for x in results if x["outcome"] == "matched"), "cost_usd": round(spent, 3)}
            print(f"revise round: {out['revise']['kept']}/{len(results)} kept, ${spent:.2f}", flush=True)
            r = finish.finish(p, module)
            out["passes"].append({k: r[k] for k in ("ok", "tus", "hoisted", "renamed", "contested", "collapsed", "queue")})
            print(f"tu-finish {module}: ok={r['ok']} collapsed={r['collapsed']} unresolved={len(r['queue'])}", flush=True)
    return out


def checkpoint_batch(p, batch, matched_count, harness, model, *, shadow=False, interrupted=False, total_count=0):
    # SQLite/attempt bodies are authoritative. A presentation snapshot must not
    # prolong shutdown, and shadow admission promises not to commit project state.
    if shadow or interrupted:
        return dict(snapshot_deferred=True, snapshot_reason='shadow' if shadow else 'interrupted')
    with oracle.build_lock('submit.lock', timeout_s=1800):
        oracle.clear_stale_index_lock()
        api.snapshot(p)
        subprocess.run(["git", "add", str(ROOT / "state" / "ledger.json")], cwd=ROOT, capture_output=True, check=True)
        subprocess.run(["git", "commit", '--only', "-q", "-m", f"batch {batch}: {matched_count}/{total_count} matched ({harness}/{model})",
                        '--', str(ROOT / 'state/ledger.json')], cwd=ROOT, capture_output=True, check=True)
    return dict(snapshot_deferred=False)


def main(argv: Optional[List[str]] = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--harness", choices=["claude", "codex", "cline", "agy", "opencode", "hermes"], default="codex")
    ap.add_argument("--provider", choices=["openai", "deepseek"], default="openai", help="codex model provider")
    ap.add_argument("--api-key-file", type=Path, help="DeepSeek key file; otherwise use DEEPSEEK_API_KEY")
    ap.add_argument("--model", help="explicit provider model; defaults: Opus 5.5 / GPT 6.1-Sol / Space Bunny Alpha / Gemini 3.8 High")
    ap.add_argument("--parallel", type=int, default=48)
    ap.add_argument("--tool-parallel", type=int, default=min(16, os.cpu_count() or 4),
                    help="maximum simultaneous local tool processes, independent of model sessions")
    ap.add_argument("--timeout", type=int, default=900, help="seconds per agent")
    ap.add_argument('--verify-interval', type=float, default=60,
                    help='seconds between live verification passes; 0 keeps end-only verification')
    ap.add_argument('--seeds', type=Path, help='JSON manifest of saved C, compiler options and scores; selects its functions by default')
    ap.add_argument('--max-checks', type=int, help='checks allowed per worker attempt')
    ap.add_argument('--max-stale', type=int, help='consecutive non-improving checks allowed per worker')
    ap.add_argument('--max-attempts', type=int, help='claim attempt cap for this batch')
    ap.add_argument("--symbols", nargs="*", default=[])
    ap.add_argument("--select", help="module:min_size:max_size:count, e.g. main_rel:8:96:48")
    ap.add_argument("--select-tu", nargs="*", help="whole-file batches: TU names from tus.json, e.g. camera.c coli.c")
    ap.add_argument("--module", default="main_rel", help="module for --select-tu")
    ap.add_argument("--max-size", type=int, default=0, help="size cap for --select-tu")
    ap.add_argument("--retry", type=int, default=0, help="--select-tu: also functions with fewer than N attempts")
    ap.add_argument("--budget-usd", type=float, help="stop launching new agents past spend; token-priced providers are estimates")
    ap.add_argument("--batch", default=time.strftime("b%Y%m%d-%H%M"))
    ap.add_argument("--no-trivial", action="store_true", help="skip the mechanical blr/li pass first")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--fast", action="store_true", help="codex: service_tier=fast (2x price, faster generation)")
    ap.add_argument("--effort", choices=["none", "minimal", "low", "medium", "high", "xhigh", "max", "ultra"], help="model reasoning effort; hermes accepts ultra")
    ap.add_argument("--shadow", action="store_true",
                    help="A/B trial: run on already-matched functions without relinking or committing")
    ap.add_argument("--finish", action="store_true", help="after the batch: TU-finish pass, revise round on its queue, pass again")
    ap.add_argument("--finish-only", action="store_true", help="no matching batch: just the TU-finish round for --module")
    ap.add_argument("--revise", action="store_true",
                    help="rewrite already-matched functions for readability; kept only if still 100%%")
    a = ap.parse_args(argv)
    if a.parallel < 1 or a.tool_parallel < 1 or a.timeout < 1:
        ap.error('parallel, tool-parallel and timeout must be positive')
    # Each compile attempt costs two inodes, so a batch launched on a full
    # filesystem dies with ENOSPC instead of matching anything. Collect the
    # session scratch first rather than failing 48 agents into the same wall.
    if not a.dry_run:
        from fzgx import fixup_gc
        free = os.statvfs(STATE_DIR).f_favail
        if free < 100_000:
            print(f"pre-flight: {free:,} free inodes; collecting fixup scratch", flush=True)
            if fixup_gc.main([]) != 0 or os.statvfs(STATE_DIR).f_favail < 10_000:
                ap.error(f'only {os.statvfs(STATE_DIR).f_favail:,} free inodes on {STATE_DIR}; refusing to start')
    if a.verify_interval < 0:
        ap.error('--verify-interval must be nonnegative')
    if len(a.symbols) != len(set(a.symbols)):
        ap.error('duplicate symbols are not allowed')
    if a.provider == "deepseek":
        if a.harness != "codex":
            ap.error("--provider deepseek requires --harness codex")
        if a.fast:
            ap.error("DeepSeek does not support Codex's OpenAI --fast service tier")
        if a.effort and a.effort not in ("none", "low", "high", "max"):
            ap.error("DeepSeek supports --effort none, low, high, or max")
        if a.model and a.model not in DEEPSEEK_PRICES:
            ap.error("use --model deepseek-flash for DeepSeek-V4.1-Flash")
        a.model = a.model or "deepseek-flash"
        a.effort = a.effort or "high"
        if a.api_key_file:
            try:
                os.environ["DEEPSEEK_API_KEY"] = a.api_key_file.expanduser().read_text().strip()
            except OSError as error:
                ap.error(f"cannot read --api-key-file: {error}")
        if not a.dry_run and not os.environ.get("DEEPSEEK_API_KEY"):
            ap.error("set DEEPSEEK_API_KEY or pass --api-key-file")
    elif a.api_key_file:
        ap.error("--api-key-file requires --provider deepseek")
    if a.harness == "claude":
        a.provider = "anthropic"
    for option, name in ((a.max_checks, 'FZGX_MAX_CHECKS'), (a.max_stale, 'FZGX_MAX_STALE'),
                         (a.max_attempts, 'FZGX_MAX_ATTEMPTS')):
        if option is not None:
            if option < 1:
                ap.error(name + ' must be positive')
            os.environ[name] = str(option)
    os.environ['FZGX_CLAIM_TTL'] = str(max(api.DEFAULT_TTL, a.timeout + 300))
    if a.seeds:
        os.environ['FZGX_SEEDS'] = str(a.seeds.resolve())
    model = a.model or EXPECTED_MODEL[a.harness]
    a.effort = a.effort or ('medium' if a.harness == 'codex' else 'high')
    os.environ['FZGX_EFFORT'] = a.effort
    if a.harness == "claude":
        EXPECTED_MODEL["claude"] = CLAUDE_MODELS.get(model, model)  # the guard checks the tier that was asked for
    elif a.model:
        EXPECTED_MODEL[a.harness] = a.model
    p = Project()

    if a.finish_only:
        fr = finish_round(p, a, model, a.module)
        print(json.dumps(fr, indent=1))
        return 0 if all(x["ok"] for x in fr["passes"]) else 1
    symbols = list(a.symbols)
    if a.seeds and not symbols:
        symbols = list(json.loads(a.seeds.read_text()))
    if a.select:
        symbols += select(p, a.select)
    if a.select_tu:
        symbols += select_tu(p, a.module, a.select_tu, a.max_size, a.revise, a.retry)
    symbols = list(dict.fromkeys(symbols))
    if not symbols:
        print("nothing selected", file=sys.stderr)
        return 2
    print(f"batch {a.batch}: {len(symbols)} functions, harness={a.harness} provider={a.provider} model={model} parallel={a.parallel} tool_parallel={a.tool_parallel}")
    if a.dry_run:
        print(" ".join(symbols))
        return 0
    if not a.no_trivial and not a.shadow and not a.revise:
        triv = trivial.apply(p)
        reused = reuse.run(p, max_size=a.max_size or 255, module=a.module)
        from fzgx import lift  # scoped: the lifter needs the build tree, not the harness
        lifted = lift.apply(p, [a.module] if a.module else None, a.max_size or 400)
        # reuse.run defers to fixup's clone pass, which reports its landings as `matches`.
        reuse_n = len(reused.get('matches') or reused.get('matched') or [])
        print(f"trivial pass: {triv.get('applied', 0)} matched mechanically; reuse: {reuse_n}; "
              f"lifter: {lifted.get('submitted', 0)} submitted of {lifted.get('lifted', 0)} lifted", flush=True)
        ledger = Ledger()
        symbols = [s for s in symbols if (row := ledger.get(api._key(p, s))) is not None and row['status'] == 'unmatched']
    # nothing is carved up front: a unit exists only once a function matches (submit carves it)

    t0 = time.time()
    results, spent = fan_out(p, a, model, symbols, a.batch, a.revise)
    ver = {"ok": True, "verified": [], "rejected": []}
    live = []
    if not a.shadow:
        ver = api.verify_links(p, f"batch {a.batch}: link-verified matches")
        live_log = STATE_DIR / 'runs' / a.batch / 'verify.jsonl'
        if live_log.exists():
            live = [json.loads(line) for line in live_log.read_text().splitlines() if line.strip()]
            ver['verified'] = sorted(set(ver.get('verified', []) + [s for r in live for s in r.get('verified', [])]))
            ver['rejected'] = sorted(set(ver.get('rejected', []) + [s for r in live for s in r.get('rejected', [])]))
            # The final drain retries any pending work after a watcher failure;
            # its result determines current health, not an earlier transient error.
        print(f"verify: {len(ver.get('verified', []))} verified, {len(ver.get('rejected', []))} rejected"
              + (f" ({ver.get('error')})" if ver.get("error") else ""), flush=True)
        for r in results:
            if r["outcome"] == "matched" and r["symbol"] in ver.get("rejected", []):
                r["outcome"] = "link-mismatch"
    finish_result = None
    if a.finish and not a.shadow:
        finish_result = finish_round(p, a, model, a.module)
    matched = [r for r in results if r["outcome"] == "matched"]
    released = [r for r in results if r["outcome"].startswith("released")]
    interrupted = [r for r in results if r['outcome'].startswith('interrupted')]
    other = [r for r in results if r not in matched and r not in released and r not in interrupted]
    models = sorted({r.get("model") for r in results if r.get("model")})
    summary = {"batch": a.batch, "harness": a.harness, "model": model + (" (fast)" if a.fast else ""), "models_seen": models, "n": len(results), "matched": len(matched),
               "provider": a.provider, "transport": "app-server" if a.harness == "codex" else "cli",
               "parallel": a.parallel, "tool_parallel": a.tool_parallel, "cost_basis": "; ".join(sorted({r["cost_basis"] for r in results})),
               "verify_interval": a.verify_interval, "live_verifications": len(live),
               "live_verify_errors": sum(not r.get('ok') for r in live),
               "stream_retries": sum(r.get('stream_retries', 0) for r in results),
               "retried_sessions": sum(bool(r.get('stream_retries')) for r in results),
               "link_rejected": len(ver.get("rejected", [])),
               "released": len(released), "interrupted": len(interrupted), "unstarted": len(symbols) - len(results),
               "failed": len(other), "cost_usd": round(spent, 3),
               "wall_s": round(time.time() - t0, 1), "finish": finish_result, "results": results}
    # only the codex app-server reports a turn count; the CLIs cap turns but never report
    # what they used, so name that in the report instead of leaving the column empty
    summary["turns_reported"] = sum(1 for r in results if r.get("turns") is not None)
    summary["turns_note"] = (f"reported for {summary['turns_reported']}/{len(results)} sessions"
                             if summary["turns_reported"] else
                             f"not reported by the {a.harness} harness (capped at 40 per session)")
    # report + snapshot
    rep = STATE_DIR / "reports" / f"{a.batch}{'-shadow' if a.shadow else ''}{'-revise' if a.revise else ''}{'-' + a.effort if a.effort else ''}.md"
    lines = [f"# Batch {a.batch}{' (shadow A/B trial)' if a.shadow else ''} — {a.harness}/{model}, {a.parallel} parallel",
             "", f"{len(results)} functions: {len(matched)} matched, {len(released)} released, "
             f"{len(interrupted)} interrupted, {len(symbols) - len(results)} unstarted, {len(other)} failed; "
             f"${spent:.2f}; {summary['wall_s']} s wall.", "",
             f"Provider: {a.provider}. Cost basis: {summary['cost_basis']}.",
             f"Turns: {summary['turns_note']}.", "",
             "| Function | Outcome | % | Checks | Turns | $ | s |",
             "|---|---|---|---|---|---|---|"]
    for r in sorted(results, key=lambda r: r["symbol"]):
        # every cell gets an explicit placeholder: an empty cell reads as a rendering
        # glitch rather than as "not reported", which is what a blank column looks like
        lines.append(f"| {r['symbol']} | {r['outcome']} | {_pct(r['percent'])} | "
                     f"{_num(r['checks'])} | {_num(r['turns'])} | {r['cost']:.3f} | {r['secs']} |")
    rep.parent.mkdir(parents=True, exist_ok=True)
    rep.write_text("\n".join(lines) + "\n")
    # Normal reporting checkpoints retain their original serialized path.
    summary.update(checkpoint_batch(p, a.batch, len(matched), a.harness, model,
                                    shadow=a.shadow, interrupted=bool(interrupted), total_count=len(results)))
    print(json.dumps({k: v for k, v in summary.items() if k != "results"}))
    return 0 if ver.get("ok") and not other else 1


if __name__ == "__main__":
    sys.exit(main())
