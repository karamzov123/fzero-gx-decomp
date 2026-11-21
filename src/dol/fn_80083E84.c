#include "types.h"


/* --- dol/fn_80083BCC.c --- */
int fn_80083BCC(const char *s1, const char *s2);

/* --- dol/fn_80083CF4.c --- */
/* --- dol/fn_80083CF4.c --- */
char *fn_80083CF4(char *dest, const char *src, size_t n);

/* --- dol/strcat.c --- */
char *strcat(char *dest, const char *src);

/* --- dol/strncpy.c --- */
char *strncpy(char *dst, const char *src, size_t n);

/* --- dol/fn_80083DB0.c --- */
char *fn_80083DB0(char *dst, const char *src);

/* --- dol/strlen.c --- */
size_t strlen(const char *str);

/* --- dol/fn_80083E84.c --- */
extern f64 lbl_801A6650[];
extern f64 lbl_801A6658[];
extern f64 lbl_801A74F8;
extern f64 fn_80083F10(u32, u32, void *, void *, void *);
extern u32 lbl_801A6DE0[2];
extern void fn_800829EC(void);

void fn_80083E84(u32 arg0) {
    struct {
        u32 a[2];
    } loc_10;
    u32 loc_C;
    u32 loc_8;
    f64 value;
    f64 abs_value;

    loc_10.a[0] = arg0;
    loc_10.a[1] = 0;
    value = fn_80083F10((0x80000000 - 1), (u32)fn_800829EC, &loc_10, &loc_8, &loc_C);
    abs_value = __fabs(value);
    if ((s32)loc_C != 0 || (lbl_801A74F8 != value && (abs_value < lbl_801A6650[0] || abs_value > lbl_801A6658[0]))) {
        lbl_801A6DE0[0] = 34;
    }
}
