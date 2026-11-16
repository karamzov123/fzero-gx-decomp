#include "types.h"

typedef struct {
    u8 *str;
    u8 pad_4[0x9C];
    u32 len;
    u8 pad_A4[4];
} Entry;

typedef struct {
    u8 pad_0[0x424];
    Entry entries[5];
    u8 pad_76C[0x48];
    u32 *cursor;
} Ctx;

#pragma opt_propagation off
#pragma opt_lifetimes off
s32 fn_8003A4E8(Ctx *d, u32 idx, u8 *counts) {
    u32 * fzgx_live_;
    u32 * fzgx_live;
    u32 * fzgx_live_2;
    struct { s8 value; } c;
    s32 j;
    u32 t;
    s32 k;
    s32 i;
    s32 n = 0;
    s32 base;

    for (j = 1; j <= 16; j++) {
        n += ((j - 1)[counts]);
    }
    fzgx_live_ = (d->cursor);
    fzgx_live = fzgx_live_;
    ((idx & 0xFF)[d->entries]).str = (u8 *)fzgx_live;
    fzgx_live_2 = (d->cursor);
    base = n + (s32)(u32)fzgx_live_2;
    d->cursor = (u32 *)(base + 1);
    t = 0;
    for (i = 1; i <= 16; i++) {
        n = ((i - 1)[counts]);
        c.value = (s8)i;
        for (k = 0; k != n; k++) {
            ((idx & 0xFF)[d->entries]).str[t] = c.value;
            t++;
        }
    }
    ((idx & 0xFF)[d->entries]).str[t] = 0;
    ((idx & 0xFF)[d->entries]).len = t;
    return 0;
}

#pragma opt_lifetimes reset

#pragma opt_propagation reset
