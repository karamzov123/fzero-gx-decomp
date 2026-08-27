#!/usr/bin/env python3
"""Regression tests for natc_gate.completeness_check (2026-08-26 re-review).

The check used to decide a sibling was "present" by WORD presence (\\bname\\b
anywhere in the candidate). That is blind to a dropped definition that leaves a
declaration, call, or comment behind. CARDBlock's `asm void __CARDUnlock` was
removed from a candidate while `extern void __CARDUnlock(void);` stayed; the
word survived, completeness_check passed, the gate went green, and the link died
on an undefined symbol. The fix requires the sibling to remain DEFINED (asm or
C) in the candidate.

These tests run against a tiny synthetic dest/cand pair, no real tree or build.
"""
import importlib.util
import re
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SPEC = importlib.util.spec_from_file_location(
    "natc_gate", ROOT / "tools" / "natc_gate.py")
gate = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(gate)


def _cand(name="cand.c"):
    return Path("/tmp") / name


# completeness_check builds an error string via dest.relative_to(REPO), so the
# synthetic dest must live somewhere under the repo root.
def _dest(name="dest.c"):
    p = ROOT / ".cache" / "natc_gate_test" / name
    p.parent.mkdir(parents=True, exist_ok=True)
    return p


# A head with one asm body and one extern declaration that names the same
# function (exactly the CARDBlock shape: `asm void __CARDUnlock` + `extern void
# __CARDUnlock(void);`).
HEAD = """\
// dest: src/dolphin/card/CARDBlock.c
#pragma force_active on
extern void __CARDUnlock(void);
asm void __CARDUnlock(void) {
    blr
}
int sibling_keep(int x) { return x + 1; }
#pragma force_active off
"""


class CompletenessPresenceTests(unittest.TestCase):

    def test_dropped_asm_body_but_extern_kept_is_refused(self):
        """The CARDBlock incident: body gone, `extern` decl survives. Must
        be refused now (was a false green before)."""
        # candidate = head minus the asm body, extern decl stays
        cand_text = re.sub(r"(?s)asm\s+void\s+__CARDUnlock\s*\(void\)\s*\{.*?\}\n",
                           "", HEAD)
        self.assertIn("extern void __CARDUnlock", cand_text)
        self.assertNotIn("asm void __CARDUnlock", cand_text)
        cand = _cand(); cand.write_text(cand_text)
        dest = _dest(); dest.write_text(HEAD)
        errs = gate.completeness_check([(cand, dest)])
        self.assertTrue(
            errs,
            "dropped asm body (extern kept) must be refused, not a false green")
        self.assertIn("__CARDUnlock", "\n".join(errs))

    def test_dropped_c_def_named_in_removes_ack_passes(self):
        """An honest worker may remove a converted C sibling on purpose if
        they record it with `removes:` in CARD.md (e.g. an inlined static
        helper). Lost ASM bodies are never acked (asm cannot be inlined away),
        so this exercises the C branch."""
        head = HEAD + "\nstatic int helper_drop(int x) { return x * 2; }\n"
        cand_text = re.sub(r"static int helper_drop\(int x\) \{ return x \* 2; \}\n",
                           "", head)
        cand = _cand(); cand.write_text(cand_text)
        dest = _dest(); dest.write_text(head)
        card = "removes: helper_drop — inlined into sibling_keep\n"
        errs = gate.completeness_check([(cand, dest)], card_text=card)
        self.assertFalse(errs, f"removes:-acked C drop must pass, got {errs}")

    def test_asm_to_c_conversion_is_not_lost(self):
        """Converting an asm body to a C definition is the whole point; it must
        NOT be flagged as lost."""
        cand_text = HEAD.replace(
            "asm void __CARDUnlock(void) {\n    blr\n}\n",
            "void __CARDUnlock(void) { /* converted */ }\n")
        cand = _cand(); cand.write_text(cand_text)
        dest = _dest(); dest.write_text(HEAD)
        errs = gate.completeness_check([(cand, dest)])
        self.assertFalse(errs, f"asm->C conversion must pass, got {errs}")

    def test_intact_candidate_passes(self):
        cand = _cand(); cand.write_text(HEAD)
        dest = _dest(); dest.write_text(HEAD)
        errs = gate.completeness_check([(cand, dest)])
        self.assertFalse(errs, f"intact candidate must pass, got {errs}")


if __name__ == "__main__":
    unittest.main()
