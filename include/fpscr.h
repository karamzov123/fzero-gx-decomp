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
 * it with the surrounding code (fn_1_1030D4).
 *
 * The stack word pair is an s32 array, not a double: retail homes it at 4-byte
 * alignment (fn_1_106EB0 stores to 0xc(r1)). Each inline site gets its own home. */
static inline s32 fpscr_floor(register f32 x) {
    register f64 t;
    register f64 fpscr;
    s32 w[2];
    asm {
        mffs fpscr
        mtfsb1 30
        mtfsb1 31
        fctiw t, x
        stfd t, w
        mtfsf 255, fpscr
    }
    return w[1];
}

#endif
