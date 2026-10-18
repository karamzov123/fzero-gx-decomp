# 387 - fn_1_8CA70 / fn_1_8CAF4: register-color swap closed by index-expression reassociation

Symbols: `fn_1_8CA70` and `fn_1_8CAF4` (main_rel/car, 132 B, 33 words each).
Both landed byte-exact: commits `aed53248` (fn_1_8CA70) and `4325e49f` (fn_1_8CAF4).
Before this pass both sat at 99.09091 with the same six-row residual.

## The residual, exactly

0-based instruction rows (retail | ours, pre-fix):

```
 3  addi r8, r5, lbl_1_rodata_3508@l  |  addi r7, r5, lbl_1_rodata_3508@l
 5  lfs  f1, 0x10(r8)                 |  lfs  f1, 0x10(r7)
15  subf r7, r3, r4  (span = b - a)   |  subf r8, r3, r4
21  add  r3, r7, r0                   |  add  r3, r8, r0
26  lfd  f0, 0x668(r8)                |  lfd  f0, 0x668(r7)
29  lfd  f0, 0x7e8(r8)                |  lfd  f0, 0x7e8(r7)
```

A pure color swap: the address of `lbl_1_rodata_3508` wants `r8` and the span
(`b - a`) wants `r7`; our build had them exchanged. Words: 33 = 33, six rows.

## Why the deterministic routes could not close it

The fresh capture (post-header-rotation, `FZGX_ATOM_H` `ad0f67b6`) classifies the
function `fixed-graph-hypothesis` with `object_percent` 100.0 and two
`baseline_order_witnesses`; its object mapping is exactly `r7 -> r8`,
`r8 -> r7` (`/tmp/opencode/i8ca70/captures/report.json`). The projected engine
run (946 variants, 2 rounds, beam 4) produced no improvement, and the
declaration-order search reported `no-predicted-declaration-repair`
(`orders: 7, exhaustive: true, best_conflicts: 2`).

The reason is the web census: `span` is a *named* local (vr37, color 8), while
the rodata base is an unnamed front-end temp (vr41, color 7). Named locals are
numbered 32+, temps 40+; simplify order is descending vreg, coloring runs
ascending, so the named local is always colored before the temp and no
permutation of the *movable* (named, uninitialized, scalar) stratum can move the
temp's rank relative to it. The lever has to change the *structural* shape so
the address temp's rank moves - or `span` stops being a named local at all.

## The mechanism

What sets the colors is how the index expression is written, because that
decides both the instruction order and the web numbering:

| shape | score | behavior |
| --- | --- | --- |
| statements `index = span; index += T - H; index -= 1;` | 81.82 (27/33) | retail's `subf -> add -> addi` order, but `span` is a named local -> colors stay swapped |
| one expression, span/index still locals (`index = span + T - H - 1;`) | 93.94 (31/33) | colors fixed, but compiler folds `-1` into the `T - H` subexpr (`subf -> addi -> add`), one instruction order off |
| `index = span + ((T - H) - 1);` | 96.97 (32/33) | compiler canonicalizes to `(span + T - H) - 1`, but the add operands come out as `add r3, r0, r7` (temp first) |
| **`index = (T - H) + (span - 1);`** | **100.00 (33/33)** | canonicalizes to `(span + T - H) - 1` with the `-1`-carrying child **first**: `subf r0, r3, r0` / `add r3, r7, r0` / `addi r0, r3, -1` |

The rule MWCC applies: `A + (B - 1)` is rewritten to `(B + A) - 1`, and the
operand that carried the `-1` ends up as the **first** operand of the add. So
writing the `-1` on `span` (not on the `T - H` subexpression) is what puts
`span` in `rA` of `add r3, r7, r0` - and, since the whole computation now lives
in one expression tree, the front-end temp numbering flips the two colors.
Identical-scoring spellings: `(span - 1) + (T - H)`, flat `span - 1 + (T - H)`,
and the same with `total`/`half` as locals (`(total - half) + (span - 1)`), all
33/33.

Reached along the way (recorded so it is not retried): the pointer carrier
assigned *inside* the `if (a == b)` branch does flip the colors, but only by
leaving an uninitialized register read on the main path (`lfd 0x668(r8)` with
`r8` never defined there) - undefined behavior, not admissible natural C.

## Prologue integration

The first 100% submission was queued for revision: the unit redeclared
`lbl_1_rodata_3508` as `struct rodata_3508` while the car.c prologue already
declares it `extern f32 lbl_1_rodata_3508[];` (`identifier redeclared`). The
fix: keep the prologue's declaration and cast it -
`constants.value = (struct rodata_3508 *)lbl_1_rodata_3508;` - which compiles to
the identical words and clears the `PROLOGUE CONFLICT` gate.

## Twin

`fn_1_8CAF4` is word-for-word identical to `fn_1_8CA70` (33/33, same branch
targets); its relocation table differs in exactly one pair:
`lbl_1_bss_6DA80` instead of `lbl_1_bss_6E160`. `fzgx reuse` does not find it
(the naive clone keeps the wrong base symbol), so it was landed manually:
claim -> write-unit with the renamed extern -> check 100% -> submit -> verify.

## Commands that landed it

```
fzgx claim fn_1_8CA70 --max-attempts 15
fzgx write-unit fn_1_8CA70 --file <body>.c     # p6: (total - half) + (span - 1)
fzgx check fn_1_8CA70                          # 100.0% MATCH
fzgx submit fn_1_8CA70 --agent agent
fzgx verify --message "match: fn_1_8CA70 landed ..."   # aed53248
# twin: same body with fn_1_8CAF4 / lbl_1_bss_6DA80 -> 4325e49f
```
