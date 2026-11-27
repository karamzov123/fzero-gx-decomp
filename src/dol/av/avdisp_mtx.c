#include "types.h"
#include "psvec.h"

typedef struct { u32 dummy[8]; } GXTexObj;
typedef struct { u8 r, g, b, a; } GXColor;
typedef struct { f32 x, y, z; } Vec;

typedef struct {
    u8 unk_0;
    s8 unk_1;
    u8 unk_2;
    s8 unk_3;
    s8 unk_4;
    s8 unk_5;
    u8 pad_6[2];
    u32 unk_8;
    u32 unk_C;
    GXColor unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
    s32 unk_24;
    s32 unk_28;
    s32 unk_2C;
    s32 unk_30;
    u16 unk_34;
    u16 unk_36;
    u16 unk_38;
    u8 pad_3A[2];
    u32 unk_3C;
    u32 unk_40;
    u32 unk_44;
    u32 unk_48;
    u32 unk_4C;
    Vec unk_50;
} fn_800756B0_State;

__declspec(section ".data") u8 lbl_8019F040[0x20];
__declspec(section ".data") f32 lbl_8019F040__fzgx_offset_20[3][4];
__declspec(section ".data") f32 lbl_8019F040__fzgx_offset_50[3][3][4];
__declspec(section ".data") s32 lbl_8019F040__fzgx_offset_E0[3];
__declspec(section ".data") u32 lbl_8019F040_fill_8019F12C;
__declspec(section ".data") f32 lbl_8019F130[4];
__declspec(section ".data") Vec lbl_8019F130__fzgx_offset_10;
__declspec(section ".data") Vec lbl_8019F14C;
__declspec(section ".data") GXTexObj lbl_8019F158;
__declspec(section ".data") f32 lbl_8019F158__fzgx_offset_20[3][4];
__declspec(section ".data") u32 lbl_8019F158_fill_8019F1A8[6];
__declspec(section ".data") u8 lbl_8019F158_68[0x40];
__declspec(section ".data") GXTexObj lbl_8019F200;
__declspec(section ".data") u8 lbl_8019F200_20[0x4000];
__declspec(section ".data") fn_800756B0_State lbl_801A3220;

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_8019F040;
    s = *(u8 *)&lbl_8019F040__fzgx_offset_20;
    s = *(u8 *)&lbl_8019F040__fzgx_offset_50;
    s = *(u8 *)&lbl_8019F040__fzgx_offset_E0;
    s = *(u8 *)&lbl_8019F040_fill_8019F12C;
    s = *(u8 *)&lbl_8019F130;
    s = *(u8 *)&lbl_8019F130__fzgx_offset_10;
    s = *(u8 *)&lbl_8019F14C;
    s = *(u8 *)&lbl_8019F158;
    s = *(u8 *)&lbl_8019F158__fzgx_offset_20;
    s = *(u8 *)&lbl_8019F158_fill_8019F1A8;
    s = *(u8 *)&lbl_8019F158_68;
    s = *(u8 *)&lbl_8019F200;
    s = *(u8 *)&lbl_8019F200_20;
    s = *(u8 *)&lbl_801A3220;
}
#pragma section code_type ".text"

extern const f32 lbl_801A7480;
extern const f32 lbl_801A7484;
extern const f32 lbl_801A7488;
extern const f32 lbl_801A748C;
extern const f64 lbl_801A7490;
extern const f32 lbl_801A749C;
extern const GXColor lbl_801A7928;
extern const GXColor lbl_801A7498;
extern u32 lbl_801A6D38;
extern u32 lbl_801A6D40;
extern s32 lbl_801A6D44;
extern s32 lbl_801A6D48;
extern f32 lbl_801A6D4C;
extern GXColor lbl_801A6D50;
extern u32 lbl_801A6D54;
extern s32 lbl_801A6D58;
extern s32 lbl_801A6D5C;
extern s32 lbl_801A6D60;
extern s32 lbl_801A6D64;
extern f32 lbl_801A6D68;
extern f32 lbl_801A6D6C;
extern f32 lbl_801A6D70;
extern s32 lbl_801A6D74;
extern s32 lbl_801A6D78;
extern u32 lbl_801A6D7C;
extern u8 lbl_801A6D80[4];
extern s32 lbl_801A6D84;
extern s32 lbl_801A6D88[2];
extern f32 *lbl_801A6D00;
extern void GXLoadTexMtxImm();
extern void fn_800736C0();
extern void lbl_8006D668();


/* --- dol/fn_800747D0.c --- */
/* --- dol/fn_800747D0.c --- */
extern u32 fn_80035960(u32, u32, u32, u32, u32, u32, u32);

typedef struct {
    u8 unk_00;
    s32 unk_04;
    s32 unk_08;
    u32 unk_0C;
    s32 unk_10;
    s32 unk_14;
} fn_800747D0_Entry;

void fn_800747D0(u32 arg0, u32 arg1, s32 arg2, s32 arg3, u32 arg4, s32 arg5, s32 arg6) {
    fn_800747D0_Entry *entry;
    u32 id;

    id = arg0;
    switch (arg0) {
    case 0:
        entry = (fn_800747D0_Entry *)(lbl_801A6D38 + 3120);
        break;
    case 1:
        entry = (fn_800747D0_Entry *)(lbl_801A6D38 + 3144);
        break;
    case 2:
        entry = (fn_800747D0_Entry *)(lbl_801A6D38 + 3168);
        break;
    case 3:
        break;
    case 4:
        fn_800747D0(0, arg1, arg2, arg3, arg4, arg5, arg6);
        id = 2;
        entry = (fn_800747D0_Entry *)(lbl_801A6D38 + 3168);
        break;
    case 5:
        fn_800747D0(1, arg1, arg2, arg3, arg4, arg5, arg6);
        id = 3;
        entry = (fn_800747D0_Entry *)(lbl_801A6D38 + 3192);
        break;
    }
    if (entry->unk_00 != (arg1 & 0xFF) || entry->unk_04 != arg2 || entry->unk_08 != arg3 || entry->unk_0C != arg4 || entry->unk_10 != arg5 || entry->unk_14 != arg6) {
        fn_80035960(id, arg1, arg2, arg3, arg4, arg5, arg6);
        entry->unk_00 = arg1;
        entry->unk_04 = arg2;
        entry->unk_08 = arg3;
        entry->unk_0C = arg4;
        entry->unk_10 = arg5;
        entry->unk_14 = arg6;
    }
}

/* --- dol/fn_80074918.c --- */
extern void fn_80037BC0(u8 arg0, s32 arg1, u8 arg2);

typedef struct CacheData {
    u8 unk_00;
    u8 unk_01[3];
    s32 unk_04;
    u8 unk_08;
} CacheData;

void fn_80074918(u8 arg0, s32 arg1, u8 arg2) {
    CacheData *cache;

    cache = (CacheData *)lbl_801A6D38;
    if (cache->unk_00 == arg0 && cache->unk_04 == arg1 && cache->unk_08 == arg2) {
        return;
    }

    fn_80037BC0(arg0, arg1, arg2);
    ((CacheData *)lbl_801A6D38)->unk_00 = arg0;
    ((CacheData *)lbl_801A6D38)->unk_04 = arg1;
    ((CacheData *)lbl_801A6D38)->unk_08 = arg2;
}

/* --- dol/fn_800749B0.c --- */
extern void lbl_8006DD14(void *arg0, void *arg1);

void fn_800749B0(u32 index, void *transform) {
    if (index == 0) {
        if (transform != 0) {
            lbl_8006DD14(transform, lbl_8019F040__fzgx_offset_20);
            lbl_801A6D78 = 1;
        } else {
            lbl_801A6D78 = 0;
        }
    } else {
        if (transform != 0) {
            lbl_8006DD14(transform, lbl_8019F040__fzgx_offset_50[index - 1]);
            *(u32 *)((u8 *)lbl_8019F040__fzgx_offset_E0 + ((index - 1) << 2)) = 1;
        } else {
            *(u32 *)((u8 *)lbl_8019F040__fzgx_offset_E0 + ((index - 1) << 2)) = 0;
        }
    }
}

/* --- dol/fn_80074A60.c --- */
/* --- dol/fn_80074A60.c --- */
/* --- dol/fn_80074A60.c --- */

void fn_80074A60(u32 arg0, u32 arg1) {
    lbl_801A6D60 = arg0;
    lbl_801A6D5C = arg1;
}

/* --- dol/fn_80074A6C.c --- */
void fn_80074A6C(void) {
    lbl_801A6D60 = 0xFFFFFFFF;
    lbl_801A6D5C = 0xFFFFFFFF;
}

