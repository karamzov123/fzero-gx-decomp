#include "types.h"
#include "rel/main_rel/globals.h"

extern struct ArenaData lbl_1_data_8;
extern u32 OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern void OSSetArenaLo(u32 arena_lo);
extern u16 lbl_1_bss_990[28];
extern u8 lbl_1_bss_D78;
extern u8 lbl_1_bss_DA6;
extern u32 lbl_1_bss_DB0[2];
extern u32 lbl_1_bss_DA8;
extern void fn_1_43A4(void);
extern u32 lbl_1_data_2C70;
extern void fn_80008E84(u32 value);
extern u32 lbl_1_bss_DAC;
extern struct fn_1_634_lbl_1_bss_54 lbl_1_bss_54;
extern u32 fn_8006FFC4(u32);
extern u32 fn_1_48780(void);
extern u32 lbl_801A66B4;
extern u32 lbl_801A66BC;
extern struct fn_1_904_lbl_1_bss_4 lbl_1_bss_4;
extern struct fn_1_914_lbl_1_bss_0 lbl_1_bss_0;
extern u16 lbl_1_bss_96A;
extern u32 fn_1_37E98(void);
extern u32 lbl_1_bss_96C;
extern u32 camera_set_state_flag(u32);
extern u32 fn_1_D31E0(u32);
extern struct fn_1_12B4_lbl_1_bss_962 lbl_1_bss_962;
extern u32 lbl_1_data_2A20;
extern u32 lbl_1_data_7C0;
extern u32 fn_1_15659C(u32);
extern u32 fn_80008BEC(void *, u32, u32);
extern u8 lbl_1_bss_978[];
extern u32 lbl_1_data_2B78;
extern u32 OSGetTick(u32);
extern u32 lbl_1_bss_D7C;
extern u8 lbl_1_bss_DA4;
extern char lbl_1_data_2C9C[20];
extern char lbl_1_data_2CB0[31];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_156754(u32);
extern u32 fn_1_A5864(void);
extern u32 fn_1_F7578(void);
extern struct fn_1_3C98_lbl_1_bss_DA5 lbl_1_bss_DA5;
extern u32 fn_80008EC8(u32, u32, u32);
extern u32 fn_800793D4(u32, u32, u32);
extern struct fn_1_48B0_lbl_801A6CF8 lbl_801A6CF8;
extern u32 lbl_801A6CFC;
extern struct fn_1_44B4_lbl_1_bss_DB8 lbl_1_bss_DB8;
extern struct fn_1_4438_lbl_1_bss_DC4 lbl_1_bss_DC4;
extern u8 lbl_1_bss_8E6B0[308];
extern void fn_1_14FCE4(void *data, s32 value);
extern struct fn_1_798_slot lbl_1_bss_8E7E4[];
extern u8 lbl_1_bss_AA0[336];
extern u8 lbl_1_rodata_108[88];
extern u32 fn_80008BA8(void *, void *, u32);
extern void fn_1_3BDC(u32 arg0);
extern u32 fn_1_3C18(s32);

/* fzgx:begin _prolog noprologue */
#include "types.h"
#include "dolphin/hw_regs.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table2[19] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFF80000, 0x00000000, 0x00000000, 0x00000000, 0xFFF00000, 0xFFF00000, 0xFFF00000, 0xFFF00000, 0xFFF00000, 0xFFF00000, 0xFFFC0000, 0xFFF00000, 0xFFF00000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 55.0f;
    s = 0.10000000149011612f;
    s = 90000.0f;
    s = 640.0f;
    s = 480.0f;
    s = 0.0f;
    s = 400.0f;
    s = 0.4000000059604645f;
}
#pragma section code_type ".text"

typedef struct CardSlot {
    u8 unk_0[4];
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[0x1A];
} CardSlot;




u32 fzgx_obj_lbl_1_bss_0;
u32 fzgx_obj_lbl_1_bss_4;
u32 lbl_1_bss_4__fzgx_offset_4;
u32 fzgx_obj_lbl_1_bss_C;
CardSlot lbl_1_bss_C__fzgx_offset_4;
CardSlot lbl_1_bss_C__fzgx_offset_24;
u32 lbl_1_bss_C__fzgx_offset_44;
u32 fzgx_obj_lbl_1_bss_54;
u8 fzgx_obj_lbl_1_bss_58[0x20];
u32 lbl_1_bss_58__fzgx_offset_20;
u32 lbl_1_bss_58__fzgx_offset_24;
u32 lbl_1_bss_58__fzgx_offset_28;
#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_4;
    s = *(u8 *)&lbl_1_bss_4__fzgx_offset_4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_C;
    s = *(u8 *)&lbl_1_bss_C__fzgx_offset_4;
    s = *(u8 *)&lbl_1_bss_C__fzgx_offset_24;
    s = *(u8 *)&lbl_1_bss_C__fzgx_offset_44;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_54;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_58;
    s = *(u8 *)&lbl_1_bss_58__fzgx_offset_20;
    s = *(u8 *)&lbl_1_bss_58__fzgx_offset_24;
    s = *(u8 *)&lbl_1_bss_58__fzgx_offset_28;
}
#pragma section code_type ".text"

static u32 fzgx_pool_fzgx_data_lbl_1_data_0[0x108] = {  /* fzgx-allow: A1 retail data bytes: the TU's .data objects before its string literals; dropped at integration */
    0x00800000, 0x7F7FFFFF, 0x00000000, 0x0001E000, 0x00000000, 0x00018000, 0x4E4F4E00, 0x4D415354,
    0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000,
    0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000, 0x54455354,
    0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F,
    0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000,
    0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000,
    0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B,
    0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000,
    0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100,
    0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F,
    0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241,
    0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954, 0x4F4B0000,
    0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B,
    0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B,
    0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F,
    0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000,
    0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x44424E00, 0x4D544700, 0x4A534D00, 0x44535700, 0x42414200,
    0x53475200, 0x50434F00, 0x43464C00, 0x4F435400, 0x45414400, 0x4A4D4300, 0x424C5900, 0x4B414C00,
    0x5A444100, 0x4A4C5600, 0x42525800, 0x534B4C00, 0x41475300, 0x42535400, 0x4C454F00, 0x53415200,
    0x4D415200, 0x47615300, 0x534E4500, 0x4D434800, 0x42464C00, 0x4A544B00, 0x44525100, 0x52425300,
    0x44434C00, 0x42534400, 0x44474500, 0x44425900, 0x44534700, 0x53504400, 0x44475200, 0x50524900,
    0x4C494C00, 0x504A0000, 0x51515100, 0x50455800, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFF0000, 0x6D61696E, 0x2E630000,
};

#define DATA ((u8 *)fzgx_pool_fzgx_data_lbl_1_data_0)
extern u8 lbl_1_bss_8B3A0[];
extern u8 lbl_1_bss_64710[];
extern s32 lbl_1_bss_7180C;
extern s32 lbl_1_bss_6F600;
extern s16 lbl_1_bss_968;
extern s16 lbl_1_bss_96A;
extern u32 lbl_801A63C0;
extern u32 lbl_801A66A0;
extern u32 lbl_801A66A4;
extern u32 lbl_801A66A8;
extern u32 lbl_801A66B4;
extern u8 lbl_801A66B8;
extern u8 lbl_801A66B9;
extern u8 lbl_801A66BA;
extern u8 lbl_801A66BB;
extern u32 lbl_801A66C0;
extern u32 lbl_801A66C4;
extern u32 lbl_801A66C8;

extern f32 fn_1_A6FE8(void);
extern void fn_1_A7024(f32, f32, f32, f32);
extern void fn_8006F774(f32, f32);
extern void fn_1_668(void);
extern void fn_1_A8D84(void);
extern void fn_80006914(void (*)(void));
extern void fn_80006AEC(void (*)(void));
extern void fn_800068F4(void (*)(void));
extern void fn_80006904(void (*)(void));
extern void fn_1_D3214(void);
extern void fn_1_B7E48(void);
extern void fn_1_E34(void);
extern void fn_1_E78(void);
extern void fn_1_AA590(void);
extern u32 OSGetTick(void);
extern void fn_1_9FF9C(void);
extern void fn_1_3238(void);
extern void fn_1_4B8DC(void);
extern void fn_1_487EC(void);
extern void fn_1_479B0(void);
extern void fn_1_4DDC0(void);
extern void fn_1_72848(void);
extern void fn_1_D2FC0(void);
extern void fn_1_A8F40(s32);
extern void fn_1_A5DEC(void);
extern void fn_1_E9C(void);
extern void fn_1_6D4(void *);
extern void fn_1_798(void);
extern void fn_1_54868(u32, u32);
extern void fn_1_542C4(void *, u32, f32, f32, f32);
extern void fn_1_55118(void);
extern void fn_80074CF4(f32, f32, f32);
extern void fn_1_4502C(void);
extern void fn_1_9E1B8(void);
extern void fn_1_40F78(void);
extern void fn_1_95C(void);
extern void CARDInit(void);
extern void *fn_8002A7AC(s32);
extern void fn_80008BA8(void *, void *, u32);
extern s32 fn_8002A7C4(s32, CardSlot);
extern void fn_8006FEFC(void);
extern u32 fn_1_A8DC4(void);
extern void fn_8006FFC4(s32);
extern void fn_1_814(void *);
extern void fn_80008BEC(void *, s32, u32);
extern void fn_1_44B4(void);
extern void fn_1_9FFD8(void);
extern void fn_1_3FCF8(void);
extern void fn_1_E9680(void);
extern void fn_1_107900(void);
extern void GXClearGPMetric(void);
extern void fn_8006FD1C(void);
extern void fn_1_D31AC(void);
extern void fn_1_A8FA0(void);
extern void fn_1_4F724(void);
extern void fn_1_54320(void);
extern void fn_8000659C(void);
extern void fn_1_3308(void);
extern void fn_1_B4AC0(void);
extern void fn_1_4FFC(void);
extern void fn_1_451E4(void);
extern void fn_1_ECC(void);
extern void fn_1_545B8(void);
extern u32 fn_8006FFDC(void);
extern void fn_1_A0214(void);
extern void fn_1_76218(s32);
extern void fn_1_728B0(void);
extern void fn_1_B6B28(void);
extern s32 *fn_1_FB870(void);
extern void fn_1_FC40C(void);
extern void fn_1_FC410(void);
extern void fn_1_79654(void);
extern void fn_1_4DE44(void);
extern void fn_1_4DEC0(void);
extern void fn_1_4FD64(void);
extern void fn_8006CD50(void);
extern void fn_8006CDA8(void);
extern void fn_1_A9250(s32);
extern void fn_1_D3144(void);
extern void fn_1_D3178(void);
extern void fn_1_A6E68(void);
extern s32 fn_1_D0D88(void);
extern s32 fn_8006FDEC(void);
extern void fn_1_D0E74(void);
extern void fn_1_D0F60(void);
extern void fn_80007C60(s32);
extern void OSReport(const char *, ...);
extern void fn_1_D3474(void);
extern void fn_1_4928(void);
extern void fn_1_9E1D0(void);
extern void fn_80039954(u32 *, u32 *);
extern u32 fn_8006FFBC(void);
extern s32 fn_1_3F164(void);

void _prolog(void) {
    u16 t1;
    u16 t2;
    u16 t3;
    u32 start;
    u32 now;

    fn_1_A7024(55.0f, fn_1_A6FE8(), 0.1f, 90000.0f);
    fn_8006F774(640.0f, 480.0f);
    fn_1_668();
    fn_1_A8D84();
    fn_80006914(fn_1_D3214);
    fn_80006AEC(fn_1_B7E48);
    fn_800068F4(fn_1_E34);
    fn_80006904(fn_1_E78);
    fn_1_AA590();
    lbl_801A63C0 = 1;
    lbl_801A66A0 = 0;
    lbl_801A66A4 = 0;
    lbl_801A63C0 = OSGetTick() ^ 0xCAE87FB5;
    fn_1_9FF9C();
    fn_1_3238();
    fn_1_4B8DC();
    fn_1_487EC();
    fn_1_479B0();
    fn_1_4DDC0();
    fn_1_72848();
    fn_1_D2FC0();
    fn_1_A8F40(0xFF);
    fn_1_A5DEC();
    lbl_801A66C0 = 0;
    lbl_801A66C4 = 0;
    lbl_801A66A8 = 0;
    lbl_801A66A4 = 0;
    lbl_801A66A0 = 0;
    lbl_801A66C8 = 0;
    fn_1_E9C();
    lbl_1_bss_968 = 10;
    fn_1_6D4(lbl_1_bss_8B3A0);
    fn_1_798();
    fn_1_54868(fzgx_obj_lbl_1_bss_C, 0x18000);
    fn_1_542C4(lbl_1_bss_64710, 0x1000, 0.0f, 0.0f, 400.0f);
    fn_1_55118();
    fn_80074CF4(0.4f, 0.4f, 0.4f);
    fn_1_4502C();
    fn_1_9E1B8();
    fn_1_40F78();
    lbl_801A66C8++;
    lbl_801A66A0++;
    lbl_801A66A4++;
    lbl_801A66A8++;
    lbl_801A66C0++;
    fn_1_95C();
    if (lbl_1_bss_7180C != 0) {
        CARDInit();
    }
    if (lbl_1_bss_7180C != 0) {
        fn_80008BA8(&lbl_1_bss_C__fzgx_offset_4, fn_8002A7AC(0), 0x20);
        lbl_1_bss_C__fzgx_offset_4.unk_4 = 0x38;
        lbl_1_bss_C__fzgx_offset_4.unk_5 = 0x50;
        fn_8002A7C4(0, lbl_1_bss_C__fzgx_offset_4);
        fn_80008BA8(&lbl_1_bss_C__fzgx_offset_24, fn_8002A7AC(1), 0x20);
        lbl_1_bss_C__fzgx_offset_24.unk_4 = 0x38;
        lbl_1_bss_C__fzgx_offset_24.unk_5 = 0x50;
        fn_8002A7C4(1, lbl_1_bss_C__fzgx_offset_24);
    }
    fn_8006FEFC();
    lbl_1_bss_C__fzgx_offset_44 = fn_1_A8DC4();
    lbl_801A66BB = 0;
    lbl_801A66BA = 1;
    lbl_801A66B9 = 0;
    lbl_801A66B8 = 0;
    fzgx_obj_lbl_1_bss_54 = 1;
    fn_8006FFC4(1);
    switch (lbl_801A66B4) {
    case 0:
        fn_1_814("en");
        break;
    case 5:
    default:
        fn_1_814("ja");
        break;
    }
    fn_80008BEC(fzgx_obj_lbl_1_bss_58, 0, 0x20);
    fn_1_44B4();
    fn_1_9FFD8();
    fn_1_3FCF8();
    fn_1_E9680();
    fn_1_107900();
    for (;;) {
        GXClearGPMetric();
        fn_8006FD1C();
        fn_1_D31AC();
        fn_1_A8FA0();
        fn_1_4F724();
        fn_1_54320();
        fn_8000659C();
        fn_1_3308();
        if (lbl_1_bss_7180C != 0) {
            fn_1_B4AC0();
        }
        fn_1_D3214();
        fn_1_4FFC();
        fn_1_451E4();
        lbl_801A66BB = 0;
        fn_1_ECC();
        fn_1_545B8();
        t1 = fn_8006FFDC();
        fn_1_A0214();
        if (lbl_801A66BB == 0) {
            fn_1_76218(0);
            fn_1_728B0();
            fn_1_76218(1);
        }
        if (lbl_801A66BB == 0 && lbl_1_bss_7180C != 0) {
            fn_1_B6B28();
        }
        if (*fn_1_FB870() != 0) {
            fn_1_FC40C();
            fn_1_FC410();
        }
        if (lbl_801A66BB == 0) {
            fn_1_79654();
        }
        fn_1_4DE44();
        if (lbl_801A66BB == 0) {
            fn_1_4DEC0();
        }
        fn_1_4FD64();
        fn_8006CD50();
        fn_8006CDA8();
        t2 = fn_8006FFDC();
        fn_1_A9250(0);
        fn_1_4FD64();
        fn_1_D3144();
        fn_1_D3178();
        if (lbl_1_bss_6F600 != 0) {
            fn_1_A6E68();
        }
        if (fn_1_D0D88() != 0) {
            fn_8006FDEC();
            fn_1_D0E74();
            fn_1_D0F60();
        }
        fn_80007C60(lbl_1_bss_968 != -1 || lbl_1_bss_96A != -1);
        t3 = fn_8006FFDC();
        if (fn_8006FDEC() != 0) {
            OSReport("Ord ID: %d\n2D ID: %d\nLast ID: %d\n", t1, t2, t3);
            fn_1_D3474();
        }
        fn_1_4928();
        fn_1_9E1D0();
        start = OSGetTick();
        fn_8006FEFC();
        fn_80039954(&lbl_1_bss_58__fzgx_offset_20, &lbl_1_bss_58__fzgx_offset_24);
        fzgx_obj_lbl_1_bss_4 = ((OSGetTick() - start) * 8) / (OS_TIMER_CLOCK / 125000);
        lbl_1_bss_4__fzgx_offset_4 = 0xC0000 - fn_8006FFBC();
        now = fn_1_A8DC4();
        fzgx_obj_lbl_1_bss_0 = now - lbl_1_bss_C__fzgx_offset_44;
        lbl_1_bss_C__fzgx_offset_44 = now;
        if (lbl_801A66BB == 0) {
            lbl_801A66C8++;
            if (fn_1_3F164() == 0) {
                lbl_801A66A0++;
                lbl_801A66A4++;
                lbl_801A66A8++;
            }
            lbl_801A66C0++;
        }
    }
}
/* fzgx:end _prolog */

