#include "types.h"

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
