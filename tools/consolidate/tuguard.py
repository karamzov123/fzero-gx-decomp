"""TU-boundary guard for the consolidators: never merge DOL units that the draft TU map
(state/tumap/GFZE01_main.json) places in different translation units."""
import json, pathlib
_MAP = None


def _tu_of():
    global _MAP
    if _MAP is None:
        p = pathlib.Path('state/tumap/GFZE01_main.json')
        _MAP = {f: t['file'] for t in json.loads(p.read_text())['tus'] for f in t['functions']} if p.exists() else {}
    return _MAP


def same_tu(sources, units):
    """True when the units' functions belong to at most one known TU (unknown ones are neutral)."""
    m = _tu_of(); seen = set()
    for s in sources:
        u = units.get(s)
        if not u: continue
        seen |= {m[x] for x in u['symbols'] if x in m}
        if len(seen) > 1:
            return False
    return True
