/* Non-matching: best partial attempt (83.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_801A6C80;

void fn_80064E84(u32 arg0, u32 arg1) {
    u16 val;
    u32 i;
    u32 n;
    u16 *p;
    u16 *row;
    u16 *arr;
    u32 n_2;
    u8 *grp;

    grp = (u8 *)(*(u32 *)((((u8 *)lbl_801A6C80) + ((((arg0 & 0xff) << 4)) + (8)))));

    if (*(u8 *)((u8 *)lbl_801A6C80 + ((arg1 & 0xff) << 5) + 0x589) & 2) {
        n = *(u32 *)((u8 *)grp + 0x28);
        if (((0) != (n))) {
            *(u32 *)((u8 *)lbl_801A6C80 + ((arg1 & 0xff) << 5) + 0x5a4) = ((n) + ((u32)grp));
        } else {
            *(u32 *)((u8 *)lbl_801A6C80 + ((arg1 & 0xff) << 5) + 0x5a4) = 0;
        }
        return;
    }

    arr = (u16 *)(((*(u32 *)((u8 *)grp + 0x1c)) + ((u8 *)grp)));
    n = *(u8 *)((u8 *)lbl_801A6C80 + ((arg1 & 0xff) << 5) + 0x58c);
    p = arr;
    for (i = 0; i <= n; i++) {
        p++;
    }
    row = (u16 *)((u8 *)arr + *p);
    p = row;
    n_2 = *(u8 *)((((((arg1 & 0xff) << 5)) + (0x58d)) + ((u8 *)lbl_801A6C80)));
    for (i = 0; i <= n_2; i++) {
        p++;
    }
    val = *p;
    if (val != 0) {
        *(u32 *)((((u8 *)lbl_801A6C80) + ((((arg1 & 0xff) << 5)) + (0x5a4)))) = val + (u32)row;
    } else {
        *(u32 *)((((u8 *)lbl_801A6C80) + ((((arg1 & 0xff) << 5)) + (0x5a4)))) = 0;
    }
}
