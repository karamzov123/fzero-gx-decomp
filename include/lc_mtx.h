#ifndef LC_MTX_H
#define LC_MTX_H

#include "types.h"
#include "dolphin/hw_regs.h"

/* Sets the translation column of a 3x4 matrix (callers pass the locked-cache matrix). */
static inline void mtx_set_translate(f32 (*mtx)[4], f32 x, f32 y, f32 z) {
    if (mtx != NULL) {
        mtx[0][3] = x;
        mtx[1][3] = y;
        mtx[2][3] = z;
    }
}

#endif
