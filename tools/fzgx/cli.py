"""`fzgx` command line: thin wrapper over tools/fzgx/api.py."""

from __future__ import annotations

import argparse
import json
import hashlib
import os
import time
from pathlib import Path
from typing import List, Optional

from . import api, naming, structs, trivial, tu
from .project import Project


def _print(obj, as_json: bool) -> None:
    if as_json:
        print(json.dumps(obj, indent=None, default=str))
    elif isinstance(obj, str):
        print(obj)
    else:
        print(json.dumps(obj, indent=2, default=str))


def cmd_sync(a, p):
    _print(api.sync(p), a.json); return 0


def cmd_data_import(a, p):
    from . import dataimport
    if a.inventory:
        _print(dataimport.inventory(p, a.module), a.json)
        return 0
    recipes = json.loads(Path(a.recipes).read_text()) if a.recipes else {}
    names = a.symbols or list(recipes)
    if a.regenerate:
        from .project import ROOT
        saved = json.loads((ROOT / 'state/dataimports' / f'{p.version}.json').read_text())
        if a.symbols:
            requested = {f'{sym.module}:{sym.name}' if (sym := p.resolve(name)) else name for name in a.symbols}
            if missing := requested - saved.keys():
                raise ValueError('no saved data import for: ' + ', '.join(sorted(missing)))
            # A shared source owns its complete split; regenerating one member
            # must retain the other objects in that same source.
            sources = {(saved[name]['module'], saved[name]['source']) for name in requested}
            names = [key for key, r in saved.items() if (r['module'], r['source']) in sources]
        else:
            names = list(saved)
        recipes = {key: recipes.get(r['symbol'], r.get('recipe')) for key, r in saved.items()}
    if not names:
        raise ValueError('provide data symbols, --recipes, or --inventory')
    result = dataimport.import_data(p, names, a.apply, recipes, a.regenerate)
    _print(result if a.json else {k: v for k, v in result.items() if k != 'records'}, a.json)
    return 1 if result['skipped'] else 0


def cmd_inventory(a, p):
    rows = api.inventory(p, a.module, a.status, a.limit, a.max_size)
    if a.json:
        _print(rows, True)
    else:
        for r in rows:
            # best is None for a function that has never been measured; printing '-' keeps
            # inventory usable on the unmeasured set instead of raising TypeError
            best = "-" if r["best"] is None else f"{r['best']:.0f}%"
            print(f"{r['status']:9s} {r['module']:13s} {r['symbol']:28s} {r['size']:6d}B  att={r['attempts']} best={best}")
        print(f"({len(rows)} functions)")
    return 0


def cmd_claim(a, p):
    started = time.monotonic()
    r = api.claim(p, a.symbol, a.agent, a.ttl, a.max_attempts, a.no_carve)
    prepared = time.monotonic()
    seed = r.get('seed') or {}
    if r['ok'] and a.check and seed and not (seed.get('kind') == 'lift_total' and '???' in seed['source']):
        # One tool slot covers preparation: a wide claim queue must not hold
        # every first model response behind a second queue of initial checks.
        r['initial_check'] = api.format_check(api.check(p, a.symbol))
    if r['ok'] and a.repair and not seed:
        # Search the best saved body before the retry costs a model request.
        try:
            r['preflight'] = api.preflight_repair(p, a.symbol, a.agent)
            if r['preflight'].get('improved'):
                from .ledger import Ledger
                r['context'] = api.build_context(p, Ledger(), a.symbol,
                                                 compiler_options=api._compiler_options(p, api._key(p, a.symbol)))
        except Exception as error:
            r['preflight'] = dict(ok=False, error=str(error)[-500:])
    r['timings'] = dict(prepare_secs=round(prepared - started, 3),
                        preflight_secs=round(time.monotonic() - prepared, 3))
    _print(r, a.json); return 0 if r["ok"] else 2


def cmd_carve(a, p):
    _print(api.carve_many(p, a.symbols, a.dry_run), a.json); return 0


def cmd_context(a, p):
    print(api.context(p, a.symbol, a.budget_tokens)); return 0


def cmd_stuck(a, p):
    from . import stuck
    out = stuck.run(p, a.min_percent, a.module, a.workers, a.max_size, a.seeds)
    if a.json:
        print(json.dumps(out, indent=1))
    else:
        print(stuck.summary(out))


def cmd_sweep(a, p):
    from . import sweep
    sweep.run(p, a.min_percent, a.max_percent, a.output, a.rounds,
              a.families.split(',') if a.families else None, a.land, a.symbols or None, a.seeds, a.recover_membercopy)


def cmd_evidence(a, p):
    from . import work_evidence as w, exemplars
    from .ledger import Ledger
    if not 1 <= a.limit <= 200 or (a.module and a.module not in p.modules):
        raise ValueError('limit must be 1..200; module must be a configured module')
    if a.action in ('packet', 'witnesses', 'eligibility', 'record', 'acknowledge') and not a.symbol:
        raise ValueError('this evidence action requires a symbol')
    if a.action == 'packet':
        result = w.packet(p, a.symbol, check=a.check, include_witnesses=a.witnesses)
    elif a.action == 'witnesses':
        result = exemplars.witnesses(p, a.symbol, a.pattern, a.limit, a.max_gap)
    elif a.action == 'clusters':
        result = w.clusters(p, a.module, a.limit)
    elif a.action == 'refresh':
        result = w.refresh(p, a.limit)
    elif a.action == 'queue':
        result = dict(queue=w.queue(p, a.limit))
    elif a.action == 'acknowledge':
        result = w.acknowledge(p, a.symbol)
    elif a.action == 'eligibility':
        result = w.eligibility(p, a.symbol)
    elif a.action == 'yield':
        result = w.yield_report(p, a.module)
    elif a.action == 'donors':
        result = w.donor_report(p)
    else:
        if a.agent:
            row = Ledger().get(api._key(p, a.symbol))
            if not row or row['status'] != 'claimed' or row['claimed_by'] != a.agent:
                _print(dict(ok=False, error='hypothesis notes require your own live claim'), a.json)
                return 2
        result = w.record_hypothesis(p, a.symbol, a.hypothesis, a.prediction, a.observation, a.outcome, a.unlock)
    _print(result, a.json)
    return 0


def cmd_tutruth(a, p):
    from . import finish, tutruth
    r = tutruth.resolve(p, a.tu, finish.Verifier(p), apply=not a.dry_run)
    print(json.dumps({k: v for k, v in r.items() if k not in ('prologue', 'adapted', 'tu_text', 'truth')}, indent=1))


def cmd_uncarve(a, p):
    from . import uncarve
    if a.stubs:
        srcs = [u["source"] for u in uncarve.stubs(p)]
    else:
        srcs = a.sources
    print(json.dumps(uncarve.uncarve(p, srcs)))


def cmd_check(a, p):
    r = api.check(p, a.symbol, a.max_diff_lines, a.versions)
    _print(r if a.json else api.format_check(r), a.json)
    if 'evidence' in r:
        return 0 if r['ok'] else 2
    if "versions" in r:
        return 0 if any(v >= 100.0 for v in r["versions"].values()) else 1
    return 0 if r["ok"] and r["matched"] else 1


def cmd_read_evidence(a, p):
    r = api.read_evidence(p, a.symbol, a.section, a.cursor)
    if a.section in ('decision', 'witnesses'):
        _print(r, a.json)
        return 0 if r.get('ok', True) else 2
    _print(r if a.json else api.format_check(r), a.json)
    return 0 if r['ok'] else 2


def cmd_levelscan(a, p):
    from . import levelscan
    r = levelscan.run(p, a.limit, Path(a.out) if a.out else levelscan._OUT,
                      not a.fresh, log=lambda m: print(m, flush=True))
    print(levelscan.format_report(r))


def cmd_levelrecheck(a, p):
    from . import levelrecheck
    r = levelrecheck.recheck(p, a.symbols or None, a.module,
                             log=(lambda m: None) if a.json else (lambda m: print(m, flush=True)))
    if a.out:
        out = Path(a.out)
        out.parent.mkdir(parents=True, exist_ok=True)
        stage = out.with_name(out.name + '.tmp')
        stage.write_text(json.dumps(r, indent=2) + '\n')
        stage.replace(out)
    if a.json:
        _print(r, True)
    else:
        print(levelrecheck.summary(r))
    return 0 if r['ok'] else 2


def cmd_structmap(a, p):
    from . import structmap
    if a.body:
        body = Path(a.body).read_text()
        r = structmap.compare(p, a.symbol, body, a.mw_version)
    elif a.skeleton:
        r = structmap.skeleton(p, a.symbol, a.base)
    else:
        r = structmap.fingerprint(p, a.symbol)
    if a.json:
        print(json.dumps(r, indent=2))
    elif a.body:
        print(structmap.format_compare(r))
    elif a.skeleton:
        print(structmap.format_skeleton(r))
    else:
        print(structmap.format_fingerprint(r))
    return 0 if r['ok'] else 2


def cmd_flagcell(a, p):
    from . import flagcell, api as _api
    body = Path(a.body).read_text() if a.body else _api._attempt_text(p, a.symbol)
    if body is None:
        print('FLAGCELL FAILED: no saved C for %s' % a.symbol)
        return 2
    r = flagcell.probe(p, a.symbol, body, a.a, a.b, a.mw_version, a.max_rows)
    if a.json:
        print(json.dumps(r, indent=2))
    else:
        print(flagcell.format_probe(r))
    return 0 if r['ok'] else 2


def cmd_submit(a, p):
    names = json.loads(Path(a.names).read_text()) if a.names else None
    r = api.submit(p, a.symbol, a.agent, a.message or "", a.harness, a.model, a.mw_version, a.extra_cflags,
                   names, a.tokens_in, a.tokens_out, a.cost_usd, a.max_diff_lines)
    _print(r, a.json); return 0 if r["ok"] else 1


def cmd_search(a, p):
    r = api.search(p, a.symbol, a.agent)
    _print(r, a.json); return 0 if r['ok'] else 2


def cmd_release(a, p):
    r = api.release(p, a.symbol, a.reason, a.harness, a.model, a.tokens_in, a.tokens_out, a.cost_usd, agent=a.agent,
                    save_only=a.save_only)
    _print(r, a.json); return 0 if r["ok"] else 2


def cmd_block(a, p):
    _print(api.block(p, a.symbol, a.reason), a.json); return 0


def cmd_unblock(a, p):
    _print(api.unblock(p, a.symbol), a.json); return 0


def cmd_report(a, p):
    r = api.report(p)
    if a.json:
        _print(r, True)
    else:
        tot = {}
        for st in r["ledger"].values():
            for k, v in st.items():
                if not k.endswith("_bytes"):
                    tot[k] = tot.get(k, 0) + v
        print("status totals:", ", ".join(f"{k}={v}" for k, v in sorted(tot.items())))
        print("costs:", r["costs"])
        if r["objdiff"]:
            print("objdiff:", r["objdiff"])
        h = r.get("honest") or {}
        if "error" in h:
            print("honest: unavailable:", h["error"])
        else:
            t = h["total"]
            print(f"honest: authored {t['authored']}/{t['credited']} credited "
                  f"({h['authored_of_credited_percent']}%), authored code "
                  f"{h['authored_code_percent']}% of {t['known_bytes']}B")
    return 0


