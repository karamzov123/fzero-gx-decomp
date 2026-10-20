#include "types.h"

extern u32 lbl_8017B028[];
extern s32 fn_8004F00C(const s8 *a, s32 b, s16 *c, s16 *d, s16 *e, s16 *f, s16 g, s16 h, s16 *i, s16 j, s16 k);
extern s32 fn_8004F26C(const s8 *a, s32 b, s16 *c, s16 *d, s16 *e, s16 *f, s16 g, s16 h, s16 *i, s16 j, s16 k);

s32 fn_8004EFA8(const s8 *a, s32 b, s16 *c, s16 *d, s16 *e, s16 *f, s16 g, s16 h, s16 *i, s16 j, s16 k) {
    if ((s32)lbl_8017B028[0] == 0) {
        return fn_8004F00C(a, b, c, d, e, f, g, h, i, j, k);
    } else {
        return fn_8004F26C(a, b, c, d, e, f, g, h, i, j, k);
    }
}
