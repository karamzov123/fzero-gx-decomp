#include "types.h"

/* --- rel/movie_module/UTY_MulDiv.c --- */
unsigned int UTY_MulDiv(int multiplicand, int multiplier, int divisor) {
    if (divisor == 0) {
        unsigned int limit = 0x80000000u;
        unsigned int sign = (unsigned int)(multiplicand ^ multiplier) >> 31;
        return sign == 0 ? limit - 1 : limit;
    }
    return (unsigned int)(((long long)multiplicand * multiplier) / divisor);
}
extern const f64 lbl_12_rodata_1108;
extern f64 floor(f64);

s32 fn_12_334FC(s32 a, s32 b, s32 c) {
    if (c == 0) {
        u32 limit = 0x80000000u;
        u32 sign = (u32)(a ^ b) >> 31;
        return sign == 0 ? limit - 1 : limit;
    }
    return (s32)floor(
        lbl_12_rodata_1108
        + (f64)a * (f64)b / (f64)c);
}
