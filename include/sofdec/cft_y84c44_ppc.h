#ifndef SOFDEC_CFT_Y84C44_PPC_H
#define SOFDEC_CFT_Y84C44_PPC_H

/* CRI CFT/GC, Ycc420 planar -> Y8/C44 tile converter (movie_module fn_12_3C17C): cache control and the
 * luma tile store, written as inline assembly on the caller's register variables like the Sofdec kernels
 * in mpvidct_ppc.h and mpvmc_ppc.h. All operands must be `register` variables. A macro is one logical
 * line, hence the ';' after each instruction.
 *
 * None of these can be written in C:
 * - Retail stores one luma tile with four separate `stfdu f, 8(out)`. From C (`*++out = a;` four times)
 *   MWCC always folds the pointer updates into `stfd 8/16/24` plus one `stfdu 32` (both the IR optimiser
 *   and the peephole pass do it).
 * - The cache instructions are the first statement of each inner loop. As inline assembly they stop the
 *   IR optimiser for the whole function (no common subexpressions, no propagation, no lifetime
 *   splitting; the back end still unrolls the luma loop and strength-reduces the row offsets), and an
 *   assembly statement does not start a new statement weight, so the inner loop body keeps the weight
 *   of the row loop. Retail's code and its register colouring need both; the `__dcbz`/`__dcbt`
 *   intrinsics give neither. */

/* Zero the cache line at base + offset before it is written. */
#define CFT_CACHE_ZERO(base, offset) asm { dcbz base, offset; }

/* Prefetch the cache line at base + offset. */
#define CFT_CACHE_TOUCH(base, offset) asm { dcbt base, offset; }

/* Store four doubles (one 8-byte row of each of the four tile rows) behind `out`, which points one
 * element before the destination and is advanced by four elements. */
#define CFT_STORE_Y8_TILE(out, row0, row1, row2, row3) \
    asm { \
        stfdu row0, 8(out); \
        stfdu row1, 8(out); \
        stfdu row2, 8(out); \
        stfdu row3, 8(out); \
    }

#endif
