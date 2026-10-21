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

/* One 8x8 block row pair: two 8-byte rows a stride apart, then advance two rows. */
#define ROW2_DCBZ(_n) \
    __dcbz(d, 0); \
    f0 = *(f64 *)s; \
    __dcbz(d, (_n) * 8); \
    f1 = *(f64 *)(s + (_n) * 8); \
    s += (_n) * 16; \
    *(f64 *)d = f0; \
    *(f64 *)(d + (_n) * 8) = f1; \
    d += (_n) * 16

#define ROW2(_n) \
    f0 = *(f64 *)s; \
    f1 = *(f64 *)(s + (_n) * 8); \
    s += (_n) * 16; \
    *(f64 *)d = f0; \
    *(f64 *)(d + (_n) * 8) = f1; \
    d += (_n) * 16

/* One 16-byte row, then advance one row. */
#define ROW16_DCBZ(_n) \
    __dcbz(d, 0); \
    f0 = *(f64 *)s; \
    f1 = *(f64 *)(s + 8); \
    s += (_n) * 8; \
    *(f64 *)d = f0; \
    *(f64 *)(d + 8) = f1; \
    d += (_n) * 8

#define ROW16(_n) \
    f0 = *(f64 *)s; \
    f1 = *(f64 *)(s + 8); \
    s += (_n) * 8; \
    *(f64 *)d = f0; \
    *(f64 *)(d + 8) = f1; \
    d += (_n) * 8

void fn_12_112D4(Stride *stride, Src *src, Dst *dst) {
    s32 n;
    u8 *s;
    u8 *d;
    f64 f0;
    f64 f1;

    n = dst->count0 / 8;
    if ((stride->off0 & 0x1F) == 0) {
        s = src->base0 + stride->off0;
        d = dst->base0 + stride->off0;
        ROW2_DCBZ(n); ROW2_DCBZ(n); ROW2_DCBZ(n); ROW2_DCBZ(n);
        s = src->base1 + stride->off0;
        d = dst->base1 + stride->off0;
        ROW2_DCBZ(n); ROW2_DCBZ(n); ROW2_DCBZ(n); ROW2_DCBZ(n);
    } else {
        s = src->base0 + stride->off0;
        d = dst->base0 + stride->off0;
        ROW2(n); ROW2(n); ROW2(n); ROW2(n);
        s = src->base1 + stride->off0;
        d = dst->base1 + stride->off0;
        ROW2(n); ROW2(n); ROW2(n); ROW2(n);
    }

    n = dst->count1 / 8;
    if ((stride->off1 & 0x1F) == 0) {
        s = src->base2 + stride->off1;
        d = dst->base2 + stride->off1;
        ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n);
        ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n);
        ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n);
        ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n);
    } else {
        s = src->base2 + stride->off1;
        d = dst->base2 + stride->off1;
        ROW16(n); ROW16(n); ROW16(n); ROW16(n);
        ROW16(n); ROW16(n); ROW16(n); ROW16(n);
        ROW16(n); ROW16(n); ROW16(n); ROW16(n);
        ROW16(n); ROW16(n); ROW16(n); ROW16(n);
    }
}
