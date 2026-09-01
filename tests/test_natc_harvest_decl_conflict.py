#!/usr/bin/env python3
"""A recovered declaration must beat the head's dtk stub.

2026-08-31, second order of the same defect. These carve heads open with a
block of placeholder declarations that record only the NAME:

    extern void EXISelect(void);
    extern void __CARDGetControlBlock(void);
    extern unsigned char __CARDBlock[544];

They are not real signatures -- they were generated when the function was
still assembly and nothing knew its parameters. The recovered candidate
carries the true prototypes (it compiled standalone to the retail bytes), but
`merge_preamble`'s ownership guard skips any declaration whose name the head
already mentions. So the head keeps `void EXISelect(void)` and the spliced
body calls `EXISelect(chan, 0, 4)`:

    function call 'EXISelect(int, int, int)' does not match 'EXISelect()'
    cannot convert 'unsigned char *' to 'struct CARDControl *'
    undefined identifier 'CARDControl'

Three separate refusal buckets, one cause. The recovered declaration is
evidence-backed and the stub is a placeholder, so the recovered one wins --
but ONLY over a declaration. A head that DEFINES the symbol is authoritative
and must never be overwritten by a prototype.
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


def test_stub_is_replaced_by_the_recovered_prototype(H):
    head = "extern void EXISelect(void);\n"
    recovered = "extern s32 EXISelect(s32 chan, s32 dev, u32 freq);\nint f(void) { return 0; }\n"
    out = H.merge_preamble(head, recovered, owner_text=head)
    assert "extern void EXISelect(void);" not in out
    assert "EXISelect(s32 chan, s32 dev, u32 freq)" in out


def test_an_identical_declaration_is_not_duplicated(H):
    head = "extern s32 EXISelect(s32 chan);\n"
    recovered = "extern s32 EXISelect(s32 chan);\nint f(void) { return 0; }\n"
    out = H.merge_preamble(head, recovered, owner_text=head)
    assert out.count("EXISelect") == 1


def test_a_head_DEFINITION_is_never_replaced_by_a_prototype(H):
    # The head's own converted C is authoritative; a stale prototype from a
    # recovered file must not overwrite it.
    head = "s32 EXISelect(s32 chan)\n{\n    return chan;\n}\n"
    recovered = "extern void EXISelect(void);\nint f(void) { return 0; }\n"
    out = H.merge_preamble(head, recovered, owner_text=head)
    assert "s32 EXISelect(s32 chan)\n{" in out
    assert "extern void EXISelect(void);" not in out


def test_a_data_stub_is_replaced_by_the_recovered_typed_declaration(H):
    # `extern unsigned char __CARDBlock[544];` vs the body wanting
    # `struct CARDControl __CARDBlock[2];` -> "cannot convert".
    head = "extern unsigned char __CARDBlock[544];\n"
    recovered = "extern CARDControl __CARDBlock[2];\nint f(void) { return 0; }\n"
    out = H.merge_preamble(head, recovered, owner_text=head)
    assert "unsigned char __CARDBlock[544]" not in out
    assert "CARDControl __CARDBlock[2]" in out


def test_an_unrelated_head_declaration_survives(H):
    head = "extern void EXISelect(void);\nextern void EXIDetach(void);\n"
    recovered = "extern s32 EXISelect(s32 chan);\nint f(void) { return 0; }\n"
    out = H.merge_preamble(head, recovered, owner_text=head)
    assert "extern void EXIDetach(void);" in out


def test_a_type_the_head_never_had_is_still_merged(H):
    # The existing behaviour must not regress: a genuinely new typedef lands.
    head = "extern void EXISelect(void);\n"
    recovered = "typedef struct CARDControl { int chan; } CARDControl;\nint f(void) { return 0; }\n"
    out = H.merge_preamble(head, recovered, owner_text=head)
    assert "CARDControl" in out


def test_a_call_inside_a_function_body_is_not_treated_as_a_declaration(H):
    head = "extern void EXISelect(void);\nvoid g(void)\n{\n    EXISelect();\n}\n"
    recovered = "extern s32 EXISelect(s32 chan);\nint f(void) { return 0; }\n"
    out = H.merge_preamble(head, recovered, owner_text=head)
    assert "    EXISelect();" in out


def test_a_bare_prototype_is_recognised_as_a_declaration(H):
    """DECL missed `int f(int);` — no extern, no typedef, no struct.

    2026-08-31: the recovered candidates declare the helpers they call as
    plain prototypes (`int EXISelect(int chan, unsigned int dev, unsigned int
    freq);`). DECL required one of typedef/struct/union/enum/extern/#define/
    #include/static/volatile, so a bare prototype matched nothing and
    merge_preamble never even considered it. `__CARDReadNintendoID`'s
    preamble had 12 lines and ZERO DECL matches.
    """
    assert H.DECL.match("int EXISelect(int chan, unsigned int dev, unsigned int freq);")
    assert H.DECL.match("s32 __CARDGetControlBlock(s32 chan, CARDControl** card);")


def test_a_function_definition_is_not_matched_as_a_declaration(H):
    # Ends in `{`, not `;` — merging a definition would duplicate a body.
    assert not H.DECL.match("int EXISelect(int chan) {")
    assert not H.DECL.match("int EXISelect(int chan)")


def test_a_bare_prototype_replaces_the_head_stub(H):
    head = "extern void EXISelect(void);\n"
    recovered = ("int EXISelect(int chan, unsigned int dev, unsigned int freq);\n"
                 "int f(void) { return 0; }\n")
    out = H.merge_preamble(head, recovered, owner_text=head)
    assert "extern void EXISelect(void);" not in out
    assert "int EXISelect(int chan, unsigned int dev, unsigned int freq);" in out
