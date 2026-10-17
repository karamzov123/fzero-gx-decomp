# fn_1_F85A0: zero accumulator restored; shuffle still unmatched

Target: main_rel/spline fn_1_F85A0, 888 bytes. No accepted C change.

The archived draft initializes its shuffled-bit accumulator to 4. Retail
initializes the accumulator to zero before its 32-bit permutation loop.
Restore zero; remove allocator-only `(void) v18` and dead generated counter
copies, and use naturally named local loop counters. The oracle rejects the
unmodified allocator scaffold before compilation; do not submit it as C.

Measured valid candidates:

- Cached local LCG state, corrected zero accumulator: 97.175674%, 37 differing
  rows / 223 aligned; 31 register, 3 instruction-presence, 2 immediate,
  1 opcode difference. The accepted retail function has 222 instructions.
- Replace the cached state shuffle with calls to the existing static-inline
  global RNG helper: 83.1%, 114 differences / 236 aligned. Char accesses inhibit
  removing intermediate global state stores. Reject this shape.
- Keep a named pointer to the RNG state live across the cached shuffle:
  94.3%, 57 differences / 224 aligned. Generates lwzu and changes register
  pressure; does not reproduce the target's address materialization.

Best residual is concentrated in the two-way-unrolled shuffle and its final
state store. Target materializes RNG address with lis/addi/stw after the
shuffle; the cleaned scalar store folds to lis/stw. Distinct local counter
scopes also produce separate li operations where target uses li/mr for zero.
Keep signed modulo-32 source behavior: the retail sequence retains signed
remainder lowering even though the sampled value is masked to 15 bits.

`fzgx release` ran deterministic repair but did not close it; saved clean best
body and metadata:

    .fzgx/attempts/fn_1_F85A0.1792225199.c
    .fzgx/attempts/fn_1_F85A0.1792225199.json

Ledger readback: unmatched, best_percent 97.175674, no active claim.
Do not count this as a match or quote the older, semantically wrong draft's
higher similarity as progress. The next testable source hypothesis is an RNG
state access/helper shape that materializes its address only at final store
without preserving a pointer register throughout the shuffle.
