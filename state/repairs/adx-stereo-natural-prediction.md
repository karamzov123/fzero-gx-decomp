# fn_8004F00C: remove the copy-only prediction device

## Accepted scope

The stereo ADX decoder's inner loop no longer has an artificial `kept` local or
`kept = decoded_right` assignment. Both second-sample predictions now use the
same ordinary two-tap history helper, `PredictSample`, which multiplies the two
history samples by their coefficients, accumulates the products and shifts the
fixed-point result by twelve bits. The right-channel high sample remains in
`decoded_right`, which also supplies the real `older_right` state update.

This is a partial device removal, not a fully natural-C function. Five primary
compiler-diff warnings remain in this file for the existing propagation setting,
identity helper, dead-assignment setting, stack-parameter copies and dead address
comparisons. None of those mechanisms was added or expanded. The existing
`opt_propagation off` directive remains marked; its comment now describes the
remaining mechanisms rather than the removed inner-loop copy. No compiler flags,
new pragmas, assembly, volatile accesses, widened integers or dead stores were
introduced by this change.

The historical removed-copy comment credited the technique, not code, to
`ADX_DecodeSte4AsSte` in the RE4 decompilation (`adonis-singh/re4`,
`src/lib/adx_dcd5.c`). That is retained here as historical attribution. The new
helper is independently reconstructed from this function's existing arithmetic;
no external implementation, cached contributor candidate or repair recipe was
imported.

## Compiler and source provenance

- Source: `src/dol/fn_8004F00C.c`.
- Stock compiler: `GC/1.3.2`.
- Per-unit extra flags: `-use_lmw_stmw on`; otherwise existing DOL defaults.
- Compiler SHA-256:
  `7cbae0a5bd81e07d7fa8975bbc4e969b5dea265cc29c5ee6bae0453a6e25f225`.
- Previous source SHA-256:
  `7f5c734ccf141e500f1f1140642ff898604ccb24b775cf51d38a52417d8b933b`.
- Accepted source SHA-256:
  `20316b7a5c2c7b8a2a18b2238ac9cb13944d49c0e88c4c0d28ea27bad4777b6f`.

The complete function still matches all 152 retail instruction words. The full
oracle, not merely a masked word comparison, reports `100.000 MATCH rows=0`.

## Measured source-shape investigation

With the other existing entry devices unchanged:

1. Removing only the artificial inner-loop copy leaves three differing words:
   the two right-channel prediction products receive each other's registers.
2. Accumulating those products through a meaningful local removes that exchange
   but leaves one differing word: the final add's source operands are reversed.
3. Moving the actual multiply/add/shift prediction into the small inline helper
   removes the remaining difference. Reusing it for the left second sample also
   matches exactly, so the accepted source shares genuine decoder arithmetic
   rather than introducing an identity or one-field carrier helper.

Applying the helper to the first-sample calculations, removing the remaining
identity helper, or removing the existing propagation directive did not match.
Those experiments were not installed. The same helper did not remove the mono
mix decoder's prediction device; `fn_8004F26C` remains unchanged.

A history-variable reuse experiment must combine the multiply and prediction
before overwriting the old history. Blindly renaming a two-statement accumulator
into a history variable changes which value the second statement reads and is
not a valid reconstruction.

## Verification and reproduction

```
uv run tools/manual.py try fn_8004F00C src/dol --glob fn_8004F00C.c \
  --mw GC/1.3.2 --flags='-use_lmw_stmw on' -v
python3 configure.py --version GFZE01
uv run ninja
uv run tools/fzgx.py lint
```

Verified: full oracle `100.000 MATCH rows=0`, linked hash gate `16 files OK`, and
lint `0 finding(s)`. The build also emitted the existing uninitialized `off`
warning in the unchanged `fn_8006AF94` compilation and its existing unknown-section
linker warnings; no warning-free compiler claim is made.

`fzgx snapshot` was run. Its unrelated live-ledger drift was excluded rather than
bundled into this focused source cleanup; the function was already matched and
has no ownership/status transition from this repair.

The source/header marker inventory changes from 36 to 35 primary
`WARNING: compiler-diff device` occurrences, with two `WARNING: device` references
still present across the same 12 files. Matched coverage and strict natural-C
function coverage do not increase: this function is still device-backed until
its remaining mechanisms are removed.
