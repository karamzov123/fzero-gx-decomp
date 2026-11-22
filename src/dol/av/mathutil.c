#include "types.h"

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

typedef struct {
    Vec3 pos;
    Vec3 dir;
} VecPair;

typedef struct {
    Vec3 dir;
    Vec3 up;
} DirUp;

typedef struct {
    s16 angle_y;
    s16 angle_x;
    s16 angle_z;
} EulerAngles;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
    f32 unk_C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    f32 unk_2C;
} Mat34;

extern const f32 lbl_801A73D0;
extern const f32 lbl_801A73D4;
extern const f32 lbl_801A73D8;
extern const f32 lbl_801A73DC;
extern const f32 lbl_801A73E0;
extern const f32 lbl_801A73E4;
extern const f64 lbl_801A73E8;
extern const f32 lbl_801A73F0;
extern const f32 lbl_801A73F4;
extern const f32 lbl_801A73F8;
extern f32 lbl_801A73FC;
extern const f64 lbl_801A7400;
extern const f32 lbl_801A7408;
extern const f32 lbl_801A740C;
extern u32 lbl_80094E10[4];
extern f32 (*lbl_801A6D00)[4];
extern f32 lbl_801A6618;
extern f32 lbl_801A661C;

extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D0E8(f32);
extern f32 lbl_8006D188(s16);
extern s32 lbl_8006D24C(f32, f32);
extern u32 lbl_8006D5A4(void *, void *, void *, f32);
extern f32 lbl_8006D668(void *);
extern void lbl_8006D7DC(void *);
extern void lbl_8006D890(s16 angle);
extern void lbl_8006D8D8();
extern void lbl_8006D91C(s16 angle);
extern void lbl_8006DAEC();
extern void lbl_8006DB30(void);
extern void lbl_8006DBAC(void *);
extern u32 lbl_8006DC34(u32);
extern void lbl_8006DF44(void);
extern void lbl_8006E0C8(Vec3 *value);
extern void lbl_8006E1B0(void *, void *);
extern void lbl_8006E1C0(void *, void *);
extern void fn_8006E2B0(void *, void *);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16 angle);
extern void mathutil_mtxA_from_quat(void *);
extern f64 fn_800883E8(f64);
extern f64 fn_80088538(f64);

void fn_8006E5FC(f32 *arg0) {
    f32 q[4];
    u32 order[3];
    f32 t;
    f32 s;
    s32 i;
    s32 j;
    s32 k;
    f32 f;

    order[0] = lbl_80094E10[0];
    order[1] = lbl_80094E10[1];
    order[2] = lbl_80094E10[2];
    t = lbl_801A6D00[0][0] + lbl_801A6D00[1][1] + lbl_801A6D00[2][2];

    if (t > lbl_801A73D4) {
        s = lbl_8006D0B4(lbl_801A73D8 + t);
        f = lbl_801A73DC / s;
        arg0[3] = lbl_801A73DC * s;
        arg0[0] = f * (lbl_801A6D00[2][1] - lbl_801A6D00[1][2]);
        arg0[1] = f * (lbl_801A6D00[0][2] - lbl_801A6D00[2][0]);
        arg0[2] = f * (lbl_801A6D00[1][0] - lbl_801A6D00[0][1]);
    } else {
        i = 0;
        if (lbl_801A6D00[1][1] > lbl_801A6D00[0][0]) {
            i = 1;
        }
        if (lbl_801A6D00[2][2] > lbl_801A6D00[i][i]) {
            i = 2;
        }
        j = order[i];
        k = order[j];
        s = lbl_8006D0B4(lbl_801A73D8 + (lbl_801A6D00[i][i] - (lbl_801A6D00[j][j] + lbl_801A6D00[k][k])));
        q[i] = lbl_801A73DC * s;
        if (lbl_801A73D4 != s) {
            s = lbl_801A73DC / s;
        }
        q[3] = s * (lbl_801A6D00[k][j] - lbl_801A6D00[j][k]);
        q[j] = s * (lbl_801A6D00[j][i] + lbl_801A6D00[i][j]);
        q[k] = s * (lbl_801A6D00[k][i] + lbl_801A6D00[i][k]);
        arg0[0] = q[0];
        arg0[1] = q[1];
        arg0[2] = q[2];
        arg0[3] = q[3];
    }
}

