#!/usr/bin/env python3
"""Collapse GX library TUs (draft DOL TU map) onto the shared GX headers.

Each unit is rewritten by gx_unify, the units of a contiguous run are merged, and tu_try.py proves
every function keeps its instruction bytes and relocations in every region. The whole TU is tried
first, then its longest contiguous runs.

  gx_tu.py [--apply] [TU.c ...]      default: every GX TU in state/tumap/GFZE01_main.json
"""
import argparse, importlib.util, json, os, pathlib, re, shlex, subprocess, sys, tempfile

HERE = pathlib.Path(__file__).parent
sys.path.insert(0, str(HERE)); sys.path.insert(0, 'tools')
import devprobe as d
import gx_unify as g

spec = importlib.util.spec_from_file_location('sm', str(HERE / 'apply_smart_dol_mm.py'))
assert spec and spec.loader
sm = importlib.util.module_from_spec(spec); spec.loader.exec_module(sm)
ROOT = pathlib.Path.cwd()


def tu_units(tu, tumap, units, splits):
    fns = {f for t in tumap['tus'] if t['file'] == tu for f in t['functions']}
    out = []
    for u in units:
        if u.get('asm') or u.get('data') or not set(u['symbols']) & fns or set(u['symbols']) - fns:
            continue
        b = re.search(rf'^{re.escape(u["source"])}:\n((?:\t.*\n)*)', splits, re.M)
        t = b and re.search(r'\.text\s+start:0x(\w+) end:0x(\w+)', b.group(1))
        if t:
            out.append((int(t.group(1), 16), int(t.group(2), 16), u['source']))
    return sorted(out)


def runs(rows):
    cur = []
    for r in rows:
        if cur and cur[-1][1] != r[0]:
            yield cur
            cur = []
        cur.append(r)
    if cur:
        yield cur


def tidy(code):
    """Drop the merge's per-file markers and repeated identical macro definitions."""
    code = re.sub(r'^/\* --- \S+ --- \*/\n', '', code, flags=re.M)
    seen = set()

    def once(m):
        k = re.sub(r'\s+', ' ', m.group(0))
        if k in seen:
            return ''
        seen.add(k)
        return m.group(0)
    code = re.sub(r'^#define\s+\w+\((?:[^\n]*\\\n)*[^\n]*\n', once, code, flags=re.M)
    return re.sub(r'\n{3,}', '\n\n', code)


def unified(src):
    """(text, rlwimi) for the first macro form under which the unit alone stays identical."""
    text = pathlib.Path('src', src).read_text()
    for rlwimi in (False, True):
        try:
            n = g.unify(text, rlwimi)
        except g.Unsupported:
            return None
        with tempfile.NamedTemporaryFile('w', suffix='.c', delete=False) as f:
            f.write(n)
        try:
            r = subprocess.run([sys.executable, str(HERE / 'tu_try.py'), f.name, '--units', src],
                               capture_output=True, text=True)
        finally:
            os.unlink(f.name)
        if r.stdout.strip().splitlines()[-1:] and r.stdout.strip().splitlines()[-1].startswith('IDENTICAL'):
            return n
    return None


def merge(srcs, texts):
    with tempfile.TemporaryDirectory() as td:
        for s in srcs:
            p = pathlib.Path(td, 'src', s); p.parent.mkdir(parents=True, exist_ok=True)
            p.write_text(texts[s])
        os.chdir(td)
        try:
            return tidy(sm.merge_c_files_smart(srcs))
        finally:
            os.chdir(ROOT)


def first_error(code, src, nu):
    mv, cf = nu['src/' + src]
    with tempfile.TemporaryDirectory() as td:
        p = pathlib.Path(td, 'c.c'); p.write_text(code)
        r = subprocess.run(['build/tools/wibo', f'build/compilers/{mv}/mwcceppc.exe'] + shlex.split(cf) +
                           ['-c', str(p), '-o', td + '/c.o'], capture_output=True, text=True)
    if r.returncode == 0:
        return None
    m = re.search(r'#\s+\d+: (.*)\n#\s+Error:.*\n#\s+(.*)\n', r.stdout)
    return f'{m.group(2)[:70]} at: {m.group(1).strip()[:60]}' if m else r.stdout[-100:]


def attempt(srcs, texts, dest, nu, apply):
    code = merge(srcs, texts)
    err = first_error(code, srcs[0], nu)
    if err:
        return False, 'compile: ' + err
    with tempfile.NamedTemporaryFile('w', suffix='.c', delete=False) as f:
        f.write(code)
    first = None
    try:
        # per-function units never exposed auto-inlining: a TU may need it off, as retail's calls show
        for extra in ([], ['--extra', '-inline on,noauto']):
            cmd = [sys.executable, str(HERE / 'tu_try.py'), f.name, '--units', ','.join(srcs)] + extra
            r = subprocess.run(cmd, capture_output=True, text=True)
            lines = (r.stdout + r.stderr).strip().splitlines()
            first = first or (lines[0][:110] if lines else '?')
            if any(x.startswith('IDENTICAL') for x in lines):
                if apply:
                    r = subprocess.run(cmd + ['--apply', '--as', dest], capture_output=True, text=True)
                    if 'applied as' not in r.stdout:
                        return False, 'apply failed: ' + (r.stdout + r.stderr).strip()[-110:]
                return True, 'noauto' if extra else 'default'
    finally:
        os.unlink(f.name)
    return False, first


def main():
    ap = argparse.ArgumentParser(); ap.add_argument('tus', nargs='*'); ap.add_argument('--apply', action='store_true')
    a = ap.parse_args()
    tumap = json.load(open('state/tumap/GFZE01_main.json'))
    tus = a.tus or sorted(t['file'] for t in tumap['tus'] if t.get('lib') == 'gx')
    total = 0
    for tu in tus:
        units = json.load(open('config/GFZE01/units.json'))
        splits = open('config/GFZE01/splits.txt').read()
        nu = d.ninja_units()
        rows = tu_units(tu, tumap, units, splits)
        if len(rows) < 2:
            continue
        texts = {r[2]: unified(r[2]) for r in rows}
        good = [r for r in rows if texts[r[2]]]
        whole = len(good) == len(rows) and len(list(runs(rows))) == 1
        for run in runs(good):
            lo = 0
            while lo < len(run) - 1:
                for hi in range(len(run), lo + 1, -1):
                    srcs = [r[2] for r in run[lo:hi]]
                    is_tu = whole and hi - lo == len(rows)
                    dest = f'dol/gx/{tu}' if is_tu else srcs[0]
                    ok, msg = attempt(srcs, texts, dest, nu, a.apply)
                    if ok:
                        total += len(srcs) - 1
                        print(f'{tu}: {len(srcs)} units -> 1 ({dest})', flush=True)
                        lo = hi - 1
                        break
                    if hi == len(run):
                        print(f'{tu}: run of {len(srcs)} from {srcs[0]}: {msg}', flush=True)
                lo += 1
    print('units retired:', total)


if __name__ == '__main__':
    main()
