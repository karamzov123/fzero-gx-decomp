/* Non-matching: best partial attempt (98.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 LCEnable(void);
extern s32 lbl_801A6CE0;
extern u32 lbl_801A6CF0;
extern s32 fn_80070CF8(u32);
extern volatile u32 lbl_801A6CEC;
extern u8 lbl_8019E140[16];
extern u32 lbl_801A6D00[2];
extern u32 lbl_801A6D30[2];
extern u32 lbl_801A6D38;

#pragma opt_lifetimes off
#pragma opt_common_subs off
u32 fn_80070158(s32 arg0) {
    u32 d30;
    u32 size;
    u32 count;
    u32 off;
    u32 end;
    u32 limit;
    s16 i;
    u8 v;
    u32 lab_t0;

#pragma opt_propagation off

    if (arg0) {
        LCEnable();
        lbl_801A6CF0 = 0xE0000000;
        lbl_801A6CE0 |= 2;
    } else {
        lab_t0 = 0x4000;
        (void) lab_t0;  /* fzgx: keeps the web at its definition */
        lbl_801A6CF0 = fn_80070CF8(lab_t0);
    }

{
    u32 x;
    struct { u8 *value; } p;
    x = 0;
{
    u32 base;
    base = lbl_801A6CF0;
    lbl_801A6CEC = x;
    lbl_801A6CEC = 0x1c0;
{
    d30 = ((0x1c0) + (base));
    size = 0x1db;
    lbl_801A6CEC = 0x1dc;
    count = size;
    count >>= 5;
    p.value = lbl_8019E140;
    off = (((1) + (count))) << 5;
    lbl_801A6CEC = off;
    end = ((0xca0) + (off));
    lbl_801A6CEC = end;
    limit = (((0x3ff) + (end))) & ~0x3ff;
    lbl_801A6D00[0] = base;
    lbl_801A6D30[0] = d30;
}
    lbl_801A6D38 = ((base) + (off));
}
    lbl_801A6CEC = limit;

    {
    s32 fzgx_loop_i_1236;
for (fzgx_loop_i_1236 = 0; fzgx_loop_i_1236 < 16; fzgx_loop_i_1236++) {
        if (fzgx_loop_i_1236 < 14) {
            if (x <= limit) {
                v = 0xff;
            } else {
                v = 0;
            }
        } else {
            v = 1;
        }
        *p.value = v;
        x += 0x400;
        p.value += 1;
    }
    i = fzgx_loop_i_1236;
}
}
    return (u32)limit;
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset
