# Production recovery: one Hermes, two Codex, compiler-pinned batches

## Owner-directed execution mix

`gpt` is enabled with two sessions, Codex `gpt-6-luna`, high reasoning.
`oc1` alone is enabled with one Hermes `stepfun/step-5-preview:free` ultra
session through Nous. Other lanes are off, automatic surge is off, and no
silent fallback or provider cooldown reset is authorized. Actual Codex
`thread/started` receipts report `model=gpt-6-luna` and `reasoningEffort=high`.
The first completed Codex assignment issued eight tool calls/six compiler
checks and released a 95.65% best candidate; it is productive tool execution,
not a delivered exact match. Hermes's existing idle-failure cooldown is retained.

## 1. Restore productive capacity

The four-Hermes-only retry cycle was drained with no claims left. The new
controller has two working Codex sessions, with whole-unit reservations and
atomic claims unchanged. Keep the enabled Hermes lane bounded by the existing
compiler-progress idle timeout. Do not reinterpret an enabled cooling lane as
an active session. Do not expand session counts to compensate for zero yield.

## 2. Preserve measured compiler pins

A manifest is a closed batch input. Formerly a mixed batch containing both a
pinned near-miss and ordinary work omitted `--seeds` for the entire batch.
`seed_batch_symbols` now keeps the first selected seed class BEFORE reservation
and scheduling history are recorded. Deferred symbols are not marked tried.
Direct mixed `command` calls and incomplete source/hash records fail instead
of silently discarding the pin.

Tests reproduced ordinary/seeded mixing, direct mixed dispatch and an incomplete
pin record; all six regression tests pass. Permanent tests are in `tests/test_fleet_seed_batches.py`.
Run `.venv/bin/python -m unittest discover -s tests`.

## 3. Residual conversion and shared declarations

The 63-body compiler-aware <=2-row corpus was frozen from finding 304's
portable archive. Two members (`fn_1_15B70C`, `fn_1_727C`) were already matched
and were correctly excluded by the repair engine. The bounded two-round pass
searched 61 eligible functions, evaluated 5,847 variants, and delivered zero
matches and zero frontier improvements. `--apply` accepted/rejected no functions.
This is negative evidence for these existing rewrite families at these pins,
not permission to repeat unchanged input with larger budgets.

Three localized unsigned-shift hypotheses for `fn_80043798` produced 10–19
residual rows rather than one. The source patterns were absent in its sibling
`fn_800446E4`, so they were not guessed into it. Two halfword-store hypotheses
for `movie:_prolog` fixed the local width but disrupted scheduling, producing
20 residual rows. Original best bodies remain intact. These residuals require
structural/allocator evidence, not another generic sign-flip sweep.

Shared-TU blockers were reproduced with actual canonical prologues:

| candidate | standalone saved baseline | integrated before | repaired integrated |
| --- | ---: | --- | ---: |
| fn_1_9A958 | 97.73585% | owned array redeclared as struct | 92.830185% |
| fn_1_A02F0 | 98.1982% | fn_1_46B4 prototype conflict | 98.1982% |

For `fn_1_9A958`, keep the shared `burner.h` declaration of
`lbl_1_data_2A0C0`, and use a typed view rather than redeclaring the symbol.
For `fn_1_A02F0`, retain the sound prologue's
`void fn_1_46B4(u32, void *, void *, u32)` signature and explicit first-argument
casts. Both repaired candidates compile with the real prologue; neither is an
exact match, and the burner candidate has a real integrated-score regression.
Do not erase that regression or claim accepted source. The integrated sources,
compiler pins and prologue hashes are in the existing priority manifest, with
portable evidence in `state/repairs/shared-tu-declarations-20261011.json.gz`.
The ledger's higher-scoring standalone bodies were not overwritten.

### Bounded Codex retry and the implicit-release latency trap

