# Blocked large near matches

## Current fn_1_15C6C0 structural triage

The 2026-10-11 pass proves the six-rectangle storage inside
lbl_1_rodata_DD98+0x24, replaces the cross-object DD58+0x64 copy with a typed
native table, and verifies the full 248-byte literal pool. The shared-TU source
compiles with the recorded GC/1.3.2 pin at 83.79% adjusted similarity and 238
aligned differing rows, compared with the prior 83.15% / 248 rows. These row
counts are not the historical word/shape counts in the table below.

The function now has executable split coverage and a registered nonmatching unit
rel/main_rel/bg_win/fn_1_15C6C0.c. It remains blocked from generic model dispatch:
continue structural/value-flow work from the typed archived source, not an old
raw-score near-miss. Archive: state/repairs/15C6C0-storage-and-compile-path-20261011.json.gz.
No exact C match or authored-byte credit is claimed.

Continuation pass (same date): the unit record was registered but the shared-TU
block had never been spliced into rel/main_rel/bg_win.c, so the generated unit
source was still the `not matched yet` placeholder and every check reported
`missing in our object`. The block is now spliced and the `-fp_contract off`
compiler pin applied. Fresh evidence: 96.2% raw, 84.0% adjusted, 236 differing
rows (regalloc 172, ins 31, frame 17, op 13, imm 3) — a marginal improvement
over the 238-row baseline, so contraction is not the residual repair. The splice
relinks with all sixteen executable hashes intact, lint reports zero findings,
and the eleven tests pass.

Triage stays local. Candidates and compiler settings are preserved in
`state/repairs/large_near_frontier_20260914.json.gz`. The measured differences
below do not imply that declaration order alone can repair a function.

| Function | Words | Shape edits |
| --- | ---: | ---: |
| `fn_12_975C` | 12 | 0 |
| `fn_12_3DB8` | 16 | 0 |
| `fn_1_D123C` | 16 | 2 |
| `fn_8_2660` | 155 | 10 |
| `fn_12_BBC0` | 28 | 13 |
| `fn_3_1D338` | 112 | 6 |
| `fn_12_364CC` | 95 | 3 |
| `fn_1_9012C` | 111 | 26 |
| `fn_16_4E90` | 139 | 35 |
| `fn_1_AFC8` | 48 | 4 |
| `fn_1_15C6C0` | 254 | 43 |
| `fn_3_255DC` | 240 | 27 |
| `fn_1_13B98` | 241 | 17 |
| `fn_12_23F5C` | 87 | 5 |
| `fn_1_7FD7C` | 3 | 0 |

The 2026-09-15 shared-state pass linked `fn_8001B42C` from C.
`fn_3_1D338` now has a retail zero palette and corrected multiplication
association; the 109-word/8-shape alternative is also preserved in
`state/repairs/shared_regions_20260915.json.gz`. Neither customization
candidate is a full match. See `docs/batches/2026-09-15-shared-regions.md`.

The subsequent selection pass linked the 4,156-byte `fn_10_1C2D8` from C.
Its arithmetic, initialized data and all 867 pointer bindings are verified.
The adjacent `fn_10_1D314` remains unmatched at 121 words / 15 shape edits;
its corrected source is in `state/repairs/large_closures_20260915.json.gz`.
See `docs/batches/2026-09-15-large-closures.md`.
## src/rel/movie/ attempt-cap triage (cline-7)

All remaining unmatched functions in the movie module hit the claim attempt
cap before this session, so none could be worked. Blocked pending triage;
best objdiff score recorded for the next agent.

| Function | Bytes | Attempts | Best % |
| --- | ---: | ---: | ---: |
| `fn_5_6E8` | 184 | 5 | 94.85 |
| `fn_5_37C` | 332 | 6 | 93.34 |
| `fn_5_4C8` | 444 | 5 | 92.93 |
| `fn_5_7A0` | 3088 | 3 | 82.96 |
| `fn_5_1404` | 664 | 3 | 98.28 |
| `fn_5_169C` | 2656 | 3 | 68.02 |
| `fn_5_2C54` | 428 | 3 | 76.83 |
| `fn_5_3C44` | 528 | 3 | 94.81 |
| `movie:_prolog` | 512 | 3 | 90.70 |
| `fn_5_20FC` | 2904 | 3 | 40.59 |
| `fn_5_2E00` | 3576 | 3 | 61.01 |

