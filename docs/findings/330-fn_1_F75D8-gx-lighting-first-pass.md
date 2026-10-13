# fn_1_F75D8 (lighting): GX light setup, 64.7% first pass

Selected a carved-but-never-written unit (664 B, `main_rel`). No prior session had attempted it. No
claims remained; no fleet settings were changed and no canonical gameplay source was submitted. Only
`.fzgx` state and the unit body were touched.

## What the function does

A GX lighting setup function. It:
1. Calls `lbl_8006DAEC` to initialize
2. Optionally gets an index from `fn_1_5910`
3. Calls `lbl_8006D758` or `lbl_8006DCA4` based on a flag
4. Loops over 0x20 light entries, setting up each light's position, direction, and attenuation
5. Uses paired-single operations for vector scaling
6. Calls `fn_80074CF4` with normalized color values at the end

## Key structural findings

- `_savegpr_21`/`_restgpr_21` for register save/restore
- Frame size 0xd0 with f31 saved (paired-single or f64 usage)
- u8-to-f64 conversion via `lbz` + `stw` + `lfd` + `fsub` pattern
- Paired-single `ps_muls0` for vector scaling in the i==0 case

## Residual: frame layout and register allocation, ~142 rows

The body reaches **64.7% raw**. The structure is largely correct but the frame layout differs
(0xd0 vs 0xa0) and register assignments don't match. The stack buffer usage pattern is different —
retail uses `r1+0x14` through `r1+0x2C` for the light data, while our `stackbuf` is placed differently.

The body is at `.fzgx/attempts/fn_1_F75D8.best.c`
(SHA-256 `21d69ab0bb17089f...`, full hash in `.fzgx/attempts/fn_1_F75D8.best.json`), 64.7% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_1_F75D8.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: match the stack frame layout (use individual variables instead of
a stack buffer array), and align the paired-single operations with `psvec.h` helpers.
