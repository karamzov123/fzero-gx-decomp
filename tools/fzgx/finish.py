"""The TU-finish pass: everything that turns matched blocks into whole translation units,
as one idempotent job over a module.

For every TU that has block units:
  1. its headers (globals.h and the TU header, when they exist) join the prologue;
  2. tidy: block-private declarations the headers cover are dropped;
  3. hoist: canonical extern declarations move to the prologue;
  4. reflag: every block's include set is re-decided (prologue, or self-contained);
  5. if every function of the TU is matched and the whole-file trial compiles with every
     block byte-identical, the TU is collapsed into one compiled unit (hash-verified).
Every step is verified per block by the object oracle; nothing is kept that stops matching.
Blocks that cannot compile under the prologue are the revise queue: the orchestrator
sends them to revise agents and runs the pass again. The pass ends with a relink; if the
hash fails, the TU files it touched are restored from git and the failure is reported.
"""

from __future__ import annotations

import hashlib
import json
import re
import subprocess
import threading
import time
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from typing import Dict, List, Optional

from . import collapse, oracle, reconcile, tufile, tutrial
from .project import ROOT, STATE_DIR, Project


def _failed_units(out: str) -> List[str]:
    """Unit stems (`rel/m/tu/fn`) named by a failed ninja run: single edges by their object,
    grouped edges by the driver's `FAILED unit:` lines."""
    found = re.findall(r"FAILED: \[code=\d+\] build/\S+/src/(\S+?)\.o", out)
    for src in re.findall(r"FAILED unit: (\S+)", out):
        src = re.sub(r"^build/[^/]+/gen/|^src/", "", src)
        found.append(src.rsplit(".", 1)[0])
    return list(dict.fromkeys(found))


def _tus(p: Project, module: str) -> List[str]:
    return sorted({u["tu"] for u in p.load_units() if u.get("tu") and u["module"] == module})


