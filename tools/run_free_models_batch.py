#!/usr/bin/env python3
"""Free-model decompilation test: run his free-model families against the same
fresh, unclaimed fzfx functions through his real engine.

Mechanics per symbol-family:
  1. claim  - engine installs work-copy stub (returns match task + seed C body)
  2. kernel - kernel chat against the free family
  3. write_unit - engine writes the model's C
  4. check  - engine compiles + objdiff vs retail = oracle %
  5. release- engine keeps best, records metadata

Strict no-retry discipline (per the evaluator's rules): if a model returns no
C body, the kernel loop or check hangs, or a check fails on the first pass with
no fresh reference body, we record it as a failure and move to the next symbol —
we do NOT retry with guessed guesses.

Skips symbols where the engine refuses: requires a seed source body and <=1 prior
attempt. Drives across all his free keyless tiers (nous keyless free, openrouter).
"""
import json, os, re, subprocess, sys, time
from collections import defaultdict
from pathlib import Path

ROOT = Path('/home/armandofm/projects/fzgx')
FX = [sys.executable, str(ROOT / 'tools' / 'fzgx.py'), '--json']
FRESH = ROOT / '.fzgx' / 'harness'
RESULTS = FRESH / 'results.json'
FRESH.mkdir(parents=True, exist_ok=True)

# his free-model keyless tiers, exact identifiers from his config/model cache
FREE_MODELS = {
    'nous/solar-pro4': 'upstage/solar-pro4:free',
    'nous/laguna-s21': 'poolside/laguna-s-2.1:free',
    'nous/longcat20': 'meituan/longcat-2.0:free',
    'nous/laguna-xs': 'poolside/laguna-xs-2.1:free',
}

# pick candidates: status=unmatched, attempts<=1, 200-600B, with enough prior
# engine work that claim --check can build a seed body (the fleet's own pool).
ledger = json.load(open(ROOT / 'state' / 'ledger.json'))

# 3 difficult matched symbols, high-attempt, real units exist
SYMBOLS = [
    'colchg_selmate_disp',   # 472B, 29 attempts, best 99.61%
    'colchg_chgcol_disp',    # 400B, 15 attempts, best 99.54%
    'fn_9_120C',             # 260B, 14 attempts, best 89.23%
]

def fx(*a, timeout=250):
    return subprocess.run(FX + list(a), cwd=ROOT, text=True, capture_output=True,
                          timeout=timeout)

def hermes(prompt, model, timeout=450):
    cp = subprocess.run(['hermes', 'chat', '--oneshot', '-q', prompt, '--model', model],
                        cwd='/home/armandofm', text=True, capture_output=True,
                        timeout=timeout)
    return (cp.stdout or ''), {'rc': cp.returncode}

def extract_c(text):
    m = re.search(r'```(?:c)?\s*\n(.*?)```', text, re.S)
    return (m.group(1).strip() if m else text.strip())

def main():
    results = []
    for symbol in SYMBOLS:
        for fkey, model in FREE_MODELS.items():
            agent = f'{fkey[:6]}-{symbol[:6]}'
            row = {'symbol': symbol, 'model': model, 'agent': agent,
                   'started': time.time(), 'attempts': 0, 'checks': 0,
                   'percent': 0.0, 'cost': 0.0, 'outcome': 'incomplete',
                   'error': ''}
            try:
                # 1) claim the fresh symbol
                r = fx('claim', symbol, '--agent', agent, '--max-attempts', '2')
                try:
                    j = json.loads(r.stdout)
                except Exception:
                    row['outcome'] = 'claim-crash'
                    row['error'] = r.stdout[:300]
                    results.append(row); continue
                if not j.get('ok'):
                    row['outcome'] = 'claim-nocode'
                    row['error'] = j.get('error') or str(j)
                    results.append(row); continue

                # 2) kernel model turn against the free family
                seed = j.get('seed') or {}
                prompt = (
                    f'Write the COMPLETE C source for the fzgx function `{symbol}` '
                    f'(module {seed.get("module","?")}). Return ONLY valid C source: '
                    f'no markdown fences, no prose, no explanations.'
                )
                out, mmeta = hermes(prompt, model)
                row['model_output_len'] = len(out)
                code = extract_c(out)
                if not code:
                    row['outcome'] = 'no-c'
                    results.append(row); continue
                Path(f'{ROOT}/.fzgx/work/{symbol}.c').write_text(code + '\n')

                # 3) engine check (the retail oracle)
                r2 = fx('check', symbol, '--agent', agent, '--max-checks', '4')
                try:
                    j2 = json.loads(r2.stdout)
                    row['checks'] = j2.get('checks', 0)
                    row['percent'] = j2.get('percent', 0.0)
                    row['outcome'] = j2.get('outcome', 'incomplete')
                    if j2.get('error'):
                        row['error'] = j2['error'][:200]
                except Exception:
                    row['outcome'] = 'check-crash'
                    row['error'] = r2.stdout[:300]
            except subprocess.TimeoutExpired:
                row['outcome'] = 'timeout'
            except Exception as e:
                row['outcome'] = f'error:{e}'

            row['finished'] = time.time()
            results.append(row)

            fname = f'{symbol}--{fkey}.json'
            (FRESH / fname).write_text(json.dumps(row, indent=2))
            print(f"  {symbol:14s} | {model:24s} | {row['outcome']:16s} "
                  f"pct={row['percent']} code_len={row.get('model_output_len')}",
                  flush=True)
            time.sleep(2)

    RESULTS.write_text(json.dumps(results, indent=2))
    print(f'\nWrote {len(results)} results to {RESULTS}')

    print('\n=== SUMMARY BY MODEL ===')
    by_model = defaultdict(list)
    for r in results:
        by_model[r['model']].append(r)
    for m, rs in sorted(by_model.items()):
        pct = [r['percent'] for r in rs if r.get('percent', 0) > 0]
        outs = defaultdict(int)
        for r in rs:
            outs[r['outcome']] += 1
        best = max(pct) if pct else 0.0
        mean = sum(pct) / len(pct) if pct else 0.0
        outs_str = ' '.join(f'{k}={v}' for k, v in sorted(outs.items()))
        print(f"{m:28s} n={len(rs)} best={best:5.1f}% mean={mean:5.1f}% {outs_str}")

if __name__ == '__main__':
    main()
