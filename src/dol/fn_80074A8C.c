#include "types.h"


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