class Verifier:
    """Compile and match verdicts memoised by the generated unit's text: an unchanged block
    costs nothing on the next pass. Persisted under .fzgx/verify_cache.json."""

    def __init__(self, p: Project):
        self.p = p
        self.path = STATE_DIR / "verify_cache.json"
        self.lock = threading.Lock()
        try:
            self.cache: Dict[str, dict] = json.loads(self.path.read_text()) if self.path.exists() else {}
        except ValueError:
            self.cache = {}
        self.hits = self.misses = 0
        # a verdict depends on the headers too: the same generated text compiles differently
        # once globals.h changes, so the include tree is part of every key
        h = hashlib.sha256()
        for f in sorted((ROOT / "include").rglob("*.h")):
            h.update(f.read_bytes())
        for name in ('oracle.py', 'poolfix.py', 'regflow.py'):
            h.update((ROOT / 'tools/fzgx' / name).read_bytes())
        self.env = h.hexdigest()[:16]

    def _key(self, u: dict, kind: str) -> str:
        gen = tufile.gen_path(self.p, u["source"])
        text = gen.read_text() if gen.exists() else ""
        h = hashlib.sha256((self.env + "\0" + u["source"] + "\0" + (u.get("mw_version") or "") + "\0" + " ".join(u.get("extra_cflags") or [])
                            + "\0" + json.dumps(u.get("pool") or {}, sort_keys=True) + "\0" + text).encode()).hexdigest()
        return f"{kind}:{h}"

    def compiles(self, u: dict) -> bool:
        k = self._key(u, "compile")
        with self.lock:
            if k in self.cache:
                self.hits += 1
                return self.cache[k]["ok"]
        self.misses += 1
        ok = oracle.compile_unit(self.p, self.p.objdiff_unit_name(u["module"], u["source"]), u["source"]).returncode == 0
        with self.lock:
            self.cache[k] = {"ok": ok}
        return ok

    def matches(self, p: Project, name: str, module: Optional[str] = None) -> bool:
        """Verdict for a block by name; `module` disambiguates _prolog/_epilog, which every REL has."""
        with self.lock:
            if not hasattr(self, "_units"):
                self._units = {}
                for x in p.load_units():
                    if x.get("symbols"):
                        self._units[(x["module"], x["symbols"][0])] = x
                        self._units.setdefault((None, x["symbols"][0]), x)
            u = self._units.get((module, name)) if module else None
            if u is None and module is None:
                cands = [x for (m, n), x in self._units.items() if n == name and m is not None]
                u = cands[0] if len(cands) == 1 else None
        if u is None:
            return False
        k = self._key(u, "match")
        with self.lock:
            if k in self.cache:
                self.hits += 1
                return self.cache[k]["ok"]
        self.misses += 1
        res = oracle.check(p, f"{u['module']}:{name}", 20)  # _prolog/_epilog exist in every module
        ok = res.ok and (res.matched or res.matched_pool) and oracle.unit_fully_matches(res) is None
        with self.lock:
            self.cache[k] = {"ok": ok, "pool_map": res.pool_map if res.ok else {}}
        return ok

    def verdicts(self, p: Project, names: List[str], module: str) -> Dict[str, bool]:
        """`matches` for several blocks at once: the uncached verdicts come from one batched
        compile+diff instead of one compiler process per block."""
        with self.lock:
            if not hasattr(self, "_units"):
                self._units = {}
                for x in p.load_units():
                    if x.get("symbols"):
                        self._units[(x["module"], x["symbols"][0])] = x
                        self._units.setdefault((None, x["symbols"][0]), x)
        out: Dict[str, bool] = {}
        todo = []
        for name in names:
            u = self._units.get((module, name))
            if u is None:
                out[name] = False
                continue
            k = self._key(u, "match")
            with self.lock:
                hit = self.cache.get(k)
            if hit is not None:
                self.hits += 1
                out[name] = bool(hit["ok"])
                continue
            todo.append((name, u, k))
        if todo:
            res = oracle.check_many(p, [(f"{u['module']}:{u['symbols'][0]}", None) for _, u, _ in todo], 20)
            with self.lock:
                for name, u, k in todo:
                    r = res.get(f"{u['module']}:{u['symbols'][0]}")
                    ok = bool(r and r.ok and (r.matched or r.matched_pool) and oracle.unit_fully_matches(r) is None)
                    self.cache[k] = {"ok": ok, "pool_map": r.pool_map if r and r.ok else {}}
                    self.misses += 1
                    out[name] = ok
        return out

    def matches_many(self, p: Project, names: List[str], module: str) -> bool:
        return all(self.verdicts(p, names, module).values())

    def prefetch(self, p: Project, module: str) -> int:
        """One batched compile+diff for every block of the module whose verdict is not cached:
        the per-block `matches` calls then hit the cache. Returns the number verified."""
        todo = []
        for u in p.load_units():
            if u["module"] != module or not u.get("symbols") or not u.get("tu"):
                continue
            k = self._key(u, "match")
            with self.lock:
                if k in self.cache:
                    continue
            todo.append((u, k))
        if not todo:
            return 0
        res = oracle.check_many(p, [(f"{u['module']}:{u['symbols'][0]}", None) for u, _ in todo], 20)
        with self.lock:
            for u, k in todo:
                r = res.get(f"{u['module']}:{u['symbols'][0]}")
                if r is None:
                    continue
                ok = r.ok and (r.matched or r.matched_pool) and oracle.unit_fully_matches(r) is None
                self.cache[k] = {"ok": ok, "pool_map": r.pool_map if r.ok else {}}
                self.misses += 1
        return len(todo)

    def save(self) -> None:
        with self.lock:
            self.path.parent.mkdir(parents=True, exist_ok=True)
            self.path.write_text(json.dumps(self.cache))


