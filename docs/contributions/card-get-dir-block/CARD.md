# __CARDGetDirBlock

## Scope and provenance

This contribution converts `__CARDGetDirBlock` in
`src/dolphin/card/CARDBlock.c` from inline assembly to natural C. It is
outside contributor PR #26, whose CARD changes do not include `CARDBlock.c`.

| Function | Retail address | Bytes | Provenance |
| --- | --- | ---: | --- |
| `__CARDGetDirBlock` | `0x8002C4BC` | 8 | `dolsdk2001:src/card/CARDOpen.c` |

The implementation returns the directory-block pointer at the verified
`CARDControl` offset `0x84` using the coarse unit's existing ABI-safe pointer
form.

## Verification

- `__CARDGetDirBlock`: 100.0% fuzzy match, 8 bytes.
- Complete CARDBlock unit: 100.0% fuzzy match; all 19 functions exact.
- Full DOL checksum gate: `build/GFZE01/main.dol: OK`.
- Progress generation completed successfully.
- Public tests: 11 passed.
