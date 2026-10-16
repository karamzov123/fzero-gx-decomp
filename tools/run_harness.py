#!/usr/bin/env python3
"""Free-model decompilation harness: 3 difficult matched symbols x working free models."""
import json, subprocess, re, time, os
from pathlib import Path
from collections import defaultdict

ROOT = Path('/home/armandofm/projects/fzgx')
FX = [os.sys.executable, str(ROOT / 'tools' / 'fzgx.py'), '--json']
WORK = ROOT / '.fzgx' / 'work'
OUT = ROOT / '.fzgx' / 'harness'
OUT.mkdir(parents=True, exist_ok=True)

SYMBOLS = ['colchg_selmate_disp', 'colchg_chgcol_disp', 'fn_9_120C']
FREE_MODELS = {
    'nous/longcat-2.5-preview': 'meituan/longcat-2.5-preview:free',
    'nous/link-3.0-flash-sante': 'inclusionai/ling-3.0-flash-sante:free',
    'nous/laguna-s-2.1': 'poolside/laguna-s-2.1:free',
    'nous/solar-mini4': 'upstage/solar-mini4:free',
    'openrouter/nemtron-3-ultra-550b': 'nvidia/nemtron-3-ultra-550b-a55b:free',
}

results = []
for symbol in SYMBOLS:
    unit_path = WORK / f'{symbol}.c'
    backup = OUT / f'{symbol}.c.bak'
    backup.write_text(unit_path.read_text())

    for fkey, model in FREE_MODELS.items():
        safe = fkey.replace('/', '_')
        agent = f'{safe}-{symbol[:6]}'
        row = {'symbol': symbol, 'model': model, 'agent': agent,
               'started': time.time(), 'attempts': 0, 'checks': 0,
               'percent': 0.0, 'cost': 0.0, 'outcome': 'incomplete', 'error': ''}
        try:
            prompt = (f'Write the COMPLETE C source for the fzfx function `{symbol}` '
                      f'(module car_colchg). Return ONLY valid C source: '
                      f'no markdown fences, no prose, no explanations.')
            cp = subprocess.run(
                ['hermes', 'chat', '--oneshot', '-q', prompt, '--model', model],
                cwd='/home/armandofm', text=True, capture_output=True, timeout=450)
            out = (cp.stdout or '')
            code = re.search(r'```(?:c)?\s*\n(.*?)```', out, re.S)
            code = code.group(1).strip() if code else out.strip()
            if not code:
                row['outcome'] = 'no-c'
                results.append(row)
                print(f'  {symbol:14s} | {model:26s} | no-c')
            else:
                unit_path.write_text(code + '\n')
                row['model_output_len'] = len(code)
                r2 = subprocess.run(FX + ['check', symbol], cwd=ROOT,
                                    text=True, capture_output=True, timeout=250)
                try:
                    j2 = json.loads(r2.stdout)
                    row['checks'] = 1
                    row['percent'] = j2.get('percent', 0.0)
                    row['outcome'] = j2.get('outcome', 'incomplete')
                    if j2.get('error'): row['error'] = j2['error'][:200]
                except Exception:
                    row['outcome'] = 'check-crash'
                    row['error'] = r2.stdout[:300]
                results.append(row)
                print(f'  {symbol:14s} | {model:26s} | {row["outcome"]:16s} pct={row["percent"]}')
        except subprocess.TimeoutExpired:
            row['outcome'] = 'timeout'
            results.append(row)
            print(f'  {symbol:14s} | {model:26s} | timeout')
        except Exception as e:
            row['outcome'] = f'error:{e}'
            results.append(row)
            print(f'  {symbol:14s} | {model:26s} | error')
        row['finished'] = time.time()
        fname = f'{symbol}--{safe}.json'
        (OUT / fname).write_text(json.dumps(row, indent=2))
        unit_path.write_text(backup.read_text())
        time.sleep(2)

(OUT / 'results.json').write_text(json.dumps(results, indent=2))
print(f'\nWrote {len(results)} results')
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
    print(f'{m:28s} n={len(rs)} best={best:5.1f}% mean={mean:5.1f}% {dict(outs)}')
