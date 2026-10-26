/* Non-matching: best partial attempt (87.23% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
#include "rel/main_rel/stcoli.h"

typedef struct { f32 x, y, z; } V3;

struct Rod {
    u8 pad_0[0x8];
    f32 zero;
    f32 one;
    u8 pad_10[0x8];
    f32 neg1;
    u8 pad_1C[0x4];
    f32 half;
    u8 pad_24[0x10];
    f32 nhalf;
    f32 c200;
    u8 pad_3C[0x70];
    f32 quarter;
};

struct Mot;
typedef struct Hist {
    s32 count;
    u8 pad_4[0x18];
    struct Mot *a[4];
    f32 b[4];
    u32 c[4];
    s32 d[4];
} Hist;

typedef struct Stk {
    Hist *cur;
    Hist *prev;
} Stk;

typedef struct Mot {
    u32 flags;
} Mot;

typedef struct GS {
    u8 pad_0[0x1b8];
    s32 f1b8;
    s32 f1bc;
    s32 f1c0;
    f32 f1c4;
    u8 pad_1c8[0xc];
    u32 f1d4;
    u8 pad_1d8[0x4];
    f32 f1dc;
    f32 f1e0;
    u8 pad_1e4[0x44];
    s32 f228;
    s32 f22c;
    s32 f230;
    f32 f234;
    u32 f238;
    f32 f23c;
    V3 f240;
    V3 f24c;
    V3 f258;
    u8 pad_264[0xc];
    u32 *f270;
} GS;

extern struct Rod lbl_1_rodata_6C8;
extern GS *lbl_801A66CC;
extern f32 *lbl_801A6D00;

extern void fn_1_18784(u32, Mot *, f32 *, void *, f32);
extern int fn_1_17B5C(int, int, int, f32);
extern s16 fn_1_7B054(void);
extern void lbl_8006DAEC(void);
extern void fn_8006E250(void *, void *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006E1C0(void *, void *);
extern void lbl_8006D668(void *);
extern void lbl_8006D5F0(void *, void *, f32);
extern void lbl_8006DB30(void);
extern void mathutil_mtxA_rotate_z(int);

#define MTX(o) (*(f32 *)(0xE0000000 + (o)))

static inline int is_finite(f32 x)
{
    u32 bits = *(u32 *)&x;
    return (bits & 0x7f800000) != 0x7f800000;
}

static inline int chk(struct Rod *R, Stk *stk, Mot *m, int i, int id)
{
    Hist *q;
    s32 n;
    u32 c;
    u32 mask;
    u32 mf;
    int prevId;
    if (stk == NULL) {
        return 0;
    }
    q = stk->prev;
    n = stk->cur->count;
    c = q->c[n];
    if (q->count <= n) {
        return 0;
    }
    if (((c << ((i + 1) & 31)) >> 31) == 0) {
        return 0;
    }
    mask = 0x03e00000;
    if (lbl_801A66CC->f1b8 == q->count) {
        mask |= 0xc00;
    }
    mf = m->flags & mask;
    prevId = stk->prev->d[n];
    if (mf == (mf & c) &&
        (stk->prev->a[n] == m ||
         fn_1_17B5C(prevId, id, lbl_1_bss_3BE0->unk_8, R->c200) != 0)) {
        if (fn_1_7B054() == 0x10) {
            if (id >= 0x5f && id <= 0x79) {
                if (prevId < 0x5f || prevId > 0x79) {
                    s32 g = lbl_801A66CC->f1bc;
                    if ((g == 1 && i == 0) || (g == 2 && i == 1)) {
                        return 0;
                    }
                }
            }
            return 1;
        } else if (fn_1_7B054() == 0x1c) {
            if (id >= 0x74 && id <= 0x90) {
                if (prevId < 0x74) {
                    s32 g = lbl_801A66CC->f1bc;
                    if ((g == 1 && i == 1) || (g == 2 && i == 0)) {
                        return 0;
                    }
                }
                if (prevId > 0x90) {
                    s32 g = lbl_801A66CC->f1bc;
                    if ((g == 1 && i == 0) || (g == 2 && i == 1)) {
                        return 0;
                    }
                }
                return 1;
            } else if (id >= 0xa8 && id <= 0xc6) {
                if (prevId < 0xa8) {
                    s32 g = lbl_801A66CC->f1bc;
                    if ((g == 1 && i == 0) || (g == 2 && i == 1)) {
                        return 0;
                    }
                }
                if (prevId > 0xc6) {
                    s32 g = lbl_801A66CC->f1bc;
                    if ((g == 1 && i == 1) || (g == 2 && i == 0)) {
                        return 0;
                    }
                }
                return 1;
            }
            return 1;
        }
        return 1;
    }
    return 0;
}

void fn_1_1EBD4(V3 *p0, V3 *p1, u32 flags, Mot *m, f32 *pt, Stk *stk, void *arg6, int id, f32 arg8)
{
    struct Rod *R = (struct Rod *)&lbl_1_rodata_6C8;
    GS **g1;
    GS **g2;
    s32 i;
    u32 m27;
    u32 m28;
    u32 m29;
    u32 r26;
    u32 r31;
    f32 sgn;
    f32 f28;
    f32 f29;
    f32 f30;
    f32 f31;
    f32 quarter;
    V3 v64;
    V3 v58;
    V3 v40;
    V3 v4c;
    V3 v34;
    V3 v28;
    V3 v1c;

    if (m->flags & 1) {
        sgn = R->one;
        r26 = 0x400000 + 1;
    } else {
        r26 = 0x400000;
        sgn = R->neg1;
    }
    m29 = 0xf0000000;
    m28 = 0xf0000000;
    m27 = 0;
    fn_1_18784(flags, m, pt, arg6, arg8);
    g1 = (GS **)&lbl_801A66CC;
    quarter = R->quarter;
    r31 = flags & 0x02000000;
    f31 = R->zero;
    f28 = (*g1)->f1dc;
    f29 = (*g1)->f1e0;
    i = 0;
    do {
        GS *G = *g1;
        s32 hit = 0;
        s32 le;
        s32 ok;
        f32 t;
        f32 a2, b2, A, B, disc, w, s;
        lbl_8006DAEC();
        w = f28 * (i == 0 ? R->half : R->nhalf);
        MTX(0x0c) = MTX(0x00) * w + MTX(0x0c);
        MTX(0x1c) = MTX(0x10) * w + MTX(0x1c);
        MTX(0x2c) = MTX(0x20) * w + MTX(0x2c);
        fn_8006E250(p0, &v64);
        v64.x = v64.x / f29;
        v64.y = v64.y / f29;
        fn_8006E250(p1, &v58);
        v58.x = v58.x / f29;
        v58.y = v58.y / f29;
        psvec_sub(&v64, &v58, &v40);
        v40.z = v64.z - v58.z;
        a2 = v64.x * v64.x + v64.y * v64.y - quarter;
        b2 = v58.x * v58.x + v58.y * v58.y - quarter;
        s = sgn * a2;
        le = (s <= f31);
        if (le) {
            m29 &= ~(0x80000000 >> i);
        }
        if (a2 > f31 && b2 > f31) {
            m28 &= ~(0x80000000 >> i);
        }
        ok = chk(R, stk, m, i, id);
        A = v40.x * v40.x + v40.y * v40.y;
        B = v40.x * v58.x + v40.y * v58.y;
        disc = B * B - A * b2;
        if (disc >= f31) {
            f32 sq = lbl_8006D0B4(disc);
            if (is_finite(sq)) {
                t = -(B + sgn * sq) / A;
                if (R->zero <= t && t <= R->one) {
                    if (G->f238 == 0 || t < G->f23c) {
                        if (is_finite(t)) {
                            hit = 1;
                        }
                    }
                }
            }
        }
        if (ok && !hit && le && G->f238 == 0 && r31 != 0) {
            hit = 1;
            t = R->zero;
        }
        if (hit) {
            f32 px = v58.x + t * v40.x;
            if (i == 0) {
                if (px < R->zero) {
                    hit = 0;
                }
            } else {
                if (px > R->zero) {
                    hit = 0;
                }
            }
        }
        if (hit) {
            f32 dz;
            psvec_scale_add(&v58, &v40, t, &v4c);
            psvec_sub(p0, p1, &v34);
            psvec_scale_add(p1, &v34, t, &G->f240);
            dz = p0->z - p1->z;
            v34.z = dz;
            G->f240.z = dz * t + p1->z;
            v34.x = sgn * v4c.x;
            G->f24c.x = v34.x;
            v34.y = sgn * v4c.y;
            G->f24c.y = v34.y;
            v34.z = R->zero;
            v4c.z = v40.z * t + v58.z;
            G->f24c.z = R->zero;
            lbl_8006E1C0(&G->f24c, &G->f24c);
            lbl_8006D668(&G->f24c);
            {
                f32 len = lbl_8006D0B4(v64.x * v64.x + v64.y * v64.y);
                f32 d = sgn * (R->half - len);
                if (d > R->zero) {
                    lbl_8006D5F0(&v34, &v34, d);
                    v34.x = v34.x * f29;
                    v34.y = v34.y * f29;
                    lbl_8006E1C0(&v34, &G->f258);
                } else {
                    G->f258.x = R->zero;
                    G->f258.y = R->zero;
                    G->f258.z = R->zero;
                }
            }
            G->f23c = t;
            G->f238 = r26;
            G->f22c = lbl_801A66CC->f1bc;
            G->f230 = lbl_801A66CC->f1c0;
            G->f234 = lbl_801A66CC->f1c4;
            G->f270 = stk ? &stk->cur->c[stk->cur->count] : 0;
            m27 |= 0x80000000 >> i;
        }
        lbl_8006DB30();
        i++;
    } while (i <= 1);

    f30 = R->half * f29;
    f31 = R->zero;
    f29 = R->nhalf * f29;
    g2 = (GS **)&lbl_801A66CC;
    i = 2;
    do {
        GS *G = *g2;
        s32 hit = 0;
        s32 neg;
        s32 valid;
        f32 t;
        lbl_8006DAEC();
        if (i == 3) {
            mathutil_mtxA_rotate_z(0x8000);
        }
        if (m->flags & 1) {
            MTX(0x0c) = MTX(0x04) * f30 + MTX(0x0c);
            MTX(0x1c) = MTX(0x14) * f30 + MTX(0x1c);
            MTX(0x2c) = MTX(0x24) * f30 + MTX(0x2c);
        } else {
            MTX(0x0c) = MTX(0x04) * f29 + MTX(0x0c);
            MTX(0x1c) = MTX(0x14) * f29 + MTX(0x1c);
            MTX(0x2c) = MTX(0x24) * f29 + MTX(0x2c);
        }
        fn_8006E250(p0, &v64);
        v64.x = v64.x / f28;
        fn_8006E250(p1, &v58);
        v58.x = v58.x / f28;
        neg = (f31 >= v64.y);
        if (neg) {
            m29 &= ~(0x80000000 >> i);
        }
        if ((f31 < sgn * v64.y && f31 < sgn * v58.y) ||
            (R->nhalf > v64.x && R->nhalf > v58.x) ||
            (R->half < v64.x && R->half < v58.x)) {
            m28 &= ~(0x80000000 >> i);
        }
        valid = chk(R, stk, m, i, id);
        if (neg && v58.y >= R->zero &&
            !(R->nhalf > v58.x && R->nhalf > v64.x) &&
            !(R->half < v58.x && R->half < v64.x)) {
            t = v58.y / (v58.y - v64.y);
            if (G->f238 == 0 || t < G->f23c) {
                if (is_finite(t)) {
                    hit = 1;
                }
            }
        }
        if (!hit && neg && G->f238 == 0 && valid && r31 != 0) {
            hit = 1;
            t = R->zero;
        }
        if (hit) {
            f32 dz;
            psvec_sub(&v64, &v58, &v28);
            psvec_scale_add(&v58, &v28, t, &v1c);
            dz = v64.z - v58.z;
            v28.z = dz;
            v1c.z = dz * t + v58.z;
            if ((valid && !(m->flags & 1)) ||
                (R->nhalf <= v1c.x && v1c.x <= R->half)) {
                f32 nb;
                psvec_sub(p0, p1, &v28);
                psvec_scale_add(p1, &v28, t, &G->f240);
                dz = p0->z - p1->z;
                v28.z = dz;
                G->f240.z = dz * t + p1->z;
                G->f24c.x = lbl_801A6D00[1];
                G->f24c.y = lbl_801A6D00[5];
                G->f24c.z = lbl_801A6D00[9];
                nb = -v64.y;
                if (nb > R->zero) {
                    G->f258.x = MTX(0x04) * nb;
                    G->f258.y = MTX(0x14) * nb;
                    G->f258.z = MTX(0x24) * nb;
                } else {
                    G->f258.x = R->zero;
                    G->f258.y = R->zero;
                    G->f258.z = R->zero;
                }
                G->f23c = t;
                G->f238 = r26;
                G->f22c = lbl_801A66CC->f1bc;
                G->f230 = lbl_801A66CC->f1c0;
                G->f234 = lbl_801A66CC->f1c4;
                G->f270 = stk ? &stk->cur->c[stk->cur->count] : 0;
                m27 |= 0x80000000 >> i;
            }
        }
        lbl_8006DB30();
        i++;
    } while (i <= 3);

    if (m27 != 0 && (flags & 0x00200000) != 0 && fn_1_7B054() == 0x20) {
        GS *G = lbl_801A66CC;
        if ((G->f1c0 >= 0x1e && G->f1c0 <= 0x45) ||
            (G->f1c0 == 0x5c && R->half <= G->f1c4) ||
            (G->f1c0 >= 0x5d && G->f1c0 <= 0x60) ||
            (G->f1c0 == 0x61 && R->half >= G->f1c4) ||
            (G->f1c0 >= 0x78 && G->f1c0 <= 0x8b)) {
            G->f1d4 = 0x80000;
        }
    }
    if (!(m->flags & 1)) {
        s32 any = 0;
        if ((m28 >> 31) || ((m28 >> 30) & 1) || (((m28 >> 29) & 1) && ((m28 >> 28) & 1))) {
            any = 1;
        }
        if (any || m27 != 0) {
            m29 = 0xf0000000;
        } else {
            m29 = 0;
        }
    }
    if (stk != NULL) {
        u32 mk = m29 | m27;
        stk->cur->a[stk->cur->count] = m;
        stk->cur->b[stk->cur->count] = *pt;
        if (mk != 0) {
            stk->cur->c[stk->cur->count] = m->flags | mk;
        } else {
            stk->cur->c[stk->cur->count] = m->flags;
        }
        stk->cur->d[stk->cur->count] = id;
        if (stk->cur->count < 3) {
            stk->cur->count = stk->cur->count + 1;
        }
    }
}
