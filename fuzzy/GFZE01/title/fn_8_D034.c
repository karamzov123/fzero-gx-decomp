/* Non-matching: best partial attempt (83.12% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table7[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 989.0;
    d = 795.0;
    d = 15.0;
    d = 975.0;
    d = 0.0;
    d = 320.0;
    d = 640.0;
    d = 1.0;
    d = 780.0;
    d = 990.0;
    s = 0.5f;
    s = 240.0f;
    s = 0.0f;
    s = 1.0f;
    s = 0.8333333134651184f;
    s = 5.0f;
    s = 255.0f;
    s = 20.0f;
    d = 1800.0;
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

struct Sig_fn_8_CF94_fn_8_CF94_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA4];
    u32 unk_A8;
    u32 unk_AC;
    u8 pad_B0[0x14];
    u32 unk_C4;
    u8 pad_C8[0x4];
    u32 unk_CC;
};
struct fn_8_D034_lbl_8_bss_540 {
    s8 unk_0;
    u8 pad_1[3];
    s32 unk_4;
    s32 unk_8;
    s32 unk_C;
};
struct fn_8_D034_lbl_8_rodata_368 {
    u32 unk_0, unk_4, unk_8, unk_C, unk_10, unk_14;
    u32 unk_18;
    u8 pad_1C[4];
    f64 unk_20, unk_28, unk_30, unk_38, unk_40, unk_48, unk_50, unk_58, unk_60, unk_68;
    f32 unk_70, unk_74, unk_78, unk_7C, unk_80, unk_84, unk_88, unk_8C;
    f64 unk_90, unk_98;
};
struct fn_8_D034_lbl_8_data_A0C0 { u8 unk_0; };
struct fn_8_D034_lbl_1_bss_8E51D { u8 unk_0; };

extern s32 fn_1_1555B0(s32);
extern struct fn_8_D034_lbl_1_bss_8E51D lbl_1_bss_8E51D;
extern struct fn_8_D034_lbl_8_bss_540 lbl_8_bss_540;
extern struct fn_8_D034_lbl_8_data_A0C0 lbl_8_data_A0C0;
extern struct fn_8_D034_lbl_8_rodata_368 lbl_8_rodata_368;
extern u32 lbl_801A66B4;
extern u16 lbl_1_bss_9F8[];
extern u16 lbl_1_bss_96A;
extern void fn_1_3EB78(u32, u32, u32, u32);
extern u32 fn_1_3ED8C(u32, u32, u32, u32, u32, u32, u32);
extern void fn_1_14A1AC(u8);
extern void fn_1_14BC40(void);
extern void fn_1_1554D0(void);
extern void fn_1_3EF08(u8);
extern void fn_1_3EF8C(u8);
extern void fn_1_3EFF0(u32, u8);
extern void fn_1_3F02C(u32);
extern void fn_1_47F74(s32);
extern void fn_1_A2D84(u32);
extern void fn_1_49410(void);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_4D0A0(void);
extern void fn_1_5233C(void);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4D0D4(u32 *, f32);
extern void fn_1_14BCBC(u32);
extern u32 fn_1_144F40(u32);
extern int fn_1_3F038(void);
extern void fn_8006CE1C(f32);
extern void fn_1_3F894(void);
extern void fn_8_CF94(struct Sig_fn_8_CF94_fn_8_CF94_Arg0 *);
extern void fn_8_D020(void);

#pragma opt_common_subs off
static inline u32 *fn_8_D034_array_read(u32 *array) { return array; }
#pragma opt_strength_reduction off
static inline u16 *fn_8_D034_array_read_(u16 *array) { return array; }
void fn_8_D034(f32 arg0) {
    struct fn_8_D034_lbl_8_bss_540 *p_lbl_8_bss_540 = &lbl_8_bss_540;
    struct fn_8_D034_lbl_8_rodata_368 *p_lbl_8_rodata_368 = &lbl_8_rodata_368;
    s32 count, idx, flag, flag2;
    f64 d, t, curve;
    f32 amount, alpha;
    u32 color;
    u8 *state;
{
    u32 colors[6];
    colors[0] = fzgx_pool_table1[0];
    colors[1] = fzgx_pool_table2[0];
    colors[2] = fzgx_pool_table3[0];
    colors[3] = fzgx_pool_table4[0];
    colors[4] = fzgx_pool_table5[0];
    colors[5] = fzgx_pool_table6[0];
    if (p_lbl_8_bss_540->unk_4 == 1) {
        count = lbl_8_data_A0C0.unk_0 + 1;
        if (count > 36) count = 31;
        else if (count >= 31) count = 36;
        p_lbl_8_bss_540->unk_0 = count;
        lbl_8_data_A0C0.unk_0 = count;
        fn_1_3EF8C(6);
        fn_1_3ED8C(0, 3, 1, lbl_8_data_A0C0.unk_0, 10, 10, 0);
        fn_1_3EB78(0, 0, 0, 0);
        fn_1_3EFF0((u32)fn_8_CF94, 1);
        fn_1_3F02C((u32)fn_8_D020);
        fn_1_3EF08(0);
        fn_1_14A1AC(lbl_1_bss_8E51D.unk_0);
        fn_1_14BC40();
        fn_1_1554D0();
        fn_1_1555B0(p_lbl_8_bss_540->unk_0);
        p_lbl_8_bss_540->unk_8 = 1020;
        p_lbl_8_bss_540->unk_C = 0;
        fn_1_47F74(149);
        fn_1_47F74(151);
        fn_1_47F74(152);
    }
    count = p_lbl_8_bss_540->unk_4;
    p_lbl_8_bss_540->unk_4 = count - 1;
    if (count <= 0) {
        if (p_lbl_8_bss_540->unk_C == 0) {
            idx = p_lbl_8_bss_540->unk_8;
            if ((f64)idx == (989.0)) fn_1_A2D84(0xA9121C00);
        }
        if (p_lbl_8_bss_540->unk_C == 0) {
            idx = p_lbl_8_bss_540->unk_8;
            if ((f64)idx < (795.0)) {
                curve = ((f64)idx - (795.0)) / (15.0);
            } else if ((f64)idx > (975.0)) {
                curve = ((f64)idx - (975.0)) / (15.0);
            } else {
                curve = (0.0);
            }
            amount = (f32)((320.0) + (f64)((640.0) * curve));
            flag = 0;
            if ((f64)idx >= (780.0)) {
                if ((990.0) < (f64)idx) flag = 1;
            }
            if (flag) {
                t = (0.0);
            } else {
                flag2 = 0;
                if ((795.0) < (f64)idx &&
                    (f64)idx < (975.0)) flag2 = 1;
                if (flag2) {
                    t = 1.0;
                    t = ((f64)idx - (780.0)) / (15.0);
                } else {
                    if ((780.0) <= (f64)idx &&
                        (f64)idx <= (795.0)) {
                        t = 1.0;
                        t = ((f64)idx - (780.0)) / (15.0);
                    } else {
                        t = ((990.0) - (f64)idx) / (15.0);
                    }
                }
            }
            alpha = (f32)t;
            alpha *= alpha;
            fn_1_49410();
            fn_1_495B0(0x80000000);
            fn_1_49590((0.5f));
            fn_1_495C8(9);
            fn_1_496FC(amount, (240.0f));
            fn_1_4954C((0.0f));
            if ((s32)lbl_801A66B4 == 5) fn_1_4955C((1.0f), (1.0f));
            else fn_1_4955C((0.833333313f), (0.833333313f));
            fn_1_495A0(alpha);
            fn_1_4D0A0();
            fn_1_49738((u32)fn_1_5233C);
            fn_1_49748((5.0f));
            fn_1_4A0D8((const char *)fn_8_D034_array_read(colors)[lbl_801A66B4]);
}
            color = fzgx_pool_table7[0];
            ((u8 *)&color)[3] = (u8)((255.0f) * alpha);
            fn_1_4D0D4(&color, (20.0f));
        }
    }
    fn_1_14BCBC(0);
    if ((fn_8_D034_array_read_(lbl_1_bss_9F8)[0x1c/2] & 0x1000) || (fn_8_D034_array_read_(lbl_1_bss_9F8)[0x1c/2] & 0x2000) ||
        (fn_8_D034_array_read_(lbl_1_bss_9F8)[0x1c/2] & 1) || (fn_8_D034_array_read_(lbl_1_bss_9F8)[0x1c/2] & 0x4000) ||
        (fn_8_D034_array_read_(lbl_1_bss_9F8)[8/2] & 0x100) || (fn_8_D034_array_read_(lbl_1_bss_9F8)[8/2] & 0x400) ||
        (fn_8_D034_array_read_(lbl_1_bss_9F8)[8/2] & 0x800)) {
        if (p_lbl_8_bss_540->unk_C == 0) {
            idx = p_lbl_8_bss_540->unk_8;
            p_lbl_8_bss_540->unk_8 = (s32)((f64)idx + (1800.0));
            p_lbl_8_bss_540->unk_C = 1;
        }
    }
    fn_1_144F40(10);
    if (fn_1_3F038()) lbl_1_bss_96A = 0x9e;
    else {
        count = p_lbl_8_bss_540->unk_8;
        p_lbl_8_bss_540->unk_8 = count - 1;
        if (count < 0) {
            fn_8006CE1C((1.0f));
            fn_1_3F894();
        }
    }
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

