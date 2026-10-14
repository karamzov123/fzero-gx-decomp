/* Non-matching: best partial attempt (97.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/memcard.h"

extern u32 fn_1_A6F1C(void);
extern void fn_1_3B34(void);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, const void *, u32);

void fn_1_C3378(void)
{
    Obj_1_bss_718C0_At0 *p;
    Obj_1_bss_718C0_At0 *entry;
    s16 *src;
    Obj_1_bss_718C0_At0 * p_2;
    u32 i;

    fn_80008BEC(&lbl_1_bss_718E0, 0, 0x59E0);
    lbl_1_bss_718C0.unk_0 = (Obj_1_bss_718C0_At0 *)((u8 *)&lbl_1_bss_718E0 + 0x55C2);
    lbl_1_bss_718E0.unk_1A0 = 0;
    lbl_1_bss_718E0.unk_5520 = 0;
    lbl_1_bss_718E0.unk_0 = 0;
    lbl_1_bss_718E0.unk_6 = 0;
    lbl_1_bss_718E0.unk_2 = 15;
    fn_80008BA8(lbl_1_bss_718E0.pad_8, lbl_1_data_2AC0, 0x40);
    fn_80008BA8((u8 *)&lbl_1_bss_718E0 + 0x48, lbl_1_data_2B40, 8);
    fn_80008BA8((u8 *)&lbl_1_bss_718E0 + 0x5542, &lbl_1_data_2B50, 8);
    fn_80008BA8((u8 *)&lbl_1_bss_718E0 + 0x554A, &lbl_1_data_2B58, 8);
    lbl_1_bss_718E0.unk_3 = fn_1_A6F1C();
    fn_1_3B34();
    fn_80008BA8((u8 *)&lbl_1_bss_718E0 + 0x50, lbl_1_bss_AA0, 0x150);
    fn_80008BA8((u8 *)&lbl_1_bss_718E0 + 0x5556, &lbl_1_data_2B60, 4);

    p = lbl_1_bss_718C0.unk_0;
    p->unk_4 = 50;
    p->unk_5 = 50;
    p->unk_6 = 50;
    p->unk_7 = 50;
    p_2 = lbl_1_bss_718C0.unk_0;
    entry = p_2;
    src = &lbl_1_data_3D11C.unk_0;
    for (i = 4; i != 0; i--) {
        entry->unk_10 = *src++;
        entry->unk_16 = 1;
        entry = (Obj_1_bss_718C0_At0 *)((u8 *)entry + 0x20);
    }
}
