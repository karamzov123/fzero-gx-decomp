#include "types.h"

/* replay data loaded from or saved to the memory card, 0x4C bytes */
typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 pad_5[0x3];
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    s8 unk_14;
    u8 pad_15[0x37];
} RepMemcardReplay;

typedef struct {
    u8 unk_0;
    u8 unk_1;
} RepMemcardChar;

/* message text state, 0x130 bytes */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    RepMemcardChar *unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24;
    f32 unk_28;
    f32 unk_2C;
    u32 unk_30;
    u8 unk_34;
    u8 unk_35;
    u8 pad_36[0xFA];
} RepMemcardText;

typedef struct {
    u8 pad_0[0x134];
    RepMemcardChar *unk_134;
} RepMemcardSource;

extern void *lbl_801A6410;
extern s16 lbl_1_bss_960;

extern void *memset(void *dest, int value, u32 size);
extern s32 atoi(u8 *text);
extern void fn_80008BA8(void *dest, void *src, u32 size);
extern f64 fn_80083E84(u8 *text);
extern s32 fn_1_3F8C(void *name, void (*func)(void), s32 arg2, s32 arg3);
extern void fn_1_426C(s32 id);
extern void fn_1_435C(u32 arg0);
extern void *fn_1_4630(void *heap, u32 size, char *file, s32 line);
extern void fn_1_46B4(void *heap, void *ptr, char *file, s32 line);
extern void fn_1_48418(s32 arg0);
extern void fn_1_484CC(s32 arg0);
extern void fn_1_4955C(f32 x, f32 y);
extern void fn_1_495FC(void);
extern void fn_1_49614(void);
extern void fn_1_4966C(f32 x, f32 y);
extern void fn_1_496FC(f32 x, f32 y);
extern void fn_1_4AF64(void *text, ...);
extern f32 fn_1_4B090(void *text);
extern s32 fn_1_4B16C(void *text);
extern void fn_1_A8EB0(s32 x, s32 y);
extern u8 fn_1_B7C00(void);
extern void fn_1_B9BE0(void);
extern void fn_1_B9C0C(void);
extern void fn_1_B9DE8(RepMemcardReplay *replay);
extern s32 fn_1_BA144(RepMemcardReplay *replay);
extern void fn_1_BC29C(RepMemcardReplay *replay);
extern void fn_1_BC310(RepMemcardReplay *replay);
extern void fn_1_C0510(void *arg0, u32 arg1, u32 arg2);
extern void fn_1_C1394(RepMemcardReplay *replay);
extern s32 fn_1_FA638(void);
extern void fn_1_159440(s32 arg0, s32 arg1);
extern void fn_1_1596DC(s32 arg0);

void fn_1_154798(void);
void fn_1_1548A8(void);
void fn_1_154930(void);
void fn_1_1549B8(void);
void fn_1_154A08(void);
void fn_1_154BE4(void);
void fn_1_154F1C(void);
void fn_1_154FA8(void);
void fn_1_155120(void);
u8 *fn_1_15530C(u8 *text);

/* state handlers and their names */
void (*lbl_1_data_49A18[5])(void) = {fn_1_1548A8, fn_1_154930, fn_1_1549B8, fn_1_154A08, fn_1_154BE4};
char *lbl_1_data_49A94[5] = {"REP_MEMCARD_INIT", "REP_MEMCARD_WAIT", "REP_MEMCARD_ACTION_INIT", "REP_MEMCARD_ACTION",
                             "REP_MEMCARD_FINISH"};
s32 lbl_1_data_49AA8 = -1;  /* event id */
s32 lbl_1_data_49AAC = -1;  /* previous state */
s32 lbl_1_data_49AB0 = -1;  /* current state */
s32 lbl_1_data_49AB4 = -1;  /* next state */

void *lbl_1_bss_8ED90 = 0;  /* saved replay data */
u32 lbl_1_bss_8ED94 = 0;    /* its size */
void *lbl_1_bss_8ED98 = 0;
u32 lbl_1_bss_8ED9C = 0;
u8 lbl_1_bss_8EDA0 = 0;
RepMemcardReplay lbl_1_bss_8EDA4;
RepMemcardText lbl_1_bss_8EDF0;

