/* Non-matching: best partial attempt (98.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern struct fn_4_467C_lbl_4_bss_0 lbl_4_bss_0;
extern u32 lbl_801A66B4;
extern void fn_4_2D4(u8, u32);
extern void fn_4_40C4(u8, u32);
extern void fn_1_1380F0(u32);
extern void fn_1_13ABA8(u32);

u32 lbl_4_data_0[0x3A] = {1};
u32 tab_E8[0xC0] = {1};
u32 tab_3E8[0x20] = {1};
u32 tab_468[0xF1] = {1};
u32 tab_82C[6] = {1};
u32 tab_844[0x10] = {1};
u32 tab_884[0x40] = {1};

struct fn_4_467C_lbl_4_bss_0 {
    u16 unk_0;
    u8 pad_2[0x2];
    s32 unk_4;
    u32 unk_8;
    u8 pad_C[0x4];
    u16 unk_10;
    u8 pad_12[0xA8];
    u8 unk_BA;
    u8 unk_BB;
    u8 unk_BC;
    u8 unk_BD;
    s8 unk_BE;
    u8 unk_BF;
    u16 unk_C0;
};

void fn_4_467C(void) {
    struct fn_4_467C_lbl_4_bss_0 *p_lbl_4_bss_0;
    u32 t0, t1, t2;

    p_lbl_4_bss_0 = (struct fn_4_467C_lbl_4_bss_0 *)&lbl_4_bss_0;

    switch (p_lbl_4_bss_0->unk_BB) {
    case 0:
    default:
        t0 = tab_3E8[lbl_801A66B4];
        t1 = tab_82C[lbl_801A66B4];
        t2 = 0x28000000;
        break;
    case 1:
        t0 = tab_468[lbl_801A66B4];
        t1 = tab_844[lbl_801A66B4];
        t2 = 0x20000000;
        break;
    case 2:
        t0 = tab_E8[lbl_801A66B4];
        t1 = tab_884[lbl_801A66B4];
        fn_4_2D4(p_lbl_4_bss_0->unk_BC, t1);
        t1 = tab_82C[lbl_801A66B4];
        t2 = 0x48000000;
        break;
    }

    fn_4_40C4(p_lbl_4_bss_0->unk_BD, t1);
    fn_1_1380F0(t0);
    fn_1_13ABA8(t2);
}
