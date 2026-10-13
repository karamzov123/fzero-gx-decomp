# fn_1_BD54 (camera): camera update with psvec, 40.6% first pass

Selected a carved-but-never-written unit (588 B, `main_rel/rel/main_rel/camera`). One prior attempt
existed but scored below the reporting threshold. No claims remained; no fleet settings were changed
and no canonical gameplay source was submitted. Only `.fzgx` state and the unit body were touched.

## What the function does

A camera state update function. It:
1. Converts a s8 field to f64, scales it, and adds to a camera angle
2. Updates a u16 counter based on another s8 field
3. Calls `fn_1_10780C` to get three vectors, then `fn_80008C20` to process them
4. Conditionally calls `lbl_8006E0B4` based on button flags
5. Rotates a matrix by the u16 counter
6. Does paired-single vector interpolation (psvec_set + 6-component lerp)
7. Calls several camera subsystem functions

## Key idioms

- `#pragma fp_contract off` prevents `fmadd` fusion (retail uses separate `fmul` + `fadd`)
- `psvec_set` from `psvec.h` for the paired-single vector initialization
- `andis.` for the 0x140 mask check (retail uses andi-with-shift, not plain andi)

## Residual: instruction scheduling and register allocation, ~159 rows

The body reaches **40.6% raw**. The structure is correct but the instruction schedule differs:
retail loads float constants (`lfd f1, 0x80(r31)`, `lfd f2, 0x88(r31)`) early in the prologue,
while the compiler defers them. The `fn_1_10780C` call setup, the conditional branch structure,
and the vector math all produce different register assignments and instruction ordering.

The body is at `.fzgx/attempts/fn_1_BD54.best.c`
(SHA-256 `6bc517cd0d86083b...`, full hash in `.fzgx/attempts/fn_1_BD54.best.json`), 40.6% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_1_BD54.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: force early loading of the float constants (declare them as
variables used before the extsb), match the `andis.` instruction for the 0x140 mask, and
restructure the vector math to match retail's evaluation order.
