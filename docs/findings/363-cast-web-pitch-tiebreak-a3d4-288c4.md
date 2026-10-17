# 363 — One-web fresh-vs-pitch register tiebreak unreachable from source (fn_8003A3D4, fn_800288C4)

## fn_8003A3D4 (main/dol, 69 words, pin mwcc_233_163n = GC/1.2.5n)

Best body: `.fzgx/attempts/fn_8003A3D4.1791052138.c` (99.85507%, 67/69 words).
Residual (2 rows):
- w52 retail `clrlwi r7, r8, 0x10` vs ours `clrlwi r8, r8, 0x10` — the `(u16)` cast of
  `unk8 = (u16)(*(u32 *)(p.value + 0x6C8));`. Retail allocates a fresh r7 (the `li r7,0x10`
  home freed at w49); ours pitches the cast into r8, the dying home of the u32 load (w46 `lwz r8, 0x6c8(r9)`).
- w53 `mullw r5, r7, r5` vs `mullw r5, r8, r5` (consequence).

Structure verified: w51 `(u16)shift` cast (`clrlwi r5, r6, 0x10`) and w53 mul-dest pitch over r5 match retail in all variants; the sraw pitch (w49 `sraw r6, r7, r6`) matches too. Only the unk8-cast web home differs.

Measured cohort (offline, module-default mw; all produce the same 2 diffs unless noted):
- decl-type flips: `u16 shift`, `u32 diff` — no change. `u16 unk8` — 40-diff panel break (load becomes lhz; retail is lwz+clrlwi, u32 decl correct).
- named cast web `u16 unk8v` (in-place copy after the assignment, mul rewritten): 70 words — the copy emits its own row (`addi r7, r8, 0`), never coalesces; +bare pragmas: `opt_propagation off` 40-diff, `opt_dead_assignments off` 6-diff reshuffle, others 70.
- moving the cast out of the assignment (`unk8 = *(u32*)(...)` + `(u16)unk8` at the mul): 40-diff — **the assignment's `(u16)` cast is load-bearing for the whole panel's row structure**, not just the web's home.
- statement moves: unk8-line before diff (no change), after shift (7-diff), store-before-shift (10-diff); explicit `+=` form (no change); explicit `(u32)` on the product (40-diff).
- decl-order permutations of the 6 loop locals (all 6 positions): no change.
- mask form `& 0xFFFF`: 70 words.
- bare `#pragma opt_propagation off`: 40-diff (do not apply; poisons the body, same class as the 80078360 finding).

Engine/capture: `mwgraph` capture of the 1.2.5n allocator succeeded (`state/fixups/a3d4cap`, 84-node graph, lldb). Fixup engine with `--captures .state/fixups/a3d4cap --corpus .fzgx/corpus_a3d4`: 273 variants, 0 matches; best label `regalloc: i: s8 -> u8` — the projection only reaches decl-type changes, which do not flip the tie. Capture corpus is reusable (`.fzgx/corpus_a3d4/{inputs,results}.json` + `state/fixups/a3d4cap/fn_8003A3D4.json`).

Stopping condition: 0 closure yield over ~27 shape probes + 273 constrained engine variants. The residual is a free-list tiebreak on one web's home; no source-level edit that preserves the 69-word structure flips r8→r7.

## fn_800288C4 (module main, 63 words)

Best body: `.fzgx/attempts/fn_800288C4.1791779537.c`. Residual (2 rows), in the `arg0 > 0` branch:
- w32 retail `subf r5, r7, r3` vs ours `subf r0, r7, r3` — line 21 `arg0 -= (arg0 / 100) * 100;` (r3 = arg0, r7 = 100*(arg0/100) from w25). Both r0 (freed w29) and r5 (freed w31, the just-freed `&unk_1C0[m]` home) are free; retail takes r5 (pitch over most-recently-freed), ours takes r0 (older free).
- w33 retail `slwi r0, r5, 2` vs ours `slwi r0, r0, 2` (consequence).

Measured cohort (module-default mw; same 2 diffs unless noted):
- bare pragmas `opt_propagation`, `opt_lifetimes`, `opt_dead_assignments`, `opt_pointer_analysis` off — no change.
- `arg0 %= 100;` / `arg0 = arg0 - (arg0 / 100) * 100;` / `arg0 -= 100 * (arg0 / 100);` — no change.
- named remainder `s32 v` — 19-diff reshuffle; +`opt_propagation off` same.
- named quotient `s32 h` (`h = arg0 / 100; arg0 -= h * 100;`) — no change; +pragma no change; +m/q swap reshuffle.
- statement order swap of lines 19/20 (`m` before `q`) — 15-diff reshuffle; the q,m C order is load-bearing (lines 20/21 cannot swap: line 21 mutates arg0 which line 20 reads).

Stopping condition: 0 closure yield over 14 probes. Note the direction is the mirror of fn_8003A3D4 (there retail = fresh, ours = pitch; here retail = pitch, ours = fresh/older) — family: a single web's home is chosen by allocator tiebreak, unreachable from source shape.

## Status

Both parked; bodies remain the best saved attempts. Next candidate per plan: `fn_1_16BA0` (stcoli, 178 words, 99.86%, 16 attempts).
