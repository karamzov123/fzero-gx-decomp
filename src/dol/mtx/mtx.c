#include "types.h"

/* Dolphin SDK mtx/mtx.c. The paired-single matrix routines are CodeWarrior asm functions in
 * the original (psq_l/psq_st and ps_* arithmetic, no compiler frame); the light projection
 * matrices are C. */

typedef f32 Mtx[3][4];
typedef struct Quaternion { f32 x, y, z, w; } Quaternion;

extern const f32 lbl_801A6F48;
extern const f32 lbl_801A6F4C;
extern const f32 lbl_801A6F50;
extern const f32 lbl_801A6F54;
extern const f32 lbl_801A6F58;
extern const f32 lbl_801A6F5C;
extern f32 fn_800885DC(f32);


asm void PSMTXIdentity(register Mtx m) {
    nofralloc
    lfs f0, lbl_801A6F4C
    lfs f1, lbl_801A6F48
    psq_st f0, 0x8(r3), 0, 0
    ps_merge01 f2, f0, f1
    psq_st f0, 0x18(r3), 0, 0
    ps_merge10 f1, f1, f0
    psq_st f0, 0x20(r3), 0, 0
    psq_st f2, 0x10(r3), 0, 0
    psq_st f1, 0x0(r3), 0, 0
    psq_st f1, 0x28(r3), 0, 0
    blr
}

asm void PSMTXScale(register Mtx m, register f32 xS, register f32 yS, register f32 zS) {
    nofralloc
    lfs f0, lbl_801A6F4C
    stfs f1, 0x0(r3)
    psq_st f0, 0x4(r3), 0, 0
    psq_st f0, 0xc(r3), 0, 0
    stfs f2, 0x14(r3)
    psq_st f0, 0x18(r3), 0, 0
    psq_st f0, 0x20(r3), 0, 0
    stfs f3, 0x28(r3)
    stfs f0, 0x2c(r3)
    blr
}

asm void PSMTXQuat(register Mtx m, register const Quaternion *q) {
    nofralloc
    lfs f1, lbl_801A6F48
    psq_l f4, 0x0(r4), 0, 0
    psq_l f5, 0x8(r4), 0, 0
    fsubs f0, f1, f1
    fadds f2, f1, f1
    ps_mul f6, f4, f4
    ps_merge10 f9, f4, f4
    ps_madd f8, f5, f5, f6
    ps_mul f7, f5, f5
    ps_sum0 f3, f8, f8, f8
    ps_muls1 f10, f9, f5
    fres f11, f3
    ps_sum1 f8, f7, f8, f6
    ps_nmsub f3, f3, f11, f2
    ps_muls1 f7, f5, f5
    ps_mul f3, f11, f3
    ps_sum0 f6, f6, f6, f6
    fmuls f3, f3, f2
    ps_madd f11, f4, f9, f7
    ps_msub f7, f4, f9, f7
    psq_st f0, 0xc(r3), 1, 0
    ps_nmsub f6, f6, f3, f1
    ps_nmsub f8, f8, f3, f1
    psq_st f0, 0x2c(r3), 1, 0
    ps_mul f11, f11, f3
    ps_mul f7, f7, f3
    psq_st f6, 0x28(r3), 1, 0
    ps_madds0 f9, f4, f5, f10
    ps_merge00 f5, f11, f8
    ps_nmsub f10, f10, f2, f9
    ps_merge10 f4, f8, f7
    psq_st f5, 0x10(r3), 0, 0
    ps_mul f9, f9, f3
    ps_mul f10, f10, f3
    psq_st f4, 0x0(r3), 0, 0
    psq_st f9, 0x8(r3), 1, 0
    ps_merge10 f7, f10, f0
    ps_merge01 f11, f10, f9
    psq_st f7, 0x18(r3), 0, 0
    psq_st f11, 0x20(r3), 0, 0
    blr
}

#pragma peephole off
void fn_80015C1C(f32 *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5,
                 f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 t;
    struct { f32 value; } s;
    f32 u;

    t = lbl_801A6F48 / (arg4 - arg3);
    s.value = lbl_801A6F54 * arg5;
    out[0] = arg6 * (s.value * t);
    out[1] = lbl_801A6F4C;
    u = arg6;
    u = u * (t * (arg4 + arg3));
    out[2] = u - arg8;
    out[3] = lbl_801A6F4C;
    out[4] = lbl_801A6F4C;
    t = lbl_801A6F48 / (arg1 - arg2);
    out[5] = arg7 * ((((s.value) * t)));
    u = arg7 * (t * (arg1 + arg2));
    out[6] = u - arg9;
    out[7] = lbl_801A6F4C;
    out[8] = lbl_801A6F4C;
    out[9] = lbl_801A6F4C;
    out[10] = lbl_801A6F58;
    out[11] = lbl_801A6F4C;
}

void C_MTXLightPerspective(f32 *out, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    f32 inv;

    a = lbl_801A6F50 * a;
    a = lbl_801A6F5C * a;
    a = fn_800885DC(a);

    inv = lbl_801A6F48 / a;
    out[0] = c * (inv / b);
    out[1] = lbl_801A6F4C;
    out[2] = -e;
    out[3] = lbl_801A6F4C;
    out[4] = lbl_801A6F4C;
    out[5] = inv * d;
    out[6] = -f;
    out[7] = lbl_801A6F4C;
    out[8] = lbl_801A6F4C;
    out[9] = lbl_801A6F4C;
    out[10] = lbl_801A6F58;
    out[11] = lbl_801A6F4C;
}
#pragma peephole reset