def cmd_honest(a, p):
    """Authored-vs-credited progress, and the functions objdiff credits that we never wrote."""
    from . import progress
    if a.closure:
        c = progress.closure()
        if a.json:
            _print(c, True)
        else:
            print(progress.closure_summary(c))
        return 0
    m = progress.measure()
    if a.uncredited:
        rows = [r for r in progress.uncredited()
                if not a.module or r["module"] == a.module]
        rows.sort(key=lambda r: (r["module"], -r["size"]))
        if a.limit:
            rows = rows[:a.limit]
        if a.json:
            _print(rows, True)
            return 0
        if not rows:
            print("every credited function has a compiled C body")
            return 0
        print("%-13s %-22s %7s  %s" % ("module", "symbol", "size", "why not authored"))
        for r in rows:
            why = ("no split range" if not r["split"] else
                   "no units.json entry" if not r["registered"] else
                   "unit registered but gen/ not built" if not r["compiled"] else
                   "ledger does not call it matched")
            print("%-13s %-22s %7d  %s" % (r["module"], r["symbol"], r["size"], why))
        print("\n%d credited function(s) with no compiled C body" % len(rows))
        return 0

    if a.json:
        out = dict(m)
        out.pop("functions", None)
        if a.module:
            out["per_module"] = {a.module: m["per_module"].get(a.module, {})}
        _print(out, True)
        return 0

    t = m["total"]
    print("authored code   %8d B  %6.2f%% of %d B known"
          % (t["authored_bytes"], m["authored_code_percent"], t["known_bytes"]))
    print("credited code   %8d B  %6.2f%%  (includes retail auto objects)"
          % (t["credited_bytes"], m["credited_code_percent"]))
    print("authored fns    %8d     %6.2f%% of %d credited"
          % (t["authored"], m["authored_of_credited_percent"], t["credited"]))
    print("unmatched ledger%8d" % m["unmatched_ledger"])
    print()
    mods = m["per_module"]
    names = [a.module] if a.module else sorted(
        mods, key=lambda k: -(mods[k]["credited"] - mods[k]["authored"]))
    print("%-14s %6s %8s %8s %7s" % ("module", "known", "credited", "authored", "gap"))
    for name in names:
        v = mods.get(name)
        if not v:
            continue
        print("%-14s %6d %8d %8d %7d"
              % (name, v["known"], v["credited"], v["authored"],
                 v["credited"] - v["authored"]))
    return 0


def cmd_shapecensus(a, p):
    """Divergence-kind census of the near-miss band; see tools/fzgx/shapecensus.py."""
    from fzgx import shapecensus
    argv = ["--min-percent", str(a.min_percent), "--limit", str(a.limit)]
    if a.module:
        argv += ["--module", a.module]
    if a.json:
        argv.append("--json")
    if getattr(a, "words", False):
        argv.append("--words")
    if getattr(a, "top", None) is not None:
        argv += ["--top", str(a.top)]
    return shapecensus.main(argv)


def cmd_snapshot(a, p):
    _print(api.snapshot(p), a.json); return 0


def cmd_restore(a, p):
    _print(api.restore(p), a.json); return 0


def cmd_lint(a, p):
    findings = api.lint(p, a.paths)
    if a.json:
        _print(findings, True)
    else:
        for f, rule, line, msg in findings:
            print(f"{f}:{line}: {rule}: {msg}")
        print(f"{len(findings)} finding(s)")
    return 1 if findings else 0


def cmd_trivial(a, p):
    r = trivial.apply(p, a.module.split(",") if a.module else None, a.limit, a.dry_run)
    if not a.dry_run and not a.no_lift:
        from . import lift
        r["lift"] = lift.apply(p, a.module.split(",") if a.module else None, a.max_size, a.limit)
    _print(r, a.json); return 0


def cmd_reuse(a, p):
    from . import reuse
    _print(reuse.run(p, a.max_size, a.module, not a.no_submit), a.json)
    return 0


def cmd_harvest(a, p):
    from . import harvest
    _print(harvest.run(p, a.ref, a.label, a.land, a.workers, a.limit, a.symbol or None), a.json)
    return 0


def cmd_lift(a, p):
    from . import lift
    _print(lift.apply(p, tu=a.tu, callees=a.callee, symbols=a.symbol, submit=not a.no_submit, engine=a.engine, resume=a.resume,
                      max_size=0xFFFFFFFF if a.all else 160, limit=0 if a.all else 2000), a.json)
    return 0


def cmd_compare(a, p):
    """A/B: per-function outcome, checks, tokens and cost for two agent-id prefixes."""
    from .ledger import Ledger
    l = Ledger()
    def rows(prefix):
        out = {}
        for r in l.db.execute("SELECT symbol, outcome, checks, final_percent, tokens_in, tokens_out, cost_usd, model "
                              "FROM attempts WHERE agent LIKE ? ORDER BY id", (prefix + "%",)):
            out[r["symbol"]] = dict(r)
        return out
    A, B = rows(a.a), rows(a.b)
    syms = sorted(set(A) | set(B))
    def fmt(r):
        if not r: return "-"
        o = (r["outcome"] or "?").replace("shadow-", "")
        return f"{o[:8]:8s} {r['final_percent'] or 0:5.1f}% c={r['checks'] or 0} in={r['tokens_in'] or 0:>7} out={r['tokens_out'] or 0:>5} ${r['cost_usd'] or 0:.3f}"
    print(f"{'symbol':14s} | A: {a.a:20s} | B: {a.b}")
    for s in syms:
        print(f"{s:14s} | {fmt(A.get(s))} | {fmt(B.get(s))}")
    def tot(R):
        m = sum(1 for r in R.values() if (r["outcome"] or "").endswith("matched"))
        return f"matched {m}/{len(R)}, checks {sum(r['checks'] or 0 for r in R.values())}, tokens in {sum(r['tokens_in'] or 0 for r in R.values())} out {sum(r['tokens_out'] or 0 for r in R.values())}, ${sum(r['cost_usd'] or 0 for r in R.values()):.2f}"
    print(f"A total: {tot(A)}"); print(f"B total: {tot(B)}")
    return 0


def cmd_verify(a, p):
    if a.watch:
        if a.interval <= 0:
            raise ValueError('--interval must be positive')
        from . import verify
        verify.watch(p.version, a.interval, a.until_pid, a.stop_file, a.message)
        return 0
    r = api.verify_links(p, a.message)
    _print(r, a.json); return 0 if r.get("ok") else 1


def cmd_tu_organize(a, p):
    _print(tu.organize(p, a.module), a.json); return 0


def cmd_rename(a, p):
    if a.map:
        r = tu.rename_many(p, json.loads(Path(a.map).read_text()))
    else:
        r = tu.rename(p, a.old, a.new)
    _print(r, a.json); return 0 if r.get("ok") else 1


def cmd_naming_bundle(a, p):
    print(naming.bundle(p, a.module, a.tu, only_matched=not a.all)); return 0


def cmd_naming_apply(a, p):
    _print(naming.apply(p, json.loads(Path(a.file).read_text()), a.by), a.json); return 0




