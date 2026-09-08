# fn_8006FFBC

## Scope and provenance

This contribution converts the 8-byte SDA21 getter `fn_8006FFBC` in
`src/dolphin/mtx/fn_8006FEFC.c` from inline assembly to natural C. It returns
the existing 4-byte global `lbl_801A6CD4` without changing neighboring heap
helpers.

## Verification

- Retail symbol: `0x8006FFBC`, size `0x08`.
- Complete owner unit: 6/6 functions exact, 288/288 code bytes matched.
- Full DOL SHA-1 gate and progress generation pass.
- Repository tests pass.
