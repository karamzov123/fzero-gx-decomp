"""Incremental live link verification; isolate rejected units only on failure."""

from __future__ import annotations

import subprocess
import time
import json
import os
import re
import signal
import hashlib
from typing import Dict, List, Optional
from pathlib import Path

from . import oracle, tufile
from .ledger import Ledger
from .project import ROOT, STATE_DIR, Project

STUB = '#include "types.h"\n\n// {symbol}: carved by fzgx; {note}\n'

# A `build.sha1` miss is ambiguous: it can be a genuine layout change or a read that raced
# a concurrent writer. Retry a few times with a growing settle before treating it as real.
_RECHECK_ATTEMPTS = 3
_RECHECK_SETTLE_S = 2


def pool_backup_path(key: str) -> Path:
    return STATE_DIR / 'pool_upgrades' / (key.replace(':', '__') + '.json')


def preserve_pool(p: Project, key: str) -> None:
    """Journal accepted C and compiler settings before attempting a linked upgrade."""
    state = Ledger().get(key)
    if not state or state['status'] != 'matched' or state['link_state'] != 'pool':
        return
    path = pool_backup_path(key)
    sym = p.resolve(key)
    unit = p.unit_record(p.unit_of(sym))
    src = ROOT / 'src' / unit.get('tu', unit['source'])
    saved = dict(unit=unit, matched_commit=state['matched_commit'])
    if unit.get('tu'):
        tf = tufile.parse(src.read_text())
        block = tf.get(sym.name)
        if block is None:
            raise ValueError(f'{key}: accepted pool block is missing')
        saved['block'] = dict(name=block.name, body=block.body, flags=block.flags)
        saved['block_order'] = [b.name for b in tf.blocks]
    else:
        saved['source'] = src.read_text()
    path.parent.mkdir(parents=True, exist_ok=True)
    tufile._write_atomic(path, json.dumps(saved) + '\n')


def restore_pool(p: Project, key: str) -> bool:
    path = pool_backup_path(key)
    if not path.exists():
        return False
    saved = json.loads(path.read_text())
    unit = saved['unit']
    src = ROOT / 'src' / unit.get('tu', unit['source'])
    if 'block' in saved:
        with tufile._lock(src):
            tf = tufile.parse(src.read_text())
            block = tufile.Block(**saved['block'])
            old = tf.get(block.name)
            if old:
                tf.blocks[tf.blocks.index(old)] = block
            else:
                order = saved.get('block_order', [])
                after = set(order[order.index(block.name) + 1:]) if block.name in order else set()
                at = next((i for i, b in enumerate(tf.blocks) if b.name in after), len(tf.blocks))
                # New concurrent blocks also retain retail address order.
                sym = p.resolve(key)
                at = next((i for i, b in enumerate(tf.blocks[:at])
                           if (other := p.find_symbol(b.name, sym.module)) and other.addr > sym.addr), at)
                tf.blocks.insert(at, block)
            tufile._write_atomic(src, tf.render())
    else:
        src.write_text(saved['source'])
    with oracle.build_lock('units.lock'):
        units = p.load_units()
        units = [unit if u['source'] == unit['source'] else u for u in units]
        p.save_units(units)
    Ledger().db.execute("UPDATE functions SET status='matched', link_state='pool', matched_commit=? WHERE symbol=?",
                        (saved['matched_commit'], key))
    return True


def pending(l: Ledger) -> List[str]:
    """Symbols (ledger keys) accepted but not yet link-verified."""
    return [r["symbol"] for r in l.db.execute("SELECT symbol FROM functions WHERE link_state='pending' ORDER BY addr")]


def _units_for(p: Project, keys: List[str]) -> Dict[str, str]:
    """ledger key -> unit source path."""
    out = {}
    for k in keys:
        sym = p.resolve(k)
        if sym:
            u = p.unit_of(sym)
            if u:
                out[k] = u
    return out


