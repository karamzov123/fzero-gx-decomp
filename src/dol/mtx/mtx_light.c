#include "types.h"

extern const f32 lbl_801A6F48;
extern const f32 lbl_801A6F4C;
extern const f32 lbl_801A6F50;
extern const f32 lbl_801A6F54;
extern const f32 lbl_801A6F58;
extern const f32 lbl_801A6F5C;
extern f32 fn_800885DC(f32);

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
