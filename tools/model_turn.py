import json, subprocess, re, sys
from pathlib import Path
ROOT = '/home/armandofm/projects/fzgx'
r = subprocess.run(['hermes', 'chat', '--oneshot', '-q',
    'Write the COMPLETE C source for the fzfx matched function `fn_3_149AC` '
    '(module customize, 528 bytes). Return C code ONLY: no markdown fences, no '
    'prose, no explanations.',
    '--model', 'upstage/solar-pro4:free'],
    cwd=ROOT, text=True, capture_output=True, timeout=280)
out = (r.stdout or '')
print('rc', r.returncode, 'len', len(out))
m = re.search(r'```(?:c)?\s*\n(.*?)```', out, re.S)
code = m.group(1).strip() if m else out.strip()
print('CODE_LEN', len(code))
print('CODE[:120]:', code[:120].replace(chr(10), ' '))
Path(ROOT + '/.fzgx/work/fn_3_149AC.c').write_text(code + chr(10))
print('WROTE', len(code))
