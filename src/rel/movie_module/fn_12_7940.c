#include "types.h"

typedef struct Sig_fn_12_7E58_MovieBlockOffsets {
    u32 luma;
    u32 chroma;
} Sig_fn_12_7E58_MovieBlockOffsets;
typedef struct Sig_fn_12_7E58_MovieFrameBuffer {
    u8 *luma_top;
    u8 *luma_bottom;
    u8 *chroma;
    s16 luma_stride;
    s16 chroma_stride;
} Sig_fn_12_7E58_MovieFrameBuffer;

extern void fn_12_7E58(f64 *, Sig_fn_12_7E58_MovieBlockOffsets *, Sig_fn_12_7E58_MovieFrameBuffer *);

typedef struct MovieDecoder MovieDecoder;

struct MovieDecoder {
    u8 _pad_000[0xe0];
    f64 *dst;
    u8 _pad_0e4[0x4];
    s32 stride;
    u8 _pad_0ec[0x4];
    u8 *src;
    u8 _pad_0f4[0x234 - 0xf4];
    Sig_fn_12_7E58_MovieFrameBuffer in;
    Sig_fn_12_7E58_MovieFrameBuffer out;
    f64 *block_out;
    u8 _pad_258[0x290 - 0x258];
    void (*get_offsets)(MovieDecoder *, s32, Sig_fn_12_7E58_MovieBlockOffsets *, Sig_fn_12_7E58_MovieFrameBuffer *);
    u8 _pad_294[0x308 - 0x294];
    s32 count;
    u8 _pad_30c[0xcc0 - 0x30c];
    f64 block[48];
};

/* Gathers an 8x8 block of 8-byte rows from m->src (row pitch m->stride). */
static inline u8 * read_block_read_pointer(MovieDecoder * owner) { return owner->src; }
static inline void read_block(MovieDecoder *m, f64 *b) {
    u8 * s;
    s32 st = m->stride;
    s = read_block_read_pointer(m);
    st &= ~7;

    b[0] = *(f64 *)s;
    s += st;
    b[1] = *(f64 *)s;
    s += st;
    b[2] = *(f64 *)s;
    s += st;
    b[3] = *(f64 *)s;
    s += st;
    b[4] = *(f64 *)s;
    s += st;
    b[5] = *(f64 *)s;
    s += st;
    b[6] = *(f64 *)s;
    b[7] = *(f64 *)(s + st);
}

/* Appends the block to m->dst and returns the advanced output pointer. */
static inline f64 *write_block(MovieDecoder *m, f64 *b) {
    f64 *d = m->dst;

    d[0] = b[0];
    d[1] = b[1];
    d[2] = b[2];
    d[3] = b[3];
    d[4] = b[4];
    d[5] = b[5];
    d[6] = b[6];
    d[7] = b[7];
    return d + 8;
}

void fn_12_7940(MovieDecoder *m, s32 n) {
    struct { s32 value; } skip;
    f64 *blk;
    Sig_fn_12_7E58_MovieFrameBuffer *fb;
    Sig_fn_12_7E58_MovieFrameBuffer *fbout;
    s16 ystride;
    s16 cstride;
    f64 *out;
    Sig_fn_12_7E58_MovieBlockOffsets ofs;

    fb = &m->in;
    blk = m->block;
    fbout = fb + 1;
    out = m->block_out;
    cstride = fb->chroma_stride;
    ystride = fb->luma_stride;
    m->block_out = out + n * 48 - 48;
    skip.value = (cstride - 1) * 8;
    while (--n != 0) {
        m->get_offsets(m, m->count - n, &ofs, fb);
        m->stride = ystride;
        m->dst = out;
        m->src = fb->luma_top + ofs.luma;
        read_block(m, blk);
        m->dst = write_block(m, blk);
        m->src = fb->luma_bottom + ofs.luma;
        read_block(m, blk + 8);
        {
            f64 *d = m->dst;
            d[0] = blk[8];
            d[1] = blk[9];
            d[2] = blk[10];
            d[3] = blk[11];
            d[4] = blk[12];
            d[5] = blk[13];
            d[6] = blk[14];
            d[7] = blk[15];
            m->stride = cstride;
            m->dst = d + 8;
        }
        (void)ystride;
        m->src = fb->chroma + ofs.chroma;
        read_block(m, blk + 16);
        m->dst = write_block(m, blk + 16);
        m->src += 8;
        read_block(m, blk + 24);
        m->dst = write_block(m, blk + 24);
        m->src += skip.value;
        read_block(m, blk + 32);
        m->dst = write_block(m, blk + 32);
        m->src += 8;
        read_block(m, blk + 40);
        out = write_block(m, blk + 40);
        blk = m->block;
        fn_12_7E58(blk, &ofs, fbout);
    }
}
