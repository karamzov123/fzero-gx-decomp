# ARCGetStartAddr

## Scope and provenance

This contribution converts `ARCGetStartAddr` in
`src/dolphin/mtx/MTXHead.c` from inline assembly to natural C. It is
independent of `ARCGetLength` in PR #21 and changes no other ARC functions.

| Function | Retail address | Bytes | Provenance |
| --- | --- | ---: | --- |
| `ARCGetStartAddr` | `0x8006A998` | 20 | GFZE01 retail disassembly; ARCHandle fields at `+0x00` and `+0x04` |

The explicit byte-offset implementation loads the archive base pointer, reads
the archive start word, adds the handle offset, and returns the resulting
address. Under the pinned MWCC GC/1.2.5n toolchain it emits the retail
`lwz/lwz/lwz/add/blr` sequence exactly.

## Verification

- `ARCGetStartAddr`: 100.0% fuzzy match, 20 bytes.
- Full DOL checksum gate: `build/GFZE01/main.dol: OK`.
- Public tests: 11 passed.
