import json, subprocess, sys
ROOT='/home/armandofm/projects/fzgx'
r = subprocess.run([sys.executable, 'tools/fzgx.py', '--json', 'claim', 'fn_3_1ADA4',
                    '--agent', 'praw', '--max-attempts', '2', '--check'],
                   cwd=ROOT, text=True, capture_output=True, timeout=240)
print('rc', r.returncode)
try:
    j = json.loads(r.stdout)
    print(json.dumps(j, indent=2)[:1500])
except Exception:
    print('stdout[:1500]:', r.stdout[:1500])
    print('stderr[:100]:', r.stderr[:100])
