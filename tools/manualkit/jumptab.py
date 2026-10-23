"""jumptab.py MODULE SYMBOL...: print each retail jump table as case index -> target address."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fzgx.project import Project
p = Project()
mod = sys.argv[1]
for name in sys.argv[2:]:
    data = p.bytes_at(mod, name)
    if data is None:
        print(name, 'not found'); continue
    words = [int.from_bytes(data[i:i+4], 'big') for i in range(0, len(data), 4)]
    groups = {}
    for i, w in enumerate(words):
        groups.setdefault(w, []).append(i)
    print(f'{name}: {len(words)} entries')
    for w, idx in sorted(groups.items()):
        print(f'  {w:08X}: {idx}')
