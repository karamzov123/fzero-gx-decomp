#include "types.h"
#include "dolphin/hw_regs.h"
#include "psvec.h"
extern u8 lbl_8019F130[];
struct fn_80076790_Vec {
    f32 x;
    f32 y;
    f32 z;
};
struct Color_u6 { u8 r,g,b,a; };
typedef struct AvDispMatState {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 pad_6[2];
    u32 unk_8;
    u32 unk_C;
    struct Color_u6 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    u32 unk_24[4];
    u16 unk_34[3];
    u8 pad_3A[2];
    s32 unk_3C;
    s32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4C;
    struct fn_80076790_Vec unk_50;
    u8 pad_5C[4];
} AvDispMatState;
extern AvDispMatState lbl_801A3220;
extern u8 *lbl_801A6D00;
extern u8 *lbl_801A6D38;
extern s32 lbl_801A6D94;
extern const f32 lbl_801A7480;
extern const f32 lbl_801A7484;
extern const f32 lbl_801A7488;
extern const f32 lbl_801A748C;
extern const f64 lbl_801A7490;
extern const f32 lbl_801A749C;
extern void fn_8007264C();
extern void fn_80072AB0();
extern void fn_80072C24();
extern void fn_80072CC4();
extern void fn_80072D64();
extern void fn_80072E20();
extern void fn_800734A8();
extern void fn_800735C8();
extern void fn_80073620();
extern void fn_800736C0();
extern void fn_80073C6C();
extern void fn_800745A4();
extern s32 fn_80078538();
extern void *fn_800786B0();
extern void *fn_800789D8();
extern s32 fn_80078C28();
extern s32 fn_80078768();
void fn_80075908();
void fn_80075C78();
void fn_80075D48();
void fn_80076134();
void fn_800764A0();
void fn_80076790();
void fn_8007698C();
s32 fn_80076CD4();
void fn_80077240();
void fn_80077384();
void fn_80077488();
void fn_800775EC();
void fn_80077654();
void fn_80077714();
void fn_800777D4();
void fn_80077848();
u32 fn_8007785C();
u32 fn_80077A18();
u32 fn_80077AD0();
s32 fn_80077B14();
s32 fn_80077B64();
u32 fn_80077BAC();
void fn_80077BBC();
u32 fn_80077BD4();
u32 fn_80077D40();
void fn_80077E0C();
void fn_80077E7C();
void fn_80077F8C();
void fn_800780A4();
void fn_800781B8();
void fn_80078344();

/* === dol/fn_80075908.c === */
struct Sig_fn_800775EC_fn_800775EC_Arg0 {
    u8 pad_0[0xC];
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
};
struct Sig_fn_80075C78_fn_80075C78_Arg0 {
    u32 unk_0;
    u8 pad_4[0x3C];
    u32 unk_40;
};
struct fn_80075908_State { u32 a[11]; };
struct fn_80075908_Callback { u32 a[3]; struct fn_80075908_State state; };
typedef void (*fn_80075908_Fn0)(void *);
extern u32 fn_80072168(u32);
extern u32 fn_80074D88(u32, void *, void *);
extern fn_80075908_Fn0 lbl_801A6D40;
extern u32 lbl_801A6D58;
extern u32 lbl_801A6D84;
extern u32 lbl_801A6D88;
extern void fn_80073678(u32);
extern void fn_80073898(u32);
extern void fn_80074660(u32);
extern void fn_80074788(u32);
extern void fn_80075080(void *);

/* WARNING: compiler-diff device, not original code: without opt_common_subs off fn_80075908 differs by 16 instructions (lbl_801A3220 base and loc_8 load swap registers); the real AvDispMatState type does not change it */
#pragma opt_common_subs off
void fn_80075908(u32 arg0, u32 arg1) {
    s32 v0;
    s32 v1;
    u32 v2;
    struct fn_80075908_State loc_54;
    struct fn_80075908_Callback loc_1C;
    struct { u32 a[4]; u16 b[2]; } loc_8;
    s32 t7;
    loc_54.a[2] = 30;
    loc_54.a[3] = 0;
    loc_54.a[5] = 64;
    loc_54.a[6] = 0;
    loc_54.a[0] = 0;
    loc_54.a[1] = 0;
    loc_54.a[4] = 0;
    loc_54.a[7] = 1;
    loc_54.a[8] = 0;
    loc_54.a[3] = 1;
    loc_54.a[2] = 45;
    loc_54.a[5] = 76;
    loc_54.a[6] = 4;
    fn_800775EC((struct Sig_fn_800775EC_fn_800775EC_Arg0 *)arg0);
    if ((*(u32 *)arg0 & 1) == 0) {
        fn_80075080((void *)arg0);
    }
    fn_80072168(((*(u32 *)arg0 >> 2) & 1) ^ 1);
    loc_8.a[2] = 10;
    loc_8.a[3] = 5;
    loc_8.b[0] = 0;
    loc_8.b[1] = 0;
    loc_8.a[0] = 0;
    loc_8.a[1] = 0;
    if ((*(u32 *)arg0 & 1) != 0) {
        fn_80077488((void *)arg0, &loc_8);
    } else {
        fn_80077384((s32 *)arg0);
    }
    if ((s32)lbl_801A3220.unk_14 != (s32)loc_8.a[2]) {
        lbl_801A3220.unk_14 = loc_8.a[2];
        loc_8.a[0] = 1;
    }
    if ((s32)lbl_801A3220.unk_18 != (s32)loc_8.a[3]) {
        lbl_801A3220.unk_18 = loc_8.a[3];
        loc_8.a[1] = 1;
    }
    if ((*(u32 *)arg0 & 0x80) != 0 || (s32)lbl_801A6D58 != 0) {
        fn_80077240(arg0, &loc_54, &loc_8);
    } else {
        v0 = 4;
        v1 = 0;
        fn_8007264C(0, 10, 0, v0, v1);
        t7 = fn_80076CD4((void *)arg0, &loc_54, arg1, &loc_8);
        if (t7 == 0) {
            fn_80077240(arg0, &loc_54, &loc_8);
        }
    }
    if ((*(u32 *)arg0 & 0x200) != 0) {
        fn_80074D88(arg0, &loc_54, &loc_8);
    }
    if (lbl_801A6D40 != 0) {
        loc_1C.a[0] = lbl_801A3220.unk_0;
        loc_1C.a[1] = arg0;
        loc_1C.a[2] = arg1;
        loc_1C.state = loc_54;
        lbl_801A6D40(&loc_1C);
        loc_54 = loc_1C.state;
    }
    if ((s32)lbl_801A6D88 != 0) {
        if ((s32)lbl_801A3220.unk_8 != (s32)loc_54.a[0]) {
            lbl_801A3220.unk_8 = loc_54.a[0];
            fn_80077654(loc_54.a[0]);
        }
        v2 = loc_54.a[0] + 1;
        loc_54.a[0] = v2;
    }
    if ((s32)lbl_801A6D84 != 0) {
        if ((s32)lbl_801A3220.unk_C != (s32)loc_54.a[0]) {
            lbl_801A3220.unk_8 = loc_54.a[0];
            fn_80077714(loc_54.a[0]);
        }
        loc_54.a[0]++;
    }
    fn_80074788(1);
    fn_80073678(loc_54.a[0] & 0xFF);
    fn_80074660(loc_54.a[1] & 0xFF);
    fn_80073898(loc_54.a[4] & 0xFF);
    fn_80075C78((struct Sig_fn_80075C78_fn_80075C78_Arg0 *)arg0);
    lbl_801A3220.unk_0 = 0;
    if ((*(u32 *)arg0 & 0x80) != 0) {
        lbl_801A3220.unk_1 = 0;
    } else {
        lbl_801A3220.unk_1 = *(u8 *)(arg0 + 0x12);
    }
}
#pragma opt_common_subs reset


/* === dol/fn_80075C78.c === */


/* --- dol/fn_80075C78.c --- */
struct fn_80075C78_Arg0 {
    u32 unk_0;
    u8 pad_4[0x3C];
    u32 unk_40;
};


extern u32 lbl_801A6D5C;
extern u32 lbl_801A6D60;
extern void fn_800728A8(s32, s32, s32, s32);

void fn_80075C78(struct fn_80075C78_Arg0 *arg0) {
    AvDispMatState *p_lbl_801A3220;
    s32 v0;
    u32 v1;
    s32 v2;
    u32 unk_1;
    u32 unk_2;
    u32 v5;

    v0 = 4;
    v2 = 5;
    if ((s32)lbl_801A6D60 == -1) {
        v1 = arg0->unk_0;
        if ((v1 & 0x20) != 0) {
            v1 = arg0->unk_40;
            v0 = (v1 & 0xF);
        }
    } else {
        v0 = lbl_801A6D60;
    }
    if ((s32)lbl_801A6D5C == -1) {
        unk_1 = arg0->unk_0;
        if ((unk_1 & 0x40) != 0) {
            unk_2 = arg0->unk_40;
            v2 = ((unk_2 >> 4) & 0xF);
        }
    } else {
        v2 = lbl_801A6D5C;
    }
    p_lbl_801A3220 = &lbl_801A3220;
    if ((s32)p_lbl_801A3220->unk_1C != v0 ||
        (s32)p_lbl_801A3220->unk_20 != v2) {
        v5 = 1;
        fn_800728A8(v5, v0, v2, 0);
        p_lbl_801A3220->unk_1C = v0;
        v5 = (u32)&lbl_801A3220;
        *(u32 *)((u8 *)v5 + 32) = v2;
    }
}

/* --- dol/fn_80075D48.c --- */
struct fn_80075D48_Arg0 {
    u32 unk_0;
};


void fn_80075D48(void *arg0, void *arg1) {
    s16 temp_r0;
    s16 temp_r0_2;

    fn_80073C6C(*(s32 *)((u8 *)(arg0)));
    fn_80072AB0(*(s32 *)((u8 *)(arg0)), 0, 0);
    fn_800734A8(*(s32 *)((u8 *)(arg0)), *(s32 *)((u8 *)(arg0) + 4), *(s32 *)((u8 *)(arg0) + 12), 4);
    temp_r0 = *(s16 *)((u8 *)(arg1) + 16);
    switch (temp_r0) {                              /* switch 1; irregular */
    case 1:                                         /* switch 1 */
        fn_80072C24(*(s32 *)((u8 *)(arg0)), 0xF, 8, 0xC, *(s32 *)((u8 *)(arg1) + 8));
        fn_80072D64(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1, 0);
        break;
    case 2:                                         /* switch 1 */
        fn_80072C24(*(s32 *)((u8 *)(arg0)), 0xF, 8, 0xC, *(s32 *)((u8 *)(arg1) + 8));
        fn_80072D64(*(s32 *)((u8 *)(arg0)), 1, 0, 0, 1, 0);
        break;
    case 0:                                         /* switch 1 */
        fn_80072C24(*(s32 *)((u8 *)(arg0)), 0xF, 8, *(s32 *)((u8 *)(arg1) + 8), 0xF);
        fn_80072D64(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1, 0);
        break;
    case 4:                                         /* switch 1 */
        fn_80072C24(*(s32 *)((u8 *)(arg0)), 0xF, 8, 0xA, 0xF);
        fn_80072D64(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1, 3);
        fn_80072CC4(*(s32 *)((u8 *)(arg0)), 7, 7, 7, *(s32 *)((u8 *)(arg1) + 12));
        fn_80072E20(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1U, 0);
        (*(s32 *)((u8 *)(arg0))) = ((*(s32 *)((u8 *)(arg0))) + 1);
        fn_80073C6C(*(s32 *)((u8 *)(arg0)));
        fn_80072AB0(*(s32 *)((u8 *)(arg0)), 0, 0);
        fn_800734A8(*(s32 *)((u8 *)(arg0)), *(s32 *)((u8 *)(arg0) + 4), *(s32 *)((u8 *)(arg0) + 12), 0xFF);
        fn_80072C24(*(s32 *)((u8 *)(arg0)), *(s32 *)((u8 *)(arg1) + 8), 6, 9, 0xF);
        fn_80072D64(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1, 0);
        break;
    case 3:                                         /* switch 1 */
        fn_80072C24(*(s32 *)((u8 *)(arg0)), 0xF, 0xF, 0xF, *(s32 *)((u8 *)(arg1) + 8));
        fn_80072D64(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1, 0);
        break;
    }
    temp_r0_2 = *(s16 *)((u8 *)(arg1) + 18);
    switch (temp_r0_2) {                            /* switch 2; irregular */
    case 1:                                         /* switch 2 */
        fn_80072CC4(*(s32 *)((u8 *)(arg0)), 4, 7, 7, *(s32 *)((u8 *)(arg1) + 12));
        fn_80072E20(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1U, 0);
        break;
    case 2:                                         /* switch 2 */
        fn_80072CC4(*(s32 *)((u8 *)(arg0)), 4, 7, 7, *(s32 *)((u8 *)(arg1) + 12));
        fn_80072E20(*(s32 *)((u8 *)(arg0)), 1, 0, 0, 1U, 0);
        break;
    case 0:                                         /* switch 2 */
        fn_80072CC4(*(s32 *)((u8 *)(arg0)), 7, 4, *(s32 *)((u8 *)(arg1) + 12), 7);
        fn_80072E20(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1U, 0);
        break;
    case 4:                                         /* switch 2 */
        fn_80072CC4(*(s32 *)((u8 *)(arg0)), 7, 7, 7, 4);
        fn_80072E20(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1U, 0);
        break;
    case 5:                                         /* switch 2 */
        fn_80073620(*(s32 *)((u8 *)(arg0)), 0);
        fn_80072CC4(*(s32 *)((u8 *)(arg0)), 7, 7, 7, 6);
        fn_80072E20(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1U, 0);
        break;
    case 3:                                         /* switch 2 */
        fn_80072CC4(*(s32 *)((u8 *)(arg0)), 7, 7, 7, *(s32 *)((u8 *)(arg1) + 12));
        fn_80072E20(*(s32 *)((u8 *)(arg0)), 0, 0, 0, 1U, 0);
        break;
    }
    (*(s32 *)((u8 *)(arg0))) = ((*(s32 *)((u8 *)(arg0))) + 1);
    (*(s32 *)((u8 *)(arg0) + 4)) = ((*(s32 *)((u8 *)(arg0) + 4)) + 1);
}

/* === dol/fn_80076134.c === */

struct fn_80076134_Mtx {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
};

extern u8 lbl_8015AD10[];

extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void lbl_8006E14C(f32);
extern void GXLoadTexMtxImm(void *, u32, u32);
extern void fn_8006F120(void *, void *);

void fn_80076134(void) {
    lbl_8006DAEC();
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_C = lbl_801A7480;
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_1C = lbl_801A7480;
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_2C = lbl_801A7480;
    GXLoadTexMtxImm(((struct fn_80076134_Mtx *)lbl_801A6D00), 30, 0);
    lbl_8006DB30();
    lbl_801A3220.unk_3C = 1;
    lbl_8006DAEC();
    fn_8006F120(lbl_8015AD10, &lbl_801A3220.unk_50);
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_C = lbl_801A748C;
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_10 = ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_10 * lbl_801A749C;
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_14 = ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_14 * lbl_801A749C;
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_18 = ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_18 * lbl_801A749C;
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_1C = lbl_801A748C;
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_20 = lbl_801A7480;
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_24 = lbl_801A7480;
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_28 = lbl_801A7480;
    ((struct fn_80076134_Mtx *)lbl_801A6D00)->unk_2C = lbl_801A7488;
    lbl_8006E14C(lbl_801A748C);
    GXLoadTexMtxImm(((struct fn_80076134_Mtx *)lbl_801A6D00), 64, 0);
    lbl_8006DB30();
}

/* === dol/fn_80076238.c === */

struct fn_80076238_arg1 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
};

struct fn_80076238_arg2 {
    u8 unk0[8];
    s32 unk8;
    s32 unkC;
};

struct fn_80076238_Mtx {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
};

extern u8 lbl_8015AD1C[];



void fn_80076238(struct fn_80076238_arg1 *p0, struct fn_80076238_arg2 *p1, u32 arg2, s32 arg3) {
    u8 buf[4];
    u32 v;

    fn_80073C6C(p0->unk0);
    fn_80072AB0(p0->unk0, 0, 0);

    if (lbl_801A3220.unk_3C == 0) {
        lbl_8006DAEC();
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_C = lbl_801A7480;
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_1C = lbl_801A7480;
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_2C = lbl_801A7480;
        GXLoadTexMtxImm(((struct fn_80076238_Mtx *)lbl_801A6D00), 30, 0);
        lbl_8006DB30();
        lbl_801A3220.unk_3C = 1;
    }

    if (lbl_801A3220.unk_40 == 0) {
        lbl_8006DAEC();
        fn_8006F120(lbl_8015AD1C, &lbl_801A3220.unk_50);
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_C = lbl_801A748C;
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_10 = ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_10 * lbl_801A749C;
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_14 = ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_14 * lbl_801A749C;
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_18 = ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_18 * lbl_801A749C;
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_1C = lbl_801A748C;
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_20 = lbl_801A7480;
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_24 = lbl_801A7480;
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_28 = lbl_801A7480;
        ((struct fn_80076238_Mtx *)lbl_801A6D00)->unk_2C = lbl_801A7488;
        lbl_8006E14C(lbl_801A748C);
        GXLoadTexMtxImm(((struct fn_80076238_Mtx *)lbl_801A6D00), 64, 0);
        lbl_8006DB30();
        lbl_801A3220.unk_40 = 1;
    }

    buf[0] = arg2;
    buf[1] = arg2;
    buf[2] = arg2;
    buf[3] = arg2;

    fn_800734A8(p0->unk0, p0->unk4, p0->unkC, 4);

    v = *(u32 *)buf;
    fn_800736C0(0, &v);

    fn_800735C8(p0->unk0, 0xC);
    fn_800745A4(p0->unk4, 0, 1, 0x1E, 1, 0x40);

    if (arg3) {
        fn_80072C24(p0->unk0, 0xF, 8, p1->unk8, 0xF);
    } else {
        fn_80072C24(p0->unk0, 0xF, 8, 0xE, p1->unk8);
    }

    fn_80072D64(p0->unk0, 0, 0, 0, 1, 0);
    fn_80072CC4(p0->unk0, 7, 7, 7, p1->unkC);
    fn_80072E20(p0->unk0, 0, 0, 0, 1, 0);

    p0->unk0 = p0->unk0 + 1;
    p0->unk4 = p0->unk4 + 1;
}

