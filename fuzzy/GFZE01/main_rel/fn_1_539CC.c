/* Non-matching: best partial attempt (86.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

extern const f32 lbl_1_rodata_2754;
extern const f64 lbl_1_rodata_2758;

struct u8x4 {
    u8 x;
    u8 y;
    u8 z;
    u8 w;
};

struct u8x4 fn_1_539CC(u8 *a, u8 *b, f32 t)
{
    struct u8x4 r;
    f32 s, p0, p1, p2, p3, q0, q1, q2, q3;

    s = lbl_1_rodata_2754 - t;

    p0 = (f32)(u32)a[0] * t;
    q0 = (f32)(u32)b[0] * s;
    r.x = p0 + q0;

    p1 = (f32)(u32)a[1] * t;
    q1 = (f32)(u32)b[1] * s;
    r.y = p1 + q1;

    p2 = (f32)(u32)a[2] * t;
    q2 = (f32)(u32)b[2] * s;
    r.z = p2 + q2;

    p3 = (f32)(u32)a[3] * t;
    q3 = (f32)(u32)b[3] * s;
    r.w = p3 + q3;

    return r;
}
