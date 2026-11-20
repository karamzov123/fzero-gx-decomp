#include "types.h"


/* --- rel/movie_module/fn_12_A9C0.c --- */
// fn_12_A9C0: empty in retail (single blr).
void fn_12_A9C0(void) {
}

/* --- rel/movie_module/fn_12_A9C4.c --- */
extern int fn_12_CAB4(void *movie, void *out_a, void *out_b);
extern int fn_12_A660(int arg0, u32 arg1);

int fn_12_A9C4(void *movie, void *out_a, void *out_b) {
    if (fn_12_CAB4(movie, out_a, out_b)) {
        return fn_12_A660(0, 0xff03020e);
    }

    *(u32 *)out_a = *(u32 *)((u8 *)movie + 0x284);
    *(u32 *)out_b = *(u32 *)((u8 *)movie + 0x288);
    return 0;
}

/* --- rel/movie_module/fn_12_AA38.c --- */
int fn_12_AA38(void *movie, void *out_a, void *out_b, void *out_c) {
    s32 scale;

    if (fn_12_CAB4(movie, out_a, out_b)) {
        return fn_12_A660(0, 0xff03020f);
    }

    *(u32 *)out_a = *(u32 *)((u8 *)movie + 0x27c) << 11;
    *(u32 *)out_b = *(u32 *)((u8 *)movie + 0x28c);
    scale = *(s32 *)((u8 *)movie + 0x278);

    if (scale == 0x3FFFF) {
        *(u32 *)out_c = -1;
    } else {
        *(s32 *)out_c =
            (*(s32 *)((u8 *)movie + 0x28c) * scale) / 1800;
    }

    return 0;
}
