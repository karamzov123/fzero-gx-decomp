#include "types.h"

char *fn_80083DB0(char *dst, const char *src) {
    u8 *d = (u8 *)dst;
    const u8 *s = (const u8 *)src;
    u32 w;
    u32 n;

    if (((u32)dst & 3) == ((u32)src & 3)) {
        n = (u32)src & 3;
        if (n != 0) {
            if ((*d = *s) == 0) {
                return dst;
            }
            for (n = 3 - n; n != 0; n--) {
                if ((*++d = *++s) == 0) {
                    return dst;
                }
            }
            d++;
            s++;
        }
        w = *(const u32 *)s;
        if (((w - 0x01010101) & ~0x7F7F7F7Fu) == 0) {
            u32 *dw = (u32 *)d - 1;
            do {
                *++dw = w;
                w = *(const u32 *)(s += 4);
            } while (((w - 0x01010101) & ~0x7F7F7F7Fu) == 0);
            d = (u8 *)(dw + 1);
        }
    }
    if ((*d = *s) == 0) {
        return dst;
    }
    while ((*++d = *++s) != 0) {
    }
    return dst;
}