/* === dol/fn_800764A0.c === */
struct fn_800764A0_Arg0 { u32 unk_0; };
struct fn_800764A0_lbl_801A6D00_T {
 u8 pad_0[0xC]; f32 unk_C; f32 unk_10; f32 unk_14; f32 unk_18;
 f32 unk_1C; f32 unk_20; f32 unk_24; f32 unk_28; f32 unk_2C;
};
extern u32 lbl_8015AD28[];
void fn_800764A0(struct fn_800764A0_Arg0 *arg0, void *arg1, u32 arg2) {
 AvDispMatState *p_lbl_801A3220;
 u8 buf[4];
 u32 v;
 fn_80073C6C(arg0->unk_0);
 fn_80072AB0(arg0->unk_0,0,0);
 p_lbl_801A3220 = &lbl_801A3220;
 if (p_lbl_801A3220->unk_3C == 0) {
 lbl_8006DAEC();
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_C = 0.0f;
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_1C = 0.0f;
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_2C = 0.0f;
 GXLoadTexMtxImm(((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00),30,0);
 lbl_8006DB30();
 p_lbl_801A3220->unk_3C = 1;
 }
 p_lbl_801A3220 = &lbl_801A3220;
 if (p_lbl_801A3220->unk_40 == 0) {
 lbl_8006DAEC();
 fn_8006F120(lbl_8015AD28,&lbl_801A3220.unk_50);
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_C = 0.5f;
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_10 *= -1.0f;
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_14 *= -1.0f;
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_18 *= -1.0f;
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_1C = 0.5f;
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_20 = 0.0f;
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_24 = 0.0f;
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_28 = 0.0f;
 ((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00)->unk_2C = 1.0f;
 lbl_8006E14C(0.5f);
 GXLoadTexMtxImm(((struct fn_800764A0_lbl_801A6D00_T *)lbl_801A6D00),64,0);
 lbl_8006DB30();
 p_lbl_801A3220->unk_40 = 1;
 }
 buf[0] = arg2;
 buf[1] = arg2;
 buf[2] = arg2;
 buf[3] = arg2;
 fn_800734A8(arg0->unk_0,*(u32 *)((u8 *)arg0+4),*(u32 *)((u8 *)arg0+12),4);
 v = *(u32 *)buf;
 fn_800736C0(0,&v);
 fn_800735C8(*(u32 *)(arg0),12);
 fn_800745A4(*(u32 *)((u8 *)arg0+4),0,1,30,1,64);
 fn_80072C24(*(u32 *)(arg0),15,8,14,15);
 fn_80072D64(*(u32 *)(arg0),0,0,0,1,2);
 fn_80072CC4(*(u32 *)(arg0),7,7,7,*(u32 *)((u8 *)arg1+12));
 fn_80072E20(*(u32 *)(arg0),0,0,0,1,2);
 (*(u32 *)(arg0))++;
 (*(u32 *)((u8 *)arg0+4))++;
 fn_80073C6C(*(u32 *)(arg0));
 fn_80072AB0(*(u32 *)(arg0),0,0);
 fn_800734A8(*(u32 *)(arg0),255,255,255);
 fn_80072C24(*(u32 *)(arg0),15,4,10,*(u32 *)((u8 *)arg1+8));
 fn_80072D64(*(u32 *)(arg0),0,0,0,1,0);
 fn_80072CC4(*(u32 *)(arg0),7,7,7,2);
 fn_80072E20(*(u32 *)(arg0),0,0,0,1,0);
 { u32 v3; v3=*(u32 *)(arg0); *(u32 *)(arg0)=v3+1; }
}

/* === dol/fn_80076790.c === */

struct fn_80076790_Mtx {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
};

extern u32 lbl_80094E20[];
extern u32 lbl_8019F14C[];
extern f32 lbl_801A74A0;

extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DFC4(void *);

/* WARNING: compiler-diff device, not original code: without opt_common_subs off fn_80076790 differs by 12 instructions (FPR numbering of the scaled vector loc_14) */
#pragma opt_common_subs off
void fn_80076790(void) {
    f32 loc_38[3][4];
    u32 loc_2C[3];
    struct fn_80076790_Vec loc_20;
    struct fn_80076790_Vec loc_14;
    struct fn_80076790_Vec loc_8;
    f32 scale;

    loc_2C[0] = lbl_80094E20[0];
    loc_2C[1] = lbl_80094E20[1];
    loc_2C[2] = lbl_80094E20[2];
    lbl_8006DAEC();
    scale = lbl_801A74A0;
    loc_20 = *(struct fn_80076790_Vec *)lbl_8019F14C;
    loc_14 = lbl_801A3220.unk_50;
    loc_14.x = loc_14.x * scale;
    loc_14.y = loc_14.y * scale;
    loc_14.z = loc_14.z * scale;
    loc_20.x = lbl_801A748C * (loc_14.x + loc_20.x);
    loc_20.y = lbl_801A748C * (loc_14.y + loc_20.y);
    loc_20.z = lbl_801A748C * (loc_14.z + loc_20.z);
    loc_8.x = loc_20.x - loc_14.x;
    loc_8.y = loc_20.y - loc_14.y;
    loc_8.z = loc_20.z - loc_14.z;
    fn_8006F1F0(loc_2C, &loc_8, &loc_20);
    lbl_8006DB74(&loc_38);
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_C = lbl_801A748C;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_10 = ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_10 * lbl_801A749C;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_14 = ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_14 * lbl_801A749C;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_18 = ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_18 * lbl_801A749C;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_1C = lbl_801A748C;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_20 = lbl_801A7480;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_24 = lbl_801A7480;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_28 = lbl_801A7480;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_2C = lbl_801A7488;
    lbl_8006E14C(lbl_801A748C);
    GXLoadTexMtxImm(((struct fn_80076790_Mtx *)lbl_801A6D00), 67, 0);
    lbl_8006D758();
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_0 = lbl_801A7480;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_8 = lbl_801A748C;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_C = lbl_801A748C;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_14 = lbl_801A7480;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_28 = lbl_801A7480;
    ((struct fn_80076790_Mtx *)lbl_801A6D00)->unk_2C = lbl_801A7488;
    lbl_8006DFC4(&loc_38);
    GXLoadTexMtxImm(((struct fn_80076790_Mtx *)lbl_801A6D00), 70, 0);
    lbl_8006DB30();
    lbl_801A3220.unk_44 = 1;
}
#pragma opt_common_subs reset


/* === dol/fn_8007698C.c === */
struct fn_8007698C_lbl_801A6D00_T {
    u8 pad_0[0xC]; f32 unk_C;
    u8 pad_10[0xC]; f32 unk_1C;
    u8 pad_20[0xC]; f32 unk_2C;
};
extern f32 lbl_801A6D68, lbl_801A6D6C, lbl_801A6D70;
extern u8 lbl_8019F200[16416];
extern void fn_80073778(void *, s32);
void fn_8007698C(void *arg0, void *arg1) {
    AvDispMatState *p_lbl_801A3220;
    s32 v9;
    u32 v10;
    struct Color_u6 color;
    struct Color_u6 loc;
    p_lbl_801A3220 = &lbl_801A3220;
    if ((s32)p_lbl_801A3220->unk_4C == 0) {
        color = p_lbl_801A3220->unk_10;
        if (color.r == 0 && color.g == 0 && color.b == 0) {
            color.r = 255;
            color.g = 255;
            color.b = 255;
        }
        color.r *= lbl_801A6D70;
        color.g *= lbl_801A6D6C;
        color.b *= lbl_801A6D68;
        loc = color;
        fn_800736C0(1, &loc);
        p_lbl_801A3220->unk_4C = 1;
    }
    p_lbl_801A3220 = &lbl_801A3220;
    if (p_lbl_801A3220->unk_3C == 0) {
        lbl_8006DAEC();
        ((struct fn_8007698C_lbl_801A6D00_T *)lbl_801A6D00)->unk_C = lbl_801A7480;
        ((struct fn_8007698C_lbl_801A6D00_T *)lbl_801A6D00)->unk_1C = lbl_801A7480;
        ((struct fn_8007698C_lbl_801A6D00_T *)lbl_801A6D00)->unk_2C = lbl_801A7480;
        GXLoadTexMtxImm(((struct fn_8007698C_lbl_801A6D00_T *)lbl_801A6D00), 30, 0);
        lbl_8006DB30();
        p_lbl_801A3220->unk_3C = 1;
    }
    if ((s32)lbl_801A3220.unk_44 == 0) {
        fn_80073778(lbl_8019F200, 0);
        fn_80076790();
    }
    v9 = *(u32 *)((u8 *)arg0);
    fn_80073C6C(v9);
    fn_80072AB0(v9, 0, 0);
    fn_800735C8(v9, 13);
    fn_800745A4(*(u32 *)((u8 *)arg0 + 4), 0, 1, 30, 1, 70);
    fn_800734A8(v9, *(u32 *)((u8 *)arg0 + 4), 0, 4);
    fn_80072C24(v9, 15, 8, 14, 15);
    fn_80072D64(v9, 0, 0, 0, 1, 3);
    fn_80072CC4(v9, 7, 7, 7, *(u32 *)((u8 *)arg1 + 12));
    fn_80072E20(v9, 0, 0, 0, 1, 3);
    fn_80073C6C(v9 + 1);
    fn_80072AB0(v9 + 1, 0, 0);
    fn_800735C8(v9 + 1, 13);
    fn_800745A4(*(u32 *)((u8 *)arg0 + 4) + 1, 0, 1, 30, 1, 67);
    fn_800734A8(v9 + 1, *(u32 *)((u8 *)arg0 + 4) + 1, *(u32 *)((u8 *)arg0 + 12), 4);
    fn_80072C24(v9 + 1, 15, 8, 6, *(u32 *)((u8 *)arg1 + 8));
    fn_80072D64(v9 + 1, 0, 0, 0, 1, 0);
    fn_80072CC4(v9 + 1, 7, 7, 7, *(u32 *)((u8 *)arg1 + 12));
    fn_80072E20(v9 + 1, 0, 0, 0, 1, 0);
    *(u32 *)((u8 *)arg0 + 0) += 2;
    v10 = *(u32 *)((u8 *)arg0 + 4);
    *(u32 *)((u8 *)arg0 + 4) = v10 + 2;
}

/* === dol/fn_80076CD4.c === */
struct fn_80076CD4_Arg0 {
    u8 pad_0[0x12];
    u8 unk_12;
};
extern u32 lbl_801A6D44;
extern void fn_800729B0(s32, s32, s32, s32, s32);


s32 fn_80076CD4(void *arg0, void *arg1, s32 arg2, void *arg3, s32 arg_sp0) {
    s32 var_r5;
    void *temp_r3;
    u32 temp_r30;
    s32 temp_r3_2;
    s32 var_r29;
    u32 *var_r28;
    void *temp_r27;
    u16 *var_r26;
    s32 temp_r25;
    s32 temp_r25_2;
    s32 temp_r25_3;
    u32 *var_r24;
    s32 var_r23;
    s32 var_r22;
    s32 temp_r0;

    var_r23 = *((u8 *)(arg0) + 18);
    var_r26 = (u16 *)((u8 *)(arg0) + 0x16);
    var_r28 = lbl_801A3220.unk_24;
    var_r24 = (u32 *)lbl_801A3220.unk_34;
    var_r22 = 0;
    var_r29 = 4;
    while (var_r23 > 0) {
        temp_r27 = (void *)(arg2 + ((*var_r26) << 5));
        temp_r25 = *(s32 *)((u8 *)(temp_r27));
        temp_r30 = temp_r25 & 0x50A003;
        (*var_r28) = temp_r30;
        if (((*(u16 *)(var_r24)) != (*var_r26)) || ((*(s32 *)((u8 *)(temp_r27))) & 0x10000)) {
            temp_r3 = (*(void **)((u8 *)(temp_r27) + 8));
            if (temp_r3 != NULL) {
                fn_80073778(temp_r3, (*(s32 *)((u8 *)(arg1) + 12)));
                (*(u16 *)(var_r24)) = (*var_r26);
                goto block_5; /* Preserves the retail branch. */
            }
        } else {
block_5:
            (*(s16 *)((u8 *)(arg3) + 16)) = ((*(u32 *)((u8 *)(temp_r27) + 16)) & 0xF);
            (*(s16 *)((u8 *)(arg3) + 18)) = (((*(u32 *)((u8 *)(temp_r27) + 16)) >> 4U) & 0xF);
            if (temp_r30 == 0) {
                if ((*(s32 *)((u8 *)(temp_r27))) & 0x20000) {
                    temp_r0 = ((*(u32 *)((u8 *)(temp_r27) + 16)) >> 8U) & 3;
                    if (temp_r0 != 0) {
                        fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, ((temp_r0 * 3) + 0x30), (0U), (0x7DU));
                    } else {
                        fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, (0x24U), (0U), (0x7DU));
                    }
                } else {
                    fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, (0x3CU), (0U), (0x7DU));
                }
                fn_80075D48(arg1, arg3);
            } else if (temp_r25 & 0x2000) {
                temp_r25_2 = *(s32 *)((u8 *)(temp_r27));
                fn_80073C6C((*(void **)((u8 *)(arg1))));
                temp_r3_2 = temp_r25_2 & 0xC0000;
                switch (temp_r3_2) {                /* irregular */
                case 0x40000:
                    fn_800729B0((2), (0), (1), (2), (1));
                    fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (2));
                    break;
                case 0x80000:
                    fn_800729B0((2), (0), (1), (2), (2));
                    fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (2));
                    break;
                case 0xC0000:
                    fn_800729B0((2), (0), (1), (2), (3));
                    fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (2));
                    break;
                default:
                    fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (1));
                    break;
                }
                if (temp_r25_2 & 0x20000) {
                    fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, (0x24U), (0U), (0x7DU));
                } else {
                    fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, (0x3CU), (0U), (0x7DU));
                }
                fn_800734A8((*(void **)((u8 *)(arg1))), (*(u32 *)((u8 *)(arg1) + 4)), ((*(s32 *)((u8 *)(arg1) + 12))), (4U));
                fn_80072C24((*(void **)((u8 *)(arg1))), (0xF), (0xF), (0xF), (*(s32 *)((u8 *)(arg3) + 8)));
                fn_80072D64((*(void **)((u8 *)(arg1))), (0U), (0U), (0U), (1U), (0U));
                fn_80072CC4((*(void **)((u8 *)(arg1))), (7U), (4U), (*(u32 *)((u8 *)(arg3) + 12)), (7U));
                fn_80072E20((*(void **)((u8 *)(arg1))), (0), (0), (0), (1U), (0));
                (*(void **)((u8 *)(arg1))) = (((u8 *)((*(void **)((u8 *)(arg1)))) + 1));
                (*(u32 *)((u8 *)(arg1) + 4)) = ((*(u32 *)((u8 *)(arg1) + 4)) + 1);
            } else if (temp_r25 & 2) {
                temp_r25_3 = (*(u32 *)((u8 *)(arg1) + 4)) + 0xC;
                fn_8007264C((0U), (0x19U), (1U), (4U), (0U));
                fn_80073C6C((*(void **)((u8 *)(arg1))));
                fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (1), var_r29, (0x3CU), (0U), (0x7DU));
                fn_800734A8((*(void **)((u8 *)(arg1))), (*(u32 *)((u8 *)(arg1) + 4)), ((*(s32 *)((u8 *)(arg1) + 12))), (4U));
                fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (0));
                fn_80072C24((*(void **)((u8 *)(arg1))), (8), (0xF), (0xF), (*(s32 *)((u8 *)(arg3) + 8)));
                fn_80072D64((*(void **)((u8 *)(arg1))), (0U), (0U), (0U), (0U), (0U));
                fn_80072CC4((*(void **)((u8 *)(arg1))), (7U), (7U), (7U), (*(u32 *)((u8 *)(arg3) + 12)));
                fn_80072E20((*(void **)((u8 *)(arg1))), (0), (0), (0), (1U), (0));
                (*(void **)((u8 *)(arg1))) = (((u8 *)((*(void **)((u8 *)(arg1)))) + 1));
                (*(u32 *)((u8 *)(arg1) + 4)) = ((*(u32 *)((u8 *)(arg1) + 4)) + 1);
                fn_80073C6C((*(void **)((u8 *)(arg1))));
                fn_800745A4((*(u32 *)((u8 *)(arg1) + 4)), (2), temp_r25_3, (0x3CU), (0U), (0x7DU));
                fn_800734A8((*(void **)((u8 *)(arg1))), (*(u32 *)((u8 *)(arg1) + 4)), ((*(s32 *)((u8 *)(arg1) + 12))), (0xFFU));
                fn_80072AB0((s32)(((*(void **)((u8 *)(arg1))))), (0), (0));
                fn_80072C24((*(void **)((u8 *)(arg1))), (8), (0xF), (0xF), (0));
                fn_80072D64((*(void **)((u8 *)(arg1))), (1U), (0U), (0U), (1U), (0U));
                fn_80072CC4((*(void **)((u8 *)(arg1))), (7U), (7U), (7U), (0U));
                fn_80072E20((*(void **)((u8 *)(arg1))), (0), (0), (0), (1U), (0));
                (*(void **)((u8 *)(arg1))) = (((u8 *)((*(void **)((u8 *)(arg1)))) + 1));
                (*(u32 *)((u8 *)(arg1) + 4)) = ((*(u32 *)((u8 *)(arg1) + 4)) + 1);
            } else if (temp_r25 & 1) {
                if (temp_r25 & 0x100000) {
                    var_r5 = *((u8 *)(temp_r27) + 12);
                } else {
                    var_r5 = 0x80;
                }
                if ((s32) (lbl_801A6D44) != 0) {
                    fn_800764A0(arg1, arg3, var_r5);
                } else {
                    fn_80076238(arg1, arg3, var_r5, (temp_r25 & 0x400000));
                }
            } else {
                fn_8007698C(arg1, arg3);
            }
            var_r26 = (u16 *)((u8 *)(var_r26) + 2);
            (*(s32 *)((u8 *)(arg3) + 8)) = 0;
            var_r28 = (u32 *)((u8 *)(var_r28) + 4);
            var_r24 = (u32 *)((u8 *)(var_r24) + 2);
            var_r22 += 1;
            (*(u32 *)((u8 *)(arg3) + 12)) = 0U;
            var_r29 += 1;
            (*(s32 *)((u8 *)(arg1) + 12)) = ((*(s32 *)((u8 *)(arg1) + 12)) + 1);
        }
        var_r23 -= 1;
            }
    (*var_r28) = -1U;
    return var_r22;
}

