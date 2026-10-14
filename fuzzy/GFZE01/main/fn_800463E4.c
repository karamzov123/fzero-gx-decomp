/* Non-matching: best partial attempt (98.63% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_800463E4_Arg0 {
    u8 pad_0[0x7];
    s8 unk_7;
    u8 unk_8;
    u8 unk_9;
    u8 pad_A[0x2];
    s32 unk_C;
    u8 pad_10[0x1A];
    u16 unk_2A;
};

#pragma opt_loop_invariants off
#pragma opt_lifetimes on
#pragma opt_common_subs off
s32 fn_800463E4(struct fn_800463E4_Arg0 *arg0, u32 arg1, s16 *arg2, s8 *arg3, s8 *arg4, s8 *arg5,
                s8 *arg6, u32 *arg7, s32 *arg8, u32 *arg9, s16 *arg10) {
    s8 v;
    *arg2 = arg0->unk_7 << 4;
    *arg6 = (arg0->unk_9 & 3) + 1;
    *arg7 = arg0->unk_2A;
    switch (arg0->unk_8) {
    case 0:
        *arg4 = 16;
        v = *arg6;
        *arg5 = v * 2;
        *arg9 = 1;
        *arg8 = arg0->unk_C / 2;
        *arg10 = 0;
        break;
    case 1:
        *arg4 = 8;
        *arg5 = *arg6;
        *arg9 = 1;
        *arg8 = arg0->unk_C;
        *arg10 = 1;
        break;
    case 2:
    case 3:
        *arg4 = 4;
        *arg5 = *arg6;
        *arg9 = 2;
        *arg8 = ((2) * (arg0->unk_C));
        *arg10 = 2;
        break;
    }
    *arg5 = 2;
    *arg9 = 1;
    *arg8 = arg0->unk_C / 2;
    *arg4 = 16;
    *arg3 = -1;
    return 0;
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset
