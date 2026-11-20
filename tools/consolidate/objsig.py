"""Order-independent semantic signature of a relocatable ELF32 big-endian object."""
import struct
def sig(path):
    data = open(path, 'rb').read()
    shoff = struct.unpack('>I', data[32:36])[0]
    shentsize, shnum, shstrndx = struct.unpack('>HHH', data[46:52])
    sh = [struct.unpack('>IIIIIIIIII', data[shoff+i*shentsize:shoff+(i+1)*shentsize]) for i in range(shnum)]
    def cstr(tab, off): return tab[off:tab.index(0, off)].decode()
    shstr = data[sh[shstrndx][4]:sh[shstrndx][4]+sh[shstrndx][5]]
    names = [cstr(shstr, s[0]) for s in sh]
    syms = []
    symtab = next((i for i, s in enumerate(sh) if s[1] == 2), None)
    if symtab is not None:
        s = sh[symtab]; strtab = data[sh[s[6]][4]:sh[s[6]][4]+sh[s[6]][5]]
        for j in range(0, s[5], 16):
            n, v, sz, info, oth, ndx = struct.unpack('>IIIBBH', data[s[4]+j:s[4]+j+16])
            syms.append((cstr(strtab, n), v, sz, info, ndx))
    def secname(ndx): return names[ndx] if 0 < ndx < len(names) else str(ndx)
    out = {'sections': {}, 'relocs': {}, 'defs': set()}
    for i, s in enumerate(sh):
        if s[1] in (1, 8) and names[i] not in ('.comment',):  # PROGBITS / NOBITS
            out['sections'][names[i]] = data[s[4]:s[4]+s[5]] if s[1] == 1 else s[5]
        if s[1] == 4:  # RELA
            tgt = names[s[7]]
            rel = []
            for j in range(0, s[5], 12):
                off, info, add = struct.unpack('>IIi', data[s[4]+j:s[4]+j+12])
                sym = syms[info >> 8]
                nm = sym[0] or secname(sym[4])
                rel.append((off, info & 0xff, nm, add))
            out['relocs'][tgt] = sorted(rel)
    for nm, v, sz, info, ndx in syms:
        if nm and ndx != 0 and ndx < 0xff00:
            out['defs'].add((nm, secname(ndx), v, sz, info >> 4))
    return out

import re as _re
def canon(sg):
    """Replace compiler-numbered local names (@N, name$N) by their defining location; return
    (canonical signature, {local name: location})."""
    loc = {}
    for nm, sec, v, sz, bind in sg['defs']:
        if _re.match(r'^@\d+$', nm) or _re.search(r'\$\d+$', nm):
            loc[nm] = f'<{sec}+{v:#x}>'
    defs = {(loc.get(nm, nm), sec, v, sz, b) for nm, sec, v, sz, b in sg['defs']}
    relocs = {k: sorted((o, t, loc.get(n, n), a) for o, t, n, a in r) for k, r in sg['relocs'].items()}
    return {'sections': sg['sections'], 'relocs': relocs, 'defs': defs}, loc
