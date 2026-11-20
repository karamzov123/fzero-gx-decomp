#include "types.h"


/* --- dol/fn_80050BD4.c --- */
struct Sig_fn_800501F4_fn_800501F4_Arg0 {
    u8 pad_0[0x8];
    s32 unk_8;
    s32 unk_C;
    s32 unk_10;
};

struct fn_80050BD4_Arg1 {
    u8 pad_0[0x4];
    s32 unk_4;
    u8 pad_8[0x8];
    s32 unk_10;
};

extern s32 fn_800501F4(struct Sig_fn_800501F4_fn_800501F4_Arg0 *, s32);

void fn_80050BD4(struct Sig_fn_800501F4_fn_800501F4_Arg0 *ctx, struct fn_80050BD4_Arg1 *info,
                 u32 present[][32], s32 kind[][32], s32 out[][3][32]) {
    s32 w;
    s32 h;
    s32 x;
    s32 y;

    w = info->unk_10;
    h = info->unk_4;
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            if (present[y][x] != 0) {
                kind[y][x] = fn_800501F4(ctx, 2);
            }
        }
    }
    for (x = w; x < 32; x++) {
        for (y = 0; y < h; y++) {
            kind[y][x] = 0;
        }
    }
    for (x = 0; x < w; x++) {
        for (y = 0; y < h; y++) {
            if (present[y][x] != 0) {
                switch (kind[y][x]) {
                case 0:
                    out[y][0][x] = fn_800501F4(ctx, 6);
                    out[y][1][x] = fn_800501F4(ctx, 6);
                    out[y][2][x] = fn_800501F4(ctx, 6);
                    break;
                case 1:
                    out[y][0][x] = out[y][1][x] = fn_800501F4(ctx, 6);
                    out[y][2][x] = fn_800501F4(ctx, 6);
                    break;
                case 3:
                    out[y][0][x] = fn_800501F4(ctx, 6);
                    out[y][1][x] = out[y][2][x] = fn_800501F4(ctx, 6);
                    break;
                case 2:
                    out[y][0][x] = out[y][1][x] = out[y][2][x] = fn_800501F4(ctx, 6);
                    break;
                }
            } else {
                out[y][0][x] = out[y][1][x] = out[y][2][x] = 63;
            }
        }
    }
    for (x = w; x < 32; x++) {
        for (y = 0; y < h; y++) {
            out[y][0][x] = out[y][1][x] = out[y][2][x] = 63;
        }
    }
}

/* --- dol/fn_80050F64.c --- */
/* --- dol/fn_80050F64.c --- */
// fn_80050F64: returns a constant.
int fn_80050F64(void) {
    return 96;
}

/* --- dol/fn_80050F6C.c --- */
// fn_80050F6C: returns a constant.
int fn_80050F6C(void) {
    return 16;
}

/* --- dol/fn_80050F74.c --- */
struct fn_80050F74_Arg0 {
    u8 pad_0[0x345];
    u8 unk_345;
};

u32 fn_80050F74(struct fn_80050F74_Arg0 *arg0) {
    u32 v0;
    v0 = (u32)arg0;
    if ((s8)arg0->unk_345 == 0) {
    v0 = 0;
    return v0;
    }
    v0 = *(u32 *)(v0 + 904);
    return v0;
}

/* --- dol/fn_80050F90.c --- */
typedef struct StreamObj {
    void *unk0;
    u8 pad4[0x344];
    s32 unk348;
    u32 unk34c;
    u32 unk350;
    u8 pad354[0x30];
    u32 unk384;
    s32 unk388;
    u8 pad38c[0x2c];
    u32 unk3b8;
    u8 pad3bc[0x1fc];
    u32 unk5b8;
} StreamObj;

extern int fn_80053A30(void);
extern void fn_80050698(u32, void *, void *, void *, s32, void *);
extern void fn_80053DB4(u32, void *, s32, void *);
extern u32 lbl_80187118[6];

#define adxtNullCallback fn_80053A30
#define ADXF_Stop fn_80050698

// Donor seed for fn_80050F90 (addr 0x80050F90)
// Extracted from adxt_80050F90.c (original name: ADXF_StreamTeardown)

int fn_80050F90(StreamObj* obj, char* arg4, char* arg5)
{
    int r28 = obj->unk388;
    int i;

    if (obj->unk348 == 12) {
        return 0;
    }

    lbl_80187118[0] = adxtNullCallback();
    ADXF_Stop(obj->unk34c, &obj->unk384, &obj->unk3b8, &obj->unk5b8, obj->unk348 >> 2, obj->unk0);

    lbl_80187118[3] = adxtNullCallback();
    for (i = 0; i < 3; i++) {
        fn_80053DB4(obj->unk350, (char*)obj->unk0 + i * 0x80, 0, arg4 + i * 0x40);
    }

    lbl_80187118[4] = adxtNullCallback();
    if (r28 >= 2) {
        for (i = 0; i < 3; i++) {
            fn_80053DB4(obj->unk350, (char*)obj->unk0 + 0x180 + i * 0x80, 1, arg5 + i * 0x40);
        }
    }

    lbl_80187118[5] = adxtNullCallback();
    obj->unk348++;
    return 0x60;
}
