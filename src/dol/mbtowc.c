#include "types.h"


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
