#include "types.h"


/* --- dol/C_MTXFrustum.c --- */
/* --- dol/C_MTXFrustum.c --- */
extern const f32 lbl_801A6F60;
extern const f32 lbl_801A6F64;
extern const f32 lbl_801A6F68;
extern const f32 lbl_801A6F6C;

struct fn_80015D7C_Matrix {
    f32 m[16];
};

void C_MTXFrustum(struct fn_80015D7C_Matrix *out, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f) {
    f32 tmp;
    f32 t2;

    t2 = lbl_801A6F64 * e;
    tmp = lbl_801A6F60 / (d - c);
    out->m[0] = t2 * tmp;
    out->m[1] = lbl_801A6F68;
    out->m[2] = (d + c) * tmp;
    out->m[3] = lbl_801A6F68;
    out->m[4] = lbl_801A6F68;
    tmp = lbl_801A6F60 / (a - b);
    {
        f32 vertical_scale = lbl_801A6F64 * e;
        vertical_scale *= tmp;
        out->m[5] = vertical_scale;
    }
    out->m[6] = (a + b) * tmp;
    out->m[7] = lbl_801A6F68;
    out->m[8] = lbl_801A6F68;
    out->m[9] = lbl_801A6F68;
    tmp = lbl_801A6F60 / (f - e);
    out->m[10] = -e * tmp;
    out->m[11] = -(f * e) * tmp;
    out->m[12] = lbl_801A6F68;
    out->m[13] = lbl_801A6F68;
    out->m[14] = lbl_801A6F6C;
    (*((15) + (out->m))) = lbl_801A6F68;
}

/* --- dol/C_MTXPerspective.c --- */
extern const f32 lbl_801A6F70;
extern const f32 lbl_801A6F74;
extern f32 fn_800885DC(f32);

void C_MTXPerspective(f32 *out, f32 a1, f32 a2, f32 a3, f32 a4) {
    f32 inv;
    f32 v2;
    f32 one;
    f32 zero;

    a1 = lbl_801A6F70 * a1;
    a1 = lbl_801A6F74 * a1;
    a1 = fn_800885DC(a1);
    one = lbl_801A6F60;
    inv = one / a1;
    out[0] = inv / a2;
    v2 = one / (a4 - a3);
    zero = lbl_801A6F68;
    out[1] = zero;
    out[2] = zero;
    out[3] = zero;
    out[4] = zero;
    out[5] = inv;
    out[6] = zero;
    out[7] = zero;
    out[8] = zero;
    out[9] = zero;
    out[10] = (-a3) * v2;
    out[11] = v2 * (-(a4 * a3));
    out[12] = zero;
    out[13] = zero;
    out[14] = lbl_801A6F6C;
    out[15] = zero;
}

/* --- dol/C_MTXOrtho.c --- */
typedef struct Fn80015EE8Out {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    f32 f7;
    f32 f8;
    f32 f9;
    f32 f10;
    f32 f11;
    f32 f12;
    f32 f13;
    f32 f14;
    f32 f15;
} Fn80015EE8Out;

void C_MTXOrtho(Fn80015EE8Out *out, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    f32 tmp;

    tmp = lbl_801A6F60 / (arg4 - arg3);
    out->f0 = lbl_801A6F64 * tmp;
    out->f1 = lbl_801A6F68;
    out->f2 = lbl_801A6F68;
    out->f3 = -(arg4 + arg3) * tmp;
    out->f4 = lbl_801A6F68;

    tmp = lbl_801A6F60 / (arg1 - arg2);
    out->f5 = lbl_801A6F64 * tmp;
    out->f6 = lbl_801A6F68;
    out->f7 = -(arg1 + arg2) * tmp;
    out->f8 = lbl_801A6F68;
    out->f9 = lbl_801A6F68;

    tmp = lbl_801A6F60 / (arg6 - arg5);
    out->f10 = lbl_801A6F6C * tmp;
    out->f11 = -arg6 * tmp;
    out->f12 = lbl_801A6F68;
    out->f13 = lbl_801A6F68;
    out->f14 = lbl_801A6F68;
    out->f15 = lbl_801A6F60;
}
