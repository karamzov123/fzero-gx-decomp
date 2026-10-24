#include "types.h"

/* fzgx:begin _prolog */
struct _prolog_bss_9C {
    s8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    s16 unk_4;
    s16 unk_6;
    s32 unk_8;
};
struct _prolog_lbl_7_bss_0 {
    u32 unk_0;
    u8 pad_4[0xC];
    struct _prolog_bss_9C *unk_10;
    u8 *unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
};
struct _prolog_lbl_801A6410 {
    u32 unk_0;
};
struct _prolog_bss_970 {
    u32 unk_0;
    u8 unk_4;
};
struct _prolog_bss_58 {
    u8 pad_0[0x1C];
    u32 unk_1C;
};
struct _prolog_bss_7F0C0 {
    u8 pad_0[0x64];
    u16 unk_64;
};
struct _prolog_data_414 {
    u16 unk_0;
};

extern struct _prolog_lbl_7_bss_0 lbl_7_bss_0;
extern struct _prolog_lbl_801A6410 lbl_801A6410;
extern struct _prolog_bss_9C lbl_1_bss_9C;
extern struct _prolog_bss_970 lbl_1_bss_970;
extern struct _prolog_bss_58 lbl_1_bss_58;
extern struct _prolog_bss_7F0C0 lbl_1_bss_7F0C0;
extern struct _prolog_data_414 lbl_1_data_414;
extern s16 lbl_1_bss_964;
extern s16 lbl_1_bss_96A;
extern u8 lbl_7_rodata_0[];
extern char lbl_7_data_13A3C[];
extern char lbl_7_data_13A4C[];
extern void *lbl_1_bss_7167C;
extern void *lbl_1_bss_71680;
extern void *lbl_1_bss_71684;

extern u32 fn_7_244(void);
extern void fn_7_25C(void);
extern void fn_7_388(void);
extern void fn_1_A8F78(void);
extern u32 fn_1_45D0(u32, u32, const char *, int);
extern void fn_1_3CF0(u32, int);
extern void fn_1_F9EB0(int, int);
extern u32 fn_1_7BA08(int, int, int);
extern void fn_1_7BA48(void);
extern void fn_1_7BAF8(void);
extern void fn_1_3F8C(const char *, void *, u32, int);

#pragma opt_dead_assignments off
void _prolog(void) {
    struct _prolog_lbl_7_bss_0 *p;
    p = (struct _prolog_lbl_7_bss_0 *)&lbl_7_bss_0;
    p->unk_10 = &lbl_1_bss_9C;
    p->unk_14 = lbl_7_rodata_0 + p->unk_10->unk_0 * 0x84;
    p->unk_10->unk_4 = 6;
    fn_1_A8F78();
    p->unk_18 = fn_1_45D0(lbl_801A6410.unk_0, 0x5cc, lbl_7_data_13A3C, 333);
    p->unk_1C = fn_1_45D0(lbl_801A6410.unk_0, 0x5cc, lbl_7_data_13A3C, 334);
    fn_1_3CF0(p->unk_18, 4);
    fn_1_3CF0(p->unk_1C, 4);
    p->unk_20 = 1;
    lbl_1_bss_970.unk_0 = 0;
    lbl_1_bss_970.unk_4 = 0;
    if (lbl_1_bss_964 == 1 && p->unk_10->unk_8 == 0x86) {
        lbl_1_bss_9C.unk_3 = 0;
    }
    if (lbl_1_bss_964 == 8 && p->unk_10->unk_0 == 0) {
        fn_1_F9EB0(0, 0);
    }
    if (lbl_1_bss_964 == 8 && p->unk_10->unk_8 == 0x89) {
        if (lbl_1_bss_58.unk_1C & 2) {
            lbl_1_bss_96A = 0x87;
        } else {
            lbl_1_bss_96A = 0x89;
        }
    } else {
        lbl_1_bss_96A = p->unk_10->unk_8;
    }
    if (lbl_1_data_414.unk_0 == 0xffff) {
        u16 v = lbl_1_bss_7F0C0.unk_64;
        lbl_1_bss_96A = 0x86;
        lbl_1_data_414.unk_0 = v;
    }
    p->unk_0 = fn_1_45D0(lbl_801A6410.unk_0, fn_1_7BA08(0x20, 0x20, 0x40), lbl_7_data_13A3C, 390);
    fn_1_7BA48();
    fn_1_3F8C(lbl_7_data_13A4C, fn_1_7BAF8, p->unk_0, 2);
    lbl_1_bss_7167C = fn_7_244;
    lbl_1_bss_71680 = fn_7_25C;
    lbl_1_bss_71684 = fn_7_388;
}
#pragma opt_dead_assignments reset
/* fzgx:end _prolog */

/* fzgx:begin fn_7_244 */
extern struct fn_7_244_lbl_7_bss_C lbl_7_bss_C;

struct fn_7_244_lbl_7_bss_C {
    u32 unk_0;
};

u32 fn_7_244(void) {
    u32 v0;
    v0 = lbl_7_bss_C.unk_0;
    lbl_7_bss_C.unk_0 = (v0 + 1);
    return v0;
}
/* fzgx:end fn_7_244 */

/* fzgx:begin fn_7_25C */
extern struct fn_7_25C_lbl_7_bss_0 lbl_7_bss_0;
extern u32 camera_get_state(u32);
extern u32 fn_1_3CC4(u32);
extern u32 fn_1_407C(u32);
extern u32 fn_1_435C(u32);
extern u32 fn_1_5948(u32);
extern u32 fn_1_627C(u32);
extern u32 fn_1_9A770(u32);
extern u32 fn_1_B7C00(void);
extern u32 fn_1_C6F8C(u32);
extern u32 fn_1_C7224(u32);

struct fn_7_25C_lbl_7_bss_0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u32 unk_8;
    u8 pad_C[0xC];
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x4];
    u32 unk_24;
};

void fn_7_25C(void) {
    struct fn_7_25C_lbl_7_bss_0 *p_lbl_7_bss_0;
    u32 v0;
    u32 v1;
    u32 t0, t1, t4, t5, t7, t8, t9, t11;
    p_lbl_7_bss_0 = (struct fn_7_25C_lbl_7_bss_0 *)&lbl_7_bss_0;
    if ((s32)p_lbl_7_bss_0->unk_24 == 0) {
    t0 = fn_1_B7C00();
    if ((t0 & 0xFF) == 0) {
    t1 = fn_1_435C(p_lbl_7_bss_0->unk_18);
    fn_1_407C(t1);
    v0 = p_lbl_7_bss_0->unk_4;
    if ((s32)v0 > 0) {
    p_lbl_7_bss_0->unk_4 = (v0 - 1);
    }
    }
    }
    v1 = p_lbl_7_bss_0->unk_8;
    if ((s32)v1 > 0) {
    p_lbl_7_bss_0->unk_8 = (v1 - 1);
    }
    fn_1_3CC4(v1);
    t4 = fn_1_435C(p_lbl_7_bss_0->unk_1C);
    t5 = camera_get_state(t4);
    if ((s8)t5 == -1) {
    fn_1_407C(t5);
    } else {
    t7 = fn_1_5948(0);
    t8 = fn_1_9A770(t7);
    t9 = fn_1_C7224(t8);
    fn_1_407C(t9);
    t11 = fn_1_627C(0);
    fn_1_C6F8C(t11);
    }
}
/* fzgx:end fn_7_25C */

/* fzgx:begin _epilog */
struct _epilog_lbl_7_bss_0 {
    u32 unk_0;
    u8 pad_4[0x14];
    u32 unk_18;
    u32 unk_1C;
};
struct _epilog_lbl_801A6410 {
    u32 unk_0;
};

extern struct _epilog_lbl_7_bss_0 lbl_7_bss_0;
extern struct _epilog_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_4E060(void);
extern u32 lbl_7_data_13A3C;
extern void * fn_1_435C(void *);
extern void fn_1_3C78(void);
extern void fn_1_41A8(void);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_A8F78(void);

void _epilog(void) {
    struct _epilog_lbl_7_bss_0 *p_lbl_7_bss_0;
    p_lbl_7_bss_0 = (struct _epilog_lbl_7_bss_0 *)&lbl_7_bss_0;
    fn_1_3C78();
    fn_1_A8F78();
    fn_1_46B4(lbl_801A6410.unk_0, p_lbl_7_bss_0->unk_0, (const char *)&lbl_7_data_13A3C, 478);
    fn_1_435C((void *)p_lbl_7_bss_0->unk_18);
    fn_1_41A8();
    fn_1_435C((void *)p_lbl_7_bss_0->unk_1C);
    fn_1_41A8();
    fn_1_4E060();
}
/* fzgx:end _epilog */

/* fzgx:begin fn_7_388 */
typedef u32 (*fn_7_388_Fn0)(void);
struct fn_7_388_lbl_7_data_13A58_0_E44 {
    u8 pad_0[0x20];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};
extern s16 lbl_1_bss_962;
extern struct fn_7_388_lbl_7_data_13A58_0_E44 lbl_7_data_13A58[];
extern u32 lbl_1_bss_71688;
extern u32 lbl_1_bss_7168C;

void fn_7_388(void) {
    u32 v0;
    u32 v1;
    struct fn_7_388_lbl_7_data_13A58_0_E44 *p;
    s32 index;
    p = lbl_7_data_13A58;
    index = lbl_1_bss_962;
    index -= 133;
    p += index;
    v0 = p->unk_24;
    lbl_1_bss_71688 = v0;
    v1 = p->unk_28;
    lbl_1_bss_7168C = v1;
    ((fn_7_388_Fn0)p->unk_20)();
}
/* fzgx:end fn_7_388 */

/* fzgx:begin fn_7_3E4 */
extern const f32 lbl_7_rodata_528;
extern u32 lbl_7_bss_10;
extern u32 lbl_1_bss_9C;
extern void fn_7_4050(void);
extern void fn_1_4CC0(void);
extern void fn_8006CE1C(f32);
extern s32 fn_1_F9E80(u32, u32);
extern s32 fn_1_F9CA0(u32, u32);
extern void fn_1_F9CD0(u8, u8);

void fn_7_3E4(void) {
    u32 *p;
    u8 *q;
    fn_7_4050();
    fn_1_4CC0();
    fn_8006CE1C(lbl_7_rodata_528);
    p = &lbl_7_bss_10;
    *(u8 *)(*p) = 0;
    *(u16 *)(*p + 4) = 6;
    *(u8 *)(*p + 1) = 0;
    *(s8 *)(*p + 6) = -1;
    *(u8 *)(*p + 7) = 0;
    *(u8 *)(*p) = 0;
    while ((s8)*(u8 *)(*p) <= 10 && fn_1_F9E80(0, *(u8 *)(*p)) != 0 &&
           fn_1_F9CA0(0, (u8)(*(u8 *)(*p) + 1)) != 0) {
        (*(u8 *)(*p))++;
    }
    q = (u8 *)*(u32 *)&lbl_7_bss_10;
    if ((s8)q[0] >= 10) {
        q[0] = 9;
    }
    if (fn_1_F9CA0(0, 0) == 0) {
        fn_1_F9CD0(0, 0);
        *((u8 *)&lbl_1_bss_9C + 3) = 1;
    }
}
/* fzgx:end fn_7_3E4 */

/* fzgx:begin fn_7_50C */
extern u16 lbl_1_bss_96A;

void fn_7_50C(void) {
    lbl_1_bss_96A = 135;
}
/* fzgx:end fn_7_50C */

/* fzgx:begin fn_7_51C */
// fn_7_51C: empty in retail (single blr).
void fn_7_51C(void) {
}
/* fzgx:end fn_7_51C */

/* fzgx:begin fn_7_D20 */
struct fn_7_D20_lbl_7_bss_10 {
    u32 unk_0;
};
struct fn_7_D20_lbl_7_bss_14 {
    u32 unk_0;
};

extern int sprintf(char *, const char *, ...);
extern s32 fn_1_465D0(char *, s32);
extern struct fn_7_D20_lbl_7_bss_10 lbl_7_bss_10;
extern struct fn_7_D20_lbl_7_bss_14 lbl_7_bss_14;
extern u32 lbl_7_data_13A14[10];
extern u32 fn_1_47E54(u32);
extern u32 fn_1_A0AA4(void);
extern char lbl_7_data_13DE0[23];
extern char lbl_7_data_13DF8[23];
extern f32 lbl_7_rodata_0[330];
extern void fn_1_412A0(u32);
extern void fn_1_48140(int);
extern void fn_7_4050(void);

