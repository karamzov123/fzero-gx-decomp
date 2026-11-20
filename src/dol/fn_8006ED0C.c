#include "types.h"
#include "dolphin/types.h"


/* --- dol/fn_8006ED0C.c --- */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

extern f32 lbl_8006D0B4(f32);
extern s32 lbl_8006D24C(f32, f32);

void fn_8006ED0C(Vec3 *arg0, Vec3 *arg1, s16 *arg2) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 sum;

    dx = arg0->x - arg1->x;
    dz = arg0->z - arg1->z;
    dy = arg1->y - arg0->y;
    sum = dx * dx;
    sum += dz * dz;
    arg2[0] = lbl_8006D24C(dy, lbl_8006D0B4(sum));
    arg2[1] = lbl_8006D24C(dx, dz);
    arg2[2] = 0;
}

/* --- dol/fn_8006EDBC.c --- */
typedef struct Vec3_u1 {
    f32 x;
    f32 y;
    f32 z;
} Vec3_u1;


void fn_8006EDBC(Vec3_u1 *arg0, Vec3_u1 *arg1, s16 *arg2, s16 *arg3) {
    f32 dx;
    f32 dy;
    f32 dz;
    f32 dist;

    dx = arg0->x - arg1->x;
    dy = arg1->y - arg0->y;
    dz = arg0->z - arg1->z;
    dist = dx * dx;
    dist += dz * dz;
    *arg2 = lbl_8006D24C(dy, lbl_8006D0B4(dist));
    *arg3 = lbl_8006D24C(dx, dz);
}

/* --- dol/fn_8006EE70.c --- */
typedef struct Vec3_u2 {
    f32 x;
    f32 y;
    f32 z;
} Vec3_u2;

void fn_8006EE70(const Vec3_u2 *input, s16 *output) {
    s16 *dst;
    f32 x;
    f32 y;
    f32 z;
    f32 sum;

    dst = output;
    x = -input->x;
    y = input->y;
    z = -input->z;
    sum = x * x;
    sum += z * z;
    dst[0] = lbl_8006D24C(y, lbl_8006D0B4(sum));
    dst[1] = lbl_8006D24C(x, z);
    dst[2] = 0;
}

/* --- dol/fn_8006EF10.c --- */
/* --- dol/fn_8006EF10.c --- */
struct fn_8006EF10_Arg0 {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
};


void fn_8006EF10(void *arg0, s16 *arg1, s16 *arg2) {
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_sum;

    temp_f31 = -(*(f32 *)((u8 *)(arg0) + 0));
    temp_f30 = *(f32 *)((u8 *)(arg0) + 4);
    temp_f29 = -(*(f32 *)((u8 *)(arg0) + 8));
    temp_sum = temp_f31 * temp_f31;
    temp_sum += temp_f29 * temp_f29;
    (*(s16 *)((u8 *)(arg1) + 0)) = lbl_8006D24C((f32)(temp_f30), (f32)(lbl_8006D0B4(temp_sum)));
    (*(s16 *)((u8 *)(arg2) + 0)) = lbl_8006D24C((f32)(temp_f31), (f32)(temp_f29));
}

/* --- dol/fn_8006EFB4.c --- */
struct fn_8006EFB4_Arg0 {
    s16 unk_0;
    s16 unk_2;
};

extern void lbl_8006D8D8(s16, f32 *, f32);
extern void mathutil_mtxA_rotate_x(s16);

f32 fn_8006EFB4(struct fn_8006EFB4_Arg0 *arg0, f32 arg1, f32 *arg2) {
    f32 *pool;
    f32 z;
    f32 y;
    f32 x;
    f32 v;

    lbl_8006D8D8(arg0->unk_2, arg2, arg1);
    mathutil_mtxA_rotate_x(arg0->unk_0);
    pool = (f32 *)0xE0000000; /* fzgx-allow: A2 fixed float pool base */
    v = -arg1;
    x = pool[2];
    x *= v;
    y = pool[6];
    y *= v;
    z = pool[10];
    z *= v;
    arg2[0] = x;
    arg2[1] = y;
    arg2[2] = z;
    return y;
}

/* --- dol/fn_8006F038.c --- */
typedef struct Vec3_u3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3_u3;

extern void lbl_8006D91C(s16 angle);
extern void mathutil_mtxA_rotate_y(s16 angle);
extern void lbl_8006E0C8(Vec3_u3 *value);

void fn_8006F038(Vec3_u3 *arg0, Vec3_u3 *arg1, s16 arg2) {
    f32 dz;
    f32 dy;
    f32 dx;
    f32 distance;
    s32 angle_x;
    s32 angle_y;

    dx = arg0->x - arg1->x;
    dy = arg1->y - arg0->y;
    dz = arg0->z - arg1->z;
    distance = dx * dx;
    distance += dz * dz;
    distance = lbl_8006D0B4(distance);
    angle_x = lbl_8006D24C(dy, distance);
    angle_y = lbl_8006D24C(dx, dz);
    lbl_8006D91C(-arg2);
    mathutil_mtxA_rotate_x(-angle_x);
    mathutil_mtxA_rotate_y(-angle_y);
    lbl_8006E0C8(arg0);
}

/* --- dol/fn_8006F120.c --- */
extern void lbl_8006D890(s16 angle);

void fn_8006F120(Vec3_u3 *arg0, Vec3_u3 *arg1) {
    f32 dz;
    f32 dy;
    f32 dx;
    f32 distance;
    s32 angle_x;
    s32 angle_y;

    dx = arg0->x - arg1->x;
    dy = arg1->y - arg0->y;
    dz = arg0->z - arg1->z;
    distance = dx * dx;
    distance += dz * dz;
    distance = lbl_8006D0B4(distance);
    angle_x = lbl_8006D24C(dy, distance);
    angle_y = lbl_8006D24C(dx, dz);
    lbl_8006D890(-angle_x);
    mathutil_mtxA_rotate_y(-angle_y);
    lbl_8006E0C8(arg0);
}
