/* Non-matching: best partial attempt (74.08% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"
typedef struct { f32 x,y,z; } Vec3;
typedef struct { Vec3 v; u8 c[4]; } Particle;
extern u32 lbl_801A63C0;
extern s32 fn_1_58C4(void);
extern void fn_1_A714C(f32 *,f32 *,f32 *,f32 *);
extern f32 fn_1_A71AC(void);
static inline s32 random15(void) {
    lbl_801A63C0 = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    return (lbl_801A63C0 >> 16) & 0x7FFF;
}
void fn_1_105CC8(Particle *a, Particle *b, u8 *c, u8 *d, Vec3 *e, Vec3 *f, Vec3 *g, Vec3 *h) {
    Vec3 v;
    f32 q,r,p,s;
    f32 spread;
    f32 distance;
    f32 lateral;
    f32 vertical;
    f32 rand;
    f32 fade;
    u32 red, green, blue, dred, dgreen;
    f32 amount;
    s32 rn3;
    s32 rn;
    u32 state;
    u8 alpha;
    f32 life;
    if (fn_1_58C4() > 2) return;
    fn_1_A714C(&p,&q,&r,&s);
    v = *e;
    state = lbl_801A63C0 * 0x676A4B6B + 0x33CB;
    r -= 3.0f;
    rn = (state >> 16) & 0x7FFF;
    rand = (f32)rn / 32767.0f;
    lbl_801A63C0 = state;
    distance = r + (f32)(rand * (30.0f-r));
    psvec_scale_add(&v,g,distance,&v);
    lateral = (f32)((spread = 3.0f + distance) * fn_1_A71AC()) * ((f32)(2.5f * ((f32)random15() / 32767.0f)) - 1.25f);
    psvec_scale_add(&v,f,lateral,&v);
    rn3 = random15();
    amount = spread * fn_1_A71AC();
    vertical = (f32)(q * amount) * ((f32)(2.5f * ((f32)rn3 / 32767.0f)) - 1.25f);
    red = c[0];
    green = c[1];
    blue = c[2];
    dred = d[0];
    dgreen = d[1];
    life = 45.0f - distance;
    fade = 1.0f - (f32)(0.3f * rand);
    psvec_scale_add(&v,h,vertical,&v);
    a->v.x = 0.0f;
    a->v.y = -0.5f;
    a->v.z = 0.0f;
    a->c[0] = (s32)life;
    b->v = v;
    b->c[0] = (s32)((f32)red*fade);
    b->c[1] = (s32)((f32)green*fade);
    b->c[2] = (s32)((f32)blue*fade);
    alpha = c[3];
    b->c[3] = alpha;
    b[1].c[0] = (s32)((f32)dred*fade);
    b[1].c[1] = (s32)((f32)dgreen*fade);
    b[1].c[2] = (s32)((f32)(u32)d[2]*fade);
    b->c[3] = alpha;
}
