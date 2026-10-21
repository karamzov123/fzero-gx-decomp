#include "types.h"

typedef struct Delay {
    s32 wpos;
    s32 rpos;
    s32 size;
    s32 *buf;
    f32 val;
} Delay;

typedef struct Reverb {
    Delay comb[9];      /* 0x000 */
    Delay ap[9];        /* 0x0B4 */
    f32 room;           /* 0x168 */
    f32 gain[9];        /* 0x16C */
    f32 lp[3];          /* 0x190 */
    f32 mix;            /* 0x19C */
    f32 damp;           /* 0x1A0 */
    s32 preLen;         /* 0x1A4 */
    f32 width;          /* 0x1A8 */
    s32 *preBuf[3];     /* 0x1AC */
    s32 *prePos[3];     /* 0x1B8 */
} Reverb;

extern void *memset(void *, int, u32);
extern s32 lbl_80128160[8];
extern void *(*lbl_801A64F8)(u32);
extern f32 fn_800885B8(f32, f32);

static inline void delay_set(Delay *d, s32 n) {
    d->rpos = d->wpos - n * 4;
    while (d->rpos < 0) {
        d->rpos += d->size;
    }
}

static inline void delay_alloc(Delay *d, s32 n) {
    s32 * fzgx_live;
    d->size = n * 4;
    d->buf = lbl_801A64F8(n * 4);
    fzgx_live = d->buf;
    memset(fzgx_live, 0, n * 4);
    d->val = 0.0f;
    delay_set(d, n >> 1);
}

static inline void delay_init(Delay *d, s32 *len) {
    delay_alloc(d, *len + 2);
    d->wpos = 0;
    d->rpos = 0;
    delay_set(d, *len);
}

s32 fn_80023684(Reverb *r, f32 room, f32 time, f32 mix, f32 damp, f32 pre, f32 width) {
    u8 i;
    Reverb *self;
    u8 j;
    u8 k;
    f32 rate;

    if (room < 0.0f || room > 1.0f || time < 0.01f || time > 10.0f || mix < 0.0f || mix > 1.0f ||
        width < 0.0f || width > 1.0f || damp < 0.0f || damp > 1.0f || pre < 0.0f || pre > 0.1f) {
        return 0;
    }

    memset(r, 0, sizeof(Reverb));
    rate = 32000.0f * time;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            delay_init(&r->ap[i * 3 + j], &lbl_80128160[j]);
            r->gain[i * 3 + j] = fn_800885B8(10.0f, (f32)(lbl_80128160[j] * -3) / rate);
        }
        for (j = 0; j < 2; j++) {
            delay_init(&r->comb[i * 3 + j], &lbl_80128160[3 + j]);
        }
        delay_init(&r->comb[i * 3 + 2], &lbl_80128160[5 + i]);
        r->lp[i] = 0.0f;
    }

    r->room = room;
    r->mix = mix;
    r->width = width;
    r->damp = damp;
    if (r->damp < 0.05f) {
        r->damp = 0.05f;
    }
    r->damp = 1.0f - (0.05f + (f32)(0.8f * r->damp));

    if (0.0f != pre) {
        r->preLen = (s32)(32000.0f * pre);
        for (k = 0; k < 3; k++) {
            r->preBuf[k] = lbl_801A64F8(r->preLen * 4);
            memset(r->preBuf[k], 0, r->preLen * 4);
            r->prePos[k] = r->preBuf[k];
        }
    } else {
        r->preLen = 0;
        r->prePos[0] = 0;
        r->preBuf[0] = 0;
        r->prePos[1] = 0;
        r->preBuf[1] = 0;
        r->prePos[2] = 0;
        r->preBuf[2] = 0;
    }
    return 1;
}
