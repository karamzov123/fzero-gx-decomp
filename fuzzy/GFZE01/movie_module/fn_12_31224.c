/* Non-matching: best partial attempt (69.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_31224_Rec {
    u8 pad_0[0x18];
    u8 key;
    u8 pad_19[7];
    u8 state;
    u8 pad_21[2];
    u8 flag;
    u8 pad_24[0x5C];
};

struct fn_12_31224_Arg0 {
    s32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s32 unk_C;
};

s32 fn_12_31224(struct fn_12_31224_Arg0 *arg0, u32 arg1, u32 *arg2) {
    u8 *p = (u8 *)arg0->unk_4;
    struct fn_12_31224_Rec *found = 0;
    s32 flag;
    s32 ok;
    u32 cls;
    u32 i;

    flag = (arg0->unk_0 >= 2) || (arg0->unk_0 < -1);
    ok = 0;
    if (flag) {
        flag = (arg0->unk_C == 0x6B) || (arg0->unk_C >= 0x6E);
        if (flag) {
            ok = 1;
        } else {
            ok = 0;
        }
    }
    if (ok) {
        for (i = 0; i < 13; i++) {
            if (*(u8 *)(p + 0x198) == ((arg1 >> 24) & 0xFF)) {
                found = (struct fn_12_31224_Rec *)(p + 0x180);
                break;
            }
            if (*(u8 *)(p + 0x1D8) == ((arg1 >> 24) & 0xFF)) {
                found = (struct fn_12_31224_Rec *)(p + 0x1C0);
                break;
            }
            p += 0x80;
        }
    }
    if (found == 0) {
        return 0;
    }
    if (((arg1 >> 24) & 0xFF) >= 0xC0 && ((arg1 >> 24) & 0xFF) <= 0xDF) {
        cls = 0xC0;
    } else if (((arg1 >> 24) & 0xFF) >= 0xE0 && ((arg1 >> 24) & 0xFF) <= 0xEF) {
        cls = 0xE0;
    } else if (((arg1 >> 24) & 0xFF) == 0xBD || ((arg1 >> 24) & 0xFF) == 0xBF) {
        cls = 0xBD;
    } else {
        cls = 0;
    }
    if (cls == 0xE0) {
        if (found->state <= 1) {
            ok = (found->state != 0) ? 1 : 0;
        } else {
            ok = 0;
        }
    } else {
        ok = 0;
    }
    if (ok) {
        *arg2 = found->flag & 1;
        return 1;
    }
    return 0;
}
