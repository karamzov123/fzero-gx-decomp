/* Non-matching: best partial attempt (86.67% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    s16 angle_x;
    s16 angle_y;
    s16 angle_z;
} Fn8006F4E0;

extern void lbl_8006DAEC(void);
extern const f32 lbl_801A73F0;
extern const f32 lbl_801A73F4;
extern const f32 lbl_801A73F8;
extern void lbl_8006E1C0(Vec3 *, Vec3 *);
extern f32 lbl_8006D0B4(f32);
extern s16 lbl_8006D24C(f32, f32);
extern void lbl_8006D8D8(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void fn_8006E2B0(Vec3 *, Vec3 *);
extern void lbl_8006DB30(void);

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_loop_invariants off
void fn_8006F4E0(Fn8006F4E0 *self) {
    struct {
        Vec3 b;
        Vec3 a;
    } vec;
    Vec3 * lab_t0;
#define vec_a vec.a
#define vec_b vec.b
    f64 mx;
    f64 my;
    f32 mz;
    f32 sum;

    lbl_8006DAEC();
    vec_a.x = lbl_801A73F0;
    vec_a.y = lbl_801A73F4;
    vec_a.z = lbl_801A73F0;
    mx = *(f32 *)(0xE0000000 + 0x08);
    my = *(f32 *)(0xE0000000 + 0x18);
    mz = *(f32 *)(0xE0000000 + 0x28);
    vec_b.x = ((lbl_801A73F8) * (mx));
    vec_b.y = ((((my)) * ((lbl_801A73F8))));
    vec_b.z = ((lbl_801A73F8) * (mz));
    lab_t0 = &vec_a;
    lbl_8006E1C0(lab_t0, &vec_a);
    sum = vec_b.x * vec_b.x;
    self->angle_x = lbl_8006D24C(vec_b.y, lbl_8006D0B4(sum + vec_b.z * vec_b.z));
    self->angle_y = lbl_8006D24C(vec_b.x, vec_b.z) + -32768;
    lbl_8006D8D8(self->angle_y);
    mathutil_mtxA_rotate_x(self->angle_x);
    fn_8006E2B0(&vec_a, &vec_a);
    self->angle_z = -lbl_8006D24C(vec_a.x, vec_a.y);
    lbl_8006DB30();
}
#pragma opt_loop_invariants reset

#pragma opt_common_subs reset

