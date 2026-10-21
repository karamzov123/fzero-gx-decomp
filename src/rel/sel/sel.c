#include "types.h"

/* fzgx:begin _epilog */
extern u8 lbl_1_bss_8B3A0[];
extern s16 lbl_1_bss_960;
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_968;
extern u8 lbl_10_bss_0[];
extern char lbl_10_data_57C[];
extern char lbl_10_data_59C[];
extern u32 lbl_801A6410;

typedef struct {
    void *a;
    void *b;
} SelADXT;
extern SelADXT *lbl_1_bss_6EAD0;

extern void fn_10_95A0(void *);
extern void fn_10_96F8(void *, void *);
extern void fn_10_D2C(void);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_435C(u32);
extern void fn_1_41A8(void);
extern void fn_1_6400(void);
extern void fn_1_46BFC(void);
extern void fn_1_46DC4(s32);
extern void fn_8004BF0C(void *, u32);
extern void ADXT_Stop(void *);
extern void fn_1_A0AA4(void);
extern void fn_1_1596DC(int);
extern void fn_1_47A60(s16);
extern void fn_1_484CC(s32);
extern void fn_1_48140(int);
extern void fn_1_412A0(u32);

void _epilog(u32 lab_unused0) {
    u8 *state;
    u8 *base;
    u32 f;
    u8 *mgr;

    base = lbl_10_bss_0;
    mgr = base + 0x50000;
    state = lbl_1_bss_8B3A0;
    /* The `& (v | ~v)` identity is exact for u32 (v | ~v == 0xFFFFFFFF). The front
       end keeps the reads as operands, so the value takes this statement's anonymous
       compiler temporary; MWCC then folds the identity to `v` and the temporary
       survives coalescing, which colors it r4 between the two @ha pairs the way
       retail does (named-local spellings can only color after them). Finding 388. */
    f = *(u32 *)(state + 0x94) & (*(u32 *)(state + 0x94) | ~*(u32 *)(state + 0x94));

    *(u32 *)(state + 0x94) = f & 0xFFFFFFEF;
    *(u32 *)(state + 0x94) = f & 0xFFFFFFCF;
    if (!(((0x80000000) & (f)))) {
        fn_10_95A0(*(void **)(mgr - 0x6c80));
        fn_10_96F8(mgr - 0x6c60, mgr - 0x1140);
    }

    fn_1_46B4(lbl_801A6410, *(u32 *)(base + 4), lbl_10_data_57C, 0x424);
    fn_1_46B4(lbl_801A6410, *(u32 *)(mgr - 0x6c80), lbl_10_data_57C, 0x425);
    fn_1_46B4(lbl_801A6410, *(u32 *)(base + 0), lbl_10_data_57C, 0x426);

    fn_1_435C(*(u32 *)(mgr - 0x6c7c));
    fn_1_41A8();
    fn_1_435C(*(u32 *)(mgr - 0x6c78));
    fn_1_41A8();
    fn_1_6400();
    fn_1_46BFC();
    fn_1_46DC4((s32)lbl_10_data_59C);

    if (lbl_1_bss_960 != 1 || lbl_1_bss_962 != 0x10) {
        if (lbl_1_bss_6EAD0 != 0) {
            fn_8004BF0C(lbl_1_bss_6EAD0->a, -999);
            fn_8004BF0C(lbl_1_bss_6EAD0->b, -999);
            ADXT_Stop(lbl_1_bss_6EAD0->a);
            ADXT_Stop(lbl_1_bss_6EAD0->b);
        }
    }

    fn_1_A0AA4();
    if (*(u32 *)(state + 0x94) & 0x40000000) {
        fn_1_1596DC(3);
        fn_1_1596DC(2);
        fn_1_1596DC(1);
        fn_1_47A60(lbl_1_bss_960);
        fn_1_484CC(2);
    } else {
        fn_1_1596DC(2);
        fn_1_48140(0xa2);
        fn_1_48140(0x9c);
        fn_1_48140(0xa1);
        fn_1_48140(0x9d);
        fn_1_48140(0x9b);
        fn_1_48140(0x9a);
        fn_1_48140(0x95);
        fn_1_484CC(2);
    }
    fn_1_412A0(1);
    if (lbl_1_bss_968 == 2) {
        fn_10_D2C();
    }
}
/* fzgx:end _epilog */

/* fzgx:begin fn_10_12D8 */
#include "rel/sel/sel.h"

struct State {
    s16 current;
    s16 previous;
    u8 pad4[0x90];
    u32 flags;
    u8 pad98[0xC];
    u8 *entries;
    u8 padA8[0x81];
    u8 active;
};
extern struct State lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_964;
extern u8 *lbl_1_bss_6EAD0;
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void fn_1_4A00(u32, u32, u32);
extern u32 fn_8004CD70(u32, void *, u32);
extern void fn_1_A176C(u32, u32);
extern void fn_1_12F1E8(s32);
extern void fn_10_E294(void);

#pragma opt_strength_reduction off

#pragma opt_dead_assignments off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 fzgx_obj_lbl_10_bss_4EEC0[2592];
u32 fzgx_obj_lbl_10_bss_51740;
u32 fzgx_obj_lbl_10_bss_51744;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
    s = fzgx_obj_lbl_10_bss_3C0[0];
    s = fzgx_obj_lbl_10_bss_49380;
    s = fzgx_obj_lbl_10_bss_49384;
    s = fzgx_obj_lbl_10_bss_49388;
    s = fzgx_obj_lbl_10_bss_4938C;
    s = fzgx_obj_lbl_10_bss_4938E;
    s = fzgx_obj_lbl_10_bss_4938F;
    s = fzgx_obj_lbl_10_bss_49390[0];
    s = fzgx_obj_lbl_10_bss_493A0[0];
    s = fzgx_obj_lbl_10_bss_4EEC0[0];
    s = fzgx_obj_lbl_10_bss_51740;
    s = fzgx_obj_lbl_10_bss_51744;
}
#pragma section code_type ".text"

void fn_10_12D8(void) {
    u8 * fzgx_live;

    struct State *state;
    u32 high;
    u32 flags;
    u8 *entries;
    s32 offset;
    s16 result;
    s16 value;
    s16 finalValue;
    s32 handle;
    u8 *audio;
    u32 finalAddress;
    fn_1_435C(fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51740 = fn_1_3F8C(lbl_10_data_61C, fn_10_E294, 0, 8);
    fn_1_4A00(1, (u8)fzgx_obj_lbl_10_bss_4938C, fzgx_obj_lbl_10_bss_49388);
    audio = lbl_1_bss_6EAD0;
    fzgx_obj_lbl_10_bss_51744 = 0;
    if (audio != 0) {
        if (*(u32 *)audio == 0) {
            *(u32 *)lbl_1_bss_6EAD0 = fn_8004CD70(2, audio + 0x10, 0x25124);
        }
        if (*(u32 *)(lbl_1_bss_6EAD0 + 4) == 0) {
            *(u32 *)(lbl_1_bss_6EAD0 + 4) = fn_8004CD70(2, lbl_1_bss_6EAD0 + 0x4A258, 0x25124);
        }
        fn_1_A176C(*(u32 *)lbl_1_bss_6EAD0, 45);
    }
    state = (struct State *)&lbl_1_bss_8B3A0;
    flags = state->flags;
    state->flags = flags & 0xFFBFFFFF;
    if (0x40000000 & flags) {
        entries = state->entries;
        high = (lbl_1_bss_962 - 14) * 148;
        offset = high;
        value = *(s16 *)(entries + offset);
        result = lbl_1_bss_962;
        if (value < 9) {
            result = 9;
        } else {
            result = 10;
            if (value <= 10) result = value;
        }
        *(s16 *)(entries + offset) = result;
    } else {
        entries = state->entries;
        offset = (lbl_1_bss_962 - 14) * 148;
        if ((s16)*(s16 *)(entries + offset) < 0 || *(s16 *)(entries + offset) > 8) {
            *(s16 *)(entries + offset) = 1;
            switch (lbl_1_bss_964) {
            case 12: *(s16 *)(entries + offset) = 7; break;
            case 15: *(s16 *)(entries + offset) = 8; break;
            case 3: *(s16 *)(entries + offset) = 6; break;
            case 5: *(s16 *)(entries + offset) = 5; break;
            case 9: *(s16 *)(entries + offset) = 4; break;
            }
        }
    }
    fzgx_obj_lbl_10_bss_14 = -1;
    lbl_1_bss_8B3A0.current = -1;
    lbl_1_bss_8B3A0.active = 1;
    fn_1_12F1E8(360);
    finalValue = lbl_1_bss_8B3A0.previous;
    state->flags &= 0xFFFFFFFB;
    if (finalValue != -1) {
        fzgx_live = lbl_1_bss_8B3A0.entries;
        finalAddress = (u32)fzgx_live + lbl_1_bss_962 * 148;
        *(s16 *)((u8 *)finalAddress - 0x818) = finalValue;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_10_12D8 */

/* fzgx:begin fn_10_1F28 */
extern s32 lbl_10_bss_51740;
extern s32 lbl_10_bss_49388;
extern s16 lbl_1_bss_8B3A0;

extern void fn_1_435C(s32 value);
extern void fn_1_426C(s32 value);
extern void fn_10_BD64(void *value);
extern void fn_10_C594(void);

void fn_10_1F28(void) {
    s16 *state;

    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    state = &lbl_1_bss_8B3A0;
    fn_10_BD64(state);
    fn_10_C594();
    state[1] = state[0];
}
/* fzgx:end fn_10_1F28 */

/* fzgx:begin fn_10_21EC */
struct SelState {
    u8 pad_0[0x8];
    u16 unk_8;
    u16 unk_A;
    u8 pad_C[0x8];
    s32 unk_14;
};

struct SelSub {
    u8 pad_0[0x1a];
    u8 unk_1a;
};

struct SelObject {
    s16 unk_0;
    u8 pad_2[0x8e];
    s16 unk_90;
    u8 pad_92[0x2];
    u32 unk_94;
    s32 unk_98;
    u8 pad_9C[0x8];
    struct SelSub *unk_A4;
    u8 pad_A8[0x81];
    u8 unk_129;
    u8 pad_12A[0x16];
    u32 unk_140;
};

struct SelTile {
    u8 pad_0[0x8];
    u16 unk_8;
    u8 pad_A[0xa];
    u16 unk_14;
};

extern u8 lbl_10_bss_0[];
extern struct SelObject lbl_1_bss_8B3A0;
extern struct SelTile lbl_1_bss_9F8;
extern u8 lbl_1_bss_9C8[];
extern s16 lbl_1_bss_962;
extern s16 lbl_1_bss_96A;
extern u8 lbl_1_bss_8CA24;

extern int fn_1_4C10(void);
extern u8 fn_1_D6690(void);
extern u8 fn_1_D6698(void);
extern s16 fn_10_3D64(void);
extern s16 fn_10_C258(void *ctx, s32 arg);
extern u32 fn_10_A90C(void *obj);
extern u32 fn_10_AB98(void *obj);
extern u32 fn_10_AE14(void *obj);
extern int fn_1_12F228(void);
extern u32 fn_1_4A00(u32 a, u32 b, void *c);
extern u32 fn_1_EB4BC(void);
extern u8 fn_1_B7C00(void);
extern void fn_10_C210(void *obj, s16 arg);
extern void fn_10_C274(void *obj, int arg);
extern void fn_10_C298(void *obj, int arg);
extern void fn_1_12EF80(u32 mode, void *out1, void *out2);
extern void fn_1_12F150(s16 idx, u32 a, u32 b);
extern void fn_1_12F17C(void);
extern void fn_1_12F1E8(s32 arg);
extern void fn_1_159440(int a, int b);
extern void fn_1_1596DC(u32 a);
extern void fn_1_46A60(void);
extern void fn_1_7B218(s32 a);
extern void fn_1_7B2E8(u32 a);
extern void fn_1_A2D84(u32 a);
extern void fn_1_A51C8(s16 a);
extern void fn_1_EB330(void);

#pragma opt_common_subs off
void fn_10_21EC(void) {
    u32 fzgx_condition_19430;
    struct SelState *base;
    u8 *far;
    s16 ret;
    s16 count;
    s32 v3;
    struct SelObject *sel;
    struct { s16 value; } i;
    struct { u8 * value; } p9F8;
    struct { u8 * value; } p9C8;
    struct SelObject *psel;
    s16 t;
    u32 v;
    s16 locE;
    s16 locC;
    s16 locA;
    s16 loc8;
    s32 old;
    s32 cond;
    u32 lab_v;

    base = (struct SelState *)lbl_10_bss_0;
    far = (u8 *)base + 0x50000;
    ret = fn_10_C258(&lbl_1_bss_8B3A0, lbl_1_bss_962);
    count = 0;
    if (base->unk_14 == -1) {
        fn_1_4C10();
    }
    lab_v = lbl_1_bss_8B3A0.unk_140;
    if (((lab_v & 0x80000000) != 0) &&
        ((lab_v & 0x40000000) == 0) &&
        ((lbl_1_bss_8B3A0.unk_94 & 0x8) == 0)) {
        cond = 1;
    } else {
        if (fn_1_4C10() != 0) {
            cond = 1;
        } else {
            cond = 0;
        }
    }
    if (cond != 0) {
        return;
    }
    if (fn_1_B7C00() != 0) {
        return;
    }
    old = base->unk_14;
    if (old != -1) {
        base->unk_14 = -1;
        lbl_1_bss_96A = old;
        return;
    }
    if (((2) == (lbl_1_bss_8B3A0.unk_0)) || lbl_1_bss_8B3A0.unk_0 == 10) {
        old = (fn_1_EB4BC() == 0);
        v3 = old;
    } else {
        v3 = 1;
    }
    sel = &lbl_1_bss_8B3A0;
    if ((sel->unk_94 & 0x40000000) != 0 && v3 != 0) {
        if ((sel->unk_94 & 0x200) != 0) {
            switch (ret) {
            case 0:
                if (fn_1_12F228() == 0) {
                    fn_10_A90C(&lbl_1_bss_8B3A0);
                }
{
    struct { s16 value; } fzgx_loop_i_3463;
    struct { u8 * value; } fzgx_loop_p9C8_3463;
    struct { u8 * value; } fzgx_loop_p9F8_3463;
    struct SelObject * fzgx_loop_psel_3463;
                fzgx_loop_p9C8_3463.value = lbl_1_bss_9C8;
                fzgx_loop_p9F8_3463.value = (u8 *)&lbl_1_bss_9F8;
                fzgx_loop_i_3463.value = 0;
                fzgx_loop_psel_3463 = &lbl_1_bss_8B3A0;
                while ((s16)fzgx_loop_i_3463.value < 4) {
                    if (((-1) != ((s8)fzgx_loop_p9C8_3463.value[0xa])) &&
                        (__rlwnm(fzgx_loop_psel_3463->unk_98, (fzgx_loop_i_3463.value + 1) & 31, 31, 31)) != 0) {
                        if (((*(u16 *)(fzgx_loop_p9F8_3463.value + 8) >> 9) & 1) != 0) {
                            count--;
                        }
                        if ((((*(u16 *)(fzgx_loop_p9F8_3463.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                            count++;
                        }
                        if ((((*(u16 *)(fzgx_loop_p9F8_3463.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                            fn_1_12F150(fzgx_loop_i_3463.value, 5, 1);
                        } else if (((*(u16 *)(fzgx_loop_p9F8_3463.value + 8) >> 9) & 1) != 0) {
                            fn_1_12F150(fzgx_loop_i_3463.value, 5, 0);
                        }
                    }
                    fzgx_loop_p9C8_3463.value += 12;
                    fzgx_loop_p9F8_3463.value += 20;
                    fzgx_loop_i_3463.value++;
                }
    i.value = fzgx_loop_i_3463.value;
    p9C8.value = fzgx_loop_p9C8_3463.value;
    p9F8.value = fzgx_loop_p9F8_3463.value;
    psel = fzgx_loop_psel_3463;
}
                if (count > 0) {
                    fn_10_C274(&lbl_1_bss_8B3A0, lbl_1_bss_962);
                    fn_10_AB98(&lbl_1_bss_8B3A0);
                    fn_1_A2D84(0xA9010100);
                }
                if (count < 0 &&
                    ((sel->unk_94 & 0x40000000) == 0 || (sel->unk_94 & 0x4000) != 0)) {
                    base->unk_14 = 14;
                    t = fn_10_C258(&lbl_1_bss_8B3A0, 14);
                    if (t == 0) {
                        *(u32 *)(far + 0x1748) = 1;
                    }
                    fn_1_12F17C();
                    fn_1_4A00(0, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                    *(u32 *)(far + 0x1744) = 0;
                    fn_1_A2D84(0xA9010200);
                    fn_10_C210(&lbl_1_bss_8B3A0, base->unk_14);
                }
                break;
            case 1:
                if (*(u8 *)(far + 0x1750) > 1) {
                    *(u8 *)(far + 0x1750) -= 1;
                }
                if (*(u16 *)(far + 0x1752) > 1) {
                    *(u16 *)(far + 0x1752) -= 1;
                }
                if (*(u16 *)(far + 0x174e) != 0) {
                    u16 c = *(u16 *)(far + 0x174e);
                    c--;
                    *(u16 *)(far + 0x174e) = c;
                    if (c == 0xb3) {
                        if (lbl_1_bss_8B3A0.unk_90 != 0x24) {
                            lbl_1_bss_8CA24 = 0;
                        } else if (lbl_1_bss_8CA24 != 0) {
                            fn_1_A2D84(0xA9000400);
                        }
                        *(u8 *)(far + 0x1754) = 0;
                    }
                    if (*(u16 *)(far + 0x174e) == 0xaa) {
                        fn_1_12EF80(lbl_1_bss_8B3A0.unk_90, &locE, &locC);
                        fn_1_A51C8(locC);
                    }
                    if (*(u16 *)(far + 0x174e) == 1) {
                        base->unk_14 = 16;
                        fn_1_12F17C();
                        fn_1_4A00(0, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                        *(u32 *)(far + 0x1744) = 0;
                    }
                } else {
                    if (fn_1_12F228() == 0) {
                        fn_10_AE14(&lbl_1_bss_8B3A0);
                    }
                    p9C8.value = lbl_1_bss_9C8;
                    i.value = 0;
                    p9F8.value = (u8 *)&lbl_1_bss_9F8;
                    psel = &lbl_1_bss_8B3A0;
                    while ((s16)i.value < 4) {
                        if (((-1) != ((s8)p9C8.value[0xa])) &&
                            (__rlwnm(psel->unk_98, (i.value + 1) & 31, 31, 31)) != 0) {
                            if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                count--;
                            }
                            if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                                count++;
                            }
                            if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                                fn_1_12F150(i.value, 6, 1);
                            } else if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                fn_1_12F150(i.value, 6, 0);
                            }
                        }
                        p9C8.value += 12;
                        p9F8.value += 20;
                        i.value++;
                    }
                    if (count > 0) {
                        psel = &lbl_1_bss_8B3A0;
                        if (psel->unk_A4->unk_1a == 0) {
                            fn_1_A2D84(0xA9010100);
                            psel->unk_A4->unk_1a = 1;
                        }
                        fn_1_12F1E8(0);
                        if (fn_1_D6698() != 0 || fn_1_D6690() == 0) {
                            if (*(u16 *)(far + 0x1752) == 1) {
                                fn_1_7B2E8(lbl_1_bss_8B3A0.unk_90);
                                *(u16 *)(far + 0x174e) = 180;
                            }
                        }
                        if (*(u16 *)(far + 0x1752) == 0) {
                            if (lbl_1_bss_8B3A0.unk_0 != 2 && lbl_1_bss_8B3A0.unk_0 != 10) {
                                *(u16 *)(far + 0x1752) = 60;
                            } else {
                                *(u16 *)(far + 0x1752) = 1;
                            }
                        }
                        if (*(u8 *)(far + 0x1750) == 0) {
                            *(u8 *)(far + 0x1750) = 20;
                        }
                        if (((lbl_1_bss_9F8.unk_8 >> 12) & 1) != 0 &&
                            *(u8 *)(far + 0x1754) != 0 &&
                            (lbl_1_bss_9F8.unk_14 & 0xb) == 0xb &&
                            ((lbl_1_bss_9F8.unk_14 >> 2) & 1) == 0) {
                            *(u8 *)(far + 0x1754) = 0;
                            lbl_1_bss_8CA24 = 1;
                        }
                        lbl_1_bss_8B3A0.unk_129 = 0;
                    }
                    if (count < 0 &&
                        ((sel->unk_94 & 0x40000000) == 0 || (sel->unk_94 & 0x4000) != 0)) {
                        fn_10_C298(&lbl_1_bss_8B3A0, lbl_1_bss_962);
                        psel = &lbl_1_bss_8B3A0;
                        if (psel->unk_A4->unk_1a == 0) {
                            fn_1_A2D84(0xA9010200);
                            psel->unk_A4->unk_1a = 1;
                        }
                    }
                }
                break;
            }
        } else {
            if (*(u8 *)(far + 0x1750) > 1) {
                *(u8 *)(far + 0x1750) -= 1;
            }
            if (*(u16 *)(far + 0x1752) > 1) {
                *(u16 *)(far + 0x1752) -= 1;
            }
            if (*(u16 *)(far + 0x174e) != 0) {
                u16 c = *(u16 *)(far + 0x174e);
                c--;
                *(u16 *)(far + 0x174e) = c;
                if (c == 0xb3) {
                    if (lbl_1_bss_8B3A0.unk_90 != 0x24) {
                        lbl_1_bss_8CA24 = 0;
                    } else if (lbl_1_bss_8CA24 != 0) {
                        fn_1_A2D84(0xA9000400);
                    }
                    *(u8 *)(far + 0x1754) = 0;
                }
                if (*(u16 *)(far + 0x174e) == 0xaa) {
                    fn_1_12EF80(lbl_1_bss_8B3A0.unk_90, &locA, &loc8);
                    fn_1_A51C8(loc8);
                }
                if (*(u16 *)(far + 0x174e) == 1) {
                    base->unk_14 = 16;
                    fn_1_12F17C();
                    fn_1_4A00(0, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                    *(u32 *)(far + 0x1744) = 0;
                }
            } else {
                if (fn_1_12F228() == 0) {
                    fn_10_AE14(&lbl_1_bss_8B3A0);
                }
                p9C8.value = lbl_1_bss_9C8;
                i.value = 0;
                p9F8.value = (u8 *)&lbl_1_bss_9F8;
                psel = &lbl_1_bss_8B3A0;
                while ((s16)i.value < 4) {
                    if (((-1) != ((s8)p9C8.value[0xa])) &&
                        (__rlwnm(psel->unk_98, (i.value + 1) & 31, 31, 31)) != 0) {
                        if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                            count--;
                        }
                        if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                            count++;
                        }
                        if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                            fn_1_12F150(i.value, 6, 1);
                        } else if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                            fn_1_12F150(i.value, 6, 0);
                        }
                    }
                    p9C8.value += 12;
                    p9F8.value += 20;
                    i.value++;
                }
                if (count > 0) {
                    fn_1_12F1E8(0);
                    if (fn_1_D6698() != 0 || fn_1_D6690() == 0) {
                        if (*(u16 *)(far + 0x1752) == 1) {
                            fn_1_7B2E8(lbl_1_bss_8B3A0.unk_90);
                            *(u16 *)(far + 0x174e) = 180;
                        }
                    }
                    psel = &lbl_1_bss_8B3A0;
                    if (psel->unk_A4->unk_1a == 0) {
                        fn_1_A2D84(0xA9010100);
                        psel->unk_A4->unk_1a = 1;
                    }
                    if (*(u16 *)(far + 0x1752) == 0) {
                        if (lbl_1_bss_8B3A0.unk_0 != 2 && lbl_1_bss_8B3A0.unk_0 != 10) {
                            *(u16 *)(far + 0x1752) = 60;
                        } else {
                            *(u16 *)(far + 0x1752) = 1;
                        }
                    }
                    if (*(u8 *)(far + 0x1750) == 0) {
                        *(u8 *)(far + 0x1750) = 20;
                    }
                    if (((lbl_1_bss_9F8.unk_8 >> 12) & 1) != 0 &&
                        *(u8 *)(far + 0x1754) != 0 &&
                        (lbl_1_bss_9F8.unk_14 & 0xb) == 0xb &&
                        ((lbl_1_bss_9F8.unk_14 >> 2) & 1) == 0) {
                        *(u8 *)(far + 0x1754) = 0;
                        lbl_1_bss_8CA24 = 1;
                    }
                    lbl_1_bss_8B3A0.unk_129 = 0;
                }
                if (count < 0 &&
                    ((sel->unk_94 & 0x40000000) == 0 || (sel->unk_94 & 0x4000) != 0)) {
                    fn_10_C298(&lbl_1_bss_8B3A0, lbl_1_bss_962);
                    psel = &lbl_1_bss_8B3A0;
                    if (psel->unk_A4->unk_1a == 0) {
                        fn_1_A2D84(0xA9010200);
                        psel->unk_A4->unk_1a = 1;
                    }
                    fn_1_12F1E8(0);
                }
            }
        }
    } else {
        if (v3 != 0) {
            if (lbl_1_bss_8B3A0.unk_0 == 1) {
                switch (ret) {
                case 0:
                    fn_10_A90C(&lbl_1_bss_8B3A0);
                    p9C8.value = lbl_1_bss_9C8;
                    i.value = 0;
                    p9F8.value = (u8 *)&lbl_1_bss_9F8;
                    psel = &lbl_1_bss_8B3A0;
                    while ((s16)i.value < 4) {
                        if (((-1) != ((s8)p9C8.value[0xa])) &&
                            (__rlwnm(psel->unk_98, (i.value + 1) & 31, 31, 31)) != 0) {
                            if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                count--;
                            }
                            if (((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) {
                                count = (s16)(count + 1);
                            }
                            if (((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) {
                                fn_1_12F150(i.value, 5, 1);
                                fn_1_12F17C();
                            } else if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                fn_1_12F150(i.value, 5, 0);
                                fn_1_12F17C();
                            }
                        }
                        p9C8.value += 12;
                        p9F8.value += 20;
                        i.value++;
                    }
                    if (count > 0) {
                        t = fn_10_3D64();
                        v = sel->unk_94;
                        base->unk_A = t;
                        base->unk_8 = t;
                        if ((v & 0x400) != 0 && t != 0) {
                            base->unk_14 = 20;
                        } else {
                            base->unk_A = 0;
                            base->unk_8 = 0;
                            base->unk_14 = 16;
                        }
                        fn_10_AB98(&lbl_1_bss_8B3A0);
                        fn_1_A2D84(0xA9010100);
                        lbl_1_bss_8B3A0.unk_129 = 0;
                    }
                    if (count < 0 &&
                        ((sel->unk_94 & 0x40000000) == 0 || (sel->unk_94 & 0x4000) != 0)) {
                        v = sel->unk_94;
                        base->unk_14 = 14;
                        sel->unk_94 &= 0xffffffefU;
                        sel->unk_94 &= 0xffffffcfU;
                        t = fn_10_C258(&lbl_1_bss_8B3A0, 14);
                        if (t == 0) {
                            *(u32 *)(far + 0x1748) = 1;
                        }
                        fn_1_A2D84(0xA9010200);
                        fn_10_C210(&lbl_1_bss_8B3A0, base->unk_14);
                    }
                    if (count != 0) {
                        fn_1_4A00(0, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                        *(u32 *)(far + 0x1744) = 0;
                    }
                    break;
                }
            } else {
                switch (ret) {
                case 0:
                    fn_10_A90C(&lbl_1_bss_8B3A0);
                    p9C8.value = lbl_1_bss_9C8;
                    i.value = 0;
                    p9F8.value = (u8 *)&lbl_1_bss_9F8;
                    psel = &lbl_1_bss_8B3A0;
                    while ((s16)i.value < 4) {
                        if (((-1) != ((s8)p9C8.value[0xa])) &&
                            (__rlwnm(psel->unk_98, (i.value + 1) & 31, 31, 31)) != 0) {
                            if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                count--;
                            }
                            if (((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) {
                                count = (s16)(count + 1);
                            }
                            if (((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) {
                                fn_1_12F150(i.value, 5, 1);
                            } else if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                fn_1_12F150(i.value, 5, 0);
                            }
                        }
                        p9C8.value += 12;
                        p9F8.value += 20;
                        i.value++;
                    }
                    if (count > 0) {
                        *(s16 *)(far + 0x174c) = 1;
                        fn_1_A2D84(0xA9010100);
                        fn_1_7B218(0);
                        fn_1_4A00(0, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                        *(u32 *)(far + 0x1744) = 0;
                        return;
                    }
                    if (*(s16 *)(far + 0x174c) > 0) {
                        fn_1_4A00(1, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                        v = sel->unk_94;
                        *(u32 *)(far + 0x1744) = 0;
                        *(s16 *)(far + 0x174c) = 0;
                        if ((v & 0x4) != 0) {
                            base->unk_14 = 33;
                            fn_1_12F17C();
                            fn_1_4A00(0, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                            *(u32 *)(far + 0x1744) = 0;
                            fn_1_12F1E8(0);
                        } else {
                            fn_10_C274(&lbl_1_bss_8B3A0, lbl_1_bss_962);
                            fn_10_AB98(&lbl_1_bss_8B3A0);
                        }
                    }
                    if (count < 0 &&
                        (((fzgx_condition_19430 = sel->unk_94) & 0x40000000) == 0 || (fzgx_condition_19430 & 0x4000) != 0) &&
                        (fzgx_condition_19430 & 0x20) == 0) {
                        v = sel->unk_94;
                        base->unk_14 = 14;
                        sel->unk_94 &= 0xffffffefU;
                        sel->unk_94 &= 0xffffffcfU;
                        t = fn_10_C258(&lbl_1_bss_8B3A0, 14);
                        if (t == 0) {
                            *(u32 *)(far + 0x1748) = 1;
                        }
                        fn_1_12F17C();
                        fn_1_4A00(0, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                        *(u32 *)(far + 0x1744) = 0;
                        fn_1_A2D84(0xA9010200);
                        fn_10_C210(&lbl_1_bss_8B3A0, base->unk_14);
                    }
                    break;
                case 1:
                    if (((2) == (lbl_1_bss_8B3A0.unk_0)) && ((lbl_1_bss_9F8.unk_8 >> 11) & 1) != 0) {
                        fn_1_EB330();
                    } else {
                        fn_10_AE14(&lbl_1_bss_8B3A0);
                        p9C8.value = lbl_1_bss_9C8;
                        i.value = 0;
                        p9F8.value = (u8 *)&lbl_1_bss_9F8;
                        psel = &lbl_1_bss_8B3A0;
                        while ((s16)i.value < 4) {
                            if (((-1) != ((s8)p9C8.value[0xa])) &&
                                (__rlwnm(psel->unk_98, (i.value + 1) & 31, 31, 31)) != 0) {
                                if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                    count--;
                                }
                                if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                                    count++;
                                }
                                if ((((*(u16 *)(p9F8.value + 8) >> 8) & 1) != 0) || fn_1_12F228() != 0) {
                                    fn_1_12F150(i.value, 6, 1);
                                } else if (((*(u16 *)(p9F8.value + 8) >> 9) & 1) != 0) {
                                    fn_1_12F150(i.value, 6, 0);
                                }
                            }
                            p9C8.value += 12;
                            p9F8.value += 20;
                            i.value++;
                        }
                        if (count > 0) {
                            t = fn_10_3D64();
                            v = sel->unk_94;
                            base->unk_A = t;
                            base->unk_8 = t;
                            if ((v & 0x400) != 0 && t != 0) {
                                base->unk_14 = 20;
                            } else {
                                base->unk_A = 0;
                                base->unk_8 = 0;
                                base->unk_14 = 16;
                            }
                            fn_1_12F17C();
                            fn_1_4A00(0, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                            *(u32 *)(far + 0x1744) = 0;
                            fn_1_A2D84(0xA9010100);
                            fn_1_12F1E8(0);
                            lbl_1_bss_8B3A0.unk_129 = 0;
                        }
                        if (count < 0 &&
                            ((sel->unk_94 & 0x40000000) == 0 || (sel->unk_94 & 0x4000) != 0)) {
                            *(s16 *)(far + 0x174c) = -1;
                            fn_1_4A00(0, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                            *(u32 *)(far + 0x1744) = 0;
                            fn_1_A2D84(0xA9010200);
                            return;
                        }
                        if (*(s16 *)(far + 0x174c) < 0) {
                            fn_1_4A00(1, *(s16 *)(far - 0x6c74) & 0xff, *(void **)(far - 0x6c78));
                            *(u32 *)(far + 0x1744) = 0;
                            *(u16 *)(far + 0x174c) = 0;
                            fn_10_C298(&lbl_1_bss_8B3A0, lbl_1_bss_962);
                            fn_1_46A60();
                            fn_1_1596DC(3);
                            fn_1_159440(3, 0);
                        }
                    }
                    break;
                }
            }
        }
    }
    if (v3 == 0) {
        lbl_1_bss_96A = -1;
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_10_21EC */

/* fzgx:begin fn_10_3268 */
extern u8 lbl_10_bss_51748[6];
extern void fn_1_1596DC(s32);
extern u8 lbl_1_bss_8B3A0[];
extern void fn_10_C594(void);
extern void fn_1_EC910(void);
extern s32 lbl_10_bss_51740;
extern u32 lbl_10_bss_49388;
extern void fn_1_435C(u32);
extern void fn_1_426C(s32);
extern void fn_1_7B4C0(void);
extern void fn_10_BEF0(u8 *);

void fn_10_3268(void) {
    if (*(s32 *)lbl_10_bss_51748 == 1) {
        *(s32 *)lbl_10_bss_51748 = 0;
        *(s16 *)lbl_1_bss_8B3A0 = -1;
    }
    if (*(s16 *)lbl_1_bss_8B3A0 != 1) {
        fn_1_1596DC(3);
    }
    fn_10_C594();
    fn_1_EC910();
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    {
        u8 *state = lbl_1_bss_8B3A0;
        if ((*(u32 *)(state + 0x94) & (1u << 31)) == 0) {
            fn_1_7B4C0();
        }
        fn_10_BEF0(lbl_1_bss_8B3A0);
        if (*(u32 *)(state + 0x94) & (1u << 30)) {
            *(s16 *)(lbl_1_bss_8B3A0 + 0xe) = 6;
        }
    }
}
/* fzgx:end fn_10_3268 */

/* fzgx:begin fn_10_3954 */
typedef struct {
    u8 a;
    u8 pad[3];
    u32 arr[1];
} SelEnt;

typedef struct {
    u8 pad0[0x40e00];
    u32 flags;
    u8 b4;
    u8 b5;
    u8 pad1[0x48FA0 - 0x40e06];
    u8 x;
    u8 pad2[3];
    SelEnt e[3];
} SelBig;

extern u8 lbl_1_bss_8B3A0[];
extern u32 lbl_10_bss_3C0[74736];
extern u8 fn_1_128B00(s16);
extern s16 fn_1_14F270(u8, s16, u32);
extern u32 fn_1_151BE8(u8, s32);

#define SEL ((SelBig *)lbl_10_bss_3C0)

void fn_10_3954(void) {
    s16 i;
    s16 j;

    if ((*(u32 *)(0x94 + lbl_1_bss_8B3A0) & ((u32)1 << 30)) == 0) {
        SEL->flags &= ~((u32)3 << 30);
        return;
    }

    if ((SEL->flags & ((u32)1 << 31)) != 0 &&
        (SEL->flags & ((u32)1 << 30)) != 0) {
        return;
    }

    SEL->flags |= ((u32)3 << 30);
    SEL->b5 = 0x31;

    for (i = 0; i < 3; i++) {
        SEL->e[i].a = fn_1_14F270(fn_1_128B00(i), i, (u32)1 << 31);
    }

    SEL->x = fn_1_128B00(i);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            SEL->e[i].arr[j] = fn_1_151BE8(SEL->e[i].a, j);
        }
    }
}
/* fzgx:end fn_10_3954 */

/* fzgx:begin fn_10_3A98 */
typedef struct {
    u8 pad[4];
    u32 flags;
} SelSlot;

typedef struct {
    u8 pad[0x18];
    s16 index_x;
    s16 index_y;
    SelSlot slots[][19];
} SelState;

typedef struct {
    u8 pad[0x94];
    u32 flags;
} GlobalState;

extern GlobalState lbl_1_bss_8B3A0;
extern SelState lbl_10_bss_0;
extern u32 lbl_10_bss_3C0[74736];
extern void fn_1_152970(s16 *, s16 *, s32, s32, SelSlot *, s16, s16);

#pragma opt_propagation off
void fn_10_3A98(void) {
    SelSlot (* fzgx_live)[19];
    SelState *sel = &lbl_10_bss_0;
    s16 slot_y;
    s16 slot_x;
    u32 state;

    if (!(lbl_1_bss_8B3A0.flags & 0x40000000)) {
        return;
    }

    state = *(u32 *)((u8 *)lbl_10_bss_3C0 + 0x40e00);
    if (!(state & ((u32)1 << 31)) || !(state & 0x40000000)) {
        return;
    }

    fn_1_152970(&slot_y, &slot_x, 0x31, 0, (SelSlot *)&sel->slots[0][0],
                 sel->index_y, sel->index_x);
    fzgx_live = sel->slots;
    fzgx_live[slot_y][slot_x].flags &= ~0x40000000;
}
#pragma opt_propagation reset
/* fzgx:end fn_10_3A98 */

/* fzgx:begin fn_10_3B44 */
typedef struct {
    u8 pad[4];
    u32 flags;
} SelSlot;

typedef struct {
    u8 pad[0x18];
    s16 index_x;
    s16 index_y;
    SelSlot slots[][19];
} SelState;

typedef struct {
    u32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 pad[0x81C0 - 6];
} SelEnt;

typedef struct {
    s16 key;
    u16 pad;
    u32 mask;
} SelFnEntry;

extern u32 lbl_10_bss_3C0[74736];
extern s32 fn_1_152970(s16 *, s16 *, s16, u32, SelFnEntry *, s16, s16);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
s16 fzgx_obj_lbl_10_bss_18;
s16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
}
#pragma section code_type ".text"

#pragma opt_loop_invariants off
void fn_10_3B44(void) {
    s16 i;
    s16 row;
    s16 col;
    SelEnt *e;

    for (i = 0x29; i <= 0x30; i++) {
        s16 idx;

        fn_1_152970(&row, &col, i, 0, (SelFnEntry *)fzgx_obj_lbl_10_bss_1C,
                    fzgx_obj_lbl_10_bss_1A, fzgx_obj_lbl_10_bss_18);
        idx = i - 0x29;
        ((SelSlot (*)[19])fzgx_obj_lbl_10_bss_1C)[row][col].flags |= 0x20000000;
        e = (SelEnt *)((u8 *)lbl_10_bss_3C0 + idx * 0x81C0);
        if (e->unk_0 & 0x80000000) {
            e->unk_5 = i;
            ((SelSlot (*)[19])fzgx_obj_lbl_10_bss_1C)[row][col].flags &= ~0x40000000;
        }
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_10_3B44 */

/* fzgx:begin fn_10_3C14 */
typedef struct {
    u8 pad[4];
    u32 flags;
} SelSlot;

typedef struct {
    u8 pad[0x94];
    u32 flags;
} GlobalState;

extern GlobalState lbl_1_bss_8B3A0;
extern void fn_1_152970(s16 *, s16 *, s32, s32, SelSlot *, s16, s16);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
s16 fzgx_obj_lbl_10_bss_18;
s16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
}
#pragma section code_type ".text"

void fn_10_3C14(void) {
    u8 *flags;
    s16 slot_y;
    s16 slot_x;

    if (lbl_1_bss_8B3A0.flags & 0x20000000) {
        return;
    }
    fn_1_152970(&slot_y, &slot_x, 0x36, 0, (SelSlot *)fzgx_obj_lbl_10_bss_1C, fzgx_obj_lbl_10_bss_1A,
                fzgx_obj_lbl_10_bss_18);
    flags = (u8 *)&((SelSlot *)fzgx_obj_lbl_10_bss_1C)->flags;
    *(u32 *)(flags + slot_y * 0x98 + slot_x * 8) |= 0x10000000;
    fn_1_152970(&slot_y, &slot_x, 0x37, 0, (SelSlot *)fzgx_obj_lbl_10_bss_1C, fzgx_obj_lbl_10_bss_1A,
                fzgx_obj_lbl_10_bss_18);
    *(u32 *)(flags + slot_y * 0x98 + slot_x * 8) |= 0x10000000;
    fn_1_152970(&slot_y, &slot_x, 0x38, 0, (SelSlot *)fzgx_obj_lbl_10_bss_1C, fzgx_obj_lbl_10_bss_1A,
                fzgx_obj_lbl_10_bss_18);
    *(u32 *)(flags + slot_y * 0x98 + slot_x * 8) |= 0x10000000;
    fn_1_152970(&slot_y, &slot_x, 0x39, 0, (SelSlot *)fzgx_obj_lbl_10_bss_1C, fzgx_obj_lbl_10_bss_1A,
                fzgx_obj_lbl_10_bss_18);
    *(u32 *)(flags + slot_y * 0x98 + slot_x * 8) |= 0x10000000;
}
/* fzgx:end fn_10_3C14 */

/* fzgx:begin fn_10_3D64 */
extern int lbl_1_bss_7180C;
extern int fn_1_B7E98(int);

s16 fn_10_3D64(void) {
    s16 result = 0;

    if (lbl_1_bss_7180C == 1 && fn_1_B7E98(0) == 1) {
        result |= 1;
    }
    if (lbl_1_bss_7180C == 1 && fn_1_B7E98(1) == 1) {
        result |= 2;
    }
    return result;
}
/* fzgx:end fn_10_3D64 */

/* fzgx:begin fn_10_3DE0 */
typedef struct SelEntry {
    u32 flags;                  /* 0x0 */
    u8 pad04;                   /* 0x4 */
    u8 value5;                  /* 0x5 */
    u8 pad06;                   /* 0x6 */
    u8 type7;                   /* 0x7 */
    u8 pad08[0x81a0 - 0x8];
    u8 source_index;            /* 0x81a0 */
    u8 pad81a1[0x81c0 - 0x81a1];
} SelEntry;

typedef struct SelObject {
    u8 pad000[0x390];
    u32 flags390;               /* 0x390 */
    u8 pad394[0xc];
    void *data3a0;              /* 0x3a0 */
    u32 result3a4;              /* 0x3a4 */
    u8 pad3a8[0x12];
    s16 slot3ba;                /* 0x3ba */
} SelObject;

typedef struct SelResult {
    SelObject *object;          /* 0x0 */
    u8 kind4;                   /* 0x4 */
    u8 pad05[0x10420 - 0x5];
    u32 zero10420;              /* 0x10420 */
    void (*cb10424)(void);      /* 0x10424 */
    void (*cb10428)(void);      /* 0x10428 */
    void (*cb1042c)(void);      /* 0x1042c */
} SelResult;

typedef struct CopyData {
    u32 words[0x110];           /* 0x440 bytes */
} CopyData;

extern u8 lbl_10_bss_493A0[23328];
extern u32 lbl_10_bss_49380;

extern void fn_1_13F848(u32);
extern void fn_1_13F974(u32);
extern SelResult *fn_1_13F8B0(u32);
extern SelObject *fn_1_13F9DC(u32);
extern u32 fn_1_7F254(SelEntry *, s16);
extern void fn_1_FD324(void);
extern void fn_1_FDC00(void);
extern void fn_1_FD27C(void);
extern u32 fn_1_FD844(SelEntry *, void *);

void fn_10_3DE0(u32 index, SelEntry *entries, s16 slot) {
    u32 i = index & 0xff;
    SelEntry *entry = (SelEntry *)((u8 *)entries + i * 0x81c0);
    SelObject *object;
    SelResult *result;
    u8 old_value;
    u8 value;

    if ((entry->flags & ((u32)1 << 31)) != 0 && entry->type7 <= 4 &&
        entry->type7 != 0) {
        fn_1_13F848(index);
        fn_1_13F974(index);
        result = fn_1_13F8B0(index);
        object = fn_1_13F9DC(index);
        old_value = entry->value5;
        value = entry->source_index;

        if (entry->flags & 0x40000000) {
            object->flags390 |= 0x04000000;
            object->data3a0 = &lbl_10_bss_493A0[i * 0xa20];
        } else {
            entry->value5 = value;
            *(CopyData *)object =
                *(CopyData *)((u8 *)lbl_10_bss_49380 + value * 0x440);
        }

        object->slot3ba = slot;
        object->result3a4 = fn_1_7F254(entry, (s16)(1 << object->slot3ba));
        result->object = object;
        result->kind4 = 4;
        result->cb10424 = fn_1_FD324;
        result->cb10428 = fn_1_FDC00;
        result->cb1042c = fn_1_FD27C;
        result->zero10420 = 0;
        fn_1_FD844(entry, result);
        entry->value5 = old_value;
    }
}
/* fzgx:end fn_10_3DE0 */

/* fzgx:begin fn_10_436C */
extern u8 lbl_10_bss_0[0x50004];
extern s16 lbl_1_bss_96A;
extern s16 lbl_1_bss_962[4];
extern u8 lbl_1_bss_8B3A0[];

extern void fn_1_4BB0(void);
extern void fn_10_C594(void);
extern void fn_1_12C0EC(void *);
extern void fn_1_435C(u32);
extern void fn_1_426C(u32);
extern void fn_10_BEF4(void *);
extern void fn_1_12C000(void *, s32);
extern void fn_1_48140(s32);
extern void fn_10_96F8(void *, void *);
extern void fn_1_36AD0(void);
extern void fn_1_12F10C(void);
extern void fn_1_12AF7C(void);
extern void fn_1_A5330(u8, u32);
extern void fn_1_13F8C4(void);
extern void fn_1_13F9F0(void);
extern void fn_1_FDFF4(void);

typedef struct {
    u8 pad0[0x94];
    u32 flags;
    u8 pad98[7];
    u8 value;
    u8 padA0[4];
    u8 *items;
} SelState;

void fn_10_436C(void) {
    SelState *s;
    u8 *base;
    s32 offset;
    s16 i;
    s32 n;
    base = lbl_10_bss_0 + 0x50000;
    fn_1_4BB0();
    fn_10_C594();

    if (lbl_1_bss_96A == 0x12) {
        s16 *ids;

        s = (SelState *)lbl_1_bss_8B3A0;
        i = 0;
        ids = lbl_1_bss_962;
        offset = 0;
        while (i < 4) {
            fn_1_12C0EC(s->items + (*ids - 0xe) * 0x94 + offset + 0x24);
            offset += 0x1c;
            i++;
        }
    }

    if (lbl_1_bss_96A != 0x14 && *(s32 *)(base + 0x1740) != -1) {
        fn_1_435C(*(u32 *)(base - 0x6c78));
        fn_1_426C(*(u32 *)(base + 0x1740));
        *(s32 *)(base + 0x1740) = -1;
    }

    fn_10_BEF4(lbl_1_bss_8B3A0);

    s = (SelState *)lbl_1_bss_8B3A0;

    if ((s->flags & 0x80000000) == 0 && lbl_1_bss_96A != 0x14) {
        n = 4;
        if (s->flags & 0x20000000) {
            n = 1;
        }
        fn_1_12C000(base + 0x197c, n);
        fn_1_12C000(base + 0x17ec, n);
        fn_1_12C000(base + 0x1788, 1);
        if (s->flags & 0x100) {
            fn_1_48140(0xa0);
        }
    }

    fn_10_96F8(base - 0x6c60, base - 0x1140);

    if (lbl_1_bss_96A != 0x14) {
        fn_1_36AD0();
        fn_1_12F10C();
        fn_1_12AF7C();
    }

    if (s->flags & 0x40000000) {
        if (*(s16 *)(lbl_1_bss_8B3A0 + 0xe) == 6) {
            *(u8 *)(lbl_1_bss_8B3A0 + 0x9f) = 0x32;
        }
        fn_1_A5330(*(u8 *)(lbl_1_bss_8B3A0 + 0x9f), 0);
    }

    if (s->flags & 0x40000000) {
        fn_1_13F8C4();
        fn_1_13F9F0();
    } else {
        s16 mode = *(s16 *)lbl_1_bss_8B3A0;
        if ((u16)mode <= 1 || mode == 3 || mode == 2) {
            fn_1_13F8C4();
            fn_1_13F9F0();
            fn_1_FDFF4();
        }
    }
}
/* fzgx:end fn_10_436C */

/* fzgx:begin fn_10_4568 */
extern char lbl_10_data_67C[18];
extern void fn_10_21E30(void);
extern void *fn_1_435C(void *);
extern void *fn_1_3F8C(void *, void *, u32, u32);
extern void fn_1_47F74(s32);
extern void fn_1_34E08(void);
extern void fn_1_4A00(u32, u32, void *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 fzgx_obj_lbl_10_bss_4EEC0[2592];
u32 fzgx_obj_lbl_10_bss_51740;
u32 fzgx_obj_lbl_10_bss_51744;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
    s = fzgx_obj_lbl_10_bss_3C0[0];
    s = fzgx_obj_lbl_10_bss_49380;
    s = fzgx_obj_lbl_10_bss_49384;
    s = fzgx_obj_lbl_10_bss_49388;
    s = fzgx_obj_lbl_10_bss_4938C;
    s = fzgx_obj_lbl_10_bss_4938E;
    s = fzgx_obj_lbl_10_bss_4938F;
    s = fzgx_obj_lbl_10_bss_49390[0];
    s = fzgx_obj_lbl_10_bss_493A0[0];
    s = fzgx_obj_lbl_10_bss_4EEC0[0];
    s = fzgx_obj_lbl_10_bss_51740;
    s = fzgx_obj_lbl_10_bss_51744;
}
#pragma section code_type ".text"

void fn_10_4568(void) {
    fn_1_435C((void *)fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51740 = (u32)fn_1_3F8C(lbl_10_data_67C, fn_10_21E30, 0, 8);
    fn_1_4A00(1, (u8)fzgx_obj_lbl_10_bss_4938C, (void *)fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51744 = 0;
    fzgx_obj_lbl_10_bss_14 = -1;
    fn_1_47F74(0x8b);
    fn_1_47F74(0xa1);
    fn_1_34E08();
}
/* fzgx:end fn_10_4568 */

/* fzgx:begin fn_10_4600 */
extern s32 lbl_10_bss_14;
extern s16 lbl_10_bss_4938C;
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_51744;
extern u32 lbl_801A66C0;
extern u16 lbl_1_bss_96A;
extern u8 lbl_1_bss_8B3A0[];
struct S9F8 {
    u8 pad0[8];
    u16 f8;
    u8 pad1[0x14 - 0xa];
};
extern struct S9F8 lbl_1_bss_9F8[];

extern s32 fn_1_4C10(void);
extern s32 fn_1_467F4(void);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_12F17C(void);

void fn_10_4600(void) {
    s32 ready;
    u32 flags;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    flags = *(u32 *)(lbl_1_bss_8B3A0 + 0x140);
    if ((flags & 0x80000000) != 0 &&
        (flags & 0x40000000) == 0 &&
        (*(u32 *)(lbl_1_bss_8B3A0 + 0x94) & 8) == 0) {
        ready = 1;
    } else {
        if (fn_1_4C10() != 0) {
            ready = 1;
        } else {
            ready = 0;
        }
    }

    if (ready != 0) {
        return;
    }

    if (lbl_10_bss_14 != -1) {
        s32 value = lbl_10_bss_14;
        lbl_10_bss_14 = -1;
        lbl_1_bss_96A = (u16)value;
        return;
    }

    if (lbl_801A66C0 <= 0x12c &&
        ((lbl_1_bss_9F8[*(u8 *)(lbl_1_bss_8B3A0 + 0x9e)].f8 >> 8) & 1) == 0) {
        return;
    }

    if (fn_1_467F4() != 0) {
        return;
    }

    *(u32 *)(lbl_1_bss_8B3A0 + 0x94) |= 0x08000000;
    fn_1_4A00(0, (u8)lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    fn_1_12F17C();
}
/* fzgx:end fn_10_4600 */

/* fzgx:begin fn_10_472C */
extern void fn_10_C594(void);
extern void fn_1_48140(u32);
extern void fn_1_435C(u32);
extern void fn_1_426C(u32);
extern u32 lbl_10_bss_51740;
extern u32 lbl_10_bss_49388;

void fn_10_472C(void) {
    fn_10_C594();
    fn_1_48140(0x8b);
    if ((s32)lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
}
/* fzgx:end fn_10_472C */

/* fzgx:begin fn_10_4790 */
#include "rel/sel/sel.h"

extern void fn_10_2228C(void);
extern void fn_10_25E1C(void);
extern u8 lbl_10_data_54C[8];
extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void fn_1_4A00(s32, u8, u32);
extern u32 fn_1_15BB34(void *);
extern u8 lbl_1_bss_8B3A0[];

typedef struct {
    u8 pad_0[0x14];
    s32 unk_14;
} SelBase;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 fzgx_obj_lbl_10_bss_4EEC0[2592];
u32 fzgx_obj_lbl_10_bss_51740;
u32 fzgx_obj_lbl_10_bss_51744;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
    s = fzgx_obj_lbl_10_bss_3C0[0];
    s = fzgx_obj_lbl_10_bss_49380;
    s = fzgx_obj_lbl_10_bss_49384;
    s = fzgx_obj_lbl_10_bss_49388;
    s = fzgx_obj_lbl_10_bss_4938C;
    s = fzgx_obj_lbl_10_bss_4938E;
    s = fzgx_obj_lbl_10_bss_4938F;
    s = fzgx_obj_lbl_10_bss_49390[0];
    s = fzgx_obj_lbl_10_bss_493A0[0];
    s = fzgx_obj_lbl_10_bss_4EEC0[0];
    s = fzgx_obj_lbl_10_bss_51740;
    s = fzgx_obj_lbl_10_bss_51744;
}
#pragma section code_type ".text"

void fn_10_4790(void) {
    fn_1_435C(fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51740 = fn_1_3F8C(lbl_10_data_694, fn_10_2228C, 0, 8);
    fn_1_4A00(1, (u8)fzgx_obj_lbl_10_bss_4938C, fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51744 = 0;
    fzgx_obj_lbl_10_bss_14 = -1;
    fn_10_25E1C();
    fn_1_15BB34(lbl_10_data_54C);
    (*(u8 **)(lbl_1_bss_8B3A0 + 0xA4))[0x22] = 0;
}
/* fzgx:end fn_10_4790 */

/* fzgx:begin fn_10_4838 */
typedef struct {
    u32 unk_0;
    u32 unk_4;
} Sig_fn_1_B7F58_Result;

struct fn_10_4838_lbl_10_bss_55CE0 {
    u8 unk_0;
};
struct fn_10_4838_lbl_10_bss_14 {
    u32 unk_0;
};
struct fn_10_4838_lbl_1_bss_8B3A0 {
    u8 pad_0[146];
    u32 unk_94;
    u8 pad_98[0x6];
    u8 unk_9E;
    u8 pad_9F[0x5];
    u32 unk_A4;
    u8 pad_A8[0x98];
    s32 unk_140;

    u8 fzgx_tail_padding[2];
};
struct fn_10_4838_lbl_10_bss_4938C {
    s16 unk_0;
};
struct S9F8 {
    u8 pad0[8];
    u16 f8;
    u8 pad1[0x14 - 0xa];
};

extern int fn_1_4C10(void);
extern int fn_1_B7F58(Sig_fn_1_B7F58_Result *);
extern struct fn_10_4838_lbl_10_bss_14 lbl_10_bss_14;
extern struct fn_10_4838_lbl_10_bss_4938C lbl_10_bss_4938C;
extern struct fn_10_4838_lbl_10_bss_55CE0 lbl_10_bss_55CE0;
extern struct fn_10_4838_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct S9F8 lbl_1_bss_9F8[];
extern u16 lbl_1_bss_96A;
extern u32 fn_1_15BBC4(void);
extern u32 fn_1_4A00(u32, u32, void *);
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_51744;
extern u8 fn_10_26000(void);
extern u8 fn_1_B7C00(void);
extern void fn_1_12EF80(u32, void *, void *);
extern void fn_1_12F17C(void);
extern void fn_1_14BD44(void *, void *);

#pragma opt_common_subs off
#pragma opt_lifetimes off
static inline s16 fn_10_4838_array_read(s32 index, s16 *array) { return array[index]; }
#pragma opt_pointer_analysis off
static inline struct S9F8 *fn_10_4838_array_read_(struct S9F8 *array) { return array; }
void fn_10_4838(void) {
    u32 unk_0;
    struct fn_10_4838_lbl_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    struct fn_10_4838_lbl_10_bss_14 *p14;
    int v0;
    s32 v9;
    void * lab_t2;
    struct { f64 a[1]; } loc_10;
    s16 loc_A;
    u16 loc_8;
    u32 lab_v;

    unk_0 = fn_1_15BBC4();
    lab_t2 = (void *)&loc_8;
    fn_1_12EF80(lbl_10_bss_55CE0.unk_0, (void *)&loc_A, lab_t2);
    if ((fn_1_B7C00() & 0xFF) != 0) return;
    if ((((0xFFFF) & (unk_0)) == 0 && loc_A == 1) ||
        (((0xFFFF) & (unk_0)) == 1 && loc_A == 2) ||
        (((0xFFFF) & (unk_0)) == 2 && loc_A == 3) ||
        (((0xFFFF) & (unk_0)) == 3 && loc_A == 4) ||
        (((0xFFFF) & (unk_0)) == 4 && loc_A == 5)) {
        if (fn_1_B7F58((Sig_fn_1_B7F58_Result *)&loc_10) != 0) {
            *(u8 *)(lbl_1_bss_8B3A0.unk_A4 + 0x22) = 1;
        }
    }
    if ((s32)lbl_10_bss_14.unk_0 == -1) {
        fn_1_4C10();
    }
    lab_v = lbl_1_bss_8B3A0.unk_140;
    if ((lab_v & ~0x7FFFFFFF) != 0 &&
        (lab_v & 0x40000000) == 0 &&
        (lbl_1_bss_8B3A0.unk_94 & 0x8) == 0) {
        v0 = 1;
    } else {
        if (fn_1_4C10() != 0) {
            v0 = 1;
        } else {
            v0 = 0;
        }
    }
    if (v0 != 0) return;
    p14 = &lbl_10_bss_14;
    if ((s32)p14->unk_0 != -1) {
        u32 value = p14->unk_0;
        p14->unk_0 = -1;
        lbl_1_bss_96A = (u16)value;
        return;
    }
    p_lbl_1_bss_8B3A0 = (struct fn_10_4838_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;
    if (*(u8 *)(p_lbl_1_bss_8B3A0->unk_A4 + 0x22) == 0) {
        v0 = fn_10_26000();
    } else {
        fn_1_14BD44(&lbl_10_bss_55CE0, (void *)p_lbl_1_bss_8B3A0->unk_9E);
        v0 = 0;
    }
    if (v0 != 0) return;
    if ((((0xFFFF) & (unk_0))) != 0xFFFF) return;
    if (((fn_10_4838_array_read_(lbl_1_bss_9F8)[lbl_1_bss_8B3A0.unk_9E].f8 >> 9) & 1) == 0) return;
    if (*(u8 *)(p_lbl_1_bss_8B3A0->unk_A4 + 0x22) != 0) {
        *(u8 *)(p_lbl_1_bss_8B3A0->unk_A4 + 0x22) = 0;
        return;
    }
    v9 = (s16)(lbl_10_bss_4938C.unk_0);
    lbl_10_bss_14.unk_0 = 15;
    fn_1_4A00(0, v9 & 0xFF, (void *)lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
    fn_1_12F17C();
}
#pragma opt_pointer_analysis reset

#pragma opt_lifetimes reset

#pragma opt_common_subs reset
/* fzgx:end fn_10_4838 */

/* fzgx:begin fn_10_4A84 */
extern s32 lbl_10_bss_51740;
extern s32 lbl_10_bss_49388;
extern void fn_1_435C(s32 value);
extern void fn_1_426C(s32 value);
extern void fn_10_260D4(void);

void fn_10_4A84(void) {
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    fn_10_260D4();
}
/* fzgx:end fn_10_4A84 */

/* fzgx:begin fn_10_4AE0 pool */
#include "rel/sel/sel.h"

extern u8 lbl_1_bss_8B3A0;
extern u32 lbl_1_bss_980[];
extern s16 lbl_1_bss_962;
typedef struct Sig_fn_1_152840_Entry {
    s16 id;
    u8 pad[2];
    u32 flags;
} Sig_fn_1_152840_Entry;
extern int fn_1_152840(s16, Sig_fn_1_152840_Entry *, s16, s16);
typedef struct {
    u16 unk0;
    u32 unk4;
    u8 unk8;
    u8 pad9[3];
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
} Sig_fn_1_12C0EC_FnData;
extern void fn_1_12C0EC(Sig_fn_1_12C0EC_FnData *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
s16 fzgx_obj_lbl_10_bss_18;
s16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C;
u8 lbl_10_bss_1C_fill_1D;
u16 lbl_10_bss_1C_fill_1E;
u32 lbl_10_bss_1C_fill_20[232];
u32 fzgx_obj_lbl_10_bss_3C0[74736];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_10_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_14;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_1A;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_1C;
    s = *(u8 *)&lbl_10_bss_1C_fill_1D;
    s = *(u8 *)&lbl_10_bss_1C_fill_1E;
    s = *(u8 *)&lbl_10_bss_1C_fill_20;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_3C0;
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
u32 fn_10_4AE0(u32 arg0, u32 initial_count) {
    s16 v0;
    s64 *mask;
    s64 masks[4];
    s16 *slot;
    s16 i;
    s16 selected;
    u32 arg1;
    u8 *base;
    u8 *p_lbl_10_bss_0;
    base = (u8 *)&lbl_1_bss_8B3A0;
    v0 = (s16)arg0;
    p_lbl_10_bss_0 = (u8 *)&fzgx_obj_lbl_10_bss_0;
    arg1 = initial_count;
    slot = (s16 *)(base + v0 * 32);
    selected = *(slot += 7);
    if (selected == -1) {
        if (*(u32 *)((u8 *)&lbl_1_bss_8B3A0 + 0x94) & 0x40000000)
            selected = ((s16 *)&lbl_10_data_55C)[v0];
        else
            selected = (&lbl_10_data_554)[v0];
    }
    mask = &masks[v0];
    *mask = 0;
    for (i = 0; i < 4; i++) {
        if ((s16)arg0 != i) {
            if ((s16)fn_1_152840(*(s16 *)((u8 *)&lbl_1_bss_8B3A0 + i * 32 + 14),
                 (Sig_fn_1_152840_Entry *)&fzgx_obj_lbl_10_bss_1C,
                 fzgx_obj_lbl_10_bss_1A, fzgx_obj_lbl_10_bss_18) == 1) {
                *mask |= (s32)(1 << *(s16 *)((u8 *)&lbl_1_bss_8B3A0 + i * 32 + 14));
            }
        }
    }
    if (lbl_1_bss_980[v0] == 0x09000000 ||
        lbl_1_bss_980[v0] == 0x88000000 ||
        lbl_1_bss_980[v0] == 0x8B100000 ||
        lbl_1_bss_980[v0] == 0x08000000 ||
        (s16)arg0 == *(u8 *)((u8 *)&lbl_1_bss_8B3A0 + 0x9E)) {
        if (*(s16 *)((u8 *)&lbl_1_bss_8B3A0 + 4) > (s16)arg1) {
            if (*(u32 *)((u8 *)&lbl_1_bss_8B3A0 + 0x94) & 0x10000000) {
                while (!(s16)fn_1_152840(selected,
                       (Sig_fn_1_152840_Entry *)&fzgx_obj_lbl_10_bss_1C,
                       fzgx_obj_lbl_10_bss_1A, fzgx_obj_lbl_10_bss_18) ||
                       ((((s32)(1 << selected)) & (*mask))) != 0) {
                    selected = (selected + 1) % 41;
                }
            }
            *slot = selected;
            arg1++;
        } else {
            *slot = -1;
            fn_1_12C0EC((Sig_fn_1_12C0EC_FnData *)(*(u8 **)((u8 *)&lbl_1_bss_8B3A0 + 0xA4) +
                (lbl_1_bss_962 - 14) * 0x94 + v0 * 0x1C + 0x24));
        }
    } else {
        *slot = -1;
        fn_1_12C0EC((Sig_fn_1_12C0EC_FnData *)(*(u8 **)((u8 *)&lbl_1_bss_8B3A0 + 0xA4) +
            (lbl_1_bss_962 - 14) * 0x94 + v0 * 0x1C + 0x24));
    }
    return arg1;
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset
/* fzgx:end fn_10_4AE0 */

/* fzgx:begin fn_10_5148 */
extern u8 lbl_10_bss_0[];
extern char lbl_10_data_6A4[11];
extern void fn_10_13D64(void);
extern void *fn_1_435C(void *);
extern void *fn_1_3F8C(void *, void *, u32, u32);
extern void fn_1_4A00(u32, u32, void *);

void fn_10_5148(void) {
    u8 *base = (u8 *)lbl_10_bss_0 + 0x50000;
    void *value;
    s16 flag;

    value = fn_1_435C(*(void **)(base - 0x6c78));
    value = fn_1_3F8C(lbl_10_data_6A4, fn_10_13D64, 0, 8);
    flag = *(s16 *)(base - 0x6c74);
    *(void **)(base + 0x1740) = value;
    fn_1_4A00(1, (u8)flag, *(void **)(base - 0x6c78));
    *(u32 *)(base + 0x1744) = 0;
}
/* fzgx:end fn_10_5148 */

/* fzgx:begin fn_10_51BC */
extern u16 lbl_1_bss_96A;

void fn_10_51BC(void) {
    lbl_1_bss_96A = 0x12;
}
/* fzgx:end fn_10_51BC */

/* fzgx:begin fn_10_51CC */
extern s32 lbl_10_bss_51740;
extern u32 lbl_10_bss_49388;
extern u8 lbl_1_bss_8B3A0;

extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern void fn_10_BEF8(void *value);

void fn_10_51CC(void) {
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    fn_10_BEF8(&lbl_1_bss_8B3A0);
}
/* fzgx:end fn_10_51CC */

/* fzgx:begin fn_10_5780 */
struct Fn105780 {
    u8 pad[0x92];
    u16 value;
};

void fn_10_5780(struct Fn105780 *obj) {
    obj->value = 8;
}
/* fzgx:end fn_10_5780 */

/* fzgx:begin fn_10_7320 */
extern char lbl_10_data_6FC[18];
extern void fn_10_1B658(void);
extern void *fn_1_435C(void *);
extern void *fn_1_3F8C(void *, void *, u32, u32);
extern void fn_1_12F1E8(s32);
extern void fn_1_4A00(u32, u32, void *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 fzgx_obj_lbl_10_bss_4EEC0[2592];
u32 fzgx_obj_lbl_10_bss_51740;
u32 fzgx_obj_lbl_10_bss_51744;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
    s = fzgx_obj_lbl_10_bss_3C0[0];
    s = fzgx_obj_lbl_10_bss_49380;
    s = fzgx_obj_lbl_10_bss_49384;
    s = fzgx_obj_lbl_10_bss_49388;
    s = fzgx_obj_lbl_10_bss_4938C;
    s = fzgx_obj_lbl_10_bss_4938E;
    s = fzgx_obj_lbl_10_bss_4938F;
    s = fzgx_obj_lbl_10_bss_49390[0];
    s = fzgx_obj_lbl_10_bss_493A0[0];
    s = fzgx_obj_lbl_10_bss_4EEC0[0];
    s = fzgx_obj_lbl_10_bss_51740;
    s = fzgx_obj_lbl_10_bss_51744;
}
#pragma section code_type ".text"

void fn_10_7320(void) {
    fn_1_4A00(1, (u8)fzgx_obj_lbl_10_bss_4938C, (void *)fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51744 = 0;
    fn_1_435C((void *)fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51740 = (u32)fn_1_3F8C(lbl_10_data_6FC, fn_10_1B658, 0, 8);
    fn_1_12F1E8(480);
    fzgx_obj_lbl_10_bss_14 = -1;
}
/* fzgx:end fn_10_7320 */

/* fzgx:begin fn_10_73AC */
struct S8B3A0 {
    u8 pad0[0x94];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[2];
    u8 unk_9E;
    u8 pad_9F[0xA1];
    u32 unk_140;
};
struct S9C8 {
    u8 pad0[0xA];
    s8 fA;
    u8 pad1[0xC - 0xB];
};
struct S9F8 {
    u8 pad0[8];
    u16 f8;
    u8 pad1[0x14 - 0xA];
};

extern s32 lbl_10_bss_14;
extern s16 lbl_10_bss_4938C;
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_51744;
extern u16 lbl_1_bss_96A;
extern struct S8B3A0 lbl_1_bss_8B3A0;
extern struct S9C8 lbl_1_bss_9C8[];
extern struct S9F8 lbl_1_bss_9F8[];

extern s32 fn_1_4C10(void);
extern void fn_10_CF30(u32);
extern void fn_1_12F150(s16, u32, u32);
extern s32 fn_1_12F228(void);
extern void fn_1_4A00(s32, u8, u32);

extern int __rlwnm(int, int, int, int);

void fn_10_73AC(void) {
    struct { struct S9C8 *p; } rows;
    /* volatile: the manager fields are re-read after each call in the loop */
    volatile struct S8B3A0 *base;
    s16 count = 0;
    s16 i;
    s32 *sp;
    s32 value;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    {
        u32 flags = lbl_1_bss_8B3A0.unk_140;
        s32 ready;

        if ((flags & 0x80000000) != 0 &&
            (flags & 0x40000000) == 0 &&
            (lbl_1_bss_8B3A0.unk_94 & 8) == 0) {
            ready = 1;
        } else {
            if (fn_1_4C10() != 0) {
                ready = 1;
            } else {
                ready = 0;
            }
        }

        if (ready != 0) {
            return;
        }
    }

    sp = &lbl_10_bss_14;
    if (*sp != -1) {
        value = *sp;
        *sp = -1;
        lbl_1_bss_96A = (u16)value;
        return;
    }

    rows.p = &lbl_1_bss_9C8[0];
    base = &lbl_1_bss_8B3A0;
    for (i = 0; i < 4;
         rows.p = (struct S9C8 *)((u8 *)rows.p + 0xC), i++) {
        if (rows.p->fA == -1) {
            continue;
        }

        if (__rlwnm(base->unk_98, (i + 1) & 31, 31, 31) == 0) {
            continue;
        }

        if (((lbl_1_bss_9F8[base->unk_9E].f8 >> 12) & 1) != 0) {
            count++;
        }

        if (((lbl_1_bss_9F8[base->unk_9E].f8 >> 12) & 1) != 0) {
            fn_1_12F150(i, 2, 1);
        }
    }

    if (count == 0 && fn_1_12F228() == 0) {
        return;
    }

    fn_10_CF30(0);
    lbl_10_bss_14 = 27;
    fn_1_4A00(0, (u8)lbl_10_bss_4938C, lbl_10_bss_49388);
    lbl_10_bss_51744 = 0;
}
/* fzgx:end fn_10_73AC */

/* fzgx:begin fn_10_757C */
// Volatile preserves the retail's repeated reads of the shared sentinel.
extern volatile s32 lbl_10_bss_51740;
extern u32 lbl_10_bss_49388;
extern void fn_1_435C(u32 value);
extern void fn_1_426C(s32 value);

void fn_10_757C(void) {
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
}
/* fzgx:end fn_10_757C */

/* fzgx:begin fn_10_7E84 */
extern u8 lbl_1_bss_8B3A0[];
extern u8 lbl_1_bss_6D82C[];
extern u8 lbl_10_bss_0[];

extern void fn_1_8F494(void *value);
extern s32 fn_1_12CB04(s16 value);
extern void fn_1_12C000(void *value, s32 arg);
extern void fn_1_435C(u32 value);
extern void fn_1_426C(s32 value);
extern void fn_10_96F8(void *value, s32 arg);
extern void fn_80071718(void *value);

#pragma opt_propagation on
static inline u8 *fn_10_7E84_array_read(u8 *array) { return array; }
static inline u8 fn_10_7E84_array_read_(u8 *array, s32 index) { return array[index]; }
#pragma opt_lifetimes off
void fn_10_7E84(void) {
    u8 *state;
    s16 index;
    u32 flags;
    u8 *rec;
    u8 *call_ptr;
    u8 *ptr;
    s32 i;
    u8 *base;
    s16 count;

    base = lbl_10_bss_0 + 0x50000;
    state = lbl_1_bss_8B3A0;
    index = fn_10_7E84_array_read_(state, 0x9e);
    flags = *(u32 *)(state + 0x94);
    rec = state + (index << 5);
    count = *(s16 *)(rec + 0xe);
    rec = (u8 *)((u32)rec + 0xe);

    if ((flags & (1u << 31)) == 0) {
        call_ptr = base + 0x1b7c;
        call_ptr += index * 0x4e0;
        fn_1_8F494(call_ptr);
        ptr = base + 0x2efc;
        ptr += index * 0x9c0;
        i = 0;
        while ((s16)i < (s16)fn_1_12CB04(count)) {
            fn_1_8F494(ptr);
            ptr += 0x4e0;
            i++;
        }
    }

    flags = *(u32 *)(state + 0x94);
    if ((flags & (1u << 31)) == 0) {
        fn_1_12C000(base + 0x17ec, 1);
        fn_1_12C000(base + 0x197c, 1);
    }

    if (*(s32 *)(base + 0x1740) != -1) {
        fn_1_435C(*(u32 *)(base - 0x6c78));
        fn_1_426C(*(s32 *)(base + 0x1740));
        *(s32 *)(base + 0x1740) = -1;
    }

    fn_10_96F8(base - 0x6c60, 0);
    if (*(void **)lbl_1_bss_6D82C != 0) {
        fn_80071718(*(void **)lbl_1_bss_6D82C);
        *(u32 **)lbl_1_bss_6D82C = 0;
    }

    *(s16 *)rec = -1;
    flags = *(u32 *)(state + 0x94);
    *(u32 *)(state + 0x94) = flags & 0xfffff7ff;
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_10_7E84 */

/* fzgx:begin fn_10_7FC0 */
extern char lbl_10_data_744[18];
extern void fn_10_1B65C(void);
extern void *fn_1_435C(void *);
extern void *fn_1_3F8C(void *, void *, u32, u32);
extern void fn_1_12F1E8(s32);
extern void fn_1_4A00(u32, u32, void *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 fzgx_obj_lbl_10_bss_4EEC0[2592];
u32 fzgx_obj_lbl_10_bss_51740;
u32 fzgx_obj_lbl_10_bss_51744;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
    s = fzgx_obj_lbl_10_bss_3C0[0];
    s = fzgx_obj_lbl_10_bss_49380;
    s = fzgx_obj_lbl_10_bss_49384;
    s = fzgx_obj_lbl_10_bss_49388;
    s = fzgx_obj_lbl_10_bss_4938C;
    s = fzgx_obj_lbl_10_bss_4938E;
    s = fzgx_obj_lbl_10_bss_4938F;
    s = fzgx_obj_lbl_10_bss_49390[0];
    s = fzgx_obj_lbl_10_bss_493A0[0];
    s = fzgx_obj_lbl_10_bss_4EEC0[0];
    s = fzgx_obj_lbl_10_bss_51740;
    s = fzgx_obj_lbl_10_bss_51744;
}
#pragma section code_type ".text"

void fn_10_7FC0(void) {
    fn_1_435C((void *)fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51740 = (u32)fn_1_3F8C(lbl_10_data_744, fn_10_1B65C, 0, 8);
    fn_1_12F1E8(480);
    fn_1_4A00(1, (u8)fzgx_obj_lbl_10_bss_4938C, (void *)fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51744 = 0;
    fzgx_obj_lbl_10_bss_14 = -1;
}
/* fzgx:end fn_10_7FC0 */

/* fzgx:begin fn_10_804C */
struct fn_10_804C_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[2];
    u8 unk_9E;
    u8 pad_9F[0xA1];
    u32 unk_140;
};
struct S9F8 {
    u8 pad0[8];
    u16 f8;
    u8 pad1[10];
};
struct S9C8 {
    u8 pad0[10];
    s8 fA;
    u8 fB;
};
extern s32 lbl_10_bss_14;
extern s16 lbl_10_bss_4938C;
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_51744;
extern int fn_1_4C10(void);
extern struct fn_10_804C_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern u16 lbl_1_bss_96A;
extern s32 fn_1_12F228(void);
extern void fn_1_4A00(s32, u32, u32);
extern u32 lbl_1_bss_6EAB4;
extern struct S9F8 lbl_1_bss_9F8[];
extern struct S9C8 lbl_1_bss_9C8[];
extern void fn_1_12F150(s32, u32, u32);
extern void fn_1_12F1E8(s32);

void fn_10_804C(void) {
    u16 *v6;
    struct fn_10_804C_lbl_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    u32 v0;
    struct { int value; } v1;
    s32 v7;
    s32 v3;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    v0 = lbl_1_bss_8B3A0.unk_140;
    if ((v0 & 0x80000000) != 0 && (0x40000000 & v0) == 0 &&
        (lbl_1_bss_8B3A0.unk_94 & 8) == 0) {
        v1.value = 1;
    } else if (fn_1_4C10() != 0) {
        v1.value = 1;
    } else {
        v1.value = 0;
    }
    if (v1.value == 0) {
        if (lbl_10_bss_14 != -1) {
            s32 state = lbl_10_bss_14;
            lbl_10_bss_14 = -1;
            lbl_1_bss_96A = (u16)state;
        } else {
            v3 = 0;
#define p_lbl_1_bss_8B3A0 (&lbl_1_bss_8B3A0)
            while ((s16)v3 < 4) {
                if (lbl_1_bss_9C8[v3].fA != -1 &&
                    __rlwnm(p_lbl_1_bss_8B3A0->unk_98, ((s16)v3 + 1) & 31, 31, 31) &&
                    ((lbl_1_bss_9F8[p_lbl_1_bss_8B3A0->unk_9E].f8 >> 8) & 1)) {
                    fn_1_12F150(v3, 2, 1);
                }
                v3++;
            }
            v6 = &lbl_1_bss_9F8[0].f8;
            if ((*(u16 *)((u8 *)v6 + p_lbl_1_bss_8B3A0->unk_9E * 20) >> 8) & 1) {
                fn_1_12F1E8(0);
            }
            v7 = 0;
            while ((s16)v7 < 4) {
                if (lbl_1_bss_9C8[v7].fA != -1 &&
                    __rlwnm(p_lbl_1_bss_8B3A0->unk_98, ((s16)v7 + 1) & 31, 31, 31) &&
                    ((lbl_1_bss_9F8[p_lbl_1_bss_8B3A0->unk_9E].f8 >> 12) & 1)) {
                    fn_1_12F150(v7, 2, 1);
                }
                v7++;
            }
            if (((*(u16 *)((u8 *)v6 + p_lbl_1_bss_8B3A0->unk_9E * 20) >> 12) & 1) ||
                fn_1_12F228() != 0) {
                lbl_10_bss_14 = 24;
                fn_1_12F1E8(0);
                fn_1_4A00(0, (u8)lbl_10_bss_4938C, lbl_10_bss_49388);
                lbl_10_bss_51744 = 0;
                if (lbl_10_bss_14 == 14) {
                    lbl_1_bss_6EAB4 |= 36;
                }
            }
        }
    }
}
/* fzgx:end fn_10_804C */

/* fzgx:begin fn_10_82BC */
extern s32 lbl_10_bss_51740;
extern u32 lbl_10_bss_49388;

extern void fn_1_435C(u32 value);
extern void fn_1_426C(s32 value);

void fn_10_82BC(void) {
    s32 state = lbl_10_bss_51740;

    if (state != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
}
/* fzgx:end fn_10_82BC */

/* fzgx:begin fn_10_8314 */
#include "rel/sel/sel.h"

typedef struct SelWork {
    u8 pad_0[0x14];
    s32 unk_14;
} SelWork;

typedef struct SelState {
    u8 pad_0[0x9E];
    u8 unk_9E;
    u8 pad_9F[0x129 - 0x9F];
    u8 unk_129;
} SelState;

extern SelState lbl_1_bss_8B3A0;
extern void fn_10_1B664(void);
extern void fn_1_435C(u32 value);
extern s32 fn_1_3F8C(void *, void (*)(void), u32, u32);
extern void fn_1_12F1E8(s32 value);
extern void fn_1_4A00(s32 value, u32 arg1, u32 arg2);
extern u32 fn_10_25610(u32 arg0, u32 arg1, u32 arg2);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 fzgx_obj_lbl_10_bss_4EEC0[2592];
u32 fzgx_obj_lbl_10_bss_51740;
u32 fzgx_obj_lbl_10_bss_51744;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
    s = fzgx_obj_lbl_10_bss_3C0[0];
    s = fzgx_obj_lbl_10_bss_49380;
    s = fzgx_obj_lbl_10_bss_49384;
    s = fzgx_obj_lbl_10_bss_49388;
    s = fzgx_obj_lbl_10_bss_4938C;
    s = fzgx_obj_lbl_10_bss_4938E;
    s = fzgx_obj_lbl_10_bss_4938F;
    s = fzgx_obj_lbl_10_bss_49390[0];
    s = fzgx_obj_lbl_10_bss_493A0[0];
    s = fzgx_obj_lbl_10_bss_4EEC0[0];
    s = fzgx_obj_lbl_10_bss_51740;
    s = fzgx_obj_lbl_10_bss_51744;
}
#pragma section code_type ".text"

void fn_10_8314(void) {
    SelState *state;
    u32 arg0;
    u32 arg1;

    fn_1_435C(fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51740 = fn_1_3F8C(lbl_10_data_758, fn_10_1B664, 0, 8);
    fn_1_12F1E8(3600);
    fn_1_4A00(1, (u8)fzgx_obj_lbl_10_bss_4938C, fzgx_obj_lbl_10_bss_49388);
    state = &lbl_1_bss_8B3A0;
    fzgx_obj_lbl_10_bss_51744 = 0;
    arg0 = fzgx_obj_lbl_10_bss_49384;
    fzgx_obj_lbl_10_bss_14 = -1;
    arg1 = fzgx_obj_lbl_10_bss_49388;
    state->unk_129 = 1;
    fn_10_25610(arg0, arg1, state->unk_9E);
}
/* fzgx:end fn_10_8314 */

/* fzgx:begin fn_10_83C0 */
typedef struct SelState {
    u8 pad_0[0x94];
    u32 flags_94;
    u8 pad_98[0x91];
    u8 field_129;
    u8 pad_12A[0x16];
    u32 field_140;
} SelState;

extern s32 lbl_10_bss_14;
extern SelState lbl_1_bss_8B3A0;
extern u16 lbl_1_bss_96A;
extern s16 lbl_10_bss_4938C;
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_51744;

extern s32 fn_1_4C10(void);
extern s32 fn_1_12F228(void);
extern void fn_1_12F1E8(s32 value);
extern void fn_1_4A00(s32 value, u32 arg1, u32 arg2);
extern void fn_10_25CB0(void);
extern s32 fn_10_25888(void);

void fn_10_83C0(void) {
    s32 ready;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    if ((lbl_1_bss_8B3A0.field_140 & ((u32)1 << 31)) != 0 &&
        (lbl_1_bss_8B3A0.field_140 & 0x40000000) == 0 &&
        (lbl_1_bss_8B3A0.flags_94 & 0x8) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready == 0) {
        if (lbl_10_bss_14 != -1) {
            s32 state = lbl_10_bss_14;
            lbl_10_bss_14 = -1;
            lbl_1_bss_96A = (u16)state;
        } else {
            if (fn_1_12F228() != 0) {
                fn_1_12F1E8(0);
                fn_10_25CB0();
            }
            if (fn_10_25888() != 0) {
                lbl_1_bss_8B3A0.field_129 = 0;
                fn_1_12F1E8(0);
                fn_1_4A00(0, (u32)(u8)lbl_10_bss_4938C, lbl_10_bss_49388);
                lbl_10_bss_51744 = 0;
                lbl_10_bss_14 = 0x19;
            }
        }
    }
}
/* fzgx:end fn_10_83C0 */

/* fzgx:begin fn_10_84DC */
extern void fn_10_25BC8(void);
extern void fn_1_435C(u32 value);
extern void fn_1_426C(u32 value);
extern u32 lbl_10_bss_51740;
extern u32 lbl_10_bss_49388;

void fn_10_84DC(void) {
    fn_10_25BC8();
    if ((s32)lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = (u32)-1;
    }
}
/* fzgx:end fn_10_84DC */

/* fzgx:begin fn_10_8538 */
typedef struct {
    u8 pad[0xa4];
    u8 *ptr;
} BssObject;

extern u8 lbl_10_bss_0[];
extern char lbl_10_data_76C[25];
extern void fn_10_1B684(void);
extern BssObject lbl_1_bss_8B3A0;
extern void *lbl_1_bss_6EAD0;

extern void fn_1_435C(u32 value);
extern void *fn_1_3F8C(void *arg0, void *arg1, u32 arg2, u32 arg3);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);
extern void *fn_1_12F1E8(u32 size);
extern void fn_1_A176C(void *arg0, u32 arg1);

#pragma opt_propagation off
void fn_10_8538(void) {
    u8 *work = lbl_10_bss_0 + 0x50000;
    u8 *base = lbl_10_bss_0;
    u32 value;

    fn_1_435C(((u32 *)work)[(-0x6c78) / 4]);
    value = (u32)fn_1_3F8C(lbl_10_data_76C, fn_10_1B684, 0, 8);
    ((u32 *)work)[0x1740 / 4] = value;
    fn_1_4A00(1, (u8)((s16 *)work)[(-0x6c74) / 2], ((u32 *)work)[(-0x6c78) / 4]);
    ((u32 *)work)[0x1744 / 4] = 0;
    fn_1_12F1E8(0x384);
    lbl_1_bss_8B3A0.ptr[0x19] = 0;
    ((u32 *)base)[0x14 / 4] = (u32)-1;
    fn_1_A176C(*(void **)lbl_1_bss_6EAD0, 0x1f);
    work[0x5600] = 0xb4;
    work[0x5601] = 0;
}
#pragma opt_propagation reset
/* fzgx:end fn_10_8538 */

/* fzgx:begin fn_10_8600 pool */
typedef struct {
    u8 pad0[0x14];
    s32 state;
} SelState;

typedef struct {
    u8 *value;
} WorkBox;

typedef struct {
    u8 pad0[0x94];
    u32 flags94;
    u8 pad98[0xc];
    u8 *object;
    u8 padA8[0x98];
    u32 flags140;
} GlobalSel;

extern GlobalSel lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_96A;
extern u32 lbl_1_bss_6EAB4;

extern s32 fn_1_4C10(void);
extern u8 fn_1_D6688(void);
extern u32 fn_1_12F258(void);
extern void fn_1_A2D84(u32);
extern s32 fn_1_12F228(void);
extern void fn_1_4A00(u32, u32, u32);
extern u8 fn_10_8780(void);

#pragma opt_propagation on
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
s32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 fzgx_obj_lbl_10_bss_4EEC0[2592];
u32 fzgx_obj_lbl_10_bss_51740;
u32 fzgx_obj_lbl_10_bss_51744;
u8 fzgx_obj_lbl_10_bss_51748[6];
u16 fzgx_obj_lbl_10_bss_5174E;
u8 fzgx_obj_lbl_10_bss_51750;
u8 fzgx_pad_51751;
u8 fzgx_obj_lbl_10_bss_51752;
u8 fzgx_obj_lbl_10_bss_51752__b1;
u8 fzgx_obj_lbl_10_bss_51752__b2;
u8 fzgx_obj_lbl_10_bss_51752__b3;
u8 fzgx_obj_lbl_10_bss_51752__b4;
u8 fzgx_obj_lbl_10_bss_51752__b5;
u8 fzgx_obj_lbl_10_bss_51752__b6;
u8 fzgx_obj_lbl_10_bss_51752__b7;
u8 fzgx_obj_lbl_10_bss_51752__b8;
u8 fzgx_obj_lbl_10_bss_51752__b9;
u8 fzgx_obj_lbl_10_bss_51752__b10;
u8 fzgx_obj_lbl_10_bss_51752__b11;
u8 fzgx_obj_lbl_10_bss_51752__b12;
u8 fzgx_obj_lbl_10_bss_51752__b13;
u8 fzgx_obj_lbl_10_bss_51752__b14;
u8 fzgx_obj_lbl_10_bss_51752__b15;
u8 fzgx_obj_lbl_10_bss_51752__b16;
u8 fzgx_obj_lbl_10_bss_51752__b17;
u8 fzgx_obj_lbl_10_bss_51752__b18;
u8 fzgx_obj_lbl_10_bss_51752__b19;
u8 fzgx_obj_lbl_10_bss_51752__b20;
u8 fzgx_obj_lbl_10_bss_51752__b21;
u8 fzgx_obj_lbl_10_bss_51752__b22;
u8 fzgx_obj_lbl_10_bss_51752__b23;
u8 fzgx_obj_lbl_10_bss_51752__b24;
u8 fzgx_obj_lbl_10_bss_51752__b25;
u8 fzgx_obj_lbl_10_bss_51752__b26;
u8 fzgx_obj_lbl_10_bss_51752__b27;
u8 fzgx_obj_lbl_10_bss_51752__b28;
u8 fzgx_obj_lbl_10_bss_51752__b29;
u8 fzgx_obj_lbl_10_bss_51752__b30;
u8 fzgx_obj_lbl_10_bss_51752__b31;
u8 fzgx_obj_lbl_10_bss_51752__b32;
u8 fzgx_obj_lbl_10_bss_51752__b33;
u8 fzgx_obj_lbl_10_bss_51752__b34;
u8 fzgx_obj_lbl_10_bss_51752__b35;
u8 fzgx_obj_lbl_10_bss_51752__b36;
u8 fzgx_obj_lbl_10_bss_51752__b37;
u8 fzgx_obj_lbl_10_bss_51752__b38;
u8 fzgx_obj_lbl_10_bss_51752__b39;
u8 fzgx_obj_lbl_10_bss_51752__b40;
u8 fzgx_obj_lbl_10_bss_51752__b41;
u8 fzgx_obj_lbl_10_bss_51752__b42;
u8 fzgx_obj_lbl_10_bss_51752__b43;
u8 fzgx_obj_lbl_10_bss_51752__b44;
u8 fzgx_obj_lbl_10_bss_51752__b45;
u8 fzgx_obj_lbl_10_bss_51752__b46;
u8 fzgx_obj_lbl_10_bss_51752__b47;
u8 fzgx_obj_lbl_10_bss_51752__b48;
u8 fzgx_obj_lbl_10_bss_51752__b49;
u8 fzgx_obj_lbl_10_bss_51752__b50;
u8 fzgx_obj_lbl_10_bss_51752__b51;
u8 fzgx_obj_lbl_10_bss_51752__b52;
u8 fzgx_obj_lbl_10_bss_51752__b53;
u32 fzgx_obj_lbl_10_bss_51788[25];
u32 fzgx_obj_lbl_10_bss_517EC[100];
u32 fzgx_obj_lbl_10_bss_5197C[128];
u32 fzgx_obj_lbl_10_bss_51B7C[1248];
u32 fzgx_obj_lbl_10_bss_52EFC[2496];
u32 fzgx_obj_lbl_10_bss_555FC;
u8 fzgx_obj_lbl_10_bss_55600;
u8 fzgx_obj_lbl_10_bss_55601;
u8 lbl_10_bss_55601__fzgx_offset_1;
u8 lbl_10_bss_55601__fzgx_offset_1__b1;
u8 lbl_10_bss_55601__fzgx_offset_1__b2;
u8 lbl_10_bss_55601__fzgx_offset_1__b3;
u8 lbl_10_bss_55601__fzgx_offset_1__b4;
u8 lbl_10_bss_55601__fzgx_offset_1__b5;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
    s = fzgx_obj_lbl_10_bss_3C0[0];
    s = fzgx_obj_lbl_10_bss_49380;
    s = fzgx_obj_lbl_10_bss_49384;
    s = fzgx_obj_lbl_10_bss_49388;
    s = fzgx_obj_lbl_10_bss_4938C;
    s = fzgx_obj_lbl_10_bss_4938E;
    s = fzgx_obj_lbl_10_bss_4938F;
    s = fzgx_obj_lbl_10_bss_49390[0];
    s = fzgx_obj_lbl_10_bss_493A0[0];
    s = fzgx_obj_lbl_10_bss_4EEC0[0];
    s = fzgx_obj_lbl_10_bss_51740;
    s = fzgx_obj_lbl_10_bss_51744;
    s = fzgx_obj_lbl_10_bss_51748[0];
    s = fzgx_obj_lbl_10_bss_5174E;
    s = fzgx_obj_lbl_10_bss_51750;
    s = fzgx_pad_51751;
    s = fzgx_obj_lbl_10_bss_51752;
    s = fzgx_obj_lbl_10_bss_51752__b1;
    s = fzgx_obj_lbl_10_bss_51752__b2;
    s = fzgx_obj_lbl_10_bss_51752__b3;
    s = fzgx_obj_lbl_10_bss_51752__b4;
    s = fzgx_obj_lbl_10_bss_51752__b5;
    s = fzgx_obj_lbl_10_bss_51752__b6;
    s = fzgx_obj_lbl_10_bss_51752__b7;
    s = fzgx_obj_lbl_10_bss_51752__b8;
    s = fzgx_obj_lbl_10_bss_51752__b9;
    s = fzgx_obj_lbl_10_bss_51752__b10;
    s = fzgx_obj_lbl_10_bss_51752__b11;
    s = fzgx_obj_lbl_10_bss_51752__b12;
    s = fzgx_obj_lbl_10_bss_51752__b13;
    s = fzgx_obj_lbl_10_bss_51752__b14;
    s = fzgx_obj_lbl_10_bss_51752__b15;
    s = fzgx_obj_lbl_10_bss_51752__b16;
    s = fzgx_obj_lbl_10_bss_51752__b17;
    s = fzgx_obj_lbl_10_bss_51752__b18;
    s = fzgx_obj_lbl_10_bss_51752__b19;
    s = fzgx_obj_lbl_10_bss_51752__b20;
    s = fzgx_obj_lbl_10_bss_51752__b21;
    s = fzgx_obj_lbl_10_bss_51752__b22;
    s = fzgx_obj_lbl_10_bss_51752__b23;
    s = fzgx_obj_lbl_10_bss_51752__b24;
    s = fzgx_obj_lbl_10_bss_51752__b25;
    s = fzgx_obj_lbl_10_bss_51752__b26;
    s = fzgx_obj_lbl_10_bss_51752__b27;
    s = fzgx_obj_lbl_10_bss_51752__b28;
    s = fzgx_obj_lbl_10_bss_51752__b29;
    s = fzgx_obj_lbl_10_bss_51752__b30;
    s = fzgx_obj_lbl_10_bss_51752__b31;
    s = fzgx_obj_lbl_10_bss_51752__b32;
    s = fzgx_obj_lbl_10_bss_51752__b33;
    s = fzgx_obj_lbl_10_bss_51752__b34;
    s = fzgx_obj_lbl_10_bss_51752__b35;
    s = fzgx_obj_lbl_10_bss_51752__b36;
    s = fzgx_obj_lbl_10_bss_51752__b37;
    s = fzgx_obj_lbl_10_bss_51752__b38;
    s = fzgx_obj_lbl_10_bss_51752__b39;
    s = fzgx_obj_lbl_10_bss_51752__b40;
    s = fzgx_obj_lbl_10_bss_51752__b41;
    s = fzgx_obj_lbl_10_bss_51752__b42;
    s = fzgx_obj_lbl_10_bss_51752__b43;
    s = fzgx_obj_lbl_10_bss_51752__b44;
    s = fzgx_obj_lbl_10_bss_51752__b45;
    s = fzgx_obj_lbl_10_bss_51752__b46;
    s = fzgx_obj_lbl_10_bss_51752__b47;
    s = fzgx_obj_lbl_10_bss_51752__b48;
    s = fzgx_obj_lbl_10_bss_51752__b49;
    s = fzgx_obj_lbl_10_bss_51752__b50;
    s = fzgx_obj_lbl_10_bss_51752__b51;
    s = fzgx_obj_lbl_10_bss_51752__b52;
    s = fzgx_obj_lbl_10_bss_51752__b53;
    s = fzgx_obj_lbl_10_bss_51788[0];
    s = fzgx_obj_lbl_10_bss_517EC[0];
    s = fzgx_obj_lbl_10_bss_5197C[0];
    s = fzgx_obj_lbl_10_bss_51B7C[0];
    s = fzgx_obj_lbl_10_bss_52EFC[0];
    s = fzgx_obj_lbl_10_bss_555FC;
    s = fzgx_obj_lbl_10_bss_55600;
    s = fzgx_obj_lbl_10_bss_55601;
    s = lbl_10_bss_55601__fzgx_offset_1;
    s = lbl_10_bss_55601__fzgx_offset_1__b1;
    s = lbl_10_bss_55601__fzgx_offset_1__b2;
    s = lbl_10_bss_55601__fzgx_offset_1__b3;
    s = lbl_10_bss_55601__fzgx_offset_1__b4;
    s = lbl_10_bss_55601__fzgx_offset_1__b5;
}
#pragma section code_type ".text"

void fn_10_8600(void) {
    u8 result;
    s32 ready;
    u8 *obj;

    if (fzgx_obj_lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    if ((lbl_1_bss_8B3A0.flags140 & 0x80000000) != 0 &&
        (lbl_1_bss_8B3A0.flags140 & 0x40000000) == 0 &&
        (lbl_1_bss_8B3A0.flags94 & 8) == 0) {
        ready = 1;
    } else {
        if (fn_1_4C10() != 0) {
            ready = 1;
        } else {
            ready = 0;
        }
    }

    if (ready == 0) {
        if (fzgx_obj_lbl_10_bss_14 != -1) {
            s16 value = (s16)fzgx_obj_lbl_10_bss_14;
            fzgx_obj_lbl_10_bss_14 = -1;
            lbl_1_bss_96A = value;
        } else {
            result = fn_1_D6688();
            if (result != 0 || fzgx_obj_lbl_10_bss_55600 < 0xb4) {
                if (fzgx_obj_lbl_10_bss_55600 != 0) {
                    fzgx_obj_lbl_10_bss_55600--;
                }
            }
            if (fn_1_12F258() == 0x12c) {
                fn_1_A2D84(0xA9122100u);
            }
            if (fn_1_12F228() != 0) {
                fzgx_obj_lbl_10_bss_55601 = 1;
                obj = lbl_1_bss_8B3A0.object;
                obj[0x19] = 1;
                if (result == 0) {
                    if (fzgx_obj_lbl_10_bss_55600 != 0) {
                        return;
                    }
                }
                if (fn_10_8780() != 0) {
                    fzgx_obj_lbl_10_bss_14 = 0xf;
                    fn_1_4A00(0, (u8)fzgx_obj_lbl_10_bss_4938C, fzgx_obj_lbl_10_bss_49388);
                    fzgx_obj_lbl_10_bss_51744 = 0;
                    lbl_1_bss_6EAB4 |= 0x24;
                }
            }
        }
    }
}
/* fzgx:end fn_10_8600 */

/* fzgx:begin fn_10_8780 */
extern u8 lbl_10_bss_55601[7];
extern u8 lbl_10_bss_55600;
extern int fn_1_4C10(void);
extern u8 fn_1_D66A8(void);
extern u8 fn_1_D66A0(int);

u8 fn_10_8780(void) {
    if (fn_1_4C10() != 0) {
        return 1;
    }
    if (lbl_10_bss_55601[0] == 0) {
        return 0;
    }
    if (fn_1_D66A8() == 0) {
        if (fn_1_D66A0(0x10) == 0) {
            /* Retail converges both failure paths here. */
            goto fail;
        }
    }
    if (lbl_10_bss_55600 == 0) {
        /* Retail places the success block after the failure block. */
        goto success;
    }
fail:
    return 0;
success:
    return 1;
}
/* fzgx:end fn_10_8780 */

/* fzgx:begin fn_10_8800 */
extern s32 lbl_10_bss_51740;
extern u32 lbl_10_bss_49388;
extern u32 *lbl_1_bss_6EAD0;

extern void fn_1_435C(u32 value);
extern void fn_1_426C(s32 value);
extern void fn_1_A176C(u32 value, int arg);

void fn_10_8800(void) {
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    fn_1_A176C(*lbl_1_bss_6EAD0, 0x2d);
}
/* fzgx:end fn_10_8800 */

/* fzgx:begin fn_10_8870 */
typedef struct Sig_ADXT_Stop_ADXTHandle Sig_ADXT_Stop_ADXTHandle;

typedef struct {
    u8 pad0[12];
    s32 unk_14;
    u8 pad18[0x49370];
    u32 unk_49388;
    s16 unk_4938C;
    u8 pad4938E[0x83B2];
    s32 unk_51740;
    s32 unk_51744;
} SelState;

typedef struct {
    u8 pad0[0xa4];
    u8 *unk_a4;
} SelCtl;

extern SelCtl lbl_1_bss_8B3A0;
extern Sig_ADXT_Stop_ADXTHandle **lbl_1_bss_6EAD0;

extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, void (*)(void), s32, s32);
extern void fn_1_4A00(s32, u8, void *);
extern void fn_1_12F1E8(s32);
extern void fn_10_1B6A8(void);
extern void fn_1_A176C(Sig_ADXT_Stop_ADXTHandle *, u32);
extern void fn_1_47F74(s32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
s32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 lbl_10_bss_4EEC0[2592];
s32 fzgx_obj_lbl_10_bss_51740;
s32 fzgx_obj_lbl_10_bss_51744;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_10_bss_0;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_14;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_1A;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_1C;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_3C0;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49380;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49384;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49388;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_4938C;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_4938E;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_4938F;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_49390;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_493A0;
    s = *(u8 *)&lbl_10_bss_4EEC0;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_51740;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_51744;
}
#pragma section code_type ".text"

extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("SelChallengerWaitDisp");
}
#pragma section code_type ".text"

void fn_10_8870(void) {
    s32 lab_t0;

    fn_1_435C(fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51740 = fn_1_3F8C("SelChallengerWaitDisp", fn_10_1B6A8, 0, 8);
    fn_1_4A00(1, (u8)fzgx_obj_lbl_10_bss_4938C, (void *)fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51744 = 0;
    lab_t0 = 0x384;
    fn_1_12F1E8(lab_t0);
    ((u8 *)lbl_1_bss_8B3A0.unk_a4)[0x19] = 0;
    fzgx_obj_lbl_10_bss_14 = -1;
    fn_1_A176C(*lbl_1_bss_6EAD0, 0x1f);
    fn_1_47F74(2);
}
/* fzgx:end fn_10_8870 */

/* fzgx:begin fn_10_8930 */
typedef struct SelState {
    s16 state;
    u8 pad2[0x92];
    u32 flags;
    u8 pad98[6];
    u8 mode;
    u8 pad9f[0xa1];
    u32 unk140;
} SelState;

typedef struct SelEntry {
    u8 pad0[8];
    u16 flags;
    u8 pad0a[0xa];
} SelEntry;

extern s32 lbl_10_bss_14;
extern SelState lbl_1_bss_8B3A0;
extern SelEntry lbl_1_bss_9F8[];
extern s16 lbl_1_bss_96A;
extern s16 lbl_10_bss_4938C;
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_51744;
extern u32 lbl_1_bss_6EAB4;

extern s32 fn_1_4C10(void);
extern void fn_10_BD64(void *value);
extern s32 fn_1_12F228(void);
extern s32 fn_1_D66A0(u32 arg);
extern void fn_1_4A00(u32 arg0, u32 arg1, u32 arg2);

void fn_10_8930(void) {
    s32 ready;
    u32 flags;
    SelState *st;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    flags = lbl_1_bss_8B3A0.unk140;
    if ((flags & 0x80000000) != 0 &&
        (flags & 0x40000000) == 0 &&
        (lbl_1_bss_8B3A0.flags & 8) == 0) {
        ready = 1;
    } else {
        if (fn_1_4C10() != 0) {
            ready = 1;
        } else {
            ready = 0;
        }
    }

    if (ready != 0) {
        return;
    }

    if (lbl_10_bss_14 != -1) {
        s32 value = lbl_10_bss_14;
        lbl_10_bss_14 = -1;
        lbl_1_bss_96A = (s16)value;
        return;
    }

    st = &lbl_1_bss_8B3A0;
    if (((lbl_1_bss_9F8[*(u8 *)((u8 *)st + 0x9e)].flags >> 12) & 1) != 0) {
        st->state = 9;
        fn_10_BD64(st);
        lbl_10_bss_14 = 0x1a;
        fn_1_4A00(0, (u32)(lbl_10_bss_4938C & 0xff), lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        if (lbl_10_bss_14 != 0x15) {
            lbl_1_bss_6EAB4 |= 0x24;
        }
    } else if (fn_1_12F228() != 0 &&
               ((u8)fn_1_D66A0(0xd)) == 0 &&
               ((u8)fn_1_D66A0(0xf)) == 0) {
        lbl_1_bss_8B3A0.flags |= 0x4000000;
    }
}
/* fzgx:end fn_10_8930 */

/* fzgx:begin fn_10_8AAC */
extern s32 lbl_10_bss_51740;
extern u32 lbl_10_bss_49388;

extern void fn_1_48140(s32 arg0);
extern void fn_1_435C(u32 arg0);
extern void fn_1_426C(s32 arg0);

void fn_10_8AAC(void) {
    fn_1_48140(2);
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
}
/* fzgx:end fn_10_8AAC */

/* fzgx:begin fn_10_8B0C */
#include "rel/sel/sel.h"

extern void fn_1_435C(u32);
extern s32 fn_1_3F8C(void *, u32 (*)(void), u32, u32);
extern u32 fn_10_1B2F4(void);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_12F1E8(s32);
extern void fn_1_A2D84(u32);
typedef struct { u8 pad[0x94]; u32 flags; } SelGlobal;
extern SelGlobal lbl_1_bss_8B3A0;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 fzgx_obj_lbl_10_bss_4EEC0[2592];
u32 fzgx_obj_lbl_10_bss_51740;
u32 fzgx_obj_lbl_10_bss_51744;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
    s = fzgx_obj_lbl_10_bss_3C0[0];
    s = fzgx_obj_lbl_10_bss_49380;
    s = fzgx_obj_lbl_10_bss_49384;
    s = fzgx_obj_lbl_10_bss_49388;
    s = fzgx_obj_lbl_10_bss_4938C;
    s = fzgx_obj_lbl_10_bss_4938E;
    s = fzgx_obj_lbl_10_bss_4938F;
    s = fzgx_obj_lbl_10_bss_49390[0];
    s = fzgx_obj_lbl_10_bss_493A0[0];
    s = fzgx_obj_lbl_10_bss_4EEC0[0];
    s = fzgx_obj_lbl_10_bss_51740;
    s = fzgx_obj_lbl_10_bss_51744;
}
#pragma section code_type ".text"

void fn_10_8B0C(void) {
    fn_1_435C(fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51740 = fn_1_3F8C(lbl_10_data_7A0, fn_10_1B2F4, 0, 8);
    fn_1_4A00(1, (u8)fzgx_obj_lbl_10_bss_4938C, fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51744 = 0;
    fzgx_obj_lbl_10_bss_14 = -1;
    fn_1_12F1E8(0x1e0);
    lbl_1_bss_8B3A0.flags |= 0x800;
    fn_1_A2D84(0xa9121500);
}
/* fzgx:end fn_10_8B0C */

/* fzgx:begin fn_10_8BB8 */
struct S14 {
    u32 f;
};
extern struct S14 lbl_10_bss_14;
extern s16 lbl_10_bss_4938C;
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_51744;

struct fn_10_8BB8_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[2];
    u8 unk_9E;
    u8 pad_9F[0xA1];
    u32 unk_140;
};
struct S9F8 {
    u8 pad0[8];
    u16 f8;
    u8 pad1[0xA];
};
extern struct fn_10_8BB8_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct S9F8 lbl_1_bss_9F8[];
extern u8 lbl_1_bss_9C8[];
extern u16 lbl_1_bss_96A;
extern int fn_1_4C10(void);
extern s32 fn_1_12F258(void);
extern u32 fn_1_12F228(void);
extern void fn_1_12F150(s16, u32, u32);
extern void fn_1_12F1E8(s32);
extern void fn_1_4A00(s32, u8, void *);

#pragma opt_common_subs off
static inline struct S9F8 *fn_10_8BB8_array_read(struct S9F8 *array) { return array; }
#pragma opt_dead_assignments off
void fn_10_8BB8(void) {
    struct { struct fn_10_8BB8_lbl_1_bss_8B3A0 *value; } p_lbl_1_bss_8B3A0;
    struct { u8 *value; } p_lbl_1_bss_9C8;
    u32 v0;
    int v1;
    u32 v2;
    s16 v3;
    s16 v4 = 0;
    struct S14 *p14;

    if ((s32)lbl_10_bss_14.f == -1) {
        fn_1_4C10();
    }
    v0 = lbl_1_bss_8B3A0.unk_140;
    if ((v0 & 0x80000000) != 0 && (v0 & 0x40000000) == 0 &&
        (lbl_1_bss_8B3A0.unk_94 & 8) == 0) {
        v1 = 1;
    } else {
        if (fn_1_4C10() != 0) v1 = 1;
        else v1 = 0;
    }
    if (v1 != 0) return;
    p14 = &lbl_10_bss_14;
    if ((s32)p14->f != -1) {
        lbl_1_bss_96A = (u16)p14->f;
        p14->f = -1;
        return;
    }
    {
    s16 fzgx_loop_v3_1334;
    p_lbl_1_bss_9C8.value = (u8 *)&lbl_1_bss_9C8;
    p_lbl_1_bss_8B3A0.value = &lbl_1_bss_8B3A0;
    fzgx_loop_v3_1334 = 0;
    while ((s16)fzgx_loop_v3_1334 < 4) {
        if ((s8)p_lbl_1_bss_9C8.value[fzgx_loop_v3_1334 * 12 + 10] != -1 &&
            __rlwnm(p_lbl_1_bss_8B3A0.value->unk_98, ((s16)fzgx_loop_v3_1334 + 1) & 31, 31, 31) != 0) {
            if (((fn_10_8BB8_array_read(lbl_1_bss_9F8)[p_lbl_1_bss_8B3A0.value->unk_9E].f8 >> 8) & 1) != 0)
                v4 = (s16)(v4 + 1);
                (void) v4;  /* fzgx: keeps the web at its definition */
            if (((fn_10_8BB8_array_read(lbl_1_bss_9F8)[p_lbl_1_bss_8B3A0.value->unk_9E].f8 >> 8) & 1) != 0)
                fn_1_12F150(fzgx_loop_v3_1334, 2, 1);
        }
        fzgx_loop_v3_1334++;
    }
    v3 = fzgx_loop_v3_1334;
    }
    if (((s16)v4 != 0 && (u32)fn_1_12F258() < 300) || (s32)fn_1_12F228() != 0) {
        fn_1_12F1E8(0);
        fn_1_4A00(0, (u8)lbl_10_bss_4938C, (void *)lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        lbl_10_bss_14.f = 31;
    }
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_10_8BB8 */

/* fzgx:begin fn_10_8D90 */
extern s32 lbl_10_bss_51740;
extern u32 lbl_10_bss_49388;

extern void fn_1_435C(u32 value);
extern void fn_1_426C(s32 value);

typedef struct {
    u8 pad[0x94];
    u32 flags;
} SelGlobal;

extern SelGlobal lbl_1_bss_8B3A0;

void fn_10_8D90(void) {
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    lbl_1_bss_8B3A0.flags &= ~0x00000800;
}
/* fzgx:end fn_10_8D90 */

/* fzgx:begin fn_10_8F0C */
#include "rel/sel/sel.h"

typedef struct { u16 unk_0; } U16Box;
typedef struct {
    u8 pad_0[0x16];
    u8 unk_16;
    u8 unk_17;
    u8 pad_18[8];
    u16 unk_20;
} SelSub;
typedef struct {
    u8 pad_0[0x94];
    u32 unk_94;
    u32 unk_98;
    u8 pad_9C[2];
    u8 unk_9E;
    u8 pad_9F[5];
    SelSub *unk_A4;
    u8 pad_A8[0x98];
    u32 unk_140;
} SelState;
typedef struct {
    u8 pad_0[0xA];
    s8 unk_A;
    u8 pad_B;
} SelSlot;
typedef struct {
    u8 pad_0[8];
    u16 unk_8;
    u8 pad_A[0xA];
} Sel9F8;
extern U16Box lbl_1_bss_96A;
extern SelState lbl_1_bss_8B3A0;
extern SelSlot lbl_1_bss_9C8[];
extern Sel9F8 lbl_1_bss_9F8[];

extern void fn_1_A2D84(u32 value);
extern s32 fn_1_4C10(void);
extern void fn_1_12F150(s16 value, u32 arg1, u32 arg2);
extern s32 fn_1_12F228(void);
extern void fn_1_12F1E8(s32 value);
extern void fn_1_4A00(s32 arg0, u8 arg1, void *arg2);
static inline SelSub * fn_10_8F0C_read_pointer(SelState * owner) { return owner->unk_A4; }
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
#pragma opt_common_subs off
void fn_10_8F0C(void) {
    u32 fzgx_condition_1630;
    SelState *st;
    SelSlot *slot;
    SelState *g;
    SelState *h;
    u16 *val;
    s32 ready;
    s16 count = 0;
    s16 i;
    u8 flag;

    *(u16 *)&lbl_1_bss_96A = 14;
    st = &lbl_1_bss_8B3A0;
    if (fn_10_8F0C_read_pointer(st)->unk_20 != 0) {
        val = &st->unk_A4->unk_20;
        *val = fn_10_8F0C_read_pointer(st)->unk_20 - 1;
        if (fn_10_8F0C_read_pointer(st)->unk_20 == 0) {
            fn_1_A2D84(0xA9121E00);
        }
    }
    if ((s32)lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }
    if (((fzgx_condition_1630 = lbl_1_bss_8B3A0.unk_140) & 0x80000000) != 0 &&
        (fzgx_condition_1630 & 0x40000000) == 0 &&
        (lbl_1_bss_8B3A0.unk_94 & 0x8) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }
    if (ready == 0) {
        if ((s32)lbl_10_bss_14 != -1) {
            s32 value = lbl_10_bss_14;
            lbl_10_bss_14 = -1;
            lbl_1_bss_96A.unk_0 = (u16)value;
        } else {
            slot = lbl_1_bss_9C8;
            g = &lbl_1_bss_8B3A0;
            h = &lbl_1_bss_8B3A0;
            for (i = 0; i < 4; i++) {
                if (((i)[slot]).unk_A != -1) {
                    if (__rlwnm(g->unk_98, (((u32)i + 1) & 31), 31, 31) != 0) {
                        if (((((g->unk_9E)[lbl_1_bss_9F8]).unk_8 >> 12) & 1) != 0) {
                            count++;
                        }
                        if (((((h->unk_9E)[lbl_1_bss_9F8]).unk_8 >> 12) & 1) != 0) {
                            fn_1_12F150(i, 0, 1);
                        }
                    }
                }
            }
            if (count != 0 || fn_1_12F228() != 0) {
                fn_10_8F0C_read_pointer(st)->unk_16 = 1;
                fn_1_12F1E8(0);
            }
            if (count != 0 || fn_1_12F228() != 0) {
                fn_1_12F1E8(0);
                flag = fn_10_8F0C_read_pointer(st)->unk_17;
                lbl_10_bss_14 = 0x19 + ((-(s32)flag | flag) >> 31);
                fn_1_4A00(0, lbl_10_bss_4938C, (void *)lbl_10_bss_49388);
                lbl_10_bss_51744 = 0;
            }
        }
    }
}
#pragma opt_common_subs reset

#pragma opt_lifetimes reset
#pragma opt_dead_assignments reset
/* fzgx:end fn_10_8F0C */

/* fzgx:begin fn_10_9154 */
extern s32 lbl_10_bss_51740;
extern s32 lbl_10_bss_49388;
extern s32 lbl_10_data_7B0[15];
extern s32 lbl_10_bss_49384;

extern void fn_1_435C(s32 value);
extern void fn_1_426C(s32 value);

void fn_10_9154(void) {
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
    if (lbl_10_data_7B0[0] != -1) {
        fn_1_435C(lbl_10_bss_49384);
        fn_1_426C(lbl_10_data_7B0[0]);
        lbl_10_data_7B0[0] = -1;
    }
}
/* fzgx:end fn_10_9154 */

/* fzgx:begin fn_10_91E8 */
extern u32 lbl_1_bss_980[];

int fn_10_91E8(void) {
    int count = 0;
    u32 value;
    s16 i = 0;

    while (i < 4) {
        value = lbl_1_bss_980[i];

        if (value == 0x09000000 ||
            value == 0x88000000 ||
            value == 0x8B100000 ||
            value == 0x08000000) {
            count++;
        }
        i++;
    }

    return count;
}
/* fzgx:end fn_10_91E8 */

/* fzgx:begin fn_10_924C */
extern u32 lbl_1_bss_8B3A0[];
extern u32 lbl_10_data_0[];
extern void *lbl_1_bss_6D82C;

extern void fn_80008BEC(void *dst, int c, u32 n);
extern void *fn_1_7F518(s16 a, void *b, s32 c);
extern int sprintf(char *buf, const char *fmt, ...);
extern s32 fn_1_12A32C(void *s);
extern void fn_1_12AB38(void *p);
extern void *fn_1_D3884(void *p);
extern void fn_1_12A2B8(u32 flag);
extern void fn_1_80270(void *src, void *dst);
extern void fn_1_80058(s8 idx, u8 *p);
extern void fn_1_80C18(u8 *a, u8 *b, s8 n);

typedef struct {
    u8 pad0[0x458];
    s16 f458;
    s16 f45a;
    u8 pad1[0x108];
    s32 f564;
    u8 pad2[0x34];
    u8 str59c[0x174];
    u8 obj710[0xc];
    u8 obj71c[0x10];
    u8 obj72c[0xac];
    char fmt[0x20];
} SelData;

typedef struct {
    s16 f0;
    u16 f2;
    u32 f4;
    u8 f8;
    u8 pad[0x17];
} SelEnt;

typedef struct {
    u8 pad324[0x324];
    u32 f324;
    u8 pad[0x118];
} SelCell;

#pragma opt_loop_invariants off
void fn_10_924C(u8 *arg0) {
    u8 *archive_path;
    s16 i;
    SelData *d = (SelData *)&lbl_10_data_0;

    if (*(u32 *)((u8 *)lbl_1_bss_8B3A0 + 0x94) & 0x2000000u) {
        if (d->f564 == -1) {
            char out[0x20];
            u8 str[0x20];
            u32 buf[8];
            u32 one = 1;

            fn_80008BEC(buf, 0, 0x20);
            i = d->f45a;
            ((s16 *)buf)[1] = 6;
            ((u8 *)buf)[8] = (u8)(one << i);
            ((u32 *)buf)[1] = one << (d->f458);
            sprintf(out, d->fmt, fn_1_7F518(6, str, 0));
            d->f564 = fn_1_12A32C(out);
            if (lbl_1_bss_6D82C == 0) {
                fn_1_12AB38(d->obj710);
                lbl_1_bss_6D82C = fn_1_D3884(d->obj71c);
                archive_path = d->obj72c;
                fn_1_12AB38(archive_path);
            }
            fn_1_12A2B8(1);
            fn_1_12AB38(d->obj710);
            fn_1_80270(buf, arg0 + 0x1980);
            archive_path = d->obj72c;
            fn_1_12AB38(archive_path);
            fn_1_12A2B8(0);
            *(u32 *)(((0x1ca4) + (arg0))) = d->f564;
        }
    } else if (d->f564 == -1) {
        SelEnt entries[41];
        i = 0;
        {
            SelEnt *p = entries;
            u32 zero = i;
            u32 one = 1;

            while (i < 41) {
                fn_1_80058((s8)i, (u8 *)p);
                p->f0 = i;
                i++;
                p->f8 = zero;
                p->f8 = p->f8 | (one << d->f45a);
                p->f4 = one << d->f458;
                p++;
            }
            d->f564 = fn_1_12A32C(d->str59c);
            fn_1_12A2B8(1);
            fn_1_80C18(arg0, (u8 *)entries, 41);
            fn_1_12A2B8(0);
            for (i = 0; i < 33; i += 8) {
                ((SelCell *)arg0 + i)->f324 = d->f564;
                ((SelCell *)arg0 + i + 1)->f324 = d->f564;
                ((SelCell *)arg0 + i + 2)->f324 = d->f564;
                ((SelCell *)arg0 + i + 3)->f324 = d->f564;
                ((SelCell *)arg0 + i + 4)->f324 = d->f564;
                ((SelCell *)arg0 + i + 5)->f324 = d->f564;
                ((SelCell *)arg0 + i + 6)->f324 = d->f564;
                ((SelCell *)arg0 + i + 7)->f324 = d->f564;
            }
            for (; i < 41; i++) {
                ((SelCell *)arg0 + i)->f324 = d->f564;
            }
        }
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_10_924C */

/* fzgx:begin fn_10_948C */
typedef struct {
    u32 flags;
    u8 pad[0x81bc];
} SelEntry;

extern u32 lbl_1_bss_8B3A0[];
extern SelEntry lbl_10_bss_3C0[];
extern s16 lbl_10_data_456;

extern void fn_1_14DB48(SelEntry *entry, void *context, u32 mask);
extern u8 *fn_1_36AD0(void);

void fn_10_948C(void *context, void *arg) {
    SelEntry *entry;
    s16 i;
    u32 one;

    if (*(u32 *)((u8 *)lbl_1_bss_8B3A0 + 0x94) & ((u32)1 << 31)) {
        return;
    }

    i = 0;
    one = 1;
    while (i < 9U) {
        entry = &lbl_10_bss_3C0[i];
        if ((entry->flags & ((u32)1 << 31)) &&
            (entry->flags & ((u32)1 << 30))) {
            fn_1_14DB48(entry, (u8 *)context + i * 0xa20, one << lbl_10_data_456);
        }
        i++;
    }

    if (arg != 0) {
        i = 0;
        one = 1;
        while (i < 4) {
            entry = &((SelEntry *)fn_1_36AD0())[i];
            if ((entry->flags & ((u32)1 << 31)) &&
                (entry->flags & ((u32)1 << 30))) {
                fn_1_14DB48(entry, (u8 *)arg + i * 0xa20, one << lbl_10_data_456);
            }
            i++;
        }
    }
}
/* fzgx:end fn_10_948C */

/* fzgx:begin fn_10_95A0 */
extern u32 lbl_10_data_564[];
extern void fn_1_12A2B8(s32 value);
extern void fn_1_12A2D0(s32 value);
extern void fn_1_12C5E4(void *value);
extern void fn_1_12A734(s32 value);
extern void fn_80071718(void *value);

typedef struct {
    u8 pad[0x94];
    u32 flags;
} SelGlobal;

extern SelGlobal lbl_1_bss_8B3A0;
extern void *lbl_1_bss_6D82C;

typedef struct {
    u8 pad[0x324];
    u32 a;
    u8 pad0[0x43c];
    u32 b;
    u8 pad1[0x43c];
    u32 c;
    u8 pad2[0x43c];
    u32 d;
    u8 pad3[0x43c];
    u32 e;
    u8 pad4[0x43c];
    u32 f;
    u8 pad5[0x43c];
    u32 g;
    u8 pad6[0x43c];
    u32 h;
    u8 tail[0x11c];
} SelBlock;

void fn_10_95A0(SelBlock *data) {
    s16 i;
    SelBlock *block;
    s32 value = lbl_10_data_564[0];

    if (((u32)lbl_1_bss_8B3A0.flags & ((u32)1 << 31)) == 0) {
        if (value != -1) {
            fn_1_12A2B8(1);
            fn_1_12A2D0(value);
        } else {
            fn_1_12A2B8(0);
        }

        fn_1_12C5E4(data);
        fn_1_12A2B8(0);

        if (lbl_1_bss_6D82C != 0) {
            fn_80071718(lbl_1_bss_6D82C);
            lbl_1_bss_6D82C = 0;
        }

        if (value != -1) {
            fn_1_12A734(value);
            lbl_10_data_564[0] = -1;
        }

        block = data;
        i = 0;
        while (i < 0x21) {
            block->a = lbl_10_data_564[0];
            block->b = lbl_10_data_564[0];
            block->c = lbl_10_data_564[0];
            block->d = lbl_10_data_564[0];
            block->e = lbl_10_data_564[0];
            block->f = lbl_10_data_564[0];
            block->g = lbl_10_data_564[0];
            block->h = lbl_10_data_564[0];
            i += 8;
            block = (SelBlock *)((u8 *)block + 0x2200);
        }

        block = (SelBlock *)((u8 *)data + i * 0x440);
        while (i < 0x29) {
            block->a = lbl_10_data_564[0];
            i++;
            block = (SelBlock *)((u8 *)block + 0x440);
        }
    }
}
/* fzgx:end fn_10_95A0 */

/* fzgx:begin fn_10_96F8 */
extern void fn_1_14DBCC(void *);

void fn_10_96F8(void *first, void *second) {
    s16 i;
    u8 *ptr;

    ptr = (u8 *)first;
    for (i = 0; i < 9U; i++) {
        fn_1_14DBCC(ptr);
        ptr += 0xa20;
    }

    if (second != 0) {
        ptr = (u8 *)second;
        i = 0;
        for (; i < 4; i++) {
            fn_1_14DBCC(ptr);
            ptr += 0xa20;
        }
    }
}
/* fzgx:end fn_10_96F8 */

/* fzgx:begin fn_10_A0E8 */
struct SelState98 {
    u8 pad_0[0x98];
    u32 unk_98;
};

typedef struct {
    u8 pad_0[0xa];
    s8 unk_a;
    u8 pad_1[1];
} SelSlot9C8;

typedef struct {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
} SelSlot9F8;

extern s16 lbl_10_bss_55608;
extern struct SelState98 lbl_1_bss_8B3A0;
extern SelSlot9C8 lbl_1_bss_9C8[];
extern SelSlot9F8 lbl_1_bss_9F8[];
extern u32 lbl_801A66A8;
extern void fn_1_12F128(s16);
extern void fn_1_A2D84(u32);

#pragma opt_common_subs off

s16 fn_10_A0E8(void) {
    s32 res;
    s32 sum;
    s16 old;
    s16 counter;
    s16 i;

    old = lbl_10_bss_55608;
    counter = 0;
    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_9C8[i].unk_a == -1) {
            continue;
        }
        if (__rlwnm((&lbl_1_bss_8B3A0)->unk_98, ((u32)(i + 1) & 31), 31, 31) != 0) {
            if (((lbl_1_bss_9F8[i].unk_10 >> 3) & 1) ||
                ((lbl_1_bss_9F8[i].unk_12 >> 3) & 1)) {
                counter--;
            }
            if (((lbl_1_bss_9F8[i].unk_10 >> 2) & 1) ||
                ((lbl_1_bss_9F8[i].unk_12 >> 2) & 1)) {
                counter++;
            }
            if (((lbl_1_bss_9F8[i].unk_10 >> 2) & 1) ||
                ((lbl_1_bss_9F8[i].unk_12 >> 2) & 1)) {
                fn_1_12F128(i);
            } else if (((lbl_1_bss_9F8[i].unk_10 >> 3) & 1) ||
                       ((lbl_1_bss_9F8[i].unk_12 >> 3) & 1)) {
                fn_1_12F128(i);
            }
        }
    }

    sum = lbl_10_bss_55608 + counter;
    if (sum < 0) {
        res = 0;
    } else {
        res = 1;
        if (sum <= 1) {
            res = sum;
        }
    }
    lbl_10_bss_55608 = res;
    if ((s16)res != old) {
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }
    return lbl_10_bss_55608;
}
/* fzgx:end fn_10_A0E8 */

/* fzgx:begin fn_10_A25C */
extern s32 lbl_1_bss_980[4];
extern u32 lbl_801A66A8;

typedef struct {
    u8 pad_0[0xA];
    s8 unk_a;
    u8 pad_1[1];
} SelRowA25C;

typedef struct {
    u8 pad_0[0x10];
    u16 unk_10;
    u16 unk_12;
} SelInfoA25C;

typedef struct {
    u8 pad_0[0x94];
    u32 unk_94;
    u32 unk_98;
} SelGlobA25C;

typedef struct {
    s16 unk_0;
    s16 unk_2;
    s16 unk_4;
    s16 unk_6;
} SelObjA25C;

extern SelRowA25C lbl_1_bss_9C8[4];
extern SelInfoA25C lbl_1_bss_9F8[4];
extern SelGlobA25C lbl_1_bss_8B3A0;

extern void fn_1_12F128(s16);
extern void fn_1_A2D84(u32);

#pragma opt_common_subs off
void fn_10_A25C(SelObjA25C *obj) {
    struct { s16 value; } count;
    struct { s16 value; } i;
    s16 delta = 0;
    s16 j;
    s32 val;
    s32 t;
    s32 c;
    count.value = 0;

    for (i.value = 0; i.value < 4; i.value++) {
        val = ((i.value)[lbl_1_bss_980]);
        if (val == 0x9000000 || val == -0x78000000 || val == -0x74F00000 ||
            val == 0x8000000) {
            count.value++;
        }
    }

    for (j = 0; j < 4; j++) {
        if (((j)[lbl_1_bss_9C8]).unk_a == -1) {
            continue;
        }

        if (__rlwnm(lbl_1_bss_8B3A0.unk_98, ((u32)(((1) + (j))) & 31), 31, 31) != 0) {
            if (((((j)[lbl_1_bss_9F8]).unk_10 >> 3) & 1) ||
                ((((j)[lbl_1_bss_9F8]).unk_12 >> 3) & 1)) {
                delta--;
            }

            if (((((j)[lbl_1_bss_9F8]).unk_10 >> 2) & 1) ||
                (((1) & ((((j)[lbl_1_bss_9F8]).unk_12 >> 2))))) {
                delta++;
            }

            if (((((j)[lbl_1_bss_9F8]).unk_10 >> 2) & 1) ||
                ((((j)[lbl_1_bss_9F8]).unk_12 >> 2) & 1)) {
                fn_1_12F128(j);
            } else if (((((j)[lbl_1_bss_9F8]).unk_10 >> 3) & 1) ||
                       ((((j)[lbl_1_bss_9F8]).unk_12 >> 3) & 1)) {
                fn_1_12F128(j);
            }
        }
    }

    if ((lbl_1_bss_8B3A0.unk_94 & 0x200) != 0) {
        c = count.value;
        t = ((obj->unk_4) + (delta));
        if (t > c) {
            t = 0;
        } else if (t < 0) {
            t = c;
        }
        obj->unk_4 = t;
    } else {
        c = count.value;
        t = ((obj->unk_4) + (delta));
        if (t > c) {
            t = 2;
        } else if (t < 2) {
            t = c;
        }
        obj->unk_4 = t;
    }

    if (delta != 0) {
        fn_1_A2D84(0xA9010000);
        lbl_801A66A8 = 0;
    }

    if (obj->unk_0 == 0) {
        obj->unk_6 = obj->unk_4;
        if (obj->unk_4 == 1) {
            obj->unk_6 = 30;
        }
    }
}
#pragma opt_common_subs reset
/* fzgx:end fn_10_A25C */

/* fzgx:begin fn_10_A480 */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 pad_0[0x19];
u8 unk_19;
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
s16 unk_0;
u8 pad_2[0x2];
s16 unk_4;
u8 pad_6[0x2];
s16 unk_8;
u8 pad_A[0x4];
s16 unk_E;
u8 pad_10[0x4];
u8 unk_14;
u8 pad_15[0x19];
s16 unk_2E;
u8 pad_30[0x5C];
s16 unk_8C;
u8 pad_8E[0x2];
s16 unk_90;
s16 unk_92;
u32 unk_94;
u8 pad_98[0x6];
u8 unk_9E;
u8 unk_9F;
u8 pad_A0[0x4];
Obj_1_bss_8B3A0_AtA4 *unk_A4;
u8 pad_A8[0x8];
s16 unk_B0;
s16 unk_B2;
u8 pad_B4[0xC];
s16 unk_C0;
s16 unk_C2;
u8 pad_C4[0xC];
s16 unk_D0;
s16 unk_D2;
u8 pad_D4[0xC];
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u32 unk_FC;
u32 unk_100;
u32 unk_104;
u32 unk_108;
u32 unk_10C;
u32 unk_110;
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u8 unk_128;
u8 unk_129;
u8 pad_12A[0x2];
s16 unk_12C;
s16 unk_12E;
s16 unk_130;
s16 unk_132;
s16 unk_134;
s16 unk_136;
s16 unk_138;
s16 unk_13A;
s16 unk_13C;
u8 pad_13E[0x2];
u32 unk_140;
u8 pad_144[0x2];
s16 unk_146;
s16 unk_148;
u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;


typedef struct {
u16 unk_0;
u16 unk_2;
u8 pad_4[0x4];
u16 unk_8;
u16 unk_A;
u8 pad_C[0x4];
u16 unk_10;
u16 unk_12;
u8 pad_14[0x3C];
} Obj_1_bss_9F8;
extern Obj_1_bss_9F8 lbl_1_bss_9F8;


extern u8 lbl_10_bss_4938E;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


struct E9C8 { u8 pad[10]; s8 id; u8 pad2; };


extern u8 lbl_1_bss_9C8[];


extern void fn_1_A2D84(u32 arg0);


extern u32 lbl_801A66A8;
extern void fn_1_12F128(s16 index);


struct fn_10_A480_Arg0 {
u8 pad_0[4];
s16 unk_4;
s16 unk_6;
u8 pad_8[0x8C];
u32 unk_94;
};
struct fn_10_A480_lbl_1_bss_8B3A0 {
u8 pad_0[0x98];
u32 unk_98;
};
struct fn_10_A480_E9F8 { u8 pad[0x10]; u16 a; u16 b; };

#pragma opt_propagation off

static inline s32 fn_10_A480_read(u8 *p) { return (s8)*p; }

#pragma opt_propagation reset


#pragma opt_common_subs off


#pragma opt_dead_code off


#pragma opt_dead_assignments off


#pragma opt_empty_loops off

void fn_10_A480(struct fn_10_A480_Arg0 *arg0) {
s16 v4 = 0;
struct { s32 value; } temp;
s16 v1;
s16 v2;
s16 v3;
u16 v9;
u16 v8;
s32 v12;
s32 lower;
s32 v10;
s32 v5;
temp.value = 30;
if ((arg0->unk_94 & 2) != 0) {
temp.value = (*(s8 (*)[1])&lbl_10_bss_4938E)[0];
}
v1 = (s16)temp.value ;
v2 = 0;
goto loop_test; /* Keep the verified branch to loop_test. */
loop_body:
v2++;
loop_test:
if (v2 < 4) goto loop_body; /* Keep the verified branch to loop_body. */
for (v3 = 0; v3 < 4; v3++) {
if ((((struct E9C8 *)&lbl_1_bss_9C8))[v3].id != -1 && __rlwnm((*((struct fn_10_A480_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0)).unk_98, (v3 + 1) & 31, 31, 31)) {
if ((((((struct fn_10_A480_E9F8 *)&lbl_1_bss_9F8))[v3].a >> 3) & 1) || (((((struct fn_10_A480_E9F8 *)&lbl_1_bss_9F8))[v3].b >> 3) & 1)) {
v4--;
}
if ((((((struct fn_10_A480_E9F8 *)&lbl_1_bss_9F8))[v3].a >> 2) & 1) || (((((struct fn_10_A480_E9F8 *)&lbl_1_bss_9F8))[v3].b >> 2) & 1)) {
v4++;
}
v8 = (((struct fn_10_A480_E9F8 *)&lbl_1_bss_9F8))[v3].a;
if (((v8 >> 2) & 1) || (((v9 = (((struct fn_10_A480_E9F8 *)&lbl_1_bss_9F8))[v3].b) >> 2) & 1)) {
fn_1_12F128(v3);
} else if (((v8 >> 3) & 1) || ((v9 >> 3) & 1)) {
fn_1_12F128(v3);
}
}
}
v10 = arg0->unk_6 + v4;
v5 = v1;
if (v10 > v1) {
v10 = 1;
if (arg0->unk_4 > 1) {
v10 = arg0->unk_4;
}
} else {
lower = arg0->unk_4;
v12 = 1;
if (lower > 1) {
v12 = lower;
}
if (v10 < v12) {
v10 = v5;
}
}
arg0->unk_6 = v10;
if (v4 != 0) {
fn_1_A2D84(0xA9010000);
lbl_801A66A8 = 0;
}
}

#pragma opt_common_subs reset
/* fzgx:end fn_10_A480 */

/* fzgx:begin fn_10_A634 */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 pad_0[0x19];
u8 unk_19;
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
s16 unk_0;
u8 pad_2[0x2];
s16 unk_4;
u8 pad_6[0x2];
s16 unk_8;
u8 pad_A[0x4];
s16 unk_E;
u8 pad_10[0x4];
u8 unk_14;
u8 pad_15[0x19];
s16 unk_2E;
u8 pad_30[0x5C];
s16 unk_8C;
u8 pad_8E[0x2];
s16 unk_90;
s16 unk_92;
u32 unk_94;
u8 pad_98[0x6];
u8 unk_9E;
u8 unk_9F;
u8 pad_A0[0x4];
Obj_1_bss_8B3A0_AtA4 *unk_A4;
u8 pad_A8[0x8];
s16 unk_B0;
s16 unk_B2;
u8 pad_B4[0xC];
s16 unk_C0;
s16 unk_C2;
u8 pad_C4[0xC];
s16 unk_D0;
s16 unk_D2;
u8 pad_D4[0xC];
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u32 unk_FC;
u32 unk_100;
u32 unk_104;
u32 unk_108;
u32 unk_10C;
u32 unk_110;
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u8 unk_128;
u8 unk_129;
u8 pad_12A[0x2];
s16 unk_12C;
s16 unk_12E;
s16 unk_130;
s16 unk_132;
s16 unk_134;
s16 unk_136;
s16 unk_138;
s16 unk_13A;
s16 unk_13C;
u8 pad_13E[0x2];
u32 unk_140;
u8 pad_144[0x2];
s16 unk_146;
s16 unk_148;
u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;


typedef struct {
u16 unk_0;
u16 unk_2;
u8 pad_4[0x4];
u16 unk_8;
u16 unk_A;
u8 pad_C[0x4];
u16 unk_10;
u16 unk_12;
u8 pad_14[0x3C];
} Obj_1_bss_9F8;
extern Obj_1_bss_9F8 lbl_1_bss_9F8;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


struct E9C8 { u8 pad[10]; s8 id; u8 pad2; };


extern u8 lbl_1_bss_9C8[];


extern void fn_1_A2D84(u32 arg0);


extern u32 fn_1_F9FEC(void);
extern u32 lbl_801A66A8;
extern void fn_1_12F128(s16 index);


struct fn_10_A634_lbl_1_bss_8B3A0 {
u8 pad_0[0x98];
u32 unk_98;
};
struct fn_10_A634_E9F8 { u8 pad[0x10]; u16 a; u16 b; };

#pragma opt_common_subs off

void fn_10_A634(void *arg0) {
struct { s32 value; } v0;
s16 v2;
s16 v1;
u16 v7;
u16 v6;
s32 out;
s32 v8;
s32 v9;
v0.value = fn_1_F9FEC() != 0;
v2 = 0;
for (v1 = 0; v1 < 4; v1++) {
if ((((struct E9C8 *)&lbl_1_bss_9C8))[v1].id != -1 &&
__rlwnm((*((struct fn_10_A634_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0)).unk_98, (v1 + 1) & 31, 31, 31)) {
if ((((((struct fn_10_A634_E9F8 *)&lbl_1_bss_9F8))[v1].a >> 3) & 1) || (((((struct fn_10_A634_E9F8 *)&lbl_1_bss_9F8))[v1].b >> 3) & 1)) {
v2--;
}
if ((((((struct fn_10_A634_E9F8 *)&lbl_1_bss_9F8))[v1].a >> 2) & 1) || (((((struct fn_10_A634_E9F8 *)&lbl_1_bss_9F8))[v1].b >> 2) & 1)) {
v2++;
}
v6 = (((struct fn_10_A634_E9F8 *)&lbl_1_bss_9F8))[v1].a;
if (((v6 >> 2) & 1) || (((v7 = (((struct fn_10_A634_E9F8 *)&lbl_1_bss_9F8))[v1].b) >> 2) & 1)) {
fn_1_12F128(v1);
} else if (((v6 >> 3) & 1) || ((v7 >> 3) & 1)) {
fn_1_12F128(v1);
}
}
}
if (v0.value) {
v8 = *(s16 *)((u8 *)arg0 + 8) + v2;
if (v8 > 3) out = 0;
else {
out = 3;
if (v8 >= 0) out = v8;
}
*(s16 *)((u8 *)arg0 + 8) = out;
} else {
v9 = *(s16 *)((u8 *)arg0 + 8) + v2;
if (v9 > 2) out = 0;
else {
out = 2;
if (v9 >= 0) out = v9;
}
*(s16 *)((u8 *)arg0 + 8) = out;
}
*(s16 *)((u8 *)arg0 + 10) = *(s16 *)((u8 *)arg0 + 8);
if (v2 != 0) {
fn_1_A2D84(0xA9010000);
lbl_801A66A8 = 0;
}
}

#pragma opt_common_subs reset
/* fzgx:end fn_10_A634 */

/* fzgx:begin fn_10_A7DC */
extern int fn_1_FA070(void);
extern int fn_1_FA0BC(int);

struct SelState {
    s16 value;
    u8 padding[0x90];
    u32 flags;
};

extern struct SelState lbl_1_bss_8B3A0;

int fn_10_A7DC(s16 mode) {
    if ((lbl_1_bss_8B3A0.flags & 0x200) != 0) {
        if (mode == 0) {
            return 1;
        }
        if (mode >= 1 && mode <= 3) {
            return 1;
        }
        if (mode == 4) {
            if (fn_1_FA070() != 0) {
                return 1;
            }
        }
        if (mode == 5) {
            if (fn_1_FA0BC(lbl_1_bss_8B3A0.value == 1) != 0) {
                return 1;
            }
        }
    } else {
        if (mode >= 1 && mode <= 3) {
            return 1;
        }
        if (mode == 4) {
            if (fn_1_FA070() != 0) {
                return 1;
            }
        }
        if (mode == 5) {
            if (fn_1_FA0BC(lbl_1_bss_8B3A0.value == 1) != 0) {
                return 1;
            }
        }
    }

    return 0;
}
/* fzgx:end fn_10_A7DC */

/* fzgx:begin fn_10_A90C */
struct fn_10_A90C_lbl_1_bss_8B3A0 {
    s16 value;
    u8 pad_0[0x92];
    u32 flags;
    u32 unk_98;
};
extern struct fn_10_A90C_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern u8 lbl_1_bss_9C8[];
extern u8 lbl_1_bss_9F8[];
extern void fn_1_12F128(s32);
extern int fn_1_FA070(void);
extern int fn_1_FA0BC(int);
extern void fn_1_A2D84(u32);

static inline int available(s16 mode) {
    if ((lbl_1_bss_8B3A0.flags & 0x200) != 0) {
        if (mode == 0) return 1;
        if (mode >= 1 && mode <= 3) return 1;
        if (mode == 4) {
            if (fn_1_FA070() != 0) return 1;
        }
        if (mode == 5) {
            if (fn_1_FA0BC(lbl_1_bss_8B3A0.value == 1) != 0) return 1;
        }
    } else {
        if (mode >= 1 && mode <= 3) return 1;
        if (mode == 4) {
            if (fn_1_FA070() != 0) return 1;
        }
        if (mode == 5) {
            if (fn_1_FA0BC(lbl_1_bss_8B3A0.value == 1) != 0) return 1;
        }
    }
    return 0;
}

#pragma opt_loop_invariants off
#pragma opt_dead_assignments off
static inline u8 fn_10_A90C_array_read(s32 index, u8 *array) { return array[index]; }
#pragma opt_common_subs off
void fn_10_A90C(void *arg0) {
    u8 *p_lbl_1_bss_9C8;
    s16 v1;
    struct fn_10_A90C_lbl_1_bss_8B3A0 *p_lbl_1_bss_8B3A0;
    s32 v0;
    void *v2;
    void *v3;
    u32 v4;
    p_lbl_1_bss_9C8 = (u8 *)&lbl_1_bss_9C8;
    v2 = (u8 *)&lbl_1_bss_9F8;
    p_lbl_1_bss_8B3A0 = (struct fn_10_A90C_lbl_1_bss_8B3A0 *)&lbl_1_bss_8B3A0;
    v1 = 0;
    v0 = 0;
    v3 = p_lbl_1_bss_9C8;
    while ((s16)v0 < 4) {
        if ((s8)fn_10_A90C_array_read(v0 * 12 + 10, p_lbl_1_bss_9C8) != -1) {
            if (__rlwnm(p_lbl_1_bss_8B3A0->unk_98, (((s16)v0) + 1) & 31, 31, 31)) {
                if ((*(volatile u16 *)(lbl_1_bss_9F8 + v0 * 20 + 0x10) & 1) || (*(volatile u16 *)(lbl_1_bss_9F8 + v0 * 20 + 0x12) & 1)) v1--; // fzgx-allow: S2 layout primer sink: MWCC emits the literal pool in first-access order
                if (((*(volatile u16 *)(lbl_1_bss_9F8 + v0 * 20 + 0x10) >> 1) & 1) || ((*(volatile u16 *)(lbl_1_bss_9F8 + v0 * 20 + 0x12) >> 1) & 1)) v1++; // fzgx-allow: S2 layout primer sink: MWCC emits the literal pool in first-access order
                if (((*(u16 *)(lbl_1_bss_9F8 + v0 * 20 + 0x10) >> 1) & 1) || ((*(u16 *)(lbl_1_bss_9F8 + v0 * 20 + 0x12) >> 1) & 1)) {
                    fn_1_12F128(v0);
                } else if ((*(u16 *)(lbl_1_bss_9F8 + v0 * 20 + 0x10) & 1) || (*(u16 *)(lbl_1_bss_9F8 + v0 * 20 + 0x12) & 1)) {
                    fn_1_12F128(v0);
                }
            }
        }
        v0++;
    }
    if (v1 != 0) {
        if (*(u32 *)(((0x94) + ((u8 *)arg0))) & 0x40000000) {
            s32 value = *(s16 *)((u8 *)arg0 + 0x8c) + v1;
            *(s16 *)((u8 *)arg0 + 0x8c) = value > 8 ? 6 : value < 6 ? 8 : value;
        } else {
            v2 = (void *)(s32)v1;
            do {
                s32 value = *(s16 *)((u8 *)arg0 + 0x8c) + (s32)v2;
                *(s16 *)((u8 *)arg0 + 0x8c) = value > 10 ? 0 : value < 0 ? 10 : value;
            } while (!available(*(s16 *)((u8 *)arg0 + 0x8c)));
        }
        *(s16 *)((u8 *)arg0 + 0x8e) = 0;
        fn_1_A2D84(0xa9010000);
    }
}
#pragma opt_loop_invariants reset
/* fzgx:end fn_10_A90C */

/* fzgx:begin fn_10_AB98 */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 pad_0[0x19];
u8 unk_19;
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
s16 unk_0;
u8 pad_2[0x2];
s16 unk_4;
u8 pad_6[0x2];
s16 unk_8;
u8 pad_A[0x4];
s16 unk_E;
u8 pad_10[0x4];
u8 unk_14;
u8 pad_15[0x19];
s16 unk_2E;
u8 pad_30[0x5C];
s16 unk_8C;
u8 pad_8E[0x2];
s16 unk_90;
s16 unk_92;
u32 unk_94;
u8 pad_98[0x6];
u8 unk_9E;
u8 unk_9F;
u8 pad_A0[0x4];
Obj_1_bss_8B3A0_AtA4 *unk_A4;
u8 pad_A8[0x8];
s16 unk_B0;
s16 unk_B2;
u8 pad_B4[0xC];
s16 unk_C0;
s16 unk_C2;
u8 pad_C4[0xC];
s16 unk_D0;
s16 unk_D2;
u8 pad_D4[0xC];
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u32 unk_FC;
u32 unk_100;
u32 unk_104;
u32 unk_108;
u32 unk_10C;
u32 unk_110;
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u8 unk_128;
u8 unk_129;
u8 pad_12A[0x2];
s16 unk_12C;
s16 unk_12E;
s16 unk_130;
s16 unk_132;
s16 unk_134;
s16 unk_136;
s16 unk_138;
s16 unk_13A;
s16 unk_13C;
u8 pad_13E[0x2];
u32 unk_140;
u8 pad_144[0x2];
s16 unk_146;
s16 unk_148;
u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;


extern u8 lbl_10_data_2B4[0x1A0];


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


typedef struct fn_10_AB98_SelCursor {
u8 pad_0[0x8C];
s16 unk_8C;
s16 unk_8E;
s16 unk_90;
u8 pad_92[2];
u32 unk_94;
} fn_10_AB98_SelCursor;


extern void fn_10_C594(void);


extern void fn_10_AB98(fn_10_AB98_SelCursor *cursor);


extern void fn_1_7B2E8(u32);


extern s16 fn_1_12EF24(s16 row, s16 column);
extern s32 fn_1_F89E4(u8);


struct fn_10_AB98_SelState {
s16 value;
};
static inline s16 sel_sign(s16 x) {
return x < 0 ? -1 : (x > 0);
}
static inline void sel_move_cursor(fn_10_AB98_SelCursor *cursor, s32 step) {
s8 i;
s32 blocked;
s32 pos;
s32 next;
struct { s16 value; } count;
s16 dir;
s32 tmp_ra6;
if (cursor->unk_8C == 0) {
pos = cursor->unk_90;
pos = pos < 0 ? step : (pos > 110 ? 110 : pos);
if ((cursor->unk_94 & 2) != 0 && (s8)lbl_10_data_2B4[pos] == 0) {
step = 1;
}
count.value = __abs((s16)step);
dir = sel_sign(step);
while (count.value-- > 0) {
next = pos + dir;
pos = next > 110 ? 0 : (next < 0 ? 110 : next);
if ((cursor->unk_94 & 2) != 0) {
while ((s8)lbl_10_data_2B4[pos] == 0) {
next = pos + dir;
pos = next > 110 ? 0 : (next < 0 ? 110 : next);
}
}
}
cursor->unk_8E = pos;
cursor->unk_90 = cursor->unk_8E;
} else {
i = step;
do {
blocked = 0;
next = cursor->unk_8E + step;
cursor->unk_8E = next > 5 ? blocked : (next < 0 ? 5 : next);
cursor->unk_90 = fn_1_12EF24(cursor->unk_8C, cursor->unk_8E);
if (cursor->unk_90 == -1 && step == 0) {
step = 1;
}
if (cursor->unk_8C == 5) {
tmp_ra6 = cursor->unk_8E;
if ((tmp_ra6 == 5 && fn_1_F89E4(0) == 0) ||
(cursor->unk_8E != 5 && fn_1_F89E4(cursor->unk_8E + 1) == 0)) {
blocked = 1;
if (step == 0) {
step = blocked;
}
}
}
i++;
if (cursor->unk_90 != -1 && (s8)lbl_10_data_2B4[cursor->unk_90] != 0 && blocked == 0) {
break;
}
} while (i < 6);
}
if ((*((struct fn_10_AB98_SelState *)&lbl_1_bss_8B3A0)).value != 1) {
fn_10_C594();
}
if ((*((struct fn_10_AB98_SelState *)&lbl_1_bss_8B3A0)).value != 1 && (cursor->unk_94 & 0x80000000) == 0) {
fn_1_7B2E8(cursor->unk_90);
}
}
void fn_10_AB98(fn_10_AB98_SelCursor *cursor) {
sel_move_cursor(cursor, 0);
}
/* fzgx:end fn_10_AB98 */

/* fzgx:begin fn_10_BD64 */
#define SEL_MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct Fn10BD64 {
    s16 unk0;
    s16 unk2;
    s16 value4;
    s16 value6;
    s16 unk8;
    u8 padA[0x8A];
    u32 flags94;
} Fn10BD64;

typedef struct {
    u8 pad0[0x94];
    u32 flags;
} SelGlobal;

extern u8 lbl_10_bss_4938E;
extern SelGlobal lbl_1_bss_8B3A0;

void fn_10_BD64(Fn10BD64 *self) {
    s32 value;

    switch (self->unk0) {
    case 0:
        self->value4 = 1;
        value = 30;
        if (self->flags94 & 0x2) {
            value = *(s8 *)&lbl_10_bss_4938E;
        }
        self->value6 = value;
        break;
    case 1:
        if (lbl_1_bss_8B3A0.flags & 0x200) {
            self->value6 = SEL_MAX(1, SEL_MAX(self->value6, SEL_MAX(self->value4, 1)));
        } else {
            self->value6 = self->value4;
        }
        break;
    case 2:
        self->value4 = 1;
        self->value6 = 1;
        break;
    case 3:
        self->value4 = 1;
        self->value6 = 1;
        break;
    case 4:
        self->value6 = 30;
        self->value4 = 1;
        self->unk8 = 1;
        break;
    case 5:
        self->value4 = 1;
        self->value6 = 1;
        self->unk8 = 1;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    default:
        break;
    }

    if (self->value4 <= 1) {
        self->flags94 |= 0x20000000;
        return;
    }
    self->flags94 &= 0xDFFFFFFF;
    if (self->value4 == 2) {
        self->flags94 |= 0x00040000;
        return;
    }
    self->flags94 &= ~0x00040000;
}
/* fzgx:end fn_10_BD64 */

/* fzgx:begin fn_10_BEF0 */
// fn_10_BEF0: empty in retail (single blr).
void fn_10_BEF0(void) {
}
/* fzgx:end fn_10_BEF0 */

/* fzgx:begin fn_10_BEF4 */
// fn_10_BEF4: empty in retail (single blr).
void fn_10_BEF4(void) {
}
/* fzgx:end fn_10_BEF4 */

/* fzgx:begin fn_10_BEF8 */
#define SEL_MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct {
    s16 unk0;
    u8 pad2[2];
    s16 field4;
    s16 field6;
    s16 field8;
    u8 padA[0x8A];
    u32 flags;
} SelState;

typedef struct {
    u8 pad0[0x94];
    u32 flags;
} SelGlobal;

extern u8 lbl_10_bss_4938E;
extern SelGlobal lbl_1_bss_8B3A0;

void fn_10_BEF8(SelState *state) {
    s32 value;

    switch (state->unk0) {
    case 0:
        state->field4 = 1;
        value = 30;
        if (state->flags & 0x2) {
            value = *(s8 *)&lbl_10_bss_4938E;
        }
        state->field6 = value;
        break;
    case 1:
        if (lbl_1_bss_8B3A0.flags & 0x200) {
            state->field6 = SEL_MAX(1, SEL_MAX(state->field6, SEL_MAX(state->field4, 1)));
        } else {
            state->field6 = state->field4;
        }
        break;
    case 2:
        state->field4 = 1;
        state->field6 = 1;
        break;
    case 3:
        state->field4 = 1;
        state->field6 = 1;
        break;
    case 4:
        state->field6 = 30;
        state->field4 = 1;
        state->field8 = 1;
        break;
    case 5:
        state->field4 = 1;
        state->field6 = 1;
        state->field8 = 1;
        break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    default:
        break;
    }

    if (state->field4 <= 1) {
        state->flags |= 0x20000000;
        return;
    }
    state->flags &= 0xDFFFFFFF;
    if (state->field4 == 2) {
        state->flags |= 0x00040000;
        return;
    }
    state->flags &= ~0x00040000;
}
/* fzgx:end fn_10_BEF8 */

/* fzgx:begin fn_10_C084 */
#define SEL_MAX(x, y) ((x) > (y) ? (x) : (y))

typedef struct SelState {
    short value;
    unsigned char pad_02[2];
    short minimum;
    short maximum;
    short extra;
    unsigned char pad_0A[0x8A];
    unsigned int flags;
} SelState;

typedef struct SelGlobal {
    unsigned char pad_0094[0x94];
    unsigned int flags;
} SelGlobal;

extern unsigned char jumptable_10_data_8AC[48];
extern unsigned char lbl_10_bss_4938E;
extern SelGlobal lbl_1_bss_8B3A0;

void fn_10_C084(SelState *state) {
    int value;

    switch (state->value) {
    case 1:
    case 11:
        state->minimum = 1;
        value = 30;
        if (state->flags & 0x2) {
            value = *(signed char *)&lbl_10_bss_4938E;
        }
        state->maximum = value;
        break;
    case 0:
        if (lbl_1_bss_8B3A0.flags & 0x200) {
            state->maximum = SEL_MAX(1, SEL_MAX(state->maximum, SEL_MAX(state->minimum, 1)));
        } else {
            state->maximum = state->minimum;
        }
        break;
    case 2:
        state->minimum = 1;
        state->maximum = 1;
        break;
    case 3:
        state->minimum = 1;
        state->maximum = 1;
        break;
    case 9:
        state->maximum = 30;
        state->minimum = 1;
        state->extra = 1;
        break;
    case 10:
        state->minimum = 1;
        state->maximum = 1;
        state->extra = 1;
        break;
    default:
        break;
    }

    if (state->minimum <= 1) {
        state->flags |= 0x20000000;
        return;
    }
    state->flags &= 0xDFFFFFFF;
    if (state->minimum == 2) {
        state->flags |= 0x00040000;
        return;
    }
    state->flags &= ~0x00040000;
}
/* fzgx:end fn_10_C084 */

/* fzgx:begin fn_10_C210 */
typedef struct SelOwner {
    unsigned char pad_00A4[0xA4];
    void *entries;
} SelOwner;

typedef struct SelEntry {
    unsigned char pad_0014[0x14];
    short value;
    unsigned char pad_0024[0x0E];
    unsigned char pad_0032[0x70];
} SelEntry;

extern void fn_80008BEC(void *dst, int value, int size);

void fn_10_C210(SelOwner *owner, int index) {
    SelEntry *entry = (SelEntry *)owner->entries + (short)(index - 0xE);
    entry->value = 0;
    fn_80008BEC((unsigned char *)entry + 0x24, 0, 0x70);
}
/* fzgx:end fn_10_C210 */

/* fzgx:begin fn_10_C258 */
typedef struct SelContext {
    u8 pad[0xa4];
    u8 *entries;
} SelContext;

s16 fn_10_C258(SelContext *self, s32 index) {
    return *(s16 *)(self->entries + (s16)(index - 14) * 0x94 + 0x14);
}
/* fzgx:end fn_10_C258 */

/* fzgx:begin fn_10_C274 */
typedef struct {
    u8 _pad_00[0xa4];
    u8 *entries;
} SelObject;

void fn_10_C274(SelObject *object, int index) {
    index = (s16)(index - 0xe);
    *(s16 *)(object->entries + index * 0x94 + 0x14) += 1;
}
/* fzgx:end fn_10_C274 */

/* fzgx:begin fn_10_C298 */
typedef struct SelObject {
    u8 _pad_a4[0xa4];
    u8 *entries;
} SelObject;

void fn_10_C298(SelObject *self, int index) {
    s16 *value = (s16 *)(self->entries + (s16)(index - 0xe) * 0x94 + 0x14);
    (*value)--;
}
/* fzgx:end fn_10_C298 */

/* fzgx:begin fn_10_C2BC */
extern u8 lbl_10_data_57C[32];
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_5565C[2];
extern u32 lbl_10_bss_49384;
extern u32 lbl_10_bss_14;
extern u32 lbl_801A6410;

extern u32 fn_1_4630(u32, u32, u8 *, u32);
extern void fn_1_130EE8(u32, u32);

void fn_10_C2BC(void) {
    u32 value;

    value = fn_1_4630(lbl_801A6410, 0x20700, lbl_10_data_57C, 0x1766);
    lbl_10_bss_5565C[0] = value;
    fn_1_130EE8(lbl_10_bss_49384, lbl_10_bss_49388);
    lbl_10_bss_14 = -1;
}
/* fzgx:end fn_10_C2BC */

/* fzgx:begin fn_10_C328 pool */
typedef struct {
    u32 unk_0;
    u32 unk_4;
    s16 unk_8;
    s16 unk_A;
    u8 unk_C;
    u8 pad_D[7];
    u32 unk_10;
} Obj_10_bss_0;

typedef struct {
    u8 pad_0[0x94];
    u32 unk_94;
    u8 pad_98[0xA8];
    u32 unk_140;
} GState;

extern u32 lbl_10_bss_3C0[74736];
extern GState lbl_1_bss_8B3A0;
extern u16 lbl_1_bss_96A;

extern s32 fn_1_1310E0(void);
extern int fn_1_4C10(void);
extern void fn_1_1280(u32);
extern void fn_1_4A00(s32, u8, u32);
extern void fn_1_12F10C(void *);
extern void fn_1_131084(u32, s32);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_10_bss_0[10];
s16 lbl_10_bss_0__fzgx_offset_A;
u32 lbl_10_bss_0__fzgx_offset_C[2];
s32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 fzgx_obj_lbl_10_bss_4EEC0[2592];
u32 fzgx_obj_lbl_10_bss_51740;
u32 fzgx_obj_lbl_10_bss_51744;
u8 fzgx_obj_lbl_10_bss_51748[6];
u16 fzgx_obj_lbl_10_bss_5174E;
u8 fzgx_obj_lbl_10_bss_51750;
u8 fzgx_pad_51751;
u8 fzgx_obj_lbl_10_bss_51752;
u8 fzgx_obj_lbl_10_bss_51752__b1;
u8 fzgx_obj_lbl_10_bss_51752__b2;
u8 fzgx_obj_lbl_10_bss_51752__b3;
u8 fzgx_obj_lbl_10_bss_51752__b4;
u8 fzgx_obj_lbl_10_bss_51752__b5;
u8 fzgx_obj_lbl_10_bss_51752__b6;
u8 fzgx_obj_lbl_10_bss_51752__b7;
u8 fzgx_obj_lbl_10_bss_51752__b8;
u8 fzgx_obj_lbl_10_bss_51752__b9;
u8 fzgx_obj_lbl_10_bss_51752__b10;
u8 fzgx_obj_lbl_10_bss_51752__b11;
u8 fzgx_obj_lbl_10_bss_51752__b12;
u8 fzgx_obj_lbl_10_bss_51752__b13;
u8 fzgx_obj_lbl_10_bss_51752__b14;
u8 fzgx_obj_lbl_10_bss_51752__b15;
u8 fzgx_obj_lbl_10_bss_51752__b16;
u8 fzgx_obj_lbl_10_bss_51752__b17;
u8 fzgx_obj_lbl_10_bss_51752__b18;
u8 fzgx_obj_lbl_10_bss_51752__b19;
u8 fzgx_obj_lbl_10_bss_51752__b20;
u8 fzgx_obj_lbl_10_bss_51752__b21;
u8 fzgx_obj_lbl_10_bss_51752__b22;
u8 fzgx_obj_lbl_10_bss_51752__b23;
u8 fzgx_obj_lbl_10_bss_51752__b24;
u8 fzgx_obj_lbl_10_bss_51752__b25;
u8 fzgx_obj_lbl_10_bss_51752__b26;
u8 fzgx_obj_lbl_10_bss_51752__b27;
u8 fzgx_obj_lbl_10_bss_51752__b28;
u8 fzgx_obj_lbl_10_bss_51752__b29;
u8 fzgx_obj_lbl_10_bss_51752__b30;
u8 fzgx_obj_lbl_10_bss_51752__b31;
u8 fzgx_obj_lbl_10_bss_51752__b32;
u8 fzgx_obj_lbl_10_bss_51752__b33;
u8 fzgx_obj_lbl_10_bss_51752__b34;
u8 fzgx_obj_lbl_10_bss_51752__b35;
u8 fzgx_obj_lbl_10_bss_51752__b36;
u8 fzgx_obj_lbl_10_bss_51752__b37;
u8 fzgx_obj_lbl_10_bss_51752__b38;
u8 fzgx_obj_lbl_10_bss_51752__b39;
u8 fzgx_obj_lbl_10_bss_51752__b40;
u8 fzgx_obj_lbl_10_bss_51752__b41;
u8 fzgx_obj_lbl_10_bss_51752__b42;
u8 fzgx_obj_lbl_10_bss_51752__b43;
u8 fzgx_obj_lbl_10_bss_51752__b44;
u8 fzgx_obj_lbl_10_bss_51752__b45;
u8 fzgx_obj_lbl_10_bss_51752__b46;
u8 fzgx_obj_lbl_10_bss_51752__b47;
u8 fzgx_obj_lbl_10_bss_51752__b48;
u8 fzgx_obj_lbl_10_bss_51752__b49;
u8 fzgx_obj_lbl_10_bss_51752__b50;
u8 fzgx_obj_lbl_10_bss_51752__b51;
u8 fzgx_obj_lbl_10_bss_51752__b52;
u8 fzgx_obj_lbl_10_bss_51752__b53;
u32 fzgx_obj_lbl_10_bss_51788[25];
u32 fzgx_obj_lbl_10_bss_517EC[100];
u32 fzgx_obj_lbl_10_bss_5197C[128];
u32 fzgx_obj_lbl_10_bss_51B7C[1248];
u32 fzgx_obj_lbl_10_bss_52EFC[2496];
u32 fzgx_obj_lbl_10_bss_555FC;
u8 fzgx_obj_lbl_10_bss_55600;
u8 fzgx_obj_lbl_10_bss_55601;
u8 fzgx_obj_lbl_10_bss_55601__b1;
u8 fzgx_obj_lbl_10_bss_55601__b2;
u8 fzgx_obj_lbl_10_bss_55601__b3;
u8 fzgx_obj_lbl_10_bss_55601__b4;
u8 fzgx_obj_lbl_10_bss_55601__b5;
u8 fzgx_obj_lbl_10_bss_55601__b6;
u16 fzgx_obj_lbl_10_bss_55608;
u32 fzgx_obj_lbl_10_bss_5560C[20];
u32 fzgx_obj_lbl_10_bss_5565C;
s32 lbl_10_bss_5565C__fzgx_offset_4;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = lbl_10_bss_0__fzgx_offset_A;
    s = lbl_10_bss_0__fzgx_offset_C[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
    s = fzgx_obj_lbl_10_bss_3C0[0];
    s = fzgx_obj_lbl_10_bss_49380;
    s = fzgx_obj_lbl_10_bss_49384;
    s = fzgx_obj_lbl_10_bss_49388;
    s = fzgx_obj_lbl_10_bss_4938C;
    s = fzgx_obj_lbl_10_bss_4938E;
    s = fzgx_obj_lbl_10_bss_4938F;
    s = fzgx_obj_lbl_10_bss_49390[0];
    s = fzgx_obj_lbl_10_bss_493A0[0];
    s = fzgx_obj_lbl_10_bss_4EEC0[0];
    s = fzgx_obj_lbl_10_bss_51740;
    s = fzgx_obj_lbl_10_bss_51744;
    s = fzgx_obj_lbl_10_bss_51748[0];
    s = fzgx_obj_lbl_10_bss_5174E;
    s = fzgx_obj_lbl_10_bss_51750;
    s = fzgx_pad_51751;
    s = fzgx_obj_lbl_10_bss_51752;
    s = fzgx_obj_lbl_10_bss_51752__b1;
    s = fzgx_obj_lbl_10_bss_51752__b2;
    s = fzgx_obj_lbl_10_bss_51752__b3;
    s = fzgx_obj_lbl_10_bss_51752__b4;
    s = fzgx_obj_lbl_10_bss_51752__b5;
    s = fzgx_obj_lbl_10_bss_51752__b6;
    s = fzgx_obj_lbl_10_bss_51752__b7;
    s = fzgx_obj_lbl_10_bss_51752__b8;
    s = fzgx_obj_lbl_10_bss_51752__b9;
    s = fzgx_obj_lbl_10_bss_51752__b10;
    s = fzgx_obj_lbl_10_bss_51752__b11;
    s = fzgx_obj_lbl_10_bss_51752__b12;
    s = fzgx_obj_lbl_10_bss_51752__b13;
    s = fzgx_obj_lbl_10_bss_51752__b14;
    s = fzgx_obj_lbl_10_bss_51752__b15;
    s = fzgx_obj_lbl_10_bss_51752__b16;
    s = fzgx_obj_lbl_10_bss_51752__b17;
    s = fzgx_obj_lbl_10_bss_51752__b18;
    s = fzgx_obj_lbl_10_bss_51752__b19;
    s = fzgx_obj_lbl_10_bss_51752__b20;
    s = fzgx_obj_lbl_10_bss_51752__b21;
    s = fzgx_obj_lbl_10_bss_51752__b22;
    s = fzgx_obj_lbl_10_bss_51752__b23;
    s = fzgx_obj_lbl_10_bss_51752__b24;
    s = fzgx_obj_lbl_10_bss_51752__b25;
    s = fzgx_obj_lbl_10_bss_51752__b26;
    s = fzgx_obj_lbl_10_bss_51752__b27;
    s = fzgx_obj_lbl_10_bss_51752__b28;
    s = fzgx_obj_lbl_10_bss_51752__b29;
    s = fzgx_obj_lbl_10_bss_51752__b30;
    s = fzgx_obj_lbl_10_bss_51752__b31;
    s = fzgx_obj_lbl_10_bss_51752__b32;
    s = fzgx_obj_lbl_10_bss_51752__b33;
    s = fzgx_obj_lbl_10_bss_51752__b34;
    s = fzgx_obj_lbl_10_bss_51752__b35;
    s = fzgx_obj_lbl_10_bss_51752__b36;
    s = fzgx_obj_lbl_10_bss_51752__b37;
    s = fzgx_obj_lbl_10_bss_51752__b38;
    s = fzgx_obj_lbl_10_bss_51752__b39;
    s = fzgx_obj_lbl_10_bss_51752__b40;
    s = fzgx_obj_lbl_10_bss_51752__b41;
    s = fzgx_obj_lbl_10_bss_51752__b42;
    s = fzgx_obj_lbl_10_bss_51752__b43;
    s = fzgx_obj_lbl_10_bss_51752__b44;
    s = fzgx_obj_lbl_10_bss_51752__b45;
    s = fzgx_obj_lbl_10_bss_51752__b46;
    s = fzgx_obj_lbl_10_bss_51752__b47;
    s = fzgx_obj_lbl_10_bss_51752__b48;
    s = fzgx_obj_lbl_10_bss_51752__b49;
    s = fzgx_obj_lbl_10_bss_51752__b50;
    s = fzgx_obj_lbl_10_bss_51752__b51;
    s = fzgx_obj_lbl_10_bss_51752__b52;
    s = fzgx_obj_lbl_10_bss_51752__b53;
    s = fzgx_obj_lbl_10_bss_51788[0];
    s = fzgx_obj_lbl_10_bss_517EC[0];
    s = fzgx_obj_lbl_10_bss_5197C[0];
    s = fzgx_obj_lbl_10_bss_51B7C[0];
    s = fzgx_obj_lbl_10_bss_52EFC[0];
    s = fzgx_obj_lbl_10_bss_555FC;
    s = fzgx_obj_lbl_10_bss_55600;
    s = fzgx_obj_lbl_10_bss_55601;
    s = fzgx_obj_lbl_10_bss_55601__b1;
    s = fzgx_obj_lbl_10_bss_55601__b2;
    s = fzgx_obj_lbl_10_bss_55601__b3;
    s = fzgx_obj_lbl_10_bss_55601__b4;
    s = fzgx_obj_lbl_10_bss_55601__b5;
    s = fzgx_obj_lbl_10_bss_55601__b6;
    s = fzgx_obj_lbl_10_bss_55608;
    s = fzgx_obj_lbl_10_bss_5560C[0];
    s = fzgx_obj_lbl_10_bss_5565C;
    s = lbl_10_bss_5565C__fzgx_offset_4;
}
#pragma section code_type ".text"

void fn_10_C328(void) {
    s32 v;
    s16 dir;

    if (fn_1_1310E0() != 0) {
        return;
    }

    if (fzgx_obj_lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    {
        s32 ok;
        if ((lbl_1_bss_8B3A0.unk_140 & 0x80000000)
            && !(lbl_1_bss_8B3A0.unk_140 & 0x40000000)
            && !(lbl_1_bss_8B3A0.unk_94 & 0x8)) {
            ok = 1;
        } else if (fn_1_4C10() != 0) {
            ok = 1;
        } else {
            ok = 0;
        }
        if (ok != 0) {
            return;
        }
    }

    v = fzgx_obj_lbl_10_bss_14;
    if (v != -1) {
        fzgx_obj_lbl_10_bss_14 = -1;
        lbl_1_bss_96A = (u16)v;
        return;
    }

    if (lbl_10_bss_5565C__fzgx_offset_4 != 0) {
        s16 a = lbl_10_bss_0__fzgx_offset_A;
        lbl_10_bss_5565C__fzgx_offset_4 = 0;
        if (a != 0) {
            fzgx_obj_lbl_10_bss_14 = 0x14;
            fn_1_1280(1);
        } else {
            fzgx_obj_lbl_10_bss_14 = 0x10;
            fn_1_4A00(0, (u8)fzgx_obj_lbl_10_bss_4938C, fzgx_obj_lbl_10_bss_49388);
            fzgx_obj_lbl_10_bss_51744 = 0;
        }
        fn_1_12F10C(lbl_10_bss_3C0);
    } else {
        s16 a = lbl_10_bss_0__fzgx_offset_A;
        lbl_10_bss_5565C__fzgx_offset_4 = 1;
        dir = 4;
        if (a & 1) {
            lbl_10_bss_0__fzgx_offset_A = a & ~1;
            dir = 0;
        } else if (a & 2) {
            lbl_10_bss_0__fzgx_offset_A = a & ~2;
            dir = 1;
        }
        fn_1_131084(fzgx_obj_lbl_10_bss_5565C, dir);
    }
}
/* fzgx:end fn_10_C328 */

/* fzgx:begin fn_10_C49C */
extern u32 lbl_10_bss_5565C[2];
extern u32 lbl_10_bss_3C0[74736];
extern u8 lbl_10_bss_4938F;
extern u8 lbl_10_bss_49390[16];
extern u8 lbl_10_data_57C[32];
extern u32 lbl_801A6410;

extern int fn_1_1317B4(void);
extern int fn_1_B7C5C(void);
extern void fn_80008BA8(void *, u32, u32);
extern void fn_1_131004(void);
extern void fn_1_46B4(u32, u32, void *, u32);

void fn_10_C49C(void) {
    if (fn_1_1317B4() == 0) {
        if (fn_1_B7C5C() == 0) {
            fn_80008BA8(lbl_10_bss_3C0, lbl_10_bss_5565C[0], 0x20700);
            lbl_10_bss_4938F = 1;
        } else {
            lbl_10_bss_4938F = 0;
        }
    }
    if (fn_1_1317B4() == 1) {
        if (fn_1_B7C5C() == 0) {
            fn_80008BA8(lbl_10_bss_3C0 + 0x81c0, lbl_10_bss_5565C[0], 0x20700);
            lbl_10_bss_49390[0] = 1;
        } else {
            lbl_10_bss_49390[0] = 0;
        }
    }
    fn_1_131004();
    fn_1_46B4(lbl_801A6410, lbl_10_bss_5565C[0], lbl_10_data_57C, 0x17a0);
}
/* fzgx:end fn_10_C49C */

/* fzgx:begin fn_10_C594 */
extern void fn_1_451E4(void);
extern void fn_1_3308(void);
extern void fn_1_D3214(void);
extern void fn_8001AF64(void);
extern s32 fn_1_467F4(void);
extern s32 fn_1_13018(void);
extern void fn_8006FDEC(void);

void fn_10_C594(void) {
    // The retail loop checks its continuation conditions before entering the body.
    goto check;
body:
    fn_1_451E4();
    fn_1_3308();
    fn_1_D3214();
    fn_8001AF64();
check:
    if (fn_1_467F4() != 0) {
        goto body; // Continue the irreducible retail loop.
    }
    if (fn_1_13018() != 0) {
        goto body; // Continue the irreducible retail loop.
    }
    fn_8006FDEC();
}
/* fzgx:end fn_10_C594 */

/* fzgx:begin fn_10_C5E0 */
extern u8 lbl_10_data_57C[32];
extern u32 lbl_801A6410;

extern u32 fn_1_4404(void *obj);
extern void fn_1_46B4(u32, u32, void *, u32);
extern void fn_80008E84(u32);

struct Fn10C5E0 {
    u32 field_0;
};

void fn_10_C5E0(struct Fn10C5E0 *self) {
    u32 result;
    result = fn_1_4404(self);
    if (self->field_0 + 0x10000 != 0xffff) {
        fn_1_46B4(lbl_801A6410, self->field_0, lbl_10_data_57C, 0x181e);
        self->field_0 = 0xffffffff;
    }
    fn_80008E84(result);
}
/* fzgx:end fn_10_C5E0 */

/* fzgx:begin fn_10_C654 */
extern u32 fn_1_46C60(void);

void fn_10_C654(u32 *value) {
    *value = fn_1_46C60();
}
/* fzgx:end fn_10_C654 */

/* fzgx:begin fn_10_C684 */
extern u32 lbl_10_bss_55668;

u32 fn_10_C684(void) {
    return lbl_10_bss_55668;
}
/* fzgx:end fn_10_C684 */

/* fzgx:begin fn_10_C694 */
extern u8 lbl_10_bss_5566C;

u8 fn_10_C694(void) {
    return lbl_10_bss_5566C;
}
/* fzgx:end fn_10_C694 */

/* fzgx:begin fn_10_C6A4 */
extern u32 lbl_10_bss_55664;
extern s32 lbl_1_bss_7180C;
extern u8 lbl_1_bss_718E0;
extern u8 fn_1_B7C00(void);
extern int fn_1_B7E98(int arg0);
extern int fn_1_B7C5C(void);
extern s32 fn_1_B7C6C(u32);
extern u32 fn_1_B7CD4(void);
extern void fn_1_AA6D8(int arg0, int arg1, void *arg2);
extern void fn_1_F79C8(void);
extern void fn_1_B7F24(void);
extern void fn_80008BEC(void *dst, int value, u32 size);
extern u32 lbl_10_bss_55668;
extern u8 lbl_10_bss_5566C;
extern u32 lbl_10_bss_3C0[74736];

void fn_10_C6A4(void) {
    struct { u8 type; u8 pad[3]; u32 code; u32 unk_8; void *data; u8 rest[20]; } loc_8;
    if (fn_1_B7C00() != 0) return;
    if ((s32)lbl_1_bss_7180C != 0 && fn_1_B7E98(1) != 0) {
        if (__rlwnm(lbl_10_bss_55664, 5, 31, 31)) return;
        if (__rlwnm(lbl_10_bss_55664, 6, 31, 31)) return;
        if ((s32)lbl_10_bss_55664 == 0) {
            lbl_10_bss_55664 = (s32)lbl_10_bss_55664 | 0x80000000;
        } else {
            switch ((s32)__cntlzw((s32)lbl_10_bss_55664)) {
            case 0:
                if (fn_1_B7C6C(1) == 0) {
                    lbl_10_bss_5566C = 1;
                    fn_80008BEC(&loc_8, 0, 36);
                    loc_8.type = 1;
                    loc_8.code = 0xA004;
                    loc_8.data = &lbl_1_bss_718E0;
                    fn_1_AA6D8(2, 4, &loc_8);
                    lbl_10_bss_55664 &= 0x7FFFFFFF;
                    lbl_10_bss_55664 |= 0x20000000;
                }
                break;
            case 2:
                lbl_10_bss_55668 = fn_1_B7CD4();
                fn_1_F79C8();
                if ((s32)fn_1_B7C5C() == 0) {
                    fn_80008BEC(&loc_8, 0, 36);
                    loc_8.type = 3;
                    loc_8.code = 0xA004;
                    loc_8.data = (u8 *)&lbl_10_bss_3C0 + 0x20700;
                    fn_1_AA6D8(2, 4, &loc_8);
                    lbl_10_bss_55664 &= 0xDFFFFFFF;
                    lbl_10_bss_55664 |= 0x10000000;
                }
                break;
            case 3:
                lbl_10_bss_55664 = (s32)lbl_10_bss_55664 & 0xEFFFFFFF;
                lbl_10_bss_55664 |= 0x08000000;
                break;
            }
        }
    } else {
        lbl_10_bss_55664 = 0;
        lbl_10_bss_5566C = 0;
        lbl_10_bss_55664 |= 0x80000000;
        fn_80008BEC(&lbl_10_bss_3C0, 0, 0x40E00);
        lbl_10_bss_55668 = 0;
        fn_1_B7F24();
    }
}
/* fzgx:end fn_10_C6A4 */

/* fzgx:begin fn_10_C8A8 */
extern u32 lbl_10_bss_49388;
extern void fn_1_4A00(u32, u32, u32);
extern void fn_1_12F1E8(u32);

void fn_10_C8A8(void) {
    fn_1_4A00(1, 0xf, lbl_10_bss_49388);
    fn_1_12F1E8(0x1e0);
}
/* fzgx:end fn_10_C8A8 */

/* fzgx:begin fn_10_C8E4 */
extern s32 lbl_1_bss_7180C;
extern u32 lbl_10_bss_55670[4];
extern s16 lbl_1_bss_96A;
extern void fn_10_CEC4(u32 arg0);
extern int fn_1_B7E98(int arg0);

void fn_10_C8E4(void) {
    if (lbl_1_bss_7180C == 0) {
        fn_10_CEC4(lbl_10_bss_55670[0]);
    } else if (fn_1_B7E98(1) == 0) {
        fn_10_CEC4(lbl_10_bss_55670[0]);
    } else {
        lbl_1_bss_96A = 0x1c;
    }
}
/* fzgx:end fn_10_C8E4 */

/* fzgx:begin fn_10_C954 */
// fn_10_C954: empty in retail (single blr).
void fn_10_C954(void) {
}
/* fzgx:end fn_10_C954 */

/* fzgx:begin fn_10_C958 */
extern void fn_80008BEC(void *dst, int value, int size);
extern void fn_1_AA6D8(int arg0, int arg1, void *data);
extern u8 lbl_1_bss_718E0;

typedef struct Fn10C958Data {
    u8 unk00;
    u8 unk01[3];
    u32 unk04;
    u8 unk08[4];
    void *unk0c;
    u8 unk10[20];
} Fn10C958Data;

void fn_10_C958(void) {
    Fn10C958Data data;

    fn_80008BEC(&data, 0, 0x24);
    data.unk00 = 1;
    data.unk04 = 0x2004;
    data.unk0c = &lbl_1_bss_718E0;
    fn_1_AA6D8(2, 4, &data);
}
/* fzgx:end fn_10_C958 */

/* fzgx:begin fn_10_C9B0 */
extern u8 fn_1_B7C00(void);
extern int fn_1_B7C5C(void);
extern void fn_1_F79C8(void);
extern s16 lbl_1_bss_96A;

void fn_10_C9B0(void) {
    if (!fn_1_B7C00()) {
        if (!fn_1_B7C5C()) {
            fn_1_F79C8();
        }
        lbl_1_bss_96A = 0x1d;
    }
}
/* fzgx:end fn_10_C9B0 */

/* fzgx:begin fn_10_C9F4 */
// fn_10_C9F4: empty in retail (single blr).
void fn_10_C9F4(void) {
}
/* fzgx:end fn_10_C9F4 */

/* fzgx:begin fn_10_C9F8 */
extern u32 lbl_10_bss_3C0[74736];
extern void fn_80008BEC(void *dst, int value, u32 size);
extern void fn_1_AA6D8(int arg0, int arg1, void *arg2);

void fn_10_C9F8(void) {
    struct {
        u8 kind;
        u8 pad[3];
        u32 value;
        u8 pad2[4];
        u32 buffer;
        u8 tail[0x18];
    } local;

    fn_80008BEC(&local, 0, 0x24);
    local.kind = 3;
    local.value = 0x2004;
    local.buffer = (u32)((u8 *)lbl_10_bss_3C0 + 0x20700);
    fn_1_AA6D8(2, 1, &local);
}
/* fzgx:end fn_10_C9F8 */

/* fzgx:begin fn_10_CA58 */
extern u32 lbl_10_bss_55670[4];
extern u8 fn_1_B7C00(void);
extern void fn_10_CEC4(u32);

void fn_10_CA58(void) {
    if (!fn_1_B7C00()) {
        fn_10_CEC4(lbl_10_bss_55670[0]);
    }
}
/* fzgx:end fn_10_CA58 */

/* fzgx:begin fn_10_CA90 */
// fn_10_CA90: empty in retail (single blr).
void fn_10_CA90(void) {
}
/* fzgx:end fn_10_CA90 */

/* fzgx:begin fn_10_CA94 */
extern char lbl_10_data_8DC[18];
extern void fn_10_1B660(void);
extern void *fn_1_435C(void *);
extern void *fn_1_3F8C(void *, void *, u32, u32);
extern void fn_1_12F1E8(s32);
extern void fn_1_4A00(u32, u32, void *);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_10_bss_0[5];
u32 fzgx_obj_lbl_10_bss_14;
u16 fzgx_obj_lbl_10_bss_18;
u16 fzgx_obj_lbl_10_bss_1A;
u32 fzgx_obj_lbl_10_bss_1C[233];
u32 fzgx_obj_lbl_10_bss_3C0[74736];
u32 fzgx_obj_lbl_10_bss_49380;
u32 fzgx_obj_lbl_10_bss_49384;
u32 fzgx_obj_lbl_10_bss_49388;
s16 fzgx_obj_lbl_10_bss_4938C;
u8 fzgx_obj_lbl_10_bss_4938E;
u8 fzgx_obj_lbl_10_bss_4938F;
u32 fzgx_obj_lbl_10_bss_49390[4];
u32 fzgx_obj_lbl_10_bss_493A0[5832];
u32 fzgx_obj_lbl_10_bss_4EEC0[2592];
u32 fzgx_obj_lbl_10_bss_51740;
u32 fzgx_obj_lbl_10_bss_51744;

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_10_bss_0[0];
    s = fzgx_obj_lbl_10_bss_14;
    s = fzgx_obj_lbl_10_bss_18;
    s = fzgx_obj_lbl_10_bss_1A;
    s = fzgx_obj_lbl_10_bss_1C[0];
    s = fzgx_obj_lbl_10_bss_3C0[0];
    s = fzgx_obj_lbl_10_bss_49380;
    s = fzgx_obj_lbl_10_bss_49384;
    s = fzgx_obj_lbl_10_bss_49388;
    s = fzgx_obj_lbl_10_bss_4938C;
    s = fzgx_obj_lbl_10_bss_4938E;
    s = fzgx_obj_lbl_10_bss_4938F;
    s = fzgx_obj_lbl_10_bss_49390[0];
    s = fzgx_obj_lbl_10_bss_493A0[0];
    s = fzgx_obj_lbl_10_bss_4EEC0[0];
    s = fzgx_obj_lbl_10_bss_51740;
    s = fzgx_obj_lbl_10_bss_51744;
}
#pragma section code_type ".text"

void fn_10_CA94(void) {
    fn_1_435C((void *)fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51740 = (u32)fn_1_3F8C(lbl_10_data_8DC, fn_10_1B660, 0, 8);
    fn_1_12F1E8(480);
    fn_1_4A00(1, (u8)fzgx_obj_lbl_10_bss_4938C, (void *)fzgx_obj_lbl_10_bss_49388);
    fzgx_obj_lbl_10_bss_51744 = 0;
    fzgx_obj_lbl_10_bss_14 = -1;
}
/* fzgx:end fn_10_CA94 */

/* fzgx:begin fn_10_CB20 */
typedef struct S9F8 {
    u8 pad_0[8];
    u16 f8;
    u8 pad_1[0x14 - 0xA];
} S9F8;

typedef struct S9C8 {
    u8 pad_0[0xA];
    s8 fA;
    u8 pad_1[1];
} S9C8;

typedef struct SelState {
    u8 pad_0[0x94];
    u32 flags_94;
    u32 bits_98;
    u8 pad_9C[2];
    u8 idx_9E;
    u8 pad_9F[0xA1];
    u32 field_140;
} SelState;

extern s32 lbl_10_bss_14;
extern SelState lbl_1_bss_8B3A0;
extern u16 lbl_1_bss_96A;
extern S9C8 lbl_1_bss_9C8[];
extern S9F8 lbl_1_bss_9F8[];
extern s16 lbl_10_bss_4938C;
extern u32 lbl_10_bss_49388;
extern u32 lbl_10_bss_51744;
extern u32 lbl_1_bss_6EAB4;

extern s32 fn_1_4C10(void);
extern void fn_1_12F150(s16, u32, u32);
extern void fn_1_12F1E8(s32);
extern s32 fn_1_12F228(void);
extern void fn_1_4A00(s32, u32, u32);

void fn_10_CB20(void) {
    s32 ready;
    s16 i;
    u8 idx;

    if (lbl_10_bss_14 == -1) {
        fn_1_4C10();
    }

    if ((lbl_1_bss_8B3A0.field_140 & ((u32)1 << 31)) != 0 &&
        (lbl_1_bss_8B3A0.field_140 & ((u32)1 << 30)) == 0 &&
        (lbl_1_bss_8B3A0.flags_94 & 8) == 0) {
        ready = 1;
    } else if (fn_1_4C10() != 0) {
        ready = 1;
    } else {
        ready = 0;
    }

    if (ready != 0) {
        return;
    }

    if (lbl_10_bss_14 != -1) {
        s32 state = lbl_10_bss_14;
        lbl_10_bss_14 = -1;
        lbl_1_bss_96A = (u16)state;
        return;
    }

    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_9C8[i].fA != -1) {
            if (__rlwnm(lbl_1_bss_8B3A0.bits_98, (i + 1) & 31, 31, 31) &&
                ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.idx_9E].f8 >> 8) & 1) != 0) {
                fn_1_12F150(i, 2, 1);
            }
        }
    }

    if (((lbl_1_bss_9F8[lbl_1_bss_8B3A0.idx_9E].f8 >> 8) & 1) != 0) {
        fn_1_12F1E8(0);
    }

    for (i = 0; i < 4; i++) {
        if (lbl_1_bss_9C8[i].fA != -1) {
            if (__rlwnm(lbl_1_bss_8B3A0.bits_98, (i + 1) & 31, 31, 31) &&
                ((lbl_1_bss_9F8[lbl_1_bss_8B3A0.idx_9E].f8 >> 12) & 1) != 0) {
                fn_1_12F150(i, 2, 1);
            }
        }
    }

    idx = lbl_1_bss_8B3A0.idx_9E;
    if (((lbl_1_bss_9F8[idx].f8 >> 12) & 1) != 0 || fn_1_12F228() != 0) {
        lbl_10_bss_14 = 0x19;
        fn_1_12F1E8(0);
        fn_1_4A00(0, (u32)(u8)lbl_10_bss_4938C, lbl_10_bss_49388);
        lbl_10_bss_51744 = 0;
        if (lbl_10_bss_14 == 0xE) {
            lbl_1_bss_6EAB4 |= 0x24;
        }
    }
}
/* fzgx:end fn_10_CB20 */

/* fzgx:begin fn_10_CD90 */
struct fn_10_CD90_lbl_10_bss_51740 {
    u32 unk_0;
};

extern struct fn_10_CD90_lbl_10_bss_51740 lbl_10_bss_51740;
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);
extern u32 lbl_10_bss_49388;

void fn_10_CD90(u32 arg0) {
    u32 v0;
    u32 t0, t1;
    v0 = arg0;
    if ((s32)lbl_10_bss_51740.unk_0 != -1) {
    v0 = (u32)&lbl_10_bss_49388;
    v0 = *(u32 *)((u8 *)v0 + 0);
    t0 = fn_1_435C(v0);
    v0 = t0;
    v0 = (u32)&lbl_10_bss_51740;
    v0 = *(u32 *)((u8 *)v0 + 0);
    t1 = fn_1_426C(v0);
    v0 = t1;
    lbl_10_bss_51740.unk_0 = -1;
    }
}
/* fzgx:end fn_10_CD90 */

/* fzgx:begin fn_10_CDE8 */
extern u8 lbl_10_bss_0[];
extern char lbl_10_data_8F4[19];
extern void fn_10_13E18(void);

extern void fn_1_435C(void *resource);
extern void *fn_1_3F8C(char *data, void (*handler)(void), int arg2, int arg3);
extern void fn_1_4A00(int arg0, int arg1, void *resource);

void fn_10_CDE8(void) {
    u8 *state = (u8 *)lbl_10_bss_0 + 0x50000;
    void *registration;
    s16 mode;

    fn_1_435C(*(void **)(state - 0x6c78));
    registration = fn_1_3F8C(lbl_10_data_8F4, fn_10_13E18, 0, 8);
    mode = *(s16 *)(state - 0x6c74);
    *(void **)(state + 0x1740) = registration;
    fn_1_4A00(1, (u8)mode, *(void **)(state - 0x6c78));
    *(u32 *)(state + 0x1744) = 0;
}
/* fzgx:end fn_10_CDE8 */

/* fzgx:begin fn_10_CE5C */
extern u16 lbl_1_bss_96A;

void fn_10_CE5C(void) {
    lbl_1_bss_96A = 0xf;
}
/* fzgx:end fn_10_CE5C */

/* fzgx:begin fn_10_CE6C */
// Volatile preserves the retail's repeated sentinel accesses across calls.
extern volatile s32 lbl_10_bss_51740;
extern u32 lbl_10_bss_49388;

void fn_10_CE6C(void) {
    if (lbl_10_bss_51740 != -1) {
        fn_1_435C(lbl_10_bss_49388);
        fn_1_426C(lbl_10_bss_51740);
        lbl_10_bss_51740 = -1;
    }
}
/* fzgx:end fn_10_CE6C */

/* fzgx:begin fn_10_CEC4 */
extern u16 lbl_1_bss_96A;

void fn_10_CEC4(u32 flags) {
    u32 shift;
    u16 value;

    shift = 1;
    if (__rlwnm(flags, shift, 31, 31)) {
        value = 0x17;
    } else {
        shift = 2;
        if (__rlwnm(flags, shift, 31, 31)) {
            value = 0x19;
        } else {
            shift = 3;
            if (__rlwnm(flags, shift, 31, 31)) {
                value = 0x15;
            } else {
                shift = 4;
                if (__rlwnm(flags, shift, 31, 31) ||
                    (shift = 5, __rlwnm(flags, shift, 31, 31))) {
                    value = 0x0e;
                } else {
                    value = 0x17;
                }
            }
        }
    }
    lbl_1_bss_96A = value;
}
/* fzgx:end fn_10_CEC4 */

/* fzgx:begin fn_10_CF30 */
extern u32 lbl_10_bss_55670[4];

void fn_10_CF30(u32 shift) {
    lbl_10_bss_55670[0] |= (1u << 31) >> shift;
}
/* fzgx:end fn_10_CF30 */

/* fzgx:begin fn_10_CF50 */
extern u8 lbl_10_data_908[1016];
extern s16 lbl_1_bss_962;
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;

typedef void (*SelCallback)(void);

typedef struct SelEntry {
    u8 pad[0x20];
    SelCallback callback;
    u32 value_24;
    u32 value_28;
} SelEntry;

void fn_10_CF50(void) {
    SelEntry *entry;
    s32 index;

    entry = (SelEntry *)lbl_10_data_908;
    index = (s32)lbl_1_bss_962 - 0xd;
    entry += index;
    lbl_1_bss_71688 = entry->value_24;
    lbl_1_bss_7168C = entry->value_28;
    entry->callback();
}
/* fzgx:end fn_10_CF50 */

/* fzgx:begin fn_10_CFAC */
struct fn_10_CFAC_lbl_1_bss_8B3A0 {
    u8 pad_0[0x140];
    u32 unk_140;
    u16 unk_144;
    u16 unk_146;
    u16 unk_148;
};

extern struct fn_10_CFAC_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;

void fn_10_CFAC(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    lbl_1_bss_8B3A0.unk_140 = 0;
    lbl_1_bss_8B3A0.unk_140 |= 0x80000000;
    lbl_1_bss_8B3A0.unk_140 |= arg3;
    lbl_1_bss_8B3A0.unk_144 = arg0;
    lbl_1_bss_8B3A0.unk_146 = arg1;
    lbl_1_bss_8B3A0.unk_148 = arg2;
}
/* fzgx:end fn_10_CFAC */

/* fzgx:begin fn_10_CFDC */
typedef struct SelState {
    u8 _pad140[0x140];
    u32 flags;
    s16 step;
    s16 value;
    s16 limit;
} SelState;

extern SelState lbl_1_bss_8B3A0;

void fn_10_CFDC(void) {
    SelState *state = &lbl_1_bss_8B3A0;

    if ((state->flags & 0x80000000u) == 0) {
        return;
    }

    state->value += state->step;
    do {
        if (state->step > 0) {
            if (state->value >= state->limit) {
                break;
            }
        }
        if (state->step >= 0) {
            return;
        }
        if (state->value > lbl_1_bss_8B3A0.limit) {
            return;
        }
    } while (0);
    state->flags = 0;
}
/* fzgx:end fn_10_CFDC */

/* fzgx:begin fn_10_E034 */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct {
u8 pad_0[0x19];
u8 unk_19;
} Obj_1_bss_8B3A0_AtA4;
typedef struct {
s16 unk_0;
u8 pad_2[0x2];
s16 unk_4;
u8 pad_6[0x2];
s16 unk_8;
u8 pad_A[0x4];
s16 unk_E;
u8 pad_10[0x4];
u8 unk_14;
u8 pad_15[0x19];
s16 unk_2E;
u8 pad_30[0x5C];
s16 unk_8C;
u8 pad_8E[0x2];
s16 unk_90;
s16 unk_92;
u32 unk_94;
u8 pad_98[0x6];
u8 unk_9E;
u8 unk_9F;
u8 pad_A0[0x4];
Obj_1_bss_8B3A0_AtA4 *unk_A4;
u8 pad_A8[0x8];
s16 unk_B0;
s16 unk_B2;
u8 pad_B4[0xC];
s16 unk_C0;
s16 unk_C2;
u8 pad_C4[0xC];
s16 unk_D0;
s16 unk_D2;
u8 pad_D4[0xC];
u32 unk_E0;
u32 unk_E4;
u32 unk_E8;
u32 unk_EC;
u32 unk_F0;
u32 unk_F4;
u32 unk_F8;
u32 unk_FC;
u32 unk_100;
u32 unk_104;
u32 unk_108;
u32 unk_10C;
u32 unk_110;
u32 unk_114;
u32 unk_118;
u32 unk_11C;
u32 unk_120;
u32 unk_124;
u8 unk_128;
u8 unk_129;
u8 pad_12A[0x2];
s16 unk_12C;
s16 unk_12E;
s16 unk_130;
s16 unk_132;
s16 unk_134;
s16 unk_136;
s16 unk_138;
s16 unk_13A;
s16 unk_13C;
u8 pad_13E[0x2];
u32 unk_140;
u8 pad_144[0x2];
s16 unk_146;
s16 unk_148;
u8 pad_14A[0x2];
} Obj_1_bss_8B3A0;
extern Obj_1_bss_8B3A0 lbl_1_bss_8B3A0;


typedef struct {
u32 unk_0;
u8 pad_4[0x384];
} Obj_10_data_2CDC;
extern Obj_10_data_2CDC lbl_10_data_2CDC;


extern u32 lbl_10_data_5E2C;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


typedef struct { u8 pad_0[4]; s16 unk_4,unk_6,unk_8; u8 pad_A[0x9A]; u8 *items; } Panel;


extern s16 lbl_1_bss_962;


extern f32 lbl_10_rodata_158[];
extern s32 lbl_801A66B4;
extern u32 fn_1_535A0(void *, f32,f32,f32,f32,f32,f32);
extern void fn_1_49514(u32 *value);
extern int sprintf(char *s, const char *format, ...);


extern void fn_10_E034(Panel *arg);


typedef struct { s16 values[8]; } Options;
typedef u32 Color;
typedef struct { s16 unk_0; u8 pad_2[0x92]; u32 flags; } State;
void fn_10_E034(Panel *arg) {
const u8 *pool = (const u8 *)(((const f32 *)&lbl_10_rodata_158));
char buf[32];
Options options;
s16 i;
s16 page;
page = *(s16 *)(arg->items + (s16)(lbl_1_bss_962 - 14) * 0x94 + 0x14);
options = *(const Options *)(pool + 0xD0);
if (!((*((State *)&lbl_1_bss_8B3A0)).flags & 0x200)) return;
switch ((*((State *)&lbl_1_bss_8B3A0)).unk_0) { case 0: break; default: return; }
switch(page) {
case 0: {
f32 scale = (((const f32 *)&lbl_10_rodata_158))[17];
const Color c = *(const Color *)(pool + 0xE0);
fn_1_535A0((void *)&c, *(const f32 *)(pool+0x4C), *(const f32 *)(pool+0xF8), scale, *(const f32 *)(pool+0xFC), *(const f32 *)(pool+0x100), scale);
for(i=0; i<4; i++) {
Color c1 = *(const Color *)(pool+0xE4);
fn_1_49514( (u32 *)(void *)(&c1));
if (i == arg->unk_8) {
Color c2 = *(const Color *)(pool+0xE8);
fn_1_49514( (u32 *)(void *)(&c2));
}
fn_1_4AE0C((const char *)&lbl_10_data_5E2C, *(const char **)((u8 *)&lbl_10_data_2CDC + options.values[i]*24 + lbl_801A66B4*4));
{
Color c3 = *(const Color *)(pool+0xEC);
fn_1_49514( (u32 *)(void *)(&c3));
}
}
break;
}
case 1: {
const Color c = *(const Color *)(pool+0xF0);
fn_1_535A0((void *)&c, *(const f32 *)(pool+0x4C), *(const f32 *)(pool+0xF8), *(const f32 *)(pool+0x44), *(const f32 *)(pool+0x104), *(const f32 *)(pool+0x108), *(const f32 *)(pool+0x44));
sprintf(buf, ((const char **)(lbl_10_data_2CDC.pad_4 + 0x164))[lbl_801A66B4], arg->unk_4);
fn_1_4AE0C((const char *)&lbl_10_data_5E2C, buf);
break;
}
case 2: {
const Color c = *(const Color *)(pool+0xF4);
fn_1_535A0((void *)&c, *(const f32 *)(pool+0x4C), *(const f32 *)(pool+0xF8), *(const f32 *)(pool+0x44), *(const f32 *)(pool+0x10C), *(const f32 *)(pool+0x108), *(const f32 *)(pool+0x44));
sprintf(buf, ((const char **)(lbl_10_data_2CDC.pad_4 + 0x17C))[lbl_801A66B4], arg->unk_6);
fn_1_4AE0C((const char *)&lbl_10_data_5E2C, buf);
break;
}
}
}
/* fzgx:end fn_10_E034 */

/* fzgx:begin fn_10_E294 */
extern const f32 lbl_10_rodata_158[70];

typedef struct SelState {
    s16 mode;
    u8 pad_02[0x92];
    u32 flags_94;
    u8 pad_98[0xa8];
    u32 options_140;
} SelState;

extern volatile s16 lbl_1_bss_8B3A0; /* state mutated by callbacks during this function */
#define SEL ((SelState *)&lbl_1_bss_8B3A0)

extern void fn_1_496FC(f32, f32);
extern void fn_1_4955C(f32, f32);
extern s32 fn_1_F9FEC(void);
extern void fn_1_14083C(s32, s32, f32, f32, s32, s32, s32);
extern void fn_10_E034(SelState *);
extern void fn_10_E600(void);
extern void fn_10_D044(void);
extern void fn_10_D5D4(void);
extern void fn_10_DAF8(void);
extern void fn_10_E45C(void);

#pragma opt_propagation off
void fn_10_E294(void) {
    const f32 *data;
    s32 active;
    s32 random;
    s16 mode;
    s32 arg4;
    s32 arg6;
    u32 flags;
    u32 hi;

    data = lbl_10_rodata_158;
    fn_1_496FC(data[26], data[31]);
    fn_1_4955C(data[18], data[68]);
    fn_10_E034((SelState *)&lbl_1_bss_8B3A0);

    if (SEL->flags_94 & 0x40000000u) {
        fn_10_E600();
    } else {
        active = 0;
        random = (fn_1_F9FEC() != 0);
        mode = SEL->mode;
        if (mode == 0 || mode == -1) {
            fn_10_D044();
        }
        mode = SEL->mode;
        if (mode == 1 || mode == 11 || mode == -1) {
            fn_10_D5D4();
        }
        mode = SEL->mode;
        if (mode == 2 || mode == -1) {
            fn_10_DAF8();
        }

        arg6 = 0x9e;
        arg4 = 0xf0;
        mode = SEL->mode;
        switch (mode) {
        case 1:
        case 11:
            if (random == 1) {
                arg6 = 0xc0;
                arg4 = 0x101;
            }
            active = 1;
            break;
        case 2:
            arg6 = 0x78;
            active = 1;
            break;
        case 0:
            active = 1;
            break;
        default:
            if (mode == -1) {
                flags = SEL->options_140;
                hi = flags & 0x80000000u;
                if (hi && (flags & 4)) {
                    if (random == 1) {
                        arg6 = 0xc0;
                        arg4 = 0x101;
                    }
                } else if ((hi != 0) && (flags & 0x10)) {
                    arg6 = 0x78;
                }
                active = 1;
            }
            break;
        }

        if (active == 1) {
            fn_1_14083C(0x140, arg4, data[69], data[17], 0x136, arg6, 0xa);
        }
        fn_10_E45C();
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_10_E294 */

/* fzgx:begin fn_10_E45C */
typedef struct SelState {
    u8 pad_00[0x94];
    u32 flags;
    u32 bits;
    u8 pad_9c[8];
    u8 *items;
} SelState;

extern f32 lbl_10_rodata_158[19];
extern s16 lbl_1_bss_962;
extern SelState lbl_1_bss_8B3A0;
extern u8 lbl_1_bss_9C8[];
extern u8 lbl_1_bss_9F8[];
extern s32 lbl_801A66B4;
extern u32 lbl_80000000;

extern void fn_1_134AD4(void);
extern void fn_10_13ECC(void);
extern void fn_10_10C24(void);
extern void fn_10_21C20(s32, s16);
extern void fn_1_1380F0(void);
extern void fn_1_133DBC(s32);
extern s16 fn_10_91E8(void);
extern void fn_1_13ABA8(u32);
extern void fn_1_49410(void);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(s32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(...);

void fn_10_E45C(void) {
    f32 *pool;
    u8 *item;
    struct { u8 * value; } check;
    struct { u8 * value; } enabled;
    s16 i;
    s16 index;
    s32 found;

    pool = lbl_10_rodata_158;
    item = lbl_1_bss_8B3A0.items +
        ((s32)lbl_1_bss_962 - 0xe) * 0x94;
    fn_1_134AD4();
    fn_10_13ECC();
    fn_10_10C24();
    fn_10_21C20(4, (s16)lbl_801A66B4);
    fn_1_1380F0();
    fn_1_133DBC(1);

    if ((lbl_1_bss_8B3A0.flags & 0x200) == 0) {
        check.value = lbl_1_bss_9C8;
        enabled.value = lbl_1_bss_9F8;
        found = 0;
        for (i = 0; i < 4; i++) {
            if ((s8)check.value[0xa] != -1 &&
                __rlwnm(lbl_1_bss_8B3A0.bits, (i + 1) & 31, 31, 31) &&
                (*(u16 *)enabled.value >> 8) & 1) {
                found = 1;
                break;
            }
            check.value += 0xc;
            enabled.value += 0x14;
        }

        index = *(s16 *)(item + 0x14);
        if (*(s16 *)(item + index * 4) == 0 &&
            fn_10_91E8() < 2 &&
            found == 1) {
            fn_1_13ABA8(0);
            fn_1_49410();
            fn_1_4955C(pool[70], pool[70]);
            fn_1_495B0((u32)1 << 31);
            fn_1_495C8(1);
            fn_1_496FC(pool[22], pool[71]);
            fn_10_21C20(0x18, (s16)lbl_801A66B4);
            fn_1_4AE0C();
        } else {
            fn_1_13ABA8(0x28000000);
        }
    } else {
        fn_1_13ABA8(0x28000000);
    }
}
/* fzgx:end fn_10_E45C */

/* fzgx:begin fn_10_F050 pool noprologue */
#include <types.h>
#include <font.h>

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const u32 fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
#pragma section code_type ".text"
struct fn_10_F050_Copy88 { u32 a[22]; };
struct fn_10_F050_lbl_10_rodata_158 {
    u8 pad_0[0x44];
    f32 unk_44;
    f32 unk_48;
    u8 pad_4C[0xC];
    f32 unk_58;
    u8 pad_5C[0x1C];
    f32 unk_78;
    f32 unk_7C;
    u8 pad_80[0x8];
    f64 unk_88;
    f64 unk_90;
    u8 pad_98[0x130];
    f32 unk_1C8;
    f32 unk_1CC;
    f32 unk_1D0;
};
struct fn_10_F050_lbl_801A66A0 {
    u32 unk_0;
};
const u8 lbl_10_rodata_158[68] = {0x00,0x00,0x00,0x00,0x00,0x00,0xB5,0x00,0x00,0x00,0xB6,0x00,0x00,0x00,0xAD,0x00,0x00,0x00,0xB3,0x00,0x00,0x00,0xB8,0x00,0x00,0x00,0xB2,0x00,0x00,0x00,0xB1,0x00,0x00,0x00,0xAE,0x00,0x00,0x00,0xB4,0x00,0x00,0x00,0xB9,0x00,0x00,0x00,0xB0,0x00,0x00,0x00,0xAF,0x00,0x00,0x00,0xB7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xFF};
const f64 lbl_10_rodata_158__fzgx_offset_44 = 1.0f;
const f32 lbl_10_rodata_158__fzgx_offset_48 = 0.5f;
const u8 lbl_10_rodata_1A4[12] = {0x00,0x00,0x00,0x00,0x3E,0x4C,0xCC,0xCD,0x3E,0xCC,0xCC,0xCD};
const f32 lbl_10_rodata_1A4__fzgx_offset_C = 320.0f;
const u8 lbl_10_rodata_1A4__fzgx_offset_10[28] = {0x40,0x40,0x00,0x00,0x43,0xA1,0x80,0x00,0x40,0x80,0x00,0x00,0x40,0xA0,0x00,0x00,0x40,0xC0,0x00,0x00,0x3E,0x80,0x00,0x00,0x46,0x80,0x00,0x00};
const f32 lbl_10_rodata_1A4__fzgx_offset_2C = 65536.0f;
const f32 lbl_10_rodata_1A4__fzgx_offset_30 = 60.0f;
const u8 lbl_10_rodata_1A4__fzgx_offset_34[8] = {0x3F,0xF0,0x00,0x00,0x3F,0x0E,0x38,0xE4};
const f64 lbl_10_rodata_1E0 = 4503601774854144.0;
const f64 lbl_10_rodata_1E8 = 4503599627370496.0;
const u8 lbl_10_rodata_1E8__fzgx_offset_8[304] = {0x00,0x11,0x00,0x12,0x00,0x13,0x00,0x14,0x00,0x15,0x00,0x12,0x00,0x13,0x00,0x14,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xFF,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xFF,0x00,0x01,0x00,0x02,0x00,0x03,0x00,0x04,0x00,0x05,0x00,0x06,0x00,0x07,0x00,0x08,0x00,0x09,0x00,0x0A,0x00,0x0B,0x00,0x0C,0x00,0x11,0x00,0x12,0x00,0x13,0x00,0x14,0x00,0x15,0x00,0x12,0x00,0x13,0x00,0x14,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x42,0x6C,0x00,0x00,0x42,0xA4,0x00,0x00,0x42,0x9A,0x00,0x00,0x42,0xC4,0x00,0x00,0x41,0xC8,0x00,0x00,0x42,0xE6,0x00,0x00,0x3F,0x33,0x33,0x33,0x41,0x10,0x00,0x00,0x3F,0x2A,0xAA,0xAB,0x43,0xD7,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0x74,0x00,0x00,0x42,0xA2,0x00,0x00,0x42,0xDC,0x00,0x00,0x42,0x20,0x00,0x00,0x42,0xA0,0x00,0x00,0x43,0x52,0x00,0x00,0x43,0x66,0x00,0x00,0x43,0xB7,0x80,0x00,0x42,0x5C,0x00,0x00,0x42,0x98,0x00,0x00,0x42,0xC8,0x00,0x00,0x43,0xB6,0x80,0x00,0x42,0x96,0x00,0x00,0x42,0xEA,0x00,0x00,0x3E,0xEA,0xAA,0xAB,0x43,0x25,0x00,0x00,0x43,0x1B,0x00,0x00,0x42,0xAE,0x00,0x00,0x43,0x38,0x00,0x00,0x42,0xB4,0x00,0x00,0x43,0xBE,0x80,0x00,0x43,0xED,0x80,0x00,0x43,0x2E,0x00,0x00,0x43,0xD3,0x80,0x00,0x43,0x42,0x00,0x00,0x46,0x00,0x00,0x00,0x41,0xA0,0x00,0x00,0xC6,0x00,0x00,0x00,0x43,0xB5,0x00,0x00,0x44,0x03,0x00,0x00,0x42,0x90,0x00,0x00,0x41,0x30,0x00,0x00,0x3F,0x66,0x66,0x66,0x3F,0x0A,0xAA,0xAB,0xC0,0x80,0x00,0x00,0x43,0xA7,0x00,0x00,0x43,0xAA,0x80,0x00,0xC0,0xC0,0x00,0x00,0x3F,0x20,0x00,0x00,0x43,0xAD,0x00,0x00};
const f32 lbl_10_rodata_1E8__fzgx_offset_138 = 211.0f;
const f32 lbl_10_rodata_1E8__fzgx_offset_13C = 161.0f;
const f32 lbl_10_rodata_1E8__fzgx_offset_140 = 192.0f;
const u8 lbl_10_rodata_1E8__fzgx_offset_144[128] = {0x3D,0x8F,0x5C,0x29,0x00,0x17,0x00,0x18,0x00,0x19,0x00,0x1A,0x00,0x1B,0x00,0x1C,0x00,0x1D,0x00,0x1E,0x00,0x1F,0x00,0x21,0x00,0x22,0x00,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x42,0xEE,0x00,0x00,0x43,0x0D,0x00,0x00,0x43,0x20,0x00,0x00,0x43,0x23,0x00,0x00,0x42,0x2C,0x00,0x00,0x43,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x56,0x80,0x00,0x00,0x00,0x00,0x00,0x40,0x50,0xE0,0x00,0x00,0x00,0x00,0x00,0x40,0x36,0x80,0x00,0x00,0x00,0x00,0x00,0x41,0xB4,0x00,0x00,0x3C,0x23,0xD7,0x0A,0x3F,0x6A,0xAA,0xAB};
extern struct fn_10_F050_lbl_801A66A0 lbl_801A66A0;
extern const u8 lbl_1_rodata_26F8[];
extern int fn_1_4F734(FontDrawPacket *);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_1_51678(FontDrawPacket *, u32, s16, s16, s16, s16);
extern f32 lbl_8006D188(u32);

struct FzgxCopy_88 { u32 words[22]; };
#pragma opt_dead_assignments on
void fn_10_F050(s32 arg0, s32 arg1) {
    u32 * fzgx_live_;
    u32 * fzgx_live;
    struct FzgxCopy_88 loc_8;
    s32 sp4;
    s32 fzgx_loop_var_r22_4659;
    s32 temp_r20;
    s32 var_r21;
    s32 var_r22;
    f32 temp_f31;

    loc_8 = *(const struct FzgxCopy_88 *)lbl_1_rodata_26F8;
    (*(f32 *)((u8 *)(&loc_8) + 4)) = (320.0f) + (f32) arg0;
    (*(f32 *)((u8 *)(&loc_8) + 8)) = (211.0f);
    fzgx_live = loc_8.words;
    fzgx_live[0] = 0x9F17;
    (*(s16 *)((u8 *)(&loc_8) + 40)) = arg1;
    fzgx_live = loc_8.words;
    fzgx_live[0xC] = 0xA;
    fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
{
    s32 fzgx_loop_temp_r20_4659;
    fzgx_loop_temp_r20_4659 = (fn_1_486C4((u32)(0x9F2CU)) >> 3U) & 0x1FFF;
    temp_f31 = (161.0f);
    var_r21 = 0;
    fzgx_loop_var_r22_4659 = 0;
    while (var_r21 < fzgx_loop_temp_r20_4659) {
        loc_8 = *(const struct FzgxCopy_88 *)lbl_1_rodata_26F8;
        fzgx_live = loc_8.words;
        fzgx_live[0] = 0x9F2C;
        fzgx_live = loc_8.words;
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(fzgx_live[0]), (s16)(0), (s16)((s16) (((f32) var_r21 * (f32) fn_1_486C4((u32)(0x9F2CU))) / (f32) fzgx_loop_temp_r20_4659)), (s16)(((s16)(fn_1_48690((u32)(0x9F2CU))))), (s16)(((s16)((f32) fn_1_486C4((u32)(0x9F2CU)) / (f32) fzgx_loop_temp_r20_4659))));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = (f32) (arg0 + 0x11C);
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f31 + (((f32) var_r21 * (f32) fn_1_486C4((u32)(0x9F2CU))) / (f32) fzgx_loop_temp_r20_4659);
        if ((u32) (lbl_801A66A0.unk_0 % 120) < 0x3CU) {
            (*(s8 *)(((57) + ((u8 *)(&loc_8))))) = (s8) ((192.0f) * ((1.0f) + lbl_8006D188((u32)((u32) (s32) (((65536.0f) * (f32) ((lbl_801A66A0.unk_0 + fzgx_loop_var_r22_4659) % 60)) / (60.0f))))) / 2.0f);
        } else {
            (*(s8 *)((u8 *)(&loc_8) + 57)) = 0;
        }
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        loc_8 = *(const struct FzgxCopy_88 *)lbl_1_rodata_26F8;
        fzgx_live_ = loc_8.words;
        fzgx_live = fzgx_live_;
        fzgx_live[0] = 0x9F2C;
        fzgx_live = loc_8.words;
        fn_1_51678((FontDrawPacket *)((FontDrawPacket *) &loc_8), (u32)(fzgx_live[0]), (s16)(0), (s16)((s16) (((f32) var_r21 * (f32) fn_1_486C4((u32)(0x9F2CU))) / (f32) fzgx_loop_temp_r20_4659)), (s16)(((s16)(fn_1_48690((u32)(0x9F2CU))))), (s16)(((s16)((f32) fn_1_486C4((u32)(0x9F2CU)) / (f32) fzgx_loop_temp_r20_4659))));
        (*(f32 *)((u8 *)(&loc_8) + 4)) = (f32) (arg0 + 0x144);
        (*(f32 *)((u8 *)(&loc_8) + 8)) = temp_f31 + (((f32) var_r21 * (f32) fn_1_486C4((u32)(0x9F2CU))) / (f32) fzgx_loop_temp_r20_4659);
        if ((u32) (lbl_801A66A0.unk_0 % 120) >= 0x3CU) {
            (*(s8 *)((u8 *)(&loc_8) + 57)) = (s8) ((192.0f) * ((1.0f) + lbl_8006D188((u32)((u32) (s32) (((65536.0f) * (f32) ((lbl_801A66A0.unk_0 + fzgx_loop_var_r22_4659) % 60)) / (60.0f))))) / 2.0f);
        } else {
            (*(s8 *)((u8 *)(&loc_8) + 57)) = 0;
        }
        fzgx_live = loc_8.words;
        fzgx_live[0xC] = 0x80000;
        fn_1_4F734((FontDrawPacket *)((FontDrawPacket *) &loc_8));
        fzgx_loop_var_r22_4659 -= 5;
        var_r21 += 1;
            }
    temp_r20 = fzgx_loop_temp_r20_4659;
    var_r22 = fzgx_loop_var_r22_4659;
}
}
#pragma opt_dead_assignments reset
/* fzgx:end fn_10_F050 */

/* fzgx:begin fn_10_F57C */
#include "font.h"
#include "rel/sel/sel.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const u32 fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
static const u32 fzgx_pool_table7[15] = {0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 119.0f;
    s = 141.0f;
    s = 160.0f;
    s = 163.0f;
    s = 43.0f;
    s = 130.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 67.5;
    d = 22.5;
    s = 22.5f;
    s = 0.009999999776482582f;
    s = 0.9166666865348816f;
    s = 2.0f;
    s = 240.0f;
    s = 9.999999747378752e-05f;
    s = 278.0f;
    s = 316.0f;
}
#pragma section code_type ".text"

typedef struct SelState {
    s16 unk_0;
    u8 pad_2[0x8e];
    s16 unk_90;
    u8 pad_92[2];
    u32 flags;
    u8 pad_98[12];
    u8 *items;
} SelState;
typedef struct Sig_fn_10_C258_SelContext {
    u8 pad[0xa4];
    u8 *entries;
} Sig_fn_10_C258_SelContext;
struct Pool {
    u8 pad_00[0x4c];
    f32 f_4c;
    u8 pad_50[8];
    f32 f_58;
    u8 pad_5c[0x34];
    f64 f_90;
    u8 pad_98[0x80];
    f32 f_118;
    u8 pad_11c[0x114];
    f64 f_230;
    f64 f_238;
    f64 f_240;
    f32 f_248;
    f32 f_24c;
    f32 f_250;
    f32 f_254;
    f32 f_258;
    f32 f_25c;
    f32 f_260;
    f32 f_264;
};
struct Copy88 { u8 b[88]; };
extern SelState lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_962;
extern const f32 lbl_10_rodata_158[19];
extern u8 lbl_1_data_2B0D4[];
extern u8 lbl_1_data_2B144[];
extern u8 *lbl_1_data_2AA24[];
extern u8 *lbl_1_data_2BD54[][6];
extern u8 *lbl_1_data_418D4[];
extern struct Copy88 lbl_1_rodata_26F8;
extern s32 lbl_801A66B4;
extern s32 fn_1_5233C;
extern s16 fn_10_C258(Sig_fn_10_C258_SelContext *, s32);
extern void fn_1_134AD4(void);
extern void fn_1_133DBC(s32);
extern void fn_10_10CA8(void);
extern s32 fn_10_21C20(s16, s16);
extern void fn_10_10D2C(void);
extern void fn_10_21DA8(void);
extern void fn_1_1380F0(void *);
extern s32 fn_10_1615C(void *, u32);
extern s32 fn_10_14FDC(void *);
extern s32 fn_10_15B20(void *, u32);
extern void fn_1_13D02C(void);
extern void fn_1_13B328(u32, s32);
extern void fn_1_13DC54(void);
extern void fn_1_13ABA8(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_49738(s32 *);
extern void fn_1_49748(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(s32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4954C(f32);
extern void fn_1_4A0D8(const char *);
extern u32 fn_1_F8CF0(u32);
extern int fn_1_B7E98(int);
extern s32 fn_1_EC900(void);
extern s32 fn_1_EB85C(void);
extern void fn_1_EB8F4(void);

#pragma opt_common_subs on
void fn_10_F57C(void) {
    s16 mode;
    u8 font_index;
    u16 count;
    SelState *state;
    s32 ready;
    s32 flag;
    u8 *state2;
    struct Copy88 draw;
    mode = fn_10_C258((Sig_fn_10_C258_SelContext *)&lbl_1_bss_8B3A0, (s32)lbl_1_bss_962);
    ready = 0;
    fn_1_134AD4();
    fn_1_133DBC(1);
    if (mode == 1 || (lbl_1_bss_8B3A0.flags & 0x40000000)) {
        if (!(lbl_1_bss_8B3A0.flags & 0x80000000)) ready = 1;
    }
    state = &lbl_1_bss_8B3A0;
    if (state->flags & 0x40000000) {
        count = lbl_10_bss_5174E;
        if (count != 0 && (f64)count < (90.0)) {
            draw = lbl_1_rodata_26F8;
            font_index = lbl_1_data_2B0D4[lbl_10_bss_5568C];
            *(u32 *)draw.b = fzgx_pool_table1[lbl_1_data_2B144[font_index]];
            if ((f64)count > (67.5)) {
                *(f32 *)(draw.b + 44) = (f32)((22.5) - (f64)count) / (22.5f);
            }
            *(f32 *)(draw.b + 12) = (0.00999999978f);
            fn_1_4F734((FontDrawPacket *)&draw);
            fn_1_49410();
            fn_1_494DC(8);
            fn_1_49738(&fn_1_5233C);
            fn_1_49748((0.0f));
            fn_1_495B0(0x80000000);
            fn_1_495C8(1);
            fn_1_4955C((0.916666687f), (0.916666687f));
            fn_1_4966C((2.0f), (0.0f));
            fn_1_496FC((320.0f), (240.0f));
            fn_1_4954C((9.99999975e-05f));
            state2 = (u8 *)&lbl_1_bss_8B3A0;
            fn_1_4A0D8((const char *)lbl_1_data_2AA24[lbl_1_data_2B0D4[*(s16 *)(state2 + 0x90)]]);
            fn_1_49410();
            fn_1_49738(&fn_1_5233C);
            fn_1_49748((0.0f));
            fn_1_495B0(0x80000000);
            fn_1_495C8(1);
            fn_1_4966C((2.0f), (0.0f));
            fn_1_4955C((0.666666687f), (0.666666687f));
            fn_1_496FC((320.0f), (278.0f));
            fn_1_4954C((9.99999975e-05f));
            fn_1_4A0D8((const char *)lbl_1_data_2BD54[*(s16 *)(state2 + 0x90)][lbl_801A66B4]);
            fn_1_49410();
            fn_1_494DC(0x2a);
            fn_1_49738(&fn_1_5233C);
            fn_1_495C8(1);
            fn_1_496FC((320.0f), (316.0f));
            fn_1_4954C((9.99999975e-05f));
            fn_1_4A0D8((const char *)lbl_10_data_5E4C);
        } else {
            lbl_10_bss_5568C = (u8)lbl_1_bss_8B3A0.unk_90;
        }
        if (state->flags & 0x200) {
            fn_1_13D02C();
            if (lbl_1_bss_8B3A0.unk_0 == 0xa) fn_1_13B328(0x48800000, 0);
            else fn_1_13B328(0x40800000, 0);
            switch (mode) {
            case 0:
                fn_10_10CA8();
                fn_1_1380F0((void *)fn_10_21C20(5, (s16)lbl_801A66B4));
                break;
            case 1:
                fn_10_1615C(&lbl_1_bss_8B3A0, (u32)ready);
                fn_10_10D2C();
                if (*(u8 *)(lbl_1_bss_8B3A0.items + 0x19) != 0) {
                    fn_10_21DA8();
                    fn_1_1380F0((void *)lbl_1_data_418D4[lbl_801A66B4]);
                } else if (lbl_1_bss_8B3A0.unk_0 == 0xa) {
                    fn_1_1380F0((void *)fn_10_21C20(7, (s16)lbl_801A66B4));
                } else {
                    fn_1_1380F0((void *)fn_10_21C20(6, (s16)lbl_801A66B4));
                }
                fn_1_13DC54();
                break;
            }
        } else {
            fn_1_13D02C();
            if (lbl_1_bss_8B3A0.unk_0 == 0xa) fn_1_13B328(0x48800000, 0);
            else fn_1_13B328(0x40800000, 0);
            fn_10_1615C(&lbl_1_bss_8B3A0, (u32)ready);
            fn_10_10D2C();
            if (*(u8 *)(lbl_1_bss_8B3A0.items + 0x19) != 0) {
                fn_10_21DA8();
                fn_1_1380F0((void *)lbl_1_data_418D4[lbl_801A66B4]);
            } else if (lbl_1_bss_8B3A0.unk_0 == 0xa) {
                fn_1_1380F0((void *)fn_10_21C20(7, (s16)lbl_801A66B4));
            } else {
                fn_1_1380F0((void *)fn_10_21C20(6, (s16)lbl_801A66B4));
            }
            fn_1_13DC54();
        }
    } else {
        switch (mode) {
        case 0:
            if (state->flags & 0x20) fn_1_13ABA8(0x08000000);
            else fn_1_13ABA8(0x28000000);
            fn_10_14FDC(&lbl_1_bss_8B3A0);
            fn_10_10CA8();
            fn_1_1380F0((void *)fn_10_21C20(5, (s16)lbl_801A66B4));
            break;
        case 1:
            flag = (lbl_1_data_2B0D4[state->unk_90] == 1 || lbl_1_data_2B0D4[state->unk_90] == 0x11) && ((u8)fn_1_F8CF0(0) != 0);
            if (flag == 0 && lbl_1_data_2B0D4[state->unk_90] == 4) fn_1_F8CF0(1);
            if (lbl_1_bss_8B3A0.unk_0 == 2) {
                u32 out;
                if ((fn_1_B7E98(0) != 0 || fn_1_B7E98(1) != 0) && fn_1_EC900() != 0 && fn_1_EB85C() != 0) out = 0x28C00000;
                else if (fn_1_B7E98(0) != 0 || fn_1_B7E98(1) != 0) out = 0x28800000;
                else out = 0x28000000;
                fn_1_13ABA8(out);
            } else fn_1_13ABA8(0x28000000);
            fn_10_15B20(&lbl_1_bss_8B3A0, (u32)ready);
            fn_10_10D2C();
            fn_1_1380F0((void *)fn_10_21C20(6, (s16)lbl_801A66B4));
            break;
        }
    }
    if ((lbl_1_bss_8B3A0.unk_0 == 2 || lbl_1_bss_8B3A0.unk_0 == 0xa) && mode == 1) fn_1_EB8F4();
}
#pragma opt_common_subs reset
/* fzgx:end fn_10_F57C */

/* fzgx:begin fn_10_FBEC */
typedef struct SelPool {
    u8 pad_0[0x44];
    f32 one;
    u8 pad_48[0x40];
    f64 two52;
    u8 pad_90[0x1C4];
    f32 two;
    u8 pad_258[0x10];
    u32 color;
} SelPool;

typedef struct SelCell {
    s16 id;
    u8 pad_2[0x2];
    u32 flags;
} SelCell;

typedef struct SelSlot {
    u8 pad_0[0xE];
    s16 index;
    u8 pad_10[0x10];
} SelSlot;

static const u32 fzgx_pool_rodata_lbl_10_rodata_158[17] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0xB500, 0xB600, 0xAD00, 0xB300, 0xB800, 0xB200, 0xB100,
    0xAE00, 0xB400, 0xB900, 0xB000, 0xAF00, 0xB700, 0x0, 0x0,
    0xF0F0FF
};
static const u32 fzgx_pool_rodata_lbl_10_rodata_158_44[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F800000, 0x3F000000
};
static const u32 fzgx_pool_rodata_lbl_10_rodata_1A4[15] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, 0x3E4CCCCD, 0x3ECCCCCD, 0x43A00000, 0x40400000, 0x43A18000, 0x40800000, 0x40A00000,
    0x40C00000, 0x3E800000, 0x46800000, 0x47800000, 0x42700000, 0x3FF00000, 0x3F0E38E4
};
#pragma section code_type ".fzgxpool"
static void fzgx_float_layout_lbl_10_rodata_1E0(void) {
    volatile s16 index = 0; /* fzgx-allow: S2 layout primer input: emits the retail integer-conversion bias in pool order */
    volatile f32 value; /* fzgx-allow: S2 layout primer sink */
    value = (f32)index;
}
#pragma section code_type ".text"
static const u32 fzgx_pool_rodata_lbl_10_rodata_1E8[113] = {
    0x43300000, 0x0, 0x110012, 0x130014, 0x150012, 0x130014, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0xF0F0FF, 0x0, 0xF0F0FF, 0x10002, 0x30004, 0x50006, 0x70008, 0x9000A,
    0xB000C, 0x110012, 0x130014, 0x150012, 0x130014, 0xFF0000, 0xFFFFFF00, 0xFF0000,
    0xFFFFFF00, 0xFF0000, 0xFF0000, 0x426C0000, 0x42A40000, 0x429A0000, 0x42C40000, 0x41C80000,
    0x42E60000, 0x3F333333, 0x41100000, 0x3F2AAAAB, 0x43D78000, 0x0, 0x0, 0x42740000,
    0x42A20000, 0x42DC0000, 0x42200000, 0x42A00000, 0x43520000, 0x43660000, 0x43B78000, 0x425C0000,
    0x42980000, 0x42C80000, 0x43B68000, 0x42960000, 0x42EA0000, 0x3EEAAAAB, 0x43250000, 0x431B0000,
    0x42AE0000, 0x43380000, 0x42B40000, 0x43BE8000, 0x43ED8000, 0x432E0000, 0x43D38000, 0x43420000,
    0x46000000, 0x41A00000, 0xC6000000, 0x43B50000, 0x44030000, 0x42900000, 0x41300000, 0x3F666666,
    0x3F0AAAAB, 0xC0800000, 0x43A70000, 0x43AA8000, 0xC0C00000, 0x3F200000, 0x43AD0000, 0x43530000,  /* fzgx-allow: A1 retail data bytes */
    0x43210000, 0x43400000, 0x3D8F5C29, 0x170018, 0x19001A, 0x1B001C, 0x1D001E, 0x1F0021,
    0x220000, 0xFF0000, 0xFFFFFF00, 0xFF0000, 0xFFFFFF00, 0xFF0000, 0xFFFFFF00, 0xFF0000,
    0xFFFFFF00, 0xFF0000, 0x42EE0000, 0x430D0000, 0x43200000, 0x43230000, 0x422C0000, 0x43020000,
    0x0, 0x40568000, 0x0, 0x4050E000, 0x0, 0x40368000, 0x0, 0x41B40000,
    0x3C23D70A, 0x3F6AAAAB
};
static const u32 fzgx_pool_rodata_lbl_10_rodata_3AC[5] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x40000000, 0x43700000, 0x38D1B717, 0x438B0000, 0x439E0000
};
static const u32 fzgx_pool_rodata_lbl_10_rodata_158_268[114] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFFFFFFFF, 0x3F400000, 0x437A0000, 0x43BA8000, 0x43B10000, 0x42880000, 0x3F5DDDDE, 0xBF800000,
    0x430C0000, 0x42480000, 0x3DCCCCCD, 0x441B0000, 0x41C00000, 0x41200000, 0x43C00000, 0x44200000,
    0x3F155555, 0x3F19999A, 0xFF, 0xFF, 0x41880000, 0x43A90000, 0x43160000, 0x41700000,
    0x439E8000, 0xC2D40000, 0x439F0000, 0x42D40000, 0x43A68000, 0xC2AE0000, 0x3DB851EC, 0xC1300000,  /* fzgx-allow: A1 retail data bytes */
    0x44214000, 0x44344000, 0x43A50000, 0x3F7D70A4, 0x43270000, 0x42180000, 0xFF, 0x41000000,
    0x43B70000, 0x41400000, 0x41600000, 0x3F428F5C, 0xFF, 0x4270A3D7, 0x438C0000, 0x40B66666,
    0x40900000, 0x3F34FDF4, 0xFF9CFF9C, 0xFF9CFF9C, 0x310069, 0x9F00D5, 0x10B0141, 0x17701AD,
    0x1E30219, 0x25203E8, 0x3E803E8, 0x3E80000, 0x80808000, 0x42C60000, 0x423C0000, 0x42860000,  /* fzgx-allow: A1 retail data bytes */
    0x42800000, 0x435B0000, 0x44148000, 0x44144000, 0x42400000, 0x3EC7AE14, 0x3EDADADB, 0x0,
    0x42380000, 0x43760000, 0x42F00000, 0x43EB0000, 0x43770000, 0x42340000, 0x42080000, 0x43810000,
    0x3E99999A, 0x43A40000, 0x43850000, 0x43940000, 0x43A30000, 0x43860000, 0x41E00000, 0x43950000,
    0xFF9CFF9C, 0xFF9CFF9C, 0x310069, 0x9F00D5, 0x10B0141, 0x17701AD, 0x1E30219, 0x25103E8,
    0x3E803E8, 0x3E80000, 0x1, 0x20003, 0x30000, 0x10002, 0x20003, 0x1,
    0x10002, 0x30000, 0x1, 0x20002, 0x1, 0x10002, 0x0, 0x1,
    0x10000, 0x0
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_10_rodata_158(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_10_rodata_158;
    s = *(u8 *)fzgx_pool_rodata_lbl_10_rodata_158_44;
    s = *(u8 *)fzgx_pool_rodata_lbl_10_rodata_1A4;
    s = *(u8 *)fzgx_pool_rodata_lbl_10_rodata_1E8;
    s = *(u8 *)fzgx_pool_rodata_lbl_10_rodata_3AC;
    s = *(u8 *)fzgx_pool_rodata_lbl_10_rodata_158_268;
}
#pragma section code_type ".text"

extern u8 lbl_10_data_1038__fzgx_offset_0[];
extern u8 lbl_10_data_103C__fzgx_offset_0[];
extern u8 lbl_10_data_10D0__fzgx_offset_0[];
extern u8 lbl_10_data_10F8__fzgx_offset_0[];
extern u8 lbl_10_data_1128__fzgx_offset_0[];
extern u8 lbl_10_data_1158__fzgx_offset_0[];
extern u8 lbl_10_data_1180__fzgx_offset_0[];
extern u8 lbl_10_data_11B8__fzgx_offset_0[];
extern u8 lbl_10_data_11CC__fzgx_offset_0[];
extern u8 lbl_10_data_11E8__fzgx_offset_0[];
extern u8 lbl_10_data_11F8__fzgx_offset_0[];
extern u8 lbl_10_data_1214__fzgx_offset_0[];
extern u8 lbl_10_data_1228__fzgx_offset_0[];
extern u8 lbl_10_data_1244__fzgx_offset_0[];
extern u8 lbl_10_data_1260__fzgx_offset_0[];
extern u8 lbl_10_data_1290__fzgx_offset_0[];
extern u8 lbl_10_data_12A8__fzgx_offset_0[];
extern u8 lbl_10_data_12C4__fzgx_offset_0[];
extern u8 lbl_10_data_1320__fzgx_offset_0[];
extern u8 lbl_10_data_1380__fzgx_offset_0[];
extern u8 lbl_10_data_13D0__fzgx_offset_0[];
extern u8 lbl_10_data_1418__fzgx_offset_0[];
extern u8 lbl_10_data_1424__fzgx_offset_0[];
extern u8 lbl_10_data_143C__fzgx_offset_0[];
extern u8 lbl_10_data_1464__fzgx_offset_0[];
extern u8 lbl_10_data_1490__fzgx_offset_0[];
extern u8 lbl_10_data_14B0__fzgx_offset_0[];
extern u8 lbl_10_data_14CC__fzgx_offset_0[];
extern u8 lbl_10_data_14E0__fzgx_offset_0[];
extern u8 lbl_10_data_14FC__fzgx_offset_0[];
extern u8 lbl_10_data_1514__fzgx_offset_0[];
extern u8 lbl_10_data_152C__fzgx_offset_0[];
extern u8 lbl_10_data_1538__fzgx_offset_0[];
extern u8 lbl_10_data_1548__fzgx_offset_0[];
extern u8 lbl_10_data_155C__fzgx_offset_0[];
extern u8 lbl_10_data_1574__fzgx_offset_0[];
extern u8 lbl_10_data_15C8__fzgx_offset_0[];
extern u8 lbl_10_data_161C__fzgx_offset_0[];
extern u8 lbl_10_data_16D0__fzgx_offset_0[];
extern u8 lbl_10_data_17A0__fzgx_offset_0[];
extern u8 lbl_10_data_1804__fzgx_offset_0[];
extern u8 lbl_10_data_1888__fzgx_offset_0[];
extern u8 lbl_10_data_18C0__fzgx_offset_0[];
extern u8 lbl_10_data_1908__fzgx_offset_0[];
extern u8 lbl_10_data_1958__fzgx_offset_0[];
extern u8 lbl_10_data_19B8__fzgx_offset_0[];
extern u8 lbl_10_data_19C0__fzgx_offset_0[];
extern u8 lbl_10_data_19E8__fzgx_offset_0[];
extern u8 lbl_10_data_1A0C__fzgx_offset_0[];
extern u8 lbl_10_data_1A18__fzgx_offset_0[];
extern u8 lbl_10_data_1A24__fzgx_offset_0[];
extern u8 lbl_10_data_1A2C__fzgx_offset_0[];
extern u8 lbl_10_data_1A58__fzgx_offset_0[];
extern u8 lbl_10_data_1A88__fzgx_offset_0[];
extern u8 lbl_10_data_1AB8__fzgx_offset_0[];
extern u8 lbl_10_data_1AE8__fzgx_offset_0[];
extern u8 lbl_10_data_1B18__fzgx_offset_0[];
extern u8 lbl_10_data_1B48__fzgx_offset_0[];
extern u8 lbl_10_data_1B5C__fzgx_offset_0[];
extern u8 lbl_10_data_1B74__fzgx_offset_0[];
extern u8 lbl_10_data_1B8C__fzgx_offset_0[];
extern u8 lbl_10_data_1BA4__fzgx_offset_0[];
extern u8 lbl_10_data_1BBC__fzgx_offset_0[];
extern u8 lbl_10_data_1BD4__fzgx_offset_0[];
extern u8 lbl_10_data_1BEC__fzgx_offset_0[];
extern u8 lbl_10_data_1C08__fzgx_offset_0[];
extern u8 lbl_10_data_1C24__fzgx_offset_0[];
extern u8 lbl_10_data_1C40__fzgx_offset_0[];
extern u8 lbl_10_data_1C5C__fzgx_offset_0[];
extern u8 lbl_10_data_1C70__fzgx_offset_0[];
extern u8 lbl_10_data_1C94__fzgx_offset_0[];
extern u8 lbl_10_data_1CBC__fzgx_offset_0[];
extern u8 lbl_10_data_1CE4__fzgx_offset_0[];
extern u8 lbl_10_data_1D0C__fzgx_offset_0[];
extern u8 lbl_10_data_1D34__fzgx_offset_0[];
extern u8 lbl_10_data_1D54__fzgx_offset_0[];
extern u8 lbl_10_data_1D5C__fzgx_offset_0[];
extern u8 lbl_10_data_1D68__fzgx_offset_0[];
extern u8 lbl_10_data_1D74__fzgx_offset_0[];
extern u8 lbl_10_data_1D80__fzgx_offset_0[];
extern u8 lbl_10_data_1D8C__fzgx_offset_0[];
extern u8 lbl_10_data_1D98__fzgx_offset_0[];
extern u8 lbl_10_data_1DA0__fzgx_offset_0[];
extern u8 lbl_10_data_1DAC__fzgx_offset_0[];
extern u8 lbl_10_data_1DB8__fzgx_offset_0[];
extern u8 lbl_10_data_1DC4__fzgx_offset_0[];
extern u8 lbl_10_data_1DD0__fzgx_offset_0[];
extern u8 lbl_10_data_1DDC__fzgx_offset_0[];
extern u8 lbl_10_data_1DF4__fzgx_offset_0[];
extern u8 lbl_10_data_1E10__fzgx_offset_0[];
extern u8 lbl_10_data_1E2C__fzgx_offset_0[];
extern u8 lbl_10_data_1E48__fzgx_offset_0[];
extern u8 lbl_10_data_1E64__fzgx_offset_0[];
extern u8 lbl_10_data_21B0__fzgx_offset_0[];
extern u8 lbl_10_data_21BC__fzgx_offset_0[];
extern u8 lbl_10_data_21C8__fzgx_offset_0[];
extern u8 lbl_10_data_21D4__fzgx_offset_0[];
extern u8 lbl_10_data_21E0__fzgx_offset_0[];
extern u8 lbl_10_data_21EC__fzgx_offset_0[];
extern u8 lbl_10_data_2288__fzgx_offset_0[];
extern u8 lbl_10_data_2294__fzgx_offset_0[];
extern u8 lbl_10_data_22A4__fzgx_offset_0[];
extern u8 lbl_10_data_22B4__fzgx_offset_0[];
extern u8 lbl_10_data_22C4__fzgx_offset_0[];
extern u8 lbl_10_data_22D4__fzgx_offset_0[];
extern u8 lbl_10_data_22E4__fzgx_offset_0[];
extern u8 lbl_10_data_22F0__fzgx_offset_0[];
extern u8 lbl_10_data_2300__fzgx_offset_0[];
extern u8 lbl_10_data_2310__fzgx_offset_0[];
extern u8 lbl_10_data_2320__fzgx_offset_0[];
extern u8 lbl_10_data_2330__fzgx_offset_0[];
extern u8 lbl_10_data_233C__fzgx_offset_0[];
extern u8 lbl_10_data_2348__fzgx_offset_0[];
extern u8 lbl_10_data_2358__fzgx_offset_0[];
extern u8 lbl_10_data_2368__fzgx_offset_0[];
extern u8 lbl_10_data_2378__fzgx_offset_0[];
extern u8 lbl_10_data_2388__fzgx_offset_0[];
extern u8 lbl_10_data_2394__fzgx_offset_0[];
extern u8 lbl_10_data_23A0__fzgx_offset_0[];
extern u8 lbl_10_data_23B0__fzgx_offset_0[];
extern u8 lbl_10_data_23C0__fzgx_offset_0[];
extern u8 lbl_10_data_23D0__fzgx_offset_0[];
extern u8 lbl_10_data_23E0__fzgx_offset_0[];
extern u8 lbl_10_data_23F0__fzgx_offset_0[];
extern u8 lbl_10_data_23FC__fzgx_offset_0[];
extern u8 lbl_10_data_240C__fzgx_offset_0[];
extern u8 lbl_10_data_241C__fzgx_offset_0[];
extern u8 lbl_10_data_242C__fzgx_offset_0[];
extern u8 lbl_10_data_243C__fzgx_offset_0[];
extern u8 lbl_10_data_244C__fzgx_offset_0[];
extern u8 lbl_10_data_2454__fzgx_offset_0[];
extern u8 lbl_10_data_2460__fzgx_offset_0[];
extern u8 lbl_10_data_246C__fzgx_offset_0[];
extern u8 lbl_10_data_2478__fzgx_offset_0[];
extern u8 lbl_10_data_2484__fzgx_offset_0[];
extern u8 lbl_10_data_2490__fzgx_offset_0[];
extern u8 lbl_10_data_249C__fzgx_offset_0[];
extern u8 lbl_10_data_24AC__fzgx_offset_0[];
extern u8 lbl_10_data_24BC__fzgx_offset_0[];
extern u8 lbl_10_data_24CC__fzgx_offset_0[];
extern u8 lbl_10_data_24DC__fzgx_offset_0[];
extern u8 lbl_10_data_24EC__fzgx_offset_0[];
extern u8 lbl_10_data_24F4__fzgx_offset_0[];
extern u8 lbl_10_data_2500__fzgx_offset_0[];
extern u8 lbl_10_data_250C__fzgx_offset_0[];
extern u8 lbl_10_data_2518__fzgx_offset_0[];
extern u8 lbl_10_data_2524__fzgx_offset_0[];
extern u8 lbl_10_data_2530__fzgx_offset_0[];
extern u8 lbl_10_data_2538__fzgx_offset_0[];
extern u8 lbl_10_data_2544__fzgx_offset_0[];
extern u8 lbl_10_data_2550__fzgx_offset_0[];
extern u8 lbl_10_data_255C__fzgx_offset_0[];
extern u8 lbl_10_data_2568__fzgx_offset_0[];
extern u8 lbl_10_data_2574__fzgx_offset_0[];
extern u8 lbl_10_data_2584__fzgx_offset_0[];
extern u8 lbl_10_data_2598__fzgx_offset_0[];
extern u8 lbl_10_data_25AC__fzgx_offset_0[];
extern u8 lbl_10_data_25C0__fzgx_offset_0[];
extern u8 lbl_10_data_25D4__fzgx_offset_0[];
extern u8 lbl_10_data_25E4__fzgx_offset_0[];
extern u8 lbl_10_data_25F0__fzgx_offset_0[];
extern u8 lbl_10_data_2600__fzgx_offset_0[];
extern u8 lbl_10_data_2614__fzgx_offset_0[];
extern u8 lbl_10_data_262C__fzgx_offset_0[];
extern u8 lbl_10_data_2638__fzgx_offset_0[];
extern u8 lbl_10_data_2648__fzgx_offset_0[];
extern u8 lbl_10_data_2654__fzgx_offset_0[];
extern u8 lbl_10_data_2664__fzgx_offset_0[];
extern u8 lbl_10_data_2674__fzgx_offset_0[];
extern u8 lbl_10_data_2684__fzgx_offset_0[];
extern u8 lbl_10_data_2694__fzgx_offset_0[];
extern u8 lbl_10_data_26A4__fzgx_offset_0[];
extern u8 lbl_10_data_26AC__fzgx_offset_0[];
extern u8 lbl_10_data_26B8__fzgx_offset_0[];
extern u8 lbl_10_data_26C4__fzgx_offset_0[];
extern u8 lbl_10_data_26D0__fzgx_offset_0[];
extern u8 lbl_10_data_26DC__fzgx_offset_0[];
extern u8 lbl_10_data_26EC__fzgx_offset_0[];
extern u8 lbl_10_data_26F4__fzgx_offset_0[];
extern u8 lbl_10_data_2700__fzgx_offset_0[];
extern u8 lbl_10_data_270C__fzgx_offset_0[];
extern u8 lbl_10_data_2718__fzgx_offset_0[];
extern u8 lbl_10_data_2724__fzgx_offset_0[];
extern u8 lbl_10_data_2730__fzgx_offset_0[];
extern u8 lbl_10_data_273C__fzgx_offset_0[];
extern u8 lbl_10_data_274C__fzgx_offset_0[];
extern u8 lbl_10_data_275C__fzgx_offset_0[];
extern u8 lbl_10_data_276C__fzgx_offset_0[];
extern u8 lbl_10_data_277C__fzgx_offset_0[];
extern u8 lbl_10_data_278C__fzgx_offset_0[];
extern u8 lbl_10_data_2794__fzgx_offset_0[];
extern u8 lbl_10_data_27A0__fzgx_offset_0[];
extern u8 lbl_10_data_27AC__fzgx_offset_0[];
extern u8 lbl_10_data_27B8__fzgx_offset_0[];
extern u8 lbl_10_data_27C4__fzgx_offset_0[];
extern u8 lbl_10_data_27D4__fzgx_offset_0[];
extern u8 lbl_10_data_27DC__fzgx_offset_0[];
extern u8 lbl_10_data_27E8__fzgx_offset_0[];
extern u8 lbl_10_data_27F4__fzgx_offset_0[];
extern u8 lbl_10_data_2800__fzgx_offset_0[];
extern u8 lbl_10_data_280C__fzgx_offset_0[];
extern u8 lbl_10_data_2818__fzgx_offset_0[];
extern u8 lbl_10_data_2824__fzgx_offset_0[];
extern u8 lbl_10_data_2834__fzgx_offset_0[];
extern u8 lbl_10_data_2844__fzgx_offset_0[];
extern u8 lbl_10_data_2854__fzgx_offset_0[];
extern u8 lbl_10_data_2864__fzgx_offset_0[];
extern u8 lbl_10_data_2870__fzgx_offset_0[];
extern u8 lbl_10_data_2880__fzgx_offset_0[];
extern u8 lbl_10_data_2894__fzgx_offset_0[];
extern u8 lbl_10_data_28A8__fzgx_offset_0[];
extern u8 lbl_10_data_28BC__fzgx_offset_0[];
extern u8 lbl_10_data_28D0__fzgx_offset_0[];
extern u8 lbl_10_data_28E0__fzgx_offset_0[];
extern u8 lbl_10_data_28E8__fzgx_offset_0[];
extern u8 lbl_10_data_28F4__fzgx_offset_0[];
extern u8 lbl_10_data_2900__fzgx_offset_0[];
extern u8 lbl_10_data_290C__fzgx_offset_0[];
extern u8 lbl_10_data_2918__fzgx_offset_0[];
extern u8 lbl_10_data_292C__fzgx_offset_0[];
extern u8 lbl_10_data_2938__fzgx_offset_0[];
extern u8 lbl_10_data_2948__fzgx_offset_0[];
extern u8 lbl_10_data_2958__fzgx_offset_0[];
extern u8 lbl_10_data_2968__fzgx_offset_0[];
extern u8 lbl_10_data_2978__fzgx_offset_0[];
extern u8 lbl_10_data_2988__fzgx_offset_0[];
extern u8 lbl_10_data_2998__fzgx_offset_0[];
extern u8 lbl_10_data_29AC__fzgx_offset_0[];
extern u8 lbl_10_data_29C0__fzgx_offset_0[];
extern u8 lbl_10_data_29D4__fzgx_offset_0[];
extern u8 lbl_10_data_29E8__fzgx_offset_0[];
extern u8 lbl_10_data_29FC__fzgx_offset_0[];
extern u8 lbl_10_data_2A08__fzgx_offset_0[];
extern u8 lbl_10_data_2A18__fzgx_offset_0[];
extern u8 lbl_10_data_2A28__fzgx_offset_0[];
extern u8 lbl_10_data_2A38__fzgx_offset_0[];
extern u8 lbl_10_data_2A48__fzgx_offset_0[];
extern u8 lbl_10_data_2A5C__fzgx_offset_0[];
extern u8 lbl_10_data_2A68__fzgx_offset_0[];
extern u8 lbl_10_data_2A78__fzgx_offset_0[];
extern u8 lbl_10_data_2A88__fzgx_offset_0[];
extern u8 lbl_10_data_2A98__fzgx_offset_0[];
extern u8 lbl_10_data_2AA8__fzgx_offset_0[];
extern u8 lbl_10_data_2ABC__fzgx_offset_0[];
extern u8 lbl_10_data_2AC4__fzgx_offset_0[];
extern u8 lbl_10_data_2ACC__fzgx_offset_0[];
extern u8 lbl_10_data_2AD4__fzgx_offset_0[];
extern u8 lbl_10_data_2ADC__fzgx_offset_0[];
extern u8 lbl_10_data_2AE4__fzgx_offset_0[];
extern u8 lbl_10_data_2AF0__fzgx_offset_0[];
extern u8 lbl_10_data_2AF8__fzgx_offset_0[];
extern u8 lbl_10_data_2B04__fzgx_offset_0[];
extern u8 lbl_10_data_2B10__fzgx_offset_0[];
extern u8 lbl_10_data_2B1C__fzgx_offset_0[];
extern u8 lbl_10_data_2B28__fzgx_offset_0[];
extern u8 lbl_10_data_2B3C__fzgx_offset_0[];
extern u8 lbl_10_data_2B50__fzgx_offset_0[];
extern u8 lbl_10_data_2B54__fzgx_offset_0[];
extern u8 lbl_10_data_2B5C__fzgx_offset_0[];
extern u8 lbl_10_data_2B64__fzgx_offset_0[];
extern u8 lbl_10_data_2B6C__fzgx_offset_0[];
extern u8 lbl_10_data_2B74__fzgx_offset_0[];
extern u8 lbl_10_data_2B88__fzgx_offset_0[];
extern u8 lbl_10_data_2B90__fzgx_offset_0[];
extern u8 lbl_10_data_2B9C__fzgx_offset_0[];
extern u8 lbl_10_data_2BA8__fzgx_offset_0[];
extern u8 lbl_10_data_2BB4__fzgx_offset_0[];
extern u8 lbl_10_data_2BC0__fzgx_offset_0[];
extern u8 lbl_10_data_2BCC__fzgx_offset_0[];
extern u8 lbl_10_data_2BD4__fzgx_offset_0[];
extern u8 lbl_10_data_2BE8__fzgx_offset_0[];
extern u8 lbl_10_data_2BF0__fzgx_offset_0[];
extern u8 lbl_10_data_2BF8__fzgx_offset_0[];
extern u8 lbl_10_data_2C08__fzgx_offset_0[];
extern u8 lbl_10_data_2C1C__fzgx_offset_0[];
extern u8 lbl_10_data_2C30__fzgx_offset_0[];
extern u8 lbl_10_data_2C44__fzgx_offset_0[];
extern u8 lbl_10_data_2C58__fzgx_offset_0[];
extern u8 lbl_10_data_2C68__fzgx_offset_0[];
extern u8 lbl_10_data_2C78__fzgx_offset_0[];
extern u8 lbl_10_data_2C8C__fzgx_offset_0[];
extern u8 lbl_10_data_2CA0__fzgx_offset_0[];
extern u8 lbl_10_data_2CB4__fzgx_offset_0[];
extern u8 lbl_10_data_2CC8__fzgx_offset_0[];
extern u8 lbl_10_data_3064__fzgx_offset_0[];
extern u8 lbl_10_data_30B0__fzgx_offset_0[];
extern u8 lbl_10_data_30C0__fzgx_offset_0[];
extern u8 lbl_10_data_30D0__fzgx_offset_0[];
extern u8 lbl_10_data_30E0__fzgx_offset_0[];
extern u8 lbl_10_data_30F0__fzgx_offset_0[];
extern u8 lbl_10_data_3148__fzgx_offset_0[];
extern u8 lbl_10_data_317C__fzgx_offset_0[];
extern u8 lbl_10_data_318C__fzgx_offset_0[];
extern u8 lbl_10_data_319C__fzgx_offset_0[];
extern u8 lbl_10_data_31AC__fzgx_offset_0[];
extern u8 lbl_10_data_31BC__fzgx_offset_0[];
extern u8 lbl_10_data_31F8__fzgx_offset_0[];
extern u8 lbl_10_data_3260__fzgx_offset_0[];
extern u8 lbl_10_data_326C__fzgx_offset_0[];
extern u8 lbl_10_data_3278__fzgx_offset_0[];
extern u8 lbl_10_data_3284__fzgx_offset_0[];
extern u8 lbl_10_data_3290__fzgx_offset_0[];
extern u8 lbl_10_data_330C__fzgx_offset_0[];
extern u8 lbl_10_data_3374__fzgx_offset_0[];
extern u8 lbl_10_data_3384__fzgx_offset_0[];
extern u8 lbl_10_data_3394__fzgx_offset_0[];
extern u8 lbl_10_data_33A4__fzgx_offset_0[];
extern u8 lbl_10_data_33B4__fzgx_offset_0[];
extern u8 lbl_10_data_3430__fzgx_offset_0[];
extern u8 lbl_10_data_34B8__fzgx_offset_0[];
extern u8 lbl_10_data_34C8__fzgx_offset_0[];
extern u8 lbl_10_data_34D8__fzgx_offset_0[];
extern u8 lbl_10_data_34E8__fzgx_offset_0[];
extern u8 lbl_10_data_34F8__fzgx_offset_0[];
extern u8 lbl_10_data_357C__fzgx_offset_0[];
extern u8 lbl_10_data_35F0__fzgx_offset_0[];
extern u8 lbl_10_data_3600__fzgx_offset_0[];
extern u8 lbl_10_data_3610__fzgx_offset_0[];
extern u8 lbl_10_data_3620__fzgx_offset_0[];
extern u8 lbl_10_data_3630__fzgx_offset_0[];
extern u8 lbl_10_data_36B8__fzgx_offset_0[];
extern u8 lbl_10_data_3700__fzgx_offset_0[];
extern u8 lbl_10_data_3710__fzgx_offset_0[];
extern u8 lbl_10_data_3720__fzgx_offset_0[];
extern u8 lbl_10_data_3730__fzgx_offset_0[];
extern u8 lbl_10_data_3740__fzgx_offset_0[];
extern u8 lbl_10_data_3788__fzgx_offset_0[];
extern u8 lbl_10_data_37AC__fzgx_offset_0[];
extern u8 lbl_10_data_37C0__fzgx_offset_0[];
extern u8 lbl_10_data_37D4__fzgx_offset_0[];
extern u8 lbl_10_data_37E8__fzgx_offset_0[];
extern u8 lbl_10_data_37FC__fzgx_offset_0[];
extern u8 lbl_10_data_3824__fzgx_offset_0[];
extern u8 lbl_10_data_38D0__fzgx_offset_0[];
extern u8 lbl_10_data_38E4__fzgx_offset_0[];
extern u8 lbl_10_data_38F8__fzgx_offset_0[];
extern u8 lbl_10_data_390C__fzgx_offset_0[];
extern u8 lbl_10_data_3920__fzgx_offset_0[];
extern u8 lbl_10_data_39CC__fzgx_offset_0[];
extern u8 lbl_10_data_39D8__fzgx_offset_0[];
extern u8 lbl_10_data_39E8__fzgx_offset_0[];
extern u8 lbl_10_data_39F8__fzgx_offset_0[];
extern u8 lbl_10_data_3A08__fzgx_offset_0[];
extern u8 lbl_10_data_3A30__fzgx_offset_0[];
extern u8 lbl_10_data_3A84__fzgx_offset_0[];
extern u8 lbl_10_data_3A98__fzgx_offset_0[];
extern u8 lbl_10_data_3AAC__fzgx_offset_0[];
extern u8 lbl_10_data_3AC0__fzgx_offset_0[];
extern u8 lbl_10_data_3AD4__fzgx_offset_0[];
extern u8 lbl_10_data_3B24__fzgx_offset_0[];
extern u8 lbl_10_data_3BD0__fzgx_offset_0[];
extern u8 lbl_10_data_3BE8__fzgx_offset_0[];
extern u8 lbl_10_data_3C00__fzgx_offset_0[];
extern u8 lbl_10_data_3C18__fzgx_offset_0[];
extern u8 lbl_10_data_3C30__fzgx_offset_0[];
extern u8 lbl_10_data_3CB4__fzgx_offset_0[];
extern u8 lbl_10_data_3D00__fzgx_offset_0[];
extern u8 lbl_10_data_3D10__fzgx_offset_0[];
extern u8 lbl_10_data_3D20__fzgx_offset_0[];
extern u8 lbl_10_data_3D30__fzgx_offset_0[];
extern u8 lbl_10_data_3D40__fzgx_offset_0[];
extern u8 lbl_10_data_3D98__fzgx_offset_0[];
extern u8 lbl_10_data_3DC0__fzgx_offset_0[];
extern u8 lbl_10_data_3DCC__fzgx_offset_0[];
extern u8 lbl_10_data_3DD8__fzgx_offset_0[];
extern u8 lbl_10_data_3DE4__fzgx_offset_0[];
extern u8 lbl_10_data_3DF0__fzgx_offset_0[];
extern u8 lbl_10_data_3E1C__fzgx_offset_0[];
extern u8 lbl_10_data_3E64__fzgx_offset_0[];
extern u8 lbl_10_data_3E74__fzgx_offset_0[];
extern u8 lbl_10_data_3E84__fzgx_offset_0[];
extern u8 lbl_10_data_3E94__fzgx_offset_0[];
extern u8 lbl_10_data_3EA4__fzgx_offset_0[];
extern u8 lbl_10_data_3F00__fzgx_offset_0[];
extern u8 lbl_10_data_3F68__fzgx_offset_0[];
extern u8 lbl_10_data_3F7C__fzgx_offset_0[];
extern u8 lbl_10_data_3F90__fzgx_offset_0[];
extern u8 lbl_10_data_3FA4__fzgx_offset_0[];
extern u8 lbl_10_data_3FB8__fzgx_offset_0[];
extern u8 lbl_10_data_4040__fzgx_offset_0[];
extern u8 lbl_10_data_408C__fzgx_offset_0[];
extern u8 lbl_10_data_40A4__fzgx_offset_0[];
extern u8 lbl_10_data_40BC__fzgx_offset_0[];
extern u8 lbl_10_data_40D4__fzgx_offset_0[];
extern u8 lbl_10_data_40EC__fzgx_offset_0[];
extern u8 lbl_10_data_4124__fzgx_offset_0[];
extern u8 lbl_10_data_4178__fzgx_offset_0[];
extern u8 lbl_10_data_4184__fzgx_offset_0[];
extern u8 lbl_10_data_4190__fzgx_offset_0[];
extern u8 lbl_10_data_419C__fzgx_offset_0[];
extern u8 lbl_10_data_41A8__fzgx_offset_0[];
extern u8 lbl_10_data_4200__fzgx_offset_0[];
extern u8 lbl_10_data_42E8__fzgx_offset_0[];
extern u8 lbl_10_data_42F4__fzgx_offset_0[];
extern u8 lbl_10_data_4300__fzgx_offset_0[];
extern u8 lbl_10_data_430C__fzgx_offset_0[];
extern u8 lbl_10_data_4318__fzgx_offset_0[];
extern u8 lbl_10_data_43DC__fzgx_offset_0[];
extern u8 lbl_10_data_441C__fzgx_offset_0[];
extern u8 lbl_10_data_442C__fzgx_offset_0[];
extern u8 lbl_10_data_443C__fzgx_offset_0[];
extern u8 lbl_10_data_444C__fzgx_offset_0[];
extern u8 lbl_10_data_445C__fzgx_offset_0[];
extern u8 lbl_10_data_44B4__fzgx_offset_0[];
extern u8 lbl_10_data_44E0__fzgx_offset_0[];
extern u8 lbl_10_data_44F4__fzgx_offset_0[];
extern u8 lbl_10_data_4508__fzgx_offset_0[];
extern u8 lbl_10_data_451C__fzgx_offset_0[];
extern u8 lbl_10_data_4530__fzgx_offset_0[];
extern u8 lbl_10_data_4554__fzgx_offset_0[];
extern u8 lbl_10_data_45AC__fzgx_offset_0[];
extern u8 lbl_10_data_45BC__fzgx_offset_0[];
extern u8 lbl_10_data_45CC__fzgx_offset_0[];
extern u8 lbl_10_data_45DC__fzgx_offset_0[];
extern u8 lbl_10_data_45EC__fzgx_offset_0[];
extern u8 lbl_10_data_463C__fzgx_offset_0[];
extern u8 lbl_10_data_4668__fzgx_offset_0[];
extern u8 lbl_10_data_4678__fzgx_offset_0[];
extern u8 lbl_10_data_4688__fzgx_offset_0[];
extern u8 lbl_10_data_4698__fzgx_offset_0[];
extern u8 lbl_10_data_46A8__fzgx_offset_0[];
extern u8 lbl_10_data_46FC__fzgx_offset_0[];
extern u8 lbl_10_data_472C__fzgx_offset_0[];
extern u8 lbl_10_data_4740__fzgx_offset_0[];
extern u8 lbl_10_data_4754__fzgx_offset_0[];
extern u8 lbl_10_data_4768__fzgx_offset_0[];
extern u8 lbl_10_data_477C__fzgx_offset_0[];
extern u8 lbl_10_data_47C4__fzgx_offset_0[];
extern u8 lbl_10_data_4810__fzgx_offset_0[];
extern u8 lbl_10_data_482C__fzgx_offset_0[];
extern u8 lbl_10_data_4848__fzgx_offset_0[];
extern u8 lbl_10_data_4864__fzgx_offset_0[];
extern u8 lbl_10_data_4880__fzgx_offset_0[];
extern u8 lbl_10_data_48C8__fzgx_offset_0[];
extern u8 lbl_10_data_48DC__fzgx_offset_0[];
extern u8 lbl_10_data_48F0__fzgx_offset_0[];
extern u8 lbl_10_data_4904__fzgx_offset_0[];
extern u8 lbl_10_data_4918__fzgx_offset_0[];
extern u8 lbl_10_data_492C__fzgx_offset_0[];
extern u8 lbl_10_data_4948__fzgx_offset_0[];
extern u8 lbl_10_data_4964__fzgx_offset_0[];
extern u8 lbl_10_data_4978__fzgx_offset_0[];
extern u8 lbl_10_data_498C__fzgx_offset_0[];
extern u8 lbl_10_data_49A0__fzgx_offset_0[];
extern u8 lbl_10_data_49B4__fzgx_offset_0[];
extern u8 lbl_10_data_49D0__fzgx_offset_0[];
extern u8 lbl_10_data_49E8__fzgx_offset_0[];
extern u8 lbl_10_data_4A00__fzgx_offset_0[];
extern u8 lbl_10_data_4A18__fzgx_offset_0[];
extern u8 lbl_10_data_4A30__fzgx_offset_0[];
extern u8 lbl_10_data_4A48__fzgx_offset_0[];
extern u8 lbl_10_data_4A68__fzgx_offset_0[];
extern u8 lbl_10_data_4AB4__fzgx_offset_0[];
extern u8 lbl_10_data_4DB0__fzgx_offset_0[];
extern u8 lbl_10_data_4DDC__fzgx_offset_0[];
extern u8 lbl_10_data_4DF0__fzgx_offset_0[];
extern u8 lbl_10_data_4E04__fzgx_offset_0[];
extern u8 lbl_10_data_4E18__fzgx_offset_0[];
extern u8 lbl_10_data_4E2C__fzgx_offset_0[];
extern u8 lbl_10_data_4E4C__fzgx_offset_0[];
extern u8 lbl_10_data_4E70__fzgx_offset_0[];
extern u8 lbl_10_data_4E84__fzgx_offset_0[];
extern u8 lbl_10_data_4E98__fzgx_offset_0[];
extern u8 lbl_10_data_4EAC__fzgx_offset_0[];
extern u8 lbl_10_data_4EC0__fzgx_offset_0[];
extern u8 lbl_10_data_4EF0__fzgx_offset_0[];
extern u8 lbl_10_data_4F18__fzgx_offset_0[];
extern u8 lbl_10_data_4F2C__fzgx_offset_0[];
extern u8 lbl_10_data_4F40__fzgx_offset_0[];
extern u8 lbl_10_data_4F54__fzgx_offset_0[];
extern u8 lbl_10_data_4F68__fzgx_offset_0[];
extern u8 lbl_10_data_4F88__fzgx_offset_0[];
extern u8 lbl_10_data_4FB4__fzgx_offset_0[];
extern u8 lbl_10_data_4FCC__fzgx_offset_0[];
extern u8 lbl_10_data_4FE4__fzgx_offset_0[];
extern u8 lbl_10_data_4FFC__fzgx_offset_0[];
extern u8 lbl_10_data_5014__fzgx_offset_0[];
extern u8 lbl_10_data_5038__fzgx_offset_0[];
extern u8 lbl_10_data_5064__fzgx_offset_0[];
extern u8 lbl_10_data_5074__fzgx_offset_0[];
extern u8 lbl_10_data_5084__fzgx_offset_0[];
extern u8 lbl_10_data_5094__fzgx_offset_0[];
extern u8 lbl_10_data_50A4__fzgx_offset_0[];
extern u8 lbl_10_data_50D4__fzgx_offset_0[];
extern u8 lbl_10_data_50EC__fzgx_offset_0[];
extern u8 lbl_10_data_5104__fzgx_offset_0[];
extern u8 lbl_10_data_511C__fzgx_offset_0[];
extern u8 lbl_10_data_5134__fzgx_offset_0[];
extern u8 lbl_10_data_514C__fzgx_offset_0[];
extern u8 lbl_10_data_516C__fzgx_offset_0[];
extern u8 lbl_10_data_51AC__fzgx_offset_0[];
extern u8 lbl_10_data_51C4__fzgx_offset_0[];
extern u8 lbl_10_data_51DC__fzgx_offset_0[];
extern u8 lbl_10_data_51F4__fzgx_offset_0[];
extern u8 lbl_10_data_520C__fzgx_offset_0[];
extern u8 lbl_10_data_5254__fzgx_offset_0[];
extern u8 lbl_10_data_5284__fzgx_offset_0[];
extern u8 lbl_10_data_5294__fzgx_offset_0[];
extern u8 lbl_10_data_52A4__fzgx_offset_0[];
extern u8 lbl_10_data_52B4__fzgx_offset_0[];
extern u8 lbl_10_data_52C4__fzgx_offset_0[];
extern u8 lbl_10_data_52F4__fzgx_offset_0[];
extern u8 lbl_10_data_535C__fzgx_offset_0[];
extern u8 lbl_10_data_5378__fzgx_offset_0[];
extern u8 lbl_10_data_5394__fzgx_offset_0[];
extern u8 lbl_10_data_53B0__fzgx_offset_0[];
extern u8 lbl_10_data_53CC__fzgx_offset_0[];
extern u8 lbl_10_data_541C__fzgx_offset_0[];
extern u8 lbl_10_data_5454__fzgx_offset_0[];
extern u8 lbl_10_data_5468__fzgx_offset_0[];
extern u8 lbl_10_data_547C__fzgx_offset_0[];
extern u8 lbl_10_data_5490__fzgx_offset_0[];
extern u8 lbl_10_data_54A4__fzgx_offset_0[];
extern u8 lbl_10_data_54E8__fzgx_offset_0[];
extern u8 lbl_10_data_54F4__fzgx_offset_0[];
extern u8 lbl_10_data_5504__fzgx_offset_0[];
extern u8 lbl_10_data_5514__fzgx_offset_0[];
extern u8 lbl_10_data_5524__fzgx_offset_0[];
extern u8 lbl_10_data_5534__fzgx_offset_0[];
extern u8 lbl_10_data_5540__fzgx_offset_0[];
extern u8 lbl_10_data_5560__fzgx_offset_0[];
extern u8 lbl_10_data_5570__fzgx_offset_0[];
extern u8 lbl_10_data_5580__fzgx_offset_0[];
extern u8 lbl_10_data_5590__fzgx_offset_0[];
extern u8 lbl_10_data_55A0__fzgx_offset_0[];
extern u8 lbl_10_data_55B8__fzgx_offset_0[];
extern u8 lbl_10_data_55D8__fzgx_offset_0[];
extern u8 lbl_10_data_56AC__fzgx_offset_0[];
extern u8 lbl_10_data_56C4__fzgx_offset_0[];
extern u8 lbl_10_data_56DC__fzgx_offset_0[];
extern u8 lbl_10_data_56F4__fzgx_offset_0[];
extern u8 lbl_10_data_570C__fzgx_offset_0[];
extern u8 lbl_10_data_57A0__fzgx_offset_0[];
extern u8 lbl_10_data_57F4__fzgx_offset_0[];
extern u8 lbl_10_data_5810__fzgx_offset_0[];
extern u8 lbl_10_data_582C__fzgx_offset_0[];
extern u8 lbl_10_data_5848__fzgx_offset_0[];
extern u8 lbl_10_data_5864__fzgx_offset_0[];
extern u8 lbl_10_data_589C__fzgx_offset_0[];
extern u8 lbl_10_data_590C__fzgx_offset_0[];
extern u8 lbl_10_data_5924__fzgx_offset_0[];
extern u8 lbl_10_data_593C__fzgx_offset_0[];
extern u8 lbl_10_data_5954__fzgx_offset_0[];
extern u8 lbl_10_data_596C__fzgx_offset_0[];
extern u8 lbl_10_data_59D0__fzgx_offset_0[];
extern u8 lbl_10_data_5A34__fzgx_offset_0[];
extern u8 lbl_10_data_5A48__fzgx_offset_0[];
extern u8 lbl_10_data_5A5C__fzgx_offset_0[];
extern u8 lbl_10_data_5A70__fzgx_offset_0[];
extern u8 lbl_10_data_5A84__fzgx_offset_0[];
extern u8 lbl_10_data_5AC4__fzgx_offset_0[];
extern u8 lbl_10_data_5AF0__fzgx_offset_0[];
extern u8 lbl_10_data_5B0C__fzgx_offset_0[];
extern u8 lbl_10_data_5B28__fzgx_offset_0[];
extern u8 lbl_10_data_5B44__fzgx_offset_0[];
extern u8 lbl_10_data_5B60__fzgx_offset_0[];
extern u8 lbl_10_data_5B90__fzgx_offset_0[];
extern u8 lbl_10_data_5BAC__fzgx_offset_0[];
extern u8 lbl_10_data_5BC0__fzgx_offset_0[];
extern u8 lbl_10_data_5BD4__fzgx_offset_0[];
extern u8 lbl_10_data_5BE8__fzgx_offset_0[];
extern u8 lbl_10_data_5BFC__fzgx_offset_0[];
extern u8 lbl_10_data_5DE4__fzgx_offset_0[];
extern u8 lbl_10_data_5DFC__fzgx_offset_0[];
extern u8 lbl_10_data_D00__fzgx_offset_0[];
extern u8 lbl_10_data_D04__fzgx_offset_0[];
extern u8 lbl_10_data_D10__fzgx_offset_0[];
extern u8 lbl_10_data_D1C__fzgx_offset_0[];
extern u8 lbl_10_data_D28__fzgx_offset_0[];
extern u8 lbl_10_data_D34__fzgx_offset_0[];
extern u8 lbl_10_data_D3C__fzgx_offset_0[];
extern u8 lbl_10_data_D44__fzgx_offset_0[];
extern u8 lbl_10_data_D4C__fzgx_offset_0[];
extern u8 lbl_10_data_D54__fzgx_offset_0[];
extern u8 lbl_10_data_D60__fzgx_offset_0[];
extern u8 lbl_10_data_D70__fzgx_offset_0[];
extern u8 lbl_10_data_D80__fzgx_offset_0[];
extern u8 lbl_10_data_D88__fzgx_offset_0[];
extern u8 lbl_10_data_D90__fzgx_offset_0[];
extern u8 lbl_10_data_D9C__fzgx_offset_0[];
extern u8 lbl_10_data_DA8__fzgx_offset_0[];
extern u8 lbl_10_data_DB8__fzgx_offset_0[];
extern u8 lbl_10_data_DC0__fzgx_offset_0[];
extern u8 lbl_10_data_DCC__fzgx_offset_0[];
extern u8 lbl_10_data_DD8__fzgx_offset_0[];
extern u8 lbl_10_data_DE8__fzgx_offset_0[];
extern u8 lbl_10_data_DF0__fzgx_offset_0[];
extern u8 lbl_10_data_DFC__fzgx_offset_0[];
extern u8 lbl_10_data_E08__fzgx_offset_0[];
extern u8 lbl_10_data_E18__fzgx_offset_0[];
extern u8 lbl_10_data_E20__fzgx_offset_0[];
extern u8 lbl_10_data_E2C__fzgx_offset_0[];
extern u8 lbl_10_data_E34__fzgx_offset_0[];
extern u8 lbl_10_data_E40__fzgx_offset_0[];
extern u8 lbl_10_data_E50__fzgx_offset_0[];
extern u8 lbl_10_data_E5C__fzgx_offset_0[];
extern u8 lbl_10_data_E68__fzgx_offset_0[];
extern u8 lbl_10_data_E70__fzgx_offset_0[];
extern u8 lbl_10_data_E84__fzgx_offset_0[];
extern u8 lbl_10_data_E94__fzgx_offset_0[];
extern u8 lbl_10_data_EA4__fzgx_offset_0[];
extern u8 lbl_10_data_EB0__fzgx_offset_0[];
extern u8 lbl_10_data_EBC__fzgx_offset_0[];
extern u8 lbl_10_data_ECC__fzgx_offset_0[];
extern u8 lbl_10_data_ED4__fzgx_offset_0[];
extern u8 lbl_10_data_EE0__fzgx_offset_0[];
extern u8 lbl_10_data_EE8__fzgx_offset_0[];
extern u8 lbl_10_data_EF0__fzgx_offset_0[];
extern u8 lbl_10_data_EF8__fzgx_offset_0[];
extern u8 lbl_10_data_FB4__fzgx_offset_0[];
static u32 fzgx_pool_data_lbl_10_data_D00[2261] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156,
    0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x0, 0x54455354,
    0x0, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000,
    0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000,
    0x554E4C49, 0x4E4B0000, 0x434F494E, 0x0, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C,
    0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000,
    0x454E5452, 0x595F4F4B, 0x0, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348,
    0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552,
    0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500,
    0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000,
    0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x0, 0x4C494E4B,
    0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152,
    0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x0, 0x4C494E4B, 0x44454C49, 0x56455259,
    0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552,
    0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900,
    0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x0, 0x50415553, 0x45000000, 0x4552524F, 0x52000000,
    (u32)lbl_10_data_D00__fzgx_offset_0, (u32)lbl_10_data_D04__fzgx_offset_0, (u32)lbl_10_data_D10__fzgx_offset_0, (u32)lbl_10_data_D1C__fzgx_offset_0, (u32)lbl_10_data_D28__fzgx_offset_0, (u32)lbl_10_data_D34__fzgx_offset_0, (u32)lbl_10_data_D3C__fzgx_offset_0, (u32)lbl_10_data_D44__fzgx_offset_0,
    (u32)lbl_10_data_D4C__fzgx_offset_0, (u32)lbl_10_data_D54__fzgx_offset_0, (u32)lbl_10_data_D60__fzgx_offset_0, (u32)lbl_10_data_D70__fzgx_offset_0, (u32)lbl_10_data_D80__fzgx_offset_0, (u32)lbl_10_data_D88__fzgx_offset_0, (u32)lbl_10_data_D90__fzgx_offset_0, (u32)lbl_10_data_D9C__fzgx_offset_0,
    (u32)lbl_10_data_DA8__fzgx_offset_0, (u32)lbl_10_data_DB8__fzgx_offset_0, (u32)lbl_10_data_DC0__fzgx_offset_0, (u32)lbl_10_data_DCC__fzgx_offset_0, (u32)lbl_10_data_DD8__fzgx_offset_0, (u32)lbl_10_data_DE8__fzgx_offset_0, (u32)lbl_10_data_DF0__fzgx_offset_0, (u32)lbl_10_data_DFC__fzgx_offset_0,
    (u32)lbl_10_data_E08__fzgx_offset_0, (u32)lbl_10_data_E18__fzgx_offset_0, (u32)lbl_10_data_E20__fzgx_offset_0, (u32)lbl_10_data_E2C__fzgx_offset_0, (u32)lbl_10_data_E34__fzgx_offset_0, (u32)lbl_10_data_E40__fzgx_offset_0, (u32)lbl_10_data_E50__fzgx_offset_0, (u32)lbl_10_data_E5C__fzgx_offset_0,
    (u32)lbl_10_data_E68__fzgx_offset_0, (u32)lbl_10_data_E70__fzgx_offset_0, (u32)lbl_10_data_E84__fzgx_offset_0, (u32)lbl_10_data_E94__fzgx_offset_0, (u32)lbl_10_data_EA4__fzgx_offset_0, (u32)lbl_10_data_EB0__fzgx_offset_0, (u32)lbl_10_data_EBC__fzgx_offset_0, (u32)lbl_10_data_ECC__fzgx_offset_0,
    (u32)lbl_10_data_ED4__fzgx_offset_0, (u32)lbl_10_data_EE0__fzgx_offset_0, (u32)lbl_10_data_EE8__fzgx_offset_0, (u32)lbl_10_data_EF0__fzgx_offset_0, (u32)lbl_10_data_EF8__fzgx_offset_0, 0x54686973, 0x20697320, 0x796F7572,
    0x206F7269, 0x67696E61, 0x6C206D61, 0x6368696E, 0x652E200A, 0x4561726E, 0x20796F75, 0x72205069,
    0x6C6F7420, 0x506F696E, 0x74732062, 0x7920706C, 0x6179696E, 0x670A616E, 0x64206578, 0x6368616E,
    0x67652074, 0x68656D20, 0x666F7220, 0x74686520, 0x70617274, 0x732E200A, 0x43757374, 0x6F6D697A,
    0x65206974, 0x20696E20, 0x796F7572, 0x206F776E, 0x20776179, 0x2E200000, 0x0, 0x82A082C8,
    0x82BD82BE, 0x82AF82CC, 0x8349838A, 0x83578369, 0x838B837D, 0x83568393, 0x82C582B7, 0x81420A91,  /* fzgx-allow: A1 retail data bytes */
    0x968D7382, 0xC582E082, 0xE782A682, 0xE9837083, 0x43838D83, 0x62836783, 0x7C834383, 0x93836782,
    0xF08F5782, 0xDF82E982, 0xC60A8370, 0x815B8363, 0x82CC8CF0, 0x8AB782AA, 0x82C582AB, 0x82DC82B7,  /* fzgx-allow: A1 retail data bytes */
    0x81420A8E, 0xA995AA82, 0xBE82AF82, 0xCC837D83, 0x56839382, 0xC9834A83, 0x58835E83, 0x7D834383,  /* fzgx-allow: A1 retail data bytes */
    0x5982B582, 0xC482AD82, 0xBE82B382, 0xA2814200, 0x596F7572, 0x20706C61, 0x79206461, 0x74612061,
    0x6E642079, 0x6F757220, 0x6D616368, 0x696E6520, 0x64617461, 0x2E200000, 0x82A082C8, 0x82BD82CC,
    0x8376838C, 0x83438FEE, 0x95F182C6, 0x8349838A, 0x83578369, 0x838B837D, 0x83568393, 0x8FEE95F1,
    0x82C582B7, 0x81420000, 0x91CE90ED, 0x8ED282F0, 0x95E58F57, 0x928682C5, 0x82B78142, 0x82B582CE,  /* fzgx-allow: A1 retail data bytes */
    0x82E782AD, 0x82A891D2, 0x82BF82AD, 0x82BE82B3, 0x82A28142, 0x0, 0x50726573, 0x73207374,
    0x6172742E, 0x20205761, 0x6974696E, 0x6720666F, 0x72206368, 0x616C6C65, 0x6E676572, 0x732E2000,
    0x91CE90ED, 0x8ED282F0, 0x95E58F57, 0x928682C5, 0x82B78142, 0x8358835E, 0x815B8367, 0x837B835E,  /* fzgx-allow: A1 retail data bytes */
    0x839382F0, 0x899F82B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0, 0x53656C65, 0x63742047,
    0x616D6520, 0x4D6F6465, 0x2E200000, 0x8382815B, 0x836882F0, 0x914991F0, 0x82B582C4, 0x82AD82BE,
    0x82B382A2, 0x81420000, 0x53656C65, 0x63742061, 0x20437570, 0x2E200000, 0x834A8362, 0x837682F0,  /* fzgx-allow: A1 retail data bytes */
    0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x53656C65, 0x63742061, 0x20436F75,  /* fzgx-allow: A1 retail data bytes */
    0x7273652E, 0x20000000, 0x8352815B, 0x835882F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2,
    0x81420000, 0x53656C65, 0x63742043, 0x6F757273, 0x6520616E, 0x64204768, 0x6F73742E, 0x20000000,  /* fzgx-allow: A1 retail data bytes */
    0x8352815B, 0x835882CC, 0x914991F0, 0x82C68353, 0x815B8358, 0x836782CC, 0x90DD92E8, 0x82F08D73,  /* fzgx-allow: A1 retail data bytes */
    0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x53656C65, 0x63742059, 0x6F757220, 0x4D616368,  /* fzgx-allow: A1 retail data bytes */
    0x696E652E, 0x20000000, 0x837D8356, 0x839382F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2,
    0x81420000, 0x596F7520, 0x63616E20, 0x73656C65, 0x63742079, 0x6F757220, 0x6D616368, 0x696E6520,  /* fzgx-allow: A1 retail data bytes */
    0x66726F6D, 0x20462D5A, 0x45524F20, 0x47582061, 0x7320796F, 0x75207573, 0x6520796F, 0x7572204E,
    0x494E5445, 0x4E444F20, 0x47414D45, 0x43554245, 0x204D656D, 0x6F727920, 0x43617264, 0x2E200000,
    0x836A8393, 0x83658393, 0x8368815B, 0x8351815B, 0x8380834C, 0x8385815B, 0x83758140, 0x83818382,
    0x838A815B, 0x834A815B, 0x836882F0, 0x8E679770, 0x82B782E9, 0x82C6462D, 0x5A45524F, 0x20475882,
    0xC5936F98, 0x5E82B582, 0xBD837D83, 0x56839382, 0xAA914991, 0xF082C582, 0xAB82DC82, 0xB7814200,
    0x596F7520, 0x63616E20, 0x73656C65, 0x63742074, 0x6865206F, 0x72696769, 0x6E616C20, 0x6D616368,
    0x696E6520, 0x61732079, 0x6F752070, 0x75726368, 0x61736520, 0x74686520, 0x462D5A45, 0x524F204C,
    0x4943454E, 0x53452043, 0x4152442E, 0x20000000, 0x462D5A45, 0x524F8389, 0x8343835A, 0x83938358,
    0x834A815B, 0x836882F0, 0x8D7793FC, 0x82B782E9, 0x82C68141, 0x8349838A, 0x83578369, 0x838B837D,
    0x83568393, 0x82AA9149, 0x91F082C5, 0x82AB82DC, 0x82B78142, 0x0, 0x4E6F2047, 0x686F7374,
    0x0, 0x8353815B, 0x83588367, 0x82C691CE, 0x90ED82B5, 0x82DC82B9, 0x82F10000, 0x47686F73,
    0x74204269, 0x74204661, 0x73746572, 0x20546861, 0x6E20596F, 0x75722042, 0x65737420, 0x54696D65,
    0x0, 0x8EA98CC8, 0x83788358, 0x8367835E, 0x83438380, 0x82E682E8, 0x8FAD82B5, 0x91AC82A2,
    0x8353815B, 0x83588367, 0x82C582B7, 0x0, 0x46617374, 0x65737420, 0x47686F73, 0x74206279,
    0x20656163, 0x68204D61, 0x6368696E, 0x65000000, 0x837D8356, 0x839395CA, 0x82CC8DC5, 0x91AC8353,
    0x815B8358, 0x836782C5, 0x82B70000, 0x546F7020, 0x52616E6B, 0x696E6720, 0x47686F73, 0x74000000,  /* fzgx-allow: A1 retail data bytes */
    0x83898393, 0x834C8393, 0x834F3188, 0xCA82CC83, 0x53815B83, 0x58836782, 0xC582B700, 0x42617474,
    0x6C652077, 0x69746820, 0x53746166, 0x66204768, 0x6F737400, 0x8358835E, 0x83628374, 0x8353815B,
    0x83588367, 0x82C582B7, 0x0, 0x52616365, 0x204D6F64, 0x65000000, 0x838C815B, 0x83588382,
    0x815B8368, 0x0, 0x54696D65, 0x20417474, 0x61636B20, 0x4D6F6465, 0x0, 0x835E8343,  /* fzgx-allow: A1 retail data bytes */
    0x83808341, 0x835E8362, 0x834E8382, 0x815B8368, 0x0, 0x4120746F, 0x74616C20, 0x6F662033,  /* fzgx-allow: A1 retail data bytes */
    0x30206D61, 0x6368696E, 0x65732069, 0x6E206561, 0x63682072, 0x6163652E, 0x200A5261, 0x63652066,
    0x6F722074, 0x68652074, 0x6F702070, 0x6F736974, 0x696F6E20, 0x6F6E2065, 0x61636820, 0x636F7572,
    0x73652E20, 0x0, 0x91533330, 0x91E482AA, 0x8F6F9196, 0x82B58141, 0x825082C2, 0x82CC8352,
    0x815B8358, 0x82C58F87, 0x88CA82F0, 0x8BA382A2, 0x82DC82B7, 0x81420A8A, 0x65835281, 0x5B835882,  /* fzgx-allow: A1 retail data bytes */
    0xC5825088, 0xCA82F096, 0xDA8E7782, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x4120746F,
    0x74616C20, 0x6F662033, 0x30206D61, 0x6368696E, 0x65732069, 0x6E206561, 0x63682072, 0x6163652E,
    0x200A0950, 0x6C617965, 0x72732063, 0x616E2072, 0x61636520, 0x61676169, 0x6E737420, 0x65616368,
    0x206F7468, 0x65722069, 0x6E207665, 0x72737573, 0x20706C61, 0x792E200A, 0x2009596F, 0x75206361,
    0x6E20736B, 0x69702074, 0x68652076, 0x65727375, 0x7320706C, 0x61792062, 0x79207365, 0x6C656374,
    0x696E6720, 0x74686520, 0x6D6F6465, 0x200A0920, 0x7768696C, 0x65207374, 0x65707069, 0x6E67206F,
    0x6E207468, 0x65206272, 0x65616B73, 0x2E200A00, 0x91533330, 0x91E482AA, 0x8F6F9196, 0x82B58141,
    0x825082C2, 0x82CC8352, 0x815B8358, 0x82C58F87, 0x88CA82F0, 0x8BA382A2, 0x82DC82B7, 0x81420A09,  /* fzgx-allow: A1 retail data bytes */
    0x202F6263, 0x66666632, 0x30302F81, 0x75837683, 0x8C834383, 0x84815B93, 0xAF8E6D82, 0xCC91CE90,
    0xED837683, 0x8C834381, 0x762F6263, 0x66666666, 0x66662F82, 0xE089C294, 0x5C82C582, 0xB781420A,
    0x9208375, 0x838C815B, 0x834C82F0, 0x93A582F1, 0x82BE8FF3, 0x91D482C5, 0x8382815B, 0x836882F0,
    0x8C8892E8, 0x82B782E9, 0x82C62F62, 0x63666666, 0x3230302F, 0x9817591, 0xCE90ED82, 0xF0834C83,
    0x83839383, 0x5A838B81, 0x762F6263, 0x66666666, 0x66662F82, 0xC582AB82, 0xDC82B781, 0x420A0000,
    0x436F6D70, 0x65746520, 0x62792079, 0x6F757273, 0x656C6620, 0x666F7220, 0x74686520, 0x42657374,
    0x20546F74, 0x616C206F, 0x66206365, 0x72746169, 0x6E206C61, 0x70732E20, 0xA095365, 0x6C656374,
    0x20656974, 0x68657220, 0x736F6C6F, 0x206F7220, 0x61676169, 0x6E737420, 0x74686520, 0x67686F73,
    0x742E0A00, 0x8352815B, 0x835882F0, 0x8B4B92E8, 0x8EFC89F1, 0x91968D73, 0x82B58141, 0x82BB82CC,
    0x8367815B, 0x835E838B, 0x835E8343, 0x838082F0, 0x8BA382A2, 0x82DC82B7, 0x81420A09, 0x2F626366,  /* fzgx-allow: A1 retail data bytes */
    0x66663230, 0x302F8175, 0x925093C6, 0x91968D73, 0x81458353, 0x815B8358, 0x8367834A, 0x815B91CE,  /* fzgx-allow: A1 retail data bytes */
    0x90ED8176, 0x2F626366, 0x66666666, 0x662F82CC, 0x82A282B8, 0x82EA82A9, 0x82F09149, 0x82D782DC,
    0x82B78142, 0xA000000, 0x596F7520, 0x63616E20, 0x6A6F696E, 0x20746865, 0x20496E74, 0x65726E65,
    0x74205261, 0x6E6B696E, 0x67207769, 0x74682079, 0x6F757220, 0x70617373, 0x776F7264, 0x2E200A00,
    0x83708358, 0x838F815B, 0x836882C9, 0x82E682E9, 0x2F626366, 0x66663230, 0x302F8175, 0x836C8362,
    0x83678389, 0x8393834C, 0x8393834F, 0x81762F62, 0x63666666, 0x6666662F, 0x82E08A4A, 0x8DC39286,  /* fzgx-allow: A1 retail data bytes */
    0x82C582B7, 0x81420A00, 0x56532042, 0x4154544C, 0x450A4E6F, 0x20636F6D, 0x70757465, 0x72732E20,  /* fzgx-allow: A1 retail data bytes */
    0xA095369, 0x6E676C65, 0x20706C61, 0x79207769, 0x6C6C2062, 0x65206120, 0x6E6F726D, 0x616C2072,
    0x61636520, 0x77697468, 0x20636F6D, 0x70757465, 0x72732E20, 0xA000000, 0x82758272, 0x81408261,  /* fzgx-allow: A1 retail data bytes */
    0x82608273, 0x8273826B, 0x826482C5, 0x82B78142, 0xA835283, 0x93837383, 0x85815B83, 0x5E82CD8E,
    0x5189C182, 0xB582DC82, 0xB982F181, 0x420A0982, 0x50906C83, 0x76838C83, 0x4382CD92, 0xCA8FED82,
    0xCC838C81, 0x5B835882, 0xC982C882, 0xE882DC82, 0xB781420A, 0x0, 0x454D5054, 0x59000000,
    0x54776F20, 0x6F72206D, 0x6F726520, 0x436F6E74, 0x726F6C6C, 0x65727320, 0x61726520, 0x6E656564,
    0x65642E20, 0x0, 0x3282C288, 0xC88FE382, 0xCC835283, 0x93836783, 0x8D815B83, 0x8982AA95,
    0x4B977682, 0xC582B781, 0x42000000, 0x2564506C, 0x61796572, 0x73000000, 0x2564906C, 0x91CE90ED,
    0x0, 0x5245434F, 0x52445300, 0x54686973, 0x20697320, 0x61207061, 0x7373776F, 0x72642066,
    0x6F722069, 0x6E746572, 0x6E657420, 0x72616E6B, 0x696E672E, 0x0, 0x47455220, 0x54686973,
    0x20697320, 0x61207061, 0x7373776F, 0x72642066, 0x6F722069, 0x6E746572, 0x6E657420, 0x72616E6B,
    0x696E672E, 0x0, 0x46524520, 0x54686973, 0x20697320, 0x61207061, 0x7373776F, 0x72642066,
    0x6F722069, 0x6E746572, 0x6E657420, 0x72616E6B, 0x696E672E, 0x0, 0x53504120, 0x54686973,
    0x20697320, 0x61207061, 0x7373776F, 0x72642066, 0x6F722069, 0x6E746572, 0x6E657420, 0x72616E6B,
    0x696E672E, 0x0, 0x49544120, 0x54686973, 0x20697320, 0x61207061, 0x7373776F, 0x72642066,
    0x6F722069, 0x6E746572, 0x6E657420, 0x72616E6B, 0x696E672E, 0x0, 0x82B182EA, 0x82CD8343,
    0x8393835E, 0x815B836C, 0x83628367, 0x83898393, 0x834C8393, 0x834F9770, 0x83708358, 0x838F815B,  /* fzgx-allow: A1 retail data bytes */
    0x836882C5, 0x82B70000, 0x54686572, 0x65206973, 0x206E6F20, 0x64617461, 0x2E200000, 0x47455220,
    0x54686572, 0x65206973, 0x206E6F20, 0x64617461, 0x2E000000, 0x46524520, 0x54686572, 0x65206973,
    0x206E6F20, 0x64617461, 0x2E000000, 0x53504120, 0x54686572, 0x65206973, 0x206E6F20, 0x64617461,
    0x2E000000, 0x49544120, 0x54686572, 0x65206973, 0x206E6F20, 0x64617461, 0x2E000000, 0x8366815B,
    0x835E82AA, 0x82A082E8, 0x82DC82B9, 0x82F18142, 0x0, 0x54686973, 0x20646174, 0x61206973,
    0x20696E63, 0x6F727265, 0x63742E00, 0x47455220, 0x54686973, 0x20646174, 0x61206973, 0x20696E63,
    0x6F727265, 0x63742E00, 0x46524520, 0x54686973, 0x20646174, 0x61206973, 0x20696E63, 0x6F727265,
    0x63742E00, 0x53504120, 0x54686973, 0x20646174, 0x61206973, 0x20696E63, 0x6F727265, 0x63742E00,
    0x49544120, 0x54686973, 0x20646174, 0x61206973, 0x20696E63, 0x6F727265, 0x63742E00, 0x957390B3,
    0x82C88366, 0x815B835E, 0x82C582B7, 0x81420000, 0x596F7520, 0x68617665, 0x6E277420, 0x62656174,  /* fzgx-allow: A1 retail data bytes */
    0x656E2074, 0x68652073, 0x65742074, 0x696D652E, 0x0, 0x47455220, 0x596F7520, 0x68617665,
    0x6E277420, 0x62656174, 0x656E2074, 0x68652073, 0x65742074, 0x696D652E, 0x0, 0x46524520,
    0x596F7520, 0x68617665, 0x6E277420, 0x62656174, 0x656E2074, 0x68652073, 0x65742074, 0x696D652E,
    0x0, 0x53504120, 0x596F7520, 0x68617665, 0x6E277420, 0x62656174, 0x656E2074, 0x68652073,
    0x65742074, 0x696D652E, 0x0, 0x49544120, 0x596F7520, 0x68617665, 0x6E277420, 0x62656174,
    0x656E2074, 0x68652073, 0x65742074, 0x696D652E, 0x0, 0x8B4B92E8, 0x835E8343, 0x838082C9,
    0x924282B5, 0x82C482A2, 0x82DC82B9, 0x82F18142, 0x0, 0x4D616368, 0x696E6500, 0x47455220,
    0x4D616368, 0x696E6500, 0x46524520, 0x4D616368, 0x696E6500, 0x53504120, 0x4D616368, 0x696E6500,
    0x49544120, 0x4D616368, 0x696E6500, 0x837D8356, 0x83938140, 0x81400000, 0x50696C6F, 0x74000000,  /* fzgx-allow: A1 retail data bytes */
    0x47455220, 0x50696C6F, 0x74000000, 0x46524520, 0x50696C6F, 0x74000000, 0x53504120, 0x50696C6F,
    0x74000000, 0x49544120, 0x50696C6F, 0x74000000, 0x83708343, 0x838D8362, 0x83670000, 0x83B22043,
    0x6C656172, 0x2083B420, 0x536F7274, 0x2083A420, 0x25730000, 0x47455220, 0x83B22043, 0x6C656172,
    0x2083B420, 0x536F7274, 0x2083A420, 0x25730000, 0x46524520, 0x83B22043, 0x6C656172, 0x2083B420,
    0x536F7274, 0x2083A420, 0x25730000, 0x53504120, 0x83B22043, 0x6C656172, 0x2083B420, 0x536F7274,
    0x2083A420, 0x25730000, 0x49544120, 0x83B22043, 0x6C656172, 0x2083B420, 0x536F7274, 0x2083A420,
    0x25730000, 0x83B22083, 0x4E838A83, 0x412083B4, 0x20835C81, 0x5B836720, 0x83A42025, 0x73000000,
    (u32)lbl_10_data_FB4__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_103C__fzgx_offset_0, (u32)lbl_10_data_10D0__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_10F8__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1128__fzgx_offset_0, (u32)lbl_10_data_1158__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1180__fzgx_offset_0,
    (u32)lbl_10_data_11B8__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_11CC__fzgx_offset_0, (u32)lbl_10_data_11E8__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_11F8__fzgx_offset_0, (u32)lbl_10_data_1214__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1228__fzgx_offset_0, (u32)lbl_10_data_1244__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1260__fzgx_offset_0,
    (u32)lbl_10_data_1290__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_12A8__fzgx_offset_0, (u32)lbl_10_data_12C4__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1320__fzgx_offset_0, (u32)lbl_10_data_1380__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_13D0__fzgx_offset_0, (u32)lbl_10_data_1418__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1424__fzgx_offset_0,
    (u32)lbl_10_data_143C__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1464__fzgx_offset_0, (u32)lbl_10_data_1490__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_14B0__fzgx_offset_0, (u32)lbl_10_data_14CC__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_14E0__fzgx_offset_0, (u32)lbl_10_data_14FC__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1514__fzgx_offset_0,
    (u32)lbl_10_data_152C__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1538__fzgx_offset_0, (u32)lbl_10_data_1548__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_155C__fzgx_offset_0, (u32)lbl_10_data_1574__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_15C8__fzgx_offset_0, (u32)lbl_10_data_161C__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_16D0__fzgx_offset_0,
    (u32)lbl_10_data_17A0__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1804__fzgx_offset_0, (u32)lbl_10_data_1888__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_18C0__fzgx_offset_0, (u32)lbl_10_data_1908__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1958__fzgx_offset_0, (u32)lbl_10_data_19B8__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_19B8__fzgx_offset_0,
    (u32)lbl_10_data_19C0__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_19E8__fzgx_offset_0, (u32)lbl_10_data_1A0C__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1A18__fzgx_offset_0, (u32)lbl_10_data_1A24__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1A24__fzgx_offset_0, (u32)lbl_10_data_1A2C__fzgx_offset_0, (u32)lbl_10_data_1A58__fzgx_offset_0, (u32)lbl_10_data_1A88__fzgx_offset_0, (u32)lbl_10_data_1AB8__fzgx_offset_0, (u32)lbl_10_data_1AE8__fzgx_offset_0, (u32)lbl_10_data_1B18__fzgx_offset_0,
    (u32)lbl_10_data_1B48__fzgx_offset_0, (u32)lbl_10_data_1B5C__fzgx_offset_0, (u32)lbl_10_data_1B74__fzgx_offset_0, (u32)lbl_10_data_1B8C__fzgx_offset_0, (u32)lbl_10_data_1BA4__fzgx_offset_0, (u32)lbl_10_data_1BBC__fzgx_offset_0, (u32)lbl_10_data_1BD4__fzgx_offset_0, (u32)lbl_10_data_1BEC__fzgx_offset_0,
    (u32)lbl_10_data_1C08__fzgx_offset_0, (u32)lbl_10_data_1C24__fzgx_offset_0, (u32)lbl_10_data_1C40__fzgx_offset_0, (u32)lbl_10_data_1C5C__fzgx_offset_0, (u32)lbl_10_data_1C70__fzgx_offset_0, (u32)lbl_10_data_1C94__fzgx_offset_0, (u32)lbl_10_data_1CBC__fzgx_offset_0, (u32)lbl_10_data_1CE4__fzgx_offset_0,
    (u32)lbl_10_data_1D0C__fzgx_offset_0, (u32)lbl_10_data_1D34__fzgx_offset_0, (u32)lbl_10_data_1D54__fzgx_offset_0, (u32)lbl_10_data_1D5C__fzgx_offset_0, (u32)lbl_10_data_1D68__fzgx_offset_0, (u32)lbl_10_data_1D74__fzgx_offset_0, (u32)lbl_10_data_1D80__fzgx_offset_0, (u32)lbl_10_data_1D8C__fzgx_offset_0,
    (u32)lbl_10_data_1D98__fzgx_offset_0, (u32)lbl_10_data_1DA0__fzgx_offset_0, (u32)lbl_10_data_1DAC__fzgx_offset_0, (u32)lbl_10_data_1DB8__fzgx_offset_0, (u32)lbl_10_data_1DC4__fzgx_offset_0, (u32)lbl_10_data_1DD0__fzgx_offset_0, (u32)lbl_10_data_1DDC__fzgx_offset_0, (u32)lbl_10_data_1DF4__fzgx_offset_0,
    (u32)lbl_10_data_1E10__fzgx_offset_0, (u32)lbl_10_data_1E2C__fzgx_offset_0, (u32)lbl_10_data_1E48__fzgx_offset_0, (u32)lbl_10_data_1E64__fzgx_offset_0, 0x4D555445, 0x20434954, 0x59000000, 0x4145524F,
    0x504F4C49, 0x53000000, 0x4F555445, 0x52205350, 0x41434500, 0x504F5254, 0x20544F57, 0x4E000000,
    0x4C494748, 0x544E494E, 0x47000000, 0x47524545, 0x4E20504C, 0x414E5400, (u32)lbl_10_data_21B0__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_21B0__fzgx_offset_0, (u32)lbl_10_data_21BC__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_21BC__fzgx_offset_0, (u32)lbl_10_data_21C8__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_21C8__fzgx_offset_0,
    (u32)lbl_10_data_21D4__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_21D4__fzgx_offset_0, (u32)lbl_10_data_21E0__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_21E0__fzgx_offset_0, (u32)lbl_10_data_21EC__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_21EC__fzgx_offset_0, 0x4D6F6465, 0x2053656C, 0x65637400, 0x4D6F6465, 0x2053656C, 0x65637420,
    0x47455200, 0x4D6F6465, 0x2053656C, 0x65637420, 0x46524100, 0x4D6F6465, 0x2053656C, 0x65637420,
    0x53504100, 0x4D6F6465, 0x2053656C, 0x65637420, 0x49544100, 0x8382815B, 0x8368835A, 0x838C834E,
    0x83670000, 0x56532042, 0x6174746C, 0x65000000, 0x56532042, 0x6174746C, 0x65204745, 0x52000000,
    0x56532042, 0x6174746C, 0x65204652, 0x41000000, 0x56532042, 0x6174746C, 0x65205350, 0x41000000,
    0x56532042, 0x6174746C, 0x65204954, 0x41000000, 0x5653836F, 0x8367838B, 0x0, 0x4772616E,
    0x64205072, 0x69780000, 0x4772616E, 0x64205072, 0x69782047, 0x45520000, 0x4772616E, 0x64205072,
    0x69782046, 0x52410000, 0x4772616E, 0x64205072, 0x69782053, 0x50410000, 0x4772616E, 0x64205072,
    0x69782049, 0x54410000, 0x834F8389, 0x83938376, 0x838A0000, 0x54696D65, 0x20417474, 0x61636B00,
    0x54696D65, 0x20417474, 0x61636B20, 0x47455200, 0x54696D65, 0x20417474, 0x61636B20, 0x46524100,
    0x54696D65, 0x20417474, 0x61636B20, 0x53504100, 0x54696D65, 0x20417474, 0x61636B20, 0x49544100,
    0x835E8343, 0x83808341, 0x835E8362, 0x834E0000, 0x50726163, 0x74696365, 0x0, 0x50726163,
    0x74696365, 0x20474552, 0x0, 0x50726163, 0x74696365, 0x20465241, 0x0, 0x50726163,
    0x74696365, 0x20535041, 0x0, 0x50726163, 0x74696365, 0x20495441, 0x0, 0x83768389,
    0x834E8365, 0x83428358, 0x0, 0x53746F72, 0x79000000, 0x53746F72, 0x79204745, 0x52000000,
    0x53746F72, 0x79204652, 0x41000000, 0x53746F72, 0x79205350, 0x41000000, 0x53746F72, 0x79204954,
    0x41000000, 0x83588367, 0x815B838A, 0x815B0000, 0x43757374, 0x6F6D697A, 0x65000000, 0x43757374,  /* fzgx-allow: A1 retail data bytes */
    0x6F6D697A, 0x65204745, 0x52000000, 0x43757374, 0x6F6D697A, 0x65204652, 0x41000000, 0x43757374,
    0x6F6D697A, 0x65205350, 0x41000000, 0x43757374, 0x6F6D697A, 0x65204954, 0x41000000, 0x834A8358,
    0x835E837D, 0x83438359, 0x0, 0x4F707469, 0x6F6E7300, 0x4F707469, 0x6F6E7320, 0x47455200,
    0x4F707469, 0x6F6E7320, 0x46524100, 0x4F707469, 0x6F6E7320, 0x53504100, 0x4F707469, 0x6F6E7320,
    0x49544100, 0x83498376, 0x83568387, 0x83930000, 0x5265706C, 0x61790000, 0x5265706C, 0x61792047,
    0x45520000, 0x5265706C, 0x61792046, 0x52410000, 0x5265706C, 0x61792053, 0x50410000, 0x5265706C,
    0x61792049, 0x54410000, 0x838A8376, 0x838C8343, 0x0, 0x50696C6F, 0x74205072, 0x6F66696C,
    0x65730000, 0x50696C6F, 0x74205072, 0x6F66696C, 0x65732047, 0x45520000, 0x50696C6F, 0x74205072,
    0x6F66696C, 0x65732046, 0x52410000, 0x50696C6F, 0x74205072, 0x6F66696C, 0x65732053, 0x50410000,
    0x50696C6F, 0x74205072, 0x6F66696C, 0x65732049, 0x54410000, 0x8376838D, 0x83748342, 0x815B838B,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x52616365, 0x81694143, 0x816A0000, 0x838C815B, 0x83588169, 0x4143816A, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x54696D65, 0x41747461, 0x636B8169, 0x4143816A, 0x0, 0x835E8343, 0x83808341, 0x835E8362,
    0x834E8169, 0x4143816A, 0x0, 0x4F6E6520, 0x436F7572, 0x73650000, 0x31835281, 0x5B835883,
    0x8C815B83, 0x58000000, 0x25642050, 0x6C617965, 0x72730000, 0x25642050, 0x6C617965, 0x72732047,
    0x45520000, 0x25642050, 0x6C617965, 0x72732046, 0x52410000, 0x25642050, 0x6C617965, 0x72732053,
    0x50410000, 0x25642050, 0x6C617965, 0x72732049, 0x54410000, 0x8376838C, 0x83438384, 0x815B2025,  /* fzgx-allow: A1 retail data bytes */
    0x64000000, 0x25642043, 0x61727300, 0x25642043, 0x61727320, 0x47455200, 0x25642043, 0x61727320,
    0x46524100, 0x25642043, 0x61727320, 0x53504100, 0x25642043, 0x61727320, 0x49544100, 0x834A815B,
    0x83478393, 0x8367838A, 0x20256400, 0x4E6F7669, 0x63650000, 0x4E6F7669, 0x63652047, 0x45520000,
    0x4E6F7669, 0x63652046, 0x52410000, 0x4E6F7669, 0x63652053, 0x50410000, 0x4E6F7669, 0x63652049,
    0x54410000, 0x836D815B, 0x83728358, 0x0, 0x5374616E, 0x64617264, 0x0, 0x5374616E,
    0x64617264, 0x20474552, 0x0, 0x5374616E, 0x64617264, 0x20465241, 0x0, 0x5374616E,
    0x64617264, 0x20535041, 0x0, 0x5374616E, 0x64617264, 0x20495441, 0x0, 0x8358835E,
    0x8393835F, 0x815B8368, 0x0, 0x45787065, 0x72740000, 0x45787065, 0x72742047, 0x45520000,  /* fzgx-allow: A1 retail data bytes */
    0x45787065, 0x72742046, 0x52410000, 0x45787065, 0x72742053, 0x50410000, 0x45787065, 0x72742049,
    0x54410000, 0x8347834C, 0x83588370, 0x815B8367, 0x0, 0x4D617374, 0x65720000, 0x4D617374,  /* fzgx-allow: A1 retail data bytes */
    0x65722047, 0x45520000, 0x4D617374, 0x65722046, 0x52410000, 0x4D617374, 0x65722053, 0x50410000,
    0x4D617374, 0x65722049, 0x54410000, 0x837D8358, 0x835E815B, 0x0, 0x47616368, 0x696E6B6F,
    0x0, 0x47616368, 0x696E6B6F, 0x20474552, 0x0, 0x47616368, 0x696E6B6F, 0x20465241,
    0x0, 0x47616368, 0x696E6B6F, 0x20535041, 0x0, 0x47616368, 0x696E6B6F, 0x20495441,
    0x0, 0x834B8360, 0x83938352, 0x0, 0x436F7572, 0x73652053, 0x656C6563, 0x74000000,
    0x436F7572, 0x73652053, 0x656C6563, 0x74204745, 0x52000000, 0x436F7572, 0x73652053, 0x656C6563,
    0x74204652, 0x41000000, 0x436F7572, 0x73652053, 0x656C6563, 0x74205350, 0x41000000, 0x436F7572,
    0x73652053, 0x656C6563, 0x74204954, 0x41000000, 0x8352815B, 0x8358835A, 0x838C834E, 0x83670000,
    0x414C4C20, 0x43757000, 0x414C4C20, 0x43757020, 0x47455200, 0x414C4C20, 0x43757020, 0x46524100,
    0x414C4C20, 0x43757020, 0x53504100, 0x414C4C20, 0x43757020, 0x49544100, 0x82BA82F1, 0x82B982F1,
    0x82BD82AD, 0x834A8362, 0x83760000, 0x52756279, 0x20437570, 0x0, 0x52756279, 0x20437570,
    0x20474552, 0x0, 0x52756279, 0x20437570, 0x20465241, 0x0, 0x52756279, 0x20437570,
    0x20535041, 0x0, 0x52756279, 0x20437570, 0x20495441, 0x0, 0x838B8372, 0x815B834A,  /* fzgx-allow: A1 retail data bytes */
    0x83628376, 0x0, 0x53617070, 0x68697265, 0x20437570, 0x0, 0x53617070, 0x68697265,
    0x20437570, 0x20474552, 0x0, 0x53617070, 0x68697265, 0x20437570, 0x20465241, 0x0,
    0x53617070, 0x68697265, 0x20437570, 0x20535041, 0x0, 0x53617070, 0x68697265, 0x20437570,
    0x20495441, 0x0, 0x83548374, 0x83408343, 0x8341834A, 0x83628376, 0x0, 0x456D6572,
    0x616C6420, 0x43757000, 0x456D6572, 0x616C6420, 0x43757020, 0x47455200, 0x456D6572, 0x616C6420,
    0x43757020, 0x46524100, 0x456D6572, 0x616C6420, 0x43757020, 0x53504100, 0x456D6572, 0x616C6420,
    0x43757020, 0x49544100, 0x83478381, 0x8389838B, 0x8368834A, 0x83628376, 0x0, 0x4469616D,
    0x6F6E6420, 0x43757000, 0x4469616D, 0x6F6E6420, 0x43757020, 0x47455200, 0x4469616D, 0x6F6E6420,
    0x43757020, 0x46524100, 0x4469616D, 0x6F6E6420, 0x43757020, 0x53504100, 0x4469616D, 0x6F6E6420,
    0x43757020, 0x49544100, 0x835F8343, 0x83848382, 0x83938368, 0x834A8362, 0x83760000, 0x41582043,
    0x75700000, 0x41582047, 0x45520000, 0x41582046, 0x52410000, 0x41582053, 0x50410000, 0x41582049,
    0x54410000, 0x4158834A, 0x83628376, 0x0, 0x41632043, 0x75700000, 0x41632043, 0x75702047,
    0x45520000, 0x41632043, 0x75702046, 0x52410000, 0x41632043, 0x75702053, 0x50410000, 0x41632043,
    0x75702049, 0x54410000, 0x8341815B, 0x8350815B, 0x8368834A, 0x83628376, 0x38300000, 0x8341815B,
    0x8350815B, 0x8368834A, 0x83628376, 0x35300000, 0x41630000, 0x41632047, 0x45520000, 0x41632046,
    0x52410000, 0x41632053, 0x50410000, 0x41632049, 0x54410000, 0x8341815B, 0x8350815B, 0x8368834A,
    0x83628376, 0x33300000, 0x57686620, 0x43757000, 0x57686620, 0x43757020, 0x47455200, 0x57686620,
    0x43757020, 0x46524100, 0x57686620, 0x43757020, 0x53504100, 0x57686620, 0x43757020, 0x49544100,
    0x57484683, 0x4A836283, 0x76000000, 0x45332D30, 0x0, 0x45332031, 0x8352815B, 0x8358838C,
    0x815B8358, 0x97700000, 0x45332D31, 0x0, 0x45332056, 0x53977000, 0x4D616368, 0x696E6520,  /* fzgx-allow: A1 retail data bytes */
    0x53656C65, 0x63740000, 0x4D616368, 0x696E6520, 0x53656C65, 0x63742047, 0x45520000, 0x4D616368,
    0x696E6520, 0x53656C65, 0x63742046, 0x52410000, 0x4D616368, 0x696E6520, 0x53656C65, 0x63742053,
    0x50410000, 0x4D616368, 0x696E6520, 0x53656C65, 0x63742049, 0x54410000, 0x837D8356, 0x8393835A,
    0x838C834E, 0x83670000, 0x4D616368, 0x696E6520, 0x436F6E66, 0x69670000, 0x4D616368, 0x696E6520,
    0x436F6E66, 0x69672047, 0x45520000, 0x4D616368, 0x696E6520, 0x436F6E66, 0x69672046, 0x52410000,
    0x4D616368, 0x696E6520, 0x436F6E66, 0x69672053, 0x50410000, 0x4D616368, 0x696E6520, 0x436F6E66,
    0x69672049, 0x54410000, 0x837D8356, 0x83938352, 0x83938374, 0x8342834F, 0x0, (u32)lbl_10_data_2288__fzgx_offset_0,
    (u32)lbl_10_data_2294__fzgx_offset_0, (u32)lbl_10_data_22A4__fzgx_offset_0, (u32)lbl_10_data_22B4__fzgx_offset_0, (u32)lbl_10_data_22C4__fzgx_offset_0, (u32)lbl_10_data_22D4__fzgx_offset_0, (u32)lbl_10_data_22E4__fzgx_offset_0, (u32)lbl_10_data_22F0__fzgx_offset_0, (u32)lbl_10_data_2300__fzgx_offset_0,
    (u32)lbl_10_data_2310__fzgx_offset_0, (u32)lbl_10_data_2320__fzgx_offset_0, (u32)lbl_10_data_2330__fzgx_offset_0, (u32)lbl_10_data_233C__fzgx_offset_0, (u32)lbl_10_data_2348__fzgx_offset_0, (u32)lbl_10_data_2358__fzgx_offset_0, (u32)lbl_10_data_2368__fzgx_offset_0, (u32)lbl_10_data_2378__fzgx_offset_0,
    (u32)lbl_10_data_2388__fzgx_offset_0, (u32)lbl_10_data_2394__fzgx_offset_0, (u32)lbl_10_data_23A0__fzgx_offset_0, (u32)lbl_10_data_23B0__fzgx_offset_0, (u32)lbl_10_data_23C0__fzgx_offset_0, (u32)lbl_10_data_23D0__fzgx_offset_0, (u32)lbl_10_data_23E0__fzgx_offset_0, (u32)lbl_10_data_23F0__fzgx_offset_0,
    (u32)lbl_10_data_23FC__fzgx_offset_0, (u32)lbl_10_data_240C__fzgx_offset_0, (u32)lbl_10_data_241C__fzgx_offset_0, (u32)lbl_10_data_242C__fzgx_offset_0, (u32)lbl_10_data_243C__fzgx_offset_0, (u32)lbl_10_data_244C__fzgx_offset_0, (u32)lbl_10_data_2454__fzgx_offset_0, (u32)lbl_10_data_2460__fzgx_offset_0,
    (u32)lbl_10_data_246C__fzgx_offset_0, (u32)lbl_10_data_2478__fzgx_offset_0, (u32)lbl_10_data_2484__fzgx_offset_0, (u32)lbl_10_data_2490__fzgx_offset_0, (u32)lbl_10_data_249C__fzgx_offset_0, (u32)lbl_10_data_24AC__fzgx_offset_0, (u32)lbl_10_data_24BC__fzgx_offset_0, (u32)lbl_10_data_24CC__fzgx_offset_0,
    (u32)lbl_10_data_24DC__fzgx_offset_0, (u32)lbl_10_data_24EC__fzgx_offset_0, (u32)lbl_10_data_24F4__fzgx_offset_0, (u32)lbl_10_data_2500__fzgx_offset_0, (u32)lbl_10_data_250C__fzgx_offset_0, (u32)lbl_10_data_2518__fzgx_offset_0, (u32)lbl_10_data_2524__fzgx_offset_0, (u32)lbl_10_data_2530__fzgx_offset_0,
    (u32)lbl_10_data_2538__fzgx_offset_0, (u32)lbl_10_data_2544__fzgx_offset_0, (u32)lbl_10_data_2550__fzgx_offset_0, (u32)lbl_10_data_255C__fzgx_offset_0, (u32)lbl_10_data_2568__fzgx_offset_0, (u32)lbl_10_data_2574__fzgx_offset_0, (u32)lbl_10_data_2584__fzgx_offset_0, (u32)lbl_10_data_2598__fzgx_offset_0,
    (u32)lbl_10_data_25AC__fzgx_offset_0, (u32)lbl_10_data_25C0__fzgx_offset_0, (u32)lbl_10_data_25D4__fzgx_offset_0, (u32)lbl_10_data_25E4__fzgx_offset_0, (u32)lbl_10_data_25E4__fzgx_offset_0, (u32)lbl_10_data_25E4__fzgx_offset_0, (u32)lbl_10_data_25E4__fzgx_offset_0, (u32)lbl_10_data_25E4__fzgx_offset_0,
    (u32)lbl_10_data_25F0__fzgx_offset_0, (u32)lbl_10_data_2600__fzgx_offset_0, (u32)lbl_10_data_2600__fzgx_offset_0, (u32)lbl_10_data_2600__fzgx_offset_0, (u32)lbl_10_data_2600__fzgx_offset_0, (u32)lbl_10_data_2600__fzgx_offset_0, (u32)lbl_10_data_2614__fzgx_offset_0, (u32)lbl_10_data_262C__fzgx_offset_0,
    (u32)lbl_10_data_262C__fzgx_offset_0, (u32)lbl_10_data_262C__fzgx_offset_0, (u32)lbl_10_data_262C__fzgx_offset_0, (u32)lbl_10_data_262C__fzgx_offset_0, (u32)lbl_10_data_2638__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_2638__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_2330__fzgx_offset_0, (u32)lbl_10_data_2648__fzgx_offset_0, (u32)lbl_10_data_2654__fzgx_offset_0, (u32)lbl_10_data_2664__fzgx_offset_0, (u32)lbl_10_data_2674__fzgx_offset_0, (u32)lbl_10_data_2684__fzgx_offset_0, (u32)lbl_10_data_2694__fzgx_offset_0, (u32)lbl_10_data_26A4__fzgx_offset_0,
    (u32)lbl_10_data_26AC__fzgx_offset_0, (u32)lbl_10_data_26B8__fzgx_offset_0, (u32)lbl_10_data_26C4__fzgx_offset_0, (u32)lbl_10_data_26D0__fzgx_offset_0, (u32)lbl_10_data_26DC__fzgx_offset_0, (u32)lbl_10_data_26EC__fzgx_offset_0, (u32)lbl_10_data_26F4__fzgx_offset_0, (u32)lbl_10_data_2700__fzgx_offset_0,
    (u32)lbl_10_data_270C__fzgx_offset_0, (u32)lbl_10_data_2718__fzgx_offset_0, (u32)lbl_10_data_2724__fzgx_offset_0, (u32)lbl_10_data_2730__fzgx_offset_0, (u32)lbl_10_data_273C__fzgx_offset_0, (u32)lbl_10_data_274C__fzgx_offset_0, (u32)lbl_10_data_275C__fzgx_offset_0, (u32)lbl_10_data_276C__fzgx_offset_0,
    (u32)lbl_10_data_277C__fzgx_offset_0, (u32)lbl_10_data_278C__fzgx_offset_0, (u32)lbl_10_data_2794__fzgx_offset_0, (u32)lbl_10_data_27A0__fzgx_offset_0, (u32)lbl_10_data_27AC__fzgx_offset_0, (u32)lbl_10_data_27B8__fzgx_offset_0, (u32)lbl_10_data_27C4__fzgx_offset_0, (u32)lbl_10_data_27D4__fzgx_offset_0,
    (u32)lbl_10_data_27DC__fzgx_offset_0, (u32)lbl_10_data_27E8__fzgx_offset_0, (u32)lbl_10_data_27F4__fzgx_offset_0, (u32)lbl_10_data_2800__fzgx_offset_0, (u32)lbl_10_data_280C__fzgx_offset_0, (u32)lbl_10_data_2818__fzgx_offset_0, (u32)lbl_10_data_2824__fzgx_offset_0, (u32)lbl_10_data_2834__fzgx_offset_0,
    (u32)lbl_10_data_2844__fzgx_offset_0, (u32)lbl_10_data_2854__fzgx_offset_0, (u32)lbl_10_data_2864__fzgx_offset_0, (u32)lbl_10_data_2870__fzgx_offset_0, (u32)lbl_10_data_2880__fzgx_offset_0, (u32)lbl_10_data_2894__fzgx_offset_0, (u32)lbl_10_data_28A8__fzgx_offset_0, (u32)lbl_10_data_28BC__fzgx_offset_0,
    (u32)lbl_10_data_28D0__fzgx_offset_0, (u32)lbl_10_data_28E0__fzgx_offset_0, (u32)lbl_10_data_28E8__fzgx_offset_0, (u32)lbl_10_data_28F4__fzgx_offset_0, (u32)lbl_10_data_2900__fzgx_offset_0, (u32)lbl_10_data_290C__fzgx_offset_0, (u32)lbl_10_data_2918__fzgx_offset_0, (u32)lbl_10_data_292C__fzgx_offset_0,
    (u32)lbl_10_data_2938__fzgx_offset_0, (u32)lbl_10_data_2948__fzgx_offset_0, (u32)lbl_10_data_2958__fzgx_offset_0, (u32)lbl_10_data_2968__fzgx_offset_0, (u32)lbl_10_data_2978__fzgx_offset_0, (u32)lbl_10_data_2988__fzgx_offset_0, (u32)lbl_10_data_2998__fzgx_offset_0, (u32)lbl_10_data_29AC__fzgx_offset_0,
    (u32)lbl_10_data_29C0__fzgx_offset_0, (u32)lbl_10_data_29D4__fzgx_offset_0, (u32)lbl_10_data_29E8__fzgx_offset_0, (u32)lbl_10_data_29FC__fzgx_offset_0, (u32)lbl_10_data_2A08__fzgx_offset_0, (u32)lbl_10_data_2A18__fzgx_offset_0, (u32)lbl_10_data_2A28__fzgx_offset_0, (u32)lbl_10_data_2A38__fzgx_offset_0,
    (u32)lbl_10_data_2A48__fzgx_offset_0, (u32)lbl_10_data_2A5C__fzgx_offset_0, (u32)lbl_10_data_2A68__fzgx_offset_0, (u32)lbl_10_data_2A78__fzgx_offset_0, (u32)lbl_10_data_2A88__fzgx_offset_0, (u32)lbl_10_data_2A98__fzgx_offset_0, (u32)lbl_10_data_2AA8__fzgx_offset_0, (u32)lbl_10_data_2ABC__fzgx_offset_0,
    (u32)lbl_10_data_2AC4__fzgx_offset_0, (u32)lbl_10_data_2ACC__fzgx_offset_0, (u32)lbl_10_data_2AD4__fzgx_offset_0, (u32)lbl_10_data_2ADC__fzgx_offset_0, (u32)lbl_10_data_2AE4__fzgx_offset_0, (u32)lbl_10_data_2AF0__fzgx_offset_0, (u32)lbl_10_data_2AF8__fzgx_offset_0, (u32)lbl_10_data_2B04__fzgx_offset_0,
    (u32)lbl_10_data_2B10__fzgx_offset_0, (u32)lbl_10_data_2B1C__fzgx_offset_0, (u32)lbl_10_data_2B28__fzgx_offset_0, (u32)lbl_10_data_2AF0__fzgx_offset_0, (u32)lbl_10_data_2AF8__fzgx_offset_0, (u32)lbl_10_data_2B04__fzgx_offset_0, (u32)lbl_10_data_2B10__fzgx_offset_0, (u32)lbl_10_data_2B1C__fzgx_offset_0,
    (u32)lbl_10_data_2B3C__fzgx_offset_0, (u32)lbl_10_data_2B50__fzgx_offset_0, (u32)lbl_10_data_2B54__fzgx_offset_0, (u32)lbl_10_data_2B5C__fzgx_offset_0, (u32)lbl_10_data_2B64__fzgx_offset_0, (u32)lbl_10_data_2B6C__fzgx_offset_0, (u32)lbl_10_data_2B74__fzgx_offset_0, (u32)lbl_10_data_2B88__fzgx_offset_0,
    (u32)lbl_10_data_2B90__fzgx_offset_0, (u32)lbl_10_data_2B9C__fzgx_offset_0, (u32)lbl_10_data_2BA8__fzgx_offset_0, (u32)lbl_10_data_2BB4__fzgx_offset_0, (u32)lbl_10_data_2BC0__fzgx_offset_0, (u32)lbl_10_data_2BCC__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_2BD4__fzgx_offset_0, (u32)lbl_10_data_2BE8__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0,
    (u32)lbl_10_data_2BF0__fzgx_offset_0, (u32)lbl_10_data_2BF8__fzgx_offset_0, (u32)lbl_10_data_2C08__fzgx_offset_0, (u32)lbl_10_data_2C1C__fzgx_offset_0, (u32)lbl_10_data_2C30__fzgx_offset_0, (u32)lbl_10_data_2C44__fzgx_offset_0, (u32)lbl_10_data_2C58__fzgx_offset_0, (u32)lbl_10_data_2C68__fzgx_offset_0,
    (u32)lbl_10_data_2C78__fzgx_offset_0, (u32)lbl_10_data_2C8C__fzgx_offset_0, (u32)lbl_10_data_2CA0__fzgx_offset_0, (u32)lbl_10_data_2CB4__fzgx_offset_0, (u32)lbl_10_data_2CC8__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_10_data_D00_2354[4] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0xFF00FF, 0xFF0000FF, 0xFFFF, 0xFFFF00FF
};
static u32 fzgx_pool_data_lbl_10_data_3064[2930] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4E6F7720, 0x4C6F6164, 0x696E672E, 0x200A0944, 0x6F206E6F, 0x74207075, 0x6C6C206F, 0x75742074,
    0x6865204D, 0x656D6F72, 0x79204361, 0x72642E20, 0xA094974, 0x2063616E, 0x2064616D, 0x61676520,
    0x74686520, 0x66696C65, 0x2E200A00, 0x4E6F7720, 0x4C6F6164, 0x696E6720, 0x47455200, 0x4E6F7720,
    0x4C6F6164, 0x696E6720, 0x46524100, 0x4E6F7720, 0x4C6F6164, 0x696E6720, 0x53504100, 0x4E6F7720,
    0x4C6F6164, 0x696E6720, 0x49544100, 0x838D815B, 0x83689286, 0x82C582B7, 0x81420A83, 0x81838283,  /* fzgx-allow: A1 retail data bytes */
    0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A982, 0xC882A282, 0xC582AD82, 0xBE82B382, 0xA281420A,
    0x83748340, 0x8343838B, 0x82AA89F3, 0x82EA82E9, 0x82B182C6, 0x82AA82A0, 0x82E882DC, 0x82B78142,
    0xA000000, 0x4661696C, 0x65642074, 0x6F206C6F, 0x61642E20, 0xA09506C, 0x65617365, 0x2072656D,
    0x6F766520, 0x74686520, 0x4D656D6F, 0x72792043, 0x6172642E, 0x200A0000, 0x4C6F6164, 0x20466169,
    0x6C656420, 0x47455200, 0x4C6F6164, 0x20466169, 0x6C656420, 0x46524100, 0x4C6F6164, 0x20466169,
    0x6C656420, 0x53504100, 0x4C6F6164, 0x20466169, 0x6C656420, 0x49544100, 0x838D815B, 0x836882C9,
    0x8EB89473, 0x82B582DC, 0x82B582BD, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094,  /* fzgx-allow: A1 retail data bytes */
    0xB282A282, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x0, 0x54686973, 0x204D656D, 0x6F727920,
    0x43617264, 0x2063616E, 0x206E6F74, 0x20626520, 0x75736564, 0x2E200A09, 0x54686572, 0x65206973,
    0x206E6F20, 0x462D5A45, 0x524F2047, 0x58206761, 0x6D652064, 0x6174612E, 0x200A0950, 0x6C656173,
    0x65207265, 0x6D6F7665, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E200A00, 0x4E6F2046,
    0x696C6520, 0x47455200, 0x4E6F2046, 0x696C6520, 0x46524100, 0x4E6F2046, 0x696C6520, 0x53504100,
    0x4E6F2046, 0x696C6520, 0x49544100, 0x82B182CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CD,
    0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0xA098265, 0x817C8279, 0x82648271, 0x826E2082,  /* fzgx-allow: A1 retail data bytes */
    0x66827782, 0xCC835181, 0x5B838083, 0x66815B83, 0x5E82AA93, 0xFC82C182, 0xC482A282, 0xDC82B982,
    0xF181420A, 0x9838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF094B282, 0xA282C482, 0xAD82BE82,
    0xB382A281, 0x420A0000, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x2063616E, 0x206E6F74,
    0x20626520, 0x75736564, 0x2E200A46, 0x2D5A4552, 0x4F204758, 0x2067616D, 0x65206461, 0x74612069,
    0x7320636F, 0x72727570, 0x7465642E, 0x200A0950, 0x6C656173, 0x65207265, 0x6D6F7665, 0x20746865,
    0x204D656D, 0x6F727920, 0x43617264, 0x2E200A00, 0x46696C65, 0x2042726F, 0x6B656E20, 0x47455200,
    0x46696C65, 0x2042726F, 0x6B656E20, 0x46524100, 0x46696C65, 0x2042726F, 0x6B656E20, 0x53504100,
    0x46696C65, 0x2042726F, 0x6B656E20, 0x49544100, 0x82B182CC, 0x83818382, 0x838A815B, 0x834A815B,
    0x836882CD, 0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0xA098265, 0x817C8279, 0x82648271,  /* fzgx-allow: A1 retail data bytes */
    0x826E2082, 0x66827782, 0xCC835181, 0x5B838083, 0x66815B83, 0x5E82AA89, 0xF382EA82, 0xC482A282,
    0xDC82B781, 0x420A0983, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A282, 0xC482AD82,
    0xBE82B382, 0xA281420A, 0x0, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x2063616E,
    0x206E6F74, 0x20626520, 0x75736564, 0x2E200A09, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264,
    0x206E6565, 0x64732074, 0x6F206265, 0xA09666F, 0x726D6174, 0x74656420, 0x6279204E, 0x494E5445,
    0x4E444F20, 0x47414D45, 0x43554245, 0x2E200A09, 0x506C6561, 0x73652072, 0x656D6F76, 0x65207468,
    0x65204D65, 0x6D6F7279, 0x20436172, 0x642E200A, 0x0, 0x456E636F, 0x64696E67, 0x20474552,
    0x0, 0x456E636F, 0x64696E67, 0x20465241, 0x0, 0x456E636F, 0x64696E67, 0x20535041,
    0x0, 0x456E636F, 0x64696E67, 0x20495441, 0x0, 0x82B182CC, 0x83818382, 0x838A815B,
    0x834A815B, 0x836882CD, 0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0xA09826D, 0x8268826D,
    0x82738264, 0x826D8263, 0x826E8140, 0x82668260, 0x826C8264, 0x82628274, 0x82618264, 0x82C58F89,
    0x8AFA89BB, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A09, 0x83818382, 0x838A815B, 0x834A815B,  /* fzgx-allow: A1 retail data bytes */
    0x836882F0, 0x94B282A2, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA000000, 0x54686973, 0x204D656D,
    0x6F727920, 0x43617264, 0x2063616E, 0x206E6F74, 0x20626520, 0x75736564, 0x2E200A09, 0x54686973,
    0x204D656D, 0x6F727920, 0x43617264, 0x20697320, 0x62726F6B, 0x656E206F, 0x7220756E, 0x666F726D,
    0x61747465, 0x642E2020, 0xA09506C, 0x65617365, 0x2072656D, 0x6F766520, 0x74686520, 0x4D656D6F,
    0x72792043, 0x6172642E, 0x200A0000, 0x494F2045, 0x72726F72, 0x20474552, 0x0, 0x494F2045,
    0x72726F72, 0x20465241, 0x0, 0x494F2045, 0x72726F72, 0x20535041, 0x0, 0x494F2045,
    0x72726F72, 0x20495441, 0x0, 0x82B182CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CD,
    0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0xA098381, 0x8382838A, 0x815B834A, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82AA89F3, 0x82EA82C4, 0x82A282E9, 0x82A98141, 0xA098374, 0x8348815B, 0x837D8362, 0x836782B3,
    0x82EA82C4, 0x82A282DC, 0x82B982F1, 0x81420A09, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0,  /* fzgx-allow: A1 retail data bytes */
    0x94B282A2, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA000000, 0x54686973, 0x204D656D, 0x6F727920,
    0x43617264, 0x2063616E, 0x206E6F74, 0x20626520, 0x75736564, 0x2E200A09, 0x506C6561, 0x73652072,
    0x656D6F76, 0x65207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E200A, 0x0, 0x4F746865,
    0x72204572, 0x726F7220, 0x47455200, 0x4F746865, 0x72204572, 0x726F7220, 0x46524100, 0x4F746865,
    0x72204572, 0x726F7220, 0x53504100, 0x4F746865, 0x72204572, 0x726F7220, 0x49544100, 0x82B182CC,
    0x83818382, 0x838A815B, 0x834A815B, 0x836882CD, 0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142,
    0xA838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF094B282, 0xA282C482, 0xAD82BE82, 0xB382A281,
    0x420A0000, 0x506C6179, 0x696E6720, 0x77697468, 0x6F757420, 0x74686520, 0x4D656D6F, 0x72792043,
    0x6172642E, 0x200A0000, 0x4D656D63, 0x61726420, 0x6E6F2075, 0x73652047, 0x45520000, 0x4D656D63,
    0x61726420, 0x6E6F2075, 0x73652046, 0x52410000, 0x4D656D63, 0x61726420, 0x6E6F2075, 0x73652053,
    0x50410000, 0x4D656D63, 0x61726420, 0x6E6F2075, 0x73652049, 0x54410000, 0x83818382, 0x838A815B,
    0x834A815B, 0x836882F0, 0x8E6782ED, 0x82B882C9, 0x8376838C, 0x834382B5, 0x82DC82B7, 0x81420A00,  /* fzgx-allow: A1 retail data bytes */
    0x57726F6E, 0x67204D65, 0x6D6F7279, 0x20436172, 0x642E2050, 0x6C656173, 0x65207265, 0x6D6F7665,
    0xA092074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642061, 0x6E642069, 0x6E736572, 0x74200A09,
    0x74686520, 0x2F626366, 0x66303030, 0x302F4F72, 0x6967696E, 0x616C204D, 0x656D6F72, 0x79204361,
    0x72642F62, 0x63666666, 0x6666662F, 0x20776869, 0x63682079, 0x6F752073, 0x74617274, 0x65640A09,
    0x20746865, 0x2067616D, 0x652E2053, 0x61766520, 0x77697468, 0x696E2074, 0x68652067, 0x6976656E,
    0x2074696D, 0x652E200A, 0x20000000, 0x6E6F7420, 0x73616D65, 0x20636172, 0x64204745, 0x52000000,
    0x6E6F7420, 0x73616D65, 0x20636172, 0x64204652, 0x41000000, 0x6E6F7420, 0x73616D65, 0x20636172,
    0x64205350, 0x41000000, 0x6E6F7420, 0x73616D65, 0x20636172, 0x64204954, 0x41000000, 0x83818382,
    0x838A815B, 0x834A815B, 0x836882AA, 0x8DB782B5, 0x91D682A6, 0x82E782EA, 0x82C482A2, 0x82DC82B7,
    0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A282, 0xC482AD82, 0xBE82B382,  /* fzgx-allow: A1 retail data bytes */
    0xA281420A, 0x9835181, 0x5B83808A, 0x4A8E6E8E, 0x9E82C98E, 0x67977082, 0xB582BD83, 0x81838283,
    0x8A815B83, 0x4A815B83, 0x6882F08D, 0xB782B582, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x9835E83,
    0x43838083, 0x41834583, 0x6782C982, 0xC882E982, 0xC6835A81, 0x5B837582, 0xC582AB82, 0xDC82B982,
    0xF181420A, 0x0, 0x43616E63, 0x656C6564, 0x200A0000, 0x63616E63, 0x656C6564, 0x20474552,
    0xA000000, 0x63616E63, 0x656C6564, 0x20465241, 0x0, 0x63616E63, 0x656C6564, 0x20535041,
    0x0, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0x835A815B, 0x837582B5, 0x82DC82B9,
    0x82F182C5, 0x82B582BD, 0x81420A00, 0x436F756E, 0x64206E6F, 0x74207265, 0x61642074, 0x68652064,  /* fzgx-allow: A1 retail data bytes */
    0x61746120, 0x66726F6D, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E200A09, 0x20506C65,
    0x61736520, 0x72656D6F, 0x76652074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642E20, 0xA000000,
    0x43616E20, 0x6E6F7420, 0x72656164, 0x20474552, 0x0, 0x43616E20, 0x6E6F7420, 0x72656164,
    0x20465241, 0x0, 0x43616E20, 0x6E6F7420, 0x72656164, 0x20535041, 0x0, 0x43616E20,
    0x6E6F7420, 0x72656164, 0x20495441, 0x0, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC,
    0x8366815B, 0x835E82AA, 0x93C782DF, 0x82DC82B9, 0x82F182C5, 0x82B582BD, 0x81420A83, 0x81838283,  /* fzgx-allow: A1 retail data bytes */
    0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A282, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x0,
    0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x6172642E, 0x20506C65, 0x61736520,
    0x696E7365, 0x72740A09, 0x20746865, 0x202F6263, 0x66663030, 0x30302F6F, 0x72696769, 0x6E616C2F,
    0x62636666, 0x66666666, 0x2F204D65, 0x6D6F7279, 0x20436172, 0x64207768, 0x69636820, 0x73746172,
    0x7465640A, 0x9207468, 0x65206761, 0x6D652E20, 0x53617665, 0x20776974, 0x68696E20, 0x74686520,
    0x67697665, 0x6E207469, 0x6D652E20, 0xA095361, 0x76652077, 0x69746869, 0x6E207468, 0x65206769,
    0x76656E20, 0x74696D65, 0x2E200A00, 0x50756C6C, 0x206F7574, 0x204D656D, 0x63617264, 0x20474552,
    0x0, 0x50756C6C, 0x206F7574, 0x204D656D, 0x63617264, 0x20465241, 0x0, 0x50756C6C,
    0x206F7574, 0x204D656D, 0x63617264, 0x20535041, 0x0, 0x50756C6C, 0x206F7574, 0x204D656D,
    0x63617264, 0x20495441, 0x0, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x94B282A9,
    0x82EA82C4, 0x82A282DC, 0x82B78142, 0xA835181, 0x5B83808A, 0x4A8E6E8E, 0x9E82C98E, 0x67977082,
    0xB582BD83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F00A, 0x98DB782, 0xB582C482, 0xAD82BE82,
    0xB382A281, 0x420A0983, 0x5E834383, 0x80834183, 0x45836782, 0xC982C882, 0xE982C683, 0x5A815B83,  /* fzgx-allow: A1 retail data bytes */
    0x7582C582, 0xAB82DC82, 0xB982F181, 0x420A0000, 0x4E6F7720, 0x73617669, 0x6E672E20, 0xA09446F,
    0x206E6F74, 0x2070756C, 0x6C206F75, 0x74207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E200A,
    0x9497420, 0x63616E20, 0x64616D61, 0x67652074, 0x68652066, 0x696C652E, 0x200A0000, 0x4E6F7720,
    0x73617669, 0x6E672047, 0x45520000, 0x4E6F7720, 0x53617669, 0x6E672046, 0x52410000, 0x4E6F7720,
    0x53617669, 0x6E672053, 0x50410000, 0x4E6F7720, 0x53617669, 0x6E672049, 0x54410000, 0x835A815B,
    0x83759286, 0x82C582B7, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A982,  /* fzgx-allow: A1 retail data bytes */
    0xC882A282, 0xC582AD82, 0xBE82B382, 0xA281420A, 0x83748340, 0x8343838B, 0x82AA89F3, 0x82EA82E9,
    0x82B182C6, 0x82AA82A0, 0x82E882DC, 0x82B78142, 0xA000000, 0x46696E69, 0x73686564, 0x20736176,
    0x696E6720, 0x696E2074, 0x6865204D, 0x656D6F72, 0x79206361, 0x72642E20, 0xA000000, 0x53617665,
    0x206F6B20, 0x47455200, 0x53617665, 0x206F6B20, 0x46524100, 0x53617665, 0x206F6B20, 0x53504100,
    0x53617665, 0x206F6B20, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882D6, 0x82CC835A,
    0x815B8375, 0x82AA8F49, 0x97B982B5, 0x82DC82B5, 0x82BD8142, 0xA000000, 0x4661696C, 0x65642074,  /* fzgx-allow: A1 retail data bytes */
    0x6F207361, 0x76652069, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E200A, 0x9506C65,
    0x61736520, 0x72656D6F, 0x76652074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642E20, 0xA000000,
    0x53617665, 0x20666169, 0x6C656420, 0x47455200, 0x53617665, 0x20666169, 0x6C656420, 0x46524100,
    0x53617665, 0x20666169, 0x6C656420, 0x53504100, 0x53617665, 0x20666169, 0x6C656420, 0x49544100,
    0x83818382, 0x838A815B, 0x834A815B, 0x836882D6, 0x82CC835A, 0x815B8375, 0x82AA90B3, 0x8FED82C9,  /* fzgx-allow: A1 retail data bytes */
    0xA098D73, 0x82C882ED, 0x82EA82DC, 0x82B982F1, 0x82C582B5, 0x82BD8142, 0xA838183, 0x82838A81,
    0x5B834A81, 0x5B836882, 0xF094B282, 0xA282C482, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x54686520,
    0x4D656D6F, 0x72792043, 0x61726420, 0x69732072, 0x65616479, 0x2E200A09, 0x446F206E, 0x6F742074,
    0x6F756368, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x20647572, 0x696E6720, 0x74686520,
    0x706C6179, 0x2E200A09, 0x49742063, 0x616E2064, 0x616D6167, 0x65207468, 0x65206669, 0x6C652E20,
    0xA200000, 0x4D656D63, 0x61726420, 0x72656164, 0x79204745, 0x52000000, 0x4D656D63, 0x61726420,
    0x72656164, 0x79204652, 0x41000000, 0x4D656D63, 0x61726420, 0x72656164, 0x79205350, 0x41000000,
    0x4D656D63, 0x61726420, 0x72656164, 0x79204954, 0x41000000, 0x2F626366, 0x66666630, 0x302F8381,
    0x8382838A, 0x815B834A, 0x815B8368, 0x82CC8F80, 0x94F582AA, 0x82C582AB, 0x82DC82B5, 0x82BD8142,  /* fzgx-allow: A1 retail data bytes */
    0x2F626366, 0x66666666, 0x662F0A09, 0x8376838C, 0x83439286, 0x82CC94B2, 0x82AB8DB7, 0x82B582CD,
    0x8D7382C8, 0x82ED82C8, 0x82A282C5, 0x82AD82BE, 0x82B382A2, 0x81420A09, 0x83748340, 0x8343838B,  /* fzgx-allow: A1 retail data bytes */
    0x82AA89F3, 0x82EA82E9, 0x82B182C6, 0x82AA82A0, 0x82E882DC, 0x82B78142, 0xA000000, 0x4E6F7720,
    0x63686563, 0x6B696E67, 0x2E200A44, 0x6F206E6F, 0x74207075, 0x6C6C206F, 0x75742074, 0x6865204D,
    0x656D6F72, 0x79204361, 0x72642E20, 0xA497420, 0x63616E20, 0x64616D61, 0x67652074, 0x68652066,
    0x696C650A, 0x20000000, 0x4D656D63, 0x61726420, 0x63686563, 0x6B696E67, 0x20474552, 0x0,
    0x4D656D63, 0x61726420, 0x63686563, 0x6B696E67, 0x20465241, 0x0, 0x4D656D63, 0x61726420,
    0x63686563, 0x6B696E67, 0x20535041, 0x0, 0x4D656D63, 0x61726420, 0x63686563, 0x6B696E67,
    0x20495441, 0x0, 0x83608346, 0x8362834E, 0x928682C5, 0x82B78142, 0xA838183, 0x82838A81,
    0x5B834A81, 0x5B836882, 0xF094B282, 0xA982C882, 0xA282C582, 0xAD82BE82, 0xB382A281, 0x420A0000,
    0x506C6561, 0x73652069, 0x6E736572, 0x7420462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152,
    0x44206166, 0x7465720A, 0x9746865, 0x20646174, 0x61206973, 0x206C6F61, 0x64656420, 0x66726F6D,
    0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E200000, 0x44656661, 0x6C757420, 0x47455200,
    0x44656661, 0x756C7420, 0x46524100, 0x44656661, 0x756C7420, 0x53504100, 0x44656661, 0x756C7420,
    0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8366815B, 0x835E838D, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82AA8AAE, 0x97B982B7, 0x82E982DC, 0x82C50A09, 0x20838983, 0x43835A83, 0x93835883, 0x4A815B83,
    0x6882CC91, 0x7D93FC82, 0xF082A891, 0xD282BF82, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x506C6561,
    0x7365206D, 0x616B6520, 0x73757265, 0x20746865, 0x72652069, 0x73206E6F, 0x20666F72, 0x6569676E,
    0x206F626A, 0x65637469, 0x6E207468, 0x6520736C, 0x6F742C09, 0x6265666F, 0x72652079, 0x6F752069,
    0x6E736572, 0x74207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E200A, 0x49742069, 0x73207265,
    0x636F6D6D, 0x656E6465, 0x6420746F, 0x206F6E6C, 0x79207361, 0x76652046, 0x2D5A4552, 0x4F204758,
    0x20646174, 0x6120696E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E20200A, 0x446F206E,
    0x6F742074, 0x6F756368, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x64757269, 0x6E672074,
    0x68652070, 0x6C61792E, 0x20497420, 0x63616E20, 0x64616D61, 0x67652074, 0x6F206669, 0x6C652E20,
    0xA000000, 0x43617574, 0x696F6E20, 0x47455200, 0x43617574, 0x696F6E20, 0x46524100, 0x43617574,
    0x696F6E20, 0x53504100, 0x43617574, 0x696F6E20, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B,
    0x836882F0, 0x8DB782B5, 0x8D9E82DE, 0x914F82C9, 0x8358838D, 0x83628367, 0x82C988D9, 0x8FED82AA,
    0x82C882A2, 0x82A98A6D, 0x944682B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0xA098175, 0x82658279,
    0x82648271, 0x826E8140, 0x82668277, 0x817688C8, 0x8A4F82CC, 0x8366815B, 0x835E82F0, 0x93FC82EA,  /* fzgx-allow: A1 retail data bytes */
    0x82C882A2, 0x82C58E67, 0x977082B7, 0x82E982B1, 0x82C682F0, 0x90848FA7, 0x82B582DC, 0x82B78142,
    0xA098376, 0x838C8343, 0x928682CC, 0x834A815B, 0x836882CC, 0x94B282AB, 0x8DB782B5, 0x82CD8141,
    0x90E291CE, 0x82C982A8, 0x82E282DF, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x4E494E54, 0x454E444F,  /* fzgx-allow: A1 retail data bytes */
    0x2047414D, 0x45435542, 0x45204D65, 0x6D6F7279, 0x20436172, 0x640A0963, 0x616E206E, 0x6F740962,
    0x65207573, 0x65642061, 0x74207468, 0x69732074, 0x696D652E, 0x200A0000, 0x4D656D63, 0x61726420,
    0x4F666620, 0x47455200, 0x4D656D63, 0x61726420, 0x4F666620, 0x46524100, 0x4D656D63, 0x61726420,
    0x4F666620, 0x53504100, 0x4D656D63, 0x61726420, 0x4F666620, 0x49544100, 0x82BD82BE, 0x8DA18141,
    0x826D8268, 0x826D8273, 0x8264826D, 0x8263826E, 0x81408266, 0x8260826C, 0x82648262, 0x82748261,  /* fzgx-allow: A1 retail data bytes */
    0x82640A09, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x8E679770, 0x82B782E9, 0x82B182C6,
    0x82AA82C5, 0x82AB82DC, 0x82B982F1, 0x81420A00, 0x4D656D6F, 0x72792043, 0x61726420, 0x6361206E,  /* fzgx-allow: A1 retail data bytes */
    0x6F742062, 0x65207573, 0x65642061, 0x74207468, 0x69732074, 0x696D652E, 0x200A0000, 0x416C6C20,
    0x43617264, 0x204F6666, 0x20474552, 0x0, 0x416C6C20, 0x43617264, 0x204F6666, 0x20465241,
    0x0, 0x416C6C20, 0x43617264, 0x204F6666, 0x20535041, 0x0, 0x416C6C20, 0x43617264,
    0x204F6666, 0x20495441, 0x0, 0x82BD82BE, 0x8DA18141, 0x834A815B, 0x836882CC, 0x8E679770,
    0x82CD82C5, 0x82AB82DC, 0x82B982F1, 0x81420A00, 0x4572726F, 0x72206F63, 0x63757272, 0x65642069,  /* fzgx-allow: A1 retail data bytes */
    0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420536C, 0x6F740A09, 0x506C6561, 0x73652046,
    0x6F6C6C6F, 0x77207468, 0x6520696E, 0x73747275, 0x6374696F, 0x6E73206F, 0x6E207468, 0x65207363,
    0x7265656E, 0x0, 0x536C6F74, 0x20457272, 0x6F722047, 0x45520000, 0x536C6F74, 0x20457272,
    0x6F722046, 0x52410000, 0x536C6F74, 0x20457272, 0x6F722053, 0x50410000, 0x536C6F74, 0x20457272,
    0x6F722049, 0x54410000, 0x83818382, 0x838A815B, 0x834A815B, 0x83688358, 0x838D8362, 0x836782C9,
    0x83478389, 0x815B82AA, 0x94AD90B6, 0x82B582DC, 0x82B582BD, 0x81420A89, 0xE696CA82, 0xCC8E778E,  /* fzgx-allow: A1 retail data bytes */
    0xA682C98F, 0x5D82C182, 0xC489BA82, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x4D656D6F, 0x72792043,
    0x61642063, 0x616E206E, 0x6F742062, 0x65207573, 0x65642061, 0x74207468, 0x69732074, 0x696D652E,
    0x200A0000, 0x4E6F2052, 0x65636569, 0x76652047, 0x45520000, 0x4E6F2052, 0x65636569, 0x76652046,
    0x52410000, 0x4E6F2052, 0x65636569, 0x76652053, 0x50410000, 0x4E6F2052, 0x65636569, 0x76652049,
    0x54410000, 0x82BD82BE, 0x8DA18141, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8EF39574,
    0x82CD8D73, 0x82C882C1, 0x82C482A2, 0x82DC82B9, 0x82F18142, 0xA838183, 0x82838A81, 0x5B834A81,
    0x5B836882, 0xF08E6797, 0x7082C582, 0xAB82DC82, 0xB982F181, 0x420A0000, 0x496E7365, 0x72742074,
    0x6865204D, 0x656D6F72, 0x79204361, 0x72642077, 0x69746820, 0x462D5A45, 0x524F2047, 0x58206461,
    0x74612E20, 0xA000000, 0x496E7365, 0x7274204D, 0x656D6361, 0x72642047, 0x45520000, 0x496E7365,
    0x7274204D, 0x656D6361, 0x72642046, 0x52410000, 0x496E7365, 0x7274204D, 0x656D6361, 0x72642053,
    0x50410000, 0x496E7365, 0x7274204D, 0x656D6361, 0x72642049, 0x54410000, 0x8265817C, 0x82798264,
    0x8271826E, 0x81408266, 0x827782CC, 0x8366815B, 0x835E82AA, 0x93FC82C1, 0x82BD8381, 0x8382838A,  /* fzgx-allow: A1 retail data bytes */
    0x815B834A, 0x815B8368, 0x82F08DB7, 0x82B582C4, 0x89BA82AD, 0x82BE82B3, 0x82A28142, 0xA000000,  /* fzgx-allow: A1 retail data bytes */
    0x446F206E, 0x6F742069, 0x6E736572, 0x74207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x64207769,
    0x74682061, 0x6E20696D, 0x706F7274, 0x616E7420, 0x64617461, 0x2E200A49, 0x74206361, 0x6E206765,
    0x74206461, 0x6D616765, 0x640A0000, 0x4E6F2075, 0x73652049, 0x6D706F72, 0x74616E74, 0x20636172,
    0x64204745, 0x52000000, 0x4E6F2075, 0x73652049, 0x6D706F72, 0x74616E74, 0x20636172, 0x64204652,
    0x41000000, 0x4E6F2075, 0x73652049, 0x6D706F72, 0x74616E74, 0x20636172, 0x64205350, 0x41000000,
    0x4E6F2075, 0x73652049, 0x6D706F72, 0x74616E74, 0x20636172, 0x64204954, 0x41000000, 0x8366815B,
    0x835E82AA, 0x8EB882ED, 0x82EA82E9, 0x8BB082EA, 0x82AA82A0, 0x82E982CC, 0x82C591E5, 0x90D882C8,
    0x834A815B, 0x836882CD, 0x8E679770, 0x82B582C8, 0x82A282C5, 0x89BA82AD, 0x82BE82B3, 0x82A28142,
    0x0, 0x4E6F7720, 0x63686563, 0x6B696E67, 0x2E2E2E0A, 0x0, 0x4E6F7720, 0x63686563,
    0x6B696E67, 0x20474552, 0x0, 0x4E6F7720, 0x63686563, 0x6B696E67, 0x20465241, 0x0,
    0x4E6F7720, 0x63686563, 0x6B696E67, 0x20535041, 0x0, 0x4E6F7720, 0x63686563, 0x6B696E67,
    0x20495441, 0x0, 0x83608346, 0x8362834E, 0x82B582C4, 0x82A282DC, 0x82B78145, 0x81458145,  /* fzgx-allow: A1 retail data bytes */
    0xA000000, 0x53756363, 0x65656465, 0x6420746F, 0x20726561, 0x642F7772, 0x6974650A, 0x0,
    0x52656164, 0x20577269, 0x7465204F, 0x4B204745, 0x52000000, 0x52656164, 0x20577269, 0x7465204F,
    0x4B204652, 0x41000000, 0x52656164, 0x20577269, 0x7465204F, 0x4B205350, 0x41000000, 0x52656164,
    0x20577269, 0x7465204F, 0x4B204954, 0x41000000, 0x838A815B, 0x8368815E, 0x83898343, 0x836782C5,
    0x82AB82DC, 0x82B582BD, 0xA000000, 0x4661696C, 0x65642074, 0x6F207265, 0x61642F77, 0x72697465,
    0xA000000, 0x52656164, 0x20577269, 0x74652066, 0x616C6965, 0x64204745, 0x52000000, 0x52656164,
    0x20577269, 0x74652066, 0x61696C65, 0x64204652, 0x41000000, 0x52656164, 0x20577269, 0x74652066,
    0x61696C65, 0x64205350, 0x41000000, 0x52656164, 0x20577269, 0x74652066, 0x61696C65, 0x64204954,
    0x41000000, 0x838A815B, 0x8368815E, 0x83898343, 0x836782C9, 0x8EB89473, 0x82B582DC, 0x82B582BD,
    0xA000000, 0x506C6561, 0x73652069, 0x6E736572, 0x74207468, 0x65204D65, 0x6D6F7279, 0x20436172,
    0x640A6265, 0x666F7265, 0x20796F75, 0x20696E73, 0x65727420, 0x74686520, 0x462D5A45, 0x524F204C,
    0x4943454E, 0x53452043, 0x4152442E, 0xA000000, 0x83818382, 0x838A817C, 0x834A815B, 0x836882F0,
    0x82B28E67, 0x977082B7, 0x82E995FB, 0x82CD8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82F090E6,  /* fzgx-allow: A1 retail data bytes */
    0x82C98DB7, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x0, (u32)lbl_10_data_3064__fzgx_offset_0, (u32)lbl_10_data_30B0__fzgx_offset_0, (u32)lbl_10_data_30C0__fzgx_offset_0,
    (u32)lbl_10_data_30D0__fzgx_offset_0, (u32)lbl_10_data_30E0__fzgx_offset_0, (u32)lbl_10_data_30F0__fzgx_offset_0, (u32)lbl_10_data_3148__fzgx_offset_0, (u32)lbl_10_data_317C__fzgx_offset_0, (u32)lbl_10_data_318C__fzgx_offset_0, (u32)lbl_10_data_319C__fzgx_offset_0, (u32)lbl_10_data_31AC__fzgx_offset_0,
    (u32)lbl_10_data_31BC__fzgx_offset_0, (u32)lbl_10_data_31F8__fzgx_offset_0, (u32)lbl_10_data_3260__fzgx_offset_0, (u32)lbl_10_data_326C__fzgx_offset_0, (u32)lbl_10_data_3278__fzgx_offset_0, (u32)lbl_10_data_3284__fzgx_offset_0, (u32)lbl_10_data_3290__fzgx_offset_0, (u32)lbl_10_data_330C__fzgx_offset_0,
    (u32)lbl_10_data_3374__fzgx_offset_0, (u32)lbl_10_data_3384__fzgx_offset_0, (u32)lbl_10_data_3394__fzgx_offset_0, (u32)lbl_10_data_33A4__fzgx_offset_0, (u32)lbl_10_data_33B4__fzgx_offset_0, (u32)lbl_10_data_3430__fzgx_offset_0, (u32)lbl_10_data_34B8__fzgx_offset_0, (u32)lbl_10_data_34C8__fzgx_offset_0,
    (u32)lbl_10_data_34D8__fzgx_offset_0, (u32)lbl_10_data_34E8__fzgx_offset_0, (u32)lbl_10_data_34F8__fzgx_offset_0, (u32)lbl_10_data_357C__fzgx_offset_0, (u32)lbl_10_data_35F0__fzgx_offset_0, (u32)lbl_10_data_3600__fzgx_offset_0, (u32)lbl_10_data_3610__fzgx_offset_0, (u32)lbl_10_data_3620__fzgx_offset_0,
    (u32)lbl_10_data_3630__fzgx_offset_0, (u32)lbl_10_data_36B8__fzgx_offset_0, (u32)lbl_10_data_3700__fzgx_offset_0, (u32)lbl_10_data_3710__fzgx_offset_0, (u32)lbl_10_data_3720__fzgx_offset_0, (u32)lbl_10_data_3730__fzgx_offset_0, (u32)lbl_10_data_3740__fzgx_offset_0, (u32)lbl_10_data_3788__fzgx_offset_0,
    (u32)lbl_10_data_37AC__fzgx_offset_0, (u32)lbl_10_data_37C0__fzgx_offset_0, (u32)lbl_10_data_37D4__fzgx_offset_0, (u32)lbl_10_data_37E8__fzgx_offset_0, (u32)lbl_10_data_37FC__fzgx_offset_0, (u32)lbl_10_data_3824__fzgx_offset_0, (u32)lbl_10_data_38D0__fzgx_offset_0, (u32)lbl_10_data_38E4__fzgx_offset_0,
    (u32)lbl_10_data_38F8__fzgx_offset_0, (u32)lbl_10_data_390C__fzgx_offset_0, (u32)lbl_10_data_3920__fzgx_offset_0, (u32)lbl_10_data_39CC__fzgx_offset_0, (u32)lbl_10_data_39D8__fzgx_offset_0, (u32)lbl_10_data_39E8__fzgx_offset_0, (u32)lbl_10_data_39F8__fzgx_offset_0, (u32)lbl_10_data_390C__fzgx_offset_0,
    (u32)lbl_10_data_3A08__fzgx_offset_0, (u32)lbl_10_data_3A30__fzgx_offset_0, (u32)lbl_10_data_3A84__fzgx_offset_0, (u32)lbl_10_data_3A98__fzgx_offset_0, (u32)lbl_10_data_3AAC__fzgx_offset_0, (u32)lbl_10_data_3AC0__fzgx_offset_0, (u32)lbl_10_data_3AD4__fzgx_offset_0, (u32)lbl_10_data_3B24__fzgx_offset_0,
    (u32)lbl_10_data_3BD0__fzgx_offset_0, (u32)lbl_10_data_3BE8__fzgx_offset_0, (u32)lbl_10_data_3C00__fzgx_offset_0, (u32)lbl_10_data_3C18__fzgx_offset_0, (u32)lbl_10_data_3C30__fzgx_offset_0, (u32)lbl_10_data_3CB4__fzgx_offset_0, (u32)lbl_10_data_3D00__fzgx_offset_0, (u32)lbl_10_data_3D10__fzgx_offset_0,
    (u32)lbl_10_data_3D20__fzgx_offset_0, (u32)lbl_10_data_3D30__fzgx_offset_0, (u32)lbl_10_data_3D40__fzgx_offset_0, (u32)lbl_10_data_3D98__fzgx_offset_0, (u32)lbl_10_data_3DC0__fzgx_offset_0, (u32)lbl_10_data_3DCC__fzgx_offset_0, (u32)lbl_10_data_3DD8__fzgx_offset_0, (u32)lbl_10_data_3DE4__fzgx_offset_0,
    (u32)lbl_10_data_3DF0__fzgx_offset_0, (u32)lbl_10_data_3E1C__fzgx_offset_0, (u32)lbl_10_data_3E64__fzgx_offset_0, (u32)lbl_10_data_3E74__fzgx_offset_0, (u32)lbl_10_data_3E84__fzgx_offset_0, (u32)lbl_10_data_3E94__fzgx_offset_0, (u32)lbl_10_data_3EA4__fzgx_offset_0, (u32)lbl_10_data_3F00__fzgx_offset_0,
    (u32)lbl_10_data_3F68__fzgx_offset_0, (u32)lbl_10_data_3F7C__fzgx_offset_0, (u32)lbl_10_data_3F90__fzgx_offset_0, (u32)lbl_10_data_3FA4__fzgx_offset_0, (u32)lbl_10_data_3FB8__fzgx_offset_0, (u32)lbl_10_data_4040__fzgx_offset_0, (u32)lbl_10_data_408C__fzgx_offset_0, (u32)lbl_10_data_40A4__fzgx_offset_0,
    (u32)lbl_10_data_40BC__fzgx_offset_0, (u32)lbl_10_data_40D4__fzgx_offset_0, (u32)lbl_10_data_40EC__fzgx_offset_0, (u32)lbl_10_data_4124__fzgx_offset_0, (u32)lbl_10_data_4178__fzgx_offset_0, (u32)lbl_10_data_4184__fzgx_offset_0, (u32)lbl_10_data_4190__fzgx_offset_0, (u32)lbl_10_data_419C__fzgx_offset_0,
    (u32)lbl_10_data_41A8__fzgx_offset_0, (u32)lbl_10_data_4200__fzgx_offset_0, (u32)lbl_10_data_42E8__fzgx_offset_0, (u32)lbl_10_data_42F4__fzgx_offset_0, (u32)lbl_10_data_4300__fzgx_offset_0, (u32)lbl_10_data_430C__fzgx_offset_0, (u32)lbl_10_data_4318__fzgx_offset_0, (u32)lbl_10_data_43DC__fzgx_offset_0,
    (u32)lbl_10_data_441C__fzgx_offset_0, (u32)lbl_10_data_442C__fzgx_offset_0, (u32)lbl_10_data_443C__fzgx_offset_0, (u32)lbl_10_data_444C__fzgx_offset_0, (u32)lbl_10_data_445C__fzgx_offset_0, (u32)lbl_10_data_44B4__fzgx_offset_0, (u32)lbl_10_data_44E0__fzgx_offset_0, (u32)lbl_10_data_44F4__fzgx_offset_0,
    (u32)lbl_10_data_4508__fzgx_offset_0, (u32)lbl_10_data_451C__fzgx_offset_0, (u32)lbl_10_data_4530__fzgx_offset_0, (u32)lbl_10_data_4554__fzgx_offset_0, (u32)lbl_10_data_45AC__fzgx_offset_0, (u32)lbl_10_data_45BC__fzgx_offset_0, (u32)lbl_10_data_45CC__fzgx_offset_0, (u32)lbl_10_data_45DC__fzgx_offset_0,
    (u32)lbl_10_data_45EC__fzgx_offset_0, (u32)lbl_10_data_463C__fzgx_offset_0, (u32)lbl_10_data_4668__fzgx_offset_0, (u32)lbl_10_data_4678__fzgx_offset_0, (u32)lbl_10_data_4688__fzgx_offset_0, (u32)lbl_10_data_4698__fzgx_offset_0, (u32)lbl_10_data_46A8__fzgx_offset_0, (u32)lbl_10_data_46FC__fzgx_offset_0,
    (u32)lbl_10_data_472C__fzgx_offset_0, (u32)lbl_10_data_4740__fzgx_offset_0, (u32)lbl_10_data_4754__fzgx_offset_0, (u32)lbl_10_data_4768__fzgx_offset_0, (u32)lbl_10_data_477C__fzgx_offset_0, (u32)lbl_10_data_47C4__fzgx_offset_0, (u32)lbl_10_data_4810__fzgx_offset_0, (u32)lbl_10_data_482C__fzgx_offset_0,
    (u32)lbl_10_data_4848__fzgx_offset_0, (u32)lbl_10_data_4864__fzgx_offset_0, (u32)lbl_10_data_4880__fzgx_offset_0, (u32)lbl_10_data_48C8__fzgx_offset_0, (u32)lbl_10_data_48DC__fzgx_offset_0, (u32)lbl_10_data_48F0__fzgx_offset_0, (u32)lbl_10_data_4904__fzgx_offset_0, (u32)lbl_10_data_4918__fzgx_offset_0,
    (u32)lbl_10_data_492C__fzgx_offset_0, (u32)lbl_10_data_4948__fzgx_offset_0, (u32)lbl_10_data_4964__fzgx_offset_0, (u32)lbl_10_data_4978__fzgx_offset_0, (u32)lbl_10_data_498C__fzgx_offset_0, (u32)lbl_10_data_49A0__fzgx_offset_0, (u32)lbl_10_data_49B4__fzgx_offset_0, (u32)lbl_10_data_49D0__fzgx_offset_0,
    (u32)lbl_10_data_49E8__fzgx_offset_0, (u32)lbl_10_data_4A00__fzgx_offset_0, (u32)lbl_10_data_4A18__fzgx_offset_0, (u32)lbl_10_data_4A30__fzgx_offset_0, (u32)lbl_10_data_4A48__fzgx_offset_0, (u32)lbl_10_data_4A68__fzgx_offset_0, (u32)lbl_10_data_49E8__fzgx_offset_0, (u32)lbl_10_data_4A00__fzgx_offset_0,
    (u32)lbl_10_data_4A18__fzgx_offset_0, (u32)lbl_10_data_4A30__fzgx_offset_0, (u32)lbl_10_data_4AB4__fzgx_offset_0, 0x506C6561, 0x73652073, 0x65742075, 0x7020796F, 0x75722046,
    0x2D5A4552, 0x4F204C49, 0x43454E53, 0x45204341, 0x52442E20, 0x0, 0x504C4541, 0x53455F53,
    0x45545F55, 0x50204745, 0x52000000, 0x504C4541, 0x53455F53, 0x45545F55, 0x50204652, 0x41000000,
    0x504C4541, 0x53455F53, 0x45545F55, 0x50205350, 0x41000000, 0x504C4541, 0x53455F53, 0x45545F55,
    0x50204954, 0x41000000, 0x834A815B, 0x836882CC, 0x90DD92E8, 0x82F08D73, 0x82C182C4, 0x82AD82BE,
    0x82B382A2, 0x0, 0x446F2079, 0x6F752068, 0x61766520, 0x6120462D, 0x5A45524F, 0x204C4943,
    0x454E5345, 0x20434152, 0x443F0000, 0x515F4841, 0x56455F4C, 0x4943454E, 0x53452047, 0x45520000,
    0x515F4841, 0x56455F4C, 0x4943454E, 0x53452046, 0x52410000, 0x515F4841, 0x56455F4C, 0x4943454E,
    0x53452053, 0x50410000, 0x515F4841, 0x56455F4C, 0x4943454E, 0x53452049, 0x54410000, 0x8265817C,
    0x82798264, 0x8271826E, 0x20838983, 0x43835A83, 0x93835883, 0x4A815B83, 0x6882CD82, 0xA88E9D82,
    0xBF82C582, 0xB782A981, 0x48000000, 0x49662079, 0x6F752068, 0x61766520, 0x74686520, 0x462D5A45,
    0x524F204C, 0x4943454E, 0x53452043, 0x4152442E, 0x20000000, 0x48415645, 0x5F4C4943, 0x454E5345,
    0x20474552, 0x0, 0x48415645, 0x5F4C4943, 0x454E5345, 0x20465241, 0x0, 0x48415645,
    0x5F4C4943, 0x454E5345, 0x20535041, 0x0, 0x48415645, 0x5F4C4943, 0x454E5345, 0x20495441,
    0x0, 0x83898343, 0x835A8393, 0x8358834A, 0x815B8368, 0x82F082A8, 0x8E9D82BF, 0x82CC95FB,  /* fzgx-allow: A1 retail data bytes */
    0x0, 0x49662079, 0x6F752064, 0x6F6E2774, 0x20686176, 0x65207468, 0x6520462D, 0x5A45524F,
    0x204C4943, 0x454E5345, 0x20434152, 0x442E2000, 0x444F4E54, 0x5F484156, 0x455F4C49, 0x43454E53,
    0x45204745, 0x52000000, 0x444F4E54, 0x5F484156, 0x455F4C49, 0x43454E53, 0x45204652, 0x41000000,
    0x444F4E54, 0x5F484156, 0x455F4C49, 0x43454E53, 0x45205350, 0x41000000, 0x444F4E54, 0x5F484156,
    0x455F4C49, 0x43454E53, 0x45204954, 0x41000000, 0x83898343, 0x835A8393, 0x8358834A, 0x815B8368,  /* fzgx-allow: A1 retail data bytes */
    0x82F082A8, 0x8E9D82BF, 0x82C582C8, 0x82A295FB, 0x0, 0x4661696C, 0x65642074, 0x6F206C6F,
    0x61642E20, 0xA506C65, 0x61736520, 0x72656D6F, 0x76652074, 0x68652063, 0x6172642E, 0x20000000,
    0x4641494C, 0x45445F4C, 0x4F414420, 0x47455200, 0x4641494C, 0x45445F4C, 0x4F414420, 0x46524100,
    0x4641494C, 0x45445F4C, 0x4F414420, 0x53504100, 0x4641494C, 0x45445F4C, 0x4F414420, 0x49544100,
    0x838D815B, 0x836882C9, 0x8EB89473, 0x82B582DC, 0x82B582BD, 0x81420A83, 0x4A815B83, 0x6882F082,  /* fzgx-allow: A1 retail data bytes */
    0xA88EE682, 0xE882AD82, 0xBE82B382, 0xA2814200, 0x43616E20, 0x6E6F7420, 0x75736520, 0x74686973,
    0x20636172, 0x642E2000, 0x43414E54, 0x5F555345, 0x5F544849, 0x535F4341, 0x52442047, 0x45520000,
    0x43414E54, 0x5F555345, 0x5F544849, 0x535F4341, 0x52442046, 0x52410000, 0x43414E54, 0x5F555345,
    0x5F544849, 0x535F4341, 0x52442053, 0x50410000, 0x43414E54, 0x5F555345, 0x5F544849, 0x535F4341,
    0x52442049, 0x54410000, 0x82B182CC, 0x834A815B, 0x836882CD, 0x8E679770, 0x82C582AB, 0x82DC82B9,
    0x82F18142, 0x0, 0x54686973, 0x20697320, 0x6E6F7420, 0x6120462D, 0x5A45524F, 0x204C4943,
    0x454E5345, 0x20434152, 0x442E200A, 0x506C6561, 0x73652072, 0x65747269, 0x65766520, 0x74686520,
    0x63617264, 0x2E200000, 0x4E4F545F, 0x4C494345, 0x4E53455F, 0x43415244, 0x20474552, 0x0,
    0x4E4F545F, 0x4C494345, 0x4E53455F, 0x43415244, 0x20465241, 0x0, 0x4E4F545F, 0x4C494345,
    0x4E53455F, 0x43415244, 0x20535041, 0x0, 0x4E4F545F, 0x4C494345, 0x4E53455F, 0x43415244,
    0x20495441, 0x0, 0x8265817C, 0x82798264, 0x8271826E, 0x20838983, 0x43835A83, 0x93835883,
    0x4A815B83, 0x6882C582, 0xCD82A082, 0xE882DC82, 0xB982F181, 0x420A834A, 0x815B8368, 0x82F082A8,  /* fzgx-allow: A1 retail data bytes */
    0x8EE682E8, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x54686520, 0x64617461, 0x20697320, 0x62726F6B,  /* fzgx-allow: A1 retail data bytes */
    0x656E2E20, 0xA506C65, 0x61736520, 0x72657472, 0x69657665, 0x20746865, 0x20636172, 0x642E2000,
    0x42524541, 0x4B5F4341, 0x52442047, 0x45520000, 0x42524541, 0x4B5F4341, 0x52442046, 0x52410000,
    0x42524541, 0x4B5F4341, 0x52442053, 0x50410000, 0x42524541, 0x4B5F4341, 0x52442049, 0x54410000,
    0x8366815B, 0x835E82AA, 0x89F382EA, 0x82C482A2, 0x82DC82B7, 0x81420A83, 0x4A815B83, 0x6882F082,  /* fzgx-allow: A1 retail data bytes */
    0xA88EE682, 0xE882AD82, 0xBE82B382, 0xA2814200, 0x54686520, 0x462D5A45, 0x524F204C, 0x4943454E,
    0x53452043, 0x41524420, 0x68617320, 0xA657870, 0x69726564, 0x20616E64, 0x20746865, 0x20646174,
    0x61206973, 0x200A616C, 0x72656164, 0x79207472, 0x616E7366, 0x65727265, 0x642E200A, 0x506C6561,
    0x73652072, 0x65747269, 0x65766520, 0x74686520, 0x63617264, 0x2E200000, 0x414C5245, 0x4144595F,
    0x5452414E, 0x53464552, 0x5F434152, 0x44204745, 0x52000000, 0x414C5245, 0x4144595F, 0x5452414E,
    0x53464552, 0x5F434152, 0x44204652, 0x41000000, 0x414C5245, 0x4144595F, 0x5452414E, 0x53464552,
    0x5F434152, 0x44205350, 0x41000000, 0x414C5245, 0x4144595F, 0x5452414E, 0x53464552, 0x5F434152,
    0x44204954, 0x41000000, 0x8E679770, 0x90A78CC0, 0x82C99242, 0x82B58141, 0x8366815B, 0x835E82CC,
    0x88F882AB, 0x8C7082AC, 0x82E00A8F, 0x4997B982, 0xB582C482, 0xA282DC82, 0xB781420A, 0x834A815B,
    0x836882F0, 0x82A88EE6, 0x82E882AD, 0x82BE82B3, 0x82A28142, 0x0, 0x54686520, 0x462D5A45,
    0x524F204C, 0x4943454E, 0x53452043, 0x41524420, 0x63616E20, 0x6E6F740A, 0x62652075, 0x73656420,
    0x61742074, 0x68697320, 0x74696D65, 0x2E200000, 0x43414E54, 0x5F42455F, 0x55534544, 0x9204745,
    0x52000000, 0x43414E54, 0x5F42455F, 0x55534544, 0x9204652, 0x41000000, 0x43414E54, 0x5F42455F,
    0x55534544, 0x9205350, 0x41000000, 0x43414E54, 0x5F42455F, 0x55534544, 0x9204954, 0x41000000,
    0x82BD82BE, 0x8DA18141, 0x8265817C, 0x82798264, 0x8271826E, 0x20838983, 0x43835A83, 0x93835883,
    0x4A815B83, 0x6882F00A, 0x8E679770, 0x82B782E9, 0x82B182C6, 0x82AA82C5, 0x82AB82DC, 0x82B982F1,
    0x81420000, 0x50726F63, 0x6565642E, 0x20000000, 0x50524F43, 0x45454409, 0x20474552, 0x0,  /* fzgx-allow: A1 retail data bytes */
    0x50524F43, 0x45454409, 0x20465241, 0x0, 0x50524F43, 0x45454409, 0x20535041, 0x0,
    0x50524F43, 0x45454409, 0x20495441, 0x0, 0x90E682C9, 0x906982DE, 0x0, 0x596F7520,
    0x6E656564, 0x20256420, 0x636F696E, 0x28732920, 0x746F2063, 0x72656174, 0x652E2000, 0x4E454544,
    0x5F434F49, 0x4E530920, 0x47455200, 0x4E454544, 0x5F434F49, 0x4E530920, 0x46524100, 0x4E454544,
    0x5F434F49, 0x4E530920, 0x53504100, 0x4E454544, 0x5F434F49, 0x4E530920, 0x49544100, 0x25642043,
    0x4F494E28, 0x5329954B, 0x977682C5, 0x82B78142, 0x0, 0x596F7520, 0x6E656564, 0x20256420,
    0x636F696E, 0x28732920, 0x746F2072, 0x656E6577, 0x2E200000, 0x52656E65, 0x77696E67, 0x20796F75,
    0x7220462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152, 0x442E200A, 0x596F7572, 0x206E6577,
    0x20462D5A, 0x45524F20, 0x4C494345, 0x4E534520, 0x43415244, 0x2077696C, 0x6C206265, 0x20697373,
    0x75656420, 0x61667465, 0x72207468, 0x65206761, 0x6D652070, 0x6C61792E, 0x200A596F, 0x75722065,
    0x782D462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152, 0x44207769, 0x6C6C206E, 0x6F742062,
    0x65207573, 0x61626C65, 0x20616674, 0x65722074, 0x72616E73, 0x6665722E, 0x200A506C, 0x65617365,
    0x20726574, 0x72696576, 0x6520796F, 0x75722046, 0x2D5A4552, 0x4F204C49, 0x43454E53, 0x45204341,
    0x52442E20, 0x0, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x47455200,
    0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x46524100, 0x52454E45, 0x575F4C49,
    0x43454E53, 0x455F4341, 0x52440920, 0x53504100, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341,
    0x52440920, 0x49544100, 0x834A815B, 0x836882CC, 0x88F882AB, 0x8C7082AC, 0x82F08D73, 0x82A282DC,
    0x82B78142, 0xA905682, 0xB582A283, 0x4A815B83, 0x6882CD83, 0x76838C83, 0x438F4997, 0xB98CE382,
    0xC994728F, 0x6F82B382, 0xEA82DC82, 0xB781420A, 0x88F882AB, 0x8C7082AC, 0x82AA8F49, 0x97B982B5,
    0x82BD834A, 0x815B8368, 0x82CD8E67, 0x977082C5, 0x82AB82C8, 0x82AD82C8, 0x82E882DC, 0x82B78142,  /* fzgx-allow: A1 retail data bytes */
    0xA834A81, 0x5B836882, 0xF082A88E, 0xE682E882, 0xAD82BE82, 0xB382A281, 0x42000000, 0x4E6F7420,
    0x72656E65, 0x77696E67, 0x20796F75, 0x7220462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152,
    0x442E200A, 0x506C6561, 0x73652072, 0x65747269, 0x65766520, 0x796F7572, 0x20462D5A, 0x45524F20,
    0x4C494345, 0x4E534520, 0x43415244, 0x2E200000, 0x4E4F545F, 0x52454E45, 0x575F4C49, 0x43454E53,
    0x455F4341, 0x52440920, 0x47455200, 0x4E4F545F, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341,
    0x52440920, 0x46524100, 0x4E4F545F, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920,
    0x53504100, 0x4E4F545F, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x49544100,
    0x8366815B, 0x835E82CC, 0x88F882AB, 0x8C7082AC, 0x82F08D73, 0x82A282DC, 0x82B982F1, 0x81420A83,  /* fzgx-allow: A1 retail data bytes */
    0x4A815B83, 0x6882F082, 0xA88EE682, 0xE882AD82, 0xBE82B382, 0xA2814200, 0x596F7572, 0x20462D5A,
    0x45524F20, 0x4C494345, 0x4E534520, 0x43415244, 0x20686173, 0x20657870, 0x69726564, 0x2E200A59,
    0x6F752063, 0x616E2074, 0x72616E73, 0x66657220, 0x796F7572, 0x20706C61, 0x79206461, 0x74612062,
    0x79207265, 0x6E657769, 0x6E672079, 0x6F757220, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043,
    0x4152442E, 0x20000000, 0x43414E5F, 0x5452414E, 0x53464552, 0x5F434152, 0x44092047, 0x45520000,
    0x43414E5F, 0x5452414E, 0x53464552, 0x5F434152, 0x44092046, 0x52410000, 0x43414E5F, 0x5452414E,
    0x53464552, 0x5F434152, 0x44092053, 0x50410000, 0x43414E5F, 0x5452414E, 0x53464552, 0x5F434152,
    0x44092049, 0x54410000, 0x834A815B, 0x836882CC, 0x83898343, 0x835A8393, 0x835882AA, 0x90D882EA,
    0x82C482A2, 0x82DC82B7, 0x81420A90, 0x5682B582, 0xA2834A81, 0x5B836882, 0xF08DEC90, 0xAC82B782,  /* fzgx-allow: A1 retail data bytes */
    0xEA82CE81, 0x41837683, 0x8C834383, 0x66815B83, 0x5E82F088, 0xF882AB8C, 0x7082AE82, 0xB182C682,
    0xAA82C582, 0xAB82DC82, 0xB7814200, 0x43726561, 0x74652079, 0x6F757220, 0x462D5A45, 0x524F204C,
    0x4943454E, 0x53452043, 0x4152442E, 0x200A596F, 0x7572206E, 0x65772046, 0x2D5A4552, 0x4F204C49,
    0x43454E53, 0x45204341, 0x52442077, 0x696C6C20, 0x62652069, 0x73737565, 0x64206166, 0x74657220,
    0x74686520, 0x67616D65, 0x20706C61, 0x792E2000, 0x43524541, 0x54455F43, 0x41524409, 0x20474552,
    0x0, 0x43524541, 0x54455F43, 0x41524409, 0x20465241, 0x0, 0x43524541, 0x54455F43,
    0x41524409, 0x20535041, 0x0, 0x43524541, 0x54455F43, 0x41524409, 0x20495441, 0x0,
    0x834A815B, 0x836882F0, 0x8DEC90AC, 0x82B582DC, 0x82B78142, 0xA905682, 0xB582A283, 0x4A815B83,
    0x6882CD83, 0x76838C83, 0x438F4997, 0xB98CE382, 0xC994728F, 0x6F82B382, 0xEA82DC82, 0xB7814200,
    0x506C6179, 0x696E6720, 0x77697468, 0x6F757420, 0x74686520, 0x462D5A45, 0x524F204C, 0x4943454E,
    0x53452043, 0x4152442E, 0x20000000, 0x57495448, 0x4F55545F, 0x4C494345, 0x4E43455F, 0x43415244,
    0x9204745, 0x52000000, 0x57495448, 0x4F55545F, 0x4C494345, 0x4E43455F, 0x43415244, 0x9204652,
    0x41000000, 0x57495448, 0x4F55545F, 0x4C494345, 0x4E43455F, 0x43415244, 0x9205350, 0x41000000,
    0x57495448, 0x4F55545F, 0x4C494345, 0x4E43455F, 0x43415244, 0x9204954, 0x41000000, 0x462D5A45,
    0x524F204C, 0x4943454E, 0x53452043, 0x41524482, 0xF08E6782, 0xED82B882, 0xC90A8376, 0x838C8343,
    0x82B582DC, 0x82B78142, 0x0, 0x506C6179, 0x696E6720, 0x77697468, 0x6F757420, 0x74686520,
    0x63617264, 0x732E2000, 0x57495448, 0x4F55545F, 0x43415244, 0x9204745, 0x52000000, 0x57495448,
    0x4F55545F, 0x43415244, 0x9204652, 0x41000000, 0x57495448, 0x4F55545F, 0x43415244, 0x9205350,
    0x41000000, 0x57495448, 0x4F55545F, 0x43415244, 0x9204954, 0x41000000, 0x834A815B, 0x836882F0,
    0x8E6782ED, 0x82B882C9, 0x8376838C, 0x834382B5, 0x82DC82B7, 0x81420000, (u32)lbl_10_data_4DB0__fzgx_offset_0, (u32)lbl_10_data_4DDC__fzgx_offset_0,  /* fzgx-allow: A1 retail data bytes */
    (u32)lbl_10_data_4DF0__fzgx_offset_0, (u32)lbl_10_data_4E04__fzgx_offset_0, (u32)lbl_10_data_4E18__fzgx_offset_0, (u32)lbl_10_data_4E2C__fzgx_offset_0, (u32)lbl_10_data_4E4C__fzgx_offset_0, (u32)lbl_10_data_4E70__fzgx_offset_0, (u32)lbl_10_data_4E84__fzgx_offset_0, (u32)lbl_10_data_4E98__fzgx_offset_0,
    (u32)lbl_10_data_4EAC__fzgx_offset_0, (u32)lbl_10_data_4EC0__fzgx_offset_0, (u32)lbl_10_data_4EF0__fzgx_offset_0, (u32)lbl_10_data_4F18__fzgx_offset_0, (u32)lbl_10_data_4F2C__fzgx_offset_0, (u32)lbl_10_data_4F40__fzgx_offset_0, (u32)lbl_10_data_4F54__fzgx_offset_0, (u32)lbl_10_data_4F68__fzgx_offset_0,
    (u32)lbl_10_data_4F88__fzgx_offset_0, (u32)lbl_10_data_4FB4__fzgx_offset_0, (u32)lbl_10_data_4FCC__fzgx_offset_0, (u32)lbl_10_data_4FE4__fzgx_offset_0, (u32)lbl_10_data_4FFC__fzgx_offset_0, (u32)lbl_10_data_5014__fzgx_offset_0, (u32)lbl_10_data_5038__fzgx_offset_0, (u32)lbl_10_data_5064__fzgx_offset_0,
    (u32)lbl_10_data_5074__fzgx_offset_0, (u32)lbl_10_data_5084__fzgx_offset_0, (u32)lbl_10_data_5094__fzgx_offset_0, (u32)lbl_10_data_50A4__fzgx_offset_0, (u32)lbl_10_data_50D4__fzgx_offset_0, (u32)lbl_10_data_50EC__fzgx_offset_0, (u32)lbl_10_data_5104__fzgx_offset_0, (u32)lbl_10_data_511C__fzgx_offset_0,
    (u32)lbl_10_data_5134__fzgx_offset_0, (u32)lbl_10_data_514C__fzgx_offset_0, (u32)lbl_10_data_516C__fzgx_offset_0, (u32)lbl_10_data_51AC__fzgx_offset_0, (u32)lbl_10_data_51C4__fzgx_offset_0, (u32)lbl_10_data_51DC__fzgx_offset_0, (u32)lbl_10_data_51F4__fzgx_offset_0, (u32)lbl_10_data_520C__fzgx_offset_0,
    (u32)lbl_10_data_5254__fzgx_offset_0, (u32)lbl_10_data_5284__fzgx_offset_0, (u32)lbl_10_data_5294__fzgx_offset_0, (u32)lbl_10_data_52A4__fzgx_offset_0, (u32)lbl_10_data_52B4__fzgx_offset_0, (u32)lbl_10_data_52C4__fzgx_offset_0, (u32)lbl_10_data_52F4__fzgx_offset_0, (u32)lbl_10_data_535C__fzgx_offset_0,
    (u32)lbl_10_data_5378__fzgx_offset_0, (u32)lbl_10_data_5394__fzgx_offset_0, (u32)lbl_10_data_53B0__fzgx_offset_0, (u32)lbl_10_data_53CC__fzgx_offset_0, (u32)lbl_10_data_541C__fzgx_offset_0, (u32)lbl_10_data_5454__fzgx_offset_0, (u32)lbl_10_data_5468__fzgx_offset_0, (u32)lbl_10_data_547C__fzgx_offset_0,
    (u32)lbl_10_data_5490__fzgx_offset_0, (u32)lbl_10_data_54A4__fzgx_offset_0, (u32)lbl_10_data_54E8__fzgx_offset_0, (u32)lbl_10_data_54F4__fzgx_offset_0, (u32)lbl_10_data_5504__fzgx_offset_0, (u32)lbl_10_data_5514__fzgx_offset_0, (u32)lbl_10_data_5524__fzgx_offset_0, (u32)lbl_10_data_5534__fzgx_offset_0,
    (u32)lbl_10_data_5540__fzgx_offset_0, (u32)lbl_10_data_5560__fzgx_offset_0, (u32)lbl_10_data_5570__fzgx_offset_0, (u32)lbl_10_data_5580__fzgx_offset_0, (u32)lbl_10_data_5590__fzgx_offset_0, (u32)lbl_10_data_55A0__fzgx_offset_0, (u32)lbl_10_data_55B8__fzgx_offset_0, (u32)lbl_10_data_5560__fzgx_offset_0,
    (u32)lbl_10_data_5570__fzgx_offset_0, (u32)lbl_10_data_5580__fzgx_offset_0, (u32)lbl_10_data_5590__fzgx_offset_0, (u32)lbl_10_data_55A0__fzgx_offset_0, (u32)lbl_10_data_55D8__fzgx_offset_0, (u32)lbl_10_data_56AC__fzgx_offset_0, (u32)lbl_10_data_56C4__fzgx_offset_0, (u32)lbl_10_data_56DC__fzgx_offset_0,
    (u32)lbl_10_data_56F4__fzgx_offset_0, (u32)lbl_10_data_570C__fzgx_offset_0, (u32)lbl_10_data_57A0__fzgx_offset_0, (u32)lbl_10_data_57F4__fzgx_offset_0, (u32)lbl_10_data_5810__fzgx_offset_0, (u32)lbl_10_data_582C__fzgx_offset_0, (u32)lbl_10_data_5848__fzgx_offset_0, (u32)lbl_10_data_5864__fzgx_offset_0,
    (u32)lbl_10_data_589C__fzgx_offset_0, (u32)lbl_10_data_590C__fzgx_offset_0, (u32)lbl_10_data_5924__fzgx_offset_0, (u32)lbl_10_data_593C__fzgx_offset_0, (u32)lbl_10_data_5954__fzgx_offset_0, (u32)lbl_10_data_596C__fzgx_offset_0, (u32)lbl_10_data_59D0__fzgx_offset_0, (u32)lbl_10_data_5A34__fzgx_offset_0,
    (u32)lbl_10_data_5A48__fzgx_offset_0, (u32)lbl_10_data_5A5C__fzgx_offset_0, (u32)lbl_10_data_5A70__fzgx_offset_0, (u32)lbl_10_data_5A84__fzgx_offset_0, (u32)lbl_10_data_5AC4__fzgx_offset_0, (u32)lbl_10_data_5AF0__fzgx_offset_0, (u32)lbl_10_data_5B0C__fzgx_offset_0, (u32)lbl_10_data_5B28__fzgx_offset_0,
    (u32)lbl_10_data_5B44__fzgx_offset_0, (u32)lbl_10_data_5B60__fzgx_offset_0, (u32)lbl_10_data_5B90__fzgx_offset_0, (u32)lbl_10_data_5BAC__fzgx_offset_0, (u32)lbl_10_data_5BC0__fzgx_offset_0, (u32)lbl_10_data_5BD4__fzgx_offset_0, (u32)lbl_10_data_5BE8__fzgx_offset_0, (u32)lbl_10_data_5BFC__fzgx_offset_0,
    0x91CE90ED, 0x8ED282AA, 0x914991F0, 0x928682C5, 0x82B78142, 0x0, 0x57616974, 0x696E6720,
    0x666F7220, 0x796F7572, 0x206F7070, 0x6F6E656E, 0x74277320, 0x64656369, 0x73696F6E, 0x2E000000,
    (u32)lbl_10_data_5DE4__fzgx_offset_0, (u32)lbl_10_data_5DFC__fzgx_offset_0
};
static u32 fzgx_pool_data_lbl_10_data_5E2C[2] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730A00, 0xA0A0000
};
static u32 fzgx_pool_data_lbl_10_data_5E34[10] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x25730000, 0xA000000, 0x5B25645D, 0xA000000, 0x2532643A, 0x25730A00, 0x82C98C88, 0x92E882B5,
    0x82DC82B5, 0x82BD0000
};
static u32 fzgx_pool_data_lbl_10_data_D00_515C[1] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3F3F3F00
};
static u32 fzgx_pool_data_lbl_10_data_D00_5160[23] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x4D656D43, 0x61726425, 0x640A0000, 0x5B202573, 0x205D0A0A, 0x0, 0x4E6F6E65, 0x0,
    0x4D656D43, 0x61726420, 0x25640000, 0x25252D25, 0x64730000, 0x2D2D2D2D, 0x2D2D0A00, 0x5061645B,
    0x2531645D, 0x3A000000, 0x28253264, 0x29253164, 0x25730A00, 0x4F4B0000, 0x20200000
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_10_data_D00(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_data_lbl_10_data_D00;
    s = *(u8 *)fzgx_pool_data_lbl_10_data_D00_2354;
    s = *(u8 *)fzgx_pool_data_lbl_10_data_3064;
    s = *(u8 *)fzgx_pool_data_lbl_10_data_5E2C;
    s = *(u8 *)fzgx_pool_data_lbl_10_data_5E34;
    s = *(u8 *)fzgx_pool_data_lbl_10_data_D00_515C;
    s = *(u8 *)fzgx_pool_data_lbl_10_data_D00_5160;
}
#pragma section code_type ".text"


extern s16 fn_10_0(s16 *, s16 *, s16, int);
extern s16 lbl_10_bss_18;
extern s16 lbl_10_bss_1A;
extern u32 lbl_801A66B4;
extern SelCell lbl_10_bss_1C[][19];
extern char *fn_1_7F49C(s16, s16, void *);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

void fn_10_FBEC(SelSlot *slots, f32 x, f32 y, f32 sx, f32 sy) {
    s16 k;
    s16 i;
    s16 j;
    s16 index;
    SelCell *cell;
    u32 flags;
    u32 buf[9];
    u32 col;
    u32 last;
    u32 *colors;
    f32 fx;
    f32 fy;
    s16 cx;
    s16 cy;

    
    
    fn_1_4954C((*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_10_rodata_3AC))));
    for (i = 0; i < lbl_10_bss_1A; i++) {
        for (j = 0; j < lbl_10_bss_18; j++) {
            fx = (f32)j * sx;
            fy = (f32)i * sy;
            fn_1_496FC(x + fx, y + fy);
            cell = &lbl_10_bss_1C[i][j];
            flags = cell->flags;
            if (flags & 0x40000000) {
                continue;
            }
            if (flags & 0x80000000) {
                fn_1_4AE0C((const char *)(((u8 *)fzgx_pool_data_lbl_10_data_5E2C)), ((u8 *)fzgx_pool_data_lbl_10_data_D00_515C));
            } else if (flags & 0x20000000) {
                fn_1_4AE0C((const char *)(((u8 *)fzgx_pool_data_lbl_10_data_D00_5160)), cell->id - 0x29);
            } else {
                fn_1_4AE0C((const char *)(((u8 *)fzgx_pool_data_lbl_10_data_5E2C)), fn_1_7F49C(cell->id, (s16)lbl_801A66B4, buf));
            }
        }
    }
    fn_1_4954C((*(f32 *)(((u8 *)fzgx_pool_rodata_lbl_10_rodata_158_44))));
    colors = (u32 *)(((u8 *)fzgx_pool_data_lbl_10_data_D00_2354));
    for (k = 0; k < 4; k++) {
        index = slots[k].index;
        if (index == -1) {
            continue;
        }
        col = colors[k];
        fn_1_49514(&col);
        fn_10_0(&cx, &cy, index, 0);
        fx = (f32)cx * sx;
        fy = (f32)cy * sy;
        fn_1_496FC(x + fx, y + fy);
        cell = &lbl_10_bss_1C[cy][cx];
        flags = cell->flags;
        if (flags & 0x40000000) {
            continue;
        }
        if (flags & 0x80000000) {
            fn_1_4AE0C((const char *)(((u8 *)fzgx_pool_data_lbl_10_data_5E2C)), ((u8 *)fzgx_pool_data_lbl_10_data_D00_515C));
        } else if (flags & 0x20000000) {
            fn_1_4AE0C((const char *)(((u8 *)fzgx_pool_data_lbl_10_data_D00_5160)), cell->id - 0x29);
        } else {
            fn_1_4AE0C((const char *)(((u8 *)fzgx_pool_data_lbl_10_data_5E2C)), fn_1_7F49C(cell->id, (s16)lbl_801A66B4, buf));
        }
    }
    last = (*(u32 *)(((u8 *)fzgx_pool_rodata_lbl_10_rodata_158_268)));
    fn_1_49514(&last);
}
/* fzgx:end fn_10_FBEC */

/* fzgx:begin fn_10_FF08 */
typedef struct SelState {
    u8 pad_0[0x94];
    u32 flags;
} SelState;

extern SelState lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_8CA26;
extern void fn_10_FF54(void);
extern void fn_10_10168(void);

void fn_10_FF08(void) {
    if ((lbl_1_bss_8B3A0.flags & 0x40000000) != 0 &&
        lbl_1_bss_8CA26 == 0) {
        fn_10_FF54();
    } else {
        fn_10_10168();
    }
}
/* fzgx:end fn_10_FF08 */

/* fzgx:begin fn_10_FF54 */
#include "rel/sel/sel.h"

typedef struct SelEntry {
    u8 pad_0[0xe];
    s16 unk_E;
    u8 pad_10[0x10];
} SelEntry;

typedef struct SelState {
    SelEntry entries[4];
    u8 pad_80[0x14];
    u32 flags;
    u32 bits;
    u8 pad_9c[2];
    u8 unk_9E;
    u8 pad_9f[5];
    u8 *items;
} SelState;

extern f32 lbl_10_rodata_158[19];
extern SelState lbl_1_bss_8B3A0;
extern s32 lbl_801A66B4;
extern void *lbl_1_data_418D4[];

extern void fn_10_12C14(void);
extern void fn_10_19040(void);
extern void fn_10_1973C(void);
extern void fn_10_21C44(s32);
extern void fn_10_12024(void);
extern void fn_10_117D0(void);
extern void fn_10_10DB0(void);
extern void fn_10_18A50(void *, u32);
extern void fn_10_21DA8(void);
extern void *fn_10_21C20(s32, s16);
extern void fn_1_13D02C(void);
extern void fn_1_49410(void);
extern void fn_1_133DBC(s32);
extern void fn_1_134AD4(void);
extern void fn_1_13DA0C(void);
extern void fn_1_13DC54(void);
extern void fn_1_13DDB8(void);
extern void fn_1_1380F0(void *);
extern void fn_1_13B328(u32, s32);
extern void fn_1_134EE4(s32, s32, s32, f32);
extern void fn_1_135894(s16, s16, s32, s32, s32, s32, s32, f32, f32);
extern void fn_1_136174(s16, s32, s32, s32, s16, s32, s32, f32, f32);
extern void fn_1_13EDDC(s32, s32, s32, s32, s32);
extern void fn_1_1363F0(s32, s32, s32);
extern void fn_1_1368A0(s32, s32, s32, f32, f32, f32, f32, f32);

static inline f32 *fn_10_FF54_array_read(f32 *array) { return array; }
#pragma opt_common_subs off
void fn_10_FF54(void) {
    f32 *pool = lbl_10_rodata_158;
    s32 idx = lbl_1_bss_8B3A0.unk_9E;
    s16 val = lbl_1_bss_8B3A0.entries[(s16)idx].unk_E;

    fn_1_13D02C();
    fn_1_49410();
    if ((lbl_1_bss_8B3A0.flags & 0x80000000) == 0) {
        lbl_10_bss_55690.unk_0 = lbl_10_bss_55690.unk_4 = fn_10_FF54_array_read(pool)[17];
        fn_10_12C14();
        fn_10_19040();
        fn_10_1973C();
        fn_10_21C44(val);
    }
    fn_10_12024();
    fn_1_133DBC(1);
    fn_1_134AD4();
    fn_1_13DA0C();
    fn_1_13DC54();
    fn_1_13DDB8();
    fn_10_117D0();
    fn_10_10DB0();
    fn_10_18A50(&lbl_1_bss_8B3A0, 0xac);
    if (lbl_1_bss_8B3A0.items[0x19] != 0) {
        fn_10_21DA8();
        fn_1_1380F0(lbl_1_data_418D4[lbl_801A66B4]);
    } else {
        fn_1_1380F0(fn_10_21C20(8, (s16)lbl_801A66B4));
    }
    fn_1_13B328(0x40800000, 0);
    fn_1_134EE4(0, 1, 0, fn_10_FF54_array_read(pool)[19]);
    fn_1_135894(0xd5, 0x16e - (lbl_801A66B4 == 5 ? 0 : (val > 0x28 ? 4 : 7)), 6, val, 0, idx, 0, fn_10_FF54_array_read(pool)[17], fn_10_FF54_array_read(pool)[17]);
    fn_1_136174(0xd5, 0x163, 1, val, (s16)lbl_801A66B4, idx, 0, fn_10_FF54_array_read(pool)[18], fn_10_FF54_array_read(pool)[18]);
    fn_1_13EDDC(0x1f9, 0x181, val, idx, 0);
    fn_1_1363F0(idx, 0, 1);
    fn_1_1368A0(val, idx, 0, fn_10_FF54_array_read(pool)[157], fn_10_FF54_array_read(pool)[158], fn_10_FF54_array_read(pool)[159], fn_10_FF54_array_read(pool)[17], fn_10_FF54_array_read(pool)[17]);
}
#pragma opt_common_subs reset
/* fzgx:end fn_10_FF54 */

/* fzgx:begin fn_10_107D4 */
#include "font.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const u32 fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
static const u32 fzgx_pool_table7[15] = {0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 119.0f;
    s = 141.0f;
    s = 160.0f;
    s = 163.0f;
    s = 43.0f;
    s = 130.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 67.5;
    d = 22.5;
    s = 22.5f;
    s = 0.009999999776482582f;
    s = 0.9166666865348816f;
    s = 2.0f;
    s = 240.0f;
    s = 9.999999747378752e-05f;
    s = 278.0f;
    s = 316.0f;
}
static const u32 fzgx_pool_table11[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 250.0f;
    s = 373.0f;
    s = 354.0f;
    s = 68.0f;
    s = 0.8666666746139526f;
    s = -1.0f;
    s = 140.0f;
    s = 50.0f;
    s = 0.10000000149011612f;
    s = 620.0f;
    s = 24.0f;
    s = 10.0f;
    s = 384.0f;
    s = 640.0f;
    s = 0.5833333134651184f;
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table13[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table14[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep14(void) { const u32 *volatile cp; cp = fzgx_pool_table14; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime15(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 338.0f;
    s = 150.0f;
    s = 15.0f;
    s = 317.0f;
    s = -106.0f;
    s = 318.0f;
    s = 106.0f;
    s = 333.0f;
    s = -87.0f;
    s = 0.09000000357627869f;
    s = -11.0f;
    s = 645.0f;
    s = 721.0f;
    s = 330.0f;
    s = 0.9900000095367432f;
}
#pragma section code_type ".text"
struct fn_10_107D4_Copy88 { u32 a[22]; };
struct fn_10_107D4_lbl_10_rodata_158 {
 u8 pad_0[0x2B0]; u32 unk_2B0; u32 unk_2B4;
};
extern int fn_1_4F734(FontDrawPacket *);
extern s32 fn_1_A5DC4(void);
extern u32 fn_10_139E4(void);
extern FontDrawPacket lbl_1_rodata_26F8;
extern void fn_1_508C4(FontDrawPacket *, f32, f32);
#pragma opt_propagation on
void fn_10_107D4(void) {
    u32 * fzgx_live;
 struct fn_10_107D4_Copy88 loc_8;
 FontDrawPacket *font;
 f32 v10;
 f32 v14;
 f32 v16;
 f32 v15;
 s32 v13;
 s16 v12;
 loc_8 = *(struct fn_10_107D4_Copy88 *)&lbl_1_rodata_26F8;
 fzgx_live = loc_8.a;
 fzgx_live[0] = 18;
 *(f32 *)((u8 *)&loc_8 + 4) = 17.0f;
 *(f32 *)((u8 *)&loc_8 + 8) = 338.0f;
 *(f32 *)((u8 *)&loc_8 + 12) = 150.0f;
 *(f32 *)((u8 *)&loc_8 + 16) *= 75.0f;
 *(f32 *)((u8 *)&loc_8 + 20) *= 15.0f;
 *(f32 *)((u8 *)&loc_8 + 44) = 0.7f;
 fzgx_live = loc_8.a;
 fzgx_live[14] = (*((0) + (fzgx_pool_table13)));
 fn_1_4F734((FontDrawPacket *)&loc_8);
 loc_8 = *(struct fn_10_107D4_Copy88 *)&lbl_1_rodata_26F8;
 fzgx_live = loc_8.a;
 fzgx_live[0] = 0x9D05;
 *(f32 *)((u8 *)&loc_8 + 4) = 0.0f;
 *(f32 *)((u8 *)&loc_8 + 8) = 317.0f;
 *(f32 *)((u8 *)&loc_8 + 12) = 4.0f;
 fn_1_4F734((FontDrawPacket *)&loc_8);
 fn_10_139E4();
 if ((s8)fn_1_A5DC4()) {
 loc_8 = *(struct fn_10_107D4_Copy88 *)&lbl_1_rodata_26F8;
 fzgx_live = loc_8.a;
 fzgx_live[0] = 0x9D11;
 *(f32 *)((u8 *)&loc_8 + 4) = -106.0f;
 *(f32 *)((u8 *)&loc_8 + 8) = 318.0f;
 fn_1_508C4((FontDrawPacket *)&loc_8, 106.0f, 5.0f);
 loc_8 = *(struct fn_10_107D4_Copy88 *)&lbl_1_rodata_26F8;
 fzgx_live = loc_8.a;
 fzgx_live[0] = 0x9D11;
 *(f32 *)((u8 *)&loc_8 + 4) = -106.0f;
 *(f32 *)((u8 *)&loc_8 + 8) = 333.0f;
 fn_1_508C4((FontDrawPacket *)&loc_8, 106.0f, 5.0f);
 loc_8 = *(struct fn_10_107D4_Copy88 *)&lbl_1_rodata_26F8;
 fzgx_live = loc_8.a;
 fzgx_live[0] = 0x9D11;
 *(f32 *)((u8 *)&loc_8 + 4) = 640.0f;
 *(f32 *)((u8 *)&loc_8 + 8) = 318.0f;
 fn_1_508C4((FontDrawPacket *)&loc_8, 106.0f, 5.0f);
 loc_8 = *(struct fn_10_107D4_Copy88 *)&lbl_1_rodata_26F8;
 fzgx_live = loc_8.a;
 fzgx_live[0] = 0x9D11;
 *(f32 *)((u8 *)&loc_8 + 4) = 640.0f;
 *(f32 *)((u8 *)&loc_8 + 8) = 333.0f;
 fn_1_508C4((FontDrawPacket *)&loc_8, 106.0f, 5.0f);
 loc_8 = *(struct fn_10_107D4_Copy88 *)&lbl_1_rodata_26F8;
 fzgx_live = loc_8.a;
 fzgx_live[0] = 0x9D12;
 *(f32 *)((u8 *)&loc_8 + 4) = -87.0f;
 *(f32 *)((u8 *)&loc_8 + 8) = 318.0f;
 *(f32 *)((u8 *)&loc_8 + 12) = 0.09f;
 fn_1_4F734((FontDrawPacket *)&loc_8);
 *(f32 *)((u8 *)&loc_8 + 4) = -11.0f;
 fn_1_4F734((FontDrawPacket *)&loc_8);
 *(f32 *)((u8 *)&loc_8 + 4) = 645.0f;
 fn_1_4F734((FontDrawPacket *)&loc_8);
 *(f32 *)((u8 *)&loc_8 + 4) = 721.0f;
 fn_1_4F734((FontDrawPacket *)&loc_8);
 }
 font = &lbl_1_rodata_26F8;
 v10 = 330.0f; v14 = 0.99f; v15 = 3.0f; v16 = 0.7f;
 v12 = 0; v13 = 11;
 while (v12 < 4) {
 loc_8 = *(struct fn_10_107D4_Copy88 *)font;
 fzgx_live = loc_8.a;
 fzgx_live[0] = 0x9D04;
 *(f32 *)((u8 *)&loc_8 + 4) = (f32)v13;
 *(f32 *)((u8 *)&loc_8 + 8) = v10;
 *(f32 *)((u8 *)&loc_8 + 12) = v14;
 fn_1_4F734((FontDrawPacket *)&loc_8);
 loc_8 = *(struct fn_10_107D4_Copy88 *)font;
 fzgx_live = loc_8.a;
 fzgx_live[0] = 0x9D0F;
 *(f32 *)((u8 *)&loc_8 + 8) = v10;
 *(f32 *)((u8 *)&loc_8 + 4) = (f32)v13;
 *(f32 *)((u8 *)&loc_8 + 12) = v15;
 *(f32 *)((u8 *)&loc_8 + 44) = v16;
 fzgx_live = loc_8.a;
 fzgx_live[14] = (*(volatile const u32 *)fzgx_pool_table14); /* fzgx-allow: S2 retain retail color reload after drawing calls */
 fn_1_4F734((FontDrawPacket *)&loc_8);
 v13 += 150; v12++;
 }
}
#pragma opt_propagation reset
/* fzgx:end fn_10_107D4 */

/* fzgx:begin fn_10_10C24 */
#include "font.h"

typedef struct {
    u8 pad_000[0x174];
    f32 unk_174;
    u8 pad_178[0x180];
    f32 unk_2F8;
    f32 unk_2FC;
} SelFloatPool;

extern FontDrawPacket lbl_1_rodata_26F8;
extern SelFloatPool lbl_10_rodata_158;
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_propagation off
void fn_10_10C24(void) {
    SelFloatPool *pool = &lbl_10_rodata_158;
    FontDrawPacket local = lbl_1_rodata_26F8;

    local.image = 0x9A15;
    local.x = pool->unk_2F8;
    local.y = pool->unk_2FC;
    local.z = pool->unk_174;
    local.flags = 0xA;
    fn_1_4F734(&local);
}
#pragma opt_propagation reset
/* fzgx:end fn_10_10C24 */

/* fzgx:begin fn_10_10CA8 */
typedef struct {
    u32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    u8 pad_10[0x20];
    u32 unk_30;
    u8 pad_34[0x24];
} SelFontPacket;

typedef struct {
    u8 pad_000[0x174];
    f32 unk_174;
    u8 pad_178[0x180];
    f32 unk_2F8;
    f32 unk_2FC;
} SelFloatPool;

extern SelFontPacket lbl_1_rodata_26F8;
extern SelFloatPool lbl_10_rodata_158;
extern int fn_1_4F734(SelFontPacket *);

#pragma opt_propagation off
void fn_10_10CA8(void) {
    SelFloatPool *pool = &lbl_10_rodata_158;
    SelFontPacket local = lbl_1_rodata_26F8;

    local.unk_00 = 0x9A13;
    local.unk_04 = pool->unk_2F8;
    local.unk_08 = pool->unk_2FC;
    local.unk_0C = pool->unk_174;
    local.unk_30 = 0xA;
    fn_1_4F734(&local);
}
#pragma opt_propagation reset
/* fzgx:end fn_10_10CA8 */

/* fzgx:begin fn_10_10D2C */
typedef struct {
    u32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    u8 pad_10[0x20];
    u32 unk_30;
    u8 pad_34[0x24];
} SelFontPacket;

typedef struct {
    u8 pad_000[0x174];
    f32 unk_174;
    u8 pad_178[0x180];
    f32 unk_2F8;
    f32 unk_2FC;
} SelFloatPool;

extern SelFontPacket lbl_1_rodata_26F8;
extern SelFloatPool lbl_10_rodata_158;
extern int fn_1_4F734(SelFontPacket *);

#pragma opt_propagation off
void fn_10_10D2C(void) {
    SelFloatPool *pool = &lbl_10_rodata_158;
    SelFontPacket local = lbl_1_rodata_26F8;

    local.unk_00 = 0x9A11;
    local.unk_04 = pool->unk_2F8;
    local.unk_08 = pool->unk_2FC;
    local.unk_0C = pool->unk_174;
    local.unk_30 = 0xA;
    fn_1_4F734(&local);
}
#pragma opt_propagation reset
/* fzgx:end fn_10_10D2C */

/* fzgx:begin fn_10_10DB0 */
typedef struct {
    u32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    u8 pad_10[0x20];
    u32 unk_30;
    u8 pad_34[0x24];
} SelFontPacket;

typedef struct {
    u8 pad_000[0x174];
    f32 unk_174;
    u8 pad_178[0x180];
    f32 unk_2F8;
    f32 unk_2FC;
} SelFloatPool;

extern SelFontPacket lbl_1_rodata_26F8;
extern SelFloatPool lbl_10_rodata_158;
extern int fn_1_4F734(SelFontPacket *);

#pragma opt_propagation off
void fn_10_10DB0(void) {
    SelFloatPool *pool = &lbl_10_rodata_158;
    SelFontPacket local = lbl_1_rodata_26F8;

    local.unk_00 = 0x9A16;
    local.unk_04 = pool->unk_2F8;
    local.unk_08 = pool->unk_2FC;
    local.unk_0C = pool->unk_174;
    local.unk_30 = 0xA;
    fn_1_4F734(&local);
}
#pragma opt_propagation reset
/* fzgx:end fn_10_10DB0 */

/* fzgx:begin fn_10_12C14 */
#include "font.h"
#include "rel/sel/sel.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const u32 fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
static const u32 fzgx_pool_table7[15] = {0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 119.0f;
    s = 141.0f;
    s = 160.0f;
    s = 163.0f;
    s = 43.0f;
    s = 130.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 67.5;
    d = 22.5;
    s = 22.5f;
    s = 0.009999999776482582f;
    s = 0.9166666865348816f;
    s = 2.0f;
    s = 240.0f;
    s = 9.999999747378752e-05f;
    s = 278.0f;
    s = 316.0f;
}
static const u32 fzgx_pool_table11[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 250.0f;
    s = 373.0f;
    s = 354.0f;
    s = 68.0f;
    s = 0.8666666746139526f;
    s = -1.0f;
    s = 140.0f;
    s = 50.0f;
    s = 0.10000000149011612f;
    s = 620.0f;
    s = 24.0f;
    s = 10.0f;
    s = 384.0f;
    s = 640.0f;
    s = 0.5833333134651184f;
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table13[2] = {0x000000FF, 0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 338.0f;
    s = 150.0f;
    s = 15.0f;
    s = 317.0f;
    s = -106.0f;
    s = 318.0f;
    s = 106.0f;
    s = 333.0f;
    s = -87.0f;
    s = 0.09000000357627869f;
    s = -11.0f;
    s = 645.0f;
    s = 721.0f;
    s = 330.0f;
    s = 0.9900000095367432f;
    s = 167.0f;
    s = 38.0f;
}
static const u32 fzgx_pool_table15[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 8.0f;
    s = 366.0f;
    s = 12.0f;
    s = 14.0f;
    s = 0.7599999904632568f;
}
static const u32 fzgx_pool_table17[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.15999984741211f;
    s = 280.0f;
    s = 5.699999809265137f;
    s = 4.5f;
    s = 0.7070000171661377f;
}
static const u32 fzgx_pool_table19[11] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025203E8, 0x03E803E8, 0x03E80000, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 99.0f;
    s = 47.0f;
    s = 67.0f;
    s = 64.0f;
    s = 219.0f;
    s = 594.0f;
    s = 593.0f;
    s = 48.0f;
    s = 0.38999998569488525f;
    s = 0.4274509847164154f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 46.0f;
    s = 246.0f;
    s = 120.0f;
    s = 470.0f;
    s = 247.0f;
    s = 45.0f;
    s = 34.0f;
    s = 258.0f;
    s = 0.30000001192092896f;
    s = 328.0f;
    s = 266.0f;
    s = 296.0f;
    s = 326.0f;
    s = 268.0f;
    s = 28.0f;
    s = 298.0f;
}
static const u32 fzgx_pool_table23[26] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025103E8, 0x03E803E8, 0x03E80000, 0x00000001, 0x00020003, 0x00030000, 0x00010002, 0x00020003, 0x00000001, 0x00010002, 0x00030000, 0x00000001, 0x00020002, 0x00000001, 0x00010002, 0x00000000, 0x00000001, 0x00010000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    s = 0.05000000074505806f;
    s = 127.0f;
    s = 3.427000045776367f;
    s = 0.0010000000474974513f;
}
#pragma section code_type ".text"

typedef struct SelState {
    u8 pad_0[0x94];
    u32 flags;
} SelState;

typedef struct SelVec {
    f32 x, y, z;
} SelVec;

typedef struct SelSprite {
    u8 pad_0[0x30];
    u16 width;
    u16 height;
    u32 image;
    u8 pad_38[0x28];
    u32 format;
} SelSprite;

extern SelState lbl_1_bss_8B3A0;
extern s16 lbl_1_bss_8CA26;
extern u8 lbl_1_bss_8CA28;
extern SelSprite lbl_10_bss_51788;
extern const FontDrawPacket lbl_1_rodata_26F8;
extern int fn_1_B7F58(u32 *);
extern u32 fn_10_13128(void *);
extern void fn_1_8D1C8(void *, u32 (*)(void *), SelVec *);
extern s32 fn_1_4FC50(FontDrawPacket *, u32, u16, u16, u32);

#pragma fp_contract off
void fn_10_12C14(void) {
    SelState *state = &lbl_1_bss_8B3A0;
    FontDrawPacket packet;
    SelVec pos = {0.0f, -20.0f, 0.0f};
    u32 result[2];
    f32 offset;

    if ((state->flags & 0x40000000) && lbl_1_bss_8CA26 == 0) {
        pos.y -= 2.0f;
        pos.x = fn_1_B7F58(result) == 1 ? 0.0f : 3.0f;
        pos.z -= 1.0f;
    } else {
        pos.y -= 2.0f;
    }
    fn_1_8D1C8(&lbl_10_bss_51788, fn_10_13128, &pos);
    packet = lbl_1_rodata_26F8;
    if ((state->flags & 0x40000000) && lbl_1_bss_8CA26 == 0) {
        offset = fn_1_B7F58(result) == 1 ? 0.0f : 6.0f;
        packet.x = offset + (320.0f * lbl_10_bss_55690.unk_0 + lbl_10_bss_55698.unk_0);
        packet.y = 343.0f * lbl_10_bss_55690.unk_4 + lbl_10_bss_55698.unk_4;
    } else {
        packet.x = 320.0f * lbl_10_bss_55690.unk_0 + lbl_10_bss_55698.unk_0;
        packet.y = 150.0f * lbl_10_bss_55690.unk_4 + lbl_10_bss_55698.unk_4;
    }
    packet.z = 0.4f;
    packet.scale_x = lbl_10_bss_55690.unk_0;
    packet.scale_y = lbl_10_bss_55690.unk_4;
    if (lbl_1_bss_8CA28 != 0) {
        packet.scale_x *= 2.0f;
        packet.scale_y *= 2.0f;
    }
    packet.flags = 10;
    fn_1_4FC50(&packet, lbl_10_bss_51788.image, lbl_10_bss_51788.width, lbl_10_bss_51788.height,
               lbl_10_bss_51788.format);
}
#pragma fp_contract reset
/* fzgx:end fn_10_12C14 */

/* fzgx:begin fn_10_139E4 */
typedef signed short s16;
typedef signed long s32;


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;


typedef float f32;


typedef struct FontDrawPacket FontDrawPacket;
typedef struct FontVertex {
f32 x, y, z;
} FontVertex;
struct FontDrawPacket {
u32 image;
f32 x, y, z;
f32 scale_x, scale_y;
f32 u0, v0, u1, v1;
s16 rotation_z, rotation_y;
f32 alpha;
u32 flags;
f32 depth;
u8 color[4], color_add[4];
u32 format;
u16 width, height;
void* pixels;
FontDrawPacket* secondary;
void (*vertex_callback)(FontDrawPacket* packet, FontVertex* vertices);
u32 unk_54;
};
void fn_1_4A0D8(const char* text);
void fn_1_4AE0C(const char* format, ...);
int fn_1_4F734(FontDrawPacket* packet);
void fn_1_4EDAC(FontDrawPacket* packet, f32 width, f32 height);
void fn_1_51678(FontDrawPacket* packet, u32 image, s16 x, s16 y, s16 width, s16 height);
void fn_1_517EC(FontDrawPacket* packet, s16 x, s16 y, s16 width, s16 height,
s16 texture_width, s16 texture_height);


extern FontDrawPacket lbl_1_rodata_26F8;


extern void fn_10_139E4(void);


extern void fn_1_51564(u16 first, u16 second, u16 third, u16 fourth, u16 fifth, u16 sixth);
extern u32 fn_1_5158C(FontDrawPacket *, u32, s16, s16);


void fn_10_139E4(void) {
FontDrawPacket packet;
s32 i;
u16 id = 0x9D0B;
for (i = 0; i < 4; i++) {
fn_1_51564(0, 0, 24, 20, 2, 2);
packet = lbl_1_rodata_26F8;
*(u32 *)((u8 *)&packet + 0) = id;
*(f32 *)((u8 *)&packet + 4) = (f32)(29 + i * 150);
*(f32 *)((u8 *)&packet + 8) = 348.0f;
*(f32 *)((u8 *)&packet + 12) = 2.0f;
*(u32 *)((u8 *)&packet + 0x30) = 10;
fn_1_5158C(&packet, *(u32 *)((u8 *)&packet + 0), (s16)(i % 2), (s16)(i / 2));
fn_1_4F734(&packet);
}
}
/* fzgx:end fn_10_139E4 */

/* fzgx:begin fn_10_13D64 */
extern struct fn_10_13D64_lbl_10_rodata_158 lbl_10_rodata_158;
extern u32 fn_1_49410(void);
extern u32 fn_1_4955C(f32, f32);
extern u32 fn_1_495B0(u32);
extern u32 fn_1_495C8(u32);
extern u32 fn_1_496FC(f32, f32);
extern u32 fn_1_53C9C(u32, u32, f32, f32, f32, f32, f32);
extern u32 lbl_10_data_5EC0;
extern u32 lbl_10_data_5EE0;
extern u32 lbl_801A66B4;

struct fn_10_13D64_lbl_10_rodata_158 {
    u8 pad_0[0x58];
    f32 unk_58;
    u8 pad_5C[0x134];
    f32 unk_190;
    u8 pad_194[0xC4];
    f32 unk_258;
    u8 pad_25C[0x34];
    f32 unk_290;
    u8 pad_294[0x208];
    f32 unk_49C;
};

u32 fn_10_13D64(u32 arg0, f32 arg1) {
    struct fn_10_13D64_lbl_10_rodata_158 *p_lbl_10_rodata_158;
    f32 v0;
    u32 v1;
    f32 v2;
    u32 t5, t6;
    p_lbl_10_rodata_158 = (struct fn_10_13D64_lbl_10_rodata_158 *)&lbl_10_rodata_158;
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_495C8(9);
    v0 = p_lbl_10_rodata_158->unk_49C;
    fn_1_4955C(v0, v0);
    fn_1_496FC(p_lbl_10_rodata_158->unk_58, p_lbl_10_rodata_158->unk_258);
    v1 = arg0;
    v2 = arg1;
    if ((s32)lbl_801A66B4 == 5) {
    v2 = p_lbl_10_rodata_158->unk_58;
    v1 = 0;
    t5 = fn_1_53C9C(v1, (u32)&lbl_10_data_5EC0, v2, p_lbl_10_rodata_158->unk_258, p_lbl_10_rodata_158->unk_290, p_lbl_10_rodata_158->unk_190, p_lbl_10_rodata_158->unk_49C);
    v1 = t5;
    } else {
    v2 = p_lbl_10_rodata_158->unk_58;
    v1 = 0;
    t6 = fn_1_53C9C(v1, (u32)&lbl_10_data_5EE0, v2, p_lbl_10_rodata_158->unk_258, p_lbl_10_rodata_158->unk_290, p_lbl_10_rodata_158->unk_190, p_lbl_10_rodata_158->unk_49C);
    v1 = t6;
    }
    return v1;
}
/* fzgx:end fn_10_13D64 */

/* fzgx:begin fn_10_13E18 */
extern struct fn_10_13E18_lbl_10_rodata_158 lbl_10_rodata_158;
extern u32 fn_1_49410(void);
extern u32 fn_1_4955C(f32, f32);
extern u32 fn_1_495B0(u32);
extern u32 fn_1_495C8(u32);
extern u32 fn_1_496FC(f32, f32);
extern u32 fn_1_53C9C(u32, u32, f32, f32, f32, f32, f32);
extern u32 lbl_10_data_5F00;
extern u32 lbl_10_data_5F1C;
extern u32 lbl_801A66B4;

struct fn_10_13E18_lbl_10_rodata_158 {
    u8 pad_0[0x58];
    f32 unk_58;
    u8 pad_5C[0x134];
    f32 unk_190;
    u8 pad_194[0xC4];
    f32 unk_258;
    u8 pad_25C[0x34];
    f32 unk_290;
    u8 pad_294[0x208];
    f32 unk_49C;
};

u32 fn_10_13E18(u32 arg0, f32 arg1) {
    struct fn_10_13E18_lbl_10_rodata_158 *p_lbl_10_rodata_158;
    f32 v0;
    u32 v1;
    f32 v2;
    u32 t5, t6;
    p_lbl_10_rodata_158 = (struct fn_10_13E18_lbl_10_rodata_158 *)&lbl_10_rodata_158;
    fn_1_49410();
    fn_1_495B0(0x80000000);
    fn_1_495C8(9);
    v0 = p_lbl_10_rodata_158->unk_49C;
    fn_1_4955C(v0, v0);
    fn_1_496FC(p_lbl_10_rodata_158->unk_58, p_lbl_10_rodata_158->unk_258);
    v1 = arg0;
    v2 = arg1;
    if ((s32)lbl_801A66B4 == 5) {
    v2 = p_lbl_10_rodata_158->unk_58;
    v1 = 0;
    t5 = fn_1_53C9C(v1, (u32)&lbl_10_data_5F00, v2, p_lbl_10_rodata_158->unk_258, p_lbl_10_rodata_158->unk_290, p_lbl_10_rodata_158->unk_190, p_lbl_10_rodata_158->unk_49C);
    v1 = t5;
    } else {
    v2 = p_lbl_10_rodata_158->unk_58;
    v1 = 0;
    t6 = fn_1_53C9C(v1, (u32)&lbl_10_data_5F1C, v2, p_lbl_10_rodata_158->unk_258, p_lbl_10_rodata_158->unk_290, p_lbl_10_rodata_158->unk_190, p_lbl_10_rodata_158->unk_49C);
    v1 = t6;
    }
    return v1;
}
/* fzgx:end fn_10_13E18 */

/* fzgx:begin fn_10_160BC */
extern int fn_1_F89E4(int value);

int fn_10_160BC(s16 value) {
    switch (value) {
    case 0x24:
        return fn_1_F89E4(0);
    case 0x1f:
        return fn_1_F89E4(1);
    case 0x20:
        return fn_1_F89E4(2);
    case 0x21:
        return fn_1_F89E4(3);
    case 0x22:
        return fn_1_F89E4(4);
    case 0x23:
        return fn_1_F89E4(5);
    default:
        return 1;
    }
}
/* fzgx:end fn_10_160BC */

/* fzgx:begin fn_10_1772C */
extern u16 lbl_10_bss_51752[27];
extern u8 lbl_10_data_6008[20];
extern int sprintf(char *, const u8 *, ...);
extern void fn_10_1C2D8(void *);

struct SelEntry {
    int index;
    int value;
    u8 pad[4];
    int even;
    int divisible;
    u8 pad2[0x0e];
    u16 width;
    u16 height;
    u8 pad3[0x16];
    u8 duration;
    u8 pad4[6];
    char text[17];
};

void fn_10_1772C(void) {
    int i;
    struct SelEntry entry;

    if (lbl_10_bss_51752[0] == 0) {
        for (i = 0; i < 4; i++) {
            entry.even = ((i % 2) == 0);
            entry.divisible = ((i % 3) == 0);
            entry.index = i;
            entry.value = i;
            entry.text[16] = 0;
            entry.width = 999;
            entry.height = 999;
            entry.duration = 30;
            sprintf(entry.text, lbl_10_data_6008);
            fn_10_1C2D8(&entry);
        }
    }
}
/* fzgx:end fn_10_1772C */

/* fzgx:begin fn_10_18DD0 */
#include "rel/sel/sel.h"

#pragma section code_type ".fzgxpool"
static const unsigned long fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const unsigned long *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const unsigned long fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const unsigned long *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const unsigned long fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const unsigned long *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
static const unsigned long fzgx_pool_table7[15] = {0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const unsigned long *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 119.0f;
    s = 141.0f;
    s = 160.0f;
    s = 163.0f;
    s = 43.0f;
    s = 130.0f;
}
static const unsigned long fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const unsigned long *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 67.5;
    d = 22.5;
    s = 22.5f;
    s = 0.009999999776482582f;
    s = 0.9166666865348816f;
    s = 2.0f;
    s = 240.0f;
    s = 9.999999747378752e-05f;
    s = 278.0f;
    s = 316.0f;
}
static const unsigned long fzgx_pool_table11[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const unsigned long *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 250.0f;
    s = 373.0f;
    s = 354.0f;
    s = 68.0f;
    s = 0.8666666746139526f;
    s = -1.0f;
    s = 140.0f;
    s = 50.0f;
    s = 0.10000000149011612f;
    s = 620.0f;
    s = 24.0f;
    s = 10.0f;
    s = 384.0f;
    s = 640.0f;
    s = 0.5833333134651184f;
    s = 0.6000000238418579f;
}
static const unsigned long fzgx_pool_table13[2] = {0x000000FF, 0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const unsigned long *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 338.0f;
    s = 150.0f;
    s = 15.0f;
    s = 317.0f;
    s = -106.0f;
    s = 318.0f;
    s = 106.0f;
    s = 333.0f;
    s = -87.0f;
    s = 0.09000000357627869f;
    s = -11.0f;
    s = 645.0f;
    s = 721.0f;
    s = 330.0f;
    s = 0.9900000095367432f;
    s = 167.0f;
    s = 38.0f;
}
static const unsigned long fzgx_pool_table15[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const unsigned long *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 8.0f;
    s = 366.0f;
    s = 12.0f;
    s = 14.0f;
    s = 0.7599999904632568f;
}
static const unsigned long fzgx_pool_table17[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const unsigned long *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.15999984741211f;
    s = 280.0f;
    s = 5.699999809265137f;
    s = 4.5f;
    s = 0.7070000171661377f;
}
static const unsigned long fzgx_pool_table19[11] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025203E8, 0x03E803E8, 0x03E80000, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const unsigned long *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 99.0f;
    s = 47.0f;
    s = 67.0f;
    s = 64.0f;
    s = 219.0f;
    s = 594.0f;
    s = 593.0f;
    s = 48.0f;
    s = 0.38999998569488525f;
    s = 0.4274509847164154f;
}
static const unsigned long fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const unsigned long *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 46.0f;
    s = 246.0f;
    s = 120.0f;
    s = 470.0f;
    s = 247.0f;
    s = 45.0f;
    s = 34.0f;
    s = 258.0f;
    s = 0.30000001192092896f;
    s = 328.0f;
    s = 266.0f;
    s = 296.0f;
    s = 326.0f;
    s = 268.0f;
    s = 28.0f;
    s = 298.0f;
}
static const unsigned long fzgx_pool_table23[26] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025103E8, 0x03E803E8, 0x03E80000, 0x00000001, 0x00020003, 0x00030000, 0x00010002, 0x00020003, 0x00000001, 0x00010002, 0x00030000, 0x00000001, 0x00020002, 0x00000001, 0x00010002, 0x00000000, 0x00000001, 0x00010000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const unsigned long *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    s = 0.05000000074505806f;
    s = 127.0f;
    s = 3.427000045776367f;
    s = 0.0010000000474974513f;
}
static const unsigned long fzgx_pool_table25[3] = {0x00000000, 0xC1A00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const unsigned long *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 343.0f;
    s = 32767.0f;
    s = 2.1764705181121826f;
    s = 1.317647099494934f;
    s = 1.541176438331604f;
    s = 2.4000000953674316f;
    s = 2.4941177368164062f;
    s = 0.29411765933036804f;
    s = 315.0f;
    s = 1.2999999523162842f;
    s = 348.0f;
}
static const unsigned long fzgx_pool_table27[2] = {0x00000000, 0xFF000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const unsigned long *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 337.0f;
    s = 0.6600000262260437f;
    s = 0.46000000834465027f;
    s = 63.0f;
    s = 0.800000011920929f;
    s = 0.47999998927116394f;
    s = 1.25f;
    s = 44.0f;
}
static const unsigned long fzgx_pool_table29[39] = {0x358637BD, 0x00010000, 0x0000A117, 0x0000A118, 0x00000000, 0x00000000, 0x0000A125, 0x0000A126, 0x00010000, 0x00020000, 0x0000A123, 0x0000A124, 0x00020000, 0x00030000, 0x0000A11B, 0x0000A11C, 0x00040000, 0x00040000, 0x0000A121, 0x0000A122, 0x00030000, 0x00070000, 0x0000A11F, 0x0000A120, 0x00070000, 0x00050000, 0x0000A115, 0x0000A116, 0x00050000, 0x00060000, 0x0000A119, 0x0000A11A, 0x00060000, 0x00080000, 0x0000A11D, 0x0000A11E, 0x00040000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const unsigned long *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 255.0f;
    s = 95.0f;
    s = 180.0f;
    s = 92.0f;
    s = 9.999999046325684f;
    s = 80.0999984741211f;
    s = 83.0f;
    s = 85.0f;
    s = 0.6470588445663452f;
    s = 172.0f;
    s = 84.0f;
}
static const unsigned long fzgx_pool_table31[55] = {0xFF00FF00, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x0000A102, 0x0000A103, 0x0000A104, 0x0000A105, 0x0000A106, 0x00000000, 0x00000000, 0x00000140, 0x00000000, 0x00000000, 0x00A001E0, 0x00000000, 0x00000082, 0x014001FE, 0x00000000, 0x006200F6, 0x018A021E, 0x021E0050, 0x00C80140, 0x01B80230, 0x00000000, 0x000000B0, 0x008E0074, 0x00000000, 0x0000003D, 0x002C001F, 0xFF83F200, 0x00CAFF00, 0x00F0AE00, 0xF0ECAA00, 0xD4189300, 0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0xA0A0A000, 0x00000000, 0xFFFFFFDF, 0xFFFFFFF5, 0x0000000B, 0x00000021};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const unsigned long *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 349.0f;
    s = 1.3333333730697632f;
    s = 128.0f;
    s = 30.0f;
    s = 243.0f;
    s = 32.0f;
    s = 175.0f;
}
static const unsigned long fzgx_pool_table33[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const unsigned long *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime34(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.75;
    d = 0.25;
}
static const unsigned long fzgx_pool_table35[25] = {0xC8C8C800, 0x00000000, 0x00FF00FF, 0x00FF00FF, 0xFF960300, 0x00FF00FF, 0xFFED0000, 0x002C0014, 0x00140014, 0x00140014, 0x002C0000, 0x00600052, 0x00520052, 0x00520060, 0x00000008, 0x00000094, 0x00000008, 0x0000009A, 0x00000008, 0x00000094, 0x00000008, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFF00FF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep35(void) { const unsigned long *volatile cp; cp = fzgx_pool_table35; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime36(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 74.0f;
    s = 304.0f;
    s = 208.0f;
    s = 86.0f;
    s = 112.0f;
    s = 256.0f;
    s = 139.0f;
    s = 151.0f;
    s = 0.7200000286102295f;
    s = 220.0f;
    s = 231.0f;
    s = 102.0f;
    s = 329.0f;
    s = 70.0f;
    s = 79.0f;
    s = 345.0f;
    s = 0.125f;
    s = 377.0f;
    s = 389.0f;
}
static const unsigned long fzgx_pool_table37[35] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF00FF00, 0x000B000C, 0x000D000E, 0xFFFF000F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep37(void) { const unsigned long *volatile cp; cp = fzgx_pool_table37; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime38(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 350.0f;
    s = 252.0f;
    s = 244.0f;
    s = 52.0f;
    s = 62.0f;
    s = 0.47058823704719543f;
    s = 0.6196078658103943f;
}
static const unsigned long fzgx_pool_table39[2] = {0x00FF00FF, 0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep39(void) { const unsigned long *volatile cp; cp = fzgx_pool_table39; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime40(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.875f;
    s = 0.1666666716337204f;
    s = 0.1428571492433548f;
    s = 0.10000000894069672f;
    s = 0.08571429550647736f;
    s = 0.8333333730697632f;
    s = 0.8571429252624512f;
}
static const unsigned long fzgx_pool_table41[1] = {0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep41(void) { const unsigned long *volatile cp; cp = fzgx_pool_table41; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime42(void) {
    volatile float s; volatile double d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.1411764770746231f;
    s = 109.07058715820312f;
    s = -15.0f;
    s = 19.0f;
    s = -4.5f;
}
#pragma section code_type ".text"

typedef struct Sig_fn_1_8CED0_Fn8CED0Window Sig_fn_1_8CED0_Fn8CED0Window;

typedef struct SelEntry {
    s16 unk_0;
    u8 pad_2[0x1E];
} SelEntry;

typedef struct SelGlobal {
    u8 pad_0[0xE];
    SelEntry entries[4];
    u8 pad_8E[0x10];
    u8 unk_9E;
    u8 pad_9F[0x5];
    u8 *unk_A4;
} SelGlobal;

typedef struct SelDesc {
    u32 unk_0;
    f32 x;
    f32 y;
    f32 unk_C;
    f32 sx;
    f32 sy;
    u8 pad_18[0x18];
    u32 flags;
    u8 pad_34[0x1C];
    void (*callback)(void);
    u8 pad_54[0x4];
} SelDesc;

typedef struct SelParam {
    s16 id;
    u8 pad_2[0xA];
    u32 unk_C;
    void *unk_10;
    s16 unk_14;
    u8 pad_16[0x6];
    void *unk_1C;
    u8 pad_20[0x18];
    f32 f38[6];
    u32 bits[6];
} SelParam;


typedef struct SelSlot {
    u32 unk_0;
    u32 unk_4;
} SelSlot;

typedef struct SelRow {
    SelSlot slots[19];
} SelRow;

extern s16 fn_10_0(s16 *, s16 *, int, int);
extern s8 fn_1_A5DC4(void);
extern u16 fn_1_A5D9C(void);
extern u16 fn_1_A5D88(void);
extern void fn_1_8CED0(Sig_fn_1_8CED0_Fn8CED0Window *, u16, u16);
extern u32 fn_1_8D3F8(void *, SelDesc *, void (*)(void), SelParam *);
extern void fn_10_19290(void);
extern void fn_1_131C08(void);

extern s16 lbl_1_bss_962;
extern SelGlobal lbl_1_bss_8B3A0;
extern u8 lbl_1_bss_8CA28;
extern const SelDesc lbl_1_rodata_26F8;

void fn_10_18DD0(void) {
    SelDesc desc;
    SelParam param;
    s16 col;
    s16 row;
    u16 h;
    s16 kind;

    param.f38[0] = 0.0f;
    param.f38[1] = 0.0f;
    param.f38[2] = -15.0f;
    param.f38[3] = 0.0f;
    param.f38[4] = 0.0f;
    param.f38[5] = 0.0f;
    param.unk_C = lbl_10_bss_49380;
    param.unk_10 = lbl_10_bss_493A0;
    param.unk_14 = lbl_10_data_454;
    param.unk_1C = lbl_1_bss_8B3A0.unk_A4 + (s16)(lbl_1_bss_962 - 14) * 0x94 + 0x24;
    param.id = lbl_1_bss_8B3A0.unk_9E;

    kind = lbl_1_bss_8B3A0.entries[param.id].unk_0;
    if (kind >= 41 && kind <= 48 && lbl_1_bss_962 == 20) {
        return;
    }

    desc = lbl_1_rodata_26F8;
    desc.x = (s32)(fn_1_A5DC4() ? 72 : 88);
    kind = lbl_1_bss_8B3A0.entries[param.id].unk_0;
    desc.y = 366.0f;
    if (kind == 32) {
        desc.y += 19.0f;
    }
    if (kind == 39) {
        desc.y += 10.0f;
    }
    desc.unk_C = 60.0f;
    desc.flags = 0x400000A;
    desc.callback = fn_10_19290;
    if (lbl_1_bss_8CA28 != 0) {
        desc.sx *= 2.0f;
        desc.sy *= 2.0f;
    }

    fn_1_8CED0((Sig_fn_1_8CED0_Fn8CED0Window *)&lbl_10_bss_517EC, fn_1_A5D88() >> 1, fn_1_A5D9C() >> 1);
    lbl_10_bss_517EC.unk_44 = 55.0f;
    fn_10_0(&col, &row, lbl_1_bss_8B3A0.entries[param.id].unk_0, 0);
    param.bits[param.id] = !!(*(&lbl_10_bss_1C.unk_4 + row * 38 + col * 2) & 0x80000000);
    fn_1_8D3F8(&lbl_10_bss_517EC, &desc, fn_1_131C08, &param);
}
/* fzgx:end fn_10_18DD0 */

/* fzgx:begin fn_10_19290 */
extern void fn_800736C0(int, void *);
extern void fn_80073620(int, int);
extern void fn_80072CC4(int, int, int, int, int);
extern void fn_80072E20(int, int, int, int, int, int);

void fn_10_19290(void) {
    struct {
        u32 a;
        u8 b[4];
    } local;
    local.b[3] = 0xff;
    local.a = *(u32 *)&local.b[0];
    fn_800736C0(3, &local);
    fn_80073620(0, 0x1f);
    fn_80072CC4(0, 4, 7, 6, 7);
    fn_80072E20(0, 0xe, 0, 0, 0, 0);
}
/* fzgx:end fn_10_19290 */

/* fzgx:begin fn_10_1973C */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const u32 fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
static const u32 fzgx_pool_table7[15] = {0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 119.0f;
    s = 141.0f;
    s = 160.0f;
    s = 163.0f;
    s = 43.0f;
    s = 130.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 67.5;
    d = 22.5;
    s = 22.5f;
    s = 0.009999999776482582f;
    s = 0.9166666865348816f;
    s = 2.0f;
    s = 240.0f;
    s = 9.999999747378752e-05f;
    s = 278.0f;
    s = 316.0f;
}
static const u32 fzgx_pool_table11[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 250.0f;
    s = 373.0f;
    s = 354.0f;
    s = 68.0f;
    s = 0.8666666746139526f;
    s = -1.0f;
    s = 140.0f;
    s = 50.0f;
    s = 0.10000000149011612f;
    s = 620.0f;
    s = 24.0f;
    s = 10.0f;
    s = 384.0f;
    s = 640.0f;
    s = 0.5833333134651184f;
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table13[2] = {0x000000FF, 0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 338.0f;
    s = 150.0f;
    s = 15.0f;
    s = 317.0f;
    s = -106.0f;
    s = 318.0f;
    s = 106.0f;
    s = 333.0f;
    s = -87.0f;
    s = 0.09000000357627869f;
    s = -11.0f;
    s = 645.0f;
    s = 721.0f;
    s = 330.0f;
    s = 0.9900000095367432f;
    s = 167.0f;
    s = 38.0f;
}
static const u32 fzgx_pool_table15[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 8.0f;
    s = 366.0f;
    s = 12.0f;
    s = 14.0f;
    s = 0.7599999904632568f;
}
static const u32 fzgx_pool_table17[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.15999984741211f;
    s = 280.0f;
    s = 5.699999809265137f;
    s = 4.5f;
    s = 0.7070000171661377f;
}
static const u32 fzgx_pool_table19[11] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025203E8, 0x03E803E8, 0x03E80000, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 99.0f;
    s = 47.0f;
    s = 67.0f;
    s = 64.0f;
    s = 219.0f;
    s = 594.0f;
    s = 593.0f;
    s = 48.0f;
    s = 0.38999998569488525f;
    s = 0.4274509847164154f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 46.0f;
    s = 246.0f;
    s = 120.0f;
    s = 470.0f;
    s = 247.0f;
    s = 45.0f;
    s = 34.0f;
    s = 258.0f;
    s = 0.30000001192092896f;
    s = 328.0f;
    s = 266.0f;
    s = 296.0f;
    s = 326.0f;
    s = 268.0f;
    s = 28.0f;
    s = 298.0f;
}
static const u32 fzgx_pool_table23[26] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025103E8, 0x03E803E8, 0x03E80000, 0x00000001, 0x00020003, 0x00030000, 0x00010002, 0x00020003, 0x00000001, 0x00010002, 0x00030000, 0x00000001, 0x00020002, 0x00000001, 0x00010002, 0x00000000, 0x00000001, 0x00010000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    s = 0.05000000074505806f;
    s = 127.0f;
    s = 3.427000045776367f;
    s = 0.0010000000474974513f;
}
static const u32 fzgx_pool_table25[3] = {0x00000000, 0xC1A00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 343.0f;
    s = 32767.0f;
    s = 2.1764705181121826f;
    s = 1.317647099494934f;
    s = 1.541176438331604f;
    s = 2.4000000953674316f;
    s = 2.4941177368164062f;
    s = 0.29411765933036804f;
    s = 315.0f;
    s = 1.2999999523162842f;
    s = 348.0f;
}
static const u32 fzgx_pool_table27[2] = {0x00000000, 0xFF000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 337.0f;
    s = 0.6600000262260437f;
    s = 0.46000000834465027f;
    s = 63.0f;
    s = 0.800000011920929f;
    s = 0.47999998927116394f;
    s = 1.25f;
    s = 44.0f;
}
static const u32 fzgx_pool_table29[39] = {0x358637BD, 0x00010000, 0x0000A117, 0x0000A118, 0x00000000, 0x00000000, 0x0000A125, 0x0000A126, 0x00010000, 0x00020000, 0x0000A123, 0x0000A124, 0x00020000, 0x00030000, 0x0000A11B, 0x0000A11C, 0x00040000, 0x00040000, 0x0000A121, 0x0000A122, 0x00030000, 0x00070000, 0x0000A11F, 0x0000A120, 0x00070000, 0x00050000, 0x0000A115, 0x0000A116, 0x00050000, 0x00060000, 0x0000A119, 0x0000A11A, 0x00060000, 0x00080000, 0x0000A11D, 0x0000A11E, 0x00040000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 255.0f;
    s = 95.0f;
    s = 180.0f;
    s = 92.0f;
    s = 9.999999046325684f;
    s = 80.0999984741211f;
    s = 83.0f;
    s = 85.0f;
    s = 0.6470588445663452f;
    s = 172.0f;
    s = 84.0f;
}
static const u32 fzgx_pool_table31[55] = {0xFF00FF00, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x0000A102, 0x0000A103, 0x0000A104, 0x0000A105, 0x0000A106, 0x00000000, 0x00000000, 0x00000140, 0x00000000, 0x00000000, 0x00A001E0, 0x00000000, 0x00000082, 0x014001FE, 0x00000000, 0x006200F6, 0x018A021E, 0x021E0050, 0x00C80140, 0x01B80230, 0x00000000, 0x000000B0, 0x008E0074, 0x00000000, 0x0000003D, 0x002C001F, 0xFF83F200, 0x00CAFF00, 0x00F0AE00, 0xF0ECAA00, 0xD4189300, 0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0xA0A0A000, 0x00000000, 0xFFFFFFDF, 0xFFFFFFF5, 0x0000000B, 0x00000021};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const u32 *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 349.0f;
    s = 1.3333333730697632f;
    s = 128.0f;
    s = 30.0f;
    s = 243.0f;
    s = 32.0f;
    s = 175.0f;
}
static const u32 fzgx_pool_table33[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const u32 *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime34(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.75;
    d = 0.25;
}
static const u32 fzgx_pool_table35[25] = {0xC8C8C800, 0x00000000, 0x00FF00FF, 0x00FF00FF, 0xFF960300, 0x00FF00FF, 0xFFED0000, 0x002C0014, 0x00140014, 0x00140014, 0x002C0000, 0x00600052, 0x00520052, 0x00520060, 0x00000008, 0x00000094, 0x00000008, 0x0000009A, 0x00000008, 0x00000094, 0x00000008, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFF00FF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep35(void) { const u32 *volatile cp; cp = fzgx_pool_table35; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime36(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 74.0f;
    s = 304.0f;
    s = 208.0f;
    s = 86.0f;
    s = 112.0f;
    s = 256.0f;
    s = 139.0f;
    s = 151.0f;
    s = 0.7200000286102295f;
    s = 220.0f;
    s = 231.0f;
    s = 102.0f;
    s = 329.0f;
    s = 70.0f;
    s = 79.0f;
    s = 345.0f;
    s = 0.125f;
    s = 377.0f;
    s = 389.0f;
}
static const u32 fzgx_pool_table37[35] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF00FF00, 0x000B000C, 0x000D000E, 0xFFFF000F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep37(void) { const u32 *volatile cp; cp = fzgx_pool_table37; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime38(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 350.0f;
    s = 252.0f;
    s = 244.0f;
    s = 52.0f;
    s = 62.0f;
    s = 0.47058823704719543f;
    s = 0.6196078658103943f;
}
static const u32 fzgx_pool_table39[2] = {0x00FF00FF, 0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep39(void) { const u32 *volatile cp; cp = fzgx_pool_table39; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime40(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.875f;
    s = 0.1666666716337204f;
    s = 0.1428571492433548f;
    s = 0.10000000894069672f;
    s = 0.08571429550647736f;
    s = 0.8333333730697632f;
    s = 0.8571429252624512f;
}
static const u32 fzgx_pool_table41[1] = {0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep41(void) { const u32 *volatile cp; cp = fzgx_pool_table41; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime42(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.1411764770746231f;
    s = 109.07058715820312f;
    s = -15.0f;
    s = 19.0f;
    s = -4.5f;
    s = -17.5f;
    s = 89.0f;
    s = 0.6274510025978088f;
    s = 0.007843137718737125f;
    s = 7.0f;
    s = 0.14901961386203766f;
    s = 586.0f;
    s = 400.0f;
}
#pragma section code_type ".text"

typedef struct {
    u32 w[22];
} Packet;

typedef struct {
    f32 pos[6];
    f32 pad_18[5];
    f32 field_2c;
    u32 field_30;
    u32 pad_34[7];
    u32 field_50;
    f32 field_54;
} Car;

typedef struct {
    u8 pad_0[0x9e];
    u8 unk_9e;
} Obj_8B3A0;
extern Obj_8B3A0 lbl_1_bss_8B3A0;

typedef struct {
    u8 pad_0[0x12];
    u8 unk_12;
    u8 pad_13[0x3d];
} Obj_5560C;
extern Obj_5560C lbl_10_bss_5560C;

typedef struct {
    u8 pad_0[0x30];
    u16 unk_30;
    u16 unk_32;
    u32 unk_34;
    u8 pad_38[0xc];
    f32 unk_44;
    u8 pad_48[0x18];
    u32 unk_60;
} Obj_5197C;
extern Obj_5197C lbl_10_bss_5197C;

extern f32 lbl_10_rodata_158[];
extern u32 lbl_1_rodata_26F8[];
extern u8 lbl_1_bss_8CA28;

typedef s32 (*cb_t)(u32);

extern void fn_1_51914(const void *);
extern void fn_1_51990(void *);
extern u16 fn_1_486C4(u32);
extern u16 fn_1_48690(u32);
extern void fn_1_8CED0(void *, u16, u16);
extern void fn_1_8D1C8(void *, cb_t, u32);
extern s32 fn_1_4FC50(void *, u32, u16, u16, u32);
extern void fn_10_12E34(void);
extern u32 fn_10_19C90(void);

void fn_10_1973C(void) {
    s8 *tab;
    Obj_5197C *p;
    s16 idx;
    Car car;
    Packet pkt;

    idx = lbl_1_bss_8B3A0.unk_9e;

    pkt = *(Packet *)lbl_1_rodata_26F8;
    pkt.w[0] = 0x9E1F;
    fn_1_51914(&pkt);

    car = *(Car *)lbl_1_rodata_26F8;
    tab = (s8 *)((u8 *)&lbl_10_bss_5560C + 0x12);
    car.pos[1] = 586.0f;
    car.pos[2] = 172.0f;
    car.pos[3] = 400.0f;
    car.field_54 = (f32)(tab[idx * 0x14] == 4);
    car.field_30 = 0x500000B;
    car.field_50 = (u32)fn_10_12E34;
    car.field_2c = 0.7f;
    fn_1_51990(&car);

    p = &lbl_10_bss_5197C;
    if (tab[idx * 0x14] == 4) {
        fn_1_8CED0(p, fn_1_48690(pkt.w[0]), fn_1_486C4(pkt.w[0]));
        p->unk_44 = 30.0f;
        fn_1_8D1C8(p, (cb_t)fn_10_19C90, (u32)&idx);
    }

    if (lbl_1_bss_8CA28) {
        car.pos[4] *= 2.0f;
        car.pos[5] *= 2.0f;
    }

    fn_1_4FC50(&car, p->unk_34, p->unk_30, p->unk_32, p->unk_60);
}
/* fzgx:end fn_10_1973C */

/* fzgx:begin fn_10_1B2F4 */
#include "font.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0f;
    d = 4503599627370496.0f;
}
static const u32 fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const u32 fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
static const u32 fzgx_pool_table7[15] = {0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 119.0f;
    s = 141.0f;
    s = 160.0f;
    s = 163.0f;
    s = 43.0f;
    s = 130.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0f;
    d = 67.5f;
    d = 22.5f;
    s = 22.5f;
    s = 0.009999999776482582f;
    s = 0.9166666865348816f;
    s = 2.0f;
    s = 240.0f;
    s = 9.999999747378752e-05f;
    s = 278.0f;
    s = 316.0f;
}
static const u32 fzgx_pool_table11[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 250.0f;
    s = 373.0f;
    s = 354.0f;
    s = 68.0f;
    s = 0.8666666746139526f;
    s = -1.0f;
    s = 140.0f;
    s = 50.0f;
    s = 0.10000000149011612f;
    s = 620.0f;
    s = 24.0f;
    s = 10.0f;
    s = 384.0f;
    s = 640.0f;
    s = 0.5833333134651184f;
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table13[2] = {0x000000FF, 0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 338.0f;
    s = 150.0f;
    s = 15.0f;
    s = 317.0f;
    s = -106.0f;
    s = 318.0f;
    s = 106.0f;
    s = 333.0f;
    s = -87.0f;
    s = 0.09000000357627869f;
    s = -11.0f;
    s = 645.0f;
    s = 721.0f;
    s = 330.0f;
    s = 0.9900000095367432f;
    s = 167.0f;
    s = 38.0f;
}
static const u32 fzgx_pool_table15[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 8.0f;
    s = 366.0f;
    s = 12.0f;
    s = 14.0f;
    s = 0.7599999904632568f;
}
static const u32 fzgx_pool_table17[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.15999984741211f;
    s = 280.0f;
    s = 5.699999809265137f;
    s = 4.5f;
    s = 0.7070000171661377f;
}
static const u32 fzgx_pool_table19[11] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025203E8, 0x03E803E8, 0x03E80000, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 99.0f;
    s = 47.0f;
    s = 67.0f;
    s = 64.0f;
    s = 219.0f;
    s = 594.0f;
    s = 593.0f;
    s = 48.0f;
    s = 0.38999998569488525f;
    s = 0.4274509847164154f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 46.0f;
    s = 246.0f;
    s = 120.0f;
    s = 470.0f;
    s = 247.0f;
    s = 45.0f;
    s = 34.0f;
    s = 258.0f;
    s = 0.30000001192092896f;
    s = 328.0f;
    s = 266.0f;
    s = 296.0f;
    s = 326.0f;
    s = 268.0f;
    s = 28.0f;
    s = 298.0f;
}
static const u32 fzgx_pool_table23[26] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025103E8, 0x03E803E8, 0x03E80000, 0x00000001, 0x00020003, 0x00030000, 0x00010002, 0x00020003, 0x00000001, 0x00010002, 0x00030000, 0x00000001, 0x00020002, 0x00000001, 0x00010002, 0x00000000, 0x00000001, 0x00010000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    s = 0.05000000074505806f;
    s = 127.0f;
    s = 3.427000045776367f;
    s = 0.0010000000474974513f;
}
static const u32 fzgx_pool_table25[3] = {0x00000000, 0xC1A00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 343.0f;
    s = 32767.0f;
    s = 2.1764705181121826f;
    s = 1.317647099494934f;
    s = 1.541176438331604f;
    s = 2.4000000953674316f;
    s = 2.4941177368164062f;
    s = 0.29411765933036804f;
    s = 315.0f;
    s = 1.2999999523162842f;
    s = 348.0f;
}
static const u32 fzgx_pool_table27[2] = {0x00000000, 0xFF000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 337.0f;
    s = 0.6600000262260437f;
    s = 0.46000000834465027f;
    s = 63.0f;
    s = 0.800000011920929f;
    s = 0.47999998927116394f;
    s = 1.25f;
    s = 44.0f;
}
static const u32 fzgx_pool_table29[39] = {0x358637BD, 0x00010000, 0x0000A117, 0x0000A118, 0x00000000, 0x00000000, 0x0000A125, 0x0000A126, 0x00010000, 0x00020000, 0x0000A123, 0x0000A124, 0x00020000, 0x00030000, 0x0000A11B, 0x0000A11C, 0x00040000, 0x00040000, 0x0000A121, 0x0000A122, 0x00030000, 0x00070000, 0x0000A11F, 0x0000A120, 0x00070000, 0x00050000, 0x0000A115, 0x0000A116, 0x00050000, 0x00060000, 0x0000A119, 0x0000A11A, 0x00060000, 0x00080000, 0x0000A11D, 0x0000A11E, 0x00040000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 255.0f;
    s = 95.0f;
    s = 180.0f;
    s = 92.0f;
    s = 9.999999046325684f;
    s = 80.0999984741211f;
    s = 83.0f;
    s = 85.0f;
    s = 0.6470588445663452f;
    s = 172.0f;
    s = 84.0f;
}
static const u32 fzgx_pool_table31[55] = {0xFF00FF00, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x0000A102, 0x0000A103, 0x0000A104, 0x0000A105, 0x0000A106, 0x00000000, 0x00000000, 0x00000140, 0x00000000, 0x00000000, 0x00A001E0, 0x00000000, 0x00000082, 0x014001FE, 0x00000000, 0x006200F6, 0x018A021E, 0x021E0050, 0x00C80140, 0x01B80230, 0x00000000, 0x000000B0, 0x008E0074, 0x00000000, 0x0000003D, 0x002C001F, 0xFF83F200, 0x00CAFF00, 0x00F0AE00, 0xF0ECAA00, 0xD4189300, 0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0xA0A0A000, 0x00000000, 0xFFFFFFDF, 0xFFFFFFF5, 0x0000000B, 0x00000021};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const u32 *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 349.0f;
    s = 1.3333333730697632f;
    s = 128.0f;
    s = 30.0f;
    s = 243.0f;
    s = 32.0f;
    s = 175.0f;
}
static const u32 fzgx_pool_table33[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const u32 *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime34(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.75f;
    d = 0.25f;
}
static const u32 fzgx_pool_table35[25] = {0xC8C8C800, 0x00000000, 0x00FF00FF, 0x00FF00FF, 0xFF960300, 0x00FF00FF, 0xFFED0000, 0x002C0014, 0x00140014, 0x00140014, 0x002C0000, 0x00600052, 0x00520052, 0x00520060, 0x00000008, 0x00000094, 0x00000008, 0x0000009A, 0x00000008, 0x00000094, 0x00000008, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFF00FF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep35(void) { const u32 *volatile cp; cp = fzgx_pool_table35; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime36(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 74.0f;
    s = 304.0f;
    s = 208.0f;
    s = 86.0f;
    s = 112.0f;
    s = 256.0f;
    s = 139.0f;
    s = 151.0f;
    s = 0.7200000286102295f;
    s = 220.0f;
    s = 231.0f;
    s = 102.0f;
    s = 329.0f;
    s = 70.0f;
    s = 79.0f;
    s = 345.0f;
    s = 0.125f;
    s = 377.0f;
    s = 389.0f;
}
static const u32 fzgx_pool_table37[35] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF00FF00, 0x000B000C, 0x000D000E, 0xFFFF000F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep37(void) { const u32 *volatile cp; cp = fzgx_pool_table37; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime38(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 350.0f;
    s = 252.0f;
    s = 244.0f;
    s = 52.0f;
    s = 62.0f;
    s = 0.47058823704719543f;
    s = 0.6196078658103943f;
}
static const u32 fzgx_pool_table39[2] = {0x00FF00FF, 0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep39(void) { const u32 *volatile cp; cp = fzgx_pool_table39; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime40(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.875f;
    s = 0.1666666716337204f;
    s = 0.1428571492433548f;
    s = 0.10000000894069672f;
    s = 0.08571429550647736f;
    s = 0.8333333730697632f;
    s = 0.8571429252624512f;
}
static const u32 fzgx_pool_table41[1] = {0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep41(void) { const u32 *volatile cp; cp = fzgx_pool_table41; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime42(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.1411764770746231f;
    s = 109.07058715820312f;
    s = -15.0f;
    s = 19.0f;
    s = -4.5f;
    s = -17.5f;
    s = 89.0f;
    s = 0.6274510025978088f;
    s = 0.007843137718737125f;
    s = 7.0f;
    s = 0.14901961386203766f;
    s = 586.0f;
    s = 400.0f;
    d = 0.55;
    s = 0.8299999833106995f;
}
static const u32 fzgx_pool_table43[1] = {0x00100000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep43(void) { const u32 *volatile cp; cp = fzgx_pool_table43; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime44(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5600000023841858f;
    s = 0.8899999856948853f;
    s = 0.019999999552965164f;
    s = 0.8799999952316284f;
}
static const u32 fzgx_pool_table45[1] = {0x000F0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep45(void) { const u32 *volatile cp; cp = fzgx_pool_table45; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime46(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4699999988079071f;
    s = 0.8100000023841858f;
}
static const u32 fzgx_pool_table47[4] = {0x3C23D70A, 0x3F4F5C29, 0x00130000, 0x3EF5C28F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep47(void) { const u32 *volatile cp; cp = fzgx_pool_table47; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime48(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9100000262260437f;
}
static const u32 fzgx_pool_table49[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep49(void) { const u32 *volatile cp; cp = fzgx_pool_table49; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime50(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8399999737739563f;
}
static const u32 fzgx_pool_table51[1] = {0x00170000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep51(void) { const u32 *volatile cp; cp = fzgx_pool_table51; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime52(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.49000000953674316f;
}
static const u32 fzgx_pool_table53[1] = {0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep53(void) { const u32 *volatile cp; cp = fzgx_pool_table53; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime54(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
}
static const u32 fzgx_pool_table55[2] = {0x3F570A3D, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep55(void) { const u32 *volatile cp; cp = fzgx_pool_table55; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime56(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5199999809265137f;
}
static const u32 fzgx_pool_table57[4] = {0x3F6147AE, 0x3C23D70A, 0x3F570A3D, 0x00240000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep57(void) { const u32 *volatile cp; cp = fzgx_pool_table57; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime58(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
    s = 0.8600000143051147f;
}
static const u32 fzgx_pool_table59[1] = {0x3C23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep59(void) { const u32 *volatile cp; cp = fzgx_pool_table59; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime60(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8500000238418579f;
}
static const u32 fzgx_pool_table61[2] = {0x000D0000, 0x3EF0A3D7};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep61(void) { const u32 *volatile cp; cp = fzgx_pool_table61; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime62(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8700000047683716f;
}
static const u32 fzgx_pool_table63[4] = {0x3C23D70A, 0x3F570A3D, 0x00180000, 0x3F11EB85};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep63(void) { const u32 *volatile cp; cp = fzgx_pool_table63; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime64(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0700000524520874f;
}
static const u32 fzgx_pool_table65[3] = {0xBC23D70A, 0x3F63D70A, 0x00170000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep65(void) { const u32 *volatile cp; cp = fzgx_pool_table65; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime66(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6399999856948853f;
}
static const u32 fzgx_pool_table67[2] = {0x3F63D70A, 0x3CA3D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep67(void) { const u32 *volatile cp; cp = fzgx_pool_table67; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime68(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.7900000214576721f;
}
static const u32 fzgx_pool_table69[6] = {0x00050000, 0x3EF0A3D7, 0x3F6147AE, 0x3C23D70A, 0x3F547AE1, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep69(void) { const u32 *volatile cp; cp = fzgx_pool_table69; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime70(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6299999952316284f;
}
static const u32 fzgx_pool_table71[1] = {0x3F63D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep71(void) { const u32 *volatile cp; cp = fzgx_pool_table71; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime72(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05999999865889549f;
}
static const u32 fzgx_pool_table73[2] = {0x3F4A3D71, 0x000B0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep73(void) { const u32 *volatile cp; cp = fzgx_pool_table73; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime74(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4399999976158142f;
}
static const u32 fzgx_pool_table75[14] = {0x3F400000, 0x00000000, 0x3F59999A, 0x00160000, 0x3EE147AE, 0x3F6147AE, 0x3C23D70A, 0x3F570A3D, 0x00120000, 0x3EF5C28F, 0x3F59999A, 0x3C23D70A, 0x3F59999A, 0x001D0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep75(void) { const u32 *volatile cp; cp = fzgx_pool_table75; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime76(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6800000071525574f;
    s = 0.9599999785423279f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table77[2] = {0x3F4F5C29, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep77(void) { const u32 *volatile cp; cp = fzgx_pool_table77; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime78(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.3700000047683716f;
}
static const u32 fzgx_pool_table79[9] = {0x3F800000, 0x3CF5C28F, 0x3F5C28F6, 0x000B0000, 0x3F000000, 0x3F5EB852, 0x3C23D70A, 0x3F570A3D, 0x00140000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep79(void) { const u32 *volatile cp; cp = fzgx_pool_table79; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime80(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4300000071525574f;
}
static const u32 fzgx_pool_table81[1] = {0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep81(void) { const u32 *volatile cp; cp = fzgx_pool_table81; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime82(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03999999910593033f;
}
static const u32 fzgx_pool_table83[17] = {0x3F547AE1, 0x000F0000, 0x3F2147AE, 0x3F5C28F6, 0x00000000, 0x3F5EB852, 0x00030000, 0x3F051EB8, 0x3F4A3D71, 0x3C23D70A, 0x3F59999A, 0x00050000, 0x3F000000, 0x3F59999A, 0x3C23D70A, 0x3F5C28F6, 0x00150000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep83(void) { const u32 *volatile cp; cp = fzgx_pool_table83; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime84(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5799999833106995f;
}
static const u32 fzgx_pool_table85[4] = {0x3F428F5C, 0x3C23D70A, 0x3F570A3D, 0x00080000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep85(void) { const u32 *volatile cp; cp = fzgx_pool_table85; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime86(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.44999998807907104f;
}
static const u32 fzgx_pool_table87[5] = {0x3F63D70A, 0x3CF5C28F, 0x3F5C28F6, 0x001E0000, 0x3EFAE148};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep87(void) { const u32 *volatile cp; cp = fzgx_pool_table87; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime88(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9200000166893005f;
}
static const u32 fzgx_pool_table89[14] = {0x3C23D70A, 0x3F59999A, 0x00000000, 0x3EE147AE, 0x3F6147AE, 0x3C23D70A, 0x3F5C28F6, 0x00160000, 0x3EDC28F6, 0x3F63D70A, 0x00000000, 0x3F4CCCCD, 0x00100000, 0x3F051EB8};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep89(void) { const u32 *volatile cp; cp = fzgx_pool_table89; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime90(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6899999976158142f;
}
static const u32 fzgx_pool_table91[8] = {0x3CA3D70A, 0x3F59999A, 0x00060000, 0x3EF0A3D7, 0x3F400000, 0xBC23D70A, 0x3F59999A, 0x00190000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep91(void) { const u32 *volatile cp; cp = fzgx_pool_table91; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime92(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5899999737739563f;
}
static const u32 fzgx_pool_table93[2] = {0x3F570A3D, 0x3CF5C28F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep93(void) { const u32 *volatile cp; cp = fzgx_pool_table93; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime94(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8199999928474426f;
}
static const u32 fzgx_pool_table95[1] = {0x00050000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep95(void) { const u32 *volatile cp; cp = fzgx_pool_table95; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime96(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5099999904632568f;
}
static const u32 fzgx_pool_table97[5] = {0x3F5C28F6, 0x00000000, 0x3F570A3D, 0x00040000, 0x3EF0A3D7};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep97(void) { const u32 *volatile cp; cp = fzgx_pool_table97; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime98(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.949999988079071f;
}
static const u32 fzgx_pool_table99[14] = {0x3C23D70A, 0x3F51EB85, 0x00100000, 0x3F28F5C3, 0x3F7D70A4, 0x3D23D70A, 0x3F6147AE, 0x000B0000, 0x3EE66666, 0x3F63D70A, 0x3C23D70A, 0x3F570A3D, 0x00060000, 0x3F333333};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep99(void) { const u32 *volatile cp; cp = fzgx_pool_table99; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime100(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2899999618530273f;
}
static const u32 fzgx_pool_table101[18] = {0xBC23D70A, 0x3F59999A, 0x00030000, 0x3EF0A3D7, 0x3F5EB852, 0x3C23D70A, 0x3F68F5C3, 0x00080000, 0x3EF5C28F, 0x3F6B851F, 0x00000000, 0x3F570A3D, 0x00060000, 0x3EE147AE, 0x3F547AE1, 0x00000000, 0x3F4A3D71, 0x00070000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep101(void) { const u32 *volatile cp; cp = fzgx_pool_table101; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime102(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4099999964237213f;
    s = 0.9700000286102295f;
}
static const u32 fzgx_pool_table103[3] = {0x3C23D70A, 0x3F51EB85, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep103(void) { const u32 *volatile cp; cp = fzgx_pool_table103; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime104(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.7300000190734863f;
}
static const u32 fzgx_pool_table105[11] = {0x3F63D70A, 0x3CF5C28F, 0x3F4F5C29, 0x00000000, 0x3F75C28F, 0x3F5EB852, 0x3CA3D70A, 0x3F59999A, 0x00050000, 0x3EEB851F, 0x3F51EB85};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep105(void) { const u32 *volatile cp; cp = fzgx_pool_table105; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime106(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.019999999552965164f;
}
static const u32 fzgx_pool_table107[1] = {0x3F59999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep107(void) { const u32 *volatile cp; cp = fzgx_pool_table107; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime108(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 88.0f;
    s = 116.0f;
    s = 16.0f;
    s = 340.0f;
    s = 335.0f;
    s = 397.0f;
}
static const u32 fzgx_pool_table109[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep109(void) { const u32 *volatile cp; cp = fzgx_pool_table109; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime110(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.49;
}
static const u32 fzgx_pool_table111[1] = {0x3F5C28F6};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep111(void) { const u32 *volatile cp; cp = fzgx_pool_table111; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime112(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.05999999865889549f;
}
static const u32 fzgx_pool_table113[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep113(void) { const u32 *volatile cp; cp = fzgx_pool_table113; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime114(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 36.0f;
    s = 21.0f;
}
static const u32 fzgx_pool_table115[18] = {0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep115(void) { const u32 *volatile cp; cp = fzgx_pool_table115; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime116(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 132.0f;
}
static const u32 fzgx_pool_table117[50] = {0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42D40000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep117(void) { const u32 *volatile cp; cp = fzgx_pool_table117; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime118(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 138.0f;
}
static const u32 fzgx_pool_table119[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep119(void) { const u32 *volatile cp; cp = fzgx_pool_table119; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime120(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 126.0f;
}
static const u32 fzgx_pool_table121[17] = {0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep121(void) { const u32 *volatile cp; cp = fzgx_pool_table121; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime122(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 124.0f;
}
static const u32 fzgx_pool_table123[104] = {0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x43000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42AC0000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42AC0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep123(void) { const u32 *volatile cp; cp = fzgx_pool_table123; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime124(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 148.0f;
}
static const u32 fzgx_pool_table125[38] = {0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42D40000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x430A0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep125(void) { const u32 *volatile cp; cp = fzgx_pool_table125; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime126(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 205.0f;
    s = 442.0f;
    s = 200.0f;
    s = -2.9000000953674316f;
}
static const u32 fzgx_pool_table127[1] = {0x3F23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep127(void) { const u32 *volatile cp; cp = fzgx_pool_table127; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime128(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 41.0f;
    s = 217.0f;
    s = 313.0f;
}
static const u32 fzgx_pool_table129[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep129(void) { const u32 *volatile cp; cp = fzgx_pool_table129; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"
extern int fn_1_4F734(FontDrawPacket *);
extern f32 lbl_8006D188(u32);
extern u32 lbl_801A66A0;
typedef struct {
    u32 id;
    f32 x, y, z;
    u8 pad[32];
    u32 flags;
    u8 pad2[4];
    u8 r, g, b, a;
    u8 pad3[28];
} DrawPacketLocal;
extern const DrawPacketLocal lbl_1_rodata_26F8;
static inline f32 fn_10_1B2F4_operand(f32 right, f32 left) { return left * right; }
#pragma peephole on
#pragma opt_strength_reduction off
static inline f32 fn_10_1B2F4_operand_(f32 left, f32 right) { return left * right; }
#pragma opt_common_subs off
void fn_10_1B2F4(void) {
    f32 fzgx_value;
    DrawPacketLocal p;
    FontDrawPacket * lab_t0;
    p = lbl_1_rodata_26F8;
    p.id = 40762;
    p.x = 320.0f;
    p.y = 240.0f;
    p.z = 100.0f;
    p.flags = 15;
    fn_1_4F734((FontDrawPacket *)&p);
    p.flags = 0x8000D;
    fn_1_4F734((FontDrawPacket *)&p);
    p.flags = 0x100007;
    fn_1_4F734((FontDrawPacket *)&p);
    p.flags = 0x180005;
    lab_t0 = (FontDrawPacket *)&p;
    fn_1_4F734(lab_t0);
    p = lbl_1_rodata_26F8;
    p.id = 40769;
    p.x = 172.0f;
    p.y = 298.0f;
    p.z = 80.0f;
    p.r = fn_10_1B2F4_operand(0.5f, 255.0f * (1.0f + lbl_8006D188((s32)(fn_10_1B2F4_operand_((65536.0f), ((lbl_801A66A0 % 60))) / 60.0f))));
    p.g = fn_10_1B2F4_operand(0.5f, 255.0f * (1.0f + lbl_8006D188((s32)(65536.0f * (lbl_801A66A0 % 60) / 60.0f))));
    p.b = fn_10_1B2F4_operand(0.5f, 255.0f * (1.0f + lbl_8006D188((s32)(fn_10_1B2F4_operand(((lbl_801A66A0 % 60)), (65536.0f)) / 60.0f))));
    fn_1_4F734((FontDrawPacket *)&p);
    p = lbl_1_rodata_26F8;
    p.id = 40707;
    p.x = 320.0f;
    p.y = 240.0f;
    p.z = 60.0f;
    p.flags = 10;
    fn_1_4F734((FontDrawPacket *)&p);
    p = lbl_1_rodata_26F8;
    p.x = 313.0f;
    fzgx_value = 230.0f;
    p.y = fzgx_value;
    p.z = 50.0f;
    p.id = 40708;
    fn_1_4F734((FontDrawPacket *)&p);
}
#pragma opt_common_subs reset

#pragma opt_strength_reduction reset

#pragma peephole reset
/* fzgx:end fn_10_1B2F4 */

/* fzgx:begin fn_10_1B658 */
// fn_10_1B658: empty in retail (single blr).
void fn_10_1B658(void) {
}
/* fzgx:end fn_10_1B658 */

/* fzgx:begin fn_10_1B65C */
// fn_10_1B65C: empty in retail (single blr).
void fn_10_1B65C(void) {
}
/* fzgx:end fn_10_1B65C */

/* fzgx:begin fn_10_1B660 */
// fn_10_1B660: empty in retail (single blr).
void fn_10_1B660(void) {
}
/* fzgx:end fn_10_1B660 */

/* fzgx:begin fn_10_1B664 */
extern void fn_1_13D02C(void);

void fn_10_1B664(void) {
    fn_1_13D02C();
}
/* fzgx:end fn_10_1B664 */

/* fzgx:begin fn_10_1B684 */
extern void fn_1_13D02C(void);
extern void fn_10_1B6CC(void);

void fn_10_1B684(void) {
    fn_1_13D02C();
    fn_10_1B6CC();
}
/* fzgx:end fn_10_1B684 */

/* fzgx:begin fn_10_1B6A8 */
extern void fn_1_13D02C(void);
extern void fn_10_1B6CC(void);

void fn_10_1B6A8(void) {
    fn_1_13D02C();
    fn_10_1B6CC();
}
/* fzgx:end fn_10_1B6A8 */

/* fzgx:begin fn_10_1BCD0 */
#include "font.h"

struct fn_10_1BCD0_Copy88 { u32 a[22]; };
struct fn_10_1BCD0_lbl_10_rodata_158 {
    u8 pad_0[0x48];
    f32 unk_48;
    f32 unk_4C;
    u8 pad_50[0x8];
    f32 unk_58;
    u8 pad_5C[0xF4];
    f32 unk_150;
    u8 pad_154[0x23C];
    f32 unk_390;
    u8 pad_394[0x10C];
    f32 unk_4A0;
    u8 pad_4A4[0x388];
    f32 unk_82C;
    u8 pad_830[0x7A8];
    u32 unk_FD8;
    u32 unk_FDC;
    u32 unk_FE0;
    u32 unk_FE4;
    f32 unk_FE8;
    f32 unk_FEC;
    f32 unk_FF0;
};

extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_10_1BCD0_lbl_10_rodata_158 lbl_10_rodata_158;
extern u32 lbl_1_rodata_26F8;

void fn_10_1BCD0(void) {
    FontDrawPacket loc_8;
    f32 v21;
    u32 v20;
    f32 v19;
    f32 v18;
    f32 v17;
    u32 v16;
    f32 v15;
    f32 v14;
    f32 v13;
    u32 v12;
    f32 v11;
    f32 v10;
    u32 v9;
    u32 v8;
    f32 v7;
    f32 v6;
    f32 v5;
    f32 v4;
    f32 v3;
    f32 v2;
    f32 v1;
    f32 v0;
    struct fn_10_1BCD0_lbl_10_rodata_158 *p_lbl_10_rodata_158;
    /* frame */
    p_lbl_10_rodata_158 = (struct fn_10_1BCD0_lbl_10_rodata_158 *)&lbl_10_rodata_158;
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v0 = p_lbl_10_rodata_158->unk_4C;
    loc_8.image = (0x10000 - 26107);
    loc_8.x = v0;
    loc_8.y = v0;
    loc_8.z = p_lbl_10_rodata_158->unk_150;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v1 = p_lbl_10_rodata_158->unk_58;
    v2 = p_lbl_10_rodata_158->unk_4C;
    loc_8.image = (0x10000 - 26107);
    loc_8.x = v1;
    loc_8.y = v2;
    loc_8.z = p_lbl_10_rodata_158->unk_390;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v3 = p_lbl_10_rodata_158->unk_4C;
    v4 = p_lbl_10_rodata_158->unk_FE8;
    loc_8.image = (0x10000 - 26111);
    loc_8.x = v3;
    loc_8.y = v4;
    loc_8.z = p_lbl_10_rodata_158->unk_FEC;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v5 = p_lbl_10_rodata_158->unk_58;
    v6 = p_lbl_10_rodata_158->unk_4A0;
    v7 = p_lbl_10_rodata_158->unk_82C;
    v8 = (0x10000 - 26085);
    v9 = (0x100000 + 7);
    loc_8.image = v8;
    loc_8.x = v5;
    loc_8.y = v6;
    loc_8.z = v7;
    loc_8.flags = v9;
    *(u32 *)((u8 *)&loc_8 + 56) = p_lbl_10_rodata_158->unk_FD8;
    loc_8.alpha = p_lbl_10_rodata_158->unk_48;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v10 = p_lbl_10_rodata_158->unk_58;
    v11 = p_lbl_10_rodata_158->unk_4A0;
    v12 = (0x10000 - 26085);
    v13 = p_lbl_10_rodata_158->unk_82C;
    loc_8.image = v12;
    loc_8.x = v10;
    loc_8.y = v11;
    loc_8.z = v13;
    loc_8.flags = 0x180000;
    *(u32 *)((u8 *)&loc_8 + 56) = p_lbl_10_rodata_158->unk_FDC;
    loc_8.alpha = p_lbl_10_rodata_158->unk_48;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v14 = p_lbl_10_rodata_158->unk_58;
    v15 = p_lbl_10_rodata_158->unk_FF0;
    v16 = (0x10000 - 26085);
    v17 = p_lbl_10_rodata_158->unk_82C;
    loc_8.image = v16;
    loc_8.x = v14;
    loc_8.y = v15;
    loc_8.z = v17;
    loc_8.flags = 7;
    *(u32 *)((u8 *)&loc_8 + 56) = p_lbl_10_rodata_158->unk_FE0;
    loc_8.alpha = p_lbl_10_rodata_158->unk_48;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    v18 = p_lbl_10_rodata_158->unk_58;
    v19 = p_lbl_10_rodata_158->unk_FF0;
    v20 = (0x10000 - 26085);
    v21 = p_lbl_10_rodata_158->unk_82C;
    loc_8.image = v20;
    loc_8.x = v18;
    loc_8.y = v19;
    loc_8.z = v21;
    loc_8.flags = 0x80000;
    *(u32 *)((u8 *)&loc_8 + 56) = p_lbl_10_rodata_158->unk_FE4;
    loc_8.alpha = p_lbl_10_rodata_158->unk_48;
    fn_1_4F734((FontDrawPacket *)&loc_8);
}
/* fzgx:end fn_10_1BCD0 */

/* fzgx:begin fn_10_1C2D8 noprologue */
#include "types.h"
#include "font.h"
#include "rel/main_rel/globals.h"

typedef struct {u8 r, g, b, a;} SelectionColor;
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const u32 fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
static const u32 fzgx_pool_table7[15] = {0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 119.0f;
    s = 141.0f;
    s = 160.0f;
    s = 163.0f;
    s = 43.0f;
    s = 130.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 67.5;
    d = 22.5;
    s = 22.5f;
    s = 0.009999999776482582f;
    s = 0.9166666865348816f;
    s = 2.0f;
    s = 240.0f;
    s = 9.999999747378752e-05f;
    s = 278.0f;
    s = 316.0f;
}
static const u32 fzgx_pool_table11[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 250.0f;
    s = 373.0f;
    s = 354.0f;
    s = 68.0f;
    s = 0.8666666746139526f;
    s = -1.0f;
    s = 140.0f;
    s = 50.0f;
    s = 0.10000000149011612f;
    s = 620.0f;
    s = 24.0f;
    s = 10.0f;
    s = 384.0f;
    s = 640.0f;
    s = 0.5833333134651184f;
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table13[2] = {0x000000FF, 0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 338.0f;
    s = 150.0f;
    s = 15.0f;
    s = 317.0f;
    s = -106.0f;
    s = 318.0f;
    s = 106.0f;
    s = 333.0f;
    s = -87.0f;
    s = 0.09000000357627869f;
    s = -11.0f;
    s = 645.0f;
    s = 721.0f;
    s = 330.0f;
    s = 0.9900000095367432f;
    s = 167.0f;
    s = 38.0f;
}
static const u32 fzgx_pool_table15[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 8.0f;
    s = 366.0f;
    s = 12.0f;
    s = 14.0f;
    s = 0.7599999904632568f;
}
static const u32 fzgx_pool_table17[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.15999984741211f;
    s = 280.0f;
    s = 5.699999809265137f;
    s = 4.5f;
    s = 0.7070000171661377f;
}
static const u32 fzgx_pool_table19[11] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025203E8, 0x03E803E8, 0x03E80000, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 99.0f;
    s = 47.0f;
    s = 67.0f;
    s = 64.0f;
    s = 219.0f;
    s = 594.0f;
    s = 593.0f;
    s = 48.0f;
    s = 0.38999998569488525f;
    s = 0.4274509847164154f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 46.0f;
    s = 246.0f;
    s = 120.0f;
    s = 470.0f;
    s = 247.0f;
    s = 45.0f;
    s = 34.0f;
    s = 258.0f;
    s = 0.30000001192092896f;
    s = 328.0f;
    s = 266.0f;
    s = 296.0f;
    s = 326.0f;
    s = 268.0f;
    s = 28.0f;
    s = 298.0f;
}
static const u32 fzgx_pool_table23[26] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025103E8, 0x03E803E8, 0x03E80000, 0x00000001, 0x00020003, 0x00030000, 0x00010002, 0x00020003, 0x00000001, 0x00010002, 0x00030000, 0x00000001, 0x00020002, 0x00000001, 0x00010002, 0x00000000, 0x00000001, 0x00010000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    s = 0.05000000074505806f;
    s = 127.0f;
    s = 3.427000045776367f;
    s = 0.0010000000474974513f;
}
static const u32 fzgx_pool_table25[3] = {0x00000000, 0xC1A00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 343.0f;
    s = 32767.0f;
    s = 2.1764705181121826f;
    s = 1.317647099494934f;
    s = 1.541176438331604f;
    s = 2.4000000953674316f;
    s = 2.4941177368164062f;
    s = 0.29411765933036804f;
    s = 315.0f;
    s = 1.2999999523162842f;
    s = 348.0f;
}
static const u32 fzgx_pool_table27[2] = {0x00000000, 0xFF000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 337.0f;
    s = 0.6600000262260437f;
    s = 0.46000000834465027f;
    s = 63.0f;
    s = 0.800000011920929f;
    s = 0.47999998927116394f;
    s = 1.25f;
    s = 44.0f;
}
static const u32 fzgx_pool_table29[39] = {0x358637BD, 0x00010000, 0x0000A117, 0x0000A118, 0x00000000, 0x00000000, 0x0000A125, 0x0000A126, 0x00010000, 0x00020000, 0x0000A123, 0x0000A124, 0x00020000, 0x00030000, 0x0000A11B, 0x0000A11C, 0x00040000, 0x00040000, 0x0000A121, 0x0000A122, 0x00030000, 0x00070000, 0x0000A11F, 0x0000A120, 0x00070000, 0x00050000, 0x0000A115, 0x0000A116, 0x00050000, 0x00060000, 0x0000A119, 0x0000A11A, 0x00060000, 0x00080000, 0x0000A11D, 0x0000A11E, 0x00040000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 255.0f;
    s = 95.0f;
    s = 180.0f;
    s = 92.0f;
    s = 9.999999046325684f;
    s = 80.0999984741211f;
    s = 83.0f;
    s = 85.0f;
    s = 0.6470588445663452f;
    s = 172.0f;
    s = 84.0f;
}
static const u32 fzgx_pool_table31[55] = {0xFF00FF00, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x0000A102, 0x0000A103, 0x0000A104, 0x0000A105, 0x0000A106, 0x00000000, 0x00000000, 0x00000140, 0x00000000, 0x00000000, 0x00A001E0, 0x00000000, 0x00000082, 0x014001FE, 0x00000000, 0x006200F6, 0x018A021E, 0x021E0050, 0x00C80140, 0x01B80230, 0x00000000, 0x000000B0, 0x008E0074, 0x00000000, 0x0000003D, 0x002C001F, 0xFF83F200, 0x00CAFF00, 0x00F0AE00, 0xF0ECAA00, 0xD4189300, 0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0xA0A0A000, 0x00000000, 0xFFFFFFDF, 0xFFFFFFF5, 0x0000000B, 0x00000021};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const u32 *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 349.0f;
    s = 1.3333333730697632f;
    s = 128.0f;
    s = 30.0f;
    s = 243.0f;
    s = 32.0f;
    s = 175.0f;
}
static const u32 fzgx_pool_table33[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const u32 *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime34(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.75;
    d = 0.25;
}
static const u32 fzgx_pool_table35[25] = {0xC8C8C800, 0x00000000, 0x00FF00FF, 0x00FF00FF, 0xFF960300, 0x00FF00FF, 0xFFED0000, 0x002C0014, 0x00140014, 0x00140014, 0x002C0000, 0x00600052, 0x00520052, 0x00520060, 0x00000008, 0x00000094, 0x00000008, 0x0000009A, 0x00000008, 0x00000094, 0x00000008, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFF00FF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep35(void) { const u32 *volatile cp; cp = fzgx_pool_table35; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime36(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 74.0f;
    s = 304.0f;
    s = 208.0f;
    s = 86.0f;
    s = 112.0f;
    s = 256.0f;
    s = 139.0f;
    s = 151.0f;
    s = 0.7200000286102295f;
    s = 220.0f;
    s = 231.0f;
    s = 102.0f;
    s = 329.0f;
    s = 70.0f;
    s = 79.0f;
    s = 345.0f;
    s = 0.125f;
    s = 377.0f;
    s = 389.0f;
}
static const u32 fzgx_pool_table37[35] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF00FF00, 0x000B000C, 0x000D000E, 0xFFFF000F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep37(void) { const u32 *volatile cp; cp = fzgx_pool_table37; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime38(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 350.0f;
    s = 252.0f;
    s = 244.0f;
    s = 52.0f;
    s = 62.0f;
    s = 0.47058823704719543f;
    s = 0.6196078658103943f;
}
static const u32 fzgx_pool_table39[2] = {0x00FF00FF, 0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep39(void) { const u32 *volatile cp; cp = fzgx_pool_table39; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime40(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.875f;
    s = 0.1666666716337204f;
    s = 0.1428571492433548f;
    s = 0.10000000894069672f;
    s = 0.08571429550647736f;
    s = 0.8333333730697632f;
    s = 0.8571429252624512f;
}
static const u32 fzgx_pool_table41[1] = {0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep41(void) { const u32 *volatile cp; cp = fzgx_pool_table41; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime42(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.1411764770746231f;
    s = 109.07058715820312f;
    s = -15.0f;
    s = 19.0f;
    s = -4.5f;
    s = -17.5f;
    s = 89.0f;
    s = 0.6274510025978088f;
    s = 0.007843137718737125f;
    s = 7.0f;
    s = 0.14901961386203766f;
    s = 586.0f;
    s = 400.0f;
    d = 0.55;
    s = 0.8299999833106995f;
}
static const u32 fzgx_pool_table43[1] = {0x00100000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep43(void) { const u32 *volatile cp; cp = fzgx_pool_table43; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime44(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5600000023841858f;
    s = 0.8899999856948853f;
    s = 0.019999999552965164f;
    s = 0.8799999952316284f;
}
static const u32 fzgx_pool_table45[1] = {0x000F0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep45(void) { const u32 *volatile cp; cp = fzgx_pool_table45; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime46(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4699999988079071f;
    s = 0.8100000023841858f;
}
static const u32 fzgx_pool_table47[4] = {0x3C23D70A, 0x3F4F5C29, 0x00130000, 0x3EF5C28F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep47(void) { const u32 *volatile cp; cp = fzgx_pool_table47; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime48(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9100000262260437f;
}
static const u32 fzgx_pool_table49[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep49(void) { const u32 *volatile cp; cp = fzgx_pool_table49; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime50(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8399999737739563f;
}
static const u32 fzgx_pool_table51[1] = {0x00170000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep51(void) { const u32 *volatile cp; cp = fzgx_pool_table51; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime52(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.49000000953674316f;
}
static const u32 fzgx_pool_table53[1] = {0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep53(void) { const u32 *volatile cp; cp = fzgx_pool_table53; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime54(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
}
static const u32 fzgx_pool_table55[2] = {0x3F570A3D, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep55(void) { const u32 *volatile cp; cp = fzgx_pool_table55; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime56(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5199999809265137f;
}
static const u32 fzgx_pool_table57[4] = {0x3F6147AE, 0x3C23D70A, 0x3F570A3D, 0x00240000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep57(void) { const u32 *volatile cp; cp = fzgx_pool_table57; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime58(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
    s = 0.8600000143051147f;
}
static const u32 fzgx_pool_table59[1] = {0x3C23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep59(void) { const u32 *volatile cp; cp = fzgx_pool_table59; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime60(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8500000238418579f;
}
static const u32 fzgx_pool_table61[2] = {0x000D0000, 0x3EF0A3D7};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep61(void) { const u32 *volatile cp; cp = fzgx_pool_table61; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime62(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8700000047683716f;
}
static const u32 fzgx_pool_table63[4] = {0x3C23D70A, 0x3F570A3D, 0x00180000, 0x3F11EB85};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep63(void) { const u32 *volatile cp; cp = fzgx_pool_table63; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime64(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0700000524520874f;
}
static const u32 fzgx_pool_table65[3] = {0xBC23D70A, 0x3F63D70A, 0x00170000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep65(void) { const u32 *volatile cp; cp = fzgx_pool_table65; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime66(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6399999856948853f;
}
static const u32 fzgx_pool_table67[2] = {0x3F63D70A, 0x3CA3D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep67(void) { const u32 *volatile cp; cp = fzgx_pool_table67; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime68(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.7900000214576721f;
}
static const u32 fzgx_pool_table69[6] = {0x00050000, 0x3EF0A3D7, 0x3F6147AE, 0x3C23D70A, 0x3F547AE1, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep69(void) { const u32 *volatile cp; cp = fzgx_pool_table69; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime70(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6299999952316284f;
}
static const u32 fzgx_pool_table71[1] = {0x3F63D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep71(void) { const u32 *volatile cp; cp = fzgx_pool_table71; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime72(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05999999865889549f;
}
static const u32 fzgx_pool_table73[2] = {0x3F4A3D71, 0x000B0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep73(void) { const u32 *volatile cp; cp = fzgx_pool_table73; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime74(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4399999976158142f;
}
static const u32 fzgx_pool_table75[14] = {0x3F400000, 0x00000000, 0x3F59999A, 0x00160000, 0x3EE147AE, 0x3F6147AE, 0x3C23D70A, 0x3F570A3D, 0x00120000, 0x3EF5C28F, 0x3F59999A, 0x3C23D70A, 0x3F59999A, 0x001D0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep75(void) { const u32 *volatile cp; cp = fzgx_pool_table75; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime76(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6800000071525574f;
    s = 0.9599999785423279f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table77[2] = {0x3F4F5C29, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep77(void) { const u32 *volatile cp; cp = fzgx_pool_table77; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime78(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.3700000047683716f;
}
static const u32 fzgx_pool_table79[9] = {0x3F800000, 0x3CF5C28F, 0x3F5C28F6, 0x000B0000, 0x3F000000, 0x3F5EB852, 0x3C23D70A, 0x3F570A3D, 0x00140000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep79(void) { const u32 *volatile cp; cp = fzgx_pool_table79; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime80(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4300000071525574f;
}
static const u32 fzgx_pool_table81[1] = {0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep81(void) { const u32 *volatile cp; cp = fzgx_pool_table81; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime82(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03999999910593033f;
}
static const u32 fzgx_pool_table83[17] = {0x3F547AE1, 0x000F0000, 0x3F2147AE, 0x3F5C28F6, 0x00000000, 0x3F5EB852, 0x00030000, 0x3F051EB8, 0x3F4A3D71, 0x3C23D70A, 0x3F59999A, 0x00050000, 0x3F000000, 0x3F59999A, 0x3C23D70A, 0x3F5C28F6, 0x00150000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep83(void) { const u32 *volatile cp; cp = fzgx_pool_table83; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime84(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5799999833106995f;
}
static const u32 fzgx_pool_table85[4] = {0x3F428F5C, 0x3C23D70A, 0x3F570A3D, 0x00080000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep85(void) { const u32 *volatile cp; cp = fzgx_pool_table85; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime86(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.44999998807907104f;
}
static const u32 fzgx_pool_table87[5] = {0x3F63D70A, 0x3CF5C28F, 0x3F5C28F6, 0x001E0000, 0x3EFAE148};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep87(void) { const u32 *volatile cp; cp = fzgx_pool_table87; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime88(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9200000166893005f;
}
static const u32 fzgx_pool_table89[14] = {0x3C23D70A, 0x3F59999A, 0x00000000, 0x3EE147AE, 0x3F6147AE, 0x3C23D70A, 0x3F5C28F6, 0x00160000, 0x3EDC28F6, 0x3F63D70A, 0x00000000, 0x3F4CCCCD, 0x00100000, 0x3F051EB8};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep89(void) { const u32 *volatile cp; cp = fzgx_pool_table89; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime90(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6899999976158142f;
}
static const u32 fzgx_pool_table91[8] = {0x3CA3D70A, 0x3F59999A, 0x00060000, 0x3EF0A3D7, 0x3F400000, 0xBC23D70A, 0x3F59999A, 0x00190000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep91(void) { const u32 *volatile cp; cp = fzgx_pool_table91; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime92(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5899999737739563f;
}
static const u32 fzgx_pool_table93[2] = {0x3F570A3D, 0x3CF5C28F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep93(void) { const u32 *volatile cp; cp = fzgx_pool_table93; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime94(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8199999928474426f;
}
static const u32 fzgx_pool_table95[1] = {0x00050000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep95(void) { const u32 *volatile cp; cp = fzgx_pool_table95; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime96(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5099999904632568f;
}
static const u32 fzgx_pool_table97[5] = {0x3F5C28F6, 0x00000000, 0x3F570A3D, 0x00040000, 0x3EF0A3D7};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep97(void) { const u32 *volatile cp; cp = fzgx_pool_table97; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime98(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.949999988079071f;
}
static const u32 fzgx_pool_table99[14] = {0x3C23D70A, 0x3F51EB85, 0x00100000, 0x3F28F5C3, 0x3F7D70A4, 0x3D23D70A, 0x3F6147AE, 0x000B0000, 0x3EE66666, 0x3F63D70A, 0x3C23D70A, 0x3F570A3D, 0x00060000, 0x3F333333};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep99(void) { const u32 *volatile cp; cp = fzgx_pool_table99; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime100(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2899999618530273f;
}
static const u32 fzgx_pool_table101[18] = {0xBC23D70A, 0x3F59999A, 0x00030000, 0x3EF0A3D7, 0x3F5EB852, 0x3C23D70A, 0x3F68F5C3, 0x00080000, 0x3EF5C28F, 0x3F6B851F, 0x00000000, 0x3F570A3D, 0x00060000, 0x3EE147AE, 0x3F547AE1, 0x00000000, 0x3F4A3D71, 0x00070000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep101(void) { const u32 *volatile cp; cp = fzgx_pool_table101; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime102(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4099999964237213f;
    s = 0.9700000286102295f;
}
static const u32 fzgx_pool_table103[3] = {0x3C23D70A, 0x3F51EB85, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep103(void) { const u32 *volatile cp; cp = fzgx_pool_table103; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime104(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.7300000190734863f;
}
static const u32 fzgx_pool_table105[11] = {0x3F63D70A, 0x3CF5C28F, 0x3F4F5C29, 0x00000000, 0x3F75C28F, 0x3F5EB852, 0x3CA3D70A, 0x3F59999A, 0x00050000, 0x3EEB851F, 0x3F51EB85};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep105(void) { const u32 *volatile cp; cp = fzgx_pool_table105; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime106(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.019999999552965164f;
}
static const u32 fzgx_pool_table107[1] = {0x3F59999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep107(void) { const u32 *volatile cp; cp = fzgx_pool_table107; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime108(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 88.0f;
    s = 116.0f;
    s = 16.0f;
    s = 340.0f;
    s = 335.0f;
    s = 397.0f;
}
static const u32 fzgx_pool_table109[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep109(void) { const u32 *volatile cp; cp = fzgx_pool_table109; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime110(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.49;
}
static const u32 fzgx_pool_table111[1] = {0x3F5C28F6};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep111(void) { const u32 *volatile cp; cp = fzgx_pool_table111; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime112(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.05999999865889549f;
}
static const u32 fzgx_pool_table113[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep113(void) { const u32 *volatile cp; cp = fzgx_pool_table113; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime114(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 36.0f;
    s = 21.0f;
}
static const u32 fzgx_pool_table115[18] = {0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep115(void) { const u32 *volatile cp; cp = fzgx_pool_table115; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime116(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 132.0f;
}
static const u32 fzgx_pool_table117[50] = {0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42D40000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep117(void) { const u32 *volatile cp; cp = fzgx_pool_table117; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime118(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 138.0f;
}
static const u32 fzgx_pool_table119[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep119(void) { const u32 *volatile cp; cp = fzgx_pool_table119; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime120(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 126.0f;
}
static const u32 fzgx_pool_table121[17] = {0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep121(void) { const u32 *volatile cp; cp = fzgx_pool_table121; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime122(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 124.0f;
}
static const u32 fzgx_pool_table123[104] = {0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x43000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42AC0000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42AC0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep123(void) { const u32 *volatile cp; cp = fzgx_pool_table123; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime124(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 148.0f;
}
static const u32 fzgx_pool_table125[38] = {0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42D40000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x430A0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep125(void) { const u32 *volatile cp; cp = fzgx_pool_table125; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime126(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 205.0f;
    s = 442.0f;
    s = 200.0f;
    s = -2.9000000953674316f;
}
static const u32 fzgx_pool_table127[1] = {0x3F23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep127(void) { const u32 *volatile cp; cp = fzgx_pool_table127; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime128(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 41.0f;
    s = 217.0f;
    s = 313.0f;
}
static const u32 fzgx_pool_table129[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep129(void) { const u32 *volatile cp; cp = fzgx_pool_table129; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime130(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 428.0f;
    s = 239.0f;
    s = 0.10999999940395355f;
    s = 0.37662336230278015f;
    s = 0.9090909361839294f;
    s = 0.09090909361839294f;
    s = 0.41558441519737244f;
    s = 0.8116883039474487f;
    s = 0.3961038887500763f;
    s = 0.8831169009208679f;
    s = 0.025974025949835777f;
    s = 578.0f;
    s = 0.10500000417232513f;
    s = 0.375f;
    s = 203.0f;
    s = 272.0f;
    s = 206.0f;
    s = 275.0f;
    s = 0.11500000208616257f;
    s = 8.25f;
    s = 271.0f;
}
static const u32 fzgx_pool_table131[1] = {0x43140000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep131(void) { const u32 *volatile cp; cp = fzgx_pool_table131; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime132(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 147.0f;
    s = 492.0f;
}
static const u32 fzgx_pool_table133[4] = {0x161846FF, 0x161846FF, 0x161846FF, 0x161846FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep133(void) { const u32 *volatile cp; cp = fzgx_pool_table133; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime134(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 436.0f;
    s = 300.0f;
    s = 388.0f;
}
static const u32 fzgx_pool_table135[1] = {0xA0FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep135(void) { const u32 *volatile cp; cp = fzgx_pool_table135; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime136(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4166666567325592f;
    s = 216.0f;
    s = 27.0f;
    s = 176.0f;
}
static const SelectionColor fzgx_pool_color0 = {0, 0, 0, 0};
static const SelectionColor fzgx_pool_color1 = {96, 96, 96, 255};
static const SelectionColor fzgx_pool_color2 = {255, 255, 255, 0};
static const SelectionColor fzgx_pool_color3 = {160, 255, 0, 255};
static const SelectionColor fzgx_pool_color4 = {255, 255, 255, 0};
static const SelectionColor fzgx_pool_color5 = {160, 255, 0, 255};
static const SelectionColor fzgx_pool_color6 = {255, 255, 255, 0};
static const SelectionColor fzgx_pool_color7 = {160, 255, 0, 255};
static const SelectionColor fzgx_pool_color8 = {255, 255, 255, 0};
static const SelectionColor fzgx_pool_color9 = {160, 255, 0, 255};
static const SelectionColor fzgx_pool_color10 = {255, 255, 255, 0};
static const SelectionColor fzgx_pool_color11 = {160, 255, 0, 255};
static const SelectionColor fzgx_pool_color12 = {255, 255, 255, 0};
static const SelectionColor fzgx_pool_color13 = {160, 255, 0, 255};
static const SelectionColor fzgx_pool_color14 = {255, 255, 255, 0};
static const SelectionColor fzgx_pool_color15 = {160, 255, 0, 255};
static const SelectionColor fzgx_pool_color16 = {255, 255, 255, 0};
static const SelectionColor fzgx_pool_color17 = {160, 255, 0, 255};
static const SelectionColor fzgx_pool_color18 = {255, 255, 255, 0};
static const SelectionColor fzgx_pool_color19 = {0, 0, 0, 0};
__declspec(section ".fzgxpool") static void fzgx_pool_keep137(void) {const u32 *volatile p; p = (const u32 *)&fzgx_pool_color0; p = (const u32 *)&fzgx_pool_color1; p = (const u32 *)&fzgx_pool_color2; p = (const u32 *)&fzgx_pool_color3; p = (const u32 *)&fzgx_pool_color4; p = (const u32 *)&fzgx_pool_color5; p = (const u32 *)&fzgx_pool_color6; p = (const u32 *)&fzgx_pool_color7; p = (const u32 *)&fzgx_pool_color8; p = (const u32 *)&fzgx_pool_color9; p = (const u32 *)&fzgx_pool_color10; p = (const u32 *)&fzgx_pool_color11; p = (const u32 *)&fzgx_pool_color12; p = (const u32 *)&fzgx_pool_color13; p = (const u32 *)&fzgx_pool_color14; p = (const u32 *)&fzgx_pool_color15; p = (const u32 *)&fzgx_pool_color16; p = (const u32 *)&fzgx_pool_color17; p = (const u32 *)&fzgx_pool_color18; p = (const u32 *)&fzgx_pool_color19;} /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime138(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 120.0;
    d = 80.0;
    s = 356.0f;
    s = 476.0f;
    s = 0.2800000011920929f;
    s = 385.0f;
    s = 426.0f;
    s = 0.07999999821186066f;
    s = 474.0f;
    s = 361.0f;
    s = 65.0f;
    s = 479.0f;
    s = 54.0f;
    s = 481.0f;
    s = 588.0f;
    s = 592.0f;
    s = 482.0f;
}
static const u32 fzgx_pool_table139[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep139(void) { const u32 *volatile cp; cp = fzgx_pool_table139; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern u8 fn_10_13ECC__fzgx_offset_938[];
extern u8 fn_10_13ECC__fzgx_offset_940[];
extern u8 fn_10_13ECC__fzgx_offset_948[];
extern u8 fn_10_13ECC__fzgx_offset_950[];
extern u8 fn_10_13ECC__fzgx_offset_958[];
extern u8 fn_10_13ECC__fzgx_offset_960[];
extern u8 fn_10_13ECC__fzgx_offset_968[];
extern u8 fn_10_13ECC__fzgx_offset_970[];
extern u8 fn_10_13ECC__fzgx_offset_978[];
extern u8 fn_10_13ECC__fzgx_offset_980[];
extern u8 fn_10_13ECC__fzgx_offset_984[];
extern u8 lbl_10_data_1038__fzgx_offset_0[];
extern u8 lbl_10_data_103C__fzgx_offset_0[];
extern u8 lbl_10_data_10D0__fzgx_offset_0[];
extern u8 lbl_10_data_10F8__fzgx_offset_0[];
extern u8 lbl_10_data_1128__fzgx_offset_0[];
extern u8 lbl_10_data_1158__fzgx_offset_0[];
extern u8 lbl_10_data_1180__fzgx_offset_0[];
extern u8 lbl_10_data_11B8__fzgx_offset_0[];
extern u8 lbl_10_data_11CC__fzgx_offset_0[];
extern u8 lbl_10_data_11E8__fzgx_offset_0[];
extern u8 lbl_10_data_11F8__fzgx_offset_0[];
extern u8 lbl_10_data_1214__fzgx_offset_0[];
extern u8 lbl_10_data_1228__fzgx_offset_0[];
extern u8 lbl_10_data_1244__fzgx_offset_0[];
extern u8 lbl_10_data_1260__fzgx_offset_0[];
extern u8 lbl_10_data_1290__fzgx_offset_0[];
extern u8 lbl_10_data_12A8__fzgx_offset_0[];
extern u8 lbl_10_data_12C4__fzgx_offset_0[];
extern u8 lbl_10_data_1320__fzgx_offset_0[];
extern u8 lbl_10_data_1380__fzgx_offset_0[];
extern u8 lbl_10_data_13D0__fzgx_offset_0[];
extern u8 lbl_10_data_1418__fzgx_offset_0[];
extern u8 lbl_10_data_1424__fzgx_offset_0[];
extern u8 lbl_10_data_143C__fzgx_offset_0[];
extern u8 lbl_10_data_1464__fzgx_offset_0[];
extern u8 lbl_10_data_1490__fzgx_offset_0[];
extern u8 lbl_10_data_14B0__fzgx_offset_0[];
extern u8 lbl_10_data_14CC__fzgx_offset_0[];
extern u8 lbl_10_data_14E0__fzgx_offset_0[];
extern u8 lbl_10_data_14FC__fzgx_offset_0[];
extern u8 lbl_10_data_1514__fzgx_offset_0[];
extern u8 lbl_10_data_152C__fzgx_offset_0[];
extern u8 lbl_10_data_1538__fzgx_offset_0[];
extern u8 lbl_10_data_1548__fzgx_offset_0[];
extern u8 lbl_10_data_155C__fzgx_offset_0[];
extern u8 lbl_10_data_1574__fzgx_offset_0[];
extern u8 lbl_10_data_15C8__fzgx_offset_0[];
extern u8 lbl_10_data_161C__fzgx_offset_0[];
extern u8 lbl_10_data_16D0__fzgx_offset_0[];
extern u8 lbl_10_data_17A0__fzgx_offset_0[];
extern u8 lbl_10_data_1804__fzgx_offset_0[];
extern u8 lbl_10_data_1888__fzgx_offset_0[];
extern u8 lbl_10_data_18C0__fzgx_offset_0[];
extern u8 lbl_10_data_1908__fzgx_offset_0[];
extern u8 lbl_10_data_1958__fzgx_offset_0[];
extern u8 lbl_10_data_19B8__fzgx_offset_0[];
extern u8 lbl_10_data_19C0__fzgx_offset_0[];
extern u8 lbl_10_data_19E8__fzgx_offset_0[];
extern u8 lbl_10_data_1A0C__fzgx_offset_0[];
extern u8 lbl_10_data_1A18__fzgx_offset_0[];
extern u8 lbl_10_data_1A24__fzgx_offset_0[];
extern u8 lbl_10_data_1A2C__fzgx_offset_0[];
extern u8 lbl_10_data_1A58__fzgx_offset_0[];
extern u8 lbl_10_data_1A88__fzgx_offset_0[];
extern u8 lbl_10_data_1AB8__fzgx_offset_0[];
extern u8 lbl_10_data_1AE8__fzgx_offset_0[];
extern u8 lbl_10_data_1B18__fzgx_offset_0[];
extern u8 lbl_10_data_1B48__fzgx_offset_0[];
extern u8 lbl_10_data_1B5C__fzgx_offset_0[];
extern u8 lbl_10_data_1B74__fzgx_offset_0[];
extern u8 lbl_10_data_1B8C__fzgx_offset_0[];
extern u8 lbl_10_data_1BA4__fzgx_offset_0[];
extern u8 lbl_10_data_1BBC__fzgx_offset_0[];
extern u8 lbl_10_data_1BD4__fzgx_offset_0[];
extern u8 lbl_10_data_1BEC__fzgx_offset_0[];
extern u8 lbl_10_data_1C08__fzgx_offset_0[];
extern u8 lbl_10_data_1C24__fzgx_offset_0[];
extern u8 lbl_10_data_1C40__fzgx_offset_0[];
extern u8 lbl_10_data_1C5C__fzgx_offset_0[];
extern u8 lbl_10_data_1C70__fzgx_offset_0[];
extern u8 lbl_10_data_1C94__fzgx_offset_0[];
extern u8 lbl_10_data_1CBC__fzgx_offset_0[];
extern u8 lbl_10_data_1CE4__fzgx_offset_0[];
extern u8 lbl_10_data_1D0C__fzgx_offset_0[];
extern u8 lbl_10_data_1D34__fzgx_offset_0[];
extern u8 lbl_10_data_1D54__fzgx_offset_0[];
extern u8 lbl_10_data_1D5C__fzgx_offset_0[];
extern u8 lbl_10_data_1D68__fzgx_offset_0[];
extern u8 lbl_10_data_1D74__fzgx_offset_0[];
extern u8 lbl_10_data_1D80__fzgx_offset_0[];
extern u8 lbl_10_data_1D8C__fzgx_offset_0[];
extern u8 lbl_10_data_1D98__fzgx_offset_0[];
extern u8 lbl_10_data_1DA0__fzgx_offset_0[];
extern u8 lbl_10_data_1DAC__fzgx_offset_0[];
extern u8 lbl_10_data_1DB8__fzgx_offset_0[];
extern u8 lbl_10_data_1DC4__fzgx_offset_0[];
extern u8 lbl_10_data_1DD0__fzgx_offset_0[];
extern u8 lbl_10_data_1DDC__fzgx_offset_0[];
extern u8 lbl_10_data_1DF4__fzgx_offset_0[];
extern u8 lbl_10_data_1E10__fzgx_offset_0[];
extern u8 lbl_10_data_1E2C__fzgx_offset_0[];
extern u8 lbl_10_data_1E48__fzgx_offset_0[];
extern u8 lbl_10_data_1E64__fzgx_offset_0[];
extern u8 lbl_10_data_2288__fzgx_offset_0[];
extern u8 lbl_10_data_2294__fzgx_offset_0[];
extern u8 lbl_10_data_22A4__fzgx_offset_0[];
extern u8 lbl_10_data_22B4__fzgx_offset_0[];
extern u8 lbl_10_data_22C4__fzgx_offset_0[];
extern u8 lbl_10_data_22D4__fzgx_offset_0[];
extern u8 lbl_10_data_22E4__fzgx_offset_0[];
extern u8 lbl_10_data_22F0__fzgx_offset_0[];
extern u8 lbl_10_data_2300__fzgx_offset_0[];
extern u8 lbl_10_data_2310__fzgx_offset_0[];
extern u8 lbl_10_data_2320__fzgx_offset_0[];
extern u8 lbl_10_data_2330__fzgx_offset_0[];
extern u8 lbl_10_data_233C__fzgx_offset_0[];
extern u8 lbl_10_data_2348__fzgx_offset_0[];
extern u8 lbl_10_data_2358__fzgx_offset_0[];
extern u8 lbl_10_data_2368__fzgx_offset_0[];
extern u8 lbl_10_data_2378__fzgx_offset_0[];
extern u8 lbl_10_data_2388__fzgx_offset_0[];
extern u8 lbl_10_data_2394__fzgx_offset_0[];
extern u8 lbl_10_data_23A0__fzgx_offset_0[];
extern u8 lbl_10_data_23B0__fzgx_offset_0[];
extern u8 lbl_10_data_23C0__fzgx_offset_0[];
extern u8 lbl_10_data_23D0__fzgx_offset_0[];
extern u8 lbl_10_data_23E0__fzgx_offset_0[];
extern u8 lbl_10_data_23F0__fzgx_offset_0[];
extern u8 lbl_10_data_23FC__fzgx_offset_0[];
extern u8 lbl_10_data_240C__fzgx_offset_0[];
extern u8 lbl_10_data_241C__fzgx_offset_0[];
extern u8 lbl_10_data_242C__fzgx_offset_0[];
extern u8 lbl_10_data_243C__fzgx_offset_0[];
extern u8 lbl_10_data_244C__fzgx_offset_0[];
extern u8 lbl_10_data_2454__fzgx_offset_0[];
extern u8 lbl_10_data_2460__fzgx_offset_0[];
extern u8 lbl_10_data_246C__fzgx_offset_0[];
extern u8 lbl_10_data_2478__fzgx_offset_0[];
extern u8 lbl_10_data_2484__fzgx_offset_0[];
extern u8 lbl_10_data_2490__fzgx_offset_0[];
extern u8 lbl_10_data_249C__fzgx_offset_0[];
extern u8 lbl_10_data_24AC__fzgx_offset_0[];
extern u8 lbl_10_data_24BC__fzgx_offset_0[];
extern u8 lbl_10_data_24CC__fzgx_offset_0[];
extern u8 lbl_10_data_24DC__fzgx_offset_0[];
extern u8 lbl_10_data_24EC__fzgx_offset_0[];
extern u8 lbl_10_data_24F4__fzgx_offset_0[];
extern u8 lbl_10_data_2500__fzgx_offset_0[];
extern u8 lbl_10_data_250C__fzgx_offset_0[];
extern u8 lbl_10_data_2518__fzgx_offset_0[];
extern u8 lbl_10_data_2524__fzgx_offset_0[];
extern u8 lbl_10_data_2530__fzgx_offset_0[];
extern u8 lbl_10_data_2538__fzgx_offset_0[];
extern u8 lbl_10_data_2544__fzgx_offset_0[];
extern u8 lbl_10_data_2550__fzgx_offset_0[];
extern u8 lbl_10_data_255C__fzgx_offset_0[];
extern u8 lbl_10_data_2568__fzgx_offset_0[];
extern u8 lbl_10_data_2574__fzgx_offset_0[];
extern u8 lbl_10_data_2584__fzgx_offset_0[];
extern u8 lbl_10_data_2598__fzgx_offset_0[];
extern u8 lbl_10_data_25AC__fzgx_offset_0[];
extern u8 lbl_10_data_25C0__fzgx_offset_0[];
extern u8 lbl_10_data_25D4__fzgx_offset_0[];
extern u8 lbl_10_data_25E4__fzgx_offset_0[];
extern u8 lbl_10_data_25F0__fzgx_offset_0[];
extern u8 lbl_10_data_2600__fzgx_offset_0[];
extern u8 lbl_10_data_2614__fzgx_offset_0[];
extern u8 lbl_10_data_262C__fzgx_offset_0[];
extern u8 lbl_10_data_2638__fzgx_offset_0[];
extern u8 lbl_10_data_2648__fzgx_offset_0[];
extern u8 lbl_10_data_2654__fzgx_offset_0[];
extern u8 lbl_10_data_2664__fzgx_offset_0[];
extern u8 lbl_10_data_2674__fzgx_offset_0[];
extern u8 lbl_10_data_2684__fzgx_offset_0[];
extern u8 lbl_10_data_2694__fzgx_offset_0[];
extern u8 lbl_10_data_26A4__fzgx_offset_0[];
extern u8 lbl_10_data_26AC__fzgx_offset_0[];
extern u8 lbl_10_data_26B8__fzgx_offset_0[];
extern u8 lbl_10_data_26C4__fzgx_offset_0[];
extern u8 lbl_10_data_26D0__fzgx_offset_0[];
extern u8 lbl_10_data_26DC__fzgx_offset_0[];
extern u8 lbl_10_data_26EC__fzgx_offset_0[];
extern u8 lbl_10_data_26F4__fzgx_offset_0[];
extern u8 lbl_10_data_2700__fzgx_offset_0[];
extern u8 lbl_10_data_270C__fzgx_offset_0[];
extern u8 lbl_10_data_2718__fzgx_offset_0[];
extern u8 lbl_10_data_2724__fzgx_offset_0[];
extern u8 lbl_10_data_2730__fzgx_offset_0[];
extern u8 lbl_10_data_273C__fzgx_offset_0[];
extern u8 lbl_10_data_274C__fzgx_offset_0[];
extern u8 lbl_10_data_275C__fzgx_offset_0[];
extern u8 lbl_10_data_276C__fzgx_offset_0[];
extern u8 lbl_10_data_277C__fzgx_offset_0[];
extern u8 lbl_10_data_278C__fzgx_offset_0[];
extern u8 lbl_10_data_2794__fzgx_offset_0[];
extern u8 lbl_10_data_27A0__fzgx_offset_0[];
extern u8 lbl_10_data_27AC__fzgx_offset_0[];
extern u8 lbl_10_data_27B8__fzgx_offset_0[];
extern u8 lbl_10_data_27C4__fzgx_offset_0[];
extern u8 lbl_10_data_27D4__fzgx_offset_0[];
extern u8 lbl_10_data_27DC__fzgx_offset_0[];
extern u8 lbl_10_data_27E8__fzgx_offset_0[];
extern u8 lbl_10_data_27F4__fzgx_offset_0[];
extern u8 lbl_10_data_2800__fzgx_offset_0[];
extern u8 lbl_10_data_280C__fzgx_offset_0[];
extern u8 lbl_10_data_2818__fzgx_offset_0[];
extern u8 lbl_10_data_2824__fzgx_offset_0[];
extern u8 lbl_10_data_2834__fzgx_offset_0[];
extern u8 lbl_10_data_2844__fzgx_offset_0[];
extern u8 lbl_10_data_2854__fzgx_offset_0[];
extern u8 lbl_10_data_2864__fzgx_offset_0[];
extern u8 lbl_10_data_2870__fzgx_offset_0[];
extern u8 lbl_10_data_2880__fzgx_offset_0[];
extern u8 lbl_10_data_2894__fzgx_offset_0[];
extern u8 lbl_10_data_28A8__fzgx_offset_0[];
extern u8 lbl_10_data_28BC__fzgx_offset_0[];
extern u8 lbl_10_data_28D0__fzgx_offset_0[];
extern u8 lbl_10_data_28E0__fzgx_offset_0[];
extern u8 lbl_10_data_28E8__fzgx_offset_0[];
extern u8 lbl_10_data_28F4__fzgx_offset_0[];
extern u8 lbl_10_data_2900__fzgx_offset_0[];
extern u8 lbl_10_data_290C__fzgx_offset_0[];
extern u8 lbl_10_data_2918__fzgx_offset_0[];
extern u8 lbl_10_data_292C__fzgx_offset_0[];
extern u8 lbl_10_data_2938__fzgx_offset_0[];
extern u8 lbl_10_data_2948__fzgx_offset_0[];
extern u8 lbl_10_data_2958__fzgx_offset_0[];
extern u8 lbl_10_data_2968__fzgx_offset_0[];
extern u8 lbl_10_data_2978__fzgx_offset_0[];
extern u8 lbl_10_data_2988__fzgx_offset_0[];
extern u8 lbl_10_data_2998__fzgx_offset_0[];
extern u8 lbl_10_data_29AC__fzgx_offset_0[];
extern u8 lbl_10_data_29C0__fzgx_offset_0[];
extern u8 lbl_10_data_29D4__fzgx_offset_0[];
extern u8 lbl_10_data_29E8__fzgx_offset_0[];
extern u8 lbl_10_data_29FC__fzgx_offset_0[];
extern u8 lbl_10_data_2A08__fzgx_offset_0[];
extern u8 lbl_10_data_2A18__fzgx_offset_0[];
extern u8 lbl_10_data_2A28__fzgx_offset_0[];
extern u8 lbl_10_data_2A38__fzgx_offset_0[];
extern u8 lbl_10_data_2A48__fzgx_offset_0[];
extern u8 lbl_10_data_2A5C__fzgx_offset_0[];
extern u8 lbl_10_data_2A68__fzgx_offset_0[];
extern u8 lbl_10_data_2A78__fzgx_offset_0[];
extern u8 lbl_10_data_2A88__fzgx_offset_0[];
extern u8 lbl_10_data_2A98__fzgx_offset_0[];
extern u8 lbl_10_data_2AA8__fzgx_offset_0[];
extern u8 lbl_10_data_2ABC__fzgx_offset_0[];
extern u8 lbl_10_data_2AC4__fzgx_offset_0[];
extern u8 lbl_10_data_2ACC__fzgx_offset_0[];
extern u8 lbl_10_data_2AD4__fzgx_offset_0[];
extern u8 lbl_10_data_2ADC__fzgx_offset_0[];
extern u8 lbl_10_data_2AE4__fzgx_offset_0[];
extern u8 lbl_10_data_2AF0__fzgx_offset_0[];
extern u8 lbl_10_data_2AF8__fzgx_offset_0[];
extern u8 lbl_10_data_2B04__fzgx_offset_0[];
extern u8 lbl_10_data_2B10__fzgx_offset_0[];
extern u8 lbl_10_data_2B1C__fzgx_offset_0[];
extern u8 lbl_10_data_2B28__fzgx_offset_0[];
extern u8 lbl_10_data_2B3C__fzgx_offset_0[];
extern u8 lbl_10_data_2B50__fzgx_offset_0[];
extern u8 lbl_10_data_2B54__fzgx_offset_0[];
extern u8 lbl_10_data_2B5C__fzgx_offset_0[];
extern u8 lbl_10_data_2B64__fzgx_offset_0[];
extern u8 lbl_10_data_2B6C__fzgx_offset_0[];
extern u8 lbl_10_data_2B74__fzgx_offset_0[];
extern u8 lbl_10_data_2B88__fzgx_offset_0[];
extern u8 lbl_10_data_2B90__fzgx_offset_0[];
extern u8 lbl_10_data_2B9C__fzgx_offset_0[];
extern u8 lbl_10_data_2BA8__fzgx_offset_0[];
extern u8 lbl_10_data_2BB4__fzgx_offset_0[];
extern u8 lbl_10_data_2BC0__fzgx_offset_0[];
extern u8 lbl_10_data_2BCC__fzgx_offset_0[];
extern u8 lbl_10_data_2BD4__fzgx_offset_0[];
extern u8 lbl_10_data_2BE8__fzgx_offset_0[];
extern u8 lbl_10_data_2BF0__fzgx_offset_0[];
extern u8 lbl_10_data_2BF8__fzgx_offset_0[];
extern u8 lbl_10_data_2C08__fzgx_offset_0[];
extern u8 lbl_10_data_2C1C__fzgx_offset_0[];
extern u8 lbl_10_data_2C30__fzgx_offset_0[];
extern u8 lbl_10_data_2C44__fzgx_offset_0[];
extern u8 lbl_10_data_2C58__fzgx_offset_0[];
extern u8 lbl_10_data_2C68__fzgx_offset_0[];
extern u8 lbl_10_data_2C78__fzgx_offset_0[];
extern u8 lbl_10_data_2C8C__fzgx_offset_0[];
extern u8 lbl_10_data_2CA0__fzgx_offset_0[];
extern u8 lbl_10_data_2CB4__fzgx_offset_0[];
extern u8 lbl_10_data_2CC8__fzgx_offset_0[];
extern u8 lbl_10_data_3064__fzgx_offset_0[];
extern u8 lbl_10_data_30B0__fzgx_offset_0[];
extern u8 lbl_10_data_30C0__fzgx_offset_0[];
extern u8 lbl_10_data_30D0__fzgx_offset_0[];
extern u8 lbl_10_data_30E0__fzgx_offset_0[];
extern u8 lbl_10_data_30F0__fzgx_offset_0[];
extern u8 lbl_10_data_3148__fzgx_offset_0[];
extern u8 lbl_10_data_317C__fzgx_offset_0[];
extern u8 lbl_10_data_318C__fzgx_offset_0[];
extern u8 lbl_10_data_319C__fzgx_offset_0[];
extern u8 lbl_10_data_31AC__fzgx_offset_0[];
extern u8 lbl_10_data_31BC__fzgx_offset_0[];
extern u8 lbl_10_data_31F8__fzgx_offset_0[];
extern u8 lbl_10_data_3260__fzgx_offset_0[];
extern u8 lbl_10_data_326C__fzgx_offset_0[];
extern u8 lbl_10_data_3278__fzgx_offset_0[];
extern u8 lbl_10_data_3284__fzgx_offset_0[];
extern u8 lbl_10_data_3290__fzgx_offset_0[];
extern u8 lbl_10_data_330C__fzgx_offset_0[];
extern u8 lbl_10_data_3374__fzgx_offset_0[];
extern u8 lbl_10_data_3384__fzgx_offset_0[];
extern u8 lbl_10_data_3394__fzgx_offset_0[];
extern u8 lbl_10_data_33A4__fzgx_offset_0[];
extern u8 lbl_10_data_33B4__fzgx_offset_0[];
extern u8 lbl_10_data_3430__fzgx_offset_0[];
extern u8 lbl_10_data_34B8__fzgx_offset_0[];
extern u8 lbl_10_data_34C8__fzgx_offset_0[];
extern u8 lbl_10_data_34D8__fzgx_offset_0[];
extern u8 lbl_10_data_34E8__fzgx_offset_0[];
extern u8 lbl_10_data_34F8__fzgx_offset_0[];
extern u8 lbl_10_data_357C__fzgx_offset_0[];
extern u8 lbl_10_data_35F0__fzgx_offset_0[];
extern u8 lbl_10_data_3600__fzgx_offset_0[];
extern u8 lbl_10_data_3610__fzgx_offset_0[];
extern u8 lbl_10_data_3620__fzgx_offset_0[];
extern u8 lbl_10_data_3630__fzgx_offset_0[];
extern u8 lbl_10_data_36B8__fzgx_offset_0[];
extern u8 lbl_10_data_3700__fzgx_offset_0[];
extern u8 lbl_10_data_3710__fzgx_offset_0[];
extern u8 lbl_10_data_3720__fzgx_offset_0[];
extern u8 lbl_10_data_3730__fzgx_offset_0[];
extern u8 lbl_10_data_3740__fzgx_offset_0[];
extern u8 lbl_10_data_3788__fzgx_offset_0[];
extern u8 lbl_10_data_37AC__fzgx_offset_0[];
extern u8 lbl_10_data_37C0__fzgx_offset_0[];
extern u8 lbl_10_data_37D4__fzgx_offset_0[];
extern u8 lbl_10_data_37E8__fzgx_offset_0[];
extern u8 lbl_10_data_37FC__fzgx_offset_0[];
extern u8 lbl_10_data_3824__fzgx_offset_0[];
extern u8 lbl_10_data_38D0__fzgx_offset_0[];
extern u8 lbl_10_data_38E4__fzgx_offset_0[];
extern u8 lbl_10_data_38F8__fzgx_offset_0[];
extern u8 lbl_10_data_390C__fzgx_offset_0[];
extern u8 lbl_10_data_3920__fzgx_offset_0[];
extern u8 lbl_10_data_39CC__fzgx_offset_0[];
extern u8 lbl_10_data_39D8__fzgx_offset_0[];
extern u8 lbl_10_data_39E8__fzgx_offset_0[];
extern u8 lbl_10_data_39F8__fzgx_offset_0[];
extern u8 lbl_10_data_3A08__fzgx_offset_0[];
extern u8 lbl_10_data_3A30__fzgx_offset_0[];
extern u8 lbl_10_data_3A84__fzgx_offset_0[];
extern u8 lbl_10_data_3A98__fzgx_offset_0[];
extern u8 lbl_10_data_3AAC__fzgx_offset_0[];
extern u8 lbl_10_data_3AC0__fzgx_offset_0[];
extern u8 lbl_10_data_3AD4__fzgx_offset_0[];
extern u8 lbl_10_data_3B24__fzgx_offset_0[];
extern u8 lbl_10_data_3BD0__fzgx_offset_0[];
extern u8 lbl_10_data_3BE8__fzgx_offset_0[];
extern u8 lbl_10_data_3C00__fzgx_offset_0[];
extern u8 lbl_10_data_3C18__fzgx_offset_0[];
extern u8 lbl_10_data_3C30__fzgx_offset_0[];
extern u8 lbl_10_data_3CB4__fzgx_offset_0[];
extern u8 lbl_10_data_3D00__fzgx_offset_0[];
extern u8 lbl_10_data_3D10__fzgx_offset_0[];
extern u8 lbl_10_data_3D20__fzgx_offset_0[];
extern u8 lbl_10_data_3D30__fzgx_offset_0[];
extern u8 lbl_10_data_3D40__fzgx_offset_0[];
extern u8 lbl_10_data_3D98__fzgx_offset_0[];
extern u8 lbl_10_data_3DC0__fzgx_offset_0[];
extern u8 lbl_10_data_3DCC__fzgx_offset_0[];
extern u8 lbl_10_data_3DD8__fzgx_offset_0[];
extern u8 lbl_10_data_3DE4__fzgx_offset_0[];
extern u8 lbl_10_data_3DF0__fzgx_offset_0[];
extern u8 lbl_10_data_3E1C__fzgx_offset_0[];
extern u8 lbl_10_data_3E64__fzgx_offset_0[];
extern u8 lbl_10_data_3E74__fzgx_offset_0[];
extern u8 lbl_10_data_3E84__fzgx_offset_0[];
extern u8 lbl_10_data_3E94__fzgx_offset_0[];
extern u8 lbl_10_data_3EA4__fzgx_offset_0[];
extern u8 lbl_10_data_3F00__fzgx_offset_0[];
extern u8 lbl_10_data_3F68__fzgx_offset_0[];
extern u8 lbl_10_data_3F7C__fzgx_offset_0[];
extern u8 lbl_10_data_3F90__fzgx_offset_0[];
extern u8 lbl_10_data_3FA4__fzgx_offset_0[];
extern u8 lbl_10_data_3FB8__fzgx_offset_0[];
extern u8 lbl_10_data_4040__fzgx_offset_0[];
extern u8 lbl_10_data_408C__fzgx_offset_0[];
extern u8 lbl_10_data_40A4__fzgx_offset_0[];
extern u8 lbl_10_data_40BC__fzgx_offset_0[];
extern u8 lbl_10_data_40D4__fzgx_offset_0[];
extern u8 lbl_10_data_40EC__fzgx_offset_0[];
extern u8 lbl_10_data_4124__fzgx_offset_0[];
extern u8 lbl_10_data_4178__fzgx_offset_0[];
extern u8 lbl_10_data_4184__fzgx_offset_0[];
extern u8 lbl_10_data_4190__fzgx_offset_0[];
extern u8 lbl_10_data_419C__fzgx_offset_0[];
extern u8 lbl_10_data_41A8__fzgx_offset_0[];
extern u8 lbl_10_data_4200__fzgx_offset_0[];
extern u8 lbl_10_data_42E8__fzgx_offset_0[];
extern u8 lbl_10_data_42F4__fzgx_offset_0[];
extern u8 lbl_10_data_4300__fzgx_offset_0[];
extern u8 lbl_10_data_430C__fzgx_offset_0[];
extern u8 lbl_10_data_4318__fzgx_offset_0[];
extern u8 lbl_10_data_43DC__fzgx_offset_0[];
extern u8 lbl_10_data_441C__fzgx_offset_0[];
extern u8 lbl_10_data_442C__fzgx_offset_0[];
extern u8 lbl_10_data_443C__fzgx_offset_0[];
extern u8 lbl_10_data_444C__fzgx_offset_0[];
extern u8 lbl_10_data_445C__fzgx_offset_0[];
extern u8 lbl_10_data_44B4__fzgx_offset_0[];
extern u8 lbl_10_data_44E0__fzgx_offset_0[];
extern u8 lbl_10_data_44F4__fzgx_offset_0[];
extern u8 lbl_10_data_4508__fzgx_offset_0[];
extern u8 lbl_10_data_451C__fzgx_offset_0[];
extern u8 lbl_10_data_4530__fzgx_offset_0[];
extern u8 lbl_10_data_4554__fzgx_offset_0[];
extern u8 lbl_10_data_45AC__fzgx_offset_0[];
extern u8 lbl_10_data_45BC__fzgx_offset_0[];
extern u8 lbl_10_data_45CC__fzgx_offset_0[];
extern u8 lbl_10_data_45DC__fzgx_offset_0[];
extern u8 lbl_10_data_45EC__fzgx_offset_0[];
extern u8 lbl_10_data_463C__fzgx_offset_0[];
extern u8 lbl_10_data_4668__fzgx_offset_0[];
extern u8 lbl_10_data_4678__fzgx_offset_0[];
extern u8 lbl_10_data_4688__fzgx_offset_0[];
extern u8 lbl_10_data_4698__fzgx_offset_0[];
extern u8 lbl_10_data_46A8__fzgx_offset_0[];
extern u8 lbl_10_data_46FC__fzgx_offset_0[];
extern u8 lbl_10_data_472C__fzgx_offset_0[];
extern u8 lbl_10_data_4740__fzgx_offset_0[];
extern u8 lbl_10_data_4754__fzgx_offset_0[];
extern u8 lbl_10_data_4768__fzgx_offset_0[];
extern u8 lbl_10_data_477C__fzgx_offset_0[];
extern u8 lbl_10_data_47C4__fzgx_offset_0[];
extern u8 lbl_10_data_4810__fzgx_offset_0[];
extern u8 lbl_10_data_482C__fzgx_offset_0[];
extern u8 lbl_10_data_4848__fzgx_offset_0[];
extern u8 lbl_10_data_4864__fzgx_offset_0[];
extern u8 lbl_10_data_4880__fzgx_offset_0[];
extern u8 lbl_10_data_48C8__fzgx_offset_0[];
extern u8 lbl_10_data_48DC__fzgx_offset_0[];
extern u8 lbl_10_data_48F0__fzgx_offset_0[];
extern u8 lbl_10_data_4904__fzgx_offset_0[];
extern u8 lbl_10_data_4918__fzgx_offset_0[];
extern u8 lbl_10_data_492C__fzgx_offset_0[];
extern u8 lbl_10_data_4948__fzgx_offset_0[];
extern u8 lbl_10_data_4964__fzgx_offset_0[];
extern u8 lbl_10_data_4978__fzgx_offset_0[];
extern u8 lbl_10_data_498C__fzgx_offset_0[];
extern u8 lbl_10_data_49A0__fzgx_offset_0[];
extern u8 lbl_10_data_49B4__fzgx_offset_0[];
extern u8 lbl_10_data_49D0__fzgx_offset_0[];
extern u8 lbl_10_data_49E8__fzgx_offset_0[];
extern u8 lbl_10_data_4A00__fzgx_offset_0[];
extern u8 lbl_10_data_4A18__fzgx_offset_0[];
extern u8 lbl_10_data_4A30__fzgx_offset_0[];
extern u8 lbl_10_data_4A48__fzgx_offset_0[];
extern u8 lbl_10_data_4A68__fzgx_offset_0[];
extern u8 lbl_10_data_4AB4__fzgx_offset_0[];
extern u8 lbl_10_data_4DB0__fzgx_offset_0[];
extern u8 lbl_10_data_4DDC__fzgx_offset_0[];
extern u8 lbl_10_data_4DF0__fzgx_offset_0[];
extern u8 lbl_10_data_4E04__fzgx_offset_0[];
extern u8 lbl_10_data_4E18__fzgx_offset_0[];
extern u8 lbl_10_data_4E2C__fzgx_offset_0[];
extern u8 lbl_10_data_4E4C__fzgx_offset_0[];
extern u8 lbl_10_data_4E70__fzgx_offset_0[];
extern u8 lbl_10_data_4E84__fzgx_offset_0[];
extern u8 lbl_10_data_4E98__fzgx_offset_0[];
extern u8 lbl_10_data_4EAC__fzgx_offset_0[];
extern u8 lbl_10_data_4EC0__fzgx_offset_0[];
extern u8 lbl_10_data_4EF0__fzgx_offset_0[];
extern u8 lbl_10_data_4F18__fzgx_offset_0[];
extern u8 lbl_10_data_4F2C__fzgx_offset_0[];
extern u8 lbl_10_data_4F40__fzgx_offset_0[];
extern u8 lbl_10_data_4F54__fzgx_offset_0[];
extern u8 lbl_10_data_4F68__fzgx_offset_0[];
extern u8 lbl_10_data_4F88__fzgx_offset_0[];
extern u8 lbl_10_data_4FB4__fzgx_offset_0[];
extern u8 lbl_10_data_4FCC__fzgx_offset_0[];
extern u8 lbl_10_data_4FE4__fzgx_offset_0[];
extern u8 lbl_10_data_4FFC__fzgx_offset_0[];
extern u8 lbl_10_data_5014__fzgx_offset_0[];
extern u8 lbl_10_data_5038__fzgx_offset_0[];
extern u8 lbl_10_data_5064__fzgx_offset_0[];
extern u8 lbl_10_data_5074__fzgx_offset_0[];
extern u8 lbl_10_data_5084__fzgx_offset_0[];
extern u8 lbl_10_data_5094__fzgx_offset_0[];
extern u8 lbl_10_data_50A4__fzgx_offset_0[];
extern u8 lbl_10_data_50D4__fzgx_offset_0[];
extern u8 lbl_10_data_50EC__fzgx_offset_0[];
extern u8 lbl_10_data_5104__fzgx_offset_0[];
extern u8 lbl_10_data_511C__fzgx_offset_0[];
extern u8 lbl_10_data_5134__fzgx_offset_0[];
extern u8 lbl_10_data_514C__fzgx_offset_0[];
extern u8 lbl_10_data_516C__fzgx_offset_0[];
extern u8 lbl_10_data_51AC__fzgx_offset_0[];
extern u8 lbl_10_data_51C4__fzgx_offset_0[];
extern u8 lbl_10_data_51DC__fzgx_offset_0[];
extern u8 lbl_10_data_51F4__fzgx_offset_0[];
extern u8 lbl_10_data_520C__fzgx_offset_0[];
extern u8 lbl_10_data_5254__fzgx_offset_0[];
extern u8 lbl_10_data_5284__fzgx_offset_0[];
extern u8 lbl_10_data_5294__fzgx_offset_0[];
extern u8 lbl_10_data_52A4__fzgx_offset_0[];
extern u8 lbl_10_data_52B4__fzgx_offset_0[];
extern u8 lbl_10_data_52C4__fzgx_offset_0[];
extern u8 lbl_10_data_52F4__fzgx_offset_0[];
extern u8 lbl_10_data_535C__fzgx_offset_0[];
extern u8 lbl_10_data_5378__fzgx_offset_0[];
extern u8 lbl_10_data_5394__fzgx_offset_0[];
extern u8 lbl_10_data_53B0__fzgx_offset_0[];
extern u8 lbl_10_data_53CC__fzgx_offset_0[];
extern u8 lbl_10_data_541C__fzgx_offset_0[];
extern u8 lbl_10_data_5454__fzgx_offset_0[];
extern u8 lbl_10_data_5468__fzgx_offset_0[];
extern u8 lbl_10_data_547C__fzgx_offset_0[];
extern u8 lbl_10_data_5490__fzgx_offset_0[];
extern u8 lbl_10_data_54A4__fzgx_offset_0[];
extern u8 lbl_10_data_54E8__fzgx_offset_0[];
extern u8 lbl_10_data_54F4__fzgx_offset_0[];
extern u8 lbl_10_data_5504__fzgx_offset_0[];
extern u8 lbl_10_data_5514__fzgx_offset_0[];
extern u8 lbl_10_data_5524__fzgx_offset_0[];
extern u8 lbl_10_data_5534__fzgx_offset_0[];
extern u8 lbl_10_data_5540__fzgx_offset_0[];
extern u8 lbl_10_data_5560__fzgx_offset_0[];
extern u8 lbl_10_data_5570__fzgx_offset_0[];
extern u8 lbl_10_data_5580__fzgx_offset_0[];
extern u8 lbl_10_data_5590__fzgx_offset_0[];
extern u8 lbl_10_data_55A0__fzgx_offset_0[];
extern u8 lbl_10_data_55B8__fzgx_offset_0[];
extern u8 lbl_10_data_55D8__fzgx_offset_0[];
extern u8 lbl_10_data_56AC__fzgx_offset_0[];
extern u8 lbl_10_data_56C4__fzgx_offset_0[];
extern u8 lbl_10_data_56DC__fzgx_offset_0[];
extern u8 lbl_10_data_56F4__fzgx_offset_0[];
extern u8 lbl_10_data_570C__fzgx_offset_0[];
extern u8 lbl_10_data_57A0__fzgx_offset_0[];
extern u8 lbl_10_data_57F4__fzgx_offset_0[];
extern u8 lbl_10_data_5810__fzgx_offset_0[];
extern u8 lbl_10_data_582C__fzgx_offset_0[];
extern u8 lbl_10_data_5848__fzgx_offset_0[];
extern u8 lbl_10_data_5864__fzgx_offset_0[];
extern u8 lbl_10_data_589C__fzgx_offset_0[];
extern u8 lbl_10_data_590C__fzgx_offset_0[];
extern u8 lbl_10_data_5924__fzgx_offset_0[];
extern u8 lbl_10_data_593C__fzgx_offset_0[];
extern u8 lbl_10_data_5954__fzgx_offset_0[];
extern u8 lbl_10_data_596C__fzgx_offset_0[];
extern u8 lbl_10_data_59D0__fzgx_offset_0[];
extern u8 lbl_10_data_5A34__fzgx_offset_0[];
extern u8 lbl_10_data_5A48__fzgx_offset_0[];
extern u8 lbl_10_data_5A5C__fzgx_offset_0[];
extern u8 lbl_10_data_5A70__fzgx_offset_0[];
extern u8 lbl_10_data_5A84__fzgx_offset_0[];
extern u8 lbl_10_data_5AC4__fzgx_offset_0[];
extern u8 lbl_10_data_5AF0__fzgx_offset_0[];
extern u8 lbl_10_data_5B0C__fzgx_offset_0[];
extern u8 lbl_10_data_5B28__fzgx_offset_0[];
extern u8 lbl_10_data_5B44__fzgx_offset_0[];
extern u8 lbl_10_data_5B60__fzgx_offset_0[];
extern u8 lbl_10_data_5B90__fzgx_offset_0[];
extern u8 lbl_10_data_5BAC__fzgx_offset_0[];
extern u8 lbl_10_data_5BC0__fzgx_offset_0[];
extern u8 lbl_10_data_5BD4__fzgx_offset_0[];
extern u8 lbl_10_data_5BE8__fzgx_offset_0[];
extern u8 lbl_10_data_5BFC__fzgx_offset_0[];
extern u8 lbl_10_data_5DE4__fzgx_offset_0[];
extern u8 lbl_10_data_5DFC__fzgx_offset_0[];
extern u8 lbl_10_data_6188__fzgx_offset_0[];
extern u8 lbl_10_data_6194__fzgx_offset_0[];
extern u8 lbl_10_data_6238__fzgx_offset_0[];
extern u8 lbl_10_data_625C__fzgx_offset_0[];
extern u8 lbl_10_data_62A4__fzgx_offset_0[];
extern u8 lbl_10_data_62C4__fzgx_offset_0[];
extern u8 lbl_10_data_62F4__fzgx_offset_0[];
extern u8 lbl_10_data_6380__fzgx_offset_0[];
extern u8 lbl_10_data_6390__fzgx_offset_0[];
extern u8 lbl_10_data_63B4__fzgx_offset_0[];
extern u8 lbl_10_data_63C4__fzgx_offset_0[];
extern u8 lbl_10_data_63E8__fzgx_offset_0[];
extern u8 lbl_10_data_63F4__fzgx_offset_0[];
extern u8 lbl_10_data_6418__fzgx_offset_0[];
extern u8 lbl_10_data_6424__fzgx_offset_0[];
extern u8 lbl_10_data_6474__fzgx_offset_0[];
extern u8 lbl_10_data_6490__fzgx_offset_0[];
extern u8 lbl_10_data_6498__fzgx_offset_0[];
extern u8 lbl_10_data_64B4__fzgx_offset_0[];
extern u8 lbl_10_data_64BC__fzgx_offset_0[];
extern u8 lbl_10_data_6554__fzgx_offset_0[];
extern u8 lbl_10_data_6584__fzgx_offset_0[];
extern u8 lbl_10_data_65FC__fzgx_offset_0[];
extern u8 lbl_10_data_661C__fzgx_offset_0[];
extern u8 lbl_10_data_6654__fzgx_offset_0[];
extern u8 lbl_10_data_6670__fzgx_offset_0[];
extern u8 lbl_10_data_66DC__fzgx_offset_0[];
extern u8 lbl_10_data_FB4__fzgx_offset_0[];
extern u8 lbl_10_data_21B0__fzgx_offset_0[];
extern u8 lbl_10_data_21BC__fzgx_offset_0[];
extern u8 lbl_10_data_21C8__fzgx_offset_0[];
extern u8 lbl_10_data_21D4__fzgx_offset_0[];
extern u8 lbl_10_data_21E0__fzgx_offset_0[];
extern u8 lbl_10_data_21EC__fzgx_offset_0[];
extern u8 lbl_10_data_64F0__fzgx_offset_0[];
extern u8 lbl_10_data_650C__fzgx_offset_0[];
extern u8 lbl_10_data_6530__fzgx_offset_0[];
extern u8 lbl_10_data_65D4__fzgx_offset_0[];
extern u8 lbl_10_data_66A4__fzgx_offset_0[];
extern u8 lbl_10_data_D00__fzgx_offset_0[];
extern u8 lbl_10_data_D04__fzgx_offset_0[];
extern u8 lbl_10_data_D10__fzgx_offset_0[];
extern u8 lbl_10_data_D1C__fzgx_offset_0[];
extern u8 lbl_10_data_D28__fzgx_offset_0[];
extern u8 lbl_10_data_D34__fzgx_offset_0[];
extern u8 lbl_10_data_D3C__fzgx_offset_0[];
extern u8 lbl_10_data_D44__fzgx_offset_0[];
extern u8 lbl_10_data_D4C__fzgx_offset_0[];
extern u8 lbl_10_data_D54__fzgx_offset_0[];
extern u8 lbl_10_data_D60__fzgx_offset_0[];
extern u8 lbl_10_data_D70__fzgx_offset_0[];
extern u8 lbl_10_data_D80__fzgx_offset_0[];
extern u8 lbl_10_data_D88__fzgx_offset_0[];
extern u8 lbl_10_data_D90__fzgx_offset_0[];
extern u8 lbl_10_data_D9C__fzgx_offset_0[];
extern u8 lbl_10_data_DA8__fzgx_offset_0[];
extern u8 lbl_10_data_DB8__fzgx_offset_0[];
extern u8 lbl_10_data_DC0__fzgx_offset_0[];
extern u8 lbl_10_data_DCC__fzgx_offset_0[];
extern u8 lbl_10_data_DD8__fzgx_offset_0[];
extern u8 lbl_10_data_DE8__fzgx_offset_0[];
extern u8 lbl_10_data_DF0__fzgx_offset_0[];
extern u8 lbl_10_data_DFC__fzgx_offset_0[];
extern u8 lbl_10_data_E08__fzgx_offset_0[];
extern u8 lbl_10_data_E18__fzgx_offset_0[];
extern u8 lbl_10_data_E20__fzgx_offset_0[];
extern u8 lbl_10_data_E2C__fzgx_offset_0[];
extern u8 lbl_10_data_E34__fzgx_offset_0[];
extern u8 lbl_10_data_E40__fzgx_offset_0[];
extern u8 lbl_10_data_E50__fzgx_offset_0[];
extern u8 lbl_10_data_E5C__fzgx_offset_0[];
extern u8 lbl_10_data_E68__fzgx_offset_0[];
extern u8 lbl_10_data_E70__fzgx_offset_0[];
extern u8 lbl_10_data_E84__fzgx_offset_0[];
extern u8 lbl_10_data_E94__fzgx_offset_0[];
extern u8 lbl_10_data_EA4__fzgx_offset_0[];
extern u8 lbl_10_data_EB0__fzgx_offset_0[];
extern u8 lbl_10_data_EBC__fzgx_offset_0[];
extern u8 lbl_10_data_ECC__fzgx_offset_0[];
extern u8 lbl_10_data_ED4__fzgx_offset_0[];
extern u8 lbl_10_data_EE0__fzgx_offset_0[];
extern u8 lbl_10_data_EE8__fzgx_offset_0[];
extern u8 lbl_10_data_EF0__fzgx_offset_0[];
extern u8 lbl_10_data_EF8__fzgx_offset_0[];
static struct {u32 w_0[128]; void *p_200; void *p_204; void *p_208; void *p_20C; void *p_210; void *p_214; void *p_218; void *p_21C; void *p_220; void *p_224; void *p_228; void *p_22C; void *p_230; void *p_234; void *p_238; void *p_23C; void *p_240; void *p_244; void *p_248; void *p_24C; void *p_250; void *p_254; void *p_258; void *p_25C; void *p_260; void *p_264; void *p_268; void *p_26C; void *p_270; void *p_274; void *p_278; void *p_27C; void *p_280; void *p_284; void *p_288; void *p_28C; void *p_290; void *p_294; void *p_298; void *p_29C; void *p_2A0; void *p_2A4; void *p_2A8; void *p_2AC; void *p_2B0; u32 w_2B4[947]; void *p_1180; void *p_1184; void *p_1188; void *p_118C; void *p_1190; void *p_1194; void *p_1198; void *p_119C; void *p_11A0; void *p_11A4; void *p_11A8; void *p_11AC; void *p_11B0; void *p_11B4; void *p_11B8; void *p_11BC; void *p_11C0; void *p_11C4; void *p_11C8; void *p_11CC; void *p_11D0; void *p_11D4; void *p_11D8; void *p_11DC; void *p_11E0; void *p_11E4; void *p_11E8; void *p_11EC; void *p_11F0; void *p_11F4; void *p_11F8; void *p_11FC; void *p_1200; void *p_1204; void *p_1208; void *p_120C; void *p_1210; void *p_1214; void *p_1218; void *p_121C; void *p_1220; void *p_1224; void *p_1228; void *p_122C; void *p_1230; void *p_1234; void *p_1238; void *p_123C; void *p_1240; void *p_1244; void *p_1248; void *p_124C; void *p_1250; void *p_1254; void *p_1258; void *p_125C; void *p_1260; void *p_1264; void *p_1268; void *p_126C; void *p_1270; void *p_1274; void *p_1278; void *p_127C; void *p_1280; void *p_1284; void *p_1288; void *p_128C; void *p_1290; void *p_1294; void *p_1298; void *p_129C; void *p_12A0; void *p_12A4; void *p_12A8; void *p_12AC; void *p_12B0; void *p_12B4; void *p_12B8; void *p_12BC; void *p_12C0; void *p_12C4; void *p_12C8; void *p_12CC; void *p_12D0; void *p_12D4; void *p_12D8; void *p_12DC; void *p_12E0; void *p_12E4; void *p_12E8; void *p_12EC; void *p_12F0; void *p_12F4; void *p_12F8; void *p_12FC; void *p_1300; void *p_1304; void *p_1308; void *p_130C; void *p_1310; void *p_1314; void *p_1318; void *p_131C; void *p_1320; void *p_1324; void *p_1328; void *p_132C; void *p_1330; void *p_1334; void *p_1338; void *p_133C; void *p_1340; void *p_1344; void *p_1348; void *p_134C; void *p_1350; void *p_1354; void *p_1358; void *p_135C; void *p_1360; void *p_1364; void *p_1368; void *p_136C; void *p_1370; void *p_1374; void *p_1378; void *p_137C; void *p_1380; void *p_1384; void *p_1388; void *p_138C; void *p_1390; void *p_1394; void *p_1398; void *p_139C; void *p_13A0; void *p_13A4; void *p_13A8; void *p_13AC; void *p_13B0; void *p_13B4; void *p_13B8; void *p_13BC; void *p_13C0; void *p_13C4; void *p_13C8; void *p_13CC; void *p_13D0; void *p_13D4; void *p_13D8; void *p_13DC; void *p_13E0; void *p_13E4; void *p_13E8; void *p_13EC; void *p_13F0; void *p_13F4; void *p_13F8; void *p_13FC; void *p_1400; void *p_1404; void *p_1408; void *p_140C; void *p_1410; void *p_1414; void *p_1418; void *p_141C; void *p_1420; void *p_1424; void *p_1428; void *p_142C; void *p_1430; void *p_1434; void *p_1438; void *p_143C; void *p_1440; void *p_1444; void *p_1448; void *p_144C; void *p_1450; void *p_1454; void *p_1458; void *p_145C; void *p_1460; void *p_1464; void *p_1468; void *p_146C; void *p_1470; void *p_1474; void *p_1478; void *p_147C; void *p_1480; void *p_1484; void *p_1488; void *p_148C; void *p_1490; void *p_1494; void *p_1498; void *p_149C; void *p_14A0; void *p_14A4; void *p_14A8; void *p_14AC; u32 w_14B0[18]; void *p_14F8; void *p_14FC; void *p_1500; void *p_1504; void *p_1508; void *p_150C; void *p_1510; void *p_1514; void *p_1518; void *p_151C; void *p_1520; void *p_1524; void *p_1528; void *p_152C; void *p_1530; void *p_1534; void *p_1538; void *p_153C; void *p_1540; void *p_1544; void *p_1548; void *p_154C; void *p_1550; void *p_1554; void *p_1558; void *p_155C; void *p_1560; void *p_1564; void *p_1568; void *p_156C; void *p_1570; void *p_1574; void *p_1578; void *p_157C; void *p_1580; void *p_1584; u32 w_1588[661]; void *p_1FDC; void *p_1FE0; void *p_1FE4; void *p_1FE8; void *p_1FEC; void *p_1FF0; void *p_1FF4; void *p_1FF8; void *p_1FFC; void *p_2000; void *p_2004; void *p_2008; void *p_200C; void *p_2010; void *p_2014; void *p_2018; void *p_201C; void *p_2020; void *p_2024; void *p_2028; void *p_202C; void *p_2030; void *p_2034; void *p_2038; void *p_203C; void *p_2040; void *p_2044; void *p_2048; void *p_204C; void *p_2050; void *p_2054; void *p_2058; void *p_205C; void *p_2060; void *p_2064; void *p_2068; void *p_206C; void *p_2070; void *p_2074; void *p_2078; void *p_207C; void *p_2080; void *p_2084; void *p_2088; void *p_208C; void *p_2090; void *p_2094; void *p_2098; void *p_209C; void *p_20A0; void *p_20A4; void *p_20A8; void *p_20AC; void *p_20B0; void *p_20B4; void *p_20B8; void *p_20BC; void *p_20C0; void *p_20C4; void *p_20C8; void *p_20CC; void *p_20D0; void *p_20D4; void *p_20D8; void *p_20DC; void *p_20E0; void *p_20E4; void *p_20E8; void *p_20EC; void *p_20F0; void *p_20F4; void *p_20F8; void *p_20FC; void *p_2100; void *p_2104; void *p_2108; void *p_210C; void *p_2110; void *p_2114; void *p_2118; void *p_211C; void *p_2120; void *p_2124; void *p_2128; void *p_212C; void *p_2130; void *p_2134; void *p_2138; void *p_213C; void *p_2140; void *p_2144; void *p_2148; void *p_214C; void *p_2150; void *p_2154; void *p_2158; void *p_215C; void *p_2160; void *p_2164; void *p_2168; void *p_216C; void *p_2170; void *p_2174; void *p_2178; void *p_217C; void *p_2180; void *p_2184; void *p_2188; void *p_218C; void *p_2190; void *p_2194; void *p_2198; void *p_219C; void *p_21A0; void *p_21A4; void *p_21A8; void *p_21AC; void *p_21B0; void *p_21B4; void *p_21B8; void *p_21BC; void *p_21C0; void *p_21C4; void *p_21C8; void *p_21CC; void *p_21D0; void *p_21D4; void *p_21D8; void *p_21DC; void *p_21E0; void *p_21E4; void *p_21E8; void *p_21EC; void *p_21F0; void *p_21F4; void *p_21F8; void *p_21FC; void *p_2200; void *p_2204; void *p_2208; void *p_220C; void *p_2210; void *p_2214; void *p_2218; void *p_221C; void *p_2220; void *p_2224; void *p_2228; void *p_222C; void *p_2230; void *p_2234; void *p_2238; void *p_223C; void *p_2240; void *p_2244; void *p_2248; void *p_224C; void *p_2250; void *p_2254; void *p_2258; void *p_225C; void *p_2260; void *p_2264; void *p_2268; void *p_226C; void *p_2270; void *p_2274; void *p_2278; void *p_227C; void *p_2280; void *p_2284; void *p_2288; void *p_228C; void *p_2290; void *p_2294; void *p_2298; void *p_229C; void *p_22A0; void *p_22A4; void *p_22A8; void *p_22AC; void *p_22B0; void *p_22B4; void *p_22B8; void *p_22BC; void *p_22C0; void *p_22C4; void *p_22C8; void *p_22CC; void *p_22D0; void *p_22D4; void *p_22D8; void *p_22DC; void *p_22E0; void *p_22E4; void *p_22E8; void *p_22EC; void *p_22F0; void *p_22F4; void *p_22F8; void *p_22FC; void *p_2300; void *p_2304; void *p_2308; void *p_230C; void *p_2310; void *p_2314; void *p_2318; void *p_231C; void *p_2320; void *p_2324; void *p_2328; void *p_232C; void *p_2330; void *p_2334; void *p_2338; void *p_233C; void *p_2340; void *p_2344; void *p_2348; void *p_234C; void *p_2350; u32 w_2354[1705]; void *p_3DF8; void *p_3DFC; void *p_3E00; void *p_3E04; void *p_3E08; void *p_3E0C; void *p_3E10; void *p_3E14; void *p_3E18; void *p_3E1C; void *p_3E20; void *p_3E24; void *p_3E28; void *p_3E2C; void *p_3E30; void *p_3E34; void *p_3E38; void *p_3E3C; void *p_3E40; void *p_3E44; void *p_3E48; void *p_3E4C; void *p_3E50; void *p_3E54; void *p_3E58; void *p_3E5C; void *p_3E60; void *p_3E64; void *p_3E68; void *p_3E6C; void *p_3E70; void *p_3E74; void *p_3E78; void *p_3E7C; void *p_3E80; void *p_3E84; void *p_3E88; void *p_3E8C; void *p_3E90; void *p_3E94; void *p_3E98; void *p_3E9C; void *p_3EA0; void *p_3EA4; void *p_3EA8; void *p_3EAC; void *p_3EB0; void *p_3EB4; void *p_3EB8; void *p_3EBC; void *p_3EC0; void *p_3EC4; void *p_3EC8; void *p_3ECC; void *p_3ED0; void *p_3ED4; void *p_3ED8; void *p_3EDC; void *p_3EE0; void *p_3EE4; void *p_3EE8; void *p_3EEC; void *p_3EF0; void *p_3EF4; void *p_3EF8; void *p_3EFC; void *p_3F00; void *p_3F04; void *p_3F08; void *p_3F0C; void *p_3F10; void *p_3F14; void *p_3F18; void *p_3F1C; void *p_3F20; void *p_3F24; void *p_3F28; void *p_3F2C; void *p_3F30; void *p_3F34; void *p_3F38; void *p_3F3C; void *p_3F40; void *p_3F44; void *p_3F48; void *p_3F4C; void *p_3F50; void *p_3F54; void *p_3F58; void *p_3F5C; void *p_3F60; void *p_3F64; void *p_3F68; void *p_3F6C; void *p_3F70; void *p_3F74; void *p_3F78; void *p_3F7C; void *p_3F80; void *p_3F84; void *p_3F88; void *p_3F8C; void *p_3F90; void *p_3F94; void *p_3F98; void *p_3F9C; void *p_3FA0; void *p_3FA4; void *p_3FA8; void *p_3FAC; void *p_3FB0; void *p_3FB4; void *p_3FB8; void *p_3FBC; void *p_3FC0; void *p_3FC4; void *p_3FC8; void *p_3FCC; void *p_3FD0; void *p_3FD4; void *p_3FD8; void *p_3FDC; void *p_3FE0; void *p_3FE4; void *p_3FE8; void *p_3FEC; void *p_3FF0; void *p_3FF4; void *p_3FF8; void *p_3FFC; void *p_4000; void *p_4004; void *p_4008; void *p_400C; void *p_4010; void *p_4014; void *p_4018; void *p_401C; void *p_4020; void *p_4024; void *p_4028; void *p_402C; void *p_4030; void *p_4034; void *p_4038; void *p_403C; void *p_4040; void *p_4044; void *p_4048; void *p_404C; void *p_4050; void *p_4054; void *p_4058; void *p_405C; void *p_4060; void *p_4064; void *p_4068; void *p_406C; void *p_4070; void *p_4074; void *p_4078; void *p_407C; void *p_4080; void *p_4084; void *p_4088; void *p_408C; void *p_4090; void *p_4094; void *p_4098; void *p_409C; void *p_40A0; void *p_40A4; void *p_40A8; void *p_40AC; u32 w_40B0[923]; void *p_4F1C; void *p_4F20; void *p_4F24; void *p_4F28; void *p_4F2C; void *p_4F30; void *p_4F34; void *p_4F38; void *p_4F3C; void *p_4F40; void *p_4F44; void *p_4F48; void *p_4F4C; void *p_4F50; void *p_4F54; void *p_4F58; void *p_4F5C; void *p_4F60; void *p_4F64; void *p_4F68; void *p_4F6C; void *p_4F70; void *p_4F74; void *p_4F78; void *p_4F7C; void *p_4F80; void *p_4F84; void *p_4F88; void *p_4F8C; void *p_4F90; void *p_4F94; void *p_4F98; void *p_4F9C; void *p_4FA0; void *p_4FA4; void *p_4FA8; void *p_4FAC; void *p_4FB0; void *p_4FB4; void *p_4FB8; void *p_4FBC; void *p_4FC0; void *p_4FC4; void *p_4FC8; void *p_4FCC; void *p_4FD0; void *p_4FD4; void *p_4FD8; void *p_4FDC; void *p_4FE0; void *p_4FE4; void *p_4FE8; void *p_4FEC; void *p_4FF0; void *p_4FF4; void *p_4FF8; void *p_4FFC; void *p_5000; void *p_5004; void *p_5008; void *p_500C; void *p_5010; void *p_5014; void *p_5018; void *p_501C; void *p_5020; void *p_5024; void *p_5028; void *p_502C; void *p_5030; void *p_5034; void *p_5038; void *p_503C; void *p_5040; void *p_5044; void *p_5048; void *p_504C; void *p_5050; void *p_5054; void *p_5058; void *p_505C; void *p_5060; void *p_5064; void *p_5068; void *p_506C; void *p_5070; void *p_5074; void *p_5078; void *p_507C; void *p_5080; void *p_5084; void *p_5088; void *p_508C; void *p_5090; void *p_5094; void *p_5098; void *p_509C; void *p_50A0; void *p_50A4; void *p_50A8; void *p_50AC; void *p_50B0; void *p_50B4; void *p_50B8; void *p_50BC; void *p_50C0; void *p_50C4; void *p_50C8; void *p_50CC; void *p_50D0; void *p_50D4; void *p_50D8; void *p_50DC; void *p_50E0; u32 w_50E4[16]; void *p_5124; void *p_5128; u32 w_512C[2];} fzgx_pool_sel_0 = {{0x4E4F4E00, 0x4D415354, 0x45522052, 0x45435600, 0x4D415354, 0x45522053, 0x454E4400, 0x534C4156, 0x45205345, 0x4E440000, 0x534C4156, 0x45205245, 0x43560000, 0x494E4954, 0x00000000, 0x54455354, 0x00000000, 0x54455354, 0x454E4400, 0x53455455, 0x50000000, 0x53455455, 0x505F444F, 0x4E450000, 0x53455455, 0x505F434F, 0x554E5445, 0x52000000, 0x53455455, 0x505F434E, 0x545F444F, 0x4E450000, 0x554E4C49, 0x4E4B0000, 0x434F494E, 0x00000000, 0x454E5452, 0x595F5741, 0x49540000, 0x4348414C, 0x4C454E47, 0x45520000, 0x4348414C, 0x4C454E47, 0x45525F4F, 0x4B000000, 0x454E5452, 0x59000000, 0x454E5452, 0x595F4F4B, 0x00000000, 0x53494E47, 0x4C454348, 0x45434B00, 0x53494E47, 0x4C454348, 0x45434B5F, 0x4F4B0000, 0x434F5552, 0x53450000, 0x434F5552, 0x53455F4F, 0x4B000000, 0x434F5552, 0x53455F44, 0x41544100, 0x434F5552, 0x53455F44, 0x4154415F, 0x4F4B0000, 0x4D414348, 0x494E4500, 0x4D414348, 0x494E455F, 0x4F4B0000, 0x434F4E46, 0x49470000, 0x434F4E46, 0x49475F4F, 0x4B000000, 0x434F554E, 0x54455241, 0x444A5553, 0x54000000, 0x4C494E4B, 0x57414954, 0x00000000, 0x4C494E4B, 0x57414954, 0x4F4B0000, 0x4C494E4B, 0x53454C00, 0x4C494E4B, 0x44454C49, 0x56455259, 0x53544152, 0x54000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x00000000, 0x4C494E4B, 0x44454C49, 0x56455259, 0x4F4B0000, 0x4C494E4B, 0x53454C4F, 0x4B000000, 0x434F5552, 0x53455649, 0x45570000, 0x434F5552, 0x53455649, 0x45575F4F, 0x4B000000, 0x4C494E4B, 0x52455100, 0x4C494E4B, 0x5354414E, 0x44425900, 0x4C494E4B, 0x4F4B0000, 0x4C494E4B, 0x00000000, 0x50415553, 0x45000000, 0x4552524F, 0x52000000}, lbl_10_data_D00__fzgx_offset_0, lbl_10_data_D04__fzgx_offset_0, lbl_10_data_D10__fzgx_offset_0, lbl_10_data_D1C__fzgx_offset_0, lbl_10_data_D28__fzgx_offset_0, lbl_10_data_D34__fzgx_offset_0, lbl_10_data_D3C__fzgx_offset_0, lbl_10_data_D44__fzgx_offset_0, lbl_10_data_D4C__fzgx_offset_0, lbl_10_data_D54__fzgx_offset_0, lbl_10_data_D60__fzgx_offset_0, lbl_10_data_D70__fzgx_offset_0, lbl_10_data_D80__fzgx_offset_0, lbl_10_data_D88__fzgx_offset_0, lbl_10_data_D90__fzgx_offset_0, lbl_10_data_D9C__fzgx_offset_0, lbl_10_data_DA8__fzgx_offset_0, lbl_10_data_DB8__fzgx_offset_0, lbl_10_data_DC0__fzgx_offset_0, lbl_10_data_DCC__fzgx_offset_0, lbl_10_data_DD8__fzgx_offset_0, lbl_10_data_DE8__fzgx_offset_0, lbl_10_data_DF0__fzgx_offset_0, lbl_10_data_DFC__fzgx_offset_0, lbl_10_data_E08__fzgx_offset_0, lbl_10_data_E18__fzgx_offset_0, lbl_10_data_E20__fzgx_offset_0, lbl_10_data_E2C__fzgx_offset_0, lbl_10_data_E34__fzgx_offset_0, lbl_10_data_E40__fzgx_offset_0, lbl_10_data_E50__fzgx_offset_0, lbl_10_data_E5C__fzgx_offset_0, lbl_10_data_E68__fzgx_offset_0, lbl_10_data_E70__fzgx_offset_0, lbl_10_data_E84__fzgx_offset_0, lbl_10_data_E94__fzgx_offset_0, lbl_10_data_EA4__fzgx_offset_0, lbl_10_data_EB0__fzgx_offset_0, lbl_10_data_EBC__fzgx_offset_0, lbl_10_data_ECC__fzgx_offset_0, lbl_10_data_ED4__fzgx_offset_0, lbl_10_data_EE0__fzgx_offset_0, lbl_10_data_EE8__fzgx_offset_0, lbl_10_data_EF0__fzgx_offset_0, lbl_10_data_EF8__fzgx_offset_0, {0x54686973, 0x20697320, 0x796F7572, 0x206F7269, 0x67696E61, 0x6C206D61, 0x6368696E, 0x652E200A, 0x4561726E, 0x20796F75, 0x72205069, 0x6C6F7420, 0x506F696E, 0x74732062, 0x7920706C, 0x6179696E, 0x670A616E, 0x64206578, 0x6368616E, 0x67652074, 0x68656D20, 0x666F7220, 0x74686520, 0x70617274, 0x732E200A, 0x43757374, 0x6F6D697A, 0x65206974, 0x20696E20, 0x796F7572, 0x206F776E, 0x20776179, 0x2E200000, 0x00000000, 0x82A082C8, 0x82BD82BE, 0x82AF82CC, 0x8349838A, 0x83578369, 0x838B837D, 0x83568393, 0x82C582B7, 0x81420A91, 0x968D7382, 0xC582E082, 0xE782A682, 0xE9837083, 0x43838D83, 0x62836783, 0x7C834383, 0x93836782, 0xF08F5782, 0xDF82E982, 0xC60A8370, 0x815B8363, 0x82CC8CF0, 0x8AB782AA, 0x82C582AB, 0x82DC82B7, 0x81420A8E, 0xA995AA82, 0xBE82AF82, 0xCC837D83, 0x56839382, 0xC9834A83, 0x58835E83, 0x7D834383, 0x5982B582, 0xC482AD82, 0xBE82B382, 0xA2814200, 0x596F7572, 0x20706C61, 0x79206461, 0x74612061, 0x6E642079, 0x6F757220, 0x6D616368, 0x696E6520, 0x64617461, 0x2E200000, 0x82A082C8, 0x82BD82CC, 0x8376838C, 0x83438FEE, 0x95F182C6, 0x8349838A, 0x83578369, 0x838B837D, 0x83568393, 0x8FEE95F1, 0x82C582B7, 0x81420000, 0x91CE90ED, 0x8ED282F0, 0x95E58F57, 0x928682C5, 0x82B78142, 0x82B582CE, 0x82E782AD, 0x82A891D2, 0x82BF82AD, 0x82BE82B3, 0x82A28142, 0x00000000, 0x50726573, 0x73207374, 0x6172742E, 0x20205761, 0x6974696E, 0x6720666F, 0x72206368, 0x616C6C65, 0x6E676572, 0x732E2000, 0x91CE90ED, 0x8ED282F0, 0x95E58F57, 0x928682C5, 0x82B78142, 0x8358835E, 0x815B8367, 0x837B835E, 0x839382F0, 0x899F82B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x00000000, 0x53656C65, 0x63742047, 0x616D6520, 0x4D6F6465, 0x2E200000, 0x8382815B, 0x836882F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x53656C65, 0x63742061, 0x20437570, 0x2E200000, 0x834A8362, 0x837682F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x53656C65, 0x63742061, 0x20436F75, 0x7273652E, 0x20000000, 0x8352815B, 0x835882F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x53656C65, 0x63742043, 0x6F757273, 0x6520616E, 0x64204768, 0x6F73742E, 0x20000000, 0x8352815B, 0x835882CC, 0x914991F0, 0x82C68353, 0x815B8358, 0x836782CC, 0x90DD92E8, 0x82F08D73, 0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x53656C65, 0x63742059, 0x6F757220, 0x4D616368, 0x696E652E, 0x20000000, 0x837D8356, 0x839382F0, 0x914991F0, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x596F7520, 0x63616E20, 0x73656C65, 0x63742079, 0x6F757220, 0x6D616368, 0x696E6520, 0x66726F6D, 0x20462D5A, 0x45524F20, 0x47582061, 0x7320796F, 0x75207573, 0x6520796F, 0x7572204E, 0x494E5445, 0x4E444F20, 0x47414D45, 0x43554245, 0x204D656D, 0x6F727920, 0x43617264, 0x2E200000, 0x836A8393, 0x83658393, 0x8368815B, 0x8351815B, 0x8380834C, 0x8385815B, 0x83758140, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x8E679770, 0x82B782E9, 0x82C6462D, 0x5A45524F, 0x20475882, 0xC5936F98, 0x5E82B582, 0xBD837D83, 0x56839382, 0xAA914991, 0xF082C582, 0xAB82DC82, 0xB7814200, 0x596F7520, 0x63616E20, 0x73656C65, 0x63742074, 0x6865206F, 0x72696769, 0x6E616C20, 0x6D616368, 0x696E6520, 0x61732079, 0x6F752070, 0x75726368, 0x61736520, 0x74686520, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043, 0x4152442E, 0x20000000, 0x462D5A45, 0x524F8389, 0x8343835A, 0x83938358, 0x834A815B, 0x836882F0, 0x8D7793FC, 0x82B782E9, 0x82C68141, 0x8349838A, 0x83578369, 0x838B837D, 0x83568393, 0x82AA9149, 0x91F082C5, 0x82AB82DC, 0x82B78142, 0x00000000, 0x4E6F2047, 0x686F7374, 0x00000000, 0x8353815B, 0x83588367, 0x82C691CE, 0x90ED82B5, 0x82DC82B9, 0x82F10000, 0x47686F73, 0x74204269, 0x74204661, 0x73746572, 0x20546861, 0x6E20596F, 0x75722042, 0x65737420, 0x54696D65, 0x00000000, 0x8EA98CC8, 0x83788358, 0x8367835E, 0x83438380, 0x82E682E8, 0x8FAD82B5, 0x91AC82A2, 0x8353815B, 0x83588367, 0x82C582B7, 0x00000000, 0x46617374, 0x65737420, 0x47686F73, 0x74206279, 0x20656163, 0x68204D61, 0x6368696E, 0x65000000, 0x837D8356, 0x839395CA, 0x82CC8DC5, 0x91AC8353, 0x815B8358, 0x836782C5, 0x82B70000, 0x546F7020, 0x52616E6B, 0x696E6720, 0x47686F73, 0x74000000, 0x83898393, 0x834C8393, 0x834F3188, 0xCA82CC83, 0x53815B83, 0x58836782, 0xC582B700, 0x42617474, 0x6C652077, 0x69746820, 0x53746166, 0x66204768, 0x6F737400, 0x8358835E, 0x83628374, 0x8353815B, 0x83588367, 0x82C582B7, 0x00000000, 0x52616365, 0x204D6F64, 0x65000000, 0x838C815B, 0x83588382, 0x815B8368, 0x00000000, 0x54696D65, 0x20417474, 0x61636B20, 0x4D6F6465, 0x00000000, 0x835E8343, 0x83808341, 0x835E8362, 0x834E8382, 0x815B8368, 0x00000000, 0x4120746F, 0x74616C20, 0x6F662033, 0x30206D61, 0x6368696E, 0x65732069, 0x6E206561, 0x63682072, 0x6163652E, 0x200A5261, 0x63652066, 0x6F722074, 0x68652074, 0x6F702070, 0x6F736974, 0x696F6E20, 0x6F6E2065, 0x61636820, 0x636F7572, 0x73652E20, 0x00000000, 0x91533330, 0x91E482AA, 0x8F6F9196, 0x82B58141, 0x825082C2, 0x82CC8352, 0x815B8358, 0x82C58F87, 0x88CA82F0, 0x8BA382A2, 0x82DC82B7, 0x81420A8A, 0x65835281, 0x5B835882, 0xC5825088, 0xCA82F096, 0xDA8E7782, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x4120746F, 0x74616C20, 0x6F662033, 0x30206D61, 0x6368696E, 0x65732069, 0x6E206561, 0x63682072, 0x6163652E, 0x200A0950, 0x6C617965, 0x72732063, 0x616E2072, 0x61636520, 0x61676169, 0x6E737420, 0x65616368, 0x206F7468, 0x65722069, 0x6E207665, 0x72737573, 0x20706C61, 0x792E200A, 0x2009596F, 0x75206361, 0x6E20736B, 0x69702074, 0x68652076, 0x65727375, 0x7320706C, 0x61792062, 0x79207365, 0x6C656374, 0x696E6720, 0x74686520, 0x6D6F6465, 0x200A0920, 0x7768696C, 0x65207374, 0x65707069, 0x6E67206F, 0x6E207468, 0x65206272, 0x65616B73, 0x2E200A00, 0x91533330, 0x91E482AA, 0x8F6F9196, 0x82B58141, 0x825082C2, 0x82CC8352, 0x815B8358, 0x82C58F87, 0x88CA82F0, 0x8BA382A2, 0x82DC82B7, 0x81420A09, 0x202F6263, 0x66666632, 0x30302F81, 0x75837683, 0x8C834383, 0x84815B93, 0xAF8E6D82, 0xCC91CE90, 0xED837683, 0x8C834381, 0x762F6263, 0x66666666, 0x66662F82, 0xE089C294, 0x5C82C582, 0xB781420A, 0x09208375, 0x838C815B, 0x834C82F0, 0x93A582F1, 0x82BE8FF3, 0x91D482C5, 0x8382815B, 0x836882F0, 0x8C8892E8, 0x82B782E9, 0x82C62F62, 0x63666666, 0x3230302F, 0x09817591, 0xCE90ED82, 0xF0834C83, 0x83839383, 0x5A838B81, 0x762F6263, 0x66666666, 0x66662F82, 0xC582AB82, 0xDC82B781, 0x420A0000, 0x436F6D70, 0x65746520, 0x62792079, 0x6F757273, 0x656C6620, 0x666F7220, 0x74686520, 0x42657374, 0x20546F74, 0x616C206F, 0x66206365, 0x72746169, 0x6E206C61, 0x70732E20, 0x0A095365, 0x6C656374, 0x20656974, 0x68657220, 0x736F6C6F, 0x206F7220, 0x61676169, 0x6E737420, 0x74686520, 0x67686F73, 0x742E0A00, 0x8352815B, 0x835882F0, 0x8B4B92E8, 0x8EFC89F1, 0x91968D73, 0x82B58141, 0x82BB82CC, 0x8367815B, 0x835E838B, 0x835E8343, 0x838082F0, 0x8BA382A2, 0x82DC82B7, 0x81420A09, 0x2F626366, 0x66663230, 0x302F8175, 0x925093C6, 0x91968D73, 0x81458353, 0x815B8358, 0x8367834A, 0x815B91CE, 0x90ED8176, 0x2F626366, 0x66666666, 0x662F82CC, 0x82A282B8, 0x82EA82A9, 0x82F09149, 0x82D782DC, 0x82B78142, 0x0A000000, 0x596F7520, 0x63616E20, 0x6A6F696E, 0x20746865, 0x20496E74, 0x65726E65, 0x74205261, 0x6E6B696E, 0x67207769, 0x74682079, 0x6F757220, 0x70617373, 0x776F7264, 0x2E200A00, 0x83708358, 0x838F815B, 0x836882C9, 0x82E682E9, 0x2F626366, 0x66663230, 0x302F8175, 0x836C8362, 0x83678389, 0x8393834C, 0x8393834F, 0x81762F62, 0x63666666, 0x6666662F, 0x82E08A4A, 0x8DC39286, 0x82C582B7, 0x81420A00, 0x56532042, 0x4154544C, 0x450A4E6F, 0x20636F6D, 0x70757465, 0x72732E20, 0x0A095369, 0x6E676C65, 0x20706C61, 0x79207769, 0x6C6C2062, 0x65206120, 0x6E6F726D, 0x616C2072, 0x61636520, 0x77697468, 0x20636F6D, 0x70757465, 0x72732E20, 0x0A000000, 0x82758272, 0x81408261, 0x82608273, 0x8273826B, 0x826482C5, 0x82B78142, 0x0A835283, 0x93837383, 0x85815B83, 0x5E82CD8E, 0x5189C182, 0xB582DC82, 0xB982F181, 0x420A0982, 0x50906C83, 0x76838C83, 0x4382CD92, 0xCA8FED82, 0xCC838C81, 0x5B835882, 0xC982C882, 0xE882DC82, 0xB781420A, 0x00000000, 0x454D5054, 0x59000000, 0x54776F20, 0x6F72206D, 0x6F726520, 0x436F6E74, 0x726F6C6C, 0x65727320, 0x61726520, 0x6E656564, 0x65642E20, 0x00000000, 0x3282C288, 0xC88FE382, 0xCC835283, 0x93836783, 0x8D815B83, 0x8982AA95, 0x4B977682, 0xC582B781, 0x42000000, 0x2564506C, 0x61796572, 0x73000000, 0x2564906C, 0x91CE90ED, 0x00000000, 0x5245434F, 0x52445300, 0x54686973, 0x20697320, 0x61207061, 0x7373776F, 0x72642066, 0x6F722069, 0x6E746572, 0x6E657420, 0x72616E6B, 0x696E672E, 0x00000000, 0x47455220, 0x54686973, 0x20697320, 0x61207061, 0x7373776F, 0x72642066, 0x6F722069, 0x6E746572, 0x6E657420, 0x72616E6B, 0x696E672E, 0x00000000, 0x46524520, 0x54686973, 0x20697320, 0x61207061, 0x7373776F, 0x72642066, 0x6F722069, 0x6E746572, 0x6E657420, 0x72616E6B, 0x696E672E, 0x00000000, 0x53504120, 0x54686973, 0x20697320, 0x61207061, 0x7373776F, 0x72642066, 0x6F722069, 0x6E746572, 0x6E657420, 0x72616E6B, 0x696E672E, 0x00000000, 0x49544120, 0x54686973, 0x20697320, 0x61207061, 0x7373776F, 0x72642066, 0x6F722069, 0x6E746572, 0x6E657420, 0x72616E6B, 0x696E672E, 0x00000000, 0x82B182EA, 0x82CD8343, 0x8393835E, 0x815B836C, 0x83628367, 0x83898393, 0x834C8393, 0x834F9770, 0x83708358, 0x838F815B, 0x836882C5, 0x82B70000, 0x54686572, 0x65206973, 0x206E6F20, 0x64617461, 0x2E200000, 0x47455220, 0x54686572, 0x65206973, 0x206E6F20, 0x64617461, 0x2E000000, 0x46524520, 0x54686572, 0x65206973, 0x206E6F20, 0x64617461, 0x2E000000, 0x53504120, 0x54686572, 0x65206973, 0x206E6F20, 0x64617461, 0x2E000000, 0x49544120, 0x54686572, 0x65206973, 0x206E6F20, 0x64617461, 0x2E000000, 0x8366815B, 0x835E82AA, 0x82A082E8, 0x82DC82B9, 0x82F18142, 0x00000000, 0x54686973, 0x20646174, 0x61206973, 0x20696E63, 0x6F727265, 0x63742E00, 0x47455220, 0x54686973, 0x20646174, 0x61206973, 0x20696E63, 0x6F727265, 0x63742E00, 0x46524520, 0x54686973, 0x20646174, 0x61206973, 0x20696E63, 0x6F727265, 0x63742E00, 0x53504120, 0x54686973, 0x20646174, 0x61206973, 0x20696E63, 0x6F727265, 0x63742E00, 0x49544120, 0x54686973, 0x20646174, 0x61206973, 0x20696E63, 0x6F727265, 0x63742E00, 0x957390B3, 0x82C88366, 0x815B835E, 0x82C582B7, 0x81420000, 0x596F7520, 0x68617665, 0x6E277420, 0x62656174, 0x656E2074, 0x68652073, 0x65742074, 0x696D652E, 0x00000000, 0x47455220, 0x596F7520, 0x68617665, 0x6E277420, 0x62656174, 0x656E2074, 0x68652073, 0x65742074, 0x696D652E, 0x00000000, 0x46524520, 0x596F7520, 0x68617665, 0x6E277420, 0x62656174, 0x656E2074, 0x68652073, 0x65742074, 0x696D652E, 0x00000000, 0x53504120, 0x596F7520, 0x68617665, 0x6E277420, 0x62656174, 0x656E2074, 0x68652073, 0x65742074, 0x696D652E, 0x00000000, 0x49544120, 0x596F7520, 0x68617665, 0x6E277420, 0x62656174, 0x656E2074, 0x68652073, 0x65742074, 0x696D652E, 0x00000000, 0x8B4B92E8, 0x835E8343, 0x838082C9, 0x924282B5, 0x82C482A2, 0x82DC82B9, 0x82F18142, 0x00000000, 0x4D616368, 0x696E6500, 0x47455220, 0x4D616368, 0x696E6500, 0x46524520, 0x4D616368, 0x696E6500, 0x53504120, 0x4D616368, 0x696E6500, 0x49544120, 0x4D616368, 0x696E6500, 0x837D8356, 0x83938140, 0x81400000, 0x50696C6F, 0x74000000, 0x47455220, 0x50696C6F, 0x74000000, 0x46524520, 0x50696C6F, 0x74000000, 0x53504120, 0x50696C6F, 0x74000000, 0x49544120, 0x50696C6F, 0x74000000, 0x83708343, 0x838D8362, 0x83670000, 0x83B22043, 0x6C656172, 0x2083B420, 0x536F7274, 0x2083A420, 0x25730000, 0x47455220, 0x83B22043, 0x6C656172, 0x2083B420, 0x536F7274, 0x2083A420, 0x25730000, 0x46524520, 0x83B22043, 0x6C656172, 0x2083B420, 0x536F7274, 0x2083A420, 0x25730000, 0x53504120, 0x83B22043, 0x6C656172, 0x2083B420, 0x536F7274, 0x2083A420, 0x25730000, 0x49544120, 0x83B22043, 0x6C656172, 0x2083B420, 0x536F7274, 0x2083A420, 0x25730000, 0x83B22083, 0x4E838A83, 0x412083B4, 0x20835C81, 0x5B836720, 0x83A42025, 0x73000000}, lbl_10_data_FB4__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_103C__fzgx_offset_0, lbl_10_data_10D0__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_10F8__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1128__fzgx_offset_0, lbl_10_data_1158__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1180__fzgx_offset_0, lbl_10_data_11B8__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_11CC__fzgx_offset_0, lbl_10_data_11E8__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_11F8__fzgx_offset_0, lbl_10_data_1214__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1228__fzgx_offset_0, lbl_10_data_1244__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1260__fzgx_offset_0, lbl_10_data_1290__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_12A8__fzgx_offset_0, lbl_10_data_12C4__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1320__fzgx_offset_0, lbl_10_data_1380__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_13D0__fzgx_offset_0, lbl_10_data_1418__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1424__fzgx_offset_0, lbl_10_data_143C__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1464__fzgx_offset_0, lbl_10_data_1490__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_14B0__fzgx_offset_0, lbl_10_data_14CC__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_14E0__fzgx_offset_0, lbl_10_data_14FC__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1514__fzgx_offset_0, lbl_10_data_152C__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1538__fzgx_offset_0, lbl_10_data_1548__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_155C__fzgx_offset_0, lbl_10_data_1574__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_15C8__fzgx_offset_0, lbl_10_data_161C__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_16D0__fzgx_offset_0, lbl_10_data_17A0__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1804__fzgx_offset_0, lbl_10_data_1888__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_18C0__fzgx_offset_0, lbl_10_data_1908__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1958__fzgx_offset_0, lbl_10_data_19B8__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_19B8__fzgx_offset_0, lbl_10_data_19C0__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_19E8__fzgx_offset_0, lbl_10_data_1A0C__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1A18__fzgx_offset_0, lbl_10_data_1A24__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1A24__fzgx_offset_0, lbl_10_data_1A2C__fzgx_offset_0, lbl_10_data_1A58__fzgx_offset_0, lbl_10_data_1A88__fzgx_offset_0, lbl_10_data_1AB8__fzgx_offset_0, lbl_10_data_1AE8__fzgx_offset_0, lbl_10_data_1B18__fzgx_offset_0, lbl_10_data_1B48__fzgx_offset_0, lbl_10_data_1B5C__fzgx_offset_0, lbl_10_data_1B74__fzgx_offset_0, lbl_10_data_1B8C__fzgx_offset_0, lbl_10_data_1BA4__fzgx_offset_0, lbl_10_data_1BBC__fzgx_offset_0, lbl_10_data_1BD4__fzgx_offset_0, lbl_10_data_1BEC__fzgx_offset_0, lbl_10_data_1C08__fzgx_offset_0, lbl_10_data_1C24__fzgx_offset_0, lbl_10_data_1C40__fzgx_offset_0, lbl_10_data_1C5C__fzgx_offset_0, lbl_10_data_1C70__fzgx_offset_0, lbl_10_data_1C94__fzgx_offset_0, lbl_10_data_1CBC__fzgx_offset_0, lbl_10_data_1CE4__fzgx_offset_0, lbl_10_data_1D0C__fzgx_offset_0, lbl_10_data_1D34__fzgx_offset_0, lbl_10_data_1D54__fzgx_offset_0, lbl_10_data_1D5C__fzgx_offset_0, lbl_10_data_1D68__fzgx_offset_0, lbl_10_data_1D74__fzgx_offset_0, lbl_10_data_1D80__fzgx_offset_0, lbl_10_data_1D8C__fzgx_offset_0, lbl_10_data_1D98__fzgx_offset_0, lbl_10_data_1DA0__fzgx_offset_0, lbl_10_data_1DAC__fzgx_offset_0, lbl_10_data_1DB8__fzgx_offset_0, lbl_10_data_1DC4__fzgx_offset_0, lbl_10_data_1DD0__fzgx_offset_0, lbl_10_data_1DDC__fzgx_offset_0, lbl_10_data_1DF4__fzgx_offset_0, lbl_10_data_1E10__fzgx_offset_0, lbl_10_data_1E2C__fzgx_offset_0, lbl_10_data_1E48__fzgx_offset_0, lbl_10_data_1E64__fzgx_offset_0, {0x4D555445, 0x20434954, 0x59000000, 0x4145524F, 0x504F4C49, 0x53000000, 0x4F555445, 0x52205350, 0x41434500, 0x504F5254, 0x20544F57, 0x4E000000, 0x4C494748, 0x544E494E, 0x47000000, 0x47524545, 0x4E20504C, 0x414E5400}, lbl_10_data_21B0__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_21B0__fzgx_offset_0, lbl_10_data_21BC__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_21BC__fzgx_offset_0, lbl_10_data_21C8__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_21C8__fzgx_offset_0, lbl_10_data_21D4__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_21D4__fzgx_offset_0, lbl_10_data_21E0__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_21E0__fzgx_offset_0, lbl_10_data_21EC__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_21EC__fzgx_offset_0, {0x4D6F6465, 0x2053656C, 0x65637400, 0x4D6F6465, 0x2053656C, 0x65637420, 0x47455200, 0x4D6F6465, 0x2053656C, 0x65637420, 0x46524100, 0x4D6F6465, 0x2053656C, 0x65637420, 0x53504100, 0x4D6F6465, 0x2053656C, 0x65637420, 0x49544100, 0x8382815B, 0x8368835A, 0x838C834E, 0x83670000, 0x56532042, 0x6174746C, 0x65000000, 0x56532042, 0x6174746C, 0x65204745, 0x52000000, 0x56532042, 0x6174746C, 0x65204652, 0x41000000, 0x56532042, 0x6174746C, 0x65205350, 0x41000000, 0x56532042, 0x6174746C, 0x65204954, 0x41000000, 0x5653836F, 0x8367838B, 0x00000000, 0x4772616E, 0x64205072, 0x69780000, 0x4772616E, 0x64205072, 0x69782047, 0x45520000, 0x4772616E, 0x64205072, 0x69782046, 0x52410000, 0x4772616E, 0x64205072, 0x69782053, 0x50410000, 0x4772616E, 0x64205072, 0x69782049, 0x54410000, 0x834F8389, 0x83938376, 0x838A0000, 0x54696D65, 0x20417474, 0x61636B00, 0x54696D65, 0x20417474, 0x61636B20, 0x47455200, 0x54696D65, 0x20417474, 0x61636B20, 0x46524100, 0x54696D65, 0x20417474, 0x61636B20, 0x53504100, 0x54696D65, 0x20417474, 0x61636B20, 0x49544100, 0x835E8343, 0x83808341, 0x835E8362, 0x834E0000, 0x50726163, 0x74696365, 0x00000000, 0x50726163, 0x74696365, 0x20474552, 0x00000000, 0x50726163, 0x74696365, 0x20465241, 0x00000000, 0x50726163, 0x74696365, 0x20535041, 0x00000000, 0x50726163, 0x74696365, 0x20495441, 0x00000000, 0x83768389, 0x834E8365, 0x83428358, 0x00000000, 0x53746F72, 0x79000000, 0x53746F72, 0x79204745, 0x52000000, 0x53746F72, 0x79204652, 0x41000000, 0x53746F72, 0x79205350, 0x41000000, 0x53746F72, 0x79204954, 0x41000000, 0x83588367, 0x815B838A, 0x815B0000, 0x43757374, 0x6F6D697A, 0x65000000, 0x43757374, 0x6F6D697A, 0x65204745, 0x52000000, 0x43757374, 0x6F6D697A, 0x65204652, 0x41000000, 0x43757374, 0x6F6D697A, 0x65205350, 0x41000000, 0x43757374, 0x6F6D697A, 0x65204954, 0x41000000, 0x834A8358, 0x835E837D, 0x83438359, 0x00000000, 0x4F707469, 0x6F6E7300, 0x4F707469, 0x6F6E7320, 0x47455200, 0x4F707469, 0x6F6E7320, 0x46524100, 0x4F707469, 0x6F6E7320, 0x53504100, 0x4F707469, 0x6F6E7320, 0x49544100, 0x83498376, 0x83568387, 0x83930000, 0x5265706C, 0x61790000, 0x5265706C, 0x61792047, 0x45520000, 0x5265706C, 0x61792046, 0x52410000, 0x5265706C, 0x61792053, 0x50410000, 0x5265706C, 0x61792049, 0x54410000, 0x838A8376, 0x838C8343, 0x00000000, 0x50696C6F, 0x74205072, 0x6F66696C, 0x65730000, 0x50696C6F, 0x74205072, 0x6F66696C, 0x65732047, 0x45520000, 0x50696C6F, 0x74205072, 0x6F66696C, 0x65732046, 0x52410000, 0x50696C6F, 0x74205072, 0x6F66696C, 0x65732053, 0x50410000, 0x50696C6F, 0x74205072, 0x6F66696C, 0x65732049, 0x54410000, 0x8376838D, 0x83748342, 0x815B838B, 0x00000000, 0x52616365, 0x81694143, 0x816A0000, 0x838C815B, 0x83588169, 0x4143816A, 0x00000000, 0x54696D65, 0x41747461, 0x636B8169, 0x4143816A, 0x00000000, 0x835E8343, 0x83808341, 0x835E8362, 0x834E8169, 0x4143816A, 0x00000000, 0x4F6E6520, 0x436F7572, 0x73650000, 0x31835281, 0x5B835883, 0x8C815B83, 0x58000000, 0x25642050, 0x6C617965, 0x72730000, 0x25642050, 0x6C617965, 0x72732047, 0x45520000, 0x25642050, 0x6C617965, 0x72732046, 0x52410000, 0x25642050, 0x6C617965, 0x72732053, 0x50410000, 0x25642050, 0x6C617965, 0x72732049, 0x54410000, 0x8376838C, 0x83438384, 0x815B2025, 0x64000000, 0x25642043, 0x61727300, 0x25642043, 0x61727320, 0x47455200, 0x25642043, 0x61727320, 0x46524100, 0x25642043, 0x61727320, 0x53504100, 0x25642043, 0x61727320, 0x49544100, 0x834A815B, 0x83478393, 0x8367838A, 0x20256400, 0x4E6F7669, 0x63650000, 0x4E6F7669, 0x63652047, 0x45520000, 0x4E6F7669, 0x63652046, 0x52410000, 0x4E6F7669, 0x63652053, 0x50410000, 0x4E6F7669, 0x63652049, 0x54410000, 0x836D815B, 0x83728358, 0x00000000, 0x5374616E, 0x64617264, 0x00000000, 0x5374616E, 0x64617264, 0x20474552, 0x00000000, 0x5374616E, 0x64617264, 0x20465241, 0x00000000, 0x5374616E, 0x64617264, 0x20535041, 0x00000000, 0x5374616E, 0x64617264, 0x20495441, 0x00000000, 0x8358835E, 0x8393835F, 0x815B8368, 0x00000000, 0x45787065, 0x72740000, 0x45787065, 0x72742047, 0x45520000, 0x45787065, 0x72742046, 0x52410000, 0x45787065, 0x72742053, 0x50410000, 0x45787065, 0x72742049, 0x54410000, 0x8347834C, 0x83588370, 0x815B8367, 0x00000000, 0x4D617374, 0x65720000, 0x4D617374, 0x65722047, 0x45520000, 0x4D617374, 0x65722046, 0x52410000, 0x4D617374, 0x65722053, 0x50410000, 0x4D617374, 0x65722049, 0x54410000, 0x837D8358, 0x835E815B, 0x00000000, 0x47616368, 0x696E6B6F, 0x00000000, 0x47616368, 0x696E6B6F, 0x20474552, 0x00000000, 0x47616368, 0x696E6B6F, 0x20465241, 0x00000000, 0x47616368, 0x696E6B6F, 0x20535041, 0x00000000, 0x47616368, 0x696E6B6F, 0x20495441, 0x00000000, 0x834B8360, 0x83938352, 0x00000000, 0x436F7572, 0x73652053, 0x656C6563, 0x74000000, 0x436F7572, 0x73652053, 0x656C6563, 0x74204745, 0x52000000, 0x436F7572, 0x73652053, 0x656C6563, 0x74204652, 0x41000000, 0x436F7572, 0x73652053, 0x656C6563, 0x74205350, 0x41000000, 0x436F7572, 0x73652053, 0x656C6563, 0x74204954, 0x41000000, 0x8352815B, 0x8358835A, 0x838C834E, 0x83670000, 0x414C4C20, 0x43757000, 0x414C4C20, 0x43757020, 0x47455200, 0x414C4C20, 0x43757020, 0x46524100, 0x414C4C20, 0x43757020, 0x53504100, 0x414C4C20, 0x43757020, 0x49544100, 0x82BA82F1, 0x82B982F1, 0x82BD82AD, 0x834A8362, 0x83760000, 0x52756279, 0x20437570, 0x00000000, 0x52756279, 0x20437570, 0x20474552, 0x00000000, 0x52756279, 0x20437570, 0x20465241, 0x00000000, 0x52756279, 0x20437570, 0x20535041, 0x00000000, 0x52756279, 0x20437570, 0x20495441, 0x00000000, 0x838B8372, 0x815B834A, 0x83628376, 0x00000000, 0x53617070, 0x68697265, 0x20437570, 0x00000000, 0x53617070, 0x68697265, 0x20437570, 0x20474552, 0x00000000, 0x53617070, 0x68697265, 0x20437570, 0x20465241, 0x00000000, 0x53617070, 0x68697265, 0x20437570, 0x20535041, 0x00000000, 0x53617070, 0x68697265, 0x20437570, 0x20495441, 0x00000000, 0x83548374, 0x83408343, 0x8341834A, 0x83628376, 0x00000000, 0x456D6572, 0x616C6420, 0x43757000, 0x456D6572, 0x616C6420, 0x43757020, 0x47455200, 0x456D6572, 0x616C6420, 0x43757020, 0x46524100, 0x456D6572, 0x616C6420, 0x43757020, 0x53504100, 0x456D6572, 0x616C6420, 0x43757020, 0x49544100, 0x83478381, 0x8389838B, 0x8368834A, 0x83628376, 0x00000000, 0x4469616D, 0x6F6E6420, 0x43757000, 0x4469616D, 0x6F6E6420, 0x43757020, 0x47455200, 0x4469616D, 0x6F6E6420, 0x43757020, 0x46524100, 0x4469616D, 0x6F6E6420, 0x43757020, 0x53504100, 0x4469616D, 0x6F6E6420, 0x43757020, 0x49544100, 0x835F8343, 0x83848382, 0x83938368, 0x834A8362, 0x83760000, 0x41582043, 0x75700000, 0x41582047, 0x45520000, 0x41582046, 0x52410000, 0x41582053, 0x50410000, 0x41582049, 0x54410000, 0x4158834A, 0x83628376, 0x00000000, 0x41632043, 0x75700000, 0x41632043, 0x75702047, 0x45520000, 0x41632043, 0x75702046, 0x52410000, 0x41632043, 0x75702053, 0x50410000, 0x41632043, 0x75702049, 0x54410000, 0x8341815B, 0x8350815B, 0x8368834A, 0x83628376, 0x38300000, 0x8341815B, 0x8350815B, 0x8368834A, 0x83628376, 0x35300000, 0x41630000, 0x41632047, 0x45520000, 0x41632046, 0x52410000, 0x41632053, 0x50410000, 0x41632049, 0x54410000, 0x8341815B, 0x8350815B, 0x8368834A, 0x83628376, 0x33300000, 0x57686620, 0x43757000, 0x57686620, 0x43757020, 0x47455200, 0x57686620, 0x43757020, 0x46524100, 0x57686620, 0x43757020, 0x53504100, 0x57686620, 0x43757020, 0x49544100, 0x57484683, 0x4A836283, 0x76000000, 0x45332D30, 0x00000000, 0x45332031, 0x8352815B, 0x8358838C, 0x815B8358, 0x97700000, 0x45332D31, 0x00000000, 0x45332056, 0x53977000, 0x4D616368, 0x696E6520, 0x53656C65, 0x63740000, 0x4D616368, 0x696E6520, 0x53656C65, 0x63742047, 0x45520000, 0x4D616368, 0x696E6520, 0x53656C65, 0x63742046, 0x52410000, 0x4D616368, 0x696E6520, 0x53656C65, 0x63742053, 0x50410000, 0x4D616368, 0x696E6520, 0x53656C65, 0x63742049, 0x54410000, 0x837D8356, 0x8393835A, 0x838C834E, 0x83670000, 0x4D616368, 0x696E6520, 0x436F6E66, 0x69670000, 0x4D616368, 0x696E6520, 0x436F6E66, 0x69672047, 0x45520000, 0x4D616368, 0x696E6520, 0x436F6E66, 0x69672046, 0x52410000, 0x4D616368, 0x696E6520, 0x436F6E66, 0x69672053, 0x50410000, 0x4D616368, 0x696E6520, 0x436F6E66, 0x69672049, 0x54410000, 0x837D8356, 0x83938352, 0x83938374, 0x8342834F, 0x00000000}, lbl_10_data_2288__fzgx_offset_0, lbl_10_data_2294__fzgx_offset_0, lbl_10_data_22A4__fzgx_offset_0, lbl_10_data_22B4__fzgx_offset_0, lbl_10_data_22C4__fzgx_offset_0, lbl_10_data_22D4__fzgx_offset_0, lbl_10_data_22E4__fzgx_offset_0, lbl_10_data_22F0__fzgx_offset_0, lbl_10_data_2300__fzgx_offset_0, lbl_10_data_2310__fzgx_offset_0, lbl_10_data_2320__fzgx_offset_0, lbl_10_data_2330__fzgx_offset_0, lbl_10_data_233C__fzgx_offset_0, lbl_10_data_2348__fzgx_offset_0, lbl_10_data_2358__fzgx_offset_0, lbl_10_data_2368__fzgx_offset_0, lbl_10_data_2378__fzgx_offset_0, lbl_10_data_2388__fzgx_offset_0, lbl_10_data_2394__fzgx_offset_0, lbl_10_data_23A0__fzgx_offset_0, lbl_10_data_23B0__fzgx_offset_0, lbl_10_data_23C0__fzgx_offset_0, lbl_10_data_23D0__fzgx_offset_0, lbl_10_data_23E0__fzgx_offset_0, lbl_10_data_23F0__fzgx_offset_0, lbl_10_data_23FC__fzgx_offset_0, lbl_10_data_240C__fzgx_offset_0, lbl_10_data_241C__fzgx_offset_0, lbl_10_data_242C__fzgx_offset_0, lbl_10_data_243C__fzgx_offset_0, lbl_10_data_244C__fzgx_offset_0, lbl_10_data_2454__fzgx_offset_0, lbl_10_data_2460__fzgx_offset_0, lbl_10_data_246C__fzgx_offset_0, lbl_10_data_2478__fzgx_offset_0, lbl_10_data_2484__fzgx_offset_0, lbl_10_data_2490__fzgx_offset_0, lbl_10_data_249C__fzgx_offset_0, lbl_10_data_24AC__fzgx_offset_0, lbl_10_data_24BC__fzgx_offset_0, lbl_10_data_24CC__fzgx_offset_0, lbl_10_data_24DC__fzgx_offset_0, lbl_10_data_24EC__fzgx_offset_0, lbl_10_data_24F4__fzgx_offset_0, lbl_10_data_2500__fzgx_offset_0, lbl_10_data_250C__fzgx_offset_0, lbl_10_data_2518__fzgx_offset_0, lbl_10_data_2524__fzgx_offset_0, lbl_10_data_2530__fzgx_offset_0, lbl_10_data_2538__fzgx_offset_0, lbl_10_data_2544__fzgx_offset_0, lbl_10_data_2550__fzgx_offset_0, lbl_10_data_255C__fzgx_offset_0, lbl_10_data_2568__fzgx_offset_0, lbl_10_data_2574__fzgx_offset_0, lbl_10_data_2584__fzgx_offset_0, lbl_10_data_2598__fzgx_offset_0, lbl_10_data_25AC__fzgx_offset_0, lbl_10_data_25C0__fzgx_offset_0, lbl_10_data_25D4__fzgx_offset_0, lbl_10_data_25E4__fzgx_offset_0, lbl_10_data_25E4__fzgx_offset_0, lbl_10_data_25E4__fzgx_offset_0, lbl_10_data_25E4__fzgx_offset_0, lbl_10_data_25E4__fzgx_offset_0, lbl_10_data_25F0__fzgx_offset_0, lbl_10_data_2600__fzgx_offset_0, lbl_10_data_2600__fzgx_offset_0, lbl_10_data_2600__fzgx_offset_0, lbl_10_data_2600__fzgx_offset_0, lbl_10_data_2600__fzgx_offset_0, lbl_10_data_2614__fzgx_offset_0, lbl_10_data_262C__fzgx_offset_0, lbl_10_data_262C__fzgx_offset_0, lbl_10_data_262C__fzgx_offset_0, lbl_10_data_262C__fzgx_offset_0, lbl_10_data_262C__fzgx_offset_0, lbl_10_data_2638__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_2638__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_2330__fzgx_offset_0, lbl_10_data_2648__fzgx_offset_0, lbl_10_data_2654__fzgx_offset_0, lbl_10_data_2664__fzgx_offset_0, lbl_10_data_2674__fzgx_offset_0, lbl_10_data_2684__fzgx_offset_0, lbl_10_data_2694__fzgx_offset_0, lbl_10_data_26A4__fzgx_offset_0, lbl_10_data_26AC__fzgx_offset_0, lbl_10_data_26B8__fzgx_offset_0, lbl_10_data_26C4__fzgx_offset_0, lbl_10_data_26D0__fzgx_offset_0, lbl_10_data_26DC__fzgx_offset_0, lbl_10_data_26EC__fzgx_offset_0, lbl_10_data_26F4__fzgx_offset_0, lbl_10_data_2700__fzgx_offset_0, lbl_10_data_270C__fzgx_offset_0, lbl_10_data_2718__fzgx_offset_0, lbl_10_data_2724__fzgx_offset_0, lbl_10_data_2730__fzgx_offset_0, lbl_10_data_273C__fzgx_offset_0, lbl_10_data_274C__fzgx_offset_0, lbl_10_data_275C__fzgx_offset_0, lbl_10_data_276C__fzgx_offset_0, lbl_10_data_277C__fzgx_offset_0, lbl_10_data_278C__fzgx_offset_0, lbl_10_data_2794__fzgx_offset_0, lbl_10_data_27A0__fzgx_offset_0, lbl_10_data_27AC__fzgx_offset_0, lbl_10_data_27B8__fzgx_offset_0, lbl_10_data_27C4__fzgx_offset_0, lbl_10_data_27D4__fzgx_offset_0, lbl_10_data_27DC__fzgx_offset_0, lbl_10_data_27E8__fzgx_offset_0, lbl_10_data_27F4__fzgx_offset_0, lbl_10_data_2800__fzgx_offset_0, lbl_10_data_280C__fzgx_offset_0, lbl_10_data_2818__fzgx_offset_0, lbl_10_data_2824__fzgx_offset_0, lbl_10_data_2834__fzgx_offset_0, lbl_10_data_2844__fzgx_offset_0, lbl_10_data_2854__fzgx_offset_0, lbl_10_data_2864__fzgx_offset_0, lbl_10_data_2870__fzgx_offset_0, lbl_10_data_2880__fzgx_offset_0, lbl_10_data_2894__fzgx_offset_0, lbl_10_data_28A8__fzgx_offset_0, lbl_10_data_28BC__fzgx_offset_0, lbl_10_data_28D0__fzgx_offset_0, lbl_10_data_28E0__fzgx_offset_0, lbl_10_data_28E8__fzgx_offset_0, lbl_10_data_28F4__fzgx_offset_0, lbl_10_data_2900__fzgx_offset_0, lbl_10_data_290C__fzgx_offset_0, lbl_10_data_2918__fzgx_offset_0, lbl_10_data_292C__fzgx_offset_0, lbl_10_data_2938__fzgx_offset_0, lbl_10_data_2948__fzgx_offset_0, lbl_10_data_2958__fzgx_offset_0, lbl_10_data_2968__fzgx_offset_0, lbl_10_data_2978__fzgx_offset_0, lbl_10_data_2988__fzgx_offset_0, lbl_10_data_2998__fzgx_offset_0, lbl_10_data_29AC__fzgx_offset_0, lbl_10_data_29C0__fzgx_offset_0, lbl_10_data_29D4__fzgx_offset_0, lbl_10_data_29E8__fzgx_offset_0, lbl_10_data_29FC__fzgx_offset_0, lbl_10_data_2A08__fzgx_offset_0, lbl_10_data_2A18__fzgx_offset_0, lbl_10_data_2A28__fzgx_offset_0, lbl_10_data_2A38__fzgx_offset_0, lbl_10_data_2A48__fzgx_offset_0, lbl_10_data_2A5C__fzgx_offset_0, lbl_10_data_2A68__fzgx_offset_0, lbl_10_data_2A78__fzgx_offset_0, lbl_10_data_2A88__fzgx_offset_0, lbl_10_data_2A98__fzgx_offset_0, lbl_10_data_2AA8__fzgx_offset_0, lbl_10_data_2ABC__fzgx_offset_0, lbl_10_data_2AC4__fzgx_offset_0, lbl_10_data_2ACC__fzgx_offset_0, lbl_10_data_2AD4__fzgx_offset_0, lbl_10_data_2ADC__fzgx_offset_0, lbl_10_data_2AE4__fzgx_offset_0, lbl_10_data_2AF0__fzgx_offset_0, lbl_10_data_2AF8__fzgx_offset_0, lbl_10_data_2B04__fzgx_offset_0, lbl_10_data_2B10__fzgx_offset_0, lbl_10_data_2B1C__fzgx_offset_0, lbl_10_data_2B28__fzgx_offset_0, lbl_10_data_2AF0__fzgx_offset_0, lbl_10_data_2AF8__fzgx_offset_0, lbl_10_data_2B04__fzgx_offset_0, lbl_10_data_2B10__fzgx_offset_0, lbl_10_data_2B1C__fzgx_offset_0, lbl_10_data_2B3C__fzgx_offset_0, lbl_10_data_2B50__fzgx_offset_0, lbl_10_data_2B54__fzgx_offset_0, lbl_10_data_2B5C__fzgx_offset_0, lbl_10_data_2B64__fzgx_offset_0, lbl_10_data_2B6C__fzgx_offset_0, lbl_10_data_2B74__fzgx_offset_0, lbl_10_data_2B88__fzgx_offset_0, lbl_10_data_2B90__fzgx_offset_0, lbl_10_data_2B9C__fzgx_offset_0, lbl_10_data_2BA8__fzgx_offset_0, lbl_10_data_2BB4__fzgx_offset_0, lbl_10_data_2BC0__fzgx_offset_0, lbl_10_data_2BCC__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_2BD4__fzgx_offset_0, lbl_10_data_2BE8__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_1038__fzgx_offset_0, lbl_10_data_2BF0__fzgx_offset_0, lbl_10_data_2BF8__fzgx_offset_0, lbl_10_data_2C08__fzgx_offset_0, lbl_10_data_2C1C__fzgx_offset_0, lbl_10_data_2C30__fzgx_offset_0, lbl_10_data_2C44__fzgx_offset_0, lbl_10_data_2C58__fzgx_offset_0, lbl_10_data_2C68__fzgx_offset_0, lbl_10_data_2C78__fzgx_offset_0, lbl_10_data_2C8C__fzgx_offset_0, lbl_10_data_2CA0__fzgx_offset_0, lbl_10_data_2CB4__fzgx_offset_0, lbl_10_data_2CC8__fzgx_offset_0, {0x00FF00FF, 0xFF0000FF, 0x0000FFFF, 0xFFFF00FF, 0x4E6F7720, 0x4C6F6164, 0x696E672E, 0x200A0944, 0x6F206E6F, 0x74207075, 0x6C6C206F, 0x75742074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642E20, 0x0A094974, 0x2063616E, 0x2064616D, 0x61676520, 0x74686520, 0x66696C65, 0x2E200A00, 0x4E6F7720, 0x4C6F6164, 0x696E6720, 0x47455200, 0x4E6F7720, 0x4C6F6164, 0x696E6720, 0x46524100, 0x4E6F7720, 0x4C6F6164, 0x696E6720, 0x53504100, 0x4E6F7720, 0x4C6F6164, 0x696E6720, 0x49544100, 0x838D815B, 0x83689286, 0x82C582B7, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A982, 0xC882A282, 0xC582AD82, 0xBE82B382, 0xA281420A, 0x83748340, 0x8343838B, 0x82AA89F3, 0x82EA82E9, 0x82B182C6, 0x82AA82A0, 0x82E882DC, 0x82B78142, 0x0A000000, 0x4661696C, 0x65642074, 0x6F206C6F, 0x61642E20, 0x0A09506C, 0x65617365, 0x2072656D, 0x6F766520, 0x74686520, 0x4D656D6F, 0x72792043, 0x6172642E, 0x200A0000, 0x4C6F6164, 0x20466169, 0x6C656420, 0x47455200, 0x4C6F6164, 0x20466169, 0x6C656420, 0x46524100, 0x4C6F6164, 0x20466169, 0x6C656420, 0x53504100, 0x4C6F6164, 0x20466169, 0x6C656420, 0x49544100, 0x838D815B, 0x836882C9, 0x8EB89473, 0x82B582DC, 0x82B582BD, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A282, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x00000000, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x2063616E, 0x206E6F74, 0x20626520, 0x75736564, 0x2E200A09, 0x54686572, 0x65206973, 0x206E6F20, 0x462D5A45, 0x524F2047, 0x58206761, 0x6D652064, 0x6174612E, 0x200A0950, 0x6C656173, 0x65207265, 0x6D6F7665, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E200A00, 0x4E6F2046, 0x696C6520, 0x47455200, 0x4E6F2046, 0x696C6520, 0x46524100, 0x4E6F2046, 0x696C6520, 0x53504100, 0x4E6F2046, 0x696C6520, 0x49544100, 0x82B182CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CD, 0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x0A098265, 0x817C8279, 0x82648271, 0x826E2082, 0x66827782, 0xCC835181, 0x5B838083, 0x66815B83, 0x5E82AA93, 0xFC82C182, 0xC482A282, 0xDC82B982, 0xF181420A, 0x09838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF094B282, 0xA282C482, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x2063616E, 0x206E6F74, 0x20626520, 0x75736564, 0x2E200A46, 0x2D5A4552, 0x4F204758, 0x2067616D, 0x65206461, 0x74612069, 0x7320636F, 0x72727570, 0x7465642E, 0x200A0950, 0x6C656173, 0x65207265, 0x6D6F7665, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E200A00, 0x46696C65, 0x2042726F, 0x6B656E20, 0x47455200, 0x46696C65, 0x2042726F, 0x6B656E20, 0x46524100, 0x46696C65, 0x2042726F, 0x6B656E20, 0x53504100, 0x46696C65, 0x2042726F, 0x6B656E20, 0x49544100, 0x82B182CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CD, 0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x0A098265, 0x817C8279, 0x82648271, 0x826E2082, 0x66827782, 0xCC835181, 0x5B838083, 0x66815B83, 0x5E82AA89, 0xF382EA82, 0xC482A282, 0xDC82B781, 0x420A0983, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A282, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x00000000, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x2063616E, 0x206E6F74, 0x20626520, 0x75736564, 0x2E200A09, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x206E6565, 0x64732074, 0x6F206265, 0x0A09666F, 0x726D6174, 0x74656420, 0x6279204E, 0x494E5445, 0x4E444F20, 0x47414D45, 0x43554245, 0x2E200A09, 0x506C6561, 0x73652072, 0x656D6F76, 0x65207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E200A, 0x00000000, 0x456E636F, 0x64696E67, 0x20474552, 0x00000000, 0x456E636F, 0x64696E67, 0x20465241, 0x00000000, 0x456E636F, 0x64696E67, 0x20535041, 0x00000000, 0x456E636F, 0x64696E67, 0x20495441, 0x00000000, 0x82B182CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CD, 0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x0A09826D, 0x8268826D, 0x82738264, 0x826D8263, 0x826E8140, 0x82668260, 0x826C8264, 0x82628274, 0x82618264, 0x82C58F89, 0x8AFA89BB, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x81420A09, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x94B282A2, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0A000000, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x2063616E, 0x206E6F74, 0x20626520, 0x75736564, 0x2E200A09, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x20697320, 0x62726F6B, 0x656E206F, 0x7220756E, 0x666F726D, 0x61747465, 0x642E2020, 0x0A09506C, 0x65617365, 0x2072656D, 0x6F766520, 0x74686520, 0x4D656D6F, 0x72792043, 0x6172642E, 0x200A0000, 0x494F2045, 0x72726F72, 0x20474552, 0x00000000, 0x494F2045, 0x72726F72, 0x20465241, 0x00000000, 0x494F2045, 0x72726F72, 0x20535041, 0x00000000, 0x494F2045, 0x72726F72, 0x20495441, 0x00000000, 0x82B182CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CD, 0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x0A098381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82AA89F3, 0x82EA82C4, 0x82A282E9, 0x82A98141, 0x0A098374, 0x8348815B, 0x837D8362, 0x836782B3, 0x82EA82C4, 0x82A282DC, 0x82B982F1, 0x81420A09, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x94B282A2, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0A000000, 0x54686973, 0x204D656D, 0x6F727920, 0x43617264, 0x2063616E, 0x206E6F74, 0x20626520, 0x75736564, 0x2E200A09, 0x506C6561, 0x73652072, 0x656D6F76, 0x65207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E200A, 0x00000000, 0x4F746865, 0x72204572, 0x726F7220, 0x47455200, 0x4F746865, 0x72204572, 0x726F7220, 0x46524100, 0x4F746865, 0x72204572, 0x726F7220, 0x53504100, 0x4F746865, 0x72204572, 0x726F7220, 0x49544100, 0x82B182CC, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CD, 0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF094B282, 0xA282C482, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x506C6179, 0x696E6720, 0x77697468, 0x6F757420, 0x74686520, 0x4D656D6F, 0x72792043, 0x6172642E, 0x200A0000, 0x4D656D63, 0x61726420, 0x6E6F2075, 0x73652047, 0x45520000, 0x4D656D63, 0x61726420, 0x6E6F2075, 0x73652046, 0x52410000, 0x4D656D63, 0x61726420, 0x6E6F2075, 0x73652053, 0x50410000, 0x4D656D63, 0x61726420, 0x6E6F2075, 0x73652049, 0x54410000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x8E6782ED, 0x82B882C9, 0x8376838C, 0x834382B5, 0x82DC82B7, 0x81420A00, 0x57726F6E, 0x67204D65, 0x6D6F7279, 0x20436172, 0x642E2050, 0x6C656173, 0x65207265, 0x6D6F7665, 0x0A092074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642061, 0x6E642069, 0x6E736572, 0x74200A09, 0x74686520, 0x2F626366, 0x66303030, 0x302F4F72, 0x6967696E, 0x616C204D, 0x656D6F72, 0x79204361, 0x72642F62, 0x63666666, 0x6666662F, 0x20776869, 0x63682079, 0x6F752073, 0x74617274, 0x65640A09, 0x20746865, 0x2067616D, 0x652E2053, 0x61766520, 0x77697468, 0x696E2074, 0x68652067, 0x6976656E, 0x2074696D, 0x652E200A, 0x20000000, 0x6E6F7420, 0x73616D65, 0x20636172, 0x64204745, 0x52000000, 0x6E6F7420, 0x73616D65, 0x20636172, 0x64204652, 0x41000000, 0x6E6F7420, 0x73616D65, 0x20636172, 0x64205350, 0x41000000, 0x6E6F7420, 0x73616D65, 0x20636172, 0x64204954, 0x41000000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x8DB782B5, 0x91D682A6, 0x82E782EA, 0x82C482A2, 0x82DC82B7, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A282, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x09835181, 0x5B83808A, 0x4A8E6E8E, 0x9E82C98E, 0x67977082, 0xB582BD83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F08D, 0xB782B582, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x09835E83, 0x43838083, 0x41834583, 0x6782C982, 0xC882E982, 0xC6835A81, 0x5B837582, 0xC582AB82, 0xDC82B982, 0xF181420A, 0x00000000, 0x43616E63, 0x656C6564, 0x200A0000, 0x63616E63, 0x656C6564, 0x20474552, 0x0A000000, 0x63616E63, 0x656C6564, 0x20465241, 0x00000000, 0x63616E63, 0x656C6564, 0x20535041, 0x00000000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882C9, 0x835A815B, 0x837582B5, 0x82DC82B9, 0x82F182C5, 0x82B582BD, 0x81420A00, 0x436F756E, 0x64206E6F, 0x74207265, 0x61642074, 0x68652064, 0x61746120, 0x66726F6D, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E200A09, 0x20506C65, 0x61736520, 0x72656D6F, 0x76652074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642E20, 0x0A000000, 0x43616E20, 0x6E6F7420, 0x72656164, 0x20474552, 0x00000000, 0x43616E20, 0x6E6F7420, 0x72656164, 0x20465241, 0x00000000, 0x43616E20, 0x6E6F7420, 0x72656164, 0x20535041, 0x00000000, 0x43616E20, 0x6E6F7420, 0x72656164, 0x20495441, 0x00000000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8366815B, 0x835E82AA, 0x93C782DF, 0x82DC82B9, 0x82F182C5, 0x82B582BD, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A282, 0xC482AD82, 0xBE82B382, 0xA281420A, 0x00000000, 0x54686572, 0x65206973, 0x206E6F20, 0x4D656D6F, 0x72792043, 0x6172642E, 0x20506C65, 0x61736520, 0x696E7365, 0x72740A09, 0x20746865, 0x202F6263, 0x66663030, 0x30302F6F, 0x72696769, 0x6E616C2F, 0x62636666, 0x66666666, 0x2F204D65, 0x6D6F7279, 0x20436172, 0x64207768, 0x69636820, 0x73746172, 0x7465640A, 0x09207468, 0x65206761, 0x6D652E20, 0x53617665, 0x20776974, 0x68696E20, 0x74686520, 0x67697665, 0x6E207469, 0x6D652E20, 0x0A095361, 0x76652077, 0x69746869, 0x6E207468, 0x65206769, 0x76656E20, 0x74696D65, 0x2E200A00, 0x50756C6C, 0x206F7574, 0x204D656D, 0x63617264, 0x20474552, 0x00000000, 0x50756C6C, 0x206F7574, 0x204D656D, 0x63617264, 0x20465241, 0x00000000, 0x50756C6C, 0x206F7574, 0x204D656D, 0x63617264, 0x20535041, 0x00000000, 0x50756C6C, 0x206F7574, 0x204D656D, 0x63617264, 0x20495441, 0x00000000, 0x83818382, 0x838A815B, 0x834A815B, 0x836882AA, 0x94B282A9, 0x82EA82C4, 0x82A282DC, 0x82B78142, 0x0A835181, 0x5B83808A, 0x4A8E6E8E, 0x9E82C98E, 0x67977082, 0xB582BD83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F00A, 0x098DB782, 0xB582C482, 0xAD82BE82, 0xB382A281, 0x420A0983, 0x5E834383, 0x80834183, 0x45836782, 0xC982C882, 0xE982C683, 0x5A815B83, 0x7582C582, 0xAB82DC82, 0xB982F181, 0x420A0000, 0x4E6F7720, 0x73617669, 0x6E672E20, 0x0A09446F, 0x206E6F74, 0x2070756C, 0x6C206F75, 0x74207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E200A, 0x09497420, 0x63616E20, 0x64616D61, 0x67652074, 0x68652066, 0x696C652E, 0x200A0000, 0x4E6F7720, 0x73617669, 0x6E672047, 0x45520000, 0x4E6F7720, 0x53617669, 0x6E672046, 0x52410000, 0x4E6F7720, 0x53617669, 0x6E672053, 0x50410000, 0x4E6F7720, 0x53617669, 0x6E672049, 0x54410000, 0x835A815B, 0x83759286, 0x82C582B7, 0x81420A83, 0x81838283, 0x8A815B83, 0x4A815B83, 0x6882F094, 0xB282A982, 0xC882A282, 0xC582AD82, 0xBE82B382, 0xA281420A, 0x83748340, 0x8343838B, 0x82AA89F3, 0x82EA82E9, 0x82B182C6, 0x82AA82A0, 0x82E882DC, 0x82B78142, 0x0A000000, 0x46696E69, 0x73686564, 0x20736176, 0x696E6720, 0x696E2074, 0x6865204D, 0x656D6F72, 0x79206361, 0x72642E20, 0x0A000000, 0x53617665, 0x206F6B20, 0x47455200, 0x53617665, 0x206F6B20, 0x46524100, 0x53617665, 0x206F6B20, 0x53504100, 0x53617665, 0x206F6B20, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882D6, 0x82CC835A, 0x815B8375, 0x82AA8F49, 0x97B982B5, 0x82DC82B5, 0x82BD8142, 0x0A000000, 0x4661696C, 0x65642074, 0x6F207361, 0x76652069, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E200A, 0x09506C65, 0x61736520, 0x72656D6F, 0x76652074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642E20, 0x0A000000, 0x53617665, 0x20666169, 0x6C656420, 0x47455200, 0x53617665, 0x20666169, 0x6C656420, 0x46524100, 0x53617665, 0x20666169, 0x6C656420, 0x53504100, 0x53617665, 0x20666169, 0x6C656420, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882D6, 0x82CC835A, 0x815B8375, 0x82AA90B3, 0x8FED82C9, 0x0A098D73, 0x82C882ED, 0x82EA82DC, 0x82B982F1, 0x82C582B5, 0x82BD8142, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF094B282, 0xA282C482, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x54686520, 0x4D656D6F, 0x72792043, 0x61726420, 0x69732072, 0x65616479, 0x2E200A09, 0x446F206E, 0x6F742074, 0x6F756368, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x20647572, 0x696E6720, 0x74686520, 0x706C6179, 0x2E200A09, 0x49742063, 0x616E2064, 0x616D6167, 0x65207468, 0x65206669, 0x6C652E20, 0x0A200000, 0x4D656D63, 0x61726420, 0x72656164, 0x79204745, 0x52000000, 0x4D656D63, 0x61726420, 0x72656164, 0x79204652, 0x41000000, 0x4D656D63, 0x61726420, 0x72656164, 0x79205350, 0x41000000, 0x4D656D63, 0x61726420, 0x72656164, 0x79204954, 0x41000000, 0x2F626366, 0x66666630, 0x302F8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82CC8F80, 0x94F582AA, 0x82C582AB, 0x82DC82B5, 0x82BD8142, 0x2F626366, 0x66666666, 0x662F0A09, 0x8376838C, 0x83439286, 0x82CC94B2, 0x82AB8DB7, 0x82B582CD, 0x8D7382C8, 0x82ED82C8, 0x82A282C5, 0x82AD82BE, 0x82B382A2, 0x81420A09, 0x83748340, 0x8343838B, 0x82AA89F3, 0x82EA82E9, 0x82B182C6, 0x82AA82A0, 0x82E882DC, 0x82B78142, 0x0A000000, 0x4E6F7720, 0x63686563, 0x6B696E67, 0x2E200A44, 0x6F206E6F, 0x74207075, 0x6C6C206F, 0x75742074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642E20, 0x0A497420, 0x63616E20, 0x64616D61, 0x67652074, 0x68652066, 0x696C650A, 0x20000000, 0x4D656D63, 0x61726420, 0x63686563, 0x6B696E67, 0x20474552, 0x00000000, 0x4D656D63, 0x61726420, 0x63686563, 0x6B696E67, 0x20465241, 0x00000000, 0x4D656D63, 0x61726420, 0x63686563, 0x6B696E67, 0x20535041, 0x00000000, 0x4D656D63, 0x61726420, 0x63686563, 0x6B696E67, 0x20495441, 0x00000000, 0x83608346, 0x8362834E, 0x928682C5, 0x82B78142, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF094B282, 0xA982C882, 0xA282C582, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x506C6561, 0x73652069, 0x6E736572, 0x7420462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152, 0x44206166, 0x7465720A, 0x09746865, 0x20646174, 0x61206973, 0x206C6F61, 0x64656420, 0x66726F6D, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E200000, 0x44656661, 0x6C757420, 0x47455200, 0x44656661, 0x756C7420, 0x46524100, 0x44656661, 0x756C7420, 0x53504100, 0x44656661, 0x756C7420, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8366815B, 0x835E838D, 0x815B8368, 0x82AA8AAE, 0x97B982B7, 0x82E982DC, 0x82C50A09, 0x20838983, 0x43835A83, 0x93835883, 0x4A815B83, 0x6882CC91, 0x7D93FC82, 0xF082A891, 0xD282BF82, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x506C6561, 0x7365206D, 0x616B6520, 0x73757265, 0x20746865, 0x72652069, 0x73206E6F, 0x20666F72, 0x6569676E, 0x206F626A, 0x65637469, 0x6E207468, 0x6520736C, 0x6F742C09, 0x6265666F, 0x72652079, 0x6F752069, 0x6E736572, 0x74207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x642E200A, 0x49742069, 0x73207265, 0x636F6D6D, 0x656E6465, 0x6420746F, 0x206F6E6C, 0x79207361, 0x76652046, 0x2D5A4552, 0x4F204758, 0x20646174, 0x6120696E, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x2E20200A, 0x446F206E, 0x6F742074, 0x6F756368, 0x20746865, 0x204D656D, 0x6F727920, 0x43617264, 0x64757269, 0x6E672074, 0x68652070, 0x6C61792E, 0x20497420, 0x63616E20, 0x64616D61, 0x67652074, 0x6F206669, 0x6C652E20, 0x0A000000, 0x43617574, 0x696F6E20, 0x47455200, 0x43617574, 0x696F6E20, 0x46524100, 0x43617574, 0x696F6E20, 0x53504100, 0x43617574, 0x696F6E20, 0x49544100, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x8DB782B5, 0x8D9E82DE, 0x914F82C9, 0x8358838D, 0x83628367, 0x82C988D9, 0x8FED82AA, 0x82C882A2, 0x82A98A6D, 0x944682B5, 0x82C482AD, 0x82BE82B3, 0x82A28142, 0x0A098175, 0x82658279, 0x82648271, 0x826E8140, 0x82668277, 0x817688C8, 0x8A4F82CC, 0x8366815B, 0x835E82F0, 0x93FC82EA, 0x82C882A2, 0x82C58E67, 0x977082B7, 0x82E982B1, 0x82C682F0, 0x90848FA7, 0x82B582DC, 0x82B78142, 0x0A098376, 0x838C8343, 0x928682CC, 0x834A815B, 0x836882CC, 0x94B282AB, 0x8DB782B5, 0x82CD8141, 0x90E291CE, 0x82C982A8, 0x82E282DF, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x4E494E54, 0x454E444F, 0x2047414D, 0x45435542, 0x45204D65, 0x6D6F7279, 0x20436172, 0x640A0963, 0x616E206E, 0x6F740962, 0x65207573, 0x65642061, 0x74207468, 0x69732074, 0x696D652E, 0x200A0000, 0x4D656D63, 0x61726420, 0x4F666620, 0x47455200, 0x4D656D63, 0x61726420, 0x4F666620, 0x46524100, 0x4D656D63, 0x61726420, 0x4F666620, 0x53504100, 0x4D656D63, 0x61726420, 0x4F666620, 0x49544100, 0x82BD82BE, 0x8DA18141, 0x826D8268, 0x826D8273, 0x8264826D, 0x8263826E, 0x81408266, 0x8260826C, 0x82648262, 0x82748261, 0x82640A09, 0x83818382, 0x838A815B, 0x834A815B, 0x836882F0, 0x8E679770, 0x82B782E9, 0x82B182C6, 0x82AA82C5, 0x82AB82DC, 0x82B982F1, 0x81420A00, 0x4D656D6F, 0x72792043, 0x61726420, 0x6361206E, 0x6F742062, 0x65207573, 0x65642061, 0x74207468, 0x69732074, 0x696D652E, 0x200A0000, 0x416C6C20, 0x43617264, 0x204F6666, 0x20474552, 0x00000000, 0x416C6C20, 0x43617264, 0x204F6666, 0x20465241, 0x00000000, 0x416C6C20, 0x43617264, 0x204F6666, 0x20535041, 0x00000000, 0x416C6C20, 0x43617264, 0x204F6666, 0x20495441, 0x00000000, 0x82BD82BE, 0x8DA18141, 0x834A815B, 0x836882CC, 0x8E679770, 0x82CD82C5, 0x82AB82DC, 0x82B982F1, 0x81420A00, 0x4572726F, 0x72206F63, 0x63757272, 0x65642069, 0x6E207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x6420536C, 0x6F740A09, 0x506C6561, 0x73652046, 0x6F6C6C6F, 0x77207468, 0x6520696E, 0x73747275, 0x6374696F, 0x6E73206F, 0x6E207468, 0x65207363, 0x7265656E, 0x00000000, 0x536C6F74, 0x20457272, 0x6F722047, 0x45520000, 0x536C6F74, 0x20457272, 0x6F722046, 0x52410000, 0x536C6F74, 0x20457272, 0x6F722053, 0x50410000, 0x536C6F74, 0x20457272, 0x6F722049, 0x54410000, 0x83818382, 0x838A815B, 0x834A815B, 0x83688358, 0x838D8362, 0x836782C9, 0x83478389, 0x815B82AA, 0x94AD90B6, 0x82B582DC, 0x82B582BD, 0x81420A89, 0xE696CA82, 0xCC8E778E, 0xA682C98F, 0x5D82C182, 0xC489BA82, 0xAD82BE82, 0xB382A281, 0x420A0000, 0x4D656D6F, 0x72792043, 0x61642063, 0x616E206E, 0x6F742062, 0x65207573, 0x65642061, 0x74207468, 0x69732074, 0x696D652E, 0x200A0000, 0x4E6F2052, 0x65636569, 0x76652047, 0x45520000, 0x4E6F2052, 0x65636569, 0x76652046, 0x52410000, 0x4E6F2052, 0x65636569, 0x76652053, 0x50410000, 0x4E6F2052, 0x65636569, 0x76652049, 0x54410000, 0x82BD82BE, 0x8DA18141, 0x83818382, 0x838A815B, 0x834A815B, 0x836882CC, 0x8EF39574, 0x82CD8D73, 0x82C882C1, 0x82C482A2, 0x82DC82B9, 0x82F18142, 0x0A838183, 0x82838A81, 0x5B834A81, 0x5B836882, 0xF08E6797, 0x7082C582, 0xAB82DC82, 0xB982F181, 0x420A0000, 0x496E7365, 0x72742074, 0x6865204D, 0x656D6F72, 0x79204361, 0x72642077, 0x69746820, 0x462D5A45, 0x524F2047, 0x58206461, 0x74612E20, 0x0A000000, 0x496E7365, 0x7274204D, 0x656D6361, 0x72642047, 0x45520000, 0x496E7365, 0x7274204D, 0x656D6361, 0x72642046, 0x52410000, 0x496E7365, 0x7274204D, 0x656D6361, 0x72642053, 0x50410000, 0x496E7365, 0x7274204D, 0x656D6361, 0x72642049, 0x54410000, 0x8265817C, 0x82798264, 0x8271826E, 0x81408266, 0x827782CC, 0x8366815B, 0x835E82AA, 0x93FC82C1, 0x82BD8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82F08DB7, 0x82B582C4, 0x89BA82AD, 0x82BE82B3, 0x82A28142, 0x0A000000, 0x446F206E, 0x6F742069, 0x6E736572, 0x74207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x64207769, 0x74682061, 0x6E20696D, 0x706F7274, 0x616E7420, 0x64617461, 0x2E200A49, 0x74206361, 0x6E206765, 0x74206461, 0x6D616765, 0x640A0000, 0x4E6F2075, 0x73652049, 0x6D706F72, 0x74616E74, 0x20636172, 0x64204745, 0x52000000, 0x4E6F2075, 0x73652049, 0x6D706F72, 0x74616E74, 0x20636172, 0x64204652, 0x41000000, 0x4E6F2075, 0x73652049, 0x6D706F72, 0x74616E74, 0x20636172, 0x64205350, 0x41000000, 0x4E6F2075, 0x73652049, 0x6D706F72, 0x74616E74, 0x20636172, 0x64204954, 0x41000000, 0x8366815B, 0x835E82AA, 0x8EB882ED, 0x82EA82E9, 0x8BB082EA, 0x82AA82A0, 0x82E982CC, 0x82C591E5, 0x90D882C8, 0x834A815B, 0x836882CD, 0x8E679770, 0x82B582C8, 0x82A282C5, 0x89BA82AD, 0x82BE82B3, 0x82A28142, 0x00000000, 0x4E6F7720, 0x63686563, 0x6B696E67, 0x2E2E2E0A, 0x00000000, 0x4E6F7720, 0x63686563, 0x6B696E67, 0x20474552, 0x00000000, 0x4E6F7720, 0x63686563, 0x6B696E67, 0x20465241, 0x00000000, 0x4E6F7720, 0x63686563, 0x6B696E67, 0x20535041, 0x00000000, 0x4E6F7720, 0x63686563, 0x6B696E67, 0x20495441, 0x00000000, 0x83608346, 0x8362834E, 0x82B582C4, 0x82A282DC, 0x82B78145, 0x81458145, 0x0A000000, 0x53756363, 0x65656465, 0x6420746F, 0x20726561, 0x642F7772, 0x6974650A, 0x00000000, 0x52656164, 0x20577269, 0x7465204F, 0x4B204745, 0x52000000, 0x52656164, 0x20577269, 0x7465204F, 0x4B204652, 0x41000000, 0x52656164, 0x20577269, 0x7465204F, 0x4B205350, 0x41000000, 0x52656164, 0x20577269, 0x7465204F, 0x4B204954, 0x41000000, 0x838A815B, 0x8368815E, 0x83898343, 0x836782C5, 0x82AB82DC, 0x82B582BD, 0x0A000000, 0x4661696C, 0x65642074, 0x6F207265, 0x61642F77, 0x72697465, 0x0A000000, 0x52656164, 0x20577269, 0x74652066, 0x616C6965, 0x64204745, 0x52000000, 0x52656164, 0x20577269, 0x74652066, 0x61696C65, 0x64204652, 0x41000000, 0x52656164, 0x20577269, 0x74652066, 0x61696C65, 0x64205350, 0x41000000, 0x52656164, 0x20577269, 0x74652066, 0x61696C65, 0x64204954, 0x41000000, 0x838A815B, 0x8368815E, 0x83898343, 0x836782C9, 0x8EB89473, 0x82B582DC, 0x82B582BD, 0x0A000000, 0x506C6561, 0x73652069, 0x6E736572, 0x74207468, 0x65204D65, 0x6D6F7279, 0x20436172, 0x640A6265, 0x666F7265, 0x20796F75, 0x20696E73, 0x65727420, 0x74686520, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043, 0x4152442E, 0x0A000000, 0x83818382, 0x838A817C, 0x834A815B, 0x836882F0, 0x82B28E67, 0x977082B7, 0x82E995FB, 0x82CD8381, 0x8382838A, 0x815B834A, 0x815B8368, 0x82F090E6, 0x82C98DB7, 0x82B582C4, 0x82AD82BE, 0x82B382A2, 0x00000000}, lbl_10_data_3064__fzgx_offset_0, lbl_10_data_30B0__fzgx_offset_0, lbl_10_data_30C0__fzgx_offset_0, lbl_10_data_30D0__fzgx_offset_0, lbl_10_data_30E0__fzgx_offset_0, lbl_10_data_30F0__fzgx_offset_0, lbl_10_data_3148__fzgx_offset_0, lbl_10_data_317C__fzgx_offset_0, lbl_10_data_318C__fzgx_offset_0, lbl_10_data_319C__fzgx_offset_0, lbl_10_data_31AC__fzgx_offset_0, lbl_10_data_31BC__fzgx_offset_0, lbl_10_data_31F8__fzgx_offset_0, lbl_10_data_3260__fzgx_offset_0, lbl_10_data_326C__fzgx_offset_0, lbl_10_data_3278__fzgx_offset_0, lbl_10_data_3284__fzgx_offset_0, lbl_10_data_3290__fzgx_offset_0, lbl_10_data_330C__fzgx_offset_0, lbl_10_data_3374__fzgx_offset_0, lbl_10_data_3384__fzgx_offset_0, lbl_10_data_3394__fzgx_offset_0, lbl_10_data_33A4__fzgx_offset_0, lbl_10_data_33B4__fzgx_offset_0, lbl_10_data_3430__fzgx_offset_0, lbl_10_data_34B8__fzgx_offset_0, lbl_10_data_34C8__fzgx_offset_0, lbl_10_data_34D8__fzgx_offset_0, lbl_10_data_34E8__fzgx_offset_0, lbl_10_data_34F8__fzgx_offset_0, lbl_10_data_357C__fzgx_offset_0, lbl_10_data_35F0__fzgx_offset_0, lbl_10_data_3600__fzgx_offset_0, lbl_10_data_3610__fzgx_offset_0, lbl_10_data_3620__fzgx_offset_0, lbl_10_data_3630__fzgx_offset_0, lbl_10_data_36B8__fzgx_offset_0, lbl_10_data_3700__fzgx_offset_0, lbl_10_data_3710__fzgx_offset_0, lbl_10_data_3720__fzgx_offset_0, lbl_10_data_3730__fzgx_offset_0, lbl_10_data_3740__fzgx_offset_0, lbl_10_data_3788__fzgx_offset_0, lbl_10_data_37AC__fzgx_offset_0, lbl_10_data_37C0__fzgx_offset_0, lbl_10_data_37D4__fzgx_offset_0, lbl_10_data_37E8__fzgx_offset_0, lbl_10_data_37FC__fzgx_offset_0, lbl_10_data_3824__fzgx_offset_0, lbl_10_data_38D0__fzgx_offset_0, lbl_10_data_38E4__fzgx_offset_0, lbl_10_data_38F8__fzgx_offset_0, lbl_10_data_390C__fzgx_offset_0, lbl_10_data_3920__fzgx_offset_0, lbl_10_data_39CC__fzgx_offset_0, lbl_10_data_39D8__fzgx_offset_0, lbl_10_data_39E8__fzgx_offset_0, lbl_10_data_39F8__fzgx_offset_0, lbl_10_data_390C__fzgx_offset_0, lbl_10_data_3A08__fzgx_offset_0, lbl_10_data_3A30__fzgx_offset_0, lbl_10_data_3A84__fzgx_offset_0, lbl_10_data_3A98__fzgx_offset_0, lbl_10_data_3AAC__fzgx_offset_0, lbl_10_data_3AC0__fzgx_offset_0, lbl_10_data_3AD4__fzgx_offset_0, lbl_10_data_3B24__fzgx_offset_0, lbl_10_data_3BD0__fzgx_offset_0, lbl_10_data_3BE8__fzgx_offset_0, lbl_10_data_3C00__fzgx_offset_0, lbl_10_data_3C18__fzgx_offset_0, lbl_10_data_3C30__fzgx_offset_0, lbl_10_data_3CB4__fzgx_offset_0, lbl_10_data_3D00__fzgx_offset_0, lbl_10_data_3D10__fzgx_offset_0, lbl_10_data_3D20__fzgx_offset_0, lbl_10_data_3D30__fzgx_offset_0, lbl_10_data_3D40__fzgx_offset_0, lbl_10_data_3D98__fzgx_offset_0, lbl_10_data_3DC0__fzgx_offset_0, lbl_10_data_3DCC__fzgx_offset_0, lbl_10_data_3DD8__fzgx_offset_0, lbl_10_data_3DE4__fzgx_offset_0, lbl_10_data_3DF0__fzgx_offset_0, lbl_10_data_3E1C__fzgx_offset_0, lbl_10_data_3E64__fzgx_offset_0, lbl_10_data_3E74__fzgx_offset_0, lbl_10_data_3E84__fzgx_offset_0, lbl_10_data_3E94__fzgx_offset_0, lbl_10_data_3EA4__fzgx_offset_0, lbl_10_data_3F00__fzgx_offset_0, lbl_10_data_3F68__fzgx_offset_0, lbl_10_data_3F7C__fzgx_offset_0, lbl_10_data_3F90__fzgx_offset_0, lbl_10_data_3FA4__fzgx_offset_0, lbl_10_data_3FB8__fzgx_offset_0, lbl_10_data_4040__fzgx_offset_0, lbl_10_data_408C__fzgx_offset_0, lbl_10_data_40A4__fzgx_offset_0, lbl_10_data_40BC__fzgx_offset_0, lbl_10_data_40D4__fzgx_offset_0, lbl_10_data_40EC__fzgx_offset_0, lbl_10_data_4124__fzgx_offset_0, lbl_10_data_4178__fzgx_offset_0, lbl_10_data_4184__fzgx_offset_0, lbl_10_data_4190__fzgx_offset_0, lbl_10_data_419C__fzgx_offset_0, lbl_10_data_41A8__fzgx_offset_0, lbl_10_data_4200__fzgx_offset_0, lbl_10_data_42E8__fzgx_offset_0, lbl_10_data_42F4__fzgx_offset_0, lbl_10_data_4300__fzgx_offset_0, lbl_10_data_430C__fzgx_offset_0, lbl_10_data_4318__fzgx_offset_0, lbl_10_data_43DC__fzgx_offset_0, lbl_10_data_441C__fzgx_offset_0, lbl_10_data_442C__fzgx_offset_0, lbl_10_data_443C__fzgx_offset_0, lbl_10_data_444C__fzgx_offset_0, lbl_10_data_445C__fzgx_offset_0, lbl_10_data_44B4__fzgx_offset_0, lbl_10_data_44E0__fzgx_offset_0, lbl_10_data_44F4__fzgx_offset_0, lbl_10_data_4508__fzgx_offset_0, lbl_10_data_451C__fzgx_offset_0, lbl_10_data_4530__fzgx_offset_0, lbl_10_data_4554__fzgx_offset_0, lbl_10_data_45AC__fzgx_offset_0, lbl_10_data_45BC__fzgx_offset_0, lbl_10_data_45CC__fzgx_offset_0, lbl_10_data_45DC__fzgx_offset_0, lbl_10_data_45EC__fzgx_offset_0, lbl_10_data_463C__fzgx_offset_0, lbl_10_data_4668__fzgx_offset_0, lbl_10_data_4678__fzgx_offset_0, lbl_10_data_4688__fzgx_offset_0, lbl_10_data_4698__fzgx_offset_0, lbl_10_data_46A8__fzgx_offset_0, lbl_10_data_46FC__fzgx_offset_0, lbl_10_data_472C__fzgx_offset_0, lbl_10_data_4740__fzgx_offset_0, lbl_10_data_4754__fzgx_offset_0, lbl_10_data_4768__fzgx_offset_0, lbl_10_data_477C__fzgx_offset_0, lbl_10_data_47C4__fzgx_offset_0, lbl_10_data_4810__fzgx_offset_0, lbl_10_data_482C__fzgx_offset_0, lbl_10_data_4848__fzgx_offset_0, lbl_10_data_4864__fzgx_offset_0, lbl_10_data_4880__fzgx_offset_0, lbl_10_data_48C8__fzgx_offset_0, lbl_10_data_48DC__fzgx_offset_0, lbl_10_data_48F0__fzgx_offset_0, lbl_10_data_4904__fzgx_offset_0, lbl_10_data_4918__fzgx_offset_0, lbl_10_data_492C__fzgx_offset_0, lbl_10_data_4948__fzgx_offset_0, lbl_10_data_4964__fzgx_offset_0, lbl_10_data_4978__fzgx_offset_0, lbl_10_data_498C__fzgx_offset_0, lbl_10_data_49A0__fzgx_offset_0, lbl_10_data_49B4__fzgx_offset_0, lbl_10_data_49D0__fzgx_offset_0, lbl_10_data_49E8__fzgx_offset_0, lbl_10_data_4A00__fzgx_offset_0, lbl_10_data_4A18__fzgx_offset_0, lbl_10_data_4A30__fzgx_offset_0, lbl_10_data_4A48__fzgx_offset_0, lbl_10_data_4A68__fzgx_offset_0, lbl_10_data_49E8__fzgx_offset_0, lbl_10_data_4A00__fzgx_offset_0, lbl_10_data_4A18__fzgx_offset_0, lbl_10_data_4A30__fzgx_offset_0, lbl_10_data_4AB4__fzgx_offset_0, {0x506C6561, 0x73652073, 0x65742075, 0x7020796F, 0x75722046, 0x2D5A4552, 0x4F204C49, 0x43454E53, 0x45204341, 0x52442E20, 0x00000000, 0x504C4541, 0x53455F53, 0x45545F55, 0x50204745, 0x52000000, 0x504C4541, 0x53455F53, 0x45545F55, 0x50204652, 0x41000000, 0x504C4541, 0x53455F53, 0x45545F55, 0x50205350, 0x41000000, 0x504C4541, 0x53455F53, 0x45545F55, 0x50204954, 0x41000000, 0x834A815B, 0x836882CC, 0x90DD92E8, 0x82F08D73, 0x82C182C4, 0x82AD82BE, 0x82B382A2, 0x00000000, 0x446F2079, 0x6F752068, 0x61766520, 0x6120462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152, 0x443F0000, 0x515F4841, 0x56455F4C, 0x4943454E, 0x53452047, 0x45520000, 0x515F4841, 0x56455F4C, 0x4943454E, 0x53452046, 0x52410000, 0x515F4841, 0x56455F4C, 0x4943454E, 0x53452053, 0x50410000, 0x515F4841, 0x56455F4C, 0x4943454E, 0x53452049, 0x54410000, 0x8265817C, 0x82798264, 0x8271826E, 0x20838983, 0x43835A83, 0x93835883, 0x4A815B83, 0x6882CD82, 0xA88E9D82, 0xBF82C582, 0xB782A981, 0x48000000, 0x49662079, 0x6F752068, 0x61766520, 0x74686520, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043, 0x4152442E, 0x20000000, 0x48415645, 0x5F4C4943, 0x454E5345, 0x20474552, 0x00000000, 0x48415645, 0x5F4C4943, 0x454E5345, 0x20465241, 0x00000000, 0x48415645, 0x5F4C4943, 0x454E5345, 0x20535041, 0x00000000, 0x48415645, 0x5F4C4943, 0x454E5345, 0x20495441, 0x00000000, 0x83898343, 0x835A8393, 0x8358834A, 0x815B8368, 0x82F082A8, 0x8E9D82BF, 0x82CC95FB, 0x00000000, 0x49662079, 0x6F752064, 0x6F6E2774, 0x20686176, 0x65207468, 0x6520462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152, 0x442E2000, 0x444F4E54, 0x5F484156, 0x455F4C49, 0x43454E53, 0x45204745, 0x52000000, 0x444F4E54, 0x5F484156, 0x455F4C49, 0x43454E53, 0x45204652, 0x41000000, 0x444F4E54, 0x5F484156, 0x455F4C49, 0x43454E53, 0x45205350, 0x41000000, 0x444F4E54, 0x5F484156, 0x455F4C49, 0x43454E53, 0x45204954, 0x41000000, 0x83898343, 0x835A8393, 0x8358834A, 0x815B8368, 0x82F082A8, 0x8E9D82BF, 0x82C582C8, 0x82A295FB, 0x00000000, 0x4661696C, 0x65642074, 0x6F206C6F, 0x61642E20, 0x0A506C65, 0x61736520, 0x72656D6F, 0x76652074, 0x68652063, 0x6172642E, 0x20000000, 0x4641494C, 0x45445F4C, 0x4F414420, 0x47455200, 0x4641494C, 0x45445F4C, 0x4F414420, 0x46524100, 0x4641494C, 0x45445F4C, 0x4F414420, 0x53504100, 0x4641494C, 0x45445F4C, 0x4F414420, 0x49544100, 0x838D815B, 0x836882C9, 0x8EB89473, 0x82B582DC, 0x82B582BD, 0x81420A83, 0x4A815B83, 0x6882F082, 0xA88EE682, 0xE882AD82, 0xBE82B382, 0xA2814200, 0x43616E20, 0x6E6F7420, 0x75736520, 0x74686973, 0x20636172, 0x642E2000, 0x43414E54, 0x5F555345, 0x5F544849, 0x535F4341, 0x52442047, 0x45520000, 0x43414E54, 0x5F555345, 0x5F544849, 0x535F4341, 0x52442046, 0x52410000, 0x43414E54, 0x5F555345, 0x5F544849, 0x535F4341, 0x52442053, 0x50410000, 0x43414E54, 0x5F555345, 0x5F544849, 0x535F4341, 0x52442049, 0x54410000, 0x82B182CC, 0x834A815B, 0x836882CD, 0x8E679770, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x00000000, 0x54686973, 0x20697320, 0x6E6F7420, 0x6120462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152, 0x442E200A, 0x506C6561, 0x73652072, 0x65747269, 0x65766520, 0x74686520, 0x63617264, 0x2E200000, 0x4E4F545F, 0x4C494345, 0x4E53455F, 0x43415244, 0x20474552, 0x00000000, 0x4E4F545F, 0x4C494345, 0x4E53455F, 0x43415244, 0x20465241, 0x00000000, 0x4E4F545F, 0x4C494345, 0x4E53455F, 0x43415244, 0x20535041, 0x00000000, 0x4E4F545F, 0x4C494345, 0x4E53455F, 0x43415244, 0x20495441, 0x00000000, 0x8265817C, 0x82798264, 0x8271826E, 0x20838983, 0x43835A83, 0x93835883, 0x4A815B83, 0x6882C582, 0xCD82A082, 0xE882DC82, 0xB982F181, 0x420A834A, 0x815B8368, 0x82F082A8, 0x8EE682E8, 0x82AD82BE, 0x82B382A2, 0x81420000, 0x54686520, 0x64617461, 0x20697320, 0x62726F6B, 0x656E2E20, 0x0A506C65, 0x61736520, 0x72657472, 0x69657665, 0x20746865, 0x20636172, 0x642E2000, 0x42524541, 0x4B5F4341, 0x52442047, 0x45520000, 0x42524541, 0x4B5F4341, 0x52442046, 0x52410000, 0x42524541, 0x4B5F4341, 0x52442053, 0x50410000, 0x42524541, 0x4B5F4341, 0x52442049, 0x54410000, 0x8366815B, 0x835E82AA, 0x89F382EA, 0x82C482A2, 0x82DC82B7, 0x81420A83, 0x4A815B83, 0x6882F082, 0xA88EE682, 0xE882AD82, 0xBE82B382, 0xA2814200, 0x54686520, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043, 0x41524420, 0x68617320, 0x0A657870, 0x69726564, 0x20616E64, 0x20746865, 0x20646174, 0x61206973, 0x200A616C, 0x72656164, 0x79207472, 0x616E7366, 0x65727265, 0x642E200A, 0x506C6561, 0x73652072, 0x65747269, 0x65766520, 0x74686520, 0x63617264, 0x2E200000, 0x414C5245, 0x4144595F, 0x5452414E, 0x53464552, 0x5F434152, 0x44204745, 0x52000000, 0x414C5245, 0x4144595F, 0x5452414E, 0x53464552, 0x5F434152, 0x44204652, 0x41000000, 0x414C5245, 0x4144595F, 0x5452414E, 0x53464552, 0x5F434152, 0x44205350, 0x41000000, 0x414C5245, 0x4144595F, 0x5452414E, 0x53464552, 0x5F434152, 0x44204954, 0x41000000, 0x8E679770, 0x90A78CC0, 0x82C99242, 0x82B58141, 0x8366815B, 0x835E82CC, 0x88F882AB, 0x8C7082AC, 0x82E00A8F, 0x4997B982, 0xB582C482, 0xA282DC82, 0xB781420A, 0x834A815B, 0x836882F0, 0x82A88EE6, 0x82E882AD, 0x82BE82B3, 0x82A28142, 0x00000000, 0x54686520, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043, 0x41524420, 0x63616E20, 0x6E6F740A, 0x62652075, 0x73656420, 0x61742074, 0x68697320, 0x74696D65, 0x2E200000, 0x43414E54, 0x5F42455F, 0x55534544, 0x09204745, 0x52000000, 0x43414E54, 0x5F42455F, 0x55534544, 0x09204652, 0x41000000, 0x43414E54, 0x5F42455F, 0x55534544, 0x09205350, 0x41000000, 0x43414E54, 0x5F42455F, 0x55534544, 0x09204954, 0x41000000, 0x82BD82BE, 0x8DA18141, 0x8265817C, 0x82798264, 0x8271826E, 0x20838983, 0x43835A83, 0x93835883, 0x4A815B83, 0x6882F00A, 0x8E679770, 0x82B782E9, 0x82B182C6, 0x82AA82C5, 0x82AB82DC, 0x82B982F1, 0x81420000, 0x50726F63, 0x6565642E, 0x20000000, 0x50524F43, 0x45454409, 0x20474552, 0x00000000, 0x50524F43, 0x45454409, 0x20465241, 0x00000000, 0x50524F43, 0x45454409, 0x20535041, 0x00000000, 0x50524F43, 0x45454409, 0x20495441, 0x00000000, 0x90E682C9, 0x906982DE, 0x00000000, 0x596F7520, 0x6E656564, 0x20256420, 0x636F696E, 0x28732920, 0x746F2063, 0x72656174, 0x652E2000, 0x4E454544, 0x5F434F49, 0x4E530920, 0x47455200, 0x4E454544, 0x5F434F49, 0x4E530920, 0x46524100, 0x4E454544, 0x5F434F49, 0x4E530920, 0x53504100, 0x4E454544, 0x5F434F49, 0x4E530920, 0x49544100, 0x25642043, 0x4F494E28, 0x5329954B, 0x977682C5, 0x82B78142, 0x00000000, 0x596F7520, 0x6E656564, 0x20256420, 0x636F696E, 0x28732920, 0x746F2072, 0x656E6577, 0x2E200000, 0x52656E65, 0x77696E67, 0x20796F75, 0x7220462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152, 0x442E200A, 0x596F7572, 0x206E6577, 0x20462D5A, 0x45524F20, 0x4C494345, 0x4E534520, 0x43415244, 0x2077696C, 0x6C206265, 0x20697373, 0x75656420, 0x61667465, 0x72207468, 0x65206761, 0x6D652070, 0x6C61792E, 0x200A596F, 0x75722065, 0x782D462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152, 0x44207769, 0x6C6C206E, 0x6F742062, 0x65207573, 0x61626C65, 0x20616674, 0x65722074, 0x72616E73, 0x6665722E, 0x200A506C, 0x65617365, 0x20726574, 0x72696576, 0x6520796F, 0x75722046, 0x2D5A4552, 0x4F204C49, 0x43454E53, 0x45204341, 0x52442E20, 0x00000000, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x47455200, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x46524100, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x53504100, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x49544100, 0x834A815B, 0x836882CC, 0x88F882AB, 0x8C7082AC, 0x82F08D73, 0x82A282DC, 0x82B78142, 0x0A905682, 0xB582A283, 0x4A815B83, 0x6882CD83, 0x76838C83, 0x438F4997, 0xB98CE382, 0xC994728F, 0x6F82B382, 0xEA82DC82, 0xB781420A, 0x88F882AB, 0x8C7082AC, 0x82AA8F49, 0x97B982B5, 0x82BD834A, 0x815B8368, 0x82CD8E67, 0x977082C5, 0x82AB82C8, 0x82AD82C8, 0x82E882DC, 0x82B78142, 0x0A834A81, 0x5B836882, 0xF082A88E, 0xE682E882, 0xAD82BE82, 0xB382A281, 0x42000000, 0x4E6F7420, 0x72656E65, 0x77696E67, 0x20796F75, 0x7220462D, 0x5A45524F, 0x204C4943, 0x454E5345, 0x20434152, 0x442E200A, 0x506C6561, 0x73652072, 0x65747269, 0x65766520, 0x796F7572, 0x20462D5A, 0x45524F20, 0x4C494345, 0x4E534520, 0x43415244, 0x2E200000, 0x4E4F545F, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x47455200, 0x4E4F545F, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x46524100, 0x4E4F545F, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x53504100, 0x4E4F545F, 0x52454E45, 0x575F4C49, 0x43454E53, 0x455F4341, 0x52440920, 0x49544100, 0x8366815B, 0x835E82CC, 0x88F882AB, 0x8C7082AC, 0x82F08D73, 0x82A282DC, 0x82B982F1, 0x81420A83, 0x4A815B83, 0x6882F082, 0xA88EE682, 0xE882AD82, 0xBE82B382, 0xA2814200, 0x596F7572, 0x20462D5A, 0x45524F20, 0x4C494345, 0x4E534520, 0x43415244, 0x20686173, 0x20657870, 0x69726564, 0x2E200A59, 0x6F752063, 0x616E2074, 0x72616E73, 0x66657220, 0x796F7572, 0x20706C61, 0x79206461, 0x74612062, 0x79207265, 0x6E657769, 0x6E672079, 0x6F757220, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043, 0x4152442E, 0x20000000, 0x43414E5F, 0x5452414E, 0x53464552, 0x5F434152, 0x44092047, 0x45520000, 0x43414E5F, 0x5452414E, 0x53464552, 0x5F434152, 0x44092046, 0x52410000, 0x43414E5F, 0x5452414E, 0x53464552, 0x5F434152, 0x44092053, 0x50410000, 0x43414E5F, 0x5452414E, 0x53464552, 0x5F434152, 0x44092049, 0x54410000, 0x834A815B, 0x836882CC, 0x83898343, 0x835A8393, 0x835882AA, 0x90D882EA, 0x82C482A2, 0x82DC82B7, 0x81420A90, 0x5682B582, 0xA2834A81, 0x5B836882, 0xF08DEC90, 0xAC82B782, 0xEA82CE81, 0x41837683, 0x8C834383, 0x66815B83, 0x5E82F088, 0xF882AB8C, 0x7082AE82, 0xB182C682, 0xAA82C582, 0xAB82DC82, 0xB7814200, 0x43726561, 0x74652079, 0x6F757220, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043, 0x4152442E, 0x200A596F, 0x7572206E, 0x65772046, 0x2D5A4552, 0x4F204C49, 0x43454E53, 0x45204341, 0x52442077, 0x696C6C20, 0x62652069, 0x73737565, 0x64206166, 0x74657220, 0x74686520, 0x67616D65, 0x20706C61, 0x792E2000, 0x43524541, 0x54455F43, 0x41524409, 0x20474552, 0x00000000, 0x43524541, 0x54455F43, 0x41524409, 0x20465241, 0x00000000, 0x43524541, 0x54455F43, 0x41524409, 0x20535041, 0x00000000, 0x43524541, 0x54455F43, 0x41524409, 0x20495441, 0x00000000, 0x834A815B, 0x836882F0, 0x8DEC90AC, 0x82B582DC, 0x82B78142, 0x0A905682, 0xB582A283, 0x4A815B83, 0x6882CD83, 0x76838C83, 0x438F4997, 0xB98CE382, 0xC994728F, 0x6F82B382, 0xEA82DC82, 0xB7814200, 0x506C6179, 0x696E6720, 0x77697468, 0x6F757420, 0x74686520, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043, 0x4152442E, 0x20000000, 0x57495448, 0x4F55545F, 0x4C494345, 0x4E43455F, 0x43415244, 0x09204745, 0x52000000, 0x57495448, 0x4F55545F, 0x4C494345, 0x4E43455F, 0x43415244, 0x09204652, 0x41000000, 0x57495448, 0x4F55545F, 0x4C494345, 0x4E43455F, 0x43415244, 0x09205350, 0x41000000, 0x57495448, 0x4F55545F, 0x4C494345, 0x4E43455F, 0x43415244, 0x09204954, 0x41000000, 0x462D5A45, 0x524F204C, 0x4943454E, 0x53452043, 0x41524482, 0xF08E6782, 0xED82B882, 0xC90A8376, 0x838C8343, 0x82B582DC, 0x82B78142, 0x00000000, 0x506C6179, 0x696E6720, 0x77697468, 0x6F757420, 0x74686520, 0x63617264, 0x732E2000, 0x57495448, 0x4F55545F, 0x43415244, 0x09204745, 0x52000000, 0x57495448, 0x4F55545F, 0x43415244, 0x09204652, 0x41000000, 0x57495448, 0x4F55545F, 0x43415244, 0x09205350, 0x41000000, 0x57495448, 0x4F55545F, 0x43415244, 0x09204954, 0x41000000, 0x834A815B, 0x836882F0, 0x8E6782ED, 0x82B882C9, 0x8376838C, 0x834382B5, 0x82DC82B7, 0x81420000}, lbl_10_data_4DB0__fzgx_offset_0, lbl_10_data_4DDC__fzgx_offset_0, lbl_10_data_4DF0__fzgx_offset_0, lbl_10_data_4E04__fzgx_offset_0, lbl_10_data_4E18__fzgx_offset_0, lbl_10_data_4E2C__fzgx_offset_0, lbl_10_data_4E4C__fzgx_offset_0, lbl_10_data_4E70__fzgx_offset_0, lbl_10_data_4E84__fzgx_offset_0, lbl_10_data_4E98__fzgx_offset_0, lbl_10_data_4EAC__fzgx_offset_0, lbl_10_data_4EC0__fzgx_offset_0, lbl_10_data_4EF0__fzgx_offset_0, lbl_10_data_4F18__fzgx_offset_0, lbl_10_data_4F2C__fzgx_offset_0, lbl_10_data_4F40__fzgx_offset_0, lbl_10_data_4F54__fzgx_offset_0, lbl_10_data_4F68__fzgx_offset_0, lbl_10_data_4F88__fzgx_offset_0, lbl_10_data_4FB4__fzgx_offset_0, lbl_10_data_4FCC__fzgx_offset_0, lbl_10_data_4FE4__fzgx_offset_0, lbl_10_data_4FFC__fzgx_offset_0, lbl_10_data_5014__fzgx_offset_0, lbl_10_data_5038__fzgx_offset_0, lbl_10_data_5064__fzgx_offset_0, lbl_10_data_5074__fzgx_offset_0, lbl_10_data_5084__fzgx_offset_0, lbl_10_data_5094__fzgx_offset_0, lbl_10_data_50A4__fzgx_offset_0, lbl_10_data_50D4__fzgx_offset_0, lbl_10_data_50EC__fzgx_offset_0, lbl_10_data_5104__fzgx_offset_0, lbl_10_data_511C__fzgx_offset_0, lbl_10_data_5134__fzgx_offset_0, lbl_10_data_514C__fzgx_offset_0, lbl_10_data_516C__fzgx_offset_0, lbl_10_data_51AC__fzgx_offset_0, lbl_10_data_51C4__fzgx_offset_0, lbl_10_data_51DC__fzgx_offset_0, lbl_10_data_51F4__fzgx_offset_0, lbl_10_data_520C__fzgx_offset_0, lbl_10_data_5254__fzgx_offset_0, lbl_10_data_5284__fzgx_offset_0, lbl_10_data_5294__fzgx_offset_0, lbl_10_data_52A4__fzgx_offset_0, lbl_10_data_52B4__fzgx_offset_0, lbl_10_data_52C4__fzgx_offset_0, lbl_10_data_52F4__fzgx_offset_0, lbl_10_data_535C__fzgx_offset_0, lbl_10_data_5378__fzgx_offset_0, lbl_10_data_5394__fzgx_offset_0, lbl_10_data_53B0__fzgx_offset_0, lbl_10_data_53CC__fzgx_offset_0, lbl_10_data_541C__fzgx_offset_0, lbl_10_data_5454__fzgx_offset_0, lbl_10_data_5468__fzgx_offset_0, lbl_10_data_547C__fzgx_offset_0, lbl_10_data_5490__fzgx_offset_0, lbl_10_data_54A4__fzgx_offset_0, lbl_10_data_54E8__fzgx_offset_0, lbl_10_data_54F4__fzgx_offset_0, lbl_10_data_5504__fzgx_offset_0, lbl_10_data_5514__fzgx_offset_0, lbl_10_data_5524__fzgx_offset_0, lbl_10_data_5534__fzgx_offset_0, lbl_10_data_5540__fzgx_offset_0, lbl_10_data_5560__fzgx_offset_0, lbl_10_data_5570__fzgx_offset_0, lbl_10_data_5580__fzgx_offset_0, lbl_10_data_5590__fzgx_offset_0, lbl_10_data_55A0__fzgx_offset_0, lbl_10_data_55B8__fzgx_offset_0, lbl_10_data_5560__fzgx_offset_0, lbl_10_data_5570__fzgx_offset_0, lbl_10_data_5580__fzgx_offset_0, lbl_10_data_5590__fzgx_offset_0, lbl_10_data_55A0__fzgx_offset_0, lbl_10_data_55D8__fzgx_offset_0, lbl_10_data_56AC__fzgx_offset_0, lbl_10_data_56C4__fzgx_offset_0, lbl_10_data_56DC__fzgx_offset_0, lbl_10_data_56F4__fzgx_offset_0, lbl_10_data_570C__fzgx_offset_0, lbl_10_data_57A0__fzgx_offset_0, lbl_10_data_57F4__fzgx_offset_0, lbl_10_data_5810__fzgx_offset_0, lbl_10_data_582C__fzgx_offset_0, lbl_10_data_5848__fzgx_offset_0, lbl_10_data_5864__fzgx_offset_0, lbl_10_data_589C__fzgx_offset_0, lbl_10_data_590C__fzgx_offset_0, lbl_10_data_5924__fzgx_offset_0, lbl_10_data_593C__fzgx_offset_0, lbl_10_data_5954__fzgx_offset_0, lbl_10_data_596C__fzgx_offset_0, lbl_10_data_59D0__fzgx_offset_0, lbl_10_data_5A34__fzgx_offset_0, lbl_10_data_5A48__fzgx_offset_0, lbl_10_data_5A5C__fzgx_offset_0, lbl_10_data_5A70__fzgx_offset_0, lbl_10_data_5A84__fzgx_offset_0, lbl_10_data_5AC4__fzgx_offset_0, lbl_10_data_5AF0__fzgx_offset_0, lbl_10_data_5B0C__fzgx_offset_0, lbl_10_data_5B28__fzgx_offset_0, lbl_10_data_5B44__fzgx_offset_0, lbl_10_data_5B60__fzgx_offset_0, lbl_10_data_5B90__fzgx_offset_0, lbl_10_data_5BAC__fzgx_offset_0, lbl_10_data_5BC0__fzgx_offset_0, lbl_10_data_5BD4__fzgx_offset_0, lbl_10_data_5BE8__fzgx_offset_0, lbl_10_data_5BFC__fzgx_offset_0, {0x91CE90ED, 0x8ED282AA, 0x914991F0, 0x928682C5, 0x82B78142, 0x00000000, 0x57616974, 0x696E6720, 0x666F7220, 0x796F7572, 0x206F7070, 0x6F6E656E, 0x74277320, 0x64656369, 0x73696F6E, 0x2E000000}, lbl_10_data_5DE4__fzgx_offset_0, lbl_10_data_5DFC__fzgx_offset_0, {0x25730A00, 0x0A0A0000}}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5134[116] = {0x25730000, 0x0A000000, 0x5B25645D, 0x0A000000, 0x2532643A, 0x25730A00, 0x82C98C88, 0x92E882B5, 0x82DC82B5, 0x82BD0000, 0x3F3F3F00, 0x4D656D43, 0x61726425, 0x640A0000, 0x5B202573, 0x205D0A0A, 0x00000000, 0x4E6F6E65, 0x00000000, 0x4D656D43, 0x61726420, 0x25640000, 0x25252D25, 0x64730000, 0x2D2D2D2D, 0x2D2D0A00, 0x5061645B, 0x2531645D, 0x3A000000, 0x28253264, 0x29253164, 0x25730A00, 0x4F4B0000, 0x20200000, 0x3F000000, 0x837D8356, 0x83938FEE, 0x95F182F0, 0x92CA904D, 0x82B582C4, 0x82A282DC, 0x82B78142, 0x00000000, 0x4E6F7720, 0x72656365, 0x6976696E, 0x6720706C, 0x61796572, 0x73272064, 0x6174612E, 0x00000000, 0x82B582CE, 0x82E782AD, 0x82A882DC, 0x82BF82AD, 0x82BE82B3, 0x82A28142, 0x00000000, 0x57616974, 0x2061204D, 0x6F6D656E, 0x742E2E2E, 0x00000000, 0x01A00084, 0x0000A125, 0x0000A126, 0x01000000, 0x00E00084, 0x0000A117, 0x0000A118, 0x00000000, 0x008000EE, 0x0000A123, 0x0000A124, 0x02000000, 0x020000EE, 0x0000A11B, 0x0000A11C, 0x04000000, 0x014000EE, 0x0000A121, 0x0000A122, 0x03000000, 0x00E00158, 0x0000A115, 0x0000A116, 0x05000000, 0x01A00158, 0x0000A119, 0x0000A11A, 0x06000000, (u32)fn_10_13ECC__fzgx_offset_948, (u32)fn_10_13ECC__fzgx_offset_940, (u32)fn_10_13ECC__fzgx_offset_950, (u32)fn_10_13ECC__fzgx_offset_958, (u32)fn_10_13ECC__fzgx_offset_960, (u32)fn_10_13ECC__fzgx_offset_970, (u32)fn_10_13ECC__fzgx_offset_978, (u32)fn_10_13ECC__fzgx_offset_968, (u32)fn_10_13ECC__fzgx_offset_980, (u32)fn_10_13ECC__fzgx_offset_984, (u32)fn_10_13ECC__fzgx_offset_984, (u32)fn_10_13ECC__fzgx_offset_938, 0x5B000000, 0x5D000000, 0x93EF88D5, 0x93788146, 0x00000000, 0x44696666, 0x6963756C, 0x74793A00, 0x819A0000, 0x25303264, 0x3B253032, 0x643C2530, 0x33640000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5304[230] = {0x25640000, 0x83418393, 0x8367836A, 0x834982CE, 0x82CE82CE, 0x00000000, 0x47686F73, 0x74204F66, 0x66000000, 0x8353815B, 0x83588367, 0x83498374, 0x00000000, 0x52697661, 0x6C204768, 0x6F737400, 0x83898343, 0x836F838B, 0x8353815B, 0x83588367, 0x00000000, 0x8ED48EED, 0x95CA8353, 0x815B8358, 0x83670000, 0x4368616D, 0x70696F6E, 0x2047686F, 0x73740000, 0x83608383, 0x83938373, 0x83498393, 0x8353815B, 0x83588367, 0x00000000, 0x53746166, 0x66204768, 0x6F737400, 0x8358835E, 0x83628374, 0x8353815B, 0x83588367, 0x00000000, 0x4E4F2044, 0x41544100, 0x82A282EB, 0x82CD82C9, 0x82D982D6, 0x82C682BF, 0x00000000, 0x5A8B8900, 0x91968D73, 0x89F19094, 0x20256489, 0xF1000000, 0x73000000, 0x50617274, 0x69636970, 0x6174696E, 0x67202564, 0x2054696D, 0x65257300, 0x4E414D45, 0x00000000, 0x49737375, 0x65204461, 0x74650000, 0x25303264, 0x2F253032, 0x642F2530, 0x32642025, 0x3032643A, 0x25303264, 0x00000000, 0x8DEC90AC, 0x93FA0000, 0x4E656564, 0x2052656E, 0x6577616C, 0x20616674, 0x65720000, 0x2564506C, 0x61790000, 0x4C494345, 0x4E53458D, 0x58905682, 0xDC82C500, 0x256489F1, 0x00000000, 0x506C6179, 0x65642066, 0x6F720000, 0x25645469, 0x6D650000, 0x8376838C, 0x834389F1, 0x90940000, 0x50494C4F, 0x54205241, 0x4E4B0000, 0x50494C4F, 0x5420504F, 0x494E5400, 0x25647074, 0x00000000, 0x50494C4F, 0x5420504F, 0x494E5453, 0x00000000, 0x25647074, 0x73000000, 0x4D6F7265, 0x20706F69, 0x6E747320, 0x746F2067, 0x65742074, 0x68652070, 0x61727473, 0x00000000, 0x596F7520, 0x63616E20, 0x67657420, 0x74686520, 0x70617274, 0x732E0000, 0x8370815B, 0x83638351, 0x83628367, 0x00000000, 0x836F815B, 0x83638351, 0x83628367, 0x89C2945C, 0x82C582B7, 0x00000000, 0x8370815B, 0x83638351, 0x83628367, 0x82DC82C5, 0x2082A082, 0xC6000000, 0x4E756D62, 0x6572206F, 0x66205269, 0x76616C73, 0x20596F75, 0x27766520, 0x44657374, 0x726F7965, 0x64000000, 0x918D8C82, 0x946A9094, 0x00000000, 0x256491E4, 0x00000000, 0x2564506C, 0x61797300, 0x25645469, 0x6D657300, 0x82B382CE, 0x82CC82DD, 0x82BB82C9, 0x82A082B0, 0x00000000, 0x834A838C, 0x815B82C8, 0x82F182CE, 0x82F15200, 0x57616974, 0x696E6720, 0x666F7220, 0x61206E65, 0x77206368, 0x616C6C65, 0x6E676572, 0x00000000, 0x91CE90ED, 0x8ED282F0, 0x91D282C1, 0x82C482A2, 0x82DC82B7, 0x81420000, (u32)lbl_10_data_62A4__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_62C4__fzgx_offset_0, 0x57616974, 0x696E6720, 0x666F7220, 0x6E657720, 0x6368616C, 0x6C656E67, 0x65727300, (u32)lbl_10_data_62F4__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_62C4__fzgx_offset_0, 0x83578383, 0x8393837B, 0x82D382B6, 0x82BD0000, (u32)lbl_10_data_6188__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_6188__fzgx_offset_0, (u32)lbl_10_data_6194__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_6194__fzgx_offset_0, (u32)lbl_10_data_6238__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_625C__fzgx_offset_0, 0x50617274, 0x69636970, 0x6174696E, 0x67000000, 0x91968D73, 0x89F19094, 0x00000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_569C[13] = {(u32)lbl_10_data_6380__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_6390__fzgx_offset_0, 0x42657374, 0x20526573, 0x756C7420, 0x00000000, 0x8DC58D82, 0x8F8788CA, 0x00000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_56D0[12] = {(u32)lbl_10_data_63B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_63C4__fzgx_offset_0, 0x31737420, 0x506C6163, 0x65000000, 0x3188CA82, 0xCC89F190, 0x94000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5700[11] = {(u32)lbl_10_data_63E8__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_63F4__fzgx_offset_0, 0x57696E6E, 0x696E6720, 0x25000000, 0x8F9F97A6, 0x00000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_572C[10] = {(u32)lbl_10_data_6418__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_6424__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5754[8] = {0x00000000, (u32)lbl_10_data_1038__fzgx_offset_0, (u32)lbl_10_data_1038__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_1038__fzgx_offset_0}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5774[10] = {0x91E40000, (u32)lbl_10_data_1038__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_6474__fzgx_offset_0, 0x54696D65, 0x00000000, 0x89F10000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_579C[9] = {(u32)lbl_10_data_6490__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_6498__fzgx_offset_0, 0x20506C61, 0x63650000, 0x88CA0000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_57C0[5] = {(u32)lbl_10_data_64B4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_57D4[1] = {(u32)lbl_10_data_64BC__fzgx_offset_0}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_57D8[7] = {(u32)lbl_10_data_6490__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_6498__fzgx_offset_0, 0x25000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_57F4[1] = {(u32)lbl_10_data_64F0__fzgx_offset_0}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_57F8[8] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_64F0__fzgx_offset_0, 0x4E4F2045, 0x4E545259, 0x00000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5818[9] = {(u32)lbl_10_data_650C__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_650C__fzgx_offset_0, 0x25645020, 0x4E4F2043, 0x41524400}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_583C[113] = {(u32)lbl_10_data_6530__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_6530__fzgx_offset_0, 0x4E6F2E25, 0x640A0A20, 0x69732070, 0x6C617969, 0x6E672E0A, 0x596F7520, 0x63616E20, 0x6E6F7420, 0x6A6F696E, 0x20746869, 0x73207261, 0x63652E00, 0x4E6F2E25, 0x640A0A83, 0x76838C83, 0x43928682, 0xC582B781, 0x420A82B1, 0x82CC838C, 0x815B8358, 0x82C982CD, 0x8E5189C1, 0x82C582AB, 0x82DC82B9, 0x82F18142, 0x00000000, (u32)lbl_10_data_6554__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_6584__fzgx_offset_0, 0x4E6F2E25, 0x640A0A4E, 0x4F204341, 0x52440000, (u32)lbl_10_data_65D4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_65D4__fzgx_offset_0, 0x4E6F2E25, 0x640A0A57, 0x61697469, 0x6E672066, 0x6F722063, 0x68616C6C, 0x656E6765, 0x72732E00, 0x4E6F2E25, 0x640A0A83, 0x47839383, 0x67838A81, 0x5B8EF395, 0x74928682, 0xC582B781, 0x42000000, (u32)lbl_10_data_65FC__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_661C__fzgx_offset_0, 0x4E6F2E25, 0x640A0A53, 0x656C6563, 0x74696E67, 0x2061206D, 0x6F64652E, 0x00000000, 0x4E6F2E25, 0x640A0A83, 0x82815B83, 0x68914991, 0xF0928682, 0xC582B781, 0x42000000, (u32)lbl_10_data_6654__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_6670__fzgx_offset_0, 0x4E6F2E25, 0x640A0A00, (u32)lbl_10_data_66A4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_66A4__fzgx_offset_0, (u32)lbl_10_data_66A4__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_66A4__fzgx_offset_0, 0x838C815B, 0x83588E51, 0x89C10000, (u32)lbl_10_data_6380__fzgx_offset_0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, (u32)lbl_10_data_66DC__fzgx_offset_0}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5A00[4] = {0x82D982E8, 0x82B182B5, 0x20836D83, 0x8A82B100}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5A10[8] = {0x8341838D, 0x837D8365, 0x83898373, 0x815B8260, 0x8B898389, 0x8343835A, 0x83938358, 0x00000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5A30[2] = {0x25642573, 0x00000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5A38[2] = {0x25642573, 0x73000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5A40[1] = {0x2D2D2D00}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5A44[1] = {0x25326400}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5A48[2] = {0x25732573, 0x25730000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5A50[1] = {0x30000000}; /* fzgx-allow: A1 measured initialized pool */
static u32 fzgx_pool_sel_5A54[1] = {0x25732573}; /* fzgx-allow: A1 measured initialized pool */

struct Arg0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u32 unk_C;
    u32 unk_10;
    u8 pad_14[0x10];
    u16 unk_24[6];
    u16 unk_30[6];
    u8 unk_3C[1];
};



extern f64 lbl_8006D188(u32);
extern int fn_1_4F734(FontDrawPacket *);
extern int fn_1_D66B0(void);
extern int sprintf(char *, const char *, ...);
extern u8 lbl_10_bss_5568C;
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_801A66A0;
extern s32 lbl_801A66B4;
extern u8 fn_1_128DD8(u8);
extern void *__cvt_fp2unsigned(f64);
extern void *fn_1_5417C(void *);
extern u32 fn_1_49410(void);
extern u32 fn_1_53FE4(u32, u32);
extern void fn_1_49514(u32 *);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(void *);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);
extern void fn_1_4CE48(Obj_1_bss_4B9CC *, f32);
extern void fn_1_4CF3C(u32, f32, ...);
extern void fn_1_50164(f32, f32, f32, f32, void *);

static inline const char *selection_string(u32 *table) {return (const char *)table[lbl_801A66B4];}
#pragma opt_common_subs off
#pragma opt_propagation off
void fn_10_1C2D8(struct Arg0 *arg0) {


    u32 v0;
    u32 selection_value;
    u32 v12;
    u32 vb4;
    u32 t;
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 ratio;
    char buf[0x100];
    FontDrawPacket loc_54;
    u32 loc_50;
    u32 loc_4C;
    u32 loc_48;
    u32 loc_44;
    u32 loc_40;
    u32 loc_3C;
    u32 loc_38;
    u32 loc_34;
    u32 loc_30;
    u32 loc_2C;
    u32 loc_28;
    u32 loc_24;
    u32 loc_20;
    u32 loc_1C;
    u32 loc_18;
    u32 loc_14;
    u32 loc_10;
    u32 loc_C;
    u32 loc_8;
    u32 *tp;
    const char * lab_t0;

#define IDX (lbl_801A66B4)

    v0 = arg0->unk_0;

    v0 = v0 * 53 + 74;
    loc_54 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_54.image = 0x9E2B;
    loc_54.flags = 5;
    if ((s32)arg0->unk_0 == (s32)((u32)fn_1_D66B0() & 0xFF)) {
        loc_50 = (*(const u32 *)&fzgx_pool_color0);
        *(u8 *)((u8 *)&loc_50 + 0) = (u8)(s32)((120.0) * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9))));
        *(u8 *)((u8 *)&loc_50 + 1) = (u8)(s32)((80.0) * __fabs(lbl_8006D188((s16)(lbl_801A66A0 << 9))));
        *(u32 *)((u8 *)&loc_54 + 60) = loc_50;
    }
    loc_54.x = (356.0f);
    loc_54.y = (f32)(s32)v0;
    fn_1_50164((240.0f), (50.0f), (8.0f), (8.0f), &loc_54);
    if ((s32)arg0->unk_10 == 0) {
        fn_1_49410();
        fn_1_495C8((void *)9);
        fn_1_495B0(0x80000000);
        fn_1_496FC((476.0f), (f32)(s32)(v0 + 25));
        fn_1_4955C((0.666666687f), (0.666666687f));
        loc_4C = (*(const u32 *)&fzgx_pool_color1);
        fn_1_49514(&loc_4C);
        lab_t0 = selection_string(fzgx_pool_sel_5818);
        fn_1_4AE0C(lab_t0);
        return;
    }
    if ((s32)arg0->unk_C == 0) {
        fn_1_49410();
        fn_1_495C8((void *)9);
        fn_1_495B0(0x80000000);
        fn_1_496FC((476.0f), (f32)(s32)(v0 + 25));
        fn_1_4955C((0.666666687f), (0.666666687f));
        tp = fzgx_pool_sel_583C;
        lab_t0 = (const char *)tp[IDX];
        fn_1_4AE0C(lab_t0, arg0->unk_4 + 1);
        return;
    }
    fn_1_49410();
    fn_1_495C8((void *)8);
    fn_1_4966C((0.0f), (4.0f));
    fn_1_4955C((0.458333343f), (0.5f));
    fn_1_49590((0.300000012f));
    fn_1_495B0(0x80000000);
    v12 = v0 + 12;
    loc_54 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_54.image = 0x9E14;
    loc_54.flags = 10;
    f1 = (0.5f);
    vb4 = arg0->unk_4;
    loc_54.u0 = f1 * (f32)(s32)((s32)vb4 % 2);
    loc_54.u1 = f1 + loc_54.u0;
    loc_54.v0 = f1 * (f32)(s32)((s32)vb4 / 2);
    loc_54.v1 = f1 + loc_54.v0;
    loc_54.x = (373.0f);
    loc_54.y = (f32)(s32)(v0 + 12);
    loc_54.scale_x = (0.400000006f);
    loc_54.scale_y = (0.280000001f);
    loc_54.z = (0.0900000036f);
    fn_1_4F734(&loc_54);
    fn_1_495C8((void *)8);
    fn_1_496FC((385.0f), (f32)(s32)v12);
    loc_48 = (*(const u32 *)&fzgx_pool_color2);
    fn_1_49514(&loc_48);
    fn_1_4CE48((Obj_1_bss_4B9CC *)&fzgx_pool_sel_5A00, (62.0f));
    loc_54 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_54.image = 0x9500;
    loc_54.x = (426.0f);
    loc_54.y = (f32)(s32)v12;
    loc_54.z = (0.0799999982f);
    loc_54.scale_x = (0.800000012f);
    loc_54.scale_y = (0.800000012f);
    loc_54.flags = 10;
    fn_1_53FE4((u32)&loc_54, 0);
    fn_1_495C8((void *)10);
    fn_1_496FC((50.0f) + loc_54.x, (f32)(s32)v12);
    fn_1_4CE48((Obj_1_bss_4B9CC *)&fzgx_pool_sel_5A10, (120.0f));
    fn_1_495C8((void *)8);
    if (lbl_801A66B4 == 5) {
        fn_1_496FC((367.0f), (f32)(s32)(v12 + 14));
        loc_44 = (*(const u32 *)&fzgx_pool_color3);
        fn_1_49514(&loc_44);
        fn_1_495C8((void *)8);
        tp = fzgx_pool_sel_569C;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5134, (50.0f), tp[IDX]);
        fn_1_496FC((474.0f), (f32)(s32)(v12 + 14));
        loc_40 = (*(const u32 *)&fzgx_pool_color4);
        fn_1_49514(&loc_40);
        fn_1_495C8((void *)10);
        if (lbl_801A66B4 == 5 || (u32)arg0->unk_24[fn_1_128DD8(lbl_10_bss_5568C)] < 2) {
            selection_value = (u32)arg0->unk_24[fn_1_128DD8(lbl_10_bss_5568C)];
            tp = fzgx_pool_sel_579C;
            fn_1_4CF3C((u32)&fzgx_pool_sel_5A30, (50.0f), selection_value, tp[IDX]);
        } else {
            selection_value = (u32)arg0->unk_24[fn_1_128DD8(lbl_10_bss_5568C)];
            tp = fzgx_pool_sel_579C;
            fn_1_4CF3C((u32)&fzgx_pool_sel_5A38, (50.0f), selection_value, tp[IDX]);
        }
    } else {
        fn_1_496FC((361.0f), (f32)(s32)(v12 + 14));
        loc_3C = (*(const u32 *)&fzgx_pool_color5);
        fn_1_49514(&loc_3C);
        fn_1_495C8((void *)8);
        tp = fzgx_pool_sel_569C;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5134, (65.0f), tp[IDX]);
        fn_1_496FC((479.0f), (f32)(s32)(v12 + 14));
        loc_38 = (*(const u32 *)&fzgx_pool_color6);
        fn_1_49514(&loc_38);
        fn_1_495C8((void *)10);
        if (lbl_801A66B4 == 5 || (u32)arg0->unk_24[fn_1_128DD8(lbl_10_bss_5568C)] < 2) {
            selection_value = (u32)arg0->unk_24[fn_1_128DD8(lbl_10_bss_5568C)];
            tp = fzgx_pool_sel_579C;
            fn_1_4CF3C((u32)&fzgx_pool_sel_5A30, (50.0f), selection_value, tp[IDX]);
        } else {
            selection_value = (u32)arg0->unk_24[fn_1_128DD8(lbl_10_bss_5568C)];
            tp = fzgx_pool_sel_579C;
            fn_1_4CF3C((u32)&fzgx_pool_sel_5A38, (54.0f), selection_value, tp[IDX]);
        }
    }
    if (lbl_801A66B4 == 5) {
        fn_1_496FC((481.0f), (f32)(s32)(v12 + 14));
        loc_34 = (*(const u32 *)&fzgx_pool_color7);
        fn_1_49514(&loc_34);
        fn_1_495C8((void *)8);
        tp = fzgx_pool_sel_5700;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5134, (50.0f), tp[IDX]);
        fn_1_496FC((588.0f), (f32)(s32)(v12 + 14));
        loc_30 = (*(const u32 *)&fzgx_pool_color8);
        fn_1_49514(&loc_30);
        fn_1_495C8((void *)10);
        if (lbl_801A66B4 == 5 || (u32)arg0->unk_30[fn_1_128DD8(lbl_10_bss_5568C)] < 2) {
            selection_value = (u32)arg0->unk_30[fn_1_128DD8(lbl_10_bss_5568C)];
            tp = fzgx_pool_sel_57D8;
            fn_1_4CF3C((u32)&fzgx_pool_sel_5A30, (50.0f), selection_value, tp[IDX]);
        } else {
            selection_value = (u32)arg0->unk_30[fn_1_128DD8(lbl_10_bss_5568C)];
            tp = fzgx_pool_sel_57D8;
            fn_1_4CF3C((u32)&fzgx_pool_sel_5A38, (50.0f), selection_value, tp[IDX]);
        }
    } else {
        fn_1_496FC((479.0f), (f32)(s32)(v12 + 14));
        loc_2C = (*(const u32 *)&fzgx_pool_color9);
        fn_1_49514(&loc_2C);
        fn_1_495C8((void *)8);
        tp = fzgx_pool_sel_5700;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5134, (50.0f), tp[IDX]);
        fn_1_496FC((592.0f), (f32)(s32)(v12 + 14));
        loc_28 = (*(const u32 *)&fzgx_pool_color10);
        fn_1_49514(&loc_28);
        fn_1_495C8((void *)10);
        if (lbl_801A66B4 == 5 || (u32)arg0->unk_30[fn_1_128DD8(lbl_10_bss_5568C)] < 2) {
            selection_value = (u32)arg0->unk_30[fn_1_128DD8(lbl_10_bss_5568C)];
            tp = fzgx_pool_sel_57D8;
            fn_1_4CF3C((u32)&fzgx_pool_sel_5A30, (50.0f), selection_value, tp[IDX]);
        } else {
            selection_value = (u32)arg0->unk_30[fn_1_128DD8(lbl_10_bss_5568C)];
            tp = fzgx_pool_sel_57D8;
            fn_1_4CF3C((u32)&fzgx_pool_sel_5A38, (62.0f), selection_value, tp[IDX]);
        }
    }
    if (lbl_801A66B4 == 5) {
        if ((u32)arg0->unk_3C[fn_1_128DD8(lbl_10_bss_5568C)] == 0) {
            sprintf(buf, (char *)&fzgx_pool_sel_5A40);
        } else {
            sprintf(buf, (char *)&fzgx_pool_sel_5A44, arg0->unk_3C[fn_1_128DD8(lbl_10_bss_5568C)]);
        }
        fn_1_496FC((367.0f), (f32)(s32)(v12 + 28));
        loc_24 = (*(const u32 *)&fzgx_pool_color11);
        fn_1_49514(&loc_24);
        fn_1_495C8((void *)8);
        tp = fzgx_pool_sel_56D0;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5134, (50.0f), tp[IDX]);
        fn_1_496FC((474.0f), (f32)(s32)(v12 + 28));
        loc_20 = (*(const u32 *)&fzgx_pool_color12);
        fn_1_49514(&loc_20);
        fn_1_495C8((void *)10);
        selection_value = (u32)fn_1_5417C((void *)(u32)arg0->unk_3C[fn_1_128DD8(lbl_10_bss_5568C)]);
        tp = fzgx_pool_sel_57C0;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5A48, (50.0f), buf, selection_value, tp[IDX]);
    } else {
        if ((u32)arg0->unk_3C[fn_1_128DD8(lbl_10_bss_5568C)] == 0) {
            sprintf(buf, (char *)&fzgx_pool_sel_5A40);
        } else {
            sprintf(buf, (char *)&fzgx_pool_sel_5A44, arg0->unk_3C[fn_1_128DD8(lbl_10_bss_5568C)]);
        }
        fn_1_496FC((362.0f), (f32)(s32)(v12 + 28));
        loc_1C = (*(const u32 *)&fzgx_pool_color13);
        fn_1_49514(&loc_1C);
        fn_1_495C8((void *)8);
        tp = fzgx_pool_sel_56D0;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5134, (67.0f), tp[IDX]);
        fn_1_496FC((479.0f), (f32)(s32)(v12 + 28));
        loc_18 = (*(const u32 *)&fzgx_pool_color14);
        fn_1_49514(&loc_18);
        fn_1_495C8((void *)10);
        selection_value = (u32)fn_1_5417C((void *)(u32)arg0->unk_3C[fn_1_128DD8(lbl_10_bss_5568C)]);
        tp = fzgx_pool_sel_57C0;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5A48, (54.0f), buf, selection_value, tp[IDX]);
    }
    if (lbl_801A66B4 == 5) {
        if ((u32)arg0->unk_24[fn_1_128DD8(lbl_10_bss_5568C)] != 0) {
            ratio = (f32)(u32)arg0->unk_24[fn_1_128DD8(lbl_10_bss_5568C)];
            f2 = (f32)(u32)arg0->unk_30[fn_1_128DD8(lbl_10_bss_5568C)] / ratio;
            f1 = (100.0f) * f2;
            f1 = (0.5f) + f1;
            sprintf(buf, (char *)&fzgx_pool_sel_5304, __cvt_fp2unsigned(f1));
        } else {
            sprintf(buf, (char *)&fzgx_pool_sel_5A50);
        }
        fn_1_496FC((481.0f), (f32)(s32)(v12 + 28));
        loc_14 = (*(const u32 *)&fzgx_pool_color15);
        fn_1_49514(&loc_14);
        fn_1_495C8((void *)8);
        tp = fzgx_pool_sel_572C;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5134, (50.0f), tp[IDX]);
        fn_1_496FC((588.0f), (f32)(s32)(v12 + 28));
        loc_10 = (*(const u32 *)&fzgx_pool_color16);
        fn_1_49514(&loc_10);
        fn_1_495C8((void *)10);
        tp = fzgx_pool_sel_57F4;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5A54, (50.0f), buf, tp[IDX]);
    } else {
        if ((u32)arg0->unk_24[fn_1_128DD8(lbl_10_bss_5568C)] != 0) {
            ratio = (f32)(u32)arg0->unk_24[fn_1_128DD8(lbl_10_bss_5568C)];
            f2 = (f32)(u32)arg0->unk_30[fn_1_128DD8(lbl_10_bss_5568C)] / ratio;
            f1 = (100.0f) * f2;
            f1 = (0.5f) + f1;
            sprintf(buf, (char *)&fzgx_pool_sel_5304, __cvt_fp2unsigned(f1));
        } else {
            sprintf(buf, (char *)&fzgx_pool_sel_5A50);
        }
        fn_1_496FC((482.0f), (f32)(s32)(v12 + 28));
        loc_C = (*(const u32 *)&fzgx_pool_color17);
        fn_1_49514(&loc_C);
        fn_1_495C8((void *)8);
        tp = fzgx_pool_sel_572C;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5134, (61.0f), tp[IDX]);
        fn_1_496FC((593.0f), (f32)(s32)(v12 + 28));
        loc_8 = (*(const u32 *)&fzgx_pool_color18);
        fn_1_49514(&loc_8);
        fn_1_495C8((void *)10);
        tp = fzgx_pool_sel_57F4;
        fn_1_4CF3C((u32)&fzgx_pool_sel_5A54, (50.0f), buf, tp[IDX]);
    }
}
#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end fn_10_1C2D8 */

/* fzgx:begin fn_10_1E398 */
#include "font.h"

struct fn_10_1E398_lbl_10_rodata_158 {
    u8 pad_0[0x174];
    f32 unk_174;
    u8 pad_178[0x180];
    f32 unk_2F8;
    f32 unk_2FC;
};

extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_10_1E398_lbl_10_rodata_158 lbl_10_rodata_158;
extern FontDrawPacket lbl_1_rodata_26F8;

void fn_10_1E398(void) {
    FontDrawPacket loc;
    struct fn_10_1E398_lbl_10_rodata_158 *p;

    p = (struct fn_10_1E398_lbl_10_rodata_158 *)(u32)&lbl_10_rodata_158;
    loc = lbl_1_rodata_26F8;
    loc.image = 0x10000 - 26089;
    loc.x = p->unk_2F8;
    loc.y = p->unk_2FC;
    loc.z = p->unk_174;
    loc.flags = 10;
    fn_1_4F734(&loc);
}
/* fzgx:end fn_10_1E398 */

/* fzgx:begin fn_10_1E41C pool */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const u32 fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
static const u32 fzgx_pool_table7[15] = {0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 119.0f;
    s = 141.0f;
    s = 160.0f;
    s = 163.0f;
    s = 43.0f;
    s = 130.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 67.5;
    d = 22.5;
    s = 22.5f;
    s = 0.009999999776482582f;
    s = 0.9166666865348816f;
    s = 2.0f;
    s = 240.0f;
    s = 9.999999747378752e-05f;
    s = 278.0f;
    s = 316.0f;
}
static const u32 fzgx_pool_table11[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 250.0f;
    s = 373.0f;
    s = 354.0f;
    s = 68.0f;
    s = 0.8666666746139526f;
    s = -1.0f;
    s = 140.0f;
    s = 50.0f;
    s = 0.10000000149011612f;
    s = 620.0f;
    s = 24.0f;
    s = 10.0f;
}
#pragma section code_type ".text"

extern int fn_10_1E57C(int, int, int);
extern void fn_1_133DBC(void *);
extern void fn_1_13D02C(void);
extern u8 lbl_10_data_5C1C[456];
extern s32 lbl_801A66B4;
extern void fn_10_1E67C(void *);
extern void fn_10_1BCD0(void);
extern void fn_10_1E9CC(int, int, f32, int);
extern void fn_10_1F3B8(int, int, int);
extern void fn_10_1FEF4(int, int, int);
extern void fn_10_210F0(void);

typedef struct {
    u8 pad[0x4a4];
    s32 state;
    s32 previous_state;
    s32 timer;
} SelState;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 fzgx_obj_lbl_10_bss_55680;
u8 lbl_10_bss_55680_gap_55681;
u16 lbl_10_bss_55680_gap_55681_fill_55682;
u32 lbl_10_bss_55684;
u32 lbl_10_bss_55688;
u8 fzgx_obj_lbl_10_bss_5568C;
u8 lbl_10_bss_55680_gap_5568D;
u16 lbl_10_bss_55680_gap_5568D_fill_5568E;
u32 fzgx_obj_lbl_10_bss_55690[2];
u32 fzgx_obj_lbl_10_bss_55698[274];
u16 lbl_10_bss_55AE0;
u16 lbl_10_bss_55680_gap_55AE2;
u32 fzgx_obj_lbl_10_bss_55AE4[8];
u32 lbl_10_bss_55B04_fill_55B04[8];
s32 lbl_10_bss_55B04_20;
s32 lbl_10_bss_55B04_24;
s32 lbl_10_bss_55B04_28;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_10_bss_55680;
    s = *(u8 *)&lbl_10_bss_55680_gap_55681;
    s = *(u8 *)&lbl_10_bss_55680_gap_55681_fill_55682;
    s = *(u8 *)&lbl_10_bss_55684;
    s = *(u8 *)&lbl_10_bss_55688;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_5568C;
    s = *(u8 *)&lbl_10_bss_55680_gap_5568D;
    s = *(u8 *)&lbl_10_bss_55680_gap_5568D_fill_5568E;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_55690;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_55698;
    s = *(u8 *)&lbl_10_bss_55AE0;
    s = *(u8 *)&lbl_10_bss_55680_gap_55AE2;
    s = *(u8 *)&fzgx_obj_lbl_10_bss_55AE4;
    s = *(u8 *)&lbl_10_bss_55B04_fill_55B04;
    s = *(u8 *)&lbl_10_bss_55B04_20;
    s = *(u8 *)&lbl_10_bss_55B04_24;
    s = *(u8 *)&lbl_10_bss_55B04_28;
}
#pragma section code_type ".text"

void fn_10_1E41C(void) {
    
    s32 old_state;
    s32 index;
    f32 progress;
    s32 timer;

    old_state = lbl_10_bss_55B04_20;
    index = fn_10_1E57C(0, 0, 1);
    lbl_10_bss_55B04_20 = index;
    if (old_state != index) {
        timer = 10;
        lbl_10_bss_55B04_24 = old_state;
        lbl_10_bss_55B04_28 = timer;
    }
    timer = lbl_10_bss_55B04_28 - 1;
    lbl_10_bss_55B04_28 = timer > 0 ? timer : 0;
    fn_1_133DBC((void *)1);
    fn_1_13D02C();
    fn_10_1E67C(((void **)lbl_10_data_5C1C)[lbl_801A66B4]);
    fn_10_1BCD0();
    progress = 1.0f;
    fn_10_1E9CC(lbl_10_bss_55B04_20, lbl_10_bss_55B04_28, progress, 0);
    if (lbl_10_bss_55B04_20 >= 12 && lbl_10_bss_55B04_20 <= 18) {
        progress = 0.5f + 0.5f * (f32)lbl_10_bss_55B04_28 / 10.0f;
        fn_10_1E9CC(lbl_10_bss_55B04_24, 0, progress, 0);
    } else {
        fn_10_1E9CC(lbl_10_bss_55B04_24, lbl_10_bss_55B04_28, 1.0f, 1);
    }
    fn_10_1F3B8(lbl_10_bss_55B04_20, lbl_10_bss_55B04_24, lbl_10_bss_55B04_28);
    fn_10_1FEF4(lbl_10_bss_55B04_20, lbl_10_bss_55B04_28, 0);
    fn_10_210F0();
}
/* fzgx:end fn_10_1E41C */

/* fzgx:begin fn_10_1E57C */
#pragma peephole off
int fn_10_1E57C(int arg0, int arg1, int arg2) {
    if (arg2 == 0) {
        return 7;
    }

    switch (arg0) {
    case 0:
        return 1;
    case 1:
        return 100;
    case 2:
        return 3;
    case 4:
        return 5;
    case 5:
        return 2;
    case 6:
        return 6;
    case 8:
        return 16;
    case 9:
        if (arg1) {
            return 109;
        }
        return 108;
    case 10:
        if (arg1) {
            return 9;
        }
        return 8;
    case 11:
        if (arg1) {
            return 111;
        }
        return 110;
    case 12:
        if (arg1) {
            return 11;
        }
        return 10;
    case 13:
        return 12;
    case 14:
        return 13;
    case 15:
        return 101;
    case 18:
        return 15;
    case 19:
        return 17;
    case 20:
        return 18;
    }

    return 999;
}
#pragma peephole reset
/* fzgx:end fn_10_1E57C */

/* fzgx:begin fn_10_1E67C */
extern struct fn_10_1E67C_lbl_10_rodata_158 lbl_10_rodata_158;
extern u32 fn_1_49410(u32);
extern u32 fn_1_4955C(u32, f32, f32);
extern u32 fn_1_49590(u32, f32);
extern u32 fn_1_495B0(u32);
extern u32 fn_1_495C8(u32);
extern u32 fn_1_496FC(u32, f32, f32);
extern u32 fn_1_4AE0C(u32, ...);

struct fn_10_1E67C_lbl_10_rodata_158 {
    u8 pad_0[0x48];
    f32 unk_48;
    u8 pad_4C[0xC];
    f32 unk_58;
    u8 pad_5C[0xBC];
    f32 unk_118;
    u8 pad_11C[0xEE4];
    f32 unk_1000;
};

void fn_10_1E67C(u32 arg0) {
    struct fn_10_1E67C_lbl_10_rodata_158 *p_lbl_10_rodata_158;
    f32 v0;
    u32 t0, t3, t4;
    p_lbl_10_rodata_158 = (struct fn_10_1E67C_lbl_10_rodata_158 *)&lbl_10_rodata_158;
    t0 = fn_1_49410(arg0);
    fn_1_496FC(t0, p_lbl_10_rodata_158->unk_58, p_lbl_10_rodata_158->unk_1000);
    fn_1_495B0(0x80000000);
    t3 = fn_1_495C8(1);
    v0 = p_lbl_10_rodata_158->unk_118;
    t4 = fn_1_4955C(t3, v0, v0);
    fn_1_49590(t4, p_lbl_10_rodata_158->unk_48);
    fn_1_4AE0C(arg0);
}
/* fzgx:end fn_10_1E67C */

/* fzgx:begin fn_10_1E6F4 */
extern s32 lbl_801A66B4;
extern u32 lbl_10_data_5C1C[114];
extern u8 lbl_10_data_1038[4];
extern void fn_80008BEC(void *arg0, int arg1, u32 arg2);

typedef struct {
    u32 f0;
    u32 f4;
    u8 pad8[8];
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
    u8 pad2C[0xC];
    u32 f38;
    u32 f3C;
    u32 f40;
    u8 pad44[8];
    u32 f4C;
} Obj;

s32 fn_10_1E6F4(s32 arg0, Obj *arg1) {
    fn_80008BEC(arg1, 0, 0x50);
    if (((u32)(arg0 - 0x64) <= 1) || ((u32)(arg0 - 1) <= 2) || ((u32)(arg0 - 5) <= 1) || (arg0 == 7)) {
        switch (arg0) {
        case 1:
        case 0x64:
        case 0x65:
            arg1->f4 = lbl_10_data_5C1C[6 + lbl_801A66B4];
            arg1->f14 = lbl_10_data_5C1C[0xc + lbl_801A66B4];
            arg1->f38 = lbl_10_data_5C1C[0x12 + lbl_801A66B4];
            arg1->f18 = (u32)lbl_10_data_1038;
            arg1->f3C = (u32)lbl_10_data_1038;
            arg1->f1C = 6;
            arg1->f40 = 7;
            if (arg0 == 1) {
                arg1->f0 = 1;
            } else if (arg0 == 0x64) {
                arg1->f28 = 1;
                arg1->f4C = 2;
            } else if (arg0 == 0x65) {
                arg1->f0 = 2;
                arg1->f28 = 2;
                arg1->f4C = 1;
            }
            break;
        case 2:
            arg1->f18 = lbl_10_data_5C1C[0x18 + lbl_801A66B4];
            arg1->f1C = 10;
            break;
        case 3:
            arg1->f4 = lbl_10_data_5C1C[0x1e + lbl_801A66B4];
            arg1->f18 = lbl_10_data_5C1C[0x24 + lbl_801A66B4];
            arg1->f1C = 10;
            break;
        case 5:
            arg1->f4 = lbl_10_data_5C1C[0x1e + lbl_801A66B4];
            arg1->f18 = lbl_10_data_5C1C[0x2a + lbl_801A66B4];
            arg1->f1C = 10;
            break;
        case 6:
            arg1->f4 = lbl_10_data_5C1C[0x1e + lbl_801A66B4];
            arg1->f18 = lbl_10_data_5C1C[0x30 + lbl_801A66B4];
            arg1->f1C = 10;
            break;
        case 7:
            arg1->f0 = 1;
            arg1->f4 = lbl_10_data_5C1C[0x36 + lbl_801A66B4];
            arg1->f38 = lbl_10_data_5C1C[0x3c + lbl_801A66B4];
            arg1->f3C = (u32)lbl_10_data_1038;
            arg1->f40 = 7;
            break;
        }
        return 1;
    }
    return 0;
}
/* fzgx:end fn_10_1E6F4 */

/* fzgx:begin fn_10_1F3B8 */
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const u32 fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
static const u32 fzgx_pool_table7[15] = {0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 119.0f;
    s = 141.0f;
    s = 160.0f;
    s = 163.0f;
    s = 43.0f;
    s = 130.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 67.5;
    d = 22.5;
    s = 22.5f;
    s = 0.009999999776482582f;
    s = 0.9166666865348816f;
    s = 2.0f;
    s = 240.0f;
    s = 9.999999747378752e-05f;
    s = 278.0f;
    s = 316.0f;
}
static const u32 fzgx_pool_table11[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 250.0f;
    s = 373.0f;
    s = 354.0f;
    s = 68.0f;
    s = 0.8666666746139526f;
    s = -1.0f;
    s = 140.0f;
    s = 50.0f;
    s = 0.10000000149011612f;
    s = 620.0f;
    s = 24.0f;
    s = 10.0f;
    s = 384.0f;
    s = 640.0f;
    s = 0.5833333134651184f;
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table13[2] = {0x000000FF, 0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 338.0f;
    s = 150.0f;
    s = 15.0f;
    s = 317.0f;
    s = -106.0f;
    s = 318.0f;
    s = 106.0f;
    s = 333.0f;
    s = -87.0f;
    s = 0.09000000357627869f;
    s = -11.0f;
    s = 645.0f;
    s = 721.0f;
    s = 330.0f;
    s = 0.9900000095367432f;
    s = 167.0f;
    s = 38.0f;
}
static const u32 fzgx_pool_table15[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 8.0f;
    s = 366.0f;
    s = 12.0f;
    s = 14.0f;
    s = 0.7599999904632568f;
}
static const u32 fzgx_pool_table17[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.15999984741211f;
    s = 280.0f;
    s = 5.699999809265137f;
    s = 4.5f;
    s = 0.7070000171661377f;
}
static const u32 fzgx_pool_table19[11] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025203E8, 0x03E803E8, 0x03E80000, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 99.0f;
    s = 47.0f;
    s = 67.0f;
    s = 64.0f;
    s = 219.0f;
    s = 594.0f;
    s = 593.0f;
    s = 48.0f;
    s = 0.38999998569488525f;
    s = 0.4274509847164154f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static inline void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 46.0f;
    s = 246.0f;
    s = 120.0f;
    s = 470.0f;
    s = 247.0f;
    s = 45.0f;
    s = 34.0f;
    s = 258.0f;
    s = 0.30000001192092896f;
    s = 328.0f;
    s = 266.0f;
    s = 296.0f;
    s = 326.0f;
    s = 268.0f;
    s = 28.0f;
    s = 298.0f;
}
static const u32 fzgx_pool_table23[26] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025103E8, 0x03E803E8, 0x03E80000, 0x00000001, 0x00020003, 0x00030000, 0x00010002, 0x00020003, 0x00000001, 0x00010002, 0x00030000, 0x00000001, 0x00020002, 0x00000001, 0x00010002, 0x00000000, 0x00000001, 0x00010000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    s = 0.05000000074505806f;
    s = 127.0f;
    s = 3.427000045776367f;
    s = 0.0010000000474974513f;
}
static const u32 fzgx_pool_table25[3] = {0x00000000, 0xC1A00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 343.0f;
    s = 32767.0f;
    s = 2.1764705181121826f;
    s = 1.317647099494934f;
    s = 1.541176438331604f;
    s = 2.4000000953674316f;
    s = 2.4941177368164062f;
    s = 0.29411765933036804f;
    s = 315.0f;
    s = 1.2999999523162842f;
    s = 348.0f;
}
static const u32 fzgx_pool_table27[2] = {0x00000000, 0xFF000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 337.0f;
    s = 0.6600000262260437f;
    s = 0.46000000834465027f;
    s = 63.0f;
    s = 0.800000011920929f;
    s = 0.47999998927116394f;
    s = 1.25f;
    s = 44.0f;
}
static const u32 fzgx_pool_table29[39] = {0x358637BD, 0x00010000, 0x0000A117, 0x0000A118, 0x00000000, 0x00000000, 0x0000A125, 0x0000A126, 0x00010000, 0x00020000, 0x0000A123, 0x0000A124, 0x00020000, 0x00030000, 0x0000A11B, 0x0000A11C, 0x00040000, 0x00040000, 0x0000A121, 0x0000A122, 0x00030000, 0x00070000, 0x0000A11F, 0x0000A120, 0x00070000, 0x00050000, 0x0000A115, 0x0000A116, 0x00050000, 0x00060000, 0x0000A119, 0x0000A11A, 0x00060000, 0x00080000, 0x0000A11D, 0x0000A11E, 0x00040000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 255.0f;
    s = 95.0f;
    s = 180.0f;
    s = 92.0f;
    s = 9.999999046325684f;
    s = 80.0999984741211f;
    s = 83.0f;
    s = 85.0f;
    s = 0.6470588445663452f;
    s = 172.0f;
    s = 84.0f;
}
static const u32 fzgx_pool_table31[55] = {0xFF00FF00, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x0000A102, 0x0000A103, 0x0000A104, 0x0000A105, 0x0000A106, 0x00000000, 0x00000000, 0x00000140, 0x00000000, 0x00000000, 0x00A001E0, 0x00000000, 0x00000082, 0x014001FE, 0x00000000, 0x006200F6, 0x018A021E, 0x021E0050, 0x00C80140, 0x01B80230, 0x00000000, 0x000000B0, 0x008E0074, 0x00000000, 0x0000003D, 0x002C001F, 0xFF83F200, 0x00CAFF00, 0x00F0AE00, 0xF0ECAA00, 0xD4189300, 0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0xA0A0A000, 0x00000000, 0xFFFFFFDF, 0xFFFFFFF5, 0x0000000B, 0x00000021};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const u32 *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 349.0f;
    s = 1.3333333730697632f;
    s = 128.0f;
    s = 30.0f;
    s = 243.0f;
    s = 32.0f;
    s = 175.0f;
}
static const u32 fzgx_pool_table33[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const u32 *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime34(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.75;
    d = 0.25;
}
static const u32 fzgx_pool_table35[25] = {0xC8C8C800, 0x00000000, 0x00FF00FF, 0x00FF00FF, 0xFF960300, 0x00FF00FF, 0xFFED0000, 0x002C0014, 0x00140014, 0x00140014, 0x002C0000, 0x00600052, 0x00520052, 0x00520060, 0x00000008, 0x00000094, 0x00000008, 0x0000009A, 0x00000008, 0x00000094, 0x00000008, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFF00FF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep35(void) { const u32 *volatile cp; cp = fzgx_pool_table35; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime36(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 74.0f;
    s = 304.0f;
    s = 208.0f;
    s = 86.0f;
    s = 112.0f;
    s = 256.0f;
    s = 139.0f;
    s = 151.0f;
    s = 0.7200000286102295f;
    s = 220.0f;
    s = 231.0f;
    s = 102.0f;
    s = 329.0f;
    s = 70.0f;
    s = 79.0f;
    s = 345.0f;
    s = 0.125f;
    s = 377.0f;
    s = 389.0f;
}
static const u32 fzgx_pool_table37[35] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF00FF00, 0x000B000C, 0x000D000E, 0xFFFF000F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep37(void) { const u32 *volatile cp; cp = fzgx_pool_table37; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime38(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 350.0f;
    s = 252.0f;
    s = 244.0f;
    s = 52.0f;
    s = 62.0f;
    s = 0.47058823704719543f;
    s = 0.6196078658103943f;
}
static const u32 fzgx_pool_table39[2] = {0x00FF00FF, 0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep39(void) { const u32 *volatile cp; cp = fzgx_pool_table39; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime40(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.875f;
    s = 0.1666666716337204f;
    s = 0.1428571492433548f;
    s = 0.10000000894069672f;
    s = 0.08571429550647736f;
    s = 0.8333333730697632f;
    s = 0.8571429252624512f;
}
static const u32 fzgx_pool_table41[1] = {0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep41(void) { const u32 *volatile cp; cp = fzgx_pool_table41; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime42(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.1411764770746231f;
    s = 109.07058715820312f;
    s = -15.0f;
    s = 19.0f;
    s = -4.5f;
    s = -17.5f;
    s = 89.0f;
    s = 0.6274510025978088f;
    s = 0.007843137718737125f;
    s = 7.0f;
    s = 0.14901961386203766f;
    s = 586.0f;
    s = 400.0f;
    d = 0.55;
    s = 0.8299999833106995f;
}
static const u32 fzgx_pool_table43[1] = {0x00100000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep43(void) { const u32 *volatile cp; cp = fzgx_pool_table43; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime44(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5600000023841858f;
    s = 0.8899999856948853f;
    s = 0.019999999552965164f;
    s = 0.8799999952316284f;
}
static const u32 fzgx_pool_table45[1] = {0x000F0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep45(void) { const u32 *volatile cp; cp = fzgx_pool_table45; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime46(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4699999988079071f;
    s = 0.8100000023841858f;
}
static const u32 fzgx_pool_table47[4] = {0x3C23D70A, 0x3F4F5C29, 0x00130000, 0x3EF5C28F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep47(void) { const u32 *volatile cp; cp = fzgx_pool_table47; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime48(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9100000262260437f;
}
static const u32 fzgx_pool_table49[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep49(void) { const u32 *volatile cp; cp = fzgx_pool_table49; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime50(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8399999737739563f;
}
static const u32 fzgx_pool_table51[1] = {0x00170000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep51(void) { const u32 *volatile cp; cp = fzgx_pool_table51; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime52(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.49000000953674316f;
}
static const u32 fzgx_pool_table53[1] = {0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep53(void) { const u32 *volatile cp; cp = fzgx_pool_table53; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime54(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
}
static const u32 fzgx_pool_table55[2] = {0x3F570A3D, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep55(void) { const u32 *volatile cp; cp = fzgx_pool_table55; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime56(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5199999809265137f;
}
static const u32 fzgx_pool_table57[4] = {0x3F6147AE, 0x3C23D70A, 0x3F570A3D, 0x00240000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep57(void) { const u32 *volatile cp; cp = fzgx_pool_table57; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime58(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
    s = 0.8600000143051147f;
}
static const u32 fzgx_pool_table59[1] = {0x3C23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep59(void) { const u32 *volatile cp; cp = fzgx_pool_table59; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime60(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8500000238418579f;
}
static const u32 fzgx_pool_table61[2] = {0x000D0000, 0x3EF0A3D7};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep61(void) { const u32 *volatile cp; cp = fzgx_pool_table61; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime62(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8700000047683716f;
}
static const u32 fzgx_pool_table63[4] = {0x3C23D70A, 0x3F570A3D, 0x00180000, 0x3F11EB85};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep63(void) { const u32 *volatile cp; cp = fzgx_pool_table63; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime64(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0700000524520874f;
}
static const u32 fzgx_pool_table65[3] = {0xBC23D70A, 0x3F63D70A, 0x00170000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep65(void) { const u32 *volatile cp; cp = fzgx_pool_table65; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime66(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6399999856948853f;
}
static const u32 fzgx_pool_table67[2] = {0x3F63D70A, 0x3CA3D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep67(void) { const u32 *volatile cp; cp = fzgx_pool_table67; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime68(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.7900000214576721f;
}
static const u32 fzgx_pool_table69[6] = {0x00050000, 0x3EF0A3D7, 0x3F6147AE, 0x3C23D70A, 0x3F547AE1, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep69(void) { const u32 *volatile cp; cp = fzgx_pool_table69; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime70(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6299999952316284f;
}
static const u32 fzgx_pool_table71[1] = {0x3F63D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep71(void) { const u32 *volatile cp; cp = fzgx_pool_table71; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime72(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05999999865889549f;
}
static const u32 fzgx_pool_table73[2] = {0x3F4A3D71, 0x000B0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep73(void) { const u32 *volatile cp; cp = fzgx_pool_table73; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime74(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4399999976158142f;
}
static const u32 fzgx_pool_table75[14] = {0x3F400000, 0x00000000, 0x3F59999A, 0x00160000, 0x3EE147AE, 0x3F6147AE, 0x3C23D70A, 0x3F570A3D, 0x00120000, 0x3EF5C28F, 0x3F59999A, 0x3C23D70A, 0x3F59999A, 0x001D0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep75(void) { const u32 *volatile cp; cp = fzgx_pool_table75; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime76(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6800000071525574f;
    s = 0.9599999785423279f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table77[2] = {0x3F4F5C29, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep77(void) { const u32 *volatile cp; cp = fzgx_pool_table77; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime78(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.3700000047683716f;
}
static const u32 fzgx_pool_table79[9] = {0x3F800000, 0x3CF5C28F, 0x3F5C28F6, 0x000B0000, 0x3F000000, 0x3F5EB852, 0x3C23D70A, 0x3F570A3D, 0x00140000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep79(void) { const u32 *volatile cp; cp = fzgx_pool_table79; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime80(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4300000071525574f;
}
static const u32 fzgx_pool_table81[1] = {0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep81(void) { const u32 *volatile cp; cp = fzgx_pool_table81; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime82(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03999999910593033f;
}
static const u32 fzgx_pool_table83[17] = {0x3F547AE1, 0x000F0000, 0x3F2147AE, 0x3F5C28F6, 0x00000000, 0x3F5EB852, 0x00030000, 0x3F051EB8, 0x3F4A3D71, 0x3C23D70A, 0x3F59999A, 0x00050000, 0x3F000000, 0x3F59999A, 0x3C23D70A, 0x3F5C28F6, 0x00150000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep83(void) { const u32 *volatile cp; cp = fzgx_pool_table83; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime84(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5799999833106995f;
}
static const u32 fzgx_pool_table85[4] = {0x3F428F5C, 0x3C23D70A, 0x3F570A3D, 0x00080000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep85(void) { const u32 *volatile cp; cp = fzgx_pool_table85; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime86(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.44999998807907104f;
}
static const u32 fzgx_pool_table87[5] = {0x3F63D70A, 0x3CF5C28F, 0x3F5C28F6, 0x001E0000, 0x3EFAE148};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep87(void) { const u32 *volatile cp; cp = fzgx_pool_table87; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime88(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9200000166893005f;
}
static const u32 fzgx_pool_table89[14] = {0x3C23D70A, 0x3F59999A, 0x00000000, 0x3EE147AE, 0x3F6147AE, 0x3C23D70A, 0x3F5C28F6, 0x00160000, 0x3EDC28F6, 0x3F63D70A, 0x00000000, 0x3F4CCCCD, 0x00100000, 0x3F051EB8};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep89(void) { const u32 *volatile cp; cp = fzgx_pool_table89; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime90(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6899999976158142f;
}
static const u32 fzgx_pool_table91[8] = {0x3CA3D70A, 0x3F59999A, 0x00060000, 0x3EF0A3D7, 0x3F400000, 0xBC23D70A, 0x3F59999A, 0x00190000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static inline void fzgx_pool_keep91(void) { const u32 *volatile cp; cp = fzgx_pool_table91; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime92(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5899999737739563f;
}
static const u32 fzgx_pool_table93[2] = {0x3F570A3D, 0x3CF5C28F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep93(void) { const u32 *volatile cp; cp = fzgx_pool_table93; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime94(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8199999928474426f;
}
static const u32 fzgx_pool_table95[1] = {0x00050000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep95(void) { const u32 *volatile cp; cp = fzgx_pool_table95; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime96(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5099999904632568f;
}
static const u32 fzgx_pool_table97[5] = {0x3F5C28F6, 0x00000000, 0x3F570A3D, 0x00040000, 0x3EF0A3D7};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep97(void) { const u32 *volatile cp; cp = fzgx_pool_table97; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime98(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.949999988079071f;
}
static const u32 fzgx_pool_table99[14] = {0x3C23D70A, 0x3F51EB85, 0x00100000, 0x3F28F5C3, 0x3F7D70A4, 0x3D23D70A, 0x3F6147AE, 0x000B0000, 0x3EE66666, 0x3F63D70A, 0x3C23D70A, 0x3F570A3D, 0x00060000, 0x3F333333};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep99(void) { const u32 *volatile cp; cp = fzgx_pool_table99; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime100(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2899999618530273f;
}
static const u32 fzgx_pool_table101[18] = {0xBC23D70A, 0x3F59999A, 0x00030000, 0x3EF0A3D7, 0x3F5EB852, 0x3C23D70A, 0x3F68F5C3, 0x00080000, 0x3EF5C28F, 0x3F6B851F, 0x00000000, 0x3F570A3D, 0x00060000, 0x3EE147AE, 0x3F547AE1, 0x00000000, 0x3F4A3D71, 0x00070000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep101(void) { const u32 *volatile cp; cp = fzgx_pool_table101; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime102(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4099999964237213f;
    s = 0.9700000286102295f;
}
static const u32 fzgx_pool_table103[3] = {0x3C23D70A, 0x3F51EB85, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep103(void) { const u32 *volatile cp; cp = fzgx_pool_table103; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime104(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.7300000190734863f;
}
static const u32 fzgx_pool_table105[11] = {0x3F63D70A, 0x3CF5C28F, 0x3F4F5C29, 0x00000000, 0x3F75C28F, 0x3F5EB852, 0x3CA3D70A, 0x3F59999A, 0x00050000, 0x3EEB851F, 0x3F51EB85};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep105(void) { const u32 *volatile cp; cp = fzgx_pool_table105; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime106(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.019999999552965164f;
}
static const u32 fzgx_pool_table107[1] = {0x3F59999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep107(void) { const u32 *volatile cp; cp = fzgx_pool_table107; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime108(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 88.0f;
    s = 116.0f;
    s = 16.0f;
    s = 340.0f;
    s = 335.0f;
    s = 397.0f;
}
static const u32 fzgx_pool_table109[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep109(void) { const u32 *volatile cp; cp = fzgx_pool_table109; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime110(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.49;
}
static const u32 fzgx_pool_table111[1] = {0x3F5C28F6};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep111(void) { const u32 *volatile cp; cp = fzgx_pool_table111; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime112(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.05999999865889549f;
}
static const u32 fzgx_pool_table113[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep113(void) { const u32 *volatile cp; cp = fzgx_pool_table113; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime114(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 36.0f;
    s = 21.0f;
}
static const u32 fzgx_pool_table115[18] = {0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep115(void) { const u32 *volatile cp; cp = fzgx_pool_table115; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime116(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 132.0f;
}
static const u32 fzgx_pool_table117[50] = {0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42D40000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep117(void) { const u32 *volatile cp; cp = fzgx_pool_table117; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime118(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 138.0f;
}
static const u32 fzgx_pool_table119[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep119(void) { const u32 *volatile cp; cp = fzgx_pool_table119; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime120(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 126.0f;
}
static const u32 fzgx_pool_table121[17] = {0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep121(void) { const u32 *volatile cp; cp = fzgx_pool_table121; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime122(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 124.0f;
}
static const u32 fzgx_pool_table123[104] = {0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x43000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42AC0000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42AC0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep123(void) { const u32 *volatile cp; cp = fzgx_pool_table123; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime124(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 148.0f;
}
static const u32 fzgx_pool_table125[38] = {0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42D40000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x430A0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep125(void) { const u32 *volatile cp; cp = fzgx_pool_table125; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime126(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 205.0f;
    s = 442.0f;
    s = 200.0f;
    s = -2.9000000953674316f;
}
static const u32 fzgx_pool_table127[1] = {0x3F23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep127(void) { const u32 *volatile cp; cp = fzgx_pool_table127; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime128(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 41.0f;
    s = 217.0f;
    s = 313.0f;
}
static const u32 fzgx_pool_table129[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep129(void) { const u32 *volatile cp; cp = fzgx_pool_table129; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime130(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 428.0f;
    s = 239.0f;
    s = 0.10999999940395355f;
    s = 0.37662336230278015f;
    s = 0.9090909361839294f;
    s = 0.09090909361839294f;
    s = 0.41558441519737244f;
    s = 0.8116883039474487f;
    s = 0.3961038887500763f;
    s = 0.8831169009208679f;
    s = 0.025974025949835777f;
    s = 578.0f;
    s = 0.10500000417232513f;
    s = 0.375f;
    s = 203.0f;
    s = 272.0f;
    s = 206.0f;
    s = 275.0f;
    s = 0.11500000208616257f;
    s = 8.25f;
    s = 271.0f;
}
static const u32 fzgx_pool_table131[1] = {0x43140000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep131(void) { const u32 *volatile cp; cp = fzgx_pool_table131; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime132(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 147.0f;
    s = 492.0f;
}
static const u32 fzgx_pool_table133[4] = {0x161846FF, 0x161846FF, 0x161846FF, 0x161846FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep133(void) { const u32 *volatile cp; cp = fzgx_pool_table133; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime134(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 436.0f;
    s = 300.0f;
    s = 388.0f;
}
static const u32 fzgx_pool_table135[1] = {0xA0FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep135(void) { const u32 *volatile cp; cp = fzgx_pool_table135; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime136(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4166666567325592f;
    s = 216.0f;
    s = 27.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table137[20] = {0x00000000, 0x606060FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep137(void) { const u32 *volatile cp; cp = fzgx_pool_table137; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime138(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 120.0;
    d = 80.0;
    s = 356.0f;
    s = 476.0f;
    s = 0.2800000011920929f;
    s = 385.0f;
    s = 426.0f;
    s = 0.07999999821186066f;
    s = 474.0f;
    s = 361.0f;
    s = 65.0f;
    s = 479.0f;
    s = 54.0f;
    s = 481.0f;
    s = 588.0f;
    s = 592.0f;
    s = 482.0f;
}
static const u32 fzgx_pool_table139[27] = {0x00000000, 0x606060FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep139(void) { const u32 *volatile cp; cp = fzgx_pool_table139; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime140(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 142.0f;
    s = 39.0f;
    s = 66.0f;
}
static const u32 fzgx_pool_table141[27] = {0x00000000, 0x606060FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep141(void) { const u32 *volatile cp; cp = fzgx_pool_table141; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime142(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 324.0f;
    s = 473.0f;
    s = 311.0f;
    s = 306.0f;
    s = 312.0f;
    s = 412.0f;
    s = 418.0f;
    s = 305.0f;
    s = 395.0f;
    s = 402.0f;
}
static const u32 fzgx_pool_table143[1] = {0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep143(void) { const u32 *volatile cp; cp = fzgx_pool_table143; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime144(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -640.0f;
}
#pragma section code_type ".text"

extern u32 fn_10_F050(s32, s32);
extern u32 fn_10_1F688(s32, u32, f32);
extern f32 lbl_8006D188(s32);

void fn_10_1F3B8(s32 a, s32 b, s32 c) {
    s32 r30 = 0;
    s32 r6 = 0;
    f32 f31 = 1.0f;
    u32 r29 = 0;

    if (((u32)(a - 8) <= 3) || ((u32)(a - 0x6c) <= 2) || a == 0x6f) {
        if (((u32)(b - 8) <= 3) || ((u32)(b - 0x6c) <= 2) || b == 0x6f) {
            if (a >= 100) {
                r6 = (s32)(8192.0f * lbl_8006D188((s32)(65536.0f * (f32)(c % 20) / 20.0f)));
            } else {
                r6 = (s32)(-8192.0f * lbl_8006D188((s32)(65536.0f * (f32)(c % 20) / 20.0f)));
            }
        } else {
            r30 = (s32)(-640.0f * (f32)c / 10.0f);
        }
    } else if (((u32)(b - 8) <= 3) || ((u32)(b - 0x6c) <= 2) || b == 0x6f) {
        a = b;
        r29 = 0x20000000;
        f31 = 0.5f + (0.5f * (f32)c) / 10.0f;
    } else {
        return;
    }

    fn_10_F050(r30, r6);
    switch (a) {
    case 8:    r29 |= 0xd0000000; break;
    case 9:    r29 |= (0x80000000 | 0x40000000); break;
    case 10:   r29 |= 0x48000000; break;
    case 11:   r29 |= 0x40000000; break;
    case 0x6c: r29 |= 0x90000000; break;
    case 0x6d: r29 |= 0x80000000; break;
    case 0x6e: r29 |= 0x08000000; break;
    case 0x6f: break;
    }
    fn_10_1F688(r30, r29, f31);
}
/* fzgx:end fn_10_1F3B8 */

/* fzgx:begin fn_10_1FEF4 */
extern f32 lbl_10_rodata_158[19];
extern u8 jumptable_10_data_67E0[28];
extern u8 lbl_10_data_5C1C[456];
extern u8 lbl_10_data_1038[4];
extern s32 lbl_801A66B4;

extern void fn_1_49410(void);
extern void fn_1_495B0(s32 value);
extern void fn_1_496FC(f32 arg0, f32 arg1);
extern void fn_1_4954C(f32 value);
extern void fn_1_4955C(f32 arg0, f32 arg1);
extern void fn_1_495C8(s32 value);
extern void fn_1_49590(f32 value);
extern void fn_1_4CE48(u8 *arg0, f32 value);
extern f32 fn_1_4B090(u8 *arg0);
extern void fn_1_53B14(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5);

void fn_10_1FEF4(s32 arg0) {
    f32 *constants = lbl_10_rodata_158;
    u8 *value;
    s32 index;
    s32 inRange;

    if (arg0 - 12 < 0) {
        index = 0;
    } else {
        index = arg0 - 12 > 6 ? 6 : arg0 - 12;
    }

    switch (index) {
    case 0:
        value = ((u8 **)(lbl_10_data_5C1C + 0x138))[lbl_801A66B4];
        break;
    case 1:
        value = ((u8 **)(lbl_10_data_5C1C + 0x150))[lbl_801A66B4];
        break;
    case 2:
        value = lbl_10_data_1038;
        break;
    case 3:
        value = ((u8 **)(lbl_10_data_5C1C + 0x168))[lbl_801A66B4];
        break;
    case 4:
        value = ((u8 **)(lbl_10_data_5C1C + 0x180))[lbl_801A66B4];
        break;
    case 5:
        value = ((u8 **)(lbl_10_data_5C1C + 0x198))[lbl_801A66B4];
        break;
    case 6:
        value = ((u8 **)(lbl_10_data_5C1C + 0x1b0))[lbl_801A66B4];
        break;
    }

    inRange = arg0 - 12 > 6 ? 0 : !(arg0 - 12 < 0);
    if (inRange) {
        fn_1_49410();
        fn_1_495B0(-2147483648);
        fn_1_496FC(constants[22], constants[1160]);
        fn_1_4954C((f32)((f64)constants[1161] - *(f64 *)(constants + 1162)));
        fn_1_4955C(constants[112], constants[112]);
        fn_1_495C8(9);
        fn_1_49590(constants[18]);
        fn_1_4CE48(value, constants[1164]);
        fn_1_53B14(0, constants[22], constants[1160],
            constants[1134], constants[1165] + fn_1_4B090(value),
            constants[1161]);
    }
}
/* fzgx:end fn_10_1FEF4 */

/* fzgx:begin fn_10_21978 */
#include "font.h"

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[17] = {0x00000000, 0x0000B500, 0x0000B600, 0x0000AD00, 0x0000B300, 0x0000B800, 0x0000B200, 0x0000B100, 0x0000AE00, 0x0000B400, 0x0000B900, 0x0000B000, 0x0000AF00, 0x0000B700, 0x00000000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    s = 0.5f;
    s = 0.0f;
    s = 0.20000000298023224f;
    s = 0.4000000059604645f;
    s = 320.0f;
    s = 3.0f;
    s = 323.0f;
    s = 4.0f;
    s = 5.0f;
    s = 6.0f;
    s = 0.25f;
    s = 16384.0f;
    s = 65536.0f;
    s = 60.0f;
    s = 1.875f;
    s = 0.5555555820465088f;
    d = 4503601774854144.0;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table3[24] = {0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00000000, 0x00F0F0FF, 0x00000000, 0x00F0F0FF, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00110012, 0x00130014, 0x00150012, 0x00130014, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 59.0f;
    s = 82.0f;
    s = 77.0f;
    s = 98.0f;
    s = 25.0f;
    s = 115.0f;
    s = 0.699999988079071f;
    s = 9.0f;
    s = 0.6666666865348816f;
    s = 431.0f;
}
static const u32 fzgx_pool_table5[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 61.0f;
    s = 81.0f;
    s = 110.0f;
    s = 40.0f;
    s = 80.0f;
    s = 210.0f;
    s = 230.0f;
    s = 367.0f;
    s = 55.0f;
    s = 76.0f;
    s = 100.0f;
    s = 365.0f;
    s = 75.0f;
    s = 117.0f;
    s = 0.4583333432674408f;
    s = 165.0f;
    s = 155.0f;
    s = 87.0f;
    s = 184.0f;
    s = 90.0f;
    s = 381.0f;
    s = 475.0f;
    s = 174.0f;
    s = 423.0f;
    s = 194.0f;
    s = 8192.0f;
    s = 20.0f;
    s = -8192.0f;
    s = 362.0f;
    s = 524.0f;
    s = 72.0f;
    s = 11.0f;
    s = 0.8999999761581421f;
    s = 0.5416666865348816f;
    s = -4.0f;
    s = 334.0f;
    s = 341.0f;
    s = -6.0f;
    s = 0.625f;
    s = 346.0f;
    s = 211.0f;
    s = 161.0f;
    s = 192.0f;
    s = 0.07000000029802322f;
}
static const u32 fzgx_pool_table7[15] = {0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000, 0xFFFFFF00, 0x00FF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 119.0f;
    s = 141.0f;
    s = 160.0f;
    s = 163.0f;
    s = 43.0f;
    s = 130.0f;
}
static const u32 fzgx_pool_table9[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 90.0;
    d = 67.5;
    d = 22.5;
    s = 22.5f;
    s = 0.009999999776482582f;
    s = 0.9166666865348816f;
    s = 2.0f;
    s = 240.0f;
    s = 9.999999747378752e-05f;
    s = 278.0f;
    s = 316.0f;
}
static const u32 fzgx_pool_table11[1] = {0xFFFFFFFF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 250.0f;
    s = 373.0f;
    s = 354.0f;
    s = 68.0f;
    s = 0.8666666746139526f;
    s = -1.0f;
    s = 140.0f;
    s = 50.0f;
    s = 0.10000000149011612f;
    s = 620.0f;
    s = 24.0f;
    s = 10.0f;
    s = 384.0f;
    s = 640.0f;
    s = 0.5833333134651184f;
    s = 0.6000000238418579f;
}
static const u32 fzgx_pool_table13[2] = {0x000000FF, 0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 17.0f;
    s = 338.0f;
    s = 150.0f;
    s = 15.0f;
    s = 317.0f;
    s = -106.0f;
    s = 318.0f;
    s = 106.0f;
    s = 333.0f;
    s = -87.0f;
    s = 0.09000000357627869f;
    s = -11.0f;
    s = 645.0f;
    s = 721.0f;
    s = 330.0f;
    s = 0.9900000095367432f;
    s = 167.0f;
    s = 38.0f;
}
static const u32 fzgx_pool_table15[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep15(void) { const u32 *volatile cp; cp = fzgx_pool_table15; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime16(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 8.0f;
    s = 366.0f;
    s = 12.0f;
    s = 14.0f;
    s = 0.7599999904632568f;
}
static const u32 fzgx_pool_table17[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep17(void) { const u32 *volatile cp; cp = fzgx_pool_table17; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime18(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 60.15999984741211f;
    s = 280.0f;
    s = 5.699999809265137f;
    s = 4.5f;
    s = 0.7070000171661377f;
}
static const u32 fzgx_pool_table19[11] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025203E8, 0x03E803E8, 0x03E80000, 0x80808000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep19(void) { const u32 *volatile cp; cp = fzgx_pool_table19; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime20(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 99.0f;
    s = 47.0f;
    s = 67.0f;
    s = 64.0f;
    s = 219.0f;
    s = 594.0f;
    s = 593.0f;
    s = 48.0f;
    s = 0.38999998569488525f;
    s = 0.4274509847164154f;
}
static const u32 fzgx_pool_table21[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep21(void) { const u32 *volatile cp; cp = fzgx_pool_table21; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime22(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 46.0f;
    s = 246.0f;
    s = 120.0f;
    s = 470.0f;
    s = 247.0f;
    s = 45.0f;
    s = 34.0f;
    s = 258.0f;
    s = 0.30000001192092896f;
    s = 328.0f;
    s = 266.0f;
    s = 296.0f;
    s = 326.0f;
    s = 268.0f;
    s = 28.0f;
    s = 298.0f;
}
static const u32 fzgx_pool_table23[26] = {0xFF9CFF9C, 0xFF9CFF9C, 0x00310069, 0x009F00D5, 0x010B0141, 0x017701AD, 0x01E30219, 0x025103E8, 0x03E803E8, 0x03E80000, 0x00000001, 0x00020003, 0x00030000, 0x00010002, 0x00020003, 0x00000001, 0x00010002, 0x00030000, 0x00000001, 0x00020002, 0x00000001, 0x00010002, 0x00000000, 0x00000001, 0x00010000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep23(void) { const u32 *volatile cp; cp = fzgx_pool_table23; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime24(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 182.04444885253906f;
    s = 0.05000000074505806f;
    s = 127.0f;
    s = 3.427000045776367f;
    s = 0.0010000000474974513f;
}
static const u32 fzgx_pool_table25[3] = {0x00000000, 0xC1A00000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep25(void) { const u32 *volatile cp; cp = fzgx_pool_table25; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime26(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 343.0f;
    s = 32767.0f;
    s = 2.1764705181121826f;
    s = 1.317647099494934f;
    s = 1.541176438331604f;
    s = 2.4000000953674316f;
    s = 2.4941177368164062f;
    s = 0.29411765933036804f;
    s = 315.0f;
    s = 1.2999999523162842f;
    s = 348.0f;
}
static const u32 fzgx_pool_table27[2] = {0x00000000, 0xFF000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep27(void) { const u32 *volatile cp; cp = fzgx_pool_table27; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime28(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 337.0f;
    s = 0.6600000262260437f;
    s = 0.46000000834465027f;
    s = 63.0f;
    s = 0.800000011920929f;
    s = 0.47999998927116394f;
    s = 1.25f;
    s = 44.0f;
}
static const u32 fzgx_pool_table29[39] = {0x358637BD, 0x00010000, 0x0000A117, 0x0000A118, 0x00000000, 0x00000000, 0x0000A125, 0x0000A126, 0x00010000, 0x00020000, 0x0000A123, 0x0000A124, 0x00020000, 0x00030000, 0x0000A11B, 0x0000A11C, 0x00040000, 0x00040000, 0x0000A121, 0x0000A122, 0x00030000, 0x00070000, 0x0000A11F, 0x0000A120, 0x00070000, 0x00050000, 0x0000A115, 0x0000A116, 0x00050000, 0x00060000, 0x0000A119, 0x0000A11A, 0x00060000, 0x00080000, 0x0000A11D, 0x0000A11E, 0x00040000, 0x00000000, 0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep29(void) { const u32 *volatile cp; cp = fzgx_pool_table29; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime30(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 255.0f;
    s = 95.0f;
    s = 180.0f;
    s = 92.0f;
    s = 9.999999046325684f;
    s = 80.0999984741211f;
    s = 83.0f;
    s = 85.0f;
    s = 0.6470588445663452f;
    s = 172.0f;
    s = 84.0f;
}
static const u32 fzgx_pool_table31[55] = {0xFF00FF00, 0x00010002, 0x00030004, 0x00050006, 0x00070008, 0x0009000A, 0x000B000C, 0x00170018, 0x0019001A, 0x001B001C, 0x001D001E, 0x001F0021, 0x00220000, 0x0000A102, 0x0000A103, 0x0000A104, 0x0000A105, 0x0000A106, 0x00000000, 0x00000000, 0x00000140, 0x00000000, 0x00000000, 0x00A001E0, 0x00000000, 0x00000082, 0x014001FE, 0x00000000, 0x006200F6, 0x018A021E, 0x021E0050, 0x00C80140, 0x01B80230, 0x00000000, 0x000000B0, 0x008E0074, 0x00000000, 0x0000003D, 0x002C001F, 0xFF83F200, 0x00CAFF00, 0x00F0AE00, 0xF0ECAA00, 0xD4189300, 0x00000000, 0x00000001, 0x00000002, 0x00000003, 0x00000004, 0xA0A0A000, 0x00000000, 0xFFFFFFDF, 0xFFFFFFF5, 0x0000000B, 0x00000021};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep31(void) { const u32 *volatile cp; cp = fzgx_pool_table31; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime32(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 349.0f;
    s = 1.3333333730697632f;
    s = 128.0f;
    s = 30.0f;
    s = 243.0f;
    s = 32.0f;
    s = 175.0f;
}
static const u32 fzgx_pool_table33[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep33(void) { const u32 *volatile cp; cp = fzgx_pool_table33; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime34(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.75;
    d = 0.25;
}
static const u32 fzgx_pool_table35[25] = {0xC8C8C800, 0x00000000, 0x00FF00FF, 0x00FF00FF, 0xFF960300, 0x00FF00FF, 0xFFED0000, 0x002C0014, 0x00140014, 0x00140014, 0x002C0000, 0x00600052, 0x00520052, 0x00520060, 0x00000008, 0x00000094, 0x00000008, 0x0000009A, 0x00000008, 0x00000094, 0x00000008, 0xFFFFFF00, 0x00000000, 0x00000000, 0xFF00FF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep35(void) { const u32 *volatile cp; cp = fzgx_pool_table35; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime36(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 74.0f;
    s = 304.0f;
    s = 208.0f;
    s = 86.0f;
    s = 112.0f;
    s = 256.0f;
    s = 139.0f;
    s = 151.0f;
    s = 0.7200000286102295f;
    s = 220.0f;
    s = 231.0f;
    s = 102.0f;
    s = 329.0f;
    s = 70.0f;
    s = 79.0f;
    s = 345.0f;
    s = 0.125f;
    s = 377.0f;
    s = 389.0f;
}
static const u32 fzgx_pool_table37[35] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFF00FF00, 0x000B000C, 0x000D000E, 0xFFFF000F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep37(void) { const u32 *volatile cp; cp = fzgx_pool_table37; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime38(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 350.0f;
    s = 252.0f;
    s = 244.0f;
    s = 52.0f;
    s = 62.0f;
    s = 0.47058823704719543f;
    s = 0.6196078658103943f;
}
static const u32 fzgx_pool_table39[2] = {0x00FF00FF, 0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep39(void) { const u32 *volatile cp; cp = fzgx_pool_table39; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime40(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 136.0f;
    s = 0.875f;
    s = 0.1666666716337204f;
    s = 0.1428571492433548f;
    s = 0.10000000894069672f;
    s = 0.08571429550647736f;
    s = 0.8333333730697632f;
    s = 0.8571429252624512f;
}
static const u32 fzgx_pool_table41[1] = {0x00F0F0FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep41(void) { const u32 *volatile cp; cp = fzgx_pool_table41; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime42(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.1411764770746231f;
    s = 109.07058715820312f;
    s = -15.0f;
    s = 19.0f;
    s = -4.5f;
    s = -17.5f;
    s = 89.0f;
    s = 0.6274510025978088f;
    s = 0.007843137718737125f;
    s = 7.0f;
    s = 0.14901961386203766f;
    s = 586.0f;
    s = 400.0f;
    d = 0.55;
    s = 0.8299999833106995f;
}
static const u32 fzgx_pool_table43[1] = {0x00100000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep43(void) { const u32 *volatile cp; cp = fzgx_pool_table43; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime44(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5600000023841858f;
    s = 0.8899999856948853f;
    s = 0.019999999552965164f;
    s = 0.8799999952316284f;
}
static const u32 fzgx_pool_table45[1] = {0x000F0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep45(void) { const u32 *volatile cp; cp = fzgx_pool_table45; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime46(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4699999988079071f;
    s = 0.8100000023841858f;
}
static const u32 fzgx_pool_table47[4] = {0x3C23D70A, 0x3F4F5C29, 0x00130000, 0x3EF5C28F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep47(void) { const u32 *volatile cp; cp = fzgx_pool_table47; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime48(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9100000262260437f;
}
static const u32 fzgx_pool_table49[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep49(void) { const u32 *volatile cp; cp = fzgx_pool_table49; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime50(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8399999737739563f;
}
static const u32 fzgx_pool_table51[1] = {0x00170000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep51(void) { const u32 *volatile cp; cp = fzgx_pool_table51; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime52(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.49000000953674316f;
}
static const u32 fzgx_pool_table53[1] = {0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep53(void) { const u32 *volatile cp; cp = fzgx_pool_table53; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime54(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.009999999776482582f;
}
static const u32 fzgx_pool_table55[2] = {0x3F570A3D, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep55(void) { const u32 *volatile cp; cp = fzgx_pool_table55; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime56(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5199999809265137f;
}
static const u32 fzgx_pool_table57[4] = {0x3F6147AE, 0x3C23D70A, 0x3F570A3D, 0x00240000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep57(void) { const u32 *volatile cp; cp = fzgx_pool_table57; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime58(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
    s = 0.8600000143051147f;
}
static const u32 fzgx_pool_table59[1] = {0x3C23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep59(void) { const u32 *volatile cp; cp = fzgx_pool_table59; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime60(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8500000238418579f;
}
static const u32 fzgx_pool_table61[2] = {0x000D0000, 0x3EF0A3D7};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep61(void) { const u32 *volatile cp; cp = fzgx_pool_table61; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime62(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8700000047683716f;
}
static const u32 fzgx_pool_table63[4] = {0x3C23D70A, 0x3F570A3D, 0x00180000, 0x3F11EB85};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep63(void) { const u32 *volatile cp; cp = fzgx_pool_table63; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime64(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0700000524520874f;
}
static const u32 fzgx_pool_table65[3] = {0xBC23D70A, 0x3F63D70A, 0x00170000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep65(void) { const u32 *volatile cp; cp = fzgx_pool_table65; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime66(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6399999856948853f;
}
static const u32 fzgx_pool_table67[2] = {0x3F63D70A, 0x3CA3D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep67(void) { const u32 *volatile cp; cp = fzgx_pool_table67; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime68(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.7900000214576721f;
}
static const u32 fzgx_pool_table69[6] = {0x00050000, 0x3EF0A3D7, 0x3F6147AE, 0x3C23D70A, 0x3F547AE1, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep69(void) { const u32 *volatile cp; cp = fzgx_pool_table69; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime70(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6299999952316284f;
}
static const u32 fzgx_pool_table71[1] = {0x3F63D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep71(void) { const u32 *volatile cp; cp = fzgx_pool_table71; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime72(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.05999999865889549f;
}
static const u32 fzgx_pool_table73[2] = {0x3F4A3D71, 0x000B0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep73(void) { const u32 *volatile cp; cp = fzgx_pool_table73; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime74(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4399999976158142f;
}
static const u32 fzgx_pool_table75[14] = {0x3F400000, 0x00000000, 0x3F59999A, 0x00160000, 0x3EE147AE, 0x3F6147AE, 0x3C23D70A, 0x3F570A3D, 0x00120000, 0x3EF5C28F, 0x3F59999A, 0x3C23D70A, 0x3F59999A, 0x001D0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep75(void) { const u32 *volatile cp; cp = fzgx_pool_table75; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime76(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6800000071525574f;
    s = 0.9599999785423279f;
    s = 0.029999999329447746f;
}
static const u32 fzgx_pool_table77[2] = {0x3F4F5C29, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep77(void) { const u32 *volatile cp; cp = fzgx_pool_table77; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime78(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.3700000047683716f;
}
static const u32 fzgx_pool_table79[9] = {0x3F800000, 0x3CF5C28F, 0x3F5C28F6, 0x000B0000, 0x3F000000, 0x3F5EB852, 0x3C23D70A, 0x3F570A3D, 0x00140000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep79(void) { const u32 *volatile cp; cp = fzgx_pool_table79; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime80(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4300000071525574f;
}
static const u32 fzgx_pool_table81[1] = {0x3F666666};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep81(void) { const u32 *volatile cp; cp = fzgx_pool_table81; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime82(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.03999999910593033f;
}
static const u32 fzgx_pool_table83[17] = {0x3F547AE1, 0x000F0000, 0x3F2147AE, 0x3F5C28F6, 0x00000000, 0x3F5EB852, 0x00030000, 0x3F051EB8, 0x3F4A3D71, 0x3C23D70A, 0x3F59999A, 0x00050000, 0x3F000000, 0x3F59999A, 0x3C23D70A, 0x3F5C28F6, 0x00150000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep83(void) { const u32 *volatile cp; cp = fzgx_pool_table83; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime84(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5799999833106995f;
}
static const u32 fzgx_pool_table85[4] = {0x3F428F5C, 0x3C23D70A, 0x3F570A3D, 0x00080000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep85(void) { const u32 *volatile cp; cp = fzgx_pool_table85; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime86(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.44999998807907104f;
}
static const u32 fzgx_pool_table87[5] = {0x3F63D70A, 0x3CF5C28F, 0x3F5C28F6, 0x001E0000, 0x3EFAE148};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep87(void) { const u32 *volatile cp; cp = fzgx_pool_table87; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime88(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.9200000166893005f;
}
static const u32 fzgx_pool_table89[14] = {0x3C23D70A, 0x3F59999A, 0x00000000, 0x3EE147AE, 0x3F6147AE, 0x3C23D70A, 0x3F5C28F6, 0x00160000, 0x3EDC28F6, 0x3F63D70A, 0x00000000, 0x3F4CCCCD, 0x00100000, 0x3F051EB8};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep89(void) { const u32 *volatile cp; cp = fzgx_pool_table89; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime90(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.6899999976158142f;
}
static const u32 fzgx_pool_table91[8] = {0x3CA3D70A, 0x3F59999A, 0x00060000, 0x3EF0A3D7, 0x3F400000, 0xBC23D70A, 0x3F59999A, 0x00190000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep91(void) { const u32 *volatile cp; cp = fzgx_pool_table91; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime92(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5899999737739563f;
}
static const u32 fzgx_pool_table93[2] = {0x3F570A3D, 0x3CF5C28F};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep93(void) { const u32 *volatile cp; cp = fzgx_pool_table93; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime94(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.8199999928474426f;
}
static const u32 fzgx_pool_table95[1] = {0x00050000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep95(void) { const u32 *volatile cp; cp = fzgx_pool_table95; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime96(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5099999904632568f;
}
static const u32 fzgx_pool_table97[5] = {0x3F5C28F6, 0x00000000, 0x3F570A3D, 0x00040000, 0x3EF0A3D7};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep97(void) { const u32 *volatile cp; cp = fzgx_pool_table97; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime98(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.949999988079071f;
}
static const u32 fzgx_pool_table99[14] = {0x3C23D70A, 0x3F51EB85, 0x00100000, 0x3F28F5C3, 0x3F7D70A4, 0x3D23D70A, 0x3F6147AE, 0x000B0000, 0x3EE66666, 0x3F63D70A, 0x3C23D70A, 0x3F570A3D, 0x00060000, 0x3F333333};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep99(void) { const u32 *volatile cp; cp = fzgx_pool_table99; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime100(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.2899999618530273f;
}
static const u32 fzgx_pool_table101[18] = {0xBC23D70A, 0x3F59999A, 0x00030000, 0x3EF0A3D7, 0x3F5EB852, 0x3C23D70A, 0x3F68F5C3, 0x00080000, 0x3EF5C28F, 0x3F6B851F, 0x00000000, 0x3F570A3D, 0x00060000, 0x3EE147AE, 0x3F547AE1, 0x00000000, 0x3F4A3D71, 0x00070000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep101(void) { const u32 *volatile cp; cp = fzgx_pool_table101; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime102(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4099999964237213f;
    s = 0.9700000286102295f;
}
static const u32 fzgx_pool_table103[3] = {0x3C23D70A, 0x3F51EB85, 0x00110000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep103(void) { const u32 *volatile cp; cp = fzgx_pool_table103; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime104(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.7300000190734863f;
}
static const u32 fzgx_pool_table105[11] = {0x3F63D70A, 0x3CF5C28F, 0x3F4F5C29, 0x00000000, 0x3F75C28F, 0x3F5EB852, 0x3CA3D70A, 0x3F59999A, 0x00050000, 0x3EEB851F, 0x3F51EB85};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep105(void) { const u32 *volatile cp; cp = fzgx_pool_table105; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime106(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.019999999552965164f;
}
static const u32 fzgx_pool_table107[1] = {0x3F59999A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep107(void) { const u32 *volatile cp; cp = fzgx_pool_table107; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime108(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 88.0f;
    s = 116.0f;
    s = 16.0f;
    s = 340.0f;
    s = 335.0f;
    s = 397.0f;
}
static const u32 fzgx_pool_table109[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep109(void) { const u32 *volatile cp; cp = fzgx_pool_table109; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime110(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.49;
}
static const u32 fzgx_pool_table111[1] = {0x3F5C28F6};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep111(void) { const u32 *volatile cp; cp = fzgx_pool_table111; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime112(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.05999999865889549f;
}
static const u32 fzgx_pool_table113[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep113(void) { const u32 *volatile cp; cp = fzgx_pool_table113; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime114(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 36.0f;
    s = 21.0f;
}
static const u32 fzgx_pool_table115[18] = {0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep115(void) { const u32 *volatile cp; cp = fzgx_pool_table115; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime116(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 132.0f;
}
static const u32 fzgx_pool_table117[50] = {0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43200000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42D40000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep117(void) { const u32 *volatile cp; cp = fzgx_pool_table117; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime118(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 138.0f;
}
static const u32 fzgx_pool_table119[2] = {0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep119(void) { const u32 *volatile cp; cp = fzgx_pool_table119; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime120(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 126.0f;
}
static const u32 fzgx_pool_table121[17] = {0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000, 0x42FC0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep121(void) { const u32 *volatile cp; cp = fzgx_pool_table121; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime122(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 124.0f;
}
static const u32 fzgx_pool_table123[104] = {0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42F80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42E80000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x43000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42AC0000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42000000, 0x00000000, 0x00000000, 0x42AC0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep123(void) { const u32 *volatile cp; cp = fzgx_pool_table123; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime124(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 148.0f;
}
static const u32 fzgx_pool_table125[38] = {0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42A40000, 0x00000000, 0x00000000, 0x42D40000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x43040000, 0x00000000, 0x00000000, 0x430A0000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep125(void) { const u32 *volatile cp; cp = fzgx_pool_table125; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime126(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 205.0f;
    s = 442.0f;
    s = 200.0f;
    s = -2.9000000953674316f;
}
static const u32 fzgx_pool_table127[1] = {0x3F23D70A};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep127(void) { const u32 *volatile cp; cp = fzgx_pool_table127; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime128(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 41.0f;
    s = 217.0f;
    s = 313.0f;
}
static const u32 fzgx_pool_table129[1] = {0x000000FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep129(void) { const u32 *volatile cp; cp = fzgx_pool_table129; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime130(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 428.0f;
    s = 239.0f;
    s = 0.10999999940395355f;
    s = 0.37662336230278015f;
    s = 0.9090909361839294f;
    s = 0.09090909361839294f;
    s = 0.41558441519737244f;
    s = 0.8116883039474487f;
    s = 0.3961038887500763f;
    s = 0.8831169009208679f;
    s = 0.025974025949835777f;
    s = 578.0f;
    s = 0.10500000417232513f;
    s = 0.375f;
    s = 203.0f;
    s = 272.0f;
    s = 206.0f;
    s = 275.0f;
    s = 0.11500000208616257f;
    s = 8.25f;
    s = 271.0f;
}
static const u32 fzgx_pool_table131[1] = {0x43140000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep131(void) { const u32 *volatile cp; cp = fzgx_pool_table131; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime132(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 147.0f;
    s = 492.0f;
}
static const u32 fzgx_pool_table133[4] = {0x161846FF, 0x161846FF, 0x161846FF, 0x161846FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep133(void) { const u32 *volatile cp; cp = fzgx_pool_table133; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime134(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 436.0f;
    s = 300.0f;
    s = 388.0f;
}
static const u32 fzgx_pool_table135[1] = {0xA0FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep135(void) { const u32 *volatile cp; cp = fzgx_pool_table135; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime136(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.4166666567325592f;
    s = 216.0f;
    s = 27.0f;
    s = 176.0f;
}
static const u32 fzgx_pool_table137[20] = {0x00000000, 0x606060FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep137(void) { const u32 *volatile cp; cp = fzgx_pool_table137; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime138(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 120.0;
    d = 80.0;
    s = 356.0f;
    s = 476.0f;
    s = 0.2800000011920929f;
    s = 385.0f;
    s = 426.0f;
    s = 0.07999999821186066f;
    s = 474.0f;
    s = 361.0f;
    s = 65.0f;
    s = 479.0f;
    s = 54.0f;
    s = 481.0f;
    s = 588.0f;
    s = 592.0f;
    s = 482.0f;
}
static const u32 fzgx_pool_table139[27] = {0x00000000, 0x606060FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep139(void) { const u32 *volatile cp; cp = fzgx_pool_table139; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime140(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 142.0f;
    s = 39.0f;
    s = 66.0f;
}
static const u32 fzgx_pool_table141[27] = {0x00000000, 0x606060FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF, 0xA0FF00FF, 0xFFFFFF00, 0xA0FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep141(void) { const u32 *volatile cp; cp = fzgx_pool_table141; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime142(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 324.0f;
    s = 473.0f;
    s = 311.0f;
    s = 306.0f;
    s = 312.0f;
    s = 412.0f;
    s = 418.0f;
    s = 305.0f;
    s = 395.0f;
    s = 402.0f;
}
static const u32 fzgx_pool_table143[1] = {0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep143(void) { const u32 *volatile cp; cp = fzgx_pool_table143; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime144(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -640.0f;
    s = 500.0f;
    s = 494.0f;
    s = 269.0f;
    s = 0.8333333134651184f;
    s = 121.0f;
    s = 232.0f;
    s = 286.0f;
}
static const u32 fzgx_pool_table145[1] = {0xFFF20000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep145(void) { const u32 *volatile cp; cp = fzgx_pool_table145; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime146(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 424.0f;
    s = 31.0f;
    s = 0.7083333134651184f;
    s = 394.0f;
}
static const u32 fzgx_pool_table147[8] = {0x43250000, 0x43ED8000, 0x00000005, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep147(void) { const u32 *volatile cp; cp = fzgx_pool_table147; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime148(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 214.0f;
    s = 188.0f;
    s = 260.0f;
    s = -10.0f;
    s = 248.0f;
    s = 274.0f;
    s = 204.0f;
    s = 0.004999999888241291f;
    d = 0.0005;
    s = 466.0f;
    s = 37.5f;
}
static const u32 fzgx_pool_table149[12] = {0xFFFFFFF6, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFF6, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep149(void) { const u32 *volatile cp; cp = fzgx_pool_table149; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime150(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -28.0f;
    s = 390.0f;
    s = -2.0f;
    s = -18.0f;
    s = 344.0f;
    s = 407.0f;
    s = 544.0f;
    s = 379.0f;
    s = 427.0f;
    s = 374.0f;
    s = 417.0f;
    s = 0.01666666753590107f;
}
#pragma section code_type ".text"

extern u32 lbl_10_bss_55B34[2];
extern FontDrawPacket lbl_1_rodata_26F8;
extern u8 fn_10_8780(void);
extern u32 lbl_801A66C0;
extern f32 lbl_8006D0B4(f32);

void fn_10_21978(void) {
    FontDrawPacket packet;
    s32 x;
    s32 i;
    s32 t;

    if (!fn_10_8780()) {
        lbl_10_bss_55B34[0] = 1;
        packet = lbl_1_rodata_26F8;
        packet.image = 0x9e1a;
        packet.flags = 9;
        packet.y = 240.0f;
        packet.z = 0.08f;
        for (i = 0, x = 140; i < 60; i++, x += 6) {
            packet.x = x;
            packet.scale_x = 1.0f;
            t = (s32)(lbl_801A66C0 % 320) - i;
            if (t > 0 && t < 20) {
                packet.scale_y = lbl_8006D0B4(20.0f / (t + 1));
                packet.alpha = t / 20.0f;
            } else if (t > 220 && t < 240) {
                packet.scale_y = lbl_8006D0B4(20.0f / (241 - t));
                packet.alpha = (240 - t) / 20.0f;
            } else if (t >= 20 && t <= 220) {
                packet.scale_y = 1.0f;
                packet.alpha = 1.0f;
            } else if (t <= 0 || t >= 240) {
                packet.alpha = 0.0f;
            }
            packet.u0 = i / 60.0f;
            packet.u1 = (i + 1) / 60.0f;
            packet.scale_x *= 0.016666667f;
            fn_1_4F734(&packet);
        }
    }
}
/* fzgx:end fn_10_21978 */

/* fzgx:begin fn_10_21C20 */
extern u8 lbl_10_data_1E80[816];

u32 fn_10_21C20(s16 row, s16 column) {
    return ((u32 (*)[6])lbl_10_data_1E80)[row][column];
}
/* fzgx:end fn_10_21C20 */

/* fzgx:begin fn_10_21C44 */
extern f32 lbl_10_rodata_158[];
extern u32 lbl_1_rodata_26F8[];
extern u8 *fn_1_12F118(void);
extern void fn_10_12E34(void);
extern void fn_1_4F734(void *arg0);

typedef struct {
    u32 w[41];
} WordTable;

typedef struct {
    u32 w[22];
} PacketInit;

typedef struct {
    u32 field0;
    u8 pad_04[0x81a0 - 4];
    u8 field81A0;
    u8 pad_81A1[0x1f];
} BigRecord;

void fn_10_21C44(s32 value) {
    u8 data[0x58];
    u32 words[41];
    f32 *constants;
    BigRecord *table;

    constants = lbl_10_rodata_158;
    *(WordTable *)words = *(WordTable *)((u8 *)constants + 0x129c);
    *(PacketInit *)data = *(PacketInit *)lbl_1_rodata_26F8;

    if ((u16)(value - 0x2d) <= 2 || (s16)value == 0x30) {
        table = (BigRecord *)fn_1_12F118();
        if (table[(s16)value - 0x29].field0 & 0x40000000) {
            *(u32 *)data = 0x900;
        } else {
            *(u32 *)data = words[table[(s16)value - 0x29].field81A0];
        }
    } else if ((s16)value >= 0x29) {
        *(u32 *)data = 0x900;
    } else {
        *(u32 *)data = words[(s16)value];
    }

    *(f32 *)(data + 4) = constants[83];
    *(f32 *)(data + 8) = constants[1233];
    *(f32 *)(data + 0xc) = constants[163];
    *(u32 *)(data + 0x38) = *(u32 *)((u8 *)constants + 0x1340);
    *(u32 *)(data + 0x30) = 0x4000000;
    *(u32 *)(data + 0x50) = (u32)fn_10_12E34;
    *(f32 *)(data + 0x54) = constants[17];
    fn_1_4F734(data);
}
/* fzgx:end fn_10_21C44 */

/* fzgx:begin fn_10_21DA8 */
extern f32 lbl_10_rodata_158[];
extern u32 lbl_10_data_5E24[2];
extern s32 lbl_801A66B4;

extern void fn_1_49410(void);
extern void fn_1_495B0(s32 value);
extern void fn_1_53C9C(s32 arg0, u32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);

void fn_10_21DA8(void) {
    f32 *constants = lbl_10_rodata_158;
    u32 value;

    if (lbl_801A66B4 == 5) {
        value = lbl_10_data_5E24[0];
    } else {
        value = lbl_10_data_5E24[1];
    }

    fn_1_49410();
    fn_1_495B0(-2147483648);
    fn_1_53C9C(0, value,
        constants[22],
        constants[150],
        constants[164],
        constants[735],
        constants[17]);
}
/* fzgx:end fn_10_21DA8 */

/* fzgx:begin fn_10_2228C */
extern u8 lbl_10_bss_55CE0;

typedef struct {
    u8 pad_00[0x22];
    u8 flag;
} SelState;

typedef struct {
    u8 pad_00[0xa4];
    SelState *state;
} SelGlobals;

extern SelGlobals lbl_1_bss_8B3A0;

extern void fn_1_140EE8(u8, int, int);
extern void fn_10_22330(int);
extern void fn_1_52070(int);
extern void fn_1_1461C8(int, u8);
extern void fn_10_2287C(void);
extern void fn_1_52088(void);
extern void fn_1_144F40(int, u8 *);
extern void fn_10_266AC(void);

void fn_10_2228C(void) {
    SelGlobals *globals = &lbl_1_bss_8B3A0;

    fn_1_140EE8(lbl_10_bss_55CE0, 1, 0);
    fn_10_22330(!globals->state->flag);

    if (globals->state->flag) {
        fn_1_52070(0x140);
        fn_1_1461C8(4, lbl_10_bss_55CE0);
        fn_10_2287C();
        fn_1_52088();
    } else {
        fn_1_144F40(6, &lbl_10_bss_55CE0);
        fn_10_266AC();
    }
}
/* fzgx:end fn_10_2228C */

/* fzgx:begin fn_10_22760 */
extern u8 lbl_10_bss_55CE0;

extern void fn_1_12EF80(u8 value, s16 *arg0, s16 *arg1);
extern s16 fn_1_12EF24(s16 parsed, s16 current);
extern s32 fn_1_F89E4(u8 value);

#pragma opt_strength_reduction off
s32 fn_10_22760(s32 arg0) {
    s16 parsed;
    s16 current;
    s16 result;

    parsed = 0;
    current = 0;
    result = -1;

    fn_1_12EF80(lbl_10_bss_55CE0, &parsed, &current);

    if (arg0 != 0) {
        current += arg0;

        while (current >= 0 && current <= 5) {
            result = fn_1_12EF24(parsed, current);
            if (parsed == 5 &&
                ((current == 5 && fn_1_F89E4(0) == 0) ||
                 (current != 5 && fn_1_F89E4((u8)(current + 1)) == 0))) {
                result = -1;
            }

            if (result != -1) {
                break;
            }

            current += arg0;
        }

        if (result != -1) {
            if (lbl_10_bss_55CE0 != result) {
                return 1;
            }
        }
    }
    return 0;
}
#pragma opt_strength_reduction reset
/* fzgx:end fn_10_22760 */

/* fzgx:begin fn_10_2287C */
extern u8 lbl_10_bss_55CE0;
extern u8 lbl_1_bss_718E0[];

typedef struct {
    u32 value;
    u8 pad[0x1a - 4];
    u8 type;
    u8 pad1b;
    u8 field_1c;
    u8 field_1d;
    u8 field_1e;
    u8 field_1f;
} SelObject;

extern SelObject *fn_1_156198(u8 enabled);
extern u64 fn_1_15AC10(void);
extern s16 fn_1_14F118(u8 value, int index);
extern void fn_1_1598C4(int value, u8 type, u8 a, u8 b, u8 c, u8 d, u8 e,
                         u8 *table, u64 pair, u32 zero);
extern void fn_1_159AE0(void);
extern void fn_10_22998(SelObject *object);

void fn_10_2287C(void) {
    SelObject *object;
    u64 pair;
    u8 a;
    u8 b;
    u8 c;

    object = fn_1_156198(lbl_10_bss_55CE0);
    pair = fn_1_15AC10();
    if (object == 0) {
        fn_10_22998(object);
    } else {
        if (object->type >= 0x29) {
            a = fn_1_14F118(object->field_1d, 0);
            b = fn_1_14F118(object->field_1e, 1);
            c = fn_1_14F118(object->field_1f, 2);
        } else {
            a = b = c = 0;
        }
        fn_1_1598C4((((object->value & 0xfff)) + ((((object->value >> 12) & 0xff) * 1000) + (((object->value >> 20) & 0xff) * 60000))),
                    object->type, a, b, c, object->field_1c,
                    lbl_10_bss_55CE0, lbl_1_bss_718E0 + 0x5522, pair, 0);
        fn_1_159AE0();
        fn_10_22998(object);
    }
}
/* fzgx:end fn_10_2287C */

/* fzgx:begin fn_10_2323C */
extern u8 lbl_10_bss_55680;

void fn_10_2323C(void) {
    lbl_10_bss_55680 = 1;
}
/* fzgx:end fn_10_2323C */

/* fzgx:begin fn_10_2324C */
extern u8 lbl_10_bss_55680;

void fn_10_2324C(void) {
    lbl_10_bss_55680 = 0;
}
/* fzgx:end fn_10_2324C */

/* fzgx:begin fn_10_25888 */
typedef signed char s8;
typedef signed short s16;
typedef signed long s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef int BOOL;
typedef unsigned long size_t;

typedef struct {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
    u8 unk_11;
    u16 unk_12;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u8 pad_24[0x4];
    u8 unk_28;
    u8 pad_29[0xD];
    u8 unk_36;
    u8 unk_37;
    u8 pad_38[0x2];
    u8 unk_3A;
    u8 unk_3B;
    u32 unk_3C;
} Obj_10_bss_55CD8_Target;
extern Obj_10_bss_55CD8_Target *lbl_10_bss_55CD8;
extern u8 lbl_10_data_68E0[0xA0];

extern u32 lbl_10_rodata_1D64;
extern u32 lbl_10_rodata_1D68;
extern s32 lbl_801A66B4;
extern struct fn_10_25888_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_435C(u32);
extern s32 fn_1_45D0(u32, u32, u8 *, u32);
extern s32 fn_1_3F8C(u8 *, u32, u32, u32);
extern void fn_1_A2D84(u32);
extern s32 fn_1_14CEB8(u32);
extern void fn_80083DB0(u8 *, u32);
extern void fn_10_2325C(void);
struct fn_10_25888_lbl_801A6410 {
    u32 unk_0;
};
typedef struct {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    u8 unk_C;
    u8 pad_D[0x3];
    u32 unk_10;
} Entry_4_D420;
typedef struct { u32 v; } Word;

#pragma opt_loop_invariants off
#pragma opt_lifetimes off
s32 fn_10_25888(void) {
    s32 bit;
    u8 *src;
    s32 i;
    Obj_10_bss_55CD8_Target *maskstate;
    struct { u8 value; } k;
    struct { s32 value; } n;
    s32 res;
    u8 *src2;
    u8 *data;
    Entry_4_D420 *t;
    Word c;
    Word c2;

    res = 0;
    data = lbl_10_data_68E0;
    if ((lbl_10_bss_55CD8->unk_0 >> 30) & 1) {
        c = *(Word *)&lbl_10_rodata_1D68;
        fn_1_435C(lbl_10_bss_55CD8->unk_8);
        n.value = 0;
        i = 0;
        while (src = (u8 *)lbl_10_bss_55CD8 + 0x28 + i, src[0] != 0) {
            t = (Entry_4_D420 *)fn_1_45D0(lbl_801A6410.unk_0, 0x12, ((0xA0) + (data)), 0xD4);
            t->unk_8 = (u8)n.value * 0x38 + 0x7E;
            t->unk_A = 0x17A;
            t->unk_0 = 2;
            t->unk_1 = 0;
            t->unk_4 = t->unk_8;
            t->unk_6 = t->unk_A;
            t->unk_2 = src[0];
            t->unk_3 = src[1];
            *(u32 *)((u8 *)t + 0xD) = c.v;
            t->unk_C = n.value;
            fn_1_3F8C(data + 0xC8, (u32)&fn_10_2325C, (u32)t, 0xB);
            i += 2;
            n.value += 1;
        }
        c2.v = lbl_10_bss_55CD8->unk_0;
        /* Retail reloads the target pointer after reading its flags. */
        (*(Obj_10_bss_55CD8_Target * volatile *)&lbl_10_bss_55CD8)->unk_0 = c2.v & ~0x40000000;
    }
    if (lbl_10_bss_55CD8->unk_0 >> 31) {
        return 1;
    }
    if (((lbl_10_bss_55CD8->unk_0 >> 29) & 1) || ((lbl_10_bss_55CD8->unk_0 >> 28) & 1)) {
        fn_1_A2D84(0xA9010100);
        lbl_10_bss_55CD8->unk_0 &= ~0x20000000;
        lbl_10_bss_55CD8->unk_0 &= ~0x10000000;
        lbl_10_bss_55CD8->unk_0 |= 0x80000000;
        if (fn_1_14CEB8((u32)lbl_10_bss_55CD8 + 0x28) != 0) {
            bit = 0;
            lbl_10_bss_55CD8->unk_0 |= 0x40000000;
            while (((u8 *)lbl_10_bss_55CD8)[0x28 + bit * 2] != 0) {
                lbl_10_bss_55CD8->unk_20 |= 0x80000000 >> bit;
                bit++;
            }
        }
        if (((u8 *)lbl_10_bss_55CD8)[0x28] == 0) {
            if (lbl_801A66B4 == 5) {
                fn_80083DB0((u8 *)lbl_10_bss_55CD8 + 0x28, (u32)(data + 0x114));
            } else {
                fn_80083DB0((u8 *)lbl_10_bss_55CD8 + 0x28, (u32)(data + 0x120));
            }
            c2 = *(Word *)&lbl_10_rodata_1D64;
            fn_1_435C(lbl_10_bss_55CD8->unk_8);
            n.value = 0;
            while (src2 = (u8 *)lbl_10_bss_55CD8 + 0x28 + n.value * 2, src2[0] != 0) {
                k.value = n.value;
                t = (Entry_4_D420 *)fn_1_45D0(lbl_801A6410.unk_0, 0x12, ((0xA0) + (data)), 0xD4);
                t->unk_8 = k.value * 0x38 + 0x7E;
                t->unk_A = 0x17A;
                t->unk_0 = 2;
                t->unk_1 = 0;
                t->unk_4 = t->unk_8;
                t->unk_6 = t->unk_A;
                t->unk_2 = src2[0];
                t->unk_3 = src2[1];
                *(u32 *)((u8 *)t + 0xD) = c2.v;
                t->unk_C = k.value;
                fn_1_3F8C(data + 0xC8, (u32)&fn_10_2325C, (u32)t, 0xB);
                n.value += 1;
            }
            lbl_10_bss_55CD8->unk_E = n.value;
        }
        res = 1;
    }
    return res;
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset
/* fzgx:end fn_10_25888 */
