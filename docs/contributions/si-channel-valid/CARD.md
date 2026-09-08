# SIChannelValid

## Scope and provenance

This contribution converts `SIChannelValid` in `src/dolphin/os/SIBios.c` from
inline assembly to natural C. It is independent of PR #25, which changes only
`SISetXY` in the same translation unit.

The body follows the public Dolphin SDK SI semantics: channel 0 is valid when
`Si[0]` is not `-1`, and the function returns the corresponding boolean value.

## Verification

- Retail symbol: `0x8001191C`, size `0x20`.
- `SIChannelValid`: 100.0% fuzzy match, 32 bytes.
- Complete SIBios unit: 100.0% exact.
