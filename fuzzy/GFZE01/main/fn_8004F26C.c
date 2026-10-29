/* Non-matching: best partial attempt (88.12% in the project ledger). Scored for the
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
 * mixed to mono at 7/10 and written to both outputs. */
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_common_subs off
static inline const s32 fn_8004F26C_array_read(const s32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
s32 fn_8004F26C(s8 *arg0, s32 arg1, struct Out *arg2, struct Coef *arg3, struct Out *arg4,
                struct Coef *arg5, s32 arg6, s32 arg7, struct Acc *arg8, s16 arg9, s16 arg10) {
    s32 y0;
    s32 y1;
    s32 b1;
    s32 j;
    s16 v0;
    s16 v1;
    s16 v1_2;
    s8 b0;
    s32 i;
    s32 hi0;
    s32 hi1;
    s32 x1_2;
    s32 x0;
    s32 t1;

    x0 = arg3->a;
    y0 = arg3->b;
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
        v1_2 = (s16)(1 + ((v1_2 ^ arg8->v) & 0x1FFF));
        arg8->v = (s16)(arg8->v * arg9 + arg10);
        arg8->v = (s16)(0x7FFF & arg8->v);
        arg0 += 2;
        for (j = 0; j < 16; j++) {
            b0 = arg0[0];
            b1 = arg0[0x12];
            arg0++;
            hi0 = ((arg6 * x0 + arg7 * y0) >> 12) + (b0 >> 4) * v0;
            CLAMP16(hi0)
            hi1 = ((arg6 * (arg5->a) + arg7 * y1) >> 12) + (b1 >> 4) * v1_2;
            CLAMP16(hi1)
            y1 = hi1;
{
    s32 m;
            m = (hi0 + hi1) * 7 / 10;
            CLAMP16(m)
            arg4->lo = m;
            arg2->lo = m;
            t1 = fn_8004F26C_array_read(lbl_800911E0, b1 & 0xF);
            y0 = hi0;
            x0 = (fn_8004F26C_array_read(lbl_800911E0, b0 & 0xF)) * v0 + ((arg6 * hi0 + arg7 * x0) >> 12);
            CLAMP16(x0)
            x1_2 = t1 * v1_2 + ((arg6 * y1 + arg7 * x1_2) >> 12);
            CLAMP16(x1_2)
            m = (x0 + x1_2) * 7 / 10;
            CLAMP16(m)
            arg4->lo = m;
            arg4++;
            arg2->lo = m;
}
            arg2++;
        }
        arg0 += 0x12;
    }
    arg3->a = x0;
    arg3->b = y0;
    arg5->a = x1_2;
    arg5->b = y1;
    return arg1;
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset
