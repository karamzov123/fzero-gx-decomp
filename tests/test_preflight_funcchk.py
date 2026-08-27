#!/usr/bin/env python3
"""Regression test for natc_preflight.rescore's build-free FUNCCHECK.

The documented deliverability failure: preflight reports a candidate 100% clean
(per-function diff score) yet the full-DOL gate then fails the SHA because a
FUNC symbol was silently dropped — the link emitted a stub or the DOL layout
shifted, and the per-function score could never see it. natc_preflight.rescore
now mirrors the gate's own FUNCCHECK by reading the recompiled object's ELF FUNC
set and comparing it to the unit's current obj/ object.

This test exercises that logic directly (no real compile, no build) by
monkeypatching the two external seams: the natc_compile subprocess and
gate.elf_funcs.
"""
import importlib.util
import io
import json
import unittest
from pathlib import Path
from unittest import mock

ROOT = Path(__file__).resolve().parent.parent
SPEC = importlib.util.spec_from_file_location(
    "natc_preflight", ROOT / "tools" / "natc_preflight.py")
pf = importlib.util.module_from_spec(SPEC)
# import natc_gate alongside so monkeypatching its elf_funcs works through pf
import sys
sys.path.insert(0, str(ROOT / "tools"))
import natc_gate as gate
SPEC.loader.exec_module(pf)


class FakeCompileResult:
    def __init__(self, obj_path, ok=True, score=100.0, refused=False,
                 stderr="", write_file=True):
        self.obj_path = obj_path
        self.ok = ok
        self.score = score if score is not None else 100.0
        self.refused = refused
        self.stderr = stderr
        self.returncode = 0
        self.stdout = json.dumps({
            "ok": ok, "obj_path": obj_path, "diff_score": score,
            "refused": refused, "stderr": stderr})
        # rescore stats the produced object; create it so the path resolves.
        if write_file and obj_path:
            Path(obj_path).write_text("")


def _run_rescore(pairs, compile_results, want_funcs, got_funcs):
    """Run rescore with patched natc_compile + elf_funcs."""
    calls = {"i": 0}

    def fake_run(cmd, **kw):
        # cmd is [python3, tools/natc_compile.py, ...] — return the next result
        r = compile_results[calls["i"]]
        calls["i"] += 1
        out = r.stdout
        class R:
            returncode = 0
            stdout = out
            stderr = ""
        return R()

    def fake_elf(obj):
        p = str(obj)
        # The unit's target object lives under build/GFZE01/obj/...; the
        # freshly recompiled candidate is the [temporary path]/recomp.o produced by the
        # faked natc_compile. Discriminate on the candidate suffix so the mock
        # returns the right FUNC set for each (the real rescore relies on the
        # path coming from out["obj_path"] vs. the unit's target_path).
        if p.endswith("recomp.o"):       # the freshly recompiled candidate
            return dict(got_funcs)
        return dict(want_funcs)          # the unit's current object

    with mock.patch.object(gate, "elf_funcs", side_effect=fake_elf), \
         mock.patch("subprocess.run", side_effect=fake_run):
        problems = pf.rescore(pairs, "tool")
    return problems


class PreflightFuncCheckTests(unittest.TestCase):

    def test_lost_func_symbol_is_refused(self):
        """Candidate scores 100% but its object drops a sibling FUNC symbol."""
        pairs = [(Path("[temporary path]/cand.c"), ROOT / "src/dolphin/card/CARDBlock.c")]
        # natc_compile returns a 100% object whose FUNC set lacks __CARDUnlock
        res = [FakeCompileResult("[temporary path]/recomp.o", score=100.0)]
        want = {"__CARDUnlock": 12, "sibling_keep": 8}
        got = {"sibling_keep": 8}        # __CARDUnlock vanished
        problems = _run_rescore(pairs, res, want, got)
        self.assertTrue(problems, "lost FUNC symbol must be refused")
        self.assertIn("FUNCCHECK", "\n".join(problems))
        self.assertIn("__CARDUnlock", "\n".join(problems))

    def test_no_lost_func_symbol_passes(self):
        """Candidate keeps every FUNC symbol — clean."""
        pairs = [(Path("[temporary path]/cand.c"), ROOT / "src/dolphin/card/CARDBlock.c")]
        res = [FakeCompileResult("[temporary path]/recomp.o", score=100.0)]
        want = {"__CARDUnlock": 12, "sibling_keep": 8}
        got = {"__CARDUnlock": 12, "sibling_keep": 8}
        problems = _run_rescore(pairs, res, want, got)
        self.assertFalse(problems, f"intact FUNC set must pass, got {problems}")

    def test_compile_error_is_reported_not_funcchk(self):
        pairs = [(Path("[temporary path]/cand.c"), ROOT / "src/dolphin/card/CARDBlock.c")]
        res = [FakeCompileResult(None, ok=False, score=None,
                                 stderr="error: syntax")]
        want = {"__CARDUnlock": 12}
        got = {}
        problems = _run_rescore(pairs, res, want, got)
        self.assertTrue(problems)
        # compile failure is the reported class, not FUNCCHECK
        self.assertFalse(any("FUNCCHECK" in p for p in problems))
        self.assertIn("does not COMPILE", "\n".join(problems))


if __name__ == "__main__":
    unittest.main()
