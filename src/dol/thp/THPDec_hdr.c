#include "types.h"

typedef struct ThpComp {
    u8 id;          /* 0x00 */
    u8 h;           /* 0x01 */
    u8 v;           /* 0x02 */
    u8 tq;          /* 0x03 */
    u8 dc;          /* 0x04 */
    u8 ac;          /* 0x05 */
    u16 pred;       /* 0x06 */
    s32 w8;         /* 0x08 */
    s32 hC;         /* 0x0C */
    u8 pad10[0x8];  /* 0x10 */
    s32 hs;         /* 0x18 */
    s32 vs;         /* 0x1C */
    s32 blocks;     /* 0x20 */
    s32 hpix;       /* 0x24 */
    s32 rows;       /* 0x28 */
    s32 cols;       /* 0x2C */
} ThpComp;          /* size 0x30 */

typedef struct ThpHuffTab {
    u8 *bits;       /* 0x00 */
    s8 *huffsize;   /* 0x04 */
    s32 *huffcode;  /* 0x08 */
    u16 numVals;    /* 0x0C */
    u8 pad_E[0x2];  /* 0x0E */
    u8 *vals;       /* 0x10 */
    u8 pad_14[0x4]; /* 0x14 */
    s32 maxcode[16];/* 0x18..0x57 */
    s32 sentinel;   /* 0x58 */
    s32 pad_5C;     /* 0x5C */
    s32 valptr[16]; /* 0x60..0x9F */
    u8 pad_A0[4];   /* 0xA0..0xA3 */
    u32 size_len;   /* 0xA4..0xA7 */
} ThpHuffTab;       /* size 0xA8 */

typedef struct ThpDec {
    f32 quant[4][64];      /* 0x000..0x3FF */
    u8 *ptr;               /* 0x400 */
    u8 pad_404[4];         /* 0x404 */
    u16 width;             /* 0x408 */
    u16 height;            /* 0x40A */
    u8 pad_40c[0xc];       /* 0x40C..0x417 */
    u8 validHuffmanTabs;   /* 0x418 */
    u8 validQuantTabs;     /* 0x419 */
    u8 maxH;               /* 0x41A */
    u8 maxV;               /* 0x41B */
    u8 numComp;            /* 0x41C */
    u8 pad_41d[3];         /* 0x41D..0x41F */
    ThpHuffTab huff[4];    /* 0x420..0x6BF */
    ThpComp comps[4];      /* 0x6C0..0x77F */
    u8 pad_780[0x10];      /* 0x780..0x78F */
    u8 mcu[0x10];          /* 0x790..0x79F */
    u16 mcux;              /* 0x7A0 */
    u16 nblocks;           /* 0x7A2 */
    u16 mcuy;              /* 0x7A4 */
    u16 unk_7a6;           /* 0x7A6 */
    u16 unk_7a8;           /* 0x7A8 */
    u8 pad_7aa[0xa];       /* 0x7AA..0x7B3 */
    u8 *heap;              /* 0x7B4 */
} ThpDec;

static const u32 fzgx_pool_rodata_lbl_8008FF50[20] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x10810, 0x902030A, 0x11182019, 0x120B0405, 0xC131A21, 0x28302922, 0x1B140D06, 0x70E151C,
    0x232A3138, 0x39322B24, 0x1D160F17, 0x1E252C33, 0x3A3B342D, 0x261F272E, 0x353C3D36, 0x2F373E3F,
    0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F, 0x3F3F3F3F
};
static const u32 fzgx_pool_rodata_lbl_8008FF50_50[16] = {  /* fzgx-allow: A1 retail data bytes and bindings */
    0x3FF00000, 0x0, 0x3FF63150, 0xC0000000, 0x3FF4E7AE, 0xA0000000, 0x3FF2D062, 0xE0000000,  /* fzgx-allow: A1 retail data bytes */
    0x3FF00000, 0x0, 0x3FE92469, 0xC0000000, 0x3FE1517A, 0x80000000, 0x3FD1A855, 0xE0000000  /* fzgx-allow: A1 retail data bytes */
};
#pragma section code_type ".fzgxpool"
static void fzgx_data_layout_lbl_8008FF50(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: keeps the retail .data objects in retail order */
    s = *(u8 *)fzgx_pool_rodata_lbl_8008FF50;
    s = *(u8 *)fzgx_pool_rodata_lbl_8008FF50_50;
}
#pragma section code_type ".text"

