#include "types.h"

extern f32 lbl_8006D0B4(f32);
extern s16 lbl_8006D2AC(f32);

#pragma fp_contract off

s16 lbl_8006D46C(f32 x) {
    s16 angle;
    f32 c;

    if (__fabs(x) > 1.0) {
        if (x > 0.0f) {
            return 0;
        }
        return -0x8000;
    }
    if (__fabs(x) > 1.0) {
        if (x > 0.0f) {
            angle = 0x4000;
        } else {
            angle = -0x4000;
        }
    } else {
        c = lbl_8006D0B4(1.0f - x * x);
        if (c > 1.1920929e-07f) {
            angle = lbl_8006D2AC(x / c);
        } else if (x > 0.0f) {
            angle = 0x4000;
        } else {
            angle = -0x4000;
        }
    }
    return (0x4000 - angle) & 0xFFFF;
}
