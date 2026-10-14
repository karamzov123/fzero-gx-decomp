/* Non-matching: best partial attempt (22.71% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern f32 lbl_8006D188(s16 angle);
extern f32 lbl_801A6F10;
extern f32 lbl_801A6F14;
extern f64 lbl_801A6F18;
extern f64 lbl_801A6F20;
extern f64 lbl_801A6F28;

s32 fn_80007F70(u8 *a, u8 *b, s16 angle, f32 scale) {
    f32 t;
    f32 w0;
    f32 w1;
    f32 w2;
    f32 w3;
    s32 out;
    u8 *o = (u8 *)&out;

    t = lbl_8006D188((s16)(angle & 0x3FF));
    t = lbl_801A6F10 * (t + lbl_801A6F14);

    if (a[0] < b[0]) {
        u8 tmp = a[0];

        b[0] = tmp;
        a[0] = b[0];
        w0 = (f32)(lbl_801A6F18 - (f64)t);
    } else {
        w0 = t;
    }
    if (a[1] < b[1]) {
        u8 tmp = a[1];

        b[1] = tmp;
        a[1] = b[1];
        w1 = (f32)(lbl_801A6F18 - (f64)t);
    } else {
        w1 = t;
    }
    if (a[2] < b[2]) {
        u8 tmp = a[2];

        b[2] = tmp;
        a[2] = b[2];
        w2 = (f32)(lbl_801A6F18 - (f64)t);
    } else {
        w2 = t;
    }
    if (a[3] < b[3]) {
        u8 tmp = a[3];

        b[3] = tmp;
        a[3] = b[3];
        w3 = (f32)(lbl_801A6F18 - (f64)t);
    } else {
        w3 = t;
    }

    {
        f32 d0 = (f32)((f64)(u32)a[0] - 4503601774854144.0) - (f32)((f64)(u32)b[0] - 4503601774854144.0);
        f32 d1 = (f32)((f64)(u32)a[1] - 4503601774854144.0) - (f32)((f64)(u32)b[1] - 4503601774854144.0);
        f32 d2 = (f32)((f64)(u32)a[2] - 4503601774854144.0) - (f32)((f64)(u32)b[2] - 4503601774854144.0);
        f32 d3 = (f32)((f64)(u32)a[3] - 4503601774854144.0) - (f32)((f64)(u32)b[3] - 4503601774854144.0);

        o[0] = (u8)(a[0] - (u32)(w0 * d0));
        o[1] = (u8)(a[1] - (u32)(w1 * d1));
        o[2] = (u8)(a[2] - (u32)(w2 * d2));
        o[3] = (u8)(a[3] - (u32)(w3 * d3));
    }
    return out;
}
