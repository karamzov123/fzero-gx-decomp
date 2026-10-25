#include "types.h"

extern const f32 lbl_801A7370;
extern const f32 lbl_801A7374;
extern const f32 lbl_801A7378;
extern const f32 lbl_801A737C;
extern const f64 lbl_801A7380;
extern u8 lbl_8019DF90[132];
extern f64 fn_80088598(f64, f64);

/* Power curve sample at x / 128; the conversions share one stack slot only when inlined. */
static inline f32 curve(s32 x) {
    return (f32)fn_80088598((f32)x * lbl_801A7370, lbl_801A7374);
}

#pragma optimize_for_size on
void fn_8006B99C(void) {
    s32 v0;
    f32 v1;
    for (v0 = 0; v0 < 129; v0++) {
        if (v0 < 0) {
            v1 = -(lbl_801A7378 + lbl_801A737C * curve(-v0));
        } else {
            v1 = lbl_801A7378 + lbl_801A737C * curve(v0);
        }
        lbl_8019DF90[v0] = (s32)v1;
    }
}
