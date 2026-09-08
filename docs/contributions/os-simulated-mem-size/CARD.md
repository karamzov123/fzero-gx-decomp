# OSGetConsoleSimulatedMemSize

## Scope and provenance

This contribution removes the remaining inline-assembly body from
`OSGetConsoleSimulatedMemSize` in `src/dolphin/os/OSMemory.c`. It is a distinct
12-byte getter from `OSGetPhysicalMemSize` in PR #27 and does not change that
PR's hunk.

## Verification

- Retail symbol: `0x8000E7A0`, size `0x0C`.
- `OSMemory` unit: 100.0% exact.
- Full GFZE01 DOL SHA-1 gate: passed.
- `python3 -m unittest discover -s tests`: 11 tests passed.
