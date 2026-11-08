#ifndef MATHUTIL_VEC_CROSS_PROD_H
#define MATHUTIL_VEC_CROSS_PROD_H

#include "types.h"
#include "game/vec3.h"

/* Inline-asm vector cross product of the engine's math library (Amusement Vision's
 * mathutil, shared with Super Monkey Ball).
 *
 * One kernel family per header, and a landed header never grows: each inline function
 * a header adds shifts MWCC's anonymous literal numbering (@N) in every includer, which
 * breaks their recorded pool maps (measured: +3 per kernel in fn_1_D9224). Add new
 * kernels in a new header. See include/mathutil.h.
 */

/* out = a x b, written component by component (SMB1 counterpart:
 * mathutil_vec_cross_prod). Validated 2026-11-07 (GC/1.3.2 -O4,p) on main_rel
 * fn_1_10976C, four calls. The kernel's load order is part of the match: loading
 * a then b component-wise gives 60 differing rows, and the C spelling leaves the
 * block out of MWCC's post-allocation reschedule (the c.x store lands before the
 * following fmuls). */
static inline void mathutil_vec_cross_prod(register Vec3 *a, register Vec3 *b, register Vec3 *out) {
    register f32 ax, ay, az;
    register f32 bx, by, bz;
    register f32 x, y, z;
    asm {
        lfs ay, a->y
        lfs bz, b->z
        lfs az, a->z
        lfs bx, b->x
        lfs ax, a->x
        lfs by, b->y
        fmuls x, ay, bz
        fmuls y, az, bx
        fmuls z, ax, by
        fnmsubs x, az, by, x
        stfs x, out->x
        fnmsubs y, ax, bz, y
        stfs y, out->y
        fnmsubs z, ay, bx, z
        stfs z, out->z
    }
}

#endif  // MATHUTIL_VEC_CROSS_PROD_H
