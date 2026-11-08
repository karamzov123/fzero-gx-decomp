#ifndef MATHUTIL_VEC_SQ_DISTANCE_H
#define MATHUTIL_VEC_SQ_DISTANCE_H

#include "types.h"
#include "game/vec3.h"

/* Inline-asm squared distance of the engine's math library.
 *
 * One kernel family per header, and a landed header never grows: each inline function
 * a header adds shifts MWCC's anonymous literal numbering (@N) in every includer, which
 * breaks their recorded pool maps (measured: +3 per kernel in fn_1_D9224). Add new
 * kernels in a new header. See include/mathutil.h.
 */

/* (a - b) . (a - b), accumulated in one register. No exact SMB1 counterpart: it is SMB1's
 * mathutil_vec_distance kernel without the final sqrt, with the squares accumulated into
 * the x difference the way mathutil_sum_of_sq_3 does. Validated 2026-11-08 (GC/1.3.2
 * -O4,p) on main_rel fn_1_1177C4 (two vertex-coincidence tests against 1e-07). Plain C
 * gives 22 differing rows there; C differences plus mathutil_sum_of_sq_3 give 11. */
static inline f32 mathutil_vec_sq_distance(register Vec3 *a, register Vec3 *b) {
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
        fmuls x1, x1, x1
        fmadds x1, y1, y1, x1
        fmadds x1, z1, z1, x1
    }
    return x1;
}

#endif  // MATHUTIL_VEC_SQ_DISTANCE_H
