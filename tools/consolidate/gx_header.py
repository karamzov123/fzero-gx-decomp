"""Extract the GX private types embedded in DOL GX files into include/dolphin/gx/GXPriv.h.

Each lifted/imported GX file carried its own copy of the SDK's private GX types (GXData, the
enums, PPCWGPipe...). The header takes the majority definition of every type, in dependency
order of the most complete file. A file whose embedded copies are all identical to the header's
loses them and includes the header; files with variant definitions are left unchanged and
reported. Usage: gx_header.py [--apply]"""
import re, sys, pathlib, collections

def blocks(t):
    lines = t.splitlines(keepends=True); i = 0; pos = 0
    offs = [0]
    for l in lines: offs.append(offs[-1] + len(l))
    while i < len(lines):
        s = lines[i].strip(); start = offs[i]
        if re.match(r'^typedef\s+(struct|enum|union)\b.*\{', s) or re.match(r'^(struct|union|enum)\s+\w+\s*\{', s):
            j = i; depth = lines[i].count('{') - lines[i].count('}')
            while depth > 0 and j + 1 < len(lines):
                j += 1; depth += lines[j].count('{') - lines[j].count('}')
            text = ''.join(lines[i:j + 1])
            m = re.search(r'\}\s*(\w+)\s*;\s*$', text.strip()) or re.match(r'\s*(?:typedef\s+)?(?:struct|union|enum)\s+(\w+)', text)
            yield (m.group(1) if m else None), text, start, offs[j + 1]
            i = j + 1; continue
        if s.startswith('typedef ') and s.endswith(';'):
            fm = re.search(r'\(\s*\*\s*(\w+)\s*\)', s); mm = re.search(r'(\w+)\s*(?:\[[^\]]*\])*\s*;$', s)
            yield (fm.group(1) if fm else (mm.group(1) if mm else None)), lines[i], start, offs[i + 1]
        i += 1

norm = lambda t: re.sub(r'\s+', ' ', t.strip())

def main():
    files = sorted(p for p in pathlib.Path('src/dol').rglob('*.c') if 'typedef struct _GXData' in p.read_text())
    votes = collections.defaultdict(collections.Counter); text_of = {}; per_file = {}
    for p in files:
        bl = [(n, t, s, e) for n, t, s, e in blocks(p.read_text()) if n]
        per_file[p] = bl
        for n, t, s, e in bl:
            votes[n][norm(t)] += 1; text_of.setdefault((n, norm(t)), t)
    best = {n: c.most_common(1)[0][0] for n, c in votes.items()}
    base = max(files, key=lambda p: len(per_file[p]))
    order = [n for n, *_ in per_file[base]]
    for p in files:
        for n, *_ in per_file[p]:
            if n not in order: order.append(n)
    seen = set(); body = []
    for n in order:
        if n in seen: continue
        seen.add(n); body.append(text_of[(n, best[n])].rstrip('\n'))
    hdr = ('#ifndef DOLPHIN_GX_GXPRIV_H\n#define DOLPHIN_GX_GXPRIV_H\n/* Private GX types shared by the GX library translation units (SDK layout). */\n'
           '#include <types.h>\n\n' + '\n\n'.join(body) + '\n\nextern GXData *const gx;\n\n#endif\n')
    ok, skip = [], []
    for p in files:
        bl = per_file[p]
        if any(norm(t) != best[n] for n, t, s, e in bl):
            skip.append(p); continue
        t = p.read_text()
        for n, tt, s, e in sorted(bl, key=lambda x: -x[2]):
            t = t[:s] + t[e:]
        t = re.sub(r'^\s*extern\s+GXData\s*\*\s*const\s+gx\s*;\s*\n', '', t, flags=re.M)
        lines = t.splitlines(keepends=True)
        k = max((i for i, l in enumerate(lines[:20]) if l.startswith('#include')), default=-1)
        lines.insert(k + 1, '#include <dolphin/gx/GXPriv.h>\n')
        ok.append((p, re.sub(r'\n{3,}', '\n\n', ''.join(lines))))
    print('files', len(files), 'types', len(order), 'converted', len(ok), 'variant files kept', [str(p) for p in skip])
    if '--apply' in sys.argv:
        hp = pathlib.Path('include/dolphin/gx/GXPriv.h'); hp.parent.mkdir(parents=True, exist_ok=True); hp.write_text(hdr)
        for p, t in ok: p.write_text(t)
        print('written', hp)

if __name__ == '__main__':
    main()
