"""bsslayout.py MODULE START END [SPLIT=addr:decl,...]: emit unit .bss definitions for retail objects in [START, END)
in address order (fzgx_obj_ names), filling gaps; prints C text. SPLIT overrides an address with explicit decls."""
import sys,re
sys.path.insert(0, str(__import__("pathlib").Path(__file__).resolve().parents[1]))
from fzgx.project import Project
mod=sys.argv[1]; lo=int(sys.argv[2],16); hi=int(sys.argv[3],16)
over={}
for a in sys.argv[4:]:
    k,v=a.split('=',1); over[int(k,16)]=v
p=Project()
syms=sorted((s for s in p.symbols(mod).values() if s.section=='.bss' and lo<=s.addr<hi), key=lambda s:s.addr)
out=[]; names=[]; cur=lo
def emit(addr,decl,name):
    out.append(decl); names.append(name)
def align_of(decl):
    if '[' in decl or decl.startswith(('u32','s32','f32','void','struct')) or '*' in decl: return 4
    if decl.startswith(('s16','u16')): return 2
    return 1
def place(cur,a): return (cur+a-1)//a*a
for s in syms:
    if s.addr<cur: continue
    if s.addr in over:
        decls=[d.strip()+';' for d in over[s.addr].split(';') if d.strip()]
    else:
        n='fzgx_obj_'+s.name; size=s.size; decls=[]
        if size==1: decls=[f'u8 {n};']
        elif size==2 and s.addr%2==0: decls=[f's16 {n};']
        elif size==4 and s.addr%4==0: decls=[f'u32 {n};']
        elif s.addr%4==0: decls=[f'u8 {n}[0x{size:X}];']
        else:
            a=s.addr; e=s.addr+size; first=True
            while a<e:
                nm=n if first else f'{s.name}__fzgx_offset_{a-s.addr:X}'
                if a%2: decls.append(f'u8 {nm};'); a+=1
                elif a%4==2 or e-a<4: decls.append(f's16 {nm};'); a+=2
                else: decls.append(f'u32 {nm};'); a+=4
                first=False
    # pad with single bytes until the first decl lands exactly
    while place(cur,align_of(decls[0]))<s.addr:
        emit(cur,f'u8 fzgx_pad_{cur:X};',f'fzgx_pad_{cur:X}'); cur+=1
    for d in decls: emit(s.addr,d,re.findall(r'(\w+)\s*(?:\[|;|$)',d)[0] if False else re.sub(r'\[.*','',d.rstrip(';')).split()[-1].lstrip('*'))
    cur=s.addr+s.size
print('\n'.join(out))
print('#pragma section code_type ".fzgxpool"')
print('static void fzgx_bss_layout(void) {')
print('    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */')
for n in names: print(f'    s = *(u8 *)&{n};')
print('}')
print('#pragma section code_type ".text"')
