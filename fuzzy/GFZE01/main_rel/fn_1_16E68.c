/* Non-matching: best partial attempt (96.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/stcoli.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3L;

typedef struct {
    f32 f_0;
    f32 f_4;
    f32 a_8;
    f32 a_C;
    f32 a_10;
    f32 a_14;
    f32 f_18;
    f32 f_1C;
    f32 f_20;
    f32 b_24;
    f32 b_28;
    f32 b_2C;
    f32 b_30;
} PlaneL;

typedef struct {
    u32 f_0;
    PlaneL *planes;
    u32 f_8;
} EntryL;

typedef struct {
    u8 pad_0[0x8];
    s32 count;
    EntryL *entries;
} ListL;

typedef struct {
    u8 pad_0[0x8];
    f32 zero;
    f32 one;
    u8 pad_10[0x18];
    f32 tol_big;
    f32 tol_small;
} PoolL;

extern const PoolL lbl_1_rodata_6C8;

static inline f32 fn_1_16E68_read_pointer(PlaneL * owner) { return owner->a_8; }
#pragma opt_loop_invariants on
#pragma opt_dead_assignments off
#pragma opt_strength_reduction off
static inline f32 fn_1_16E68_read_pointer_(Vec3L * owner) { return owner->z; }
static inline f32 fn_1_16E68_read_pointer__(Vec3L * owner) { return owner->z; }
f32 fn_1_16E68(Vec3L *pos, s32 idx, u32 sub) {
    f32 fzgx_live________;
    f32 fzgx_live_______;
    f32 fzgx_live______;
    f32 fzgx_live_____;
    f32 fzgx_live____;
    f32 fzgx_live___;
    f32 fzgx_live__;
    f32 fzgx_live_;
    f32 fzgx_live;
    struct {
        const PoolL *p;
    } pool;
    ListL *lst;
    PlaneL *pl;
    s32 cnt;
    f32 tol;
    f32 d1;
    f32 d2;
    s16 t;

    pool.p = &lbl_1_rodata_6C8;
    t = fn_1_7B054();
    tol = (t == 0x19) ? pool.p->tol_big : pool.p->tol_small;

    lst = (ListL *)lbl_1_bss_3BE0->unk_0;
    cnt = lst->count;
    if (idx < 0 || cnt <= idx) {
        idx = 0;
    }
    pl = (PlaneL *)((u8 *)lst->entries[idx].planes + sub * 0x50);

    if (idx == 0) {
        if (pos->z < pool.p->zero) {
            goto case0;
        }
        return pool.p->zero;
    case0:
        fzgx_live = pl->b_24;
        fzgx_live_ = pos->y;
        d2 = fzgx_live + (fzgx_live_ * pl->b_2C + pos->x * pl->b_28 + fn_1_16E68_read_pointer__(pos) * pl->b_30);
        if (-tol <= d2) {
            goto case0_ok;
        }
        return pool.p->one;
    case0_ok:
        fzgx_live_ = pos->y;
        fzgx_live____ = pl->a_10;
        fzgx_live__ = fzgx_live____;
        d1 = fn_1_16E68_read_pointer(pl) + (fzgx_live_ * fzgx_live__ + pos->x * pl->a_C + pos->z * pl->a_14);
        goto out;
    }
    if (idx == cnt - 1) {
        if (fn_1_16E68_read_pointer_(pos) >= pool.p->zero) {
            goto case1;
        }
        return pool.p->one;
    case1:
        fzgx_live_ = pos->y;
        fzgx_live______ = pl->a_10;
        fzgx_live_______ = pl->a_14;
        d1 = fn_1_16E68_read_pointer(pl) + (fzgx_live_ * fzgx_live______ + pos->x * pl->a_C + pos->z * fzgx_live_______);
        if (-tol <= d1) {
            goto case1_ok;
        }
        return -tol;
    case1_ok:
        fzgx_live = pl->b_24;
        fzgx_live_ = pos->y;
        fzgx_live___ = pl->b_2C;
        d2 = fzgx_live + (fzgx_live_ * fzgx_live___ + pos->x * pl->b_28 + pos->z * pl->b_30);
        goto out;
    }
    fzgx_live = pl->b_24;
    fzgx_live_ = pos->y;
    fzgx_live_____ = pl->b_2C;
    d2 = fzgx_live + (fzgx_live_ * fzgx_live_____ + pos->x * pl->b_28 + pos->z * pl->b_30);
    if (-tol <= d2) {
        goto case2_ok;
    }
    return pool.p->one;
case2_ok:
    fzgx_live_ = pos->y;
    fzgx_live________ = pl->a_10;
    d1 = fn_1_16E68_read_pointer(pl) + (fzgx_live_ * fzgx_live________ + pos->x * pl->a_C + pos->z * pl->a_14);
    if (-tol <= d1) {
        goto out;
    }
    return pool.p->zero;
out:
    return d1 / (d1 + d2);
}
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset

