#include "types.h"


/* --- dol/fn_800884C0.c --- */
extern f64 lbl_801A78F8;
extern f64 fn_80087C44(u32, f64, f64);
extern u32 __ieee754_rem_pio2(f64, f64 *);

f64 fn_800884C0(f64 value) {
    f64 temp[2];
    s32 bits;
    u32 sign;

    bits = *(s32 *)&value;
    bits = bits & 0x7fffffff;
    if (bits <= 0x3fe921fb) {
        return fn_80087C44(1, value, lbl_801A78F8);
    }
    if (bits >= 0x7ff00000) {
        return value - value;
    }
    sign = __ieee754_rem_pio2(value, temp);
    sign = (sign & 1) << 1;
    return fn_80087C44(1 - sign, temp[0], temp[1]);
}

/* --- dol/fn_80088538.c --- */
extern u32 fn_8008596C(void);

void fn_80088538(void) {
    fn_8008596C();
}

/* --- dol/fn_80088558.c --- */
extern u32 __ieee754_log(void);

void fn_80088558(void) {
    __ieee754_log();
}

/* --- dol/fn_80088578.c --- */
extern u32 __ieee754_log10(void);

void fn_80088578(void) {
    __ieee754_log10();
}

/* --- dol/fn_80088598.c --- */
extern u32 fn_80086008(void);

void fn_80088598(void) {
    fn_80086008();
}
