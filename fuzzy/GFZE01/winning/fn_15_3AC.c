/* Non-matching: best partial attempt (98.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_15_3AC_lbl_15_bss_0 {
    u8 pad_0[0x4];
    u8 unk_4;
    u8 pad_5[0xF];
    u32 unk_14;
    u8 pad_18[0x8];
    u8 unk_20;
    u8 pad_21[2];
    u8 unk_23;
    u8 pad_24[8];
    struct fn_15_3AC_slot *unk_2C;
    u32 unk_30;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 pad_37;
    u16 unk_38;
    u16 unk_3A;
    u16 unk_3C;
};

/* One 8-byte table entry; the whole table is 0x198 bytes wide. */
struct fn_15_3AC_slot {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 pad_7;
};

extern struct fn_15_3AC_lbl_15_bss_0 lbl_15_bss_0;
extern struct fn_15_3AC_slot lbl_1_bss_525C[51];
extern s16 lbl_1_bss_964;
extern u32 lbl_801A63C0;
struct fn_15_3AC_lbl_1_bss_96A {
    u16 unk_0;
};

extern struct fn_15_3AC_lbl_1_bss_96A lbl_1_bss_96A;
extern void fn_1_469BC(void);
extern u32 fn_1_4706C(void);
extern s32 fn_1_12C7B8(s32);
extern u64 __shl2i(u32, u32, u32);
extern u32 fn_1_3FC9C(void);
extern void *memset(void *, int, u32);

void fn_15_3AC(void) {
    struct fn_15_3AC_lbl_15_bss_0 *p;
    u32 r;
    struct fn_15_3AC_slot *slot;
    s32 i;
    u64 mask;
    struct fn_15_3AC_slot *car;
    s16 idx;

    p = &lbl_15_bss_0;
    car = &lbl_1_bss_525C[0];
    p->unk_2C = car;
    slot = car;
    mask = 0;
    p->unk_30 = 0;
    p->unk_20 = 1;
    p->unk_23 = 0;
    p->unk_4 = 0;
    p->unk_34 = 0;
    p->unk_35 = 0;
    p->unk_36 = 0;
    p->unk_38 = 3;
    fn_1_469BC();
    fn_1_4706C();
    if (lbl_1_bss_964 == 10) {
        memset(p->unk_2C, 0, 0x198);
        p->unk_3A = 3;
        p->unk_14 |= 0x20000000;
        ((u8 *)p->unk_2C)[0x192] = 3;
        p->unk_3C = 0;
        p->unk_34 = 1;
        p->unk_35 = 1;
        p->unk_36 = 1;
        for (i = 0; (s16)i < 4; i++, slot++) {
            slot->unk_4 = i;
            slot->unk_5 = i;
            slot->unk_6 = 0x10;
            idx = fn_1_12C7B8(slot->unk_5);
            mask |= (u64)1 << idx;
        }
        for (; (s16)i < 30; i++, slot++) {
            r = lbl_801A63C0;
            do {
                r = r * 0x676A4B6B + 0x33CB;
                idx = (s16)((s32)((r >> 16) & 0x7FFF) % 41);
            } while ((mask & ((u64)1 << idx)) != 0);
            lbl_801A63C0 = r;
            mask |= (u64)1 << idx;
            slot->unk_4 = idx;
            slot->unk_5 = idx;
            slot->unk_6 = 0x10;
        }
    } else {
        p->unk_14 &= 0x1FF;
        p->unk_14 |= 1;
        p->unk_3C = (u8)fn_1_3FC9C();
        if (((u8 *)p->unk_2C)[0x191] & 0x2) {
            p->unk_14 |= 0x80;
            p->unk_38 = ((u8 *)p->unk_2C)[0x192];
        } else {
            switch (((u8 *)car)[0xF8]) {
            case 0:
                p->unk_14 |= 0x8;
                break;
            case 1:
                p->unk_14 |= 0x10;
                break;
            case 2:
                p->unk_14 |= 0x20;
                break;
            default:
                p->unk_14 |= 0x40;
                break;
            }
        }
        p->unk_3A = (p->unk_14 & 0x40) ? 1 : 3;
        lbl_1_bss_96A.unk_0 = 0xB8;
    }
}
