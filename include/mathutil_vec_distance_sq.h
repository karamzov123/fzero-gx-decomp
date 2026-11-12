#ifndef MATHUTIL_VEC_DISTANCE_SQ_H
#define MATHUTIL_VEC_DISTANCE_SQ_H

#include "types.h"
#include "game/vec3.h"
#include "mathutil.h"

/* Inline-asm squared distance of the engine's math library (Amusement Vision's mathutil,
 * shared with Super Monkey Ball).
 *
 * One kernel family per header, and a landed header never grows: each inline function
 * a header adds shifts MWCC's anonymous literal numbering (@N) in every includer, which
 * breaks their recorded pool maps. Add new kernels in a new header. See include/mathutil.h.
 */

/* (a - b) . (a - b): the loads and differences of SMB1's mathutil_vec_distance kernel
 * (x1, x2, y1, y2, z1, z2, then three fsubs), squared and summed by mathutil_sum_of_sq_3.
 * Validated 2026-11-11 (GC/1.3.2 -O4,p) on main_rel fn_1_A47F4 (sound.c), three calls:
 * every load is a register variable of the kernel and the accumulator is the nested
 * kernel's parameter, numbered below all twelve loads of the two back-to-back calls. With C
 * differences the best body differs by 7 rows (four float registers); with the accumulate-in-x1
 * kernel of mathutil_vec_sq_distance.h by 23. fn_1_1177C4, the user of that header, also
 * matches with this kernel. */
static inline f32 mathutil_vec_distance_sq(register Vec3 *a, register Vec3 *b) {
    register f32 x1, y1, z1, x2, y2, z2;
    asm {
        lfs x1, a->x
        lfs x2, b->x
        lfs y1, a->y
        lfs y2, b->y
        lfs z1, a->z
        lfs z2, b->z
        fsubs x1, x1, x2
        fsubs y1, y1, y2
        fsubs z1, z1, z2
    }
    return mathutil_sum_of_sq_3(x1, y1, z1);
}

#endif  // MATHUTIL_VEC_DISTANCE_SQ_H
