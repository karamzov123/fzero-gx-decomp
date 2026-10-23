"""split a `static union { u32 w[N]; T v[..]; } NAME = {{ ... }};` object at byte offset."""
import re
def parse(t,name):
    s=t.index('static union {'+'', t.index(name+' = {{')-200)
    s=t.rfind('static ',0,t.index(name+' = {{'))
    e=t.index('}};',s)+4
    blk=t[s:e]
    body=blk[blk.index('{{')+2:blk.rindex('}}')]
    items=[x.strip() for x in re.split(r',\s*', re.sub(r'/\*.*?\*/','',body).strip()) if x.strip()]
    return s,e,items
def emit(name,words,decl):
    lines=['    '+', '.join(words[i:i+8]) for i in range(0,len(words),8)]
    return (f'static union {{ u32 w[{len(words)}]; {decl}; }} {name} = {{{{  /* fzgx-allow: A1 retail data bytes and bindings */\n'
            +',\n'.join(l+'  /* fzgx-allow: A1 retail data bytes */' for l in lines)+'\n}};\n')
def split(t,name,base,cuts):
    """cuts: list of (addr, newname, decl) in increasing order; first entry is base itself."""
    s,e,items=parse(t,name)
    out=''
    for i,(addr,nm,decl) in enumerate(cuts):
        end=cuts[i+1][0] if i+1<len(cuts) else base+4*len(items)
        out+=emit(nm,items[(addr-base)//4:(end-base)//4],decl)
    return t[:s]+out+t[e:]
