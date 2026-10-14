/* Non-matching: best partial attempt (71.45% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_1_data_42198;
extern u8 lbl_1_bss_8E51D;
extern u8 lbl_1_bss_8E594;
extern u8 lbl_1_bss_8E52C;
extern s32 lbl_1_bss_8E570[9];
extern u32 lbl_801A66A4;
extern s32 lbl_801A66B4;
extern void *lbl_1_data_212A8[];
extern struct { u8 pad[8]; u8 unk_8; } lbl_1_bss_3C30;
extern u32 lbl_1_rodata_92C0[];

extern void fn_1_49410(void);
extern void fn_1_149B64(void *, void *);
extern void fn_1_149B24(void *, void *);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_495C8(s32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4954C(f32);
extern s32 fn_1_155F8C(void);
extern s32 fn_1_155F7C(void);
extern void fn_1_49514(void *);
extern void fn_1_49528(void *);
extern void fn_1_4A0D8(const char *);
extern void fn_1_495B0(u32);
extern void fn_1_49590(f32);
extern f32 fn_1_4B090(const char *);
extern void fn_1_53B14(void *, f32, f32, f32, f32, f32);
extern u32 fn_1_53C9C(void *, void *, f32, f32, f32, f32, f32);
extern void fn_1_494DC(s16);
extern void fn_1_4962C(void);
extern void fn_1_4966C(f32, f32);
extern s16 fn_1_12C930(s16);
extern void fn_1_4CE48(void *, f32);
extern char *strncpy(char *, const char *, size_t);
extern size_t strlen(const char *);
extern s32 strncmp(const char *, const char *, size_t);
extern char *fn_80083DB0(char *, const char *);
extern f32 lbl_8006D188(s32);
extern int sprintf(char *, const char *, ...);
extern s32 fn_8006FC1C(void *, void *);

typedef struct {
    u8 r, g, b, a;
} Col;

typedef struct {
    s32 unk_0;
    u8 pad_4[0x1C];
    s32 unk_20;
    s32 unk_24;
    char *unk_28;
    void *unk_2C;
    u8 pad_30[0x1C];
    s32 unk_4C;
    u8 pad_50[0x14];
    s32 unk_64;
    s32 unk_68;
    u8 pad_6C[8];
    s32 unk_74;
    s32 unk_78;
} Sel;

typedef struct {
    char *r[4][6];
} Tbl;

#define MODE_A(m) (((u32)((m) - 4) <= 1) || (m) == 9 || (m) == 10 || (m) == 6)

void fn_1_147A04(s32 arg0, Sel *arg1) {
    char buf[0x11];
    char sbuf[0x100];
    u8 *d = (u8 *)&lbl_1_data_42198;
    s32 len;
    s32 i;
    char *p;
    s32 flag;

    if (MODE_A(arg0)) {
        fn_1_49410();
        fn_1_49738(fn_1_149B64);
        fn_1_49748(0.0f);
        fn_1_495C8(8);
        fn_1_496FC((f32)(arg1->unk_68 + arg1->unk_74 + 180), (f32)(arg1->unk_64 + 21));
        fn_1_4955C(0.75f, 0.75f);
        fn_1_4954C(48.0f);
        buf[16] = 0;
        strncpy(buf, arg1->unk_28, 16);
        if (lbl_1_bss_8E51D == 6 && arg1->unk_20 == fn_1_155F8C()) {
            if (lbl_1_bss_8E594 != 0) {
                len = strlen(buf);
            } else {
                len = strlen(buf) - 2;
            }
        } else {
            len = strlen(buf);
        }
        p = buf;
        for (i = 0; i < len; i += 2) {
            if (strncmp(p, (char *)(d + 0x664), 2) == 0) {
                strncpy(p, (char *)(d + 0x668), 2);
                fn_80083DB0(p + 1, p + 2);
                p += 1;
            } else {
                p += 2;
            }
        }
        if (lbl_1_bss_8E51D == 6 && arg1->unk_20 == fn_1_155F8C()) {
            Col c1;
            Col c2;
            Col c3;
            c1 = *(Col *)((u8 *)lbl_1_rodata_92C0 + 0x490);
            fn_1_49514(&c1);
            c2 = *(Col *)((u8 *)lbl_1_rodata_92C0 + 0x494);
            c2.g = (u8)(255.0f * lbl_8006D188((s16)(lbl_801A66A4 << 8)));
            c2.b = (u8)(255.0f * lbl_8006D188((s16)(lbl_801A66A4 << 8)));
            c3 = c2;
            fn_1_49528(&c3);
            if (lbl_1_bss_8E594 != 0) {
                if (lbl_801A66A4 % 60 > 10) {
                    strncpy(buf + strlen(buf), (char *)(d + 0x66c), 3);
                }
            } else {
                if (lbl_801A66A4 % 60 > 50) {
                    if (strlen(buf) >= 2) {
                        buf[strlen(buf) - 2] = 0;
                    }
                }
            }
        }
        fn_1_4A0D8(buf);
        if (lbl_1_bss_8E51D == 6 && arg1->unk_20 == fn_1_155F8C()) {
            Tbl tbl = *(Tbl *)((u8 *)lbl_1_rodata_92C0 + 0x498);
            char *a[6];
            f32 f31;
            f32 f30;
            *(u32 *)&a[0] = lbl_1_rodata_92C0[0x4f8 / 4];
            *(u32 *)&a[1] = lbl_1_rodata_92C0[0x4fc / 4];
            *(u32 *)&a[2] = lbl_1_rodata_92C0[0x500 / 4];
            *(u32 *)&a[3] = lbl_1_rodata_92C0[0x504 / 4];
            *(u32 *)&a[4] = lbl_1_rodata_92C0[0x508 / 4];
            *(u32 *)&a[5] = lbl_1_rodata_92C0[0x50c / 4];
            if ((f32)arg1->unk_78 > 45.0f) {
                s32 row = lbl_1_bss_8E570[0];
                if (row < 0) {
                    row = 0;
                } else if (row > 3) {
                    row = 3;
                }
                sprintf(sbuf, a[lbl_801A66B4], tbl.r[row][lbl_801A66B4]);
            }
            fn_1_49410();
            fn_1_495B0(0x80000000);
            fn_1_49590(0.5f);
            if (lbl_801A66B4 != 5) {
                f31 = (f32)(arg1->unk_68 + 0x9e);
                f30 = (f32)(arg1->unk_64 + 0x2e);
                if ((f32)arg1->unk_78 > 45.0f) {
                    fn_1_496FC(f31, f30);
                    fn_1_4954C(0.01f - 0.0005);
                    fn_1_4955C(0.6666667f, 0.6666667f);
                    fn_1_495C8(8);
                    fn_1_4A0D8(sbuf);
                    fn_1_53B14(0, 166.0f + f31, f30, 348.33334f, 13.333333f + fn_1_4B090(sbuf), 0.01f);
                }
            } else {
                f32 t = ((f32)arg1->unk_78 - 40.0f) / 5.0f;
                if (t > 1.0f) {
                    t = 1.0f;
                }
                fn_1_53C9C(0, sbuf, (f32)(arg1->unk_68 + 0x122), (f32)(arg1->unk_64 + 0x2e), 0.01f, 20.0f,
                           (9.0f + 7.0f * t) / 24.0f);
            }
        }
    } else {
        fn_1_49410();
        fn_1_494DC(0x15);
        fn_1_495B0(0x80000000);
        fn_1_49738(fn_1_149B24);
        if ((((u32)(arg0 - 8) <= 1) || arg0 == 10) || MODE_A(arg0)) {
            fn_1_496FC((f32)(arg1->unk_68 + arg1->unk_74 + 0xa6), (f32)(arg1->unk_64 + 0xb));
        } else if ((u32)arg0 <= 1) {
            fn_1_496FC((f32)(arg1->unk_68 + arg1->unk_74 + 0x96), (f32)(arg1->unk_64 + 0xd));
        } else {
            fn_1_496FC((f32)(arg1->unk_74 + 0xc4), (f32)(arg1->unk_64 + 0xd));
        }
        fn_1_4954C(47.0f);
        fn_1_4962C();
        fn_1_49590(0.5f);
        fn_1_4966C(-1.0f, 0.0f);
        if (arg0 == 10 || arg0 == 6) {
            flag = (arg1->unk_20 == 0);
        } else if (MODE_A(arg0)) {
            flag = 0;
            if (fn_1_155F7C() != 0) {
                if (arg1->unk_20 == fn_1_155F8C()) {
                    flag = 1;
                }
            }
        } else {
            flag = lbl_1_bss_3C30.unk_8 < arg1->unk_4C;
        }
        if (flag != 0) {
            Col c4;
            c4.a = 255;
            c4.b = 255;
            c4.r = 255;
            c4.g = (u8)(255.0f * ((1.0f - lbl_8006D188((s32)(65536.0f * (f32)((s32)lbl_801A66A4 % 60) / 60.0f))) * 0.5f));
            fn_1_49514(&c4);
        }
        if (lbl_1_bss_8E52C != 0) {
            s16 k = fn_1_12C930((s16)arg1->unk_24);
            if (fn_8006FC1C(lbl_1_data_212A8[k], d + 0x430) != 0) {
                fn_1_4CE48(d + 0x440, 170.0f);
            } else {
                fn_1_4CE48(lbl_1_data_212A8[fn_1_12C930((s16)arg1->unk_24)], 170.0f);
            }
        } else {
            fn_1_4CE48(arg1->unk_2C, 170.0f);
        }
    }
}
