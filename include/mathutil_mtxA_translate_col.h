#ifndef MATHUTIL_MTXA_TRANSLATE_COL_H
#define MATHUTIL_MTXA_TRANSLATE_COL_H

#include "types.h"
#include "game/vec3.h"

/* Inline-asm translate of the locked-cache matrix along one of its columns
 * (engine math library).
 *
 * One kernel family per header, and a landed header never grows: each inline function
 * a header adds shifts MWCC's anonymous literal numbering (@N) in every includer, which
 * breaks their recorded pool maps (measured: +3 per kernel in fn_1_D9224). Add new
 * kernels in a new header. See include/mathutil.h.
 */

/* mtxA translation += column 2 of mtxA * d, in place (mtxA is the locked-cache matrix).
 * No exact SMB1 counterpart: SMB1's mathutil_unk_inline computes the same
 * col2 * a + translate with the same load/fmadds order, but stores the result to a Vec;
 * this one stores it back into mtxA[0..2][3]. Validated 2026-11-07 (GC/1.3.2 -O4,p) on
 * main_rel fn_1_10976C (scales 0.025f and 0.057f). With d a register parameter of an
 * opaque kernel, the constant scale is not propagated into the multiply, which is what
 * retail does; no C spelling keeps it (the C form needs opt_lifetimes off and still
 * misses). The same kernel also reproduces the translates of fn_1_203E4, fn_1_29A0C,
 * fn_1_44A74 and fn_1_FD3A8 without their opt_lifetimes off pragmas. */
static inline void mathutil_mtxA_translate_z(register f32 d) {
    register f32 *mtxA;
    register f32 x, y, z;
    register f32 tx, ty, tz;
    asm {
        lis mtxA, 0xE000  /* fzgx-allow: A2 locked matrix */
        lfs x, 0x08(mtxA)
        lfs tx, 0x0C(mtxA)
        lfs y, 0x18(mtxA)
        lfs ty, 0x1C(mtxA)
        lfs z, 0x28(mtxA)
        lfs tz, 0x2C(mtxA)
        fmadds x, x, d, tx
        stfs x, 0x0C(mtxA)
        fmadds y, y, d, ty
        stfs y, 0x1C(mtxA)
        fmadds z, z, d, tz
        stfs z, 0x2C(mtxA)
    }
}

/* As mathutil_mtxA_translate_z, along column 0 (no SMB1 counterpart). Validated
 * 2026-11-07 on main_rel fn_1_10976C (scale -0.019f). */
static inline void mathutil_mtxA_translate_x(register f32 d) {
    register f32 *mtxA;
    register f32 x, y, z;
    register f32 tx, ty, tz;
    asm {
        lis mtxA, 0xE000  /* fzgx-allow: A2 locked matrix */
        lfs x, 0x00(mtxA)
        lfs tx, 0x0C(mtxA)
        lfs y, 0x10(mtxA)
        lfs ty, 0x1C(mtxA)
        lfs z, 0x20(mtxA)
        lfs tz, 0x2C(mtxA)
        fmadds x, x, d, tx
        stfs x, 0x0C(mtxA)
        fmadds y, y, d, ty
        stfs y, 0x1C(mtxA)
        fmadds z, z, d, tz
        stfs z, 0x2C(mtxA)
    }
}

#endif  // MATHUTIL_MTXA_TRANSLATE_COL_H
