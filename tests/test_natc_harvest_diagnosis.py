#!/usr/bin/env python3
"""Harvest must say WHY a solved function cannot be packaged.

2026-08-31. `natc_harvest` reported `PACKAGEABLE (full preflight clean): 0`
against 98 recoverable solves and gave no reason for a single one:
`build_packageable_batches` drops a row with a bare `continue` in three
places, and `refusal_reason` keeps only the first line matching a keyword --
which is the preflight banner, never the compiler's actual diagnostic.

So "0 packageable / 98 need re-conversion" was reported through three audits
as if it meant 98 genuinely stale conversions. Instrumenting it by hand shows
it is nothing of the kind:

    27  splice emitted malformed C ("declaration syntax error", "')' expected")
    18  genuinely scores <100 against the current head
    15  signature conflict (head's old no-prototype decl vs recovered defn)
     7  declaration left behind by the splice (undefined identifier/label)
     6  source-form refusal
     5  splice raised
     5  no per-symbol provenance

Those are four different bugs and one real backlog. A number with no cause
attached cannot be worked, so this pins the causes.
"""
import importlib.util
import sys
import tempfile
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))


def _load():
    spec = importlib.util.spec_from_file_location(
        "natc_harvest", REPO / "tools/natc_harvest.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


@pytest.fixture(scope="module")
def H():
    return _load()


REDECLARED = """SCORE REFUSAL:
  main/game/axmix: candidate does not COMPILE against the current head —
### mwcceppc.exe Compiler:
#    1799: {
#   Error: ^
#   identifier 'axmix_ctrl_init_type14()' redeclared
#   was declared as: 'void ()'
#   now declared as: 'void (void *)'
"""

SYNTAX = """SCORE REFUSAL:
  main/dolphin/card/CARDDir: candidate does not COMPILE against the current head —
### mwcceppc.exe Compiler:
#    2759: s32 CARDClose(CARDFileInfo* fileInfo) {
#   Error:     ^^^^^^^^^
#   declaration syntax error
"""

UNDEFINED = """SCORE REFUSAL:
  main/dolphin/gx/GXFifo: candidate does not COMPILE against the current head —
### mwcceppc.exe Compiler:
#   Error: undefined identifier 'GXWGFifoV'
"""

STALE = """SCORE REFUSAL:
  main/game/gxstate: scores 97.051 against the CURRENT head, not 100. Your
  measurement was against a stale base — rebase the candidate
"""

SOURCE_FORM = """SOURCE-FORM REFUSAL:
  unit.c: instruction-word array forbidden
"""


def test_signature_conflict_is_named(H):
    assert H.classify_preflight_refusal(REDECLARED) == "signature-conflict"


def test_call_signature_mismatch_is_a_signature_conflict(H):
    text = ("does not COMPILE against the current head —\n"
            "#   Error: function call 'fn_80003590(char *, int, int)' does not "
            "match\n#   'fn_80003590()'\n")
    assert H.classify_preflight_refusal(text) == "signature-conflict"


def test_malformed_splice_output_is_named(H):
    assert H.classify_preflight_refusal(SYNTAX) == "splice-syntax"


def test_paren_expected_is_also_malformed_splice_output(H):
    text = "does not COMPILE against the current head —\n#   Error: ')' expected\n"
    assert H.classify_preflight_refusal(text) == "splice-syntax"


def test_missing_declaration_is_named(H):
    assert H.classify_preflight_refusal(UNDEFINED) == "missing-declaration"


def test_stale_score_is_named_and_not_called_a_compile_error(H):
    assert H.classify_preflight_refusal(STALE) == "stale-score"


def test_source_form_is_named(H):
    assert H.classify_preflight_refusal(SOURCE_FORM) == "source-form"


def test_an_unrecognised_refusal_is_not_silently_bucketed(H):
    # A cause this tool does not know must be visible as unknown, never folded
    # into a named bucket -- that is how "0 packageable" became unreadable.
    assert H.classify_preflight_refusal("something new\n") == "unclassified"


def test_refusal_reason_keeps_the_compiler_diagnostic(H):
    # The old version returned only the banner line, so every one of the 64
    # compile failures read "candidate does not COMPILE" and nothing else.
    class R:
        stdout = REDECLARED
        stderr = ""
    text = H.refusal_reason(R())
    assert "redeclared" in text


def test_batches_account_for_every_dropped_row(H):
    """Accepted + refused must equal the rows in. No silent `continue`."""
    with tempfile.TemporaryDirectory() as td:
        root = Path(td)
        dest = root / "unit.c"
        good = root / "good.c"
        noprov = root / "noprov.c"
        dest.write_text("asm int one(void) { return 0; }\n"
                        "asm int two(void) { return 0; }\n")
        good.write_text("// provenance: original\nint one(void) { return 1; }\n")
        # `two` is not defined here at all, so the rebase cannot splice it.
        noprov.write_text("// provenance: original\nint other(void) { return 2; }\n")
        rows = [
            ("main/test", "one", 100.0, good, dest, "test", 0),
            ("main/test", "two", 100.0, noprov, dest, "test", 0),
        ]
        stats = {}
        batches = H.build_packageable_batches(
            rows, validator=lambda *a, **k: True, stats=stats)
        accepted = sum(len(items) for items, _ in batches.values())
        refused = sum(stats["refusals"].values())
        assert accepted + refused + stats["deferred_by_cap"] == len(rows)
        # `two` has no recovered definition, so it is refused with a NAMED
        # cause -- never dropped silently and never left "unclassified".
        assert refused == 1
        assert stats["refusals"]["no-provenance"] == 1
        assert "unclassified" not in stats["refusals"]


def test_validator_refusals_are_recorded_with_their_cause(H):
    with tempfile.TemporaryDirectory() as td:
        root = Path(td)
        dest = root / "unit.c"
        one = root / "one.c"
        dest.write_text("asm int one(void) { return 0; }\n")
        one.write_text("// provenance: original\nint one(void) { return 1; }\n")
        rows = [("main/test", "one", 100.0, one, dest, "test", 0)]

        def validator(text, d, unit, reasons=None):
            if reasons is not None:
                reasons.append("signature-conflict")
            return False

        stats = {}
        H.build_packageable_batches(rows, validator=validator, stats=stats)
        assert stats["refusals"]["signature-conflict"] == 1