u8 fn_8003A4E8(ThpDec *d, u8 idx, u8 *counts);
u8 fn_8003A680(ThpDec *arg0, u8 arg1);
s32 fn_8003A760(ThpDec *arg0, u8 arg1);
s32 fn_8003A91C(ThpDec *d);

static inline s32 divUp(s32 a, s32 b) {
    a = b + a;
    return (a - 1) / b;
}

s32 fn_80039C40(ThpDec *d) {
    u8 i;
    u32 b;
    ThpComp *c;
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
    if (((3) != d->numComp) && (((d->numComp) != ((1))))) {
        return 6;
    }
    for (i = 0; i < d->numComp; i++) {
        (d->comps)[i].id = *d->ptr++;
        bb = *d->ptr++;
        (d->comps)[i].h = bb >> 4;
        (d->comps)[i].v = bb & 0xf;
        (d->comps)[i].tq = *d->ptr++;
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
            lab_t0 = d->width * (d->comps)[fzgx_loop_i_1473].h;
            lab_t1_ = d->maxH;
            (d->comps)[fzgx_loop_i_1473].w8 = divUp(lab_t0, lab_t1_);
            lab_t0 = d->height * (d->comps)[fzgx_loop_i_1473].v;
            lab_t1_ = d->maxV;
            (d->comps)[fzgx_loop_i_1473].hC = divUp(lab_t0, lab_t1_);
        }
        i = fzgx_loop_i_1473;
    }
    return 0;
}