void fn_7_D20(void) {
    u32 ptr;
    u32 index;
    s32 offset;
    struct { u32 a0, a1, a2, a3, a4, a5, a6, a7, a8, a9; } loc_8;

    fn_1_412A0(6);
    fn_1_412A0(1);
    fn_1_48140(100);
    fn_1_48140(155);
    fn_1_48140(154);
    fn_1_48140(186);

    ptr = lbl_7_bss_10.unk_0;
    lbl_7_bss_14.unk_0 = (u32)((u8 *)lbl_7_rodata_0 + (s8)*(u8 *)ptr * 132);
    fn_7_4050();
    sprintf((char *)&loc_8, lbl_7_data_13DE0, *(s8 *)((u8 *)lbl_7_bss_14.unk_0 + 1));
    fn_1_465D0((char *)&loc_8, 1);
    sprintf((char *)&loc_8, lbl_7_data_13DF8, *(s8 *)((u8 *)lbl_7_bss_14.unk_0 + 1));
    fn_1_465D0((char *)&loc_8, 1);

    offset = *(s8 *)((u8 *)lbl_7_bss_14.unk_0 + 1) - 0x24;
    if (offset < 0) {
        index = 0;
    } else {
        index = 9;
        if (offset <= 9) {
            index = offset;
        }
    }
    fn_1_47E54(lbl_7_data_13A14[index]);
    fn_1_A0AA4();
}
/* fzgx:end fn_7_D20 */

/* fzgx:begin fn_7_E50 */
extern struct fn_7_E50_lbl_7_bss_1C lbl_7_bss_1C;
extern u32 fn_1_4A00(u32, u32, u32);

struct fn_7_E50_lbl_7_bss_1C {
    u32 unk_0;
};

void fn_7_E50(void) {
    fn_1_4A00(1, 30, lbl_7_bss_1C.unk_0);
}
/* fzgx:end fn_7_E50 */

/* fzgx:begin fn_7_E84 */
struct fn_7_E84_lbl_7_bss_14 {
    u32 unk_0;
};
struct fn_7_E84_lbl_1_bss_58 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    u8 pad_15[0x1];
    u8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[0x2];
    u32 unk_1C;
};
struct fn_7_E84_lbl_7_bss_10_T {
    s8 unk_0;
    u8 pad_1[0x7];
    u32 unk_8;
};

extern f32 lbl_7_rodata_52C;
extern struct fn_7_E84_lbl_1_bss_58 lbl_1_bss_58;
extern struct fn_7_E84_lbl_7_bss_10_T *lbl_7_bss_10;
extern struct fn_7_E84_lbl_7_bss_14 lbl_7_bss_14;
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern u16 lbl_1_data_414;
extern u8 lbl_1_bss_198[];
extern u8 lbl_7_data_13E10[220];
extern u32 lbl_801A66B4;
extern u32 fn_80083DB0(void *, void *);

void fn_7_E84(void) {
    u32 v;
    f32 f0;

    v = *(u32 *)((u8 *)lbl_7_bss_14.unk_0 + 0x18);
    if (v != 0) {
        fn_80083DB0(lbl_1_bss_198, (void *)v);
        fn_80083DB0(lbl_1_bss_198 + 0x40, lbl_7_data_13E10);
        f0 = lbl_7_rodata_52C;
        lbl_1_bss_58.unk_0 = lbl_801A66B4;
        lbl_1_bss_58.unk_14 = 7;
        lbl_1_bss_58.unk_1 = 1;
        lbl_1_bss_58.unk_2 = 0;
        lbl_1_bss_58.unk_3 = 0;
        lbl_1_bss_58.unk_4 = 640;
        lbl_1_bss_58.unk_6 = 336;
        lbl_1_bss_58.unk_8 = 0;
        lbl_1_bss_58.unk_A = 0;
        lbl_1_bss_58.unk_C = f0;
        lbl_1_bss_58.unk_10 = f0;
        lbl_1_bss_58.unk_16 = 0;
        lbl_1_bss_58.unk_17 = -1;
        lbl_1_bss_58.unk_18 = -1;
        lbl_1_bss_58.unk_1C = 0;
        lbl_1_bss_58.unk_14 = 6;
        if ((lbl_1_data_414 & (0x8000 >> lbl_7_bss_10->unk_0)) != 0) {
            lbl_1_bss_58.unk_14 |= 1;
        }
        lbl_1_bss_968 = 8;
        lbl_7_bss_10->unk_8 = 137;
    } else {
        lbl_1_bss_96A = 144;
    }
}
/* fzgx:end fn_7_E84 */

/* fzgx:begin fn_7_FB0 */
// fn_7_FB0: empty in retail (single blr).
void fn_7_FB0(void) {
}
/* fzgx:end fn_7_FB0 */

/* fzgx:begin fn_7_FB4 */
extern u32 lbl_7_bss_0;
extern u8 lbl_7_data_0[];

extern void fn_7_4050(void);
extern u32 fn_1_47F74(u32);
extern s32 fn_1_465D0(void *, s32);
extern void fn_1_411A4(u32);
extern void fn_1_12F28C(void *, void *, u32, void *);
extern void fn_1_4A00(s32, u8, void *);
extern u32 fn_1_47E54(u32);
extern void fn_80006E10(u32);
extern u32 fn_1_7FD7C(void *);
extern u8 *fn_1_12D254(s32, s32);
extern u32 fn_1_A0680(void);
extern void fn_1_A1588(void *, u32);

extern void **lbl_1_bss_6EAD0;
extern u8 lbl_1_bss_8B5F0;
extern u8 lbl_1_bss_8B5F1;

struct fn_7_FB4_state {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x8];
    u32 unk_10;
    s8 *unk_14;
    u8 pad_18[0x4];
    u32 unk_1c;
    u8 pad_20[0x8];
    u32 unk_28;
    u32 unk_2c;
    u32 unk_30;
    u8 pad_34[0x8];
    u32 unk_3c;
    u32 unk_40;
    u8 unk_44[1];
};

struct fn_7_FB4_arg {
    u8 pad_0[2];
    s16 unk_2;
    u32 unk_4;
    u8 unk_8;
    u8 pad_9[0x17];
};

#pragma opt_propagation off
void fn_7_FB4(void) {
    struct fn_7_FB4_state *state;
    struct fn_7_FB4_arg arg;
    s32 offset;
    s32 index;
    u8 *base;
    u32 *tbl;
    void *res;

    base = lbl_7_data_0 + 0x10000;
    state = (struct fn_7_FB4_state *)&lbl_7_bss_0;
    state->unk_4 = 0;
    state->unk_28 = 0;
    state->unk_2c = 10;
    state->unk_3c = 0;
    state->unk_40 = 0;
    state->unk_30 = 0;
    fn_7_4050();
    fn_1_47F74(0xba);
    fn_1_47F74(0x9a);
    fn_1_47F74(0x9b);
    offset = state->unk_14[1] - 0x24;
    index = offset < 0 ? 0 : (offset > 9 ? 9 : offset);
    offset = index * 4;
    tbl = (u32 *)(base + 0x3A14);
    fn_1_47F74(*(u32 *)((u8 *)tbl + offset));
    res = base + 0x3E14;
    fn_1_465D0(res, 1);
    fn_1_411A4(1);
    fn_1_12F28C((void *)state->unk_1c, state->unk_44, 7, state->unk_14 + 1);
    fn_1_4A00(1, 0x1e, (void *)state->unk_1c);
    arg.unk_2 = *(s16 *)(state->unk_10 + 4);
    arg.unk_4 = 2;
    arg.unk_8 = 0x10;
    fn_1_47E54(0x30);
    fn_80006E10((u32)(base + 0x3E30));
    res = base + 0x3E38;
    fn_1_465D0(res, 1);
    fn_1_7FD7C(&arg);
    fn_80006E10((u32)(base + 0x3E48));
    res = fn_1_12D254(arg.unk_2, arg.unk_4);
    fn_1_465D0(res, 1);
    fn_1_A0680();
    fn_1_A1588(*(void **)lbl_1_bss_6EAD0, 0x2e);
    lbl_1_bss_8B5F0 = 0;
    lbl_1_bss_8B5F1 = 0;
}
#pragma opt_propagation reset
/* fzgx:end fn_7_FB4 */

/* fzgx:begin fn_7_1134 */
struct fn_7_1134_state {
    u8 pad_0[0x4];
    s32 unk_4;
    u8 pad_8[0x8];
    s8 *unk_10;
    u8 pad_14[0x8];
    u32 unk_1C;
    u8 pad_20[0x8];
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u8 pad_34[0x8];
    s32 unk_3C;
    s32 unk_40;
};

struct fn_7_1134_entry {
    u8 pad_0[0x8];
    u16 flags;
    u8 pad_A[0xA];
};

extern u32 lbl_7_bss_0[];
extern u16 lbl_1_bss_96A;
extern struct fn_7_1134_entry lbl_1_bss_9F8[];

extern u32 fn_7_33F0(void);
extern int fn_1_4C10(void);
extern u32 fn_1_4A00(u32, u32, u32);
extern void fn_1_A2D84(u32);

#pragma opt_common_subs off
static inline void fn_7_1134_store(s32 *destination, s32 value) { *destination = value; }
#pragma opt_dead_assignments off
void fn_7_1134(void) {
    struct fn_7_1134_state *p;
    s32 sum;
    u32 val;
    u32 lab_t2;
    u32 lab_t1;

    p = (struct fn_7_1134_state *)&lbl_7_bss_0;
    fn_7_33F0();

    if (p->unk_2C != 0) {
        sum = p->unk_28 + p->unk_2C;
        p->unk_28 = sum;
        if (sum > 200) {
            p->unk_28 = 200;
            p->unk_2C = 0;
            p->unk_3C = 360;
            p->unk_40 = -4;
        } else if (sum < 0) {
            fn_7_1134_store(&(p->unk_28), 0);
            p->unk_2C = 0;
        } else {
            return;
        }
    }

    if (p->unk_40 != 0) {
        sum = p->unk_3C + p->unk_40;
        p->unk_3C = sum;
        if (sum < -101) {
            p->unk_3C = -101;
            p->unk_40 = 0;
        }
    }

    if (fn_1_4C10() != 0) {
        return;
    }

    if (p->unk_4 == 1) {
        val = 0x8a;
        if (4 == p->unk_30) {
            val = 0x87;
        }
        lbl_1_bss_96A = val;
        return;
    } else if (p->unk_4 == 0) {
        if (p->unk_3C == -101) {
            if ((lbl_1_bss_9F8[(*((p->unk_10) + (2)))].flags >> 8) & 1) {
                u32 arg = p->unk_1C;
                p->unk_4 = 0x20;
                p->unk_2C = -10;
                p->unk_30 = 3;
                lab_t2 = arg;
                lab_t1 = 0x1e;
                fn_1_4A00(0, lab_t1, lab_t2);
                fn_1_A2D84(0xa9010100);
                return;
            }
        }
        if ((lbl_1_bss_9F8[(*((p->unk_10) + (2)))].flags >> 9) & 1) {
            u32 arg = p->unk_1C;
            p->unk_4 = 0x20;
            p->unk_2C = -10;
            p->unk_30 = 4;
            lab_t1 = 0x1e;
            fn_1_4A00(0, lab_t1, arg);
            fn_1_A2D84(0xa9010200);
        }
    }
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset
/* fzgx:end fn_7_1134 */

/* fzgx:begin fn_7_12FC */
extern u32 lbl_7_bss_0;
extern void fn_7_4050(void);
extern void fn_1_12F30C(u32, void *);
extern void fn_1_412A0(u32);
extern void fn_1_48140(u32);
extern u32 lbl_7_data_13A14[10];

struct fn_7_12FC_state {
    u8 pad_0[0x14];
    s8 *unk_14;
    u8 pad_18[0x4];
    u32 unk_1c;
    u8 pad_20[0x24];
    u8 unk_44[1];
};

void fn_7_12FC(void) {
    struct fn_7_12FC_state *state;
    u32 index;
    s32 offset;

    state = (struct fn_7_12FC_state *)&lbl_7_bss_0;
    fn_7_4050();
    fn_1_12F30C(state->unk_1c, &state->unk_44);
    fn_1_412A0(1);
    offset = state->unk_14[1] - 0x24;
    if (offset < 0) {
        index = 0;
    } else {
        index = 9;
        if (offset <= 9) {
            index = offset;
        }
    }
    fn_1_48140(lbl_7_data_13A14[index]);
    fn_1_48140(0x9b);
    fn_1_48140(0x9a);
    fn_1_48140(0xba);
}
/* fzgx:end fn_7_12FC */

/* fzgx:begin fn_7_1398 */
extern u32 fn_1_12F10C(u32);
extern u32 fn_7_4050(void);
extern u32 lbl_7_bss_4;

void fn_7_1398(void) {
    fn_7_4050();
    fn_1_12F10C(0);
    lbl_7_bss_4 = 0;
}
/* fzgx:end fn_7_1398 */

/* fzgx:begin fn_7_13CC */
extern struct fn_7_13CC_lbl_1_bss_8B3A0 lbl_1_bss_8B3A0;
extern struct fn_7_13CC_lbl_7_bss_10_T *lbl_7_bss_10;
extern u16 lbl_1_bss_968;

struct fn_7_13CC_lbl_1_bss_8B3A0 {
    u8 pad_0[0x94];
    u32 unk_94;
};
struct fn_7_13CC_lbl_7_bss_10_T {
    u8 pad_0[0x8];
    u32 unk_8;
};

void fn_7_13CC(void) {
    lbl_1_bss_8B3A0.unk_94 = 0x2000000;
    lbl_7_bss_10->unk_8 = 139;
    lbl_1_bss_968 = 1;
}
/* fzgx:end fn_7_13CC */

/* fzgx:begin fn_7_13FC */
// fn_7_13FC: empty in retail (single blr).
void fn_7_13FC(void) {
}
/* fzgx:end fn_7_13FC */

/* fzgx:begin fn_7_1400 */
struct Sig_fn_7_2114_fn_7_2114_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA8];
    u32 unk_AC;
    u8 pad_B0[0x18];
    u32 unk_C8;
};

