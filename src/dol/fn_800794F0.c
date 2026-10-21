#include "types.h"

void fn_800794F0(u8 *dst, u8 *src, s32 len) {
    s32 n = len >> 4;
    s32 m;
    while (n > 0) {
        ((u32 *)dst)[0] = ((u32 *)src)[0];
        ((u32 *)dst)[1] = ((u32 *)src)[1];
        ((u32 *)dst)[2] = ((u32 *)src)[2];
        ((u32 *)dst)[3] = ((u32 *)src)[3];
        dst += 16;
        src += 16;
        n--;
    }
    m = len & 15;
    while (m > 0) {
        *dst++ = *src++;
        m--;
    }
}
