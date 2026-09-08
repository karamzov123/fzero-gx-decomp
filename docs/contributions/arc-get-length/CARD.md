# ARCGetLength

## Scope and provenance

This contribution converts `ARCGetLength` in `src/dolphin/mtx/MTXHead.c`
from inline assembly to natural C. No other functions or ABI declarations are
changed.

| Function | Retail address | Bytes | Provenance |
| --- | --- | ---: | --- |
| `ARCGetLength` | `0x8006A9AC` | 8 | GFZE01 retail disassembly; `ARCHandle` length field at `+0x08` |

The implementation is an explicit byte-offset access because this translation
unit does not currently carry a typed `ARCHandle` definition. It compiles to
`lwz r3, 8(r3); blr`, matching the retail function exactly under the pinned
MWCC GC/1.2.5n toolchain.

## Verification

- `ARCGetLength`: 100.0% fuzzy match, 8 bytes.
- Full DOL checksum gate: `build/GFZE01/main.dol: OK`.
- Public tests: 11 passed.
