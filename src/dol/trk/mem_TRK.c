#include "dol/trk_memory.h"

__declspec(section ".init") void *fn_80003590(void *dst, int value, size_t size) {
    TRK_fill_mem(dst, value, size);
    return dst;
}

__declspec(section ".init") void *fn_800035C0(void *dest, const void *src, size_t n) {
    const u8 *s = src;
    u8 *d = dest;

    s--;
    d--;
    n++;
    while (--n != 0) {
        *++d = *++s;
    }
    return dest;
}

void TRK_fill_mem(void *dst, int val, size_t n) {
    u32 v, i, j;
    v = (u8)val;
    ((u8 *)dst) = ((u8 *)dst) - 1;
    if (n >= 32) {
        i = (~(u32)dst) & 3;
        if (i) {
            n -= i;
            do {
                *++(((u8 *)dst)) = v;
            } while (--i);
        }
        if (v)
            v |= v << 24 | v << 16 | v << 8;
        ((u32 *)dst) = ((u32 *)(((u8 *)dst) + 4)) - 1;
        ((u32 *)dst) = ((u32 *)(((u8 *)dst) + 1)) - 1;
        i = n / 32;
        if (i) {
            do {
                for (j = 0; j < 8; j++)
                    *++((u32 *)dst) = v;
            } while (--i);
        }
        i = (n / 4) % 8;
        if (i) {
            do {
                *++((u32 *)dst) = v;
            } while (--i);
        }
        ((u8 *)dst) = ((u8 *)(((u32 *)dst) + 1)) - 1;
        n %= 4;
    }
    if (n)
        do {
            *++((u8 *)dst) = v;
        } while (--n);
}
