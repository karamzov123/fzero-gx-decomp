/* Non-matching: best partial attempt (94.17% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct Sig_fn_12_7E58_fn_12_7E58_a {
    f64 v[16];
    f64 w[32];
};

struct Sig_fn_12_7E58_fn_12_7E58_b {
    u32 unk_0;
    u32 unk_4;
};

struct Sig_fn_12_7E58_fn_12_7E58_c {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
    s16 unk_C;
    s16 unk_E;
};

typedef struct Sig_fn_12_7E58_fn_12_7E58_a MovieData;
typedef struct Sig_fn_12_7E58_fn_12_7E58_b MovieOut;
typedef struct Sig_fn_12_7E58_fn_12_7E58_c MovieNode;

typedef struct MovieObject MovieObject;

struct MovieObject {
    u8 _pad_000[0xe0];
    u32 dest;
    u32 _pad_0e4;
    u32 stride;
    u32 _pad_0ec;
    u32 in_ptr;
    u8 _pad_0f4[0x140];
    MovieNode nodes[2];
    u32 buf;
    u8 _pad_258[0x38];
    void (*calc)(MovieObject *, s32, MovieOut *, MovieNode *);
    u8 _pad_294[0x74];
    s32 field_308;
    u8 _pad_30c[0x9b4];
    MovieData data;
};

extern void fn_12_7E58(MovieData *, MovieOut *, MovieNode *);

#define LOAD8(d, b, n)                    \
    do {                                  \
        (d)[0] = *(f64 *)(b); (b) += (n);  \
        (d)[1] = *(f64 *)(b); (b) += (n);  \
        (d)[2] = *(f64 *)(b); (b) += (n);  \
        (d)[3] = *(f64 *)(b); (b) += (n);  \
        (d)[4] = *(f64 *)(b); (b) += (n);  \
        (d)[5] = *(f64 *)(b); (b) += (n);  \
        (d)[6] = *(f64 *)(b); (b) += (n);  \
        (d)[7] = *(f64 *)(b);              \
    } while (0);

#define STORE8(d, s)              \
    do {                          \
        (d)[0] = (s)[0];          \
        (d)[1] = (s)[1];          \
        (d)[2] = (s)[2];          \
        (d)[3] = (s)[3];          \
        (d)[4] = (s)[4];          \
        (d)[5] = (s)[5];          \
        (d)[6] = (s)[6];          \
        (d)[7] = (s)[7];          \
    } while (0);

void fn_12_7940(MovieObject *movie, s32 frame) {
    s32 stride;
    MovieData *data = &movie->data;
    MovieNode *node = &movie->nodes[0];
    MovieNode *extra = &movie->nodes[1];
    s32 cols = node->unk_C;
    s32 rows = node->unk_E;
    u32 buf = movie->buf;
    MovieOut out;
    register u8 *b;
    f64 *d;
    u32 n;

    stride = (rows - 1) << 3;
    movie->buf = buf + (frame * 0x180 - 0x180);

    while (frame--) {
        movie->calc(movie, movie->field_308 - frame, &out, node);
        movie->stride = cols;
        movie->dest = buf;

        movie->in_ptr = node->unk_0 + out.unk_0;
        b = (u8 *)movie->in_ptr;
        n = movie->stride & ~7;
        LOAD8(data->v, b, n)
        d = (f64 *)movie->dest;
        STORE8(d, data->v)
        movie->dest = (u32)(d + 8);

        movie->in_ptr = node->unk_4 + out.unk_0;
        b = (u8 *)movie->in_ptr;
        n = movie->stride & ~7;
        LOAD8(data->v + 8, b, n)
        d = (f64 *)movie->dest;
        STORE8(d, data->v + 8)
        movie->stride = rows;
        movie->dest = (u32)(d + 8);

        movie->in_ptr = node->unk_8 + out.unk_4;
        b = (u8 *)movie->in_ptr;
        n = movie->stride & ~7;
        LOAD8(data->w, b, n)
        d = (f64 *)movie->dest;
        STORE8(d, data->w)
        movie->dest = (u32)(d + 8);
        movie->in_ptr = movie->in_ptr + 8;

        b = (u8 *)movie->in_ptr;
        n = movie->stride & ~7;
        LOAD8(data->w + 8, b, n)
        d = (f64 *)movie->dest;
        STORE8(d, data->w + 8)
        movie->dest = (u32)(d + 8);
        movie->in_ptr = movie->in_ptr + 8;

        b = (u8 *)movie->in_ptr;
        n = movie->stride & ~7;
        LOAD8(data->w + 16, b, n)
        d = (f64 *)movie->dest;
        STORE8(d, data->w + 16)
        movie->dest = (u32)(d + 8);
        movie->in_ptr = movie->in_ptr + stride;

        b = (u8 *)movie->in_ptr;
        n = movie->stride & ~7;
        LOAD8(data->w + 24, b, n)
        d = (f64 *)movie->dest;
        STORE8(d, data->w + 24)

        fn_12_7E58(data, &out, extra);
    }
}
