#!/usr/bin/env python3
"""The inline-asm completion tranche: what source_form_check must admit.

Finding 257 opens a lane for functions that pure C cannot express -- a Gekko
paired-single kernel, an `mtmsr` interrupt disable, an `icbi` cache op. MWCC
selects none of those from ordinary source, so those functions were parked as
`inline_asm_required` and no worker could ever touch them.

The gate previously refused ALL inline asm in a candidate. Relaxing that
blanket rule needs three guards, or the lane becomes a hole in the mission:

  1. A WRAPPER is still refused. `void f() { asm { ...whole body... } }` is an
     asm body with a C signature; nothing was converted. (Finding 258: fifteen
     of those were already in src/ and were being counted as natural C.)
  2. A HYBRID is admitted only when the DESTINATION's asm body for that symbol
     actually contains an un-C-able instruction. The evidence comes from the
     canonical tree's retail-derived asm, never from the candidate, so a
     candidate cannot enrol itself.
  3. The card must declare it, so a stray asm block a worker forgot to remove
     cannot pass as a deliberate tranche conversion.
"""
import importlib.util
import sys
from pathlib import Path

import pytest

REPO = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(REPO / "tools"))


def _load():
    spec = importlib.util.spec_from_file_location(
        "natc_gate", REPO / "tools/natc_gate.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


_TRANCHE_PHRASES = ("nothing but an asm block", "un-C-able instruction",
                    "inline-asm tranche conversions must be declared",
                    "destination holds no asm body")


def _is_tranche(err):
    return any(p in err for p in _TRANCHE_PHRASES)


def _pair(cand_text, dest_text, base):
    cand = base / "_tranche_cand.c"
    dest = base / "_tranche_dest.c"
    cand.write_text(cand_text)
    dest.write_text(dest_text)
    return [(cand, dest)]


# The destination still holds the retail asm body: `mfmsr` is a supervisor
# instruction, so this symbol is genuinely pure-C-ineligible.
DEST_SUPERVISOR = """\
asm BOOL OSDisableInterrupts(void)
{
    nofralloc
    mfmsr   r3
    rlwinm  r4, r3, 0, 17, 15
    mtmsr   r4
    blr
}
"""

# Ordinary integer work. Plain C emits every one of these.
DEST_PLAIN = """\
asm int Add(register int a, register int b)
{
    nofralloc
    add     r3, r3, r4
    blr
}
"""

HYBRID = """\
BOOL OSDisableInterrupts(void)
{
    // provenance: retail asm, dolphin SDK shape
    register BOOL level;
    asm { mfmsr level }
    return level;
}
"""

WRAPPER = """\
BOOL OSDisableInterrupts(void)
{
    // provenance: retail asm
    asm
    {
    mfmsr   r3
    blr
    }
}
"""

HYBRID_PLAIN = """\
int Add(register int a, register int b)
{
    // provenance: retail asm
    register int r;
    asm { add r, a, b }
    return r;
}
"""

CARD_OK = "inline-asm: OSDisableInterrupts — supervisor (mfmsr)\n"


def test_wrapper_is_refused_even_with_a_card(tmp_path):
    m = _load()
    errs = m.source_form_check(_pair(WRAPPER, DEST_SUPERVISOR, tmp_path),
                               card_text=CARD_OK)
    assert any("OSDisableInterrupts" in e and "nothing but an asm block" in e
               for e in errs), errs


def test_hybrid_over_uncable_instruction_is_admitted(tmp_path):
    m = _load()
    errs = m.source_form_check(_pair(HYBRID, DEST_SUPERVISOR, tmp_path),
                               card_text=CARD_OK)
    assert not [e for e in errs if _is_tranche(e)], errs


def test_hybrid_without_a_card_declaration_is_refused(tmp_path):
    m = _load()
    errs = m.source_form_check(_pair(HYBRID, DEST_SUPERVISOR, tmp_path),
                               card_text="")
    assert any("OSDisableInterrupts" in e and "inline-asm:" in e for e in errs), errs


def test_hybrid_over_ordinary_c_is_refused(tmp_path):
    # `add` is not un-C-able; inline asm here is a shortcut past the mission.
    m = _load()
    card = "inline-asm: Add — supervisor (nope)\n"
    errs = m.source_form_check(_pair(HYBRID_PLAIN, DEST_PLAIN, tmp_path),
                               card_text=card)
    assert any("Add" in e and "no un-C-able instruction" in e for e in errs), errs


def test_plain_c_candidate_is_unaffected(tmp_path):
    m = _load()
    cand = "int Add(register int a, register int b)\n{\n    // provenance: x\n    return a + b;\n}\n"
    errs = m.source_form_check(_pair(cand, DEST_PLAIN, tmp_path), card_text="")
    assert not [e for e in errs if _is_tranche(e)], errs


def test_card_cannot_enrol_a_symbol_the_destination_does_not_justify(tmp_path):
    # The evidence is the destination's asm body, not the card. A card naming
    # a symbol whose retail body is ordinary C work must not admit it.
    m = _load()
    card = "inline-asm: Add — paired-single\n"
    errs = m.source_form_check(_pair(HYBRID_PLAIN, DEST_PLAIN, tmp_path),
                               card_text=card)
    assert any("no un-C-able instruction" in e for e in errs), errs
