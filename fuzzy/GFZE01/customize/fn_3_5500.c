/* Non-matching: best partial attempt (90.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Head {
    u32 unk_0;
    u8 pad_4[0x19];
    u8 unk_1D;
    u8 pad_1E[0xD2];
    u32 unk_F0;
    u8 pad_F4[0x2C];
    s32 unk_120;
};
struct Sub {
    u32 flags;
    u8 pad_4[2];
    s16 unk_6;
    s16 unk_8;
    u8 pad_A[0x1A];
    s8 unk_24;
};
struct Rod {
    u8 pad_0[4];
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[8];
    f32 unk_14;
    u8 pad_18[0x2C];
    f32 unk_44;
    u32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    u8 pad_58[4];
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    f32 unk_68;
    u8 pad_6C[4];
    f32 unk_70;
    u8 pad_74[8];
    f32 unk_7C;
    u8 pad_80[0x5C];
    f32 unk_DC;
};
struct Dat {
    u8 pad_0[0xB4];
    u32 unk_B4;
    s32 unk_B8;
    u8 pad_BC[0xE80 - 0xBC];
    u32 tab[5][6];
    u8 pad_EF8[0x6D4];
    char name[8];
};
struct Itm {
    u16 unk_0;
    u8 pad_2[6];
    s16 unk_8;
    u8 pad_A[6];
    s16 unk_10;
    u16 unk_12;
    u8 pad_14[0];
};

extern struct Head lbl_3_bss_0[];
extern struct Rod lbl_3_rodata_0;
extern struct Dat lbl_3_data_0;
extern u16 lbl_3_bss_140[];
extern s32 lbl_801A66B4;
extern u16 lbl_1_bss_96A;
extern struct Itm lbl_1_bss_9F8[8];
extern u32 lbl_3_bss_6DD70;
extern u8 lbl_3_bss_6DD74;

extern int fn_1_4C10(void);
extern void fn_3_5A50(void);
extern void fn_3_BFC(char *, void *, const char *, const char *);
extern void fn_3_E64(u8 *);
extern s16 fn_3_5070(void);
extern s32 fn_3_B68(const s16 *);
extern void fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern u32 fn_1_4AEC0(u32);
extern void fn_1_4AEB4(f32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_A2D84(u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_FDFF4(void);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_1280(u32);

#define SUB ((struct Sub *)((u8 *)b + 0xF0))
#define TAB2 (*(u32 *)((u8 *)d + 0xF00 + lbl_801A66B4 * 4))

#pragma opt_propagation off
void fn_3_5500(void) {
    u32 fzgx_value;
    u32 tbl;
    u32 (* fzgx_live)[6];
    struct Head *b = (struct Head *)&lbl_3_bss_0;
    struct Rod *ro = (struct Rod *)&lbl_3_rodata_0;
    struct Dat *d = (struct Dat *)&lbl_3_data_0;
    struct { u8 *value; } shw;
    u32 locC[265];
    u32 loc8;
    s32 sel = (s16)(SUB->unk_6);
    s16 v;
    s32 t;

    shw.value = (u8 *)b + 0x20000;
    if (b->unk_120 == -1) fn_1_4C10();
    if (!((SUB->unk_24 & 0x80000000) || ((b->unk_F0 & 0x2) != 0))) {
        t = 1;
    } else {
        if (fn_1_4C10()) t = 1; else t = 0;
    }
    if (t != 0) return;

    if (b->unk_120 != -1) {
        if ((b->unk_F0 & 0x4000000) == 0) {
            if (d->unk_B8 != -1) {
                fn_1_435C(*(u32 *)(shw.value + 0x850));
                fn_1_426C(d->unk_B8);
                d->unk_B8 = -1;
            }
            fn_3_5A50();
        }
        lbl_1_bss_96A = b->unk_120;
        b->unk_120 = -1;
        return;
    }

    if (b->unk_1D != 0) {
        loc8 = ro->unk_48;
        fn_1_53BD8(&loc8, ro->unk_4, ro->unk_8, ro->unk_4C, ro->unk_50, ro->unk_54);
        tbl = TAB2;
        fn_1_4AEC0(1);
        fn_1_4AEB4(ro->unk_5C);
        fn_1_49410();
        fn_1_4955C(ro->unk_7C, ro->unk_7C);
        fn_1_4954C(ro->unk_70);
        fn_1_495C8(9);
        fn_1_496FC(ro->unk_4, ro->unk_DC);
        fn_1_4966C(ro->unk_60, ro->unk_64);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(ro->unk_14);
            fn_1_4966C(ro->unk_60, ro->unk_68);
        }
        fzgx_live = d->tab;
        fn_3_BFC((char *)&locC, (void *)tbl, d->name, (const char *)fzgx_live[*(u8 *)(shw.value + 0x437C)][lbl_801A66B4]);
        fzgx_live = d->tab;
        fn_3_BFC((char *)&locC, (void *)&locC, d->name, (const char *)fzgx_live[*(u8 *)(shw.value + 0x437C)][lbl_801A66B4]);
        fzgx_live = d->tab;
        fn_3_BFC((char *)&locC, (void *)&locC, d->name, (const char *)fzgx_live[*(u8 *)(shw.value + 0x437C)][lbl_801A66B4]);
        fn_1_4A0D8((const char *)&locC);
        fn_1_4AEC0(0);
        fn_1_4AEB4(ro->unk_44);
        fn_3_E64(&lbl_3_bss_6DD74);
        if ((lbl_1_bss_9F8[sel].unk_10 & 1) || ((lbl_1_bss_9F8[sel].unk_12 & 1) != 0)) {
            lbl_3_bss_6DD74 = 0;
            fn_1_A2D84(0xA9011300);
        }
        if (((lbl_1_bss_9F8[sel].unk_0 & 2) != 0) || ((lbl_1_bss_9F8[sel].unk_12 & 2) != 0)) {
            lbl_3_bss_6DD74 = 1;
            fn_1_A2D84(0xA9011300);
        }
        if ((lbl_1_bss_9F8[sel].unk_8 & 0x200) != 0) lbl_3_bss_6DD74 = 1;
        if (((lbl_1_bss_9F8[sel].unk_8 & 0x100) != 0) || ((lbl_1_bss_9F8[sel].unk_8 & 0x200) != 0)) {
            b->unk_1D = 0;
            if (lbl_3_bss_6DD74 == 0) {
                v = 6;
                fn_1_A2D84(0xA9010100);
            } else {
                fn_1_A2D84(0xA9010200);
                b->unk_120 = 0x5F;
                return;
            }
        } else {
            return;
        }
    } else {
        v = fn_3_5070();
        if (v == 6) {
            if (b->unk_1D == 0) {
                b->unk_1D = 1;
                return;
            }
        }
    }

    if (v == -1) {
        b->unk_120 = 0x5C;
        return;
    }
    if (v != 0) {
        fn_80008BA8((void *)(shw.value + 0x43C0), (void *)&lbl_3_bss_140[SUB->unk_8 * 0x81C0], 0x81C0);
    }

    switch (v) {
    case 1:
        b->unk_120 = 0x6B;
        fn_1_FDFF4();
        fn_1_4A00(0, 15, (void *)*(u32 *)(shw.value + 0x850));
        *(u32 *)(shw.value + 0x43A8) = 0;
        break;
    case 2:
        b->unk_120 = 0x60;
        fn_1_FDFF4();
        fn_1_4A00(0, 15, (void *)*(u32 *)(shw.value + 0x850));
        *(u32 *)(shw.value + 0x43A8) = 0;
        break;
    case 3:
        b->unk_120 = 0x6B;
        fn_1_FDFF4();
        fn_1_4A00(0, 15, (void *)*(u32 *)(shw.value + 0x850));
        *(u32 *)(shw.value + 0x43A8) = 0;
        break;
    case 4:
        b->unk_120 = 0x6C;
        fn_1_FDFF4();
        fn_1_4A00(0, 15, (void *)*(u32 *)(shw.value + 0x850));
        *(u32 *)(shw.value + 0x43A8) = 0;
        break;
    case 5:
        b->unk_120 = 0x68;
        fn_1_FDFF4();
        fn_1_4A00(0, 15, (void *)*(u32 *)(shw.value + 0x850));
        *(u32 *)(shw.value + 0x43A8) = 0;
        break;
    case 6:
        lbl_3_bss_6DD70 |= 1 << SUB->unk_8;
        b->unk_0 = 1;
        b->unk_120 = 0x5D;
        fn_1_1280(1);
        fn_1_FDFF4();
        SUB->flags |= 0x4000000;
        fzgx_value = 0x5F;
        d->unk_B4 = fzgx_value;
        *(u32 *)(shw.value + 0x4374) = (u32)&fn_3_B68;
        *(u32 *)(shw.value + 0x4378) = (u32)&SUB->unk_8;
        break;
    }
}
#pragma opt_propagation reset
