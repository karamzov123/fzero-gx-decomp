#include "types.h"

__declspec(section ".init") void *fn_800035C0(void *dest, const void *src, u32 n) {
    const u8 *s = src;
    u8 *d = dest;

    s--;
    d--;
    n++;
    while (--n != 0) {
        *++d = *++s;
    }
}
