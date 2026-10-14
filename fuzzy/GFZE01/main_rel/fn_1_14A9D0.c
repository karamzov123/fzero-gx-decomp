/* Non-matching: best partial attempt (95.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[95] = {0x82A082A2, 0x82A482A6, 0x82A882A9, 0x82AB82AD, 0x82AF82B1, 0x82B382B5, 0x82B782B9, 0x82BB82BD, 0x82BF82C2, 0x82C482C6, 0x82C882C9, 0x82CA82CB, 0x82CC82CD, 0x82D082D3, 0x82D682D9, 0x82DC82DD, 0x82DE82DF, 0x82E082E2, 0x82E482E6, 0x82E782E8, 0x82E982EA, 0x82EB82ED, 0x82EE82EF, 0x82F082F1, 0x82A482AA, 0x82AC82AE, 0x82B082B2, 0x82B482B6, 0x82B882BA, 0x82BC82BE, 0x82C082C3, 0x82C582C7, 0x82CE82D1, 0x82D482D7, 0x82DA82CF, 0x82D282D5, 0x82D882DB, 0x829F82A1, 0x82A382A5, 0x82A782C1, 0x82E182E3, 0x82E582EC, 0x00000000, 0x83418343, 0x83458347, 0x8349834A, 0x834C834E, 0x83508352, 0x83548356, 0x8358835A, 0x835C835E, 0x83608363, 0x83658367, 0x8369836A, 0x836B836C, 0x836D836E, 0x83718374, 0x8377837A, 0x837D837E, 0x83808381, 0x83828384, 0x83868388, 0x8389838A, 0x838B838C, 0x838D838F, 0x83908391, 0x83928393, 0x8394834B, 0x834D834F, 0x83518353, 0x83558357, 0x8359835B, 0x835D835F, 0x83618364, 0x83668368, 0x836F8372, 0x83758378, 0x837B8370, 0x83738376, 0x8379837C, 0x83408342, 0x83448346, 0x83488362, 0x83838385, 0x8387838E, 0x00000000, 0x81968196, 0x81960000, 0x83478374, 0x835B838D, 0x00000000, 0x8265817C, 0x82798264, 0x8271826E, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    d = 4503599627370496.0;
    d = 4503601774854144.0;
    s = 0.20000000298023224f;
    s = 0.10000000149011612f;
    s = 0.05999999865889549f;
    s = 0.014999999664723873f;
    s = -0.10000000149011612f;
    s = 0.05000000074505806f;
    s = -0.05000000074505806f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

struct fn_1_14A9D0_lbl_1_bss_8E518 {
    u8 pad_0[0x4];
    u8 unk_4;
    u8 pad_5[0xB];
    u32 unk_10;
    u8 pad_14[0x4];
    u32 unk_18;
    f32 unk_1C;
    u32 unk_20;
    f32 unk_24;
    u8 pad_28[0x8];
    u8 unk_30;
    u8 pad_31[0x3];
    f32 unk_34;
    u8 unk_38;
    u8 pad_39[0x3];
    u32 unk_3C;
};
struct fn_1_14A9D0_lbl_1_bss_9F8 {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
};
struct fn_1_14A9D0_lbl_1_rodata_9828 {
    u8 pad_0[0x17C];
    f32 unk_17C;
    u8 pad_180[0x8];
    f64 unk_188;
    f32 unk_190;
    f32 unk_194;
    f32 unk_198;
    f32 unk_19C;
    f32 unk_1A0;
    f32 unk_1A4;
    f32 unk_1A8;
};
extern struct fn_1_14A9D0_lbl_1_bss_8E518 lbl_1_bss_8E518;
extern struct fn_1_14A9D0_lbl_1_bss_9F8 lbl_1_bss_9F8;
const u8 lbl_1_rodata_9828[172] = {0x82,0xA0,0x82,0xA2,0x82,0xA4,0x82,0xA6,0x82,0xA8,0x82,0xA9,0x82,0xAB,0x82,0xAD,0x82,0xAF,0x82,0xB1,0x82,0xB3,0x82,0xB5,0x82,0xB7,0x82,0xB9,0x82,0xBB,0x82,0xBD,0x82,0xBF,0x82,0xC2,0x82,0xC4,0x82,0xC6,0x82,0xC8,0x82,0xC9,0x82,0xCA,0x82,0xCB,0x82,0xCC,0x82,0xCD,0x82,0xD0,0x82,0xD3,0x82,0xD6,0x82,0xD9,0x82,0xDC,0x82,0xDD,0x82,0xDE,0x82,0xDF,0x82,0xE0,0x82,0xE2,0x82,0xE4,0x82,0xE6,0x82,0xE7,0x82,0xE8,0x82,0xE9,0x82,0xEA,0x82,0xEB,0x82,0xED,0x82,0xEE,0x82,0xEF,0x82,0xF0,0x82,0xF1,0x82,0xA4,0x82,0xAA,0x82,0xAC,0x82,0xAE,0x82,0xB0,0x82,0xB2,0x82,0xB4,0x82,0xB6,0x82,0xB8,0x82,0xBA,0x82,0xBC,0x82,0xBE,0x82,0xC0,0x82,0xC3,0x82,0xC5,0x82,0xC7,0x82,0xCE,0x82,0xD1,0x82,0xD4,0x82,0xD7,0x82,0xDA,0x82,0xCF,0x82,0xD2,0x82,0xD5,0x82,0xD8,0x82,0xDB,0x82,0x9F,0x82,0xA1,0x82,0xA3,0x82,0xA5,0x82,0xA7,0x82,0xC1,0x82,0xE1,0x82,0xE3,0x82,0xE5,0x82,0xEC,0x00,0x00,0x00,0x00};
const u8 lbl_1_rodata_98D4[208] = {0x83,0x41,0x83,0x43,0x83,0x45,0x83,0x47,0x83,0x49,0x83,0x4A,0x83,0x4C,0x83,0x4E,0x83,0x50,0x83,0x52,0x83,0x54,0x83,0x56,0x83,0x58,0x83,0x5A,0x83,0x5C,0x83,0x5E,0x83,0x60,0x83,0x63,0x83,0x65,0x83,0x67,0x83,0x69,0x83,0x6A,0x83,0x6B,0x83,0x6C,0x83,0x6D,0x83,0x6E,0x83,0x71,0x83,0x74,0x83,0x77,0x83,0x7A,0x83,0x7D,0x83,0x7E,0x83,0x80,0x83,0x81,0x83,0x82,0x83,0x84,0x83,0x86,0x83,0x88,0x83,0x89,0x83,0x8A,0x83,0x8B,0x83,0x8C,0x83,0x8D,0x83,0x8F,0x83,0x90,0x83,0x91,0x83,0x92,0x83,0x93,0x83,0x94,0x83,0x4B,0x83,0x4D,0x83,0x4F,0x83,0x51,0x83,0x53,0x83,0x55,0x83,0x57,0x83,0x59,0x83,0x5B,0x83,0x5D,0x83,0x5F,0x83,0x61,0x83,0x64,0x83,0x66,0x83,0x68,0x83,0x6F,0x83,0x72,0x83,0x75,0x83,0x78,0x83,0x7B,0x83,0x70,0x83,0x73,0x83,0x76,0x83,0x79,0x83,0x7C,0x83,0x40,0x83,0x42,0x83,0x44,0x83,0x46,0x83,0x48,0x83,0x62,0x83,0x83,0x83,0x85,0x83,0x87,0x83,0x8E,0x00,0x00,0x00,0x00,0x81,0x96,0x81,0x96,0x81,0x96,0x00,0x00,0x83,0x47,0x83,0x74,0x83,0x5B,0x83,0x8D,0x00,0x00,0x00,0x00,0x82,0x65,0x81,0x7C,0x82,0x79,0x82,0x64,0x82,0x71,0x82,0x6E,0x00,0x00,0x00,0x00};
const f32 lbl_1_rodata_99A4 = 0.0f;
const u8 lbl_1_rodata_99A8[8] = {0x43,0x30,0x00,0x00,0x00,0x00,0x00,0x00};
const f64 lbl_1_rodata_99B0 = 4503601774854144.0;
const f32 lbl_1_rodata_99B0__fzgx_offset_8 = 0.200000003f;
const f32 lbl_1_rodata_99B0__fzgx_offset_C = 0.100000001f;
const f32 lbl_1_rodata_99B0__fzgx_offset_10 = 0.0599999987f;
const f32 lbl_1_rodata_99B0__fzgx_offset_14 = 0.0149999997f;
const f32 lbl_1_rodata_99B0__fzgx_offset_18 = -0.100000001f;
const f32 lbl_1_rodata_99B0__fzgx_offset_1C = 0.0500000007f;
const f32 lbl_1_rodata_99B0__fzgx_offset_20 = -0.0500000007f;
const u8 lbl_1_rodata_99B0__fzgx_offset_24[4] = {0x00,0x00,0x00,0x00};
extern u32 lbl_801A66A4;
extern void fn_1_A2D84(u32);

#pragma opt_common_subs off
u32 fn_1_14A9D0(u8 arg0, s32 arg1, u32 arg2, u32 arg3, s32 arg4, s32 arg5, u8 arg6) {
    struct fn_1_14A9D0_lbl_1_rodata_9828 *q;
    struct fn_1_14A9D0_lbl_1_bss_8E518 *p;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r4_3;
    u32 temp_r3_2;
    s32 temp_r3_4;
    u8 *var_r29;
    u8 *var_r28;
    s32 var_r0;
    u32 var_r0_2;
    f32 var_f0;
    f32 var_f4_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 var_f2_4;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f0_2;
    f32 var_f2_3;
    f32 temp_f3_3;
    f32 var_f1;
    f32 var_f4;

    p = &lbl_1_bss_8E518;
    
    p = &lbl_1_bss_8E518;
    p->unk_38 = arg0;
    p->unk_3C = arg3;
    if (arg5 != 0) {
        var_r29 = (u8 *)p + 28;
        var_r28 = (u8 *)p + 36;
    } else {
        var_r29 = (u8 *)p + 24;
        var_r28 = (u8 *)p + 32;
    }
    if ((lbl_801A66A4 - p->unk_10) > arg3) {
        if (((lbl_1_bss_9F8.unk_10 >> 3) & 1) || ((lbl_1_bss_9F8.unk_12 >> 3) & 1)) {
            temp_r4 = *(s32 *)(var_r28);
            if (temp_r4 > 0) {
                *(s32 *)(var_r28) = temp_r4 - 1;
                fn_1_A2D84(0xA9010400U);
            }
        } else if (((lbl_1_bss_9F8.unk_10 >> 2) & 1) || ((lbl_1_bss_9F8.unk_12 >> 2) & 1)) {
            temp_r4 = *(s32 *)(var_r28);
            if (temp_r4 < (s32)(p->unk_38 - p->unk_30)) {
                *(s32 *)(var_r28) = temp_r4 + 1;
                fn_1_A2D84(0xA9010400U);
            }
        }
    }
    temp_r3_2 = lbl_801A66A4 - p->unk_10;
    if (temp_r3_2 > arg2) {
        if (temp_r3_2 >= (*(u32 volatile *)&(p->unk_3C)) /* Retail reloads this field. */) {
            temp_f3 = *(f32 *)(var_r29);
            var_f4 = (0.0f);
            var_f0 = (0.200000003f) * ((f32)(s32)*(s32 *)(var_r28) - temp_f3);
            *(f32 *)(var_r29) = temp_f3 + var_f0;
            var_f2 = *(f32 *)(var_r29);
            if (var_f2 >= var_f4) {
                temp_r4 = p->unk_38 - p->unk_30;
                if (var_f2 > (f32)temp_r4) {
                    var_f2 = (f32)temp_r4;
                }
                var_f4 = var_f2;
            }
            *(f32 *)(var_r29) = var_f4;
            temp_r4_2 = *(s32 *)(var_r28);
            temp_f3_2 = *(f32 *)(var_r29);
            if (temp_f3_2 > ((f32)temp_r4_2 + (0.100000001f))) {
                var_r0 = 0;
            } else if (temp_f3_2 < ((f32)temp_r4_2 - (0.100000001f))) {
                var_r0 = 0;
            } else {
                var_r0 = 1;
            }
            if (var_r0 == 0) {
                *(f32 *)(var_r29) = (f32)temp_r4_2;
            }
        } else if (arg1 != 0) {
            if (p->unk_4 != 0) {
                var_f4_2 = (0.0599999987f);
            } else {
                var_f4_2 = (0.0149999997f);
            }
            var_f1 = var_f4_2 * ((f32)(s32)*(s32 *)(var_r28) - *(f32 *)(var_r29));
            if (var_f1 < (0.0f)) {
                if (var_f1 > (-0.100000001f)) {
                    var_f1 = (-0.100000001f);
                }
            } else if (var_f1 < (0.100000001f)) {
                var_f1 = (0.100000001f);
            }
            *(f32 *)(var_r29) = *(f32 *)(var_r29) + var_f1;
        } else {
            temp_r3_4 = *(s32 *)(var_r28);
            temp_f3_3 = *(f32 *)(var_r29);
            if ((f32)temp_r3_4 > temp_f3_3) {
                var_f2_2 = temp_f3_3;
                var_f2_2 += (0.0500000007f);
                if (var_f2_2 >= (f32)temp_r3_4) {
                    var_f2_2 = (f32)temp_r3_4;
                } else {
                }
                *(f32 *)(var_r29) = var_f2_2;
            } else if ((f32)temp_r3_4 < temp_f3_3) {
                var_f2_3 = temp_f3_3;
                var_f2_3 += (-0.0500000007f);
                if (var_f2_3 <= (f32)temp_r3_4) {
                    var_f2_3 = (f32)temp_r3_4;
                } else {
                }
                *(f32 *)(var_r29) = var_f2_3;
            }
        }
        var_f2_4 = *(f32 *)(var_r29);
        var_f0_2 = (0.0f);
        if (var_f2_4 < var_f0_2) {
        } else {
            temp_r4_3 = p->unk_38 - p->unk_30;
            if (var_f2_4 > (f32)temp_r4_3) {
                var_f2_4 = (f32)temp_r4_3;
            }
            var_f0_2 = var_f2_4;
        }
        *(f32 *)(var_r29) = var_f0_2;
        if ((s32)p->unk_34 != (s32)*(f32 *)(var_r29)) {
            fn_1_A2D84(0xA9010500U);
        }
        p->unk_34 = *(f32 *)(var_r29);
        temp_r4_3 = *(s32 *)(var_r28);
        temp_f3_3 = *(f32 *)(var_r29);
        if (temp_f3_3 > ((f32)temp_r4_3 + (0.100000001f))) {
            var_r0_2 = 0;
        } else if (temp_f3_3 < ((f32)temp_r4_3 - (0.100000001f))) {
            var_r0_2 = 0;
        } else {
            var_r0_2 = 1;
        }
        if (var_r0_2 != 0) {
            *(f32 *)(var_r29) = (f32)temp_r4_3;
            p->unk_10 = lbl_801A66A4 - (*(u32 volatile *)&(p->unk_3C)) /* Retail reloads this field. */;
        }
    }
    if (arg4) {
    }
    return (u32)var_r0_2;
}
#pragma opt_common_subs reset

