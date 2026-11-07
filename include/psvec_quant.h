#ifndef PSVEC_QUANT_H
#define PSVEC_QUANT_H

#include "types.h"

/* Quantized paired-single kernels (non-zero GQR). Not in psvec.h for the same reason as
 * psvec_fill.h: a new inline function there renumbers @N literals in every includer.
 *
 * These are C loops around asm statements, not hand-written functions. Update-form kernels are
 * macros, because an inline function's register parameters are copies and `psq_lu` must advance
 * the caller's pointer. The optimizer still treats the block as loop body: it hoists the constant
 * loads, adds the loop guard and unrolls (`srwi. r0, n, 2; mtctr r0; beq`, then a remainder
 * loop), so `blelr`/`beqlr` and the 4x/8x copies in retail are compiler output. A kernel's
 * physical registers are fixed; its `register` locals are colored by the allocator.
 *
 * Validated byte-exact 2026-11-07: fn_12_12324 (psq3_row), fn_8003B9AC (psq2_merge4),
 * fn_8003BB30 (psq27_merge2). */

/* Four qr3 pairs from src+0,4,8,12 to dst+0,2,4,6. Declaring the locals d, c, b, a gives retail's
 * ascending f0..f3. Constant offsets on src fold into the displacement. */
static inline void psq3_row(const register void *src, register void *dst) {
    register f32 d, c, b, a;
    asm {
        psq_l a, 0(src), 0, 3
        psq_l b, 4(src), 0, 3
        psq_l c, 8(src), 0, 3
        psq_l d, 12(src), 0, 3
        psq_st a, 0(dst), 0, 3
        psq_st b, 2(dst), 0, 3
        psq_st c, 4(dst), 0, 3
        psq_st d, 6(dst), 0, 3
    }
}

/* Two pairs from a and one each from b and c, scaled (ps_madd x, x, k, k0), merged, then four
 * pairs stored; every access pre-increments by 2 and uses qr2. Use with `i += 4`. */
#define psq2_merge4(d, a, b, c, k0, k1, k2, k3) \
    asm { \
        psq_lu f4, 2(a), 0, 2; \
        psq_lu f6, 2(b), 0, 2; \
        ps_madd f4, f4, k1, k0; \
        ps_madd f6, f6, k2, k0; \
        psq_lu f5, 2(a), 0, 2; \
        psq_lu f7, 2(c), 0, 2; \
        ps_madd f5, f5, k1, k0; \
        ps_madd f7, f7, k3, k0; \
        ps_merge00 f8, f4, f6; \
        ps_merge10 f4, f4, f7; \
        psq_stu f8, 2(d), 0, 2; \
        psq_stu f4, 2(d), 0, 2; \
        ps_merge01 f4, f5, f6; \
        ps_merge11 f5, f5, f7; \
        psq_stu f4, 2(d), 0, 2; \
        psq_stu f5, 2(d), 0, 2; \
    }

/* The scale pairs psq27_merge2 reads from f4 and f5, set up before the loop. */
#define psq27_merge2_setup(k1, k2, k3) \
    asm { \
        ps_merge00 f4, k1, k2; \
        ps_merge00 f5, k1, k3; \
    }

/* One pair from a (qr2) and one each from b and c (qr7), summed, scaled by f4/f5, two pairs
 * stored; every access pre-increments by 2. Use with `i += 2`. Declare the temporaries
 * t1, t2, t3 after the constants: they reuse the constants' registers once those are dead. */
#define psq27_merge2(d, a, b, c, k0, t1, t2, t3) \
    asm { \
        psq_lu t1, 2(a), 0, 2; \
        psq_lu t3, 2(c), 0, 7; \
        psq_lu t2, 2(b), 0, 7; \
        ps_sum0 t3, t3, t1, t3; \
        ps_sum1 t1, t2, t1, t2; \
        ps_merge10 t3, t3, t3; \
        ps_madd t1, t1, f4, k0; \
        ps_madd t3, t3, f5, k0; \
        psq_stu t1, 2(d), 0, 2; \
        psq_stu t3, 2(d), 0, 2; \
    }

#endif  // PSVEC_QUANT_H
