#ifndef PSVEC_SET_XYZ_H
#define PSVEC_SET_XYZ_H

#include "types.h"

/* WARNING: compiler-diff device, not original code (owner-approved 2026-11-24, lane AC).
 * dst = (x, y, z), stored with three stfs. Honest form: `dst->x = x; dst->y = y; dst->z = z;`.
 * It is used for the sphere centres of the accessory.c sphere family (fn_1_11A774, fn_1_11F250,
 * fn_1_123050, fn_1_124AD4, fn_1_1256EC, fn_1_12744C). Retail loads each centre constant at its
 * assignment (z, y, x), hoisted out of the loop in that order; MWCC 1.3.2 constant-propagates the
 * plain C stores to their first use, and no C spelling was found that keeps the centre literals
 * unpropagated (laneAC rounds 2 and 3). As inline-asm operands they are not propagated. Residual with
 * the plain stores in the one-unit build: 11A774 21 words, 11F250 12, 123050 133, 124AD4 10,
 * 1256EC 10, 12744C 23 (and .rodata literal order). Related evidence, not proof: SMB1 (same
 * developer) src/mathutil.h stores register floats with inline-asm stfs in its vector kernels
 * (e.g. mathutil_mtxA_set_translate_xyz stores three register floats with stfs). Found by laneAC p2.
 * Its own header, not psvec.h: a new inline in psvec.h renumbers the @N literals of the units that
 * include psvec.h and breaks their literal-pool maps (7 units failed). */
static inline void vec_set_xyz(register void *dst, register f32 x, register f32 y, register f32 z) {
    asm {
        stfs x, 0(dst)
        stfs y, 4(dst)
        stfs z, 8(dst)
    }
}

#endif
