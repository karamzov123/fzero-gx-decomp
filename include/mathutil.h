#ifndef MATHUTIL_H
#define MATHUTIL_H

#include "types.h"

/* Inline-asm kernels of the engine's math library (Amusement Vision's mathutil,
 * shared with Super Monkey Ball). Kept in their own header: an inline function added
 * to a widely included header shifts MWCC's anonymous literal numbering in every
 * includer (see include/ppc_ops.h).
 *
 * In the Super Monkey Ball decomp, the same engine's mathutil.c is hand-written
 * assembly and its header kernels are inline asm, so the GX kernels are written the
 * same way. Each kernel below is validated against retail. */

/* a*a + b*b + c*c in one accumulator register (fmuls; fmadds; fmadds).
 * Validated 2026-11-07 (GC/1.3.2 -O4,p): retail main_rel fn_1_D9224 squares a
 * literal 0.0f z with `fmadds f1, K, K, f1`, K a pool load. In C, MWCC always folds
 * a product of two constants, so only this asm form keeps the multiply. */
static inline f32 mathutil_sum_of_sq_3(register f32 a, register f32 b, register f32 c) {
    asm {
        fmuls a, a, a
        fmadds a, b, b, a
        fmadds a, c, c, a
    }
    return a;
}

#endif  // MATHUTIL_H
