/* Non-matching: best partial attempt (96.04% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/sel_static_disp.h"

typedef struct fn_1_14BFD8_Pad {
    u16 unk_0;
    u16 unk_2;
    u8 pad_4[4];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[4];
    u16 unk_10;
    u16 unk_12;
} fn_1_14BFD8_Pad;

typedef struct fn_1_14BFD8_Sel {
    u32 unk_0;
    u8 pad_4[0xC];
    u32 unk_10;
    u8 pad_14[4];
    f32 unk_18;
    u8 pad_1C[4];
    s32 unk_20;
    u8 pad_24[0xC];
    u8 unk_30;
    u8 pad_31[0xF];
    u8 unk_40;
    u8 unk_41;
    u8 pad_42[2];
    u32 unk_44;
    u32 unk_48;
} fn_1_14BFD8_Sel;

extern const f32 lbl_1_rodata_99A4;
extern s32 fn_1_1555B0(s32);
extern u32 fn_1_12EF80(u32, s16 *, s16 *);
extern s16 fn_1_12EF24(s16);
extern u32 fn_1_1556B4(u32, u32);
extern s32 fn_1_F89E4(u8);
extern u32 lbl_801A66A0;
extern u32 lbl_801A66A4;
extern void fn_1_A2D84(u32);

#define PAD(off) ((fn_1_14BFD8_Pad *)((u8 *)&lbl_1_bss_9F8 + (off)))

static inline s32 fn_1_14BFD8_min(s32 a, s32 b) {
    return (a > b) ? b : a;
}

static inline void fn_1_14BFD8_scroll(fn_1_14BFD8_Sel *s) {
    s32 top = 0;
    s32 x;
    u8 n;

    n = s->unk_30;
    s->unk_20 = top;
    s->unk_20 = x = -((n >> 1) - 1);
    top = (x < 0) ? 0 : fn_1_14BFD8_min(x, 10 - n);
    s->unk_20 = top;
    s->unk_18 = lbl_1_rodata_99A4;
}

#pragma opt_common_subs off
#pragma opt_propagation off
void fn_1_14BFD8(s16 port, u8 *sel, s32 apply) {
    s32 blocked;
    s32 left;
    u16 *rep;
    s32 right;
    s32 toggle;
    fn_1_14BFD8_Sel *s;
    u16 *trig;
    s32 dir;
    s16 next;
    s32 changed;
    s32 toggled;
    u32 sound;
    s16 a;
    s16 b;
    s32 off;

    off = port * 20;
    s = (fn_1_14BFD8_Sel *)&lbl_1_bss_8E518;
    blocked = 0;
    if (((PAD(off)->unk_0 >> 3) & 1) || ((PAD(off)->unk_2 >> 3) & 1) ||
        ((PAD(off)->unk_0 >> 2) & 1) || ((PAD(off)->unk_2 >> 2) & 1)) {
        blocked = 1;
    }
    left = 0;
    trig = (u16 *)PAD(off);
    rep = trig;
    trig += 4;
    rep += 8;
    if ((*rep & 1) || (PAD(off)->unk_12 & 1)) {
        if (blocked == 0) {
            left = 1;
        }
    }
    right = 0;
    if (((*rep >> 1) & 1) || ((PAD(off)->unk_12 >> 1) & 1)) {
        if (blocked == 0) {
            right = 1;
        }
    }
    toggle = (*trig >> 10) & 1;

    if (sel != NULL) {
        a = 0;
        b = 0;
        dir = 0;
        next = -1;
        fn_1_12EF80(*sel, &a, &b);
        if (left != 0) {
            dir = -1;
            s->unk_44 = lbl_801A66A0;
        } else if (right != 0) {
            dir = 1;
            s->unk_48 = lbl_801A66A0;
        }
        if (dir != 0) {
            for (b += dir; (s16)b >= 0 && b <= 5; b += dir) {
                next = fn_1_12EF24(a);
                if (a == 5) {
                    if ((b == 5 && fn_1_F89E4(0) == 0) || (b != 5 && fn_1_F89E4(b + 1) == 0)) {
                        next = -1;
                    }
                }
                if (next != -1) {
                    break;
                }
            }
            if (next != -1 && *sel != next) {
                *sel = next;
                fn_1_14BFD8_scroll(s);
                fn_1_1555B0(*sel);
                fn_1_1556B4(s->unk_40, s->unk_41);
                s->unk_0 = 0;
                s->unk_10 = lbl_801A66A4;
                fn_1_A2D84(0xA9010000);
            }
        }
    }

    if (apply != 0) {
        changed = 0;
        toggled = 0;
        if (toggle != 0) {
            switch (s->unk_41) {
            case 0:
                s->unk_41 = 2;
                sound = 0xA9121900;
                break;
            case 2:
                s->unk_41 = 1;
                sound = 0xA9121A00;
                break;
            case 1:
                s->unk_41 = 0;
                sound = 0xA9121800;
                break;
            }
            toggled = 1;
            fn_1_A2D84(sound);
        }
        if (changed != 0 || toggled != 0) {
            fn_1_1556B4(s->unk_40, s->unk_41);
            fn_1_14BFD8_scroll(s);
            s->unk_10 = lbl_801A66A4;
        }
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
