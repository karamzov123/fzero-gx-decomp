# OSGetTick

## Scope and provenance

This contribution converts `OSGetTick` in `src/dolphin/os/OSTime.c` from an
asm-defined function into a natural-C wrapper. The required `mftb` instruction
remains inline assembly because the PowerPC time-base register has no C
expression; the surrounding ABI, return value, and function boundaries are
natural C.

| Function | Retail address | Bytes | Provenance |
| --- | --- | ---: | --- |
| `OSGetTick` | `0x80011424` | 8 | `dolsdk2001:src/os/OSTime.c`; historical exact candidate `1c2d38e7` |

## Verification

- `OSGetTick`: 100.0% fuzzy match, 8 bytes.
- Complete OSTime unit: 100.0% fuzzy match; all 3 functions exact.
- Full DOL checksum gate: `build/GFZE01/main.dol: OK`.
- Progress generation completed successfully.
- Public tests: 11 passed.