struct fn_7_1400_sub {
    u8 pad_0[0x248];
    u16 unk_248;
};

struct fn_7_1400_lbl_7_bss_0 {
    u8 pad_0[0x10];
    u8 *unk_10;
    u8 *unk_14;
    u8 pad_18[0xC];
    u32 unk_24;
    u8 pad_28[0x20];
    struct fn_7_1400_sub sub;
};

extern struct Sig_fn_7_2114_fn_7_2114_Arg0 * fn_7_2114(struct Sig_fn_7_2114_fn_7_2114_Arg0 *);
extern u16 lbl_1_data_414;
extern u16 lbl_1_bss_96A;
extern f32 lbl_7_rodata_0[330];
extern u32 fn_1_47F74(u32);
extern u32 fn_7_4108(void *, u32, u32);
extern u32 fn_7_41FC(void *);
extern void fn_1_F1B78(u32);
extern void fn_1_3EF8C(u8);
extern void fn_1_3EFF0(u32, u8);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 lbl_7_bss_0;
u32 lbl_7_bss_4[2];
u32 lbl_7_bss_C;
u8 *lbl_7_bss_10;
u8 *lbl_7_bss_14;
u32 lbl_7_bss_18;
u32 lbl_7_bss_1C__fzgx_offset_0[2];
u32 lbl_7_bss_1C__fzgx_offset_8;
u32 lbl_7_bss_1C__fzgx_offset_C[8];
struct fn_7_1400_sub lbl_7_bss_48;
u16 lbl_7_bss_48__fzgx_offset_24A;
u32 lbl_7_bss_48__fzgx_offset_24C[2];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_7_bss_0;
    s = *(u8 *)&lbl_7_bss_4;
    s = *(u8 *)&lbl_7_bss_C;
    s = *(u8 *)&lbl_7_bss_10;
    s = *(u8 *)&lbl_7_bss_14;
    s = *(u8 *)&lbl_7_bss_18;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_0;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_8;
    s = *(u8 *)&lbl_7_bss_1C__fzgx_offset_C;
    s = *(u8 *)&lbl_7_bss_48;
    s = *(u8 *)&lbl_7_bss_48__fzgx_offset_24A;
    s = *(u8 *)&lbl_7_bss_48__fzgx_offset_24C;
}
#pragma section code_type ".text"

void fn_7_1400(void) {
    s8 v0;
    u8 *v1;
    s32 v2;
    s32 v4;

    
    fn_1_47F74(186);
    if (lbl_7_bss_14[0] == 9) {
        v0 = (s8)lbl_7_bss_10[1];
        switch (v0) {
        case 0:
        default:
            fn_1_F1B78(0);
            break;
        case 1:
            fn_1_F1B78(1);
            break;
        case 2:
            fn_1_F1B78(2);
            break;
        }
    } else {
        fn_1_F1B78(-1);
    }
    v1 = lbl_7_bss_10;
    v2 = (0x10000 + -32768);
    v4 = ((s8)v1[0] * 132);
    lbl_7_bss_14 = (u8 *)&lbl_7_rodata_0 + v4;
    lbl_1_data_414 = (lbl_1_data_414 | (v2 >> (s8)v1[0]));
    fn_1_3EF8C(5);
    fn_1_3EFF0((u32)fn_7_2114, 1);
    lbl_7_bss_1C__fzgx_offset_8 = 0;
    lbl_7_bss_48.unk_248 = (s8)lbl_7_bss_10[1];
    fn_7_4108(&lbl_7_bss_48, *(u32 *)(lbl_7_bss_14 + 0x20), 0);
    fn_7_41FC((u8 *)&lbl_7_bss_48);
    lbl_1_bss_96A = 140;
}
/* fzgx:end fn_7_1400 */

/* fzgx:begin fn_7_1538 */
// fn_7_1538: empty in retail (single blr).
void fn_7_1538(void) {
}
/* fzgx:end fn_7_1538 */

/* fzgx:begin fn_7_153C */
// fn_7_153C: empty in retail (single blr).
void fn_7_153C(void) {
}
/* fzgx:end fn_7_153C */

/* fzgx:begin fn_7_1540 */
// fn_7_1540: empty in retail (single blr).
void fn_7_1540(void) {
}
/* fzgx:end fn_7_1540 */

/* fzgx:begin fn_7_1544 */
extern u16 lbl_1_bss_96A;
extern u32 fn_1_3F038(void);
extern u32 fn_1_3F0C8(void);

void fn_7_1544(void) {
    u32 v0;
    s16 v1;
    u32 t0, t1;
    t0 = fn_1_3F038();
    v0 = t0;
    if ((s32)t0 != 0) {
    t1 = fn_1_3F0C8();
    v0 = t1;
    v1 = (s16)v0;
    switch (v1) {
    case 42:
    lbl_1_bss_96A = 141;
    break;
    case 43:
    lbl_1_bss_96A = 149;
    break;
    default:
    lbl_1_bss_96A = 135;
    }
    }
}
/* fzgx:end fn_7_1544 */

/* fzgx:begin fn_7_15B8 */
// fn_7_15B8: empty in retail (single blr).
void fn_7_15B8(void) {
}
/* fzgx:end fn_7_15B8 */

/* fzgx:begin fn_7_15BC */
#include "rel/story/story_mode.h"

typedef struct StoryTime {
    u8 min;
    u8 sec;
    u16 ms;
} StoryTime;

typedef struct StoryRecords {
    u8 pad_0[0x6c];
    StoryTime times[8][12];
} StoryRecords;

typedef struct StoryClock {
    u8 pad_0[0x1e0];
    u8 min;
    u8 sec;
    u16 ms;
} StoryClock;

extern s32 fn_1_8623C(void);
extern StoryClock *fn_1_3F0D8(u8, u8 *, f32 *);
extern StoryRecords lbl_1_bss_7F0C0;
extern u8 lbl_1_bss_9C[];

void fn_7_15BC(void) {
    f32 scale;
    u8 name[12];
    StoryClock *clock;
    s32 course;

    clock = fn_1_3F0D8(fn_1_8623C(), name, &scale);
    course = (s8)lbl_7_bss_10->unk_0;
#define REC lbl_1_bss_7F0C0.times[(s8)lbl_7_bss_10->unk_1][course]
    if (REC.min || REC.sec || REC.ms) {
        if (clock->sec * 1000 + clock->min * 60000 + clock->ms >=
            REC.sec * 1000 + REC.min * 60000 + REC.ms) {
            return;
        }
    }
    REC.min = clock->min;
    REC.sec = clock->sec;
    REC.ms = clock->ms;
#undef REC
    lbl_1_bss_9C[3] = 1;
}
/* fzgx:end fn_7_15BC */

/* fzgx:begin fn_7_16FC */
extern u16 lbl_1_bss_96A;

void fn_7_16FC(void) {
    lbl_1_bss_96A = 144;
}
/* fzgx:end fn_7_16FC */

/* fzgx:begin fn_7_170C */
// fn_7_170C: empty in retail (single blr).
void fn_7_170C(void) {
}
/* fzgx:end fn_7_170C */

/* fzgx:begin fn_7_1710 */
typedef struct {
    s8 a;
    s8 b;
} StoryPos;

struct fn_7_1710_bss_0 {
    u8 pad_0[0x10];
    StoryPos *pos;
    u8 pad_14[0x4];
    void *unk_18;
    void *unk_1C;
};

struct fn_7_1710_bss_5138 {
    u16 unk_0;
    u8 count2;
    u8 count3;
    u8 list[4];
    u16 arr[4];
    u16 unk_10;
    u16 unk_12;
    u8 pad_14[0xD1];
    u8 unk_E5;
};

struct fn_7_1710_bss_9C {
    u8 pad_0[3];
    u8 unk_3;
};

extern struct fn_7_1710_bss_0 lbl_7_bss_0;
extern struct fn_7_1710_bss_5138 lbl_1_bss_5138;
extern struct fn_7_1710_bss_9C lbl_1_bss_9C;
extern u16 lbl_1_bss_96A;

extern void fn_1_4CC0(void);
extern void fn_8006CE1C(f32);
extern u32 fn_1_F9CA0(u32, u32);
extern void fn_1_F9CD0(u8, u8);
extern u32 fn_1_F9E80(u32, u32);
extern u32 fn_1_F9EB0(u32, u32);
extern s32 fn_1_F7EDC(s16);
extern int fn_1_F8334(s16);
extern void fn_1_3FDA8(void *, void *);

/* Layout primer: the story TU's .rodata ahead of this function (0x528 bytes of tables,
 * then the 0.0f / 1.0f literals), so the initializers below land at retail's offsets. */
#define FZGX_Z8 0, 0, 0, 0, 0, 0, 0, 0
#define FZGX_Z32 FZGX_Z8, FZGX_Z8, FZGX_Z8, FZGX_Z8
static const u32 fzgx_pool_table_0[330] = {
    FZGX_Z32, 0, 0x01250000,
    FZGX_Z32, 0x02260000,
    FZGX_Z32, 0x03270000,
    FZGX_Z32, 0x04280000,
    FZGX_Z32, 0x05290000,
    FZGX_Z32, 0x062A0000,
    FZGX_Z32, 0x072B0000,
    FZGX_Z32, 0x082C0000,
    FZGX_Z32, 0x092D0000,
    FZGX_Z32,
};

#pragma section code_type ".fzgxpool"
static void fzgx_pool_primer(void) {
    fn_1_4CC0();
    fn_1_3FDA8((void *)fzgx_pool_table_0, (void *)fzgx_pool_table_0);
    fn_8006CE1C(0.0f);
    fn_8006CE1C(1.0f);
}
#pragma section code_type ".text"

