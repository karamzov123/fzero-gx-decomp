#include "types.h"

extern const f32 lbl_801A73D0;
extern const f32 lbl_801A73D4;
extern const f32 lbl_801A73D8;
extern f32 lbl_8006D188(s16);
extern f32 lbl_8006D0E8(f32);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;


#pragma opt_common_subs off
void fn_8006E7E4(Vec4 *arg0, Vec3 *arg1, s32 arg2) {
    f32 length_squared = arg1->x * arg1->x;
    f32 scale;

    length_squared += arg1->y * arg1->y;
    length_squared += arg1->z * arg1->z;

    if (length_squared < lbl_801A73D0) {
        arg0->x = lbl_801A73D4;
        arg0->y = lbl_801A73D4;
        arg0->z = lbl_801A73D4;
        arg0->w = lbl_801A73D8;
    } else {
        s16 a = arg2;
        f32 s = lbl_8006D188(a >> 1);
        scale = lbl_8006D0E8(length_squared);
        scale *= s;
        arg0->x = arg1->x * scale;
        arg0->y = arg1->y * scale;
        arg0->z = arg1->z * scale;
        arg0->w = lbl_8006D188((s16)(a >> 1) + 0x4000);
    }
}
#pragma opt_common_subs reset
