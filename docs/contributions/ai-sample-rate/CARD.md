# AIGetDSPSampleRate

## Scope and provenance

This contribution converts `AIGetDSPSampleRate` in
`src/dolphin/ai/AISampleRate.c` from inline assembly to natural C. No sibling
AI functions or register declarations are changed.

| Function | Retail address | Bytes | Provenance |
| --- | --- | ---: | --- |
| `AIGetDSPSampleRate` | `0x8001E1C4` | 20 | `dolsdk2001:src/ai/ai.c:193` and GFZE01 retail disassembly |

The implementation reads the volatile AI control register at `0xCC006C00`,
extracts bit 6, and inverts it. Under the pinned MWCC GC/1.2.5n toolchain it
emits the retail `lis/lwz/extrwi/xori/blr` sequence exactly.

## Verification

- `AIGetDSPSampleRate`: 100.0% fuzzy match, 20 bytes.
- Complete AISampleRate unit: 100.0% fuzzy match; all 5 functions exact.
- Full DOL checksum gate: `build/GFZE01/main.dol: OK`.
- Progress generation completed successfully.
- Public tests: 11 passed.