s32 fn_80039E48(ThpDec *arg0) {
    u16 v2;
    u8 v4;
    u32 v5;
    u16 v20;
    u16 v19;
    u16 v22;
    union { f64 alignment; f32 values[64]; } quantBuffer;
    f64 *scale;
    v2 = (arg0->ptr[0] << 8) | arg0->ptr[1];
    arg0->ptr += 2;
    scale = (f64 *)(((const u8 *)fzgx_pool_rodata_lbl_8008FF50_50));
    v2 -= 2;
    do {
        v4 = *arg0->ptr++;
        for (v5 = 0; (u16)v5 < 64; v5 += 8) {
            quantBuffer.values[((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[v5]] = (f32)(u32)*arg0->ptr++;
            quantBuffer.values[((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 1)]] = (f32)(u32)*arg0->ptr++;
            quantBuffer.values[((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 2)]] = (f32)(u32)*arg0->ptr++;
            quantBuffer.values[((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 3)]] = (f32)(u32)*arg0->ptr++;
            quantBuffer.values[((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 4)]] = (f32)(u32)*arg0->ptr++;
            quantBuffer.values[((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 5)]] = (f32)(u32)*arg0->ptr++;
            quantBuffer.values[((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 6)]] = (f32)(u32)*arg0->ptr++;
            quantBuffer.values[((const u8 *)fzgx_pool_rodata_lbl_8008FF50)[(u16)(v5 + 7)]] = (f32)(u32)*arg0->ptr++;
        }
        arg0->validQuantTabs |= 1 << v4;
        v20 = 0;
        for (v19 = 0; v19 < 8; v19++) {
            for (v22 = 0; v22 < 8; v22++) {
                arg0->quant[v4][v20] = ((f64 *)(((const u8 *)fzgx_pool_rodata_lbl_8008FF50_50)))[v22] *
                    ((f64)quantBuffer.values[v20] * ((f64 *)(((const u8 *)fzgx_pool_rodata_lbl_8008FF50_50)))[v19]);
                v20++;
            }
        }
        v2 -= 65;
    } while (v2);
    return 0;
}

u8 fn_8003A1CC(ThpDec *info) {
    u8 tabClass;
    u8 id;
    u8 i;
    u8 tabIndex;
    u8 err;
    u8 byte;
    u8 *bits;
    u16 length;
    u16 numVals;

    length = ((info->ptr[0] << 8) | info->ptr[1]);
    info->ptr += 2;
    length -= 2;

    do {
        byte = *info->ptr++;
        bits = info->ptr;
        tabClass = byte >> 4;
        id = byte & 0xF;
        if (tabClass > 1 || id >= 2) {
            return 7;
        }
        tabIndex = (id << 1) + tabClass;

        numVals = 0;
        for (i = 0; i < 16; i++) {
            numVals += *info->ptr++;
        }
        info->huff[tabIndex].bits = bits;
        info->huff[tabIndex].vals = info->ptr;
        info->huff[tabIndex].numVals = numVals;
        for (i = 0; i < numVals; i++) {
            info->ptr++;
        }

        if ((err = fn_8003A4E8(info, tabIndex, bits)) != 0) {
            return err;
        }
        if ((err = fn_8003A680(info, tabIndex)) != 0) {
            return err;
        }
        fn_8003A760(info, tabIndex);
        length -= numVals + 17;
        info->validHuffmanTabs |= 1 << tabIndex;
    } while (length);

    return 0;
}

s32 fn_8003A3D4(u8 *arg0) {
    u8 count;
    u8 i;
    struct { u8 *value; } p;

    *(u8 **)(arg0 + 0x400) += 2;
    count = *(*(u8 **)(arg0 + 0x400))++;
    if (count != *(arg0 + 0x41C)) {
        return 6;
    }

    p.value = arg0;
    for (i = 0; i < count; i++, p.value += 0x30) {
        s32 hi;
        u16 val;
        s32 lo;
        u16 unk8;
        s16 shift;
        s32 diff;

        (*(u8 **)(arg0 + 0x400)) = (*(u8 **)(arg0 + 0x400)) + 1;
        val = (*(*(u8 **)(((0x400) + arg0)))++);
        hi = val >> 4;
        *(u8 *)(p.value + 0x6C4) = hi;
        lo = val & 0xF;
        *(u8 *)(p.value + 0x6C5) = lo;
        if (!(*(((0x418) + arg0)) & (1 << hi))) {
            return 9;
        }
        if (!(*(((0x418) + arg0)) & (1 << (lo + 1)))) {
            return 9;
        }

        diff = *(arg0 + 0x41B) - *(((0x6C2) + p.value));
        unk8 = (*(u32 *)(p.value + 0x6C8));
        shift = 16 >> diff;
        *(u32 *)(p.value + 0x6D0) = *(u32 *)(arg0 + 0x7B4);
        *(u32 *)(arg0 + 0x7B4) += ((u16)unk8) * ((u16)shift);
    }

    *(u8 **)(arg0 + 0x400) += 3;
    return fn_8003A91C((ThpDec *)arg0);
}

#pragma opt_propagation off
#pragma opt_lifetimes off
u8 fn_8003A4E8(ThpDec *d, u8 idx, u8 *counts) {
    u32 *fzgx_live_;
    u32 *fzgx_live;
    u32 *fzgx_live_2;
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
    fzgx_live_ = (u32 *)d->heap;
    fzgx_live = fzgx_live_;
    ((idx & 0xFF)[d->huff]).huffsize = (s8 *)fzgx_live;
    fzgx_live_2 = (u32 *)d->heap;
    base = n + (u32)fzgx_live_2;
    d->heap = (u8 *)(base + 1);
    t = 0;
    for (i = 1; i <= 16; i++) {
        n = ((i - 1)[counts]);
        c.value = i;
        for (k = 0; k != n; k++) {
            ((idx & 0xFF)[d->huff]).huffsize[t] = c.value;
            t++;
        }
    }
    ((idx & 0xFF)[d->huff]).huffsize[t] = 0;
    ((idx & 0xFF)[d->huff]).size_len = t;
    return 0;
}
#pragma opt_lifetimes reset
#pragma opt_propagation reset

u8 fn_8003A680(ThpDec *arg0, u8 arg1) {
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
    arg0->huff[arg1].huffcode = (s32 *)arg0->heap;
    arg0->heap += k * 4;
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

s32 fn_8003A760(ThpDec *arg0, u8 arg1) {
    ThpHuffTab *p = &arg0->huff[arg1];
    s32 acc = 0;
    s32 i;

    for (i = 1; i <= 16; i++) {
        if (p->bits[i - 1] != 0) {
            p->valptr[i - 1] = acc - p->huffcode[acc];
            acc += p->bits[i - 1];
            p->maxcode[i - 1] = p->huffcode[acc - 1];
        } else {
            p->maxcode[i - 1] = -1;
            p->valptr[i - 1] = -1;
        }
    }
    p->sentinel = 0xFFFFF;
    return 0;
}

#define CEIL_DIV(a, b) (((b) - 1 + (a)) / (b))

s32 fn_8003A91C(ThpDec *d) {
    u32 i;
    s32 n;

    d->mcux = CEIL_DIV(d->width, d->maxH * 8);
    d->mcuy = CEIL_DIV(d->height, d->maxV * 8);
    d->nblocks = 0;
    for (i = 0; i < d->numComp; i++) {
        ThpComp *c = &d->comps[i];
        c->cols = CEIL_DIV(d->width * c->h, d->maxH * 8);
        c->rows = CEIL_DIV(d->height * c->v, d->maxV * 8);
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