This closes the module: all 10 remaining unmatched functions are recorded
here, so no `src/rel/movie/` function is left silently attempt-capped.
`fn_5_20FC` and `fn_5_2E00` were missing from the first table.

`fn_5_1404` is listed above but is no longer blocked: it has since been merged
into `src/rel/movie/_prolog.c` and the claim tool reports `status is matched`.
Only `fzgx inventory --module movie` still reports it as unmatched, so the
inventory status view is stale for symbols that are already merged into a
translation unit.

Correction (cline-7, later session): the `fzgx context` "attempts so far" line
is NOT authoritative for cap state, and the earlier claim in this file that it
is was wrong. The cap is enforced from the ledger counter, which `inventory`
reports. A symbol can show `attempts so far: 1` in `context` and still be
unclaimable: `fn_5_2E00` and `fn_5_6E8` both display 1-2 in `context` yet
`fzgx claim` refuses both with "attempt cap 3 reached". Judge claimability from
`fzgx inventory`, not from `context`, and do not read a low `context` counter as
an invitation to retry.

Unblocking any of these needs triage judgement, not another blind attempt: the
four near-misses (`fn_5_6E8` 94.85, `fn_5_37C` 93.34, `fn_5_4C8` 92.93,
`fn_5_3C44` 94.81) should be re-derived from the saved diff corpora rather than
resubmitted.

## car_colchg hand triage (2026-10-03 status report follow-up)

`colchg_selmate_disp` is **code-complete at 99.6%**. All 8 remaining rows are
`L` rows and the oracle reports zero rows owned by the matcher. The eight loads
(160.0, 50.0, 255.0, 0.5, 480.0 and one f64) belong to the module's *shared*
literal pool `lbl_9_rodata_0` at offsets 0x14/0x18/0x3c/0x40/0x44/0x48, but a
standalone carved unit compiles them into its own anonymous `.rodata.0`, so
only the base symbol differs. Rewriting the loads as field reads through the
shared `PoolRow` symbol *regresses* to 96.7%: it adds a `lis @27@ha`, reorders
`lis lbl_9_bss_14` / `lis lbl_1_rodata_26F8`, and swaps the `fmuls` operand
order. The release path already prints the needed binding as
`pool_map {"...rodata.0": "lbl_9_rodata_0", "@15": "lbl_9_rodata_14",
"@16": "lbl_9_rodata_18"}`. This needs the layout/pool priming path
(`fzgx fixup` with a seeded corpus, or `fzgx data-import` pool_objects), not
more matcher attempts. Best body:
`.fzgx/attempts/colchg_selmate_disp.1790882668.c`.

`colchg_menu_disp` stays at 94.7% (best body 90.1% locally). Two hand
variants both regressed and are recorded so they are not retried: the
inline ternary argument form gives 87.9%, and hoisting the format string into
its own local spills r28 and gives 81.7%. The 8 differing rows are the
`fn_1_496FC` argument materialisation order (retail schedules
`lfs f2 lbl_9_rodata_18[0]` before `stw r30`; the candidate schedules it after)
plus the switch guard register: retail keeps the sign-extended induction
variable in **r5** for both `cmpwi r5, 0x73` and `cmpw r0, r5`, while the
candidate reuses r3/r4. A fresh candidate should aim to keep the loop
induction in r5 and to let the second float load hoist with the first.

`fn_3_15A0` (customize, 7680 B) is **blocked as unrecoverable locally**. All 8
attempts' best bodies (peak 60.6%) live only under
`/Users/rayan/fzgx/.fzgx/attempts/`; neither `state/repairs/large_near_frontier_20260914`
nor `large_closures_20260915` contains it, so there is no seed to hand-decomp
from. 8 attempts across 4 model tiers all plateaued 54.7-60.6%, which is the
measured stopping condition. Unblocking requires copying the rayan-host bodies
into `state/repairs/` as a portable archive, or a fresh carve with a new seed.

## Link-rejected object-perfect bodies (2026-10-03, see docs/findings/279)

