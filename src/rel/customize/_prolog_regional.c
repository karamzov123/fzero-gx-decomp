/* Previously matched Japan/PAL units of _prolog.c, retained until that TU matches those releases as one unit. */
#include "types.h"
#include "rel/customize/globals.h"
extern u32 lbl_1_bss_6D82C;
extern u32 lbl_1_bss_6EAD0;
extern u8 lbl_1_bss_7F0C0[0x5360];
extern s16 lbl_1_bss_96A;
extern s32 lbl_1_bss_970;
extern u8 lbl_1_bss_9F8[];
extern s32 lbl_3_bss_120;
extern s16 lbl_3_bss_20[104];
extern u8 lbl_3_bss_20854[0xc];
extern u8 lbl_3_bss_20860[0x1100];
extern u8 lbl_3_bss_21960[10368];
extern u8 lbl_3_bss_2437C[44];
extern u32 lbl_3_bss_243A8;
extern u32 lbl_3_bss_243C0;
extern u32 lbl_3_bss_2C7C0[66624];
extern s16 lbl_3_bss_6D8C0[600];
extern u32 lbl_3_bss_6DE20;
extern u8 lbl_3_bss_7DB60[0x520];
extern u8 lbl_3_bss_7E080[0x4];
extern s32 lbl_3_bss_8;
extern s32 lbl_3_data_11D4;
extern s32 lbl_3_data_11D8;
extern char lbl_3_data_15CC[5];
extern s32 lbl_3_data_B8;
extern const char * lbl_3_data_E80[12];
extern u8 lbl_3_rodata_1A4[0xa4];
extern u8 lbl_3_rodata_F8[0xa4];
extern u32 lbl_801A6410;
extern s32 lbl_801A66B4;
extern void fn_3_8F8(void);
extern void fn_3_BA0(void);
extern void fn_3_1308C(u32, u32, u32);
extern void fn_3_11F60(u32, u32);
extern void fn_1_A0680(void);
extern void fn_1_3CF0(u32, u32);
extern void fn_1_5124(u32, u32);
extern void fn_80074CF4(f32, f32, f32);
extern void OSReport(const char *format, ...);
extern void *memset(void *, int, u32);
extern u16 fn_1_A5DB0(void);
extern u16 fn_1_A5D88(void);
extern void fn_1_411A4(u32);
extern u32 fn_1_7BA08(u16, u16, u16);
extern void fn_1_7BA48(u32);
extern s32 fn_1_465D0(const char *, s32);
extern void fn_1_545B8(void);
extern void fn_1_7BAF8(void);
extern u32 lbl_801A66C8[];
extern void fn_3_11FA0(void);
extern void fn_3_130A8(void);
extern void fn_1_3C78(void);
extern void fn_1_41A8(void);
extern void fn_1_6400(void);
extern void fn_1_8D168(void *);
extern void fn_1_412A0(u32);
extern void fn_1_56298(f32, f32, f32, f32);
extern void fn_1_A0AA4(void);
extern s32 fn_1_46DC4(s32);
extern void fn_1_53C9C(void *color, char *text, f32 x, f32 y, f32 scale, f32 spacing, f32 alpha);
extern void fn_3_968C();
extern void fn_3_60C8(void);
extern u8 fn_1_F8C50(s32);
extern void fn_3_7A30(void);
extern void fzgx_pool_f32(f32);
extern void fzgx_pool_f64(f64);
extern void fzgx_pool_addr(void *);
extern void fn_3_2BFB4(void);
extern char lbl_3_data_15D8[];
extern void fn_3_3438(void);
extern u32 fn_1_B7F08(void);
extern s32 fn_1_F7954(void);
extern void fn_3_23524(void);
extern void fn_3_78C8(s32);
extern void fn_3_BA74(void);
extern s16 fn_1_F7B80(void);

/* fzgx:begin fn_3_33A0 */
extern void fn_1_131004(void);
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_1_47F74(int value);

extern u32 lbl_3_data_BC[2];





void fn_3_33A0(void) {
    fn_1_131004();
    if (*(s32 *)lbl_3_data_BC != -1) {
        fn_1_435C(lbl_3_bss_20850);
        fn_1_426C(lbl_3_data_BC[0]);
        lbl_3_data_BC[0] = (u32)-1;
    }
    if (*(u32 *)(*(u16 (*)[24])&lbl_3_bss_F0) & ((u32)1 << 31)) {
        fn_1_47F74(0x85);
        fn_1_47F74(0xa1);
    }
    *(u32 *)(*(u16 (*)[24])&lbl_3_bss_F0) &= 0x02ffffff;
}
/* fzgx:end fn_3_33A0 */
