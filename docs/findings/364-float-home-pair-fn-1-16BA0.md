# 364 — two-web float home pair mirrored between ours and retail (fn_1_16BA0, stcoli)

fn_1_16BA0 (module main_rel, 178 words, pin GC/1.3.2 = mwcc_242_81), stcoli loop body.
Best body: `.fzgx/attempts/fn_1_16BA0.1792003655.c` (99.85955%, 174/178 words). All 14
saved attempts sit at the same percentage; the fixup engine previously burned
12910 permutations (searched records, budget 150 s runs) without closing.

## Residual (exactly 4 rows, loop body)

- w74 `lfs f3, 4(r15)` (retail) vs `lfs f1, 4(r15)` (ours) — arg0[1] (v17) load home.
- w84 `lfs f1, 0x10(r23)` vs `lfs f3, 0x10(r23)` — v20->unk_10 load home.
- w88 `fmadds f6, f3, f1, f6` vs `fmadds f6, f1, f3, f6` — v24-chain add.
- w89 `fmadds f5, f3, f4, f5` vs `fmadds f5, f1, f4, f5` — v25-chain add.

The two webs swap homes as an exact pair: retail {arg0[1]=f3, unk_10=f1},
ours {arg0[1]=f1, unk_10=f3}. The C multiplicand order (arg0[1] first) is identical in
both; only the fmadds operand list compensates for the swapped homes. The C
multiplicand order is correct; the residual is purely the home-pair choice.
Everything else in the 178-word body matches, including the schedule (arg0 loads
hoisted before the r23 pointer chain in both) and every other float web home.

## Context facts

- f1 is free at w74 in BOTH binaries: the v0 web (rodata unk_2C conditional load,
  w24) dies at w49 (`fneg f31, f1`). So machine state is identical; the home pair
  comes from pcode structure, not execution state.
- v8 (-v0) lives in nonvolatile f31 through the loop, identical in both.
- `#pragma opt_propagation off` is active for this body (three pragma walls:
  opt_propagation off / opt_common_subs on / opt_dead_assignments off), plus inline
  wrappers `fn_1_16BA0_array_read` (arg0 reads) and `fn_1_16BA0_read_pointer`
  (unk_10). These were load-bearing for the rest of the panel.

## Measured cohort (all offline, module-default mw; same 4 diffs unless noted)

- Product-order reversal in statement 3 (`read_pointer * v17`): no change (MWCC
  re-canonicalizes the fmadds; homes pinned).
- Product-order reversal in statement 4 (`fzgx_live * v17`): w89 commutes, homes
  pinned. Both reversals together: same.
- Statement 3 ↔ statement 4 order swap (independent v24/v25 chains): no change.
- Statement 5 reversal: adds a 5th diff.
- Access-path matrix for the three arg0 loads (v16/v17/v18 each direct or via
  array_read helper; all 8 combos + 2 statement reorderings tested): the three load
  homes RESPOND (e.g. v17 direct → arg0[0] becomes f3, arg0[1] becomes f5), but none
  reaches retail's assignment; helper form in statement 3 (`read_pointer`) is itself
  load-bearing (direct `v20->unk_10` = 9-diff reshuffle, reversed = 9-diff).

Stopping condition: 0 closure yield over 16 probes spanning product order, statement
order, and the full access-path matrix, on top of prior engine work (12910 perms).
Same family as finding 363: one web home (here a linked pair) decided by allocator
tiebreak unreachable from source shape; direction here is ours=earlier-reg-first,
retail=later-read-gets-earlier-reg.

Status: parked; 99.85955 body remains best saved attempt.
