/* Non-matching: best partial attempt (78.72% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/accessory.h"

extern void lbl_8006DAEC(void);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DBE4(void);
extern void lbl_8006DC20(void);
extern void lbl_8006E1B0(void *, void *);
extern void fn_8006E250(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D118(void *);
extern f32 lbl_8006D188(u32);
extern f32 lbl_8006D668(void *);
extern int fn_80083BCC(const char *, const char *);
extern s32 fn_80077B14(void *);
extern void fn_1_108128(void *, u32);
extern void fn_1_1286F4(void *);
extern const char *fn_1_950E8(void *);
extern u32 lbl_801A63C0;
extern u32 lbl_801A66A0;
extern f32 lbl_1_rodata_7AB8[9];

typedef struct {
    f32 x, y, z;
} Vec;

typedef struct {
    u8 flag;
    u8 pad_1;
    u8 cnt;
    u8 pad_3;
    u16 idx[1];
    u8 pad[0xA];
    Vec pos;
    Vec prev;
    Vec unk28;
    Vec vel;
    f32 mass;
} Part;

typedef struct {
    u32 id;
    u32 bone;
    f32 range;
} Pair;

typedef struct {
    u8 pad_8[8];
    u8 *base;
} Chunk;

typedef struct {
    u8 pad_150[0x150];
    Chunk *chunk;
} Model;

typedef struct {
    u8 flags;
    u8 pad_1[3];
    u16 pad_4;
    u16 pad_6;
    u32 index;
    Model *model;
    void *handle;
    u32 unk_14;
    u32 count;
    u32 pairCount;
    u32 unk_20;
    Part *parts;
    Pair *pairs;
} Obj;

#define ROD(o) (*(const f64 *)(K + (o)))
#define ROF(o) (*(const f32 *)(K + (o)))
#define BASE(v) ((v)->model->chunk->base)
#define TBL(v) (*(const u32 *)(D + 0xAAC + (v)->index * 4))

#define SOLVE(aa, bb, pp, dist, vv)                                                  \
    do {                                                                             \
        f32 s_ = lbl_8006D118(&(dist));                                               \
        f32 t_ = lbl_8006D0B4((pp)->range);                                          \
        f32 f_ = s_ * (dist - t_);                                                   \
        f32 vx_ = (vv).x * f_;                                                       \
        f32 vy_ = (vv).y * f_;                                                       \
        f32 vz_ = (vv).z * f_;                                                       \
        f32 ma_ = (aa)->mass;                                                        \
        f32 mb_ = (bb)->mass;                                                        \
        f32 sum_ = ma_ + mb_;                                                        \
        f32 ra_ = ROF(0xa0) / sum_;                                                  \
        f32 a2_ = ma_ * ra_;                                                         \
        f32 b2_ = mb_ * ra_;                                                         \
        (aa)->pos.x = (aa)->pos.x - vx_ * a2_;                                        \
        (aa)->pos.y = (aa)->pos.y - vy_ * a2_;                                        \
        (aa)->pos.z = (aa)->pos.z - vz_ * a2_;                                        \
        (bb)->pos.x = (bb)->pos.x + vx_ * b2_;                                        \
        (bb)->pos.y = (bb)->pos.y + vy_ * b2_;                                        \
        (bb)->pos.z = (bb)->pos.z + vz_ * b2_;                                        \
    } while (0)

#define ATLOOP(ofs, cxv, thr, fac, C_, T_)                                            \
    do {                                                                             \
        Part *q = o->parts;                                                          \
        C_.x = (cxv);                                                                \
        C_.y = k0;                                                                   \
        C_.z = k0;                                                                   \
        lbl_8006DBAC((void *)(BASE(o) + (ofs)));                                     \
        lbl_8006E1B0(&C_, &C_);                                                      \
        for (j = 0; j < o->count; j++, q++) {                                        \
            if (!(q->flag & 1)) {                                                    \
                f32 dx = q->pos.x - C_.x;                                            \
                f32 dy = q->pos.y - C_.y;                                            \
                f32 dz = q->pos.z - C_.z;                                            \
                f32 d = dx * dx;                                                     \
                d = dy * dy + d;                                                     \
                d = dz * dz + d;                                                     \
                if (d < (thr)) {                                                     \
                    f32 sc = ROF(fac) * lbl_8006D0E8(d);                             \
                    psvec_sub_scale_add(&q->pos, &C_, sc, &T_, &q->pos);              \
                }                                                                    \
            }                                                                        \
        }                                                                            \
    } while (0)

#define RNG1(g)                                                                       \
    do {                                                                              \
        seed = lbl_801A63C0;                                                          \
        seed = seed * 0x676A4B6Bu + 0x33CBu;                                          \
        lbl_801A63C0 = seed;                                                          \
        g = (f32)((c18 + (f64)(((seed >> 1) & 0x7FFF) ^ 0x8000)) - c23);              \
        g = g / c24;                                                                  \
    } while (0)

#define NOISE(g, div)                                                                 \
    do {                                                                              \
        s32 nd_ = (s32)((i + lbl_801A66A0) % (div));                                  \
        f32 t_ = (f32)(c18 + (f64)nd_);                                               \
        t_ = t_ * c27 / c28 + c26;                                                    \
        g = lbl_8006D188((s32)t_);                                                    \
    } while (0)

void fn_1_110478(Obj *o) {
    const u8 *K;
    u8 *D;
    u32 i;
    u32 j;
    u32 seed;
    Part *p;
    Part *qa;
    Part *qb;
    Pair *pr;
    f32 len;
    Vec c6, t6;
    Vec c5, t5;
    Vec c4, t4;
    Vec c3, t3;
    Vec c2, t2;
    Vec c1, t1;
    Vec v;
    Vec dif;
    Vec w;
    Vec tv;
    f32 dx, dy, dz;
    f32 k0, k1, k2, k3;
    u8 *tblbase;

    K = (const u8 *)lbl_1_rodata_7AB8;
    D = (u8 *)lbl_1_data_3F510;

    if (o == 0) {
        return;
    }
    if (o->handle == 0) {
        return;
    }
    fn_80077B14(o->handle);
    if (o->flags & 2) {
        o->flags &= 0xFD;
        lbl_8006DBAC((void *)(BASE(o) + TBL(o) * 0x18C + 0x88));
        lbl_8006DAEC();
        p = o->parts;
        for (i = 0; i < o->count; i++, p++) {
            lbl_8006DBE4();
            lbl_8006E1B0(&p->unk28, &p->pos);
        }
        lbl_8006DC20();
    }
    p = o->parts;
    for (i = 0; i < o->count; i++, p++) {
        if (!(p->flag & 1)) {
            p->prev = p->pos;
            p->pos.x = p->pos.x + p->vel.x;
            p->pos.y = p->pos.y + p->vel.y;
            p->pos.z = p->pos.z + p->vel.z;
            p->pos.y = (f32)((f64)p->pos.y - ROD(0x58));
            p->vel.y = p->vel.y - ROF(0x60);
        }
    }
    tblbase = BASE(o) + TBL(o) * 0x18C;
    p = o->parts;
    for (i = 0; i < o->count; i++, p++) {
        lbl_8006DBAC((void *)(tblbase + 0x88));
        lbl_8006DAEC();
        if (p->flag & 1) {
            lbl_8006DBE4();
            lbl_8006E1B0(&p->unk28, &p->pos);
        }
        lbl_8006DC20();
    }

    k0 = ROF(0x68);
    k1 = ROF(0x1a8);
    k2 = ROF(0x1d0);
    k3 = ROF(0x1dc);
    j = 0;
    do {
        pr = o->pairs;
        for (i = 0; i < o->pairCount; i++, pr++) {
            qa = (Part *)pr->id;
            qb = (Part *)pr->bone;
            if (qa == 0 || qb == 0) {
                continue;
            }
            dx = qa->pos.x - qb->pos.x;
            dy = qa->pos.y - qb->pos.y;
            dz = qa->pos.z - qb->pos.z;
            tv.x = dx;
            tv.y = dy;
            tv.z = dz;
            len = dx * dx;
            len = dy * dy + len;
            len = dz * dz + len;
            if (len - ROF(0x9c) > pr->range) {
                SOLVE(qa, qb, pr, len, tv);
            }
            if (qa->pos.y < k0 || qb->pos.y < k0) {
                if (qa->pos.y < k0) {
                    qa->pos.y = ROF(0x248);
                }
                if (qb->pos.y < k0) {
                    qb->pos.y = ROF(0x248);
                }
                dx = qa->pos.x - qb->pos.x;
                dy = qa->pos.y - qb->pos.y;
                dz = qa->pos.z - qb->pos.z;
                tv.x = dx;
                tv.y = dy;
                tv.z = dz;
                len = dx * dx;
                len = dy * dy + len;
                len = dz * dz + len;
                SOLVE(qa, qb, pr, len, tv);
            }
        }
        ATLOOP(0x214, k1, ROF(0x1ac), 0x1b0, c1, t1);
        ATLOOP(0x1948, k0, ROF(0x1b4), 0x1b8, c2, t2);
        ATLOOP(0x1c60, k2, ROF(0x1d4), 0x1d8, c3, t3);
        ATLOOP(0x1c60, k3, ROF(0x1e0), 0x1e4, c4, t4);
        ATLOOP(0x241c, k2, ROF(0x1d4), 0x1d8, c5, t5);
        ATLOOP(0x241c, k3, ROF(0x1e0), 0x1e4, c6, t6);
        j++;
    } while (j < 4);

    if (fn_80083BCC(fn_1_950E8((void *)((u8 *)o->model + 0x148)),
                   *(const char **)(D + 0x1040)) &&
        fn_80083BCC(fn_1_950E8((void *)((u8 *)o->model + 0x148)),
                    *(const char **)(D + 0x1048))) {
        f32 c16 = ROF(0x1c8);
        f32 c17 = ROF(0x200);
        f64 c18 = ROD(0x50);
        f32 c19 = ROF(0x204);
        f64 c20 = ROD(0x190);
        f64 c21 = ROD(0x188);
        f32 c22 = ROF(0x208);
        f64 c23 = ROD(0x240);
        f32 c24 = ROF(0x20c);
        f32 c25 = ROF(0x24c);
        f32 c26 = ROF(0x218);
        f32 c27 = ROF(0x21c);
        f32 c28 = ROF(0x220);
        f32 c29 = ROF(0x214);
        f32 c30 = ROF(0x228);
        f32 c31 = ROF(0x250);
        p = o->parts;
        for (i = 0; i < o->count; i++, p++) {
            {
                s32 kk = (s32)(i % 9);
                f64 dk = c18 + (f64)kk;
                f64 dk2 = c18 + (f64)(9 - kk);
                f32 f15 = c16 + (f32)(dk2 - c18) * c17 / c19;
                f32 f14 = c16 + (f32)(dk - c18) * c17 / c19;
                f32 g1, g2, g3, g4;
                p->vel.x = (f32)((f64)p->vel.x * c20);
                p->vel.y = (f32)((f64)p->vel.y * c20);
                p->vel.z = (f32)((f64)p->vel.z * c20);
                p->vel.x = (f32)((f64)p->vel.x + c21 * (p->pos.x - p->prev.x));
                p->vel.y = (f32)((f64)p->vel.y + c21 * (p->pos.y - p->prev.y));
                p->vel.z = (f32)((f64)p->vel.z + c21 * (p->pos.z - p->prev.z));
                RNG1(g1);
                p->vel.x = p->vel.x - c22 * g1 * f15;
                RNG1(g2);
                p->vel.y = p->vel.y + c25 * g2 * f15;
                NOISE(g3, 39);
                p->vel.z = p->vel.z + c29 * g3 * f15;
                RNG1(g4);
                p->vel.z = p->vel.z + c22 * g4 * f14;
                RNG1(g4);
                p->vel.y = p->vel.y + c31 * g4 * f14;
                NOISE(g4, 29);
                p->vel.x = p->vel.x + c29 * g4 * f14;
            }
        }
    } else {
        f64 d80 = ROD(0x190);
        f64 d20 = ROD(0x188);
        f64 d50 = ROD(0x198);
        if (lbl_801A66A0 % 60 < 20) {
            tblbase = BASE(o) + TBL(o) * 0x18C;
            p = o->parts;
            for (i = 0; i < o->count; i++, p++) {
                lbl_8006DBAC((void *)(tblbase + 0x88));
                lbl_8006E1B0(&p->unk28, &v);
                dif.x = p->pos.x - v.x;
                dif.y = p->pos.y - v.y;
                dif.z = p->pos.z - v.z;
                lbl_8006D668(&dif);
                p->vel.x = p->vel.x - ROF(0x1a4) * dif.x;
                p->vel.y = p->vel.y - ROF(0x1a4) * dif.y;
                p->vel.z = p->vel.z - ROF(0x1a4) * dif.z;
            }
        }
        p = o->parts;
        for (i = 0; i < o->count; i++, p++) {
            fn_1_1286F4(&w);
            p->vel.x = (f32)((f64)p->vel.x * d80);
            p->vel.y = (f32)((f64)p->vel.y * d80);
            p->vel.z = (f32)((f64)p->vel.z * d80);
            p->pos.x = (f32)((f64)p->vel.x + d20 * (p->pos.x - p->prev.x));
            p->pos.y = (f32)((f64)p->vel.y + d20 * (p->pos.y - p->prev.y));
            p->pos.z = (f32)((f64)p->vel.z + d20 * (p->pos.z - p->prev.z));
            p->vel.x = (f32)((f64)p->vel.x + d50 * w.x);
            p->vel.y = (f32)((f64)p->vel.y + d50 * w.y);
            p->vel.z = (f32)((f64)p->vel.z + d50 * w.z);
        }
    }

    fn_1_108128(o, 9);
    {
        void *hd = (void *)fn_80077B14(o->handle);
        lbl_8006DBAC((void *)(BASE(o) + TBL(o) * 0x18C + 0x88));
        p = o->parts;
        for (i = 0; i < o->count; i++, p++) {
            for (j = 0; j < p->cnt; j++) {
                fn_8006E250(&p->pos, (void *)((u8 *)hd + p->idx[j] * 64));
            }
        }
    }
}