/* fzgx:begin fn_1_634 */
struct fn_1_634_lbl_1_bss_54 {
    u32 unk_0;
};

void * fn_1_634(void) {
    fn_8006FFC4(lbl_1_bss_54.unk_0);
    return &lbl_1_bss_54;
}
/* fzgx:end fn_1_634 */

/* fzgx:begin fn_1_668 */
struct ArenaData {
    u32 *arena_lo;
    u32 arena_lo_size;
    u32 *aligned_lo;
    u32 aligned_lo_size;
};

void fn_1_668(void) {
    u32 arena_lo;
    u32 aligned_lo;

    arena_lo = OSGetArenaLo();
    OSGetArenaHi();
    *lbl_1_data_8.arena_lo = arena_lo;
    aligned_lo = (arena_lo + lbl_1_data_8.arena_lo_size + 0x1f) & ~0x1f;
    *lbl_1_data_8.aligned_lo = aligned_lo;
    aligned_lo = (aligned_lo + lbl_1_data_8.aligned_lo_size + 0x1f) & ~0x1f;
    OSSetArenaLo(aligned_lo);
}
/* fzgx:end fn_1_668 */

/* fzgx:begin fn_1_6D4 */
extern u32 fn_80008BEC(void *, u32, u32);

struct fn_1_6D4_Data {
    s16 unk_0;
    s16 unk_2;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    s16 unk_A;
    u8 unk_C[2];
    s16 unk_E;
    u8 pad_10[0x1e];
    s16 unk_2E;
    u8 pad_30[0x1e];
    s16 unk_4E;
    u8 pad_50[0x1e];
    s16 unk_6E;
    u8 pad_70[0x22];
    u16 unk_92;
    u8 pad_94[0xb];
    u8 unk_9F;
    u8 unk_A0;
    u8 unk_A1;
    u8 unk_A2;
    u8 pad_A3;
    u32 unk_A4;
    u8 pad_A8[0x84];
    u16 unk_12C;
    u16 unk_12E;
    u16 unk_130;
    u16 unk_132;
    u16 unk_134;
    u16 unk_136;
    u16 unk_138;
    u16 unk_13A;
    u16 unk_13C;
};

void fn_1_6D4(struct fn_1_6D4_Data *data) {
    fn_80008BEC(data, 0, 0x14c);
    data->unk_A4 = 0;
    fn_80008BEC(data->unk_C, 0, 0x80);
    data->unk_E = (u16)-1;
    data->unk_9F = 0;
    data->unk_2E = (u16)-1;
    data->unk_A0 = 0;
    data->unk_4E = (u16)-1;
    data->unk_A1 = 0;
    data->unk_6E = (u16)-1;
    data->unk_A2 = 0;
    data->unk_0 = (u16)-1;
    data->unk_2 = (u16)-1;
    data->unk_4 = 1;
    data->unk_6 = 0x1e;
    data->unk_8 = 0;
    data->unk_A = (u16)-1;
    data->unk_92 = 8;
    data->unk_12C = 0;
    data->unk_12E = 0;
    data->unk_130 = 0;
    data->unk_132 = 1;
    data->unk_134 = 1;
    data->unk_136 = 1;
    data->unk_138 = 1;
    data->unk_13C = 3;
    data->unk_13A = 0;
}
/* fzgx:end fn_1_6D4 */

/* fzgx:begin fn_1_798 */
struct fn_1_798_slot {
    u8 unk_0[8];
    s32 value_8;
    u8 unk_C[0x3C];
};


