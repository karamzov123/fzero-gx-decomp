/* Non-matching: best partial attempt (95.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/toolkit.h"

struct fn_3_1A648_lbl_1_bss_9F8_8_E20 {
    u16 unk_0;
    u8 pad_2[0x12];
};

struct fn_3_1A648_lbl_1_bss_9F8 {
    u8 pad_0[0x8];
    struct fn_3_1A648_lbl_1_bss_9F8_8_E20 unk_8[1];
};

extern struct fn_3_1A648_lbl_1_bss_9F8 lbl_1_bss_9F8;
extern u8 fn_3_14064(void);
extern u32 fn_3_1401C(void);
extern u32 fn_3_1402C(u8);
extern void fn_3_1445C(void);
extern void fn_1_A2D84(u32);
extern void fn_80008BA8(u32, u32, u32);
extern void fn_80008BEC(void *, int, u32);

#pragma opt_pointer_analysis on
#pragma opt_propagation off
void fn_3_1A648(void) {
    struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *entries;
    u32 t3;
    u32 t4;
    struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *entries_2;
    u32 t5;
    u8 tmp_ra10;

    entries = (struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *)((u8 *)&lbl_1_bss_9F8 + 0x10);

    if ((entries[lbl_3_bss_A2438.unk_0].unk_0 & 1) != 0 ||
        (*(u16 *)((u8 *)&lbl_1_bss_9F8 + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) & 1) != 0) {
        if ((lbl_3_bss_A2438.unk_8 & 0x40000000) != 0) {
            if (lbl_3_bss_A2438.unk_10 == 0) {
                fn_1_A2D84(0xA9010000);
            }
            lbl_3_bss_A2438.unk_10 = 1;
        } else if (lbl_3_bss_A2438.unk_14 != 0) {
            fn_1_A2D84(0xA9150600);
            lbl_3_bss_A2438.unk_14--;
        }
    }

    if (((entries[lbl_3_bss_A2438.unk_0].unk_0 >> 1) & 1) != 0 ||
        ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) >> 1) & 1) != 0) {
        if ((lbl_3_bss_A2438.unk_8 & 0x40000000) != 0) {
            if (lbl_3_bss_A2438.unk_10 != 0) {
                fn_1_A2D84(0xA9010000);
            }
            lbl_3_bss_A2438.unk_10 = 0;
        } else if (lbl_3_bss_A2438.unk_14 < 4) {
            t3 = fn_3_14064();
            if (((1) + (((lbl_3_bss_A2438.unk_14) + ((lbl_3_bss_A2438.unk_15 * 5) + (lbl_3_bss_A2438.unk_12))))) < (s32)(t3 & 0xFF)) {
                fn_1_A2D84(0xA9150600);
                lbl_3_bss_A2438.unk_14++;
            }
        }
    }

    if (((entries[lbl_3_bss_A2438.unk_0].unk_0 >> 3) & 1) != 0 ||
        ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) >> 3) & 1) != 0) {
        if ((lbl_3_bss_A2438.unk_8 & 0x40000000) == 0) {
            if (lbl_3_bss_A2438.unk_15 != 0) {
                fn_1_A2D84(0xA9150600);
                lbl_3_bss_A2438.unk_15--;
            } else if (lbl_3_bss_A2438.unk_12 - 5 >= 0) {
                fn_1_A2D84(0xA9150600);
                lbl_3_bss_A2438.unk_1A = 10;
                lbl_3_bss_A2438.unk_18 = 0;
                lbl_3_bss_A2438.unk_12 = lbl_3_bss_A2438.unk_12 - 5;
            }
        }
    }

    if (((entries[lbl_3_bss_A2438.unk_0].unk_0 >> 2) & 1) != 0 ||
        ((*(u16 *)((u8 *)&lbl_1_bss_9F8 + lbl_3_bss_A2438.unk_0 * 0x14 + 0x12) >> 2) & 1) != 0) {
        if ((lbl_3_bss_A2438.unk_8 & 0x40000000) == 0) {
            t3 = fn_3_14064();
            if (lbl_3_bss_A2438.unk_12 + 20 < (s32)(t3 & 0xFF)) {
                if (lbl_3_bss_A2438.unk_15 < 3) {
                    fn_1_A2D84(0xA9150600);
                    lbl_3_bss_A2438.unk_15++;
                } else {
                    fn_1_A2D84(0xA9150600);
                    lbl_3_bss_A2438.unk_18 = 10;
                    lbl_3_bss_A2438.unk_1A = 0;
                    lbl_3_bss_A2438.unk_12 = lbl_3_bss_A2438.unk_12 + 5;
                    t3 = fn_3_14064();
                    if ((((lbl_3_bss_A2438.unk_14) + (lbl_3_bss_A2438.unk_15 * 5)) +
                            (lbl_3_bss_A2438.unk_12)) >= (s32)(t3 & 0xFF)) {
                        lbl_3_bss_A2438.unk_15--;
                    }
                }
            } else if (lbl_3_bss_A2438.unk_15 < 3) {
                t3 = fn_3_14064();
                if (((lbl_3_bss_A2438.unk_12) + (((lbl_3_bss_A2438.unk_15 + 1) * 5) +
                        (lbl_3_bss_A2438.unk_14))) < (s32)(t3 & 0xFF)) {
                    fn_1_A2D84(0xA9150600);
                    lbl_3_bss_A2438.unk_15++;
                }
            }
        }
    }

    entries_2 = (struct fn_3_1A648_lbl_1_bss_9F8_8_E20 *)((u8 *)&lbl_1_bss_9F8 + 8);

    if (((entries_2[lbl_3_bss_A2438.unk_0].unk_0 >> 8) & 1) != 0) {
        t4 = fn_3_1401C();
        t5 = fn_3_1402C((u8)((((lbl_3_bss_A2438.unk_12) + (lbl_3_bss_A2438.unk_14)) +
                              (lbl_3_bss_A2438.unk_15 * 5))));
        if ((lbl_3_bss_A2438.unk_8 & 0x40000000) == 0) {
            lbl_3_bss_A2438.unk_8 = lbl_3_bss_A2438.unk_8 | 0x40000000;
        } else if (lbl_3_bss_A2438.unk_10 != 0) {
            if (t5 != 0) {
                fn_80008BA8(t4, t5, 0x2000);
            } else {
                fn_80008BEC((void *)t4, 0, 1);
            }
            lbl_3_bss_A2438.unk_8 = lbl_3_bss_A2438.unk_8 & 0xE0000000;
            lbl_3_bss_A2438.unk_4 = 0x40000000;
            lbl_3_bss_A2438.unk_E = 0;
            lbl_3_bss_A2438.unk_10 = 0;
            fn_3_1445C();
            fn_1_A2D84(0xA9150400);
        } else {
            lbl_3_bss_A2438.unk_8 = lbl_3_bss_A2438.unk_8 & 0xE0000000;
            lbl_3_bss_A2438.unk_10 = 0;
        }
    }

    if (((entries_2[lbl_3_bss_A2438.unk_0].unk_0 >> 9) & 1) != 0) {
        tmp_ra10 = lbl_3_bss_A2438.unk_8;
        if ((tmp_ra10 & 0x40000000) != 0) {
            lbl_3_bss_A2438.unk_8 = lbl_3_bss_A2438.unk_8 & 0xE0000000;
            lbl_3_bss_A2438.unk_10 = 0;
        } else {
            lbl_3_bss_A2438.unk_10 = 0;
            fn_1_A2D84(0xA9150500);
            lbl_3_bss_A2438.unk_4 = 0x40000000;
            lbl_3_bss_A2438.unk_E = 0;
        }
    }
}
#pragma opt_propagation reset
#pragma opt_pointer_analysis reset
