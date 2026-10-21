#include "types.h"

/* ADX_GetCoefficient (adx_dcd.c, CRI ADX): IIR prediction coefficients for a cutoff. */

extern const f32 lbl_80090938;
extern const f64 lbl_80090940;
extern const f64 lbl_80090948;
extern const f64 lbl_80090950;
extern const f32 lbl_80090958;
extern const f32 lbl_8009095C;
extern const f32 lbl_80090960;
extern const f32 lbl_80090964;
extern f64 __frsqrte(f64);
extern f64 fn_80087E80(f32);

static f64 fn_80046D94_refine(f64 x) {
    f64 r;
    r = __frsqrte(x);
    r = lbl_80090948 * r * (lbl_80090950 - x * (r * r));
    r = lbl_80090948 * r * (lbl_80090950 - x * (r * r));
    r = lbl_80090948 * r * (lbl_80090950 - x * (r * r));
    return x * r;
}

void fn_80046D94(s32 arg0, s32 arg1, short *arg2, short *arg3) {
    volatile f32 sa; /* retail rounds each square root through a float stack slot */
    volatile f32 sb; /* retail rounds each square root through a float stack slot */
    volatile f32 vr; /* retail rounds each square root through a float stack slot */
    f32 v;
    f32 ang;
    f32 d;
    f32 e;
    f32 t;
    ang = (f32)fn_80087E80(lbl_80090938 * (f32)arg0 / (f32)arg1);
    sa = (f32)fn_80046D94_refine(lbl_80090940);
    d = sa - ang;
    sb = (f32)fn_80046D94_refine(lbl_80090940);
    e = sb - lbl_80090958;
    v = (d + e) * (d - e);
    if (v > lbl_8009095C) {
        vr = (f32)fn_80046D94_refine(v);
        v = vr;
    }
    t = (d - v) / e;
    *arg2 = lbl_80090960 * (lbl_80090964 * t);
    *arg3 = lbl_80090960 * (-t * t);
}
