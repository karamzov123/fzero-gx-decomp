# Byte-reversed memory lowering exposes missing stack extent proofs

## Reproduced blocker

The sample `_prolog` closure function failed m2c generation with M2C_ERROR for
three real instructions: two stwbrx stores and one lhbrx load. The unknown-store
fallback incorrectly treated the first operand as a register destination, so the
second store appeared to produce the value later shifted into a filename byte.

The repository adapter now models the store and load as real indexed memory
operations, preserving their register dependencies. It reuses ordinary indexed
memory classification and replaces evaluation with unsigned byte-reversal C
operations. This also avoids the pinned backend's width parser, which does not
recognize the `br` suffix. RA=r0-as-zero remains handled by the existing normalizer;
r0 in the index or source position remains an ordinary register.

Only the two operations found in this real function were added. No instruction
fixture, opcode-forcing variable, inline assembly, builtin no-op or compatibility
macro was introduced. Adapter restoration after generation remains checked.

## Validation against the actual function

The original generation assertion failed with unresolved M2C_ERROR before the
change. After lowering, raw sample C contains no unknown operations. Dependency
checks use input.s generated from retail, not synthetic opcode fixtures:

- stwbrx r0,r0,r28: store; inputs r0/zero/r28; no register output.
- stwbrx r4,r28,r0: store; inputs r4/r28/r0; no register output.
- lhbrx r5,r28,r0: load; inputs r28/r0; destination r5.

The actual unsigned expression helper passed all 65,536 halfword values with
nonzero upper input bits, confirming zero-extension, and 1,029 word cases
including edge values and deterministic random values. The reference is byte
serialization/reversal rather than another copy of the bit-expression formula.

The provisional generated draft compiled under stock GC/1.3.2 and the module
default. Both yielded raw similarity 44.611763%, adjusted 15.05%, and 254 differing
rows out of 299. The compiler recognizes the ordinary C byte-swap idiom and emits
stwbrx. This is neither a near-match nor an accepted source reconstruction.

## New safety boundary, not a suppressed error

Generation exposed an independent structural defect: a placeholder scalar sp47
is escaped, aligned down and used by memset with lengths 0x28 and 0x32. Merely
turning M2C_UNK into s32 would create a C object too small for those writes.

The generator now rejects escaped unknown stack scalars before returning a
candidate. The regression initially failed because generation returned that
unsafe draft; afterward it fails closed with:

    unproven escaped stack object extent: sp47

Raw C remains available as evidence. The previous provisional candidate in the
archive is explicitly diagnostic-only and must not be dispatched or submitted.
The same real closure control identifies replay's unproven sp68 extent, while
car_colchg:fn_9_AF0 still generates successfully. A conservative refusal is not
proof that replay's required object is large; it means the current placeholder
has no proven type/extent and needs analysis before admission.

## Continuation and provenance

The next source-realizability work is to recover escaped stack storage from real
address formation, call lengths and overlapping object ranges, including the
sample alignment expression. Do not fix this by renaming the unknown scalar,
guessing a GXTexObj type from an unrelated inferred signature, dropping the mask,
or assigning an arbitrary large array. Validate the recovered extent before
re-running the existing lift/fixup engine.

state/repairs/sample-byte-reverse-lowering-20261011.json.gz preserves input
assembly, raw/draft C, context and diagnostic verdict with six checked hashes.
It records candidate_admissible=false and zero delivered bytes. The standing
matcher slots were left active while investigating this independent tooling
path; no new models or higher attempt budgets were introduced.

## Completed cohort readback: reject score-only allocator tricks

The four admitted targets finished and released with no exact match. The car_test
fn_1_7D6B8 attempt reported raw 99.957924%; independent GC/1.3.2 replay gives
adjusted 99.3% and five aligned register rows, not a one-row match. Its shared
prologue is unchanged and allocator replay is clean, but source inspection finds
unused lab_pad storage and a void liveness expression added solely to influence
allocation. This violates the natural-C source rule despite its numerical score.

The draft is rejected, not a new accepted or admissible frontier. Its provisional
priority update was retracted; the previous source and its consumed admission
receipt remain intact, and no new claim was made on this rejected body. The other
three cohort targets did not improve their best bodies. Evidence is explicitly
candidate_admissible=false in
state/repairs/car-test-cohort-rejected-frontier-20261011.json.gz. A source/pin/hash
check and capture replay are necessary, but do not replace source-hygiene review.
