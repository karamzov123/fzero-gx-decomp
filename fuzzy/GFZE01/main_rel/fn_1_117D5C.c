/* Non-matching: best partial attempt (74.37% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/accessory.h"

typedef struct Vec3 {
    f32 x, y, z;
} Vec3;

typedef struct Vec {
    u8 flag0;
    u8 pad1;
    u8 count;
    u8 pad3;
    u16 idx[6];
    Vec3 pos;
    Vec3 prev;
    void *unk28;
    u32 pad2C[2];
    Vec3 vel;
    f32 mass;
} Vec;

typedef struct Pair {
    void *a;
    void *b;
    f32 radius;
} Pair;

typedef struct Mgr {
    u8 flags;
    u8 pad1[7];
    u32 index;
    void *gfx;
    void *ctx;
    u32 pad14;
    u32 countA;
    u32 countPairs;
    u32 countB;
    Vec *a;
    Pair *pairs;
    Vec *b;
} Mgr;

extern f32 lbl_1_rodata_7AB8[];
extern s32 fn_80077B14(void *);
extern u8 *fn_80083970(u8 *, const u8 *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D118(const f32 *);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006E250(void *, void *);

#define RF(o) (*(const f32 *)(rc + (o)))
#define RD(o) (*(const f64 *)(rc + (o)))

#define BASE() ((u8 *)(*(u32 *)((u8 *)*(u32 *)((u8 *)m->gfx + 0x150) + 8)) + \
                 (((u32 *)(dc + 0xaac))[m->index] * 0x18c))

#define PUSH(a, b, rad)                                    \
    do {                                                   \
        f32 len, rsq, scl, ma, mb;                        \
        dv.x = (a)->pos.x - (b)->pos.x;                    \
        dv.y = (a)->pos.y - (b)->pos.y;                    \
        dv.z = (a)->pos.z - (b)->pos.z;                    \
        dist = dv.x*dv.x + dv.y*dv.y + dv.z*dv.z;          \
        if (dist - RF(0x9c) > (rad)) {                     \
            len = lbl_8006D118(&dist);                     \
            rsq = lbl_8006D0B4(rad);                       \
            dist = len * (dist - rsq);                     \
            dv.x *= dist;                                  \
            dv.y *= dist;                                  \
            dv.z *= dist;                                  \
            scl = RF(0xa0) / ((a)->mass + (b)->mass);      \
            ma = (a)->mass * scl;                          \
            mb = (b)->mass * scl;                          \
            (a)->pos.x -= dv.x*ma;                         \
            (a)->pos.y -= dv.y*ma;                         \
            (a)->pos.z -= dv.z*ma;                         \
            (b)->pos.x += dv.x*mb;                         \
            (b)->pos.y += dv.y*mb;                         \
            (b)->pos.z += dv.z*mb;                         \
        }                                                  \
    } while (0)

void fn_1_117D5C(Mgr *m)
{
    const u8 *rc;
    const u8 *dc;
    Vec *a, *b, *e, *ca, *cb;
    Pair *p;
    u32 i, k, n;
    u8 *base;
    u8 *ret;
    f32 dist;
    Vec3 tv1, tv2;
    Vec3 dv;
    f32 dx, dy, dz;
    f32 kk;

    rc = (const u8 *)lbl_1_rodata_7AB8;
    dc = lbl_1_data_3F510;
    if (m == 0) return;
    if (m->ctx == 0) return;
    fn_80077B14(m->ctx);
    fn_80083970(((u8 **)(dc + 0x79c))[m->index], (const u8 *)dc + 0x4bc);

    if (m->flags & 2) {
        m->flags &= ~2;
        base = BASE();
        e = m->a;
        for (i = 0; i < m->countA; i++, e++) {
            lbl_8006DBAC((void *)(base + 0x88));
            lbl_8006E1B0((void *)&e->unk28, (void *)&e->pos);
        }
        e = m->b;
        for (i = 0; i < m->countB; i++, e++) {
            lbl_8006DBAC((void *)(base + 0x88));
            lbl_8006E1B0((void *)&e->unk28, (void *)&e->pos);
        }
    }

    e = m->b;
    for (i = 0; i < m->countB; i++, e++) {
        if (!(e->flag0 & 1)) {
            e->prev = e->pos;
            e->pos.x += e->vel.x;
            e->pos.y += e->vel.y;
            e->pos.z += e->vel.z;
            e->pos.y = e->pos.y - RD(0x58);
            e->vel.y = e->vel.y - RF(0x60);
        }
    }

    base = BASE();
    e = m->a;
    for (i = 0; i < m->countA; i++, e++) {
        if (e->flag0 & 1) {
            lbl_8006DBAC((void *)(base + 0x88));
            lbl_8006E1B0((void *)&e->unk28, (void *)&e->pos);
        }
    }
    e = m->b;
    for (i = 0; i < m->countB; i++, e++) {
        if (e->flag0 & 1) {
            lbl_8006DBAC((void *)(base + 0x88));
            lbl_8006E1B0((void *)&e->unk28, (void *)&e->pos);
        }
    }

    for (k = 0; k < 4; k++) {
        p = m->pairs;
        for (i = 0; i < m->countPairs; i++, p++) {
            if (p->a != 0 && p->b != 0) {
                ca = (Vec *)p->a;
                cb = (Vec *)p->b;
                PUSH(ca, cb, p->radius);
                if (dist - RF(0x1a4) < p->radius) {
                    if (ca->pos.y < RF(0x68)) ca->pos.y = RF(0x248);
                    if (cb->pos.y < RF(0x68)) cb->pos.y = RF(0x248);
                    PUSH(ca, cb, p->radius);
                }
            }
        }
    }

    base = BASE();
    e = m->b;
    for (i = 0; i < m->countB; i++, e++) {
        if (!(e->flag0 & 1)) {
            lbl_8006DBAC((void *)(base + 0x88));
            lbl_8006E1B0((void *)&e->unk28, (void *)&tv1);
            kk = 0.2f * (1.0f - (f32)i / (f32)m->countB) * (1.0f + e->mass);
            tv2.x = (tv1.x - e->pos.x) * kk;
            tv2.y = (tv1.y - e->pos.y) * kk;
            tv2.z = (tv1.z - e->pos.z) * kk;
            e->pos.x += tv2.x;
            e->pos.y += tv2.y;
            e->pos.z += tv2.z;
        }
    }

    base = BASE();
    a = m->a;
    n = m->countA;
    while (n != 0) {
        if (!(a->flag0 & 1)) break;
        a++;
        n--;
    }
    e = m->b + 1;
    for (k = 0; k < 14; k++, e++) {
        lbl_8006DBAC((void *)(base + 0x88));
        lbl_8006E1B0((void *)&e->unk28, (void *)&tv2);
        dx = e->pos.x - tv2.x;
        dy = e->pos.y - tv2.y;
        dz = e->pos.z - tv2.z;
        for (i = 0; i < 6; i++, a++) {
            lbl_8006DBAC((void *)(base + 0x88));
            lbl_8006E1B0((void *)&a->unk28, (void *)&tv2);
            a->pos.x = tv2.x + dx;
            a->pos.y = tv2.y + dy;
            a->pos.z = tv2.z + dz;
        }
    }

    e = m->b;
    for (i = 0; i < m->countB; i++, e++) {
        e->vel.x = (e->pos.x - e->prev.x) * RF(0x3ec);
        e->vel.y = e->pos.y - e->prev.y;
        e->vel.z = (e->pos.z - e->prev.z) * RF(0x3ec);
        if (e->vel.y > RF(0x68)) e->vel.y *= RF(0x200);
    }

    ret = (u8 *)fn_80077B14(m->ctx);
    base = BASE();
    lbl_8006DBAC((void *)(base + 0x88));
    e = m->a;
    for (i = 0; i < m->countA; i++, e++) {
        for (k = 0; k < e->count; k++) {
            fn_8006E250((void *)&e->pos, (void *)(ret + (e->idx[k] << 6)));
        }
    }
}