def cmd_headers(a, p):
    if a.merge_u64:
        r = structs.merge_u64(p, a.module, dry_run=a.dry_run)
        if a.json:
            _print(r, True); return 0 if r["ok"] else 1
        for lo, hi, n, users in r["pairs"]:
            print(f"{lo:22s} + {hi:22s} pair sightings {n:2d}, refs to the high half {users:2d}")
        print(f"merged {len(r['merged'])}, skipped {len(r['skipped'])}{' (dry run)' if a.dry_run else ''}", r.get("error", ""))
        for a_, b_, why in r["skipped"]:
            print(f"  skipped {a_}+{b_}: {why}")
        return 0 if r["ok"] else 1
    if a.symbol:
        info = structs.analyze(p, a.module, a.symbol)
        if a.json:
            _print(info, True); return 0
        print(f"{a.symbol}: kind={info['kind']} users={len(info['users'])} shapes={info['shapes']}")
        print(structs.typedef(info))
        for poff, fl in sorted(info.get("pointees", {}).items()):
            print(f"// pointee at +0x{poff:X}:"); print(structs.typedef(info, f"At{poff:X}", fl))
        return 0
    if a.oversize:
        rows = structs.oversize(p, a.module, a.min_refs)
        if a.json:
            _print(rows, True); return 0
        for r in rows:
            print(f"{r['symbol']:22s} {r['section']:8s} size 0x{r['size']:<6X} furthest 0x{r['furthest_access']:<6X} refs={r['refs']:3d} swallows {r['n_swallowed']}: {', '.join(r['swallows'][:6])}")
        print(f"({len(rows)} under-sized globals)")
        return 0
    if a.write:
        err = structs.write_header(p, a.module, a.tu, a.min_refs)
        if err:
            print("SELF-CHECK FAILED:\n" + err); return 1
        print("self-check: every field offset verified under MWCC"); return 0
    print(structs.tu_header(p, a.module, a.tu) if a.tu else structs.header(p, a.module, a.min_refs))
    return 0


def cmd_tu_migrate(a, p):
    r = tu.migrate(p, a.module, verify=not a.no_verify)
    _print(r, a.json); return 0 if r.get("ok") else 1


def cmd_tu_check(a, p):
    from . import tufile  # scoped: keeps the CLI import graph light; tufile pulls the project only
    ok, text = tufile.tu_check(p, a.tu)
    print(("OK" if ok else "FAILED") + f": {a.tu}")
    if text and (not ok or a.verbose):
        print(text)
    return 0 if ok else 1









def cmd_tu_finish(a, p):
    from . import finish  # scoped: the whole pass only when asked
    r = finish.finish(p, a.module)
    r.pop("results", None) if not a.verbose else None
    _print(r, a.json); return 0 if r.get("ok") else 1


def cmd_sdkmatch(a, p):
    from . import sdkmatch  # scoped: compiles a whole SDK tree; only when asked
    if a.apply:
        r = sdkmatch.apply_names(p)
        print(json.dumps(r, indent=1)); return 0 if r.get("ok") else 1
    roots = [tuple(x.split(":", 1)) for x in a.roots] if a.roots else None
    r = sdkmatch.run(p, a.sdk, a.mw, a.min_size, roots)
    print(json.dumps({k: r[k] for k in ("compiled", "sdk_functions", "dol_functions", "summary")}, indent=1))
    print(f"failed to compile: {len(r['failed'])}", r["failed"][:8])
    return 0


def cmd_sdkimport(a, p):
    from . import sdkimport
    r = sdkimport.consolidate(p, a.library) if a.consolidate else sdkimport.run(p, a.library, do_submit=not a.no_submit)
    _print(r, a.json)
    return 0 if not r.get('still') and not r.get('errors') and not r.get('failed') else 1


def cmd_sourcealign(a, p):
    from . import sourcealign
    if a.fuzzy:
        from . import fuzzy
        _print(fuzzy.run(p, a.min_size, a.root, a.rel_only), a.json)
        return 0
    if a.apply_names:
        result = sourcealign.apply_names(p)
        _print(result, a.json)
        return 0 if result['ok'] else 1
    if a.recheck_saved:
        _print(sourcealign.recheck_saved(p, a.symbol, not a.no_submit), a.json)
        return 0
    if a.compile_sdk:
        _print(sourcealign.compile_library(p, a.compile_sdk, a.root, a.functions), a.json)
        return 0
    result = sourcealign.submit_saved(p, a.symbol) if a.submit_saved else sourcealign.run(
        p, a.min_size, a.symbol, a.saved, not a.no_submit, a.discover, roots=a.root, rel_only=a.rel_only)
    _print(result, a.json)
    return 0


def cmd_why_link(a, p):
    from . import oracle  # scoped
    _print(oracle.why_link(p, a.symbol), a.json); return 0





def cmd_fixup(a, p):
    from . import fixup
    fixup.command(p, a)
    return 0


def cmd_read_unit(a, p):
    r = api.read_unit(p, a.symbol)
    _print(r if a.json else (r.get("source") or r.get("error")), a.json); return 0 if r["ok"] else 2


def cmd_write_unit(a, p):
    r = api.write_unit(p, a.symbol, a.agent, Path(a.file).read_text())
    _print(r, a.json); return 0 if r["ok"] else 2





def cmd_asm_unit(a, p):
    from . import asmunit
    from .ledger import Ledger
    syms = list(a.symbols)
    if a.blocked:
        syms += [r[0] for r in Ledger().db.execute("select symbol from functions where status='blocked'").fetchall()]
    r = asmunit.make(p, syms)
    print(json.dumps(r, indent=1)); return 0 if r.get("ok") else 2



def cmd_patch_unit(a, p):
    r = api.patch_unit(p, a.symbol, a.agent, Path(a.old_file).read_text(), Path(a.new_file).read_text())
    _print(r, a.json); return 0 if r["ok"] else 2