/* fzgx:begin fn_1_154708 */
void fn_1_154708(u32 arg0) {
    lbl_1_bss_8ED9C = arg0;
    lbl_1_data_49AA8 = -1;
    fn_1_435C(arg0);
    lbl_1_data_49AA8 = fn_1_3F8C("RepMemcardEvent", fn_1_154798, 0, 18);
    lbl_1_data_49AAC = -1;
    lbl_1_data_49AB0 = -1;
    lbl_1_data_49AB4 = -1;
    lbl_1_bss_8EDA0 = 0;
    lbl_1_bss_8ED98 = 0;
    lbl_1_bss_8ED90 = 0;
    lbl_1_bss_8ED94 = 0;
    fn_1_B9BE0();
}
/* fzgx:end fn_1_154708 */

/* fzgx:begin fn_1_154798 */
void fn_1_154798(void) {
    if (lbl_1_data_49AB4 >= 0) {
        lbl_1_data_49AAC = lbl_1_data_49AB0;
        lbl_1_data_49AB0 = lbl_1_data_49AB4;
        lbl_1_data_49AB4 = -1;
    }
    if (lbl_1_data_49AB0 >= 0) {
        lbl_1_data_49A18[lbl_1_data_49AB0]();
    }
}
/* fzgx:end fn_1_154798 */

/* fzgx:begin fn_1_1547FC */
void fn_1_1547FC(void) {
    fn_1_B9C0C();
    if (lbl_1_bss_8ED90 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, "rep_memcard.c", 0x73);
        lbl_1_bss_8ED90 = 0;
        lbl_1_bss_8ED94 = 0;
    }
    lbl_1_data_49AAC = -1;
    lbl_1_data_49AB0 = -1;
    lbl_1_data_49AB4 = -1;
    if (lbl_1_data_49AA8 != -1) {
        fn_1_435C(lbl_1_bss_8ED9C);
        fn_1_426C(lbl_1_data_49AA8);
        lbl_1_bss_8ED9C = 0;
        lbl_1_data_49AA8 = -1;
    }
}
/* fzgx:end fn_1_1547FC */

/* fzgx:begin fn_1_1548A8 */
// Initialize the tow settings and select the mode-dependent input value.
void fn_1_1548A8(void) {
    s16 mode;
    RepMemcardReplay *replay;

    fn_1_B9BE0();
    fn_1_B9DE8(&lbl_1_bss_8EDA4);
    replay = &lbl_1_bss_8EDA4;
    mode = lbl_1_bss_960;
    replay->unk_0 = 0x20;
    if (mode == 0xc) {
        replay->unk_4 = 0xa;
    } else {
        replay->unk_4 = 9;
    }
    if (mode != 2) {
        fn_1_48418(2);
        fn_1_159440(2, 0);
    }
    lbl_1_data_49AB4 = 1;
}
/* fzgx:end fn_1_1548A8 */

/* fzgx:begin fn_1_154930 */
void fn_1_154930(void) {
    s8 result;

    result = fn_1_BA144(&lbl_1_bss_8EDA4);
    if (result == 0) {
        lbl_1_data_49AB4 = 2;
    } else if (result == 1) {
        lbl_1_data_49AB4 = 4;
        lbl_1_bss_8EDA0 = 1;
        fn_1_1596DC(2);
        fn_1_484CC(2);
    } else {
        fn_1_BC310(&lbl_1_bss_8EDA4);
    }
}
/* fzgx:end fn_1_154930 */

/* fzgx:begin fn_1_1549B8 */
// Copy the tow state into the active settings and advance the tow mode.
void fn_1_1549B8(void) {
    lbl_1_bss_8EDA4.unk_8 = (u32)lbl_1_bss_8ED90;
    lbl_1_bss_8EDA4.unk_C = lbl_1_bss_8ED94;
    lbl_1_bss_8EDA4.unk_10 = 5;
    fn_1_C0510(&lbl_1_bss_8EDA4, lbl_1_bss_8ED94, (u32)lbl_1_bss_8ED90);
    lbl_1_data_49AB4 = 3;
}
/* fzgx:end fn_1_1549B8 */

/* fzgx:begin fn_1_154A08 */
/* REP_MEMCARD_ACTION: wait for the memory-card task, then keep (or drop) the loaded replay. */
void fn_1_154A08(void) {
    void *buf;
    s8 state;

    if (fn_1_B7C00()) {
        return;
    }
    if (lbl_1_bss_8ED98 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED98, "rep_memcard.c", 0xcd);
    }
    state = lbl_1_bss_8EDA4.unk_14;
    if (state == 1) {
        fn_1_B9C0C();
        fn_1_BC29C(&lbl_1_bss_8EDA4);
        lbl_1_data_49AB4 = 4;
    } else if (state == 2) {
        if (lbl_1_bss_8ED90 != 0) {
            fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, "rep_memcard.c", 0xda);
        }
        if ((s32)lbl_1_bss_8EDA4.unk_C != 0) {
            buf = fn_1_4630(lbl_801A6410, lbl_1_bss_8EDA4.unk_C, "rep_memcard.c", 0xdf);
            fn_80008BA8(buf, (void *)lbl_1_bss_8EDA4.unk_8, lbl_1_bss_8EDA4.unk_C);
            fn_1_B9C0C();
            if (lbl_1_bss_8EDA4.unk_8 != 0) {
                fn_1_46B4(lbl_801A6410, (void *)lbl_1_bss_8EDA4.unk_8, "rep_memcard.c", 0xe9);
                lbl_1_bss_8EDA4.unk_8 = 0;
            }
            lbl_1_bss_8ED90 = fn_1_4630(lbl_801A6410, lbl_1_bss_8EDA4.unk_C, "rep_memcard.c", 0xee);
            lbl_1_bss_8ED94 = lbl_1_bss_8EDA4.unk_C;
            lbl_1_bss_8EDA4.unk_C = 0;
            fn_80008BA8(lbl_1_bss_8ED90, buf, lbl_1_bss_8ED94);
            fn_1_46B4(lbl_801A6410, buf, "rep_memcard.c", 0xf9);
        }
        lbl_1_data_49AB4 = 4;
        fn_1_BC29C(&lbl_1_bss_8EDA4);
    } else if (state == 8) {
        fn_1_C1394(&lbl_1_bss_8EDA4);
        lbl_1_data_49AB4 = 1;
    }
}
/* fzgx:end fn_1_154A08 */

/* fzgx:begin fn_1_154BE4 */
void fn_1_154BE4(void) {
    if (lbl_1_bss_8EDA4.unk_14 != 2 && lbl_1_bss_8ED90 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, "rep_memcard.c", 0x10D);
        lbl_1_bss_8ED90 = 0;
        lbl_1_bss_8ED94 = 0;
    }
    fn_1_B9C0C();
    fn_1_1596DC(2);
    fn_1_484CC(2);
    lbl_1_data_49AAC = -1;
    lbl_1_data_49AB0 = -1;
    lbl_1_data_49AB4 = -1;
}
/* fzgx:end fn_1_154BE4 */

/* fzgx:begin fn_1_154C84 */
s32 fn_1_154C84(void) {
    if (lbl_1_data_49AB0 == 4) {
        return 0;
    }
    if (lbl_1_data_49AB0 != -1 || lbl_1_data_49AB4 != -1) {
        return 1;
    }
    return 0;
}
/* fzgx:end fn_1_154C84 */

/* fzgx:begin fn_1_154CC4 */
void fn_1_154CC4(s32 state) {
    lbl_1_data_49AB4 = state;
}
/* fzgx:end fn_1_154CC4 */

/* fzgx:begin fn_1_154CD0 */
void fn_1_154CD0(void *data, u32 size) {
    if (lbl_1_bss_8ED90 != 0) {
        fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, "rep_memcard.c", 0x12f);
        lbl_1_bss_8ED90 = 0;
        lbl_1_bss_8ED94 = 0;
    }
    lbl_1_bss_8ED90 = fn_1_4630(lbl_801A6410, size, "rep_memcard.c", 0x133);
    fn_80008BA8(lbl_1_bss_8ED90, data, size);
    lbl_1_bss_8ED94 = size;
}
/* fzgx:end fn_1_154CD0 */

/* fzgx:begin fn_1_154D84 */
/* Saves the pending memory-card data and clears the pending state. */
u32 fn_1_154D84(void *dest) {
    if (lbl_1_bss_8ED90 == 0) {
        return 0;
    }
    if (dest == 0) {
        return 0;
    }
    fn_80008BA8(dest, lbl_1_bss_8ED90, lbl_1_bss_8ED94);
    fn_1_46B4(lbl_801A6410, lbl_1_bss_8ED90, "rep_memcard.c", 0x13f);
    lbl_1_bss_8ED90 = 0;
    lbl_1_bss_8ED94 = 0;
    return 1;
}
/* fzgx:end fn_1_154D84 */

/* fzgx:begin fn_1_154E24 */
u8 fn_1_154E24(void) {
    return lbl_1_bss_8EDA0;
}
/* fzgx:end fn_1_154E24 */

