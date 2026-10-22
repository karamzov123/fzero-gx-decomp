import sys
sys.path.insert(0, str(__import__("pathlib").Path(__file__).resolve().parents[1]))
from pathlib import Path
from fzgx.project import Project
from fzgx import oracle, poolfix
mod,src,base=sys.argv[1],Path(sys.argv[2]),int(sys.argv[3],16)
p=Project()
o=oracle.compile_many(p,mod,[src],src.parent/'objmap',mw_version=sys.argv[4] if len(sys.argv)>4 else None)[src]
elf=poolfix.Elf(Path(o).read_bytes()); sec=elf.section('.bss')
syms=sorted((s for s in elf.symbols() if s['shndx']==sec['index']),key=lambda s:s['value'])
for s in syms:
    name=s['name']; want=None
    import re
    m=re.search(r'([0-9A-F]{5})(?:__fzgx_offset_([0-9A-F]+))?$',name.replace('fzgx_pad_','lbl_1_bss_'))
    if m: want=int(m[1],16)+(int(m[2],16) if m[2] else 0)-base
    print(f"{s['value']:5X} {s['size']:4X} {name:40} {'' if want is None else ('OK' if want==s['value'] else f'want {want:X}')}")
