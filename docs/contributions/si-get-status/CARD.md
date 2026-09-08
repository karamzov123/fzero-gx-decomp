# SIGetStatus

## Scope and provenance

This contribution converts `SIGetStatus` in `src/dolphin/os/SIBios.c` from
inline assembly to natural C. It preserves the absolute COMCSR register read,
channel shift, Type update, and interrupt critical section.

The function is independent of PR #25 (`SISetXY`) and PR #31 (`SIChannelValid`);
no contributor PR touches this SIBios hunk.

## Verification

- Retail symbol: `0x800124D0`, size `0x7C`.
- SIGetStatus: 100.0% exact, 124 bytes.
- Complete SIBios unit: 100.0% exact.
- Full GFZE01 DOL checksum and progress gates pass.
- `python3 -m unittest discover -s tests` passes all 11 tests.