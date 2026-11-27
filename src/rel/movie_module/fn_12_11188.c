#include "types.h"

/* --- rel/movie_module/fn_12_11188.c --- */
typedef struct MovieContext {
    u8 unk_000[0x1d8];
    u32 unk_1d8;
} MovieContext;

typedef struct MovieDimensions {
    u8 unk_00[0x0c];
    s16 width;
    s16 height;
} MovieDimensions;

typedef struct DivResult {
    s32 quot;
    s32 rem;
} DivResult;

extern DivResult fn_8007E914(s32 value, s32 context);

void fn_12_11188(MovieContext *movie, u32 value, u32 *out, const MovieDimensions *dimensions) {
    DivResult d = fn_8007E914(value, movie->unk_1d8);
    s32 width = dimensions->width;
    s32 height = dimensions->height;

    out[0] = (d.quot << 3) * width + (d.rem << 3);
    out[1] = (d.quot << 4) * height + (d.rem << 4);
}

/* --- rel/movie_module/fn_12_11204.c --- */
struct fn_12_7870_Arg2 {
    u32 unk_0;
    s32 unk_4;
};
struct fn_12_7870_Arg3 {
    u8 pad_0[0xC];
    s16 unk_C;
    s16 unk_E;
};

#pragma opt_propagation off
#pragma opt_lifetimes off
void fn_12_11204(u32 arg0, u32 arg1, struct fn_12_7870_Arg2 *arg2, struct fn_12_7870_Arg3 *arg3) {
    u8 *entry;
    s16 y;
    s8 a;
    s8 b;
    s32 a8;

    y = arg3->unk_E;
    arg1 <<= 1;
    entry = (u8 *)arg1 + 0x1344;
    entry = (u8 *)arg0 + (u32)entry;
    a = (s8)entry[0];
    b = (s8)entry[1];
    a8 = a << 3;
    arg2->unk_0 = (a8 * arg3->unk_C) + (b << 3);
    arg2->unk_4 = (a << 4) * y + (b << 4);
}
#pragma opt_lifetimes reset
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_11254.c --- */
/* --- rel/movie_module/fn_12_11254.c --- */
typedef struct MovieModule {
    u8 unk_000[0x2a8];
    void (*callback)(struct MovieModule *);
    u8 unk_2ac[0x5c];
    s32 current_frame;
    u8 unk_30c[0x08];
    s32 field_314;
} MovieModule;

void fn_12_11254(MovieModule *movie, s32 frame) {
    s32 end_frame;
    s32 current_frame;
    void (*callback)(MovieModule *);

    end_frame = movie->current_frame;
    movie->field_314 = 0;
    current_frame = end_frame - frame + 1;
    callback = movie->callback;
    while (current_frame < end_frame) {
        movie->current_frame = current_frame;
        callback(movie);
        current_frame += 1;
    }
    movie->current_frame = end_frame;
}

/* --- rel/movie_module/fn_12_112D4.c --- */
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

void fn_12_112D4(Stride *stride, Src *src, Dst *dst);
