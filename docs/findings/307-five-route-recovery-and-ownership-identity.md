# Five-route recovery: landability, compiler defaults, cohort, producer mix, closure

## Operational changes

The owner approved all five routes after the zero-delivery check-in. Existing
fleet jobs were drained before changes. Two Codex `gpt-6-luna/high` slots remain
enabled; Hermes Step5 ultra automatic retries are parked, with its pin and
cooldown untouched. All other lanes remain off, automatic surge remains off,
and no new manual model agents or model fallback were introduced.

## 1. Landability is an admission gate

The previous selector reproduced six uncovered symbols in an eight-symbol
selection. Sorting uncovered work last was not sufficient: it became the paid
fallback when other pools could not fill the batch.

The selector now excludes symbols lacking either a registered unit or an
executable split range. Both `.text` and `.init` are recognized. Validation
used actual inventory, plus registered/range controls for every known nonzero
matched function; none failed the control. Unit reservations, attempt/size caps,
module-share limits, and source protection remain intact.

Five units were dry-run, carved and registered with the existing tool:

- fn_80059884: 144 bytes, DOL; measured GC/1.3.2 pin retained in its unit.
- fn_800736C0: 184 bytes, DOL; measured GC/1.3.2 pin retained in its unit.
- fn_1_A3BD8: 160 bytes, main_rel sound.
- fn_13_3FC: 1,604 bytes, replay.
- sample:_prolog: 1,020 bytes, sample.

These are registrations, not newly authored exact matches. The rebuilt DOL and
all fifteen RELs passed their hashes after registration. When supply is exhausted,
only the existing bounded, measured carve path may replenish it; the selector
cannot resume unlandable fallback dispatch.

## 2. Compiler-default audit uses the right comparison

`levelrecheck` compared positional machine words. A save-helper insertion shifts
the function and makes that metric rank a materially worse aligned match higher.
For fn_12_364CC it ranked default 1.04% below -O2 1.71%, although the fresh aligned
verdict was default 91.29% versus -O2 71.77%. This inverted the decision.

The tool now uses aligned, relocation-aware word agreement, includes the real
unit compiler/extra flags, and atomically writes its advertised `--out` report.
The actual-symbol regression failed before and passed after the change. The old
positional diagnostic text is marked historical.

All 259 recorded levels were freshly rechecked. Results:

- 201 strictly harmful settings removed from state/compiler_options.json.
- 32 beneficial settings retained.
- 26 equal-scoring settings conservatively retained rather than discarded.
- No unavailable bodies in this audit.

The retained 58 settings were rechecked after the write; none was strictly
harmful. The measured non-level `-use_lmw_stmw on` option for fn_12_364CC was
retained in its unit. No matching source or accepted compiler setting was
rewritten merely from an old percentage. The original map, all 259 body hashes
and the fresh audit are archived.

## 3. A real, coherent admitted cohort

The 2,852-byte car_test fn_1_7D6B8 and three newly registered small near-misses
were compiled with actual shared-TU prologues and GC/1.3.2 pins. All four were
compatible before admission. Stock compiler/allocator captures validated normal
object identity and replay with no errors.

The existing capture-guided fixup ran two bounded rounds: 388 evaluated variants,
zero exact matches, one improved frontier. For fn_1_7D6B8:

- Raw similarity: 99.66339% -> 99.67742%.
- Aligned adjusted similarity: 98.74% -> 99.02%.
- Differing aligned rows: nine -> seven.
- Framework word errors: ten -> eight.

The improved source preserves the shared prologue and is independently checked.
Unimproved or worse framework-selected carrier variants were NOT adopted; the
other three seeds retain their original measured compatible C.

The priority manifest now contains all four exact source hashes/pins. A newly
measured cohort takes precedence through a one-admission token keyed by source,
compiler, flags and prologue, not HEAD. The existing scheduling receipt marks
only actually dispatched symbols. Simulation on real inventory selects the
four sources, preserves the closed seed manifest, and does not reopen them when
only a batch snapshot changes HEAD. This is a bounded new-evidence retry, not an
attempt-cap increase or permission to repeat unchanged input forever.

## 4. Park the zero-yield producer

oc1 is disabled in the installed owner control, but retains
`stepfun/step-5-preview:free`, Hermes through Nous, ultra effort. Codex remains
parallel=2, high, with the same subscription model. Provider cooldowns were not
cleared. Control/policy were read back after the write. Thermal, memory, disk and
inode safeguards were not weakened. In particular, the ACPI temperature later
returned below the threshold, so the apparent CPU/ACPI discrepancy was not used
to bypass a potentially real thermal zone.

## 5. Correct module ownership before declaring closure

The strict progress reporter itself had two identity bugs: units were keyed by
bare symbol across modules, and ledger status was queried with bare `_prolog`/
`_epilog` rather than the qualified keys. `_prolog` occurs in fifteen modules;
`_epilog` occurs in thirteen. One module's registration could be borrowed by
another, and nineteen historical qualified matched functions were omitted.

Unit lookup is now module-qualified, and repeated function names use qualified
ledger identities. The actual car_colchg:_prolog control was false before and
correct afterward; car_colchg and replay resolve to distinct unit records.
Corrected historical authored accounting is 5,760 functions / 1,167,308 bytes,
39.915% of 2,924,488 known executable bytes. The 5,924-byte change from the
previous report is historical accounting, NOT a new delivery.

The true closure obligations are one function each: car_colchg fn_9_AF0,
replay fn_13_3FC, and sample:_prolog. The missing sample/replay units are now
registered and covered. Existing m2c sources were resumed in that new build
context; no exact match or submitted byte resulted. Sample's generation fails
closed with M2C_ERROR for unsupported byte-reversed stwbrx/lhbrx operations.
No no-op replacement or invented source was used to suppress that blocker.
None of the three modules is declared complete.

## Evidence and acceptance boundary

state/repairs/five-routes-recovery-20261011.json.gz contains four final stock
captures/C sources, independent retail verdicts, the full level audit and before/
after options, 259 exact body hashes, verified repair frontiers and closure data.
Its existing graph-format replay covers four functions/four allocation passes
with zero errors. Capture same-object agreement is baseline identity, not a
retail acceptance verdict.

31 pre-existing untracked operator files were hashed before work and remain
unchanged. Source registration and tooling changes must pass lint, the full
sixteen-target gate and preserved-file checks before publication. No new unit
test framework, opcode fixture, asm conversion, fake match output or unrelated
operator file was introduced. Existing model slots are restored only after that
gate. New executable bytes delivered by this recovery remain zero until a genuine
exact source candidate is integrated and hash-verified.
