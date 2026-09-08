# __msl_strrchr natural-C conversion

Target: GFZE01 `__msl_strrchr` at 0x80083B14, 72 bytes, in
`src/dolphin/msl/tail_8008279C.c`.

Base: GitHub main 08cdf620cb9e6e1ab87b5dbaa6579495cbadd8ca, including
contributor PRs #6, #8, #9 and #10 and the EXI/CI repairs.

## Reconstruction

Original reconstruction from the existing retail assembly, not a copied SDK
reference. The loop preincrements a byte pointer and remembers the last matching
nonzero byte. If no such byte was found, a zero search byte returns the string's
terminator; any other absent byte returns null. The int argument is truncated
to unsigned char before comparison.

A direct reread of `*p` introduced an extra load (92.5% symbol match). Caching
in an unsigned-char local instead introduced an extra clrlwi (92.5%). Caching
the byte and the converted search value in unsigned-long locals removes that
mask and reproduces the retail register allocation under the existing GC/1.3
unit configuration. No compiler flags or pins changed.

The one-before pointer setup mirrors the retail/MSL idiom and the surrounding
recovered string routines. The host harness supplies an interior pointer, so
that setup stays within the test buffer's allocation.

## Verification

- `python3 -m unittest discover -s tests -v`: behavioral and existing tests.
- `ninja -j4 all_source build/GFZE01/main.dol`: full source and DOL build.
- `build/tools/objdiff-cli report generate -o build/GFZE01/report.strrchr.json`:
  function 100%, entire 5,540-byte unit 100%; all 13 function entries match.
  Other functions still include assembly: this is NOT a whole-unit natural-C claim.
- DOL SHA-1: `421c88106697d3275a3fc26fb7a01bf6d816b271`.
- Disassembled replacement has the same 18 instructions as the retail assembly
  baseline; original baseline DOL also passed the retail hash.
- Host behavioral test compares exact result pointers with libc strrchr across
  lengths 0 through 64, 32 deterministic byte-string samples per length, and
  search arguments -256 through 511. Includes empty strings, null terminators,
  high-bit bytes, absent values, truncation and repeated-byte last-occurrence
  behavior. Host behavior alone is not the target-code acceptance gate.

Verified conversion gain: one assembly function replaced by natural C, 72 bytes.
