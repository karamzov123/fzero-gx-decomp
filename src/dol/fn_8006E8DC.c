#include "types.h"
#pragma fp_contract off

/* --- dol/fn_8006E8DC.c --- */
extern const f32 lbl_801A73D4;
extern const f32 lbl_801A73D8;
extern f32 lbl_8006D0E8(f32);

typedef struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

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

/* --- dol/fn_8006E978.c --- */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

extern f32 lbl_8006D0B4(f32);
extern const f32 lbl_801A73DC;
extern const f32 lbl_801A73E0;
extern const f32 lbl_801A73E4;
extern const f64 lbl_801A73E8;


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
