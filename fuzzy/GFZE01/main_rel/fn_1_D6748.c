/* Non-matching: best partial attempt (56.76% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_lig.h"

extern u32 lbl_1_rodata_6360[76];
extern s32 fn_1_66B8(void *, f32);
extern u8 fn_1_58C4(void);
extern void fn_1_681C(u32, u32 *);
extern u32 fn_1_584AC(void);
extern s16 fn_1_58E3C(void *);
extern f32 lbl_8006D0B4(f32);
extern void *memset(void *, int, u32);
extern f32 lbl_8006D668(void *);
extern u32 lbl_801A63C0;

typedef struct Vec3f { f32 x, y, z; } Vec3f;
typedef struct Blob { u8 bytes[0xe8]; } Blob;

static f32 dist2(Vec3f *p, f32 *v) {
    f32 x = p->x - v[0];
    f32 y = p->y - v[1];
    f32 z = p->z - v[2];
    return (f32)(x * x) + y * y + z * z;
}

void fn_1_D6748(Vec3f *a, Vec3f *b, u16 arg2) {
    u32 i, n;
    f32 best;
    Vec3f v;
    Blob obj;
    u32 seed, x, y, z;
    f32 t, u;
    f64 d;

    if (fn_1_66B8(a, *(f32 *)((u8 *)lbl_1_rodata_6360 + 0xc)) == 0 &&
        fn_1_66B8(b, *(f32 *)((u8 *)lbl_1_rodata_6360 + 0xc)) == 0)
        return;

    n = fn_1_58C4();
    fn_1_681C(0, (u32 *)&v);
    best = lbl_8006D0B4(dist2(a, (f32 *)&v));
    for (i = 1; i < n; i++) {
        fn_1_681C(i, (u32 *)&v);
        if (best < lbl_8006D0B4(dist2(a, (f32 *)&v))) {
        } else {
            best = lbl_8006D0B4(dist2(a, (f32 *)&v));
        }
    }
    if (best < *(f32 *)((u8 *)lbl_1_rodata_6360 + 0x10))
        return;

    n = fn_1_58C4();
    fn_1_681C(0, (u32 *)&v);
    best = lbl_8006D0B4(dist2(b, (f32 *)&v));
    for (i = 1; i < n; i++) {
        fn_1_681C(i, (u32 *)&v);
        if (best < lbl_8006D0B4(dist2(b, (f32 *)&v))) {
        } else {
            best = lbl_8006D0B4(dist2(b, (f32 *)&v));
        }
    }
    if (best >= *(f32 *)((u8 *)lbl_1_rodata_6360 + 0x10))
        return;

    memset(&obj, 0, sizeof(obj));
    *(u16 *)(obj.bytes + 0x18) = 0;
    *(u16 *)(obj.bytes + 0x0c) = 19;
    *(u16 *)(obj.bytes + 0x1a) = 0xffff;
    *(u16 *)(obj.bytes + 0xb2) = arg2;

    seed = lbl_801A63C0;
    x = seed * 0x676a4b6b + 0x33cb;
    y = x * 0x676a4b6b + 0x33cb;
    lbl_801A63C0 = x;
    d = (f64)((x >> 1) & 0x7fff) + *(f64 *)((u8 *)lbl_1_rodata_6360 + 0x58);
    t = ((f32)(d - *(f64 *)((u8 *)lbl_1_rodata_6360 + 0x58))) /
        *(f32 *)((u8 *)lbl_1_rodata_6360 + 0x28);
    u = (t - *(f32 *)((u8 *)lbl_1_rodata_6360 + 0x30)) *
        *(f64 *)((u8 *)lbl_1_rodata_6360 + 0x20);
    u += *(f64 *)((u8 *)lbl_1_rodata_6360 + 0x18);
    *(f32 *)(obj.bytes + 0x28) = u;
    d = (f64)((y >> 1) & 0x7fff) + *(f64 *)((u8 *)lbl_1_rodata_6360 + 0x58);
    t = ((f32)(d - *(f64 *)((u8 *)lbl_1_rodata_6360 + 0x58))) /
        *(f32 *)((u8 *)lbl_1_rodata_6360 + 0x28);
    u = (t - *(f32 *)((u8 *)lbl_1_rodata_6360 + 0x30)) *
        *(f64 *)((u8 *)lbl_1_rodata_6360 + 0x20);
    u += *(f64 *)((u8 *)lbl_1_rodata_6360 + 0x18);
    *(f32 *)(obj.bytes + 0x30) = u;

    *(u32 *)(obj.bytes + 0x3c) = b->x;
    *(u32 *)(obj.bytes + 0x40) = b->y;
    *(u32 *)(obj.bytes + 0x44) = b->z;
    *(u32 *)(obj.bytes + 0x48) = a->x;
    *(u32 *)(obj.bytes + 0x4c) = a->y;
    *(u32 *)(obj.bytes + 0x50) = a->z;
    *(u32 *)(obj.bytes + 0x38) = lbl_1_rodata_6360[0];
    *(u32 *)(obj.bytes + 0x3c) = lbl_1_rodata_6360[1];
    *(u32 *)(obj.bytes + 0x40) = lbl_1_rodata_6360[2];

    t = (f32)((s32)fn_1_584AC() - 0x8000) / *(f32 *)((u8 *)lbl_1_rodata_6360 + 0x28);
    *(f32 *)(obj.bytes + 0x20) = t;
    t = (f32)((s32)fn_1_584AC() - 0x8000) / *(f32 *)((u8 *)lbl_1_rodata_6360 + 0x28);
    *(f32 *)(obj.bytes + 0x24) = t;
    fn_1_584AC();
    fn_1_584AC();
    fn_1_58E3C(&obj);
}
