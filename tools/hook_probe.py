import json, subprocess, sys
r = subprocess.run([sys.executable, 'tools/fzgx.py', '--json', 'claim', 'fn_9_AF0',
                    '--agent', 'hook-probe', '--max-attempts', '2'],
                   cwd='/home/armandofm/projects/fzgx', text=True, capture_output=True, timeout=300)
try:
    j = json.loads(r.stdout)
    print('ok:', j.get('ok'))
    print('attempt:', j.get('attempt'))
    print('seed:', json.dumps(j.get('seed'), indent=2)[:300])
    print('context_len:', len(j.get('context') or ''))
    print('context[:120]:', (j.get('context') or '')[:120])
except Exception as e:
    print('parse fail:', e, 'rc', r.returncode)
    print('stdout[:200]:', r.stdout[:200])
