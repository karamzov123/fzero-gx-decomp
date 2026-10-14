/* Non-matching: best partial attempt (97.61% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Src {
    u8 *base0;
    u8 *base1;
    u8 *base2;
} Src;

typedef struct Dst {
    u8 *base0;
    u8 *base1;
    u8 *base2;
    s16 count0;
    s16 count1;
} Dst;

typedef struct Stride {
    u32 off0;
    u32 off1;
} Stride;

#define COPY16(_z) \
    _z; \
    f0 = *(f64 *)(s + 0); \
    f1 = *(f64 *)(s + 8); \
    s += step; \
    *(f64 *)(d + 0) = f0; \
    *(f64 *)(d + 8) = f1; \
    d += step

#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
#pragma peephole off
static inline u8 * fn_12_112D4_read_pointer(Dst * owner) { return owner->base0; }
void fn_12_112D4(Stride *stride, Src *src, Dst *dst) {
    u8 * fzgx_live_____;
    u8 * fzgx_live____;
    u8 * fzgx_live___;
    u8 * fzgx_live__;
    u8 * fzgx_live_;
    u8 * fzgx_live;
    u32 off0;
    s32 n0;
    u32 stride0;
    u32 stride1;
    u8 *s;
    u8 *d;
    f64 f0;
    f64 f1;
    s32 i;
    u32 off1;
    s32 n1;
    s32 step;

    off0 = stride->off0;
    n0 = dst->count0 / 8;

    if ((off0 & 0x1F) == 0) {
        fzgx_live____ = src->base0;
        s = fzgx_live____ + off0;
        d = fn_12_112D4_read_pointer(dst) + off0;
        stride0 = n0;
        stride0 <<= 3;
        stride1 = n0;
        stride1 = stride1 << 4;
        for (i = 0; i < 4; i++) {
            __dcbz(d, 0);
            f0 = *(f64 *)(s + 0);
            __dcbz(d, stride0);
            f1 = *(f64 *)(s + stride0);
            s += stride1;
            *(f64 *)(d + 0) = f0;
            *(f64 *)(d + stride0) = f1;
            d += stride1;
        }
        s = src->base1 + stride->off0;
        fzgx_live__ = dst->base1;
        d = fzgx_live__ + stride->off0;
        for (i = 0; i < 4; i++) {
            __dcbz(d, 0);
            f0 = *(f64 *)(s + 0);
            __dcbz(d, stride0);
            f1 = *(f64 *)(s + stride0);
            s += stride1;
            *(f64 *)(d + 0) = f0;
            *(f64 *)(d + stride0) = f1;
            d += stride1;
        }
    } else {
        fzgx_live____ = src->base0;
        s = fzgx_live____ + off0;
        d = dst->base0 + off0;
        stride1 = n0 << 4;
        stride0 = n0 << 3;
        for (i = 0; i < 4; i++) {
            f0 = *(f64 *)(s + 0);
            f1 = *(f64 *)(s + stride0);
            s += stride1;
            *(f64 *)(d + 0) = f0;
            *(f64 *)(d + stride0) = f1;
            d += stride1;
        }
        s = src->base1 + stride->off0;
        fzgx_live__ = dst->base1;
        d = fzgx_live__ + stride->off0;
        for (i = 0; i < 4; i++) {
            f0 = *(f64 *)(s + 0);
            f1 = *(f64 *)(s + stride0);
            s += stride1;
            *(f64 *)(d + 0) = f0;
            *(f64 *)(d + stride0) = f1;
            d += stride1;
        }
    }

    off1 = stride->off1;
    n1 = dst->count1 / 8;

    if ((off1 & 0x1F) == 0) {
        step = n1;
        step = step << 3;
        fzgx_live___ = src->base2;
        fzgx_live_ = fzgx_live___;
        fzgx_live = fzgx_live_;
        s = fzgx_live + off1;
        fzgx_live_____ = dst->base2;
        d = fzgx_live_____ + off1;
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
        COPY16(__dcbz(d, 0));
    } else {
        off0 = n1;
        step = off0;
        step = step << 3;
        fzgx_live___ = src->base2;
        fzgx_live = fzgx_live___;
        s = fzgx_live + off1;
        fzgx_live_____ = dst->base2;
        d = fzgx_live_____ + off1;
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
        COPY16();
    }
}
#pragma peephole reset

#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset

