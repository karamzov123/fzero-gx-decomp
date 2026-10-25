/* Non-matching: best partial attempt (82.86% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_3_bss_0[];
extern u8 lbl_3_data_0[];
extern u32 lbl_1_bss_6D82C;
extern void fn_3_23524(void);
extern void fn_1_4A00(u32, u32, u32);
extern void fn_8006FDEC(void);
extern s32 fn_1_3F8C(void *, void *, u32, u32);
extern void fn_1_14E9E4(s32, void *);
extern s16 fn_1_14F014(void);
extern void fn_80008BEC(void *, s32, u32);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_1_12AB38(void *);
extern void *fn_1_D3884(void *);
extern void *fn_1_12A32C(void *);
extern void fn_1_12A2B8(s32);
extern void fn_1_12A2C4(s32);
extern void fn_1_14D994(void *, u32, u32);
extern void fn_1_151BDC(void);
extern void fn_3_78C8(s32);
extern void fn_3_7A08(s16 *, s16 *, u32);
extern void fn_1_47F74(s32);

void fn_3_7038(void) {
    struct {
        u8 *p;
    } b;
    struct {
        u8 *p;
    } d;
    u8 *bss;
    u8 *data;
    u8 *b20000;
    u8 *b70000;
    u8 *b80000;
    u8 *p24;
    u8 *p21;
    u8 *p25;
    s16 buf1[3];
    s16 buf2[3];
    s16 lo;
    s16 hi;
    s16 *rowp;
    u8 *dst;
    s16 i;
    s16 j;
    s16 col;
    s16 row;
    s16 total;

    b.p = lbl_3_bss_0;
    d.p = lbl_3_data_0;
    bss = b.p;
    data = d.p;
    b20000 = bss + 0x20000;
    b70000 = bss + 0x70000;
    b80000 = bss + 0x80000;
    p24 = b70000 - 0x2740;
    p21 = b80000 - 0x1DC0;
    p25 = b80000 - 0x1910;

    fn_1_4A00(1, 0xF, *(u32 *) (b20000 + 0x850));
    *(u32 *) (b20000 + 0x43A8) = 0;
    if (*(s32 *) (data + 0xB8) == -1) {
        fn_8006FDEC();
        *(u32 *) (data + 0xB8) = fn_1_3F8C(data + 0x191C, fn_3_23524, 0, 8);
    }

    for (i = 0; i < fn_1_14F014(); i++) {
        fn_1_14E9E4(i, p24 + i * 0x10);
    }

    fn_80008BEC(buf1, 0, 6);
    for (j = 0; j < fn_1_14F014(); j++) {
        s16 v = *(s16 *) (p24 + j * 0x10 + 2);

        dst = p21 + v * 0x190 + buf1[v] * 0x10;
        fn_80008BA8(dst, p24 + j * 0x10, 0x10);
        buf1[v] = buf1[v] + 1;
    }

    if (lbl_1_bss_6D82C == 0) {
        fn_1_12AB38(data + 0x18A4);
        lbl_1_bss_6D82C = (u32) fn_1_D3884(data + 0x18B0);
        fn_1_12AB38(data + 0x18C0);
    }
    *(u32 *) (data + 0x11D8) = (u32) fn_1_12A32C(data + 0x1180);
    fn_1_12A2B8(1);
    fn_1_12A2C4(1);
    fn_1_14D994(b70000 - 0x21E0, 1 << *(u32 *) (b20000 + 0x848), 1);
    fn_1_12A2B8(0);
    fn_1_12A2C4(0);

    fn_80008BEC(buf2, 0, 6);
    for (i = 0; i < fn_1_14F014(); i++) {
        s16 v = *(s16 *) (p24 + i * 0x10 + 2);

        dst = p21 + v * 0x190 + buf2[v] * 0x10;
        fn_80008BA8(dst, p24 + i * 0x10, 0x10);
        buf2[v] = buf2[v] + 1;
    }

    *(s32 *) (bss + 0x120) = -1;
    fn_1_151BDC();
    fn_3_78C8(1);

    rowp = (s16 *) (bss + 0x20);
    *(s16 *) ((u8 *) rowp + 0x18) = 0;
    *(u8 *) (bss + 0x20) = *(s16 *) ((u8 *) rowp + 0x22);
    *(u8 *) ((u8 *) rowp + 0x8) = *(s16 *) ((u8 *) rowp + 0x58);
    *(u8 *) ((u8 *) rowp + 0x10) = *(s16 *) ((u8 *) rowp + 0x8E);

    dst = p25;
    total = 0;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < rowp[0x10]; col++) {
            fn_1_14E9E4(rowp[0x11 + col], dst);
            dst += 0x10;
            total++;
        }
        rowp += 0x1B;
    }
    *(s16 *) (b80000 - 0x1460) = total;

    rowp = (s16 *) (bss + 0x20);
    rowp[0x61] = 0;
    rowp[0x62] = 0;
    for (j = 0; j < rowp[0x61]; j++) {
        fn_3_7A08(&lo, &hi, 6);
        if (rowp[0x61] > hi) {
            rowp[0x62] = rowp[0x62] - 1;
        }
    }
    fn_1_47F74(0xA3);
    *(u32 *) (bss + 0xC) = 0;
}