/* === dol/fn_80077240.c === */



void fn_80077240(u32 arg0, u32 arg1, u32 arg2) {
    u32 v0;
    if ((s8)lbl_801A3220.unk_1 != 0 || (s32)*(u32 *)(arg2) != 0 || (s32)*(u32 *)(arg2 + 4) != 0) {
    fn_800734A8(*(u32 *)(arg1), 255, 255, 4);
    fn_80072C24(*(u32 *)(arg1), 15, 15, 15, *(u32 *)(arg2 + 8));
    fn_80072D64(*(u32 *)(arg1), 0, 0, 0, 1, 0);
    fn_80072CC4(*(u32 *)(arg1), 7, 7, 7, *(u32 *)(arg2 + 12));
    fn_80072E20(*(u32 *)(arg1), 0, 0, 0, 1, 0);
    } else {
    if ((s32)*(u32 *)(arg2) != 0) {
    if ((s32)*(u32 *)(arg2) != 0) {
    fn_80072C24(*(u32 *)(arg1), 15, 15, 15, *(u32 *)(arg2 + 8));
    }
    if ((s32)*(u32 *)(arg2 + 4) != 0) {
    fn_80072CC4(*(u32 *)(arg1), 7, 7, 7, *(u32 *)(arg2 + 12));
    }
    }
    }
    lbl_801A3220.unk_24[0] = -1;
    v0 = *(u32 *)(arg1);
    *(u32 *)((u8 *)arg1 + 0) = (v0 + 1);
}

