import sys
import json, subprocess
ROOT = '/home/armandofm/projects/fzgx'
r = subprocess.run([sys.executable, 'tools/fzgx.py', '--json', 'claim',
                    'fn_3_149AC', '--agent', 'mth-probe', '--max-attempts', '2'],
                   cwd=ROOT, text=True, capture_output=True, timeout=240)
print('rc', r.returncode)
try:
    j = json.loads(r.stdout)
    print('ok:', j.get('ok'), '| attempt:', j.get('attempt'), '| context_len:', len(j.get('context') or ''))
    print('ctx[:300]:', (j.get('context') or '')[:300])
except Exception as e:
    print('parse fail:', r.stdout[:300], r.stderr[:100])
