#include "types.h"

struct Out {
    u16 hi;
    u16 lo;
};

struct Coef {
    s16 a;
    s16 b;
};

struct Acc {
    s16 v;
};

extern const s32 lbl_800911E0[16];

s32 fn_8004F55C(s8 *arg0, s32 arg1, struct Out *arg2, struct Coef *arg3,
               s16 arg4, s16 arg5, struct Acc *arg6, s16 arg7, s16 arg8) {
    struct Out *o;
    s8 b;
    s32 y;
    s32 t;
    s32 j;
    s32 x;
    s32 i;
    s16 v;

    o = arg2;
    x = arg3->a;
    y = arg3->b;

    for (i = 0; i < arg1; i++) {
        v = *(s16 *)arg0;
        if (v & 0x8000) {
            return i;
        }
        v = (s16)(1 + ((v ^ arg6->v) & 0x1FFF));
        arg6->v = (s16)(arg6->v * arg7 + arg8);
        arg6->v = (s16)(0x7FFF & arg6->v);
        arg0 += 2;
        for (j = 0; j < 16; j++) {
            b = *arg0++;
            {
                s32 hi;
                hi = ((arg4 * x + arg5 * y) >> 12) + (b >> 4) * v;
                if (hi > 32767 || hi < -32768) {
                    if (hi < -32768) {
                        hi = -32768;
                    } else if (hi > 32767) {
                        hi = 32767;
                    }
                }
                t = lbl_800911E0[b & 0xF];
                o->hi = hi;
                x = t * v + ((arg4 * hi + arg5 * x) >> 12);
                if (x > 32767 || x < -32768) {
                    if (x < -32768) {
                        x = -32768;
                    } else if (x > 32767) {
                        x = 32767;
                    }
                }
                o->lo = x;
                y = hi;
                o++;
            }
        }
    }
    arg3->a = x;
    arg3->b = y;
    return arg1;
}
