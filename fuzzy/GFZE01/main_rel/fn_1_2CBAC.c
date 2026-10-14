/* Non-matching: best partial attempt (77.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/stcoli.h"

extern u32 fn_1_3FC9C(void);
extern void fn_1_3F2A0(void);
extern void fn_1_FA154(u32, u32);
extern int fn_1_4017C(void);
extern void fn_1_FA038(void);
extern int fn_1_40224(void);
extern void fn_1_F9FB4(void);
extern void fn_1_FA67C(s32);
extern u32 fn_1_F8A38(u32);
extern u8 lbl_1_rodata_DCDC[80];
extern u16 lbl_1_rodata_DD2C[4];
extern int fn_1_F8334(s16);
extern s32 fn_1_F7EDC(s16);
extern int fn_1_FA180(u32, u32);
extern u8 lbl_1_rodata_DD34[36];
extern u8 lbl_1_rodata_DBE4[240];
extern s16 fn_1_12EF24(s16, s16);

void fn_1_2CBAC(void) {
    s32 condition;
    u32 player;
    s32 index;
    s32 state;
    s32 found;
    s32 i;
    s32 j;
    s32 choice;
    s32 table;
    s32 value;
    u8 race;
    s32 kind;
    s32 id;
    s32 *unused;

    condition = 0;
    if (lbl_1_bss_3C30.unk_5 == 1 && lbl_1_bss_3C30.unk_A7 >= 4) {
        condition = 1;
    }
    if (condition == 0) {
        return;
    }
    found = 0;
    player = fn_1_3FC9C() & 0xff;
    index = lbl_1_bss_3C30.unk_A6 - 1;
    fn_1_3F2A0();
    kind = lbl_1_bss_3C30.unk_DC;
    if (kind == 0) {
        race = lbl_1_bss_3C30.unk_156;
        fn_1_FA154(player, index);
        if (fn_1_4017C() != 0) {
            fn_1_FA038();
        }
        if (player == 2 && fn_1_40224() != 0) {
            fn_1_F9FB4();
        }
        if (player == 3) {
            fn_1_FA67C(race);
        }
        if (index + 1 == 5 && fn_1_F8A38(0) == 0) {
            value = lbl_1_bss_5138.unk_E4;
            lbl_1_bss_5138.unk_E4 = value + 1;
            *((u8 *)&lbl_1_bss_5138 + 0xE6 + value) = 0;
        }
        state = 2;
    } else {
        state = 1;
    }

    table = (s32)(lbl_1_rodata_DCDC + player * 20 + index * 4 + state * 2);
    for (i = state; i > 0; i--) {
        id = *(u16 *)(table - 2);
        if ((u16)id == 0xfffe) {
            found = 0;
            for (j = 0; j < 3; j++) {
                value = (s16)lbl_1_rodata_DD2C[j];
                if (fn_1_F8334(value) == 0) {
                    found = 1;
                    value = lbl_1_bss_5138.unk_2;
                    lbl_1_bss_5138.unk_2 = value + 1;
                    *(u16 *)((u8 *)&lbl_1_bss_5138 + 8 + value * 2) = (u16)(s16)lbl_1_rodata_DD2C[j];
                }
            }
            if (found != 0) {
                break;
            }
        } else if ((u16)id != 0xffff && fn_1_F7EDC((s16)id) == 0) {
            found = 1;
            value = lbl_1_bss_5138.unk_3;
            lbl_1_bss_5138.unk_3 = value + 1;
            *((u8 *)&lbl_1_bss_5138 + 4 + value) = (u8)id;
            break;
        }
        table -= 2;
    }

    if (found == 0) {
        if (kind == 0) {
            choice = 1;
            if (player == 0) {
                choice = 2;
            } else if (player == 1) {
                choice = 4;
            } else {
                for (i = 0; i < 3; i++) {
                    if (index != i &&
                        fn_1_FA180(2, i) == 0 &&
                        fn_1_FA180(3, i) != 0) {
                        break;
                    }
                }
                choice = i == 3 ? 5 : 4;
            }
        } else {
            choice = 1;
            if (player > 0) {
                choice = 2;
            }
        }
        table = choice;
        for (i = 0; i < table; i++) {
            if (choice == 2 && kind == 0 && table == choice) {
                id = (s32)(lbl_1_rodata_DD34 + 12);
            } else {
                id = (s32)(lbl_1_rodata_DD34 + (table - 1) * 6);
            }
            for (j = 0; j < 3; j++) {
                value = *(u16 *)(id + j * 2);
                if (fn_1_F8334((s16)value) == 0) {
                    value = lbl_1_bss_5138.unk_2;
                    lbl_1_bss_5138.unk_2 = value + 1;
                    *(u16 *)((u8 *)&lbl_1_bss_5138 + 8 + value * 2) = (u16)value;
                    found = 1;
                    if (table == 5) break;
                }
            }
            if (found == 0) table--;
        }
    }

    if (kind == 0) {
        choice = 0;
    } else if (kind == 1) {
        choice = 1;
    } else if (kind == 2) {
        choice = 2;
    } else if (kind < 9) {
        choice = 3;
    } else if (kind < 19) {
        choice = 4;
    } else {
        choice = 5;
    }
    lbl_1_bss_5138.unk_0 = *(u16 *)(lbl_1_rodata_DBE4 + player * 60 + index * 12 + choice * 2);
    if (player == 3) {
        for (i = 0; i < 4; i++) {
            if (fn_1_FA180(3, i) == 0) found = 0;
        }
        if (found != 0) {
            for (i = 1; i < 6; i++) {
                fn_1_12EF24(6, i);
                if (fn_1_F8A38(i) == 0) {
                    value = lbl_1_bss_5138.unk_E4;
                    *((u8 *)&lbl_1_bss_5138 + 0xE6 + value) = i;
                    lbl_1_bss_5138.unk_E4 = value + 1;
                }
            }
            lbl_1_bss_5138.unk_EB = 1;
        }
    }
}
