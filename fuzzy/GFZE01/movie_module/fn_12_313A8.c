/* Non-matching: best partial attempt (86.44% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_313A8_Item {
    u8 pad_0[0x18];
    u8 id;
    u8 pad_1[7];
    u8 flag;
    u8 pad_2;
    u8 value;
    u8 pad_3[0x1D];
};

struct fn_12_313A8_Table {
    u8 pad_0[0x180];
    struct fn_12_313A8_Item first;
    struct fn_12_313A8_Item second;
};

struct fn_12_313A8_Arg0 {
    s32 unk_0;
    struct fn_12_313A8_Table *unk_4;
    u32 unk_8;
    s32 unk_C;
};

#pragma peephole off
#pragma opt_strength_reduction off
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_dead_assignments off
s8 fn_12_313A8(struct fn_12_313A8_Arg0 *arg0, u32 arg1, u32 *arg2) {
    struct fn_12_313A8_Item *res;
    s32 f1_2;
    u32 i;
    struct fn_12_313A8_Table *t;
    struct fn_12_313A8_Table *base = arg0->unk_4;
    s32 f1;
    s32 ok;
    u8 f;
    u32 c;

    if (arg0->unk_0 < 2) {
        if (arg0->unk_0 < -1) {
            f1 = 1;
        } else {
            f1_2 = 0;
        }
    } else {
        f1_2 = 1;
    }
    if (((0) == (f1_2))) {
        ok = 0;
    } else {
        s32 t0 = arg0->unk_C;
        ok = (((0x6B) == (t0))) || (t0 >= 0x6E);
    }
    if (((0) == (ok))) {
        res = 0;
    } else {
        res = 0;
        for (i = 0; i < 13; i++) {
            t = (struct fn_12_313A8_Table *)((u8 *)base + i * 0x1);
            if ((((arg1 & 0xFF)) == (t->first.id))) {
                res = &t->first;
                break;
            }
            if (((((t->second.id)) == (((arg1 & 0xFF)))))) {
                res = &t->second;
                break;
            }
        }
    }
    if (((0) == (res))) {
        return 0;
    }
    c = arg1 & 0xFF;
    if (c >= 0xC0 && c <= 0xDF) {
        c = 0xC0;
    } else if (c >= 0xE0 && c <= 0xEF) {
        c = 0xE0;
    } else if (((0xBD) == (c)) || ((0xBF) == (c))) {
        c = 0xBD;
    } else {
        c = 0;
    }
    if (c != 0xE0) {
        ok = 0;
    } else {
        f = res->flag;
        if (f > 1) {
            ok = 0;
        } else if (((0) == (f))) {
            ok = 0;
        } else {
            ok = 1;
        }
    }
    if (((0) == (ok))) {
        return 0;
    }
    *arg2 = res->value;
    return 1;
}
#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset

#pragma opt_common_subs reset

#pragma opt_strength_reduction reset

#pragma peephole reset

