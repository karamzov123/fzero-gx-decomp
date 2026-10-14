/* Non-matching: best partial attempt (97.78% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_80056584_lbl_801878B8 {
    u32 pad_0[3];
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0xFA0];
    u32 unk_FB4;
};

extern u32 lbl_801878B8[3];
extern u32 lbl_80132260[];
extern u32 lbl_80188870[];
extern void *memset(void *, int, u32);

#pragma opt_deadstores off
void *fn_80056584(void) {
    struct { struct fn_80056584_lbl_801878B8 *value; } p_lbl_801878B8;
    p_lbl_801878B8.value = (struct fn_80056584_lbl_801878B8 *)&lbl_801878B8;
    /* Preserve the observed read/write of the manager word. */
    *(volatile u32 *)&p_lbl_801878B8.value->unk_FB4 = p_lbl_801878B8.value->unk_FB4;
    memset((void *)&lbl_80188870, 0, 256);
    p_lbl_801878B8.value->unk_10 = 0;
    p_lbl_801878B8.value->unk_C = 0;
    memset(p_lbl_801878B8.value->pad_0, 0, 12);
    return &lbl_80132260;
}
