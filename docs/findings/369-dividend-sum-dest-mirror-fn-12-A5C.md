# 369 — dividend-sum dest mirror, fifth tiebreak unit (fn_12_A5C)

## unit
movie_module fn_12_A5C, 129 words, pin GC/1.3.2 with `-use_lmw_stmw on`.
The flags live only in the attempt sidecar `.json`; rescoring the saved body
without the flag reproduces a fake 40-row prologue shift (lmw/stmw vs spill
loop). Always read the sidecar before re-scoring an archived body.
Best body: `.fzgx/attempts/fn_12_A5C.1792000232.c` (99.76744%). Residual = 5 rows.

## residual decode (after the b1 operand-order fix)
```
w19 R add r3, r3, r4        O add r4, r3, r4    quarter's dividend sum; both srcs die on the row
w20 R lwz r4, 0x14(r29)     O lwz r3, 0x14(r29) field_14 load; freshest-free pitch on both sides, consistent
w21 R srawi r5, r3, 1       O srawi r4, r4, 1   quarter; retail takes fresh r5, ours pitches
w22 R add r3, r4, r5        O add r3, r3, r4    var3.f04 = field_14 + quarter (operand order matches; homes differ)
w25 R add r3, r3, r5        O add r3, r3, r4    var3.f08 = field_24 + quarter (same)
```
C region (b1 form; the archive's `((quarter) + (param1->field_14))` reads quarter-
first and pre-fixes left w22 operand-reversed):
```
product = param1->field_08 * param1->field_0C;
half = product / 2;
quarter = half / 2;
var3.f00 = param1->field_04 + half;
var3.f04 = param1->field_14 + quarter;
var3.f08 = param1->field_24 + quarter;
```

## mechanism
- w14 (matched, half's own chain: `add r4, r4, r5`) is the house rule: when both
  sum sources die on the row, the dest pitches the FIRST source's reg. Retail
  w19 keeps it (src1 = the fresh fixup, r3). Ours pitches src2 (half, r4), so our
  IR must list the commutative sum reversed; the emitted `add` list is
  re-canonicalized, hiding the difference.
- w20 stays consistent in both (pitch the one free dying home). The divergence is
  exactly the w19 dest plus w21's pitch-vs-fresh choice on the same tie.
- w21 is an inversion: retail turns FRESH r5 although the dying dividend (r3) is
  pitchable — while the matched half chain at w15 pitches its srawi onto the
  dying src in the same shape. The flip is co-located with the w19 mirror;
  plausible single root cause, not source-addressable.
- Cascade follows mechanically: with the dividend in r4 the load takes r3, the
  srawi pitches r4, and f04/f08 list compensating homes; with the dividend in r3
  retail gets load r4, fresh quarter r5, and r5 still home across the f0C store.

## probes (offline, module pin + flag; 7 shapes on top of prior engine 15 attempts)
- b1 — `var3.f04 = param1->field_14 + quarter;`: closes the w22 operand list;
  kept as the better form. 5 diffs.
- m2 — `var3.f00` statement moved above `quarter = half / 2;`: no-op, 5 diffs.
- d1/d2 — `half`/`quarter` decl swap (d2 adds the statement reorder): no-op, 5 diffs.
- q1 — inline `half / 2` at both uses, drop `quarter` (word count 130): MWCC CSEs
  the fixup+dividend but DUPLICATES the tail `srawi` per use (the second one
  re-consumes the still-live dividend home) and shifts the whole var3 store block.
  Probe-design intel: two inline uses of one div do not form one CSE'd chain.
- v3a/v3b — explicit `quarter = (((u32)half >> 31) + half) >> 1;` and the mirrored
  operand order: bit-identical output to each other (the cast transparently
  canonicalizes the commutative sum, so C text cannot set the operand order), and
  the unsigned type of the cast turns the outer shift into `srwi` where retail has
  `srawi` — a semantic break; rejected as an invalid authored-C form.

## stopping condition
Shared-cause cohort = 5 units (findings 363 x2, 364, 365, this), all "adjacent
same-class webs' homes mirrored while every other row matches". Measured C-shape
yield on the fifth member = 0/7. Parked; any closure needs the mwconstraints
web-pair generator with validated flip evidence (family note in finding 365).

Status: parked; body remains best saved attempt, plus the f04 field-first shape
from b1 for the next rescoring pass.
