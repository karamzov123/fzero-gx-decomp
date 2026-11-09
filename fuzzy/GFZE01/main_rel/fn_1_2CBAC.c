/* Non-matching: best partial attempt (97.29% in the project ledger). Scored for the
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
extern s32 fn_1_F8A38(u32);
extern u8 lbl_1_rodata_DCDC[80];
extern u16 lbl_1_rodata_DD2C[4];
extern int fn_1_F8334(s16);
extern s32 fn_1_F7EDC(s16);
extern int fn_1_FA180(u32, u32);
extern u8 lbl_1_rodata_DD34[36];
extern u8 lbl_1_rodata_DBE4[240];
extern s16 fn_1_12EF24(s16, s16);

/* the unlock record: two pending-unlock lists (bytes at +0x4, halfwords at +0x8)
 * and the unlocked-cup list at +0xE6; the generated header types only their first elements */
typedef struct {
    u16 unk_0;
    u8 count_u16;       /* 0x02 */
    s8 count_u8;        /* 0x03 */
    u8 list_u8[4];      /* 0x04 */
    u16 list_u16[0x6C]; /* 0x08 */
    u8 pad_E0[4];
    u8 cup_count;       /* 0xE4 */
    u8 pad_E5;
    u8 cups[5];         /* 0xE6 */
    u8 unk_EB;          /* 0xEB */
    u8 pad_EC[0x18];
} UnlockView;

#define UNLOCK (*(UnlockView *)&lbl_1_bss_5138)

#pragma opt_loop_invariants off
static inline s32 fn_1_2CBAC_fallback(s16 kind, s16 player, s16 index) {
    s32 count;
    s32 n;
    u16 *list;
    s32 i;
    u16 id;
    player = player;

    count = 1;
    if (kind == 0) {
        if (player == 0) {
            count = 2;
        } else if (player == 1) {
            count = 4;
        } else {
            for (i = 0; i < 3; i++) {
                s32 a = fn_1_FA180(2, (u8)i);
                s32 b = fn_1_FA180(3, (i & 0xFF));
                if (index != i && a == 0 && b == 0) {
                    break;
                }
            }
            if (i == 3) {
                count = 5;
            } else {
                count = 4;
            }
        }
    } else if (player > 0) {
        count = 2;
    }
{
    s32 found;
    found = 0;
    for (n = count; n > 0; n--) {
        s32 j;

        if (count == 2 && kind == 0 && n == count) {
            list = (u16 *)(lbl_1_rodata_DD34 + 12);
        } else {
            list = (u16 *)(lbl_1_rodata_DD34 + (n - 1) * 6);
        }
        for (j = 0; j < 3; j++, list++) {
            i = *list;
            id = i;
            if (fn_1_F8334((s16)id) == 0) {
                found = 1;
                UNLOCK.list_u16[UNLOCK.count_u16++] = id;
                if (n != 5) {
                    break;
                }
            }
        }
        if (found != 0) {
            break;
        }
    }
    return found;
}
}
#pragma opt_loop_invariants reset


static inline s32 fn_1_2CBAC_active(Obj_1_bss_3C30 *game) {
    if (game->unk_5 != 1) {
        return 0;
    }
    if (game->unk_A7 < 4) {
        return 0;
    }
    return 1;
}

static inline u16 fn_1_2CBAC_array_read(s32 index, u16 *array) { return array[index]; }
#pragma opt_lifetimes on
static inline s32 fn_1_2CBAC_loop1(void) {
    u16 *list;
    s32 j;
    s32 found;
    s16 value;
            found = 0;
            list = (u16 *)lbl_1_rodata_DD2C;
            for (j = 0; j < 3; j++, list++) {
                value = *list;
                if (fn_1_F8334(value) == 0) {
                    found = 1;
                    UNLOCK.list_u16[UNLOCK.count_u16++] = value;
                }
            }
    return found;
}

static inline void fn_1_2CBAC_loop2(void) {
    s32 tmp_call1;
    u32 i;
            for (i = 1; i < 6; i++) {
                tmp_call1 = fn_1_12EF24(6, i);
                tmp_call1;
                if (fn_1_F8A38((u8)i) == 0) {
                    UNLOCK.cups[UNLOCK.cup_count] = i;
                    UNLOCK.cup_count++;
                }
            }
}

void fn_1_2CBAC(void) {
    s32 active;
    s32 i;
    Obj_1_bss_3C30 *game;
    s32 kind;
    u8 player;
    s32 index;
    u16 race;
    s32 state;
    s32 choice;
    s32 all;
    u16 *entry;
    s32 found;
    s32 id;

    game = &lbl_1_bss_3C30;
    active = fn_1_2CBAC_active(game);
    if (active == 0) {
        return;
    }
    found = 0;
    player = fn_1_3FC9C();
    index = lbl_1_bss_3C30.unk_A6 - 1;
    fn_1_3F2A0();
    kind = game->unk_DC;
    if (kind == 0) {
        race = game->unk_156;
        fn_1_FA154(player, (index & 0xFF));
        if (fn_1_4017C() != 0) {
            fn_1_FA038();
        }
        if (player == 2 && fn_1_40224() != 0) {
            fn_1_F9FB4();
        }
        if (player == 3) {
            fn_1_FA67C(race);
        }
        if ((u8)index + 1 == 5 && fn_1_F8A38(0) == 0) {
            UNLOCK.cups[UNLOCK.cup_count++] = 0;
        }
        state = 2;
    } else {
        state = 1;
    }

    entry = (u16 *)(((((lbl_1_rodata_DCDC + player * 20)) + (((index * 4)) + ((state * 2))))));
    for (i = state; i > 0; entry--, i--) {
        id = entry[-1];
        if (id == 0xFFFE) {
            found = fn_1_2CBAC_loop1();
            if (((0) != (found))) {
                break;
            }
        } else if (id != 0xFFFF && fn_1_F7EDC((s16)id) == 0) {
            UNLOCK.list_u8[UNLOCK.count_u8++] = id;
            break;
            found = 1;
        }
    }

    if (found == 0) {
        active = fn_1_2CBAC_fallback(kind, player, index);
        found = active;
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
    UNLOCK.unk_0 = ((u16 *)(lbl_1_rodata_DBE4 + player * 60 + index * 12))[choice];
    if ((s32)player == 3) {
        all = 1;
        for (i = 0; i < 4; i++) {
            if (fn_1_FA180(3, (u8)i) == 0) {
                all = 0;
            }
        }
        if (all != 0) {
            fn_1_2CBAC_loop2();
            UNLOCK.unk_EB = 1;
        }
    }
}
#pragma opt_lifetimes reset

