/* Non-matching: best partial attempt (96.84% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_8006AA44_Arg0 {
    u8 pad_0[0x4];
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
};

struct fn_8006AA44_Arg1 {
    u8 pad_0[0x2];
    u8 unk_2;
    u8 pad_3;
    u8 unk_4;
    u8 unk_5;
};

struct fn_8006AA44_Arg2 {
    u8 pad_0[0x4];
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 pad_7[0x7];
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
    u8 pad_11[0x7];
    u8 unk_18;
    u8 unk_19;
    u8 pad_1A[0x6];
    u8 unk_20;
    u8 pad_21[0x7];
    s32 unk_28;
};

#pragma opt_propagation off
void fn_8006AA44(struct fn_8006AA44_Arg0 *arg0, struct fn_8006AA44_Arg1 *arg1, struct fn_8006AA44_Arg2 *arg2) {
    u8 *fzgx_value_;
    s32 fzgx_value;
    s32 t;
    struct { s32 value; } c;

    if ((arg1->unk_2 ^ arg2->unk_20) & 8) {
        c.value = 64;
        arg2->unk_4 = 64;
        arg2->unk_28 = c.value;
        arg2->unk_5 = 80;
        t = (arg2->unk_4 - arg2->unk_5) / 2;
        if (t < -128) {
            t = -128;
        } else if (t > 127) {
            t = 127;
        }
        arg2->unk_6 = t;
        arg2->unk_E = 176;
        fzgx_value_ = &(arg2->unk_F);
        *fzgx_value_ = 176;
        t = (arg2->unk_E - arg2->unk_F) / 2;
        if (t < -128) {
            t = -128;
        } else if (t > 127) {
            t = 127;
        }
        arg2->unk_10 = t;
        arg2->unk_18 = 10;
        arg2->unk_19 = 10;
    }

    if (arg2->unk_28 > 0) {
        arg2->unk_28 = arg2->unk_28 - 1;
        arg0->unk_5 = 0;
        arg0->unk_4 = 0;
        arg0->unk_6 = 0;
        return;
    }

    if (arg1->unk_2 & 8) {
        {
            s32 min;
            s32 v;
            s32 radius;
            s32 max;
            s32 denom;
            v = arg1->unk_4;
            min = arg2->unk_4;
            radius = arg2->unk_18;
            max = arg2->unk_E;
            if (v < min) {
                arg2->unk_4 = v;
                min = v;
            }
            if (v > max) {
                arg2->unk_E = v;
                max = v;
            }
            denom = (max - min) - (u8)radius * 2;
            if (denom == 0) {
                denom = 1;
            }
            t = (v - (min + radius)) * 255 / denom;
            if (t < 0) {
                t = 0;
            }
            if (t > 255) {
                t = 255;
            }
            arg0->unk_4 = t;
        }
        {
            s32 min;
            s32 v;
            s32 radius;
            s32 max;
            s32 denom;
            v = arg1->unk_5;
            min = arg2->unk_5;
            radius = arg2->unk_19;
            max = arg2->unk_F;
            if (v < min) {
                arg2->unk_5 = v;
                min = v;
            }
            if (v > max) {
                arg2->unk_F = v;
                max = v;
            }
            if ((denom = (max - min) - 2 * (u8)radius) == 0) {
                denom = 1;
            }
            t = (v - (min + radius)) * 255 / denom;
            if (t < 0) {
                t = 0;
            }
            if (t > 255) {
                t = 255;
            }
            arg0->unk_5 = t;
        }
        t = (arg0->unk_4 - arg0->unk_5) / 2;
        if (t < -128) {
            t = -128;
        } else if (t > 127) {
            t = 127;
        }
        arg0->unk_6 = t;
    } else {
        fzgx_value = 0;
        arg0->unk_5 = fzgx_value;
        arg0->unk_4 = 0;
        arg0->unk_6 = 0;
    }
}
#pragma opt_propagation reset
