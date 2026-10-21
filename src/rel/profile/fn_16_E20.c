#include "types.h"

/* Flag words that retail reloads on every read. */
struct fn_16_E20_entry {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    volatile u16 unk_8; // fzgx-allow: S2 retail reloads this field on every read
    u16 unk_A;
    u8 pad_C[4];
    volatile u16 unk_10; // fzgx-allow: S2 retail reloads this field on every read
    volatile u16 unk_12; // fzgx-allow: S2 retail reloads this field on every read
};
struct fn_16_E20_state {
    u8 pad_0[8];
    s16 unk_8;
    u16 unk_A;
    s16 unk_C;
    u8 pad_E[0x3E];
    u32 unk_4C;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
};
extern struct fn_16_E20_state lbl_1_bss_8B614;
extern struct fn_16_E20_entry lbl_1_bss_9F8[];
extern s16 lbl_16_bss_B060[41];
extern s16 lbl_16_bss_B0B2;
extern void fn_1_A2D84(u32);
extern s32 fn_1_F7BE4(s16);

s32 fn_16_E20(void) {
    s16 idx;
    s16 v;
    s16 i;
    s16 found;
    s32 t;
    s32 max;

    idx = lbl_1_bss_8B614.unk_8;
    v = 0;
    if ((lbl_1_bss_9F8[idx].unk_10 & 1) || (lbl_1_bss_9F8[idx].unk_12 & 1)) {
        v = -1;
    }
    if (((lbl_1_bss_9F8[idx].unk_10 >> 1) & 1) || ((lbl_1_bss_9F8[idx].unk_12 >> 1) & 1)) {
        v++;
    }
    if (v != 0) {
        fn_1_A2D84(0xA9010000);
        if (v < 0) {
            lbl_1_bss_8B614.unk_4C = 0;
            lbl_1_bss_8B614.unk_4C |= 0x80000000;
            lbl_1_bss_8B614.unk_50 = v;
            lbl_1_bss_8B614.unk_4C |= 0x20000001;
            lbl_1_bss_8B614.unk_52 = 0;
            lbl_1_bss_8B614.unk_54 = v * 5;
        } else {
            lbl_1_bss_8B614.unk_4C = 0;
            lbl_1_bss_8B614.unk_4C |= 0x80000000;
            lbl_1_bss_8B614.unk_50 = v;
            lbl_1_bss_8B614.unk_4C |= 0x40000001;
            lbl_1_bss_8B614.unk_52 = 0;
            lbl_1_bss_8B614.unk_54 = v * 5;
        }
        for (i = 0; i < 41; i++) {
            if (lbl_16_bss_B060[i] == lbl_1_bss_8B614.unk_C) {
                found = i;
                break;
            }
        }
        do {
            max = lbl_16_bss_B0B2 - 1;
            t = found + v;
            found = (t > max) ? 0 : ((t < 0) ? max : t);
        } while (fn_1_F7BE4(lbl_16_bss_B060[found]) == 0);
        lbl_1_bss_8B614.unk_C = lbl_16_bss_B060[found];
    }
    if ((lbl_1_bss_9F8[idx].unk_8 >> 9) & 1) {
        fn_1_A2D84(0xA9010200);
        return -1;
    }
    if ((lbl_1_bss_9F8[idx].unk_8 >> 8) & 1) {
        fn_1_A2D84(0xA9010100);
        return 1;
    }
    return 0;
}