void fn_1_798(void) {
    s32 value;
    s16 index;

    fn_1_14FCE4(lbl_1_bss_8E6B0, 0x4d);
    fn_80008BEC(lbl_1_bss_8E7E4, 0, 0x5a4);
    value = -1;
    for (index = 0; index < 0x14; index++) {
        ((struct fn_1_798_slot *)&lbl_1_bss_8E7E4)[index].value_8 = value;
    }
}
/* fzgx:end fn_1_798 */

/* fzgx:begin fn_1_814 */
extern struct ArenaData lbl_1_data_8;
extern u32 OSGetArenaLo(void);
extern u32 OSGetArenaHi(void);
extern void OSSetArenaLo(u32 arena_lo);
extern u16 lbl_1_bss_990[28];
extern u8 lbl_1_bss_D78;
extern u8 lbl_1_bss_DA6;
extern u32 lbl_1_bss_DB0[2];
extern u32 lbl_1_bss_DA8;
extern void fn_1_43A4(void);
extern u32 lbl_1_data_2C70;
extern void fn_80008E84(u32 value);
extern u32 lbl_1_bss_DAC;
extern struct fn_1_634_lbl_1_bss_54 lbl_1_bss_54;
extern u32 fn_8006FFC4(u32);
extern u32 fn_1_48780(void);
extern u32 lbl_801A66B4;
extern u32 lbl_801A66BC;
extern struct fn_1_904_lbl_1_bss_4 lbl_1_bss_4;
extern struct fn_1_914_lbl_1_bss_0 lbl_1_bss_0;
extern u16 lbl_1_bss_96A;
extern u32 fn_1_37E98(void);
extern u32 lbl_1_bss_96C;
extern u32 camera_set_state_flag(u32);
extern u32 fn_1_D31E0(u32);
extern struct fn_1_12B4_lbl_1_bss_962 lbl_1_bss_962;
extern u32 lbl_1_data_2A20;
extern u32 lbl_1_data_7C0;
extern u32 fn_1_15659C(u32);
extern u32 fn_80008BEC(void *, u32, u32);
extern u8 lbl_1_bss_978[];
extern u32 lbl_1_data_2B78;
extern u32 OSGetTick(u32);
extern u32 lbl_1_bss_D7C;
extern u8 lbl_1_bss_DA4;
extern char lbl_1_data_2C9C[20];
extern char lbl_1_data_2CB0[31];
extern void OSPanic(const char *message, int line, const char *file, ...);
extern void fn_80009AA8(u32 value, u32 count, const char *file, int line);
extern u32 fn_1_156754(u32);
extern u32 fn_1_A5864(void);
extern u32 fn_1_F7578(void);
extern struct fn_1_3C98_lbl_1_bss_DA5 lbl_1_bss_DA5;
extern u32 fn_80008EC8(u32, u32, u32);
extern u32 fn_800793D4(u32, u32, u32);
extern struct fn_1_48B0_lbl_801A6CF8 lbl_801A6CF8;
extern u32 lbl_801A6CFC;
extern struct fn_1_44B4_lbl_1_bss_DB8 lbl_1_bss_DB8;
extern struct fn_1_4438_lbl_1_bss_DC4 lbl_1_bss_DC4;
extern u8 lbl_1_bss_8E6B0[308];
extern void fn_1_14FCE4(void *data, s32 value);
extern struct fn_1_798_slot lbl_1_bss_8E7E4[];
extern u8 lbl_1_bss_AA0[336];
extern u8 lbl_1_rodata_108[88];
extern u32 fn_80008BA8(void *, void *, u32);
extern void fn_1_3BDC(u32 arg0);
extern u32 fn_1_3C18(s32);

struct fn_1_814_Arg0 {
    u8 unk_0;
    u8 unk_1;
};

extern u32 OSGetArenaHi(void);
extern u32 fn_1_15B970(u32);
extern void fn_80006E10(void *);
extern u8 lbl_1_data_0[];
extern void OSSetArenaHi(u32);
extern s32 fn_1_45730(void *, void *);
extern u32 fn_1_45850(void *);
extern void fn_1_458A0(void *, u32, u32, u32);
extern u32 fn_1_45B2C(void *);

extern void OSReport(const char *, ...);
static u32 fzgx_pool_fzgx_data_lbl_1_data_0[0x113] = {  /* fzgx-allow: A1 retail data bytes: the TU's .data objects before its string literals; dropped at integration */
    0x00800000, 0x7F7FFFFF, 0x00000000, 0x0001E000, 0x00000000, 0x00018000, 0x4E4F4E00, 0x4D415354,
    0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000,
    0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000, 0x54455354,
    0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F,
    0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000,
    0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000,
    0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B,
    0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000,
    0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100,
    0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F,
    0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241,
    0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954, 0x4F4B0000,
    0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B,
    0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B,
    0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F,
    0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000,
    0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x44424E00, 0x4D544700, 0x4A534D00, 0x44535700, 0x42414200,
    0x53475200, 0x50434F00, 0x43464C00, 0x4F435400, 0x45414400, 0x4A4D4300, 0x424C5900, 0x4B414C00,
    0x5A444100, 0x4A4C5600, 0x42525800, 0x534B4C00, 0x41475300, 0x42535400, 0x4C454F00, 0x53415200,
    0x4D415200, 0x47615300, 0x534E4500, 0x4D434800, 0x42464C00, 0x4A544B00, 0x44525100, 0x52425300,
    0x44434C00, 0x42534400, 0x44474500, 0x44425900, 0x44534700, 0x53504400, 0x44475200, 0x50524900,
    0x4C494C00, 0x504A0000, 0x51515100, 0x50455800, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFF0000, 0x6D61696E, 0x2E630000,
    0x656E0000, 0x6A610000, 0x4F726420, 0x49443A20, 0x25640A32, 0x44204944, 0x3A202564, 0x0A4C6173,
    0x74204944, 0x3A202564, 0x0A000000,
};

