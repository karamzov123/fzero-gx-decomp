# fn_1_CAB38 (font/UI): font rendering with float math, 18.0% first pass

Selected a carved-but-never-written unit (652 B, `main_rel`). No prior session had attempted it. No
claims remained; no fleet settings were changed and no canonical gameplay source was submitted. Only
`.fzgx` state and the unit body were touched.

## What the function does

A font rendering function that:
1. Gets a car ID from `fn_1_86A10`
2. Checks table flags via `fn_1_5910` and `lbl_1_data_3D544`
3. Conditionally computes a float value using clamping (`fn_1_15E1D0`)
4. Copies a 0x58-byte FontDrawPacket template from rodata
5. Does u32-to-f64 conversion for position calculation
6. Renders multiple font packets in two loops (tens digit and ones digit)

## Key structural findings

- Division by 10 via `mulhw` with magic constant 0x66666667
- u32-to-f64 conversion via `xoris 0x8000` + `lfd` + `fsub` pattern
- `mtctr 0xB` copy loop for the FontDrawPacket template (same unrolling issue as fn_1_F965C)
- Two rendering loops with different stride values (0x12 and 0x11)

## Residual: codegen volume and structure, ~209 rows

The body reaches **18.0% raw** (19.6% adjusted). The 260 generated rows vs retail's 163 indicates
the compiler is generating significantly more code than retail. Key issues:

- The FontDrawPacket copy loop generates different code (unrolled vs mtctr pattern)
- Float conversion expressions produce different instruction sequences
- The conditional branch structure for the table flag checks differs
- `fp_contract off` may not be preventing all fusion

The body is at `.fzgx/attempts/fn_1_CAB38.best.c`
(SHA-256 `f84976f42a4a1838...`, full hash in `.fzgx/attempts/fn_1_CAB38.best.json`), 18.0% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_1_CAB38.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: find the C pattern that produces `mtctr 0xB` for the template copy,
match the u32-to-f64 conversion idiom, and simplify the conditional structure.
