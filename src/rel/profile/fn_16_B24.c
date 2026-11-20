#include "types.h"

struct fn_16_B24_lbl_16_bss_150 {
    u32 unk_0;
};
struct fn_16_B24_lbl_16_bss_B060 {
    u16 unk_0[41];
};
struct fn_16_B24_lbl_1_bss_8B614 {
    u8 pad_0[0xC];
    s16 unk_C;
    u8 pad_E[0x22];
    u16 unk_30;
    u8 pad_32[0x1A];
    u32 unk_4C;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
};
struct fn_16_B24_lbl_1_bss_6EAD0 {
    u32 unk_0;
};

extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern struct fn_16_B24_lbl_16_bss_150 lbl_16_bss_150;
extern struct fn_16_B24_lbl_16_bss_B060 lbl_16_bss_B060;
extern struct fn_16_B24_lbl_1_bss_6EAD0 lbl_1_bss_6EAD0;
extern struct fn_16_B24_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern u16 lbl_16_bss_B0B2;
extern void fn_16_4E90(void);
extern u32 fn_1_435C(u32);
extern u32 fn_1_4A00(u32, u32, u32);
extern u32 fn_1_A1588(u32, u32);
extern u32 fn_1_F7BE4(u32);
extern u32 lbl_16_bss_21C;
extern u32 lbl_16_bss_B0B4;
extern u32 lbl_16_data_82B00;
extern u32 lbl_16_data_82D3C;

void fn_16_B24(void) {
    struct fn_16_B24_lbl_16_bss_B060 *p_lbl_16_bss_B060;
    s32 v1;
    s32 v2;
    s16 v4;
    u32 v6;
    u32 t2;
    u32 t3;

    fn_1_435C(lbl_16_bss_150.unk_0);
    fn_1_4A00(1, 15, lbl_16_bss_150.unk_0);
    lbl_16_bss_B0B4 = 0;
    t2 = fn_1_3F8C((u32)&lbl_16_data_82D3C, (u32)fn_16_4E90, 0, 8);
    lbl_16_data_82B00 = t2;
    lbl_16_bss_21C = -1;
    v1 = 0;
    t3 = fn_1_F7BE4(30);
    if ((s32)t3 != 0) {
        lbl_16_bss_B060.unk_0[(s16)v1++] = 30;
    }
    p_lbl_16_bss_B060 = &lbl_16_bss_B060;
    v2 = 0;
    while ((u32)(s16)v2 < 41) {
        if ((s16)v2 != 30 && (s32)fn_1_F7BE4(v2) != 0) {
            v4 = v1;
            v1++;
            p_lbl_16_bss_B060->unk_0[v4] = v2;
        }
        v2++;
    }
    lbl_16_bss_B0B2 = v1;
    if (lbl_1_bss_8B614.unk_C == -1) {
        lbl_1_bss_8B614.unk_C = 6;
    }
    lbl_1_bss_8B614.unk_4C = 0;
    lbl_1_bss_8B614.unk_4C |= 0x80000000;
    v6 = lbl_1_bss_6EAD0.unk_0;
    lbl_1_bss_8B614.unk_4C |= 0x10000000;
    lbl_1_bss_8B614.unk_50 = 1;
    lbl_1_bss_8B614.unk_52 = 0;
    lbl_1_bss_8B614.unk_54 = 15;
    lbl_1_bss_8B614.unk_30 = 0;
    fn_1_A1588(*(u32 *)((u8 *)v6), 32);
}
