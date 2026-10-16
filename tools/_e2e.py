import json, subprocess, sys, time
SYM = 'fn_9_AF0'
AGENT = 'probe3'
ROOT = '/home/armandofm/projects/fzgx'

def fx(*args):
    return subprocess.run([sys.executable, 'tools/fzgx.py', '--json', *args],
                          cwd=ROOT, text=True, capture_output=True, timeout=180)

# 1) claim (no --check): installs work-copy stub, returns context
r = fx('claim', SYM, '--agent', AGENT, '--max-attempts', '2')
try:
    j = json.loads(r.stdout)
    print('CLAIM ok:', j.get('ok'), 'attempt:', j.get('attempt'), 'context_len:', len(j.get('context') or ''))
except Exception:
    print('CLAIM raw:', r.stdout[:300], r.stderr[:100])
    sys.exit(1)

ctx = j.get('context') or ''

# 2) ask hermes for C (prompt just names the symbol + short context)
prompt = f"Write the COMPLETE C source for the matched function `{SYM}` (module car_colchg, 720 bytes). Return the C code only, no markdown fences. Context: {ctx[:400]}"
r2 = subprocess.run(['hermes', 'chat', '--oneshot', '-q', prompt, '--model', 'fn_9_AF0'], cwd='/home/armandofm', text=True, capture_output=True, timeout=180)
out = (r2.stdout or '')
print('hermes rc:', r2.returncode, 'len:', len(out))

# 3) write C to work copy
import re
m = re.search(r'```(?:c)?\s*\n(.*?)```', out, re.S)
code = m.group(1).strip() if m else out.strip()
print('code len:', len(code), 'first:', code[:60].replace(chr(10),' '))
work = f'{ROOT}/.fzgx/work/{SYM}.c'
open(work, 'w').write(code + '\n')
print('wrote work copy')

# 4) write_unit + check + release with SAME agent
from pathlib import Path
def fx(*args):
    return subprocess.run([sys.executable, 'tools/fzgx.py', '--json', *args], cwd=ROOT, text=True, capture_output=True, timeout=180)

r3 = fx('write_unit', SYM, '--agent', AGENT, '--source', code)
print('write_unit:', r3.stdout[:200])

r4 = fx('check', SYM, '--agent', AGENT, '--max-checks', '4')
try:
    j4 = json.loads(r4.stdout)
    print('check ok:', j4.get('ok'), 'outcome:', j4.get('outcome'), 'percent:', j4.get('percent'), 'checks:', j4.get('checks'))
except Exception as e:
    print('check raw:', r4.stdout[:300], r4.stderr[:100])

r5 = fx('release', SYM, '--agent', AGENT, '--reason', 'e2e-probe')
print('release:', r5.stdout[:200])