`shared-tu-compatibility-codex-20261011` used exactly two `gpt-6-luna/high`
sessions, with the standing fleet drained first, explicit source/compiler seeds,
8 checks, 3 stale checks and 240-second model deadlines. The model turns were
interrupted at their deadlines, but outstanding `patch_unit` calls had taken
more than 200 seconds. The outer terminal call timed out at 420 seconds before
summary/cleanup, leaving two orphan claims. Both claims were recovered through
owner-matched CLI release after confirming no batch runner remained, and the
standing fleet was restored. Ledger outcomes are two released attempts, not
accepted matches. No completed batch summary exists; do not manufacture one.

The retry did recover a better **compatible** `fn_1_9A958` body: 95.9434%, with
the canonical burner prologue unchanged, versus the initial compatible 92.830185%.
It is preserved in `state/repairs/burner-compatible-frontier-20261011.json.gz`
and the priority seed manifest. The incompatible standalone 97.73585% remains
separate. A fresh compiler replay proved the new compatible score and source hash.

The bound stop path called `release` without `save_only`, invoking the potentially
minutes-long full repair search inside a model's patch/check response while holding
the single tool-worker slot. This is not ordinary compiler latency: recovered
sources replayed in 0.36 and 0.05 seconds. Automatic budget/plateau stop now uses
`save_only=True`; explicit search and preflight repair remain available. Its
regression test failed before the change and passed afterward. A real non-stub
98.1982% source reached a one-check budget stop, archived its source and cleared
its claim in 0.12 seconds; the archived body independently replayed at 98.1982%.
The full suite now has eleven passing tests.

## 4. Byte-weighted work and module closure

The existing selector already reserves two thirds of a batch for `main_rel`
when supply permits, and one closure slot in batches of at least four. The seed
partition preserves that selected priority without weakening attempt/size caps
or unit collision guards. Current Codex receipts confirm actual `main_rel` work,
not merely a simulated queue allocation.

The known remaining `main_rel` inventory is 793 functions / 994,020 bytes,
56.57% of the 1,757,180-byte known remaining inventory. Prioritize coherent
shared-TU interfaces and fresh medium/large bodies; generic small-function
counts are not the main progress objective.

The three one-function module closures were exercised with the existing lift
engines:

- `car_colchg`: `fn_9_AF0`, 720 bytes.
- `replay`: `fn_13_3FC`, 1,604 bytes.
- `sample`: `sample:_prolog`, 1,020 bytes.

The basic lifter produced no candidates. The alternate m2c pass generated four
candidates, with zero matches, zero near results and zero submitted bytes.
Keep these as bounded subsystem investigations, not claimed closed modules.

## 5. Measure real accepted output

Use the existing `fzgx report` / `fzgx honest` paths and the authoritative build
report. At this continuation's measurement:

- Built objdiff: 39.711903% code, 5,756 / 7,312 functions.
- Authored measure: 1,161,384 / 2,924,488 known bytes, 39.7124%.
- Pending link: zero. Pool-matched: 42 (not ordinary exact deliveries).
- Unique link-verified successful functions in the previous 24 hours: two,
  totaling 900 bytes. Their `matched_commit` timestamps were checked:
  `fn_1_727C` (`f6012cea`) and `fn_1_15B70C` (`64e0eb74`).
- Since the new mix began: zero unique link-verified deliveries at measurement.

Deduplicate by the functions primary key, not attempt rows. Require matched
status, verified link state and a non-null matched commit. A recent successful
attempt is only a candidate for the daily metric: check the actual landing
commit timestamp before crediting its bytes. Report improvements, generated
candidates, compiler checks and accepted bytes separately.

## Remaining execution gates

The producer configuration and seed dispatch fix are operational changes, not
completion of the decompilation. Continue only from fresh source or compiler/
allocator evidence for exhausted residuals. Retain compiler-progress guards,
shared declaration compatibility, and all sixteen build hashes as acceptance
requirements. Count a new function only after exact compilation and link/hash
verification; no new exact match was produced by the bounded parent repair and
closure passes recorded here.