/* fzgx:begin fn_1_154E34 */
void *fn_1_154E34(u32 *size) {
    *size = lbl_1_bss_8ED94;
    return lbl_1_bss_8ED90;
}
/* fzgx:end fn_1_154E34 */

/* fzgx:begin fn_1_154E4C */
void fn_1_154E4C(void) {
    memset(&lbl_1_bss_8EDF0, 0, sizeof(lbl_1_bss_8EDF0));
    lbl_1_bss_8EDF0.unk_C = 0;
    lbl_1_bss_8EDF0.unk_28 = 1.0f;
    lbl_1_bss_8EDF0.unk_30 = 2;
    lbl_1_bss_8EDF0.unk_8 &= ~2;
    lbl_1_bss_8EDF0.unk_10 = 0;
    lbl_1_bss_8EDF0.unk_20 = 80;
    lbl_1_bss_8EDF0.unk_24 = 385;
    lbl_1_bss_8EDF0.unk_2C = 0.5f;
    fn_1_154FA8();
}
/* fzgx:end fn_1_154E4C */

/* fzgx:begin fn_1_154ED0 */
void fn_1_154ED0(RepMemcardSource *src) {
    fn_1_154F1C();
    lbl_1_bss_8EDF0.unk_C = (u32)src;
    lbl_1_bss_8EDF0.unk_10 = src->unk_134;
    lbl_1_bss_8EDF0.unk_0 = 0;
    lbl_1_bss_8EDF0.unk_4 = 0;
}
/* fzgx:end fn_1_154ED0 */

/* fzgx:begin fn_1_154F1C */
/* Reset the message state and clear its text buffer. */
// Reset the memory-card state and clear its backing buffer.
void fn_1_154F1C(void) {
    lbl_1_bss_8EDF0.unk_1C = 0;
    lbl_1_bss_8EDF0.unk_14 = 0;
    lbl_1_bss_8EDF0.unk_18 = 0;
    memset(&lbl_1_bss_8EDF0.unk_34, 0, 250);
    lbl_1_bss_8EDF0.unk_34 = 0;
}
/* fzgx:end fn_1_154F1C */

/* fzgx:begin fn_1_154F74 */
// Stores the two memory-card state values used by the replication subsystem.
void fn_1_154F74(u32 x, u32 y) {
    lbl_1_bss_8EDF0.unk_20 = x;
    lbl_1_bss_8EDF0.unk_24 = y;
}
/* fzgx:end fn_1_154F74 */

/* fzgx:begin fn_1_154F88 */
// Stores the current float value in the memory-card state.
void fn_1_154F88(f32 value) {
    lbl_1_bss_8EDF0.unk_2C = value;
}
/* fzgx:end fn_1_154F88 */

/* fzgx:begin fn_1_154F98 */
void fn_1_154F98(u32 value) {
    lbl_1_bss_8EDF0.unk_30 = value;
}
/* fzgx:end fn_1_154F98 */

/* fzgx:begin fn_1_154FA8 */
void fn_1_154FA8(void) {
    lbl_1_bss_8EDF0.unk_8 |= 4;
}
/* fzgx:end fn_1_154FA8 */

/* fzgx:begin fn_1_154FC0 */
void fn_1_154FC0(void) {
    lbl_1_bss_8EDF0.unk_8 &= ~4;
}
/* fzgx:end fn_1_154FC0 */

/* fzgx:begin fn_1_154FD8 */
void fn_1_154FD8(void) {
    RepMemcardText *obj;
    f32 value;
    f32 ratio;

    obj = &lbl_1_bss_8EDF0;
    if ((obj->unk_8 & 1) == 0) {
        obj->unk_0++;
        if ((s32)obj->unk_4 != 0) {
            obj->unk_4--;
        }
    }
    if ((s32)obj->unk_4 <= 0) {
        if (((s32)obj->unk_0 % (s32)obj->unk_30) == 0) {
            fn_1_155120();
        }
    }
    fn_1_496FC((s32)obj->unk_20, (s32)obj->unk_24);
    fn_1_4955C(obj->unk_28, obj->unk_28);
    fn_1_495FC();
    value = fn_1_4B090(&obj->unk_34);
    ratio = value / (fn_1_4B16C(&obj->unk_34));
    fn_1_4966C(0.0f, ratio * obj->unk_2C);
    if (fn_1_FA638() != 0) {
        fn_1_4AF64(&obj->unk_34);
    }
    fn_1_49614();
}
/* fzgx:end fn_1_154FD8 */

