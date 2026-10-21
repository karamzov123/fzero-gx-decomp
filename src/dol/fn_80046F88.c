#include "types.h"

/* ADXERR_ItoA2, from the CC0 MK Deception decomp (adx_errs.c) */

extern unsigned long strlen(const char *string);
extern char *fn_80083CF4(char *destination, const char *source, unsigned long size);
extern signed char lbl_8017B038[32];

static inline void adxerr_itoa(int value, signed char* string, int length)
{
    int i;
    int n;
    int l;

    for (i = 0; i < 32; i++) {
        string[i] = value % 10;
        value /= 10;
        if (value == 0) {
            string[i] = '\0';
            break;
        }
    }

    l = strlen((const char*)lbl_8017B038);
    n = length - 1;
    if (l < n) {
        n = l;
    }
    for (i = 0; i < n; i++) {
        string[i] = lbl_8017B038[n - 1 - i];
    }
    string[i] = '\0';
}

void fn_80046F88(int value1, int value2, signed char* string, int length)
{
    adxerr_itoa(value1, string, length);
    fn_80083CF4((char*)string, " ", length - strlen((const char*)string) - 1);
    adxerr_itoa(value2, string + strlen((const char*)string),
                4 - strlen((const char*)string));
}

