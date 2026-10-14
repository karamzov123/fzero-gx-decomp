/* Non-matching: best partial attempt (83.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

extern u32 fn_8008FC3C(void *, u32, u32);
extern vu32 __EXIRegs[];

#pragma opt_common_subs off
s32 fn_8008FAB4(u32 arg0, u32 arg1, u32 arg2) {
    s32 v0;
    u32 loc_20;
    u32 v1;
    vu32 *v2;
    vu32 *v3;
    u32 v4;
    vu32 *v5;
    struct { u32 a[1]; } loc_24;
    v1 = arg1;
    v0 = arg2;
    v2 = __EXIRegs - 0x1A00;
    v3 = v2 + 0x1A00;
    *(v3 += 10) = (v2[0x1A0A] & 0x405) | 0xC0;
    loc_24.a[0] = ((arg0 << 8) & 0x1FFFC00) | 0x20000000;
    v4 = !fn_8008FC3C(&loc_24, 4, 1);
    do {
        v5 = __EXIRegs;
    } while (*(v5 += 13) & 1);
    while (v0 != 0) {
        v4 |= !fn_8008FC3C(&loc_20, 4, 0);
        while (*v5 & 1) {
        }
        v0 -= 4;
        *(u32 *)v1 = loc_20;
        v1 += 4;
        if (v0 < 0) {
            v0 = 0;
        }
    }
    *v3 = *v3 & 0x405;
    return !v4;
}
