#!/usr/bin/env python3
"""The head OWNS a name only if it DECLARES it, not if it merely uses it.

2026-08-31, the last big harvest defect. merge_preamble's ownership guard was

    if any(re.search(rf"\\b{n}\\b", owner) for n in names): continue

— a bare substring search. A carve head that merely *uses* `CARDControl`
inside some function body 900 lines down therefore "owned" the type, so the
recovered file's `typedef struct CARDControl {...}` was skipped and nothing
declared it at all. The merged prototypes that reference it then failed:

    extern s32 __CARDSeek(CARDFileInfo*, s32, s32, CARDControl** pcard);
    -> illegal function definition / ';' expected / undefined identifier

Using a name is not declaring it. Ownership requires a declaration or a
definition; anything less and the recovered declaration is merged.
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


def test_a_mere_use_in_a_body_is_not_ownership(H):
    assert not H.head_declares("void f(void)\n{\n    CARDControl* c = 0;\n}\n",
                               "CARDControl")


def test_a_typedef_is_ownership(H):
    assert H.head_declares("typedef struct CARDControl { int c; } CARDControl;\n",
                           "CARDControl")


def test_an_extern_declaration_is_ownership(H):
    assert H.head_declares("extern s32 EXISelect(s32 chan);\n", "EXISelect")


def test_a_struct_tag_definition_is_ownership(H):
    assert H.head_declares("struct CARDControl {\n    int c;\n};\n", "CARDControl")


def test_a_function_definition_is_ownership(H):
    assert H.head_declares("s32 EXISelect(s32 chan)\n{\n    return chan;\n}\n",
                           "EXISelect")


def test_an_asm_definition_is_ownership(H):
    assert H.head_declares("asm void EXISelect(void)\n{\n    nofralloc\n}\n",
                           "EXISelect")


def test_a_used_but_undeclared_type_gets_its_typedef_merged(H):
    head = ("extern void CARDWrite(void);\n"
            "void other(void)\n{\n    CARDControl* c = 0;\n}\n")
    recovered = ("typedef struct CARDControl { int chan; } CARDControl;\n"
                 "int f(void) { return 0; }\n")
    out = H.merge_preamble(head, recovered, owner_text=head)
    assert "typedef struct CARDControl" in out


def test_a_genuinely_owned_typedef_is_still_not_duplicated(H):
    head = ("typedef struct CARDControl { int chan; } CARDControl;\n"
            "extern void CARDWrite(void);\n")
    recovered = ("typedef struct CARDControl { int chan; } CARDControl;\n"
                 "int f(void) { return 0; }\n")
    out = H.merge_preamble(head, recovered, owner_text=head)
    assert out.count("typedef struct CARDControl") == 1
