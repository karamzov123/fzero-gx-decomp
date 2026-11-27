#include "types.h"

/* fzgx:begin fn_12_4D4 noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_4D4.c --- */
extern char lbl_12_rodata_3C[2];
extern char lbl_12_rodata_40[9];
extern s32 memcmp(u32, const char *, s32);

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
        if (memcmp(p, lbl_12_rodata_3C, 1) == 0 &&
            memcmp(p, lbl_12_rodata_40, 8) == 0) {
            *result = p;
            *duration = (*result == 0) ? 0 : 20;
        }
        p++;
        i++;
    }
}
/* fzgx:end fn_12_4D4 */

/* fzgx:begin fn_12_59C noprologue */

/* --- rel/movie_module/fn_12_59C.c --- */
extern char lbl_12_rodata_38[2];
extern s32 strncmp(void *movie, char *name, s32 value);

s32 fn_12_59C(void *movie, s32 index) {
    if (movie == 0 || index < 0) {
        return 0;
    }
    return strncmp((char *)movie + 0x13, lbl_12_rodata_38, 1) == 0;
}
/* fzgx:end fn_12_59C */

/* fzgx:begin fn_12_5EC noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_5EC.c --- */
/* --- rel/movie_module/fn_12_5EC.c --- */
/* --- rel/movie_module/fn_12_5EC.c --- */
extern u32 lbl_12_rodata_34;
extern u32 strncmp(u32, u32, u32);

u32 fn_12_5EC(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg0 == 0 || (s32)arg1 < 0) {
    v0 = 0;
    } else {
    v0 += 18;
    t0 = strncmp(v0, (u32)&lbl_12_rodata_34, 1);
    v0 = t0;
    v0 = ((u32)__cntlzw(v0) >> 5);
    }
    return v0;
}
/* fzgx:end fn_12_5EC */

/* fzgx:begin fn_12_63C noprologue */

/* --- rel/movie_module/fn_12_63C.c --- */
extern s32 lbl_12_bss_0;

void fn_12_63C(void) {
    if (lbl_12_bss_0 > 0) {
        lbl_12_bss_0--;
    }
}
/* fzgx:end fn_12_63C */

/* fzgx:begin fn_12_65C noprologue */

/* --- rel/movie_module/fn_12_65C.c --- */
extern char lbl_12_rodata_0[49];
extern u32 lbl_12_bss_4;

void fn_12_65C(void) {
    if (lbl_12_bss_0 < 1) {
        lbl_12_bss_4 = (u32)&lbl_12_rodata_0;
        lbl_12_bss_0 = lbl_12_bss_0 + 1;
    }
}
/* fzgx:end fn_12_65C */
