"""Why do adjacent same-TU DOL units (draft TU map, same profile, .text only, unpooled) not merge?
Compiles merge_c_files_smart([a, b]) and reports the first compiler error, or the first
object difference."""
import json, re, sys, tempfile, pathlib, subprocess, shlex, collections, importlib.util, concurrent.futures
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d
spec = importlib.util.spec_from_file_location('sm', str(pathlib.Path(__file__).with_name('apply_smart_dol_mm.py')))
sm = importlib.util.module_from_spec(spec); spec.loader.exec_module(sm)


def one(task):
    a, b, mv, cf = task
    code = sm.merge_c_files_smart([a, b])
    with tempfile.TemporaryDirectory() as td:
        p = pathlib.Path(td) / 'u.c'; p.write_text(code)
        r = subprocess.run(['build/tools/wibo', f'build/compilers/{mv}/mwcceppc.exe'] + shlex.split(cf) + ['-c', str(p), '-o', td + '/u.o'], capture_output=True, text=True)
    if r.returncode == 0:
        return (a, b, 'compiles', '')
    m = re.search(r'#\s+\d+: (.*)\n#\s+Error:.*\n#   (.*)\n', r.stdout)
    kind = re.sub(r"'[^']*'", "'X'", m.group(2)) if m else '?'
    return (a, b, kind, (m.group(1)[:90] + ' || ' + m.group(2)[:120]) if m else r.stdout[-200:])


def main():
    m = json.load(open('state/tumap/GFZE01_main.json'))
    tu_of = {f: t['file'] for t in m['tus'] for f in t['functions']}
    units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units()
    sp = open('config/GFZE01/splits.txt').read()
    blocks = {mm.group(1): mm.group(2) for mm in re.finditer(r'(\S+\.c):\n((?:\t.*\n)*)', sp)}
    rows = []
    for u in units:
        if u['module'] != 'main' or u.get('data') or u.get('asm') or u.get('tu') or u.get('pool'): continue
        tus = {tu_of.get(s) for s in u['symbols']} - {None}
        secs = re.findall(r'(\.\w+)\s+start', blocks.get(u['source'], ''))
        st = re.search(r'\.text\s+start:0x(\w+) end:0x(\w+)', blocks.get(u['source'], ''))
        if len(tus) == 1 and secs == ['.text'] and st and f"src/{u['source']}" in nu:
            rows.append((int(st.group(1), 16), int(st.group(2), 16), u['source'], tus.pop(), (u.get('mw_version'), tuple(u.get('extra_cflags') or []))))
    rows.sort()
    tasks = [(a[2], b[2], *nu['src/' + a[2]]) for a, b in zip(rows, rows[1:]) if a[3] == b[3] and a[4] == b[4] and a[1] == b[0]]
    with concurrent.futures.ProcessPoolExecutor(12) as ex:
        res = list(ex.map(one, tasks))
    json.dump(res, open('.fzgx/dol_pairdiag.json', 'w'), indent=0)
    c = collections.Counter(r[2] for r in res)
    print(len(tasks), 'pairs')
    for k, v in c.most_common(12):
        print(v, k); [print('     ', r[0], r[1], r[3]) for r in res if r[2] == k][:2]


if __name__ == '__main__':
    main()