#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("ja.gmo");
    OSReport("game");
    OSReport("..");
}
#pragma section code_type ".text"

void fn_1_814(struct fn_1_814_Arg0 *arg0) {
    u32 v2;
    u32 unk_4;
    u32 v3;
    struct { u32 a[24]; } loc_8;
    u32 t3;
    struct fn_1_814_Arg0 *v0;
    struct fn_1_814_Arg0 *w;

    
    v0 = (struct fn_1_814_Arg0 *)((u8 *)"ja.gmo");
    w = v0;
    w->unk_0 = arg0->unk_0;
    w->unk_1 = arg0->unk_1;
    fn_80006E10(((u8 *)"game"));
    if (!fn_1_45730(v0, &loc_8)) {
        v3 = 0;
    } else {
        v2 = fn_1_45B2C(&loc_8);
        unk_4 = v2 + 0x1f;
        v2 = unk_4 & ~0x1F;
        t3 = OSGetArenaHi();
        v3 = t3 - v2;
        fn_1_458A0(&loc_8, v3, v2, 0);
        fn_1_45850(&loc_8);
        OSSetArenaHi(v3);
    }
    fn_1_15B970(v3);
    fn_80006E10(((u8 *)".."));
}
/* fzgx:end fn_1_814 */

/* fzgx:begin fn_1_8D4 */
void fn_1_8D4(void) {
    lbl_801A66B4 = lbl_801A66BC;
    fn_1_48780();
}
/* fzgx:end fn_1_8D4 */

/* fzgx:begin fn_1_904 */
struct fn_1_904_lbl_1_bss_4 {
    u32 unk_0;
};

u32 fn_1_904(void) {
    return lbl_1_bss_4.unk_0;
}
/* fzgx:end fn_1_904 */

/* fzgx:begin fn_1_914 */
struct fn_1_914_lbl_1_bss_0 {
    u32 unk_0;
};

u32 fn_1_914(void) {
    return lbl_1_bss_0.unk_0;
}
/* fzgx:end fn_1_914 */

/* fzgx:begin fn_1_924 */
u32 fn_1_924(void) {
    lbl_1_bss_96A = 36;
    return fn_1_37E98();
}
/* fzgx:end fn_1_924 */

/* fzgx:begin fn_1_950 */
// fn_1_950: empty in retail (single blr).
void fn_1_950(void) {
}
/* fzgx:end fn_1_950 */

/* fzgx:begin fn_1_954 */
// fn_1_954: empty in retail (single blr).
void fn_1_954(void) {
}
/* fzgx:end fn_1_954 */

/* fzgx:begin fn_1_958 */
// fn_1_958: empty in retail (single blr).
void fn_1_958(void) {
}
/* fzgx:end fn_1_958 */

/* fzgx:begin fn_1_95C */
extern u32 OSGetArenaHi(void);
extern void OSSetArenaHi(u32 arena_hi);
extern u32 fn_80008BEC(void *, u32, u32);
extern u32 fn_1_12B88(char *path, u8 *dest, u8 *work);
extern void fn_800074C4(u32 mapped, u8 *data, u32 size, u32 arg3, u32 arg4, u32 arg5);
extern void fn_800075AC(u8 *data, u32 size, u32 arg2);
extern void DCFlushRange(void *addr, u32 size);
extern size_t strlen(const char *s);
extern s32 fn_1_15C35C(s32 a, s32 b, s32 c, s32 d);
extern char lbl_1_data_45C[3];

/*
 * Loads game/cardata.lz once before the first frame into 0x6000 bytes below the arena top, turns every
 * word of each 0xB4-byte block high byte first except the four bytes at 0x48, puts each block's name
 * address in its word 0, and maps the table at 0x23800000. fn_1_15C35C(a, b, c, d) is a * b - c + d:
 * every constant goes through it.
 */
