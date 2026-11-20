#include "types.h"
struct fn_16_2054_lbl_16_bss_220_0_E1088 {
    u8 pad_0[0x324];
    u32 unk_324;
    u8 pad_328[0x118];
};
struct fn_16_2054_lbl_16_data_82B00 {
    u32 unk_0;
};
struct fn_16_2054_lbl_16_bss_150 {
    u32 unk_0;
};
struct fn_16_2054_lbl_1_bss_8B614 {
    u8 pad_0[0xC];
    s16 unk_C;
};
struct fn_16_2054_lbl_16_data_82B54 {
    u32 unk_0[1];
};
struct fn_16_2054_lbl_16_bss_220 {
    struct fn_16_2054_lbl_16_bss_220_0_E1088 unk_0[1];
};
extern struct fn_16_2054_lbl_16_bss_150 lbl_16_bss_150;
extern struct fn_16_2054_lbl_16_bss_220 lbl_16_bss_220;
extern struct fn_16_2054_lbl_16_data_82B00 lbl_16_data_82B00;
extern struct fn_16_2054_lbl_16_data_82B54 lbl_16_data_82B54;
extern struct fn_16_2054_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern u32 fn_1_435C(u32);
extern void fn_1_48140(int);
extern void fn_1_80F1C(s32, void *);


s32 fn_1_426C(u32);                             /* extern */

void fn_16_2054(void) {
    struct fn_16_2054_lbl_16_bss_220 *temp_r4;

    if ((s32) lbl_16_data_82B00.unk_0 != -1) {
        fn_1_435C((lbl_16_bss_150.unk_0));
        fn_1_426C((lbl_16_data_82B00.unk_0));
        lbl_16_data_82B00.unk_0 = -1U;
    }
    fn_1_48140((*(s32 *)&((&lbl_16_data_82B54)[lbl_1_bss_8B614.unk_C])));
    temp_r4 = (struct fn_16_2054_lbl_16_bss_220 *)(&(&lbl_16_bss_220)[lbl_1_bss_8B614.unk_C]);
    fn_1_80F1C(((s16) temp_r4->unk_0[0].unk_324), (void *)(temp_r4));
}
