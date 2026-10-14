/* Non-matching: best partial attempt (75.09% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

extern u32 fn_8008FC3C(void *, u32, u32);
extern vu32 __EXIRegs[];

u32 fn_8008F9D8(u32 arg0, u32 arg1, u32 arg2) {
    s32 v0;
    u32 v1;
    vu32 *v2;
    u32 v3;
    u32 v4;
    vu32 *v5;
    u32 v6;
    u32 v7;
    s32 v8;
    struct { u32 a[1]; } loc_24;
    u32 loc_20;
    u32 t0;
    u32 t1;
    v0 = arg2;
    v1 = arg1;
    loc_24.a[0] = ((arg0 << 8) & 0x1FFFC00) | 0xA0000000;
    v2 = __EXIRegs;
    v3 = (__EXIRegs[10] & 1029) | 192;
    *(v2 += 10) = v3;
    t0 = fn_8008FC3C(&loc_24, 4, 1);
    v7 = (u32)__cntlzw(t0) >> 5;
    do {
        v5 = __EXIRegs;
    } while (*(v5 += 13) & 1);
    while (v0 != 0) {
        loc_20 = *(u32 *)v1;
        v1 += 4;
        t1 = fn_8008FC3C(&loc_20, 4, 1);
        v7 |= (u32)__cntlzw(t1) >> 5;
        while (*v5 & 1) {}
        v0 -= 4;
        if (v0 < 0) {
            v0 = 0;
        }
    }
    *v2 = *v2 & 1029;
    return (u32)__cntlzw(v7) >> 5;
}
