# 372 — fn_1_A1CE8 landed: `cmplwi` + double branch is the last term of a short-circuit OR, not a switch

Session of 2026-10-17 (opencode/deepseek, agent `deepseek-opencode`).
Closes the 98.9474% / one-word plateau of `fn_1_A1CE8` (main_rel, sound, 57
words, attempt 15): retail w15 is `cmplwi r0, 0` on the loaded flag byte; ours
(carried by a one-case `switch` that reproduced every other word, including
the `beq body; b exit` double branch) emitted `cmpwi r0, 0`.
Landed in commit `a5ac7b0a` (`claim --max-attempts 50`, `write-unit` auto-check
100.0% MATCH, verify fast path 13s; gate: ninja 0, 16 files OK, lint 0,
tests 11 OK).

## What did not work (do not repeat)

The `cmpwi`/`cmplwi` pair comes from the *construct*, not an operand cast:
`u32`/`u8`/bare flag locals, direct `switch ((u32)lbl)`, `case 0u`, implicit
conversion, separate assignment, `& 0xFFu`, `+ 0u`, and an `unsigned int : 8`
bitfield pun all still produced `cmpwi` (1 diff each). Every `if (...) return;`
polarity regressed to the 43-row single-branch layout — the one-case switch's
double branch was load-bearing *for layout only*.

## The witness and the fix

Matched same-unit sibling `fn_1_A0978` contains the exact retail shape:

    fn_1_A0978 w12: lbz r0, 0xd(r31); cmplwi r0, 0; beq +x; b far

whose source (sound.c) is a short-circuit OR:

    if (fn_1_3F864() == 0 || lbl_1_bss_6EAA4__fzgx_offset_1 != 0) {
        return;
    }

The OR lowering evaluates the last term as `cmplwi r0, 0; beq <continue>; b
<true-target>`: the unsigned compare and the extra `b` both come from the
condition composition, free of charge. Rewriting the guard as a single
three-term OR closed it:

    if (lbl_1_bss_6EAD0.unk_0 == NULL || (u8)arg0 >= 0x2D || lbl_1_bss_6F243 != 0) {
        return;
    }
    if (fn_8004C658(lbl_1_bss_6EAD0.unk_0->unk_0) == 3) { ... }

57/57 words. Note the first two terms reproduce retail w7-12 unchanged (they
were byte-identical in the switch body via canonicalization); only the final
flag term needed the OR form.

## Law

`switch (byte){case 0: ... default: return;}` cannot produce `cmplwi` on
MWCC 1.3.2 — switch equality canonicalizes signed. An unsigned `cmplwi r0,0`
guarding a byte flag with a `beq`+`b` pair is the last operand of a
short-circuit OR with an out-of-line true block (`if (A == 0 || B >= K || C != 0)
return;`). Same-module witnesses (7 more `lbz ... cmplwi r0,0` sites in the
matched sound functions) confirm the family; grep for the pattern before
shaping.

Files: prior best `.fzgx/attempts/fn_1_A1CE8.best.c`; landed body is the
`fn_1_A1CE8` carve inside `src/rel/main_rel/sound.c` (commit `a5ac7b0a`).
