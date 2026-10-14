/* Non-matching: best partial attempt (83.03% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef void (*Sig_fn_12_24A88_MovieCallback)(void *, s32);

typedef struct Sig_fn_12_24A88_MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    Sig_fn_12_24A88_MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} Sig_fn_12_24A88_MovieObject;

typedef struct MovieEntry {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 payload[0x14];
} MovieEntry;

typedef struct MovieList {
    u8 pad_00[0x0c];
    s32 f0c;
    s16 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    s16 f20;
    u32 f24;
    u32 f28[2];
    u32 u30[0x36];
    u32 f108;
    u32 f10c;
    u32 f110;
    u16 f114;
    u16 f116;
    u32 f118;
    u32 f11c;
    u32 f120;
    u16 f124;
    u16 f126;
    u32 f128;
    u32 f12c;
    u32 f130;
    u32 f134;
    MovieEntry ent[16];
} MovieList;

typedef struct MovieObject {
    u8 pad_00[0x38];
    s32 f38;
    u8 pad_3c[0x1af4];
    MovieList *list;
} MovieObject;

typedef struct MovieSize {
    s32 height;
    s32 width;
} MovieSize;

extern s32 fn_12_24A88(Sig_fn_12_24A88_MovieObject *movie, s32 code);
extern u32 *fn_12_2AB68(MovieObject *movie);
extern void fn_12_33428(u32 *data, u32 a, u32 b);

static void setup_entry(MovieEntry *e, u32 value) {
    e->f00 = 0;
    e->f04 = value;
    e->f08 = 0;
    e->f0c = 1;
    e->f10 = 0;
    e->f14 = 0;
    e->f18 = 0;
    e->f1c = 0;
    e->f20 = 0;
    fn_12_33428(e->payload, 0xffffffff, 0x14);
}

#pragma opt_loop_invariants off
s32 fn_12_27C58(MovieObject *movie, MovieSize *size) {
    s32 cnt;
    MovieList *list;
    s32 qa, qb, qc, qd;
    s32 w1, w2, w3, w4;
    s32 v5, v6, v8, v12;
    s32 d1, d2;
    s32 sz1, sz2;
    s32 n, i, j, sum, lim, maxn;
    u32 base;
    MovieEntry *ent;

    list = movie->list;
    ent = list->ent;

    qa = (size->height + 15) / 16;
    v5 = (((qa << 4) + 312) / 32) << 5;
    w1 = ((qa << 5) + ((qa >> 27) & 1)) / 2;
    v8 = ((w1 + 31) / 32) << 5;
    qb = (size->height + 15) / 16;
    w2 = ((qb << 4) + ((qb >> 27) & 1)) / 2;
    qc = (list->f0c + 15) / 16;
    w3 = ((qc << 4) + ((qc >> 27) & 4)) / 2;
    v12 = (((qc << 4) + 312) / 32) << 5;
    v6 = ((w3 + 312) / 32) << 5;
    qd = (list->f10 + 15) / 16;
    w4 = ((qd << 4) + ((qd >> 27) & 1)) / 2;
    d1 = (qb << 4) * v5;
    d2 = w2 * v8;
    sz1 = d1 + d2 * 2 + 32;
    sz2 = (qd << 4) * v12 + w4 * v6 * 2 + 32;

    if (sz1 * 2 > sz2 * 2) {
        return fn_12_24A88((Sig_fn_12_24A88_MovieObject *)movie, 0xff000f17);
    }

    maxn = list->f20;
    base = list->f24;
    n = maxn;

    if (base != 0) {
        sum = sz1;
        lim = maxn * sz2;
        n = 1;

        for (j = 0; j < 2; j++) {
            if (sum > lim) {
                n--;
                break;
            }
            sum += sz1;
            if (sum > lim) {
                break;
            }
            sum += sz1;
            if (sum > lim) {
                n++;
                break;
            }
            sum += sz1;
            if (sum > lim) {
                n += 2;
                break;
            }
            sum += sz1;
            if (sum > lim) {
                n += 3;
                break;
            }
            sum += sz1;
            if (sum > lim) {
                n += 4;
                break;
            }
            sum += sz1;
            if (sum > lim) {
                n += 5;
                break;
            }
            sum += sz1;
            if (sum > lim) {
                n += 6;
                break;
            }
            sum += sz1;
            n += 8;
        }

        if (n < maxn) {
            return fn_12_24A88((Sig_fn_12_24A88_MovieObject *)movie, 0xff000f17);
        }

        list->f28[0] = list->f14;
        list->f28[1] = list->f14 + sz1;

        for (i = 0; i < n; i++) {
            list->u30[i] = base + i * sz1;
        }
    }

    list->f116 = v5;
    list->f114 = v8;
    list->f110 = (*((list->f28) + (0)));
    list->f108 = list->f110 + d1;
    list->f10c = list->f108 + d2;
    list->f126 = v5;
    list->f124 = v8;
    list->f120 = (*((list->f28) + (1)));
    list->f118 = list->f120 + d1;
    list->f11c = list->f118 + d2;

    if (movie->f38 == 3) {
        cnt = (n < 14) ? n : 14;

        list->f134 = cnt + 2;

        for (i = 0; i < 2; i++) {
            setup_entry(&ent[i], (*((list->f28) + (i))));
        }

        for (i = 0; i < cnt; i++) {
            setup_entry(&ent[i + 2], (*((list->u30) + (i))));
        }

        list->f128 = (u32)fn_12_2AB68(movie);
        list->f12c = (u32)fn_12_2AB68(movie);
    } else {
        cnt = (n < 16) ? n : 16;

        list->f134 = cnt;

        for (i = 0; i < cnt; i++) {
            setup_entry(&list->ent[i], (*((list->u30) + (i))));
        }
    }

    return 0;
}
#pragma opt_loop_invariants reset

