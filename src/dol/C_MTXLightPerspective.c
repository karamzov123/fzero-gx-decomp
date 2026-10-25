#include "types.h"

extern const f32 lbl_801A6F50;
extern const f32 lbl_801A6F5C;
extern f32 fn_800885DC(f32);
extern const f32 lbl_801A6F48;
extern const f32 lbl_801A6F4C;
extern const f32 lbl_801A6F58;

#pragma peephole off
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

