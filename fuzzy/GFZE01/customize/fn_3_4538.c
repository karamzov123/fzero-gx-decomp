/* Non-matching: best partial attempt (99.06% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 unk_0;
    u32 unk_4;
    union {
        s16 s;
        u16 u;
    } f8;
    u16 unk_A;
    u32 unk_C;
    volatile u16 f10;  /* fzgx: retail reloads this field per bit test */
    volatile u16 unk_12;  /* fzgx: retail reloads this field per bit test */
} fn_3_4538_elem;

struct fn_3_4538_lbl_3_bss_F0 {
    u8 pad_0[0x6];
    s16 unk_6;
    s16 unk_8;
};

struct fn_3_4538_lbl_3_data_C4 {
    s16 unk_0;
};

extern struct fn_3_4538_lbl_3_bss_F0 lbl_3_bss_F0;
extern struct fn_3_4538_lbl_3_data_C4 lbl_3_data_C4;
extern fn_3_4538_elem lbl_1_bss_9F8[1];
extern u32 lbl_3_bss_2C584[98];
extern s16 lbl_3_bss_20[104];
extern u8 lbl_3_bss_140[1];
extern u8 lbl_3_bss_243C0[1];
extern u8 fn_1_152CB4(s32, s16, s16, u32 *, s32, s32);
extern s32 fn_1_8D5F0(s16);
extern s32 fn_1_F7BE4(s16);
extern void fn_1_A2D84(u32);
extern s32 fn_1_152970(s16 *, s16 *, s16, s32, u32 *, s32, s32);
extern void fn_3_7A08(s16 *, s16 *, int);
extern void fn_3_BD00(s16, s32, s16, s32);
extern s32 fn_3_837C(s16);

static inline u8 fn_3_4538_array_read(s32 index, u8 *array) { return array[index]; }
#pragma opt_strength_reduction on
s32 fn_3_4538(u32 lab_unused0) {
    struct fn_3_4538_lbl_3_bss_F0 *p;
    s16 fzgx_value;
    s32 tmp_call7;
    s32 sel;
    s32 off;
    s32 res;
    s16 c1;
    s16 c2;
    s32 v2;
    s32 v0;
    s16 flag;
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    s16 i;

    p = &lbl_3_bss_F0;
    v0 = lbl_3_data_C4.unk_0;
    off = p->unk_6;
    res = 0;
    (void) res;  /* fzgx: keeps the web at its definition */
    v2 = p->unk_8;
    c1 = 0;
    c2 = 0;
    flag = 0;
    i = 0;

    while (i < 41) {
        if ((fn_1_8D5F0(i) & 0x10000000) && fn_1_F7BE4(i)) {
            flag = 1;
            break;
        }
        i++;
    }

    if ((((*((off) + (lbl_1_bss_9F8))).f10 >> 3) & 1) ||
        (((*((off) + (lbl_1_bss_9F8))).unk_12 >> 3) & 1)) {
        c1 = -1;
    }

    if ((((*((off) + (lbl_1_bss_9F8))).f10 >> 2) & 1) ||
        (((*((off) + (lbl_1_bss_9F8))).unk_12 >> 2) & 1)) {
        c1++;
    }

    if (((*((off) + (lbl_1_bss_9F8))).f10 & 1) ||
        ((*((off) + (lbl_1_bss_9F8))).unk_12 & 1)) {
        c2 = -1;
    }

    if ((((*((off) + (lbl_1_bss_9F8))).f10 >> 1) & 1) ||
        (((*((off) + (lbl_1_bss_9F8))).unk_12 >> 1) & 1)) {
        c2++;
    }

    if (c2 || c1) {
        sel = fn_1_152CB4(lbl_3_data_C4.unk_0, c1, c2, lbl_3_bss_2C584, 7, 7);
        fzgx_value = (s16)sel;
        lbl_3_data_C4.unk_0 = fzgx_value;
        if (flag == 0) {
            if (((u16)((s16)sel - 0x18) <= 2) || ((s16)sel == 0x1B)) {
                if ((c1 > 0) && (v0 == (s16)sel)) {
                    lbl_3_data_C4.unk_0 = 0x1E;
                }
            }
        } else {
            if (((s16)sel == 0x22) && (c1 > 0) && (v0 == (s16)sel)) {
                lbl_3_data_C4.unk_0 = 0x28;
            }
        }
    }

    if (v0 != lbl_3_data_C4.unk_0) {
        fn_1_A2D84(0xA9010000);
    }

    fn_1_152970(&c, &d, lbl_3_data_C4.unk_0, 0, lbl_3_bss_2C584, 7, 7);
    fn_3_7A08(&a, &b, 3);

    if ((c < a) || (c > b)) {
        fn_3_BD00(c1, 0, (s16)(c1 * 10), 0x800000);
        lbl_3_bss_20[98] -= c1;
    }

    if (fn_1_F7BE4(lbl_3_data_C4.unk_0)) {
        u8 val;

        val = (u8)lbl_3_data_C4.unk_0;
        lbl_3_bss_140[v2 * 0x81C0 + 0x81A0] = val;
        lbl_3_bss_140[v2 * 0x81C0 + 5] = val;
    } else {
        u8 val;

        val = fn_3_4538_array_read(0x81A0, lbl_3_bss_243C0);
        lbl_3_bss_140[((0x81A0) + (v2 * 0x81C0))] = val;
        lbl_3_bss_140[v2 * 0x81C0 + 5] = val;
    }

    tmp_call7 = fn_1_F7BE4(lbl_3_data_C4.unk_0);
    if (tmp_call7) {
        if (fn_3_837C(p->unk_8) == 1) {
            if ((((*((off) + (lbl_1_bss_9F8))).f8.s >> 12) & 1) ||
                (((*((off) + (lbl_1_bss_9F8))).f8.u >> 11) & 1)) {
                res = 0xC;
                (void) res;  /* fzgx: keeps the web at its definition */
                fn_1_A2D84(0xA9010100);
            } else if (((*((off) + (lbl_1_bss_9F8))).f8.u >> 8) & 1) {
                res = 0xB;
                fn_1_A2D84(0xA9010100);
            }
        }
    }

    if (((*((off) + (lbl_1_bss_9F8))).f8.u >> 9) & 1) {
        res = -1;
        fn_1_A2D84(0xA9010200);
    }

    return res;
}
#pragma opt_strength_reduction reset
