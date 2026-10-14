/* Non-matching: best partial attempt (60.42% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"

extern u32 fn_8008FC3C(void *, u32, u32);
extern vu32 __EXIRegs[];

u32 fn_8008F92C(u32 *arg0) {
    void *v0;
    vu32 *v1;
    u32 v2;
    vu32 *v3;
    struct { u32 a[3]; } loc_18;
    u32 t0;
    u32 t1;
    v0 = arg0;
    v1 = __EXIRegs;
    *(v1 += 10) = (__EXIRegs[10] & 0x405) | 0xC0;
    loc_18.a[0] = 0x40000000;
    t0 = fn_8008FC3C(&loc_18, 2, 1);
    v2 = (u32)__cntlzw(t0) >> 5;
    do {
        v3 = __EXIRegs;
    } while (*(v3 += 13) & 1);
    t1 = fn_8008FC3C(v0, 4, 0);
    v2 |= (u32)__cntlzw(t1) >> 5;
    while (*v3 & 1) {}
    *v1 = *v1 & 0x405;
    return (u32)__cntlzw(v2) >> 5;
}
