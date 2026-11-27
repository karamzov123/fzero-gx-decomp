#!/usr/bin/env python3
"""Collapse the TUs of a REL module whose units are standalone files (movie_module, profile).

  rel_tu_batch.py MODULE --recut [--apply] [TU_FILE...]
  rel_tu_batch.py MODULE [--apply] [--jobs N] [TU_FILE...]

TUs come from config/GFZE01/MODULE/tus.json. --recut cuts every .text-only unit that crosses a TU
boundary into one piece per TU (tu_cut.py), checks each piece against the old unit's object
(tu_try.py --functions: identical bytes and relocations, pool map re-derived from the matching
sites) and replaces the unit with its pieces (tu_recut.py). Without --recut, the units of each TU
are merged as tu_batch.py does for the DOL (declarations reconciled, compiler and TU-wide flags
tried, tu_try.py decides) and written to src/rel/MODULE/<tu>.c. Asm units and units with data
splits are left alone. Afterwards configure and run gate.sh: the link hash is the proof.
"""
import collections, concurrent.futures, json, pathlib, re, subprocess, sys, tempfile
sys.path.insert(0, str(pathlib.Path(__file__).parent))
import tu_batch, devprobe as d

TRY, CUT, RECUT = 'tools/consolidate/tu_try.py', 'tools/consolidate/tu_cut.py', 'tools/consolidate/tu_recut.py'


def load(module):
    tus = json.load(open(f'config/GFZE01/{module}/tus.json'))
    tu_of = {f: t['file'] for t in tus['tus'] for f in t['functions']}
    addr, size = {}, {}
    for line in open(f'config/GFZE01/{module}/symbols.txt'):
        m = re.match(r'(\S+) = \.text:0x(\w+); // type:function size:0x(\w+)', line)
        if m:
            addr[m[1]], size[m[1]] = int(m[2], 16), int(m[3], 16)
    splits = open(f'config/GFZE01/{module}/splits.txt').read()
    blocks = {m.group(1): m.group(2) for m in re.finditer(r'^(\S+\.c):\n((?:\t.*\n)*)', splits, re.M)}
    units = [u for u in json.load(open('config/GFZE01/units.json')) if u['module'] == module and not u.get('data')]
    return tu_of, addr, blocks, units


def text_only(u, blocks):
    return re.findall(r'\t(\.\w+)', blocks.get(u['source'], '')) == ['.text'] and not u.get('asm')


def recut(module, apply, only):
    tu_of, addr, blocks, units = load(module)
    done = 0
    for u in units:
        names = sorted(u['symbols'], key=addr.get)
        runs = []
        for n in names:
            t = tu_of.get(n, '_prolog.c')
            if runs and runs[-1][0] == t:
                runs[-1][1].append(n)
            else:
                runs.append((t, [n]))
        if len(runs) < 2 or (only and not only & {t for t, _ in runs}):
            continue
        if len({t for t, _ in runs}) != len(runs):
            print('no ', u['source'], 'interleaves TUs'); continue
        if not text_only(u, blocks):
            print('no ', u['source'], 'has data splits or is asm'); continue
        hi_text = int(re.search(r'\.text\s+start:0x\w+ end:0x(\w+)', blocks[u['source']])[1], 16)
        td = tempfile.mkdtemp(dir=tu_batch.WORK)
        new, ok = [], True
        for k, (t, fs) in enumerate(runs):
            cand = pathlib.Path(td, f'p{k}.c')
            r = subprocess.run(['python3', CUT, 'src/' + u['source'], str(cand)] + fs, capture_output=True, text=True)
            if r.returncode:
                print('no ', u['source'], 'cut failed', r.stderr[-200:]); ok = False; break
            r = subprocess.run(['python3', TRY, str(cand), '--units', u['source'], '--functions', ','.join(fs)],
                               capture_output=True, text=True)
            last = (r.stdout.strip().splitlines() or ['no output'])[-1]
            if r.returncode or not last.startswith('IDENTICAL'):
                print('no ', u['source'], t, last[:100]); ok = False; break
            pool = next((json.loads(l[5:]) for l in r.stdout.splitlines() if l.startswith('POOL ')), None)
            lo = addr[fs[0]]
            hi = addr[runs[k + 1][1][0]] if k + 1 < len(runs) else hi_text
            src = u['source'] if k == 0 else f'rel/{module}/{fs[0]}.c'
            if k and pathlib.Path('src', src).exists():
                print('no ', u['source'], src, 'exists'); ok = False; break
            entry = {'source': src, 'candidate': str(cand), 'lo': f'{lo:08X}', 'hi': f'{hi:08X}',
                     'version': u.get('mw_version'), 'flags': u.get('extra_cflags') or [],
                     'collapsed': bool(u.get('collapsed'))}
            if u.get('matching_for'):
                entry['regions'] = u['matching_for']
            if pool:
                entry['pool'] = pool
            elif u.get('pool') and pool is None:
                print('no ', u['source'], t, 'pool map not derived'); ok = False; break
            new.append(entry)
        if not ok:
            continue
        print('OK ', u['source'], '->', [(e['source'], t) for e, (t, _) in zip(new, runs)])
        if apply:
            spec = pathlib.Path(td, 'spec.json'); spec.write_text(json.dumps({'old': [u['source']], 'new': new}))
            r = subprocess.run(['python3', RECUT, str(spec)], capture_output=True, text=True)
            print('    ', (r.stdout.strip() or r.stderr.strip())[-200:])
            done += r.returncode == 0
    print('recut', done)


def merge(module, apply, only, jobs):
    tu_of, addr, blocks, units = load(module)
    per = collections.defaultdict(list)
    for u in units:
        tus = {tu_of.get(n, '_prolog.c') for n in u['symbols']}
        if len(tus) == 1:
            per[tus.pop()].append(u)
        else:
            for t in tus:
                per[t].append(None)
    todo = {}
    for tu, us in per.items():
        if (only and tu not in only) or tu == '_prolog.c' or len(us) < 2:
            continue
        if None in us or any(not text_only(u, blocks) for u in us):
            print('skip', tu, 'crossing, asm or data units'); continue
        todo[tu] = sorted(us, key=lambda u: min(addr[n] for n in u['symbols']))
    nu = d.ninja_units()
    with concurrent.futures.ThreadPoolExecutor(jobs) as pool:
        results = dict(zip(todo, pool.map(lambda t: tu_batch.attempt(t, todo[t], nu), todo)))
    done = 0
    for tu, (order, flags, text, last) in sorted(results.items()):
        print(f"{'OK ' if order else 'no '} {tu}: {len(todo[tu])} units [{flags}] {last[:90]}")
        if not order or not apply:
            continue
        dest = f'rel/{module}/{tu}'
        if pathlib.Path('src', dest).exists() and dest not in [u['source'] for u in todo[tu]]:
            print('    destination exists'); continue
        with tempfile.TemporaryDirectory(dir=tu_batch.WORK) as td:
            path = pathlib.Path(td, 'candidate.c'); path.write_text(text)
            cmd = ['python3', TRY, str(path), '--units', ','.join(order), '--apply', '--as', dest]
            if flags:
                cmd += ['--extra', flags]
            r = subprocess.run(cmd, capture_output=True, text=True)
        tail = r.stdout.strip().splitlines()[-1] if r.stdout.strip() else r.stderr[-200:]
        print('    ', tail)
        done += r.returncode == 0 and tail.startswith('applied')
    print('collapsed', done, 'of', len(todo))


def main():
    args = sys.argv[1:]
    module = args[0]
    jobs = int(args[args.index('--jobs') + 1]) if '--jobs' in args else 8
    only = {a for i, a in enumerate(args[1:], 1) if not a.startswith('--') and args[i - 1] != '--jobs'}
    if '--recut' in args:
        recut(module, '--apply' in args, only)
    else:
        merge(module, '--apply' in args, only, jobs)


if __name__ == '__main__':
    main()
