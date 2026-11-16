#include "types.h"
#include "dolphin/types.h"

struct fn_8006EFB4_Arg0 {
    s16 unk_0;
    s16 unk_2;
};

extern void lbl_8006D8D8(s16, f32 *, f32);
extern void mathutil_mtxA_rotate_x(s16);

f32 fn_8006EFB4(struct fn_8006EFB4_Arg0 *arg0, f32 arg1, f32 *arg2) {
    f32 *pool;
    f32 z;
    f32 y;
    f32 x;
    f32 v;

    lbl_8006D8D8(arg0->unk_2, arg2, arg1);
    mathutil_mtxA_rotate_x(arg0->unk_0);
    pool = (f32 *)0xE0000000; /* fzgx-allow: A2 fixed float pool base */
    v = -arg1;
    x = pool[2];
    x *= v;
    y = pool[6];
    y *= v;
    z = pool[10];
    z *= v;
    arg2[0] = x;
    arg2[1] = y;
    arg2[2] = z;
    return y;
}
