"""asmcmp.py TARGET DONOR: opcode-level diff of two retail functions (differing regions + symbol renames). Use it to port a matched near-clone."""
import json,re,difflib,sys,glob
idx={}
for f in glob.glob('/home/armandofm/projects/fzgx/.fzgx/asm_index_GFZE01_*.json'):
    for k,v in json.load(open(f))['functions'].items(): idx[k]=[re.sub(r'^[0-9A-F]+: ','',l) for l in v['asm'] if re.match(r'[0-9A-F]+: ',l)]
a=idx[sys.argv[1]]; b=idx[sys.argv[2]]
sm=difflib.SequenceMatcher(None,[x.split()[0] for x in a],[x.split()[0] for x in b],autojunk=False)
print(f'ratio {sm.ratio():.3f} len {len(a)} vs {len(b)}')
for tag,i1,i2,j1,j2 in sm.get_opcodes():
    if tag!='equal':
        print(tag,i1,i2,j1,j2)
        for x in a[max(i1-2,0):i2+2]: print('   T:',x)
        for x in b[max(j1-2,0):j2+2]: print('   D:',x)
# operand-level differences inside equal opcode runs (symbols/immediates)
diffs=set()
for tag,i1,i2,j1,j2 in sm.get_opcodes():
    if tag=='equal':
        for x,y in zip(a[i1:i2],b[j1:j2]):
            for p,q in zip(re.findall(r'\b(?:lbl|fn)_\w+',x),re.findall(r'\b(?:lbl|fn)_\w+',y)):
                if p!=q: diffs.add((q,p))
print('symbol renames donor->target:'); [print('  ',q,'->',p) for q,p in sorted(diffs)]
