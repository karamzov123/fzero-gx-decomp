/* Non-matching: best partial attempt (37.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
void __dcbi(void *, int);

extern u32 lbl_12_bss_528C[25];
extern void fn_12_20184(void);

void fn_12_D038(void) {
    u32 v0;
    s32 v1;
    void *base;
    u32 flags;
    fn_12_20184();
    flags = lbl_12_bss_528C[18];
    base = (void *)lbl_12_bss_528C[20];
    if ((flags & 0x10000000) != 0) {
        v1 = 0;
        for (v0 = 13; v0 != 0; v0--) {
            __dcbi(base, v1);
            v1 += 32;
            __dcbi(base, v1);
            v1 += 32;
            __dcbi(base, v1);
            v1 += 32;
            __dcbi(base, v1);
            v1 += 32;
            __dcbi(base, v1);
            v1 += 32;
            __dcbi(base, v1);
            v1 += 32;
            __dcbi(base, v1);
            v1 += 32;
        }
    }
}
