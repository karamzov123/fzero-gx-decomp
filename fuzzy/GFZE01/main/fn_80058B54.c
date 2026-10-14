/* Non-matching: best partial attempt (95.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

extern void *memset(void *, int, u32);

#pragma opt_common_subs off
void fn_80058B54(void) {
    Obj_8018FEB0 *p = &lbl_8018FEB0;
    u32 *q;
    p->unk_0--;
    if (*(volatile u32 *)&p->unk_0 == 0) {
{
    u32 lab_t2;
        lab_t2 = 0x20;
        memset((u8 *)p + 0x288, 0, lab_t2);
        lab_t2 = 8;
        memset((u8 *)p + 0xC0, 0, lab_t2);
        lab_t2 = 8;
        memset((u8 *)p + 0xB8, 0, lab_t2);
        q = (u32 *)((u8 *)p + 0x2A8);
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q[4] = 0;
        q[5] = 0;
        p->unk_2C = 0;
        lab_t2 = 8;
        memset((u8 *)p + 0x2A8, 0, lab_t2);
}
    }
}
#pragma opt_common_subs reset

