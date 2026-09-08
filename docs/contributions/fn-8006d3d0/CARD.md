# fn_8006D3D0

## Scope and provenance

This contribution converts the 156-byte `fn_8006D3D0` math helper in
`src/dolphin/mtx/MTXFused.c` from inline PowerPC assembly to natural C. The
implementation preserves the retail threshold, square-root normalization,
atanf path, and signed quarter-turn fallback.

The body is a clean-room reconstruction from the retail GFZE01 instruction
sequence and neighboring `sqrtf`/`atanf` helpers. No retail binary or
proprietary input is committed.

## Verification

- Retail symbol: `0x8006D3D0`, size `0x9C` (156 bytes).
- Exact match: 156/156 bytes; `build/GFZE01/main.dol` matches the retail DOL
  at the target range.
- Full GFZE01 DOL SHA-1: `421c88106697d3275a3fc26fb7a01bf6d816b271`.
- Repository tests: `python3 -m unittest discover -s tests` — 14 passed.
- Source build: `ninja all_source` — passed.
- Report generation: `ninja build/GFZE01/report.json` — passed; report entry
  inspected for `fn_8006D3D0`.