def _all_matched(p: Project, tu_source: str) -> bool:
    module = tu_source.split("/")[1] if tu_source.startswith("rel/") else "main"
    t = collapse._tu_entry(p, module, tu_source)
    if t is None:
        return False
    st = {u["symbols"][0]: u["status"] for u in p.load_units() if u.get("tu") == tu_source}
    return all(st.get(f) == "matching" for f in t["functions"])


def finish_tu(p: Project, tu_source: str, do_collapse: bool = True, v: Optional[Verifier] = None) -> Dict[str, object]:
    v = v or Verifier(p)
    r = reconcile.reconcile_tu(p, tu_source, v)
    out: Dict[str, object] = {"tu": tu_source, "renamed": r["renamed"], "hoisted": len(r["hoisted"]),
                              "contested": len(r["contested"]), "queue": list(r["unresolved"]),
                              "included": r["included"]}
    tf = tufile.load(p, tu_source)
    out["blocks"] = len(tf.blocks)
    # a tidied block may renumber its private literals: keep the pool mappings current
    for u in p.load_units():
        if u.get("tu") == tu_source and isinstance(u.get("pool"), dict):
            new_map = oracle.refreshed_pool_map(p, u)
            if new_map:
                with oracle.build_lock("units.lock"):
                    units = p.load_units()
                    for x in units:
                        if x["source"] == u["source"]:
                            x["pool"] = dict(new_map)
                    p.save_units(units)
                out.setdefault("pool_remapped", []).append(u["symbols"][0])
    if do_collapse and _all_matched(p, tu_source) and not out["queue"]:
        tr = tutrial.trial(p, tu_source)
        out["trial"] = {"ok": tr.get("ok"), "at_100": tr.get("at_100"), "functions": tr.get("functions")}
        if tr.get("ok") and tr.get("at_100") == tr.get("functions"):
            c = collapse.collapse(p, tu_source)
            out["collapsed"] = bool(c.get("ok"))
            if not c.get("ok"):
                out["collapse_error"] = c.get("error")
    return out


def _fresh_reverify(p: Project, module: str, tus: List[str]) -> Dict[str, object]:
    """Re-verify every block of the pass without the verdict cache, before the relink.

    The cache returned `ok` for blocks that do not match (story: fn_7_72C at 92.4%, fn_7_2538 at
    99.2%), so the relink failed and the whole module rolled back. A block that fails a fresh check
    goes back to its committed text, self-contained, with its committed pool map; then every
    remaining pool map whose private literal names went stale is refreshed."""
    cp = subprocess.run(["git", "show", "HEAD:config/" + p.version + "/units.json"], cwd=ROOT, text=True, capture_output=True)
    try:
        head_units = json.loads(cp.stdout) if cp.returncode == 0 else []
    except ValueError:
        head_units = []
    head_units = head_units if isinstance(head_units, list) else head_units.get("units", [])
    head_pool = {u["source"]: u.get("pool") for u in head_units}
    restored: List[str] = []
    remapped: List[str] = []
    for tu in tus:
        tf = tufile.load(p, tu)
        by_sym = {u["symbols"][0]: u for u in p.load_units() if u.get("tu") == tu and u.get("module") == module}
        names = [b.name for b in tf.blocks if b.name in by_sym]
        for n in names:
            tufile.write_gen(p, by_sym[n], tf)
        if not names:
            continue
        res = oracle.check_many(p, [(f"{module}:{n}", None) for n in names], 3)
        bad = []
        for n in names:
            r = res.get(f"{module}:{n}")
            if not (r and r.ok and (r.matched or r.matched_pool) and oracle.unit_fully_matches(r) is None):
                bad.append(n)
        if bad:
            for n in bad:
                b = tf.get(n)
                b.body, b.flags = reconcile._committed_block(p, tu, n, b.body, b.flags)
            tufile._write_atomic(tufile.tu_path(p, tu), tf.render())
            with oracle.build_lock("units.lock"):
                units = p.load_units()
                for x in units:
                    if x.get("tu") == tu and x["symbols"][0] in bad and x["source"] in head_pool:
                        x["pool"] = head_pool[x["source"]]
                p.save_units(units)
            for n in bad:
                tufile.write_gen(p, by_sym[n], tf)
            restored += bad
        for u in p.load_units():
            if u.get("tu") == tu and u["symbols"][0] not in bad and isinstance(u.get("pool"), dict):
                new_map = oracle.refreshed_pool_map(p, u)
                if new_map:
                    with oracle.build_lock("units.lock"):
                        units = p.load_units()
                        for x in units:
                            if x["source"] == u["source"]:
                                x["pool"] = dict(new_map)
                        p.save_units(units)
                    remapped.append(u["symbols"][0])
    return {"restored": restored, "remapped": remapped}


