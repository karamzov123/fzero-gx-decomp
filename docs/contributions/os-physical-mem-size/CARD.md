# OSGetPhysicalMemSize

## Scope and provenance

This contribution converts `OSGetPhysicalMemSize` in
`src/dolphin/os/OSMemory.c` from inline assembly to natural C. The sibling
`OSGetConsoleSimulatedMemSize` accessor and the rest of OSMemory remain
unchanged.

| Function | Retail address | Bytes | Provenance |
| --- | --- | ---: | --- |
| `OSGetPhysicalMemSize` | `0x8000E794` | 12 | `dolsdk2001:src/os/OSMemory.c` |

The implementation performs the documented volatile read from the cached
physical-memory-size location at `0x80000028`. Under the pinned MWCC GC/1.2.5n
toolchain it emits the exact retail two-instruction body.

## Verification

- `OSGetPhysicalMemSize`: 100.0% fuzzy match, 12 bytes.
- Complete OSMemory unit: 100.0% fuzzy match; all 9 functions exact.
- Full DOL checksum gate: `build/GFZE01/main.dol: OK`.
- Progress generation completed successfully.
- Public tests: 11 passed.
