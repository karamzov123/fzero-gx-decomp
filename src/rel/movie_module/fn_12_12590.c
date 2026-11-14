#include "types.h"

typedef struct {
    u8 pad_00[0x1d0];
    s32 field_1d0;
    s32 field_1d4;
    u8 pad_1d8[0x254 - 0x1d8];
    s32 field_254;
    u8 pad_258[0x264 - 0x258];
    s32 field_264;
    s32 field_268;
    s32 field_26c;
    s16 field_270;
    s16 field_272;
} MovieCtx;

void fn_12_12590(MovieCtx *m, u32 lab_unused0) {
    s16 *fzgx_value;
    s32 w0;
    s32 rows;
    s32 rows16;
    s32 rbit;
    struct { s32 value; } half;
    s32 wide;
    s32 h32;
    s32 w32;
    s32 h0;
    s32 cols;
    u32 c16;
    s32 base;
    w0 = m->field_1d0;
    rows = (w0 + 15) / 16;
    rows16 = rows << 4;
    rbit = (s32)((u32)rows >> 27 & 1u);
    half.value = (rows16 + 31) / 32;
    wide = (((rbit + rows16) >> 1) + 31) / 32;
    h32 = half.value << 5;
    w32 = wide << 5;
    h0 = m->field_1d4;
    cols = (h0 + 15) / 16;
    h0 = cols << 4;
    rbit = h0;
    wide = rbit;
    c16 = wide;
    base = m->field_254;

    m->field_272 = (s16)h32;
    fzgx_value = &(m->field_270);
    *fzgx_value = (s16)w32;
    m->field_26c = base;
    m->field_264 = m->field_26c + (((((c16)) * ((h32)))));
    {
        s32 cbit = (s32)((u32)cols >> 27 & 1u);
        s32 csum = (cbit + (s32)c16) >> 1;
        m->field_268 = m->field_264 + (((csum) * (w32)));
    }
}