void fn_7_1710(void) {
    struct fn_7_1710_bss_0 *g = (struct fn_7_1710_bss_0 *)&lbl_7_bss_0;
    s16 tblA[9][3] = {
        { 15, 25, 35 }, { 15, 25, 35 }, { 15, 25, 35 },
        { 20, 25, 35 }, { 20, 25, 35 }, { 25, 30, 40 },
        { 25, 30, 40 }, { 30, 35, 45 }, { 30, 35, 45 },
    };
    s16 tblB[9][3] = {
        { 31, 16, 71 }, { 29, 10, 72 }, { 30, 3, 66 },
        { 35, 2, 59 }, { 42, 7, 55 }, { 33, 21, 63 },
        { 27, 5, 51 }, { 40, 15, 68 }, { 43, 4, 56 },
    };
    s16 tblC[9] = { 40, 36, 39, 31, 32, 35, 33, 37, 38 };

    struct fn_7_1710_bss_5138 *st;
    s16 i;
    s32 ok;
    int done;
    StoryPos *pos;

    fn_1_4CC0();
    fn_8006CE1C(0.0f);
    pos = g->pos;
    if (pos->a == 0) {
        if ((s32)fn_1_F9CA0(0, 1) == 0) {
            lbl_1_bss_9C.unk_3 = 1;
        }
        fn_1_F9CD0(0, 1);
        lbl_1_bss_96A = 0x92;
        return;
    }
    done = fn_1_F9E80((u8)pos->b, (u8)pos->a) == 0;
    lbl_1_bss_5138.unk_10 = 320;
    lbl_1_bss_5138.unk_12 = 200;
    st = &lbl_1_bss_5138;
    if (!done) {
        return;
    }
    st->count3 = 0;
    st->count2 = 0;
    st->unk_0 += tblA[g->pos->a - 1][g->pos->b];
    fn_1_F9EB0((u8)g->pos->b, (u8)g->pos->a);
    if (g->pos->b < 2) {
        fn_1_F9CD0(g->pos->b + 1, g->pos->a);
    }
    switch (g->pos->b) {
    case 0:
        if (g->pos->a < 9) {
            lbl_1_bss_5138.unk_E5 = g->pos->a + 1;
        } else if (g->pos->a == 9 && fn_1_F7EDC(30) == 0) {
            lbl_1_bss_5138.list[st->count3] = 30;
            st->count3++;
        }
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            if (fn_1_F8334(tblB[g->pos->a - 1][i]) == 0) {
                lbl_1_bss_5138.arr[st->count2] = tblB[g->pos->a - 1][i];
                st->count2++;
            }
        }
        if (st->count2 == 0) {
            lbl_1_bss_5138.unk_0 += 10;
        }
        ok = 1;
        for (i = 1; i < 10; i++) {
            if ((s32)fn_1_F9E80(1, (u8)i) == 0) {
                ok = 0;
            }
        }
        if ((u8)ok) {
            lbl_1_bss_5138.list[st->count3] = 34;
            st->count3++;
        }
        break;
    case 2:
        if (fn_1_F7EDC(tblC[g->pos->a - 1]) == 0) {
            lbl_1_bss_5138.list[st->count3] = tblC[g->pos->a - 1];
            st->count3++;
        } else {
            lbl_1_bss_5138.unk_0 += 20;
        }
        break;
    }
    fn_1_3FDA8(g->unk_18, g->unk_1C);
    lbl_1_bss_9C.unk_3 = 1;
}
/* fzgx:end fn_7_1710 */

/* fzgx:begin fn_7_1BA8 */
struct StoryState_1BA8 {
    u8 pad_00[0xe0];
    u8 value_e0;
    u8 pad_e1[1];
    u8 flag_e2;
};

struct StoryFlags_1BA8 {
    u8 pad_00[8];
    u16 flags;
};

extern struct StoryState_1BA8 lbl_1_bss_5138;
extern struct StoryFlags_1BA8 lbl_1_bss_9F8;
extern u16 lbl_1_bss_96A;

void fn_7_1BA8(void) {
    u16 flags = lbl_1_bss_9F8.flags;
    s32 bit = (flags >> 8) & 1;
    struct StoryState_1BA8 *state = &lbl_1_bss_5138;
    if (state->flag_e2 != 0) {
        if (bit != 0) {
            if (state->value_e0 >= 15 && state->value_e0 <= 120) {
                state->value_e0 = 120;
            }
        }
    }

    if (state->flag_e2 == 0) {
        lbl_1_bss_96A = 146;
    }
}
/* fzgx:end fn_7_1BA8 */

/* fzgx:begin fn_7_1C0C */
extern u32 fn_1_48140(u32);

void fn_7_1C0C(void) {
    fn_1_48140(186);
}
/* fzgx:end fn_7_1C0C */

/* fzgx:begin fn_7_1C30 */
struct S58 {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    u8 pad_15;
    u8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[2];
    u32 unk_1C;
};

extern f32 lbl_7_rodata_52C;
extern struct S58 lbl_1_bss_58;
extern u32 lbl_7_bss_10;
extern u32 lbl_7_bss_14;
extern u16 lbl_1_bss_968;
extern u16 lbl_1_bss_96A;
extern u32 fn_80083DB0(u32, u32);
extern u8 lbl_1_bss_198[];
extern s8 lbl_1_bss_9C[];
extern u8 lbl_7_data_13E10[];
extern u32 lbl_801A66B4;

void fn_7_1C30(void) {
    if ((s8)*(u8 *)(*(u32 *)&lbl_7_bss_10) == 9) {
        lbl_1_bss_96A = 147;
    } else {
        u32 off = *(u32 *)(*(u32 *)&lbl_7_bss_14 + 0x1C);
        if (off != 0) {
            u32 p;
            s8 v3;
            fn_80083DB0((u32)&lbl_1_bss_198[0], off);
            fn_80083DB0((u32)&lbl_1_bss_198[0x40], (u32)&lbl_7_data_13E10[0]);
            p = lbl_7_bss_10;
            if ((s8)*(u8 *)p == 0 && lbl_1_bss_9C[3] == 1) {
                *(u32 *)(p + 8) = 134;
            } else {
                *(u32 *)(p + 8) = 135;
            }
            v3 = lbl_1_bss_9C[3];
            lbl_1_bss_58.unk_0 = lbl_801A66B4;
            lbl_1_bss_58.unk_14 = 7;
            lbl_1_bss_58.unk_1 = 1;
            lbl_1_bss_58.unk_2 = 0;
            lbl_1_bss_58.unk_3 = 0;
            lbl_1_bss_58.unk_4 = 640;
            lbl_1_bss_58.unk_6 = 336;
            lbl_1_bss_58.unk_8 = 0;
            lbl_1_bss_58.unk_A = 0;
            lbl_1_bss_58.unk_C = lbl_7_rodata_52C;
            lbl_1_bss_58.unk_10 = lbl_7_rodata_52C;
            lbl_1_bss_58.unk_16 = 0;
            lbl_1_bss_58.unk_17 = -1;
            lbl_1_bss_58.unk_18 = -1;
            lbl_1_bss_58.unk_1C = 0;
            lbl_1_bss_58.unk_14 = 4;
            if (v3 != 1 || *(s8 *)((u8 *)(*(u32 *)&lbl_7_bss_10) + 1) > 0) {
                lbl_1_bss_58.unk_14 |= 1;
            }
            lbl_1_bss_968 = 8;
        } else {
            lbl_1_bss_96A = 135;
        }
    }
}
/* fzgx:end fn_7_1C30 */

/* fzgx:begin fn_7_1DB4 */
// fn_7_1DB4: empty in retail (single blr).
void fn_7_1DB4(void) {
}
/* fzgx:end fn_7_1DB4 */

/* fzgx:begin fn_7_1DB8 */
// fn_7_1DB8: empty in retail (single blr).
void fn_7_1DB8(void) {
}
/* fzgx:end fn_7_1DB8 */

/* fzgx:begin fn_7_1DBC */
struct fn_7_1DBC_lbl_1_bss_58 {
    s8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u16 unk_4;
    u16 unk_6;
    u16 unk_8;
    u16 unk_A;
    f32 unk_C;
    f32 unk_10;
    u8 unk_14;
    u8 pad_15[0x1];
    u8 unk_16;
    s8 unk_17;
    s16 unk_18;
    u8 pad_1A[0x2];
    u32 unk_1C;
};
struct fn_7_1DBC_lbl_7_bss_10_T {
    s8 unk_0;
    s8 unk_1;
    u8 pad_2[0x6];
    u32 unk_8;
};

extern f32 lbl_7_rodata_52C;
extern f32 lbl_7_rodata_5B4;
extern struct fn_7_1DBC_lbl_1_bss_58 lbl_1_bss_58;
extern struct fn_7_1DBC_lbl_7_bss_10_T *lbl_7_bss_10;
extern u16 lbl_1_bss_968;
extern u8 lbl_1_bss_198[];
extern s8 lbl_1_bss_9C[];
extern u8 lbl_7_data_0[];
extern u32 lbl_801A66B4;
extern u32 fn_80083DB0(void *, const void *);

void fn_7_1DBC(void) {
    struct { const u8 *value; } strs;  // retail addresses the TU's strings off one base (+0x10000)
    s8 v3;
    f32 half;
    f32 one;

    strs.value = lbl_7_data_0 + 0x10000;
    fn_80083DB0(lbl_1_bss_198 + 0x000, strs.value + 0x3e4c);
    fn_80083DB0(lbl_1_bss_198 + 0x040, strs.value + 0x3e54);
    fn_80083DB0(lbl_1_bss_198 + 0x080, strs.value + 0x395c);
    fn_80083DB0(lbl_1_bss_198 + 0x0c0, strs.value + 0x3e5c);
    fn_80083DB0(lbl_1_bss_198 + 0x100, strs.value + 0x3e64);
    fn_80083DB0(lbl_1_bss_198 + 0x140, strs.value + 0x3e6c);
    fn_80083DB0(lbl_1_bss_198 + 0x180, strs.value + 0x3e78);
    fn_80083DB0(lbl_1_bss_198 + 0x1c0, strs.value + 0x2fa0);
    fn_80083DB0(lbl_1_bss_198 + 0x200, strs.value + 0x3e80);
    fn_80083DB0(lbl_1_bss_198 + 0x240, strs.value + 0x3144);
    fn_80083DB0(lbl_1_bss_198 + 0x280, strs.value + 0x3e78);
    fn_80083DB0(lbl_1_bss_198 + 0x2c0, strs.value + 0x3240);
    fn_80083DB0(lbl_1_bss_198 + 0x300, strs.value + 0x3e88);
    fn_80083DB0(lbl_1_bss_198 + 0x340, strs.value + 0x3324);
    fn_80083DB0(lbl_1_bss_198 + 0x380, strs.value + 0x3e90);
    fn_80083DB0(lbl_1_bss_198 + 0x3c0, strs.value + 0x342c);
    fn_80083DB0(lbl_1_bss_198 + 0x400, strs.value + 0x3e98);
    fn_80083DB0(lbl_1_bss_198 + 0x440, strs.value + 0x35bc);
    fn_80083DB0(lbl_1_bss_198 + 0x480, strs.value + 0x3ea0);
    fn_80083DB0(lbl_1_bss_198 + 0x4c0, strs.value + 0x376c);
    fn_80083DB0(lbl_1_bss_198 + 0x500, strs.value + 0x3ea8);
    fn_80083DB0(lbl_1_bss_198 + 0x540, strs.value + 0x3844);
    fn_80083DB0(lbl_1_bss_198 + 0x580, strs.value + 0x3eb0);
    fn_80083DB0(lbl_1_bss_198 + 0x5c0, strs.value + 0x3ec0);
    fn_80083DB0(lbl_1_bss_198 + 0x600, strs.value + 0x3e10);

    v3 = lbl_1_bss_9C[3];
    one = lbl_7_rodata_52C;
    lbl_1_bss_58.unk_0 = lbl_801A66B4;
    lbl_1_bss_58.unk_1 = 1;
    lbl_1_bss_58.unk_2 = 0;
    lbl_1_bss_58.unk_3 = 0;
    lbl_1_bss_58.unk_4 = 640;
    lbl_1_bss_58.unk_6 = 336;
    lbl_1_bss_58.unk_8 = 0;
    lbl_1_bss_58.unk_A = 0;
    lbl_1_bss_58.unk_C = one;
    lbl_1_bss_58.unk_10 = one;
    lbl_1_bss_58.unk_14 = 7;
    lbl_1_bss_58.unk_16 = 0;
    lbl_1_bss_58.unk_17 = -1;
    lbl_1_bss_58.unk_18 = -1;
    lbl_1_bss_58.unk_1C = 0;
    lbl_1_bss_58.unk_C = 0.5f;
    lbl_1_bss_58.unk_10 = 0.5f;
    lbl_1_bss_58.unk_8 = 136;
    lbl_1_bss_58.unk_A = 0;
    lbl_1_bss_58.unk_0 = -1;
    lbl_1_bss_58.unk_1 = 0;
    lbl_1_bss_58.unk_3 = 2;
    lbl_1_bss_58.unk_18 = 0;
    lbl_1_bss_58.unk_14 = 4;
    if (v3 != 1 || lbl_7_bss_10->unk_1 > 0) {
        lbl_1_bss_58.unk_14 |= 1;
    }
    lbl_1_bss_968 = 8;
    lbl_7_bss_10->unk_8 = 135;
}
/* fzgx:end fn_7_1DBC */

