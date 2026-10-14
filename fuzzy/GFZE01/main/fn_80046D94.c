/* Non-matching: best partial attempt (70.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

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

void fn_80046D94(s32 arg0, s32 arg1, u16 *arg2, u16 *arg3) {
    volatile f32 sa;
    volatile f32 sb;
    volatile f32 vr;
    f32 v;
    f32 ang;
    f32 d;
    f32 e;
    f32 t;
    ang = (f32)fn_80087E80(lbl_80090938 * (f32)arg0 / (f32)arg1);
    sa = (f32)fn_80046D94_refine(lbl_80090940);
    sb = (f32)fn_80046D94_refine(lbl_80090940);
    d = sa - ang;
    e = sb - lbl_80090958;
    v = (d + e) * (d - e);
    if (v > lbl_8009095C) {
        vr = (f32)fn_80046D94_refine(v);
        v = vr;
    }
    t = (d - v) / e;
    *arg2 = (u16)(s32)(lbl_80090960 * (lbl_80090964 * t));
    *arg3 = (u16)(s32)(lbl_80090960 * ((-t) * t));
}