#pragma opt_common_subs off
void fn_8006E7E4(Vec4 *arg0, Vec3 *arg1, s32 arg2) {
    f32 length_squared = arg1->x * arg1->x;
    f32 scale;

    length_squared += arg1->y * arg1->y;
    length_squared += arg1->z * arg1->z;

    if (length_squared < lbl_801A73D0) {
        arg0->x = lbl_801A73D4;
        arg0->y = lbl_801A73D4;
        arg0->z = lbl_801A73D4;
        arg0->w = lbl_801A73D8;
    } else {
        s16 a = arg2;
        f32 s = lbl_8006D188(a >> 1);
        scale = lbl_8006D0E8(length_squared);
        scale *= s;
        arg0->x = arg1->x * scale;
        arg0->y = arg1->y * scale;
        arg0->z = arg1->z * scale;
        arg0->w = lbl_8006D188((s16)(a >> 1) + 0x4000);
    }
}
#pragma opt_common_subs reset

#pragma fp_contract off
void fn_8006E8DC(Vec4 *arg0) {
    f32 scale = lbl_801A73D4;
    f32 length_squared = (arg0->x * arg0->x) + (arg0->y * arg0->y) + (arg0->z * arg0->z) + (arg0->w * arg0->w);

    if (length_squared > scale) {
        scale = lbl_8006D0E8(length_squared);
    } else {
        scale = lbl_801A73D8;
    }

    arg0->x = arg0->x * scale;
    arg0->y = arg0->y * scale;
    arg0->z = arg0->z * scale;
    arg0->w = arg0->w * scale;
}

void fn_8006E978(f32 *arg0, Vec3 *arg1, Vec3 *arg2) {
    f32 cx;
    f32 cy;
    f32 cz;
    f32 dot;
    f32 ax;
    f32 ay;
    f32 az;
    f32 n;
    f32 s;

    dot = arg1->x * arg2->x + arg1->y * arg2->y + arg1->z * arg2->z;
    if (dot > lbl_801A73E0) {
        arg0[2] = lbl_801A73D4;
        arg0[1] = lbl_801A73D4;
        arg0[0] = lbl_801A73D4;
        arg0[3] = lbl_801A73D8;
    } else if (dot < lbl_801A73E4) {
        ay = arg1->x;
        az = -arg1->y;
        ax = lbl_801A73D4;
        if (lbl_8006D0B4(arg1->x * arg1->x + az * az) < lbl_801A73E8) {
            ax = -arg1->z;
            ay = lbl_801A73D4;
            az = arg1->x;
        }
        n = lbl_8006D0E8(ax * ax + ay * ay + az * az);
        ax = ax * n;
        ay = ay * n;
        az = az * n;
        arg0[0] = ax;
        arg0[1] = ay;
        arg0[2] = az;
        arg0[3] = lbl_801A73D4;
    } else {
        cx = arg1->y * arg2->z - arg1->z * arg2->y;
        cy = arg1->z * arg2->x - arg1->x * arg2->z;
        cz = arg1->x * arg2->y - arg1->y * arg2->x;
        n = lbl_8006D0E8(cx * cx + cy * cy + cz * cz);
        cx = cx * n;
        cy = cy * n;
        cz = cz * n;
        s = lbl_8006D0B4(lbl_801A73DC * (lbl_801A73D8 - dot));
        cx = cx * s;
        cy = cy * s;
        cz = cz * s;
        arg0[0] = cx;
        arg0[1] = cy;
        arg0[2] = cz;
        arg0[3] = lbl_8006D0B4(lbl_801A73DC * (lbl_801A73D8 + dot));
    }
}

void fn_8006EB4C(Vec4 *arg0, const Vec4 *arg1, const Vec4 *arg2, f32 arg3) {
    f32 bx;
    f32 by;
    f32 bz;
    f32 bw;
    f32 dot;
    f32 w0;
    f32 w1;
    f32 ang;
    f32 s;

    bx = arg2->x;
    dot = arg1->w * (bw = arg2->w) + (arg1->z * (bz = arg2->z) + (arg1->x * bx + arg1->y * (by = arg2->y)));
    if (dot < lbl_801A73D4) {
        dot = -dot;
        bx = -bx;
        by = -by;
        bz = -bz;
        bw = -bw;
    }
    if (lbl_801A73D8 - dot > lbl_801A73E8) {
        ang = fn_80088538(dot);
        s = fn_800883E8(ang);
        w0 = lbl_801A73D8 - arg3;
        w0 = fn_800883E8(w0 * ang) / s;
        w1 = fn_800883E8(arg3 * ang) / s;
    } else {
        w0 = lbl_801A73D8 - arg3;
        w1 = arg3;
    }
    arg0->x = w0 * arg1->x + w1 * bx;
    arg0->y = w0 * arg1->y + w1 * by;
    arg0->z = w0 * arg1->z + w1 * bz;
    arg0->w = w0 * arg1->w + w1 * bw;
}
#pragma fp_contract reset

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

