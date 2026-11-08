#ifndef MATHUTIL_VEC_DOT_PROD_H
#define MATHUTIL_VEC_DOT_PROD_H

#include "types.h"
#include "game/vec3.h"

/* Inline-asm vector dot product of the engine's math library (Amusement Vision's
 * mathutil, shared with Super Monkey Ball).
 *
 * One kernel family per header, and a landed header never grows: each inline function
 * a header adds shifts MWCC's anonymous literal numbering (@N) in every includer, which
 * breaks their recorded pool maps (measured: +3 per kernel in fn_1_D9224). Add new
 * kernels in a new header. See include/mathutil.h.
 */

/* a . b accumulated in one register (SMB1 counterpart: mathutil_vec_dot_prod): loads
 * x1, x2, y1, y2, z1, z2, then fmuls/fmadds/fmadds. Validated 2026-11-08 (GC/1.3.2
 * -O4,p) on main_rel fn_1_DEDC4, four calls: with a C dot product the best body
 * differs by 47 rows, because retail's dot products keep the kernel's register order. */
static inline f32 mathutil_vec_dot_prod(register Vec3 *a, register Vec3 *b) {
    register f32 result;
    register f32 x1, y1, z1, x2, y2, z2;
    asm {
        lfs x1, a->x
        lfs x2, b->x
        lfs y1, a->y
        lfs y2, b->y
        lfs z1, a->z
        lfs z2, b->z
        fmuls result, x1, x2
        fmadds result, y1, y2, result
        fmadds result, z1, z2, result
    }
    return result;
}

#endif  // MATHUTIL_VEC_DOT_PROD_H
