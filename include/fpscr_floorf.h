#ifndef FPSCR_FLOORF_H
#define FPSCR_FLOORF_H

#include "types.h"

/* fpscr_floor returning f32, converting in place (`fctiw x, x`): retail's stcoli
 * grid lookup (fn_1_20A5C) converts in the input register and turns the result back
 * into a float before the caller's integer conversion. Kept out of fpscr.h because
 * every inline a header defines shifts MWCC's anonymous literal numbering (@N) in
 * the units that include it, which breaks their recorded pool mappings. */
static inline f32 fpscr_floorf(register f32 x) {
    register f64 fpscr;
    s32 w[2];
    asm {
        mffs fpscr
        mtfsb1 30
        mtfsb1 31
        fctiw x, x
        stfd x, w
        mtfsf 255, fpscr
    }
    return w[1];
}

#endif