/* === dol/fn_80077384.c === */
struct fn_80077384_Arg0 {
    u32 unk_0;
};
extern u32 lbl_801A6D64;
extern u32 lbl_801A6D74;
extern void fn_800747D0(u32, u32, u32, u32, u32, u32, u32);

void fn_80077384(s32 *arg0) {
    u32 var_r6;

    if ((*arg0) & 0x100) {
        if (lbl_801A3220.unk_2 != 4) {
            lbl_801A3220.unk_2 = 4;
            if (lbl_801A7488 == (*(f32 *)((u8 *)(((u32 *)lbl_8019F130)) + 12))) {
                var_r6 = 1;
            } else {
                var_r6 = 0;
            }
            fn_800747D0(2U, 0U, 0U, var_r6, 0U, 0U, 2U);
            fn_800747D0(0U, 1U, 0U, 1U, lbl_801A6D74, 2U, lbl_801A6D64);
        }
    } else if (lbl_801A3220.unk_2 != 3) {
        lbl_801A3220.unk_2 = 3;
        fn_800747D0(2U, 0U, 0U, 0U, 0U, 0U, 2U);
        fn_800747D0(0U, 1U, 0U, 0U, lbl_801A6D74, 2U, lbl_801A6D64);
    }
}

/* === dol/fn_80077488.c === */
struct fn_80077488_Arg0 {
    u32 unk_0;
};
extern u32 fn_800371F8(u32, void *);

struct FzgxCopy_4 { u32 words[1]; };
void fn_80077488(void *arg0, void *arg1) {
    struct FzgxCopy_4 loc_C;
    u32 sp8;
    s32 temp_r5;

    temp_r5 = *(s32 *)((u8 *)(arg0));
    if (temp_r5 & 0x100) {
        if (lbl_801A3220.unk_2 != 2) {
            lbl_801A3220.unk_2 = 2;
            if (lbl_801A7488 == (*(f32 *)((u8 *)(((u32 *)lbl_8019F130)) + 12))) {
                fn_800747D0((4U), (0U), (1U), (1U), (0U), (0U), (2U));
                return;
            }
            fn_800747D0((2U), (0U), (0U), (0U), (0U), (0U), (2U));
            fn_800747D0((0U), (0U), (1U), (1U), (0U), (0U), (2U));
        }
    } else {
        lbl_801A3220.unk_2 = 1;
        if (!(temp_r5 & 0x88)) {
            (*(u8 *)(&loc_C)) = 0xFF;
            (*((u8 *)(&loc_C) + 1)) = 0xFF;
            (*((u8 *)(&loc_C) + 2)) = 0xFF;
        } else {
            loc_C.words[0] = *(u32 *)((u8 *)(arg0) + 4);
        }
        (*((u8 *)(&loc_C) + 3)) = ((*((u8 *)(arg0) + 17)) * (*(f32 *)((u8 *)(((u32 *)lbl_8019F130)) + 12)));
        sp8 = loc_C.words[0];
        fn_800371F8((1U), &sp8);
        (*(s32 *)((u8 *)(arg1) + 8)) = 2;
        (*(s32 *)((u8 *)(arg1) + 12)) = 1;
    }
}

/* === dol/fn_800775EC.c === */


/* --- dol/fn_800775EC.c --- */
struct fn_800775EC_Arg0 {
    u8 pad_0[0xC];
    u8 unk_C;
    u8 unk_D;
    u8 unk_E;
};


void fn_800775EC(struct fn_800775EC_Arg0 *arg0) {
    u8 v0;
    v0 = lbl_801A3220.unk_10.g;
    if (lbl_801A3220.unk_10.r == arg0->unk_C && lbl_801A3220.unk_10.g == arg0->unk_D) {
    v0 = lbl_801A3220.unk_10.b;
    if (v0 == arg0->unk_E) { return; }
    }
    lbl_801A3220.unk_48 = 0;
    lbl_801A3220.unk_4C = 0;
    lbl_801A3220.unk_10.r = arg0->unk_C;
    lbl_801A3220.unk_10.g = arg0->unk_D;
    lbl_801A3220.unk_10.b = arg0->unk_E;
}

/* --- dol/fn_80077654.c --- */

void fn_80077654(u32 arg0) {
    fn_800735C8(arg0, 14);
    fn_80073620(arg0, 30);
    fn_80073C6C(arg0);
    fn_800734A8(arg0, 255, 255, 255);
    fn_80072C24(arg0, 15, 0, 14, 15);
    fn_80072D64(arg0, 0, 0, 0, 1, 0);
    fn_80072CC4(arg0, 7, 0, 6, 7);
    fn_80072E20(arg0, 0, 0, 0, 1, 0);
}

/* --- dol/fn_80077714.c --- */
void fn_80077714(u32 arg0) {
    fn_800735C8(arg0, 15);
    fn_80073620(arg0, 31);
    fn_80073C6C(arg0);
    fn_800734A8(arg0, 255, 255, 255);
    fn_80072C24(arg0, 0, 15, 15, 14);
    fn_80072D64(arg0, 0, 0, 0, 1, 0);
    fn_80072CC4(arg0, 0, 7, 7, 6);
    fn_80072E20(arg0, 0, 0, 0, 1, 0);
}

/* --- dol/fn_800777D4.c --- */
extern f32 lbl_801A74A8;
extern f32 lbl_801A74AC;
extern u32 fn_80070D94(void);
extern u32 fn_80070E00(void);
extern u32 fn_80072778(void);
extern u32 fn_80074A8C(f32, f32, f32, f32);
extern u32 fn_80074BC4(f32, f32, f32, f32);
extern u32 fn_80075240(void);
extern u32 lbl_801A6D90;
extern u32 lbl_801A6D98;

struct fn_800777D4_lbl_8019F130 {
    u8 pad_0[0xC];
    f32 unk_C;
};

void fn_800777D4(void) {
    fn_80072778();
    (*(struct fn_800777D4_lbl_8019F130 *)lbl_8019F130).unk_C = lbl_801A74A8;
    fn_80074A8C(lbl_801A74A8, lbl_801A74A8, lbl_801A74A8, lbl_801A74A8);
    fn_80074BC4(lbl_801A74AC, lbl_801A74AC, lbl_801A74AC, lbl_801A74AC);
    lbl_801A6D90 = 0;
    lbl_801A6D98 = 0;
    lbl_801A6D94 = 0;
    fn_80075240();
    fn_80077848();
    fn_80070E00();
    fn_80070D94();
}

/* === dol/fn_80077848.c === */

/* --- dol/fn_80077848.c --- */
extern u32 lbl_801A6DA0;
extern u32 lbl_801A6DA4;
extern u32 lbl_801A6DA8;

void fn_80077848(void) {
    lbl_801A6DA8 = 0;
    lbl_801A6DA4 = 0;
    lbl_801A6DA0 = 0;
}

/* --- dol/fn_8007785C.c --- */
extern u32 OSGetArenaHi(void);
extern u32 fn_80071794(u32);
extern void OSSetArenaHi(u32);

