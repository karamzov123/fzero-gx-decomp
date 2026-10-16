import json, subprocess, sys, time, re
from pathlib import Path
ROOT = '/home/armandofm/projects/fzgx'
SYM = 'fn_9_AF0'
AGENT = 'clean-probe'

def fx(*args, timeout=180):
    return subprocess.run([sys.executable, 'tools/fzgx.py', '--json', *args],
                          cwd=ROOT, text=True, capture_output=True, timeout=timeout)

print('=== 1) claim ===')
r = fx('claim', SYM, '--agent', AGENT, '--max-attempts', '2')
try:
    j = json.loads(r.stdout)
    print('ok:', j.get('ok'), '| attempt:', j.get('attempt'), '| context_len:', len(j.get('context') or ''))
    ctx = j.get('context') or ''
except Exception as e:
    print('claim failed:', r.stdout[:300], r.stderr[:100])
    sys.exit(1)

print('=== 2) hermes model turn ===')
prompt = f"Write the COMPLETE C source for matched function `{SYM}` (module car_colchg, 720 bytes, 180 instructions). Return C code ONLY, no markdown fences, no prose. Context start: {ctx[:300]}"
r2 = subprocess.run(['hermes', 'chat', '--oneshot', '-q', prompt, '--model', 'upstage/solar-pro4:free'],
                    cwd='/home/armandofm', text=True, capture_output=True, timeout=300)
out = (r2.stdout or '')
print('hermes rc:', r2.returncode, 'len:', len(out))
m = re.search(r'```(?:c)?\s*\n(.*?)```', out, re.S)
code = m.group(1).strip() if m else out.strip()
print('code len:', len(code), 'first:', code[:50].replace(chr(10),' '))
assert len(code) > 100, 'model returned too little C'

Path(f'{ROOT}/.fzgx/work/{SYM}.c').write_text(code + '\n')

print('=== 3) write_unit + check + release (same agent) ===')
r3 = fx('write_unit', SYM, '--agent', AGENT, '--source', code)
print('write_unit:', r3.stdout[:200].replace(chr(10),' '))
time.sleep(2)

r4 = fx('check', SYM, '--agent', AGENT, '--max-checks', '4')
try:
    j4 = json.loads(r4.stdout)
    print('check ok:', j4.get('ok'), '| outcome:', j4.get('outcome'), '| percent:', j4.get('percent'), '| checks:', j4.get('checks'))
except Exception:
    print('check raw:', r4.stdout[:300], r4.stderr[:100])

r5 = fx('release', SYM, '--agent', AGENT, '--reason', 'e2e-clean-probe')
print('release:', r5.stdout[:200].replace(chr(10),' '))
