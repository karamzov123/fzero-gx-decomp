/* Non-matching: best partial attempt (67.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void fn_1_49410(void);
extern void fn_1_495FC(void);
extern void fn_1_4954C(f32);
extern void fn_1_495C8(u8);
extern void fn_1_495B0(u32);
extern void fn_1_495A0(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_49514(u32 *);
extern void fn_1_49614(void);
extern f32 fn_1_4B068(const void *);
extern void fn_1_49738(void (*)(void));
extern void fn_1_49748(f32);
extern void fn_1_4AF10(void *);
extern void fn_1_4AEC0(u32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_5233C(void);
extern void fn_1_50A90(void *, s32, s32, s32, s32);

extern const f32 lbl_17_rodata_0[];
extern u32 lbl_1_rodata_26F8[];
extern u8 lbl_17_data_0[];

typedef struct {
    u8 pad_00[0x10];
    u8 *field_10;
    u8 pad_14[0x40];
    s32 field_54;
    u8 pad_58[0x8];
    u8 *field_60[4];
    u8 pad_70[0x88];
    s32 field_F8;
    u8 pad_FC[0x4];
    s32 field_100;
    s32 field_104;
    u8 pad_108[0x4];
    f32 field_10C;
    u8 pad_110[0x8];
    u32 field_118[1];
} PrologBss;

typedef struct {
    u8 pad_00[0xB4];
    char name[0x100];
} PrologEntry;

typedef struct {
    u32 field_00;
    u32 field_04;
    f32 field_08;
    f32 field_0C;
    f32 field_10;
    f32 field_14;
    u8 pad_18[0x18];
    f32 field_30;
    s32 field_34;
    u8 pad_38[0x20];
} PrologParam;

extern PrologBss lbl_17_bss_0;

void fn_17_2414(void) {
    const u8 *ro = (const u8 *)lbl_17_rodata_0;
    PrologBss *bss = &lbl_17_bss_0;
    u8 *base = &lbl_17_data_0[0x6000];
    f32 f31, f30, f29, f27;
    f64 f26, f28;
    const char *name;
    s32 i, j;
    u32 *p118;
    PrologParam p;

    if (*(const f32 *)(ro + 0x20) == bss->field_10C) {
        return;
    }

    {
        f64 lo = *(const f64 *)(ro + 0x78);
        f64 hi = *(const f64 *)(ro + 0x80);
        f64 t = *(const f64 *)(ro + 0x88) * (bss->field_10C - *(const f64 *)(ro + 0x90));
        f64 c;
        if (t < lo) {
            c = lo;
        } else if (t > hi) {
            c = hi;
        } else {
            c = t;
        }
        f31 = (f32)c;
    }

    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(*(const f32 *)(ro + 0x98));
    fn_1_495C8(1);
    fn_1_495B0(0x80000000); /* fzgx-allow: A1 non-address bit pattern */

    {
        f32 d = bss->field_10C - *(const f32 *)(ro + 0x3C);
        f30 = *(const f32 *)(ro + 0x9C) * d;
    }
    if (f30 < *(const f32 *)(ro + 0x20)) {
        f30 = *(const f32 *)(ro + 0x20);
    }

    fn_1_495A0(f31);
    fn_1_4955C(f30, f30);
    fn_1_496FC(*(const f32 *)(ro + 0xA0), *(const f32 *)(ro + 0xA4));

    if (bss->field_54 == 5) {
        f29 = fn_1_4B068(base - 0x112C);
        name = (const char *)(base + 0x3FDC);
    } else {
        name = *(const char *const *)(base - 0x1114 + bss->field_54 * 4);
        f29 = fn_1_4B068(name);
    }

    fn_1_49738(fn_1_5233C);
    fn_1_49748(*(const f32 *)(ro + 0xA8));
    fn_1_4AF10((void *)name);
    fn_1_49738(NULL);

    f27 = *(const f32 *)(ro + 0xB8);
    f26 = *(const f64 *)(ro + 0xB0) * f30;
    f28 = *(const f64 *)(ro + 0x68);

    for (i = 0, j = 0, p118 = &bss->field_118[0]; i < bss->field_104;
         i++, j += 0x26, p118++) {
        s32 sel = *(u8 *)(bss->field_10 + 4);
        s32 f8 = bss->field_F8;
        s32 f100 = bss->field_100;
        const s16 *row;
        s16 idx;
        PrologEntry *e;
        const char *nm;
        u32 tmp;

        switch (sel) {
        case 3:  row = (const s16 *)(base + 0x2E78); break;
        case 5:  row = (const s16 *)(base + 0x2DD8); break;
        case 0x1D: row = (const s16 *)(base + 0x2F18); break;
        case 0x20: row = (const s16 *)(base + 0x2FB8); break;
        default: row = (const s16 *)(base + 0x2D38); break;
        }
        idx = row[f100 * 16 + f8 * 4 + i];
        e = (PrologEntry *)(bss->field_60[4] + (idx - 1) * 0x138);

        fn_1_49410();
        fn_1_495FC();
        fn_1_4954C(*(const f32 *)(ro + 0x98));
        fn_1_495C8(1);
        fn_1_495B0(0x80000000); /* fzgx-allow: A1 non-address bit pattern */
        fn_1_495A0(f31);
        fn_1_49590(*(const f32 *)(ro + 0x3C));
        tmp = p118[0];
        fn_1_49514(&tmp);
        fn_1_496FC(*(const f32 *)(ro + 0xA0),
                   f27 + f30 * ((f32)(s32)j - f28));

        if (bss->field_54 == 5) {
            fn_1_4AEC0(1);
            fn_1_4955C(f30, f30);
        } else {
            fn_1_4955C((f32)f26, (f32)f26);
            fn_1_49590(*(const f32 *)(ro + 0x3C));
        }

        if (e->name[0] == 0) {
            nm = *(const char *const *)(base + 0x2778 + (idx - 1) * 4);
        } else {
            char *q = e->name;
            while (*q != '<' && *q != '\0') {
                q++;
            }
            *q = '\0';
            nm = e->name;
        }
        fn_1_4A0D8(nm);
        {
            f32 v = fn_1_4B068(nm);
            if (f29 < v) {
                f29 = v;
            }
        }
        fn_1_4AEC0(0);
    }

    p = *(PrologParam *)lbl_1_rodata_26F8;
    if (f29 < *(const f32 *)(ro + 0xC4)) {
        f29 = *(const f32 *)(ro + 0xC4);
    }
    p.field_04 = 2;
    p.field_08 = *(const f32 *)(ro + 0xA0);
    p.field_0C = *(const f32 *)(ro + 0xBC);
    p.field_10 = *(const f32 *)(ro + 0xC0);
    p.field_30 = bss->field_10C;
    p.field_34 = 6;

    {
        f64 acc = f29 + *(const f32 *)(ro + 0xC8) + *(const f32 *)(ro + 0xCC);
        f64 v = *(const f32 *)(ro + 0xD0) + ((f32)(s32)(i * 0x26) - f28);
        fn_1_50A90(&p.field_04, 0x12, 0x2D, (s32)(acc * f30), (s32)(f30 * v));
    }
    {
        u32 tmp = *(const u32 *)(ro + 0x70);
        fn_1_49514(&tmp);
    }
    fn_1_49614();
    fn_1_49410();
}
