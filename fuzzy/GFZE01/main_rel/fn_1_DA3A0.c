/* Non-matching: best partial attempt (98.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

struct Sig_fn_80077B14_fn_80077B14_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
    u8 pad_8[0x18];
    u32 unk_20;
};

struct fn_1_DA3A0_Obj {
    u8 pad_0[0x4];
    struct Sig_fn_80077B14_fn_80077B14_Arg0 *unk_4;
    u8 pad_8[0x4];
    u32 unk_C;
    u8 pad_10[0x4];
    u32 unk_14;
};

struct fn_1_DA3A0_Vec3 {
    f32 x;
    f32 y;
    f32 z;
};

struct fn_1_DA3A0_Ent {
    u8 pad_0[0x2];
    u8 cnt;
    u8 pad_3[0x1];
    u16 idx[6];
    struct fn_1_DA3A0_Vec3 v;
    u8 pad_1C[0x28];
};

extern s32 fn_80077B14(struct Sig_fn_80077B14_fn_80077B14_Arg0 *);
extern void lbl_8006D668(void *data);

static inline f32 fn_1_DA3A0_cross_read_pointer(struct fn_1_DA3A0_Vec3 * owner) { return owner->x; }
static inline void fn_1_DA3A0_cross(struct fn_1_DA3A0_Vec3 *out, struct fn_1_DA3A0_Vec3 *p, struct fn_1_DA3A0_Vec3 *q)
{
    out->z = (f32)(p->x * q->y) - p->y * q->x;
    out->y = (f32)(p->z * q->x) - fn_1_DA3A0_cross_read_pointer(p) * q->z;
    out->x = (f32)(((q->z) * (p->y))) - p->z * q->y;
}

#define FN_1_DA3A0_XPROD() \
    do { \
        lbl_8006D668(&a); \
        lbl_8006D668(&b); \
        fn_1_DA3A0_cross(&c, &a, &b); \
    } while (0)

#pragma opt_loop_invariants off
#pragma opt_lifetimes off
void fn_1_DA3A0(void *arg0)
{
    u16 * fzgx_live_;
    struct Sig_fn_80077B14_fn_80077B14_Arg0 * fzgx_live;
    u32 i;
    struct fn_1_DA3A0_Ent *ent;
    struct fn_1_DA3A0_Obj *obj;
    u32 j;
    struct fn_1_DA3A0_Vec3 a;
    struct fn_1_DA3A0_Vec3 b;
    struct fn_1_DA3A0_Vec3 c;

    if ((obj = (struct fn_1_DA3A0_Obj *)arg0) == 0) {
        return;
    }
    if (obj->unk_4 == 0) {
        return;
    }
{
    u8 *pool;
    fzgx_live = obj->unk_4;
    pool = (u8 *)fn_80077B14(fzgx_live);
    ent = (struct fn_1_DA3A0_Ent *)(obj->unk_14 + 0x83C);
    for (i = 0; i < obj->unk_C - 0x1F; i++, ent++) {
        if (i > obj->unk_C - 12) {
            if (i + 1 == 11) {
                psvec_sub(&ent[-1].v, &ent->v, &a);
                psvec_sub(&ent[-11].v, &ent->v, &b);
                FN_1_DA3A0_XPROD();
            } else {
                psvec_sub(&ent[-11].v, &ent->v, &a);
                psvec_sub(&ent[1].v, &ent->v, &b);
                FN_1_DA3A0_XPROD();
            }
        } else {
            if (i + 1 == 11) {
                psvec_sub(&ent[11].v, &ent->v, &a);
                psvec_sub(&ent[-1].v, &ent->v, &b);
                FN_1_DA3A0_XPROD();
            } else {
                psvec_sub(&ent[1].v, &ent->v, &a);
                psvec_sub(&ent[11].v, &ent->v, &b);
                FN_1_DA3A0_XPROD();
            }
        }
        for (j = 0; j < (u32)ent->cnt; j++) {
            fzgx_live_ = ent->idx;
            *(struct fn_1_DA3A0_Vec3 *)(pool + ((u32)fzgx_live_[j] << 6) + 0xC) = c;
}
        }
        ent++;
    }
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset

