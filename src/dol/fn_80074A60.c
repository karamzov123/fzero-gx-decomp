#include "types.h"


/* --- dol/fn_80074A60.c --- */
/* --- dol/fn_80074A60.c --- */
extern u32 lbl_801A6D5C;
extern u32 lbl_801A6D60;

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
extern u32 lbl_801A6D40;

u32 fn_80074A7C(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D40;
    lbl_801A6D40 = arg0;
    return v0;
}

/* --- dol/fn_80074A8C.c --- */
/* --- dol/fn_80074A8C.c --- */
extern const f32 lbl_801A7488;
extern const f32 lbl_801A7484;
extern u8 lbl_801A6D80[4];
extern u32 lbl_801A6D88[2];

void fn_80074A8C(f32 a, f32 b, f32 c, f32 d) {
    if (lbl_801A7488 != a || lbl_801A7488 != b ||
        lbl_801A7488 != c || lbl_801A7488 != d) {
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
        green = (u8)(lbl_801A7484 * b);
        blue = (u8)(lbl_801A7484 * c);
        alpha = (u8)(lbl_801A7484 * d);
        lbl_801A6D88[0] = 1;
        lbl_801A6D80[0] = ((u8)(lbl_801A7484 * a));
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
extern const f32 lbl_801A7480;
extern u32 lbl_801A6D7C;
extern u32 lbl_801A6D84;

void fn_80074BC4(f32 a, f32 b, f32 c, f32 d) {
    u8 v3;
    if (!(lbl_801A7480 == a &&
          lbl_801A7480 == b &&
          lbl_801A7480 == c &&
          lbl_801A7480 == d)) {
        f32 scale = lbl_801A7484;
        u8 v0 = (u8)(scale * a);
        u8 v1 = (u8)(scale * b);
        u8 v2 = (u8)(scale * c);

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
extern f32 lbl_8019F130[7];

void fn_80074CF4(f32 arg0, f32 arg1, f32 arg2) {
    lbl_8019F130[0] = arg0;
    lbl_8019F130[1] = arg1;
    lbl_8019F130[2] = arg2;
}

/* --- dol/fn_80074D08.c --- */
extern u32 lbl_801A6D74;

u32 fn_80074D08(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6D74;
    lbl_801A6D74 = arg0;
    return v0;
}

/* --- dol/fn_80074D18.c --- */
extern u32 lbl_801A6D64;

void fn_80074D18(u32 arg0) {
    lbl_801A6D64 = ((u32)__cntlzw(arg0) >> 5);
}

/* --- dol/fn_80074D28.c --- */
struct fn_80074D28_Data {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

extern struct fn_80074D28_Data lbl_8019F14C;
extern void lbl_8006D668(struct fn_80074D28_Data *);

void fn_80074D28(struct fn_80074D28_Data *src) {
    lbl_8019F14C = *src;
    lbl_8006D668(&lbl_8019F14C);
}

/* --- dol/fn_80074D68.c --- */
/* --- dol/fn_80074D68.c --- */
extern f32 lbl_801A6D68;
extern f32 lbl_801A6D6C;
extern f32 lbl_801A6D70;

void fn_80074D68(f32 arg0, f32 arg1, f32 arg2) {
    lbl_801A6D70 = arg0;
    lbl_801A6D6C = arg1;
    lbl_801A6D68 = arg2;
}

/* --- dol/fn_80074D78.c --- */
extern u32 lbl_801A6D58;

void fn_80074D78(u32 arg0) {
    lbl_801A6D58 = ((u32)__cntlzw(arg0) >> 5);
}
