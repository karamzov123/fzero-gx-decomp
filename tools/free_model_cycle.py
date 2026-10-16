import json, re, subprocess, sys
from pathlib import Path

ROOT = '/home/armandofm/projects/fzgx'

def fx(*a, timeout=250):
    return subprocess.run([sys.executable, 'tools/fzgx.py', '--json', *a],
                          cwd=ROOT, text=True, capture_output=True, timeout=timeout)

def hermes(prompt, model='upstage/solar-pro4:free', timeout=400):
    cp = subprocess.run(['hermes', 'chat', '--oneshot', '-q', prompt,
                         '--model', model], cwd='/home/armandofm',
                        text=True, capture_output=True, timeout=timeout)
    return (cp.stdout or ''), {'rc': cp.returncode}

def extract_c(text):
    m = re.search(r'```(?:c)?\s*\n(.*?)```', text, re.S)
    return (m.group(1).strip() if m else text.strip())

def main():
    symbol = 'fn_3_149AC'      # fresh 0-attempt unmatched symbol
    model = 'upstage/solar-pro4:free'
    agent = 'free-model-single'

    # 1) engine claim
    r = fx('claim', symbol, '--agent', agent, '--max-attempts', '2')
    try:
        j = json.loads(r.stdout)
    except Exception:
        print('claim parse fail:', r.stdout[:300], r.stderr[:100]); sys.exit(0)
    print('CLAIM ok:', j.get('ok'), 'attempt:', j.get('attempt'),
          'ctx_len:', len(j.get('context') or ''))

    # 2) model turn via his keyless free tier
    prompt = (f'Write the COMPLETE C source for the fzgx function `{symbol}` '
              f'(module customize, 528 bytes). Return only valid C source. '
              f'No fences, no prose.')
    out, meta = hermes(prompt, model)
    code = extract_c(out)
    print('MODEL_OUTPUT_LEN', len(out), 'CODE_LEN', len(code))
    if not code:
        print('--- raw model output ---')
        print(out[:2000])
    Path(f'{ROOT}/.fzgx/work/{symbol}.c').write_text(code + '\n')

    # 3) engine write_unit then check (the oracle the fleet uses)
    r2 = fx('write_unit', symbol, '--agent', agent, '--source', code)
    print('write_unit:', r2.stdout[:300].replace('\n', ' '))
    r3 = fx('check', symbol, '--agent', agent, '--max-checks', '4')
    try:
        j3 = json.loads(r3.stdout)
        print('CHECK ok:', j3.get('ok'), 'outcome:', j3.get('outcome'),
              'percent:', j3.get('percent'), 'checks:', j3.get('checks'))
        if j3.get('error'):
            print('CHECK error:', j3['error'][:400])
    except Exception:
        print('check parse fail:', r3.stdout[:300], r3.stderr[:200])

    # 4) release (keep best candidate)
    r4 = fx('release', symbol, '--agent', agent, '--reason', 'free-model-single-cycle')
    try:
        j4 = json.loads(r4.stdout)
        print('RELEASE ok:', j4.get('ok'), j4.get('error'))
    except Exception:
        print('release raw:', r4.stdout[:300], r4.stderr[:200])

if __name__ == '__main__':
    main()
