#include "types.h"

typedef struct MovieSrc {
    u32 *data;
    u8 pad4[8];
    s32 stride;
} MovieSrc;

typedef struct MovieDst {
    u32 pad0;
    u32 *data;
    s32 pitch;
    volatile s32 height;  /* fzgx-allow: S2 volatile keeps the verified access order */
    s32 width;
} MovieDst;

static inline void fn_12_3DBE0_fzgx_rgn0(u32 * palette, u32 i2, u32 i3, s32 top) {
    u32 a;
    u32 b;

    a = *(u32 *)((u8 *)palette + i2);
                b = *(u32 *)((u8 *)palette + i3);
                *(u32 *)(top + 4) = (b & 0xFFFF0000) | (a >> 16);
}

static inline u32 fn_12_3DBE0_merge(u32 a, u32 b) {
    return (a << 16) | (b & 0xFFFF);
}

static inline s32 fn_12_3DBE0_div4(s32 value, MovieSrc *source, s32 *src) {
    s32 quotient;
    *src = (s32)source->data;
    quotient = value / 4;
    return quotient;
}

#pragma inline_max_size(4096)
#pragma opt_lifetimes on
void fn_12_3DBE0(MovieSrc *source, MovieDst *dest, u32 *palette) {
    s32 width;
    u32 i2;
    s32 x;
    struct { s32 value; } rawHeight;
    u32 a;
    u32 b;
    s32 y;
    register s32 height;
    s32 row;
    s32 src;
    s32 top;
    s32 bottom;
    struct { s32 value; } skip;
    struct { s32 value; } stride;
    struct { s32 value; } stride4;
    u32 packed;
    u32 i0;
    u32 i1;
    u32 i3;
    s32 rawStride;
    s32 rawSkip;
    s32 rawWidth;

    skip.value = 0;
    stride.value = 0;
    stride4.value = 0;

    rawWidth = dest->width;
    b = source->stride;
    height = rawWidth / 4;
    width = height;
    rawSkip = dest->pitch - rawWidth;
    top = (u32)dest->data;
    rawHeight.value = dest->height;
    src = (u32)source->data;
    rawHeight.value /= 4;
    dest = (MovieDst *)rawHeight.value;
    height = (s32)dest;
    bottom = top + 32;
    stride.value = b & ~3;
    stride4.value = (b << 2) & ~15;
    skip.value = rawSkip << 4;

    for (y = 0; y < height;) {
        for (x = 0; x < width;) {
            for (row = 0; row < 4; row++) {
                packed = *(u32 *)src;
                src += stride.value;
                i1 = (packed >> 22) & 1020;
                i0 = (packed >> 14) & 1020;
                i2 = (packed << 2) & 1020;
                i3 = (packed >> 6) & 1020;
                b = *(u32 *)((u8 *)palette + i1);
                a = *(u32 *)((u8 *)palette + i0);
                *(u32 *)(top + 0) = (b & 0xFFFF0000) | (a >> 16);
                fn_12_3DBE0_fzgx_rgn0(palette, i2, i3, top);
                top += 8;
                a = *(u32 *)((u8 *)palette + i1);
                b = *(u32 *)((u8 *)palette + i0);
                *(u32 *)(bottom + 0) = (a << 16) | (b & 0xFFFF);
                a = *(u32 *)((u8 *)palette + i3);
                b = *(volatile u32 *)((u8 *)palette + i2);  /* fzgx-allow: S2 volatile view keeps the verified load order */
                *(u32 *)(bottom + 4) = fn_12_3DBE0_merge(a, b);
                bottom += 8;
            }
            src -= stride4.value;
            x++;
            src += 4;
            top += 32;
            bottom += 32;
        }
        x = src - stride.value;
        top += skip.value;
        bottom += skip.value;
        y++;
        src = x + stride4.value;
    }
}
