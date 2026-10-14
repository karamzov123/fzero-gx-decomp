/* Non-matching: best partial attempt (76.98% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_80192D68[1344];
extern const f32 lbl_801A72A8;
extern const f64 lbl_801A72A0;
extern const f64 lbl_801A7298;
extern f64 fn_80088578(f32);

typedef struct CurvePoint {
    u8 end;
    u8 value;
    s16 slope;
} CurvePoint;

void fn_80060724(u8 *arg0, u8 arg1, u8 arg2, s32 *arg3, s32 *arg4, s32 *arg5) {
    s32 tmp_cse1;
    u8 *data = arg0 + 12;
    CurvePoint *point;
    s32 value;
    u8 i;
    u8 start = arg0[4];
    CurvePoint * point_2;
    *arg3 = arg0[1];
    point = (CurvePoint *)(data + data[9]);
    for (i = 0; i < data[8]; i++) {
        if (arg2 <= point->end) break;
        start = point->end + 1;
        point++;
    }
    value = (point->slope * (arg2 - start)) >> 8;
    tmp_cse1 = arg1 * 0x54;
    value += ((s32)lbl_80192D68[tmp_cse1 + 6] - 64) << 1;
    value += point->value;
    if (value > 127) value = 127;
    else if (value < 0) value = 0;
    if (value != 0) {
        *arg4 = (s32)(lbl_801A7298 * (lbl_801A72A0 * fn_80088578((f32)value / lbl_801A72A8)));
    } else {
        *arg4 = -904;
    }
    point_2 = (CurvePoint *)(((data[11]) + (data)));
    for (i = 0; i < data[10]; i++) {
        if (arg2 <= point_2->end) break;
        start = point_2->end + 1;
        point_2++;
    }
    value = (point_2->slope * (arg2 - start)) >> 8;
    value += ((s32)lbl_80192D68[tmp_cse1 + 7] - 64) << 1;
    value += point_2->value;
    if (value > 127) value = 127;
    else if (value < 0) value = 0;
    if (value != 0) {
        *arg5 = (s32)(lbl_801A7298 * (lbl_801A72A0 * fn_80088578((f32)value / lbl_801A72A8)));
    } else {
        *arg5 = -904;
    }
}
