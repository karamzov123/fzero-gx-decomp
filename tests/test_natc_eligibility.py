#!/usr/bin/env python3
"""The eligible denominator must be conservative and must not creep.

Audit F9. Understating the ceiling is safe; overstating it retires functions
that C could actually have produced. The first hand count of this made exactly
that mistake -- it swept in lmw/stmw and mtcrf and reported 394 ineligible
functions when the honest figure is 178 -- so the exclusions below are pinned
by test, not by intention.
"""
from __future__ import annotations
import importlib.util
import sqlite3
import sys
import tempfile
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TOOL = REPO / "tools/natc_eligibility.py"


def _mod():
    sys.path.insert(0, str(REPO / "tools"))
    spec = importlib.util.spec_from_file_location("natc_eligibility_t", TOOL)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def test_plain_integer_body_is_eligible():
    m = _mod()
    assert m.classify("    lwz r3, 0(r4)\n    addi r3, r3, 1\n    blr\n") == []


def test_paired_single_is_ineligible():
    m = _mod()
    assert m.classify("    psq_l f1, 0(r3), 0, 0\n    ps_madd f1,f1,f1,f1\n") \
        == ["paired-single"]


def test_supervisor_is_ineligible():
    m = _mod()
    assert m.classify("    mfmsr r3\n    mtmsr r4\n    rfi\n") == ["supervisor"]


def test_compiler_emittable_instructions_are_NOT_counted():
    """These are the ones the first hand count got wrong. MWCC emits every one
    of them from ordinary C, so a function using them is still convertible."""
    m = _mod()
    for emittable in ("    lmw r26, 8(r1)\n",
                      "    stmw r26, 8(r1)\n",
                      "    mtcrf 0xff, r3\n",
                      "    mfcr r3\n",
                      "    mffs f0\n",
                      "    mtfsf 7, f0\n",
                      "    lswi r3, r4, 8\n",
                      "    stswi r3, r4, 8\n"):
        assert m.classify(emittable) == [], f"{emittable.strip()} is emittable"


def test_asm_bodies_are_brace_matched():
    """An asm body is full of braces-free text but the extractor must still
    stop at the right place, or one function's classification leaks into the
    next and inflates the ineligible count."""
    m = _mod()
    src = (
        "asm void First(void)\n{\n    nofralloc\n    psq_l f1, 0(r3), 0, 0\n    blr\n}\n"
        "\n"
        "asm void Second(void)\n{\n    nofralloc\n    li r3, 0\n    blr\n}\n"
    )
    bodies = m.asm_bodies(src)
    assert set(bodies) == {"First", "Second"}
    assert m.classify(bodies["First"]) == ["paired-single"]
    assert m.classify(bodies["Second"]) == [], "leak from the previous body"


def test_scan_of_the_real_tree_stays_conservative():
    """A regression here means the classifier started retiring functions that
    plain C could reach. The bound is deliberately loose -- it is a tripwire
    for a class mistake, not a pin on the exact count, which moves as
    conversions land."""
    m = _mod()
    s = m.summarise(m.scan())
    assert s["asm_functions"] > 1000, "scan found almost nothing — extractor broke"
    frac = s["ineligible"] / s["asm_functions"]
    assert 0.03 < frac < 0.15, (
        f"{s['ineligible']}/{s['asm_functions']} = {frac:.1%} ineligible; "
        f"outside the conservative band, re-check the instruction classes")
    assert set(s["by_class"]) <= {"paired-single", "supervisor", "cache/sync"}


def test_apply_routes_only_ineligible_symbols_without_erasing_terminal_evidence():
    m = _mod()
    rows = [
        {"file": "src/a.c", "unit": "main/a", "symbol": "ps", "blockers": ["paired-single"]},
        {"file": "src/a.c", "unit": "main/a", "symbol": "plain", "blockers": []},
    ]
    with tempfile.TemporaryDirectory() as td:
        db = Path(td) / "runs.sqlite"
        assert m.apply_classifications(rows, db) == 1
        con = sqlite3.connect(db)
        assert con.execute("select status from symbol_states where symbol='ps'").fetchone()[0] == "inline_asm_required"
        assert con.execute("select 1 from symbol_states where symbol='plain'").fetchone() is None
        con.execute("update symbol_states set status='terminal',evidence='manual' where symbol='ps'")
        con.commit(); con.close()
        assert m.apply_classifications(rows, db) == 0
        con = sqlite3.connect(db)
        assert con.execute("select status,evidence from symbol_states where symbol='ps'").fetchone() == ("terminal", "manual")
        con.close()
