/* Non-matching: best partial attempt (96.87% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad[0x324];
    s32 unk_324;
} Obj_1_7F934;

struct Obj_1_80071718 {
    u8 pad_0[0xC];
    u32 unk_C;
};

extern u32 lbl_1_bss_7B180[];
extern u8 lbl_1_data_3E358[];
extern u32 lbl_1_bss_6D82C[3];
extern s16 lbl_1_bss_960;
extern u32 lbl_801A6410;
extern int sprintf(char *, const char *, ...);
extern u32 fn_1_3F8C0(void);
extern u32 fn_80008E84(u32);
extern void fn_1_14DBCC(void *);
extern u32 fn_1_12A734(u32);
extern void fn_1_7F934(Obj_1_7F934 *);
extern void fn_1_46B4(u32, u32, u8 *, u32);
extern void fn_1_435C(void *);
extern void fn_1_426C(u32);
extern void fn_80071718(struct Obj_1_80071718 *);
extern void fn_80008BEC(void *, void *, u32);

#define PW(off) (*(u32 *)(bss + (off)))
#define PH(off) (*(s16 *)(bss + (off)))
#define PB(off) (*(u8 *)(bss + (off)))

#define SLOT(p, line)                                                           \
    if (*(p) != 0) {                                                            \
        fn_1_46B4(lbl_801A6410, *(p), data + 0x2d4, (line));                     \
        *(p) = 0;                                                               \
    }

static inline u32 fn_1_E9CFC_array_read(s32 index, u32 *array) { return array[index]; }
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
void fn_1_E9CFC(void) {
    u8 *data;
    u8 *bss;
    u32 v_2;
    char msgA[0x100];
    char msgB[0x100];
    char msgC[0x100];
    u32 *p17a8;
    u32 *p1794;
    u32 *p16ec;
    u32 *p1700;
    u32 *p1714;
    u32 *p1728;
    u32 *p1600;
    u32 *p1614;
    u32 *p1628;
    u32 *p163c;
    u32 *p1650;
    u32 *p1664;
    u32 *p1678;
    u32 *p168c;
    u32 *p16a0;
    u32 *p16b4;
    s16 *sh;
    u32 *wd;
    u8 *by;
    u32 i;
    struct { u32 value; } j;
    u32 k;
    u32 v;
    u8 *record;

    data = lbl_1_data_3E358;
    bss = (u8 *)&lbl_1_bss_7B180;

    if (*(s32 *)(bss + 8) != 0) {
        if (lbl_1_bss_960 == 9) {
            PW(0x16dc) = fn_80008E84(fn_1_3F8C0());
        }
        v = PW(0x16e4);
        PW(8) = 0;
        if (v != 0) {
            fn_1_46B4(lbl_801A6410, v, data + 0x2d4, 0x353);
            PW(0x16e4) = 0;
        }
        v = PW(0x16e8);
        if (v != 0) {
            fn_1_46B4(lbl_801A6410, v, data + 0x2d4, 0x358);
            PW(0x16e8) = 0;
        }
        sh = (s16 *)(bss + 0x17d0);
        wd = (u32 *)(bss + 0x17dc);
        by = (u8 *)(bss + 0x17f0);
        for (k = 0; k < 5; k++) {
            sh[k] = -1;
            wd[k] = 0;
            by[k * 3] = 0;
            by[k * 3 + 1] = 0;
            by[k * 3 + 2] = 0;
        }
        p16ec = (u32 *)(bss + 0x16ec);
        p17a8 = (u32 *)(bss + 0x17a8);
        p1794 = (u32 *)(bss + 0x1794);
        p1700 = (u32 *)(bss + 0x1700);
        p1714 = (u32 *)(bss + 0x1714);
        p1728 = (u32 *)(bss + 0x1728);
        p1600 = (u32 *)(bss + 0x1600);
        p1614 = (u32 *)(bss + 0x1614);
        p1628 = (u32 *)(bss + 0x1628);
        p163c = (u32 *)(bss + 0x163c);
        p1650 = (u32 *)(bss + 0x1650);
        p1664 = (u32 *)(bss + 0x1664);
        p1678 = (u32 *)(bss + 0x1678);
        p168c = (u32 *)(bss + 0x168c);
        p16a0 = (u32 *)(bss + 0x16a0);
        p16b4 = (u32 *)(bss + 0x16b4);
        i = 0;
        do {
            if (*p17a8 != 0) {
                fn_1_14DBCC((void *)*p17a8);
                fn_1_46B4(lbl_801A6410, *p17a8, data + 0x2d4, 0x369);
                sprintf(msgA, (const char *)(data + 0x338), i);
                *p17a8 = 0;
            }
            if (*p1794 != 0) {
                if (*(s32 *)(*p1794 + 0x324) != -1) {
                    fn_1_12A734(*(u32 *)(*p1794 + 0x324));
                    *(u32 *)(*p1794 + 0x324) = -1;
                }
                fn_1_7F934((Obj_1_7F934 *)*p1794);
                fn_1_46B4(lbl_801A6410, *p1794, data + 0x2d4, 0x378);
                sprintf(msgB, (const char *)(data + 0x348), i);
                *p1794 = 0;
            }
            SLOT(p16ec, 0x381)
            SLOT(p1700, 0x382)
            SLOT(p1714, 0x383)
            SLOT(p1728, 0x384)
            SLOT(p1600, 0x385)
            SLOT(p1614, 0x386)
            SLOT(p1628, 0x387)
            SLOT(p163c, 0x388)
            SLOT(p1650, 0x389)
            SLOT(p1664, 0x38a)
            SLOT(p1678, 0x38b)
            SLOT(p168c, 0x38c)
            SLOT(p16a0, 0x38d)
            sprintf(msgC, (const char *)(data + 0x354), i);
            SLOT(p16b4, 0x395)
            p16ec++;
            p1794++;
            p1700++;
            p1714++;
            p1728++;
            p1600++;
            p1614++;
            p1628++;
            p163c++;
            p1650++;
            p1664++;
            p1678++;
            p168c++;
            p16a0++;
            p16b4++;
            p17a8++;
            i++;
        } while (i < 5);
        if (fn_1_E9CFC_array_read(0, lbl_1_bss_6D82C) != 0) {
            v_2 = fn_80008E84(fn_1_3F8C0());
            fn_80071718((struct Obj_1_80071718 *)fn_1_E9CFC_array_read(0, lbl_1_bss_6D82C));
            lbl_1_bss_6D82C[0] = 0;
            fn_80008E84(v_2);
        }
        *(u32 *)(data + 0x1d8) = -1;
        *(u32 *)(data + 0x1d4) = -1;
        PW(0x16c8) = -1;
        PB(0x174e) = 0;
        PB(0x1754) = 0;
        PW(0x17c4) = 0;
        PW(0x10) = 0;
        PB(0x16cc) = 0xff;
        if (lbl_1_bss_960 == 9) {
            fn_80008E84(PW(0x16dc));
        }
        fn_1_435C((void *)PW(0x1744));
        if (*(s32 *)(bss + 0x173c) != 0) {
            fn_1_426C(PW(0x173c));
        }
        fn_1_435C((void *)PW(0x1748));
        if (*(s32 *)(bss + 0x1740) != 0) {
            fn_1_426C(PW(0x1740));
        }
        PW(0x1744) = 0;
        PW(0x1748) = 0;
        PW(0x173c) = 0;
        PW(0x1740) = 0;
        record = bss + 0x2c;
        for (j.value = 0; j.value < 0x7f; j.value++) {
            fn_80008BEC(record, 0, 0x28);
            record += 0x28;
        }
        PW(0x17cc) = 1;
        PW(0xc) = 0;
        *(s16 *)(data + 0x1dc) = -1;
    }
}
#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset

