#!/usr/bin/env python3
"""Rewrite a lifted GX unit's private `GXData` view onto the shared include/dolphin/gx/GXPriv.h.

Lifted GX files declare their own padded GXData (only the fields that function touches) and their
own PPCWGPipe. This drops both, includes the shared headers and renames every `gx->field` to the
SDK field at the same offset. It only rewrites text: tu_try.py proves the object is unchanged.

Usage (library): unify(text) -> new text, or raises Unsupported with the reason.
       (CLI):    gx_unify.py src/dol/A.c ...   prints what would change
"""
import pathlib, re, sys

sys.path.insert(0, str(pathlib.Path(__file__).parent))
import gx_header

HDR = pathlib.Path('include/dolphin/gx/GXPriv.h')
SIZES = {'float': 4, 'u8': 1, 's8': 1, 'char': 1, 'GXBool': 1, 'u16': 2, 's16': 2, 'u32': 4, 's32': 4, 'int': 4,
         'f32': 4, 'GXAttrType': 4, 'GXPerf0': 4, 'GXPerf1': 4, 'GXTexRegionCallback': 4,
         'GXTlutRegionCallback': 4, 'GXTexRegion': 16, 'GXTlutRegion': 16}
ALIGN = {'GXTexRegion': 4, 'GXTlutRegion': 4}
DIMS = {'GX_MAX_TEXMAP': 8, 'GX_MAX_TLUT_ALL': 20}


SET_REG_FIELD = ('#define SET_REG_FIELD(reg, size, shift, val) \\\n'
                 '    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))\n')
SET_REG_FIELD_RLWIMI = ('#define SET_REG_FIELD_RLWIMI(reg, size, shift, val) \\\n'
                        '    ((reg) = __rlwimi((reg), (val), (shift), 32 - (shift) - (size), 31 - (shift)))\n')
VIEW = re.compile(r'(?:typedef\s+)?struct\s+(\w*(?:_gx_T|GXContext|GXState|GXData\w*))\s*\{([^{}]*)\}\s*(\w*)\s*;\n?')


class Unsupported(Exception):
    pass


def layout(body):
    """name -> (offset, element size, count or None for a scalar)"""
    out, off = {}, 0
    for raw in body.split(';'):
        d = re.sub(r'/\*.*?\*/|//[^\n]*', '', raw, flags=re.S).strip()
        if not d:
            continue
        d = d.replace('unsigned char', 'u8')
        fp = re.fullmatch(r'.*\(\s*\*\s*(\w+)\s*\)\s*\(.*\)', d, re.S)
        if fp:
            off = (off + 3) & ~3
            out[fp.group(1)] = (off, 4, None)
            off += 4
            continue
        m = re.match(r'^(?:volatile\s+)?(\w+)\s*(\*?)\s*(\w+)\s*(?:\[([^\]]+)\])?$', d)
        if not m:
            raise Unsupported(f'field {d!r}')
        ty, ptr, name, dim = m.groups()
        size = 4 if ptr else SIZES.get(ty)
        if size is None:
            raise Unsupported(f'field type {ty}')
        al = 4 if ptr else ALIGN.get(ty, size)
        off = (off + al - 1) & ~(al - 1)
        n = None if dim is None else DIMS.get(dim.strip()) or int(dim, 0)
        out[name] = (off, size, n)
        off += size * (n or 1)
    return out


def canonical():
    m = re.search(r'typedef struct _GXData \{(.*?)\} GXData;', HDR.read_text(), re.S)
    if m is None:
        raise Unsupported('GXData not found in GXPriv.h')
    c = layout(m.group(1))
    if c['tevc'][0] != 0x130 or c['cmode0'][0] != 0x1D0:
        raise Unsupported('canonical GXData layout changed')
    return c


def resolve(canon, off, size):
    for name, (o, s, n) in canon.items():
        if o <= off < o + s * (n or 1):
            if s != size or (off - o) % s:
                raise Unsupported(f'offset {off:#x}: size {size} over {name}')
            return name, None if n is None else (off - o) // s, n
    raise Unsupported(f'offset {off:#x} is not in GXData')


def strip_header_types(text):
    """Drop the file's own copy of any type the shared header defines (the object check decides)."""
    known = {n for n, *_ in gx_header.blocks(HDR.read_text()) if n}
    for name, _, start, end in sorted(gx_header.blocks(text), key=lambda b: -b[2]):
        if name in known:
            text = text[:start] + text[end:]
    return text


def macro(name):
    return re.compile(rf'^#define\s+{name}\((?:[^\n]*\\\n)*[^\n]*\n?', re.M)


