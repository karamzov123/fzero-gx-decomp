/* Non-matching: best partial attempt (97.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_10_7FC0_lbl_10_bss_0 {
    u8 lab_pad[8];
    u8 pad_0[0xC];
    s32 unk_14;
};

extern struct fn_10_7FC0_lbl_10_bss_0 lbl_10_bss_0;
extern u32 lbl_10_data_744;
extern void fn_10_1B65C(void);
extern u32 fn_1_435C(u32);
extern u32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_12F1E8(u32);
extern u32 fn_1_4A00(u32, u32, u32);

#pragma opt_strength_reduction off
u32 fn_10_7FC0(u32 lab_unused0) {
    struct { u8 *value; } base;
    struct { struct fn_10_7FC0_lbl_10_bss_0 *value; } p;
    u32 t1;

    base.value = (u8 *)&lbl_10_bss_0 + 0x50000;
    p.value = (struct fn_10_7FC0_lbl_10_bss_0 *)&lbl_10_bss_0;
    fn_1_435C(*(u32 *)(base.value - 0x6c78));
    t1 = fn_1_3F8C((u32)&"SelMagCardBuyDisp", (u32)fn_10_1B65C, 0, 8);
    *(u32 *)(base.value + 0x1740) = t1;
    fn_1_12F1E8(480);
    fn_1_4A00(1, (*(s16 *)(base.value - 0x6c74) & 0xFF), *(u32 *)(base.value - 0x6c78));
    *(u32 *)(base.value + 0x1744) = 0;
    p.value->unk_14 = -1;
    return (u32)p.value;
}
#pragma opt_strength_reduction reset

