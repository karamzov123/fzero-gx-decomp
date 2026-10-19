#include "types.h"

void fn_800538D0(f32 *tile, f32 *kernel, s16 *out) {
    s32 n = 32;

    do {
        f32 acc = 0.0f;
        f32 v;

        acc += kernel[0] * tile[0x0 / 4];
        acc += kernel[1] * tile[0x180 / 4];
        acc += kernel[2] * tile[0x200 / 4];
        acc += kernel[3] * tile[0x380 / 4];
        acc += kernel[4] * tile[0x400 / 4];
        acc += kernel[5] * tile[0x580 / 4];
        acc += kernel[6] * tile[0x600 / 4];
        acc += kernel[7] * tile[0x780 / 4];
        acc += kernel[8] * tile[0x800 / 4];
        acc += kernel[9] * tile[0x980 / 4];
        acc += kernel[10] * tile[0xa00 / 4];
        acc += kernel[11] * tile[0xb80 / 4];
        acc += kernel[12] * tile[0xc00 / 4];
        acc += kernel[13] * tile[0xd80 / 4];
        acc += kernel[14] * tile[0xe00 / 4];
        acc += kernel[15] * tile[0xf80 / 4];

        kernel += 16;
        tile++;

        if (acc > 2147483648.0f) {
            v = 2147483648.0f;
        } else if (acc < -2147483648.0f) {
            v = -2147483648.0f;
        } else {
            v = acc;
        }

        *out++ = (f32)((s32)v >> 16);
    } while (--n);
}
