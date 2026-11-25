#include "types.h"


/* --- dol/strstr.c --- */
u8 *strstr(u8 *str, const u8 *needle) {
    u8 *p = str - 1;
    u8 ch;
    u32 c;

    if (needle == 0) {
        return str;
    }
    c = *needle;
    if (c == 0) {
        return str;
    }

    while ((ch = *++p) != 0) {
        if (ch == c) {
            u32 c1;
            u32 c2;
            u8 *s = p - 1;
            const u8 *n = needle - 1;

            do {
                c1 = *++s;
                c2 = *++n;
                if (c1 != c2) {
                    break;
                }
            } while (c1 != 0);

            if (c2 == 0) {
                return p;
            }
        }
    }

    return 0;
}

/* --- dol/strtok.c --- */
char *strtok(char *string, const char *delimiters);

extern char *lbl_801A6640;

extern char *lbl_801A6644;

char *strtok(char *string, const char *delimiters) {
    unsigned char delimiter_map[32] = {0};
    unsigned char *scan;
    unsigned char *token;
    unsigned long value;

    if (string != 0)
        lbl_801A6644 = string;

    scan = (unsigned char *)delimiters - 1;
    while ((s32)(value = *++scan) != 0) {
        delimiter_map[(value >> 3) & 0x1FU] |= 1U << (value & 7);
    }

    scan = (unsigned char *)lbl_801A6644 - 1;
    while ((s32)(value = *++scan) != 0) {
        if ((delimiter_map[(value >> 3) & 0x1FU] & (1U << (value & 7))) == 0)
            break;
    }

    if ((s32)value == 0) {
        lbl_801A6644 = lbl_801A6640;
        return 0;
    }

    token = scan;
    while ((s32)(value = *++scan) != 0) {
        if ((delimiter_map[(value >> 3) & 0x1FU] & (1U << (value & 7))) != 0)
            break;
    }

    if ((s32)value == 0) {
        lbl_801A6644 = lbl_801A6640;
        return (char *)token;
    }
    lbl_801A6644 = (char *)scan + 1;
    *scan = 0;
    return (char *)token;
}
