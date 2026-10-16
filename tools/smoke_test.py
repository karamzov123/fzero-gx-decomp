import json, re, subprocess, sys
from pathlib import Path
ROOT = '/home/armandofm/projects/fzgx'
# 1. carve a fresh symbol
r = subprocess.run([sys.executable, 'tools/fzgx.py', '--json', 'carve',
                    'fn_80053770', '--agent', 'smoke', '--max-attempts', '2'],
                   cwd=ROOT, text=True, capture_output=True, timeout=220)
import re
try:
    j = json.loads(r.stdout)
    print('CARVE ok:', j.get('ok'), '| attempt:', j.get('attempt'), '| ctx_len:', len(j.get('context') or ''))
except Exception:
    print('carve raw:', r.stdout[:200], r.stderr[:100])
    sys.exit(0)
ctx = j.get('context') or ''

# 2. hermes model turn
prompt = f"Write the COMPLETE C source for fzgx function fn_80053770 (module main, 352 bytes). Return C code ONLY."
r2 = subprocess.run(['hermes','chat','--oneshot','-q',prompt,'--model','upstage/solar-pro4:free'],
                    cwd='/home/armandofm', text=True, capture_output=True, timeout=220)
out = (r2.stdout or '')
print('HERMES rc:', r2.returncode, 'len:', len(out))
m = re.search(r'```(?:c)?\s*\n(.*?)```', out, re.S)
import re
code = m.group(1).strip() if m else out.strip()
print('CODE_LEN:', len(code))
Path(ROOT+'/.fzgx/work/fn_80053770.c').write_text(code+chr(10))

# 3. engine check
r3 = subprocess.run([sys.executable,'tools/fzgx.py','--json','check','fn_80053770','--agent','smoke','--max-checks','4'], cwd=ROOT, text=True, capture_output=True, timeout=220)
try:
    j3 = json.loads(r3.stdout)
    print('CHECK ok:', j3.get('ok'), '| outcome:', j3.get('outcome'), '| percent:', j3.get('percent'), '| checks:', j3.get('checks'))
except Exception:
    print('check raw:', r3.stdout[:200])

# 4. release
r4 = subprocess.run([sys.executable,'tools/fzgx.py','--json','release','fn_80053770','--agent','smoke','--reason','smoke'], cwd=ROOT, text=True, capture_output=True, timeout=220)
try:
    j4 = json.loads(r4.stdout); print('RELEASE ok:', j4.get('ok'), j4.get('error'))
except Exception:
    print('release raw:', r4.stdout[:200])