def build_parser() -> argparse.ArgumentParser:
    ap = argparse.ArgumentParser(prog="fzgx", description="F-Zero GX decomp agent CLI")
    ap.add_argument("--version", default="GFZE01")
    ap.add_argument("--json", action="store_true", help="machine-readable output")
    sub = ap.add_subparsers(dest="cmd", required=True)

    s = sub.add_parser('data-import', help='generate and object-verify shared data; --apply transfers splits and checks all hashes')
    s.set_defaults(fn=cmd_data_import)
    s.add_argument('symbols', nargs='*')
    s.add_argument('--apply', action='store_true')
    s.add_argument('--inventory', action='store_true')
    s.add_argument('--module')
    s.add_argument('--recipes', help='JSON string-grid layouts keyed by symbol')
    s.add_argument('--regenerate', action='store_true', help='recreate saved imports and preserve their split ownership')

    s = sub.add_parser("sync", help="load functions from dtk config into the ledger"); s.set_defaults(fn=cmd_sync)
    s = sub.add_parser("inventory", help="list functions"); s.set_defaults(fn=cmd_inventory)
    s.add_argument("--module"); s.add_argument("--status"); s.add_argument("--limit", type=int)
    s.add_argument("--max-size", type=int, help="only functions up to N bytes")
    s = sub.add_parser("claim", help="claim a function and install its saved work copy"); s.set_defaults(fn=cmd_claim)
    s.add_argument("symbol"); s.add_argument("--agent", default=os.environ.get("FZGX_AGENT_ID", "agent"))
    s.add_argument("--ttl", type=int, default=api.DEFAULT_TTL); s.add_argument("--max-attempts", type=int, default=api.MAX_ATTEMPTS)
    s.add_argument("--no-carve", action="store_true")
    s.add_argument('--check', action='store_true', help='compile a complete seed before returning the assignment')
    s.add_argument('--repair', action='store_true', help='run the deterministic search on the best saved body first; a match is submitted')
    s = sub.add_parser('search', help='deterministic search on the claimed work copy'); s.set_defaults(fn=cmd_search)
    s.add_argument('symbol'); s.add_argument('--agent', default=os.environ.get('FZGX_AGENT_ID', 'agent'))
    s = sub.add_parser("carve", help="carve functions into units without claiming"); s.set_defaults(fn=cmd_carve)
    s.add_argument("symbols", nargs="+"); s.add_argument("--dry-run", action="store_true")
    s = sub.add_parser("context", help="print the context bundle"); s.set_defaults(fn=cmd_context)
    s.add_argument("symbol"); s.add_argument("--budget-tokens", type=int, default=6000)
    s = sub.add_parser("read-unit", help="print a carved unit's source"); s.set_defaults(fn=cmd_read_unit); s.add_argument("symbol")
    s = sub.add_parser('read-evidence', help='read a cached diff or decoded retail data without compiling'); s.set_defaults(fn=cmd_read_evidence)
    s.add_argument('symbol'); s.add_argument('--section', choices=('diff', 'data', 'decision', 'witnesses'), default='diff')
    s.add_argument('--cursor', type=int, default=0)
    s = sub.add_parser('levelscan', help='probe every function with a local body for a better -O level (reports only)'); s.set_defaults(fn=cmd_levelscan)
    s = sub.add_parser("levelrecheck",
                       help="re-probe recorded levelscan levels against current bodies (reports only)")
    s.set_defaults(fn=cmd_levelrecheck)
    s.add_argument("symbols", nargs="*")
    s.add_argument("--module")
    s.add_argument("--json", action="store_true")
    s.add_argument('--limit', type=int, default=0); s.add_argument('--out', default=None); s.add_argument('--fresh', action='store_true', help='ignore any existing scan and start over')
    s = sub.add_parser('structmap', help='retail struct fingerprint: which field offsets each base register touches'); s.set_defaults(fn=cmd_structmap)
    s.add_argument('symbol'); s.add_argument('--body', help='compare retail offsets against this candidate body instead of printing the retail fingerprint'); s.add_argument('--mw-version', default=None)
    s.add_argument('--skeleton', action='store_true', help='infer a struct layout for one base register from the widths retail touches (provisional)'); s.add_argument('--base', default=None, help='base register for --skeleton (default: the most-accessed)')
    s = sub.add_parser('flagcell', help='name what a compiler setting did, by diffing our own two objects'); s.set_defaults(fn=cmd_flagcell)
    s.add_argument('symbol')
    s.add_argument('--body', help='source to probe (default: the saved body)')
    s.add_argument('--a', default='as-is', help='baseline setting: a pragma name, "pragma value", or a cflag')
    s.add_argument('--b', default='scheduling off', help='setting to compare against --a')
    s.add_argument('--mw-version', dest='mw_version', help='compiler version for both cells')
    s.add_argument('--max-rows', dest='max_rows', type=int, default=40)
    s = sub.add_parser("write-unit", help="replace a claimed unit's source from a file"); s.set_defaults(fn=cmd_write_unit)
    s.add_argument("symbol"); s.add_argument("--agent", default=os.environ.get("FZGX_AGENT_ID", "agent")); s.add_argument("--file", required=True)
    s = sub.add_parser("patch-unit", help="replace one unique span of a claimed unit's work copy, then check"); s.set_defaults(fn=cmd_patch_unit)
    s.add_argument("symbol"); s.add_argument("--agent", default=os.environ.get("FZGX_AGENT_ID", "agent")); s.add_argument("--old-file", required=True); s.add_argument("--new-file", required=True)
    s = sub.add_parser("asm-unit", help="link assembly-only functions from their own split assembly (units the build assembles); --blocked takes every blocked function"); s.set_defaults(fn=cmd_asm_unit)
    s.add_argument("symbols", nargs="*"); s.add_argument("--blocked", action="store_true")
    s = sub.add_parser("check", help="compile + objdiff one function"); s.set_defaults(fn=cmd_check)
    s.add_argument("symbol"); s.add_argument("--max-diff-lines", type=int, default=80)
    s.add_argument("--versions", help="'all' or comma list, e.g. GC/1.2.5n,GC/1.3.2: compile under each compiler and report %%")
    s = sub.add_parser("submit", help="accept a 100%% match: relink, hash, lint, commit"); s.set_defaults(fn=cmd_submit)
    s.add_argument("symbol"); s.add_argument("--agent", default=os.environ.get("FZGX_AGENT_ID", "agent")); s.add_argument("--names", help="JSON sidecar of name proposals")
    s.add_argument("--message"); s.add_argument("--max-diff-lines", type=int, default=40)
    s.add_argument("--mw-version", help="record a compiler version for this unit (e.g. GC/1.3) before relinking")
    s.add_argument("--extra-cflags", help="extra compiler flags for this unit, space separated")
    s = sub.add_parser("release", help="give up on a claim, keeping the best attempt"); s.set_defaults(fn=cmd_release)
    s.add_argument("symbol"); s.add_argument("--reason", required=True); s.add_argument("--agent", default=os.environ.get("FZGX_AGENT_ID", "agent"))
    s.add_argument('--save-only', action='store_true', help='save an interrupted attempt without compiling or repair search')
    for name in ("submit", "release"):
        sp = sub.choices[name]
        sp.add_argument("--model"); sp.add_argument("--harness")
        sp.add_argument("--tokens-in", type=int, default=0); sp.add_argument("--tokens-out", type=int, default=0)
        sp.add_argument("--cost-usd", type=float, default=0.0)
    s = sub.add_parser("block", help="record a blocked function locally"); s.set_defaults(fn=cmd_block)
    s.add_argument("symbol"); s.add_argument("--reason", required=True)
    s = sub.add_parser("unblock"); s.set_defaults(fn=cmd_unblock); s.add_argument("symbol")
    s = sub.add_parser("report", help="progress and cost summary"); s.set_defaults(fn=cmd_report)
    s = sub.add_parser("honest",
                       help="authored-vs-credited progress: matched functions with a real compiled C body")
    s.set_defaults(fn=cmd_honest)
    s.add_argument("--json", action="store_true")
    s.add_argument("--module", help="restrict the per-module table to one module")
    s.add_argument("--uncredited", action="store_true",
                   help="list the credited functions this project never wrote in C")
    s.add_argument("--limit", type=int, default=0, help="cap --uncredited output")
    s.add_argument("--closure", action="store_true",
                   help="per-module closure table: what is authored, and what each module still costs")
    s = sub.add_parser("shapecensus",
                       help="classify the near-miss band by divergence kind (is regalloc one shape?)")
    s.set_defaults(fn=cmd_shapecensus)
    s.add_argument("--min-percent", type=float, default=99.0)
    s.add_argument("--limit", type=int, default=60)
    s.add_argument("--module")
    s.add_argument("--json", action="store_true")
    s.add_argument("--words", action="store_true",
                   help="rank by differing word count instead of diff rows")
    s.add_argument("--top", type=int, default=20, help="how many to show in --words mode")
    s = sub.add_parser("snapshot", help="write state/ledger.json"); s.set_defaults(fn=cmd_snapshot)
    s = sub.add_parser("restore", help="load state/ledger.json into the local ledger"); s.set_defaults(fn=cmd_restore)
    s = sub.add_parser("lint", help="shiftability/style lint"); s.set_defaults(fn=cmd_lint); s.add_argument("paths", nargs="*")
    s = sub.add_parser("tu-organize", help="move carved units into TU directories from tus.json; relink-verify"); s.set_defaults(fn=cmd_tu_organize)
    s.add_argument("--module", default="main_rel")
    s = sub.add_parser("rename", help="rename a symbol everywhere (symbols.txt, src, units.json, ledger, file); relink-verify"); s.set_defaults(fn=cmd_rename)
    s.add_argument("old", nargs="?"); s.add_argument("new", nargs="?"); s.add_argument("--map", help="JSON {old: new} applied with one relink")
    s = sub.add_parser("naming-bundle", help="librarian bundle for one TU"); s.set_defaults(fn=cmd_naming_bundle)
    s.add_argument("tu"); s.add_argument("--module", default="main_rel"); s.add_argument("--all", action="store_true")
    s = sub.add_parser("naming-apply", help="apply a librarian proposal JSON (renames + structs)"); s.set_defaults(fn=cmd_naming_apply)
    s.add_argument("--file", required=True); s.add_argument("--by", default="librarian")
    s = sub.add_parser("headers", help="generate include/rel/<module>/globals.h for the most-referenced globals (--symbol: one global's recovered layout; --oversize: globals whose accesses exceed the symbol size)"); s.set_defaults(fn=cmd_headers)
    s.add_argument("--module", default="main_rel"); s.add_argument("--min-refs", type=int, default=20); s.add_argument("--write", action="store_true")
    s.add_argument("--tu", help="per-file header for this TU (e.g. camera.c) instead of globals.h")
    s.add_argument("--symbol", help="print the recovered struct layout of one global"); s.add_argument("--oversize", action="store_true")
    s.add_argument("--merge-u64", action="store_true", help="merge adjacent 4-byte symbols retail moves as a register pair into one u64 (relink-verified)"); s.add_argument("--dry-run", action="store_true")
    s = sub.add_parser("tu-migrate", help="stitch a module's per-function units into TU files (blocks; objects generated)"); s.set_defaults(fn=cmd_tu_migrate)
    s.add_argument("--module", default="main_rel"); s.add_argument("--no-verify", action="store_true")
    s = sub.add_parser("tu-check", help="compile a whole TU file as one unit (the goal state)"); s.set_defaults(fn=cmd_tu_check)
    s.add_argument("tu", help="e.g. rel/main_rel/camera.c"); s.add_argument("-v", "--verbose", action="store_true")
    s = sub.add_parser("tu-finish", help="one pass over every TU of a module: include, tidy, hoist, reflag, collapse complete TUs; prints the revise queue"); s.set_defaults(fn=cmd_tu_finish)
    s.add_argument("--module", default="main_rel"); s.add_argument("-v", "--verbose", action="store_true")
    s = sub.add_parser("sdkimport", help="import saved SDK C signatures with shared declarations and verified relocation bindings"); s.set_defaults(fn=cmd_sdkimport)
    s.add_argument("--library", choices=["card", "os", "exi", "si", "ar", "vi", "dvd", "gx", "dsp", "pad", "ai", "Runtime", "MSL"], default="card")
    s.add_argument("--no-submit", action="store_true", help="adapt and check C without submitting units")
    s.add_argument("--consolidate", action="store_true", help="combine complete, identified SDK source files and verify the link")
    s = sub.add_parser("sourcealign", help="recover SDK relatives and C layouts from instruction alignment and compiler probes"); s.set_defaults(fn=cmd_sourcealign)
    s.add_argument("--min-size", type=int, default=256)
    s.add_argument("--symbol", action="append", default=[])
    s.add_argument("--saved", action="store_true", help="use the saved source discovery")
    s.add_argument("--discover", action="store_true", help="only identify source relatives")
    s.add_argument("--no-submit", action="store_true")
    s.add_argument("--submit-saved", action="store_true", help="recheck and submit saved exact candidates without repeating probes")
    s.add_argument("--recheck-saved", action="store_true", help="recheck bound imports after oracle repairs without repeating layout probes")
    s.add_argument("--compile-sdk", help="compile another local SDK donor tree under build/tools")
    s.add_argument("--functions", action="store_true", help="compile donor functions independently, excluding unresolved dependencies")
    s.add_argument("--apply-names", action="store_true", help="apply unambiguous function names from verified licensed imports")
    s.add_argument("--root", action="append", default=[], help="source root relative to the SDK; filters compilation or discovery, repeatable")
    s.add_argument("--rel-only", action="store_true", help="discover matches in REL modules only")
    s.add_argument("--fuzzy", action="store_true", help="rank whole-function and partial overlap below import cutoffs")
    s = sub.add_parser("sdkmatch", help="identify SDK/runtime functions in the DOL by masked-byte signatures of a compiled public SDK decomp"); s.set_defaults(fn=cmd_sdkmatch)
    s.add_argument("--sdk", default="build/tools/mkdd"); s.add_argument("--mw", default="GC/1.2.5n"); s.add_argument("--min-size", type=int, default=16)
    s.add_argument("--apply", action="store_true", help="name the identified unnamed DOL functions from the saved runs (link-verified)")
    s.add_argument("--roots", nargs="*", help="dir:flagset pairs to compile instead of the SDK layout, e.g. src:smb")
    s = sub.add_parser("why-link", help="link with one rejected match flipped to Matching and name the bytes that differ"); s.set_defaults(fn=cmd_why_link)
    s.add_argument("symbol")
    s = sub.add_parser('fixup', help='all deterministic repairs: saved corpus, one body, graph capture and verified integration'); s.set_defaults(fn=cmd_fixup)
    s.add_argument('symbol', nargs='?'); s.add_argument('--body', type=Path)
    s.add_argument('--corpus', type=Path, help='frozen corpus; symbol filters entries, explicit --body overrides'); s.add_argument('--output', type=Path)
    s.add_argument('--captures', type=Path, help='validated PCode/allocator evidence for selected seeds')
    s.add_argument('--capture', action='store_true', help='capture stock allocator evidence for --corpus into --output')
    s.add_argument('--replay', action='store_true', help='validate existing --capture output')
    s.add_argument('--archive', type=Path, help='reproduce portable archived repair evidence')
    s.add_argument('--saved', action='store_true', help='reuse this output report without repeating search')
    s.add_argument('--clones', action='store_true', help='pool saved C across exact retail clones and repair one representative per family')
    s.add_argument('--pool-upgrades', action='store_true', help='repair accepted pool-only C into linkable matches, largest first')
    s.add_argument('--apply', action='store_true', help='submit exact results, verify all 16 hashes and commit')
    s.add_argument('--min-percent', type=float, help='minimum saved similarity (default: 95, or 0 with --clones)'); s.add_argument('--max-percent', type=float, default=100)
    s.add_argument('--module'); s.add_argument('--max-size', type=int); s.add_argument('--limit', type=int)
    s.add_argument('--rounds', type=int, default=2); s.add_argument('--beam', type=int, default=3)
    s.add_argument('--max-candidates', type=int, default=80, help='per frontier seed per round, shared by every repair family')
    s.add_argument('--budget', type=float, help='total search seconds, including compilation')
    s.add_argument('--drafts', action='store_true', help='include saved lifter bodies')
    s = sub.add_parser("stuck", help="classify plateaued attempts (>= N%%) by failure mode from the object diff"); s.set_defaults(fn=cmd_stuck)
    s.add_argument('--seeds', type=Path, help='analyse saved candidates with their recorded compiler settings')
    s.add_argument("--min-percent", type=float, default=80.0); s.add_argument("--module"); s.add_argument("--workers", type=int, default=12)
    s.add_argument("--max-size", type=int, help="only functions up to N bytes")
    s.add_argument("--json", action="store_true")
    s = sub.add_parser("sweep", help="fast repair path: every cheap family over every saved body in a range, one batched compile per round; --land submits matches and saves improvements"); s.set_defaults(fn=cmd_sweep)
    s.add_argument("symbols", nargs="*"); s.add_argument("--min-percent", type=float, default=90.0); s.add_argument("--max-percent", type=float, default=100.0)
    s.add_argument("--rounds", type=int, default=4); s.add_argument("--output", type=Path); s.add_argument("--families", help="comma-separated family names (default: all)")
    s.add_argument("--land", action="store_true")
    s.add_argument("--seeds", type=Path, help="frozen source hashes and compiler settings, as for stuck --seeds")
    s.add_argument("--recover-membercopy", action="store_true", help="select eligible historical bodies, freeze their contexts, then sweep the membercopy family")
    s = sub.add_parser('evidence', help='read-only decision packets, instruction witnesses, structural cohorts, changed-input queues and verified yield; record stores observations only')
    s.set_defaults(fn=cmd_evidence)
    s.add_argument('action', choices=('packet', 'witnesses', 'clusters', 'refresh', 'queue', 'acknowledge', 'eligibility', 'record', 'yield', 'donors'))
    s.add_argument('symbol', nargs='?')
    s.add_argument('--module')
    s.add_argument('--limit', type=int, default=10)
    s.add_argument('--check', action='store_true', help='compile the actual selected source, without a claim or match credit')
    s.add_argument('--witnesses', action='store_true')
    s.add_argument('--pattern', help='1..4 semicolon-separated PPC instructions, with register reuse preserved')
    s.add_argument('--max-gap', type=int, default=4)
    s.add_argument('--agent')
    s.add_argument('--hypothesis')
    s.add_argument('--prediction')
    s.add_argument('--observation')
    s.add_argument('--outcome', choices=('tested', 'blocked', 'improved'), default='tested')
    s.add_argument('--unlock', default='')
    s = sub.add_parser("tutruth", help="one truth per symbol for a TU file: candidate search with verified call-site adaptations; blocks that cannot follow stay self-contained"); s.set_defaults(fn=cmd_tutruth)
    s.add_argument("tu", help="e.g. rel/main_rel/font.c"); s.add_argument("--dry-run", action="store_true")
    s = sub.add_parser("uncarve", help="drop units that have no matched code (rejected, or every stub with --stubs); re-splits"); s.set_defaults(fn=cmd_uncarve)
    s.add_argument("sources", nargs="*"); s.add_argument("--stubs", action="store_true")
    s = sub.add_parser("verify", help="relink once for all accepted units, verify hashes, commit; bisect on failure"); s.set_defaults(fn=cmd_verify)
    s.add_argument("--message")
    s.add_argument('--watch', action='store_true', help='verify completed matches periodically, independent of model sessions')
    s.add_argument('--interval', type=float, default=60, help='seconds between pending-work checks in watch mode')
    s.add_argument('--until-pid', type=int, help='watch until this parent exits, then drain once more')
    s.add_argument('--stop-file', type=Path, help='stop between transactions when this file exists, after a final drain')
    s = sub.add_parser("compare", help="A/B table for two agent-id prefixes (e.g. b3c-claude vs shadow-b3c-codex)"); s.set_defaults(fn=cmd_compare)
    s.add_argument("--a", required=True); s.add_argument("--b", required=True)
    s = sub.add_parser("trivial", help="mechanically match single-blr and `li r3,N; blr` functions"); s.set_defaults(fn=cmd_trivial)
    s.add_argument("--module", help="comma list; default all"); s.add_argument("--limit", type=int); s.add_argument("--dry-run", action="store_true"); s.add_argument("--no-lift", action="store_true"); s.add_argument("--max-size", type=int, default=160)
    s = sub.add_parser("reuse", help="reuse verified C for identical retail instruction shapes"); s.set_defaults(fn=cmd_reuse)
    s.add_argument("--module"); s.add_argument("--max-size", type=int, default=255)
    s.add_argument("--no-submit", action="store_true")
    s = sub.add_parser("harvest", help="land C matched on another ref (fork or cloud branch); see docs/CLOUD.md")
    s.set_defaults(fn=cmd_harvest)
    s.add_argument("ref", help="git ref, e.g. fork-deltawave784/windows-and-types or origin/claude/...")
    s.add_argument("--label", help="provenance label (default REF@sha)")
    s.add_argument("--land", action="store_true", help="submit oracle matches (default: screen only)")
    s.add_argument("--workers", type=int, default=4); s.add_argument("--limit", type=int)
    s.add_argument("--symbol", action="append", help="restrict to these symbols (repeatable)")
    s = sub.add_parser('lift', help='lift unmatched functions in a TU or callers of a shared interface'); s.set_defaults(fn=cmd_lift)
    scope = s.add_mutually_exclusive_group(required=True)
    scope.add_argument('--tu', help='TU path relative to src/, e.g. rel/main_rel/accessory.c')
    scope.add_argument('--callee', action='append', help='direct callee to select callers of; repeat for a shared interface')
    scope.add_argument('--symbol', action='append', help='regenerate selected functions without a size cap; repeatable')
    scope.add_argument('--all', action='store_true', help='all unmatched functions, without a size or count cap')
    s.add_argument('--engine', choices=('lift', 'm2c'), default='lift')
    s.add_argument('--resume', action='store_true', help='reuse saved m2c candidates and retry generation or compilation failures')
    s.add_argument('--no-submit', action='store_true')
    return ap