Two of the six are now matched (see docs/findings/279 for the tool and the
full result table). Six functions were object-perfect and link-rejected because their
`.fzgxpool` layout
primer is never stripped: `poolfix.apply` runs only under `matched_pool`, and a body
with `pool_rows: 0` never reaches it. Five are at exactly 100.0%: `fn_3_17098`,
`fn_1_7E8F4`, `fn_1_C6F8C`, `fn_1_FC760`, `fn_8_704`; plus `colchg_selmate_disp`
at 99.61%. The recipe, validated end to end on `fn_3_17098` (object 100%, module
byte-identical to retail, `16 files OK`): drop the `.fzgxpool` block but keep its
file-scope declarations, include `types.h` plus the module headers, then delete
exactly the globals the linker names `multiply-defined`. Corrected body archived at
`.fzgx/attempts/fn_3_17098.PRIMERLESS-100.c`.

Do not read "Section '.fzgxpool' is unknown" as the failure; every REL link prints it
and still returns 0. And a `15 files OK / 1 FAILED` line under fleet load is usually a
stale mid-write read: re-run `build/tools/dtk shasum -q -c config/GFZE01/build.sha1`
by hand before believing a rejection.

## Split gaps block a third class of object-perfect bodies (2026-10-03)

A function with no `.text` split range cannot be linked, and `oracle.check` cannot see
that: it diffs one object against the retail object and never builds the module. Carving a
unit adds a *second* copy, so the module grows past retail or the REL step cannot resolve.
`splits.txt` is ours (`dol split --no-update` never rewrites it), so adding the range is
safe. Use `python3 tools/fzgx/splitgaps.py --only-unmatched` before submitting a body.

- `fn_8_704` (title): split `0x704..0x754` added. The reported
  `Failed to find symbol fn_1_14F118 in any module` was a red herring -- nothing in that
  body references it. Now **matched** (commit 1476a20e).
- `fn_12_23410` (movie_module): split `0x23410..0x23700` added. Module size delta went
  from +280 bytes to 0, so the ownership problem is gone. It is no longer a 100% body
  though: in its real split context it scores 97.2% (ins 4, op 2, regalloc 1), and
  `static inline` on its helper changed nothing. Its earlier 100% was measured against the
  auto object rather than the split's retail object.

1,422 unmatched functions have no split. That is the normal state, not a defect backlog --
a split appears when a function links -- but every one of them needs its range added
before its body can be accepted.

## Verify's hash read races with the fleet

`verify` relinks and then runs `shasum -c` immediately. Under live fleet load that read
can land mid-write and report `<module>.rel: FAILED / 15 files OK` for a module that is
byte-identical to retail. Observed four times in this cohort; every one checked by hand
came back `16 files OK` with zero differing bytes. Two of them were then re-submitted and
verified normally. **Do not re-derive a body because of this line.** Confirm with:

    build/tools/dtk shasum -q -c config/GFZE01/build.sha1

and compare bytes against the retail file (`main_rel` is `files/enemy_line/main.rel`,
the others are `files/fze.<module>.rel`). A real layout problem shows a *size* delta or
non-zero differing bytes; `fn_12_23410` did, which is how it was told apart from the
races.

## Lint gates an object-perfect body: use `fzgx-allow`, do not rewrite (2026-10-03)

`fn_15_27D4` (winning, 784 B) checked at **100.0% adjusted (MATCH pool)** -- zero differing
rows, only literal-pool relocations -- and was still refused by submit:

    lint: 13x S2 "volatile without a justification comment", 1x A1 "hardcoded address
    0x808080FF"

Every S2 is a `.fzgxpool` layout-primer sink, and the A1 is a *colour constant* in a
`static const u32` table that the 0x80000000 range check mistakes for an address. None of
them is a defect. Per docs/findings/272 the fix is a justification comment, never a source
rewrite: a rewrite changes codegen and costs the match (that is exactly what happened to
`fn_1_58248`, dropping 100% to 91.07%).

`lint.py` honours a line-scoped opt-out:

    // fzgx-allow: S2 layout primer sink: MWCC emits the literal pool in first-access order
    // fzgx-allow: A1 0x808080FF is an RGBA colour constant in this table, not an address

Derive the comments from the real findings rather than guessing -- `fzgx.lint.lint_file()`
returns `(rule, line, message)` triples. With them applied the body stayed at 100.0% and
was link-verified (`92716aa4`). Note `0x808080FF` and friends will recur in any body holding
an RGBA table; A1 on such a line is a false positive worth suppressing explicitly.

