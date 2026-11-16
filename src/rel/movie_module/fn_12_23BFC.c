#include "types.h"

typedef struct MovieState {
    u8 unk_00;
    u8 unk_01;
    s32 unk_04;
    void *unk_08;
    void *unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
    u8 unk_28;
    s32 unk_2c;
    u8 pad_30[0x10];
} MovieState;

typedef struct FrameHeader {
    u8 layer;
    u8 prot;
    u8 bitrate;
    u8 rate;
    u8 padding;
    u8 priv;
    u8 mode;
    u8 modeExt;
    u8 copyright;
    u8 original;
    u8 emphasis;
} FrameHeader;

extern void *memset(void *, int, u32);
extern s32 fn_12_2396C(u8 *data, s32 size, MovieState *movie);
extern s32 fn_12_232DC(u8 *data, s32 size, MovieState *movie);
extern s32 fn_12_23410(u8 *data, s32 size, MovieState *movie);
extern const s32 lbl_12_rodata_ADC[4];
extern const s32 lbl_12_rodata_AEC[5];
extern FrameHeader lbl_12_bss_69B0;


static inline u8 *findHeader(u8 *p, s32 size, FrameHeader *h) {
    for (; size >= 4; size--, p++) {
        if (p[0] != 0xff) {
            continue;
        }
        if ((p[1] & 0xf8) != 0xf8) {
            continue;
        }
        h->layer = (u32)(p[1] >> 1) & 3;
        h->prot = p[1] & 1;
        h->bitrate = ((u32)p[2] >> 4) & 0xf;
        h->rate = ((u32)p[2] >> 2) & 3;
        h->padding = ((u32)p[2] >> 1) & 1;
        h->priv = p[2] & 1;
        h->mode = ((u32)p[3] >> 6) & 3;
        h->modeExt = ((u32)p[3] >> 4) & 3;
        h->copyright = ((u32)p[3] >> 3) & 1;
        h->original = ((u32)p[3] >> 2) & 1;
        h->emphasis = p[3] & 3;
        if (h->layer == 0) {
            continue;
        }
        if (h->bitrate == 0xf) {
            continue;
        }
        if (h->rate == 3) {
            continue;
        }
        return p;
    }
    return 0;
}

static inline s32 detectAudio(u8 *data, s32 size, MovieState *movie) {
    FrameHeader h;

    data = findHeader(data, size, &h);
    if (data != 0) {
        if (h.layer == 2 && h.bitrate != 0 && h.rate == 0) {
            movie->unk_28 = lbl_12_rodata_ADC[h.mode];
            movie->unk_2c = lbl_12_rodata_AEC[h.rate];
        }
        lbl_12_bss_69B0 = h;
        return 1;
    }
    return 0;
}

void fn_12_23BFC(u8 *data, s32 size, MovieState *movie) {
    memset(movie, 0, 0x40);
    movie->unk_00 = 0;
    movie->unk_01 = 0;
    movie->unk_04 = 0;
    movie->unk_08 = 0;
    movie->unk_0c = 0;
    movie->unk_10 = 0;
    movie->unk_14 = 0;
    movie->unk_18 = 0;
    movie->unk_1c = 0;
    movie->unk_20 = 0;
    movie->unk_24 = 0;
    movie->unk_28 = 0;
    movie->unk_2c = 0;
    if (fn_12_2396C(data, size, movie)) {
        return;
    }
    if (fn_12_232DC(data, size, movie)) {
        return;
    }
    if (fn_12_23410(data, size, movie)) {
        return;
    }
    if (detectAudio(data, size, movie)) {
        return;
    }
}
