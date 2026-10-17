"""Undo a carve: a unit that has no matched code behind it goes back to the retail auto object.

Removes the units.json entry, the split range, the generated or stub source, and clears the
ledger's unit column. Used for units verify rejects and for legacy stubs (`--stubs`), so the
unit count stays at the matched count (a stub is a linker object for nothing).
"""

from __future__ import annotations

from typing import Dict, List

from . import collapse, oracle, tufile
from .ledger import Ledger
from .project import ROOT, Project


def stubs(p: Project) -> List[dict]:
    return [u for u in p.load_units() if u.get("status") == "nonmatching"]


def uncarve(p: Project, sources: List[str], split: bool = True) -> Dict[str, object]:
    """Drop the units named by source path. Re-splits (unless split=False) but does not relink."""
    want = set(sources)
    with oracle.build_lock("units.lock"):
        units = p.load_units()
        gone = [u for u in units if u["source"] in want]
        keep = [u for u in units if u["source"] not in want]
        by_module: Dict[str, List[str]] = {}
        for u in gone:
            by_module.setdefault(u["module"], []).append(u["source"])
            if u.get("tu"):
                tufile.remove(p, u)  # a block, if one exists
                tufile.gen_path(p, u["source"]).unlink(missing_ok=True)
            else:
                src_path = ROOT / "src" / u["source"]
                src_path.unlink(missing_ok=True)
                if u.get("asm"):
                    # an asm unit records the C name but links from the split assembly next to it
                    src_path.with_suffix(".s").unlink(missing_ok=True)
        for module, srcs in by_module.items():
            spath = p.module_config_dir(module) / "splits.txt"
            spath.write_text(collapse._splits_without(spath.read_text(), srcs))
        p.save_units(keep)
    l = Ledger()
    for u in gone:
        for s in u.get("symbols", []):
            # units.json stores bare names; ambiguous ones (_prolog/_epilog) must key as module:name
            sym = p.resolve(s)
            if sym is None and ":" not in s:
                sym = p.symbols(u["module"]).get(s)
            l.db.execute("UPDATE functions SET unit=NULL, link_state=NULL WHERE symbol=? AND status<>'matched'",
                         (p.key(sym) if sym else s,))
    l.db.commit()
    if split and gone:
        from .api import _reconfigure_and_split
        _reconfigure_and_split(p)
    return {"removed": len(gone), "modules": sorted(by_module)}
