/* Non-matching: best partial attempt (96.42% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

extern void * memset(void *, int, u32);

static void fn_80058BFC_clear6(u32 *q) {
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
    q[4] = 0;
    q[5] = 0;
}

void fn_80058BFC(void) {
    Obj_8018FEB0 *p;
    u32 v;

    p = (Obj_8018FEB0 *)&lbl_8018FEB0;
    if ((s32)p->unk_0 == 0) {
        memset((void *)((u8 *)p + 0x288), 0, 0x20);
        memset((void *)((u8 *)p + 0xC0), 0, 8);
        memset((void *)((u8 *)p + 0xB8), 0, 8);
        fn_80058BFC_clear6((u32 *)((u8 *)p + 0x2A8));
        p->unk_2C = 0;
    }
    v = p->unk_0;
    p->unk_0 = v + 1;
}
