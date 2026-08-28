#!/usr/bin/env python3
"""A compile whose named symbol is still `asm` is a no-op, not an attempt.

2026-08-28 audit. Compiling a source in which --symbol still carries an asm
body scores 100 by construction: the asm assembles to the target bytes. That
is exactly why matched_code is a diagnostic in this tree, and natc_harvest
already has to re-derive "was this actually a conversion" from gate.asm_defs
before it will trust a 100 -- it finds 97 functions recorded at 100 whose
source is still assembly.

Left as kind='attempt' those rows do two kinds of damage: they spend a
worker's 12-try budget for doing nothing, and natc_harvest.proven() has to
filter them out again downstream. kind='noop' is excluded by the same
`kind is null or kind='attempt'` predicate that already excludes verify and
discriminate rows.

The classifier must fail OPEN: mislabelling a real attempt as a no-op would
silently exempt it from the budget, which is the worse error.
"""
from __future__ import annotations
import importlib.util
import sys
import types
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
TOOL = REPO / "tools/natc_compile.py"

ASM_BODY = """\
#pragma push
#pragma force_active on
asm void Target(void)
{
    nofralloc
    blr
}
#pragma pop
"""

C_BODY = """\
#pragma push
#pragma force_active on
// provenance: original Target
void Target(void)
{
}
#pragma pop
"""


def _mod():
    sys.path.insert(0, str(REPO / "tools"))
    spec = importlib.util.spec_from_file_location("natc_compile_noop", TOOL)
    m = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(m)
    return m


def _args(**kw):
    base = dict(discriminate=False, worker="natc9", model="hy3",
                symbol="Target", src=None)
    base.update(kw)
    return types.SimpleNamespace(**base)


def test_asm_bodied_symbol_is_noop(tmp_path):
    m = _mod()
    src = tmp_path / "unit.c"
    src.write_text(ASM_BODY)
    assert m.attempt_kind(_args(src=str(src))) == "noop"


def test_converted_symbol_is_a_real_attempt(tmp_path):
    m = _mod()
    src = tmp_path / "unit.c"
    src.write_text(C_BODY)
    assert m.attempt_kind(_args(src=str(src))) == "attempt"


def test_sibling_asm_does_not_make_it_a_noop(tmp_path):
    """Converting one function in a file that still has asm siblings is the
    normal case and must stay a real attempt."""
    m = _mod()
    src = tmp_path / "unit.c"
    src.write_text(C_BODY + "\n" + ASM_BODY.replace("Target", "Sibling"))
    assert m.attempt_kind(_args(src=str(src))) == "attempt"


def test_classifier_fails_open(tmp_path):
    """Unreadable or absent source must not be labelled a no-op -- that would
    exempt a real attempt from the budget."""
    m = _mod()
    assert m.attempt_kind(_args(src=None)) == "attempt"
    assert m.attempt_kind(_args(src=str(tmp_path / "missing.c"))) == "attempt"
    assert m.submitted_symbol_is_asm(_args(symbol="", src=None)) is False


def test_verify_and_discriminate_still_win(tmp_path):
    """The no-op label only ever replaces 'attempt'; it must not swallow the
    integrator's verify rows or a discriminator sweep."""
    m = _mod()
    src = tmp_path / "unit.c"
    src.write_text(ASM_BODY)
    assert m.attempt_kind(_args(src=str(src), discriminate=True)) == "discriminate"
    assert m.attempt_kind(_args(src=str(src), worker="integ")) == "verify"
    assert m.attempt_kind(_args(src=str(src), model="preflight")) == "verify"