void fn_1_95C(void) {
    char path[16];
    u32 *part;
    u32 w;
    u32 *dst;
    u8 *data;
    u32 *machine;
    u32 j;
    char *name;
    u32 i;
    u32 size;
    u8 *group;

    /* "game" (the directory), then "cardata.lz" */
    path[0] = 'g';
    fn_80008BEC(&path[1], 'a', 10);
    path[2] += 12;
    path[4] = 0;
    path[3] += 4;
    fn_80006E10(path);
    path[0] -= 4;
    path[2] += 5;
    path[3] -= 1;
    path[4] += 'a';
    path[5] += 0x13;
    path[7] -= 0x33;
    path[8] += 0xB;
    path[9] += 0x19;
    path[10] = 0;

    size = fn_1_15C35C(60, 400, 0, 576); /* 0x6000 */
    data = (u8 *)((OSGetArenaHi() - size) & ~0xFFF);
    if (fn_1_12B88(path, data, data - 0x2000) != 0) {
        OSSetArenaHi((u32)data);
        fn_80008BEC(path, 0, 12);
        /* 0x23800000, 0x6000 */
        fn_800074C4(fn_1_15C35C(224, 0x280000, 0xFF953892, 0x153892), data, fn_1_15C35C(60, 400, 0, 576), 0, 0, 3);

        /* the 41 machines, last id first, each taking the next name from 0x23801CE0 */
        name = (char *)(fn_1_15C35C(458, 0x140000, 0x645892, 0x1C5892) + 0x1CE0);
        for (i = 0; i < fn_1_15C35C(10, 8, 54, 15); i++) {
            machine = (u32 *)(data + fn_1_15C35C(3, 8, 4, 20) * 0xB4 - i * 0xB4);
            for (w = 0, dst = machine; w < 45; dst++, w++) {
                if (w != 18) {
                    *dst = __lwbrx(machine, w * 4);
                }
            }
            machine[0] = (u32)name;
            name += strlen(name) + 1;
        }

        /* the custom parts from 0x1F04: 25 bodies, 25 cockpits, 25 boosters, all named 0x238053C0 */
        name = (char *)(fn_1_15C35C(458, 0x140000, 0x645892, 0x1C5892) + 0x53C0);
        size = (u32)data + 0x1F04; /* size is free again: it holds the parts base (retail register order) */
        for (j = 0; j < 3; j++) {
            group = (u8 *)size + j * fn_1_15C35C(6, 2, j + 7, j + 20) * 0xB4;
            for (i = 0; i < fn_1_15C35C(2, 6, 7, 20); i++) {
                part = (u32 *)(group + fn_1_15C35C(10, 3, 8, 2) * 0xB4 - i * 0xB4);
                for (w = 0, dst = part; w < 45; dst++, w++) {
                    if (w != 18) {
                        *dst = __lwbrx(part, w * 4);
                    }
                }
                part[0] = (u32)name;
            }
        }

        DCFlushRange(data, fn_1_15C35C(60, 400, 0, 576));
        fn_800075AC(data, fn_1_15C35C(60, 400, 0, 576), 1);
    }
    fn_80006E10(lbl_1_data_45C);
}
/* fzgx:end fn_1_95C */

/* fzgx:begin fn_1_E34 */
void fn_1_E34(void) {
    s32 v0;
    fn_1_A5864();
    fn_1_F7578();
    v0 = 0;
    do {
    fn_1_156754(v0);
    v0++;
    } while (v0 < 4);
}
/* fzgx:end fn_1_E34 */

/* fzgx:begin fn_1_E78 */
extern u32 fn_1_3BC0(u32);
extern u32 fn_1_A59AC(void);

void fn_1_E78(void) {
    u32 t0;
    t0 = fn_1_A59AC();
    fn_1_3BC0(t0);
}
/* fzgx:end fn_1_E78 */

/* fzgx:begin fn_1_E9C */
struct fn_1_E9C_lbl_1_bss_960 {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    u32 unk_C;
};


#pragma peephole off
#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_E9C(void) {
    s8 value = -1;
    u8 *state = (u8 *)&lbl_1_bss_960;

    *(u16 *)(state + 0) = value;
    *(u16 *)(state + 2) = value;
    *(u16 *)(state + 4) = value;
    *(u16 *)(state + 6) = value;
    *(u16 *)(state + 8) = 0;
    *(u16 *)(state + 0xa) = value;
    *(u32 *)(state + 0xc) = 0;
}
#pragma opt_common_subs reset

#pragma opt_propagation reset

#pragma peephole reset
/* fzgx:end fn_1_E9C */

/* fzgx:begin fn_1_ECC noprologue */
#include "types.h"
#include "rel/main_rel/globals.h"

typedef void (*Fn)(void);
typedef struct { u8 pad[0x20]; Fn f20; Fn f24; Fn f28; } T28;
typedef struct { u8 pad[0x20]; Fn f20; Fn f24; Fn f28; Fn f2c; } T30;
typedef struct {
    s16 a; s16 b; u16 c; u16 d; s16 e; s16 f; s32 g;
} State;

extern T28 lbl_1_data_7C0[];
extern T30 lbl_1_data_460[];
extern void fn_1_128C(void);
extern void fn_1_12F194(void);
extern void fn_1_3C98(void);
extern void fn_1_3CC4(void);
extern u32 lbl_801A66C0;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s16 fzgx_obj_lbl_1_bss_960;
s16 fzgx_obj_lbl_1_bss_962;
u16 lbl_1_bss_964;
u16 lbl_1_bss_966;
s16 lbl_1_bss_968;
s16 lbl_1_bss_96A;
s32 lbl_1_bss_96C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_960;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_962;
    s = *(u8 *)&lbl_1_bss_964;
    s = *(u8 *)&lbl_1_bss_966;
    s = *(u8 *)&lbl_1_bss_968;
    s = *(u8 *)&lbl_1_bss_96A;
    s = *(u8 *)&lbl_1_bss_96C;
}
#pragma section code_type ".text"

