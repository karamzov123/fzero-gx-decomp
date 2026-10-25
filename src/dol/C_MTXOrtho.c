#include "types.h"

extern const f32 lbl_801A6F60;
extern const f32 lbl_801A6F64;
extern const f32 lbl_801A6F68;
extern const f32 lbl_801A6F6C;

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
