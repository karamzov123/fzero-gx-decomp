"""rodump.py MODULE SECTION START END: retail words of a REL section (e.g. .rodata) in [START, END)
(section-relative offsets). Use to recover initializer words a body copies from the TU pool."""
import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from fzgx.project import Project
p = Project()
raw = p._raw_section(sys.argv[1], sys.argv[2])
lo, hi = int(sys.argv[3], 16), int(sys.argv[4], 16)
for a in range(lo, hi, 4):
    print(f'{a:#06x}: {raw[a:a+4].hex()}')