def _set_status(p: Project, sources: List[str], status: str) -> None:
    units = p.load_units()
    changed = False
    for u in units:
        if u["source"] in sources and u['status'] != status:
            u["status"] = status
            changed = True
    if changed:
        p.save_units(units)


def _relink(p: Project) -> bool:
    # Ninja tracks units.json, split config, sources and headers, including its
    # own configure edge. Explicit configure invalidated otherwise clean work.
    cp = oracle.relink(p)
    with (STATE_DIR / 'verify_builds.jsonl').open('a') as log:
        log.write(json.dumps(dict(t=time.time(), ok=cp.returncode == 0, output=cp.stdout + cp.stderr)) + '\n')
    if not cp.returncode:
        return True
    (STATE_DIR / 'verify_last_failure.log').write_text(cp.stdout + cp.stderr)
    if not _is_checksum_failure(cp):
        return False
    # The final `shasum -c` runs the instant the link lands, and under a live fleet another
    # writer can still be replacing the file, so a checksum miss here is often a read that
    # raced the writer rather than a layout change. A genuine layout problem (wrong module
    # size, wrong bytes) reproduces on every re-check; a race clears within a second or two.
    # Retry a few times with a short settle rather than rejecting on the first miss -- one
    # immediate re-check is not enough, because the writer is still mid-write when it runs.
    # See docs/findings/279.
    for attempt in range(_RECHECK_ATTEMPTS):
        time.sleep(_RECHECK_SETTLE_S * (attempt + 1))
        oracle.run(["ninja", p.rel(p.build_dir / "ok")], timeout=1800)
        cp2 = oracle.run(["build/tools/dtk", "shasum", "-q", "-c",
                          "config/GFZE01/build.sha1"], timeout=600)
        with (STATE_DIR / 'verify_builds.jsonl').open('a') as log:
            log.write(json.dumps(dict(t=time.time(), ok=cp2.returncode == 0, recheck=True,
                                      attempt=attempt + 1,
                                      output=cp2.stdout + cp2.stderr)) + '\n')
        if cp2.returncode == 0:
            (STATE_DIR / 'verify_last_failure.log').write_text(
                'checksum re-check passed on attempt %d: the first failure raced a '
                'concurrent writer.\n' % (attempt + 1))
            return True
    return False


def _is_checksum_failure(cp: subprocess.CompletedProcess) -> bool:
    """True when the run got as far as the final `build.sha1` step.

    A compile or link error fails earlier and needs no re-check; only a checksum miss is
    ambiguous, because both a raced read and a genuine layout change print the same
    `<module>.rel: FAILED / N files OK` summary.
    """
    out = cp.stdout + cp.stderr
    return 'shasum' in out and 'checksum' in out


def _tu_headers(body: str) -> List[str]:
    """The `#include` lines a body already carries, in order."""
    return [line.strip() for line in body.splitlines() if line.strip().startswith('#include')]


def _tu_includes(p: Project, rec: Optional[dict]) -> List[str]:
    """The `#include` lines the unit's own translation unit is compiled with.

    Read from the TU file rather than guessed from the unit path: the TU is what
    supplied this body's declarations when it compiled and linked, so its include
    block is the exact context to restore. Returns [] for a standalone unit.
    """
    tu = (rec or {}).get('tu')
    if not tu:
        return []
    path = tufile.tu_path(p, tu)
    try:
        text = path.read_text()
    except OSError:
        return []
    out = []
    for line in text.splitlines():
        stripped = line.strip()
        if stripped.startswith('#include'):
            out.append(stripped)
        elif out:
            break  # the include block is contiguous at the top of the TU
    return out


