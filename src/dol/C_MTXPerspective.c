#include "types.h"

extern const f32 lbl_801A6F60;
extern const f32 lbl_801A6F68;
extern const f32 lbl_801A6F6C;
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