u32 fn_8007785C(u32 count, s32 useArena) {
    u32 i;
    u32 top;

    if (useArena != 0) {
        top = OSGetArenaHi();
        top -= (count * 48) & 0xFFFFFFE0;
        lbl_801A6DA8 = top;
        top -= (count * 4) & 0xFFFFFFE0;
        lbl_801A6DA4 = top;
        lbl_801A6DA0 = 0;
        OSSetArenaHi(lbl_801A6DA4);
    } else {
        lbl_801A6DA8 = fn_80071794(count * 48);
        lbl_801A6DA4 = fn_80071794(count * 4);
        lbl_801A6DA0 = 1;
        for (i = 0; i < count; i++) {
            ((u32 *)lbl_801A6DA4)[i] = lbl_801A6DA8 + i * 48;
        }
    }
    return lbl_801A6DA4;
}

/* --- dol/fn_80077A18.c --- */
/* --- dol/fn_80077A18.c --- */

u32 fn_80077A18(void) {
    return lbl_801A6DA4;
}

/* --- dol/fn_80077A20.c --- */
/* --- dol/fn_80077A20.c --- */
extern void _savegpr_27(void);
extern void lbl_8006DD14(void *arg0, void *arg1);
extern void _restgpr_27(void);

struct fn_80077A20_Arg0 {
    u16 unk_0;
    u8 pad_2[0x16];
    u16 index;
    u8 pad_1a[4];
    u8 count;
    u8 pad_1f[0x21];
    u8 data[1];
};

void *fn_80077A20(struct fn_80077A20_Arg0 *arg0, void **table) {
    u8 *entry;
    u8 *data;
    u8 i;

    entry = (u8 *)arg0 + (arg0->index << 5);
    entry += 0x40;
    data = entry;
    if (table == 0) {
        table = (void **)lbl_801A6DA4;
        i = 0;
        while (i < arg0->count) {
            *table = entry;
            entry += 0x30;
            table += 1;
            i += 1;
        }
    } else {
        i = 0;
        while (i < arg0->count) {
            lbl_8006DD14(entry, *table);
            entry += 0x30;
            table += 1;
            i += 1;
        }
    }
    return data;
}

/* --- dol/fn_80077AD0.c --- */
struct fn_80077AD0_Arg0 {
    u8 pad_0[0x1E];
    u8 unk_1E;
};


u32 fn_80077AD0(struct fn_80077AD0_Arg0 *arg0, u32 arg1) {
    u32 v0;
    s32 v1;
    s32 v2;

    v0 = arg1;
    v2 = 0;
    v1 = 0;
    while (v2 < arg0->unk_1E) {
        v2++;
        *(u32 *)((u8 *)lbl_801A6DA4 + v1) = v0;
        v0 += 48;
        v1 += 4;
    }
    return arg0->unk_1E;
}

/* --- dol/fn_80077B04.c --- */

void fn_80077B04(f32 value) {
    ((f32 *)lbl_8019F130)[3] = value;
}

/* --- dol/fn_80077B14.c --- */
/* --- dol/fn_80077B14.c --- */
struct fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

extern u32 OSReport(u32, ...);
extern u32 lbl_8015AD48[];

s32 fn_80077B14(struct fn_80077B14_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    u32 t0;
    v0 = arg0->unk_20;
    v1 = ((u32)arg0 + v0);
    v2 = v1;
    if ((arg0->unk_4 & 0x18) != 0) {
    v2 = (v2 + *(u32 *)(v2 + 8));
    } else {
    v2 = (u32)&lbl_8015AD48;
    t0 = OSReport(v2);
    v2 = t0;
    v2 = 0;
    }
    return v2;
}

/* --- dol/fn_80077B64.c --- */
struct fn_80077B64_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};


s32 fn_80077B64(struct fn_80077B64_Arg0 *arg0) {
    u32 v0;
    u32 t0;
    v0 = (u32)arg0;
    if ((arg0->unk_4 & 0x18) != 0) {
    v0 = (v0 + *(u32 *)(v0 + 32));
    } else {
    v0 = (u32)&lbl_8015AD48;
    t0 = OSReport(v0);
    v0 = t0;
    v0 = 0;
    }
    return v0;
}

/* --- dol/fn_80077BAC.c --- */

u32 fn_80077BAC(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D90;
    lbl_801A6D90 = arg0;
    return v0;
}

/* --- dol/fn_80077BBC.c --- */
/* --- dol/fn_80077BBC.c --- */

void fn_80077BBC(s32 arg0) {
    u32 v0;
    v0 = 0;
    if (arg0) {
        v0 = 3;
    }
    lbl_801A6D98 = v0;
}

/* --- dol/fn_80077BD4.c --- */
extern u32 fn_80072404(u32, s32);

static inline u32 fn_80077BD4_entry(u32 entry) {
    u32 node;
    u32 j;
    u32 sum;
    node = entry + *(u32 *)(entry + 32);
    sum = 0;
    j = 0;
    while (j < (*(u16 *)(entry + 26) + *(u16 *)(entry + 28))) {
        u32 n;
        n = fn_80072404(*(u32 *)(node + 28), 0);
        if ((*(u32 *)(entry + 4) & 0x18) != 0) {
            if (*(u32 *)(node + 40) != 0) {
                sum += n * *(u32 *)(node + 40);
            }
            if (*(u32 *)(node + 44) != 0) {
                sum += n * *(u32 *)(node + 44);
            }
            node += 96;
        } else {
            u32 p;
            u32 k;
            u32 a;
            u32 b;
            if (*(u32 *)(node + 40) != 0) {
                sum += *(u32 *)(node + 40) / n;
            }
            if (*(u32 *)(node + 44) != 0) {
                sum += *(u32 *)(node + 44) / n;
            }
            p = node;
            p += 96;
            for (k = 0; k < 2; k++) {
                if (*(u8 *)(node + 19) & (1 << k)) {
                    p += ((u32 *)(node + 40))[k];
                }
            }
            if (*(u8 *)(node + 19) & 0xC) {
                b = *(u32 *)(p + 12);
                a = *(u32 *)(p + 8);
                p += 32;
                p += a;
                p += b;
            }
            node = p;
        }
        j++;
    }
    return sum;
}

u32 fn_80077BD4(u32 arg0, u32 arg1, u32 arg2) {
    u32 off;
    u32 i;
    u32 total;
    u32 entry;

    total = 0;
    i = 0;
    off = 0;
    while (i < *(u32 *)(arg0)) {
        entry = *(u32 *)(*(u32 *)(arg0 + 8) + off);
        if (entry != 0) {
            total += fn_80077BD4_entry(entry);
        }
        off += 8;
        i++;
    }
    return total;
}

/* --- dol/fn_80077D40.c --- */
struct Item {
    u32 flags;
    u32 unk_4;
    u16 width;
    u16 height;
    u16 max_lod;
    u16 pad_e;
};

struct TextureList {
    u32 count;
    struct Item *items;
};

typedef u8 Sig_GXGetTexBufferSize_GXBool;

extern u32 fn_800717BC(u32, u32);
extern u32 GXGetTexBufferSize(u16, u16, u32, Sig_GXGetTexBufferSize_GXBool, u8);

u32 fn_80077D40(struct TextureList *arg0) {
    u32 i;
    u32 total;
    u32 max_lod;
    struct Item *item;

    total = 0;

    for (i = 0; i < arg0->count; i++) {
        item = &arg0->items[i];
        if ((item->flags & 0x100) == 0) {
            max_lod = fn_800717BC(item->width, item->height);
            if (max_lod == 0xFFFFFFFF) {
                max_lod = 0;
            }
            if (item->max_lod != -1 && item->max_lod < max_lod) {
                max_lod = item->max_lod;
            }
            total += GXGetTexBufferSize(item->width, item->height, item->flags & 0x1F, max_lod != 0, max_lod);
        }
    }

    return total;
}

/* --- dol/fn_80077E0C.c --- */
struct fn_80077E0C_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};
struct fn_80077E0C_lbl_801A6D38_T {
    u8 pad_0[0x18];
    u32 unk_18;
};

extern u32 fn_800756B0(u32, u32);
extern u32 lbl_801A6D9C;

void fn_80077E0C(struct fn_80077E0C_Arg0 *arg0) {
    u32 v1;
    u32 v2;
    u32 v3;
    u32 v0;
    u32 v4;
    v0 = ((u32)arg0 + 64);
    v1 = arg0->unk_20;
    v2 = ((struct fn_80077E0C_lbl_801A6D38_T *)lbl_801A6D38)->unk_18;
    v3 = ((u32)arg0 + v1);
    v4 = v2;
    if ((s32)v2 != 0) {
    v4 = (v4 ^ 3);
    }
    lbl_801A6D9C = v4;
    if (lbl_801A6D90 == 0) {
    v4 = v3;
    fn_800756B0((u32)arg0, v4);
    }
    v4 = v0;
    fn_80075908(v3, v4);
}

/* === dol/fn_80077E7C.c === */
typedef struct {
    u8 pad_00[0x1a];
    u16 count_a;
    u16 count_b;
} Sig_fn_800786B0_Fn800786B0Arg0_u13;

