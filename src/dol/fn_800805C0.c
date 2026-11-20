#include "types.h"

#pragma opt_common_subs off
#pragma opt_lifetimes off
void fn_800805C0(void *arg0, const void *arg1, size_t arg2) {
    const u8 *v0;
    s32 v4_2;
    u8 *v2;
    size_t v3;
    s32 v4;
    u32 a;
    struct { u32 value; } b;
    u32 * d;
    const u8 * v0_2;
    v0 = (const u8 *)arg1 - 1;
{
    u32 v1;
    v1 = (-(u32)arg0) & 3;
    v2 = arg0;
    v2 = v2 - 1;
    v3 = arg2;
    v4 = v1;
    if (v4) {
        v3 -= v4;
        do {
            *++((u8 *)v2) = *++((const u8 *)v0);
        } while (--v4);
    }
}
    {
        const u32 *s;
        u32 words;
        v4 = v3 >> 5;
        s = (const u32 *)(v0 - 3);
        d = (u32 *)(v2 - 3);
        if (v4) {
            do {
                a = s[1];
                b.value = s[2];
                (void)b.value;
                d[1] = a;
                a = s[3];
                d[2] = b.value;
                b.value = s[4];
                d[3] = a;
                a = s[5];
                d[4] = b.value;
                b.value = s[6];
                d[5] = a;
                a = s[7];
                d[6] = b.value;
                b.value = s[8];
                d[7] = a;
                d[8] = b.value;
                d += 8;
                s += 8;
            } while (--v4);
        }
        v4_2 = (v3 >> 2) & 7;
        words = v4_2;
        if (words) {
            do {
                *++d = *++s;
            } while (--words);
        }
        v3 &= 3;
        v0_2 = (const u8 *)s;
        v0_2 += 3;
        v2 = (u8 *)d;
        v2 = v2 + 3;
    }
    if (v3) {
        do {
            *++((u8 *)v2) = *++((const u8 *)v0_2);
        } while (--v3);
    }
}
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