def _with_tu_context(body: str, rec: Optional[dict], p: Project) -> str:
    """Prepend the TU's headers to a body that is about to leave its unit.

    A quarantined body is a standalone copy: the recarve path supplies the TU's
    headers and the quarantine path does not, so bodies parked here routinely fail to
    compile on their own evidence -- "';' expected" on an undeclared u32, or an
    undefined bss label. Four of the six 100% link-mismatch functions needed nothing
    beyond this.

    Each include is added only when the body does not already carry it. A body may
    legitimately define something its TU header also declares (a reconstructed
    struct, or the `lbl_*` fragment globals a layout primer needs), and adding that
    header then makes the compiler reject the file, so a header is skipped when the
    body defines any name it declares.
    """
    if not (rec or {}).get('tu'):
        return body
    carried = _tu_headers(body)
    missing = [inc for inc in _tu_includes(p, rec)
               if not any(_same_include(inc, have) for have in carried)]
    if not missing:
        return body
    keep = [inc for inc in missing if _include_is_safe(inc, body, p)]
    if not keep:
        return body
    lines = body.splitlines(keepends=True)
    at = 0
    while at < len(lines) and (lines[at].lstrip().startswith('#include')
                               or not lines[at].strip()):
        at += 1
    prologue = ''.join(inc if inc.endswith('\n') else inc + '\n' for inc in keep)
    return prologue + ''.join(lines[at:])


def _same_include(a: str, b: str) -> bool:
    return a.split()[-1] == b.split()[-1]


def _include_is_safe(include: str, body: str, p: Project) -> bool:
    """False when the header declares a name the body also defines.

    Conservative in the safe direction: a false positive only costs the include, and
    the body still compiles if the header was not needed. A false negative makes the
    compiler reject a header that redeclares what the body defines.
    """
    name = include.split()[-1].strip('"<>')
    path = ROOT / 'include' / name
    if not path.exists():
        return True
    try:
        text = path.read_text(errors='replace')
    except OSError:
        return True
    declared = set(re.findall(r'\b(\w+)\s*(?:\[[^\]]*\])?\s*(?:;|=|\{)', text))
    defined = set(re.findall(r'(?m)^\s*(?:static\s+|const\s+|extern\s+)*[A-Za-z_][\w \t*]*?\b(\w+)\s*(?:\[[^\]]*\])?\s*(?:=|;|\{)', body))
    defined |= set(re.findall(r'(?m)^\s*typedef\b.*?\b(\w+)\s*;', body))
    return not (declared & defined)