void fn_1_ECC(void) {
    
    s16 x;

    if (lbl_1_bss_968 != -1) {
        if (fzgx_obj_lbl_1_bss_962 != -1) {
            lbl_1_data_7C0[fzgx_obj_lbl_1_bss_962].f28();
            lbl_1_bss_966 = fzgx_obj_lbl_1_bss_962;
        }
        if (fzgx_obj_lbl_1_bss_960 != -1) {
            lbl_1_data_460[fzgx_obj_lbl_1_bss_960].f2c();
            lbl_1_bss_964 = fzgx_obj_lbl_1_bss_960;
        }
        x = lbl_1_bss_968;
        fzgx_obj_lbl_1_bss_960 = x;
        fzgx_obj_lbl_1_bss_962 = -1;
        lbl_1_bss_968 = -1;
        lbl_1_bss_96C = 0;
        fn_1_128C();
        lbl_1_data_460[fzgx_obj_lbl_1_bss_960].f20();
    } else if (lbl_1_bss_96A != -1) {
        if (fzgx_obj_lbl_1_bss_962 != -1) {
            lbl_1_data_7C0[fzgx_obj_lbl_1_bss_962].f28();
            lbl_1_bss_966 = fzgx_obj_lbl_1_bss_962;
        }
        x = lbl_1_bss_96A;
        fzgx_obj_lbl_1_bss_962 = x;
        lbl_1_bss_96A = -1;
        lbl_801A66C0 = 0;
        fn_1_12F194();
        lbl_1_data_7C0[fzgx_obj_lbl_1_bss_962].f20();
    }

    if (fzgx_obj_lbl_1_bss_960 != -1) {
        lbl_1_data_460[fzgx_obj_lbl_1_bss_960].f24();
    }

    if (lbl_1_bss_968 != -1) {
        if (fzgx_obj_lbl_1_bss_962 != -1) {
            lbl_1_data_7C0[fzgx_obj_lbl_1_bss_962].f28();
            lbl_1_bss_966 = fzgx_obj_lbl_1_bss_962;
        }
        if (fzgx_obj_lbl_1_bss_960 != -1) {
            lbl_1_data_460[fzgx_obj_lbl_1_bss_960].f2c();
            lbl_1_bss_964 = fzgx_obj_lbl_1_bss_960;
        }
        fn_1_3C98();
        fn_1_3CC4();
        fzgx_obj_lbl_1_bss_960 = -1;
        fzgx_obj_lbl_1_bss_962 = -1;
        return;
    } else if (lbl_1_bss_96A != -1) {
        if (fzgx_obj_lbl_1_bss_962 != -1) {
            lbl_1_data_7C0[fzgx_obj_lbl_1_bss_962].f28();
            lbl_1_bss_966 = fzgx_obj_lbl_1_bss_962;
        }
        x = lbl_1_bss_96A;
        fzgx_obj_lbl_1_bss_962 = x;
        lbl_1_bss_96A = -1;
        lbl_801A66C0 = 0;
        fn_1_12F194();
        lbl_1_data_7C0[fzgx_obj_lbl_1_bss_962].f20();
    }

    if (fzgx_obj_lbl_1_bss_962 != -1) {
        lbl_1_data_7C0[fzgx_obj_lbl_1_bss_962].f24();
    }
    if (lbl_1_bss_96C != 0) {
        fn_1_3C98();
        lbl_1_data_460[fzgx_obj_lbl_1_bss_960].f28();
    }

    if (fzgx_obj_lbl_1_bss_962 != -1 && (lbl_1_bss_96A != -1 || lbl_1_bss_968 != -1)) {
        lbl_1_data_7C0[fzgx_obj_lbl_1_bss_962].f28();
        x = lbl_1_bss_968;
        lbl_1_bss_966 = fzgx_obj_lbl_1_bss_962;
        fzgx_obj_lbl_1_bss_962 = -1;
        if (x != -1 && fzgx_obj_lbl_1_bss_960 != -1) {
            lbl_1_data_460[fzgx_obj_lbl_1_bss_960].f2c();
            lbl_1_bss_964 = fzgx_obj_lbl_1_bss_960;
            fzgx_obj_lbl_1_bss_960 = -1;
        }
        if (lbl_1_bss_96C == 0) {
            fn_1_3C98();
            fn_1_3CC4();
            return;
        }
    }
    if (lbl_1_bss_96C == 0) {
        fn_1_3C98();
        lbl_1_data_460[fzgx_obj_lbl_1_bss_960].f28();
    }
}
/* fzgx:end fn_1_ECC */

/* fzgx:begin fn_1_1280 */
void fn_1_1280(u32 arg0) {
    lbl_1_bss_96C = arg0;
}
/* fzgx:end fn_1_1280 */

/* fzgx:begin fn_1_128C */
u32 fn_1_128C(void) {
    u32 t0;
    t0 = camera_set_state_flag(0);
    return fn_1_D31E0(t0);
}
/* fzgx:end fn_1_128C */

/* fzgx:begin fn_1_12B4 */
extern u32 OSReport(void *, ...);

struct fn_1_12B4_lbl_1_bss_962 {
    s16 unk_0;
};

void fn_1_12B4(void) {
    s16 v0;
    v0 = lbl_1_bss_962.unk_0;
    OSReport(&lbl_1_data_2A20, v0, ((u8 *)&lbl_1_data_7C0 + (v0 * 44)));
}
/* fzgx:end fn_1_12B4 */

/* fzgx:begin fn_1_12FC */
// fn_1_12FC: empty in retail (single blr).
void fn_1_12FC(void) {
}
/* fzgx:end fn_1_12FC */

/* fzgx:begin fn_1_1300 */
// fn_1_1300: empty in retail (single blr).
void fn_1_1300(void) {
}
/* fzgx:end fn_1_1300 */