## Lint-fixable near-miss sweep (2026-10-03)

59 unmatched functions at >=97% have a preserved body whose lint findings are *entirely*
comment-fixable (S1/S2/A1/A2/A3): `.fzgxpool` primer volatiles, and colour constants like
0x808080FF that the address-range check misreads. `python3 tools/fzgx/lintallow.py <symbol>`
derives `fzgx-allow` comments from the real findings and re-lints until clean. Do not rewrite
the source to satisfy lint -- comments are free, a rewrite changes codegen.

Worked `fn_8006A554` (main, 532 B) from 99.89 to **99.9%**: the S1 allows cleared and the
`(f >> 8) & 0xFFFFFF` -> `(f & 0xFFFFFF00) >> 8` rewrite turned `srwi` into retail's
`clrlwi`. One row remains and it is **register assignment, not statement order**: retail
`add r25,r28,r25` puts `p` in the destination register, ours puts `len`. `len` is `s32` and
`p` is a `u8 *` parameter, so `len += p` does not compile and source-order swaps do not move
the register. This needs the allocator's view of the two locals' live ranges. Corrected body
at `.fzgx/attempts/fn_8006A554.LINTALLOW.c`.

## Two 99.9% bodies blocked on register allocation (2026-10-03)

Both are one or two rows from done and neither is a codegen-shape problem:

- `fn_12_72F4` (movie_module, 172 B): 43 rows, **1** differs -- retail `mr r30, r25`
  against ours `mr r30, r27`. Same value, different scratch register, for the pointer live
  across the `fzgx_live()` call. Collapsing the redundant `fzgx_live_` temp changed nothing.
  Moving `arg` to the first declaration produced **13** regalloc diffs (much worse), so the
  declaration order is nearly right and wants a one-position nudge, not a rewrite.
- `fn_8006A554` (main, 532 B): **2** differ. Retail `clrlwi r0, r4, 8` is `f & 0xFFFFFF00`,
  a *mask*; the candidate emits `clrrwi`, a logical *shift*, for that same mask. Routing the
  mask through an explicit local regresses the frame from -0x50 to -0x58 with 5 extra rows, so
  MWCC folds the mask away when it is consumed by the pointer add. The remaining `add
  r25,r28,r25` vs `add r25,r25,r28` is operand order, not register assignment.

## `functions.best_percent` is trustworthy (checked, 2026-10-03)

Ranked candidates by the ledger's `best_percent` and chased `fn_8006A768` at a reported
99.94 that no attempt ever recorded -- every attempt maxed at 93.2. Checked the whole ledger
rather than assuming: of 1698 unmatched functions exactly **1** (`fn_8006A8CC`) has a
`best_percent` no attempt supports. The 231 other rows are matched functions imported without
a matcher attempt, which is expected. So the column is sound; rank candidates from
`max(attempts.best_in_attempt, attempts.final_percent)` anyway, since it is the figure the
evidence supports.

## Two measurement traps in the check store (2026-10-03)

Both were nearly reported as findings and both are wrong:

- **`rows: 0` in `state/checks/<sym>/index.jsonl` does not mean "no differing rows".**
  It is the pool-adjusted count, so a body whose only differences are literal-pool
  relocations records 0 even while its object differs. 118 unmatched functions at >=99%
  store `rows: 0`; re-checking `fn_10_A90C` by hand showed **2** real differing rows.
  Use `matched: true` in the same record, or re-check, never `rows`.
- **`own_kinds` is not recorded in the check store** at all, only in live check output. Any
  query that buckets the >=99% cohort by differing-row kind from `index.jsonl` silently
  returns nothing, which reads as "no functions have regalloc rows" rather than "the field
  is absent". The regalloc residue is real and visible in live output.

Also settled: the >=99% unmatched cohort is **register allocation, not codegen shape** --
`fn_12_72F4` (`mr r30,r25` vs `r27`), `fn_10_A90C` (`extsh r29` vs `r31`),
`fn_8006A554` (`clrlwi` mask vs `clrrwi` shift plus one `add` operand order). The
deterministic engine confirmed the class is not reachable by mechanical means: on
`fn_12_72F4` it tried **3,681 candidates** (declaration order, type/sign flips, pragmas,
pool priming) and none beat 99.9%, concluding a structural change is required. Chasing
these one at a time by hand is a poor use of budget; they need a different kind of attempt.

