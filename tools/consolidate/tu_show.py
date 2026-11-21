"""Print a draft-map DOL TU's units (in address order) and their sources, for hand collapse.
Usage: tu_show.py TU_FILE [--brief]"""
import json, re, sys, pathlib
tu = sys.argv[1]
m = json.load(open('state/tumap/GFZE01_main.json'))
fns = [f for t in m['tus'] if t['file'] == tu for f in t['functions']]
units = json.load(open('config/GFZE01/units.json'))
sp = open('config/GFZE01/splits.txt').read()
rows = []
for u in units:
    if set(u['symbols']) & set(fns):
        b = re.search(rf'^{re.escape(u["source"])}:\n((?:\t.*\n)*)', sp, re.M)
        st = re.search(r'start:0x(\w+)', b.group(1)).group(1) if b else '?'
        rows.append((st, u))
rows.sort(key=lambda r: r[0])
print('TU', tu, 'functions', fns)
print('units:', ','.join(u['source'] for _, u in rows if not u.get('asm')))
for st, u in rows:
    extra = set(u['symbols']) - set(fns)
    print(f"-- {st} {u['source']} asm={bool(u.get('asm'))} mw={u.get('mw_version')} cf={u.get('extra_cflags')} pool={bool(u.get('pool'))} mf={u.get('matching_for')} {'OTHER-TU:' + str(sorted(extra)) if extra else ''}")
if '--brief' not in sys.argv:
    for st, u in rows:
        if u.get('asm'): continue
        print(f'\n==================== {u["source"]}')
        print(pathlib.Path('src', u['source']).read_text())
