#ifndef MATHUTIL_MTXA_SET_TRANSLATE_H
#define MATHUTIL_MTXA_SET_TRANSLATE_H

#include "types.h"
#include "game/vec3.h"

/* Inline-asm set-translate of the locked-cache matrix (engine math library, shared with
 * Super Monkey Ball).
 *
 * One kernel family per header, and a landed header never grows: each inline function
 * a header adds shifts MWCC's anonymous literal numbering (@N) in every includer, which
 * breaks their recorded pool maps (measured: +3 per kernel in fn_1_D9224). Add new
 * kernels in a new header. See include/mathutil.h.
 */

/* mtxA translation = v (SMB1 counterpart: mathutil_mtxA_set_translate). Validated
 * 2026-11-08 (GC/1.3.2 -O4,p) on main_rel fn_1_98F28 (trail sprites, once per trail).
 * The asm keeps the locked-cache base out of MWCC's loop-invariant code motion: the C
 * spelling (three LC_MTX stores) hoists 0xE000 into a callee-saved register for the
 * whole function, about 80 differing rows. */
static inline void mathutil_mtxA_set_translate(register Vec3 *v) {
    register f32 *mtxA;
    register f32 x, y, z;
    asm {
        lfs x, v->x
        lfs y, v->y
        lfs z, v->z
        lis mtxA, 0xE000  /* fzgx-allow: A2 locked matrix */
        stfs x, 0x0C(mtxA)
        stfs y, 0x1C(mtxA)
        stfs z, 0x2C(mtxA)
    }
}

#endif  // MATHUTIL_MTXA_SET_TRANSLATE_H
