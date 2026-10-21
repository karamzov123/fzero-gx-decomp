#include "types.h"

/* JPEG frame component (0x30 bytes). */
struct fn_8003A91C_Comp {
    u8 id, h, v, tq;
    u8 dc, ac;
    u16 pred;
    u8 pad8[0x10];
    s32 hs;
    s32 vs;
    s32 blocks;
    s32 hpix;
    s32 rows;
    s32 cols;
};

struct fn_8003A91C_Dec {
    u8 pad0[0x408];
    u16 width;
    u16 height;
    u8 pad40C[0xE];
    u8 hmax;
    u8 vmax;
    u8 ncomp;
    u8 pad41D[0x2A3];
    struct fn_8003A91C_Comp comp[3];
    u8 pad750[0x40];
    u8 mcu[0x10];
    u16 mcux;
    u16 nblocks;
    u16 mcuy;
};

/* Round-up division. */
#define CEIL_DIV(a, b) (((b) - 1 + (a)) / (b))

s32 fn_8003A91C(struct fn_8003A91C_Dec *d) {
    u32 i;
    s32 j;
    s32 n;

    d->mcux = CEIL_DIV(d->width, d->hmax * 8);
    d->mcuy = CEIL_DIV(d->height, d->vmax * 8);
    d->nblocks = 0;
    for (i = 0; i < d->ncomp; i++) {
        struct fn_8003A91C_Comp *c = &d->comp[i];
        c->cols = CEIL_DIV(d->width * c->h, d->hmax * 8);
        c->rows = CEIL_DIV(d->height * c->v, d->vmax * 8);
        c->hs = c->h;
        c->vs = c->v;
        c->blocks = c->hs * c->vs;
        c->hpix = c->hs << 3;
        n = c->blocks;
        if (d->nblocks + n > 16) {
            return 11;
        }
        while (n-- > 0) {
            d->mcu[d->nblocks++] = (u8)i;
        }
        c->pred = 0;
    }
    return 0;
}
