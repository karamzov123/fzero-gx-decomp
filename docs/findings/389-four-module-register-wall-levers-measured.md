# 389 — The four-module near-match wall: levers measured and closed (2026-10-29)

Symbols: `fn_12_3A64` (movie_module, 852 B, 99.53 saved), `fn_80059DD8` (main,
648 B, 99.41), `fn_80022BF4` (main, 616 B, 99.58), `fn_800720B0` (main, 184 B,
96.96), `fn_80072168` (main, 148 B, 98.24). Every residual below is a register
home; what follows is what was measured, so none of it is retried.

## fn_12_3A64 — `void` + `return` is not expressible in MWCC

Retail's callee-saved panel and where each value lives:

```
w  4  mr r28, r5          table
w  6  mr r27, r3          object
w  7  mr r26, r4          index
w 33  li r26, 0           near_z
w 34  addi r29, r3, -1    far_z = 0x7FFFFFFF
w 72  lwz r29, 0x14(r1)   far_z from sscanf
w 73  addi r30, r28, 0x200   original = table + 0x100 (u16*)
w208-212  lmw / lwz / mtlr / addi / blr    r3 is never written
```

Two measured bodies bracket it exactly:

| body | words | residue |
| --- | ---: | --- |
| `void`, no return (`fn_12_3A64.voidret.1793312565.c`) | 213 | 20 rows: `r26` near_z, `r27` far_z, `r28` object, `r29` table |
| `s8`/`u32` + `return far_z` | 214 | rows 4-207 **identical to retail**; only `extsb r3, r29` at the old epilogue slot, which then shifts the four teardown rows by one |

So the `return` is what pins `far_z` into `r29`, and the panel it produces is
retail's. The one word it costs is the materialisation into `r3` that retail
does not have. Finding 379's hypothesis — "the tail returns the inlined helper's
value under a `void` prototype" — is **closed**: a `void` function cannot spell
`return expr;` for MWCC 1.3.2. Eight shapes were compiled and every one failed
to build rather than warning:

```
void + return far_z;                COMPILE FAIL
void + return (u32)far_z;           COMPILE FAIL   (also with opt_dead_assignments /
void + return (s32)far_z;           COMPILE FAIL    opt_lifetimes / opt_propagation off)
void + return -far_z;               COMPILE FAIL
void + return far_z + 0;            COMPILE FAIL
void + return near_z ? far_z : far_z;  COMPILE FAIL
```

### The `v = v;` barrier does not extend liveness into the panel

The obvious substitute for a return pin is a zero-cost liveness extension, and
`fixup_source.self_assign_barriers` is the documented idiom for that. It does not
work here: every tail form below compiles to the same 213 words and the same 20
rows as the bare `void` body.

```
far_z = far_z;                far_z = (u32)far_z;
far_z = far_z;  + #pragma opt_dead_assignments off
far_z = far_z;  + #pragma opt_lifetimes off
far_z = far_z;  + #pragma opt_propagation off   (this one is catastrophic: 216 words, 130 rows)
near_z = near_z;              table = table;              object = object;
near_z = near_z; far_z = far_z;
return;
inline helper returning far_z, result discarded / (void)-cast / consumed by a local
```

Reading: a self-assignment coalesces away and leaves the web's numbering
untouched, so it cannot stand in for a return that the allocator sees as a
live-out. The idiom is for *single-definition folding*, not for panel rank.

### Other levers, all byte-identical (153 variants)

153 generated shapes — parameter copies for every subset of
`{object, index, table}`, a `u16 *tbl = table;` alias, `near_z`/`far_z` type
flips over `{u32, s32, unsigned long}` (9 combinations), both statement orders of
the `near_z = frame_near_z; far_z = frame_far_z;` pair and of the
`near_z = 0; far_z = 0x7FFFFFFF;` pair, and the barrier/alias/return hybrids —
compile to the same 20-row permutation at 90.61.

Local declaration order is also confirmed exhausted end-to-end: all 5040
permutations of the seven locals compile (**12** distinct objects, so the order
does reach the allocator) and every one scores 90.6103 with the same 20 rows.
This is the measurement `docs/MWCC_IDIOMS.md` records for the 720-permutation
subset, now extended to the full 5040.

## fn_80022BF4 — an operand-order difference that is not one

Rows 59/60 read like a finding-387 reassociation:

```
59  add r29, r3, r29   |  add r29, r4, r29
60  add r29, r4, r29   |  add r29, r29, r3
```

It is not. `v6` and `pc->value` are added into the same accumulator, so both
adds are commutative and rows 53-60 are exactly the `r3 <-> r4` rename of those
two webs (`lwz r3/r4, 0x54(...)`, `rlwinm r4/r3`, `add`, `lwz r4/r3, 0x14(...)`,
`addi`, then the two accumulator adds). Reassociating the source expression
therefore cannot move it; do not apply the 8CA70 lever here. 8 rows, 154 words
both sides.

## fn_80059DD8 — a three-cycle

14 rows, the whole residual is a `r28/r30/r31` rotation of three values that all
live from entry to the epilogue:

```
retail  mr r28, r5   addi r30, r6, 0   addi r31, r3, 0
ours    mr r30, r5   addi r31, r6, 0   addi r28, r3, 0
```

Every consumer follows the rotation (`addi r4, r30, 0x184/0x1a0/0x1c0/0xc0/0x100`,
`cmplwi r28, 0`, the `mr r30, r5` / `mr r30, r0` pair and `add r3, r28, r30`).
Same class as finding 384.

## fn_800720B0 — the base is a parked temp either way

Retail keeps the base in `r6` and the `value` local in `r5`; ours is the reverse.
That looked like a local-vs-temp question (a named local colours before a parked
temp), so `State *state = &lbl_8019E250;` was replaced with direct member
addressing (`lbl_8019E250.flags`, `.value`, `.count`). Result: **byte-identical
output** — 46 words, the same 25 rows. MWCC parks the global address as a temp in
both spellings, so the swap is not decided by whether a local names the base.

## fn_80072168 — the literal pair is swapped, and the local is not the cause

The `0` / `0x61` pair:

```
retail  li r0, 0     li r6, 0x61     sth r0, 2(r4)      stb r6, -0x8000(r3)
ours    li r6, 0     li r0, 0x61     sth r6, 2(r4)      stb r0, -0x8000(r3)
```

Both values are literals in both branches, so removing the `u16`/`u16 *`
intermediates cannot be the fix — and it is not:

| shape | rows |
| --- | ---: |
| saved baseline (12 rows: 17,18,20,21 + 27-35) | 12 |
| branch A stores `gx->bpSent = 0;` directly | 15 |
| both branches literal | 19 |
| both branches `*(volatile u16 *)((u8 *)gx + 2) = 0;` | 19 |
| both literal, `#pragma opt_propagation` removed | 19 |

The direct store also perturbs rows 14/16/22, i.e. it changes the schedule, not
just the homes. 37 words on both sides.

## Stopping condition and what is left

0 closure yield over ~7,000 candidate compiles across these five, plus the
`fixup` engine's earlier 3.5k-17k per-symbol runs. All residuals are register-home
ties in the finding 301/384 class. What would move them is unchanged from those
records: an allocator capture of the retail build (needs macOS/Wibo), or a
regional-build sibling whose region matches, so the responsible construct can be
read off instead of searched.

Also measured this session, for the record: `fzgx trivial --dry-run --module
main,movie_module,movie,pilotpoint --max-size 600` reports 0 candidates, and all
62 unattempted functions in these modules are >= 512 B, so no small first pass is
left in the requested scope.