@oracle.build_lock('submit.lock', timeout_s=1800)
def verify(p: Project, message: Optional[str] = None) -> Dict[str, object]:
    """Relink with every pending unit Matching; commit on success; bisect on failure."""
    l = Ledger()
    keys = pending(l)
    journal = STATE_DIR / 'verify_dependencies.jsonl'
    dependencies = [str(ROOT / path) for line in journal.read_text().splitlines() for path in json.loads(line)] if journal.exists() else []
    if not keys and not dependencies:
        return {"ok": True, "verified": [], "rejected": [], "note": "nothing pending"}
    units = _units_for(p, keys)
    if missing := sorted(set(keys) - units.keys()):
        return dict(ok=False, error=f'pending functions have no units: {missing}', verified=[], rejected=[])
    sources = []
    for source in units.values():
        rec = p.unit_record(source)
        sources.append(ROOT / 'src' / (rec['tu'] if rec and rec.get('tu') else source))
    t0 = time.time()
    with oracle.build_lock():
        _set_status(p, list(units.values()), 'matching')
        if _relink(p):
            good, bad = list(units), []
            fast_path = True
        else:
            # Establish a known-good baseline only after an actual failure.
            # This distinguishes a bad candidate from a pre-existing breakage.
            _set_status(p, list(units.values()), "nonmatching")
            if not _relink(p):
                _set_status(p, list(units.values()), 'matching')
                return {"ok": False, "error": "baseline relink failed with all pending units held back; "
                        "the tree is broken independently of them; pending status restored",
                        "verified": [], "rejected": [], 'secs': round(time.time() - t0, 3)}
            good, bad = _bisect(p, list(units), units, known_failure=True)
            fast_path = False
        # final state: good units Matching, bad units uncarved (no unit without matched code); relink once more if we bisected
        if bad:
            from .uncarve import uncarve
            restored = set()
            for k in bad:
                keep = STATE_DIR / "attempts" / f"{k}.linkfail.{int(time.time())}.c"
                keep.parent.mkdir(parents=True, exist_ok=True)
                rec = p.unit_record(units[k])
                if rec and rec.get("tu"):
                    keep.write_text(tufile.remove(p, rec) or "")
                else:
                    src = ROOT / "src" / units[k]
                    if src.exists():
                        keep.write_bytes(src.read_bytes())
                # The unit is about to be uncarved, so this body is the only copy of a
                # reconstruction whose object already matches retail exactly. Record it the
                # way every other saved body is recorded: with its compiler settings, and as
                # the attempt's best_body_path. Left unrecorded it reached nobody - the
                # repair corpus, the next attempt's context and the near-miss search all
                # select saved bodies through best_body_path, and a NULL row hid a 100%
                # body from all three, so the function was re-derived from scratch forever.
                if keep.exists() and keep.read_text().strip():
                    body = _with_tu_context(keep.read_text(), rec, p)
                    if body != keep.read_text():
                        # A quarantined body is a standalone copy: the recarve path supplies the
                        # TU's headers and the quarantine path does not, so bodies parked here
                        # routinely fail to compile on their own evidence ("';' expected" on an
                        # undeclared u32, or an undefined bss label). Prepend the TU header the
                        # unit was compiled under. Four of the six 100% link-mismatch functions
                        # needed nothing else. Recompute the digest over what is actually stored.
                        keep.write_text(body)
                    keep.with_suffix('.json').write_text(json.dumps(dict(
                        sha256=hashlib.sha256(keep.read_bytes()).hexdigest(),
                        mw=(rec or {}).get('mw_version'), flags=(rec or {}).get('extra_cflags'),
                        headers=_tu_headers(body),
                        percent=100.0, link_fail=True)) + '\n')
                    l.db.execute("UPDATE attempts SET best_body_path=? WHERE id="
                                 "(SELECT id FROM attempts WHERE symbol=? ORDER BY id DESC LIMIT 1)", (str(keep), k))
                if restore_pool(p, k):
                    restored.add(k)
                else:
                    l.db.execute("UPDATE functions SET status='unmatched', link_state=NULL, attempts=attempts+1 WHERE symbol=?", (k,))
                l.db.execute("UPDATE attempts SET outcome='link-mismatch', notes=COALESCE(notes,'')||' [object matched but link differed]' "
                             "WHERE id=(SELECT id FROM attempts WHERE symbol=? ORDER BY id DESC LIMIT 1)", (k,))
            uncarve(p, [units[k] for k in bad if k not in restored], split=False)
            _set_status(p, [units[k] for k in good], "matching")
            if not _relink(p):
                return {"ok": False, "error": "relink failed after removing rejected units; accepted units remain matching",
                        "rejected": bad, "verified": []}
        commit = None
        if good or bad or dependencies:
            files = [str(p.units_path)]
            # Rejection also changes existing TU files. Include those and tracked
            # deletions, but not removed candidates that were never committed.
            for source in sources:
                if source.exists() or subprocess.run(['git', 'ls-files', '--error-unmatch', str(source)],
                        cwd=ROOT, capture_output=True).returncode == 0:
                    files.append(str(source))
            for mod in {p.resolve(k).module for k in good + bad}:
                d = p.module_config_dir(mod)
                files += [str(d / "splits.txt"), str(d / "symbols.txt")]
            files.extend(dependencies)
            files = sorted(path for path in set(files) if Path(path).exists() or
                           subprocess.run(['git', 'ls-files', '--error-unmatch', path],
                                          cwd=ROOT, capture_output=True).returncode == 0)
            oracle.clear_stale_index_lock()
            subprocess.run(["git", "add", '--', *files], cwd=ROOT, capture_output=True, check=True)
            msg = message or f"match: {len(good)} functions link-verified"
            names = ", ".join(p.key(p.resolve(k)) for k in good[:8]) + (" ..." if len(good) > 8 else "")
            changed = subprocess.run(['git', 'diff', '--cached', '--quiet', '--', *files], cwd=ROOT).returncode
            if changed:
                subprocess.run(["git", "commit", '--only', "-q", "-m", msg + (f" ({names})" if names else ''), '--', *files],
                               cwd=ROOT, capture_output=True, check=True)
            commit = subprocess.run(["git", "rev-parse", "--short", "HEAD"], cwd=ROOT, text=True,
                                    capture_output=True).stdout.strip()
            for k in good:
                l.db.execute("UPDATE functions SET link_state='verified', matched_commit=? WHERE symbol=?", (commit, k))
            journal.unlink(missing_ok=True)
            for k in good + bad:
                pool_backup_path(k).unlink(missing_ok=True)
    evidence_queue = None
    if good or bad or dependencies:
        try:
            from . import work_evidence
            update = work_evidence.refresh(p)
            evidence_queue = {key: update[key] for key in ('initialized', 'changed_files', 'newly_affected', 'pending')}
        except (OSError, ValueError, KeyError) as error:
            # Advisory triage must never manufacture or revoke hash acceptance.
            evidence_queue = dict(error=str(error))
    return {"ok": True, "verified": good, "rejected": bad, "commit": commit,
            "evidence_queue": evidence_queue,
            "fast_path": fast_path, "secs": round(time.time() - t0, 3)}


