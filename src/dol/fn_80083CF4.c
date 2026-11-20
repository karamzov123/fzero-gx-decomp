#include "types.h"


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
