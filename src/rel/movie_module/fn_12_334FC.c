#include "types.h"


/* --- rel/movie_module/fn_12_334FC.c --- */
extern const f64 lbl_12_rodata_1110;
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

/* --- rel/movie_module/fn_12_335A4.c --- */
extern u32 lbl_12_bss_1B778[2];

u64 fn_12_335A4(void) {
    return *(u64 *)lbl_12_bss_1B778;
}
