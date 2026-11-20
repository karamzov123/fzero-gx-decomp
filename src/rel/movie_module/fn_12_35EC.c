#include "types.h"


/* --- rel/movie_module/fn_12_35EC.c --- */
// fn_12_35EC: empty in retail (single blr).
void fn_12_35EC(void) {
}

/* --- rel/movie_module/fn_12_35F0.c --- */
extern u32 lbl_12_bss_4C0[42];
extern void *memset(void *dest, int value, u32 size);

void fn_12_35F0(void) {
    memset(lbl_12_bss_4C0, 0, 0xa8);
    lbl_12_bss_4C0[1] = 8;
}

/* --- rel/movie_module/fn_12_3630.c --- */
typedef struct MovieData {
    u8 _pad0[0x3c];
    f32 value0;
    f32 value1;
} MovieData;

extern const f32 lbl_12_rodata_4E8;

s32 fn_12_3630(const MovieData *movie) {
    f32 value0 = movie->value0;
    f32 value1 = movie->value1;
    s32 result = 1;

    if (lbl_12_rodata_4E8 == value0 && lbl_12_rodata_4E8 == value1) {
        result = 0;
    }
    return result;
}

/* --- rel/movie_module/fn_12_365C.c --- */
void fn_12_365C(const MovieData *movie, f32 *out0, f32 *out1) {
    *out0 = movie->value0;
    *out1 = movie->value1;
}

/* --- rel/movie_module/fn_12_3670.c --- */
extern f32 lbl_12_rodata_4EC;
extern u32 lbl_12_rodata_4F0;
extern void fn_12_309C(u32, u32, u32);


void fn_12_3670(void *arg0, f32 farg0, f32 farg1) {
    s32 var_r0;

    var_r0 = 1;
    if (farg1 <= farg0) {
        var_r0 = 0;
    }
    if ((farg1 - farg0) < (*(f32 *)((u8 *)(&lbl_12_rodata_4EC) + 0))) {
        var_r0 = 0;
    }
    if (var_r0 != 1) {
        fn_12_309C(0U, 0U, (u32)(&lbl_12_rodata_4F0));
    }
    (*(f32 *)((u8 *)(arg0) + 60)) = farg0;
    (*(f32 *)((u8 *)(arg0) + 64)) = farg1;
}
