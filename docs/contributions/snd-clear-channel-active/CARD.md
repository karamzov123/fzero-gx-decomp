# SndClearChannelActiveFlag

## Scope and provenance

This contribution converts the 12-byte global-zero setter
`SndClearChannelActiveFlag` in `src/game/gamehead_8005C120.c` from inline
assembly to natural C. It clears the existing 32-bit `lbl_801A6C7C` state word.

## Verification

- Retail symbol: `0x80065AC4`, size `0x0C`.
- Complete owner unit: 63/63 functions exact, 55,744/55,744 code bytes matched.
- Full DOL SHA-1 gate and progress generation pass.
- Repository tests pass.
