import json, re, subprocess, sys

ROOT = '/home/armandofm/projects/fzgx'
FX = ['python3', 'tools/fzgx.py', '--json']

def re_match(s, prefix):
    return s.startswith(prefix)

def run(*a, timeout=250):
    p = subprocess.run(FX + list(a), cwd=ROOT, text=True, capture_output=True, timeout=timeout)
    try:
        return json.loads(p.stdout), {'rc': p.returncode}
    except ValueError:
        return {'raw': p.stdout, 'stderr': p.stderr, 'rc': p.returncode}, {'rc': p.returncode}

def main():
    symbol = 'fn_3_149AC'
    model = 'upstage/solar-pro4:free'
    agent = 'free-probe-agent'

    # 1) claim the symbol
    j, m = run('claim', symbol, '--agent', agent, '--max-attempts', '2', '--check')
    print('CLAIM ok:', j.get('ok'), 'attempt:', j.get('attempt'), 'ctx_len:', len(j.get('context') or ''))
    ctx = j.get('context') or ''

    # 2) hermes model turn
    prompt = (f'Write the COMPLETE C source for fzgx function `{symbol}` '
              f'(module customize, 528 bytes). Return ONLY the C source: no '
              f'markdown fences, no prose, no explanations.')
    p = subprocess.run(['hermes', 'chat', '--oneshot', '-q', prompt, '--model', model],
                       cwd='/home/armandofm', text=True, capture_output=True, timeout=350)
    out = (p.stdout or '')
    print('hermes rc:', p.returncode, 'len:', len(out))

    # extract C
    lines = out.splitlines()
    code = []
    in_block = False
    for ln in lines:
        if re_match(ln.strip(), '```c'):
            in_block = True
            continue
        if in_block:
            if re.match(r'^```\s*$', ln.strip()):
                break
            code.append(ln)
    code = '\n'.join(code) if code else out.strip()
    print('CODE_LEN', len(code))

    # 3) engine write-unit (source must be in a file)
    src_path = f'{ROOT}/.fzgx/work/{symbol}.c'
    open(src_path, 'w').write(code + '\n')
    j2, m2 = run('write-unit', symbol, '--agent', agent, '--file', src_path)
    print('write-unit:', j2.get('ok'), j2.get('error'))
    print('write-unit_out:', j2.get('raw') or j2.get('stderr') or '')

    # 4) engine check (the oracle)
    j3, m3 = run('check', symbol, '--agent', agent, '--max-diff-lines', '40')
    print('CHECK raw:', j3.get('raw') or j3.get('stderr') or '')
    print('CHECK json:', json.dumps(j3, indent=1)[:2500])

    # 5) release
    j4, m4 = run('release', symbol, '--agent', agent, '--reason', 'free-model-s1')
    print('RELEASE:', j4.get('ok'), j4.get('error'))

if __name__ == '__main__':
    main()
