/* Non-matching: best partial attempt (96.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/movie/globals.h"

extern u32 fn_5_3C44(void);
extern void fn_1_FA650(void);
extern void fn_1_4A00(s32, u8, void *);
extern int fn_1_4C10(void);
extern s16 lbl_1_bss_964;
extern s16 lbl_1_bss_968;

extern u16 (*lbl_1_bss_9F8)[10];

struct fn_5_4C8_58 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};
extern struct fn_5_4C8_58 lbl_1_bss_58;

struct fn_5_4C8_bss {
    u8 pad_0[0x2C];
    void *unk_2C;
    u8 pad_30[0x10];
    s8 unk_40;
    u8 pad_41[0x1F];
    s8 unk_60;
    u8 unk_61;
    s8 unk_62;
    u8 pad_63[3];
    s8 unk_66;
    s8 unk_67;
};

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_5_bss_0[8];
u32 lbl_5_bss_20_fill_20[3];
void *lbl_5_bss_20_C;
u32 lbl_5_bss_20_fill_30[4];
s8 lbl_5_bss_40;
u8 lbl_5_bss_40_fill_41;
u16 lbl_5_bss_40_fill_42;
u32 lbl_5_bss_40_fill_44[6];
u8 lbl_5_bss_40_fill_5C;
u8 lbl_5_bss_5D;
u8 lbl_5_bss_0_gap_5E;
u8 lbl_5_bss_5F;
s8 lbl_5_bss_0_gap_60;
u8 lbl_5_bss_61_fill_61;
s8 lbl_5_bss_61_1;
u8 lbl_5_bss_61_fill_63;
u16 lbl_5_bss_61_fill_64;
s8 lbl_5_bss_61_5;
s8 lbl_5_bss_61_6;
u32 lbl_5_bss_61_fill_68[675];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_5_bss_0;
    s = *(u8 *)&lbl_5_bss_20_fill_20;
    s = *(u8 *)&lbl_5_bss_20_C;
    s = *(u8 *)&lbl_5_bss_20_fill_30;
    s = *(u8 *)&lbl_5_bss_40;
    s = *(u8 *)&lbl_5_bss_40_fill_41;
    s = *(u8 *)&lbl_5_bss_40_fill_42;
    s = *(u8 *)&lbl_5_bss_40_fill_44;
    s = *(u8 *)&lbl_5_bss_40_fill_5C;
    s = *(u8 *)&lbl_5_bss_5D;
    s = *(u8 *)&lbl_5_bss_0_gap_5E;
    s = *(u8 *)&lbl_5_bss_5F;
    s = *(u8 *)&lbl_5_bss_0_gap_60;
    s = *(u8 *)&lbl_5_bss_61_fill_61;
    s = *(u8 *)&lbl_5_bss_61_1;
    s = *(u8 *)&lbl_5_bss_61_fill_63;
    s = *(u8 *)&lbl_5_bss_61_fill_64;
    s = *(u8 *)&lbl_5_bss_61_5;
    s = *(u8 *)&lbl_5_bss_61_6;
    s = *(u8 *)&lbl_5_bss_61_fill_68;
}
#pragma section code_type ".text"

void fn_5_4C8(void) {
    u32 flags;
    s32 f23;
    s32 f22;
    s32 f19;
    s32 f27;

    
    if (lbl_5_bss_40 == 1 || lbl_5_bss_40 == 0) {
        flags = 0;
        if (lbl_5_bss_61_6 == 1) {
            f27 = 0;
            (void) f27;  /* fzgx: keeps the web at its definition */
            f19 = 0;
            f22 = 0;
            f23 = 0;
        } else if (!(lbl_5_bss_61_1 < 0 || lbl_5_bss_61_1 >= 4)) {
            u16 t = lbl_1_bss_9F8[lbl_5_bss_61_1][4];
            f23 = (t >> 8) & 1;
            f22 = (t >> 9) & 1;
            f27 = (t >> 4) & 1;
            f19 = (t >> 12) & 1;
        } else {
            u16 t = ((0)[lbl_1_bss_9F8])[4];
            f23 = (t >> 8) & 1;
            f22 = (t >> 9) & 1;
            f27 = (t >> 4) & 1;
            f19 = (t >> 12) & 1;
        }
        if ((lbl_5_bss_0_gap_60 & 1) && f23 != 0) {
            flags |= 1;
        } else if ((lbl_5_bss_0_gap_60 & 2) && f22 != 0) {
            flags |= 2;
        } else if ((lbl_5_bss_0_gap_60 & 4) && f19 != 0) {
            flags |= 4;
        }
        if (f27 != 0) {
            lbl_5_bss_61_5 = !lbl_5_bss_61_5;
            fn_1_FA650();
        }
        if (flags != 0) {
            fn_5_3C44();
            lbl_1_bss_58.unk_1C = flags;
        }
    } else if (lbl_5_bss_40 == -1) {
        if (lbl_1_bss_964 == 15) {
            lbl_5_bss_40 = 2;
            fn_1_4A00(0, 15, lbl_5_bss_20_C);
        } else {
            fn_5_3C44();
        }
    } else if (lbl_5_bss_40 == 2) {
        if (fn_1_4C10() == 0) {
            fn_5_3C44();
        }
    } else if (lbl_5_bss_40 != 0) {
        lbl_1_bss_968 = lbl_1_bss_964;
    }
}