def worker_main():
    """Serve one host-bound request at a time, retaining immutable project indexes."""
    import contextlib
    import io
    import sys
    import traceback
    project = None
    stamp = None
    bindings = ('FZGX_AGENT_ID', 'FZGX_SYMBOL', 'FZGX_HARNESS', 'FZGX_MODEL', 'FZGX_RESULT_FILE')
    for line in sys.stdin:
        stdout, stderr = io.StringIO(), io.StringIO()
        rc = 1
        with contextlib.redirect_stdout(stdout), contextlib.redirect_stderr(stderr):
            try:
                request = json.loads(line)
                for key in bindings:
                    os.environ.pop(key, None)
                env = request['env']
                if set(env) - set(bindings) or not env.get('FZGX_AGENT_ID') or not env.get('FZGX_SYMBOL'):
                    raise ValueError('tool worker requires a host-bound function and agent')
                os.environ.update(env)
                if project is None:
                    project = Project()
                paths = [project.config_dir / 'config.yml', project.units_path,
                         project.build_dir / 'config.json', project.config_dir.parent.parent / 'objdiff.json']
                paths += [project.module_config_dir(m) / 'symbols.txt' for m in project.modules]
                current = tuple((str(f), f.stat().st_mtime_ns, f.stat().st_size)
                                for f in paths if f.exists())
                if current != stamp:
                    project = Project()
                    stamp = current
                rc = main(request['args'], project=project)
            except SystemExit as error:
                rc = error.code if isinstance(error.code, int) else 1
            except Exception:
                traceback.print_exc()
            finally:
                for key in bindings:
                    os.environ.pop(key, None)
        print(json.dumps(dict(rc=rc, stdout=stdout.getvalue(), stderr=stderr.getvalue())), flush=True)
    return 0


