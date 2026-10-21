#include "types.h"

/* MPVVLC_Init (mpv_vlc.c, CRI Sofdec MPEG video VLC tables). Every object of the
 * TU is defined here under its retail name so the code reaches it off the section
 * bases like retail; names follow mpv_vlc.c in the comments. */

#define MPVVLC_VLC_AREA_SIZE 0x5B0

static const u32 lbl_12_rodata_938[8] = { /* mpvvlt_run_level_0c */
    0x12011101, 0x10010F01, 0x03060210, 0x020F020E, 0x020D020C, 0x020B011F, 0x011E011D, 0x011C011B,
};
static const u32 lbl_12_rodata_938__fzgx_offset_20[8] = { /* mpvvlt_run_level_0b */
    0x28002700, 0x26002500, 0x24002300, 0x22002100, 0x20000E01, 0x0D010C01, 0x0B010A01, 0x09010801,
};
static const u32 lbl_12_rodata_938__fzgx_offset_40[8] = { /* mpvvlt_run_level_0a */
    0x1F001E00, 0x1D001C00, 0x1B001A00, 0x19001800, 0x17001600, 0x15001400, 0x13001200, 0x11001000,
};
static const u32 lbl_12_rodata_938__fzgx_offset_60[8] = { /* mpvvlt_run_level_1 */
    0x020A0209, 0x03050403, 0x05020701, 0x06010F00, 0x0E000D00, 0x0C00011A, 0x01190118, 0x01170116,
};
static const u32 lbl_12_rodata_938__fzgx_offset_80[8] = { /* mpvvlt_run_level_2 */
    0x0B000208, 0x03040A00, 0x04020207, 0x01150114, 0x09000113, 0x01120501, 0x03030800, 0x02060111,
};
static const u32 lbl_12_rodata_938__fzgx_offset_A0[4] = { /* mpvvlt_run_level_4 */
    0x01100205, 0x07000302, 0x0401010F, 0x010E0204,
};

static s16 *lbl_12_bss_6944; /* mpvvlc_mbai_i_0 */
static s16 *lbl_12_bss_6940; /* mpvvlc_mbai_i_1 */
static s16 *lbl_12_bss_693C; /* mpvvlc_mbai_p_0 */
static s16 *lbl_12_bss_6938; /* mpvvlc_mbai_p_1 */
static s16 *lbl_12_bss_6934; /* mpvvlc_mbai_b_0 */
static s16 *lbl_12_bss_6930; /* mpvvlc_mbai_b_1 */
static s16 *lbl_12_bss_692C; /* mpvvlc_p_mbtype */
static s16 *lbl_12_bss_6928; /* mpvvlc_b_mbtype */
static s16 *lbl_12_bss_6924; /* mpvvlc_motion_0 */
static s16 *lbl_12_bss_6920; /* mpvvlc_motion_1 */
static s16 *lbl_12_bss_691C; /* mpvvlc_cbp */
static s8 *lbl_12_bss_6918;  /* mpvvlc_y_dcsiz */
static s8 *lbl_12_bss_6914;  /* mpvvlc_c_dcsiz */
static s8 *lbl_12_bss_6910;  /* mpvvlc2_y_dcsiz */
static s8 *lbl_12_bss_690C;  /* mpvvlc2_c_dcsiz */
static u32 *lbl_12_bss_6908; /* mpvvlc_run_level_0c */
static u32 *lbl_12_bss_6904; /* mpvvlc_run_level_0b */
static u32 *lbl_12_bss_6900; /* mpvvlc_run_level_0a */
static u32 *lbl_12_bss_68FC; /* mpvvlc_run_level_1 */
static u32 *lbl_12_bss_68F8; /* mpvvlc_run_level_2 */
static u32 *lbl_12_bss_68F4; /* mpvvlc_run_level_4 */
static u32 *lbl_12_bss_68F0; /* mpvvlc_run_level_8 */

static s16 lbl_12_bss_66F0[0x100];               /* mpvvlt_mbai_i_0 */
static s16 lbl_12_bss_6670[0x40];                /* mpvvlt_mbai_i_1 */
static s16 lbl_12_bss_6570[0x80];                /* mpvvlt_mbai_p_0 */
static s16 lbl_12_bss_6530[0x20];                /* mpvvlt_mbai_p_1 */
static s16 lbl_12_bss_6430[0x80];                /* mpvvlt_mbai_b_0 */
static s16 lbl_12_bss_63F0[0x20];                /* mpvvlt_mbai_b_1 */
static s16 lbl_12_bss_63B0[0x20];                /* mpvvlt_p_mbtype */
static s16 lbl_12_bss_6330[0x40];                /* mpvvlt_b_mbtype */
static s16 lbl_12_bss_6230[0x80];                /* mpvvlt_motion_0 */
static s16 lbl_12_bss_61F0[0x20];                /* mpvvlt_motion_1 */
static s16 lbl_12_bss_5D70__fzgx_offset_80[0x200]; /* mpvvlt_cbp */
static s8 lbl_12_bss_5D70[0x80];                 /* mpvvlt_y_dcsiz */
static s8 lbl_12_bss_5CF0[0x80];                 /* mpvvlt_c_dcsiz */
static s8 lbl_12_bss_58F0[0x400];                /* mpvvlt2_y_dcsiz */
static s8 lbl_12_bss_54F0[0x400];                /* mpvvlt2_c_dcsiz */
static u32 lbl_12_bss_52F0[0x80];                /* mpvvlt_run_level_8 */

