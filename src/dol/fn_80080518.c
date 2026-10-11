#include "types.h"

#pragma opt_common_subs off
#pragma opt_lifetimes off
void fn_80080518(void *dst, const void *src, size_t n) {
    u32 i;
    u32 b;
    u32 blocks;
    const u8 *s;
    u32 b_2;
    s32 i_2;
    u8 *d = (u8 *)dst + n;

    s = (const u8 *)src + n;
    i = (u32)d;

    i &= 3;
    if (i) {
        n -= i;
        do {
            *--d = *--s;
        } while (--i);
    }

    blocks = n;

    blocks >>= 5;
    if (blocks) {
        do {
            i = ((u32 *)s)[-1];
            b = ((u32 *)s)[-2];
            ((u32 *)d)[-1] = i;
            i = ((u32 *)s)[-3];
            ((u32 *)d)[-2] = b;
            b = ((u32 *)s)[-4];
            ((u32 *)d)[-3] = i;
            i = ((u32 *)s)[-5];
            ((u32 *)d)[-4] = b;
            b = ((u32 *)s)[-6];
            ((u32 *)d)[-5] = i;
            i = ((u32 *)s)[-7];
            ((u32 *)d)[-6] = b;
            b = ((u32 *)s)[-8];
            ((u32 *)d)[-7] = i;
            ((u32 *)d)[-8] = b;
            d -= 32;
            s -= 32;
        } while (--blocks);
    }

    b_2 = (n >> 2) & 7;
    i_2 = b_2;
    if (i_2) {
        do {
            *--((u32 *)d) = *--((u32 *)s);
        } while (--i_2);
    }

    n &= 3;
    if (n) {
        do {
            *--d = *--s;
        } while (--n);
    }
}
#pragma opt_lifetimes reset

#pragma opt_common_subs reset