/* --- dol/fn_80074A7C.c --- */

u32 fn_80074A7C(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D40;
    lbl_801A6D40 = arg0;
    return v0;
}

/* --- dol/fn_80074A8C.c --- */
/* --- dol/fn_80074A8C.c --- */

void fn_80074A8C(f32 a, f32 b, f32 c, f32 d) {
    if (lbl_801A7488 != a || lbl_801A7488 != b ||
        lbl_801A7488 != c || lbl_801A7488 != d) {
        u8 green;
        u8 blue;
        u8 alpha;
        green = (lbl_801A7484 * b);
        blue = (lbl_801A7484 * c);
        alpha = (lbl_801A7484 * d);
        lbl_801A6D88[0] = 1;
        lbl_801A6D80[0] = ((lbl_801A7484 * a));
        lbl_801A6D80[1] = green;
        lbl_801A6D80[2] = blue;
        lbl_801A6D80[3] = alpha;
    } else {
        lbl_801A6D88[0] = 0;
        lbl_801A6D80[0] = 0xFF;
        lbl_801A6D80[1] = 0xFF;
        lbl_801A6D80[2] = 0xFF;
        lbl_801A6D80[3] = 0xFF;
    }
}

/* --- dol/fn_80074B40.c --- */
void fn_80074B40(u8 *arg0) {
    if (arg0[0] != 0xFF || arg0[1] != 0xFF ||
        arg0[2] != 0xFF || arg0[3] != 0xFF) {
        lbl_801A6D88[0] = 1;
        lbl_801A6D80[0] = arg0[0];
        lbl_801A6D80[1] = arg0[1];
        lbl_801A6D80[2] = arg0[2];
        lbl_801A6D80[3] = arg0[3];
    } else {
        lbl_801A6D88[0] = 0;
        lbl_801A6D80[0] = 0xFF;
        lbl_801A6D80[1] = 0xFF;
        lbl_801A6D80[2] = 0xFF;
        lbl_801A6D80[3] = 0xFF;
    }
}

/* --- dol/fn_80074BC4.c --- */

void fn_80074BC4(f32 a, f32 b, f32 c, f32 d) {
    if (!(lbl_801A7480 == a &&
          lbl_801A7480 == b &&
          lbl_801A7480 == c &&
          lbl_801A7480 == d)) {
        f32 scale = lbl_801A7484;
        u8 v0 = (scale * a);
        u8 v1 = (scale * b);
        u8 v2 = (scale * c);

        lbl_801A6D84 = 1;
        *((u8 *)&lbl_801A6D7C) = v0;
        *((u8 *)&lbl_801A6D7C + 1) = v1;
        *((u8 *)&lbl_801A6D7C + 2) = v2;
        *((u8 *)&lbl_801A6D7C + 3) = ((u8)(scale * d));
    } else {
        lbl_801A6D84 = 0;
        *((u8 *)&lbl_801A6D7C) = 0;
        *((u8 *)&lbl_801A6D7C + 1) = 0;
        *((u8 *)&lbl_801A6D7C + 2) = 0;
        *((u8 *)&lbl_801A6D7C + 3) = 0;
    }
}

/* --- dol/fn_80074C74.c --- */
void fn_80074C74(u8 *arg0) {
    if (arg0[0] || arg0[1] || arg0[2] || arg0[3]) {
        lbl_801A6D84 = 1;
        ((u8 *)&lbl_801A6D7C)[0] = arg0[0];
        ((u8 *)&lbl_801A6D7C)[1] = arg0[1];
        ((u8 *)&lbl_801A6D7C)[2] = arg0[2];
        ((u8 *)&lbl_801A6D7C)[3] = arg0[3];
    } else {
        lbl_801A6D84 = 0;
        ((u8 *)&lbl_801A6D7C)[0] = 0;
        ((u8 *)&lbl_801A6D7C)[1] = 0;
        ((u8 *)&lbl_801A6D7C)[2] = 0;
        ((u8 *)&lbl_801A6D7C)[3] = 0;
    }
}

/* --- dol/fn_80074CF4.c --- */
/* --- dol/fn_80074CF4.c --- */

void fn_80074CF4(f32 arg0, f32 arg1, f32 arg2) {
    lbl_8019F130[0] = arg0;
    lbl_8019F130[1] = arg1;
    lbl_8019F130[2] = arg2;
}

