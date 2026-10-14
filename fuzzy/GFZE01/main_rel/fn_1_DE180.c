/* Non-matching: best partial attempt (64.41% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Sig_lbl_8006D534_Vec3;

struct fn_1_DE180_lbl_1_rodata_6780 {
    f32 unk_0;
    u8 pad_4[0x1C];
    f32 unk_20;
    u8 pad_24[0x4];
    f32 unk_28;
};

extern f32 lbl_8006D0B4(f32);
extern f32 lbl_8006D534(u32, u32);
extern f32 lbl_8006D668(void *);
extern struct fn_1_DE180_lbl_1_rodata_6780 lbl_1_rodata_6780;
extern void lbl_8006D5F0(u8 *, f32);
extern void fn_80008BA8(u8 *, u32, u32);
extern void fn_80008BEC(u8 *, int, u32);

f32 fn_1_DE180(Sig_lbl_8006D534_Vec3 *obj, Sig_lbl_8006D534_Vec3 *v, f32 t) {
    struct fn_1_DE180_lbl_1_rodata_6780 *pool = &lbl_1_rodata_6780;
    u32 *flags = (u32 *)((u8 *)obj + 0x138);
    u32 *flags2 = (u32 *)((u8 *)obj + 0x13c);
    Sig_lbl_8006D534_Vec3 a;
    Sig_lbl_8006D534_Vec3 b;
    Sig_lbl_8006D534_Vec3 c;
    s32 ok;

    if (((*flags2 & 0x18000) | (*flags & 0)) != 0) {
        return t;
    }
    {
        f32 d = lbl_8006D534((u32)&obj->x, (u32)v);
        f32 s;
        f32 k;
        f32 len;
        if (d > pool->unk_20) {
            return t;
        }
        s = lbl_8006D0B4(pool->unk_28 - d * d);
        k = obj->z * -obj->x;
        fn_80008BA8((u8 *)&c, (u32)v, 0xc);
        lbl_8006D5F0((u8 *)&c, k * d);
        fn_80008BA8((u8 *)&a, (u32)&obj->x, 0xc);
        {
            f32 cx = a.y * v->z - a.z * v->y;
            f32 cy = a.z * v->x - a.x * v->z;
            f32 cz = a.x * v->y - a.y * v->x;
            b.x = cx;
            b.y = cy;
            b.z = cz;
            cx = b.y * v->z - b.z * v->y;
            cy = b.z * v->x - b.x * v->z;
            cz = b.x * v->y - b.y * v->x;
            b.x = cx;
            b.y = cy;
            b.z = cz;
        }
        if (b.x * b.x + b.y * b.y + b.z * b.z > pool->unk_20) {
            lbl_8006D668(&b);
        }
        len = a.x * b.x + a.y * b.y + a.z * b.z;
        if (len <= pool->unk_20) {
            psvec_scale(&b.x, pool->unk_0, &b.x);
        }
        psvec_scale(&b.x, obj->z * s, &b.x);
        ok = 0;
        if (t >= pool->unk_20) {
            if (c.x * c.x + c.y * c.y + c.z * c.z <= t * t) {
                fn_80008BEC((u8 *)&c, 0, 0xc);
                ok = 1;
            }
        }
        if (ok) {
            *flags2 |= 0x18000;
            if (((*flags2 & 0x8000000) | (*flags & 0)) == 0) {
                *flags2 = *flags2;
                *flags |= 1;
            }
        }
        psvec_add(&c.x, &b.x, &obj->x);
        psvec_scale(&obj->z, pool->unk_28 - obj->x, &obj->z);
    }
    return t;
}
