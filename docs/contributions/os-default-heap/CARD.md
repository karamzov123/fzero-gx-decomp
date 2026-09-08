# OSGetDefaultHeap

## Scope and provenance

This contribution converts `OSGetDefaultHeap` in
`src/dolphin/mtx/fn_80071C04.c` from inline assembly to natural C. It returns
the address of the existing `lbl_8019E210` default-heap object and changes no
neighboring allocator wrappers.

## Verification

- Retail symbol: `0x80071CB4`, size `0x0C`.
- Owner unit: 100.0% exact.
- Full GFZE01 DOL SHA-1 gate: passed.
- `python3 -m unittest discover -s tests`: 11 tests passed.
