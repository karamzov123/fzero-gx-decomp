/* Non-matching: best partial attempt (97.80% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "psvec.h"

typedef struct { f32 x; f32 y; f32 z; } Vec3;
typedef struct { u8 pad[0xA0]; Vec3 accum; } Owner;
extern void fn_8006E2B0(void *, void *);

static inline void scalar_set(Vec3 *out, f32 z, f32 y, f32 x)
{
    volatile Vec3 *p = out;
    p->x = x;
    p->y = y;
    p->z = z;
}

#pragma opt_propagation off
#pragma opt_common_subs off
void fn_1_29044(Owner *self, Vec3 *src, void *matrix)
{
    f32 fzgx_live__;
    f32 fzgx_live;
    f32 fzgx_live_;
    Vec3 transformed;
    f32 fzgx_value;
    Vec3 cross;
    Vec3 v;
    scalar_set(&v, src->z, src->y, src->x);
    fn_8006E2B0(matrix, &transformed);
    fzgx_live = v.y;
    fzgx_live__ = v.z;
    fzgx_value = (f32)(fzgx_live * transformed.z) - fzgx_live__ * transformed.y;
    cross.x = fzgx_value;
    fzgx_live_ = v.x;
    fzgx_live__ = v.z;
    cross.y = (f32)(fzgx_live__ * transformed.x) - fzgx_live_ * transformed.z;
    fzgx_live = v.y;
    fzgx_live_ = v.x;
    cross.z = (f32)(fzgx_live_ * transformed.y) - ((((fzgx_live)) * ((transformed.x))));
    psvec_add(&self->accum, &cross, &self->accum);
}
#pragma opt_common_subs reset

#pragma opt_propagation reset

