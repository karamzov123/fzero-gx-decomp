/* Non-matching: best partial attempt (96.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_320A0_Arg0 {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
};

struct fn_12_320A0_Arg2 {
    u32 unk_0;
};

#pragma peephole off
#pragma opt_lifetimes off
#pragma opt_loop_invariants off
s32 fn_12_320A0(struct fn_12_320A0_Arg0 *arg0, u32 arg1, struct fn_12_320A0_Arg2 *arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6) {
    s32 kind_ok;
    u8 * rec_2;
    s32 kind;
    s32 ok;
    u8 *found;
    u8 *rec;
    u8 *movie = (u8 *)arg0->unk_4;
    s32 i;
    u32 category;

    switch ((s32)arg0->unk_0) {
    case -1:
    case 0:
    case 1:
        ok = 0;
        break;
    default:
        ok = 1;
        break;
    }
    if (ok == 0) {
        ok = 0;
    } else {
        kind = arg0->unk_C;
        kind_ok = 0;
        if (kind == 0x6b || kind >= 0x6e) {
            kind_ok = 1;
        }
        if (!(kind_ok != 0)) {
            ok = 0;
        } else {
            ok = 1;
        }
    }
    if (ok == 0) {
        found = 0;
    } else {
        found = 0;
        for (i = 0; i < 13; i++, movie += 0x80) {
            rec = movie + 0x180;
            if (rec[0x18] == (u8)(arg1 & 0xff)) {
                found = rec;
                break;
            }
            rec_2 = movie + 0x1c0;
            if (rec_2[0x18] == (u8)(arg1 & 0xff)) {
                found = rec_2;
                break;
            }
        }
    }
    if (!(found)) {
        return 0;
    }
    if ((arg1 & 0xff) >= 0xc0 && (arg1 & 0xff) <= 0xdf) {
        category = 0xc0;
    } else if ((arg1 & 0xff) >= 0xe0 && (arg1 & 0xff) <= 0xef) {
        category = 0xe0;
    } else if ((arg1 & 0xff) == 0xbd || (arg1 & 0xff) == 0xbf) {
        category = 0xbd;
    } else {
        category = 0;
    }
    if (category != 0xc0) {
        return 0;
    }
    arg2->unk_0 = found[0x19];
    return 1;
}
#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset
#pragma peephole reset
