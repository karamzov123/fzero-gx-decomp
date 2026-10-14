/* Non-matching: best partial attempt (73.11% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Matrix3 {
    f32 m[9];
} Matrix3;

extern const f32 lbl_12_rodata_2E98;

void fn_12_3E500(const Matrix3 *a, Matrix3 *out) {
    f32 a0 = a->m[0], a1 = a->m[1], a2 = a->m[2];
    f32 a3 = a->m[3], a4 = a->m[4], a5 = a->m[5];
    f32 a6 = a->m[6], a7 = a->m[7], a8 = a->m[8];
    f32 t13 = a1 * a3;
    f32 t15 = a1 * a5;
    f32 t04 = a0 * a4;
    f32 t56 = a5 * a6;
    f32 t57 = a5 * a7;
    f32 t05 = a0 * a5;
    f32 t23 = a2 * a3;
    f32 t24 = a2 * a4;
    f32 s1 = a8 * t04 + a6 * t15 + a7 * t23;
    f32 s2 = a7 * t05 + a8 * t13 + a6 * t24;
    f32 det = s1 - s2;
    f32 f27 = a2 * a7;
    f32 f26 = a2 * a6;
    f32 f46 = a4 * a6;
    f32 f16 = a1 * a6;

    out->m[0] = lbl_12_rodata_2E98 * ((a4 * a8 - t57) / det);
    out->m[1] = lbl_12_rodata_2E98 * ((t56 - a3 * a8) / det);
    out->m[2] = lbl_12_rodata_2E98 * ((t15 - t24) / det);
    out->m[3] = lbl_12_rodata_2E98 * (((f32)(f27) - a1 * a8) / det);
    out->m[4] = lbl_12_rodata_2E98 * ((a0 * a8 - f26) / det);
    out->m[5] = lbl_12_rodata_2E98 * (-(t05 - t23) / det);
    out->m[6] = lbl_12_rodata_2E98 * ((a3 * a7 - f46) / det);
    out->m[7] = lbl_12_rodata_2E98 * (((f32)(f16) - a0 * a7) / det);
    out->m[8] = lbl_12_rodata_2E98 * ((t04 - t13) / det);
}
