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
