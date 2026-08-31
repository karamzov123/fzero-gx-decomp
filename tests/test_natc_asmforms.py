# Pins the three source forms natc_metrics must tell apart.
#
# 2026-08-31. The mission headline is "exact natural-C functions". It was
# inflated: `natc_metrics.asm_symbols()` only recognises an `asm void f()`
# whole-function body, so a C-signatured function whose body is nothing but
# an `asm { }` block scored 100%, appeared in the objdiff right-side symbol
# list, and was counted as an exact natural-C conversion. 26 such functions
# were in src/ at HEAD -- 15 of them containing not one line of C.
#
# Three forms, three verdicts:
#   asm void f()            -> asm body        (already handled, unconverted)
#   void f() { asm {...} }  -> asm WRAPPER     (unconverted; must NOT be exact)
#   void f() { C; asm{}; C} -> hybrid          (complete source, NOT natural C)
#   void f() { C only }     -> exact natural C (the mission number)

import importlib.util
from pathlib import Path

import pytest


def _load():
    repo = Path(__file__).resolve().parent.parent
    spec = importlib.util.spec_from_file_location(
        "natc_asmforms", repo / "tools" / "natc_asmforms.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


@pytest.fixture(scope="module")
def af():
    return _load()


WRAPPER = """
void UnsetRun(register void* thread)
{
    asm
    {
    lwz     r4, 0x2e0(r3)
    blr
    }
}
"""

HYBRID = """
BOOL OSDisableInterrupts(void)
{
    register BOOL level;
    asm { mfmsr level }
    return level;
}
"""

PURE_C = """
int add(int a, int b)
{
    return a + b;
}
"""

ASM_BODY = """
asm void fn_80001234(void)
{
    nofralloc
    blr
}
"""


def test_wrapper_is_not_natural_c(af):
    w, h = af.classify_inline_asm(WRAPPER)
    assert w == {"UnsetRun"}
    assert h == set()


def test_hybrid_is_separated_from_wrapper(af):
    w, h = af.classify_inline_asm(HYBRID)
    assert w == set()
    assert h == {"OSDisableInterrupts"}


def test_pure_c_is_neither(af):
    assert af.classify_inline_asm(PURE_C) == (set(), set())


def test_asm_function_body_is_not_an_inline_asm_form(af):
    # `asm void f()` is already counted as an asm body by asm_symbols();
    # classifying it here too would double-count it out of the denominator.
    assert af.classify_inline_asm(ASM_BODY) == (set(), set())


def test_comment_mentioning_asm_does_not_trip_it(af):
    src = """
int f(void)
{
    /* the retail asm here uses lwz; we reproduce it in C */
    return 1;
}
"""
    assert af.classify_inline_asm(src) == (set(), set())


def test_asm_volatile_paren_form_is_caught(af):
    src = """
u32 get_sp(void)
{
    register u32 sp;
    __asm__ volatile ("mr %0, r1" : "=r"(sp));
    return sp;
}
"""
    w, h = af.classify_inline_asm(src)
    assert w == set() and h == {"get_sp"}


def test_head_of_repo_matches_the_audited_counts(af):
    # Regression pin for the 2026-08-31 audit. If these move, the headline
    # moved with them and the change must be deliberate.
    repo = Path(__file__).resolve().parent.parent
    wrap, hyb = set(), set()
    for p in (repo / "src").rglob("*.c"):
        w, h = af.classify_inline_asm(p.read_text(errors="replace"))
        wrap |= w
        hyb |= h
    assert len(wrap) == 15, sorted(wrap)
    assert len(hyb) == 11, sorted(hyb)
