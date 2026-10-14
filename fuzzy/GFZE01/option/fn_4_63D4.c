/* Non-matching: best partial attempt (62.22% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/option/globals.h"

extern s32 lbl_801A66B4;

struct fn_4_63D4_rodata {
    u8 pad_0[8];
    f32 unk_8;
    u8 pad_C[0x3C];
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C;
    u8 pad_60[0x5C];
    f32 unk_BC;
    f32 unk_C0;
    f32 unk_C4;
};

struct fn_4_63D4_bss {
    u8 pad_0[0x118];
    u8 unk_118;
    u8 pad_119[2];
    u8 unk_11B;
    u8 unk_11C;
    u8 pad_11D;
    u8 unk_11E;
};

extern struct fn_4_63D4_rodata lbl_4_rodata_0;
extern void _savegpr_27(void);
extern void fn_1_49410(void);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_49738(u32);
extern void fn_1_49748(f32);
extern void fn_1_53E40(u32, f32, f32, f32, f32, f32, void *);
extern void fn_1_5233C(void);
extern int sprintf(char *, const char *, ...);
extern void fn_1_1380F0(void *);
extern void fn_1_13ABA8(u32);
extern void fn_4_2D4(u32, void *);
extern void fn_4_4DF8(void);

void fn_4_63D4(void) {
    struct fn_4_63D4_bss *p_bss;
    u8 *p_data;
    struct fn_4_63D4_rodata *p_rodata;
    void *v;
    u32 a2;
    char buf[504];

    p_bss = (struct fn_4_63D4_bss *)&lbl_4_bss_0;
    p_data = (u8 *)&lbl_4_data_0;
    p_rodata = &lbl_4_rodata_0;

    v = ((void **)(p_data + 0x1A4))[lbl_801A66B4];
    a2 = 0x20000000;

    fn_1_49410();
    fn_1_495C8(1);
    if (lbl_801A66B4 != 5) {
        fn_1_495B0(0x80000000);
        fn_1_49590(p_rodata->unk_8);
    }

    switch (p_bss->unk_11B) {
    case 0:
        a2 = 0x28000000;
        v = ((void **)(p_data + 0x23C))[lbl_801A66B4];
        fn_1_49738((u32)fn_1_5233C);
        fn_1_49748(p_rodata->unk_48);
        fn_1_53E40(0, p_rodata->unk_50, p_rodata->unk_58, p_rodata->unk_BC,
                   p_rodata->unk_C0, p_rodata->unk_C4,
                   ((void **)(p_data + 0x778))[lbl_801A66B4]);
        break;
    case 1:
        if (p_bss->unk_11E == 0) {
            a2 = 0;
            v = ((void **)(p_data + 0x1A4))[lbl_801A66B4];
        } else {
            a2 = 0x48000000;
            v = ((void **)(p_data + 0xE8))[lbl_801A66B4];
            fn_4_2D4(p_bss->unk_11C & 1, ((void **)(p_data + 0x884))[lbl_801A66B4]);
        }
        break;
    case 2:
        a2 = 0x28000000;
        v = ((void **)(p_data + 0xE8))[lbl_801A66B4];
        fn_4_4DF8();
        break;
    case 3:
    case 4:
        a2 = 0x48000000;
        v = ((void **)(p_data + 0x158))[lbl_801A66B4];
        fn_4_4DF8();
        break;
    case 5:
        a2 = 0x48000000;
        v = ((void **)(p_data + 0xE8))[lbl_801A66B4];
        fn_4_2D4(p_bss->unk_11C, ((void **)(p_data + 0x364))[lbl_801A66B4]);
        fn_4_4DF8();
        break;
    case 6:
        a2 = 0x48000000;
        v = ((void **)(p_data + 0xE8))[lbl_801A66B4];
        fn_4_2D4(p_bss->unk_11C, ((void **)(p_data + 0x8C0))[lbl_801A66B4]);
        fn_4_4DF8();
        break;
    case 7:
        v = p_data + 0xC;
        a2 = 0;
        fn_1_49410();
        fn_1_49738((u32)fn_1_5233C);
        fn_1_49748(p_rodata->unk_48);
        if (lbl_801A66B4 != 5) {
            fn_1_495B0(0x80000000);
            fn_1_49590(p_rodata->unk_8);
        }
        sprintf(buf, ((char **)(p_data + 0x560))[lbl_801A66B4], p_bss->unk_118 + 1);
        fn_1_53E40(0, p_rodata->unk_50, p_rodata->unk_58, p_rodata->unk_BC,
                   p_rodata->unk_C0, p_rodata->unk_C4, buf);
        break;
    }

    fn_1_1380F0(v);
    fn_1_13ABA8(a2);
}
