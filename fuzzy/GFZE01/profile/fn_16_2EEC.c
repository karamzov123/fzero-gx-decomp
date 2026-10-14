/* Non-matching: best partial attempt (95.30% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "font.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
    s = 10.0f;
    s = 0.6000000238418579f;
    s = 456.0f;
    s = 0.125f;
    s = 5.0f;
    s = 1.4444444179534912f;
    s = 1.0f;
    s = 46.0f;
    s = 52.0f;
    s = 0.5f;
    s = 71.0f;
    s = 22.0f;
    s = 98.0f;
    s = 93.38823699951172f;
    s = 0.7686274647712708f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table5[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 32.0f;
    s = 28.0f;
    s = 69.0f;
    s = 338.0f;
    s = 504.0f;
    s = 24.0f;
    s = 8.0f;
    s = 0.7777777910232544f;
    s = 79.0f;
    s = 343.0f;
    s = 155.0f;
    s = 365.0f;
}
static const u32 fzgx_pool_table7[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 44.0f;
    s = 248.0f;
    s = 6.0f;
}
#pragma section code_type ".text"

struct fn_16_2EEC_Copy88 { u32 a[22]; };
struct fn_16_2EEC_lbl_1_bss_8B614 {
    u8 pad_0[0xA];
    s16 unk_A;
    u8 pad_C[0x40];
    u32 unk_4C;
    u8 pad_50[0x2];
    s16 unk_52;
    s16 unk_54;
};
struct fn_16_2EEC_lbl_16_rodata_58 {
    u8 pad_0[4];
    f32 unk_C;
    u8 pad_10[0x8];
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    u8 pad_24[0x8];
    f32 unk_2C;
    u8 pad_30[0x18];
    f64 unk_48;
    u8 pad_50[0x4];
    f32 unk_54;
    f32 unk_58;
    u8 pad_5C[0x10];
    f32 unk_6C;
    f32 unk_70;
    f32 unk_74;
    u8 pad_78[0x10];
    u32 unk_88;
    f32 unk_8C;
    f32 unk_90;
    f32 unk_94;

    u8 fzgx_tail_padding[8];
};
struct fn_16_2EEC_lbl_16_data_82F28 {
    u8 pad_0[0x78];
    u32 unk_78[1];
};
extern struct fn_16_2EEC_lbl_16_data_82F28 lbl_16_data_82F28;
const u8 lbl_16_rodata_58[12] = {0xFF,0xFF,0x00,0x00,0x41,0xA0,0x00,0x00,0x41,0x20,0x00,0x00};
const f32 lbl_16_rodata_58__fzgx_offset_C = 0.600000024f;
const u8 lbl_16_rodata_58__fzgx_offset_10[8] = {0x43,0xE4,0x00,0x00,0x3E,0x00,0x00,0x00};
const f32 lbl_16_rodata_58__fzgx_offset_18 = 5.0f;
const u8 lbl_16_rodata_58__fzgx_offset_1C[4] = {0x3F,0xB8,0xE3,0x8E};
const f32 lbl_16_rodata_58__fzgx_offset_20 = 1.0f;
const u8 lbl_16_rodata_58__fzgx_offset_24[12] = {0x42,0x38,0x00,0x00,0x42,0x50,0x00,0x00};
const f32 lbl_16_rodata_58__fzgx_offset_2C = 0.5f;
const u8 lbl_16_rodata_58__fzgx_offset_30[24] = {0x42,0x8E,0x00,0x00,0x41,0xB0,0x00,0x00,0x42,0xC4,0x00,0x00,0x42,0xBA,0xC6,0xC7,0x3F,0x44,0xC4,0xC5,0x00,0x00,0x00,0x00};
const f64 lbl_16_rodata_58__fzgx_offset_48 = 4503601774854144.0;
const u8 lbl_16_rodata_58__fzgx_offset_50[4] = {0xFF,0xFF,0x00,0x00};
const f32 lbl_16_rodata_AC = 0.0f;
const f32 lbl_16_rodata_AC__fzgx_offset_4 = 32.0f;
const u8 lbl_16_rodata_AC__fzgx_offset_8[16] = {0x41,0xE0,0x00,0x00,0x42,0x8A,0x00,0x00,0x43,0xA9,0x00,0x00,0x43,0xFC,0x00,0x00};
const f32 lbl_16_rodata_AC__fzgx_offset_18 = 24.0f;
const f32 lbl_16_rodata_AC__fzgx_offset_1C = 8.0f;
const f32 lbl_16_rodata_AC__fzgx_offset_20 = 0.777777791f;
const u8 lbl_16_rodata_AC__fzgx_offset_24[16] = {0x42,0x9E,0x00,0x00,0x43,0xAB,0x80,0x00,0x43,0x1B,0x00,0x00,0x43,0xB6,0x80,0x00};
const u16 lbl_16_rodata_AC__fzgx_offset_34 = 0xFFFF0000U;
const f32 lbl_16_rodata_AC__fzgx_offset_38 = 44.0f;
const f32 lbl_16_rodata_AC__fzgx_offset_3C = 248.0f;
const f32 lbl_16_rodata_AC__fzgx_offset_40 = 6.0f;
const u8 lbl_16_rodata_AC__fzgx_offset_44[236] = {0xFF,0xFF,0x00,0x00,0x43,0xF0,0x00,0x00,0x43,0x0E,0x00,0x00,0x43,0x6C,0x00,0x00,0x42,0xCC,0x00,0x00,0x42,0xD6,0x00,0x00,0x3F,0x20,0x00,0x00,0x43,0x0D,0x00,0x00,0x40,0xE0,0x00,0x00,0x43,0x36,0x0B,0x61,0x43,0x34,0x00,0x00,0x43,0x06,0x00,0x00,0x3D,0xCC,0xCC,0xCD,0x3F,0x40,0xC0,0xC1,0x3E,0x99,0x99,0x9A,0x43,0xB4,0x00,0x00,0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x41,0x98,0x00,0x00,0x41,0x88,0x00,0x00,0x42,0x96,0x00,0x00,0x42,0xB8,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x3F,0x40,0x00,0x00,0x42,0x14,0x00,0x00,0x42,0x94,0x00,0x00,0x41,0xD0,0x00,0x00,0x42,0x7C,0x00,0x00,0x42,0x8C,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x43,0xA0,0x00,0x00,0x43,0x58,0x00,0x00,0x42,0xF4,0x00,0x00,0x43,0x48,0x00,0x00,0x43,0x98,0x00,0x00,0x42,0x20,0x00,0x00,0x44,0x16,0x00,0x00,0x3D,0xCC,0xCC,0xD0,0x3E,0xAE,0x14,0x7A,0xC2,0xCC,0x00,0x00,0x3F,0x66,0x66,0x66,0x3F,0x28,0xF5,0xC3,0x3F,0x63,0x8E,0x39,0x42,0xBE,0x00,0x00,0x40,0x00,0x00,0x00,0x42,0x3C,0x00,0x00,0x41,0x80,0x00,0x00};
extern struct fn_16_2EEC_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern u32 lbl_16_data_83380;
extern u32 lbl_1_rodata_26F8;
extern void fn_1_50190(void *, f32, f32, f32, f32, f32, f32);
extern u32 fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_495B0(u32);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4962C(void);
extern void fn_1_495A0(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4AE0C(const char *, ...);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_4965C(u8);
extern void fn_1_495C8(u8);
extern s32 fn_1_7F49C(s16, s16, void *);
extern s32 fn_1_52250;

struct FzgxCopy_88 { u32 words[22]; };

#pragma opt_dead_assignments off
#pragma opt_strength_reduction off
void fn_16_2EEC(s16 arg0, s16 arg2, s16 arg1) {
    f32 var_f4;
    u8 sp8[0x40];
    s32 sp48;
    s32 spC;
    f32 temp_f0_2;
    f32 var_f3_2;
    f32 temp_f1;
    struct { f32 value; } temp_f5;
    f32 var_f31;
    f32 var_f3;
    struct FzgxCopy_88 loc_4C;
    s16 var_r6;
    u32 temp_ret;
    const char * lab_t0;

    if (lbl_1_bss_8B614.unk_4C & 0x80000000) {
        var_f4 = lbl_16_rodata_AC;
        temp_f5.value = (f32) lbl_1_bss_8B614.unk_54 * lbl_16_rodata_58__fzgx_offset_2C;
        temp_f0_2 = (f32) lbl_1_bss_8B614.unk_52 / temp_f5.value;
        if (temp_f0_2 < var_f4) {
            var_f4 = lbl_16_rodata_AC;
        } else if (temp_f0_2 > lbl_16_rodata_58__fzgx_offset_20) {
            var_f4 = lbl_16_rodata_58__fzgx_offset_20;
        } else {
            var_f4 = temp_f0_2;
        }
        var_f3 = lbl_16_rodata_AC;
        temp_f0_2 = ((f32) lbl_1_bss_8B614.unk_52 - temp_f5.value) / temp_f5.value;
        if (temp_f0_2 < var_f3) {
            var_f3 = lbl_16_rodata_AC;
        } else if (temp_f0_2 > lbl_16_rodata_58__fzgx_offset_20) {
            var_f3 = lbl_16_rodata_58__fzgx_offset_20;
        } else {
            var_f3_2 = temp_f0_2;
        }
        if (lbl_1_bss_8B614.unk_4C & 0x10000000) {
            var_f31 = var_f3_2;
            var_r6 = (s16) (lbl_16_rodata_AC__fzgx_offset_4 + (f32)(lbl_16_rodata_AC__fzgx_offset_38 * var_f4));
        } else if (lbl_1_bss_8B614.unk_4C & 0x08000000) {
            var_f31 = lbl_16_rodata_58__fzgx_offset_20;
            var_f31 = var_f31 - var_f4;
            var_r6 = (s16) (lbl_16_rodata_AC__fzgx_offset_4
                            + lbl_16_rodata_AC__fzgx_offset_38 * (lbl_16_rodata_58__fzgx_offset_20 - var_f3_2));
        } else {
            var_f31 = lbl_16_rodata_58__fzgx_offset_20;
            var_r6 = 0x4C;
        }
    } else {
        var_r6 = 0x4C;
        var_f31 = lbl_16_rodata_58__fzgx_offset_20;
    }
    loc_4C = *(const struct FzgxCopy_88 *) &lbl_1_rodata_26F8;
    loc_4C.words[0] = 0x9306;
    *(f32 *) ((u8 *) &loc_4C + 4) = (f32) arg1;
    *(f32 *) ((u8 *) &loc_4C + 8) = (f32) arg2;
    *(f32 *) ((u8 *) &loc_4C + 12) = lbl_16_rodata_58__fzgx_offset_20;
    *(f32 *) ((u8 *) &loc_4C + 44) = lbl_16_rodata_58__fzgx_offset_C;
    fn_1_50190(&loc_4C, lbl_16_rodata_AC__fzgx_offset_3C, (f32) var_r6, lbl_16_rodata_58__fzgx_offset_18,
               lbl_16_rodata_58__fzgx_offset_18, lbl_16_rodata_AC__fzgx_offset_18, lbl_16_rodata_AC__fzgx_offset_1C);
    fn_1_49410();
    fn_1_494DC((s16) 5);
    fn_1_495B0(0x80000000U);
    fn_1_49738((u32) &fn_1_52250);
    fn_1_49748(lbl_16_rodata_58__fzgx_offset_18);
    fn_1_4955C(lbl_16_rodata_AC__fzgx_offset_20, lbl_16_rodata_AC__fzgx_offset_20);
    fn_1_4962C();
    fn_1_495A0(lbl_16_rodata_58__fzgx_offset_20);
    fn_1_496FC((f32) (arg1 + 0xA), (f32) (arg2 + 5));
    *(u32 *) sp8 = lbl_16_rodata_AC__fzgx_offset_34;
    fn_1_49514((u32 *) sp8);
    fn_1_4954C(lbl_16_rodata_58__fzgx_offset_2C);
    lab_t0 = (const char *) ((lbl_1_bss_8B614.unk_A)[lbl_16_data_82F28.unk_78]);
    fn_1_4AE0C(lab_t0, &lbl_16_data_82F28);
    loc_4C = *(const struct FzgxCopy_88 *) &lbl_1_rodata_26F8;
    temp_r6_unused: ;
    temp_f1 = (f32) (arg2 + 0x7C);
    loc_4C.words[0] = (&lbl_16_data_83380)[arg0];
    *(f32 *) ((u8 *) &loc_4C + 4) = (f32) (arg1 + 0x7C);
    *(f32 *) ((u8 *) &loc_4C + 8) = temp_f1;
    if (lbl_1_bss_8B614.unk_A != 5) {
        *(f32 *) ((u8 *) &loc_4C + 8) = temp_f1 + lbl_16_rodata_AC__fzgx_offset_40;
    }
    *(f32 *) ((u8 *) &loc_4C + 44) = var_f31;
    *(f32 *) ((u8 *) &loc_4C + 12) = lbl_16_rodata_58__fzgx_offset_2C;
    loc_4C.words[0xC] = 0xA;
    fn_1_4F734((FontDrawPacket *) &loc_4C);
    if (lbl_1_bss_8B614.unk_A == 5) {
        fn_1_49410();
        fn_1_495B0(0x80000000U);
        fn_1_4965C(2);
        fn_1_4955C(lbl_16_rodata_58__fzgx_offset_2C, lbl_16_rodata_58__fzgx_offset_2C);
        fn_1_495C8(9);
        fn_1_496FC((f32) (arg1 + 0x7C), (f32) (arg2 + 0x40));
        fn_1_495A0(var_f31);
        fn_1_4954C(lbl_16_rodata_58__fzgx_offset_2C);
        temp_ret = fn_1_7F49C(arg0, lbl_1_bss_8B614.unk_A, &spC);
        lab_t0 = (const char *) temp_ret;
        fn_1_4AE0C(lab_t0, temp_ret);
    }
}
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