#pragma section code_type ".fzgxpool"
static void mpv_vlc_layout(void) {
    const void *volatile object; /* fzgx-allow: S2 TU object first-access order */
    object = &lbl_12_bss_52F0;
    object = &lbl_12_bss_54F0;
    object = &lbl_12_bss_58F0;
    object = &lbl_12_bss_5CF0;
    object = &lbl_12_bss_5D70;
    object = &lbl_12_bss_5D70__fzgx_offset_80;
    object = &lbl_12_bss_61F0;
    object = &lbl_12_bss_6230;
    object = &lbl_12_bss_6330;
    object = &lbl_12_bss_63B0;
    object = &lbl_12_bss_63F0;
    object = &lbl_12_bss_6430;
    object = &lbl_12_bss_6530;
    object = &lbl_12_bss_6570;
    object = &lbl_12_bss_6670;
    object = &lbl_12_bss_66F0;
    object = &lbl_12_bss_68F0;
    object = &lbl_12_bss_68F4;
    object = &lbl_12_bss_68F8;
    object = &lbl_12_bss_68FC;
    object = &lbl_12_bss_6900;
    object = &lbl_12_bss_6904;
    object = &lbl_12_bss_6908;
    object = &lbl_12_bss_690C;
    object = &lbl_12_bss_6910;
    object = &lbl_12_bss_6914;
    object = &lbl_12_bss_6918;
    object = &lbl_12_bss_691C;
    object = &lbl_12_bss_6920;
    object = &lbl_12_bss_6924;
    object = &lbl_12_bss_6928;
    object = &lbl_12_bss_692C;
    object = &lbl_12_bss_6930;
    object = &lbl_12_bss_6934;
    object = &lbl_12_bss_6938;
    object = &lbl_12_bss_693C;
    object = &lbl_12_bss_6940;
    object = &lbl_12_bss_6944;
    object = &lbl_12_rodata_938;
    object = &lbl_12_rodata_938__fzgx_offset_20;
    object = &lbl_12_rodata_938__fzgx_offset_40;
    object = &lbl_12_rodata_938__fzgx_offset_60;
    object = &lbl_12_rodata_938__fzgx_offset_80;
    object = &lbl_12_rodata_938__fzgx_offset_A0;
}
#pragma section code_type ".text"

extern void fn_12_10980(void);          /* mpvvlc_InitMbaiIpic */
extern void fn_12_105BC(void);          /* mpvvlc_InitMbaiPpic */
extern void fn_12_10200(void);          /* mpvvlc_InitMbaiBpic */
extern void fn_12_1014C(void);          /* mpvvlc_InitMbTypePpic */
extern void mpvvlc_InitMbTypeBpic(void);
extern void fn_12_FC04(void);           /* mpvvlc_InitMotion */
extern s16 *fn_12_FA5C(s16 *p);         /* mpvvlc_InitCbpSub1 */
extern s16 *mpvvlc_InitCbpSub2(s16 *p);
extern void fn_12_EFA4(void);           /* mpvvlc_InitDcSizY */
extern void fn_12_ED30(void);           /* mpvvlc_InitDcSizC */
extern void mpvvlc2_InitDcSizY(void);
extern void mpvvlc2_InitDcSizC(void);
extern void fn_12_E0F4(void);           /* mpvvlc_InitIntRunLevel */
extern void fn_12_33364(unsigned int *destination, unsigned int *source, unsigned int count);

static inline void mpvvlc_InitCbp(void) {
    s16 *p = fn_12_FA5C(lbl_12_bss_5D70__fzgx_offset_80);
    mpvvlc_InitCbpSub2(p);
}

