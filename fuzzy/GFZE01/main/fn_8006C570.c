/* Non-matching: best partial attempt (92.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_8006C570_Arg0 {
    u8 pad_0[4];
    u32 unk_4;
    u8 pad_8[0x24];
    u32 unk_2C;
};
struct fn_8006C570_Arg1 {
    s32 unk_0;
    s32 unk_4;
    u8 unk_8;
    u8 unk_9;
};

#pragma opt_lifetimes off
s32 fn_8006C570(struct fn_8006C570_Arg0 *arg0, struct fn_8006C570_Arg1 *arg1, s32 arg2) {
    u32 current;
    s32 magnitude;
    s32 negative;
    s32 value;
    s32 negative_2;
    s32 duration;
    struct { s32 value; } half;
    u32 end;
    s32 tmp_call1;
    s32 elapsed;
    current = arg0->unk_2C;
    tmp_call1 = __abs(arg2);
    magnitude = tmp_call1;
    negative = (u32)arg2;
    negative_2 = negative_2 >> 31;
    duration = arg1->unk_0;
    arg2 = magnitude;
    if (current < (u32)duration) {
        s32 base = arg1->unk_8;
        s32 delta = magnitude - base;
        half.value = duration / 2;
        if ((s32)current < 0) half.value = -half.value;
        arg2 = base;
        arg2 = arg2 + ((s32)current * delta + half.value) / duration;
    } else {
        end = arg0->unk_4;
        if (end != 0xFFFFFFFF) {
            duration = arg1->unk_4;
            (void) duration;  /* fzgx: keeps the web at its definition */
            if (current > end - duration) {
                if (current < end) {
                    s32 delta;
                    tmp_call1 = current - (end - duration);
                    arg2 = tmp_call1;
                    delta = arg1->unk_9 - magnitude;
                    half.value = duration / 2;
                    if (arg2 < 0) half.value = -half.value;
                    arg2 = magnitude + (arg2 * delta + half.value) / duration;
                } else {
                    arg2 = arg1->unk_9;
                }
            }
        }
    }
    if (negative_2) arg2 = -arg2;
    return arg2;
}
#pragma opt_lifetimes reset

