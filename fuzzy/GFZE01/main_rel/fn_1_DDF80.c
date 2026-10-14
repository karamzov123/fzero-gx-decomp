/* Non-matching: best partial attempt (97.73% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
#include "psvec.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -1.0f;
    s = 0.9999998807907104f;
    s = 1.0000001192092896f;
    s = -1.0000001192092896f;
    s = -0.9999998807907104f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 1.1920928955078125e-07;
    s = 0.0f;
    s = 5.0f;
    s = 1.0f;
}
static const u32 fzgx_pool_table4[1] = {0x00FF00FF};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
#pragma section code_type ".text"

extern f32 lbl_1_rodata_6780[10];
extern f32 lbl_8006D534(void *, void *, void *, void *, f32, f32);
extern f32 lbl_8006D0B4(f32);
extern void fn_80008BA8(void *, void *, u32);
extern u32 lbl_8006D5F0(void *, void *, f32);
extern void lbl_8006D668(void *);

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

static inline f32 fn_1_DDF80_read_pointer(Vec3 * owner) { return owner->z; }
#pragma opt_dead_assignments off
static inline f32 fn_1_DDF80_read_pointer_(Vec3 * owner) { return owner->y; }
static inline f32 fn_1_DDF80_read_pointer___read_pointer(Vec3 * owner) { return owner->z; }
static inline f32 fn_1_DDF80_read_pointer__(Vec3 * owner) { return fn_1_DDF80_read_pointer___read_pointer(owner); }
static inline f32 fn_1_DDF80_read_pointer___(Vec3 * owner) { return owner->x; }
static inline f32 fn_1_DDF80_read_pointer____(Vec3 * owner) { return owner->y; }
void fn_1_DDF80(Vec3 *a, Vec3 *b, Vec3 *c, Vec3 *out, f32 p1, f32 p2) {
    f32 n;
    f32 t;
    f32 fzgx_live;
    Vec3 v;
    f32 fzgx_live_;
    f32 fzgx_live__;
    f32 rz;
    f32 ry;
    f32 rx;

    t = lbl_8006D534(a, b, c, out, p1, p2);
    n = lbl_8006D0B4(1.0f - (f32)(t * t));
    fn_80008BA8(c, b, 12);
    lbl_8006D5F0(c, c, p1 * t);
    fn_80008BA8(&v, a, 12);
{
    f32 s2;
    s2 = p2;
    fzgx_live = b->y;
    fzgx_live_ = v.z;
    rx = (f32)(v.y * b->z) - fzgx_live_ * fzgx_live;
    ry = (f32)(v.z * b->x) - v.x * b->z;
    rz = (f32)(v.x * b->y) - v.y * b->x;
    out->x = rx;
    out->y = ry;
    out->z = rz;
    rx = (f32)(out->y * b->z) - fn_1_DDF80_read_pointer(out) * b->y;
    ry = (f32)(fn_1_DDF80_read_pointer(out) * b->x) - out->x * b->z;
    fzgx_live__ = b->y;
    rz = (f32)(out->x * fzgx_live__) - out->y * b->x;
    out->x = rx;
    out->y = ry;
    out->z = rz;
    if (out->x * out->x + out->y * fn_1_DDF80_read_pointer_(out) + fn_1_DDF80_read_pointer(out) * fn_1_DDF80_read_pointer(out) > 0.0f) {
        lbl_8006D668(out);
    }
    if (((fn_1_DDF80_read_pointer____(&v) * out->y) + (fn_1_DDF80_read_pointer___(&v) * out->x)) + fn_1_DDF80_read_pointer__(&v) * fn_1_DDF80_read_pointer(out) > 0.0f) {
    } else {
        psvec_scale(out, -1.0f, out);
    }
    psvec_scale(out, ((n) * (s2)), out);
}
}
#pragma opt_dead_assignments reset

