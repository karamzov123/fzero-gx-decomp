/* Non-matching: best partial attempt (84.89% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieTable {
    u8 pad_000[0x1600];
    u32 *f_1600;
    u32 *f_1604;
    u32 *f_1608;
    u32 *f_160c;
    u32 *f_1610;
    u32 *f_1614;
    u32 *f_1618;
    u32 *f_161c;
    u32 *f_1620;
    u32 *f_1624;
    u32 *f_1628;
    u32 *f_162c;
    u32 *f_1630;
    u32 *f_1634;
    u32 *f_1638;
    u32 *f_163c;
    u32 *f_1640;
    u32 *f_1644;
    u32 *f_1648;
    u32 *f_164c;
    u32 *f_1650;
    u32 *f_1654;
} MovieTable;

typedef struct RoData {
    u8 blk_00[0x20];
    u8 blk_20[0x20];
    u8 blk_40[0x20];
    u8 blk_60[0x20];
    u8 blk_80[0x40];
    u8 blk_a0[0x10];
} RoData;

typedef struct BlkTab {
    u8 pad_000[0xb00];
    u8 blk_b00[0x40];
} BlkTab;

typedef struct Off000 {
    u8 blk_000[0x40];
} Off000;

typedef struct OffA00 {
    u8 pad_000[0xa00];
    u8 blk_a00[0x80];
} OffA00;

typedef struct OffA80 {
    u8 pad_000[0x600];
    u8 blk_a80[0x280];
} OffA80;

typedef struct OffF00 {
    u8 pad_000[0xf00];
    u8 blk_f00[0x40];
} OffF00;

typedef struct OffF40 {
    u8 pad_000[0xf40];
    u8 blk_f40[0x40];
} OffF40;

typedef struct Off1040 {
    u8 pad_000[0x1040];
    u8 blk_1040[0x80];
} Off1040;

typedef struct Off10c0 {
    u8 pad_000[0x10c0];
    u8 blk_10c0[0x40];
} Off10c0;

extern RoData lbl_12_rodata_938;
extern u8 lbl_12_bss_52F0[];

extern void fn_12_10980(void);
extern void fn_12_105BC(void);
extern void fn_12_10200(void);
extern void fn_12_1014C(void);
extern void mpvvlc_InitMbTypeBpic(void);
extern void fn_12_FC04(void);
extern signed short *fn_12_FA5C(signed short *);
extern void mpvvlc_InitCbpSub2(void);
extern void fn_12_EFA4(void);
extern void fn_12_ED30(void);
extern void mpvvlc2_InitDcSizY(void);
extern void mpvvlc2_InitDcSizC(void);
extern void fn_12_E0F4(void);
extern void fn_12_33364(u32 *, u32 *, u32);

#pragma opt_strength_reduction on
static inline void fn_12_10F3C_call_fn_12_33364(u32 * a0, u32 * a1, u32 a2) { fn_12_33364(a0, a1, a2); }
void fn_12_10F3C(void *arg) {
    u32 * fzgx_live;
    RoData *ro = &lbl_12_rodata_938;
    MovieTable *t = (MovieTable *)lbl_12_bss_52F0;
    u32 *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;
    u32 *p9, *p10, *p11, *p12, *p13, *p14, *p15;
    u32 *p16, *p17, *p18, *p19, *p20, *p21, *p22;

    fn_12_10980();
    fn_12_105BC();
    fn_12_10200();
    fn_12_1014C();
    mpvvlc_InitMbTypeBpic();
    fn_12_FC04();
    fn_12_FA5C((signed short *)&((BlkTab *)t)->blk_b00[0]);
    mpvvlc_InitCbpSub2();
    fn_12_EFA4();
    fn_12_ED30();
    mpvvlc2_InitDcSizY();
    mpvvlc2_InitDcSizC();
    fn_12_E0F4();

    p1 = (u32 *)((u8 *)t + 0x1400);
    p2 = (u32 *)((u8 *)t + 0x1380);
    p3 = (u32 *)((u8 *)t + 0x1280);
    p4 = (u32 *)((u8 *)t + 0x1240);
    p5 = (u32 *)((u8 *)t + 0x1140);
    p6 = (u32 *)((u8 *)t + 0x1100);
    p7 = (u32 *)((u8 *)t + 0x10c0);
    p8 = (u32 *)((u8 *)t + 0x1040);
    p9 = (u32 *)((u8 *)t + 0xf40);
    p10 = (u32 *)((u8 *)t + 0xf00);
    p11 = (u32 *)((u8 *)t + 0xb00);
    p12 = (u32 *)((u8 *)t + 0xa80);
    p13 = (u32 *)((u8 *)t + 0xa00);
    p14 = (u32 *)((u8 *)t + 0x600);
    p15 = (u32 *)((u8 *)t + 0x200);
    p16 = (u32 *)&lbl_12_rodata_938.blk_00[0];
    p17 = (u32 *)&lbl_12_rodata_938.blk_20[0];
    p18 = (u32 *)&lbl_12_rodata_938.blk_40[0];
    p19 = (u32 *)&lbl_12_rodata_938.blk_60[0];
    p20 = (u32 *)&lbl_12_rodata_938.blk_80[0];
    p21 = (u32 *)&lbl_12_rodata_938.blk_a0[0];
    p22 = (u32 *)&((Off000 *)lbl_12_bss_52F0)->blk_000[0];

    t->f_1654 = p1;
    t->f_1650 = p2;
    t->f_164c = p3;
    t->f_1648 = p4;
    t->f_1644 = p5;
    t->f_1640 = p6;
    t->f_163c = p7;
    t->f_1638 = p8;
    t->f_1634 = p9;
    t->f_1630 = p10;
    t->f_162c = p11;
    t->f_1628 = p12;
    t->f_1624 = p13;
    t->f_1620 = p14;
    t->f_161c = p15;
    t->f_1618 = p16;
    t->f_1614 = p17;
    t->f_1610 = p18;
    t->f_160c = p19;
    t->f_1608 = p20;
    t->f_1604 = p21;
    t->f_1600 = p22;

    if (arg) {
        u8 *q = (u8 *)arg + 0x300;

        t->f_1600 = (u32 *)((u8 *)arg + 0x3b0);
        fn_12_10F3C_call_fn_12_33364(t->f_1600, p22, 0x80);
        t->f_1604 = (u32 *)((u8 *)arg + 0x3a0);
        fn_12_33364(t->f_1604, (u32 *)((u8 *)ro + 0xa0), 4);
        t->f_1608 = (u32 *)((u8 *)arg + 0x380);
        fn_12_33364(t->f_1608, (u32 *)((u8 *)ro + 0x80), 8);
        t->f_160c = (u32 *)((u8 *)arg + 0x360);
        fn_12_33364(t->f_160c, (u32 *)((u8 *)ro + 0x60), 8);
        t->f_1610 = (u32 *)((u8 *)arg + 0x340);
        fn_12_33364(t->f_1610, (u32 *)((u8 *)ro + 0x40), 8);
        t->f_1614 = (u32 *)((u8 *)arg + 0x320);
        fn_12_33364(t->f_1614, (u32 *)((u8 *)ro + 0x20), 8);
        t->f_1618 = (u32 *)((u8 *)arg + 0x300);
        fn_12_33364(t->f_1618, (u32 *)((u8 *)ro + 0x0), 8);
        t->f_1628 = (u32 *)((u8 *)arg + 0x280);
        fn_12_33364(t->f_1628, (u32 *)&((OffA80 *)t)->blk_a80[0], 0x20);
        t->f_1624 = (u32 *)(q - 0x100);
        fzgx_live = t->f_1624;
        fn_12_33364(fzgx_live, (u32 *)&((OffA00 *)t)->blk_a00[0], 0x20);
        t->f_1634 = (u32 *)(q - 0x200);
        fn_12_33364(t->f_1634, (u32 *)&((OffF40 *)t)->blk_f40[0], 0x40);
        t->f_1630 = (u32 *)(q - 0x240);
        fn_12_33364(t->f_1630, (u32 *)&((OffF00 *)t)->blk_f00[0], 0x10);
        t->f_163c = (u32 *)(q - 0x280);
        fn_12_33364(t->f_163c, (u32 *)&((Off10c0 *)t)->blk_10c0[0], 0x10);
        t->f_1638 = (u32 *)(q - 0x300);
        fn_12_33364(t->f_1638, (u32 *)&((Off1040 *)t)->blk_1040[0], 0x20);
    }
}
#pragma opt_strength_reduction reset