## The allocator-constraint lever exists but cannot run on this host (2026-10-03)

The regalloc residue is **90 functions classified `pure == 'regalloc'`** (plus 6 mixed), and
the repo already contains the structural lever for it: `mwgraph.py` models MWCC's allocator
(replay / simplify / `selection_order`), `mwconstraints.target_mapping` derives the desired
physical mapping from target-vs-ours, and `declaration_projection` predicts a declaration
reorder that realises it, with strict no-rewrite safety checks. This is exactly the "pin this
value to r30" capability the residue needs, and it does not rely on permutation search.

**Two real breaks stopped it from ever firing, both now fixed:**

1. `fixup.py` wrote `results.json` with a hardcoded `pure: 'unclassified'` for every entry,
   while `mwgraph.capture()` skips anything not `regalloc` (mwgraph.py:317). So capture
   rejected the entire corpus and the constraint machinery never ran on anything.
   `fixup._stuck_modes()` now reads the modes `stuck.analyse()` already computes.
   The corpus now carries 376 functions, **89 of them `regalloc`**.
2. `Engine.evaluate()` used `row['flags']` directly in a dict key. Some saved-candidate
   records spell it as a list, which is unhashable and crashed the entire corpus build with
   `TypeError: unhashable type: 'list'`. A tuple fix then reached the shell layer, which
   shlex-splits it, so list flags are now joined to the string form the engine expects.

**The remaining blocker is environmental, not a code bug.** The allocator graph only exists
inside the running compiler, so it must be read under LLDB, and capture launches
`xcrun lldb`. This host has neither `xcrun` nor `lldb`, and no package index to install one.
capture() now fails with that explanation instead of `FileNotFoundError: 'xcrun'`, and accepts
a bare `lldb` where one exists. Until a host with LLDB captures, `mwconstraints.constrain()`
has no snapshots and the 90 regalloc functions stay blocked -- the classification in
`results.json` is now correct and will be used as soon as a capture is possible.

## Allocator capture now runs on this host (LLDB installed 2026-10-03)

`sudo pacman -S lldb` put LLDB 23.1.1 on PATH and the capture path runs end to end for
the first time:

    uv run tools/fzgx.py fixup --capture --corpus .fzgx/fixup/corpus --output .fzgx/captures
    -> {"functions": 375, "capture_seconds": 26.1, "errors": 0, "unsupported_simplify": 0}

545 allocator graphs (376 GPR, 169 FPR) with **named** virtual registers
(`fzgx_loop_temp_f30_4213`, `temp_f31`, ...), so `declaration_projection` can address
locals by name. All 89 `regalloc` corpus functions have a capture; 26 pass the
`simplify(before) == before['simplify_order']` precondition with zero failures.

The capture wrote **6 source projections** (`*.projection-N.c`) -- declaration reorders
predicted from allocator witnesses. That machinery had never produced anything before the
`results.json` classification fix.

**Result so far: no match, but the lever demonstrably moves bodies.**
- `fn_1_15EC40` (main_rel, 940 B): **99.15% -> 99.5%**, and now reports **0 rows that are
  the matcher's to fix**. The repair labelled it `regalloc: scope loc_8`. What remains are
  2 literal-pool base `L` rows, which need the pool retarget, not a source edit. The corpus
  reports `score 100.0` on masked words while the oracle still refuses at 99.5% -- do not
  read that score as a match.
- `fn_1_4068C` (132 B): 99.6% with 2 `frame` rows against a 99.64% baseline; the reorder
  does not pay there.

**Next step for this cohort:** the projection fixes the regalloc rows but the survivor is
always a pool-base `L` row. The two repairs need to be composed -- apply the projection, then
run the layout/pool priming on the result -- rather than run separately.

Reproduce the capture with the command above; the snapshots live under `.fzgx/captures`
(gitignored, ~26 s to rebuild).

## Where main_rel actually stands: large functions are cold, not near (2026-10-03)

Unmatched `main_rel` by size, scored from `max(best_in_attempt, final_percent)`:

| bucket | fns | bytes | below 90 % | 90-99 % | 100 % |
| --- | ---: | ---: | ---: | ---: | ---: |
| >=2 KB | 122 | 413,260 | **110** | 10 | 0 |
| 1-2 KB | 252 | 355,104 | **218** | 33 | 0 |
| 512 B-1 KB | 264 | 195,908 | 139 | **122** | 2 |
| 257-511 B | 144 | 55,424 | 44 | **100** | 0 |
| <=256 B | 77 | 12,948 | 24 | **52** | 1 |

**The premise that the large functions are the near-miss work is wrong.** The >=2 KB and
1-2 KB bands are 768 KB -- 74 % of main_rel's unmatched bytes -- and 328 of their 374
functions score **below 90 %**. They are cold: no saved reconstruction, nothing to climb
from. A repair sweep over them has nothing to work with.

The near-miss mass is one band down: **512 B-1 KB holds 122 functions at 90-99 %** plus 2 at
100 %, and 257-511 B holds 100 at 90-99 %. Those are what `fzgx sweep` is for.

Measured, 10 main_rel functions from the 512 B-1 KB band, 2 rounds:

    round 0: 10 functions, 1128 candidates -> 2 improved
    round 1: 10 functions, 1111 candidates -> 1 improved
    fn_1_F6A8  95.81 -> 96.36  ['signed: sz: u32 -> s32']

So `sweep` is a **seed lifter, not a closer**: it improves a minority of bodies by a
fraction of a percent, which is exactly what the historical note predicted (686 bodies at
90 %+, 4 rounds: 5 matches, 167 improved). Each improvement is a better starting point for
the fleet, but expect ~0-5 % closure per pass, not a haul.

## Fleet allocation mismatch: the cold functions land on the weakest family

`FAMILY_BANDS` sends **all 122 functions >=2 KB to `oc4`**, whose band is the catch-all
`(257, inf)` and whose measured yield is 0.63 matches/hour -- second-worst of the free
families, and an order of magnitude below gpt's 4.76. So 413 KB of the hardest work is
queued at the family best suited to easy material.

GPT is quota-capped and banded to `(0, 256)`, so it cannot absorb them either. Given the
free tier is the only scalable capacity, the honest options are (a) leave the large
functions to `oc4` accepting a low rate, or (b) widen `cline` past 512 bytes and let it
compete for the same cold work -- it is *worse* per hour (0.42) than oc4, so that is not an
improvement on its own. Neither move is free capacity, so this is a judgement call about
where to grind, not a bug.

## gpt pointed at the large functions, and the token limits are not the obstacle (2026-10-03)

`FAMILY_BANDS['gpt']` moved from `(0, 256)` to `(1024, inf)` and the daemon restarted so the
change took effect. First claims under the new band were `fn_1_12DAEC` (1484 B) and
`fn_1_2D038` (1260 B), both previously outside gpt's band. Both reached **99.7%** within a
few attempts -- the first evidence that the cold large band is not unreachable, it was just
never being offered to the model that can handle it. This is an experiment; revert to
`(0, 256)` to restore the yield-tuned assignment.

**No token limit needs raising, and raising one would be harmful.**

- `fleet_multi` passes `FZGX_MAX_MODEL_INPUT_TOKENS=0` and `FZGX_MAX_MODEL_OUTPUT_TOKENS=0`
  to every fleet session -- both guards are disabled. FLEET.md records why: they were
  removed on 2026-10-01 because cumulative input counts re-read cached context each turn,
  so the guards killed productive sessions and triggered exponential backoff.