def normalize_macros(text, rlwimi=False):
    """One spelling of the register-field macro across a TU; the BP write comes from dolphin/gx.h.
    rlwimi=True keeps a unit's __rlwimi field insert (the classic and/or form changes its code)."""
    first = re.search(r'#define\s+SET_REG_FIELD\(\s*reg,\s*mask', text)
    if first:
        def to_size(mm):
            mask = int(mm.group(2), 0)
            if mask & (mask + 1):
                raise Unsupported(f'SET_REG_FIELD mask {mask:#x} is not a contiguous field')
            return f'SET_REG_FIELD({mm.group(1)}, {(mask + 1).bit_length() - 1},'
        body = macro('SET_REG_FIELD').sub('', text, count=1)
        body = re.sub(r'\bSET_REG_FIELD\(([^,]+),\s*(0x[0-9a-fA-F]+|\d+),', to_size, body)
        text = body[:first.start()] + SET_REG_FIELD + body[first.start():]
    d = re.search(r'#define\s+SET_REG_FIELD\(\s*reg,\s*size(?:[^\n]*\\\n)*[^\n]*', text)
    if d and d.group(0) != SET_REG_FIELD.rstrip('\n'):
        if rlwimi and '__rlwimi' in d.group(0):
            text = macro('SET_REG_FIELD').sub(lambda _: SET_REG_FIELD_RLWIMI, text)
            text = re.sub(r'\bSET_REG_FIELD\(', 'SET_REG_FIELD_RLWIMI(', text)
        else:
            text = macro('SET_REG_FIELD').sub(lambda _: SET_REG_FIELD, text)
    return macro('GX_WRITE_RAS_REG').sub('', text)


def normalize_fifo(text):
    """Lifted `GXWGFifo8`/u32 macros over the FIFO address become members of the named object."""
    word = re.search(r'#define\s+GXWGFifo\s+\(\*\(volatile u32', text)
    text = re.sub(r'^(?://[^\n]*fzgx-allow[^\n]*\n)*#define\s+(?:GXWGFifo\w*|GX_FIFO_ADDRESS)\b[^\n]*\n?',
                  '', text, flags=re.M)
    text = re.sub(r'\bGXWGFifo8\b', 'GXWGFifo.u8', text)
    if word:
        text = re.sub(r'\bGXWGFifo\b(?!\s*\.)', 'GXWGFifo.u32', text)
    return text


def integer_views(text, canon):
    """`(T *)(gx + 0x1EC)` from an `extern u32 gx` view addresses the field at that offset."""
    def sub(mm):
        size = SIZES.get(mm.group(1))
        if size is None:
            raise Unsupported(f'gx + offset through {mm.group(1)}')
        name, idx, _ = resolve(canon, int(mm.group(2), 0), size)
        return f'({mm.group(1)} *)&gx->{name}' + (f'[{idx}]' if idx is not None else '')
    text = re.sub(r'\(\s*(\w+)\s*\*\s*\)\s*\(\s*gx\s*\+\s*(0x[0-9a-fA-F]+|\d+)\s*\)', sub, text)
    if re.search(r'\bgx\s*\+', text):
        raise Unsupported('integer arithmetic on gx')
    return text


def normalize_externs(text):
    """The OS interrupt calls come from their SDK header; __peReg and __cpReg are volatile u16 blocks."""
    text = re.sub(r'^extern\s+\w+\s+OS(?:Disable|Restore)Interrupts\([^)]*\);\n', '', text, flags=re.M)
    text = re.sub(r'\bOSDisableInterrupts\(\s*\w+\s*\)', 'OSDisableInterrupts()', text)
    text = re.sub(r'^extern\s+void\s+OS(?:ClearContext|SetCurrentContext)\(void \*\);\n', '', text, flags=re.M)
    for reg in ('__peReg', '__cpReg'):
        decl = f'extern volatile u16 *{reg};'
        v = re.search(rf'struct\s+(\w+_{reg}_T)\s*\{{([^{{}}]*)\}}\s*;\n?', text)
        if v:
            fields = layout(v.group(2))
            text = text[:v.start()] + text[v.end():]
            text = re.sub(rf'^extern\s+struct\s+{v.group(1)}\s*\*\s*{reg}\s*;', decl, text, flags=re.M)
            text = re.sub(rf'{reg}->(\w+)', lambda m: f'{reg}[{fields[m.group(1)][0] // 2}]', text)
        text = re.sub(rf'^extern\s+(?:u16|vu16)\s*\*\s*{reg}\s*;', decl, text, flags=re.M)
    return text