void fn_8006EDBC(Vec3 *arg0, Vec3 *arg1, s16 *arg2, s16 *arg3) {
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

void fn_8006EE70(const Vec3 *input, s16 *output) {
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

void fn_8006EF10(void *arg0, s16 *arg1, s16 *arg2) {
    f32 temp_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_sum;

    temp_f31 = -(*(f32 *)((u8 *)(arg0)));
    temp_f30 = *(f32 *)((u8 *)(arg0) + 4);
    temp_f29 = -(*(f32 *)((u8 *)(arg0) + 8));
    temp_sum = temp_f31 * temp_f31;
    temp_sum += temp_f29 * temp_f29;
    (*arg1) = lbl_8006D24C(temp_f30, (lbl_8006D0B4(temp_sum)));
    (*arg2) = lbl_8006D24C(temp_f31, temp_f29);
}

f32 fn_8006EFB4(s16 *arg0, f32 arg1, f32 *arg2) {
    f32 *pool;
    f32 z;
    f32 y;
    f32 x;
    f32 v;

    lbl_8006D8D8(arg0[1], arg2, arg1);
    mathutil_mtxA_rotate_x(arg0[0]);
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

void fn_8006F038(Vec3 *arg0, Vec3 *arg1, s16 arg2) {
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

void fn_8006F120(Vec3 *arg0, Vec3 *arg1) {
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

static inline void mathutil_cross3(Vec3 *a, Vec3 *b, Vec3 *out) {
    f32 ax;
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 bz = b->z;
    f32 by = b->y;
    f32 x;
    f32 y;
    f32 z;

    ax = a->x;
    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

#pragma opt_propagation off
void fn_8006F1F0(Vec3 *arg0, Vec3 *arg1, Vec3 *arg2) {
    Vec3 w;
    Vec3 u;
    Vec3 v;
    Mat34 *p;

    v.x = arg0->x - arg2->x;
    v.y = arg0->y - arg2->y;
    v.z = arg0->z - arg2->z;
    if (lbl_801A73F0 == lbl_8006D668(&v)) {
        lbl_8006D7DC(arg0);
        return;
    }
    mathutil_cross3(arg1, &v, &w);
    if (lbl_801A73F0 == lbl_8006D668(&w)) {
        lbl_8006D7DC(arg0);
        return;
    }
    mathutil_cross3(&v, &w, &u);
    if (lbl_801A73F0 == lbl_8006D668(&u)) {
        lbl_8006D7DC(arg0);
        return;
    }
    p = (Mat34 *)lbl_801A6D00;
    p->unk_0 = w.x;
    p->unk_4 = u.x;
    p->unk_8 = v.x;
    p->unk_C = arg0->x;
    p->unk_10 = w.y;
    p->unk_14 = u.y;
    p->unk_18 = v.y;
    p->unk_1C = arg0->y;
    p->unk_20 = w.z;
    p->unk_24 = u.z;
    p->unk_28 = v.z;
    p->unk_2C = arg0->z;
    lbl_8006DF44();
}
#pragma opt_propagation reset

u16 fn_8006F394(void) {
    /* Preserve the three stack stores observed in retail, including unused y. */
    volatile Vec3 v;
    f32 a, b, c;
    f32 scale = lbl_801A73F4;
    a = *(f32 *)(0xE0000000 + 8);
    c = *(f32 *)(0xE0000000 + 0x28);
    b = *(f32 *)(0xE0000000 + 0x18);
    a *= scale;
    c *= scale;
    b *= scale;
    v.x = a;
    v.y = b;
    v.z = c;
    return lbl_8006D24C(a, c);
}

#pragma opt_propagation off
static inline f32 fn_8006F3E4_read_pointer(VecPair *owner) { return owner->dir.z; }
void fn_8006F3E4(s16 *arg0, s16 *arg1, s16 *arg2) {
    f32 sum;
    f32 mz;
    f32 my;
    f32 mx;
    VecPair vec;
    f32 fzgx_live;

    lbl_8006DAEC(arg0, arg1, arg2);

    vec.pos.x = lbl_801A73F0;
    vec.pos.y = lbl_801A73F4;
    vec.pos.z = lbl_801A73F0;

    mx = *(f32 *)(0xE0000000 + 0x08);
    my = *(f32 *)(0xE0000000 + 0x18);
    mz = *(f32 *)(0xE0000000 + 0x28);

    vec.dir.x = mx * lbl_801A73F8;
    vec.dir.y = my * lbl_801A73F8;
    vec.dir.z = mz * lbl_801A73F8;

    lbl_8006E1C0(&vec, &vec);

    sum = vec.dir.x * vec.dir.x;
    fzgx_live = fn_8006F3E4_read_pointer(&vec);
    *arg1 = lbl_8006D24C(vec.dir.y, lbl_8006D0B4(sum + fzgx_live * fzgx_live));
    *arg0 = lbl_8006D24C(vec.dir.x, (vec.dir.z)) + -32768;

    lbl_8006D8D8(*arg0);
    mathutil_mtxA_rotate_x(*arg1);

    fn_8006E2B0(&vec, &vec);
    *arg2 = -lbl_8006D24C(vec.pos.x, vec.pos.y);

    lbl_8006DB30();
}
#pragma opt_propagation reset

#pragma opt_common_subs off
#pragma opt_dead_assignments off
void fn_8006F4E0(s16 *arg0) {
    DirUp v;
    lbl_8006DAEC();
    v.up.x = lbl_801A73F0;
    v.up.y = lbl_801A73F4;
    v.up.z = lbl_801A73F0;
    {
        f32 a, b, c;
        f32 scale = lbl_801A73F8;
        a = *(f32 *)(0xE0000000 + 0x08) * scale;
        b = *(f32 *)(0xE0000000 + 0x18) * scale;
        c = *(f32 *)(0xE0000000 + 0x28) * scale;
        v.dir.x = a;
        v.dir.y = b;
        v.dir.z = c;
    }
    lbl_8006E1C0(&v.up, &v.up);
    {
        f32 z;
        f32 x;
        f32 magnitude;
        x = v.dir.x;
        z = v.dir.z;
        magnitude = x * x;
        magnitude += z * z;
        arg0[0] = lbl_8006D24C(v.dir.y, lbl_8006D0B4(magnitude));
    }
    arg0[1] = lbl_8006D24C(v.dir.x, v.dir.z) - 0x8000;
    lbl_8006D8D8(arg0[1]);
    mathutil_mtxA_rotate_x(arg0[0]);
    fn_8006E2B0(&v.up, &v.up);
    arg0[2] = -lbl_8006D24C(v.up.x, v.up.y);
    lbl_8006DB30();
}
#pragma opt_dead_assignments reset
#pragma opt_common_subs reset

#pragma opt_dead_assignments off
void fn_8006F5C4(s16 *arg0, s16 *arg1, s16 *arg2) {
    Vec3 vec0;
    Vec3 vec1;

    lbl_8006DAEC(arg0, arg1, arg2);

    vec0.y = lbl_801A73F0;
    vec0.x = lbl_801A73F4;
    vec0.z = lbl_801A73F0;
    vec1.x = lbl_801A73F0;
    vec1.y = lbl_801A73F4;
    vec1.z = lbl_801A73F0;

    lbl_8006E1C0(&vec0, &vec0);
    lbl_8006E1C0(&vec1, &vec1);

    *arg0 = lbl_8006D24C(vec0.y, vec0.x);
    {
        f32 y;
        f32 x;
        f32 magnitude;

        y = vec0.y;
        x = vec0.x;
        magnitude = y * y;
        magnitude += x * x;
        *arg1 = -lbl_8006D24C(vec0.z, lbl_8006D0B4(magnitude));
    }

    lbl_8006D91C(*arg0);
    mathutil_mtxA_rotate_y(*arg1);

    fn_8006E2B0(&vec1, &vec1);
    *arg2 = lbl_8006D24C(vec1.z, vec1.y);

    lbl_8006DB30();
}
#pragma opt_dead_assignments reset

#pragma opt_common_subs off
void fn_8006F6A8(EulerAngles *self) {
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

f32 fn_8006F774(f32 arg0, f32 arg1) {
    lbl_801A6618 = (arg0 * lbl_801A73FC);
    lbl_801A661C = (arg1 * lbl_801A73FC);
    return (arg0 * lbl_801A73FC);
}

void fn_8006F78C(void *arg0, Vec3 *arg1, f32 arg2) {
    f32 value0;
    f32 value1;
    f32 value2;
    f32 factor;

    lbl_8006E1B0(arg0, arg1);
    value2 = arg1->z;
    if (__fabsf(value2) > lbl_801A7400) {
        factor = lbl_801A661C / (value2 * arg2);
        value0 = -arg1->x * factor;
        arg1->x = lbl_801A6618 + value0;
        value1 = arg1->y * factor;
        arg1->y = lbl_801A661C + value1;
    } else {
        arg1->x = lbl_801A7408;
        arg1->y = lbl_801A7408;
    }
}

void fn_8006F828(void *arg0, Vec3 *arg1, f32 arg2) {
    f32 value0;
    f32 value1;
    f32 value2;
    f32 factor;
    f32 cur0;
    f32 cur1;

    lbl_8006E1B0(arg0, arg1);
    value2 = arg1->z;
    if (__fabsf(value2) > lbl_801A7400) {
        factor = lbl_801A661C / (value2 * arg2);
        value0 = -arg1->x * factor;
        arg1->x = lbl_801A6618 + value0;
        value1 = arg1->y * factor;
        arg1->y = lbl_801A661C + value1;
        cur0 = arg1->x;
        if (cur0 < lbl_801A740C * lbl_801A6618 && cur0 > lbl_801A73F0) {
            cur1 = arg1->y;
            if (cur1 < lbl_801A740C * lbl_801A661C && cur1 > lbl_801A73F0) {
                return;
            }
        }
    }
    arg1->x = lbl_801A7408;
    arg1->y = lbl_801A7408;
}

void fn_8006F900(void *arg0, Vec3 *arg1, f32 arg2) {
    f32 value8;
    f32 factor;

    lbl_8006E1B0(arg0, arg1);
    value8 = arg1->z;
    if (__fabsf(value8) > lbl_801A7400) {
        factor = lbl_801A73F8 / (value8 * arg2);
        arg1->x = factor * (arg1->x * (lbl_801A740C * lbl_801A661C / (lbl_801A740C * lbl_801A6618)));
        arg1->y = arg1->y * factor;
    } else {
        arg1->x = lbl_801A7408;
        arg1->y = lbl_801A7408;
    }
}

void fn_8006F9A4(f32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    struct { u32 a[4]; } loc_28;
    struct { u32 a[4]; } loc_18;
    struct { u32 a[4]; } loc_8;

    lbl_8006DBAC((void *)arg1);
    fn_8006E5FC((f32 *)&loc_28);
    lbl_8006DBAC((void *)arg2);
    fn_8006E5FC((f32 *)&loc_18);
    fn_8006EB4C((Vec4 *)&loc_8, (const Vec4 *)&loc_28, (const Vec4 *)&loc_18, arg0);
    mathutil_mtxA_from_quat(&loc_8);
    lbl_8006DC34(arg3);
}

static inline void mathutil_cross4(Vec4 *a, Vec4 *b, Vec4 *out) {
    f32 ax = a->x;
    f32 ay = a->y;
    f32 az = a->z;
    f32 bx = b->x;
    f32 bz = b->z;
    f32 by = b->y;
    f32 x;
    f32 y;
    f32 z;
    x = ay * bz;
    x -= az * by;
    y = az * bx;
    y -= ax * bz;
    z = ax * by;
    z -= ay * bx;
    out->x = x;
    out->y = y;
    out->z = z;
}

void fn_8006FA24(f32 arg0, Vec4 *arg1, Vec4 *arg2, Vec4 *arg3) {
    lbl_8006D5A4(&arg1[0], &arg2[0], &arg3[0], arg0);
    lbl_8006D5A4(&arg1[1], &arg2[1], &arg3[1], arg0);
    mathutil_cross4(&arg3[0], &arg3[1], &arg3[2]);
    mathutil_cross4(&arg3[2], &arg3[0], &arg3[1]);
    lbl_8006D668(&arg3[0]);
    lbl_8006D668(&arg3[1]);
    lbl_8006D668(&arg3[2]);
}

void fn_8006FB20(f32 arg0, u32 arg1) {
    u32 tmp_lbl_8006D668;
    f32 lab_t3;
    Vec4 *const p = (Vec4 *)lbl_801A6D00;

    lab_t3 = arg0;
    lbl_8006D5A4(&p[0], (void *)arg1, &p[0], lab_t3);
    lbl_8006D5A4(&p[1], (void *)(arg1 + 16), &p[1], arg0);
    mathutil_cross4(&p[0], &p[1], &p[2]);
    mathutil_cross4(&p[2], &p[0], &p[1]);
    tmp_lbl_8006D668 = (u32)lbl_8006D668(&p[0]);
    tmp_lbl_8006D668;
    tmp_lbl_8006D668 = (u32)lbl_8006D668(&p[1]);
    tmp_lbl_8006D668;
    tmp_lbl_8006D668 = (u32)lbl_8006D668(&p[2]);
    tmp_lbl_8006D668;
}
