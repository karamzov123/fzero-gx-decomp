#!/usr/bin/env python3
"""Collapse DOL TUs of the draft map whose units are all C and belong only to that TU.

  tu_batch.py [--apply] [--jobs N] [TU_FILE...]

The units' files are merged in address order and tried through tu_try.py under each compiler the
units already use and a short list of TU-wide flags. A TU is applied only when every function keeps
its bytes and relocations in every region its units share, and no region loses C coverage.
A repeated declaration that conflicts is dropped (a definition wins); tu_try.py then proves the code.
Afterwards run `ninja build/GFZE01/config.json`, configure again, and gate.sh: the hash is the proof.
"""
import collections, concurrent.futures, json, os, pathlib, re, shlex, subprocess, sys, tempfile
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import apply_smart_dol_mm as smart, devprobe as d

WORK = pathlib.Path('.fzgx/tu_collapse/tmp').resolve()
WORK.mkdir(parents=True, exist_ok=True)
tempfile.tempdir = str(WORK)
os.environ['TMPDIR'] = str(WORK)

FLAGS = ['', '-inline on,noauto', '-use_lmw_stmw on', '-inline on,noauto -use_lmw_stmw on',
         '-sdata 0 -sdata2 0', '-sdata 0 -sdata2 0 -use_lmw_stmw on',
         '-sdata 0 -sdata2 0 -inline on,noauto -use_lmw_stmw on']
TRY = 'tools/consolidate/tu_try.py'


def candidates():
    m = json.load(open('state/tumap/GFZE01_main.json'))
    tu_of = {f: t['file'] for t in m['tus'] for f in t['functions']}
    lib = {t['file']: t.get('lib') or 'game' for t in m['tus']}
    sym = {}
    for line in open('config/GFZE01/symbols.txt'):
        p = line.split()
        if len(p) > 2 and p[2].startswith('.text:0x'):
            sym[p[0]] = int(p[2][8:-1], 16)
    per = collections.defaultdict(list)
    for u in json.load(open('config/GFZE01/units.json')):
        if u.get('module') != 'main' or u.get('data'):
            continue
        tus = {tu_of[n] for n in u['symbols'] if n in tu_of}
        if len(tus) == 1:
            per[tus.pop()].append(u)
        else:
            for t in tus:
                per[t].append(None)     # a unit that crosses a boundary: not this pass
    out = {}
    for tu, us in per.items():
        if len(us) < 2 or None in us or any(u.get('asm') for u in us):
            continue
        us.sort(key=lambda u: min(sym[n] for n in u['symbols'] if n in sym))
        out[tu] = (us, lib[tu])
    return out


def destination(tu, us, library):
    for u in us:
        if pathlib.PurePath(u['source']).name == tu:
            return u['source']
    dest = f'dol/{library}/{tu}'
    return dest if not pathlib.Path('src', dest).exists() else None


def first_error(text, mv, cf):
    """(line, redeclared name or None) of the first compile error; None when the text compiles."""
    with tempfile.TemporaryDirectory() as td:
        path = pathlib.Path(td, 'c.c'); path.write_text(text)
        r = subprocess.run(['build/tools/wibo', f'build/compilers/{mv}/mwcceppc.exe'] + shlex.split(cf) +
                           ['-maxerrors', '1', '-c', str(path), '-o', str(path) + '.o'], capture_output=True, text=True)
    if r.returncode == 0:
        return None
    line = re.search(r'^#\s+(\d+):', r.stdout, re.M)
    name = re.search(r"identifier '(\w+)[^']*' redeclared", r.stdout)
    return int(line.group(1)) if line else 0, name.group(1) if name else None


DEFN = re.compile(r'^((?:static\s+)?(?:inline\s+)?[A-Za-z_][\w\s*]*?\b(\w+)\s*\([^;{}]*\))\s*\{', re.M)