/* fzgx:begin fn_7_20DC */
// fn_7_20DC: empty in retail (single blr).
void fn_7_20DC(void) {
}
/* fzgx:end fn_7_20DC */

/* fzgx:begin fn_7_20E0 */
// fn_7_20E0: empty in retail (single blr).
void fn_7_20E0(void) {
}
/* fzgx:end fn_7_20E0 */

/* fzgx:begin fn_7_20E4 */
extern u16 lbl_1_bss_96A;

void fn_7_20E4(void) {
    lbl_1_bss_96A = 135;
}
/* fzgx:end fn_7_20E4 */

/* fzgx:begin fn_7_20F4 */
// fn_7_20F4: empty in retail (single blr).
void fn_7_20F4(void) {
}
/* fzgx:end fn_7_20F4 */

/* fzgx:begin fn_7_20F8 */
// fn_7_20F8: empty in retail (single blr).
void fn_7_20F8(void) {
}
/* fzgx:end fn_7_20F8 */

/* fzgx:begin fn_7_20FC */
// fn_7_20FC: empty in retail (single blr).
void fn_7_20FC(void) {
}
/* fzgx:end fn_7_20FC */

/* fzgx:begin fn_7_2100 */
extern u16 lbl_1_bss_96A;

void fn_7_2100(void) {
    lbl_1_bss_96A = 135;
}
/* fzgx:end fn_7_2100 */

/* fzgx:begin fn_7_2110 */
// fn_7_2110: empty in retail (single blr).
void fn_7_2110(void) {
}
/* fzgx:end fn_7_2110 */

/* fzgx:begin fn_7_2114 */
struct fn_7_2114_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA8];
    u32 unk_AC;
    u8 pad_B0[0x18];
    u32 unk_C8;
};
struct fn_7_2114_lbl_7_bss_0 {
    u8 pad_0[0x20];
    u32 unk_20;
    u8 pad_24[0x274];
    u32 unk_298;
    u32 unk_29C;
};

extern struct fn_7_2114_lbl_7_bss_0 lbl_7_bss_0;
extern void fn_7_2170(void);
extern void fn_7_21C8(void);

u32 fn_7_2114(struct fn_7_2114_Arg0 *arg0) {
    struct fn_7_2114_lbl_7_bss_0 *p_lbl_7_bss_0;
    p_lbl_7_bss_0 = (struct fn_7_2114_lbl_7_bss_0 *)&lbl_7_bss_0;
    p_lbl_7_bss_0->unk_298 = 0;
    p_lbl_7_bss_0->unk_29C = 0;
    arg0->unk_AC = (u32)fn_7_21C8;
    arg0->unk_C8 = (u32)fn_7_2170;
    arg0->unk_0 = (arg0->unk_0 | 0x100000);
    if ((s32)p_lbl_7_bss_0->unk_20 != 0) {
    p_lbl_7_bss_0->unk_20 = 0;
    return (u32)arg0;
    }
    arg0->unk_0 = (arg0->unk_0 | 512);
}
/* fzgx:end fn_7_2114 */

/* fzgx:begin fn_7_2170 */
extern struct fn_7_2170_lbl_7_bss_14 lbl_7_bss_14;
extern u32 fn_7_4108(void *, u32, u32);
extern u32 fn_7_41FC(void *);
extern u32 lbl_7_bss_48;

struct fn_7_2170_lbl_7_bss_14 {
    u32 unk_0;
};

s32 fn_7_2170(u32 arg0) {
    if (*(u32 *)((u8 *)lbl_7_bss_14.unk_0 + 36) != 0) {
    fn_7_4108(&lbl_7_bss_48, *(u32 *)((u8 *)lbl_7_bss_14.unk_0 + 36), arg0);
    fn_7_41FC(&lbl_7_bss_48);
    }
    return 0;
}
/* fzgx:end fn_7_2170 */

/* fzgx:begin fn_7_21C8 */
struct fn_7_21C8_Arg0 {
    u32 unk_0;
    u8 pad_4[0xA4];
    u32 unk_A8;
    u32 unk_AC;
    u32 unk_B0;
    u32 unk_B4;
    u32 unk_B8;
    u32 unk_BC;
    u32 unk_C0;
    u32 unk_C4;
    u32 unk_C8;
    u32 unk_CC;
};

struct fn_7_21C8_lbl_7_bss_0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0xC];
    u8 *unk_14;
    u32 unk_18;
    u32 unk_1C;
    u8 pad_20[0x278];
    u32 unk_298;
    u32 unk_29C;
};

extern struct fn_7_21C8_lbl_7_bss_0 lbl_7_bss_0;
extern u8 lbl_7_data_0[];

extern s32 fn_7_232C(void *);
extern int fn_7_2324(void);
extern s32 fn_7_24D8(void);
extern s32 fn_7_2384(void *);
extern s32 fn_7_2514(void);
extern s32 fn_7_23A8(void);
extern s32 fn_7_235C(void);
extern void fn_1_5370(s8, u32);
extern void fn_7_3FCC(void);
extern u32 fn_7_4108(void *, u32, void *);
extern u32 fn_7_41FC(void *);
extern void *fn_1_435C(void *);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_7_44DC(void);

#pragma opt_common_subs off
#pragma opt_propagation off
s32 fn_7_21C8(struct fn_7_21C8_Arg0 *arg0) {
    struct fn_7_21C8_lbl_7_bss_0 *p;
    u8 *base;
    u32 v;
    s32 t6;
    s32 t8;

    p = &lbl_7_bss_0;
    base = lbl_7_data_0 + 0x10000;
    p->unk_298 = 0;
    p->unk_29C = 0;
    arg0->unk_A8 = (u32)fn_7_232C;
    arg0->unk_C4 = (u32)fn_7_23A8;
    arg0->unk_B0 = (u32)fn_7_2324;
    arg0->unk_BC = (u32)fn_7_2384;
    arg0->unk_B8 = (u32)fn_7_24D8;
    arg0->unk_CC = (u32)fn_7_235C;
    arg0->unk_C0 = (u32)fn_7_2514;
    fn_1_5370(0, 0);
    arg0->unk_0 = (arg0->unk_0 | 8);
    fn_7_3FCC();
    v = *(u32 *)(p->unk_14 + 40);
    if (v != 0) {
        fn_7_4108((u8 *)p + 72, v, arg0);
        fn_7_41FC((u8 *)p + 72);
    }
    fn_7_4108((u8 *)p + 72, *(u32 *)(p->unk_14 + 44), arg0);
    fn_1_435C((void *)p->unk_18);
    t6 = fn_1_3F8C((u32)(base + 16076), (u32)fn_7_41FC, (u32)((u8 *)p + 72), 1);
    *(u32 *)(base + 11880) = t6;
    fn_1_435C((void *)p->unk_1C);
    t8 = fn_1_3F8C((u32)(base + 16092), (u32)fn_7_44DC, (u32)((u8 *)p + 72), 1);
    *(u32 *)(base + 11884) = t8;
    fn_1_435C((void *)p->unk_1C);
    p->unk_4 = 420;
    return 0;
}
#pragma opt_propagation reset

#pragma opt_common_subs reset
/* fzgx:end fn_7_21C8 */

/* fzgx:begin fn_7_2324 */
// fn_7_2324: returns a constant.
int fn_7_2324(void) {
    return 0;
}
/* fzgx:end fn_7_2324 */

/* fzgx:begin fn_7_232C */
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_7_bss_0;
u32 fzgx_obj_lbl_7_bss_4[2];
u32 fzgx_obj_lbl_7_bss_C;
u32 fzgx_obj_lbl_7_bss_10;
u32 fzgx_obj_lbl_7_bss_14;
u32 fzgx_obj_lbl_7_bss_18;
u32 fzgx_obj_lbl_7_bss_1C[2];
u32 lbl_7_bss_1C__fzgx_offset_8;
u32 lbl_7_bss_1C__fzgx_offset_C[8];
u32 fzgx_obj_lbl_7_bss_48[148];
s32 lbl_7_bss_48__fzgx_offset_250;
u32 fzgx_obj_lbl_7_bss_29C;
u32 lbl_7_bss_29C__fzgx_offset_4;
u32 lbl_7_bss_29C__fzgx_offset_8[1455];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = fzgx_obj_lbl_7_bss_0;
    s = fzgx_obj_lbl_7_bss_4[0];
    s = fzgx_obj_lbl_7_bss_C;
    s = fzgx_obj_lbl_7_bss_10;
    s = fzgx_obj_lbl_7_bss_14;
    s = fzgx_obj_lbl_7_bss_18;
    s = fzgx_obj_lbl_7_bss_1C[0];
    s = lbl_7_bss_1C__fzgx_offset_8;
    s = lbl_7_bss_1C__fzgx_offset_C[0];
    s = fzgx_obj_lbl_7_bss_48[0];
    s = lbl_7_bss_48__fzgx_offset_250;
    s = fzgx_obj_lbl_7_bss_29C;
    s = lbl_7_bss_29C__fzgx_offset_4;
    s = lbl_7_bss_29C__fzgx_offset_8[0];
}
#pragma section code_type ".text"

s32 fn_7_232C(u32 *arg0) {
    s32 ret = 0;

    lbl_7_bss_29C__fzgx_offset_4 = *arg0;
    lbl_7_bss_1C__fzgx_offset_8 = lbl_7_bss_29C__fzgx_offset_4 & 2;
    if (lbl_7_bss_48__fzgx_offset_250 != 0) {
        ret = 2;
    }
    return ret;
}
/* fzgx:end fn_7_232C */

/* fzgx:begin fn_7_235C */
extern struct fn_7_235C_lbl_7_bss_48 lbl_7_bss_48;

struct fn_7_235C_lbl_7_bss_48 {
    u8 pad_0[0x244];
    u32 unk_244;
};

s32 fn_7_235C(void) {
    u32 v0;
    v0 = lbl_7_bss_48.unk_244;
    if ((lbl_7_bss_48.unk_244 & ~0x7FFFFFFF) != 0) {
    v0 = 1;
    return v0;
    }
    v0 = (-((v0 >> 30) & 0x1));
    return v0;
}
/* fzgx:end fn_7_235C */

/* fzgx:begin fn_7_2384 */
extern u32 lbl_7_bss_29C;

struct fn_7_2384_Arg0 {
    u32 unk_0;
};

s32 fn_7_2384(struct fn_7_2384_Arg0 *arg0) {
    if ((s32)lbl_7_bss_29C == 0) {
    arg0->unk_0 = (arg0->unk_0 | 0x80000);
    }
    return 0;
}
/* fzgx:end fn_7_2384 */

/* fzgx:begin fn_7_23A8 */
struct fn_7_23A8_bss_0 {
    u8 pad_0[0x8];
    s32 unk_8;
    u8 pad_C[0x4];
    u8 *unk_10;
    u8 pad_14[0x8];
    u32 unk_1C;
};

extern u32 lbl_7_bss_0[];
extern u32 lbl_7_data_12E70[2];
extern u8 lbl_7_data_13EEC[52];
extern u8 lbl_1_bss_9F8[];

extern u8 * fn_1_40B14(void);
extern void * fn_1_435C(void *);
extern u32 fn_7_3AB0(void);
extern s32 fn_1_3F8C(u32, u32, u32, u32);
extern u32 fn_1_426C(u32);

