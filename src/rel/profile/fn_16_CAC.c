#include "types.h"
struct fn_16_CAC_lbl_16_bss_21C {
    s32 unk_0;
};
struct fn_16_CAC_lbl_1_bss_8B614 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x44];
    u32 unk_4C;
};
struct fn_16_CAC_lbl_16_bss_150 {
    u32 unk_0;
};
extern struct fn_16_CAC_lbl_16_bss_150 lbl_16_bss_150;
extern struct fn_16_CAC_lbl_16_bss_21C lbl_16_bss_21C;
extern struct fn_16_CAC_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern u16 lbl_1_bss_96A;
extern u32 lbl_16_bss_B0B4;
extern int fn_1_4C10(void);

s16 fn_16_E20();                                    /* extern */
s32 fn_1_4A00(s32, s32, u32);           /* extern */

void fn_16_CAC(void) {
    s16 temp_r3;
    s32 var_r0;
    u32 temp_r4;

    if (lbl_16_bss_21C.unk_0 == -1) {
        fn_1_4C10();
    }
    if ((lbl_1_bss_8B614.unk_4C & 0x80000000) && !(lbl_1_bss_8B614.unk_4C & 1) && !(lbl_1_bss_8B614.unk_4 & 0x10000000)) {
        var_r0 = 1;
    } else if (fn_1_4C10() != 0) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }
    if (var_r0 == 0) {
        if (lbl_16_bss_21C.unk_0 != -1) {
            temp_r4 = lbl_16_bss_21C.unk_0;
            lbl_16_bss_21C.unk_0 = -1U;
            (*((&lbl_1_bss_96A))) = temp_r4;
            return;
        }
        temp_r3 = fn_16_E20();
        if (temp_r3 != 0) {
            fn_1_4A00(0, 0xF, lbl_16_bss_150.unk_0);
            (*((&lbl_16_bss_B0B4))) = 0;
        }
        if (temp_r3 == -1) {
            lbl_1_bss_8B614.unk_4 |= 0x80000000;
        }
        if (temp_r3 == 1) {
            lbl_16_bss_21C.unk_0 = 0xC0;
        }
    }
}
