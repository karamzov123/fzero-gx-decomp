# Allocator-blocked frontier — measured exhaustion record

Session of 2026-10-13/14. Two functions landed and are checksum-verified; five
more were taken to documented plateaus. This record exists so none of it is
re-derived.

## Landed

  fn_8_A954   title-screen animation   616 B   commit 3285fc7a   PR #14
  fn_1_64FB8  effect camera update     688 B   commit 36f65841   PR #16

Both used the coupled propagation/lifetime method recorded in
`docs/MWCC-PROPAGATION-CLOSURE.md`. Neither came from the parallel worker fleet.

## Improved but not landed

  fn_1_104730  camera update        102 -> 73 of 175 rows   91.3%
  fn_1_82C70   car initialisation    45 -> 30 of 158 rows   94.4%
  fn_1_F75D8   GX lighting setup     37 of 167 rows, flat   95.3%
  fn_80078360  EXI-style dispatch    32 of 132 rows, flat   99.x%
  fn_1_654B0   effect anim update    45 of 134 rows, flat   97.0%

Roughly 350 compiler/object probes were spent across these. Full per-variant
tables live in `.fzgx/overnight/{CAMERA,CAR,LIGHTING}-EXHAUSTION.md` in the
working tree (`.fzgx` is gitignored); the decisive facts are summarised below.

## Four measured one-row plateau types

Each was probed from several independent source shapes and none closed.

**Displacement fold** (fn_17_7728, 211 rows, 34 prior attempts). Retail emits
`addi r7, r4, 0x60` then `lwz r6, 0x14(r7)`; the candidate emits
`lwz r6, 0x74(r4)`. Nine shapes all pinned at 1 row. Removing the by-value
pointer-read helper cost 10 rows; `register` on the pointer cost 38.

**Doubled zero** (fn_12_2F970, 30 rows, 20 prior attempts). Retail emits
`li r31, 0x0` then `mr r30, r31` — one zero register for stores, a second as the
loop index. Seven shapes including the natural chained `i = p->pre = 0;` all
pinned at 1 row. Two explicitly distinct zero locals still produced one
immediate.

**Register renaming** (fn_1_7D6B8 5 of 713; fn_1_16BA0 4 of 178). Identical
instructions differing only in FPR/GPR numbers, e.g. `extsb r7` vs `extsb r5`,
or `fmadds f6, f3, f1, f6` vs `fmadds f6, f1, f3, f6`. Value flows are
identical, so changing names cannot repair it. On fn_1_16BA0, swapping the
fmadds multiply operands held at 4 rows and swapping the second pair regressed
to 6 — the body is already a local optimum.

**Structural reorder** (fn_80078360, 32 rows, 27 of them instruction
differences). Retail loads `unk_00` and the offset together, tests bit 1, then
loads the sda21 global and xoris. Four reorderings of that dependency chain all
held at 32 rows.

## What actually closes a function

Semantic bugs, not volume. Both landings came from a single correct structural
insight — signed conversion bias, wrong field offsets, an incorrect fade
comparison, and a coupled propagation/lifetime change. ~350 probes across six
functions produced zero landings.

## Frontier assessment

The ledger holds 7,308 functions, 5,768 matched (79%), 1,517 unmatched, with
roughly 125,000 compiler checks already spent project-wide. Every symbol shows
at least one prior attempt; the 19 with zero attempt records are already
`matched` (converted before attempt tracking began). There is no virgin
territory.

Measured row counts for the top unmatched candidates:

  fn_1_16BA0    4 of 178    regalloc 4
  fn_12_A5C     5 of 129    regalloc 5
  fn_15_5460    8 of 180    regalloc 8
  fn_3_104C4    8 of 142    regalloc 8
  fn_8_FC5C    12 of 208    regalloc 12
  fn_80078360  32 of 132    ins 27, regalloc 3, op 1, imm 1

The first five are pure register renaming. The sixth is a genuine structural
divergence and is the only one of the six worth further work.

## Tooling note for future runs

An unattended driver needs quota detection, model rotation, and a stall
detector. Without them a single rate limit produced 478 failed rounds in seven
minutes. All `opencode/*-free` models share one account-wide 429 quota, so
rotation does not buy throughput. Keep any unattended loop to `write-unit` only
— never submit, verify, commit, push or merge.
