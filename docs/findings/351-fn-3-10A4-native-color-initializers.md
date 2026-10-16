# 351 — fn_3_10A4: layout-only rows can conceal wrong RGBA initializers

Manual continuation, 2026-10-16, `hermes-sol-manual` / `gpt-6.1-sol`.
**MATCHED, link-verified, commit `a0b23443`.** 560 bytes / 140 instructions.

## Why the old frontier was misleading

The saved 99.01428% body had zero rows described as the worker's responsibility,
but eight `L` rows: pooled color-copy displacements were E0..FC instead of
retail BC..D8. A normal submit rejected this body; those rows are not an automatic
promise of a future match.

The body already primed the actual retail color words with eight standalone
u32 objects at BC..D8, followed by an unused 220.0f primer at DC. It then
created different automatic Color initializers, which MWCC appended after
the primer. That reproduced neither the initializer locations nor the
correct runtime colors.

## Recover native initializer ownership and values

First remove those eight duplicate table/keep objects and the following
220.0f primer. Keep the earlier prefix through the 352.0f literal at B8.
Move the first interpolation color declaration before the second color,
because their source first-use order must be A at BC, B at C0.

This yields **140/140 relocation-masked words equal**, but the full oracle
still rejects the two pool-base relocation rows. Direct byte comparison
against `Project._raw_section("customize", ".rodata")` identifies the problem:

| Offset | Retail bytes | Candidate's guessed bytes |
| --- | --- | --- |
| BC | A0505000 | FFFFFFFF |
| C0 | A0A0A000 | 808080FF |
| C4 | FFFFFF00 | FFFF00FF |
| C8 | 70707000 | FFFFFFFF |
| CC | 00000000 | 000000FF |
| D0 | 70707000 | FFFFFFFF |
| D4 | 00000000 | 000000FF |
| D8 | FFFFFF00 | FFFF00FF |

Restore each Color's RGBA bytes to the measured retail value. These are real
semantic corrections: red/gray interpolation inputs, white/gray/black drawing
colors and alpha differ from the prior guesses. No instruction permutation
or compiler-setting search is needed.

The final anonymous pool prefix is 220 bytes (DC hex), ending immediately
after the last color at D8. Retail's following 220.0f literal at DC belongs
to subsequent usage and is not required to bind this function's prefix.
The exact compiler output and full oracle establish that boundary; do not
require unrelated trailing TU constants to be synthesized.

## Acceptance

- Correct initializer order alone: 100% masked words, **not** a full match.
- Correct initializer order **and bytes**: full oracle **100.0% MATCH**.
- Proven pool bindings: `...rodata.0 -> lbl_3_rodata_0`, the initializer at
  +0x14, and the three-byte format string to `lbl_3_data_15D4`.
- `submit`: accepted and pending link.
- `verify`: verified only `fn_3_10A4`, no rejections; commit `a0b23443`.
- Independent `sha1sum -c config/GFZE01/build.sha1`: **16/16 OK**.
- Whole-project lint: **0 findings**.

The source retains existing compiler-owned pool priming for the proven prefix;
no handwritten instructions or compiler modifications were introduced. The
packed-u32/RGBA union now states its actual data-conversion purpose.

## Other bounded work and handoff

- fn_1_108128 and fn_1_107930: inspected history, declined to repeat the
  already measured allocation families; no claimed matches.
- fn_10_25610: typed zero-offset member and array addresses were identical to
  its 157-word baseline (retail 158); direct symbol use produced 159 words.
  Keep the existing source frontier, not fake zero-offset padding.
- fn_1_C0B0C: meaningful shared hex-digit helpers (merged return, early return,
  and second-loop-only) regressed its 27-word register frontier; baseline kept.
- fn_1_2DB50: retail calls the ghost helper when E3 != 255, but the saved C
  selected it for E3 == 255. Corrected the predicate and saved the body.
  The corrected body and a single-case switch both remain 171 words vs
  retail 172; the conditional/unconditional branch-pair frontier is unresolved.
  Corrected source is archived, not submitted or counted as complete.

All claims drained, fleet remains stopped, no subagents or push. Original 48
changed/untracked paths remain byte-identical to the original protection
manifest. Portable evidence archive:
`state/repairs/manual-shared-index-and-colors-20261016.json`.

Honest closure after the two new matches: **1500 functions remain**;
main_rel 2466 done / 764 todo; customize 176 done / 102 todo;
zero credited-but-unauthored functions, zero fully authored modules.