/* fzgx:begin fn_1_155120 */
/* WARNING: compiler-diff device, not original code: without both pragmas MWCC allocates the text pointer loads differently */
#pragma opt_common_subs off
#pragma opt_lifetimes off
void fn_1_155120(void) {
    RepMemcardText *state = &lbl_1_bss_8EDF0;
    RepMemcardChar *p = state->unk_10;
    RepMemcardChar *q;
    u32 ch;
    s8 next;

    ch = (u8)(p->unk_0);
    if (ch == 0) {
        return;
    }
    switch (ch) {
    case 0:
        break;
    case 92:
        p = (RepMemcardChar *)((u8 *)p + 1);
        state->unk_10 = (RepMemcardChar *)fn_1_15530C((u8 *)p);
        break;
    case 91:
        fn_1_A8EB0(20, 20);
        while ((ch = (q = state->unk_10)->unk_0) != 93) {
            ch = (state->unk_10->unk_0);
            if ((ch & 0x80) == 0) {
                state->unk_10 = (RepMemcardChar *)((u8 *)state->unk_10 + 1);
                state->unk_14++;
                *((u8 *)state + 0x34 + state->unk_1C) = ch;
            } else {
                next = q->unk_1;
                state->unk_10 = (RepMemcardChar *)((u8 *)state->unk_10 + 2);
                state->unk_14 += 2;
                *(((state->unk_1C) + (((u8 *)state) + (0x34)))) = ch;
                *((u8 *)state + 0x35 + state->unk_1C) = next;
            }
            state->unk_1C = state->unk_14 + state->unk_18 * 30;
        }
        state->unk_10 = (RepMemcardChar *)((u8 *)state->unk_10 + 1);
        state->unk_14++;
        ((u8 *)&state->unk_34)[state->unk_1C] = ch;
        state->unk_1C = state->unk_14 + state->unk_18 * 30;
        break;
    case 10:
        p = (RepMemcardChar *)((u8 *)p + 1);
        state->unk_10 = p;
        state->unk_14++;
        ((u8 *)&state->unk_34)[state->unk_1C] = 10;
        break;
    default:
        if ((ch & 0x80) == 0) {
            state->unk_10 = (RepMemcardChar *)((u8 *)state->unk_10 + 1);
            state->unk_14++;
            ((u8 *)&state->unk_34)[state->unk_1C] = ch;
        } else {
            next = state->unk_10->unk_1;
            state->unk_10 = (RepMemcardChar *)((u8 *)state->unk_10 + 2);
            state->unk_14 += 2;
            ((u8 *)&state->unk_34)[state->unk_1C] = ch;
            ((u8 *)&state->unk_35)[state->unk_1C] = next;
        }
        break;
    }
    state->unk_1C = state->unk_14 + state->unk_18 * 30;
}
#pragma opt_common_subs reset
#pragma opt_lifetimes reset
/* fzgx:end fn_1_155120 */

/* fzgx:begin fn_1_15530C */
u8 *fn_1_15530C(u8 *text) {
    RepMemcardText *obj = &lbl_1_bss_8EDF0;

    switch (*text) {
    case 'l':
    {
        u8 *dest;
        obj->unk_1C = 0;
        dest = &obj->unk_34;
        obj->unk_14 = 0;
        text++;
        obj->unk_18 = 0;
        memset(dest, 0, 0xFA);
        *dest = 0;
        break;
    }
    case 'w':
    {
        f32 value;
        text++;
        value = fn_80083E84(text);
        while ((*text >= '0' && *text <= '9') || *text == '.') {
            text++;
        }
        obj->unk_4 = (s16)(60.0f * value);
        break;
    }
    case 't':
    {
        s32 value;
        text++;
        value = atoi(text);
        while ((*text >= '0' && *text <= '9') || *text == '.') {
            text++;
        }
        value = value - obj->unk_0;
        if (value >= 0) {
            obj->unk_4 = value;
        } else {
            obj->unk_4 = 0;
        }
        break;
    }
    case 'p':
    {
        s32 value = 0;
        text++;
        while ((*text >= '0') && (*text <= '9')) {
            if (value != 0) {
                value *= 10;
            }
            value = *text + value;
            text++;
            value -= 0x30;
        }
        break;
    }
    case 's':
    {
        f32 value;
        text++;
        value = fn_80083E84(text);
        while ((*text >= '0' && *text <= '9') || *text == '.') {
            text++;
        }
        obj->unk_28 = value;
        break;
    }
    default:
        text++;
        break;
    }
    return text;
}
/* fzgx:end fn_1_15530C */
