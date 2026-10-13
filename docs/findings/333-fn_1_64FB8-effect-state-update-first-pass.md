# fn_1_64FB8 (effect): effect state update, 50.2% first pass

Selected a carved-but-never-written unit (688 B, `main_rel`). No prior session had attempted it. No
claims remained; no fleet settings were changed and no canonical gameplay source was submitted. Only
`.fzgx` state and the unit body were touched.

## What the function does

An effect state update function. It:
1. Converts two s16 angle fields to float, scales them, and stores back as s16
2. Gets a camera entry and processes position vectors
3. Conditionally overrides position based on camera state
4. Accumulates rotation angles and applies matrix rotations
5. Does linear interpolation on a scale factor
6. Updates a PRNG and computes randomized color values

## Key structural findings

- s16-to-float conversion via `xoris 0x8000` + `lfd` + `fsubs` + `fmuls` + `fctiwz`
- PRNG: `state = state * 1103515245 + 12345; state = (state >> 1) & 0x7FFF`
- Frame size 0xb0 with f31 saved (indicates f64 or paired-single usage)
- Hardware register writes at 0xE00000C via `lis r3, 0xe000`

## Residual: frame layout and instruction selection, ~161 rows

The body reaches **50.2% raw**. The structure is largely correct but the frame layout differs
(0xb0 vs 0x50) and instruction selection differs in several places. The s16-to-float conversion
pattern and the float operation ordering don't match exactly.

The body is at `.fzgx/attempts/fn_1_64FB8.best.c`
(SHA-256 `61c02760a47da83a...`, full hash in `.fzgx/attempts/fn_1_64FB8.best.json`), 50.2% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_1_64FB8.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: match the frame size by using the correct number of local variables,
fix the s16-to-float conversion idiom, and align the float operation ordering.
