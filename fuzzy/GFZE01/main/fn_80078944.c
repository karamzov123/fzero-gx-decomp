/* Non-matching: best partial attempt (48.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

void fn_80078944(u32 arg0, u32 arg1, u32 arg2, s32 arg3) {
    u32 v0;
    u16 *v1;
    s32 v2;
    u32 v3;
    s32 count;
    v0 = (0xCC000000 | 32768);
    v1 = (u16 *)arg2 - 1;
    do {
        v2 = *++v1;
        count = v2 + 1;
        *(volatile u8 *)v0 = 153;
        *(volatile u16 *)v0 = v2;
        do {
            v3 = arg1 + *++v1;
            *(volatile u32 *)v0 = *(u32 *)(v3 + 0);
            *(volatile u32 *)v0 = *(u32 *)(v3 + 4);
            *(volatile u32 *)v0 = *(u32 *)(v3 + 8);
            if (((arg0 >> 12) & 1) != 0) {
                *(volatile u32 *)v0 = *(u32 *)(v3 + 48);
            }
            if (((arg0 >> 13) & 1) != 0) {
                *(volatile u32 *)v0 = *(u32 *)(v3 + 12);
            }
            if (((arg0 >> 14) & 1) != 0) {
                *(volatile u32 *)v0 = *(u32 *)(v3 + 16);
            }
            if (((arg0 >> 15) & 1) != 0) {
                *(volatile u32 *)v0 = *(u32 *)(v3 + 20);
            }
        } while (--v2 > 0);
    } while ((arg3 -= count) > 0);
}
