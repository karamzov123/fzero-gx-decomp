/* Non-matching: best partial attempt (73.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"

typedef struct Obj_10_1EF04 {
    s32 f00;
    s32 f04;
    s32 f08;
    void *f0C;
    const char *f10;
    u32 f14;
    u32 f18;
    s32 f1C;
    s32 f20;
} Obj_10_1EF04;

typedef struct Rec_10_1EF04 {
    u32 f00;
    u32 f04;
    f32 f08;
    f32 f0C;
    f32 f10;
    u8 pad14[0x1C];
    f32 f30;
    u32 f34;
    u8 pad38[8];
    u8 f40;
    u8 f41;
    u8 f42;
    u8 pad43[0x15];
} Rec_10_1EF04;

typedef struct Pool_10_1EF04 {
    u8 pad00[0x44];
    f32 v1;
    f32 v2;
    f32 v3;
    u8 pad10[0x8];
    f32 v4;
    u8 pad14[0xC];
    f32 v5;
    u8 pad18[0x10];
    f32 v6;
    u8 pad20[0x8];
    f64 v7;
    u8 pad28[0xA8];
    f32 v8;
    u8 pad2C[0x70];
    f32 v9;
    u8 pad30[0xDC];
    f32 vA;
    u8 pad34[0xC];
    f32 vB;
    u8 pad38[0x64];
    f32 v8B;
    u8 pad3C[0xECC];
    u32 vC;
    f32 vD;
    f32 vE;
    f32 vF;
    f32 vG;
} Pool_10_1EF04;

extern Pool_10_1EF04 lbl_10_rodata_158;
extern u32 lbl_1_rodata_26F8;
extern u32 fn_1_5233C();
extern void fn_10_200D8(u32, u32, u32, u32, f32);
extern u32 fn_1_50190(void *, f64, f32, f32, f32, f32, f32, f32);
extern u32 fn_1_50164(f32, f32, f32, f32, f32, void *);
extern void fn_1_49410(void);
extern void fn_1_49514(u32 *);
extern void fn_1_4954C(f32);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495A0(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(u32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4CE48(Obj_1_bss_4B9CC *, f32);

void fn_10_1EF04(Obj_10_1EF04 *arg0, f32 arg1) {
    Pool_10_1EF04 *p_pool;
    Obj_10_1EF04 *self;
    Rec_10_1EF04 rec;
    f32 v31;
    f32 v6;
    f32 v30;
    f32 v0;
    f32 v4;
    f32 vv;
    self = arg0;
    p_pool = (Pool_10_1EF04 *)&lbl_10_rodata_158;
    v31 = p_pool->v6;
    v6 = p_pool->v1;
    if (self->f20 == 1) {
        v31 = p_pool->vA;
    }
    if (self->f20 == 2) {
        v0 = (f32)(s32)self->f1C / p_pool->vB;
        v4 = p_pool->v3;
        if (!(v0 < v4)) {
            v4 = p_pool->v1;
            if (!(v0 > v4)) {
                v4 = v0;
            }
        }
        v6 = v4;
    }
    if (self->f0C != 0) {
        rec = *(Rec_10_1EF04 *)&lbl_1_rodata_26F8;
        rec.f04 = 0x10000 - 0x60F1;
        rec.f08 = p_pool->v4 + (f32)(s32)self->f00;
        rec.f0C = (f32)(s32)self->f04;
        rec.f10 = p_pool->v5 + v31;
        rec.f34 = 6;
        if (self->f20 == 1) {
            rec.f40 = 128;
            rec.f41 = 128;
            rec.f42 = 128;
        }
        v30 = v6 * arg1;
        rec.f30 = v30;
        fn_1_50190(&rec.f04, (double)(s32)self->f08, p_pool->vD, (f32)(s32)self->f08, p_pool->v8B, p_pool->v8B, p_pool->vE, p_pool->v8B);
        fn_1_49410();
        fn_1_496FC(p_pool->v4 + (f32)(s32)self->f00, (f32)(s32)(self->f04 + 6));
        fn_1_495C8(1);
        vv = p_pool->vF;
        fn_1_4955C(vv, vv);
        rec.f00 = p_pool->vC;
        fn_1_49514(&rec.f00);
        fn_1_495B0(0x80000000);
        fn_1_49590(p_pool->v2);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(p_pool->v1);
        fn_1_495A0(v30);
        fn_1_4954C(v31 - p_pool->v5);
        fn_1_4CE48((Obj_1_bss_4B9CC *)self->f0C, p_pool->vG);
        fn_10_200D8(self->f14, self->f00 + 0xB8, self->f18, (u32)(int)v31, v30);
        fn_1_49410();
        fn_1_496FC((f32)(s32)(self->f00 + 0xF5), (f32)(s32)(self->f04 + 0x30));
        fn_1_495C8(8);
        vv = p_pool->v9;
        fn_1_4955C(vv, vv);
        fn_1_495B0(0x80000000);
        fn_1_49590(p_pool->v2);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(p_pool->v1);
        fn_1_495A0(v30);
        fn_1_4954C(v31 - p_pool->v5);
        fn_1_4A0D8(self->f10);
    } else {
        rec = *(Rec_10_1EF04 *)&lbl_1_rodata_26F8;
        rec.f04 = 12;
        rec.f08 = p_pool->v4 + (f32)(s32)self->f00;
        rec.f0C = (f32)(s32)self->f04;
        rec.f10 = p_pool->v5 + v31;
        rec.f34 = 6;
        v30 = v6 * arg1;
        rec.f30 = v30;
        fn_1_50164(p_pool->vD, p_pool->v8, p_pool->v8B, p_pool->v8B, (f32)(s32)self->f04, &rec.f04);
        fn_10_200D8(self->f14, self->f00 + 0xB8, self->f04 + 0x26, (u32)(int)v31, v30);
        fn_1_49410();
        fn_1_496FC((f32)(s32)(self->f00 + 0xF5), (f32)(s32)(self->f04 + 0x26));
        fn_1_495C8(8);
        vv = p_pool->v9;
        fn_1_4955C(vv, vv);
        fn_1_495B0(0x80000000);
        fn_1_49590(p_pool->v2);
        fn_1_49738(fn_1_5233C);
        fn_1_49748(p_pool->v1);
        fn_1_495A0(v30);
        fn_1_4954C(v31 - p_pool->v5);
        fn_1_4A0D8(self->f10);
    }
}