def finish(p: Project, module: str, workers: int = 12) -> Dict[str, object]:
    """The pass over every TU of the module, then one relink. Returns per-TU results, the
    revise queue and whether the tree still hashes."""
    tus = _tus(p, module)
    v = Verifier(p)
    t0 = time.time()
    v.prefetch(p, module)
    # TUs are independent files with their own locks; only collapse takes the build lock
    with ThreadPoolExecutor(max_workers=workers) as ex:
        results = list(ex.map(lambda tu: finish_tu(p, tu, True, v), tus))
    v.save()
    fresh = _fresh_reverify(p, module, tus)
    queue = [s for r in results for s in r["queue"]]
    diag: Dict[str, object] = {}
    restored: List[str] = []
    with oracle.build_lock():
        cp = oracle.configure(p)
        cp2 = oracle.relink(p, keep_going=True) if cp.returncode == 0 else cp
        linked = cp.returncode == 0 and cp2.returncode == 0
        if not linked:
            # name the culprits, restore only their TU files, keep the rest of the pass
            out = cp2.stdout + cp2.stderr
            failed = _failed_units(out)
            diag = {"failed_units": failed[:20], "errors": [l for l in out.splitlines() if l.startswith("#   ") and "Error" not in l][:12]}
            tmap = p.tu_map(module)
            units_by_src = {u["source"]: u for u in p.load_units()}
            bad_units = [units_by_src[f + ".c"] for f in failed if f + ".c" in units_by_src and units_by_src[f + ".c"].get("tu")]
            # first the fine-grained fix: only the failing blocks go back to their committed text
            for u in bad_units:
                tu_src = u["tu"]
                cp3 = subprocess.run(["git", "show", f"HEAD:src/{tu_src}"], cwd=ROOT, text=True, capture_output=True)
                if cp3.returncode != 0:
                    continue
                try:
                    old_tf = tufile.parse(cp3.stdout)
                    old_b = old_tf.get(u["symbols"][0])
                except ValueError:
                    old_tf, old_b = None, None
                tf = tufile.load(p, tu_src)
                b = tf.get(u["symbols"][0])
                if old_b is not None and b is not None:
                    b.body, b.flags = old_b.body, list(old_b.flags)
                    if "noprologue" not in b.flags:
                        # self-contained under the prologue it matched with, not today's
                        b.body = old_tf.prologue.rstrip("\n") + "\n\n" + b.body
                        b.flags.append("noprologue")
                    tufile._write_atomic(tufile.tu_path(p, tu_src), tf.render())
                    tufile.write_gen(p, u, tf)
            tufile.regenerate(p)
            oracle.configure(p)
            cp2 = oracle.relink(p, keep_going=True)
            linked = cp2.returncode == 0
            if linked:
                restored = [u["symbols"][0] for u in bad_units]
                diag["block_restored"] = restored
            failed = [] if linked else _failed_units(cp2.stdout + cp2.stderr)
            bad_tus = sorted({units_by_src[f + ".c"]["tu"] for f in failed if f + ".c" in units_by_src and units_by_src[f + ".c"].get("tu")})
        if not linked and not failed:
            # the link ran but a hash differs: put back only the blocks that differ, each
            # self-contained under its committed prologue, before giving up whole TU files
            # (pilotpoint: one block, fn_14_1090, verified 100% per function but linked 12
            # words different; restoring the whole TU threw away 67 good blocks)
            diag = oracle.byte_diff(p, module)
            culprits = [f for f, _ in diag.get("text_diffs", [])]
            if culprits and not diag.get("sections"):
                by_sym = {u["symbols"][0]: u for u in p.load_units() if u.get("module") == module and u.get("tu")}
                put_back = []
                for f in culprits:
                    u = by_sym.get(f)
                    if u is None:
                        continue
                    tf = tufile.load(p, u["tu"])
                    b = tf.get(f)
                    if b is None:
                        continue
                    b.body, b.flags = reconcile._committed_block(p, u["tu"], f, b.body, b.flags)
                    tufile._write_atomic(tufile.tu_path(p, u["tu"]), tf.render())
                    tufile.write_gen(p, u, tf)
                    put_back.append(f)
                if put_back and len(put_back) == len(culprits):
                    oracle.configure(p)
                    linked = oracle.relink(p).returncode == 0
                    if linked:
                        restored = put_back
                        diag["block_restored"] = put_back
        if not linked:
            if not failed:  # the link ran: a hash mismatch, name it by function
                diag = oracle.byte_diff(p, module)
                bad_tus = sorted({f"{p.module_src_prefix(module)}/{tmap[f]}.c" for f, _ in diag.get("text_diffs", []) if f in tmap})
                if not bad_tus or diag.get("sections"):
                    bad_tus = list(tus)  # a layout shift: no single function to blame
            for tu in bad_tus:
                cp = subprocess.run(["git", "show", f"HEAD:src/{tu}"], cwd=ROOT, text=True, capture_output=True)
                if cp.returncode == 0:
                    (ROOT / "src" / tu).write_text(cp.stdout)
                    restored.append(tu)
            tufile.regenerate(p)
            oracle.configure(p)
            linked = oracle.relink(p).returncode == 0
            if not linked:  # still red: everything back
                for tu in tus:
                    cp = subprocess.run(["git", "show", f"HEAD:src/{tu}"], cwd=ROOT, text=True, capture_output=True)
                    if cp.returncode == 0:
                        (ROOT / "src" / tu).write_text(cp.stdout)
                restored = list(tus)
                tufile.regenerate(p)
                oracle.configure(p)
                linked = oracle.relink(p).returncode == 0
    collapsed = [r["tu"] for r in results if r.get("collapsed")]
    if linked:
        files = [str(ROOT / "src" / tu) for tu in tus] + [str(p.units_path), str(p.module_config_dir(module) / "splits.txt")]
        subprocess.run(["git", "add", *files], cwd=ROOT, capture_output=True)
        msg = f"tu-finish {module}: {sum(r['hoisted'] for r in results)} declarations hoisted, {sum(r['renamed'] for r in results)} typedefs isolated, " \
              f"{sum(r['contested'] for r in results)} contested, {len(queue)} unresolved" + (f", collapsed {', '.join(Path(t).stem for t in collapsed)}" if collapsed else "")
        subprocess.run(["git", "commit", "-q", "-m", msg], cwd=ROOT, capture_output=True)
    diag["fresh_reverify"] = fresh
    return {"ok": linked, "module": module, "tus": len(tus), "queue": queue, "collapsed": collapsed,
            "secs": round(time.time() - t0, 1), "cache_hits": v.hits, "cache_misses": v.misses,
            "restored": restored, "diag": diag,
            "trials": {r["tu"]: r.get("trial") for r in results if r.get("trial")},
            "collapse_errors": {r["tu"]: r["collapse_error"] for r in results if r.get("collapse_error")},
            "hoisted": sum(r["hoisted"] for r in results), "renamed": sum(r["renamed"] for r in results),
            "contested": sum(r["contested"] for r in results),
            "results": results}