def main(argv: Optional[List[str]] = None, project=None) -> int:
    import sys
    if (sys.argv[1:] if argv is None else argv) == ['--tool-worker']:
        return worker_main()
    a = build_parser().parse_args(argv)
    assigned = os.environ.get("FZGX_SYMBOL")
    if assigned:
        if (a.cmd not in {"claim", "context", "read-unit", "read-evidence", "write-unit", "patch-unit", "check", "search", "submit", "release"}
                or getattr(a, "symbol", None) != assigned
                or getattr(a, "agent", os.environ["FZGX_AGENT_ID"]) != os.environ["FZGX_AGENT_ID"]):
            _print({"ok": False, "error": "tool call is outside this worker's assigned function and identity"}, a.json)
            return 2
        from . import oracle
        lock = "worker-" + hashlib.sha256(assigned.encode()).hexdigest() + ".lock"
        with oracle.build_lock(lock):
            p = project if project is not None and project.version == a.version else Project(a.version)
            rc = a.fn(a, p)
            result_file = os.environ.get('FZGX_RESULT_FILE')
            if result_file:
                from .ledger import Ledger
                attempt = Ledger().db.execute(
                    'SELECT * FROM attempts WHERE symbol=? AND agent=? ORDER BY id DESC LIMIT 1',
                    (api._key(p, assigned), os.environ['FZGX_AGENT_ID'])).fetchone()
                if attempt and attempt['ended'] is not None:
                    path = Path(result_file)
                    path.parent.mkdir(parents=True, exist_ok=True)
                    temporary = path.with_suffix('.tmp')
                    temporary.write_text(json.dumps(dict(attempt)) + '\n')
                    temporary.replace(path)
            return rc
    return a.fn(a, Project(a.version))
