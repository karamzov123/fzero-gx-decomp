#include "types.h"

struct fn_12_7E58_a {
    f64 v[16];
    f64 w[32];
};

struct fn_12_7E58_b {
    u32 unk_0;
    u32 unk_4;
};

struct fn_12_7E58_c_u0 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
};

typedef struct MovieDecodeContext {
    u8 *lookup;
    s16 *table;
    u8 *data;
    u8 *ref;
} MovieDecodeContext;

typedef struct MovieDecodeContext_u1 {
    u8 *lookup;
    s16 *table;
    u8 *data;
} MovieDecodeContext_u1;
extern void fn_12_7E58(struct fn_12_7E58_a *arg0, struct fn_12_7E58_b *arg1, struct fn_12_7E58_c_u0 *arg2);
extern void fn_12_847C(void *obj, u32 arg1, s32 *arg2, u8 *arg3, s32 *arg4);
extern void fn_12_80BC(f64 *output, MovieDecodeContext *context, s32 mask);
extern void fn_12_8344(f64 *output, MovieDecodeContext_u1 *context, s32 mask);
extern void fn_12_8878(s16 *source, f64 *output, u32 *entries, const u8 *table);

/* fzgx:begin fn_12_7870 */
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
/* fzgx:end fn_12_7870 */

/* fzgx:begin fn_12_78C0 */
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
/* fzgx:end fn_12_78C0 */

/* fzgx:begin fn_12_7940 */
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
        fn_12_7E58( (struct fn_12_7E58_a *)(f64 *)(blk), (struct fn_12_7E58_b *)(Sig_fn_12_7E58_MovieBlockOffsets *)(&ofs), (struct fn_12_7E58_c_u0 *)(Sig_fn_12_7E58_MovieFrameBuffer *)(fbout));
    }
}
/* fzgx:end fn_12_7940 */

/* fzgx:begin fn_12_7E58 */
/* --- rel/movie_module/fn_12_7E58.c --- */



static inline f64 fn_12_7E58_array_read(f64 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
#pragma opt_common_subs off
void fn_12_7E58(struct fn_12_7E58_a *arg0, struct fn_12_7E58_b *arg1, struct fn_12_7E58_c_u0 *arg2) { u32 st0;
    u32 st1;
    u8 *d0;
    u8 *q0;
    u8 *q1;
    f64 *w;
    f64 *p;
    f64 *s;

    st0 = arg2->unk_C & ~7;

    d0 = (u8 *)(arg2->unk_0 + arg1->unk_0);
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 0);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 1);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 2);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 3);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 4);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 5);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 6);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 7);

    d0 = (u8 *)(arg2->unk_4 + arg1->unk_0);
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 8);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 9);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 10);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 11);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 12);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 13);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 14);
    d0 += st0;
    *(f64 *)d0 = fn_12_7E58_array_read(arg0->v, 15);

    st1 = arg2->unk_E & ~7;

    q0 = (u8 *)(arg2->unk_8 + arg1->unk_4);
    q1 = q0 + 8;

    w = arg0->w;
    p = w + 3;
    s = w + 11;

    *(f64 *)q0 = fn_12_7E58_array_read(w, 0);
    *(f64 *)q1 = fn_12_7E58_array_read(w, 8);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(w, 1);
    *(f64 *)q1 = fn_12_7E58_array_read(w, 9);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(w, 2);
    q0 += st1;
    *(f64 *)q1 = fn_12_7E58_array_read(w, 10);
    q1 += st1;

    *(f64 *)q0 = fn_12_7E58_array_read(p, 0);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 0);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 1);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 1);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 2);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 2);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 3);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 3);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 4);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 4);
    q0 += st1;
    q1 += st1;

    *(f64 *)q0 = fn_12_7E58_array_read(p, 13);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 13);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 14);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 14);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 15);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 15);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 16);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 16);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 17);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 17);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 18);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 18);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 19);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 19);
    q0 += st1;
    q1 += st1;
    *(f64 *)q0 = fn_12_7E58_array_read(p, 20);
    *(f64 *)q1 = fn_12_7E58_array_read(s, 20);
}
/* fzgx:end fn_12_7E58 */

