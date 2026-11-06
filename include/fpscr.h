#ifndef FPSCR_H
#define FPSCR_H

#include "types.h"

/* Floor to integer through a temporary FPSCR rounding mode (recovered 2026-11-06).
 *
 * Retail's wrap-around code (main_rel cloth/stcoli/screen_effect/burner) saves the
 * FPSCR, sets RN to round toward minus infinity (mtfsb1 30; mtfsb1 31), converts
 * with fctiw, stores the result to a stack word and restores the FPSCR. MWCC only
 * has an intrinsic for mffs, so the sequence can come only from inline assembly
 * inlined into the caller; the compiler then allocates the registers and schedules
 * it with the surrounding code (fn_1_1030D4). */
static inline s32 fpscr_floor(register f32 x) {
    register f64 t;
    register f64 fpscr;
    union {
        f64 d;
        s32 w[2];
    } u;
    asm {
        mffs fpscr
        mtfsb1 30
        mtfsb1 31
        fctiw t, x
        stfd t, u.d
        mtfsf 255, fpscr
    }
    return u.w[1];
}

#endif
