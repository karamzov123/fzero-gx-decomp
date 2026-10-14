/* Non-matching: best partial attempt (19.68% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_12_1FADC_Arg0 {
    u8 pad_0[0x18];
    void *dst;
    u8 pad_1[4];
    u32 stride;
    u8 *src;
};

static void copy_words(void *dst, const void *src, u32 stride) {
    u32 i;
    for (i = 0; i < 16; i++) {
        ((u32 *)dst)[i] = ((const u32 *)((const u8 *)src + (stride & ~3u) * i))[0];
    }
}

void fn_12_1FADC(struct fn_12_1FADC_Arg0 *arg0) {
    u8 *src = arg0->src;
    u8 *dst = (u8 *)arg0->dst;
    u32 stride = arg0->stride;
    switch (stride & 7) {
    case 0: {
        u32 step = stride & ~7u;
        ((u64 *)(dst + 0x00))[0] = *(u64 *)(src + step * 0);
        ((u64 *)(dst + 0x40))[0] = *(u64 *)(src + step * 0 + 8);
        ((u64 *)(dst + 0x08))[0] = *(u64 *)(src + step * 1);
        ((u64 *)(dst + 0x48))[0] = *(u64 *)(src + step * 1 + 8);
        ((u64 *)(dst + 0x10))[0] = *(u64 *)(src + step * 2);
        ((u64 *)(dst + 0x50))[0] = *(u64 *)(src + step * 2 + 8);
        ((u64 *)(dst + 0x18))[0] = *(u64 *)(src + step * 3);
        ((u64 *)(dst + 0x58))[0] = *(u64 *)(src + step * 3 + 8);
        ((u64 *)(dst + 0x20))[0] = *(u64 *)(src + step * 4);
        ((u64 *)(dst + 0x60))[0] = *(u64 *)(src + step * 4 + 8);
        ((u64 *)(dst + 0x28))[0] = *(u64 *)(src + step * 5);
        ((u64 *)(dst + 0x68))[0] = *(u64 *)(src + step * 5 + 8);
        ((u64 *)(dst + 0x30))[0] = *(u64 *)(src + step * 6);
        ((u64 *)(dst + 0x70))[0] = *(u64 *)(src + step * 6 + 8);
        ((u64 *)(dst + 0x38))[0] = *(u64 *)(src + step * 7);
        ((u64 *)(dst + 0x78))[0] = *(u64 *)(src + step * 7 + 8);
        ((u64 *)(dst + 0x80))[0] = *(u64 *)(src + step * 8);
        ((u64 *)(dst + 0xC0))[0] = *(u64 *)(src + step * 8 + 8);
        ((u64 *)(dst + 0x88))[0] = *(u64 *)(src + step * 9);
        ((u64 *)(dst + 0xC8))[0] = *(u64 *)(src + step * 9 + 8);
        ((u64 *)(dst + 0x90))[0] = *(u64 *)(src + step * 10);
        ((u64 *)(dst + 0xD0))[0] = *(u64 *)(src + step * 10 + 8);
        ((u64 *)(dst + 0x98))[0] = *(u64 *)(src + step * 11);
        ((u64 *)(dst + 0xD8))[0] = *(u64 *)(src + step * 11 + 8);
        ((u64 *)(dst + 0xA0))[0] = *(u64 *)(src + step * 12);
        ((u64 *)(dst + 0xE0))[0] = *(u64 *)(src + step * 12 + 8);
        ((u64 *)(dst + 0xA8))[0] = *(u64 *)(src + step * 13);
        ((u64 *)(dst + 0xE8))[0] = *(u64 *)(src + step * 13 + 8);
        ((u64 *)(dst + 0xB0))[0] = *(u64 *)(src + step * 14);
        ((u64 *)(dst + 0xF0))[0] = *(u64 *)(src + step * 14 + 8);
        ((u64 *)(dst + 0xB8))[0] = *(u64 *)(src + step * 15);
        ((u64 *)(dst + 0xF8))[0] = *(u64 *)(src + step * 15 + 8);
        break;
    }
    case 4: {
        u32 i;
        for (i = 0; i < 16; i++) {
            u8 *s = src + (stride & ~3u) * i;
            u8 *d = dst + (i < 8 ? i * 8 : 0x80 + (i - 8) * 8);
            ((u32 *)d)[0] = ((u32 *)s)[0];
            ((u32 *)d)[1] = ((u32 *)s)[1];
            ((u32 *)(d + 0x40))[0] = ((u32 *)s)[2];
            ((u32 *)(d + 0x40))[1] = ((u32 *)s)[3];
        }
        break;
    }
    case 2:
    case 6: {
        u32 i;
        for (i = 0; i < 16; i++) {
            u8 *s = src + (stride & ~1u) * i;
            u8 *d = dst + (i < 8 ? i * 8 : 0x80 + (i - 8) * 8);
            ((u32 *)d)[0] = ((u32 *)s)[0];
            ((u32 *)d)[1] = ((u32 *)s)[1];
            ((u32 *)(d + 0x40))[0] = ((u32 *)s)[2];
            ((u32 *)(d + 0x40))[1] = ((u32 *)s)[3];
        }
        break;
    }
    case 1:
    case 5:
    case 3: {
        u32 i;
        for (i = 0; i < 16; i++) {
            u8 *s = src + stride * i;
            u8 *d = dst + (i < 8 ? i * 8 : 0x80 + (i - 8) * 8);
            ((u32 *)d)[0] = ((u32 *)s)[0];
            ((u32 *)d)[1] = ((u32 *)s)[1];
            ((u32 *)(d + 0x40))[0] = ((u32 *)s)[2];
            ((u32 *)(d + 0x40))[1] = ((u32 *)s)[3];
        }
        break;
    }
    }
}
