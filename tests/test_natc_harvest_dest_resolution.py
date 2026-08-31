#!/usr/bin/env python3
"""A symbol's destination file must be resolved with its unit.

2026-08-31. `still_asm()` returned one flat `symbol -> path` map, built by
walking src/ and overwriting on collision. 55 symbols in this tree are
defined with an asm body in more than one file -- the dtk carves duplicate
SDK leaf functions across units -- so the map answered with whichever file
`rglob` happened to reach last.

`__OSUnmaskInterrupts` (main/dolphin/os/OSInterruptMask) resolved to
`src/dolphin/metrotrk/uart.c`. Two things then follow:

  * `natc_compile._dest_for` handed `_packageable` the wrong head, the
    rebase failed, and `already_solved()` fell through to "let the attempt
    through". The symbol scored 100.0 eight times between 15:02 and 15:13 on
    2026-08-31 and was never packaged -- exactly the doom loop the guard
    exists to stop.
  * `natc_harvest` attributed stranded work to the wrong destination file.

The unit is known at both call sites, so it must be used.
"""
import importlib.util
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))


def _load(name):
    spec = importlib.util.spec_from_file_location(
        name, REPO / f"tools/{name}.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


@pytest.fixture(scope="module")
def H():
    return _load("natc_harvest")


def test_a_colliding_symbol_resolves_to_its_own_units_file(H):
    dest = H.dest_for_symbol("main/dolphin/os/OSInterruptMask",
                             "__OSUnmaskInterrupts")
    assert dest is not None
    assert dest.name == "OSInterruptMask.c", dest


def test_the_same_symbol_in_another_unit_resolves_there(H):
    # The metrotrk carves define their own copy; asking for that unit must
    # give that unit's file, not the OS one.
    dest = H.dest_for_symbol("main/dolphin/metrotrk/uart",
                             "__OSUnmaskInterrupts")
    assert dest is None or dest.name == "uart.c", dest


def test_an_unknown_unit_does_not_silently_pick_some_other_file(H):
    assert H.dest_for_symbol("main/not/a/unit", "__OSUnmaskInterrupts") is None


def test_a_symbol_absent_from_its_unit_resolves_to_nothing(H):
    assert H.dest_for_symbol("main/dolphin/os/OSInterruptMask",
                             "NoSuchSymbolAnywhere") is None


def test_compile_dest_for_uses_the_unit(H):
    C = _load("natc_compile")
    dest = C._dest_for("main/dolphin/os/OSInterruptMask", "__OSUnmaskInterrupts")
    assert dest is not None and dest.name == "OSInterruptMask.c", dest
