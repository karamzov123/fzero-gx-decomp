"""Retire `noprologue` flags: per unit, replace a noprologue block by its prologue-deduped form
when the unit's compiled object stays semantically identical (sections, relocations, defined
symbols). Usage: nopro_retire.py [--apply]"""
import json, re, sys, pathlib, tempfile, subprocess, shlex, concurrent.futures, collections, importlib.util
SD = str(pathlib.Path(__file__).parent)
sys.path.insert(0, SD); sys.path.insert(0, 'tools')
import devprobe as d, objsig
from fzgx import tufile
spec = importlib.util.spec_from_file_location('np', str(pathlib.Path(__file__).with_name('apply_nopro_smart.py')))
np = importlib.util.module_from_spec(spec); spec.loader.exec_module(np)
FIXERS = []  # optional body rewriters: f(fn, body, prologue_text) -> body or None

def compile_sig(code, mv, cf, td):
    cp = pathlib.Path(td) / 'u.c'; op = pathlib.Path(td) / 'u.o'
    cp.write_text(code)
    if op.exists(): op.unlink()
    r = subprocess.run(['build/tools/wibo', f'build/compilers/{mv}/mwcceppc.exe'] + shlex.split(cf) + ['-c', str(cp), '-o', str(op)], capture_output=True, text=True)
    return objsig.sig(op) if r.returncode == 0 and op.exists() else None

def gen(tf, syms):
    return tufile.units_gen_text(tf, syms)

import declfix
MVCF = {}
TYPEDEF_RE = re.compile(r'typedef\s+(?:struct|union|enum)\b[^{;]*\{[^{}]*\}\s*\w+\s*;')

def drop_identical_typedefs(body, pro):
    """Drop a block's typedef that the prologue already defines with identical text: an anonymous
    struct typedef defined twice is two distinct types, which renaming cannot reconcile."""
    norm = lambda t: re.sub(r'\s+', ' ', re.sub(r'//[^\n]*|/\*.*?\*/', '', t, flags=re.S)).strip()
    known = {norm(m.group(0)) for m in TYPEDEF_RE.finditer(pro)}
    return TYPEDEF_RE.sub(lambda m: '' if norm(m.group(0)) in known else m.group(0), body)

def candidates(fn, body, pro, info):
    incs, tags, tdefs, exts = info
    c = np.clean_block_for_prologue(fn, body, incs, tags, tdefs, exts)
    yield c
    d0 = drop_identical_typedefs(body, pro)
    if d0 != body:
        c1 = np.clean_block_for_prologue(fn, d0, incs, tags, tdefs, exts)
        if c1 != c: yield c1
    if '--fix' in sys.argv and MVCF:
        mv, cf = MVCF['v']
        c2 = np.clean_block_for_prologue(fn, body, incs, tags, tdefs, set())  # keep externs: fixer decides
        for r in declfix.fix(pro, c2, mv, cf):
            if r != c: yield r

def process(task):
    tu, u, (mv, cf) = task
    MVCF['v'] = (mv, cf)
    text = pathlib.Path('src', tu).read_text()
    tf = tufile.parse(text)
    info = np.parse_prologue_info(tf.prologue)
    with tempfile.TemporaryDirectory(prefix='npr_') as td:
        base0 = compile_sig(gen(tf, u['symbols']), mv, cf, td)
        if base0 is None: return (tu, u['source'], [], 'BASE-FAIL')
        base, baseloc = objsig.canon(base0)
        lastloc = baseloc
        accepted = []
        # 1. every noprologue block of the unit at once (the prologue then leads the whole unit)
        nps = [tf.get(fn) for fn in u['symbols'] if tf.get(fn) is not None and 'noprologue' in tf.get(fn).flags]
        saved = [(b.body, list(b.flags)) for b in nps]
        for b in nps:
            b.body = next(candidates(b.name, b.body, tf.prologue, info))
            b.flags = [f for f in b.flags if f != 'noprologue']
        s0 = compile_sig(gen(tf, u['symbols']), mv, cf, td)
        s, loc = objsig.canon(s0) if s0 else (None, None)
        if s == base and len(nps) > 1:
            inv = {v: k for k, v in loc.items()}
            rename = {old: inv[l] for old, l in baseloc.items() if inv.get(l, old) != old}
            return (tu, u['source'], [(b.name, b.body) for b in nps], 'ok', rename)
        for b, (bd, fl) in zip(nps, saved):
            b.body, b.flags = bd, fl
        # 2. one block at a time
        for fn in u['symbols']:
            b = tf.get(fn)
            if b is None or 'noprologue' not in b.flags: continue
            old = (b.body, list(b.flags))
            ok = False
            for cand in candidates(fn, b.body, tf.prologue, info):
                b.body = cand.rstrip('\n') + '\n' if b.body.endswith('\n') else cand.rstrip('\n')
                b.flags = [f for f in old[1] if f != 'noprologue']
                s0 = compile_sig(gen(tf, u['symbols']), mv, cf, td)
                s, loc = objsig.canon(s0) if s0 else (None, None)
                if s == base:
                    ok = True; accepted.append((fn, b.body)); lastloc = loc; break
            if not ok:
                b.body, b.flags = old
        inv = {v: k for k, v in lastloc.items()}
        rename = {old: inv[l] for old, l in baseloc.items() if inv.get(l, old) != old}
        return (tu, u['source'], accepted, 'ok', rename)

def main():
    apply = '--apply' in sys.argv
    only = [a for a in sys.argv[1:] if not a.startswith('--')]
    units = json.load(open('config/GFZE01/units.json'))
    nu = d.ninja_units()
    tasks = []
    for u in units:
        if not u.get('tu') or (only and u['tu'] not in only): continue
        txt = pathlib.Path('src', u['tu']).read_text()
        if not any(re.search(rf'/\* fzgx:begin {fn} noprologue \*/', txt) for fn in u['symbols']): continue
        key = f"build/GFZE01/gen/{u['source']}"
        if key in nu: tasks.append((u['tu'], u, nu[key]))
    print(len(tasks), 'units with noprologue blocks', flush=True)
    results = []
    with concurrent.futures.ProcessPoolExecutor(12) as ex:
        for r in ex.map(process, tasks):
            results.append(r)
    tot = sum(len(r[2]) for r in results)
    print('retirable blocks:', tot, 'base-fail units:', sum(1 for r in results if r[3] != 'ok'))
    by_tu = collections.defaultdict(list)
    for tu, src, acc, st, *_ in results:
        for fn, body in acc: by_tu[tu].append((fn, body))
    for tu, acc in sorted(by_tu.items(), key=lambda x: -len(x[1]))[:15]: print(f'  {len(acc):4d} {tu}')
    if not apply: return
    for tu, acc in by_tu.items():
        p = pathlib.Path('src', tu); txt = p.read_text()
        for fn, body in acc:
            pat = re.compile(rf'^/\* fzgx:begin {fn}((?: [a-z]+)*) \*/\n.*?^/\* fzgx:end {fn} \*/$', re.S | re.M)
            m = pat.search(txt); assert m and 'noprologue' in m.group(1).split(), fn
            flags = ''.join(' ' + f for f in m.group(1).split() if f != 'noprologue')
            body = body if body.endswith('\n') else body + '\n'
            txt = txt[:m.start()] + f'/* fzgx:begin {fn}{flags} */\n' + body + f'/* fzgx:end {fn} */' + txt[m.end():]
        p.write_text(txt)
    print('applied', tot)

if __name__ == '__main__':
    main()
