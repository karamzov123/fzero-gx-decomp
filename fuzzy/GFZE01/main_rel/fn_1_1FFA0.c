/* Non-matching: best partial attempt (98.91% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
extern const f32 lbl_1_rodata_6D0;
extern f32 lbl_1_rodata_6D4[5];
typedef struct { f32 x,y,z; } Vec;
#pragma opt_common_subs off
static inline int invalid(f32 value) {
    return (*(u32 *)&value & 0x7f800000) == 0x7f800000;
}
#pragma opt_common_subs reset

static inline f32 *fn_1_1FFA0_array_read(f32 *array) { return array; }
#pragma opt_common_subs off
static inline f32 fn_1_1FFA0_operand(f32 right, f32 left) { return left * right; }
#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
f32 fn_1_1FFA0(Vec *a, Vec *b, Vec *c, Vec *d, Vec *out1, Vec *out2) {
    f32 fzgx_live;
    f32 vy;
    f32 vx;
    f32 vz;
    f32 uy;
    f32 ux;
    f32 wx;
    f32 wy;
    f32 uz;
    f32 wz;
    f32 wv;
    f32 vu;
    f32 vv;
    f32 wu;
    f32 uu;
    f32 s;
    f32 t;
    fzgx_live = c->x;
    wx = a->x-fzgx_live;
    fzgx_live = c->x;
    vx = d->x-fzgx_live;
    vz = d->z-c->z;
    vy = d->y-c->y;
    ux = b->x-a->x;
    uy = b->y-a->y;
    wy = a->y-c->y;
    uz = b->z-a->z;
    wz = a->z-c->z;
    wv = ((f32)(wx*vx)+(f32)(wy*vy))+(f32)(wz*vz);
    vu = ((f32)(vx*ux)+(f32)(vy*uy))+(f32)(vz*uz);
    vv = ((f32)(vx*vx)+(f32)(vy*vy))+(f32)(vz*vz);
    wu = ((f32)(wx*ux)+(f32)(wy*uy))+(f32)(wz*uz);
    uu = ((f32)(ux*ux)+(f32)(uy*uy))+(f32)(uz*uz);
    s = ((f32)(wv*vu)-(f32)(wu*vv))/((f32)(uu*vv)-(f32)(vu*vu));
    if (invalid(s)) s = lbl_1_rodata_6D0;
    t = (wv+(f32)(s*vu))/vv;
    if (invalid(t)) t = lbl_1_rodata_6D0;
    psvec_sub(b,a,out1);
    if (s < lbl_1_rodata_6D0) s=lbl_1_rodata_6D0;
    else if (s > fn_1_1FFA0_array_read(lbl_1_rodata_6D4)[0]) s=fn_1_1FFA0_array_read(lbl_1_rodata_6D4)[0];
    psvec_scale(out1,s,out1);
    psvec_add(a,out1,out1);
    psvec_sub(d,c,out2);
    if (t < lbl_1_rodata_6D0) t=lbl_1_rodata_6D0;
    else if (t > fn_1_1FFA0_array_read(lbl_1_rodata_6D4)[0]) t=fn_1_1FFA0_array_read(lbl_1_rodata_6D4)[0];
    psvec_scale(out2,t,out2);
    psvec_add(c,out2,out2);
{
    Vec delta;
    psvec_sub(out2,out1,&delta);
    return (f32)(delta.x*delta.x)+delta.y*delta.y+delta.z*delta.z;
}
}
#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset

#pragma opt_common_subs reset


