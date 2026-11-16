#include "types.h"

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Fn8006F6A8 {
    s16 angle_y;
    s16 angle_x;
    s16 angle_z;
} Fn8006F6A8;

extern void lbl_8006DAEC(void);
extern const f32 lbl_801A73F0;
extern const f32 lbl_801A73F4;
extern void lbl_8006E1C0(Vec3 *, Vec3 *);
extern s16 lbl_8006D24C(f32, f32);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D91C(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void fn_8006E2B0(Vec3 *, Vec3 *);
extern void lbl_8006DB30(void);

#pragma opt_common_subs off
void fn_8006F6A8(Fn8006F6A8 *self) {
    Vec3 vec_b;
    Vec3 vec_a;
    f32 zero;
    f32 one;
    f32 sum;

    lbl_8006DAEC();

    zero = lbl_801A73F0;
    one = lbl_801A73F4;

    vec_a.y = zero;
    vec_a.x = one;
    vec_a.z = zero;
    vec_b.x = zero;
    vec_b.y = one;
    vec_b.z = zero;

    lbl_8006E1C0(&vec_a, &vec_a);
    lbl_8006E1C0(&vec_b, &vec_b);

    self->angle_z = lbl_8006D24C(vec_a.y, vec_a.x);
    sum = vec_a.y;
    sum = sum * vec_a.y;
    self->angle_x = -lbl_8006D24C(vec_a.z, lbl_8006D0B4(sum + vec_a.x * vec_a.x));

    lbl_8006D91C(self->angle_z);
    mathutil_mtxA_rotate_y(self->angle_x);
    fn_8006E2B0(&vec_b, &vec_b);
    self->angle_y = lbl_8006D24C(vec_b.z, vec_b.y);

    lbl_8006DB30();
}


#pragma opt_common_subs reset
