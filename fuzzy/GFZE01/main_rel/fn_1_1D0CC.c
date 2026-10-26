/* Non-matching: best partial attempt (90.46% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct { u32 flags; } Mot;
typedef struct {
    s32 count;
    u8 pad_4[0x18];
    void *mot[4];
    f32 sc[4];
    u32 flags[4];
    s32 idx[4];
} Buf;
typedef struct { Buf *cur; Buf *prev; } Stack;
typedef struct {
    u32 a, b;
    f32 c;
    u32 flag;
    f32 t;
    Vec3 pos, vel, vel2;
    u8 pad_38[0xc];
    u32 ptr;
} Rec;
typedef struct {
    u8 pad_0[0xd4];
    Vec3 v;
    u8 pad_e0[0xd8];
    s32 f1b8, f1bc, f1c0;
    f32 f1c4;
    u8 pad_1c8[0xc];
    u32 f1d4;
    u8 pad_1d8[0xc];
    Rec recs[2];
} G;
struct GH { G *p; };
struct BH { u8 pad_0[0x8]; u32 unk_8; };
struct RO {
    u8 pad_0[0x8];
    f32 unk_8, unk_C;
    u8 pad_10[0x8];
    f32 unk_18;
    u8 pad_1C[0x4];
    f32 unk_20;
    u8 pad_24[0x14];
    f32 unk_38;
    u8 pad_3C[0x64];
    f64 unk_A0;
    f32 unk_A8, unk_AC, unk_B0, unk_B4, unk_B8;
};
extern f64 __fabs(f64);
extern int fn_1_17B5C(int, int, int, f32);
extern s16 fn_1_7B054(void);
extern void fn_1_18784(u32, void *, Vec3 *, void *, f32);
extern struct BH *lbl_1_bss_3BE0;
extern struct RO lbl_1_rodata_6C8;
extern struct GH lbl_801A66CC;
extern void lbl_8006DAEC(void);
extern void lbl_8006DF44(void);
extern void lbl_8006E1B0(void *, void *);
extern f32 lbl_8006D0E8(f32);
extern void lbl_8006DB30(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006E1C0(void *, void *);
extern f32 lbl_8006D668(void *);
extern void lbl_8006D5F0(void *, void *, f32);
extern s16 lbl_8006D24C(f32, f32);

static inline f32 chk_read_pointer(struct RO *owner) { return owner->unk_38; }
static inline int chk(Stack *stk, Mot *m, int idx, int bit)
{
    Buf *cur;
    Buf *prev;
    int i;
    u32 mask;
    u32 fl;
    int r;
    if (stk == 0) return 0;
    cur = stk->cur;
    prev = stk->prev;
    i = cur->count;
    fl = prev->flags[i];
    if (prev->count <= i) return 0;
    if (((fl << (32 - bit)) & 0x80000000) == 0) return 0;
    mask = 0x3e00000;
    if (lbl_801A66CC.p->f1b8 == prev->count) mask |= 0xc00;
    mask &= m->flags;
    if (mask != (mask & fl)) return 0;
    if (prev->mot[i] != m && fn_1_17B5C(prev->idx[i], idx, lbl_1_bss_3BE0->unk_8, chk_read_pointer(&lbl_1_rodata_6C8)) == 0) return 0;
    if (fn_1_7B054() == 16) r = 1;
    else if (fn_1_7B054() == 28) {
        if (idx >= 116 && idx <= 144) r = 1;
        else if (idx >= 168 && idx <= 198) r = 1;
        else r = 1;
    } else r = 1;
    return r;
}

#pragma opt_common_subs off
#pragma opt_dead_assignments off
#pragma opt_lifetimes on
void fn_1_1D0CC(Vec3 *p0, Vec3 *p1, u32 flags, Mot *m, Vec3 *sc, Stack *stk, void *other, int idx, f32 fa)
{
    f32 fzgx_live__, fzgx_live_;
    s32 fzgx_condition_9278, fzgx_condition_9521;
    u32 *fzgx_live;
    void *lab_t0;
    Vec3 loc54, loc48, loc3C, loc30, loc24, loc18;
    f32 f14, f10, fC, f8;
    u32 bit21, r14, r19, r20;
    int isFlag, hasStk, near, hit, inside, ok;
    G *g;
    Rec *recA, *recB, *rec;
    f32 f31, t, l2, aa, bb, disc, s, prod, d2;
    struct RO *ro = &lbl_1_rodata_6C8;
#define lbl_1_rodata_6C8 (*ro)

    r14 = 0x20000000;
    r20 = 0;
    r19 = 0;
    fn_1_18784(flags, m, sc, other, fa);
    isFlag = m->flags & 1;
    hasStk = 0;
    if (stk != 0 && isFlag == 0) hasStk = 1;
    bit21 = flags;
    bit21 = bit21 & 0x200000;
    near = 0;
    if (bit21 != 0) {
        f32 ratio = sc->y / sc->x;
        if (__fabs(ratio - lbl_1_rodata_6C8.unk_C) < lbl_1_rodata_6C8.unk_A0) near = 1;
    }
    lbl_8006DAEC();
    lbl_8006DF44();
    lab_t0 = p1;
    lbl_8006E1B0(lab_t0, &loc48);
    hit = near;
    if (near != 0) {
        if (isFlag != 0) {
            loc54.x = lbl_1_rodata_6C8.unk_8;
            loc54.y = lbl_1_rodata_6C8.unk_8;
            loc54.z = lbl_1_rodata_6C8.unk_8;
        } else {
            l2 = (f32)(loc48.x * loc48.x) + (f32)(loc48.y * loc48.y);
            if (l2 < lbl_1_rodata_6C8.unk_C) hit = 0;
            else {
                f32 rs = lbl_8006D0E8(l2);
                f32 k = lbl_1_rodata_6C8.unk_A8;
                loc54.z = lbl_1_rodata_6C8.unk_8;
                loc54.x = loc48.x + (f32)(k * (loc48.x * rs));
                loc54.y = loc48.y + (f32)(k * (loc48.y * rs));
            }
        }
    }
    loc48.x = loc48.x / sc->x;
    loc48.y = loc48.y / sc->y;
    if (hit == 0) lbl_8006E1B0(p0, &loc54);
    loc3C = loc54;
    loc54.x = loc54.x / sc->x;
    loc54.y = loc54.y / sc->y;
    lbl_8006DB30();
    g = lbl_801A66CC.p;
    recA = &g->recs[1];
    recB = &g->recs[0];
    if (isFlag != 0) f31 = lbl_1_rodata_6C8.unk_C;
    else f31 = lbl_1_rodata_6C8.unk_18;
    d2 = (f32)(loc54.x * loc54.x) + (f32)(loc54.y * loc54.y);
    psvec_sub(&loc54, &loc48, &loc30);
    inside = !(f31 * (d2 - lbl_1_rodata_6C8.unk_AC) >= lbl_1_rodata_6C8.unk_8);
    if (inside != 0) r14 &= ~0x20000000;
    ok = chk(stk, m, idx, 29);
    aa = (f32)(loc30.x * loc30.x) + (f32)(loc30.y * loc30.y);
    bb = (f32)(loc30.x * loc48.x) + (f32)(loc30.y * loc48.y);
    disc = (f32)(bb * bb) - (f32)(aa * (((f32)(loc48.x * loc48.x) + (f32)(loc48.y * loc48.y)) - lbl_1_rodata_6C8.unk_AC));
    if (disc >= lbl_1_rodata_6C8.unk_8) {
        s = lbl_8006D0B4(disc);
        f14 = s;
        if ((*(u32 *)&f14 & 0x7F800000) != 0x7F800000) {
            prod = f31 * s;
            t = (-(bb + prod)) / aa;
            if (lbl_1_rodata_6C8.unk_8 <= t && t <= lbl_1_rodata_6C8.unk_C) {
                f10 = t;
                if ((*(u32 *)&f10 & 0x7F800000) != 0x7F800000) {
                    r19 |= 0x20000000;
                    if (recA->flag == 0 || t < recA->t) r20 = 0x20000000;
                }
            }
            if (hasStk != 0 && ok == 0 && (r20 & 0x20000000) == 0) {
                t = (-(bb - prod)) / aa;
                if (lbl_1_rodata_6C8.unk_8 <= t && t <= lbl_1_rodata_6C8.unk_C) {
                    fC = t;
                    if ((*(u32 *)&fC & 0x7F800000) != 0x7F800000) {
                        r19 |= 0x2000000;
                        if (recB->flag == 0 || t < recB->t) r20 = 0x2000000;
                    }
                }
            }
        }
    }
    if (ok != 0 && inside != 0 && (r20 & 0x20000000) == 0 && (flags & 0x2000000) != 0) {
        r19 |= 0x20000000;
        if (recA->flag == 0) { r20 = 0x20000000; t = lbl_1_rodata_6C8.unk_8; }
    }
    if (ok == 0) ok = (f31 * ((f32)(loc48.x * loc48.x) + (f32)(loc48.y * loc48.y) - lbl_1_rodata_6C8.unk_AC) >= lbl_1_rodata_6C8.unk_8);
    if (hasStk != 0 && r20 == 0) {
        if (ok == 0 || chk(stk, m, idx, 2)) {
            if (inside == 0 && (flags & 0x2000000) != 0) {
                r19 |= 0x2000000;
                if (recB->flag == 0) { r20 = 0x2000000; t = lbl_1_rodata_6C8.unk_8; }
            }
        }
    }
    if ((r20 & 0x20000000) != 0 && isFlag == 0 && (flags & 0x4000000) != 0 && ok == 0) r20 &= ~0x20000000;
    if (r20 != 0) {
        psvec_scale_add(&loc48, &loc30, t, &loc24);
        if ((r20 & 0x2000000) != 0) {
            isFlag = !isFlag; f31 = -f31; r14 = 0; r20 = 0; rec = recB;
        } else rec = recA;
        if (hit != 0) {
            lab_t0 = &loc3C;
            lbl_8006E1B0(lab_t0, &lbl_801A66CC.p->v);
            psvec_sub_scale_add(&lbl_801A66CC.p->v, p1, t, &loc18, &rec->pos);
        } else psvec_sub_scale_add(p0, p1, t, &loc18, &rec->pos);
        loc18.x = rec->vel.x = f31 * loc24.x;
        loc18.y = rec->vel.y = f31 * loc24.y;
        loc18.z = rec->vel.z = lbl_1_rodata_6C8.unk_8;
        lbl_8006E1C0(&rec->vel, &rec->vel);
        lbl_8006D668(&rec->vel);
        s = f31 * (lbl_1_rodata_6C8.unk_20 - lbl_8006D0B4((f32)(loc54.x * loc54.x) + (f32)(loc54.y * loc54.y)));
        if (s > lbl_1_rodata_6C8.unk_8) {
            lbl_8006D5F0(&loc18, &loc18, s);
            loc18.x = loc18.x * sc->x; loc18.y = loc18.y * sc->y;
            lbl_8006E1C0(&loc18, &rec->vel2);
        } else {
            rec->vel2.x = lbl_1_rodata_6C8.unk_8;
            rec->vel2.y = lbl_1_rodata_6C8.unk_8;
            rec->vel2.z = lbl_1_rodata_6C8.unk_8;
        }
        if (hit != 0) {
            f32 s1, s2;
            fzgx_live_ = p1->z;
            s1 = lbl_8006D0B4((f32)((p1->x - rec->pos.x) * (p1->x - rec->pos.x)) + (p1->y - rec->pos.y) * (p1->y - rec->pos.y) + (fzgx_live_ - rec->pos.z) * (fzgx_live_ - rec->pos.z));
            fzgx_live_ = p1->z; fzgx_live__ = p0->z;
            s2 = lbl_8006D0B4((f32)((p1->x - p0->x) * (p1->x - p0->x)) + (p1->y - p0->y) * (p1->y - p0->y) + (fzgx_live_ - fzgx_live__) * (fzgx_live_ - fzgx_live__));
            t = s1 / s2;
            f8 = t;
            if ((*(u32 *)&f8 & 0x7F800000) == 0x7F800000) t = lbl_1_rodata_6C8.unk_8;
        }
        rec->t = t;
        rec->flag = (isFlag != 0) + 0x1000000;
        rec->a = lbl_801A66CC.p->f1bc; rec->b = lbl_801A66CC.p->f1c0; rec->c = lbl_801A66CC.p->f1c4;
        if (stk != 0) rec->ptr = (u32)((u8 *)stk->cur + stk->cur->count * 4 + 0x3c);
        else rec->ptr = 0;
    }
    if (r20 != 0 && bit21 != 0) {
        s16 sv = fn_1_7B054();
        if (sv == 33) {
            g = lbl_801A66CC.p;
            if (((fzgx_condition_9278 = g->f1c0) >= 20 && fzgx_condition_9278 <= 21) ||
                (fzgx_condition_9278 == 19 && lbl_1_rodata_6C8.unk_B0 <= g->f1c4) ||
                (fzgx_condition_9278 == 22 && lbl_1_rodata_6C8.unk_B4 >= g->f1c4)) {
                s16 ang = lbl_8006D24C(loc48.y, loc48.x);
                if (ang >= 0x1800 && ang <= 0x6800) lbl_801A66CC.p->f1d4 = 0x100000;
            } else if (g->f1bc == 2) {
                if (((fzgx_condition_9521 = g->f1c0) >= 38 && fzgx_condition_9521 <= 39) ||
                    (fzgx_condition_9521 == 40 && lbl_1_rodata_6C8.unk_B8 >= g->f1c4)) {
                    s16 ang = lbl_8006D24C(loc48.y, loc48.x);
                    if (ang >= 0x1800 && ang <= 0x6800) lbl_801A66CC.p->f1d4 = 0x100000;
                }
            }
        } else if (sv == 35) {
            if (lbl_801A66CC.p->f1c0 >= 91 && lbl_801A66CC.p->f1c0 <= 102) {
                u16 ang = lbl_8006D24C(loc48.y, loc48.x);
                if (ang >= 0x6000 && ang <= 0xa000) lbl_801A66CC.p->f1d4 = 0x100000;
            }
        }
    }
    if (stk != 0) {
        u32 f4 = (r19 & 0x2000000) ? 4 : 0;
        stk->cur->mot[stk->cur->count] = m;
        stk->cur->sc[stk->cur->count] = sc->x;
        fzgx_live = stk->cur->flags;
        fzgx_live[stk->cur->count] = m->flags | f4;
        if (r14 != 0 || r20 != 0 || (r19 & ~0x2000000) != 0) {
            fzgx_live = stk->cur->flags;
            fzgx_live[stk->cur->count] |= 0xF0000000;
        }
        stk->cur->idx[stk->cur->count] = idx;
        if (stk->cur->count < 3) stk->cur->count++;
    }
}
#pragma opt_lifetimes reset
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset
