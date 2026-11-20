#include "types.h"


/* --- dol/mbtowc.c --- */
/* --- dol/mbtowc.c --- */
typedef unsigned short wchar_t;

int is_utf8_complete(const char *s, size_t n);

static inline int mbstowcs_one(wchar_t *pwc, const char *s, size_t n) {
    unsigned int result_chr;
    int number_of_bytes = 0;
    int is_utf8;
    char *source;
    if (!s) {
        number_of_bytes = 0;
        return number_of_bytes;
    }
    if (n <= 0) {
        number_of_bytes = -1;
        return number_of_bytes;
    }
    is_utf8 = is_utf8_complete(s, n);
    if (is_utf8 < 0) {
        number_of_bytes = -1;
        return number_of_bytes;
    }
    source = (char *)s;
    switch (is_utf8) {
    case 3:
        result_chr = *source & 0x1f;
        source++;
        number_of_bytes = (result_chr << 6) & 0x3c0;
    case 2:
        result_chr = number_of_bytes | (*source & 0x3f);
        source++;
        number_of_bytes = (result_chr << 6) & 0xffc0;
    case 1:
        result_chr = number_of_bytes | (*source & 0x7f);
        source++;
        number_of_bytes = result_chr & 0xffff;
    }
    result_chr = number_of_bytes & 0xffff;
    if (!result_chr)
        result_chr = 0;
    else if (result_chr < 0x80)
        result_chr = 1;
    else if (result_chr < 0x800)
        result_chr = 2;
    else
        result_chr = 3;
    if ((int)result_chr != is_utf8) {
        number_of_bytes = -1;
        return number_of_bytes;
    }
    if (pwc)
        *pwc = number_of_bytes;
    return is_utf8;
}

int mbtowc(wchar_t *pwc, const char *s, size_t n) { return mbstowcs_one(pwc, s, n); }

/* --- dol/is_utf8_complete.c --- */
int is_utf8_complete(const char *s, size_t n) {
    if (n == 0)
        return -1;
    if (s[0] == 0)
        return 0;
    if ((s[0] & 0x80) == 0)
        return 1;
    if ((s[0] & 0xe0) == 0xc0) {
        if (n >= 2) {
            if ((s[1] & 0x80) == 0x80)
                return 2;
            return -1;
        }
        return -2;
    } else if ((s[0] & 0xf0) == 0xe0) {
        if (n >= 3) {
            if ((s[1] & 0x80) == 0x80) {
                if ((s[2] & 0x80) == 0x80)
                    return 3;
            }
            return -1;
        } else if ((n == 2 && (s[1] & 0x80) == 0x80) || n == 1) {
            return -2;
        }
        return -1;
    }
    return -1;
}

/* --- dol/fn_8008023C.c --- */
/* --- dol/fn_8008023C.c --- */
s32 fn_8008023C(u32 arg0, u32 arg1, u32 arg2) {
    u8 *v0;
    u8 *v1;
    u32 v2;

    v0 = (u8 *)arg0 - 1;
    v1 = (u8 *)arg1 - 1;
    v2 = arg2 + 1;
    /* Loop enters at the bottom test in the retail control flow. */
    goto test;
loop:
    if (*++v0 != *++v1) {
        if (*v0 < *v1) {
            return -1;
        }
        return 1;
    }
test:
    if (--v2 != 0) {
        /* Loop back to the body after the retail bottom-test branch. */
        goto loop;
    }
    return 0;
}

/* --- dol/__memrchr.c --- */
s32 __memrchr(u32 arg0, u32 arg1, u32 arg2) {
    u32 v1;

    arg1 = (u8)arg1;
    arg0 += arg2;
    arg2++;
    while (--arg2 != 0) {
        arg0--;
        if (*(u8 *)arg0 == arg1) {
            return arg0;
        }
    }
    return 0;
}

/* --- dol/memchr.c --- */
s32 memchr(u32 arg0, u32 arg1, u32 arg2) {
    u32 unk_1;
    u32 unk_2;
    u32 v2;
    arg1 &= 0xff;
    arg0 -= 1;
    arg2 += 1;
    while (((arg2) -= 1) != 0) {
        arg0 = (u32)((u8 *)arg0 + 1);
        if (*(u8 *)arg0 == arg1) {
            return arg0;
        }
    }
    return 0;
}

/* --- dol/memmove.c --- */
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
