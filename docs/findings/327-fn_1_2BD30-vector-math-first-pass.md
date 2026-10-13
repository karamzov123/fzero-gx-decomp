# fn_1_2BD30 (main_rel): vector math with paired-single, 24.6% first pass

Selected a carved-but-never-written unit (604 B, `main_rel`). No prior session had attempted it. No
claims remained; no fleet settings were changed and no canonical gameplay source was submitted. Only
`.fzgx` state and the unit body were touched.

## What the function does

A vector orientation calculation. It:
1. Calls several math utility functions
2. Writes position data to hardware registers at 0xE00000C
3. Subtracts an offset vector from the input vector (using paired-single ops)
4. Normalizes the vector (length check + normalize or default)
5. Finds the dominant axis and constructs an orientation vector
6. Computes a scale factor from another vector's length

## Key structural findings

- Uses `psq_l`/`ps_sub`/`psq_st` paired-single operations for vector subtraction
- `lis r5, 0xe000` + `stfs` for hardware register writes (not an extern array)
- NaN check via `rlwinm`/`subis`/`cmplwi` pattern (bit manipulation, not `x != x`)
- Frame size 0x40 with f31 saved (indicates f64 or paired-single usage)

## Residual: paired-single codegen and register allocation, ~178 rows

The body reaches **24.6% raw**. The structure is partially correct but the paired-single operations
are not being generated from scalar C float operations. Key gaps:

- `psq_l f3, 0xc(r29)` + `ps_sub f3, f3, f2` + `psq_st f3, 0xc(r29)` — vector subtract as pair
- `lis r5, 0xe000` + `stfs f2, 0xc(r5)` — hardware register write pattern
- NaN check via bit manipulation (`rlwinm r3, r0, 0, 1, 8; subis r0, r3, 0x7f80; cmplwi`)
- Frame size mismatch (0x40 vs 0x20) — missing f31 save indicates paired-single or f64 usage

The body is at `.fzgx/attempts/fn_1_2BD30.best.c`
(SHA-256 `4f23d8ca86cbeaf0...`, full hash in `.fzgx/attempts/fn_1_2BD30.best.json`), 24.6% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_1_2BD30.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: use `psvec.h` helpers for the vector subtraction (ps_sub), use
`lis 0xe000` pattern for hardware writes, implement the NaN check as bit manipulation, and add the
missing f64/paired-single variable that forces f31 to be saved.
