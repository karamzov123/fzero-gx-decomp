/* Non-matching: best partial attempt (97.52% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_15_3B24_lbl_15_bss_0 {
    u8 pad_0[0x14];
    u32 unk_14;
    u8 pad_18[0x9];
    u8 unk_21;
    u8 pad_22[0x2];
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u8 pad_30[0x4];
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 pad_37[0x3];
    s16 unk_3A;
    u8 pad_3C[0x2];
    u8 unk_3E;
    u8 pad_3F[0xD];
    u32 unk_4C;
    u8 pad_50[0x100];
    u32 unk_150;
};

struct fn_15_3B24_lbl_15_rodata_0 {
    f32 unk_0;
    u8 pad_4[0x54];
    f32 unk_58;
    f32 unk_5C;
    u8 pad_60[0xA4];
    f32 unk_104;
    f32 unk_108;
    f32 unk_10C;
    f32 unk_110;
};

struct fn_15_3B24_lbl_801A6410 {
    u32 unk_0;
};

extern s32 fn_1_3F8C(void *, void *, void *, u32);
extern s32 fn_1_45D0(u32, u32, void *, u32);
const f32 lbl_15_rodata_0 = 0.0f;
const u8 lbl_15_rodata_0__fzgx_offset_4[84] = {0x00,0xFF,0x00,0xFF,0x80,0x80,0x80,0xFF,0xFF,0xFF,0xFF,0xFF,0xC3,0xAC,0xEF,0x3B,0x43,0xFC,0x72,0x8F,0x44,0x24,0x14,0x08,0xC3,0xAD,0x35,0xA2,0x43,0xFE,0x58,0xB4,0x44,0x24,0x3F,0xBE,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xC3,0xAC,0xEF,0x3B,0x43,0xFC,0x72,0x8F,0x44,0x24,0x14,0x08,0xC3,0xAD,0x35,0xA2,0x43,0xFE,0x58,0xB4,0x44,0x24,0x3F,0xBE,0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00};
const f32 lbl_15_rodata_0__fzgx_offset_58 = 200.0f;
const f32 lbl_15_rodata_0__fzgx_offset_5C = 1.0f;
const u8 lbl_15_rodata_0__fzgx_offset_60[4] = {0xFF,0xC8,0x00,0xFF};
const u8 lbl_15_rodata_64[44] = {0x41,0xF0,0x00,0x00,0x3F,0x84,0x7A,0xE1,0x47,0xAE,0x14,0x7B,0x40,0x00,0x00,0x00,0x43,0xA0,0x00,0x00,0x43,0x70,0x00,0x00,0x41,0xA0,0x00,0x00,0x41,0x20,0x00,0x00,0x3F,0x00,0x00,0x00,0x40,0x40,0x00,0x00,0x3D,0x23,0xD7,0x0A};
const u8 lbl_15_rodata_90[8] = {0x43,0x30,0x00,0x00,0x80,0x00,0x00,0x00};
const u8 lbl_15_rodata_98[12] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0x48,0x00,0x00};
const u8 lbl_15_rodata_A4[44] = {0x3F,0x19,0x99,0x9A,0x00,0x00,0x00,0xFF,0x40,0x40,0x40,0xFF,0x40,0x40,0x88,0xFF,0xAA,0xAA,0xAA,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xC0,0x00,0x00,0xBF,0x66,0x66,0x66};
const u8 lbl_15_rodata_D0[8] = {0x00,0x00,0x00,0x03,0x00,0x04,0x00,0x06};
const u8 lbl_15_rodata_D8[44] = {0x00,0x00,0x00,0x00,0x3F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0xBF,0xC0,0x00,0x00,0xC0,0x10,0x00,0x00,0xC0,0x00,0x00,0x00,0x3E,0x4C,0xCC,0xCD,0xBE,0x4C,0xCC,0xCD,0xC0,0x0C,0xCC,0xCD,0x41,0x10,0x00,0x00,0x3F,0x85,0x1E,0xB8};
const f32 lbl_15_rodata_D8__fzgx_offset_2C = 1000.0f;
const f32 lbl_15_rodata_D8__fzgx_offset_30 = 4.0f;
const f32 lbl_15_rodata_D8__fzgx_offset_34 = 5.0f;
const f32 lbl_15_rodata_D8__fzgx_offset_38 = -4.0f;
extern struct fn_15_3B24_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_3CF0(void *, u32);
extern u32 fn_1_4630(u32, u32, void *, u32);
extern u32 fn_1_584D4(void);
extern u32 fn_1_82724(void *, void *, void *, s16, u32);
extern u32 fn_1_83070(void *, u32, void *, s16);
extern u32 fn_1_C3A0C(void *);
extern u32 fn_1_C42F4(void);
extern s32 fn_1_FA004(void);
extern u32 fn_1_FA01C(void);
extern u32 fn_1_FA088(void);
extern u32 fn_1_FA0A0(void);
extern u32 lbl_1_data_28060;
extern u8 lbl_15_data_0[];
extern void * fn_1_435C(void *);
extern void * fn_1_86254(void *);
extern void * fn_1_868C0(s8);
extern void fn_1_4310(u32);
extern void fn_1_80058(s8, void *);
extern void fn_1_817C0(void);
extern void fn_1_81834(u8, s8, s8);
extern void fn_1_835E0(void *, void *, void *);
extern void fn_1_86194(f32);
extern void fn_1_861B4(void);
extern void fn_1_981C4(void);
extern void fn_1_98230(void);
extern void fn_1_9835C(void);
extern void fn_1_C6F80(u8);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_22E8C(void *, void *);

#pragma opt_common_subs off
#pragma opt_loop_invariants off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u16 fzgx_obj_lbl_15_bss_0;
u16 lbl_15_bss_0_gap_2;
u32 lbl_15_bss_4[2];
u32 lbl_15_bss_C;
u32 lbl_15_bss_10;
u32 fzgx_obj_lbl_15_bss_14;
u32 lbl_15_bss_14_fill_18;
u32 lbl_15_bss_1C;
u8 lbl_15_bss_1C_fill_20;
u8 lbl_15_bss_21;
u16 lbl_15_bss_21_fill_22;
u32 lbl_15_bss_21_3;
u32 lbl_15_bss_21_7;
s8 lbl_15_bss_2C;
u32 lbl_15_bss_2C_fill_30;
u8 lbl_15_bss_2C_8;
u8 lbl_15_bss_35;
u8 lbl_15_bss_35_1;
u8 lbl_15_bss_35_fill_37;
u16 lbl_15_bss_35_fill_38;
s16 lbl_15_bss_35_5;
u16 lbl_15_bss_35_fill_3C;
u8 lbl_15_bss_35_9;
u8 lbl_15_bss_35_fill_3F;
u32 lbl_15_bss_35_fill_40[3];
u32 lbl_15_bss_35_17;
u32 lbl_15_bss_35_fill_50[9];
u32 lbl_15_bss_74;
u32 lbl_15_bss_78[4];
u32 lbl_15_bss_88[5];
u32 lbl_15_bss_9C[13];
u8 lbl_15_bss_D0;
u8 lbl_15_bss_0_gap_D1;
u16 lbl_15_bss_0_gap_D1_fill_D2;
u32 lbl_15_bss_D4_fill_D4[31];
u32 lbl_15_bss_D4_7C;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_15_bss_0;
    s = *(u8 *)&lbl_15_bss_0_gap_2;
    s = *(u8 *)&lbl_15_bss_4;
    s = *(u8 *)&lbl_15_bss_C;
    s = *(u8 *)&lbl_15_bss_10;
    s = *(u8 *)&fzgx_obj_lbl_15_bss_14;
    s = *(u8 *)&lbl_15_bss_14_fill_18;
    s = *(u8 *)&lbl_15_bss_1C;
    s = *(u8 *)&lbl_15_bss_1C_fill_20;
    s = *(u8 *)&lbl_15_bss_21;
    s = *(u8 *)&lbl_15_bss_21_fill_22;
    s = *(u8 *)&lbl_15_bss_21_3;
    s = *(u8 *)&lbl_15_bss_21_7;
    s = *(u8 *)&lbl_15_bss_2C;
    s = *(u8 *)&lbl_15_bss_2C_fill_30;
    s = *(u8 *)&lbl_15_bss_2C_8;
    s = *(u8 *)&lbl_15_bss_35;
    s = *(u8 *)&lbl_15_bss_35_1;
    s = *(u8 *)&lbl_15_bss_35_fill_37;
    s = *(u8 *)&lbl_15_bss_35_fill_38;
    s = *(u8 *)&lbl_15_bss_35_5;
    s = *(u8 *)&lbl_15_bss_35_fill_3C;
    s = *(u8 *)&lbl_15_bss_35_9;
    s = *(u8 *)&lbl_15_bss_35_fill_3F;
    s = *(u8 *)&lbl_15_bss_35_fill_40;
    s = *(u8 *)&lbl_15_bss_35_17;
    s = *(u8 *)&lbl_15_bss_35_fill_50;
    s = *(u8 *)&lbl_15_bss_74;
    s = *(u8 *)&lbl_15_bss_78;
    s = *(u8 *)&lbl_15_bss_88;
    s = *(u8 *)&lbl_15_bss_9C;
    s = *(u8 *)&lbl_15_bss_D0;
    s = *(u8 *)&lbl_15_bss_0_gap_D1;
    s = *(u8 *)&lbl_15_bss_0_gap_D1_fill_D2;
    s = *(u8 *)&lbl_15_bss_D4_fill_D4;
    s = *(u8 *)&lbl_15_bss_D4_7C;
}
#pragma section code_type ".text"

static inline s32 fn_15_3B24_call_fn_1_45D0(u32 a3, void * a2, u32 a1, u32 a0) { return fn_1_45D0(a0, a1, a2, a3); }
#pragma opt_strength_reduction off
u32 fn_15_3B24(void) {
    void * v3;
    struct fn_15_3B24_lbl_15_rodata_0 *p_lbl_15_rodata_0;
    u32 v2;
    u32 v0;
    s32 v1;
    struct { u8 *value; } p_lbl_15_data_0;
    u32 v4;
    u32 v5;
    u32 v6;
    u32 v7;
    u32 v8;
    u32 v9;
    u32 t18;
    u32 v11;
    s32 v12;
    u32 v13;
    u32 v14;
    f32 v15;
    s16 v16;
    struct { u32 a[82]; } loc_8;
    void * v10;
    s32 t1;
    u32 t10;
    u32 t13;
    u32 t14;
    u32 t15;
    u32 t16;
    s32 t0;
    void * t25;
    void * t33;
    void * lab_t1;

    
    p_lbl_15_data_0.value = (u8 *)&lbl_15_data_0;
    v0 = lbl_15_bss_2C;
    lbl_15_bss_21 = 1;
    
    t0 = fn_1_45D0(lbl_801A6410.unk_0, 0x173C, p_lbl_15_data_0.value + 0xA4, 0xA4E);
    lbl_15_bss_21_3 = t0;
    t1 = fn_15_3B24_call_fn_1_45D0(0xA4F, p_lbl_15_data_0.value + 0xA4, 0x173C, lbl_801A6410.unk_0);
    lbl_15_bss_21_7 = t1;
    fn_1_3CF0((void *)lbl_15_bss_21_3, 128);
    fn_1_3CF0((void *)lbl_15_bss_21_7, 128);
    fn_1_981C4();
    fn_1_435C((void *)lbl_15_bss_21_3);
    lab_t1 = fn_1_98230;
    fn_1_3F8C(p_lbl_15_data_0.value + 0x2A8, lab_t1, (void *)0, 10);
    fn_1_435C((void *)lbl_15_bss_21_7);
    lab_t1 = fn_1_9835C;
    fn_1_3F8C(p_lbl_15_data_0.value + 0x2B0, lab_t1, (void *)0, 21);
    fn_1_584D4();
    t10 = fn_1_4630(lbl_801A6410.unk_0, 0x14B8, p_lbl_15_data_0.value + 0xA4, 0xA66);
    lbl_15_bss_D4_7C = t10;
    *(u32 *)((u8 *)t10 + 0) = ((*(u32 *)((u8 *)t10 + 0) | 0x200000) | 49216);
    v1 = 0;
    v2 = v0;
    v3 = &loc_8;
    v4 = t10;
    while ((s16)v1 < lbl_15_bss_35_5) {
        v4 = (s8)*(u8 *)((u8 *)v2 + 5);
        fn_1_80058(v4, (u8 *)v3);
        if ((fzgx_obj_lbl_15_bss_14 & 0x40) != 0) {
            v5 = *(u8 *)((u8 *)v0 + 248);
        } else {
            v5 = v1;
        }
        *(u16 *)((u8 *)v3 + 0) = v1;
        v4 = (v0 + ((s16)v5 << 3));
        *(u16 *)((u8 *)v3 + 2) = *(u8 *)((u8 *)v4 + 5);
        *(u8 *)((u8 *)v3 + 8) = *(u8 *)((u8 *)v4 + 6);
        v6 = ((31 - __cntlzw(*(u8 *)((u8 *)v3 + 8))) & 0x3);
        switch ((s32)v6) {
        case 0:
            *(u8 *)((u8 *)v3 + 8) = 16;
            break;
        case 1:
            *(u8 *)((u8 *)v3 + 8) = 32;
            break;
        case 2:
            *(u8 *)((u8 *)v3 + 8) = 64;
            break;
        case 3:
            *(u8 *)((u8 *)v3 + 8) = 128;
            break;
        default:
            *(u8 *)((u8 *)v3 + 8) = 16;
        }
        *(u32 *)((u8 *)v3 + 4) = 2;
        if (*(s16 *)((u8 *)v3 + 2) >= 41) {
            v7 = *(u32 *)((u8 *)v4 + 0);
            if (v7 != 0) {
                if ((*(u32 *)((u8 *)v7 + 0) & ~0x7FFFFFFF) != 0) {
                    v4 = (u32)((u8 *)v3 + 16);
                    fn_80008BEC((void *)v4, 0, 16);
                    if ((*(u32 *)((u8 *)v7 + 0) & 0x40000000) != 0) {
                        v4 = 1;
                        lbl_15_bss_35_9 = v4;
                        if ((s16)v5 == 0) {
                            t13 = fn_1_FA088();
                            v4 = t13;
                            if ((s32)v4 != 0) {
                                lbl_15_bss_2C_8 = 1;
                                lbl_15_bss_35_1 = 1;
                                t14 = fn_1_FA0A0();
                                v4 = t14;
                            }
                            t15 = fn_1_FA004();
                            v4 = t15;
                            if ((s32)v4 != 0) {
                                lbl_15_bss_35 = 1;
                                lbl_15_bss_35_1 = 1;
                                t16 = fn_1_FA01C();
                                v4 = t16;
                            }
                        }
                        v4 = (v7 + 0x10000);
                        *(u32 *)((u8 *)v3 + 12) = (*(u32 *)((u8 *)v3 + 12) | 0x4000000);
                        *(u16 *)((u8 *)v3 + 16) = *(u8 *)((u8 *)v4 + -32348);
                        *(u16 *)((u8 *)v3 + 18) = *(u8 *)((u8 *)v4 + -32340);
                        *(u16 *)((u8 *)v3 + 20) = *(u8 *)((u8 *)v4 + -32332);
                    } else {
                        v4 = (v7 + 0x10000);
                        *(u16 *)((u8 *)v3 + 2) = *(u8 *)((u8 *)v4 + -32352);
                    }
                    *(u32 *)((u8 *)v3 + 24) = *(u32 *)((u8 *)v3 + 4);
                }
            }
        }
        v3 = (void *)(((u8 *)v3 + 32));
        v2 += 8;
        v1++;
    }
    fn_1_81834(0, -1, 0);
    t18 = fn_1_83070((void *)lbl_15_bss_21_3, lbl_15_bss_21_7, &loc_8, lbl_15_bss_35_5);
    lbl_15_bss_35_17 = t18;
    fn_1_82724((void *)lbl_15_bss_21_3, (void *)lbl_15_bss_21_7, &loc_8, lbl_15_bss_35_5, 1);
    fn_1_835E0((void *)lbl_15_bss_D4_7C, (void *)lbl_15_bss_21_3, (void *)0);
    v8 = fzgx_obj_lbl_15_bss_14;
    if ((v8 & 0x1) == 0) {
        fn_1_86194(lbl_15_rodata_D8__fzgx_offset_2C);
    } else {
        if ((v8 & 0x78) != 0) {
            fn_1_86194(lbl_15_rodata_0);
        } else {
            fn_1_86194(lbl_15_rodata_0);
            fn_1_817C0();
        }
    }
    t25 = (void *)(fn_1_86254((void *)0));
    fn_1_C3A0C((void *)t25);
    fn_1_435C((void *)lbl_15_bss_21_3);
    lab_t1 = fn_1_C42F4;
    fn_1_3F8C(p_lbl_15_data_0.value + 0x2BC, lab_t1, (void *)((void *)(fn_1_86254((void *)0))), 2);
    fn_1_4310(0);
    fn_1_861B4();
    if ((fzgx_obj_lbl_15_bss_14 & 0x40000000) != 0) {
        fn_1_C6F80(1);
    }
{
    u32 fzgx_loop_v11_9507;
    s32 fzgx_loop_v12_9507;
    v9 = lbl_15_bss_35_17;
    v10 = (void *)(((u8 *)&lbl_1_data_28060 + 1080));
    fzgx_loop_v11_9507 = v9;
    fzgx_loop_v12_9507 = 0;
    v13 = (u32)&lbl_1_data_28060;
    v15 = lbl_15_rodata_0__fzgx_offset_58;
    while ((s16)fzgx_loop_v12_9507 < lbl_15_bss_35_5) {
        v14 = *(u32 *)((u8 *)fzgx_loop_v11_9507 + 1156);
        v13 = (s8)fzgx_loop_v12_9507;
        t33 = (void *)(fn_1_868C0(v13));
        v13 = (u32)(t33);
        *(u16 *)((u8 *)v13 + 954) = 1;
        if ((fzgx_obj_lbl_15_bss_14 & 0x78) == 0) {
            *(f32 *)((u8 *)v14 + 12) = lbl_15_rodata_0;
        }
        v16 = (s16)fzgx_loop_v12_9507;
        *(u32 *)((u8 *)v13 + 912) = (*(u32 *)((u8 *)v13 + 912) | 0x40000);
        v13 = *(u32 *)((u8 *)v14 + 0);
        v13 = (v13 | 2);
        *(u32 *)((u8 *)v14 + 0) = v13;
        switch (v16) {
        case 0:
            *(u8 *)((u8 *)v14 + 0x32) = 0x22;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x7C) = lbl_15_rodata_0;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x84) = lbl_15_rodata_0__fzgx_offset_5C;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x94) = lbl_15_rodata_0;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x98) = lbl_15_rodata_0;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x9C) = lbl_15_rodata_0;
            break;
        case 1:
            *(u8 *)((u8 *)v14 + 0x32) = 0x23;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x7C) = lbl_15_rodata_D8__fzgx_offset_30;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x84) = lbl_15_rodata_D8__fzgx_offset_34;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x94) = lbl_15_rodata_0;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x98) = lbl_15_rodata_0;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x9C) = lbl_15_rodata_0;
            break;
        case 2:
            *(u8 *)((u8 *)v14 + 0x32) = 0x24;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x7C) = lbl_15_rodata_D8__fzgx_offset_38;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x84) = lbl_15_rodata_D8__fzgx_offset_34;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x94) = lbl_15_rodata_0;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x98) = lbl_15_rodata_0;
            *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0x9C) = lbl_15_rodata_0;
            break;
        default:
            break;
        }
        fn_80008BA8((void *)((u8 *)&loc_8 + 0x60), v10, 0xB4);
        fn_1_22E8C((void *)fzgx_loop_v11_9507, (void *)((u8 *)&loc_8 + 0x60));
        *(f32 *)((u8 *)fzgx_loop_v11_9507 + 0xC) = v15;
        fzgx_loop_v12_9507++;
        fzgx_loop_v11_9507 += 0x620;
    }
    v11 = fzgx_loop_v11_9507;
    v12 = fzgx_loop_v12_9507;
}
    return (u32)p_lbl_15_data_0.value;
}
#pragma opt_strength_reduction reset

#pragma opt_loop_invariants reset

#pragma opt_common_subs reset

