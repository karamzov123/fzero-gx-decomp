#include "types.h"


/* --- rel/movie_module/fn_12_4D4.c --- */
extern char lbl_12_rodata_3C[2];
extern char lbl_12_rodata_40[9];
extern s32 fn_8008023C(u32, const char *, s32);

void fn_12_4D4(u32 movie, s32 count, u32 *result, u32 *duration) {
    s32 i;
    u32 p;

    p = movie;
    *result = 0;
    *duration = 0;
    if (movie == 0 || count <= 0) {
        return;
    }
    i = 0;
    while (i < count) {
        if (fn_8008023C(p, lbl_12_rodata_3C, 1) == 0 &&
            fn_8008023C(p, lbl_12_rodata_40, 8) == 0) {
            *result = p;
            *duration = (*result == 0) ? 0 : 20;
        }
        p++;
        i++;
    }
}

/* --- rel/movie_module/fn_12_59C.c --- */
extern char lbl_12_rodata_38[2];
extern s32 strncmp(void *movie, char *name, s32 value);

s32 fn_12_59C(void *movie, s32 index) {
    if (movie == 0 || index < 0) {
        return 0;
    }
    return strncmp((char *)movie + 0x13, lbl_12_rodata_38, 1) == 0;
}
