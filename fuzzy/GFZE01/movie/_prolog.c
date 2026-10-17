/* Non-matching: best partial attempt (99.53% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/movie/globals.h"

extern u8 lbl_5_data_0[20];
extern u32 lbl_5_bss_0[8];
extern u32 lbl_801A6410;
extern s16 lbl_1_bss_964;
extern struct lbl_1_bss_970_s lbl_1_bss_970;
extern char lbl_1_bss_198[];
extern s32 lbl_1_bss_96A;
extern u32 lbl_1_bss_7167C;
extern u32 lbl_1_bss_71680;
extern u32 lbl_1_bss_71684;
extern u32 lbl_1_bss_8B614[2];
extern const f32 lbl_5_rodata_0;
extern void fn_5_200(void);
extern void fn_5_220(void);
extern void fn_5_320(void);
extern void fn_5_3F94(void);
extern void fn_5_3FF0(void);
extern s32 fn_1_45D0(u32, u32, void *, u32);
extern void fn_1_3CF0(u32, u32);
extern void fn_1_157940(void);
extern void fn_1_479F0(s16);
extern int fn_80083BCC(const char *, const char *);
extern void fn_1_A5AA0(void *, void *);
extern void fn_8006CE1C(f32);
extern void fn_1_4A00(s32, u8, void *);
extern u32 fn_800068F4(u32);
extern u32 fn_80006904(u32);
extern void fn_1_A0680(void);

struct lbl_1_bss_970_s {
    u32 unk_0;
    u8 unk_4;
};

struct prolog_bss {
    u32 unk_0;
    u8 pad_4[0x1C];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2C;
    u32 unk_30;
    u32 unk_34;
    u8 unk_38[1];
};

struct prolog_data {
    u8 pad_0[0x14];
    u8 unk_14[8];
    u8 unk_1C[0xC];
    u8 unk_28[1];
};

void _prolog(void) {
    u32 spell_call;
    struct prolog_data *d = (struct prolog_data *)&lbl_5_data_0;
    u32 t0;
    struct prolog_bss *p = (struct prolog_bss *)&lbl_5_bss_0;

    p->unk_28 = fn_1_45D0(lbl_801A6410, 0x584, &d->unk_14, 0xf4);
    p->unk_2C = fn_1_45D0(lbl_801A6410, 0x584, &d->unk_14, 0xf5);
    fn_1_3CF0(p->unk_28, 2);
    fn_1_3CF0(p->unk_2C, 2);
    p->unk_30 = fn_1_45D0(lbl_801A6410, 0x584, &d->unk_14, 0xf8);
    spell_call = fn_1_45D0(lbl_801A6410, 0x584, &d->unk_14, 0xf9);
    p->unk_34 = spell_call;
    fn_1_3CF0(p->unk_30, 2);
    fn_1_3CF0(p->unk_34, 2);
    fn_1_157940();
    if (lbl_1_bss_964 != 9) {
        fn_1_479F0(8);
    }
    lbl_1_bss_970.unk_0 = 0;
    lbl_1_bss_970.unk_4 = 0;
    lbl_1_bss_96A = 0x82 + (fn_80083BCC(lbl_1_bss_198, (const char *)&d->unk_1C) != 0);
    lbl_1_bss_7167C = (u32)&fn_5_200;
    lbl_1_bss_71680 = (u32)&fn_5_220;
    lbl_1_bss_71684 = (u32)&fn_5_320;
    fn_1_A5AA0(&d->unk_28, &p->unk_38);
    if (lbl_1_bss_964 != 0xF) {
        fn_8006CE1C(lbl_5_rodata_0);
    } else {
        fn_1_4A00(1, 0xF, (void *)p->unk_2C);
        lbl_1_bss_8B614[1] |= 0x20000000;
    }
    p->unk_0 = 0;
    p->unk_20 = fn_800068F4((u32)&fn_5_3F94);
    p->unk_24 = fn_80006904((u32)&fn_5_3FF0);
    fn_1_A0680();
}
