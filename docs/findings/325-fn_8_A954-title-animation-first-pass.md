# fn_8_A954 (title): title screen animation, 76.8% first pass

Selected a carved-but-never-written unit (616 B, `title/rel/title/operation`). No prior session had
attempted it. No claims remained; no fleet settings were changed and no canonical gameplay source was
submitted. Only `.fzgx` state and the unit body were touched.

## What the function does

A title screen animation update. It:
1. Converts two u32 counters to f64, compares against rodata thresholds
2. Computes a fade value using linear interpolation
3. Calls ~15 graphics/audio subsystem functions with float parameters
4. Updates title state fields based on counter comparison

## Key idioms

- `u8 *` rodata pointer with explicit `*(f64 *)` and `*(f32 *)` casts at specific offsets — this
  produces `lfd`/`lfs` instructions matching retail better than struct field access or array indexing
- `#pragma fp_contract off` prevents `fmadds` fusion (retail uses separate `fmuls` + `fadds`/`fsubs`)
- The rodata has mixed f64 (at 0x0, 0x10, 0x28) and f32 (at 0x8, 0xC, etc.) constants

## Residual: register allocation and instruction scheduling, ~91 rows

The body reaches **76.8% raw**. The structure is correct but the instruction schedule differs:
retail loads constants early in the prologue, while the compiler defers them. The conditional branch
structure, the float operation ordering, and register assignments all differ.

Specific issues:
- `fadds f0, f1, f0` vs `fadds f0, f0, f1` — operand order reversed in the interpolation
- `lbl_8_bss_2A8` is declared as `u32` in the header but used as a struct pointer — requires a cast
- The `xoris`/`stw`/`lfd` pattern for u32-to-f64 conversion is correct but scheduled differently

The body is at `.fzgx/attempts/fn_8_A954.best.c`
(SHA-256 `06e78dafb9e6fbe3...`, full hash in `.fzgx/attempts/fn_8_A954.best.json`), 76.8% raw.

Not an exact C match. Resume `.fzgx/attempts/fn_8_A954.best.c`, compiler GC/1.3.2, no extra
command-line flags. Next steps: force early loading of the rodata constants, fix the operand order
in the interpolation expressions, and match the register allocation for the conditional branches.
