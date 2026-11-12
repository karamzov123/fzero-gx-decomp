# ADX SPSD header: natural C without address-escape devices

## Accepted source and configuration

- Function: `fn_800463E4`, `src/dol/fn_800463E4.c`.
- Stock compiler: `GC/1.3.2`.
- Compiler SHA-256: `7cbae0a5bd81e07d7fa8975bbc4e969b5dea265cc29c5ee6bae0453a6e25f225`.
- Per-unit flags: `-proc 7450`, recorded in `config/GFZE01/units.json`.
- Source SHA-256: `5dfbba99e771fed2c059c3308a0184cd605e649c63fb613f83ea38e9a6e76d41`.
- Result: all 73 instruction words match retail; full oracle reports
  `100.000 MATCH rows=0` using the recorded unit configuration.

The natural implementation writes through the three output parameters directly.
It has no address comparisons, `escaped` local, ordering-only parameter copies,
optimizer pragmas, volatile casts, inline assembly or identity helpers.

## Scheduling evidence

With the otherwise identical Gekko processor configuration, the natural body has
four positional word differences (three aligned differing rows): the stack-passed
output pointers are loaded in a different entry-block order. The documented
`-proc` option controls the compiler's scheduling model as well as the assembler
processor selection. Selecting 7450 reproduces the complete retail body without
adding an instruction or changing C semantics. No Altivec instructions are emitted.

This is a measured compatible stock-compiler configuration, not proof that CRI
originally selected a 7450 target. The original library compiler build remains
unidentified. Keep the per-unit setting with the source: restoring the default
Gekko scheduling model does not reproduce the match.

## Reproduction and linked verification

```
uv run tools/manual.py try fn_800463E4 src/dol --glob fn_800463E4.c -v
python3 configure.py --version GFZE01
uv run ninja
uv run tools/fzgx.py lint
```

Verified: `100.000 MATCH rows=0`, `16 files OK`, and `0 finding(s)`.
The full linked hash gate covers the DOL and all fifteen REL modules. No target
bytes, hash inputs or comparison criteria were changed.

`fzgx snapshot` was also run. Its unrelated live-ledger drift was excluded from
this change; this already-matched function needs no ownership/status transition.
