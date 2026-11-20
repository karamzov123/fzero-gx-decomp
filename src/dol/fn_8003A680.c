#include "types.h"


/* --- dol/fn_8003A680.c --- */
struct Sig_fn_8003A680_fn_8003A1CC_Huff {
    u8 *bits;
    s8 *huffsize;
    s32 *huffcode;
    u16 count;
    u8 padE[0x2];
    u8 *huffval;
    u8 pad14[0x94];
};
struct Sig_fn_8003A680_fn_8003A1CC_Dec {
    u8 pad0[0x400];
    u8 *ptr;
    u8 pad404[0x14];
    u8 tables;
    u8 pad419[0x7];
    struct Sig_fn_8003A680_fn_8003A1CC_Huff huff[4];
    u8 pad6C0[0xF4];
    u8 *data;
};

s32 fn_8003A680(struct Sig_fn_8003A680_fn_8003A1CC_Dec *arg0, u8 arg1) {
    s32 length;
    s32 k;
    s32 code;

    k = 0;
    length = arg0->huff[arg1].huffsize[0];
    while (arg0->huff[arg1].huffsize[k] != 0) {
        while (arg0->huff[arg1].huffsize[k] == length) {
            k++;
        }
        length++;
    }
    arg0->huff[arg1].huffcode = (s32 *)arg0->data;
    arg0->data += k * 4;
    k = 0;
    code = 0;
    length = arg0->huff[arg1].huffsize[0];
    while (arg0->huff[arg1].huffsize[k] != 0) {
        while (arg0->huff[arg1].huffsize[k] == length) {
            arg0->huff[arg1].huffcode[k++] = code;
            code++;
        }
        code <<= 1;
        length++;
    }
    return 0;
}

/* --- dol/fn_8003A760.c --- */
typedef struct {
    u8 *unk0;
    u32 unk4;
    s32 *unk8;
    u8 padC[0xC];
    s32 unk18[16];
    s32 unk58;
    s32 unk5C;
    s32 unk60[16];
} unkStruct;

s32 fn_8003A760(u8 *arg0, u32 arg1) {
    unkStruct *p = (unkStruct *)(arg0 + 0x420 + 0xA8 * (arg1 & 0xFF));
    s32 acc = 0;
    s32 i;

    for (i = 1; i <= 16; i++) {
        if (p->unk0[i - 1] != 0) {
            p->unk60[i - 1] = acc - p->unk8[acc];
            acc += p->unk0[i - 1];
            p->unk18[i - 1] = p->unk8[acc - 1];
        } else {
            p->unk18[i - 1] = -1;
            p->unk60[i - 1] = -1;
        }
    }
    p->unk58 = 0xFFFFF;
    return 0;
}

/* --- dol/fn_8003A91C.c --- */
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
            d->mcu[d->nblocks++] = i;
        }
        c->pred = 0;
    }
    return 0;
}
