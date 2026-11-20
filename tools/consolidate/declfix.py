"""Error-driven reconciliation of a noprologue block with its TU prologue."""
import re, pathlib, subprocess, shlex, tempfile

def decl_index(text):
    """name -> (kind, type, dims_or_params) from single-line declarations."""
    idx = {}
    for m in re.finditer(r'^[ \t]*extern\s+([^;{}()\n=]+?)\b([A-Za-z_]\w*)\s*((?:\[[^\]]*\])*)\s*;', text, re.M):
        idx.setdefault(m.group(2), ('var', m.group(1).strip(), m.group(3)))
    for m in re.finditer(r'^[ \t]*(?:extern\s+)?([A-Za-z_][^;{}()\n=]*?[\s*])([A-Za-z_]\w*)\s*\(([^;{}]*)\)\s*;', text, re.M):
        idx.setdefault(m.group(2), ('func', m.group(1).strip(), m.group(3)))
    return idx

def view_expr(name, kind, typ, extra):
    if 'struct {' in typ or 'union {' in typ or typ.startswith('enum'): return None
    if kind == 'var':
        dims = re.findall(r'\[[^\]]*\]', extra)
        if not dims: return f'(*({typ} *)&{name})'
        if dims[0] == '[]': rest = ''.join(dims[1:]); return f'(({typ} (*){rest})&{name})' if rest else f'(({typ} *)&{name})'
        return f'(*({typ} (*){"".join(dims)})&{name})'
    return f'(({typ} (*)({extra})){name})'

NO_VIEWS = True
USE = r'(?<![\w.>])(?<!->){n}\b'

def apply_view(body, name, expr, decl_line_re=None):
    out = []
    for ln in body.split('\n'):
        if re.match(rf'^\s*(?:extern\s+)?[^;(){{}}=]*\b{name}\b\s*(\[[^\]]*\]\s*)*(\([^;{{}}]*\))?\s*;\s*$', ln):
            out.append(ln); continue   # declarations stay untouched
        out.append(re.sub(USE.format(n=re.escape(name)), lambda m: expr, ln))
    return '\n'.join(out)

def compile_errs(code, mv, cf, td):
    cp = pathlib.Path(td) / 'f.c'; cp.write_text(code)
    cf = cf.replace('-maxerrors 1', '-maxerrors 1')
    r = subprocess.run(['build/tools/wibo', f'build/compilers/{mv}/mwcceppc.exe'] + shlex.split(cf) + ['-c', str(cp), '-o', str(pathlib.Path(td) / 'f.o')], capture_output=True, text=True)
    if r.returncode == 0: return None
    m = re.search(r'#\s+(\d+): (.*)\n#\s+Error:.*\n((?:#   .*\n)+)', r.stdout)
    if not m: return ('?', 0, r.stdout[-300:])
    return (m.group(3), int(m.group(1)), m.group(2))

def fix(prologue, body, mv, cf, max_iter=40):
    """Yield candidate bodies (minimal, then with views for every dropped/retyped symbol)."""
    pidx = decl_index(prologue + '\n' + ''.join(_headers(prologue)))
    dropped = {}   # name -> (kind, type, extra) of the block's own declaration
    base_lines = prologue.count('\n') + 2
    with tempfile.TemporaryDirectory(prefix='dfx_') as td:
        for _ in range(max_iter):
            e = compile_errs(prologue + '\n\n' + body + '\n', mv, cf, td)
            if e is None: break
            msg, line, src = e
            m = re.search(r"identifier '([A-Za-z_]\w*)(\(.*\))?' redeclared", msg)
            if m:
                name = m.group(1)
                bl = body.split('\n')
                hit = None
                for i, ln in enumerate(bl):
                    mm = re.match(rf'^(\s*)(extern\s+)?([^;{{}}()=\n]+?)\b{name}\s*((?:\[[^\]]*\])*)\s*(\(([^;{{}}]*)\))?\s*(=[^;]*)?;\s*$', ln)
                    if mm: hit = (i, mm); break
                if not hit: return
                i, mm = hit
                typ = mm.group(3).strip(); dims = mm.group(4); params = mm.group(6)
                if mm.group(5):                       # prototype: drop
                    dropped[name] = ('func', typ, params); del bl[i]
                elif mm.group(2):                     # extern view: drop
                    dropped[name] = ('var', typ, dims); del bl[i]
                else:                                 # definition: retype to the prologue's declaration
                    p = pidx.get(name)
                    if not p or p[0] != 'var' or mm.group(7): return
                    dropped[name] = ('var', typ, dims)
                    bl[i] = f'{mm.group(1)}{p[1]} {name}{p[2]};'
                body = '\n'.join(bl); continue
            if 'implicit conversion' in msg or 'not a struct/union/class' in msg or 'pointer/array required' in msg or 'function call' in msg or 'is not a struct/union/class member' in msg:
                if NO_VIEWS: return
                names = [n for n in dropped if re.search(USE.format(n=re.escape(n)), src)]
                names = [n for n in names if not dropped[n][0].startswith('done')]
                if not names: return
                for n in names:
                    k, t, x = dropped[n]
                    ex = view_expr(n, k, t, x)
                    if not ex: return
                    body = apply_view(body, n, ex)
                    dropped[n] = ('done-' + k, t, x)
                continue
            return
        else:
            return
        yield body
        # variant: views for every dropped symbol whose type differs from the prologue's
        if NO_VIEWS: return
        vb = body
        for n, (k, t, x) in dropped.items():
            if k.startswith('done'): continue
            p = pidx.get(n)
            if p and p[1].replace(' ', '') == t.replace(' ', '') and (p[2] or '').replace(' ', '') == (x or '').replace(' ', ''): continue
            ex = view_expr(n, k, t, x)
            if ex: vb = apply_view(vb, n, ex)
        if vb != body and compile_errs(prologue + '\n\n' + vb + '\n', mv, cf, td) is None:
            yield vb

def _headers(prologue):
    seen, q, out = set(), re.findall(r'#include\s+"([^"]+)"', prologue), []
    while q:
        h = q.pop()
        if h in seen: continue
        seen.add(h); p = pathlib.Path('include') / h
        if p.exists():
            t = p.read_text(errors='ignore'); out.append(t); q += re.findall(r'#include\s+"([^"]+)"', t)
    return out
