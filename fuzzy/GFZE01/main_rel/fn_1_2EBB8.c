/* Non-matching: best partial attempt (81.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "rel/main_rel/stcoli.h"

struct fn_1_2EBB8_lbl_1_bss_3C00 {
    u8 pad_0[0x30];
    u32 unk_30;
    u8 pad_34[0x14D0];
    u8 unk_1504;
    u8 pad_1505[3];
    u8 unk_1508;
};

struct fn_1_2EBB8_lbl_1_rodata_BD8 {
    u8 pad_0[4];
    f32 unk_4;
    u8 pad_8[0x1C];
    f32 unk_24;
    f32 unk_28;
    u8 pad_2C[0x148];
    u32 unk_174;
    u32 unk_178;
    f32 unk_17C;
    f32 unk_180;
    f32 unk_184;
};

struct fn_1_2EBB8_lbl_1_data_5730 {
    u8 pad_0[0x43C];
    f32 unk_43C;
    f32 unk_440;
    f32 unk_444;
    f32 unk_448;
};

static const u32 color_white[1] = {0xFFFFFFFF};
static const u32 color_black[1] = {0x000000FF};
extern struct fn_1_2EBB8_lbl_1_rodata_BD8 lbl_1_rodata_BD8;
extern char *fn_1_15BA78(char *);
extern f32 fn_1_4B068(s32);
extern u32 fn_1_2C97C(void);
extern u32 fn_1_4068C(void *);
extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_495C8(u8);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32, f32);

#pragma opt_common_subs off
#pragma opt_propagation off
s32 fn_1_2EBB8(u32 arg0, u32 arg1) {
    struct fn_1_2EBB8_lbl_1_bss_3C00 *p_lbl_1_bss_3C00 = (struct fn_1_2EBB8_lbl_1_bss_3C00 *)&lbl_1_bss_3C00;
    struct fn_1_2EBB8_lbl_1_rodata_BD8 *p_lbl_1_rodata_BD8 = &lbl_1_rodata_BD8;
    struct fn_1_2EBB8_lbl_1_data_5730 *p_lbl_1_data_5730 = (struct fn_1_2EBB8_lbl_1_data_5730 *)&lbl_1_data_5730;
    u32 v0 = (u32)p_lbl_1_bss_3C00 + 0x20000;
    u32 v5 = arg0;
    u8 *v3;
    u32 v7;
    u32 v6;
    u32 v10;
    f32 v8;
    f32 v9;
    f32 v2;
    f32 v11;
    char **v12;
    s32 v13;
    f32 v14;
    s32 v15;
    volatile u32 loc_8;
    f32 t10;
    f32 height;
    f32 f4;

    if ((s8)p_lbl_1_bss_3C00->unk_1504 != -1) return 0;

    if ((arg1 & 0xFF) == 0 && (p_lbl_1_bss_3C00->unk_30 & 0x800)) {
        fn_1_4068C((u8 *)p_lbl_1_bss_3C00 + 0x1508);
        {
            char *text = fn_1_15BA78((char *)p_lbl_1_data_5730 + 0xABC);
            u8 *v7_sub = (u8 *)p_lbl_1_bss_3C00 + 0x1508;
            u8 *v4_sub = (u8 *)p_lbl_1_bss_3C00 + 0x30;
            *(char **)(v7_sub + 4) = text;
            p_lbl_1_bss_3C00->unk_1508 = 2;
            v7_sub[1] = 1;
            *(u32 *)(v4_sub + 0xC4) = (u32)fn_1_2C97C;
        }
    }

    v3 = (u8 *)p_lbl_1_bss_3C00 + 0x30;
    if (v3[0x13F6] == 0 && v3[5] == 1) v5 &= -41;
    if (p_lbl_1_bss_3C00->unk_30 & 0x4000000) v5 &= 0xFFFFFE7F;

    v6 = p_lbl_1_rodata_BD8->unk_174;
    v7 = v0 + 0x2000;
    v8 = p_lbl_1_rodata_BD8->unk_4;
    *(u32 *)(v7 + 0) = v6;
    v9 = p_lbl_1_rodata_BD8->unk_17C;
    *(u32 *)(v7 + 4) = v6;
    v10 = p_lbl_1_rodata_BD8->unk_178;
    *(u32 *)(v7 + 8) = v6;
    v2 = p_lbl_1_rodata_BD8->unk_180;
    *(u32 *)(v7 + 12) = v6;
    v11 = p_lbl_1_rodata_BD8->unk_184;
    *(u32 *)(v7 + 16) = v6;
    *(u32 *)(v7 + 20) = v6;
    *(u32 *)(v7 + 24) = v6;
    *(u32 *)(v7 + 28) = v6;
    *(u32 *)(v7 + 32) = v6;
    *(u32 *)(v7 + 36) = v6;

    *(u16 *)(v0 + 0x1FE6) = v5;
    *(u16 *)(v0 + 0x1FE8) = 0;
    *(u8 *)(v0 + 0x1FEA) = arg1;
    *(u32 *)(v0 + 0x1FEC) = -2;
    *(u32 *)(v0 + 0x1FF0) = 0;
    *(u32 *)(v0 + 0x1FF4) = 0;
    *(f32 *)(v0 + 0x1FF8) = v8;
    *(f32 *)(v0 + 0x1FFC) = v8;

    p_lbl_1_data_5730->unk_43C = v9;
    p_lbl_1_data_5730->unk_440 = v2;
    p_lbl_1_data_5730->unk_444 = v9;
    p_lbl_1_data_5730->unk_448 = v11;

    loc_8 = v6;
    v3 = (u8 *)(v0 + 0x2028);
    *(u32 *)(v3 + 4) = v10;
    *(u32 *)(v0 + 0x2028) = v10;

    fn_1_49410();
    fn_1_495FC();
    fn_1_495C8(1);
    fn_1_49590(p_lbl_1_rodata_BD8->unk_24);
    fn_1_495B0(0x80000000);
    fn_1_494DC(42);
    v2 = p_lbl_1_rodata_BD8->unk_28;
    fn_1_4955C(v2, v2);

    v12 = (char **)((u8 *)p_lbl_1_data_5730 + 0x7A0 + 0x38);
    v13 = 0;
    v14 = 0.0f;
    v15 = 14;
    do {
        s32 index = v15 - 1;
        if (v5 & (1 << index)) {
            p_lbl_1_bss_3C00->unk_1504 = index;
            v13++;
            t10 = fn_1_4B068((s32)fn_1_15BA78(v12[-1]));
            if (v14 < t10) v14 = t10;
        }
        v15--;
        v12--;
    } while (v15 > 0);

    if (v14 < 200.0f) v14 = 200.0f;

    f4 = 40.0f + v14;
    height = 30.0f + (f32)(v13 * 24);
    *(f32 *)(v0 + 0x2030) = f4;
    *(f32 *)(v0 + 0x2034) = height;
    p_lbl_1_data_5730->unk_440 -= (f32)(v13 * 10);
    return (s32)height;
}
