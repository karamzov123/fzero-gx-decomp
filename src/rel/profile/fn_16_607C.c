#include "types.h"

struct fn_16_607C_lbl_16_rodata_1DC {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};
struct fn_16_607C_lbl_801A6D00 {
    u32 unk_0;
};
struct fn_16_607C_lbl_16_rodata_AC {
    f32 unk_0;
};
struct fn_16_607C_lbl_1_bss_8B614 {
    u8 pad_0[0x30];
    s16 unk_30;
};

extern struct fn_16_607C_lbl_16_rodata_1DC lbl_16_rodata_1DC;
extern struct fn_16_607C_lbl_16_rodata_AC lbl_16_rodata_AC;
extern struct fn_16_607C_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern struct fn_16_607C_lbl_801A6D00 lbl_801A6D00;
extern u32 fn_1_12CB04(s16);
extern u32 fn_1_8E728(void *, u32);
extern u32 lbl_1_data_1E5C0;
extern void fn_1_9250C(void *);
extern void fn_1_F7870(u32);
extern void fn_8006F038(void *, void *, s16);
extern void fn_80072558(void);
extern void lbl_8006D7DC(void *);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCDC(void);
extern void lbl_8006DFE8(void *);

s32 fn_16_607C(u32 arg0) {
    struct fn_16_607C_lbl_1_bss_8B614 *p_lbl_1_bss_8B614;
    struct fn_16_607C_lbl_16_rodata_1DC loc_8;
    u32 elem;
    s16 i;
    f32 v2;
    f32 v3;

    fn_8006F038((void *)(arg0 + 52), (void *)(arg0 + 64), 0);
    lbl_8006DCDC();
    fn_1_F7870((u32)&lbl_1_data_1E5C0);
    loc_8 = lbl_16_rodata_1DC;
    lbl_8006D7DC(&loc_8);
    lbl_8006DB74((void *)(lbl_801A6D00.unk_0 + 96));
    lbl_8006DFE8((void *)(lbl_801A6D00.unk_0 + 96));
    fn_80072558();
    v2 = lbl_16_rodata_AC.unk_0;
    p_lbl_1_bss_8B614 = (struct fn_16_607C_lbl_1_bss_8B614 *)&lbl_1_bss_8B614;
    *(f32 *)((u8 *)arg0 + 284) = v2;
    *(f32 *)((u8 *)arg0 + 288) = v2;
    *(f32 *)((u8 *)arg0 + 292) = v2;
    fn_1_8E728((void *)(arg0 + 116), (p_lbl_1_bss_8B614->unk_30 & 0xFF));
    fn_1_9250C((void *)(arg0 + 116));
    v3 = lbl_16_rodata_AC.unk_0;
    elem = arg0;
    i = 0;
    while (i < (s16)fn_1_12CB04(*(s16 *)(arg0 + 12))) {
        *(f32 *)((u8 *)elem + 1540) = v3;
        *(f32 *)((u8 *)elem + 1544) = v3;
        *(f32 *)((u8 *)elem + 1548) = v3;
        fn_1_8E728((void *)(elem + 1372), (p_lbl_1_bss_8B614->unk_30 & 0xFF));
        fn_1_9250C((void *)(elem + 1372));
        elem += 1256;
        i++;
    }
    return 0;
}
