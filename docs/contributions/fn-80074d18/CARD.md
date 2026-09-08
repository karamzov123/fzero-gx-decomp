# fn_80074D18

## Scope and provenance

This contribution converts the 16-byte branchless zero-test setter
`fn_80074D18` in `src/game/gxstate_80074A60.c` from inline assembly to natural
C. The body stores the logical-not result of its `s32` argument into the
existing four-byte `lbl_801A6D64` state flag.

## Verification

- Retail symbol: `0x80074D18`, size `0x10`.
- Target function: 100.0% exact.
- Complete owner unit: 100.0% exact, 13/13 functions.
- Full GFZE01 DOL SHA-1 gate: passed.
- Progress generation: passed.
- Repository tests: 11 passed.
