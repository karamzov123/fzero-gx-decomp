#include "types.h"


/* --- dol/memmove.c --- */
extern void __copy_longs_unaligned(void *destination, const void *source, size_t count);

extern void __copy_longs_rev_unaligned(void *destination, const void *source, size_t count);

extern void fn_800805C0(void *destination, const void *source, size_t count);

extern void fn_80080518(void *destination, const void *source, size_t count);

void *memmove(void *destination, const void *source, size_t count) {
    unsigned char *source_byte;
    unsigned char *destination_byte;
    int reverse = (unsigned int)source < (unsigned int)destination;
    if (count >= 32) {
        if (((unsigned int)destination ^ (unsigned int)source) & 3) {
            if (!reverse)
                __copy_longs_unaligned(destination, source, count);
            else
                __copy_longs_rev_unaligned(destination, source, count);
        } else if (!reverse) {
            fn_800805C0(destination, source, count);
        } else {
            fn_80080518(destination, source, count);
        }
        return destination;
    }
    if (!reverse) {
        source_byte = (unsigned char *)source - 1;
        destination_byte = (unsigned char *)destination - 1;
        ++count;
        while (--count > 0)
            *++destination_byte = *++source_byte;
    } else {
        source_byte = (unsigned char *)source + count;
        destination_byte = (unsigned char *)destination + count;
        ++count;
        while (--count > 0)
            *--destination_byte = *--source_byte;
    }
    return destination;
}

/* --- dol/__copy_longs_rev_unaligned.c --- */
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

/* --- dol/__copy_longs_unaligned.c --- */
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
