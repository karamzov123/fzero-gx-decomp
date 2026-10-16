import json, subprocess, sys
ROOT = '/home/armandofm/projects/fzgx'
r = subprocess.run([sys.executable, 'tools/fzgx.py', '--json', 'claim', 'fn_9_AF0',
                    '--agent', 'probe4', '--max-attempts', '2'],
                   cwd=ROOT, text=True, capture_output=True, timeout=250)
print('rc:', r.returncode)
print('stdout:', r.stdout[:2000])
print('stderr:', r.stderr[:300])
try:
    j = json.loads(r.stdout)
    print('keys:', list(j.keys()))
    print('ok:', j.get('ok'))
    print('attempt:', j.get('attempt'))
    print('context_len:', len(j.get('context') or ''))
    print('seed:', json.dumps(j.get('seed'), indent=2)[:200])
    print('context[:80]:', (j.get('context') or '')[:80])
except Exception as e:
    print('parse fail:', e)
