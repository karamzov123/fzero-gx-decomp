#include "types.h"

struct fn_16_1F1C_lbl_1_bss_8B614 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x44];
    u32 unk_4C;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
};

extern struct fn_16_1F1C_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern u32 lbl_16_bss_21C;
extern u16 lbl_1_bss_96A;
extern u32 lbl_16_bss_150;
extern u32 lbl_16_bss_B0B4;
extern int fn_1_4C10(void);
extern u32 fn_16_20F4(void);
extern u32 fn_1_4A00(u32, u32, u32);

#pragma opt_common_subs off
void fn_16_1F1C(void) {
    struct fn_16_1F1C_lbl_1_bss_8B614 *p;
    s32 v;
    u32 v0;
    s32 b;
    u32 v2;

    if ((s32)lbl_16_bss_21C == -1) {
        fn_1_4C10();
    }
    p = (struct fn_16_1F1C_lbl_1_bss_8B614 *)&lbl_1_bss_8B614;
    v0 = p->unk_4C;
    if ((v0 & 0x80000000) != 0 && (v0 & 0x1) == 0 && (p->unk_4 & 0x10000000) == 0) {
        b = 1;
    } else if (fn_1_4C10() != 0) {
        b = 1;
    } else {
        b = 0;
    }
    if (b == 0) {
        if ((s32)lbl_16_bss_21C != -1) {
            v2 = lbl_16_bss_21C;
            lbl_16_bss_21C = -1;
            lbl_1_bss_96A = v2;
        } else {
            v = fn_16_20F4();
            if ((s16)v != 0) {
                fn_1_4A00(0, 15, lbl_16_bss_150);
                p->unk_4C = 0;
                p->unk_4C |= 0x80000000;
                lbl_16_bss_B0B4 = 0;
                p->unk_4C |= 0x08000000;
                lbl_1_bss_8B614.unk_50 = 1;
                lbl_1_bss_8B614.unk_52 = 0;
                lbl_1_bss_8B614.unk_54 = 15;
            }
            if ((s16)v == -1) {
                lbl_16_bss_21C = 192;
            }
        }
    }
}
#pragma opt_common_subs reset