typedef struct {
    u8 pad_00[0xc];
    u32 offset;
    u8 pad_10[0xa];
    u16 count_a;
    u16 count_b;
    u8 pad_20[0x4];
} Sig_fn_800786B0_Fn800786B0Data_u13;

struct fn_80077E7C_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};
struct fn_80077E7C_lbl_801A6D38_T {
    u8 pad_0[0x18];
    u32 unk_18;
};
extern void fn_80078CDC(s32);



void fn_80077E7C(Sig_fn_800786B0_Fn800786B0Arg0_u13 *arg0) {
    Sig_fn_800786B0_Fn800786B0Data_u13 *var_r30;
    u32 temp_r3;
    u32 var_r3;
    u8 *temp_r29;
    s32 var_r28;

    temp_r29 = ((u8 *)(arg0) + 0x40);
    var_r3 = (*(struct fn_80077E7C_lbl_801A6D38_T **)(&((struct fn_80077E7C_lbl_801A6D38_T *)lbl_801A6D38)))->unk_18;
    var_r30 = (Sig_fn_800786B0_Fn800786B0Data_u13 *)((u8 *)(arg0) + (*(s32 *)((u8 *)(arg0) + 32)));
    if ((s32) var_r3 != 0) {
        var_r3 ^= 3;
    }
    lbl_801A6D9C = var_r3;
    temp_r3 = *(u32 *)((u8 *)(arg0) + 4);
    if (temp_r3 & 4) {
        fn_80078C28((Sig_fn_800786B0_Fn800786B0Arg0_u13 *)(arg0));
    } else if ((temp_r3 & 8) && !(temp_r3 & 0x40)) {
        fn_80078538((Sig_fn_800786B0_Fn800786B0Data_u13 *)(var_r30));
    }
    lbl_801A6D94 = 1;
    if ((*(u32 *)((u8 *)(arg0) + 4)) & 0x18) {
        fn_800786B0((Sig_fn_800786B0_Fn800786B0Arg0_u13 *)(arg0), (Sig_fn_800786B0_Fn800786B0Data_u13 *)(var_r30), temp_r29);
    } else {
        var_r28 = 0;
        while (var_r28 < (arg0->count_a + arg0->count_b)) {
            var_r30 = (Sig_fn_800786B0_Fn800786B0Data_u13 *)(fn_800789D8((Sig_fn_800786B0_Fn800786B0Arg0_u13 *)(arg0), (Sig_fn_800786B0_Fn800786B0Data_u13 *)(var_r30), temp_r29));
            var_r28 += 1;
                    }
    }
    lbl_801A6D94 = 0;
    (*(u32 *)((u8 *)(arg0) + 4)) = ((*(u32 *)((u8 *)(arg0) + 4)) & 0xFFFFFF9F);
    fn_80078CDC(((*(u32 *)((u8 *)(arg0) + 4)) >> 2U) & 1);
}

/* === dol/fn_80077F8C.c === */
typedef struct {
    u8 pad_00[0x1a];
    u16 count_a;
    u16 count_b;
} Sig_fn_800786B0_Fn800786B0Arg0_u14;

typedef struct {
    u8 pad_00[0xc];
    u32 offset;
    u8 pad_10[0xa];
    u16 count_a;
    u16 count_b;
    u8 pad_20[0x4];
} Sig_fn_800786B0_Fn800786B0Data_u14;

struct fn_80077F8C_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};
struct fn_80077F8C_lbl_801A6D38_T {
    u8 pad_0[0x18];
    u32 unk_18;
};



void fn_80077F8C(Sig_fn_800786B0_Fn800786B0Arg0_u14 *arg0) {
    Sig_fn_800786B0_Fn800786B0Data_u14 *var_r30;
    u32 temp_r3;
    u32 var_r3;
    u8 *temp_r29;
    s32 var_r28;

    temp_r29 = ((u8 *)(arg0) + 0x40);
    var_r3 = (*(struct fn_80077F8C_lbl_801A6D38_T **)(&((struct fn_80077F8C_lbl_801A6D38_T *)lbl_801A6D38)))->unk_18;
    var_r30 = (Sig_fn_800786B0_Fn800786B0Data_u14 *)((u8 *)(arg0) + (*(s32 *)((u8 *)(arg0) + 32)));
    if ((s32) var_r3 != 0) {
        var_r3 ^= 3;
    }
    lbl_801A6D9C = var_r3;
    temp_r3 = *(u32 *)((u8 *)(arg0) + 4);
    if (temp_r3 & 4) {
        fn_80078C28((Sig_fn_800786B0_Fn800786B0Arg0_u14 *)(arg0));
    } else if ((temp_r3 & 8) && !(temp_r3 & 0x40)) {
        fn_80078538((Sig_fn_800786B0_Fn800786B0Data_u14 *)(var_r30));
    }
    if (lbl_801A6D90 == 0) {
        fn_800756B0((u32)(arg0), (u32)(var_r30));
    }
    if ((*(u32 *)((u8 *)(arg0) + 4)) & 0x18) {
        fn_800786B0((Sig_fn_800786B0_Fn800786B0Arg0_u14 *)(arg0), (Sig_fn_800786B0_Fn800786B0Data_u14 *)(var_r30), temp_r29);
    } else {
        var_r28 = 0;
        while (var_r28 < (arg0->count_a + arg0->count_b)) {
            var_r30 = (Sig_fn_800786B0_Fn800786B0Data_u14 *)(fn_800789D8((Sig_fn_800786B0_Fn800786B0Arg0_u14 *)(arg0), (Sig_fn_800786B0_Fn800786B0Data_u14 *)(var_r30), temp_r29));
            var_r28 += 1;
                    }
    }
    (*(u32 *)((u8 *)(arg0) + 4)) = ((*(u32 *)((u8 *)(arg0) + 4)) & 0xFFFFFF9F);
    fn_80078CDC(((*(u32 *)((u8 *)(arg0) + 4)) >> 2U) & 1);
}

/* === dol/fn_800780A4.c === */
typedef struct {
    u8 pad_00[0x1a];
    u16 count_a;
    u16 count_b;
} Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0;

typedef struct {
    u8 pad_00[0xc];
    u32 offset;
    u8 pad_10[0xa];
    u16 count_a;
    u16 count_b;
    u8 pad_20[0x4];
} Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data;

typedef struct {
    u8 pad_00[0x1a];
    u16 count_a;
    u16 count_b;
} Sig_fn_800789D8_Sig_fn_800786B0_Fn800786B0Arg0;

typedef struct {
    u8 pad_00[0xc];
    u32 offset;
    u8 pad_10[0xa];
    u16 count_a;
    u16 count_b;
    u8 pad_20[0x4];
} Sig_fn_800789D8_Sig_fn_800786B0_Fn800786B0Data;

struct fn_800780A4_Arg0 {
    u8 pad_0[0x20];
    u32 unk_20;
};
struct fn_800780A4_lbl_801A6D38_T {
    u8 pad_0[0x18];
    u32 unk_18;
};



void fn_800780A4(Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0 *arg0) {
    Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *var_r31;
    u32 temp_r3;
    u32 var_r3;
    u8 *temp_r30;
    s32 var_r29;

    temp_r30 = ((u8 *)(arg0) + 0x40);
    var_r3 = (*(struct fn_800780A4_lbl_801A6D38_T **)(&((struct fn_800780A4_lbl_801A6D38_T *)lbl_801A6D38)))->unk_18;
    var_r31 = (Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *)((u8 *)(arg0) + (*(s32 *)((u8 *)(arg0) + 32)));
    if ((s32) var_r3 != 0) {
        var_r3 ^= 3;
    }
    lbl_801A6D9C = var_r3;
    temp_r3 = *(u32 *)((u8 *)(arg0) + 4);
    if (temp_r3 & 4) {
        fn_80078C28((Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0 *)(arg0));
    } else if ((temp_r3 & 8) && !(temp_r3 & 0x40)) {
        fn_80078538((Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *)(var_r31));
    }
    if (lbl_801A6D90 == 0) {
        fn_800756B0((u32)(arg0), (u32)(var_r31));
    }
    if ((*(u32 *)((u8 *)(arg0) + 4)) & 0x18) {
        fn_80078768((Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0 *)(arg0), (Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *)(var_r31), temp_r30, (1));
    } else {
        var_r29 = 0;
        while (var_r29 < arg0->count_a) {
            var_r31 = (Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *)(fn_800789D8((Sig_fn_800789D8_Sig_fn_800786B0_Fn800786B0Arg0 *)((Sig_fn_800789D8_Sig_fn_800786B0_Fn800786B0Arg0 *) arg0), (Sig_fn_800789D8_Sig_fn_800786B0_Fn800786B0Data *)((Sig_fn_800789D8_Sig_fn_800786B0_Fn800786B0Data *) var_r31), temp_r30));
            var_r29 += 1;
                    }
    }
    (*(u32 *)((u8 *)(arg0) + 4)) = ((*(u32 *)((u8 *)(arg0) + 4)) & 0xFFFFFF9F);
    fn_80078CDC((((*(u32 *)((u8 *)(arg0) + 4)) >> 2U) & 1));
}

/* === dol/fn_800781B8.c === */

typedef struct {
    u8 pad_00[0x1a];
    u16 count_a;
    u16 count_b;
} Sig_fn_80078768_Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0;

