import json, subprocess, sys, time, re
from pathlib import Path
ROOT = '/home/armandofm/projects/fzgx'

def fx(*args, timeout=180):
    return subprocess.run([sys.executable, 'tools/fzgx.py', '--json', *args],
                          cwd=ROOT, text=True, capture_output=True, timeout=timeout)

def claim(symbol, agent):
    r = fx('claim', symbol, '--agent', agent, '--max-attempts', '2')
    j = json.loads(r.stdout)
    ctx = j.get('context') or ''
    ok = j.get('ok')
    return ok, ctx, j

def hermes(prompt, model='upstage/solar-pro4:free'):
    cp = subprocess.run(['hermes', 'chat', '--oneshot', '-q', prompt, '--model', model],
                        cwd='/home/armandofm', text=True, capture_output=True, timeout=300)
    return (cp.stdout or ''), {'rc': cp.returncode}

def extract_c(text):
    m = re.search(r'```(?:c)?\s*\n(.*?)```', text, re.S)
    return (m.group(1).strip() if m else text.strip())

def write_release_check(symbol, agent, code):
    fx('write_unit', symbol, '--agent', agent, '--source', code)
    time.sleep(3)
    r = fx('check', symbol, '--agent', agent, '--max-checks', '4')
    j = json.loads(r.stdout)
    r2 = fx('release', symbol, '--agent', agent, '--reason', 'fresh-e2e')
    return j, r2.stdout

SYM = 'colchg_selcar_init'
AGENT = 'fresh-probe'
ok, ctx, j = claim(SYM, AGENT)
print('CLAIM ok:', ok, 'attempt:', j.get('attempt'), 'context_len:', len(ctx))
print('ctx[:200]:', ctx[:200])
prompt = f"Write the COMPLETE C source for matched function `{SYM}` (module car_colchg). Return C code ONLY, no markdown fences, no prose."
out, meta = hermes(prompt)
code = extract_c(out)
print('hermes rc:', meta['rc'], 'code len:', len(code))
open(f'{ROOT}/.fzgx/work/{SYM}.c', 'w').write(code + '\n')
chk, rel = write_release_check(SYM, AGENT, code)
print('CHECK:', chk.get('ok'), '| outcome:', chk.get('outcome'), '| percent:', chk.get('percent'), '| checks:', chk.get('checks'))
print('RELEASE:', rel[:200].replace(chr(10),' '))