def view_field(canon, views, name):
    """(offset, size, count) of a view's field; lifted `unk_1DC`/`field_2` names carry the offset."""
    for v in views:
        if name in v:
            return v[name]
    m = re.fullmatch(r'(?:unk|field)_([0-9A-Fa-f]+)', name)
    if m:
        off = int(m.group(1), 16)
        for o, s, n in canon.values():
            if o <= off < o + s * (n or 1):
                return off, s, None
    raise Unsupported(f'gx->{name} is in neither layout')


def unify(text, rlwimi=False):
    canon = canonical()
    views, names = [], []
    m = re.search(r'typedef\s+struct\s*\w*\s*\{((?:[^{}])*)\}\s*GXData\s*;\n?', text)
    if m:
        views.append(layout(m.group(1)))
        text = text[:m.start()] + text[m.end():]
    for v in reversed(list(VIEW.finditer(text))):
        views.append(layout(v.group(2)))
        names += [x for x in (v.group(1), v.group(3)) if x]
        text = text[:v.start()] + text[v.end():]
    text = re.sub(r'typedef\s+union\s*\w*\s*\{[^{}]*\}\s*PPCWGPipe\s*;\n?', '', text)
    text = normalize_fifo(text)
    text = integer_views(text, canon)
    text = re.sub(r'typedef\s+union\s*\w*\s*\{[^{}]*\}\s*GXWGFifoReg\s*;\n?', '', text)
    text = strip_header_types(text)
    text = normalize_macros(text, rlwimi)
    text = normalize_externs(text)
    text = re.sub(r'\bgx->fields\.view_(\w+)\.\1\b', r'gx->\1', text)
    text = re.sub(r'^extern\s+[^;\n]*\bgx\s*;\n?', '', text, flags=re.M)
    text = re.sub(r'^(?://[^\n]*\n)?volatile\s+PPCWGPipe\s+(?:GXWGFifo|GXFIFO)\s*:[^\n]*\n?', '', text, flags=re.M)
    text = re.sub(r'^(?://[^\n]*\n)?volatile\s+PPCWGPipe\s*\n\s*(?:GXWGFifo|GXFIFO)\s*:[^\n]*\n?', '', text, flags=re.M)
    text = re.sub(r'\bGXFIFO\b', 'GXWGFifo', text)

    # locals and casts of a view become GXData
    ptrs = {'gx'}
    for n in names:
        ty = rf'(?:struct\s+)?\b{n}\b'
        ptrs |= set(re.findall(ty + r'\s*\*\s*(\w+)\s*(?:=|;|,|\))', text))
        text = re.sub(r'\(\s*' + ty + r'\s*\*\s*\)\s*gx\b', 'gx', text)
        text = re.sub(ty + r'\s*\*', 'GXData *', text)

    def sub(mm):
        var, name, idx = mm.group(1), mm.group(2), mm.group(3)
        if name in canon and not any(name in v for v in views):
            return mm.group(0)
        off, size, n = view_field(canon, views, name)
        cn, ci, cc = resolve(canon, off, size)
        if n is None:
            return f'{var}->{cn}' + (f'[{ci}]' if ci is not None else '') + (idx or '')
        if ci == 0 and n <= cc:
            return f'{var}->{cn}' + (idx or '')       # an array over the start of an SDK array
        if idx and re.fullmatch(r'\[(0x[0-9a-fA-F]+|\d+)\]', idx):
            cn, ci, _ = resolve(canon, off + int(idx[1:-1], 0) * size, size)
            return f'{var}->{cn}' + (f'[{ci}]' if ci is not None else '')
        raise Unsupported(f'{var}->{name}{idx or ""} needs a variable index across SDK fields')

    text = re.sub(r'\b(' + '|'.join(sorted(ptrs)) + r')->(\w+)(\[[^\]]+\])?', sub, text)
    text = re.sub(r'^#include\s+[<"]dolphin/gx(?:/GXPriv)?\.h[>"]\n', '', text, flags=re.M)
    inc = re.search(r'^#include[^\n]*\n', text, re.M)
    at = inc.start() if inc else 0     # before any declaration: merged files have later includes
    os_inc = '#include <dolphin/os/OSInterrupt.h>\n'
    extra = os_inc if re.search(r'\bOS(?:Disable|Restore)Interrupts\(', text) and os_inc not in text else ''
    return text[:at] + '#include <dolphin/gx.h>\n#include <dolphin/gx/GXPriv.h>\n' + extra + text[at:]


if __name__ == '__main__':
    for p in sys.argv[1:]:
        t = pathlib.Path(p).read_text()
        try:
            n = unify(t)
            print(p, 'unchanged' if n == t else f'rewritten ({len(t)} -> {len(n)})')
        except Unsupported as e:
            print(p, 'UNSUPPORTED', e)
