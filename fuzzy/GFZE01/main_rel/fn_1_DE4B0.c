/* Non-matching: best partial attempt (56.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct { s16 angle_y, angle_x, angle_z; } Angles;
typedef struct { u32 a[3]; } U32Vec;
typedef struct { f32 a[4]; } Quat;
typedef struct { f32 a[10]; } Mat;
typedef struct {
    u8 pad0[0x0c]; s16 type;
    u8 pad0e[0x46]; f32 p54;
    u8 pad58[0x30]; f32 x; f32 scale; f32 z;
    u8 pad94[0xa4]; volatile u32 flags0; volatile u32 flags1;
} Object;
struct Pool {
    f32 v0; u8 p4[0x1c]; f32 zero; u8 p24[0xc]; f32 tenth; u8 p34[0x18];
    u32 a4; u32 a8; u32 ac; u32 b0; u32 b4; u32 b8; u32 bc; u32 c0; u32 c4;
    f32 rad; f32 onehalf; f32 epsneg; f32 eps; f64 two52;
};
struct Global { u32 value; };
extern struct Pool lbl_1_rodata_6780;
extern struct Global lbl_801A63C0;
extern void fn_1_E5840(void *, const void *);
extern u32 lbl_8006DBAC(void *);
extern u32 lbl_8006E1B0(void *);
extern u32 lbl_8006E1C0(void *);
extern f32 lbl_8006D668(void *);
extern void fn_80008BA8(void *, void *, u32);
extern void fn_8006E978(void *, void *, void *);
extern void mathutil_mtxA_from_quat(void *);
extern void fn_8006F6A8(Angles *);

void fn_1_DE4B0(Object *obj, Vec3 *arg1) {
    struct Pool *pool = &lbl_1_rodata_6780;
    U32Vec a;
    a.a[0] = pool->a4; a.a[1] = pool->a8; a.a[2] = pool->ac;
    if ((obj->flags0 & 1) && obj->type == 1) {
        if (obj->flags0 & 4) {
            U32Vec b, c;
            Vec3 q;
            Angles ang;
            Vec3 out;
            b.a[0]=pool->b0; b.a[1]=pool->b4; b.a[2]=pool->b8;
            c.a[0]=pool->bc; c.a[1]=pool->c0; c.a[2]=pool->c4;
            lbl_8006DBAC((u8 *)obj + 0xc4);
            if ((((lbl_801A63C0.value * 0x676a4b6bu + 0x33cb) >> 16) & 0x7fff) == 0) {
                lbl_8006E1C0(&b);
                lbl_8006D668(&b);
                fn_80008BA8(&q, &b, 12);
            } else {
                lbl_8006E1C0(&c);
                lbl_8006D668(&c);
                fn_80008BA8(&q, &c, 12);
            }
            fn_8006E978(&out, &q, arg1);
            mathutil_mtxA_from_quat(&out);
            fn_8006F6A8(&ang);
            {
                f32 t = pool->rad;
                Vec3 rot;
                rot.x = (f32)ang.angle_y*t;
                rot.y = (f32)ang.angle_x*t;
                rot.z = (f32)ang.angle_z*t;
                fn_1_E5840(obj, &rot);
            }
        } else {
            Vec3 v;
            v.x = pool->zero; v.y = pool->onehalf * obj->scale; v.z = pool->zero;
            if (!(v.x == obj->x && v.x == obj->scale && v.x == obj->z)) {
                Vec3 u, w, n, cross;
                Mat m;
                Angles ang;
                f32 ax = arg1->x, ay = arg1->y, az = arg1->z;
                lbl_8006DBAC((u8 *)obj + 0xc4);
                lbl_8006E1B0(&v);
                lbl_8006E1B0((u8 *)obj + 0x88);
                lbl_8006E1C0((u8 *)obj + 0x88);
                lbl_8006E1C0(&a);
                lbl_8006D668(&a);
                u.x = (f32)(0.0f); u.y = 0.0f; u.z=0.0f;
                w.x = (f32)(0.0f); w.y=0.0f; w.z=0.0f;
                n.x = (f32)(0.0f); n.y=0.0f; n.z=0.0f;
                {
                    f32 x = ((f32 *)((u8 *)obj + 0x88))[0];
                    f32 y = ((f32 *)((u8 *)obj + 0x88))[1];
                    f32 z = ((f32 *)((u8 *)obj + 0x88))[2];
                    f32 c0 = (f32)(z*ax) - (y*az);
                    f32 c1 = (f32)(y*ay) - (x*az);
                    f32 c2 = (f32)(x*az) - (z*ay);
                    f32 d0 = (f32)(c0*az) - (c1*ay);
                    f32 d1 = (f32)(c1*ax) - (c2*az);
                    f32 d2 = (f32)(c2*ay) - (c0*ax);
                    f32 dot = (f32)(d0*0.0f) + ((f32)(d1*(1.5f*obj->scale)) + (d2*0.0f));
                    f32 eps = -(d0*0.0f + (d1*0.0f + d2*0.0f));
                    if ((eps+dot)*(eps+d0*x+d1*y+d2*z) > -1.1920928955078125e-7f) {
                        fn_80008BA8(&cross, &a, 12);
                    } else {
                        cross.x = (f32)(c2*a.a[2]) - (c1*a.a[1]);
                        cross.y = (f32)(c1*a.a[0]) - (c0*a.a[2]);
                        cross.z = (f32)(c0*a.a[1]) - (c2*a.a[0]);
                        lbl_8006D668(&cross);
                    }
                    if (arg1->x*cross.x + (arg1->y*cross.y + arg1->z*cross.z) < 0.0f) {
                        cross.x = -cross.x; cross.y = -cross.y; cross.z = -cross.z;
                    }
                }
                fn_8006E978(&m, &cross, arg1);
                mathutil_mtxA_from_quat(&m);
                fn_8006F6A8(&ang);
                {
                    f32 t=pool->rad, k=pool->tenth;
                    Vec3 angles;
                    angles.x=(f32)ang.angle_y*t*k;
                    angles.y=(f32)ang.angle_x*t*k;
                    angles.z=(f32)ang.angle_z*t*k;
                    *(Vec3 *)((u8 *)obj+0x6c)=angles;
                }
            }
        }
    }
}
