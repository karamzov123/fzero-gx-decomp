/* Non-matching: best partial attempt (89.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_800927BC[];
extern u8 lbl_80190C78[];
extern void fn_8005C120(u32 arg0);
extern void *memset(void *dst, int c, u32 n);

struct fn_8005BDD4_bss {
    u32 field_0;
    u32 field_4;
    u8  pad[0x8C];
    u8  field_94[0x1040];
    u8  field_10d4[0xE80];
};

void fn_8005BDD4(void) {
    struct fn_8005BDD4_bss *p = (struct fn_8005BDD4_bss *)lbl_80190C78;
    u32 arg0 = *(u32 *)lbl_800927BC;

    if (p->field_0 == 0) {
        fn_8005C120(arg0);
        memset(p->field_10d4, 0, 0xe80);
        p->field_4 = (u32)((u8 *)p->field_94 + 0x1f) & 0xFFFFFFE0;
    }
    p->field_0 = p->field_0 + 1;
}