def _bisect(p: Project, keys: List[str], units: Dict[str, str], known_failure=False) -> tuple[List[str], List[str]]:
    """Return (good, bad). Assumes the caller holds the build lock."""
    _set_status(p, [units[k] for k in keys], "matching")
    if not known_failure and _relink(p):
        return keys, []
    if len(keys) == 1:
        _set_status(p, [units[keys[0]]], "nonmatching")
        return [], keys
    mid = len(keys) // 2
    left, right = keys[:mid], keys[mid:]
    # test each half in isolation (other half nonmatching)
    _set_status(p, [units[k] for k in right], "nonmatching")
    lg, lb = _bisect(p, left, units)
    _set_status(p, [units[k] for k in left], "nonmatching")
    rg, rb = _bisect(p, right, units)
    _set_status(p, [units[k] for k in lg + rg], "matching")
    return lg + rg, lb + rb


def watch(version: str, interval: float, until_pid: Optional[int] = None,
          stop_file: Optional[Path] = None, message: Optional[str] = None):
    """Drain completed work periodically; an outlier model cannot delay commits.

    Stop signals are observed between transactions, never in the middle of
    a link, rejection rollback or commit. Parent death triggers a final drain.
    """
    stop_requested = False

    def request_stop(signum, frame):
        nonlocal stop_requested
        stop_requested = True

    signal.signal(signal.SIGTERM, request_stop)
    signal.signal(signal.SIGINT, request_stop)
    while True:
        if pending(Ledger()) or (STATE_DIR / 'verify_dependencies.jsonl').exists():
            try:
                result = verify(Project(version), message)
            except Exception as error:
                result = dict(ok=False, error=str(error), verified=[], rejected=[])
            print(json.dumps(dict(timestamp=time.time(), **result)), flush=True)
        deadline = time.monotonic() + interval
        while True:
            stopping = stop_requested or (stop_file is not None and stop_file.exists())
            if until_pid:
                try:
                    os.kill(until_pid, 0)
                except ProcessLookupError:
                    stopping = True
            if stopping:
                # A submit may have completed during the last sleep.
                if pending(Ledger()) or (STATE_DIR / 'verify_dependencies.jsonl').exists():
                    result = verify(Project(version), message)
                    print(json.dumps(dict(timestamp=time.time(), **result)), flush=True)
                return
            remaining = deadline - time.monotonic()
            if remaining <= 0:
                break
            time.sleep(min(1.0, remaining))
