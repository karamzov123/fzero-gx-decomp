/* Non-matching: best partial attempt (65.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

// fn_4_A0C: option-screen layout pass. Walks the 0x1C-stride record table at
// .data:0x144C (3 records of 7 words), reading word [mode + 1] of each, then
// rebuilds the draw packet and re-renders it.

struct fn_4_A0C_rodata {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;   // 0.5
    u32 unk_C;
    f64 unk_10;  // 78.0
    f64 unk_18;  // 0.125
    f64 unk_20;
    f64 unk_28;  // 0.3
    f64 unk_30;  // 1.0
    f32 unk_38;
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;  // 3.5
    f32 unk_48;  // 5.0
    f32 unk_4C;  // 0.0
    f32 unk_50;  // 320.0
    f32 unk_54;  // 0.15
    f32 unk_58;  // 240.0
    f32 unk_5C;
    f64 unk_60;  // 96.0
    f64 unk_68;  // 48.0
    f32 unk_70;  // 0.25
    f32 unk_74;
    f64 unk_78;  // 2^52, int->double rounding magic
    u8 pad_80[0x34];
    f32 unk_B4;
    u8 pad_B8[0x4];
    f32 unk_BC;  // 0.05
    f32 unk_C0;  // 48.0
    f32 unk_C4;
    f32 unk_C8;  // 110.0
    f32 unk_CC;  // 1.0
    f32 unk_D0;  // 120.0
};

struct fn_4_A0C_pkt {
    u32 unk_0;
    u32 unk_4;
    s32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    u8 pad_20[0x14];
    f32 unk_34;
    s32 unk_38;
    u8 pad_3C[0x4];
    u32 unk_40;
    u8 pad_44[0x14];
};

extern struct fn_4_A0C_rodata lbl_4_rodata_0;
extern struct fn_4_A0C_pkt lbl_1_rodata_26F8;
extern u8 lbl_4_data_0[];
extern s32 lbl_801A66B4;
extern s16 lbl_1_bss_962;
extern u8 lbl_4_bss_2;
extern u8 lbl_1_bss_970[8];
extern const char fn_1_5233C[];

extern void fn_1_49410(void);
extern void fn_1_49738(const char *);
extern void fn_1_49748(f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(s32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_53E40(u32, u32, f32, f32, f32, f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern f32 fn_1_4B040(u32);
extern f64 lbl_8006D188(s32);
extern s32 fn_1_4F734(void *);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_1380F0(u32);
extern void fn_1_13ABA8(u32);

void fn_4_A0C(void)
{
    struct fn_4_A0C_pkt pkt;
    u32 *rec;
    u32 i;
    s32 j;
    u32 saved;
    f32 best;
    f32 t;
    u32 v;

    fn_1_49410();
    fn_1_49738(fn_1_5233C);
    fn_1_49748(lbl_4_rodata_0.unk_48);

    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000); /* fzgx-allow: A1 flag mask, not a register block */
        fn_1_49590(lbl_4_rodata_0.unk_8);
    }

    fn_1_53E40(0, *(u32 *)&lbl_4_data_0[0x5F8 + lbl_801A66B4 * 4],
               lbl_4_rodata_0.unk_50, lbl_4_rodata_0.unk_C8,
               lbl_4_rodata_0.unk_BC, lbl_4_rodata_0.unk_C0,
               lbl_4_rodata_0.unk_CC);

    saved = lbl_1_bss_970[4];

    fn_1_49410();
    fn_1_495C8(9);
    fn_1_49738(fn_1_5233C);
    fn_1_49748(lbl_4_rodata_0.unk_48);

    best = lbl_4_rodata_0.unk_4C;
    rec = (u32 *)&lbl_4_data_0[0x144C];
    for (i = 0, j = 0; i < 3; i++, j += 2) {
        fn_1_496FC(lbl_4_rodata_0.unk_50, (f32)(u32)((j - 2) * 0x18 + 0xf0));

        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000); /* fzgx-allow: A1 flag mask, not a register block */
            fn_1_49590(lbl_4_rodata_0.unk_8);
        }

        fn_1_4AE0C(*(const char **)&lbl_4_data_0[0x1210], rec[lbl_801A66B4 + 1]);
        t = fn_1_4B040(rec[lbl_801A66B4 + 1]);
        if (t > best) {
            best = t;
        }
        rec += 7;
    }

    if (lbl_4_data_0[0x120C] != saved || *(s16 *)&lbl_4_data_0[0x120E] != lbl_1_bss_962) {
        lbl_4_bss_2 = 0;
        lbl_4_data_0[0x120C] = saved;
        *(s16 *)&lbl_4_data_0[0x120E] = lbl_1_bss_962;
    }

    pkt = lbl_1_rodata_26F8;

    v = (saved * 2 - 2) * 0x18 + 0xf0;
    pkt.unk_8 = 0x12;
    pkt.unk_C = lbl_4_rodata_0.unk_50;
    pkt.unk_10 = (f64)(u32)v;
    pkt.unk_14 = lbl_4_rodata_0.unk_54;
    pkt.unk_18 = (f32)(((f64)best + lbl_4_rodata_0.unk_10) * lbl_4_rodata_0.unk_18);
    pkt.unk_1C = lbl_4_rodata_0.unk_44;
    pkt.unk_34 = (f32)(lbl_4_rodata_0.unk_28 *
                       (lbl_4_rodata_0.unk_30 +
                        lbl_8006D188((s16)(((u32)lbl_4_bss_2 << 10) + 0x4000))));
    pkt.unk_38 = 0xa;
    pkt.unk_40 = lbl_4_rodata_0.unk_C;

    fn_1_4F734(&pkt);

    fn_1_53BD8(0, lbl_4_rodata_0.unk_50, lbl_4_rodata_0.unk_58,
               (f32)(lbl_4_rodata_0.unk_60 + (f64)best),
               (f32)(lbl_4_rodata_0.unk_68 + lbl_4_rodata_0.unk_D0),
               lbl_4_rodata_0.unk_70);

    fn_1_1380F0(*(u32 *)&lbl_4_data_0[0xE8 + lbl_801A66B4 * 4]);
    fn_1_13ABA8(0x28000000);
}
