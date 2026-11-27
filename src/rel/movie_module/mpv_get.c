#include "types.h"
#include "sofdec/mpv.h"

/* fzgx:begin fn_12_A9C4 noprologue */
#include "types.h"

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
/* fzgx:end fn_12_A9C4 */

/* fzgx:begin fn_12_AA38 noprologue */

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
/* fzgx:end fn_12_AA38 */

/* fzgx:begin fn_12_AB00 noprologue */
#include "types.h"

typedef struct MovieObject {
    u8 pad_0[0x278];
    u32 value_278;
} MovieObject;

extern s32 fn_12_CAB4(MovieObject *movie, u32 *out);
extern s32 fn_12_A660(u32 arg0, u32 arg1);

s32 fn_12_AB00(MovieObject *movie, u32 *out) {
    if (fn_12_CAB4(movie, out)) {
        return fn_12_A660(0, 0xff03020d);
    }
    *out = movie->value_278;
    return 0;
}
/* fzgx:end fn_12_AB00 */

/* fzgx:begin fn_12_AB60 noprologue */
#include "types.h"
#include "sofdec/mpv.h"
#pragma opt_propagation off

/* --- rel/movie_module/fn_12_AB60.c --- */
extern u32 fn_12_A660(u32, u32);
extern u32 fn_12_CAB4(u32, u32);

struct fn_12_AB60_Copy80 { u32 a[20]; };

s32 fn_12_AB60(u32 arg0, u32 arg1) {
    u32 v0;
    u32 t0, t1;
    t0 = fn_12_CAB4(arg0, arg1);
    v0 = t0;
    if ((s32)t0 != 0) {
    v0 = 0;
    t1 = fn_12_A660(v0, (0xFF030000 + 524));
    v0 = t1;
    } else {
    *(struct fn_12_AB60_Copy80 *)arg1 = *(struct fn_12_AB60_Copy80 *)((u8 *)arg0 + 464);
    v0 = 0;
    }
    return v0;
}
/* fzgx:end fn_12_AB60 */
