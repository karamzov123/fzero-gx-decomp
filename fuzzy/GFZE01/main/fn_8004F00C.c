/* Non-matching: best partial attempt (87.29% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
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

#define CLAMP16(v)                     \
    if (v > 32767 || v < -32768) {     \
        if (v < -32768) {              \
            v = -32768;                \
        } else if (v > 32767) {        \
            v = 32767;                 \
        }                              \
    }

/* Stereo ADPCM frame pairs (left block then right block, 0x12 bytes each),
 * left decoded to arg2 and right to arg4. */
#pragma opt_loop_invariants on
#pragma opt_lifetimes off
s32 fn_8004F00C(s8 *arg0, s32 arg1, struct Out *arg2, struct Coef *arg3, struct Out *arg4,
                struct Coef *arg5, s16 arg6, s16 arg7, struct Acc *arg8, s16 arg9, s16 arg10) {
    s32 t1;
    s32 t0;
    s32 hi1;
    s32 hi0;
    s8 b1;
    s8 b0;
    s16 v1;
    s16 v0;
    s32 j;
    s32 i;
    s32 y1;
    s32 x1;
    s32 y0;
    s32 x0;

    x0 = arg3->a;
    y0 = arg3->b;
    x1 = arg5->a;
    y1 = arg5->b;

    for (i = 0; i < arg1 / 2; i++) {
        v0 = *(s16 *)arg0;
        if (v0 & 0x8000) {
            return i * 2;
        }
        v0 = (s16)(1 + ((v0 ^ arg8->v) & 0x1FFF));
        arg8->v = (s16)(arg8->v * arg9 + arg10);
        arg8->v = (s16)(0x7FFF & arg8->v);
        v1 = *(s16 *)(arg0 + 0x12);
        if (v1 & 0x8000) {
            return i * 2;
        }
        v1 = (s16)(1 + ((v1 ^ arg8->v) & 0x1FFF));
        arg8->v = (s16)(arg8->v * arg9 + arg10);
        arg8->v = (s16)(0x7FFF & arg8->v);
        arg0 += 2;
        for (j = 0; j < 16; j++) {
            b0 = arg0[0];
            b1 = arg0[0x12];
            arg0++;
            hi0 = ((arg6 * x0 + arg7 * y0) >> 12) + (b0 >> 4) * v0;
            CLAMP16(hi0)
            hi1 = ((arg6 * x1 + arg7 * y1) >> 12) + (b1 >> 4) * v1;
            CLAMP16(hi1)
            y1 = hi1;
            arg2->hi = hi0;
            arg4->hi = hi1;
            t0 = lbl_800911E0[b0 & 0xF];
            t1 = lbl_800911E0[b1 & 0xF];
            y0 = hi0;
            x0 = t0 * v0 + ((arg6 * hi0 + arg7 * x0) >> 12);
            CLAMP16(x0)
            x1 = t1 * v1 + ((arg6 * y1 + arg7 * x1) >> 12);
            CLAMP16(x1)
            arg2->lo = x0;
            arg2++;
            arg4->lo = x1;
            arg4++;
        }
        arg0 += 0x12;
    }
    arg3->a = x0;
    arg3->b = y0;
    arg5->a = x1;
    arg5->b = y1;
    return arg1;
}
#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset
