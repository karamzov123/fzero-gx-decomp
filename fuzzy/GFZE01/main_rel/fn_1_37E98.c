/* Non-matching: best partial attempt (96.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/game.h"

typedef void (*fn_1_37E98_Fn0)(void);
typedef void (*fn_1_37E98_Fn1)(void *);

struct fn_1_37E98_lbl_1_data_5730 {
    u8 pad_0[0x458];
    s32 unk_458;
    s32 unk_45C;
};
struct fn_1_37E98_sub30 {
    u32 unk_0;
    u8 pad_4;
    u8 unk_5;
    u8 pad_6[0xBA];
    fn_1_37E98_Fn0 unk_C0;
};
struct fn_1_37E98_lbl_1_bss_3C00 {
    u8 pad_0[0x10];
    u8 unk_10;
    u8 pad_11;
    u8 unk_12;
    u8 pad_13;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[4];
    u32 unk_24;
    u8 pad_28[2];
    s16 unk_2A;
    u8 pad_2C[4];
    struct fn_1_37E98_sub30 unk_30;
    u8 pad_F4[0x140C];
    u32 unk_1500;
};

extern u8 lbl_1_bss_5480[0x20700];
extern u16 lbl_1_bss_96A;
extern u32 lbl_1_rodata_E3C;
extern u32 lbl_801A6410;
extern u32 fn_1_435C(u32);
extern u32 fn_1_426C(u32);
extern void fn_1_1547FC(void);
extern u32 fn_1_2DE00(u32);
extern u32 fn_1_4DE04(void);
extern u8 fn_1_A0AA4(void);
extern u32 fn_1_A7024(f32, f32, f32, f32);
extern u32 fn_1_E9CFC(void);
extern u32 fn_80008E84(u32);
extern void camera_set_state_flag(u8);
extern void fn_1_15555C(void);
extern void fn_1_3FCB0(s32);
extern void fn_1_3FCD4(u32);
extern void fn_1_410A0(void);
extern void fn_1_412A0(u32);
extern void fn_1_41A8(void);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_48140(int);
extern void fn_1_48164(int);
extern void fn_1_484CC(s32);
extern void fn_1_49F0(u32 *);
extern void fn_1_58854(void);
extern void fn_1_6400(void);
extern void fn_1_76BF8(void);
extern void fn_1_79100(void);
extern void fn_1_85878(void);
extern void fn_1_8DAB4(void);
extern void fn_1_982C4(void);
extern void fn_1_C47B4(void);
extern void fn_1_C6F80(u8);
extern void fn_1_D17E8(void);
extern void fn_1_D1F88(void);
extern void fn_1_E35F0(void);
extern void fn_1_F2DDC(void);
extern void fn_1_F2EDC(void);
extern void fn_1_F7308(void);
extern void fn_80008BEC(void *, int, u32);
extern void fn_80009064(u32);
extern void fn_80074D18(u32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_1_bss_3C00;
u32 fzgx_obj_lbl_1_bss_3C04;
u32 lbl_1_bss_3C08[2];
u8 lbl_1_bss_3C10;
u8 fzgx_obj_lbl_1_bss_3C11;
u8 fzgx_obj_lbl_1_bss_3C12;
u8 lbl_1_bss_3C12_fill_3C13;
u32 lbl_1_bss_3C12_2;
u32 lbl_1_bss_3C12_6;
u32 fzgx_obj_lbl_1_bss_3C1C;
u32 lbl_1_bss_3C1C_fill_3C20;
u32 lbl_1_bss_3C1C_8;
u16 lbl_1_bss_3C1C_fill_3C28;
s16 fzgx_obj_lbl_1_bss_3C2A;
u32 lbl_1_bss_3C2A_fill_3C2C;
struct fn_1_37E98_sub30 fzgx_obj_lbl_1_bss_3C30;
u32 lbl_1_bss_3C30_fill_3CF4[1278];
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 lbl_1_bss_523C[8];
u32 fzgx_obj_lbl_1_bss_525C[102];
u16 fzgx_obj_lbl_1_bss_53F4;
u16 lbl_1_bss_3C00_gap_53F6;
u32 lbl_1_bss_53F8[34];
u32 lbl_1_bss_5480_fill_5480[31200];
u8 lbl_1_bss_5480_1E780;
u8 lbl_1_bss_5480_fill_23C01;
u16 lbl_1_bss_5480_fill_23C02;
u32 lbl_1_bss_5480_fill_23C04[2015];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C00;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C04;
    s = *(u8 *)&lbl_1_bss_3C08;
    s = *(u8 *)&lbl_1_bss_3C10;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C11;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C12;
    s = *(u8 *)&lbl_1_bss_3C12_fill_3C13;
    s = *(u8 *)&lbl_1_bss_3C12_2;
    s = *(u8 *)&lbl_1_bss_3C12_6;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C1C;
    s = *(u8 *)&lbl_1_bss_3C1C_fill_3C20;
    s = *(u8 *)&lbl_1_bss_3C1C_8;
    s = *(u8 *)&lbl_1_bss_3C1C_fill_3C28;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C2A;
    s = *(u8 *)&lbl_1_bss_3C2A_fill_3C2C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_3C30;
    s = *(u8 *)&lbl_1_bss_3C30_fill_3CF4;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8 *)&lbl_1_bss_523C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_525C;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_53F4;
    s = *(u8 *)&lbl_1_bss_3C00_gap_53F6;
    s = *(u8 *)&lbl_1_bss_53F8;
    s = *(u8 *)&lbl_1_bss_5480_fill_5480;
    s = *(u8 *)&lbl_1_bss_5480_1E780;
    s = *(u8 *)&lbl_1_bss_5480_fill_23C01;
    s = *(u8 *)&lbl_1_bss_5480_fill_23C02;
    s = *(u8 *)&lbl_1_bss_5480_fill_23C04;
}
#pragma section code_type ".text"

#pragma opt_propagation off
void fn_1_37E98(void) {
    s32 tmp_call31;
    u8 *d;
    u8 *v0;
    u32 v1;
    u16 v3;
    fn_1_37E98_Fn1 fn;
    u32 loc_8;
    u32 lab_t0;

    
    d = (u8 *)&lbl_1_data_5730;
    v0 = (u8 *)&lbl_1_bss_5480_1E780;
    if (fzgx_obj_lbl_1_bss_3C12 != 0) {
        fn_1_435C(*(u32 *)(v0 + 0x1F88));
        fn_1_8DAB4();
        if (fzgx_obj_lbl_1_bss_3C30.unk_5 == 2) {
            fn_1_435C(fzgx_obj_lbl_1_bss_5100);
            fn_1_426C(*(s16 *)(v0 + 0x2700));
        }
        v3 = fzgx_obj_lbl_1_bss_3C2A;
        if (v3 != -1) {
            (*(fn_1_37E98_Fn0 *)(((d) + ((0x38C) + ((v3 << 4)))) - 0x238))();
        }
        fn = *(fn_1_37E98_Fn1 *)(v0 + 0x3064);
        if (fn != 0) {
            fn(&fzgx_obj_lbl_1_bss_3C30);
        }
        loc_8 = lbl_1_rodata_E3C;
        fn_1_49F0(&loc_8);
        if (fzgx_obj_lbl_1_bss_3C30.unk_C0 != 0) {
            fzgx_obj_lbl_1_bss_3C30.unk_C0();
        }
        fn_1_E9CFC();
        if (*(s32 *)(v0 + 0x301C) != 0) {
            if (fzgx_obj_lbl_1_bss_3C30.unk_0 & 0x800000) {
                fn_1_F2EDC();
            }
            camera_set_state_flag(0);
            fn_1_F7308();
            fn_1_6400();
            lab_t0 = lbl_801A6410;
            fn_1_46B4(lab_t0, lbl_1_bss_3C1C_8, (const char *)(d + 0xBBC), 6148);
            lbl_1_bss_3C1C_8 = 0;
            if (*(s32 *)(v0 + 0x2288) != 0) {
                fn_1_435C(*(u32 *)(v0 + 0x1F88));
                if (((struct fn_1_37E98_lbl_1_data_5730 *)d)->unk_458 != -1) {
                    fn_1_426C(((struct fn_1_37E98_lbl_1_data_5730 *)d)->unk_458);
                    ((struct fn_1_37E98_lbl_1_data_5730 *)d)->unk_458 = -1;
                }
                fn_1_435C(*(u32 *)(v0 + 0x20A4));
                if (((struct fn_1_37E98_lbl_1_data_5730 *)d)->unk_45C != -1) {
                    fn_1_426C(((struct fn_1_37E98_lbl_1_data_5730 *)d)->unk_45C);
                    ((struct fn_1_37E98_lbl_1_data_5730 *)d)->unk_45C = -1;
                }
                fn_1_D1F88();
                *(u32 *)(v0 + 0x2288) = 0;
            }
            v1 = fn_80008E84(*(u32 *)(v0 + 0x26F8));
            fn_1_85878();
            fn_1_982C4();
            fn_80008E84(v1);
            fn_80009064(*(u32 *)(v0 + 0x26F8));
            fn_1_46B4(lbl_801A6410, *(u32 *)(v0 + 0x3018), (const char *)(d + 0xBBC), 5986);
            fn_1_58854();
            if (*(s16 *)&lbl_1_bss_960 != 10 && *(s16 *)&lbl_1_bss_960 != 12 && !(fzgx_obj_lbl_1_bss_3C30.unk_0 & 0x400000)) {
                fn_80008BEC(lbl_1_bss_5480, 0, 0x20700);
            }
        }
        fn_1_1547FC();
        fn_1_C47B4();
        fn_1_435C(*(u32 *)(v0 + 0x1F88));
        if (lbl_1_bss_3C12_2 != 0) {
            fn_1_426C(lbl_1_bss_3C12_2);
            lbl_1_bss_3C12_2 = 0;
        }
        fn_1_435C(*(u32 *)(v0 + 0x20A4));
        if (lbl_1_bss_3C12_6 != 0) {
            fn_1_426C(lbl_1_bss_3C12_6);
            lbl_1_bss_3C12_6 = 0;
        }
        fn_1_C6F80(0);
        v1 = fn_80008E84(*(u32 *)(v0 + 0x20CC));
        fn_1_79100();
        fn_80008E84(v1);
        fn_1_412A0(2);
        fn_1_E35F0();
        fn_1_435C(*(u32 *)(v0 + 0x20A4));
        fn_1_41A8();
        fn_1_435C(*(u32 *)(v0 + 0x1F88));
        fn_1_41A8();
        fn_1_435C(fzgx_obj_lbl_1_bss_5100);
        fn_1_41A8();
        fn_1_46B4(lbl_801A6410, fzgx_obj_lbl_1_bss_5100, (const char *)(d + 0xBBC), 7345);
        fn_1_46B4(lbl_801A6410, *(u32 *)(v0 + 0x1F88), (const char *)(d + 0xBBC), 7346);
        fn_1_46B4(lbl_801A6410, *(u32 *)(v0 + 0x20A4), (const char *)(d + 0xBBC), 7347);
        if (fzgx_obj_lbl_1_bss_3C30.unk_0 & 0x800000) {
            fn_1_F2DDC();
            fzgx_obj_lbl_1_bss_3C30.unk_0 &= ~0x800000;
        }
        tmp_call31 = fn_1_A0AA4();
        tmp_call31;
        fn_80074D18(0);
        fn_1_76BF8();
        if (*(s16 *)&lbl_1_bss_960 == 12) {
            fn_1_48140(150);
        } else {
            fn_1_48164(1);
            fn_1_484CC(1);
        }
        fn_1_4DE04();
        fn_1_A7024(*(f32 *)(v0 + 0x3048), *(f32 *)(v0 + 0x304C), *(f32 *)(v0 + 0x3050), *(f32 *)(v0 + 0x3054));
        if (fzgx_obj_lbl_1_bss_3C1C != 0) {
            fn_1_46B4(lbl_801A6410, fzgx_obj_lbl_1_bss_3C1C, (const char *)(d + 0xBBC), 7380);
            fzgx_obj_lbl_1_bss_3C1C = 0;
        }
        fn_1_410A0();
        fn_80009064(*(u32 *)(v0 + 0x20CC));
        fn_1_46B4(lbl_801A6410, *(u32 *)(v0 + 0x3040), (const char *)(d + 0xBBC), 7392);
        fn_1_D17E8();
        if (lbl_1_bss_3C10 == 0) {
            fn_1_2DE00(0);
        }
        *(u16 *)(v0 + 0x3068) = 0;
        fn_1_3FCB0(0);
        fn_1_3FCD4(0);
        *(u32 *)(v0 + 0x2274) = 0;
        *(u32 *)(v0 + 0x3064) = 0;
        lbl_1_bss_3C10 = 0;
        fzgx_obj_lbl_1_bss_3C12 = 0;
        fn_1_15555C();
        if (fzgx_obj_lbl_1_bss_3C30.unk_0 & 0x400000) {
            lbl_1_bss_96A = 184;
        }
    }
}
#pragma opt_propagation reset

