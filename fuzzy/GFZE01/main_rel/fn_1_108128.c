/* Non-matching: best partial attempt (98.77% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

extern f32 lbl_8006D668(void *);
extern s32 fn_80077B14(void *);
extern u32 lbl_801A66A0;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 unk_0;
    u8 pad_1;
    u8 count;
    u8 pad_3;
    u16 ids[6];
    Vec3 pos;
    u8 pad_1C[0x28];
} Entry;

typedef struct {
    u8 pad_0[0x10];
    void *unk_10;
    u8 pad_14[4];
    u32 unk_18;
    u8 pad_1C[8];
    Entry *unk_24;
} Ctx;

#pragma opt_lifetimes off
static inline f32 fn_1_108128_read_pointer(Vec3 * owner) { return owner->z; }
#pragma opt_dead_assignments off
void fn_1_108128(Ctx *c, u32 idx) {
    f32 fzgx_live_;
    f32 fzgx_live;
    u8 *base;
    u32 i;
    Entry *e;
    u32 parity;
    u32 id;
    Ctx *ctx;
    f32 nz;
    f32 ny;
    f32 nx;
    Vec3 p1;
    Vec3 p0;
    u32 k;
    s32 tmp_call1;

    ctx = c;
    id = idx;
    if (0 == ctx) {
        return;
    }
    if (0 == ctx->unk_10) {
        return;
    }
    tmp_call1 = fn_80077B14(ctx->unk_10);
    base = (u8 *)tmp_call1;
    e = ctx->unk_24;
    parity = (1 & lbl_801A66A0) ^ 1;
    for (i = 0; i < ctx->unk_18; i++, e++) {
        if (((parity != 0) && ((1 & i) != 0)) || ((parity == 0) && ((1 & i) == 0))) {
            continue;
        }
        if (i > ctx->unk_18 - 1 - id) {
            if (i + 1 == id) {
                psvec_sub(&e[-1].pos, &e->pos, &p1);
                psvec_sub(&(e - id)->pos, &e->pos, &p0);
                lbl_8006D668(&p1);
                lbl_8006D668(&p0);
                fzgx_live = p1.y;
                fzgx_live_ = p0.x;
                nz = (f32)(p1.x * p0.y) - ((fzgx_live) * (fzgx_live_));
                fzgx_live = p1.y;
                nx = (f32)(fzgx_live * p0.z) - fn_1_108128_read_pointer(&p1) * p0.y;
                fzgx_live_ = p0.x;
                ny = (f32)(fn_1_108128_read_pointer(&p1) * fzgx_live_) - p1.x * p0.z;
            } else {
                psvec_sub(&(e - id)->pos, &e->pos, &p1);
                psvec_sub(&e[1].pos, &e->pos, &p0);
                lbl_8006D668(&p1);
                lbl_8006D668(&p0);
                fzgx_live = p1.y;
                fzgx_live_ = p0.x;
                nz = (f32)(p1.x * p0.y) - ((fzgx_live) * (fzgx_live_));
                fzgx_live = p1.y;
                nx = (f32)(fzgx_live * p0.z) - fn_1_108128_read_pointer(&p1) * p0.y;
                fzgx_live_ = p0.x;
                ny = (f32)(fn_1_108128_read_pointer(&p1) * fzgx_live_) - p1.x * p0.z;
            }
        } else {
            if (i + 1 == id) {
                psvec_sub(&(id + e)->pos, &e->pos, &p1);
                psvec_sub(&e[-1].pos, &e->pos, &p0);
                lbl_8006D668(&p1);
                lbl_8006D668(&p0);
                fzgx_live = p1.y;
                fzgx_live_ = p0.x;
                nz = (f32)(p1.x * p0.y) - ((fzgx_live) * (fzgx_live_));
                fzgx_live = p1.y;
                nx = (f32)(fzgx_live * p0.z) - fn_1_108128_read_pointer(&p1) * p0.y;
                fzgx_live_ = p0.x;
                ny = (f32)(fn_1_108128_read_pointer(&p1) * fzgx_live_) - p1.x * p0.z;
            } else {
                psvec_sub(&e[1].pos, &e->pos, &p1);
                psvec_sub(&(id + e)->pos, &e->pos, &p0);
                lbl_8006D668(&p1);
                lbl_8006D668(&p0);
                fzgx_live = p1.y;
                fzgx_live_ = p0.x;
                nz = (f32)(p1.x * p0.y) - ((fzgx_live) * (fzgx_live_));
                fzgx_live = p1.y;
                nx = (f32)(fzgx_live * p0.z) - fn_1_108128_read_pointer(&p1) * p0.y;
                fzgx_live_ = p0.x;
                ny = (f32)(fn_1_108128_read_pointer(&p1) * fzgx_live_) - p1.x * p0.z;
            }
        }
        for (k = 0; k < e->count; k++) {
            u32 *dst = (u32 *)((u8 *)base + e->ids[k] * 0x40 + 0xC);
            dst[0] = *(u32 *)&nx;
            dst[1] = *(u32 *)&ny;
            dst[2] = *(u32 *)&nz;
        }
    }
}
#pragma opt_dead_assignments reset

#pragma opt_lifetimes reset
