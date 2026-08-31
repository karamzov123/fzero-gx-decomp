#!/usr/bin/env python3
"""Rebasing a recovered definition must also fix the head's stale declaration.

2026-08-31, the dominant cause of the stranded backlog. A unit under
conversion carries BOTH a forward declaration and an asm definition:

    extern void CARDClose(void);        <- line 39
    ...
    asm void CARDClose(void) { ... }    <- line 2751

`build_rebased_symbol` replaced the definition and left the declaration
alone, so every rebased artifact declared `void CARDClose(void)` and then
defined `s32 CARDClose(CARDFileInfo*)`. MWCC refuses that -- as
"declaration syntax error" when it cannot reconcile the two, and as
"identifier redeclared / was declared as / now declared as" when it can.

Those were being counted as two different problems (`splice-syntax` 33 and
`signature-conflict` 20) and read as 53 stale conversions needing redoing.
They are one missing rewrite. The recovered DEFINITION is the evidence: it
compiled to the retail bytes, so the declaration is what must move.
"""
import importlib.util
import sys
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


HEAD = """\
extern void CARDClose(void);
extern void CARDOpen(void);

asm void CARDClose(void)
{
    nofralloc
    blr
}

asm void CARDOpen(void)
{
    nofralloc
    blr
}
"""

RECOVERED = """\
// provenance: harvest
s32 CARDClose(CARDFileInfo* fileInfo)
{
    return 0;
}
"""


def test_stale_extern_is_removed(H):
    out = H.build_rebased_symbol(HEAD, RECOVERED, "CARDClose")
    assert "extern void CARDClose(void);" not in out


def test_an_unrelated_siblings_declaration_is_untouched(H):
    out = H.build_rebased_symbol(HEAD, RECOVERED, "CARDClose")
    assert "extern void CARDOpen(void);" in out


def test_the_recovered_definition_still_lands(H):
    out = H.build_rebased_symbol(HEAD, RECOVERED, "CARDClose")
    assert "s32 CARDClose(CARDFileInfo* fileInfo)" in out
    assert "asm void CARDClose(void)" not in out


def test_a_head_without_a_declaration_is_unchanged_apart_from_the_body(H):
    head = "asm void CARDClose(void)\n{\n    nofralloc\n    blr\n}\n"
    out = H.build_rebased_symbol(head, RECOVERED, "CARDClose")
    assert "extern" not in out


def test_a_matching_declaration_is_left_alone(H):
    # Already correct: rewriting it would be churn and would dirty the diff.
    head = ("extern s32 CARDClose(CARDFileInfo* fileInfo);\n"
            "asm void CARDClose(void)\n{\n    nofralloc\n    blr\n}\n")
    out = H.build_rebased_symbol(head, RECOVERED, "CARDClose")
    assert out.count("extern s32 CARDClose(CARDFileInfo* fileInfo);") == 1


def test_a_non_extern_prototype_is_removed_too(H):
    head = ("static void CARDClose(void);\n"
            "asm void CARDClose(void)\n{\n    nofralloc\n    blr\n}\n")
    out = H.build_rebased_symbol(head, RECOVERED, "CARDClose")
    assert "static void CARDClose(void);" not in out


def test_a_definition_is_never_mistaken_for_a_declaration(H):
    # `void Other(void) { ... CARDClose(); }` mentions the symbol but is not a
    # declaration of it. Rewriting inside a body would corrupt the unit.
    head = ("extern void CARDClose(void);\n"
            "void Other(void)\n{\n    CARDClose();\n}\n"
            "asm void CARDClose(void)\n{\n    nofralloc\n    blr\n}\n")
    out = H.build_rebased_symbol(head, RECOVERED, "CARDClose")
    assert "    CARDClose();" in out


def test_rewrites_are_reported_for_the_card(H):
    rewritten = []
    H.build_rebased_symbol(HEAD, RECOVERED, "CARDClose", sig_fixes=rewritten)
    assert rewritten == ["CARDClose"]


# --- merge_preamble ownership window -----------------------------------------

HEAD_NO_TYPES = """\
extern void CARDClose(void);

asm void CARDClose(void)
{
    nofralloc
    blr
}
"""

RECOVERED_WITH_TYPES = """\
// provenance: harvest
typedef int s32;

typedef struct CARDFileInfo {
    s32 chan;
} CARDFileInfo;

s32 CARDClose(CARDFileInfo* fileInfo)
{
    return fileInfo->chan;
}
"""


def test_recovered_types_survive_the_rebase(H):
    """The dominant harvest defect, 2026-08-31.

    merge_preamble skips a declaration whose name already appears in the
    destination -- the destination owns it. But it runs AFTER the splice, so
    the body just spliced in counts as the destination "already having" the
    types. `s32` and `CARDFileInfo` appear in `s32 CARDClose(CARDFileInfo*)`,
    the guard fires, and the typedefs the body needs are dropped. MWCC then
    answers `declaration syntax error` at the function name or `')' expected`
    at the parameter -- 32 and 14 of the stranded backlog respectively.

    Ownership must be judged against the head as it was BEFORE the splice.
    """
    out = H.build_rebased_symbol(HEAD_NO_TYPES, RECOVERED_WITH_TYPES, "CARDClose")
    assert "typedef int s32;" in out
    assert "CARDFileInfo" in out.split("s32 CARDClose")[0], (
        "CARDFileInfo must be declared before the definition that uses it")


def test_a_type_the_head_really_owns_is_still_not_redeclared(H):
    head = ("typedef int s32;\n"
            "extern void CARDClose(void);\n"
            "asm void CARDClose(void)\n{\n    nofralloc\n    blr\n}\n")
    out = H.build_rebased_symbol(head, RECOVERED_WITH_TYPES, "CARDClose")
    assert out.count("typedef int s32;") == 1
