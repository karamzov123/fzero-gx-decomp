#include "types.h"


/* --- dol/fn_80083BCC.c --- */
int fn_80083BCC(const char *s1, const char *s2) {
    const u8 *left = (const u8 *)s1;
    const u8 *right = (const u8 *)s2;
    u32 align;
    u32 n;
    u32 lb = *left;
    u32 rb = *right;
    u32 lw;
    u32 rw;
    s32 diff = (lb - rb);

    if (diff != 0)
        return diff;

    if (((u32)right & 3) != (align = (u32)left & 3))
        goto byte_loop; /* Keep the verified branch to byte_loop. */

    if (align != 0) {
        if (lb == 0)
            return 0;
        for (n = 3 - align; n != 0; --n) {
            lb = *++left;
            rb = *++right;
            diff = (lb - rb);
            if (diff != 0)
                return diff;
            if (lb == 0)
                return 0;
        }
        ++left;
        ++right;
    }

    lw = *(const u32 *)left;
    rw = *(const u32 *)right;
    if (((lw - 0x01010101U) & 0x80808080U) != 0)
        goto byte_cmp; /* Keep the verified branch to byte_cmp. */

    /* Word loop: equality is tested at the bottom; a zero byte found in the
       advanced word jumps out to the byte comparison. */
    while (lw == rw) {
        lw = *(const u32 *)(left += 4);
        rw = *(const u32 *)(right += 4);
        if (((lw - 0x01010101U) & 0x80808080U) != 0)
            goto byte_cmp; /* Keep the verified branch to byte_cmp. */
    }
    return lw > rw ? 1 : -1;

byte_cmp:
    lb = *left;
    rb = *right;
    diff = (lb - rb);
    if (diff != 0)
        return diff;

byte_loop:
    if (lb == 0)
        return 0;
    do {
        lb = *++left;
        diff = (lb - *++right);
        if (diff != 0)
            return diff;
    } while (lb != 0);
    return 0;
}

/* --- dol/fn_80083CF4.c --- */
/* --- dol/fn_80083CF4.c --- */
char *fn_80083CF4(char *dest, const char *src, size_t n) {
    const u8 *s = (const u8 *)src - 1;
    u8 *d = (u8 *)dest - 1;
    u8 c;

    while (*++d != 0) {
    }
    --d;
    ++n;
    while (--n != 0) {
        c = *++s;
        *++d = c;
        if (c == 0) {
            --d;
            break;
        }
    }
    *++d = 0;
    return dest;
}

/* --- dol/strcat.c --- */
char *strcat(char *dest, const char *src) {
    const unsigned char *s = (const unsigned char *)src - 1;
    unsigned char *d = (unsigned char *)dest - 1;

    while (*++d != 0) {
    }
    --d;
    while ((*++d = *++s) != 0) {
    }
    return dest;
}

/* --- dol/strncpy.c --- */
char *strncpy(char *dst, const char *src, size_t n) {
    const unsigned char *s = (const unsigned char *)src - 1;
    unsigned char *d = (unsigned char *)dst - 1;
    n++;

    while (--n != 0) {
        if ((*++d = *++s) == 0) {
            while (--n != 0) {
                *++d = 0;
            }
            return dst;
        }
    }

    return dst;
}

/* --- dol/fn_80083DB0.c --- */
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

/* --- dol/strlen.c --- */
size_t strlen(const char *str) {
    const unsigned char *p = (const unsigned char *)str - 1;
    size_t len = (size_t)-1;

    do {
        len++;
    } while (*++p != 0);

    return len;
}
