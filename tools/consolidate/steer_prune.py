"""Remove steering constructs that no longer change any object: `volatile` qualifiers and one-member
carriers (`struct { T value; } x;` -> `T x;`, `x.value` -> `x`).  Per block: all candidates of the
block at once, else one at a time; screen with GFZE01, confirm with every region of the unit.
Pool-primer sinks (.fzgxpool / fzgx-allow lines) are never touched.
Usage: steer_prune.py [--apply] [--kind volatile|carrier] [FILE...]"""
import sys, re, json, tempfile, pathlib, collections, concurrent.futures
sys.path.insert(0, str(pathlib.Path(__file__).parent)); sys.path.insert(0, 'tools')
import devprobe as d, pragma_prune as pp
SKIP = re.compile(r'fzgxpool|fzgx-allow|fzgx_pool|prime|\bcp\b|FIFO|Fifo|GXW|PPCWGPipe|FZGX_ADDR|0x[cC][cC]0|0xE0000000|locked|[Rr]egs\b|hardware|cursor|write offset|toggle|interrupt|callback|scratch area')
WHY = re.compile(r'volatile|reload|re-?read|[Rr]etail|[Pp]reserve|fzgx')
VOL = re.compile(r'\bvolatile\b\s*')
CARRIER = re.compile(r'struct \{ *([A-Za-z_][A-Za-z0-9_ ]*?\**) *value; *\} *([A-Za-z_]\w*);')

def candidates(text, lo, hi, kind):
    """(start, end, replacement, extra_edits) edits inside text[lo:hi]."""
    out = []
    seg = text[lo:hi]
    if kind == 'volatile':
        pos = 0
        for line in seg.splitlines(keepends=True):
            if not SKIP.search(line) and not line.lstrip().startswith(('//', '/*', '*')):
                cm = re.search(r'//|/\*', line); code_end = cm.start() if cm else len(line)
                for m in VOL.finditer(line[:code_end]):
                    g = [(lo + pos + m.start(), lo + pos + m.end(), '')]
                    if cm and WHY.search(line[cm.start():]):   # the comment explains the steering: drop it
                        end = len(line.rstrip('\n'))
                        if line[cm.start():cm.start() + 2] == '//' or line.rstrip().endswith('*/'):
                            g.append((lo + pos + len(line[:cm.start()].rstrip()), lo + pos + end, ''))
                    out.append(g)
            pos += len(line)
    else:
        for m in CARRIER.finditer(seg):
            t, name = m.group(1).strip(), m.group(2)
            edits = [(lo + m.start(), lo + m.end(), f'{t} {name};')]
            for u in re.finditer(rf'\b{name}\.value\b', seg[m.end():]):
                s = lo + m.end() + u.start(); edits.append((s, s + len(u.group(0)), name))
            out.append(edits)
    return out

def apply_edits(text, groups):
    edits = sorted({e for g in groups for e in g}, key=lambda e: -e[0])
    for s, e, r in edits: text = text[:s] + r + text[e:]
    return text

def blocks(text):
    spans = [(m.start(), m.end()) for m in re.finditer(r'^/\* fzgx:begin .*?^/\* fzgx:end \w+ \*/', text, re.S | re.M)]
    return spans or [(0, len(text))]

def run(task):
    path, us, profs, kind = task
    text = pathlib.Path(path).read_text(); removed = 0
    with tempfile.TemporaryDirectory(prefix='sp_') as td:
        base1, baseall, gens = {}, {}, {}
        for u in us:
            gens[u['source']] = pp.gen(u, text)
            base1[u['source']] = d.compile_text(gens[u['source']], *profs[u['source']], td)
            if base1[u['source']] is None: return (path, text, 0)
        def ok(cand):
            changed = [u for u in us if pp.gen(u, cand) != gens[u['source']]]
            for u in changed:   # screen: GFZE01 only
                if d.compile_text(pp.gen(u, cand), *profs[u['source']], td) != base1[u['source']]: return False
            for u in changed:   # confirm: every region
                if u['source'] not in baseall: baseall[u['source']] = d.compile_all(gens[u['source']], *profs[u['source']], td, u)
                if d.compile_all(pp.gen(u, cand), *profs[u['source']], td, u) != baseall[u['source']]: return False
            for u in changed: gens[u['source']] = pp.gen(u, cand); baseall.pop(u['source'], None)
            return True
        # walk blocks from the end so earlier offsets stay valid
        for lo, hi in reversed(blocks(text)):
            cs = candidates(text, lo, hi, kind)
            if not cs: continue
            cand = apply_edits(text, cs)
            if ok(cand): text = cand; removed += len(cs); continue
            if len(cs) == 1: continue
            for g in reversed(cs):   # from the end of the block: offsets of earlier ones unaffected
                cand = apply_edits(text, [g])
                if ok(cand): text = cand; removed += 1
    return (path, text, removed)

def main():
    kind = 'carrier' if '--kind' in sys.argv and sys.argv[sys.argv.index('--kind') + 1] == 'carrier' else 'volatile'
    args = [a for a in sys.argv[1:] if not a.startswith('--') and a not in ('volatile', 'carrier')]
    units = json.load(open('config/GFZE01/units.json')); nu = d.ninja_units()
    pat = VOL if kind == 'volatile' else CARRIER
    files = args or sorted(str(p) for p in pathlib.Path('src/rel').glob('**/*.c') if 'movie_module' not in str(p) and pat.search(p.read_text()))
    tasks = []
    for f in files:
        us = pp.units_of(f, units); profs = {}
        for u in us:
            key = f"build/GFZE01/gen/{u['source']}" if u.get('tu') else f"src/{u['source']}"
            if key in nu: profs[u['source']] = nu[key]
        us = [u for u in us if u['source'] in profs]
        if us: tasks.append((f, us, profs, kind))
    tasks.sort(key=lambda t: -len(pathlib.Path(t[0]).read_text()))
    tot = 0; out = []
    with concurrent.futures.ProcessPoolExecutor(14) as ex:
        for path, text, n in ex.map(run, tasks):
            if n: out.append((path, text)); tot += n; print(f'{n:5d} {path}', flush=True)
    print('removable', kind, tot)
    if '--apply' in sys.argv:
        for path, text in out: pathlib.Path(path).write_text(text)
        print('applied to', len(out), 'files')

if __name__ == '__main__':
    main()
