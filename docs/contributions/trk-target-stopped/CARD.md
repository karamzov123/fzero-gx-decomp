# TRKTargetStopped

## Scope and provenance

This contribution converts the 16-byte `TRKTargetStopped` getter in
`src/dolphin/metrotrk/trk_80088B00.c` from inline assembly to natural C. It
returns the documented `gTRKState` stopped field at byte offset `0x98`,
matching the existing MetroTRK ABI and state layout.

## Verification

- Retail symbol: `0x8008B4AC`, size `0x10`.
- Target function: 100.0% exact.
- Complete owner unit: 100.0% exact, 78/78 functions.
- Full DOL SHA-1 gate and progress generation pass.
- Repository tests pass.
