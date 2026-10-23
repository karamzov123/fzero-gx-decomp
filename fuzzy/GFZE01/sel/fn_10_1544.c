/* Non-matching: best partial attempt (99.15% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_0[0xA];
    s8 unk_a;
    u8 pad_b[1];
} SelRow;

typedef struct {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_a[0xA];
} SelInput;

typedef struct {
    s16 state;
    u8 pad_2[0x90];
    u16 unk_92;
    u32 unk_94;
    u32 unk_98;
    u8 pad_9c[0x129 - 0x9C];
    u8 unk_129;
    u8 pad_12a[0x140 - 0x12A];
    u32 unk_140;
} SelMenu;

extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern SelMenu lbl_1_bss_8B3A0;
extern SelRow lbl_1_bss_9C8[4];
extern SelInput lbl_1_bss_9F8[4];
extern s32 lbl_10_bss_14;
extern s16 lbl_10_bss_4938C;
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_51744;

extern u32 fn_10_C258(SelMenu *, s16);
extern void fn_10_C274(SelMenu *, s16);
extern void fn_10_C298(SelMenu *, s16);
extern s32 fn_1_4C10(void);
extern void fn_10_9788(SelMenu *);
extern void fn_10_A634(SelMenu *);
extern void fn_10_A25C(SelMenu *);
extern void fn_10_A480(SelMenu *);
extern s16 fn_10_A0E8(SelMenu *);
extern s16 fn_10_91E8(void);
extern void fn_1_12F150(s16, s32, s32);
extern void fn_1_12F17C(void);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_A2D84(u32);
extern void fn_10_CFAC(s32, s32, s32, s32);

#define SCAN_PLAYERS(sound)                                                         \
    for (i = 0; i < 4; i++) {                                                       \
        if (lbl_1_bss_9C8[i].unk_a == -1) {                                         \
            continue;                                                               \
        }                                                                           \
        if (__rlwnm(lbl_1_bss_8B3A0.unk_98, (i + 1) & 31, 31, 31) == 0) {           \
            continue;                                                               \
        }                                                                           \
        if ((lbl_1_bss_9F8[i].unk_8 >> 9) & 1) {                                     \
            delta--;                                                                \
        }                                                                           \
        if ((lbl_1_bss_9F8[i].unk_8 >> 8) & 1) {                                     \
            delta++;                                                                \
        }                                                                           \
        if ((lbl_1_bss_9F8[i].unk_8 >> 8) & 1) {                                     \
            fn_1_12F150(i, sound, 1);                                               \
        } else if ((lbl_1_bss_9F8[i].unk_8 >> 9) & 1) {                              \
            fn_1_12F150(i, sound, 0);                                               \
        }                                                                           \
    }

#pragma opt_common_subs off
static inline void confirm(void) {
    lbl_10_bss_14 = 0xF;
    fn_1_12F17C();
    fn_1_4A00(0, lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    fn_1_A2D84(0xA9010100);
}
#pragma opt_common_subs reset


#define MAY_CANCEL() (!(menu->unk_94 & 0x40000000) || (menu->unk_94 & 0x4000))
#define MAY_CANCEL_G() (!(lbl_1_bss_8B3A0.unk_94 & 0x40000000) || (lbl_1_bss_8B3A0.unk_94 & 0x4000))

static inline s32 is_busy(void) {
    u32 flags = lbl_1_bss_8B3A0.unk_140;
    if ((flags & 0x80000000) && !(flags & 0x40000000) && !(lbl_1_bss_8B3A0.unk_94 & 8)) {
        return 1;
    }
    if (fn_1_4C10() != 0) {
        return 1;
    }
    return 0;
}

#pragma opt_common_subs off
void fn_10_1544(void) {
    s16 fzgx_value;
    s16 delta;
    s16 i;
    SelMenu *menu;
    s32 row;
    s32 v;
    s32 tmp_ra1;
    s32 tmp_ra3;
    SelMenu * lab_t0;

    row = fn_10_C258(&lbl_1_bss_8B3A0, lbl_1_bss_962);
    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    if (is_busy()) {
        return;
    }
    if (lbl_10_bss_14 != -1) {
        v = lbl_10_bss_14;
        lbl_10_bss_14 = -1;
        lbl_1_bss_96A = v;
        return;
    }
    menu = &lbl_1_bss_8B3A0;
    tmp_ra1 = menu->state;
    if (tmp_ra1 == -1) {
        fn_10_9788(menu);
        return;
    }
    delta = 0;
    switch (menu->state) {
    case 0:
        if (menu->unk_94 & 0x200) {
            switch ((s16)row) {
            case 0:
                fn_10_A634(menu);
                SCAN_PLAYERS(2);
                if (delta > 0) {
                    lab_t0 = &lbl_1_bss_8B3A0;
                    fn_10_C274(lab_t0, lbl_1_bss_962);
                    fn_1_A2D84(0xA9010100);
                }
                if (delta < 0 && MAY_CANCEL()) {
                    lbl_1_bss_8B3A0.state = -1;
                    fn_1_A2D84(0xA9010200);
                }
                break;
            case 1:
                fn_10_A25C(menu);
                SCAN_PLAYERS(3);
                if (delta > 0) {
                    lab_t0 = &lbl_1_bss_8B3A0;
                    fn_10_C274(lab_t0, lbl_1_bss_962);
                    fn_1_A2D84(0xA9010100);
                }
                if (delta < 0 && MAY_CANCEL()) {
                    fn_10_C298(&lbl_1_bss_8B3A0, lbl_1_bss_962);
                    fn_1_A2D84(0xA9010200);
                }
                break;
            case 2:
                fn_10_A480(menu);
                SCAN_PLAYERS(4);
                if (delta > 0) {
                    confirm();
                    lbl_1_bss_8B3A0.unk_129 = 0;
                }
                if (delta < 0 && MAY_CANCEL()) {
                    fn_10_C298(&lbl_1_bss_8B3A0, lbl_1_bss_962);
                    fn_1_A2D84(0xA9010200);
                }
                break;
            }
        } else {
            switch ((s16)row) {
            case 0:
                fn_10_A25C(menu);
                SCAN_PLAYERS(3);
                if (delta > 0) {
                    confirm();
                    lbl_1_bss_8B3A0.unk_129 = 0;
                }
                if (delta < 0 || fn_10_91E8() < 2) {
                    if (MAY_CANCEL()) {
                        lbl_1_bss_8B3A0.state = -1;
                        fn_1_A2D84(0xA9010200);
                        fn_10_CFAC(1, 0, 0x1E, 9);
                    }
                }
                break;
            }
        }
        break;
    case 1:
    case 11:
        switch ((s16)row) {
        case 0:
            fn_10_A634(&lbl_1_bss_8B3A0);
            SCAN_PLAYERS(2);
            if (delta > 0) {
                confirm();
                lbl_1_bss_8B3A0.unk_129 = 0;
                if (lbl_1_bss_8B3A0.state == 1) {
                    lbl_1_bss_8B3A0.unk_94 |= 0x400000;
                }
            }
            if (delta < 0 && MAY_CANCEL_G()) {
                lbl_1_bss_8B3A0.state = -1;
                fn_1_A2D84(0xA9010200);
                fn_10_CFAC(1, 0, 0x1E, 5);
            }
            break;
        }
        break;
    case 2:
        switch ((s16)row) {
        case 0:
            lbl_1_bss_8B3A0.unk_92 = fn_10_A0E8(menu);
            SCAN_PLAYERS(3);
            if (delta > 0) {
                tmp_ra3 = lbl_1_bss_8B3A0.unk_92;
                if (tmp_ra3 == 1) {
                    lbl_1_bss_8B3A0.unk_94 |= 4;
                }
                confirm();
                lbl_1_bss_8B3A0.unk_129 = 0;
            }
            if (delta < 0 && MAY_CANCEL_G()) {
                fzgx_value = -1;
                lbl_1_bss_8B3A0.state = fzgx_value;
                fn_1_A2D84(0xA9010200);
                fn_10_CFAC(1, 0, 0x1E, 0x11);
            }
            break;
        }
        break;
    }
}
