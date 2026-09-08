# SISetXY

## Scope and provenance

This contribution converts `SISetXY` in `src/dolphin/os/SIBios.c` from inline
assembly to natural C. It preserves the existing SI register mappings and
interrupt-protection sequence; no neighboring SI functions are changed.

| Function | Retail address | Bytes | Provenance |
| --- | --- | ---: | --- |
| `SISetXY` | `0x80012570` | 108 | `dolsdk2001:src/os/OSSerial.c:181`; exact historical candidate `362c1f37` |

The implementation constructs the poll value from the X/Y fields, masks and
updates `Si[1]`, writes the resulting poll value to `__SIRegs[12]` while
interrupts are disabled, and returns it. Under the pinned MWCC GC/1.2.5n
toolchain it matches the retail function exactly.

## Verification

- `SISetXY`: 100.0% fuzzy match, 108 bytes.
- Complete SIBios unit: 100.0% fuzzy match; all 38 functions exact.
- Full DOL checksum gate: `build/GFZE01/main.dol: OK`.
- Progress generation completed successfully.
- Public tests: 11 passed.
