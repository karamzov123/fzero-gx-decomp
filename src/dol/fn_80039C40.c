#include "types.h"

typedef struct Comp {
    u8 id;
    u8 h;
    u8 v;
    u8 tq;
    u8 pad4[4];
    s32 w8;
    s32 hC;
    u8 pad10[0x20];
} Comp;

typedef struct Dec {
    u8 pad_0[0x400];
    u8 *ptr;
    u8 pad_404[4];
    u16 width;
    u16 height;
    u8 pad_40c[0xe];
    u8 maxH;
    u8 maxV;
    u8 numComp;
    u8 pad_41d[0x2a3];
    Comp comps[4];
    u8 pad_780[0x28];
    u16 unk_7a8;
} Dec;

static inline s32 divUp(s32 a, s32 b) {
    a = b + a;
    return (a - 1) / b;
}

static inline Comp * fn_80039C40_read_pointer(Dec * owner) { return owner->comps; }
s32 fn_80039C40(Dec *d) {
    u8 i;
    u32 b;
    Comp *c;
    u32 lab_t0;
    u32 lab_t1;
    u32 lab_t1_;
    u8 bb;

    d->ptr += 2;
    if (*d->ptr++ != 8) {
        return 4;
    }
    d->height = (d->ptr[0] << 8) | d->ptr[1];
    d->ptr += 2;
    d->width = (d->ptr[0] << 8) | d->ptr[1];
    d->ptr += 2;
    d->numComp = *d->ptr++;
    if (((3) != (d->numComp)) && ((((d->numComp)) != ((1))))) {
        return 6;
    }
    for (i = 0; i < d->numComp; i++) {
        fn_80039C40_read_pointer(d)[i].id = *d->ptr++;
        bb = *d->ptr++;
        fn_80039C40_read_pointer(d)[i].h = bb >> 4;
        fn_80039C40_read_pointer(d)[i].v = bb & 0xf;
        fn_80039C40_read_pointer(d)[i].tq = *d->ptr++;
    }
    d->maxH = 1;
    d->maxV = 1;
    for (i = 0; i < d->numComp; i++) {
        c = &d->comps[i];
        d->maxH = (d->maxH > c->h) ? d->maxH : c->h;
        d->maxV = (d->maxV > c->v) ? d->maxV : c->v;
    }
    lab_t0 = d->height;
    lab_t1 = d->maxV * 8;
    b = divUp(lab_t0, lab_t1);
    d->unk_7a8 = divUp(lab_t0, b);
    {
    u8 fzgx_loop_i_1473;
for (fzgx_loop_i_1473 = 0; fzgx_loop_i_1473 < d->numComp; fzgx_loop_i_1473++) {
        lab_t0 = d->width * fn_80039C40_read_pointer(d)[fzgx_loop_i_1473].h;
        lab_t1_ = d->maxH;
        fn_80039C40_read_pointer(d)[fzgx_loop_i_1473].w8 = divUp(lab_t0, lab_t1_);
        lab_t0 = d->height * fn_80039C40_read_pointer(d)[fzgx_loop_i_1473].v;
        lab_t1_ = d->maxV;
        fn_80039C40_read_pointer(d)[fzgx_loop_i_1473].hC = divUp(lab_t0, lab_t1_);
    }
    i = fzgx_loop_i_1473;
}
    return 0;
}

