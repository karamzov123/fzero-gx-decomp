#include "types.h"

/* --- rel/movie_module/fn_12_7870.c --- */
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
void fn_12_7870(u32 arg0, u32 arg1, struct fn_12_7870_Arg2 *arg2, struct fn_12_7870_Arg3 *arg3) {
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

/* --- rel/movie_module/fn_12_78C0.c --- */
/* --- rel/movie_module/fn_12_78C0.c --- */
typedef struct MovieModule_u1 MovieModule_u1;

struct MovieModule_u1 {
    u8 _pad_000[0x2a8];
    void (*update)(MovieModule_u1 *);
    u8 _pad_2ac[0x5c];
    s32 frame_count;
    u8 _pad_30c[0x8];
    s32 field_314;
};

void fn_12_78C0(MovieModule_u1 *movie, s32 frame) {
    s32 end;
    s32 current;
    void (*update)(MovieModule_u1 *);

    end = movie->frame_count;
    current = end - frame + 1;
    movie->field_314 = 0;
    update = movie->update;
    while (current < end) {
        movie->frame_count = current;
        update(movie);
        current++;
    }
    movie->frame_count = end;
}

/* --- rel/movie_module/fn_12_7940.c --- */
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

typedef struct MovieDecoder_u1 MovieDecoder_u1;

struct MovieDecoder_u1 {
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
    void (*get_offsets)(MovieDecoder_u1 *, s32, Sig_fn_12_7E58_MovieBlockOffsets *, Sig_fn_12_7E58_MovieFrameBuffer *);
    u8 _pad_294[0x308 - 0x294];
    s32 count;
    u8 _pad_30c[0xcc0 - 0x30c];
    f64 block[48];
};

/* Gathers an 8x8 block of 8-byte rows from m->src (row pitch m->stride). */
static inline u8 * read_block_read_pointer(MovieDecoder_u1 * owner) { return owner->src; }
static inline void read_block(MovieDecoder_u1 *m, f64 *b) {
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
static inline f64 *write_block(MovieDecoder_u1 *m, f64 *b) {
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

void fn_12_7940(MovieDecoder_u1 *m, s32 n) {
    s32 skip;
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
    skip = (cstride - 1) * 8;
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
        m->src += skip;
        read_block(m, blk + 32);
        m->dst = write_block(m, blk + 32);
        m->src += 8;
        read_block(m, blk + 40);
        out = write_block(m, blk + 40);
        blk = m->block;
        fn_12_7E58(blk, &ofs, fbout);
    }
}
