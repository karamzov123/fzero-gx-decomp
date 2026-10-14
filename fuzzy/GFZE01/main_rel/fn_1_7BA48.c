/* Non-matching: best partial attempt (96.48% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/screen_effect.h"

extern u32 fn_800793D4(u32, int, int);

typedef struct {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u8 pad_6[0x2];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u8 pad_1A[0x2];
    u8 *unk_1C;
    u8 *unk_20;
    u8 *unk_24;
    u16 unk_28[8];
    u32 unk_38;
} Fn17BA48State;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_1_bss_6D7A8_fill_6D7A8[2];
u32 lbl_1_bss_6D7A8_8;
s32 lbl_1_bss_6D7A8_C;
u32 lbl_1_bss_6D7A8_10;
u16 lbl_1_bss_6D7A8_14;
u16 lbl_1_bss_6D7A8_16;
u16 lbl_1_bss_6D7C0;
u16 lbl_1_bss_6D7C0_fill_6D7C2;
u8 *lbl_1_bss_6D7C0_4;
u8 *lbl_1_bss_6D7C0_8;
u8 *lbl_1_bss_6D7C0_C;
u16 lbl_1_bss_6D7C0_10[8];
u32 lbl_1_bss_6D7C0_20;
u32 lbl_1_bss_6D7C0_fill_6D7E4;
u32 fzgx_obj_lbl_1_bss_6D7E8[2];
u8 fzgx_obj_lbl_1_bss_6D7F0;
u8 lbl_1_bss_6D7A8_gap_6D7F1;
u16 lbl_1_bss_6D7A8_gap_6D7F1_fill_6D7F2;
u32 fzgx_obj_lbl_1_bss_6D7F4[11];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_6D7A8_fill_6D7A8;
    s = *(u8 *)&lbl_1_bss_6D7A8_8;
    s = *(u8 *)&lbl_1_bss_6D7A8_C;
    s = *(u8 *)&lbl_1_bss_6D7A8_10;
    s = *(u8 *)&lbl_1_bss_6D7A8_14;
    s = *(u8 *)&lbl_1_bss_6D7A8_16;
    s = *(u8 *)&lbl_1_bss_6D7C0;
    s = *(u8 *)&lbl_1_bss_6D7C0_fill_6D7C2;
    s = *(u8 *)&lbl_1_bss_6D7C0_4;
    s = *(u8 *)&lbl_1_bss_6D7C0_8;
    s = *(u8 *)&lbl_1_bss_6D7C0_C;
    s = *(u8 *)&lbl_1_bss_6D7C0_10;
    s = *(u8 *)&lbl_1_bss_6D7C0_20;
    s = *(u8 *)&lbl_1_bss_6D7C0_fill_6D7E4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7E8;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7F0;
    s = *(u8 *)&lbl_1_bss_6D7A8_gap_6D7F1;
    s = *(u8 *)&lbl_1_bss_6D7A8_gap_6D7F1_fill_6D7F2;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_6D7F4;
}
#pragma section code_type ".text"

void fn_1_7BA48(u8 *arg0) {
    
    u8 *end;
    s32 i;
    u8 *pos;

    fn_800793D4((u32)arg0, 0, lbl_1_bss_6D7A8_8 + lbl_1_bss_6D7A8_C + lbl_1_bss_6D7A8_10);
    pos = arg0 + lbl_1_bss_6D7A8_8;
    end = pos + lbl_1_bss_6D7A8_C;
    (void) end;  /* fzgx: keeps the web at its definition */
    lbl_1_bss_6D7C0 = 0;
    lbl_1_bss_6D7A8_16 = 0;
    lbl_1_bss_6D7A8_14 = 0;
    lbl_1_bss_6D7C0_4 = arg0;
    lbl_1_bss_6D7C0_8 = pos;
    lbl_1_bss_6D7C0_C = end;
    lbl_1_bss_6D7C0_10[0] = 0xFFFF;
    for (i = 1; i < 8; i++) {
        (lbl_1_bss_6D7C0_10)[i] = 0xFFFF;
    }
    lbl_1_bss_6D7C0_20 = 0;
}
