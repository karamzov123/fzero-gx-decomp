# fn_80006AF4

## Scope and provenance

This contribution converts the 8-byte unsigned-byte getter `fn_80006AF4` in
`src/main.c` from inline assembly to natural C. It reads the existing
`lbl_801A66D8` byte without changing neighboring main-unit functions.

## Verification

- Retail symbol: `0x80006AF4`, size `0x08`.
- Target function: 100.0% exact.
- Full DOL SHA-1 gate and progress generation pass.
- Repository tests pass.
