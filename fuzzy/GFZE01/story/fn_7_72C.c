/* Non-matching: best partial attempt (68.53% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_7_72C_lbl_1_bss_9C {
    u8 pad_0[0x3];
    u8 unk_3;
};

struct fn_7_72C_state {
    u8 pad_0[4];
    s32 mode;
    u8 pad_8[8];
    struct fn_7_72C_character *character;
    u8 pad_14[4];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[8];
    s32 value;
    s32 delta;
    s32 event;
    s32 timer0;
    s32 timer1;
};

struct fn_7_72C_character {
    s8 index;
    s8 selection;
    s8 type;
};

extern struct fn_7_72C_lbl_1_bss_9C lbl_1_bss_9C;
extern struct fn_7_72C_state lbl_7_bss_0;
extern s32 lbl_7_data_12E78;
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern u16 lbl_1_bss_7F0C0[];
extern u16 lbl_1_bss_9F8[];
extern u32 lbl_1_bss_6EAB4;
extern u32 lbl_1_bss_8B3A0[];
extern s32 fn_1_C24A4(void);
extern u32 fn_7_2538(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_C2454(void);
extern int fn_1_4C10(void);
extern void fn_1_A2D84(u32);
extern u32 fn_1_F9CA0(u32, u32);
extern u32 fn_1_F9E80(u32, u32);
extern void fn_1_4A00(s32, u8, void *);

void fn_7_72C(void) {
    struct fn_7_72C_state *p;
    struct fn_7_72C_lbl_1_bss_9C *status;
    struct fn_7_72C_character *character;
    s32 direction;
    s32 index;
    u16 flags;
    u16 other;
    u32 v;
    u32 type;
    u32 i;

    p = &lbl_7_bss_0;
    fn_7_2538();
    status = &lbl_1_bss_9C;
    if ((s32)status->unk_3 == 1) {
        fn_1_C2454();
        status->unk_3 = 2;
    }
    if (status->unk_3 == 2) {
        if (fn_1_C24A4() == 0 && fn_1_B7C00() == 0) {
            status->unk_3 = 0;
        } else {
            return;
        }
    }
    if (p->timer0 > 0)
        p->timer0--;
    if (p->timer1 > 0)
        p->timer1--;
    if (p->delta != 0) {
        p->value += p->delta;
        if (p->value > 200) {
            p->value = 200;
            p->delta = 0;
        } else if (p->value < 0) {
            p->value = 0;
            p->delta = lbl_7_data_12E78 == (u32)-1 ? 0 : -p->delta;
            if (lbl_7_data_12E78 == (u32)-1)
                p->delta = 0;
        }
    }
    if (lbl_7_data_12E78 != (u32)-1) {
        p->event = lbl_7_data_12E78;
        lbl_7_data_12E78 = (u32)-1;
    }
    if (fn_1_4C10() != 0)
        return;
    if (p->mode == 1) {
        if (p->event == 4)
            lbl_1_bss_968 = 1;
        else if (p->event >= 3 && p->event < 4)
            lbl_1_bss_96A = 136;
        return;
    }
    if (p->mode != 0)
        return;
    if (p->event == 2) {
        type = (u8)p->character->type;
        flags = lbl_1_bss_9F8[8 + type * 10];
        other = lbl_1_bss_9F8[9 + type * 10];
        if ((flags & 2) || (other & 2)) {
            p->timer1 = 15;
            p->timer0 = 0;
            direction = 1;
        } else if ((flags & 1) || (other & 1)) {
            p->timer0 = 15;
            p->timer1 = 0;
            direction = -1;
        } else {
            direction = 0;
        }
        index = (s8)character->index + direction;
        if (index < 0 || index > 9) {
            direction = 0;
            p->timer0 = 0;
            p->timer1 = 0;
        }
        index = (s8)character->index + direction;
        if ((lbl_1_bss_7F0C0[50] & (0x8000 >> index)) == 0) {
            direction = 0;
            p->timer0 = 0;
            p->timer1 = 0;
        }
        if (direction != 0)
            fn_1_A2D84(0xA901);
        character->index += direction;
        flags = lbl_1_bss_9F8[4 + (u8)character->type * 10];
        if ((flags & 0x100) && fn_1_F9CA0(0, (u8)character->index)) {
            if ((s8)character->index > 0 && fn_1_F9CA0(1, (u8)character->index)) {
                p->delta = -10;
                lbl_7_data_12E78 = 2;
                character->selection = 0;
                for (;;) {
                    if ((s8)character->selection >= 2 ||
                        !fn_1_F9E80((u8)character->selection, (u8)character->index))
                        break;
                    character->selection++;
                }
                fn_1_A2D84(0xA9010100);
                return;
            } else {
                character->selection = 0;
                p->event = 3;
                p->timer1 = 32;
                p->delta = -10;
                fn_1_4A00(0, 30, (void *)p->unk_1C);
                fn_1_A2D84(0xA9010100);
                lbl_1_bss_6EAB4 |= 0x24;
                return;
            }
        }
        flags = lbl_1_bss_9F8[4 + (u8)character->type * 10];
        if (flags & 0x200) {
            lbl_1_bss_8B3A0[0x94 / 4] = 0;
            fn_1_4A00(0, 30, (void *)p->unk_1C);
            lbl_7_data_12E78 = 4;
            fn_1_A2D84(0xA9010200);
            lbl_1_bss_6EAB4 |= 0x24;
            return;
        }
        return;
    }
    character = p->character;
    type = (u8)character->type;
    flags = lbl_1_bss_9F8[8 + type * 10];
    other = lbl_1_bss_9F8[9 + type * 10];
    if ((flags & 2) || (other & 2)) {
        if ((s8)character->selection < 2 &&
            fn_1_F9CA0((u8)character->index, (u8)(character->selection + 1))) {
            character->selection++;
            p->unk_18 = 0;
            fn_1_A2D84(0xA901);
        }
    } else {
        flags = lbl_1_bss_9F8[8 + type * 10];
        other = lbl_1_bss_9F8[9 + type * 10];
        if (((flags & 1) || (other & 1)) &&
            (s8)character->selection > 0 &&
            fn_1_F9CA0((u8)character->index, (u8)(character->selection - 1))) {
            character->selection--;
            p->unk_18 = 0;
            fn_1_A2D84(0xA901);
        }
    }
    flags = lbl_1_bss_9F8[4 + type * 10];
    if (flags & 0x100) {
        p->event = 3;
        p->timer1 = 32;
        p->delta = -10;
        fn_1_4A00(0, 30, (void *)p->unk_1C);
        fn_1_A2D84(0xA9010100);
        p->unk_18 = 0;
        lbl_1_bss_6EAB4 |= 0x24;
        return;
    }
    if (flags & 0x200) {
        p->delta = -10;
        lbl_7_data_12E78 = 1;
        fn_1_A2D84(0xA9010200);
    }
}
