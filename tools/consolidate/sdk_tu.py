#!/usr/bin/env python3
"""Collapse mapped DOL translation units in state/tumap/GFZE01_main.json.

Generalized version of gx_tu.py for any DOL library (os, si, exi, db, mtx, dvd, vi, pad,
ai, ar, ax, mix, dsp, card, thp, perf, runtime, trk, etc.).

For each TU, finds all non-asm, non-data units whose symbols belong strictly to that TU,
merges contiguous .text runs via apply_smart_dol_mm.merge_c_files_smart, and proves every
function keeps identical instruction bytes and relocations across all common matching_for
regions via tu_try.py. When an entire TU collapses into one unit, places it at
dol/<subdir>/<TU>.c (when --subdir is given or lib is a known SDK dir).

Usage: sdk_tu.py [--apply] [--lib LIB ...] [TU.c ...]
"""
import argparse, importlib.util, json, os, pathlib, re, shlex, subprocess, sys, tempfile

HERE = pathlib.Path(__file__).parent
sys.path.insert(0, str(HERE)); sys.path.insert(0, 'tools')
import devprobe as d

spec = importlib.util.spec_from_file_location('sm', str(HERE / 'apply_smart_dol_mm.py'))
assert spec and spec.loader
sm = importlib.util.module_from_spec(spec); spec.loader.exec_module(sm)
ROOT = pathlib.Path.cwd()

LIB_SUBDIR = {
    'os': 'os', 'si': 'si', 'exi': 'exi', 'db': 'db', 'mtx': 'mtx',
    'dvd': 'dvd', 'vi': 'vi', 'pad': 'pad', 'ai': 'ai', 'ar': 'ar',
    'ax': 'ax', 'mix': 'mix', 'dsp': 'dsp', 'card': 'card', 'gx': 'gx',
    'thp': 'thp', 'perf': 'perf',
}


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
    code = re.sub(r'^/\* --- \S+ --- \*/\n', '', code, flags=re.M)
    return re.sub(r'\n{3,}', '\n\n', code)


def merge(srcs):
    return tidy(sm.merge_c_files_smart(srcs))


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


def attempt(srcs, dest, nu, apply):
    code = merge(srcs)
    err = first_error(code, srcs[0], nu)
    if err:
        return False, 'compile: ' + err
    with tempfile.NamedTemporaryFile('w', suffix='.c', delete=False) as f:
        f.write(code)
    first = None
    try:
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
    ap = argparse.ArgumentParser()
    ap.add_argument('tus', nargs='*')
    ap.add_argument('--lib', action='append', default=[])
    ap.add_argument('--apply', action='store_true')
    a = ap.parse_args()
    tumap = json.load(open('state/tumap/GFZE01_main.json'))
    by_file = {t['file']: t for t in tumap['tus']}
    if a.tus:
        tus = a.tus
    elif a.lib:
        tus = [t['file'] for t in tumap['tus'] if t.get('lib') in a.lib]
    else:
        tus = [t['file'] for t in tumap['tus'] if t.get('lib') in LIB_SUBDIR and t.get('lib') != 'gx']
    total = 0
    whole_done = []
    for tu in tus:
        units = json.load(open('config/GFZE01/units.json'))
        splits = open('config/GFZE01/splits.txt').read()
        nu = d.ninja_units()
        rows = [r for r in tu_units(tu, tumap, units, splits) if 'src/' + r[2] in nu]
        if len(rows) < 2:
            continue
        fns = {f for t in tumap['tus'] if t['file'] == tu for f in t['functions']}
        crossing = any(set(u['symbols']) & fns and set(u['symbols']) - fns for u in units if not u.get('data'))
        has_asm = any(u.get('asm') and set(u['symbols']) & fns for u in units)
        whole = not crossing and not has_asm and len(list(runs(rows))) == 1
        subdir = LIB_SUBDIR.get(by_file[tu].get('lib', ''), '')
        for run in runs(rows):
            lo = 0
            while lo < len(run) - 1:
                for hi in range(len(run), lo + 1, -1):
                    srcs = [r[2] for r in run[lo:hi]]
                    is_tu = whole and hi - lo == len(rows) and subdir
                    dest = f'dol/{subdir}/{tu}' if is_tu else srcs[0]
                    ok, msg = attempt(srcs, dest, nu, a.apply)
                    if ok:
                        total += len(srcs) - 1
                        print(f'{tu}: {len(srcs)} units -> 1 ({dest}) [{msg}]', flush=True)
                        if is_tu:
                            whole_done.append(tu)
                        lo = hi - 1
                        break
                    if hi == len(run):
                        print(f'{tu}: run of {len(srcs)} from {srcs[0]}: {msg}', flush=True)
                lo += 1
    print(f'units retired: {total}; whole TUs: {len(whole_done)} ({whole_done})')


if __name__ == '__main__':
    main()
