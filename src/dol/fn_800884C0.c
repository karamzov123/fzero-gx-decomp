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