#pragma opt_propagation off
#pragma opt_lifetimes off
s32 fn_7_23A8(void) {
    struct fn_7_23A8_bss_0 *p;
    u8 *t0;
    u8 v0;
    u16 v1;
    u32 v2;

    p = (struct fn_7_23A8_bss_0 *)&lbl_7_bss_0;
    t0 = fn_1_40B14();
    v0 = t0[0];
    switch (v0) {
    case 1: {
        s32 res;
        fn_1_435C((void *)p->unk_1C);
        res = fn_1_3F8C((u32)lbl_7_data_13EEC, (u32)fn_7_3AB0, (u32)&p->unk_8, 5);
        p->unk_8 = 10;
        lbl_7_data_12E70[0] = res;
        t0[0] = 2;
        return 4;
    }
    case 2: {
        u8 *tbl;
        tbl = (u8 *)lbl_1_bss_9F8 + 8;
        v2 = (s8)p->unk_10[2] * 20;
        v1 = *(u16 *)(tbl + v2);
        if (((v1 >> 9) & 1) || ((v1 >> 8) & 1) || ((v1 >> 12) & 1)) {
            t0[0] = 3;
            p->unk_8 = 10;
        }
        return 4;
    }
    case 3:
        if (p->unk_8 != 0) {
            return 4;
        }
        fn_1_435C((void *)p->unk_1C);
        fn_1_426C(lbl_7_data_12E70[0]);
        t0[0] = 0;
        break;
    }
    return 0;
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
/* fzgx:end fn_7_23A8 */

/* fzgx:begin fn_7_24D8 */
struct fn_7_24D8_lbl_7_bss_29C {
    u32 unk_0;
};

extern struct fn_7_24D8_lbl_7_bss_29C lbl_7_bss_29C;
extern u32 fn_7_3FCC(void);

s32 fn_7_24D8(void) {
    if ((s32)lbl_7_bss_29C.unk_0 == 0) {
    lbl_7_bss_29C.unk_0 = 1;
    fn_7_3FCC();
    }
    return 2;
}
/* fzgx:end fn_7_24D8 */

/* fzgx:begin fn_7_2514 */
extern u32 fn_7_3FCC(void);

s32 fn_7_2514(void) {
    fn_7_3FCC();
    return 0;
}
/* fzgx:end fn_7_2514 */

/* fzgx:begin fn_7_31F4 */
#include "font.h"

struct fn_7_31F4_Copy88 { u32 a[22]; };
struct fn_7_31F4_lbl_7_rodata_0 {
    u8 pad_0[0x528];
    f32 unk_528;
    f32 unk_52C;
    u8 pad_530[0x84];
    f32 unk_5B4;
    u8 pad_5B8[0x120];
    f32 unk_6D8;
    f32 unk_6DC;
    f32 unk_6E0;
    f32 unk_6E4;
    f32 unk_6E8;
    f32 unk_6EC;
};

extern int fn_1_4F734(FontDrawPacket *);
extern struct fn_7_31F4_lbl_7_rodata_0 lbl_7_rodata_0;
extern u32 fn_1_49410(void);
extern u32 lbl_1_rodata_26F8;
extern u32 lbl_7_data_13F20;
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_495A0(f32);
extern void fn_1_495C8(u8);
extern void fn_1_4965C(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AE0C(const char *, ...);

void fn_7_31F4(u32 arg0, u32 arg1, u32 arg2, f32 arg3, f32 arg4) {
    struct fn_7_31F4_lbl_7_rodata_0 *p_lbl_7_rodata_0;
    f32 v0;
    FontDrawPacket loc_8;
    /* frame */
    p_lbl_7_rodata_0 = (struct fn_7_31F4_lbl_7_rodata_0 *)&lbl_7_rodata_0;
    v0 = p_lbl_7_rodata_0->unk_52C;
    if ((arg2 & 0xFF) == 0) {
    v0 = p_lbl_7_rodata_0->unk_5B4;
    }
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_8.image = (0x10000 - 17887);
    loc_8.x = arg3;
    loc_8.y = arg4;
    loc_8.z = (loc_8.z - p_lbl_7_rodata_0->unk_6D8);
    loc_8.alpha = v0;
    loc_8.flags = 11;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8.rotation_z = -32768;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
    loc_8.image = arg0;
    loc_8.x = arg3;
    loc_8.y = arg4;
    loc_8.z = (loc_8.z - p_lbl_7_rodata_0->unk_6DC);
    loc_8.alpha = v0;
    loc_8.flags = 15;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8.flags = (0x100000 + 7);
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8.rotation_z = -32768;
    loc_8.flags = 15;
    fn_1_4F734((FontDrawPacket *)&loc_8);
    loc_8.flags = (0x100000 + 7);
    fn_1_4F734((FontDrawPacket *)&loc_8);
    fn_1_49410();
    fn_1_4965C(2);
    fn_1_495C8(1);
    fn_1_495A0(v0);
    fn_1_4966C(p_lbl_7_rodata_0->unk_6E0, p_lbl_7_rodata_0->unk_528);
    fn_1_4955C(p_lbl_7_rodata_0->unk_5B4, p_lbl_7_rodata_0->unk_6E4);
    fn_1_4954C(p_lbl_7_rodata_0->unk_6E8);
    fn_1_496FC(arg3, (arg4 - p_lbl_7_rodata_0->unk_6EC));
    fn_1_4AE0C((const char *)(u32)&lbl_7_data_13F20, arg1);
}
/* fzgx:end fn_7_31F4 */

/* fzgx:begin fn_7_3AB0 */
#include "font.h"

typedef struct fn_7_3AB0_Entry {
    u8 pad_0[0x34];
    u32 msg[4][3];
    u8 pad_64[0x20];
} fn_7_3AB0_Entry;

struct fn_7_3AB0_lbl_7_bss_10 {
    s8 *unk_0;
};

extern u32 fn_1_50A90(void *, u32, u32, u32, u32);
extern FontDrawPacket lbl_1_rodata_26F8;
extern char lbl_7_data_13F20[];
extern char lbl_7_data_13F2C[];
extern char lbl_7_data_13F34[];
extern char lbl_7_data_13F3C[];
extern u32 lbl_801A66B4;
extern u8 *fn_1_40B14(void);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u8);
extern void fn_1_495FC(void);
extern void fn_1_4965C(u8);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_4AF64(const char *, ...);

/* story course table: first object of the TU's .rodata */
extern u8 lbl_7_data_0__fzgx_offset_0[];
extern u8 lbl_7_data_100A8__fzgx_offset_0[];
extern u8 lbl_7_data_105A0__fzgx_offset_0[];
extern u8 lbl_7_data_108A0__fzgx_offset_0[];
extern u8 lbl_7_data_109C0__fzgx_offset_0[];
extern u8 lbl_7_data_11470__fzgx_offset_0[];
extern u8 lbl_7_data_116E0__fzgx_offset_0[];
extern u8 lbl_7_data_117B8__fzgx_offset_0[];
extern u8 lbl_7_data_12790__fzgx_offset_0[];
extern u8 lbl_7_data_12958__fzgx_offset_0[];
extern u8 lbl_7_data_129A0__fzgx_offset_0[];
extern u8 lbl_7_data_12A00__fzgx_offset_0[];
extern u8 lbl_7_data_12E7C__fzgx_offset_0[];
extern u8 lbl_7_data_12EB8__fzgx_offset_0[];
extern u8 lbl_7_data_12EC8__fzgx_offset_0[];
extern u8 lbl_7_data_12ECC__fzgx_offset_0[];
extern u8 lbl_7_data_12ED4__fzgx_offset_0[];
extern u8 lbl_7_data_12F58__fzgx_offset_0[];
extern u8 lbl_7_data_12F90__fzgx_offset_0[];
extern u8 lbl_7_data_12FA0__fzgx_offset_0[];
extern u8 lbl_7_data_12FB0__fzgx_offset_0[];
extern u8 lbl_7_data_12FCC__fzgx_offset_0[];
extern u8 lbl_7_data_13034__fzgx_offset_0[];
extern u8 lbl_7_data_1309C__fzgx_offset_0[];
extern u8 lbl_7_data_130F4__fzgx_offset_0[];
extern u8 lbl_7_data_13134__fzgx_offset_0[];
extern u8 lbl_7_data_13144__fzgx_offset_0[];
extern u8 lbl_7_data_13154__fzgx_offset_0[];
extern u8 lbl_7_data_13168__fzgx_offset_0[];
extern u8 lbl_7_data_1319C__fzgx_offset_0[];
extern u8 lbl_7_data_131F4__fzgx_offset_0[];
extern u8 lbl_7_data_13230__fzgx_offset_0[];
extern u8 lbl_7_data_13240__fzgx_offset_0[];
extern u8 lbl_7_data_13250__fzgx_offset_0[];
extern u8 lbl_7_data_13268__fzgx_offset_0[];
extern u8 lbl_7_data_132D4__fzgx_offset_0[];
extern u8 lbl_7_data_13314__fzgx_offset_0[];
extern u8 lbl_7_data_13324__fzgx_offset_0[];
extern u8 lbl_7_data_13334__fzgx_offset_0[];
extern u8 lbl_7_data_13384__fzgx_offset_0[];
extern u8 lbl_7_data_133EC__fzgx_offset_0[];
extern u8 lbl_7_data_1341C__fzgx_offset_0[];
extern u8 lbl_7_data_1342C__fzgx_offset_0[];
extern u8 lbl_7_data_1343C__fzgx_offset_0[];
extern u8 lbl_7_data_1348C__fzgx_offset_0[];
extern u8 lbl_7_data_134DC__fzgx_offset_0[];
extern u8 lbl_7_data_1352C__fzgx_offset_0[];
extern u8 lbl_7_data_13574__fzgx_offset_0[];
extern u8 lbl_7_data_135AC__fzgx_offset_0[];
extern u8 lbl_7_data_135BC__fzgx_offset_0[];
extern u8 lbl_7_data_135CC__fzgx_offset_0[];
extern u8 lbl_7_data_1361C__fzgx_offset_0[];
extern u8 lbl_7_data_1366C__fzgx_offset_0[];
extern u8 lbl_7_data_136BC__fzgx_offset_0[];
extern u8 lbl_7_data_13724__fzgx_offset_0[];
extern u8 lbl_7_data_1375C__fzgx_offset_0[];
extern u8 lbl_7_data_1376C__fzgx_offset_0[];
extern u8 lbl_7_data_1377C__fzgx_offset_0[];
extern u8 lbl_7_data_1379C__fzgx_offset_0[];
extern u8 lbl_7_data_137F4__fzgx_offset_0[];
extern u8 lbl_7_data_13834__fzgx_offset_0[];
extern u8 lbl_7_data_13844__fzgx_offset_0[];
extern u8 lbl_7_data_13854__fzgx_offset_0[];
extern u8 lbl_7_data_138A4__fzgx_offset_0[];
extern u8 lbl_7_data_1390C__fzgx_offset_0[];
extern u8 lbl_7_data_1394C__fzgx_offset_0[];
extern u8 lbl_7_data_1395C__fzgx_offset_0[];
extern u8 lbl_7_data_1396C__fzgx_offset_0[];
extern u8 lbl_7_data_139BC__fzgx_offset_0[];
extern u8 lbl_7_data_1FF8__fzgx_offset_0[];
extern u8 lbl_7_data_22C8__fzgx_offset_0[];
extern u8 lbl_7_data_2418__fzgx_offset_0[];
extern u8 lbl_7_data_25B0__fzgx_offset_0[];
extern u8 lbl_7_data_2A0__fzgx_offset_0[];
extern u8 lbl_7_data_2E8__fzgx_offset_0[];
extern u8 lbl_7_data_348__fzgx_offset_0[];
extern u8 lbl_7_data_6618__fzgx_offset_0[];
extern u8 lbl_7_data_6AB0__fzgx_offset_0[];
extern u8 lbl_7_data_6DB0__fzgx_offset_0[];
extern u8 lbl_7_data_6E40__fzgx_offset_0[];
extern u8 lbl_7_data_A98__fzgx_offset_0[];
extern u8 lbl_7_data_BC20__fzgx_offset_0[];
extern u8 lbl_7_data_BEA8__fzgx_offset_0[];
extern u8 lbl_7_data_BF80__fzgx_offset_0[];
extern u8 lbl_7_data_C010__fzgx_offset_0[];
extern u8 lbl_7_data_C90__fzgx_offset_0[];
extern u8 lbl_7_data_C958__fzgx_offset_0[];
extern u8 lbl_7_data_CE80__fzgx_offset_0[];
extern u8 lbl_7_data_CF0__fzgx_offset_0[];
extern u8 lbl_7_data_D450__fzgx_offset_0[];
extern u8 lbl_7_data_D4C8__fzgx_offset_0[];
extern u8 lbl_7_data_DC8__fzgx_offset_0[];
static const union { u32 w[330]; const fn_7_3AB0_Entry v[10]; } fzgx_pool_init_fzgx_story_table = {{  /* fzgx-allow: A1 retail data bytes and bindings */
    0x0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, (u32)lbl_7_data_12E7C__fzgx_offset_0, 0x0, (u32)lbl_7_data_12EB8__fzgx_offset_0,
    0x0, 0x0, 0x0, 0x0, (u32)lbl_7_data_12EC8__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0,
    (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0,
    (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ECC__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0, (u32)lbl_7_data_12ED4__fzgx_offset_0,
    (u32)lbl_7_data_12ED4__fzgx_offset_0, 0x1250000, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F58__fzgx_offset_0, (u32)lbl_7_data_12F90__fzgx_offset_0,
    (u32)lbl_7_data_12FA0__fzgx_offset_0, (u32)lbl_7_data_0__fzgx_offset_0, (u32)lbl_7_data_2A0__fzgx_offset_0, (u32)lbl_7_data_2E8__fzgx_offset_0, (u32)lbl_7_data_348__fzgx_offset_0, (u32)lbl_7_data_12FB0__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0,
    (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0,
    (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_12FCC__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_13034__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0,
    (u32)lbl_7_data_1309C__fzgx_offset_0, (u32)lbl_7_data_1309C__fzgx_offset_0, 0x2260000, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0, (u32)lbl_7_data_130F4__fzgx_offset_0,
    (u32)lbl_7_data_13134__fzgx_offset_0, (u32)lbl_7_data_13144__fzgx_offset_0, (u32)lbl_7_data_A98__fzgx_offset_0, (u32)lbl_7_data_C90__fzgx_offset_0, (u32)lbl_7_data_CF0__fzgx_offset_0, (u32)lbl_7_data_DC8__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0,
    (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0,
    (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_13168__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0,
    (u32)lbl_7_data_1319C__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0, (u32)lbl_7_data_1319C__fzgx_offset_0, 0x3270000, (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_131F4__fzgx_offset_0,
    (u32)lbl_7_data_131F4__fzgx_offset_0, (u32)lbl_7_data_13230__fzgx_offset_0, (u32)lbl_7_data_13240__fzgx_offset_0, (u32)lbl_7_data_1FF8__fzgx_offset_0, (u32)lbl_7_data_22C8__fzgx_offset_0, (u32)lbl_7_data_2418__fzgx_offset_0, (u32)lbl_7_data_25B0__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0,
    (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0,
    (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13250__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0,
    (u32)lbl_7_data_13268__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0, (u32)lbl_7_data_13268__fzgx_offset_0, 0x4280000, (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_132D4__fzgx_offset_0,
    (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_132D4__fzgx_offset_0, (u32)lbl_7_data_13314__fzgx_offset_0, (u32)lbl_7_data_13324__fzgx_offset_0, (u32)lbl_7_data_6618__fzgx_offset_0, (u32)lbl_7_data_6AB0__fzgx_offset_0, (u32)lbl_7_data_6DB0__fzgx_offset_0, (u32)lbl_7_data_6E40__fzgx_offset_0,
    (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0,
    (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0, (u32)lbl_7_data_13334__fzgx_offset_0,
    (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, (u32)lbl_7_data_13384__fzgx_offset_0, 0x5290000, (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_133EC__fzgx_offset_0,
    (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_133EC__fzgx_offset_0, (u32)lbl_7_data_1341C__fzgx_offset_0, (u32)lbl_7_data_1342C__fzgx_offset_0, (u32)lbl_7_data_BC20__fzgx_offset_0, (u32)lbl_7_data_BEA8__fzgx_offset_0, (u32)lbl_7_data_BF80__fzgx_offset_0,
    (u32)lbl_7_data_C010__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0,
    (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0, (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1343C__fzgx_offset_0, (u32)lbl_7_data_1348C__fzgx_offset_0,
    (u32)lbl_7_data_134DC__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, (u32)lbl_7_data_1352C__fzgx_offset_0, 0x62A0000, (u32)lbl_7_data_13574__fzgx_offset_0,
    (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_13574__fzgx_offset_0, (u32)lbl_7_data_135AC__fzgx_offset_0, (u32)lbl_7_data_135BC__fzgx_offset_0, (u32)lbl_7_data_C958__fzgx_offset_0, (u32)lbl_7_data_CE80__fzgx_offset_0,
    (u32)lbl_7_data_D450__fzgx_offset_0, (u32)lbl_7_data_D4C8__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0,
    (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0, (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_135CC__fzgx_offset_0,
    (u32)lbl_7_data_1361C__fzgx_offset_0, (u32)lbl_7_data_1366C__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, (u32)lbl_7_data_136BC__fzgx_offset_0, 0x72B0000,
    (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_13724__fzgx_offset_0, (u32)lbl_7_data_1375C__fzgx_offset_0, (u32)lbl_7_data_1376C__fzgx_offset_0, (u32)lbl_7_data_100A8__fzgx_offset_0,
    (u32)lbl_7_data_105A0__fzgx_offset_0, (u32)lbl_7_data_108A0__fzgx_offset_0, (u32)lbl_7_data_109C0__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0,
    (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0,
    (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1377C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0, (u32)lbl_7_data_1379C__fzgx_offset_0,
    0x82C0000, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_137F4__fzgx_offset_0, (u32)lbl_7_data_13834__fzgx_offset_0, (u32)lbl_7_data_13844__fzgx_offset_0,
    (u32)lbl_7_data_11470__fzgx_offset_0, 0x0, (u32)lbl_7_data_116E0__fzgx_offset_0, (u32)lbl_7_data_117B8__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0,
    (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0,
    (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_13854__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0, (u32)lbl_7_data_138A4__fzgx_offset_0,
    (u32)lbl_7_data_138A4__fzgx_offset_0, 0x92D0000, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1390C__fzgx_offset_0, (u32)lbl_7_data_1394C__fzgx_offset_0,
    (u32)lbl_7_data_1395C__fzgx_offset_0, (u32)lbl_7_data_12790__fzgx_offset_0, (u32)lbl_7_data_12958__fzgx_offset_0, (u32)lbl_7_data_129A0__fzgx_offset_0, (u32)lbl_7_data_12A00__fzgx_offset_0, (u32)lbl_7_data_13154__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0,
    (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0,
    (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_1396C__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0,
    (u32)lbl_7_data_139BC__fzgx_offset_0, (u32)lbl_7_data_139BC__fzgx_offset_0
}};

/* pool primer: reproduces the TU literal pool ahead of this function */
extern void fzgx_sink_f(f32);
extern void fzgx_sink_p(const void *);

#pragma section RX ".fzgxpool" ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_0(void) { fzgx_sink_f(0.0f); fzgx_sink_f(1.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_1(void) {
    u32 b[33] = {
        0x000F0019, 0x0023000F, 0x00190023, 0x000F0019, 0x00230014, 0x00190023, 0x00140019,
        0x00230019, 0x001E0028, 0x0019001E, 0x0028001E, 0x0023002D, 0x001E0023, 0x002D0000,
        0x001F0010, 0x0047001D, 0x000A0048, 0x001E0003, 0x00420023, 0x0002003B, 0x002A0007,
        0x00370021, 0x0015003F, 0x001B0005, 0x00330028, 0x000F0044, 0x002B0004, 0x00380000,
        0x00280024, 0x0027001F, 0x00200023, 0x00210025, 0x00260000 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_2(void) { fzgx_sink_f(0.5f); }
__declspec(section ".fzgxpool") void fzgx_pool_3(void) {
    u32 b[32] = {
        0, 0, 0xC1080000, 0, 0, 0, 0xFF, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0,  /* fzgx-allow: A1 float bits -8.5f in primer data */
        0x3F4CCCCD, 0, 0x43600000, 0x43D00000, 0, 0x43380000, 0x43A00000, 0x43E40000,
        0xFFFF0000, 0x43270000, 0x42180000, 0x42B40000, 0xC1080000, 0x3E99999A };  /* fzgx-allow: A1 float bits -8.5f in primer data */
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_4(void) { fzgx_sink_f(320.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_5(void) {
    u32 b[9] = { 0x43700000, 0x44200000, 0x43F00000, 0x435C0000, 0x425C0000,
                 0x3FE38E39, 0x3DCCCCCD, 0x47AFC800, 0x3FAAAAAB };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_6(void) { fzgx_sink_f(0.8f); }
__declspec(section ".fzgxpool") void fzgx_pool_7(void) {
    u32 b[3] = { 0x41000000, 0x3F955555, 0x3E800000 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_8(void) { fzgx_sink_f(200.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_9(void) {
    u32 b[13] = { 0x40000000, 0x3F400000, 0x437A0000, 0x47800000, 0x41F00000, 0x42200000,
                  0x41700000, 0x44160000, 0x43B20000, 0x42A00000, 0x42C80000, 0x42A40000,
                  0x3F555555 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_10(void) { fzgx_sink_f(16.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_11(void) {
    u32 b[4] = { 0x43A40000, 0x43AC8000, 0x3B449BA6, 0x46800000 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_12(void) { fzgx_sink_f(60.0f); }
__declspec(section ".fzgxpool") void fzgx_pool_13(void) {
    u32 b[1] = { 0x43B68000 };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_14(s32 a, u32 b) { fzgx_sink_f((f32)a); fzgx_sink_f((f32)b); }
__declspec(section ".fzgxpool") void fzgx_pool_15(void) {
    u32 b[2] = { 0x3B03126F, 0x3B83126F };
    fzgx_sink_p(b);
}
__declspec(section ".fzgxpool") void fzgx_pool_16(void) { fzgx_sink_f(-1.0f); fzgx_sink_f(0.5833333134651184f); }
__declspec(section ".fzgxpool") void fzgx_pool_17(void) {
    u32 b[17] = { 0x3DB851EC, 0x40E00000, 0xFFFFFF00, 0x43600000, 0x43080000, 0x3C23D70A,
                  0x3CF5C28F, 0x3D23D70A, 0x3F94C1BB, 0x43450000, 0x42680000, 0x43BA0000,
                  0x38D1B717, 0x41400000, 0x41B00000, 0x41100000, 0x41600000 };
    fzgx_sink_p(b);
}
#pragma section RX ".text" ".text"

#pragma fp_contract off
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
s8 *fzgx_obj_lbl_7_bss_10;
u32 fzgx_obj_lbl_7_bss_14;
u32 lbl_7_bss_18;
u32 fzgx_obj_lbl_7_bss_1C[11];
u32 fzgx_obj_lbl_7_bss_48[149];
u32 fzgx_obj_lbl_7_bss_29C[1457];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&fzgx_obj_lbl_7_bss_10;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_14;
    s = *(u8 *)&lbl_7_bss_18;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_1C;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_48;
    s = *(u8 *)&fzgx_obj_lbl_7_bss_29C;
}
#pragma section code_type ".text"

void fn_7_3AB0(s32 *arg0) {
    f32 f;
    FontDrawPacket pkt;
    u8 *state;
    f32 t;
    f32 y;
    s32 n;

    state = fn_1_40B14();
    t = (10.0f - *arg0) / 10.0f;
    if (*state == 3) {
        t = 1.0f - t;
    }
    t = t * t;

    pkt = lbl_1_rodata_26F8;
    pkt.x = 320.0f;
    pkt.y = 200.0f;
    pkt.z = 1e-6f;
    pkt.flags = 10;
    pkt.image = 2;
    pkt.alpha = t;
    n = 3.0f * (45.0f * t);
    if (n > 45) {
        n = 45;
    }
    f = 1.1f;
    f *= t;
    if (f > 1.0f) {
        f = 1.0f;
    }
    fn_1_50A90(&pkt, 18, n, 480, (s32)(188.0f * f));

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0xBA11;
    pkt.x = 214.0f;
    y = 200.0f - 60.0f * t;
    pkt.y = y;
    pkt.z = 9e-7f;
    pkt.scale_y = t;
    pkt.alpha = t;
    fn_1_4F734(&pkt);

    pkt = lbl_1_rodata_26F8;
    pkt.image = 0xBA12;
    pkt.x = 390.0f;
    pkt.y = y;
    pkt.z = 9e-7f;
    pkt.scale_y = t;
    pkt.alpha = t;
    fn_1_51678(&pkt, 0xBA12, fzgx_obj_lbl_7_bss_10[0] * 36, 0, 36, 24);
    fn_1_4F734(&pkt);

    fn_1_49410();
    fn_1_495FC();
    fn_1_4954C(9e-7f);
    fn_1_495C8(1);
    fn_1_49590(0.4f);
    fn_1_4966C(0.0f, 16.0f);
    fn_1_4965C(2);
    fn_1_495B0(0x80000000);
    fn_1_494DC(42);
    fn_1_4955C(0.8f, 0.8f * t);
    fn_1_495A0(t);
    fn_1_496FC(320.0f, 200.0f + 10.0f * t);
    fn_1_4AF64(lbl_7_data_13F20,
               fzgx_pool_init_fzgx_story_table.v[fzgx_obj_lbl_7_bss_10[0]].msg[lbl_801A66B4][fzgx_obj_lbl_7_bss_10[1]]);

    if (fzgx_obj_lbl_7_bss_10[1] > 0) {
        u32 images[3] = { 0xBA17, 0xBA18, 0xBA19 };
        char *names[3] = { lbl_7_data_13F2C, lbl_7_data_13F34, lbl_7_data_13F3C };

        pkt = lbl_1_rodata_26F8;
        pkt.image = 0xBA21;
        pkt.x = 320.0f;
        y = 200.0f - 20.0f * t;
        pkt.y = y;
        pkt.z = 9e-7f;
        pkt.scale_y = t;
        pkt.alpha = t;
        pkt.flags = 11;
        fn_1_4F734(&pkt);
        pkt.rotation_z = -32768;
        fn_1_4F734(&pkt);

        pkt = lbl_1_rodata_26F8;
        pkt.image = images[fzgx_obj_lbl_7_bss_10[1]];
        pkt.x = 320.0f;
        pkt.y = y;
        pkt.z = 8e-7f;
        pkt.scale_y = t;
        pkt.alpha = t;
        pkt.flags = 15;
        fn_1_4F734(&pkt);
        pkt.flags = 0x100007;
        fn_1_4F734(&pkt);
        pkt.rotation_z = -32768;
        pkt.flags = 15;
        fn_1_4F734(&pkt);
        pkt.flags = 0x100007;
        fn_1_4F734(&pkt);

        fn_1_49410();
        fn_1_4965C(2);
        fn_1_495C8(1);
        fn_1_495A0(t);
        fn_1_4966C(-1.0f, 0.0f);
        fn_1_4955C(0.5f, 0.5833333134651184f * t);
        fn_1_4954C(9e-7f);
        fn_1_496FC(320.0f, 200.0f - 27.0f * t);
        fn_1_4AE0C(lbl_7_data_13F20, names[fzgx_obj_lbl_7_bss_10[1]]);
    }
}
/* fzgx:end fn_7_3AB0 */

/* fzgx:begin fn_7_3FCC */
struct fn_7_3FCC_lbl_7_bss_18 {
    u32 unk_0;
};
struct fn_7_3FCC_lbl_7_data_12E68 {
    u32 unk_0;
};
struct fn_7_3FCC_lbl_7_bss_1C {
    u32 unk_0;
};
struct fn_7_3FCC_lbl_7_data_12E6C {
    u32 unk_0;
};

extern struct fn_7_3FCC_lbl_7_bss_18 lbl_7_bss_18;
extern struct fn_7_3FCC_lbl_7_bss_1C lbl_7_bss_1C;
extern struct fn_7_3FCC_lbl_7_data_12E68 lbl_7_data_12E68;
extern struct fn_7_3FCC_lbl_7_data_12E6C lbl_7_data_12E6C;
extern u32 fn_1_426C(u32);
extern u32 fn_1_435C(u32);

void fn_7_3FCC(void) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t1, t3;
    fn_1_435C(lbl_7_bss_18.unk_0);
    v0 = lbl_7_data_12E68.unk_0;
    v1 = v0;
    if ((s32)v0 != -1) {
    t1 = fn_1_426C(v1);
    v1 = t1;
    lbl_7_data_12E68.unk_0 = -1;
    }
    fn_1_435C(lbl_7_bss_1C.unk_0);
    v2 = lbl_7_data_12E6C.unk_0;
    v3 = v2;
    if ((s32)v2 != -1) {
    t3 = fn_1_426C(v3);
    v3 = t3;
    lbl_7_data_12E6C.unk_0 = -1;
    }
}
/* fzgx:end fn_7_3FCC */

/* fzgx:begin fn_7_4050 */
extern s32 fn_1_13018(void);
extern s32 fn_1_467F4(void);
extern void fn_1_451E4(void);
extern void fn_1_D3214(void);
extern void fn_8001AF64(void);

void fn_7_4050(void) {
    while (fn_1_467F4() || fn_1_13018()) {
        fn_1_451E4();
        fn_1_D3214();
        fn_8001AF64();
    }
}
/* fzgx:end fn_7_4050 */

/* fzgx:begin fn_7_4094 */
extern u32 fn_1_4404(u32);
extern u32 fn_1_46B4(u32, u32, u32, u32);
extern u32 fn_80008E84(u32);
extern u32 lbl_7_data_13A3C;
extern u32 lbl_801A6410;

u32 fn_7_4094(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 v3;
    u32 t0, t1, t2;
    t0 = fn_1_4404(arg0);
    v0 = *(u32 *)((u8 *)arg0 + 0);
    v1 = arg2;
    v2 = t0;
    v3 = arg3;
    if ((v0 + 0x10000) != 65535) {
    v3 = (u32)&lbl_801A6410;
    v1 = (u32)&lbl_7_data_13A3C;
    v2 = *(u32 *)((u8 *)v3 + 0);
    v3 = 2443;
    t1 = fn_1_46B4(v2, v0, (u32)v1, v3);
    v2 = t1;
    *(u32 *)((u8 *)arg0 + 0) = -1;
    }
    v2 = t0;
    t2 = fn_80008E84(v2);
    v2 = t2;
    return v2;
}
/* fzgx:end fn_7_4094 */

/* fzgx:begin fn_7_41FC */
#include "rel/story/story_mode.h"

typedef struct StoryTrigger {
    u16 type;
    u8 pad_2[0x16];
} StoryTrigger;

extern const f32 lbl_7_rodata_784;
extern f32 lbl_7_rodata_788[4];
extern s32 fn_7_4648(u32 *, StoryTrigger *);
extern u32 fn_7_4FD0(u32 *, StoryTrigger *);
extern void OSReport(const char *, ...);

static inline f32 clamp_value(f32 x) {
    if (x < lbl_7_rodata_784) return lbl_7_rodata_784;
    if (x > lbl_7_rodata_788[0]) return lbl_7_rodata_788[0];
    return x;
}

#pragma opt_propagation off
void fn_7_41FC(u32 *flags) {
    Obj_7_bss_1960 *g = &lbl_7_bss_1960;
    StoryTrigger *t;
    s32 *timer;
    u32 i;
    u32 n;
    s32 ok;

    t = (StoryTrigger *)g->unk_30;
    timer = (s32 *)(flags + 0x80);
    for (i = 0; i < 8; i++, timer++) {
        if (!__rlwnm(g->unk_C, (i + 1) & 31, 31, 31) && *timer >= 0) {
            (*timer)--;
        }
    }

    n = 0;
    while (t->type != 5) {
        ok = 1;
        while (t->type <= 3) {
            if (n >= 0x1000) {
                OSReport("Too Many Scenario Trigger\n\n");
                return;
            }
            if (__rlwnm(flags[n >> 5], ((n & 31) + 1) & 31, 31, 31)) {
                ok = 0;
                break;
            }
            if (t->type == 2 || t->type == 3) {
                if (fn_7_4648(flags, t)) {
                    ok = 0;
                    break;
                }
            } else if (!fn_7_4648(flags, t)) {
                ok = 0;
                break;
            }
            t++;
            n++;
        }
        if (ok) {
            StoryTrigger *p = t - 1;
            u32 j = n - 1;
            while (p->type <= 3 && j != -1) {
                if (p->type == 0 || p->type == 2) {
                    flags[j >> 5] |= 0x80000000U >> (j & 31);
                }
                p--;
                j--;
            }
            while (t->type == 4) {
                fn_7_4FD0(flags, t);
                t++;
            }
        } else {
            while (t->type <= 3) {
                t++;
                n++;
            }
            while (t->type == 4) {
                t++;
            }
        }
    }

    {
        u8 *active = &g->unk_18;
        f32 *pos;
        f32 *vel;
        u8 k;
        for (k = 0; k < 2; k++) {
            if (active[k]) {
                pos = &g->unk_1C;
                vel = &g->unk_24;
                pos[k] = pos[k] + vel[k];
                pos[k] = clamp_value(pos[k]);
            }
        }
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_7_41FC */

/* fzgx:begin fn_7_44DC */
#include "font.h"

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u32 fzgx_obj_lbl_7_bss_1960[4];
u32 lbl_7_bss_1960__fzgx_offset_10[2];
u8 lbl_7_bss_1960__fzgx_offset_18[2];
f32 lbl_7_bss_1960__fzgx_offset_1C[2];

#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_bss_prime(void) {
    volatile u32 s;  /* fzgx-allow: S2 primer sink */
    s = ((0)[fzgx_obj_lbl_7_bss_1960]);
    s = lbl_7_bss_1960__fzgx_offset_10[0];
    s = lbl_7_bss_1960__fzgx_offset_18[0];
    s = lbl_7_bss_1960__fzgx_offset_1C[0];
}
#pragma section code_type ".text"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 1.0f;
    s = 300.0f;
    s = 640.0f;
    s = 480.0f;
    d = 4503599627370496.0;
}
#pragma section code_type ".text"

extern u32 lbl_1_rodata_26F8;
extern u16 fn_1_48690(u32);
extern int fn_1_4F734(FontDrawPacket *);

#pragma opt_propagation off
#pragma peephole on
#pragma opt_common_subs on
void fn_7_44DC(void) {
    u16 v1;
    u8 i;

    i = 0;
    while (i < 2) {
        v1 = (u16)(i);
        if (lbl_7_bss_1960__fzgx_offset_18[v1] != 0) {
{
    FontDrawPacket loc_8;
            loc_8 = *(FontDrawPacket *)&lbl_1_rodata_26F8;
            loc_8.image = 18;
            loc_8.x = 0.0f;
            loc_8.y = 0.0f;
            loc_8.z = 300.0f - (f32)i;
            loc_8.flags = 5;
{
    s16 t0;
            loc_8.scale_x = loc_8.scale_x * (640.0f / (f32)(fn_1_48690(18)));
}
{
    u32 t1;
    f32 r;
            r = 480.0f / (f32)fn_1_48690(18);
            loc_8.scale_y = loc_8.scale_y * r;
            *(u32 *)((u8 *)&loc_8 + 0x38) = lbl_7_bss_1960__fzgx_offset_10[v1];
            loc_8.alpha = lbl_7_bss_1960__fzgx_offset_1C[v1];
}
            fn_1_4F734(&loc_8);
}
        }
        i++;
    }
}
#pragma opt_common_subs reset

#pragma peephole reset

#pragma opt_propagation reset
/* fzgx:end fn_7_44DC */

/* fzgx:begin fn_7_4E28 */
extern char lbl_7_data_13FFC[15];
extern void OSReport(char *, ...);

s32 fn_7_4E28(s32 arg0, s32 arg1, s32 arg2) {
    s32 result;

    result = 0;
    switch (arg0) {
    case 0:
        if (arg1 == arg2) {
            result = 1;
        }
        break;
    case 1:
        if (arg1 != arg2) {
            result = 1;
        }
        break;
    case 2:
        if (arg1 >= arg2) {
            result = 1;
        }
        break;
    case 3:
        if (arg1 > arg2) {
            result = 1;
        }
        break;
    case 4:
        if (arg1 <= arg2) {
            result = 1;
        }
        break;
    case 5:
        if (arg1 < arg2) {
            result = 1;
        }
        break;
    default:
        OSReport(lbl_7_data_13FFC);
        break;
    }
    return result;
}
/* fzgx:end fn_7_4E28 */

/* fzgx:begin fn_7_4EF8 */
extern char lbl_7_data_13FFC[15];
extern void OSReport(char *, ...);

s32 fn_7_4EF8(u32 arg0, f32 arg1, f32 arg2) {
    s32 result;

    result = 0;
    switch ((s32)arg0) {
    case 0:
        if (arg1 == arg2) {
            result = 1;
        }
        break;
    case 1:
        if (arg1 != arg2) {
            result = 1;
        }
        break;
    case 2:
        if (arg1 >= arg2) {
            result = 1;
        }
        break;
    case 3:
        if (arg1 > arg2) {
            result = 1;
        }
        break;
    case 4:
        if (arg1 <= arg2) {
            result = 1;
        }
        break;
    case 5:
        if (arg1 < arg2) {
            result = 1;
        }
        break;
    default:
        OSReport(lbl_7_data_13FFC);
        break;
    }
    return result;
}
/* fzgx:end fn_7_4EF8 */
