import json, re, subprocess, sys
from pathlib import Path

ROOT = '/home/armandofm/projects/fzgx'

def fx(*a, timeout=250):
    return subprocess.run([sys.executable, 'tools/fzgx.py', '--json', *a],
                          cwd=ROOT, text=True, capture_output=True, timeout=timeout)

def hermes(prompt, model='upstage/solar-pro4:free', timeout=450):
    cp = subprocess.run(['hermes', 'chat', '--oneshot', '-q', prompt, '--model', model],
                        cwd='/home/armandofm', text=True, capture_output=True, timeout=timeout)
    return (cp.stdout or ''), {'rc': cp.returncode}

def main():
    symbol = 'fn_3_149AC'
    model = 'upstage/solar-pro4:free'

    # 1) claim
    r = fx('claim', symbol, '--agent', 'obs', '--max-attempts', '2')
    try:
        j = json.loads(r.stdout)
    except Exception:
        print('claim parse fail:', r.stdout[:300], r.stderr[:100]); sys.exit(0)
    ctx = j.get('context') or ''
    seed = j.get('seed') or {}
    print('CLAIM ok:', j.get('ok'), 'attempt:', j.get('attempt'), 'ctx_len:', len(ctx))
    print('seed kind:', seed.get('kind'), 'instruction:', seed.get('instruction'))
    print('seed source[:200]:', (seed.get('source') or '')[:200])

    # 2) hermes model turn
    prompt = (f'Write the COMPLETE C source for the fzgx function `{symbol}` '
              f'(module customize, 528 bytes). Return ONLY valid C source. '
              f'No fences, no prose.')
    out, meta = hermes(prompt, model)
    m = re.search(r'```(?:c)?\s*\n(.*?)```', out, re.S)
    code = m.group(1).strip() if m else out.strip()
    Path(f'{ROOT}/.fzgx/work/{symbol}.c').write_text(code + '\n')
    print('MODEL_OUTPUT_LEN', len(out), 'CODE_LEN', len(code))

    # 3) engine write_unit -> check
    r2 = fx('write_unit', symbol, '--agent', 'obs', '--source', code)
    print('--- write_unit ---', r2.stdout[:300].replace('\n', ' '))
    r3 = fx('check', symbol, '--agent', 'obs', '--max-checks', '4')
    print('--- check ---')
    print(r3.stdout[:3000])

    # 4) release
    r4 = fx('release', symbol, '--agent', 'obs', '--reason', 'obs-cycle')
    print('--- release ---', r4.stdout[:300].replace('\n', ' '))

if __name__ == '__main__':
    main()
