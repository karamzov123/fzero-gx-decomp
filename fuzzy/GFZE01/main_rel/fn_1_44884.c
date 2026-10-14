/* Non-matching: best partial attempt (89.79% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern void lbl_8006D668(void *vector);
extern f32 *lbl_801A6D00;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

#define M(i, f) (((Vec4 *)lbl_801A6D00)[i].f)

#pragma opt_strength_reduction off
static inline f32 fn_1_44884_read_pointer(Vec3 * owner) { return owner->x; }
#pragma opt_strength_reduction reset

#pragma opt_dead_assignments off
static inline f32 fn_1_44884_read_pointer_(Vec3 * owner) { return owner->z; }
#pragma opt_propagation off
static inline f32 fn_1_44884_read_pointer__(Vec3 * owner) { return owner->y; }
static inline f32 fn_1_44884_read_pointer___(Vec3 * owner) { return owner->z; }
void fn_1_44884(Vec3 *v) {
    struct { f32 value; } fzgx_value__;
    f64 fzgx_live;
    f32 *fzgx_value;
    f32 p2;
    f32 p3;
    Vec3 c;
    volatile Vec3 t;
    Vec3 d;

    fzgx_live = v->z;
{
    f32 p1;
    p1 = M(1, z) * fzgx_live;
    p2 = M(0, z) * v->y;
    p3 = M(2, z) * v->x;
    fzgx_value = &(c.x);
    *fzgx_value = p1 - M(2, z) * v->y;
}
    fzgx_value__.value = p2 - M(1, z) * v->x;
    c.z = fzgx_value__.value;
    c.y = p3 - M(0, z) * v->z;

    t.x = M(0, z);
    t.y = M(1, z);
    t.z = M(2, z);

    lbl_8006D668(&c);

{
    f32 fzgx_value_;
{
    f32 fzgx_live_;
    fzgx_live_ = v->y;
    fzgx_value_ = (f32)(fzgx_live_ * fn_1_44884_read_pointer_(&c)) - fn_1_44884_read_pointer___(v) * c.y;
}
    d.x = fzgx_value_;
}
    d.y = (f32)(v->z * fn_1_44884_read_pointer(&c)) - v->x * fn_1_44884_read_pointer_(&c);
    d.z = (f32)(v->x * fn_1_44884_read_pointer__(&c)) - v->y * fn_1_44884_read_pointer(&c);

    t.x = d.x;
    t.y = d.y;
    t.z = d.z;

    M(0, x) = v->x;
    M(1, x) = v->y;
    M(2, x) = v->z;
    M(0, y) = fn_1_44884_read_pointer(&c);
    M(1, y) = c.y;
    M(2, y) = fn_1_44884_read_pointer_(&c);
    M(0, z) = d.x;
    M(1, z) = d.y;
    M(2, z) = d.z;
}
#pragma opt_propagation reset

#pragma opt_dead_assignments reset
