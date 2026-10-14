/* Non-matching: best partial attempt (56.72% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/globals.h"
#include "rel/customize/toolkit.h"

extern const f32 lbl_3_rodata_6A0[40];
extern void fn_3_146C0(void *, s16, s16, s16, u32 *);

void fn_3_1B4BC(void *obj, s32 x1, s32 y1, s32 x2, s32 y2, u32 *items) {
    s32 x;
    s32 y;
    s32 start;
    s32 end;
    s32 i;
    s32 j;
    s32 dx;
    s32 dy;
    s32 radius;
    u16 size;
    s16 half;
    s32 row;
    s32 col;
    f32 slope;
    f32 acc;
    u32 value;

    if ((s16)x1 == (s16)x2) {
        start = (s16)y1;
        end = (s16)y2;
        if (start > end) { s32 t = start; start = end; end = t; }
        for (y = start; y <= end; y++) {
            size = lbl_3_bss_A2438.unk_C * 2 + 1;
            half = size >> 1;
            value = *items;
            for (i = -half; i <= half; i++) {
                fn_3_146C0(obj, (s16)(x1 - half), (s16)(y + i), (s16)size, &value);
            }
        }
    } else if ((s16)y1 == (s16)y2) {
        start = (s16)x1;
        end = (s16)x2;
        if (start > end) { s32 t = start; start = end; end = t; }
        for (x = start; x <= end; x++) {
            size = lbl_3_bss_A2438.unk_C * 2 + 1;
            half = size >> 1;
            value = *items;
            for (i = -half; i <= half; i++) {
                fn_3_146C0(obj, (s16)(y1 - half), (s16)(x + i), (s16)size, &value);
            }
        }
    } else {
        dx = (s16)x2 - (s16)x1;
        dy = (s16)y2 - (s16)y1;
        slope = (f32)dy / (f32)dx;

        value = *items;
        for (i = -half; i <= half; i++) {
            fn_3_146C0(obj, (s16)(y1 - half), (s16)(x1 + i), (s16)size, &value);
        }

        if (slope < 0.0f) {
            start = x1;
            end = x2;
            y = y1;
            if ((s16)start > (s16)end) { s32 t = start; start = end; end = t; y = y2; }
            acc = 1.0f;
            for (x = start + 1; (s16)x < (s16)end; x++) {
                if (slope > -1.0f) {
                    value = *items;
                    for (i = -half; i <= half; i++) {
                        fn_3_146C0(obj, (s16)(y + i), (s16)(x - half), (s16)size, &value);
                    }
                }
                acc += slope;
                if (acc < -0.5f) {
                    y--;
                    value = *items;
                    for (i = -half; i <= half; i++) {
                        fn_3_146C0(obj, (s16)(y + i), (s16)(x - half), (s16)size, &value);
                    }
                }
            }
        } else {
            start = x1;
            end = x2;
            y = y1;
            if ((s16)start > (s16)end) { s32 t = start; start = end; end = t; }
            acc = 0.0f;
            for (x = start + 1; (s16)x < (s16)end; x++) {
                if (slope < 1.0f) {
                    value = *items;
                    for (i = -half; i <= half; i++) {
                        fn_3_146C0(obj, (s16)(y + i), (s16)(x - half), (s16)size, &value);
                    }
                }
                acc += slope;
                if (acc > 0.5f) {
                    y++;
                    value = *items;
                    for (i = -half; i <= half; i++) {
                        fn_3_146C0(obj, (s16)(y + i), (s16)(x - half), (s16)size, &value);
                    }
                }
            }
        }
    }
}
