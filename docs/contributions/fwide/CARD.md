# fwide: matching C in the existing MSL unit

## Change and provenance

- Base: `3eed2db4c4d2679842a67fd964c7e90049b34950`.
- `fwide`, `src/dolphin/msl/msl_80083E84.c`, GFZE01 `0x800858E4`, 136 bytes:
  adapted from the previously consulted
  [marioparty4:src/MSL_C.PPCEABI.bare.H/wchar_io.c:3](https://github.com/mariopartyrd/marioparty4/blob/147b165a83187ac9e6cfdc3bf52f2e73437b1ffd/src/MSL_C.PPCEABI.bare.H/wchar_io.c#L3),
  pin `147b165a83187ac9e6cfdc3bf52f2e73437b1ffd`, reconciled with GX's types
  and target instructions. The preferred `dolsdk2001` checkout at
  `eb1234c45e6df75757c652c835507ca89674f9a8` had no `wchar_io.c` source.
- Move the complete existing tagged `FileMode`, `FileBuffer`, and `File` types
  to `include/dolphin/msl/file.h`, preserving members, bit widths, and layout.
  Retain `unk20`, documenting it as orientation; share `int fwide(File*, int)`.
- `vprintf`, `src/dolphin/msl/printf.c`: provenance `original` (typed stream
  argument only). Add the `File*` cast; formatting and stream storage are unchanged.

## Semantics

Null/closed streams return zero. Unoriented streams set orientation from the
mode's sign and return the original mode. Oriented streams return `1` or `-1`
without mutation. The valid-state contract is orientations `0/1/2`. No fallback
is added for reserved encoding `3`: the target retains incoming pointer bits
in `r3`, but consuming a fall-through C result is undefined behavior. A binary
match is not proof of portable C semantics or unreachability for invalid state.

## Verification

- Unchanged GC/1.3 flags and unit registration. All three complete fresh objects
  (`msl_80083E84`, `stdio_8007A060`, `printf`) are byte-identical to baseline,
  including section layout, symbols, neighboring functions, and relocations.
  `fwide` also matches split retail bytes/layout directly, with no relocations.
  A compiler probe confirms `sizeof(File) == 0x50` and existing field offsets.
- The affected baseline sources are identical at supplementary pin
  `12770d18ff53941a14204d926f22fa3fb2c40315`; its baseline/candidate links both
  hash to `421c88106697d3275a3fc26fb7a01bf6d816b271`. A private `-1` to `2`
  return mutation changes the DOL hash; `finally` restoration recovers the exact
  candidate object and retail hash. All three objects also match at this pin.
- Current-base full links remain blocked by missing `dolphin/card_private.h`;
  report tests remain blocked by missing `tools/natc_asmforms.py`. Neither is
  repaired here. Binary snapshots, mutation code, and detailed logs stay private.