/* fzgx:begin fn_12_80BC */
#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

/* --- rel/movie_module/fn_12_80BC.c --- */
/* --- rel/movie_module/fn_12_80BC.c --- */
/* --- rel/movie_module/fn_12_80BC.c --- */

void fn_12_80BC(f64 *output, MovieDecodeContext *context, s32 mask) {
    u8 *data;
    u8 *ref;
    s16 *table;
    u8 *lookup;
    s32 count;
    s32 i;
    u8 last;

    table = context->table;
    data = context->data;
    ref = context->ref;
    lookup = context->lookup;
    count = 0;
    do {
        if (mask >= 0) {
            table += 0x40;
            for (i = 0; i < 8; i++) {
                data[0] = (data[0] + ref[0] + 1) >> 1;
                data[1] = (data[1] + ref[1] + 1) >> 1;
                data[2] = (data[2] + ref[2] + 1) >> 1;
                data[3] = (data[3] + ref[3] + 1) >> 1;
                data[4] = (data[4] + ref[4] + 1) >> 1;
                data[5] = (data[5] + ref[5] + 1) >> 1;
                data[6] = (data[6] + ref[6] + 1) >> 1;
                last = ref[7];
                data[7] = (data[7] + last + 1) >> 1;
                ref += 8;
                data += 8;
            }
        } else {
            for (i = 0; i < 8; i++) {
                data[0] = lookup[((data[0] + ref[0] + 1) >> 1) + table[0]];
                data[1] = lookup[((data[1] + ref[1] + 1) >> 1) + table[1]];
                data[2] = lookup[((data[2] + ref[2] + 1) >> 1) + table[2]];
                data[3] = lookup[((data[3] + ref[3] + 1) >> 1) + table[3]];
                data[4] = lookup[((data[4] + ref[4] + 1) >> 1) + table[4]];
                data[5] = lookup[((data[5] + ref[5] + 1) >> 1) + table[5]];
                data[6] = lookup[((data[6] + ref[6] + 1) >> 1) + table[6]];
                last = ref[7];
                data[7] = lookup[((data[7] + last + 1) >> 1) + table[7]];
                ref += 8;
                data += 8;
                table += 8;
            }
        }
        {
            s32 j;
            for (j = 0; j < 8; j++) {
                output[j] = ((f64 *)data)[j - 8];
            }
        }
        output += 8;
        mask <<= 1;
        count++;
    } while (count < 6);
}
/* fzgx:end fn_12_80BC */

/* fzgx:begin fn_12_8344 */
/* --- rel/movie_module/fn_12_8344.c --- */

void fn_12_8344(f64 *output, MovieDecodeContext_u1 *context, s32 mask) {
    u8 *data;
    s16 *table;
    s32 i;
    u8 *lookup;
    s32 count;
    u8 *next;

    table = context->table;
    data = context->data;
    lookup = context->lookup;
    count = 0;
    do {
        if (mask >= 0) {
            table += 0x40;
        } else {
            for (i = 0; i < 8; i++) {
                data[0] = lookup[data[0] + table[0]];
                data[1] = lookup[data[1] + table[1]];
                data[2] = lookup[data[2] + table[2]];
                data[3] = lookup[data[3] + table[3]];
                data[4] = lookup[data[4] + table[4]];
                data[5] = lookup[data[5] + table[5]];
                data[6] = lookup[data[6] + table[6]];
                data[7] = lookup[data[7] + table[7]];
                data += 8;
                table += 8;
            }
            data -= 0x40;
        }
        next = data + 0x40;
        for (i = 0; i < 8; i++) {
            output[i] = ((f64 *)data)[i];
        }
        data = next;
        output += 8;
        mask <<= 1;
        count++;
    } while (count < 6);
}
/* fzgx:end fn_12_8344 */

/* fzgx:begin fn_12_847C */
/* --- rel/movie_module/fn_12_847C.c --- */
typedef struct Fn847C_Dest {
    u8 pad_0[0x18];
    u32 unk_18;
    u8 pad_1c[4];
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
} Fn847C_Dest;

extern void (*lbl_12_bss_4E40[2][4])(void *);

void fn_12_847C(void *obj, u32 arg1, s32 *arg2, u8 *arg3, s32 *arg4) {
    s32 ah;
    s32 al;
    s32 h;
    s32 w;
    s32 x;
    s32 y;
    Fn847C_Dest *d;
    void (*f)(void *);
    void (*g)(void *);
    s32 sel;
    s32 a;
    s32 b;
    s32 v;

    sel = *(s32 *)((u8 *)obj + 0x19C);
    w = *(s16 *)(arg3 + 0xE);
    h = *(s16 *)(arg3 + 0xC);
    (*(void (**)(void *, u32))((u8 *)obj + 0x290))((void *)obj, *(u32 *)((u8 *)obj + 0x308));
    a = arg4[6];
    b = arg4[7];
    ah = (a / 2) & 1;
    al = a & 1;
    x = ((((b / 2) >> 1) * h) + ((arg2[0]) + (((a / 2) >> 1))));
    y = (((b >> 1) * w) + ((arg2[1]) + ((a >> 1))));
    f = lbl_12_bss_4E40[sel][(((b / 2) & 1) << 1) + ah];
    g = lbl_12_bss_4E40[sel][((b & 1) << 1) + al];
    d = (Fn847C_Dest *)((u8 *)obj + 0xCC);
    d->unk_20 = h;
    d->unk_18 = arg1;
    v = *(s32 *)arg3 + x;
    d->unk_24 = v;
    d->unk_28 = (h + (ah & (sel != 0 ? -1 : 0))) + v;
    f(d);
    d->unk_18 = arg1 + 0x40;
    v = *(s32 *)(arg3 + 4) + x;
    d->unk_24 = v;
    d->unk_28 = (h + (ah & (sel != 0 ? -1 : 0))) + v;
    f(d);
    d->unk_20 = w;
    d->unk_18 = arg1 + 0x80;
    v = *(s32 *)(arg3 + 8) + y;
    d->unk_24 = v;
    d->unk_28 = (w + (al & (sel != 0 ? -1 : 0))) + v;
    g(d);
    d->unk_18 = arg1 + 0xC0;
    d->unk_24 = d->unk_24 + 8;
    d->unk_28 = d->unk_28 + 8;
    g(d);
    d->unk_18 = arg1 + 0x100;
    d->unk_24 = d->unk_24 + (w - 1) * 8;
    d->unk_28 = d->unk_28 + (w - 1) * 8;
    g(d);
    d->unk_18 = arg1 + 0x140;
    d->unk_24 = d->unk_24 + 8;
    d->unk_28 = d->unk_28 + 8;
    g(d);
}
/* fzgx:end fn_12_847C */

/* fzgx:begin fn_12_86B8 */

void fn_12_86B8(void *arg0) {
    u32 temp_r3;
    s32 sp8;
    void *temp_r31;
    void *temp_r30;
    u32 field_118;
    void * lab_t2;
    void * lab_t2_;

    temp_r31 = (void *)((u8 *)(arg0) + 0x234);
    temp_r30 = (void *)((u8 *)(arg0) + 0x110);
    lab_t2 = (void *)(&sp8);
    lab_t2_ = lab_t2;
    fn_12_847C((void *)(arg0), (u32)(*(u32 *)((u8 *)(arg0) + 280)), (s32 *)(void *)(lab_t2_), (u8 *)((void *)(temp_r31)), (s32 *)((void *)((u8 *)(arg0) + 0x2C0)));
    lab_t2 = (void *)(&sp8);
    lab_t2_ = lab_t2;
    fn_12_847C((void *)(arg0), (u32)(*(u32 *)((u8 *)(temp_r30) + 12)), (s32 *)(void *)(lab_t2_), (u8 *)((void *)((u8 *)(temp_r31) + 0x10)), (s32 *)((void *)((u8 *)(arg0) + 0x2E4)));
    temp_r3 = *(u32 *)((u8 *)(arg0) + 596);
    (*(u32 *)((u8 *)(arg0) + 596)) = (u32) (temp_r3 + 0x180);
    fn_12_80BC( (f64 *)((u32)(temp_r3)), (MovieDecodeContext *)((void *)(temp_r30)), (u32)(*(u32 *)((u8 *)(arg0) + 788)));
}
/* fzgx:end fn_12_86B8 */

/* fzgx:begin fn_12_873C */
/* --- rel/movie_module/fn_12_873C.c --- */
typedef struct fn_12_873C_MovieModule {
    u8 _pad110[0x110];
    u32 field_110;
    u8 _pad114[4];
    u32 field_118;
    u8 _pad11c[0x128];
    u32 field_244;
    u8 _pad248[0xc];
    u32 field_254;
    u8 _pad258[0x8c];
    u32 field_2e4;
    u8 _pad2e8[0x2c];
    u32 field_314;
} fn_12_873C_MovieModule;


#pragma opt_propagation off
void fn_12_873C(fn_12_873C_MovieModule *module) {
    u32 *field110 = &module->field_110;
    u32 value;

    fn_12_847C(module, module->field_118, (s32 *)(void *)(&value), (u8 *)(void *)(&module->field_244), (s32 *)(void *)(&module->field_2e4));
    {
        u32 old_value = module->field_254;
        module->field_254 = old_value + 0x180;
        fn_12_8344( (f64 *)(u32)(old_value), (MovieDecodeContext_u1 *)(u32 *)(field110), module->field_314);
    }
}
/* fzgx:end fn_12_873C */

/* fzgx:begin fn_12_879C */
#pragma opt_propagation reset

/* --- rel/movie_module/fn_12_879C.c --- */
typedef struct MovieModule_u2 {
    u8 _pad110[0x110];
    u32 field_110;
    u8 _pad114[4];
    u32 field_118;
    u8 _pad11c[0x118];
    u32 field_234;
    u8 _pad238[0x1c];
    u32 field_254;
    u8 _pad258[0x68];
    u32 field_2c0;
    u8 _pad2c4[0x50];
    u32 field_314;
} MovieModule_u2;

#pragma opt_propagation off
void fn_12_879C(MovieModule_u2 *module) {
    u32 *field110 = &module->field_110;
    u32 value;

    fn_12_847C(module, module->field_118, (s32 *)(void *)(&value), (u8 *)(void *)(&module->field_234), (s32 *)(void *)(&module->field_2c0));
    {
        u32 old_value = module->field_254;
        module->field_254 = old_value + 0x180;
        fn_12_8344( (f64 *)(u32)(old_value), (MovieDecodeContext_u1 *)(u32 *)(field110), module->field_314);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_12_879C */

/* fzgx:begin fn_12_87FC */
/* --- rel/movie_module/fn_12_87FC.c --- */
typedef struct fn_12_87FC_MovieModule {
    u8 _pad0[0x110];
    u32 field_110;
    u8 _pad114[0x4];
    u32 field_118;
    u8 _pad11c[0x118];
    u8 field_234[0x20];
    u32 field_254;
    u8 _pad258[0x68];
    u8 field_2c0[0x54];
    u32 field_314;
} fn_12_87FC_MovieModule;


#pragma opt_dead_assignments off
void fn_12_87FC(fn_12_87FC_MovieModule *module) {
    u8 local[8];
    u8 *field_234 = module->field_234;
    u8 *field_110 = (u8 *)module + 0x110;
    void * lab_t2;
    lab_t2 = local;
    fn_12_847C(module, module->field_118, (s32 *)(void *)(lab_t2), (u8 *)(void *)(field_234), (s32 *)(void *)((u8 *)module + 0x2c0));
    {
        u32 value = module->field_254;
        module->field_254 = value + 0x180;
        fn_12_8344( (f64 *)(u32)(value), (MovieDecodeContext_u1 *)(void *)(field_110), module->field_314);
    }
    fn_12_7E58( (struct fn_12_7E58_a *)(void *)(*(void **)(field_110 + 8)), (struct fn_12_7E58_b *)(void *)(local), (struct fn_12_7E58_c_u0 *)(void *)(field_234 + 0x10));
}
/* fzgx:end fn_12_87FC */

/* fzgx:begin fn_12_8878 */
#pragma opt_dead_assignments reset

/* --- rel/movie_module/fn_12_8878.c --- */
static inline void decode8(u8 *dst, const s16 *source, const u8 *table) {
    dst[0] = table[source[0]];
    dst[1] = table[source[1]];
    dst[2] = table[source[2]];
    dst[3] = table[source[3]];
    dst[4] = table[source[4]];
    dst[5] = table[source[5]];
    dst[6] = table[source[6]];
    dst[7] = table[source[7]];
}

void fn_12_8878(s16 *source, f64 *output, u32 *entries, const u8 *table) {
    u32 *p;
    s32 groups;
    u8 *base;
    s32 stride;
    u8 *dst;
    s32 rows;
    s32 i;

    p = entries + 1;
    for (groups = 6; groups > 0; groups--) {
        dst = (u8 *)p[0];
        stride = (s32)p[1];
        p += 2;
        base = dst;
        for (rows = 8; rows != 0; rows--) {
            decode8(dst, source, table);
            dst += stride;
            source += 8;
        }
        stride &= ~7;
        for (rows = 0; rows < 8; rows++) {
            *output++ = *(f64 *)base;
            base += stride;
        }
    }
}
/* fzgx:end fn_12_8878 */

/* fzgx:begin fn_12_89D4 */
/* --- rel/movie_module/fn_12_89D4.c --- */
/* --- rel/movie_module/fn_12_89D4.c --- */
typedef struct fn_12_89D4_MovieModule {
    u8 _pad0[0x40];
    void *field_40;
    u8 _pad44[0x110];
    u8 field_154;
    u8 _pad155[0xff];
    u32 field_254;
    u8 _pad258[0xe8];
    u8 field_340;
} fn_12_89D4_MovieModule;


void fn_12_89D4(fn_12_89D4_MovieModule *module) {
    u32 value = module->field_254;

    module->field_254 = value + 0x180;
    fn_12_8878( (s16 *)(void *)(&module->field_340), (f64 *)(u32)(value), (u32 *)(void *)(&module->field_154), (const u8 *)(void *)(module->field_40));
}
/* fzgx:end fn_12_89D4 */

/* fzgx:begin fn_12_8A10 */
/* --- rel/movie_module/fn_12_8A10.c --- */
typedef u32 (*fn_12_8A10_Fn0)(u32, u32, void *, u32);
struct fn_12_8A10_Arg0 {
    u8 pad_0[0x254];
    u32 unk_254;
    u8 pad_258[0x38];
    u32 unk_290;
    u8 pad_294[0x74];
    u32 unk_308;
};

void fn_12_8A10(struct fn_12_8A10_Arg0 *arg0) {
    u32 v0;
    u32 v1;
    u32 v2;
    s16 v3;
    u32 v4;
    struct { u32 a[2]; } loc_8;
    /* frame */
    v0 = ((u32)arg0 + 288);
    v1 = ((u32)arg0 + 580);
    v2 = arg0->unk_254;
    arg0->unk_254 = (v2 + 384);
    ((fn_12_8A10_Fn0)arg0->unk_290)((u32)arg0, arg0->unk_308, &loc_8, v1);
    v3 = *(s16 *)((u8 *)v1 + 14);
    *(u32 *)((u8 *)v0 + 4) = (*(u32 *)((u8 *)v1 + 0) + loc_8.a[0]);
    *(u32 *)((u8 *)v0 + 12) = (*(u32 *)((u8 *)v1 + 4) + loc_8.a[0]);
    v4 = *(u32 *)((u8 *)v1 + 8);
    *(u32 *)((u8 *)v0 + 20) = (v4 + loc_8.a[1]);
    *(u32 *)((u8 *)v0 + 28) = (*(u32 *)((u8 *)v0 + 20) + 8);
    *(u32 *)((u8 *)v0 + 36) = (*(u32 *)((u8 *)v0 + 20) + (v3 << 3));
    *(u32 *)((u8 *)v0 + 44) = (*(u32 *)((u8 *)v0 + 36) + 8);
    fn_12_8878( (s16 *)((void *)((u32)arg0 + 832)), (f64 *)(u32)(v2), (u32 *)((void *)v0), (const u8 *)((void *)*(u32 *)((u8 *)(u32)arg0 + 64)));
}
/* fzgx:end fn_12_8A10 */