/* --- dol/fn_80074D08.c --- */

u32 fn_80074D08(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D74;
    lbl_801A6D74 = arg0;
    return v0;
}

/* --- dol/fn_80074D18.c --- */

void fn_80074D18(u32 arg0) {
    lbl_801A6D64 = ((u32)__cntlzw(arg0) >> 5);
}

/* --- dol/fn_80074D28.c --- */
void fn_80074D28(Vec *src) {
    lbl_8019F14C = *src;
    lbl_8006D668(&lbl_8019F14C);
}

/* --- dol/fn_80074D68.c --- */
/* --- dol/fn_80074D68.c --- */

void fn_80074D68(f32 arg0, f32 arg1, f32 arg2) {
    lbl_801A6D70 = arg0;
    lbl_801A6D6C = arg1;
    lbl_801A6D68 = arg2;
}

/* --- dol/fn_80074D78.c --- */

void fn_80074D78(u32 arg0) {
    lbl_801A6D58 = ((u32)__cntlzw(arg0) >> 5);
}
/* WARNING: compiler-diff device, not original code: without opt_propagation off fn_80074D88 differs by 23 instructions (pragma spans fn_80074D88..fn_80075080) */
#pragma opt_propagation off

/* --- dol/fn_80074D88.c --- */
struct fn_80074D88_lbl_8019F008 {
    u8 pad_0[0x4];
    f32 unk_4;
    u8 pad_8[0x4];
    f32 unk_C;
};
extern struct fn_80074D88_lbl_8019F008 lbl_8019F008[];
extern void lbl_8006DAEC(u32, u32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073778(void *, s32);
extern void fn_800738E0(s32, s32, s32);
extern void fn_80073A58(int, void *, s8);
extern void fn_80073B50(u32, s32, s32, s32, s32, s32, s32, u8, u8, s32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void lbl_8006D758(void);
extern void lbl_8006DB30(void);

void fn_80074D88(u32 arg0, u32 arg1) {
    u32 v0;
    f32 *matrix;
    f32 v2;
    f32 v1;
    f32 half;
    f32 scale;
    f32 loc_14[2][3];
    GXColor loc_10;
    v0 = arg0;
    if (lbl_801A6D54 != 0) {
    lbl_8006DAEC(v0, arg1);
    GXLoadTexMtxImm(lbl_801A6D00, 30, 0);
    v1 = lbl_801A7488;
    lbl_801A6D00[8] = lbl_801A7480;
    lbl_801A6D00[9] = lbl_801A7480;
    lbl_801A6D00[10] = lbl_801A7480;
    matrix = (f32 *)(0xE0000000 + 0x00);
    matrix[3] = lbl_801A7480;
    matrix[7] = lbl_801A7480;
    matrix[11] = v1;
    GXLoadTexMtxImm(lbl_801A6D00, 45, 0);
    lbl_8006D758();
    v1 = lbl_801A748C;
    lbl_801A6D00[0] = (v1 * (-lbl_8019F008[0].unk_4));
    lbl_801A6D00[5] = (v1 * lbl_8019F008[0].unk_C);
    lbl_801A6D00[2] = v1;
    lbl_801A6D00[6] = v1;
    GXLoadTexMtxImm(lbl_801A6D00, 76, 0);
    lbl_8006D758();
    lbl_801A6D00[0] = lbl_801A748C;
    lbl_801A6D00[5] = lbl_801A748C;
    lbl_801A6D00[2] = lbl_801A748C;
    lbl_801A6D00[6] = lbl_801A748C;
    GXLoadTexMtxImm(lbl_801A6D00, 73, 0);
    lbl_8006DB30();
    fn_80073778(&lbl_8019F158, *(u32 *)((u8 *)arg1 + 12));
    fn_800738E0(*(u32 *)((u8 *)arg1 + 16), *(u32 *)((u8 *)arg1 + 4), *(u32 *)(arg1 + 12));
    fn_800745A4(*(u32 *)(arg1 + 4), 0, 1, 45, 0, 73);
    scale = lbl_801A6D4C;
    v1 = lbl_801A7480;
    loc_14[0][0] = v1;
    loc_14[0][1] = v1;
    v2 = (*(f32 *)(arg0 + 60) * scale);
    loc_14[1][0] = v1;
    loc_14[1][2] = v1;
    half = lbl_801A748C;
    v1 = (-v2);
    v1 = (half * v1);
    loc_14[1][1] = (half * v2);
    loc_14[0][2] = v1;
    fn_80073A58(1, &loc_14, 1);
    fn_80073B50(*(u32 *)(arg1), *(u32 *)((u8 *)arg1 + 16), 0, 7, 1, 0, 0, 0, 0, 0);
    (*(u32 *)(arg1 + 16))++;
    (*(u32 *)(arg1 + 4))++;
    (*(u32 *)(arg1 + 12))++;
    fn_80073778(lbl_8019F040, *(u32 *)(arg1 + 12));
    fn_800745A4(*(u32 *)(arg1 + 4), 0, 0, 30, 0, 76);
    loc_10 = lbl_801A6D50;
    fn_800736C0(1, &loc_10);
    fn_800735C8(*(u32 *)(arg1), 13);
    fn_80072AB0(*(u32 *)(arg1), 0, 0);
    fn_800734A8(*(u32 *)(arg1), *(u32 *)(arg1 + 4), *(u32 *)(arg1 + 12), 4);
    fn_80072C24(*(u32 *)(arg1), 0, 8, 14, 15);
    fn_80072D64(*(u32 *)(arg1), 0, 0, 0, 1, 0);
    fn_80072CC4(*(u32 *)(arg1), 0, 6, 6, 7);
    fn_80072E20(*(u32 *)(arg1), 0, 0, 0, 1, 0);
    v0 = *(u32 *)(arg1);
    *(u32 *)((u8 *)arg1 + 0) = (v0 + 1);
    v0 = *(u32 *)(arg1 + 4);
    *(u32 *)((u8 *)arg1 + 4) = (v0 + 1);
    v0 = *(u32 *)(arg1 + 12);
    *(u32 *)((u8 *)arg1 + 12) = (v0 + 1);
    }
}

/* --- dol/fn_80075080.c --- */
struct fn_80075080_Arg0 {
    u32 unk_0;
};
struct fn_80075080_lbl_8019F130 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
};
extern u32 fn_80072614(void *);
extern u32 fn_800725DC(void *);

struct FzgxCopy_4 { u32 words[1]; };
void fn_80075080(void *arg0) {
    struct FzgxCopy_4 loc_14;
    struct FzgxCopy_4 loc_10;
    u32 spC;
    u32 sp8;
    f32 temp_f31;
    f32 var_f4;
    f32 var_f5;
    f32 var_f6;
    s32 temp_r3;
    s32 var_r31;
    s32 var_r4;

    temp_r3 = *(s32 *)((u8 *)(arg0));
    var_r31 = 0;
    var_r4 = 0;
    if (temp_r3 & 8) {
        var_r4 = 1;
        var_r31 = 1;
    } else if (temp_r3 & 0x80) {
        var_r31 = 1;
    }
    temp_f31 = lbl_8019F130[3];
    if (var_r4 != 0) {
        var_f4 = (*((u8 *)(arg0) + 8));
        var_f5 = (*((u8 *)(arg0) + 9));
        var_f6 = (*((u8 *)(arg0) + 10));
    } else {
        var_f4 = lbl_801A7484;
        var_f5 = var_f4;
        var_f6 = var_f4;
    }
    (*((u8 *)(&loc_10) + 3)) = ((lbl_801A7484) * temp_f31);
    (*(s8 *)(&loc_10)) = (var_f4 * lbl_8019F130[0]);
    (*((u8 *)(&loc_10) + 1)) = (var_f5 * lbl_8019F130[1]);
    (*((u8 *)(&loc_10) + 2)) = (var_f6 * lbl_8019F130[2]);
    spC = loc_10.words[0];
    fn_80072614(&spC);
    if (var_r31 != 0) {
        (*(u8 *)(&loc_14)) = *((u8 *)(arg0) + 4);
        (*((u8 *)(&loc_14) + 1)) = *((u8 *)(arg0) + 5);
        (*((u8 *)(&loc_14) + 2)) = *((u8 *)(arg0) + 6);
    } else {
        (*(u8 *)(&loc_14)) = 0xFF;
        (*((u8 *)(&loc_14) + 1)) = 0xFF;
        (*((u8 *)(&loc_14) + 2)) = 0xFF;
    }
    (*((u8 *)(&loc_14) + 3)) = (temp_f31 * (*((u8 *)(arg0) + 17)));
    sp8 = loc_14.words[0];
    fn_800725DC(&sp8);
}
#pragma opt_propagation reset

extern void lbl_8006D7F4(f32, f32, f32);
extern void lbl_8006DB74(f32 (*)[4]);
extern void *memset(void *, int, u32);
extern void DCFlushRange(void *, u32);
extern void GXInitTexObj(GXTexObj *, void *, u16, u16, int, int, int, u8);
extern void GXInitTexObjLOD(GXTexObj *, int, int, f32, f32, f32, u8, u8, int);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_800729B0(s32, s32, s32, s32, s32);



void fn_80075240(void) {
    Vec up;
    GXColor black = lbl_801A7928;
    GXColor white = lbl_801A7498;
    s32 ty;
    s32 tx;
    s32 row;
    s32 col;
    s32 tile;
    s32 x;
    s32 n;
    /* WARNING: compiler-diff device, not original code: one-field carrier: plain u32 dst changes fn_80075240's code (MWCC renumbers its literals and the function no longer matches) */
    struct { u32 value; } dst;

    lbl_8019F130[2] = 1.0f;
    lbl_8019F130[1] = 1.0f;
    lbl_8019F130[0] = 1.0f;
    lbl_801A6D74 = 1;
    lbl_801A6D78 = 0;
    lbl_8019F040__fzgx_offset_E0[0] = 0;
    lbl_8019F040__fzgx_offset_E0[1] = 0;
    lbl_8019F040__fzgx_offset_E0[2] = 0;
    lbl_8006D7F4(0.0f, 0.0f, 1.0f);
    lbl_8006DB74(lbl_8019F158__fzgx_offset_20);
    GXLoadTexMtxImm(lbl_8019F158__fzgx_offset_20, 0x21, 0);

    up.x = 0.0f;
    up.y = 1.0f;
    up.z = 0.0f;
    lbl_801A6D60 = -1;
    lbl_801A6D5C = -1;
    lbl_8019F14C = up;
    lbl_8006D668(&lbl_8019F14C);

    {
        f32 one;
        f32 zero;
        f32 neg;
        f32 *v;
        one = lbl_801A7488;
        neg = lbl_801A749C;
        zero = lbl_801A7480;
        v = (f32 *)&lbl_8019F130__fzgx_offset_10;
        lbl_801A6D70 = one;
        lbl_801A6D6C = one;
        lbl_801A6D68 = one;
        lbl_801A6D64 = 1;
        lbl_801A6D48 = 0;
        v[0] = zero;
        v[1] = zero;
        v[2] = neg;
    }

    memset(lbl_8019F158_68, 0xFF, 0x20);
    memset(lbl_8019F158_68 + 0x20, 0, 0x20);
    DCFlushRange(lbl_8019F158_68, 0x40);
    GXInitTexObj(&lbl_8019F200, lbl_8019F158_68, 16, 4, 1, 0, 0, 0);
    GXInitTexObjLOD(&lbl_8019F200, 1, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);

    /* 64x64 RGBA8 texture in 4x4 texel tiles: AR block then GB block */
    dst.value = (u32)lbl_8019F200_20;
    for (ty = 0; ty < 16; ty++) {
        for (tx = 0; tx < 16; tx++) {
            tile = ty * 16 + tx;
            for (row = 0; row < 4; row++) {
                for (col = 0; col < 4; col++) {
                    x = tx * 4 + col;
                    n = row * 4 + col;
                    {
                        s32 address;
                        address = (tile * 64 + n * 2);
                        address += dst.value;
                        *(u8 *)(address + 0) = 0;
                        *(u8 *)(address + 1) = 0;
                        *(u8 *)(address + 32) = (x & 0x3F) << 2;
                        *(u8 *)(address + 33) = (ty * 4 + row) << 2;
                    }
                }
            }
        }
    }
    DCFlushRange(lbl_8019F200_20, 0x4000);
    GXInitTexObj(&lbl_8019F158, lbl_8019F200_20, 64, 64, 6, 2, 2, 0);
    GXInitTexObjLOD(&lbl_8019F158, 3, 1, 0.0f, 0.0f, 0.0f, 0, 0, 0);

    lbl_801A6D54 = 0;
    lbl_801A6D50 = white;
    lbl_801A6D4C = 1.0f;
    fn_800728A8(0, 1, 0, 0);
    fn_800729B0(0, 0, 1, 2, 3);
    fn_800729B0(1, 0, 1, 2, 0);
    fn_800729B0(2, 0, 1, 2, 1);
    fn_800729B0(3, 0, 1, 2, 2);
    fn_800736C0(0, black);
    fn_800736C0(1, black);
    fn_800736C0(2, black);
    fn_800736C0(3, black);
    lbl_801A6D40 = 0;
    lbl_801A6D58 = 0;
    lbl_801A6D44 = 0;
}
typedef struct {
    u8 pad_0[4];
    u32 flags;
    Vec pos;
    f32 unk_14;
} fn_800756B0_Arg0;

typedef struct {
    u32 flags;
    u8 pad_4[8];
    GXColor unk_C;
    u8 pad_10[0x30];
    u32 unk_40;
} fn_800756B0_Arg1;

extern void lbl_8006E1B0(Vec *, Vec *);

void fn_800756B0(fn_800756B0_Arg0 *arg0, fn_800756B0_Arg1 *arg1) {
    s32 i;
    u32 color0;
    u32 color1;

    lbl_801A3220.unk_0 = 1;
    if (arg0->flags & 0x18) {
        arg1 = (fn_800756B0_Arg1 *)((u8 *)arg1 + 0x20);
    }
    if (lbl_801A6D78 != 0) {
        GXLoadTexMtxImm(lbl_8019F040__fzgx_offset_20, 0x24, 0);
    } else {
        GXLoadTexMtxImm(lbl_8019F158__fzgx_offset_20, 0x24, 0);
    }
    for (i = 0; i < 3; i++) {
        if (lbl_8019F040__fzgx_offset_E0[i] != 0) {
            GXLoadTexMtxImm(lbl_8019F040__fzgx_offset_50[i], 0x33 + i * 3, 0);
        } else {
            GXLoadTexMtxImm(lbl_8019F158__fzgx_offset_20, 0x33 + i * 3, 0);
        }
    }
    fn_80075080(arg1);
    lbl_801A3220.unk_10 = arg1->unk_C;
    lbl_801A3220.unk_2 = 0;
    lbl_801A3220.unk_14 = 15;
    lbl_801A3220.unk_18 = 7;
    lbl_801A3220.unk_3 = 0xFF;
    lbl_801A3220.unk_4 = 0xFF;
    lbl_801A3220.unk_5 = 0xFF;
    lbl_801A3220.unk_8 = 16;
    lbl_801A3220.unk_C = 16;
    if (lbl_801A6D88[0] != 0) {
        color0 = *(u32 *)lbl_801A6D80;
        fn_800736C0(2, &color0);
    }
    if (lbl_801A6D84 != 0) {
        color1 = lbl_801A6D7C;
        fn_800736C0(3, &color1);
    }
    lbl_801A3220.unk_1C = 4;
    lbl_801A3220.unk_20 = 5;
    if (arg1->flags & 0x20) {
        lbl_801A3220.unk_1C = arg1->unk_40 & 0xF;
    }
    if (arg1->flags & 0x40) {
        lbl_801A3220.unk_20 = (arg1->unk_40 >> 4) & 0xF;
    }
    fn_800728A8(1, lbl_801A3220.unk_1C, lbl_801A3220.unk_20, 0);
    lbl_801A3220.unk_1 = 0xFF;
    lbl_801A3220.unk_24 = -1;
    lbl_801A3220.unk_28 = -1;
    lbl_801A3220.unk_2C = -1;
    lbl_801A3220.unk_30 = -1;
    lbl_801A3220.unk_34 = 0xFFFF;
    lbl_801A3220.unk_36 = 0xFFFF;
    lbl_801A3220.unk_38 = 0xFFFF;
    lbl_801A3220.unk_3C = 0;
    lbl_801A3220.unk_40 = 0;
    lbl_801A3220.unk_44 = 0;
    lbl_801A3220.unk_48 = 0;
    lbl_801A3220.unk_4C = 0;
    if (lbl_801A6D48 != 0) {
        lbl_8006E1B0(&arg0->pos, &lbl_801A3220.unk_50);
        lbl_801A3220.unk_50.z = lbl_801A3220.unk_50.z - arg0->unk_14;
    } else {
        lbl_801A3220.unk_50 = lbl_8019F130__fzgx_offset_10;
    }
    lbl_8006D668(&lbl_801A3220.unk_50);
}