def unify_prototypes(text):
    """Every declaration of a function the TU defines takes the definition's form: the first is rewritten, the rest go."""
    heads = {}
    for m in DEFN.finditer(text):
        if m.group(2) not in ('if', 'for', 'while', 'switch', 'return', 'sizeof'):
            heads.setdefault(m.group(2), ' '.join(m.group(1).split()))
    lines, seen = text.splitlines(), set()
    out = []
    for line in lines:
        m = re.match(r'^\s*(?!return\b)(?:extern\s+)?[A-Za-z_][\w\s*]*?\b(\w+)\s*\([^;{}]*\)\s*;\s*$', line)
        if m and m.group(1) in heads and not heads[m.group(1)].startswith(('static', 'inline')):
            if m.group(1) in seen:
                continue
            seen.add(m.group(1)); out.append(heads[m.group(1)] + ';'); continue
        out.append(line)
    return '\n'.join(out) + '\n'


def reconcile(text, mv, cf):
    """Drop repeated declarations until the merged text compiles, or return None."""
    text = unify_prototypes(text)
    for _ in range(80):
        err = first_error(text, mv, cf)
        if err is None:
            return text
        line, name = err
        if not name or not line:
            return None
        lines = text.splitlines()
        here = lines[line - 1]
        if re.match(r'\s*extern\b', here) and here.rstrip().endswith(';'):
            del lines[line - 1]
        else:
            decl = re.compile(rf'^\s*(?:extern\s+)?[\w\s*]+\b{name}\s*(?:\(.*\)|\[.*\])?\s*;')
            found = [i for i in range(line - 1) if decl.match(lines[i])]
            if not found:
                return None
            for i in reversed(found):
                del lines[i]
        text = '\n'.join(lines) + '\n'
    return None


def attempt(tu, us, nu):
    srcs = [u['source'] for u in us]
    text = smart.merge_c_files_smart(srcs)
    text = reconcile(text, *nu['src/' + srcs[0]])
    if text is None:
        return None, None, '', 'declarations do not reconcile'
    with tempfile.TemporaryDirectory() as td:
        path = pathlib.Path(td, 'candidate.c'); path.write_text(text)
        firsts = list({u.get('mw_version'): u for u in us}.values())
        last = ''
        for first in firsts:
            order = [first['source']] + [s for s in srcs if s != first['source']]
            for flags in FLAGS:
                cmd = ['python3', TRY, str(path), '--units', ','.join(order)]
                if flags:
                    cmd += ['--extra', flags]
                r = subprocess.run(cmd, capture_output=True, text=True)
                last = (r.stdout.strip().splitlines() or r.stderr.strip().splitlines() or ['no output'])[-1]
                if r.returncode == 0 and last.startswith('IDENTICAL'):
                    return order, flags, text, last
    return None, None, text, last


def main():
    args = sys.argv[1:]
    apply = '--apply' in args
    jobs = int(args[args.index('--jobs') + 1]) if '--jobs' in args else 8
    only = {a for i, a in enumerate(args) if not a.startswith('--') and (i == 0 or args[i - 1] != '--jobs')}
    todo = {t: v for t, v in candidates().items() if not only or t in only}
    nu = d.ninja_units()
    with concurrent.futures.ThreadPoolExecutor(jobs) as pool:
        results = dict(zip(todo, pool.map(lambda t: attempt(t, todo[t][0], nu), todo)))
    done = 0
    for tu, (order, flags, text, last) in sorted(results.items()):
        us, library = todo[tu]
        print(f"{'OK ' if order else 'no '} {tu}: {len(us)} units [{flags}] {last[:90]}")
        if not order or not apply:
            continue
        dest = destination(tu, us, library)
        if dest is None:
            print('    destination exists'); continue
        pathlib.Path('src', dest).parent.mkdir(parents=True, exist_ok=True)
        with tempfile.TemporaryDirectory() as td:
            path = pathlib.Path(td, 'candidate.c'); path.write_text(text)
            cmd = ['python3', TRY, str(path), '--units', ','.join(order), '--apply', '--as', dest]
            if flags:
                cmd += ['--extra', flags]
            r = subprocess.run(cmd, capture_output=True, text=True)
        tail = r.stdout.strip().splitlines()[-1] if r.stdout.strip() else r.stderr[-200:]
        print('    ', tail)
        done += r.returncode == 0 and tail.startswith('applied')
    print('collapsed', done, 'of', len(todo))


if __name__ == '__main__':
    main()
