"""poollits.py IN OUT [POOLSYM] (main_rel): replace F(0xNN)/D(0xNN)/DF(0xNN) reads of a REL literal pool with native literals.

F = f32 at the offset, D = f64, DF = the f32 value written as a double literal. Run tools/manualkit/primer.py
afterwards so the literals (and MWCC conversion constants) land on the retail pool offsets."""
import sys, re, struct
sys.path.insert(0,'tools')
from fzgx.project import Project
p=Project()
src=open(sys.argv[1]).read()
sym=sys.argv[3] if len(sys.argv)>3 else 'lbl_1_rodata_7AB8'
s=p.symbols('main_rel')[sym]
raw=p._raw_section('main_rel',s.section)
data=raw[s.addr-p._section_base('main_rel',s.section):]
def f32lit(off):
    v=struct.unpack('>f',data[off:off+4])[0]
    for prec in range(6,12):
        s='%.*g'%(prec,v)
        if struct.unpack('>f',struct.pack('>f',float(s)))[0]==v: break
    if 'e' not in s and '.' not in s: s+='.0'
    return '('+s+'f)' if not s.startswith('-') else '('+s+'f)'
def f64lit(off):
    v=struct.unpack('>d',data[off:off+8])[0]
    s=repr(v)
    if 'e' not in s and '.' not in s: s+='.0'
    return '('+s+')'
out=re.sub(r'\bDF\((0x[0-9a-fA-F]+|\d+)\)',lambda m:f32lit(int(m.group(1),0)).replace('f)',')'),src)
src=out
out=re.sub(r'\bF\((0x[0-9a-fA-F]+|\d+)\)',lambda m:f32lit(int(m.group(1),0)),src)
out=re.sub(r'\bD\((0x[0-9a-fA-F]+|\d+)\)',lambda m:f64lit(int(m.group(1),0)),out)
open(sys.argv[2],'w').write(out)
print(len(re.findall(r'\bF\(',src)),len(re.findall(r'\bD\(',src)))