typedef struct {
    u8 pad_00[0xc];
    u32 offset;
    u8 pad_10[0xa];
    u16 count_a;
    u16 count_b;
    u8 pad_20[0x4];
} Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data;

struct fn_800781B8_lbl_801A6D38_T {
    u8 pad_0[0x18];
    u32 unk_18;
};


void fn_800781B8(Sig_fn_80078768_Sig_fn_80078C28_Sig_fn_800786B0_Fn800786B0Arg0 *arg0) {
    u32 temp_r3;
    u32 var_r3;
    s32 var_r28;
    Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *var_r30;
    u8 *temp_r29;
    u32 var_b;

    temp_r29 = ((u8 *)(arg0) + 0x40);
    var_r3 = ((struct fn_800781B8_lbl_801A6D38_T *)lbl_801A6D38)->unk_18;
    var_r30 = (Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *)((u8 *)(arg0) + (*(s32 *)((u8 *)(arg0) + 32)));
    if ((s32) var_r3 != 0) {
        var_r3 ^= 3;
    }
    lbl_801A6D9C = var_r3;
    temp_r3 = *(u32 *)((u8 *)(arg0) + 4);
    if (temp_r3 & 4) {
        fn_80078C28(arg0);
    } else if ((temp_r3 & 8) && !(temp_r3 & 0x40)) {
        fn_80078538(var_r30);
    }
    if (lbl_801A6D90 == 0) {
        fn_800756B0((u32)(arg0), (u32)(var_r30));
    }
    if ((*(u32 *)((u8 *)(arg0) + 4)) & 0x18) {
        fn_80078768(arg0, var_r30, temp_r29, 0);
    } else {
        s32 var_i;
        for (var_i = 0; var_i < arg0->count_a; var_i++) {
            u8 *var_p;
            s32 var_j;
            var_p = (u8 *) var_r30 + 0x60;
            for (var_j = 0; var_j < 2; var_j++) {
                if (*((u8 *) var_r30 + 0x13) & (1 << var_j)) {
                    var_p += *(u32 *)((u8 *) var_r30 + 0x28 + var_j * 4);
                }
            }
            if (*((u8 *) var_r30 + 0x13) & 0xC) {
                u32 var_a;
                var_a = *(u32 *)(var_p + 8);
                var_b = *(u32 *)(var_p + 0xc);
                var_p += 0x20;
                var_p += var_a;
                var_p += var_b;
            }
            var_r30 = (Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *) var_p;
        }
        var_r28 = 0;
        while (var_r28 < arg0->count_b) {
            var_r30 = (Sig_fn_80078768_Sig_fn_80078538_Sig_fn_800786B0_Fn800786B0Data *)(fn_800789D8(arg0, var_r30, temp_r29));
            var_r28 += 1;
        }
    }
    (*(u32 *)((u8 *)(arg0) + 4)) = ((*(u32 *)((u8 *)(arg0) + 4)) & 0xFFFFFF9F);
    fn_80078CDC(((*(u32 *)((u8 *)(arg0) + 4)) >> 2U) & 1);
}

/* === dol/fn_80078344.c === */

/* WARNING: compiler-diff device, not original code: optimization_level 0, scheduling off and K&R register parameters reproduce retail's unscheduled li/lis/ori FIFO write in r6/r7 (6 and 1 instructions differ without them); the shape suggests an original asm helper, owner decision */
#pragma optimization_level 0
#pragma scheduling off
static inline void writeDisplayList(u32 a, u32 b, u32 unused, u32 command, u32 address) {
    /* Volatile stores send commands to the GX write-gather FIFO. */
    *(volatile u8 *)address = command;
    *(volatile u32 *)address = a;  /* fzgx-allow: S2 volatile view keeps the verified load order */
    *(volatile u32 *)address = b;  /* fzgx-allow: S2 volatile view keeps the verified load order */
}
void fn_80078344(a, b, unused, command, address)
    register u32 a;
    register u32 b;
    register u32 unused;
    register u32 command;
    register u32 address;
{
    command = 0x40;
    address = GX_FIFO_BASE & 0xFFFF0000;
    address |= GX_FIFO_BASE & 0xFFFF;
    writeDisplayList(a, b, unused, command, address);
}
/* WARNING: compiler-diff device, not original code: restores the optimizer after fn_80078344 (see above); dropping it compiles fn_80078360 at level 0 (85 instructions differ) */
#pragma optimization_level 4
#pragma scheduling reset

/* WARNING: compiler-diff device, not original code: dont_inline on keeps fn_80078344 a call in fn_80078360 (31 instructions differ without it); unneeded if fn_80078344 is an asm unit */
#pragma dont_inline on
/* === dol/fn_80078360.c === */

typedef struct {
    u32 unk_00;
    u8 pad_04[0xf];
    u8 unk_13;
    u8 pad_14[0x8];
    u32 unk_1c;
    u8 pad_20[0x8];
    u32 arr_28[2];
    u32 arr_30[6];
    u32 arr_48[2];
    u32 arr_50[2];
} fn_80078360_Arg0;

typedef struct {
    u8 pad_00[0x8];
    u32 offset;
    u8 pad_0c[0x10];
    u32 unk_1c;
} fn_80078360_Arg2;

typedef struct {
    u8 pad_00[0x4];
    u32 flags;
    u8 pad_08[0x28];
    u32 unk_30;
    u32 unk_34;
} fn_80078360_Arg4;

typedef u32 (*fn_80078360_Cb)(void *);

extern u32 fn_80078884(u32, u32, u32, u32);
extern u32 fn_80078944(u32, u32, u32, u32);
extern void fn_80033E7C(void);
extern void fn_8003458C(void);
extern void fn_800723B8(u32, u32);
extern u32 fn_800723D8(void);
extern void fn_8007245C(u32);
extern void fn_80078D60(s32);

/* WARNING: compiler-diff device, not original code: without opt_loop_invariants off fn_80078360 differs by 47 instructions (callee-saved order of p/arg3/i) */
#pragma opt_loop_invariants off
/* WARNING: compiler-diff device, not original code: without opt_propagation off fn_80078360 differs by 3 instructions (r3/r4 swap of arg2->offset); hoisting the offset read into v2 or reordering the first statements gives 3 and 7 */
#pragma opt_propagation off
void *fn_80078360(fn_80078360_Arg0 *arg0, u8 *arg1, fn_80078360_Arg2 *arg2, u8 *arg3, fn_80078360_Arg4 *arg4) {
    s32 mask2;
    u32 v1;
    u8 *p;
    s32 i;
    s32 flag;
    u32 t;
    u8 *v2;
    u8 cond;
    u32 loc_8[14];
    s32 tmp_ra3;

    v1 = arg2->offset;
    v2 = (u8 *)arg2 + v1;
    t = lbl_801A6D98 ^ 2;
    mask2 = arg0->unk_00 & 2;
    if (mask2 != 0) {
        t = 0;
    }
    flag = t ^ 0;
    fn_8007245C(arg0->unk_1c);
    if (lbl_801A6D90 != 0) {
        loc_8[1] = (u32)arg0;
        loc_8[2] = (u32)arg1;
        cond = ((fn_80078360_Cb)lbl_801A6D90)(&loc_8);
    } else {
        if (lbl_801A6D94 == 0) {
            fn_80075908((u32)arg0, (u32)arg1);
        }
        cond = 1;
    }
    if (cond != 0) {
        fn_8003458C();
        p = (u8 *)arg0;
        for (i = 0, p = (u8 *)arg0; i < 2; i++, p += 4) {
            if ((arg0->unk_13 & (1 << i)) != 0) {
                fn_80078D60(flag);
                if ((arg4->flags & 0x40) != 0) {
                    fn_80078344(*(u32 *)(p + 0x48), *(u32 *)(p + 0x50));
                } else {
                    tmp_ra3 = arg4->flags;
                    if ((tmp_ra3 & 0x20) != 0) {
                        *(u32 *)(p + 0x48) = (arg4->unk_30 + 31) & ~0x1F;
                        fn_800723B8(*(u32 *)(p + 0x48), 0x80000);
                        fn_80033E7C();
                    }
                    if ((arg2->unk_1c & 1) != 0) {
                        fn_80078944(arg0->unk_1c, (u32)v2, (u32)arg3, *(u32 *)(p + 0x28));
                        arg3 += *(u32 *)(p + 0x28) << 1;
                    } else {
                        fn_80078884(arg0->unk_1c, (u32)v2, (u32)arg3, *(u32 *)(p + 0x28));
                        arg3 += *(u32 *)(p + 0x28) << 2;
                    }
                    if ((arg4->flags & 0x20) != 0) {
                        *(u32 *)(p + 0x50) = fn_800723D8();
                        fn_80078344(*(u32 *)(p + 0x48), *(u32 *)(p + 0x50));
                        arg4->unk_30 = *(u32 *)(p + 0x48) + *(u32 *)(p + 0x50);
                        (*( u32 * )(&arg4->unk_34) = (arg4->unk_34 + *(u32 *)(p + 0x50)));
                    }
                }
            }
            if (flag != 0) {
                flag = lbl_801A6D98 ^ 1;
            }
        }
    }
    return arg3;
}
#pragma opt_loop_invariants reset
