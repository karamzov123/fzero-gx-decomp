/* Non-matching: best partial attempt (94.92% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct V3 {
    f32 v[3];
} V3;

typedef struct Particle {
    u8 flags;
    u8 pad_1;
    u8 nmat;
    u8 pad_3;
    u16 idx[6];
    f32 pos[3];
    f32 prev[3];
    f32 vec[3];
    f32 vel[3];
    f32 mass;
} Particle;

typedef struct Constraint {
    Particle *a;
    Particle *b;
    f32 dist;
} Constraint;

typedef struct OwnerInner {
    u8 pad_0[8];
    u8 *base;
} OwnerInner;

typedef struct Owner {
    u8 pad_0[0x88];
    s32 kind;
    u8 pad_8C[0x150 - 0x8C];
    OwnerInner *inner;
} Owner;

typedef struct Cloth {
    u8 flags;
    u8 pad_1[7];
    u32 index;
    Owner *owner;
    void *unk_10;
    u8 pad_14[4];
    u32 count;
    u32 ncons;
    u8 pad_20[4];
    Particle *parts;
    Constraint *cons;
} Cloth;

extern u32 lbl_1_data_3FFBC[];
extern void *fn_80077B14(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DAEC(void);
extern void lbl_8006DBE4(void);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006DC20(void);
extern f32 lbl_8006D118(f32 *);
extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D0E8(f32);
extern void fn_8006E250(void *, void *);
extern void fn_1_1286F4(void *);

static inline void vsub(f32 *a, f32 *b, f32 *o) {
    o[0] = a[0] - b[0];
    o[1] = a[1] - b[1];
    o[2] = a[2] - b[2];
}

static inline f32 vmag2(f32 *v) {
    return v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
}

#define SPRING(loc, tmp, X, Y, Z, thr, sc)                                     \
    loc[1] = (Y);                                                              \
    loc[0] = (X);                                                              \
    loc[2] = (Z);                                                              \
    lbl_8006DBAC(c->owner->inner->base + 0x214);                               \
    lbl_8006E1B0(loc, loc);                                                    \
    p = c->parts;                                                              \
    for (i = 0; i < c->count; i++, p++) {                                      \
        if (!(p->flags & 1)) {                                                 \
            f32 dx = p->pos[0] - loc[0];                                       \
            f32 dy = p->pos[1] - loc[1];                                       \
            f32 dz = p->pos[2] - loc[2];                                       \
            f32 dd = dx * dx + dy * dy + dz * dz;                              \
            if (dd < (thr)) {                                                  \
                psvec_sub_scale_add(p->pos, loc, (sc) * lbl_8006D0E8(dd), tmp, \
                                    p->pos);                                   \
            }                                                                  \
        }                                                                      \
    }

void fn_1_12744C(Cloth *c) {
    f32 len2;
    f32 rnd[3];
    f32 d[3];
    f32 l0[3], t0[3];
    f32 l1[3], t1[3];
    f32 l2[3], t2[3];
    f32 l3[3], t3[3];
    f32 l4[3], t4[3];
    f32 l5[3], t5[3];
    f32 l6[3], t6[3];
    u32 i, j, k;
    Particle *p;
    void *mats;

    if (c == 0) {
        return;
    }
    if (c->unk_10 == 0) {
        return;
    }
    fn_80077B14(c->unk_10);
    if (c->flags & 2) {
        c->flags &= ~2;
        lbl_8006DBAC(c->owner->inner->base + lbl_1_data_3FFBC[c->index] * 0x18c + 0x88);
        lbl_8006DAEC();
        p = c->parts;
        for (i = 0; i < c->count; i++, p++) {
            lbl_8006DBE4();
            lbl_8006E1B0(p->vec, p->pos);
        }
        lbl_8006DC20();
    }
    p = c->parts;
    for (i = 0; i < c->count; i++, p++) {
        if (!(p->flags & 1)) {
            *(V3 *)p->prev = *(V3 *)p->pos;
            p->pos[0] = p->pos[0] + p->vel[0];
            p->pos[1] = p->pos[1] + p->vel[1];
            p->pos[2] = p->pos[2] + p->vel[2];
            p->pos[1] = p->pos[1] - 0.0013611111376020642;
            p->vel[1] = p->vel[1] - 0.0027222223579883575f;
        }
    }
    {
        u8 *m = c->owner->inner->base + lbl_1_data_3FFBC[c->index] * 0x18c;
        p = c->parts;
        for (i = 0; i < c->count; i++, p++) {
            lbl_8006DBAC(m + 0x88);
            lbl_8006DAEC();
            if (p->flags & 1) {
                lbl_8006DBE4();
                lbl_8006E1B0(p->vec, p->pos);
            }
            lbl_8006DC20();
        }
    }
    for (k = 0; k < 4; k++) {
        Constraint *con = c->cons;
        for (i = 0; i < c->ncons; i++, con++) {
            Particle *a = con->a;
            Particle *b = con->b;
            if (a != 0 && b != 0) {
                f32 dx = a->pos[0] - b->pos[0];
                f32 dy = a->pos[1] - b->pos[1];
                f32 dz = a->pos[2] - b->pos[2];
                d[0] = dx;
                d[1] = dy;
                d[2] = dz;
                len2 = dx * dx + dy * dy + dz * dz;
                if (len2 - 0.0001f > con->dist) {
                    f32 inv = lbl_8006D118(&len2);
                    f32 w;
                    f32 ma, mb;
                    f32 s;
                    f32 t0_, t1_, t2_;
                    s = inv * (len2 - lbl_8006D0B4(con->dist));
                    len2 = s;
                    for (j = 0; j < 3; j++) {
                        d[j] = d[j] * s;
                    }
                    w = 1.0f / (a->mass + b->mass);
                    ma = a->mass * w;
                    mb = b->mass * w;
                    t0_ = d[0] * ma;
                    t1_ = d[1] * ma;
                    t2_ = d[2] * ma;
                    a->pos[0] = a->pos[0] - t0_;
                    a->pos[1] = a->pos[1] - t1_;
                    a->pos[2] = a->pos[2] - t2_;
                    t0_ = d[0] * mb;
                    t1_ = d[1] * mb;
                    t2_ = d[2] * mb;
                    b->pos[0] = b->pos[0] + t0_;
                    b->pos[1] = b->pos[1] + t1_;
                    b->pos[2] = b->pos[2] + t2_;
                }
            }
        }
        if (c->owner->kind == 27) {
            SPRING(l0, t0, 0.057f, -0.021f, 0.0f, 0.01f, 0.1f)
            SPRING(l1, t1, 0.127f, -0.021f, 0.0f, 0.01f, 0.1f)
        } else if (c->owner->kind == 4) {
            SPRING(l2, t2, 0.057f, -0.02f, 0.0f, 0.021904f, 0.148f)
            SPRING(l3, t3, 0.127f, -0.02f, 0.0f, 0.021025f, 0.145f)
        } else if (c->owner->kind == 22) {
            SPRING(l4, t4, 0.057f, -0.008f, 0.0f, 0.007225f, 0.085f)
            SPRING(l5, t5, 0.127f, -0.008f, 0.0f, 0.005776f, 0.076f)
            SPRING(l6, t6, 2.225f, 0.0f, 0.0f, 4.596736f, 2.144f)
        }
    }
    for (i = 0; i < c->count; i++) {
        Particle *p = &c->parts[i];
        fn_1_1286F4(rnd);
        p->vel[0] = p->vel[0] * 0.8;
        p->vel[1] = p->vel[1] * 0.8;
        p->vel[2] = p->vel[2] * 0.8;
        p->vel[0] = p->vel[0] + 0.2 * (p->pos[0] - p->prev[0]);
        p->vel[1] = p->vel[1] + 0.2 * (p->pos[1] - p->prev[1]);
        p->vel[2] = p->vel[2] + 0.2 * (p->pos[2] - p->prev[2]);
        p->vel[0] = p->vel[0] + 0.5 * rnd[0];
        p->vel[1] = p->vel[1] + 0.5 * rnd[1];
        p->vel[2] = p->vel[2] + 0.5 * rnd[2];
    }
    mats = fn_80077B14(c->unk_10);
    lbl_8006DBAC(c->owner->inner->base + lbl_1_data_3FFBC[c->index] * 0x18c + 0x88);
    for (i = 0; i < c->count; i++) {
        Particle *p = &c->parts[i];
        for (j = 0; (s32)j < p->nmat; j++) {
            fn_8006E250(p->pos, (u8 *)mats + p->idx[j] * 64);
        }
    }
}
