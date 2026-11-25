#include "types.h"

void __copy_longs_rev_unaligned(void *dst, const void *src, size_t n);
void __copy_longs_unaligned(void *dst, const void *src, size_t n);
void __copy_longs_rev_aligned(void *dst, const void *src, size_t n);
void __copy_longs_aligned(void *arg0, const void *arg1, size_t arg2);

#pragma opt_common_subs off
#pragma opt_lifetimes off
void __copy_longs_aligned(void *arg0, const void *arg1, size_t arg2) {
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

#pragma opt_common_subs off
#pragma opt_lifetimes off
void __copy_longs_rev_aligned(void *dst, const void *src, size_t n) {
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

void __copy_longs_unaligned(void *dst, const void *src, size_t n) {
    unsigned long i, v1, v2;
    unsigned int src_offset, left_shift, right_shift;
    i = (-(unsigned long)dst) & 3;
    ((unsigned char *)src) = ((unsigned char *)src) - 1;
    ((unsigned char *)dst) = ((unsigned char *)dst) - 1;
    if (i) {
        n -= i;
        do
            *++(((unsigned char *)dst)) = *++(((unsigned char *)src));
        while (--i);
    }
    src_offset = ((unsigned int)(((unsigned char *)src) + 1)) & 3;
    left_shift = src_offset << 3;
    right_shift = 32 - left_shift;
    ((unsigned char *)src) -= src_offset;
    ((unsigned long *)src) = ((unsigned long *)(((unsigned char *)src) + 1)) - 1;
    ((unsigned long *)dst) = ((unsigned long *)(((unsigned char *)dst) + 1)) - 1;
    i = n >> 3;
    v1 = *++(((unsigned long *)src));
    do {
        v2 = *++(((unsigned long *)src));
        *++(((unsigned long *)dst)) = (v1 << left_shift) | (v2 >> right_shift);
        v1 = *++(((unsigned long *)src));
        *++(((unsigned long *)dst)) = (v2 << left_shift) | (v1 >> right_shift);
    } while (--i);
    if (n & 4) {
        v2 = *++(((unsigned long *)src));
        *++(((unsigned long *)dst)) = (v1 << left_shift) | (v2 >> right_shift);
    }
    ((unsigned char *)src) = ((unsigned char *)(((unsigned long *)src) + 1)) - 1;
    ((unsigned char *)dst) = ((unsigned char *)(((unsigned long *)dst) + 1)) - 1;
    n &= 3;
    if (n) {
        ((unsigned char *)src) -= 4 - src_offset;
        do
            *++(((unsigned char *)dst)) = *++(((unsigned char *)src));
        while (--n);
    }
    return;
}

void __copy_longs_rev_unaligned(void *dst, const void *src, size_t n) {
    unsigned long i, v1, v2;
    unsigned int src_offset, left_shift, right_shift;
    ((unsigned char *)src) = ((unsigned char *)src) + n;
    ((unsigned char *)dst) = ((unsigned char *)dst) + n;
    i = ((unsigned long)((unsigned char *)dst)) & 3;
    if (i) {
        n -= i;
        do
            *--((unsigned char *)dst) = *--((unsigned char *)src);
        while (--i);
    }
    src_offset = ((unsigned int)((unsigned char *)src)) & 3;
    left_shift = src_offset << 3;
    right_shift = 32 - left_shift;
    ((unsigned char *)src) += 4 - src_offset;
    i = n >> 3;
    v1 = *--((unsigned long *)src);
    do {
        v2 = *--((unsigned long *)src);
        *--((unsigned long *)dst) = (v2 << left_shift) | (v1 >> right_shift);
        v1 = *--((unsigned long *)src);
        *--((unsigned long *)dst) = (v1 << left_shift) | (v2 >> right_shift);
    } while (--i);
    if (n & 4) {
        v2 = *--((unsigned long *)src);
        *--((unsigned long *)dst) = (v2 << left_shift) | (v1 >> right_shift);
    }
    n &= 3;
    if (n) {
        ((unsigned char *)src) += src_offset;
        do
            *--((unsigned char *)dst) = *--((unsigned char *)src);
        while (--n);
    }
    return;
}
