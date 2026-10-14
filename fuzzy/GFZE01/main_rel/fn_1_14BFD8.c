/* Non-matching: best partial attempt (86.42% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_14BFD8_lbl_1_bss_9F8 {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[0x3C];
};

struct fn_1_14BFD8_lbl_1_bss_8E518 {
    u32 unk_0;
    u8 pad_4[0xC];
    u32 unk_10;
    u8 pad_14[0x4];
    f32 unk_18;
    u8 pad_1C[0x4];
    u32 unk_20;
    u8 pad_24[0xC];
    u8 unk_30;
    u8 pad_31[0xF];
    u8 unk_40;
    u8 unk_41;
    u8 pad_42[0x2];
    u32 unk_44;
    u32 unk_48;
};

extern s16 fn_1_12EF24(s16);
extern u32 fn_1_12EF80(u8, void *, void *);
extern s32 fn_1_F89E4(u8);
extern s32 fn_1_1555B0(s32);
extern u32 fn_1_1556B4(u32, u32);
extern u32 fn_1_A2D84(u32);
extern f32 lbl_1_rodata_99A4;
extern u32 lbl_801A66A0;
extern u32 lbl_801A66A4;
extern struct fn_1_14BFD8_lbl_1_bss_9F8 lbl_1_bss_9F8;

#pragma opt_common_subs on
static inline s16 fn_1_14BFD8_array_read(s32 index, u16 *array) { return array[index]; }
#pragma opt_dead_assignments off
typedef struct lbl_1_bss_8E518_t {
    u32 unk_0;
} lbl_1_bss_8E518_t;

typedef struct lbl_1_bss_8E548_t {
    u8 unk_30;
    u8 pad_1[0x7];
} lbl_1_bss_8E548_t;

typedef struct lbl_1_bss_8E554_t {
    u8 pad_0[0x4];
    u8 unk_40;
} lbl_1_bss_8E554_t;

typedef struct lbl_1_bss_8E560_t {
    u32 unk_48;
    u8 pad_4[0xc];
} lbl_1_bss_8E560_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_8E518_t fzgx_obj_lbl_1_bss_8E518;
u8 lbl_1_bss_8E518_tail_8E51C;
u8 fzgx_obj_lbl_1_bss_8E51D;
u16 lbl_1_bss_8E518_gap_8E51E;
u32 fzgx_obj_lbl_1_bss_8E520;
u8 fzgx_obj_lbl_1_bss_8E524;
u8 lbl_1_bss_8E518_gap_8E525;
u16 lbl_1_bss_8E518_gap_8E525_fill_8E526;
u32 fzgx_obj_lbl_1_bss_8E528;
u8 fzgx_obj_lbl_1_bss_8E52C;
u8 lbl_1_bss_8E518_gap_8E52D;
u16 lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
f32 lbl_1_bss_8E530;
u32 lbl_1_bss_8E534;
u8 lbl_1_bss_8E538;
u32 lbl_1_bss_8E53C;
u32 fzgx_obj_lbl_1_bss_8E540;
u32 fzgx_obj_lbl_1_bss_8E544;
lbl_1_bss_8E548_t fzgx_obj_lbl_1_bss_8E548;
u8 lbl_1_bss_8E550;
u8 lbl_1_bss_8E518_gap_8E551;
u16 lbl_1_bss_8E518_gap_8E551_fill_8E552;
lbl_1_bss_8E554_t lbl_1_bss_8E554;
u8 fzgx_obj_lbl_1_bss_8E559;
u16 lbl_1_bss_8E518_gap_8E55A;
u32 lbl_1_bss_8E55C;
lbl_1_bss_8E560_t lbl_1_bss_8E560;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E518;
    s = *(u8 *)&lbl_1_bss_8E518_tail_8E51C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E51D;
    s = *(u8 *)&lbl_1_bss_8E518_gap_8E51E;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E520;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E524;
    s = *(u8 *)&lbl_1_bss_8E518_gap_8E525;
    s = *(u8 *)&lbl_1_bss_8E518_gap_8E525_fill_8E526;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E528;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E52C;
    s = *(u8 *)&lbl_1_bss_8E518_gap_8E52D;
    s = *(u8 *)&lbl_1_bss_8E518_gap_8E52D_fill_8E52E;
    s = *(u8 *)&lbl_1_bss_8E530;
    s = *(u8 *)&lbl_1_bss_8E534;
    s = *(u8 *)&lbl_1_bss_8E538;
    s = *(u8 *)&lbl_1_bss_8E53C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E540;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E544;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E548;
    s = *(u8 *)&lbl_1_bss_8E550;
    s = *(u8 *)&lbl_1_bss_8E518_gap_8E551;
    s = *(u8 *)&lbl_1_bss_8E518_gap_8E551_fill_8E552;
    s = *(u8 *)&lbl_1_bss_8E554;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_8E559;
    s = *(u8 *)&lbl_1_bss_8E518_gap_8E55A;
    s = *(u8 *)&lbl_1_bss_8E55C;
    s = *(u8 *)&lbl_1_bss_8E560;
}
#pragma section code_type ".text"

void fn_1_14BFD8(s32 arg0, u8 *arg1, s32 arg2) {
    struct { s32 value; } v;
    s32 f0_2;
    s16 v26;
    s32 v27;
    s32 f30;
    u32 f31_2;
    s16 v26_2;
    s32 f28;
    s32 f31;
    s32 v27_2;
    s32 off;
    s16 spa;
    u16 *w;
    s16 sp8;
    s32 f23;
    s32 f24;
    s16 v26_2_2;
    u32 addr;
    s32 f0;

    off = (s32)(s16)arg0 * 20;
    w = (u16 *)((u8 *)&lbl_1_bss_9F8 + off);
    
    f0 = 0;
    if ((((u32)fn_1_14BFD8_array_read(0, w) >> 3) & 1) || (((u32)fn_1_14BFD8_array_read(1, w) >> 3) & 1) ||
        (((u32)fn_1_14BFD8_array_read(0, w) >> 2) & 1) || (((u32)fn_1_14BFD8_array_read(1, w) >> 2) & 1)) {
        f0_2 = 1;
    }
    f30 = 0;
    if ((*(u16 *)((((u8 *)&lbl_1_bss_9F8) + ((off) + (0x10)))) & 1) ||
        (*(u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x12) & 1)) {
        if (f0_2 == 0) {
            f30 = 1;
        }
    }
    f31 = 0;
    if ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + off + 0x10) >> 1 & 1) ||
        (*(u16 *)((((u8 *)&lbl_1_bss_9F8) + ((off) + (0x12)))) >> 1 & 1)) {
        if (f0_2 == 0) {
            f31_2 = 1;
        }
    }
    f28 = (*(u16 *)((u8 *)&lbl_1_bss_9F8 + off + 8) >> 10) & 1;
    if (arg1 != 0) {
        spa = 0;
        sp8 = 0;
        fn_1_12EF80(arg1[0], &spa, &sp8);
        v27 = 0;
        v26 = -1;
        if (f30 != 0) {
            v27_2 = -1;
            lbl_1_bss_8E55C = lbl_801A66A0;
        } else if (f31_2 != 0) {
            v27_2 = 1;
            lbl_1_bss_8E560.unk_48 = lbl_801A66A0;
        }
        if (v27_2 != 0) {
            sp8 += v27_2;
            while (sp8 >= 0 && sp8 <= 5) {
                v26_2 = fn_1_12EF24(spa);
                if (spa == 5) {
                    if (sp8 == 5) {
                        if (fn_1_F89E4(0) == 0) {
                            v26_2_2 = -1;
                        }
                    }
                    if (sp8 != 5) {
                        if (fn_1_F89E4((u8)(sp8 + 1)) == 0) {
                            v26_2_2 = -1;
                        }
                    }
                }
                if (v26_2_2 != -1) {
                    break;
                }
                sp8 += v27_2;
            }
        }
        if (v26_2_2 != -1) {
            if (arg1[0] != v26_2_2) {
                s32 a;
                arg1[0] = (u8)v26_2_2;
                v.value = 0;
                lbl_1_bss_8E538 = v.value;
                a = -((s32)((u8)fzgx_obj_lbl_1_bss_8E548.unk_30 >> 1) - 1);
                lbl_1_bss_8E538 = a;
                if (a >= 0) {
                    s32 c = 10 - (s32)fzgx_obj_lbl_1_bss_8E548.unk_30;
                    if (a > c) {
                        a = c;
                    }
                    v.value = a;
                }
                lbl_1_bss_8E538 = v.value;
                lbl_1_bss_8E530 = lbl_1_rodata_99A4;
                fn_1_1555B0(arg1[0]);
                fn_1_1556B4(lbl_1_bss_8E554.unk_40, fzgx_obj_lbl_1_bss_8E559);
                fzgx_obj_lbl_1_bss_8E518.unk_0 = 0;
                fzgx_obj_lbl_1_bss_8E528 = lbl_801A66A4;
                fn_1_A2D84(0xA9010000);
            }
        }
    }
    if (arg2 != 0) {
        f23 = 0;
        f24 = 0;
        if (f28 != 0) {
            switch (fzgx_obj_lbl_1_bss_8E559) {
            case 0:
                fzgx_obj_lbl_1_bss_8E559 = 2;
                addr = 0xA9121900;
                break;
            case 2:
                fzgx_obj_lbl_1_bss_8E559 = 1;
                addr = 0xA9121A00;
                break;
            case 1:
                fzgx_obj_lbl_1_bss_8E559 = 0;
                addr = 0xA9121800;
                break;
            }
            f24 = 1;
            fn_1_A2D84(addr);
        }
        if (f23 != 0 || f24 != 0) {
            s32 a;
            fn_1_1556B4(lbl_1_bss_8E554.unk_40, fzgx_obj_lbl_1_bss_8E559);
            v.value = 0;
            lbl_1_bss_8E538 = v.value;
            f28 = -((s32)((u8)fzgx_obj_lbl_1_bss_8E548.unk_30 >> 1) - 1);
            a = f28;
            lbl_1_bss_8E538 = a;
            if (a >= 0) {
                s32 c = 10 - (s32)fzgx_obj_lbl_1_bss_8E548.unk_30;
                if (a > c) {
                    a = c;
                }
                v.value = a;
            }
            lbl_1_bss_8E538 = v.value;
            lbl_1_bss_8E530 = lbl_1_rodata_99A4;
            fzgx_obj_lbl_1_bss_8E528 = lbl_801A66A4;
        }
    }
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
