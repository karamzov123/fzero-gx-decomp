/* Non-matching: best partial attempt (94.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_8_5B44_lbl_1_bss_58 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[0x2];
    u32 unk_1C;
};

extern const f32 lbl_8_rodata_8;
extern struct fn_8_5B44_lbl_1_bss_58 lbl_1_bss_58;
extern u16 lbl_1_bss_968;
extern void fn_80083DB0(void *dst, const void *src);
extern u32 lbl_1_bss_198;
extern u32 lbl_801A66B4;
extern u8 lbl_8_data_0[];

#pragma opt_dead_assignments off
void fn_8_5B44(void) {
    struct fn_8_5B44_lbl_1_bss_58 *p_lbl_1_bss_58;
    f32 scale;
    u8 *p_lbl_8_data_0;
    p_lbl_1_bss_58 = (struct fn_8_5B44_lbl_1_bss_58 *)&lbl_1_bss_58;
    scale = (1.0f);
    p_lbl_8_data_0 = (u8 *)&lbl_8_data_0;
    p_lbl_1_bss_58->unk_0 = lbl_801A66B4;
    p_lbl_1_bss_58->unk_1 = 1;
    p_lbl_1_bss_58->unk_2 = 0;
    p_lbl_1_bss_58->unk_3 = 0;
    p_lbl_1_bss_58->unk_4 = 640;
    p_lbl_1_bss_58->unk_6 = 336;
    p_lbl_1_bss_58->unk_8 = 0;
    p_lbl_1_bss_58->unk_A = 0;
    p_lbl_1_bss_58->unk_C = (1.0f);
    p_lbl_1_bss_58->unk_10 = (1.0f);
    p_lbl_1_bss_58->unk_14 = 7;
    p_lbl_1_bss_58->unk_16 = 0;
    p_lbl_1_bss_58->unk_17 = -1;
    p_lbl_1_bss_58->unk_18 = 336;
    p_lbl_1_bss_58->unk_1C = 0;
    if ((s32)p_lbl_1_bss_58->unk_15 == 2) {
    fn_80083DB0(&lbl_1_bss_198, p_lbl_8_data_0 + 0x7e2c);
    } else {
    fn_80083DB0(&lbl_1_bss_198, p_lbl_8_data_0 + 0x7e3c);
    }
    fn_80083DB0((u8 *)&lbl_1_bss_198 + 0x40, p_lbl_8_data_0 + 0x7e4c);
    p_lbl_1_bss_58->unk_14 = 4;
    p_lbl_1_bss_58->unk_16 = 1;
    p_lbl_1_bss_58->unk_17 = 0;
    lbl_1_bss_968 = 8;
}
#pragma opt_dead_assignments reset

