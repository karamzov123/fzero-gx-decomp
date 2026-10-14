/* Non-matching: best partial attempt (87.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/option/globals.h"
#include "font.h"

struct fn_4_7938_ro {
    u8 pad_0[0x8];
    f32 f_08;
    u32 w_0C;
    f64 d_10;
    f64 d_18;
    u8 pad_20[0x8];
    f64 d_28;
    f64 d_30;
    u8 pad_38[0xC];
    f32 f_44;
    f32 f_48;
    f32 f_4C;
    f32 f_50;
    f32 f_54;
    f32 f_58;
    u8 pad_5C[0x4];
    f64 d_60;
    f64 d_68;
    f32 f_70;
    u8 pad_74[0x4];
    f64 d_78;
    u8 pad_80[0x3C];
    f32 f_BC;
    f32 f_C0;
    u8 pad_C4[0x4];
    f32 f_C8;
    f32 f_CC;
    f32 f_D0;
};

struct fn_4_7938_ent {
    u32 pad_0;
    u32 a[6];
};

struct fn_4_7938_pkt {
    u32 w_00;
    f32 f_04;
    f32 f_08;
    f32 f_0C;
    f32 f_10;
    f32 f_14;
    u8 pad_18[0x14];
    f32 f_2C;
    u32 w_30;
    u8 pad_34[0x4];
    u32 w_38;
    u8 pad_3C[0x1C];
};

extern struct fn_4_7938_ro lbl_4_rodata_0;
extern u32 lbl_1_rodata_26F8[];
extern s32 lbl_801A66B4;
extern s16 lbl_1_bss_962;
extern u8 lbl_4_bss_C;
extern u32 fn_1_5233C();
extern void fn_1_49410(void);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_53E40(u32, u32, f32, f32, f32, f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern f32 fn_1_4B040(s32);
extern f32 lbl_8006D188(s32, f32, f32, f32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_53BD8(void *, f32, f32, f32, f32, f32);
extern void fn_1_1380F0(void *);
extern void fn_1_13ABA8(void *);

#pragma opt_propagation off
void fn_4_7938(void) {
    struct fn_4_7938_pkt pkt;
    u32 i;
    u32 c;
    u32 k;
    struct fn_4_7938_ent *tab;
    u8 *p;
    struct fn_4_7938_ro *r;
    u32 *t;
    f32 best;
    f32 z;
    f32 y;
    f32 w;

    p = lbl_4_data_0;
    r = &lbl_4_rodata_0;
    fn_1_49410();
    fn_1_49738((u32)fn_1_5233C);
    fn_1_49748(r->f_48);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(r->f_08);
    }
    t = (u32 *)(p + 0x958);
    fn_1_53E40(0, t[lbl_801A66B4], r->f_50, r->f_C8, r->f_BC, r->f_C0, r->f_CC);
    c = lbl_4_bss_C;
    fn_1_49410();
    fn_1_495C8(9);
    fn_1_49738((u32)(void *)fn_1_5233C);
    fn_1_49748(r->f_48);
    best = r->f_4C;
    tab = (struct fn_4_7938_ent *)(p + 0x2C58);
    for (i = 0, k = 0; i < 3; i++, k += 2, tab++) {
        fn_1_496FC(r->f_50, (f32)(u32)(0xF0 + 0x18 * (k - 2)));
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(r->f_08);
        }
        fn_1_4AE0C((const char *)(p + 0x1210), tab->a[lbl_801A66B4]);
        z = fn_1_4B040(tab->a[lbl_801A66B4]);
        if (z > best) {
            best = z;
        }
    }
    if (*(u8 *)(p + 0x120C) != c || *(s16 *)(p + 0x120E) != lbl_1_bss_962) {
        lbl_4_bss_2 = 0;
        *(u8 *)(p + 0x120C) = c;
        *(s16 *)(p + 0x120E) = lbl_1_bss_962;
    }
    pkt = *(struct fn_4_7938_pkt *)lbl_1_rodata_26F8;
    (void) pkt;  /* fzgx: keeps the web at its definition */
    pkt.w_00 = 0x12;
    pkt.f_04 = r->f_50;
    y = (f32)(u32)(0xF0 + 0x18 * (2 * c - 2));
    w = (f32)(((f64)best + r->d_10) * r->d_18);
    pkt.f_08 = y;
    pkt.f_0C = r->f_54;
    pkt.f_10 = w;
    pkt.f_14 = r->f_44;
    pkt.w_30 = 0xA;
    pkt.f_2C = (f32)(r->d_28 * (r->d_30 + lbl_8006D188((s16)(lbl_4_bss_2 * 1024 + 0x4000),
        w, (*(f32 volatile *)&(r->f_54)) /* Retail reloads this field. */, y)));
    pkt.w_38 = r->w_0C;
    fn_1_4F734((FontDrawPacket *)&pkt);
    fn_1_53BD8((void *)0, r->f_50, r->f_58, (f32)(r->d_60 + (f64)best),
        (f32)(r->d_68 + r->f_D0), r->f_70);
    t = (u32 *)(((0xE8) + (p)));
    fn_1_1380F0((void *)t[lbl_801A66B4]);
    fn_1_13ABA8((void *)0x28000000);
}
#pragma opt_propagation reset
