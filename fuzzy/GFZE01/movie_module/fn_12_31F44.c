/* Non-matching: best partial attempt (98.01% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_31F44_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
};
struct fn_12_31F44_Arg2 {
    u32 unk_0;
};

#pragma peephole off
#pragma opt_loop_invariants off
s32 fn_12_31F44(struct fn_12_31F44_Arg0 *arg0, u8 arg1, struct fn_12_31F44_Arg2 *arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6) {
    u32 v0;
    s32 v2;
    u8 *v1;
    u32 v3;
    u8 *v4;
    s32 v5;
    s32 ok;
    s32 kind_ok;
    s32 kind;
    v0 = arg0->unk_4;
    switch ((s32)arg0->unk_0) {
    case -1: case 0: case 1: ok = 0; break;
    default: ok = 1; break;
    }
    if (ok == 0) {
        ok = 0;
    } else {
        kind = (s32)arg0->unk_C;
        kind_ok = 0;
        if (kind == 107 || kind >= 110) {
            kind_ok = 1;
        }
        if (kind_ok == 0) {
            ok = 0;
        } else {
            ok = 1;
        }
    }
    if (ok == 0) {
        v1 = 0;
    } else {
        v1 = 0;
        for (v2 = 0; v2 < 26; v2++) {
            v4 = ((384) + ((u8 *)v0)) + v2 * 64;
            if (v4[24] == (u8)arg1) {
                v1 = v4;
                break;
            }
        }
    }
    if (v1 == 0) {
        return 0;
    }
    if ((u8)arg1 >= 192 && (u8)arg1 <= 223) {
        v3 = 192;
    } else if ((u8)arg1 >= 224 && (u8)arg1 <= 239) {
        v3 = 224;
    } else if ((u8)arg1 == 189 || (u8)arg1 == 191) {
        v3 = 189;
    } else {
        v3 = 0;
    }
    if (v3 != 192) {
        return 0;
    }
    if (v1[25] != 1) {
        return 0;
    }
    arg2->unk_0 = v1[26];
    return 1;
}
#pragma opt_loop_invariants reset

#pragma peephole reset
