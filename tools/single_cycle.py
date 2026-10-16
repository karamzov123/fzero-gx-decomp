import json, re, subprocess, sys
from pathlib import Path

ROOT = '/home/armandofm/projects/fzgx'

def fx(*a, timeout=200):
    return subprocess.run([sys.executable, 'tools/fzgx.py', '--json', *a],
                          cwd=ROOT, text=True, capture_output=True, timeout=timeout)

def hermes(prompt, model='upstage/solar-pro4:free', timeout=300):
    cp = subprocess.run(['hermes', 'chat', '--oneshot', '-q', prompt,
                         '--model', model], cwd='/home/armandofm',
                        text=True, capture_output=True, timeout=timeout)
    return (cp.stdout or ''), {'rc': cp.returncode}

def extract_c(text):
    m = re.search(r'```(?:c)?\s*\n(.*?)```', text, re.S)
    return (m.group(1).strip() if m else text.strip())

def main():
    symbol = 'fn_3_149AC'
    model = 'upstage/solar-pro4:free'
    agent = 'single-cycle'

    # 1) engine context command: match task, module, scope, hints, initial diff (no attempt consumed)
    r = fx('context', symbol)
    ctx = r.stdout
    print('--- context ---')
    print(ctx[:1500])

    # 2) model turn via hermes (keyless free tier)
    prompt = (f'Write the COMPLETE C source for the fzgx function `{symbol}` '
              f'(module customize, ~528 bytes). Return the C code ONLY: no markdown '
              f'fences, no prose, no explanations.')
    out, meta = hermes(prompt, model)
    print('--- hermes ---')
    print('rc', meta['rc'], 'len', len(out))
    code = extract_c(out)
    print('CODE_LEN', len(code))
    print('CODE[:120]', code[:120].replace('\n', ' '))
    Path(f'{ROOT}/.fzgx/work/{symbol}.c').write_text(code + '\n')

    # 3) engine check (the oracle the fleet uses; returns % and outcome)
    r2 = fx('check', symbol, '--agent', agent, '--max-checks', '4')
    print('--- check ---')
    print(r2.stdout[:2000])
    try:
        j2 = json.loads(r2.stdout)
        print('CHECK ok:', j2.get('ok'), '| outcome:', j2.get('outcome'),
              '| percent:', j2.get('percent'), '| checks:', j2.get('checks'))
    except Exception:
        print('CHECK raw:', r2.stdout[:300])

    # 4) release (keep the best candidate)
    r3 = fx('release', symbol, '--agent', agent, '--reason', 'single-cycle-free-model-test')
    print('--- release ---')
    print(r3.stdout[:400])

if __name__ == '__main__':
    main()
