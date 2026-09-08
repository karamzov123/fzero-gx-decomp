# TRKUARTInterruptHandler

## Scope and provenance

This contribution converts the empty four-byte `TRKUARTInterruptHandler` stub
in `src/dolphin/metrotrk/main.c` from an asm-defined leaf to an ordinary C
function. No neighboring MetroTRK handlers are changed.

## Verification

- Retail symbol: `0x8008D2AC`, size `0x4`.
- The complete MetroTRK main unit remains 100.0% exact.
- Full GFZE01 DOL checksum and progress gates pass.
- `python3 -m unittest discover -s tests` passes all 11 tests.