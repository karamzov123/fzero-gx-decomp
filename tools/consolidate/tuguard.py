"""TU-boundary guard for the consolidators: never merge units that a TU map places in different
translation units: the DOL .text and .init maps and every REL module's
config/GFZE01/<module>/tus.json (movie_module's Sofdec map, for example)."""
import json, pathlib
_MAP = None


def _tu_of():
    """(module, function) -> TU file."""
    global _MAP
    if _MAP is None:
        _MAP = {}
        p = pathlib.Path('state/tumap/GFZE01_main.json')
        if p.exists():
            _MAP.update({('main', f): t['file'] for t in json.loads(p.read_text())['tus'] for f in t['functions']})
        p = pathlib.Path('state/tumap/GFZE01_main_init.json')
        if p.exists():
            _MAP.update({('main', s): t.get('text_map_file', t['file'])
                         for t in json.loads(p.read_text())['tus'] for s in t['symbols']})
        for p in sorted(pathlib.Path('config/GFZE01').glob('*/tus.json')):
            d = json.loads(p.read_text())
            _MAP.update({(d['module'], f): t['file'] for t in d['tus'] for f in t['functions']})
    return _MAP


def same_tu(sources, units):
    """True when the units' functions belong to at most one known TU (unknown ones are neutral)."""
    m = _tu_of(); seen = set()
    for s in sources:
        u = units.get(s)
        if not u: continue
        seen |= {m[(u['module'], x)] for x in u['symbols'] if (u['module'], x) in m}
        if len(seen) > 1:
            return False
    return True
