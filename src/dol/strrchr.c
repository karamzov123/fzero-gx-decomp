#include "types.h"


/* --- dol/fn_80083970.c --- */
u8 *fn_80083970(u8 *str, const u8 *needle);

/* --- dol/fn_800839D8.c --- */
char *fn_800839D8(char *string, const char *delimiters);

extern char *lbl_801A6640;

extern char *lbl_801A6644;

char *fn_800839D8(char *string, const char *delimiters);

/* --- dol/strrchr.c --- */
/* --- dol/strrchr.c --- */
char *strrchr(const char *str, int c) {
    const unsigned char *p = (const unsigned char *)str - 1;
    u32 target = (u8)c;
    char *last = 0;
    u32 ch;

    while ((ch = *++p) != 0) {
        if (ch == target) {
            last = (char *)p;
        }
    }

    if (last != 0) {
        return last;
    }
    if (target != 0) {
        return 0;
    }
    return (char *)p;
}

/* --- dol/strchr.c --- */
char *strchr(const char *str, int c) {
    const unsigned char *p = (const unsigned char *)str - 1;
    u32 target = (u8)c;
    u32 ch;

    while ((ch = *++p) != 0) {
        if (ch == target) {
            return (char *)p;
        }
    }
    if (target == 0) {
        return (char *)p;
    }
    return 0;
}