- `build_context` bounds only *auxiliary* material: `limit = required_chars + budget_tokens*4`,
  where `required_chars` is measured after the target assembly and its declarations are
  appended, and the truncation comment says so explicitly ("Bound examples/history/idioms,
  never the assembly or its declarations"). Verified on the largest unmatched function,
  `fn_1_BC310` (9832 B, 2458 instructions): **2458 of 2458 assembly rows present**, with only
  `## MWCC idioms`, `## Rules` and `## Matched code` dropped.
- `tools/codex_models.json` lists only `deepseek-flash` with a 1 M context window. It is a
  legacy file and governs nothing for `gpt-6.1-sol`, whose limits come from the Codex app
  server. Do not read it as the model's real configuration.

So a large function's assembly reaches the model in full. The limit on this work is effort
per function, not context.

## Sweep over the 119-function main_rel band: seed lifter, confirmed at scale

    fzgx sweep --min-percent 90 --max-percent 99.5 --rounds 4  (117 functions)
    round 0: 12801 candidates -> 15 improved
    round 1: 12724 candidates ->  5 improved
    round 2: 12715 candidates ->  2 improved
    round 3: 12698 candidates ->  0 improved
    matched 0, improved 6

~51,000 candidates over 4 rounds closed **nothing** and left 6 bodies better. The decay
15 -> 5 -> 2 -> 0 is the whole point: the sweep exhausts its cheap families quickly and then
stops. Its value is the 6 better seeds it hands the fleet, not closure. Re-running it on the
same band is spent effort -- the per-function improvements are saved as attempts, and the
next pass should target whatever the fleet has moved since.

## The two gpt large-band functions: why the projection path declined one (2026-10-03)

Both are `pure`-classified and were treated with the right tool, not the same one:

- **`fn_1_12DAEC` (main_rel, 1484 B) is `pure=regalloc`.** Targeted corpus
  (`.fzgx/corpus_12daec`) classified it `regalloc`; capture succeeded (1 function, 0 errors,
  5.5 s) and the captured object scored **100.0**. But the constraint stage returned
  `needs-web-alignment` and produced **0 projections**:

      conflicts: {'r3': ['r20','r21','r3'], 'r20': ['r20','r3'], 'r21': ['r21','r3']}

  `r3` is reused across unrelated value webs, so no single physical mapping fits and the
  guard refuses to guess. This is `mwconstraints` working as designed -- its docstring says a
  physical map is only a fixed-graph hypothesis and conflicts require PCode/web alignment,
  "not a broader permutation search". Closing this class needs web alignment, which does not
  exist for this path yet. This is the concrete next engineering item, and it is what gates
  the rest of the regalloc cohort, not just this one function.

- **`fn_1_2D038` (main_rel, 1260 B) is `pure=imm`**, so the projection path was the wrong
  tool. Its single differing row is a base+offset form choice: retail
  `lbz r0, 0x5(r3)` against ours `lbz r0, 0x35(r31)` -- the same address, since r3 is
  base+0x30. Three source variants: reading the properly typed field directly regressed to
  98.9 %; keeping the `hdr*` cast and adding a distinct typed `phdr` local both stay at
  99.5 %, with MWCC folding base+0x30+5 into base+0x35 either way. Reaching retail's form
  needs the pointer to stay live in a register, which the current expression does not force.

Note `object% 100.0` in the capture report is `oracle.function_score` on the captured
object, **not** an oracle acceptance -- the unit check still reports 99.66 %. Do not read the
capture's object score as a match, the same trap as the corpus's masked-word `score`.

## Web alignment is worth building -- for 67 of 189, not all of them (2026-10-03)

`target_mapping` returned one undifferentiated `needs-web-alignment` for every register-map
failure, but that single label covers two problems needing opposite responses. Bindings are
now split into **hard** (order-fixed, non-commutative operand positions) and commutative
(operand order on `add`/`and`/`xor`/... which is deferred anyway), and the failure reports
which kind it is:

- **`commutative-only`** every hard binding agrees and is injective, so the two objects *are*
  related by a register permutation and the disagreement is only commutative operand order.
  Web alignment is the right tool.
- **`structural`** the hard bindings themselves disagree, so no register permutation relates
  the two objects. Instruction shapes already match, so the difference is in the values: a
  value live across a span retail splits, or the reverse. The conflict is **evidence of a
  source defect to fix first** -- aligning the webs would mean aligning two different
  programs.

Measured over 361 captured functions:

| constraint status | functions |
| --- | ---: |
| `fixed-graph-hypothesis` | 26 |
| `needs-web-alignment` | 189 |
| `unsupported-instruction` | 61 |
| `instruction-shape` | 85 |

and of the 189: **`commutative-only` 67, `structural` 122**.

So building web alignment addresses **67**, and the other **122 need source repairs**. Without
this split, the natural reading of "189 need alignment" would have sent the whole effort at
the wrong half. `fn_1_12DAEC` is `structural`: its hard conflicts are
`{r3: [r20,r21,r3], r20: [r20,r3], r21: [r21,r3]}`, so no permutation relates it to retail
and the fix is to split a local, not to align anything.

`_consistent_hard_map` returns a map only when it satisfies every hard row and is injective;
anything else is None, which is the conservative direction. It is unit-tested for the
collision and conflict cases, and the sets-not-lists bug it had on first run against real
captures is fixed.

## Scope of the projection path, measured honestly (2026-10-03)

Of the 361 functions captured, the projection pipeline's stages are a funnel:

| stage | functions |
| --- | ---: |
| captured | 361 |
| `fixed-graph-hypothesis` (reaches the witness stage) | 26 |
| of those, `>= 99.5 %` on the real oracle | 7 |
| emit an actual `*.projection-N.c` | ~4 |

So **web alignment plus `declaration_projection` is a small lever, not the big one.** It is
the right tool for the 67 `commutative-only` functions, but `declaration_projection`'s own
safety checks -- no initializers, at least two movable locals, the reverse-creation-order
stratum verified before projecting, frontend parameter positions immovable -- reject most of
the 26. Those rejections are correct and should not be loosened.

The 7 that are both closest and reachable:
`fn_1_128B60` (632 B) and `fn_12_23410` (752 B) at 100.0 %, then `fn_1_82EDC` 99.90,
`fn_1_131194` 99.89, `fn_1_1024F8` 99.87, `fn_1_F7F48` 99.66, `fn_1_4068C` 99.64.

Caveat that bit twice while writing this up: the 100.0 % figures come from
`max(best_in_attempt, final_percent)` computed **in Python**. Doing the same maximum in SQL
(`max(COALESCE(best_in_attempt,0), ...)`) returns garbage -- `attempts.best_in_attempt` is
declared REAL but stores text on some rows, so SQLite compares strings and `max` returns 0 or
a lexically-larger string. The same query made `fn_1_15EC40` read 82.51 % when it is 99.15 %.
Compute these maxima outside SQL.

`functions.best_percent` is a separate trap, already recorded above: only 1 of 1698
unmatched functions has one no attempt supports, but it is still not the figure to rank on.

## The lint-blocked-at-100% class is exhausted (2026-10-03)

305 unmatched functions sit at >=97% and are not link-rejected, so they are the
population that `lintallow.py` can convert. Running the full loop on the top of it
(`lintallow` -> `claim` -> `write-unit` -> `check` -> `submit`, submitting only on a
literal MATCH) converted **1 in 7**: `fn_1_FD3A8` (1180 B) was a pure-lint-blocked
100.0 % and submitted clean. The other six all check at 99.9 % and are genuine
source work, not gate rejections.

So the bottleneck that produced `fn_15_27D4` is a one-function bottleneck, not a
class. Only one such case remained and it is now matched. Ranking future repair
effort on ">=97% and not link-rejected" will overstate it: 304 of those 305 need
real source changes, which is the model's job, not a mechanical pass. The
mechanical passes that remain are `primerless` and `splitgaps`, on the link-rejected
population only.

Batch driver lives at `/tmp/lintbatch.sh` (lintallow -> claim -> check ->
submit-on-MATCH). It deliberately uses a distinct `--agent lint-batch` claim so it
can run alongside the fleet without stealing claims.

## Ownership-credit reconciliation (2026-10-08)

The owner requested reconciliation of credited-but-unauthored code. The following
legacy ledger credits were suspended through the supported block API, not counted
as solved or supplied with invented C. Both had missing canonical/work source,
no accepted commit, and no reproducible exact saved body. Prior rows and the
coverage audit are retained in the committed storage/structural evidence dossier.

| Symbol | Bytes | Concrete blocker | Preserved attempt count |
| --- | ---: | --- | ---: |
| `fn_80036AC4` | 352 | Registered DOL C is missing; recover an exact body and full link proof | 2 |
| `fn_12_D0B8` | 884 | C/acceptance commit missing; old blanket asm-only diagnosis is unproven, with one HID2-read intrinsic avenue | 1 |

The archived `link_state` and score fields are historical, not current acceptance:
only status `matched` plus real source and link proof may regain credit. Do not use
unblock as a way to reset attempts. This changes unsupported credit accounting,
not the authored-C numerator or the sixteen-target hash obligations.