void fn_12_10F3C(u8 *vlc, void *ixa) {
    fn_12_10980();
    fn_12_105BC();
    fn_12_10200();
    fn_12_1014C();
    mpvvlc_InitMbTypeBpic();
    fn_12_FC04();
    mpvvlc_InitCbp();
    fn_12_EFA4();
    fn_12_ED30();
    mpvvlc2_InitDcSizY();
    mpvvlc2_InitDcSizC();
    fn_12_E0F4();

    lbl_12_bss_6944 = lbl_12_bss_66F0;
    lbl_12_bss_6940 = lbl_12_bss_6670;
    lbl_12_bss_693C = lbl_12_bss_6570;
    lbl_12_bss_6938 = lbl_12_bss_6530;
    lbl_12_bss_6934 = lbl_12_bss_6430;
    lbl_12_bss_6930 = lbl_12_bss_63F0;
    lbl_12_bss_692C = lbl_12_bss_63B0;
    lbl_12_bss_6928 = lbl_12_bss_6330;
    lbl_12_bss_6924 = lbl_12_bss_6230;
    lbl_12_bss_6920 = lbl_12_bss_61F0;
    lbl_12_bss_691C = lbl_12_bss_5D70__fzgx_offset_80;
    lbl_12_bss_6918 = lbl_12_bss_5D70;
    lbl_12_bss_6914 = lbl_12_bss_5CF0;
    lbl_12_bss_6910 = lbl_12_bss_58F0;
    lbl_12_bss_690C = lbl_12_bss_54F0;
    lbl_12_bss_6908 = (u32 *)lbl_12_rodata_938;
    lbl_12_bss_6904 = (u32 *)lbl_12_rodata_938__fzgx_offset_20;
    lbl_12_bss_6900 = (u32 *)lbl_12_rodata_938__fzgx_offset_40;
    lbl_12_bss_68FC = (u32 *)lbl_12_rodata_938__fzgx_offset_60;
    lbl_12_bss_68F8 = (u32 *)lbl_12_rodata_938__fzgx_offset_80;
    lbl_12_bss_68F4 = (u32 *)lbl_12_rodata_938__fzgx_offset_A0;
    lbl_12_bss_68F0 = lbl_12_bss_52F0;

    if (vlc != 0) {
        u8 *p;
        u8 *rl;

        p = vlc + MPVVLC_VLC_AREA_SIZE;
        p -= sizeof(lbl_12_bss_52F0);
        lbl_12_bss_68F0 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_52F0, sizeof(lbl_12_bss_52F0) / 4);
        p -= sizeof(lbl_12_rodata_938__fzgx_offset_A0);
        lbl_12_bss_68F4 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938__fzgx_offset_A0, sizeof(lbl_12_rodata_938__fzgx_offset_A0) / 4);
        p -= sizeof(lbl_12_rodata_938__fzgx_offset_80);
        lbl_12_bss_68F8 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938__fzgx_offset_80, sizeof(lbl_12_rodata_938__fzgx_offset_80) / 4);
        p -= sizeof(lbl_12_rodata_938__fzgx_offset_60);
        lbl_12_bss_68FC = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938__fzgx_offset_60, sizeof(lbl_12_rodata_938__fzgx_offset_60) / 4);
        p -= sizeof(lbl_12_rodata_938__fzgx_offset_40);
        lbl_12_bss_6900 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938__fzgx_offset_40, sizeof(lbl_12_rodata_938__fzgx_offset_40) / 4);
        p -= sizeof(lbl_12_rodata_938__fzgx_offset_20);
        lbl_12_bss_6904 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938__fzgx_offset_20, sizeof(lbl_12_rodata_938__fzgx_offset_20) / 4);
        p -= sizeof(lbl_12_rodata_938);
        lbl_12_bss_6908 = (u32 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_rodata_938, sizeof(lbl_12_rodata_938) / 4);
        rl = p;
        p -= sizeof(lbl_12_bss_5D70);
        lbl_12_bss_6918 = (s8 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_5D70, sizeof(lbl_12_bss_5D70) / 4);
        p = rl - (sizeof(lbl_12_bss_5D70) + sizeof(lbl_12_bss_5CF0));
        lbl_12_bss_6914 = (s8 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_5CF0, sizeof(lbl_12_bss_5CF0) / 4);
        p = rl - (sizeof(lbl_12_bss_5D70) + sizeof(lbl_12_bss_5CF0) + sizeof(lbl_12_bss_6230));
        lbl_12_bss_6924 = (s16 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_6230, sizeof(lbl_12_bss_6230) / 4);
        p = rl - (sizeof(lbl_12_bss_5D70) + sizeof(lbl_12_bss_5CF0) + sizeof(lbl_12_bss_6230) +
                  sizeof(lbl_12_bss_61F0));
        lbl_12_bss_6920 = (s16 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_61F0, sizeof(lbl_12_bss_61F0) / 4);
        p = rl - (sizeof(lbl_12_bss_5D70) + sizeof(lbl_12_bss_5CF0) + sizeof(lbl_12_bss_6230) +
                  sizeof(lbl_12_bss_61F0) + sizeof(lbl_12_bss_63B0));
        lbl_12_bss_692C = (s16 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_63B0, sizeof(lbl_12_bss_63B0) / 4);
        p = rl - (sizeof(lbl_12_bss_5D70) + sizeof(lbl_12_bss_5CF0) + sizeof(lbl_12_bss_6230) +
                  sizeof(lbl_12_bss_61F0) + sizeof(lbl_12_bss_63B0) + sizeof(lbl_12_bss_6330));
        lbl_12_bss_6928 = (s16 *)p;
        fn_12_33364((unsigned int *)p, (unsigned int *)lbl_12_bss_6330, sizeof(lbl_12_bss_6330) / 4);
    }
}
