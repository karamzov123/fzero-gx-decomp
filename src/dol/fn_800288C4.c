#include "types.h"

extern f32 lbl_801295E0[252];
extern f32 lbl_801A7038[2];

#pragma opt_lifetimes off
#pragma opt_propagation off
f32 fn_800288C4(s32 n) {
    f32 *t = lbl_801295E0;
    s32 rem;
    if (n > 0) {
        s32 q = n / 1200;
        s32 r = (n % 1200) / 100;
        rem = n % 100;
        return (t[100 + q] * t[112 + r]) * t[rem];
    }
    if (n < 0) {
        s32 q = n / 100;
        rem = n % 100;
        if (rem != 0) {
            rem += 100;
            q -= 1;
        }
        q *= -1;
        return t[124 + q] * t[rem];
    }
    return lbl_801A7038[0];
}
#pragma opt_lifetimes reset

