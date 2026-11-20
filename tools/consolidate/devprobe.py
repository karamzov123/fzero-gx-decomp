"""Probe pragma compiler-diff devices: remove a device's pragma lines, compile the owning unit
before/after with its exact build.ninja flags, report byte-identical objects."""
import json, re, shlex, subprocess, sys, pathlib, tempfile, itertools, concurrent.futures
sys.path.insert(0, 'tools')
from fzgx import tufile
ROOT = pathlib.Path('.')
MARK = re.compile(r'WARNING: (compiler-diff )?device')

def ninja_units():
    txt = pathlib.Path('build.ninja').read_text().replace('$\n', '')
    res = {}
    for st in re.split(r'\n(?=build )', txt):
        m = re.match(r'build (.*?):\s+(mwcc_batch|mwcc_pool|mwcc_sjis|mwcc)\s(.*?)(?:\||\n)', st)
        if not m: continue
        kv = dict(re.findall(r'\n\s+(\w+) = (.*)', st))
        ins = [x for x in m.group(3).split() if x.endswith('.c')]
        for i in ins:
            res[i] = (kv.get('mw_version'), kv.get('cflags'))
    return res

VERSIONS = ('GFZE01', 'GFZJ01', 'GFZP01')

def versions_of(unit):
    return [v for v in VERSIONS if v in (unit.get('matching_for') or VERSIONS)]

def compile_all(code, mv, cflags, td, unit):
    """Objects for every region the unit builds for (flags differ only in -DVERSION_*)."""
    out = []
    for v in versions_of(unit):
        out.append(compile_text(code, mv, cflags.replace('-DVERSION_GFZE01', f'-DVERSION_{v}').replace('build/GFZE01/include', f'build/{v}/include'), td))
    return out

def compile_text(code, mv, cflags, td):
    cp = pathlib.Path(td) / 'u.c'; op = pathlib.Path(td) / 'u.o'
    cp.write_text(code)
    if op.exists(): op.unlink()
    cmd = ['build/tools/wibo', f'build/compilers/{mv}/mwcceppc.exe'] + shlex.split(cflags) + ['-c', str(cp), '-o', str(op)]
    r = subprocess.run(cmd, capture_output=True, text=True)
    return op.read_bytes() if r.returncode == 0 and op.exists() else None

def strip_pragmas(body, opts):
    """Remove `#pragma O off/on/N` setters and their `reset` for each O in opts; remove push/pop pair if
    nothing else remains between them."""
    out = body
    for o in opts:
        out, n1 = re.subn(rf'^[ \t]*#pragma\s+{o}\s+(?:off|on|\d+)[ \t]*\n', '', out, count=1, flags=re.M)
        out, n2 = re.subn(rf'^[ \t]*#pragma\s+{o}\s+reset[ \t]*\n', '', out, count=1, flags=re.M)
        if not n1: return None
    # orphan push/pop: drop a push with matching pop if no pragma between
    out = re.sub(r'^[ \t]*#pragma push[ \t]*\n((?:(?!#pragma).*\n)*?)^[ \t]*#pragma pop[ \t]*\n', r'\1', out, flags=re.M)
    return out

def sites():
    for p in sorted(itertools.chain(ROOT.glob('src/**/*.c'))):
        t = p.read_text()
        if not MARK.search(t): continue
        lines = t.splitlines(keepends=True)
        for i, ln in enumerate(lines):
            if not MARK.search(ln): continue
            # pragmas within the 8 lines after the marker (stopping at a function/brace line)
            opts = []
            for ln2 in lines[i:i+10]:
                m = re.match(r'\s*#pragma\s+(opt_\w+|fp_contract|peephole|optimization_level|scheduling)\s+(off|on|\d+)\s*$', ln2)
                if m: opts.append(m.group(1))
                if re.match(r'^\w.*\)\s*\{?\s*$', ln2) and not ln2.startswith('#'): break
            if opts: yield p, i, opts

def unit_for(p, line_no, units_by_tu, units_by_src):
    rel = str(p.relative_to('src'))
    if rel in units_by_tu:
        tf = tufile.parse(p.read_text())
        # block containing line
        text = p.read_text(); pos = sum(len(l) for l in text.splitlines(keepends=True)[:line_no])
        for m in re.finditer(r'/\* fzgx:begin (\w+)[^*]*\*/\n(.*?)/\* fzgx:end \1 \*/', text, re.S):
            if m.start() <= pos < m.end():
                name = m.group(1)
                for u in units_by_tu[rel]:
                    if name in u['symbols']: return ('tu', u, name, m.start(2), m.end(2))
        return None
    if rel in units_by_src: return ('file', units_by_src[rel], None, None, None)
    return None

def probe(task):
    p, i, opts, kind, u, name, bs, be, mv, cf = task
    text = p.read_text()
    lines = text.splitlines(keepends=True)
    pos = sum(len(l) for l in lines[:i])
    def gen(t):
        if kind == 'file': return t
        return tufile.units_gen_text(tufile.parse(t), u['symbols'])
    def variant(sub_opts):
        # strip from the marker position to the end of its block (or file)
        end = be if kind == 'tu' else len(text)
        seg = strip_pragmas(text[pos:end], sub_opts)
        return None if seg is None else text[:pos] + seg + text[end:]
    with tempfile.TemporaryDirectory(prefix='devp_') as td:
        base = compile_text(gen(text), mv, cf, td)
        if base is None: return (p, i, opts, 'BASE-FAIL')
        res = []
        subsets = [opts] + ([[o] for o in opts] if len(opts) > 1 else [])
        for so in subsets:
            v = variant(so)
            if v is None: res.append((so, 'nostrip')); continue
            o = compile_text(gen(v), mv, cf, td)
            res.append((so, 'SAME' if o == base else ('fail' if o is None else 'diff')))
        return (p, i, opts, res)

def main():
    units = json.load(open('config/GFZE01/units.json'))
    by_tu, by_src = {}, {}
    for u in units:
        if u.get('tu'): by_tu.setdefault(u['tu'], []).append(u)
        else: by_src[u['source']] = u
    nu = ninja_units()
    tasks = []
    for p, i, opts in sites():
        r = unit_for(p, i, by_tu, by_src)
        if not r: print('nounit', p, i + 1, opts); continue
        kind, u, name, bs, be = r
        key = f"build/GFZE01/gen/{u['source']}" if kind == 'tu' else f"src/{u['source']}"
        if key not in nu: print('noninja', key); continue
        mv, cf = nu[key]
        tasks.append((p, i, opts, kind, u, name, bs, be, mv, cf))
    with concurrent.futures.ProcessPoolExecutor(8) as ex:
        for p, i, opts, res in ex.map(probe, tasks):
            print(f'{p}:{i+1} {opts} -> {res}', flush=True)

if __name__ == "__main__":
    main()
