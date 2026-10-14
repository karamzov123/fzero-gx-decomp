/* Non-matching: best partial attempt (97.74% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/replay.h"
extern s8 fn_1_86624(void);
extern void *fn_1_86254(int);
extern void fn_80008BEC(u8 *, int, u32);
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_7EFD8_fill_7EFD8[4];
s32 lbl_1_bss_7EFD8_10;
u32 lbl_1_bss_7EFD8_14;
u32 lbl_1_bss_7EFD8_fill_7EFF0[4];
s16 lbl_1_bss_7EFD8_28;
u32 lbl_1_bss_7EFD8_fill_7F004[5];
Obj_1_bss_7EFD8_At40 *lbl_1_bss_7EFD8_40;
u16 fzgx_obj_lbl_1_bss_7F01C;
u16 lbl_1_bss_7EFD8_gap_7F01E;
u32 fzgx_obj_lbl_1_bss_7F020[2];
u8 fzgx_obj_lbl_1_bss_7F028;
u8 lbl_1_bss_7EFD8_gap_7F029;
u16 lbl_1_bss_7EFD8_gap_7F029_fill_7F02A;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_7EFD8_fill_7EFD8;
    s = *(u8 *)&lbl_1_bss_7EFD8_10;
    s = *(u8 *)&lbl_1_bss_7EFD8_14;
    s = *(u8 *)&lbl_1_bss_7EFD8_fill_7EFF0;
    s = *(u8 *)&lbl_1_bss_7EFD8_28;
    s = *(u8 *)&lbl_1_bss_7EFD8_fill_7F004;
    s = *(u8 *)&lbl_1_bss_7EFD8_40;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7F01C;
    s = *(u8 *)&lbl_1_bss_7EFD8_gap_7F01E;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7F020;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_7F028;
    s = *(u8 *)&lbl_1_bss_7EFD8_gap_7F029;
    s = *(u8 *)&lbl_1_bss_7EFD8_gap_7F029_fill_7F02A;
}
#pragma section code_type ".text"

#pragma opt_common_subs off
void fn_1_F38C0(u32 lab_unused0, u32 lab_unused1) {
    struct { s32 value; } zero1;
    struct { s16 value; } zero2;
    s32 count;
    u8 *p;
    s32 i;
    u8 *entries;
    struct { s8 value; } value;
    
    entries = (u8 *)lbl_1_bss_7EFD8_40 + 0xa4;
    lbl_1_bss_7EFD8_10 = 9300;
    lbl_1_bss_7EFD8_14 = 0xd9f8;
    fn_80008BEC((u8 *)&lbl_1_bss_7EFD8_28, 0, 16);
{
    s8 tmp_call1;
    tmp_call1 = fn_1_86624();
    count = tmp_call1;
}
    if ((s8)fn_1_86624() > 4) count = 4;
    {
    u8 * fzgx_loop_p_1843;
for (fzgx_loop_p_1843 = entries; fzgx_loop_p_1843 < entries + count * 7; fzgx_loop_p_1843 += 7) {
        (&lbl_1_bss_7EFD8.unk_28)[*fzgx_loop_p_1843 & 3] = 1;
    }
    p = fzgx_loop_p_1843;
}
    zero2.value = zero1.value = i = 0;
    for (; i < 4; i++) {
        if ((s32)(&lbl_1_bss_7EFD8.unk_28)[i] != 0) {
            value.value = (s8)lbl_1_bss_7EFD8_40->unk_A0;
            *((s8 *)fn_1_86254(i) + 0x474) = value.value;
            lbl_1_bss_7EFD8_40->unk_A0 = lbl_1_bss_7EFD8_40->unk_A0 + 1;
        }
        (&lbl_1_bss_7EFD8.unk_1C)[i] = zero1.value;
        (&lbl_1_bss_7EFD8.unk_20)[i] = zero2.value;
    }
    lbl_1_bss_7EFD8_40->unk_A0--;
    lbl_1_bss_7EFD8.unk_1A = 0;
    lbl_1_bss_7EFD8.unk_1B = 0;
}
#pragma opt_common_subs reset
