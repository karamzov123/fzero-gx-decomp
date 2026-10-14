/* Non-matching: best partial attempt (57.39% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_1_645D4_Vec3;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Sig_fn_1_645D4_Vec4;

struct fn_1_645D4_pool {
    u8 pad_0[0x8];
    f32 f8;
    f32 fC;
    u8 pad_10[0x28];
    f64 d38;
    u8 pad_40[0x178];
    f64 d1B8;
    u8 pad_1C0[0x16C];
    u32 w32C;
    u32 w330;
    u32 w334;
};

struct fn_1_645D4_S {
    u8 pad_0[0x34];
    f64 a;
    f64 b;
    f64 c;
};

struct fn_1_645D4_Arg0 {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1A[0x22];
    f32 unk_3C;
    u8 pad_40[0x54];
    Sig_fn_1_645D4_Vec4 unk_94;
};

extern struct fn_1_645D4_pool lbl_1_rodata_2950;
extern struct {
    u32 state;
} lbl_801A63C0;
extern void fn_1_862D4(int, Sig_fn_1_645D4_Vec3 *);
extern void fn_1_8636C(int, void *);
extern void lbl_8006D5A4(Sig_fn_1_645D4_Vec4 *, Sig_fn_1_645D4_Vec3 *, Sig_fn_1_645D4_Vec4 *, f32);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(Sig_fn_1_645D4_Vec4 *, f32 *);

void fn_1_645D4(struct fn_1_645D4_Arg0 *arg0) {
    struct fn_1_645D4_pool *pool = &lbl_1_rodata_2950;
    Sig_fn_1_645D4_Vec3 v8;
    Sig_fn_1_645D4_Vec3 v14;
    Sig_fn_1_645D4_Vec3 v20;
    struct fn_1_645D4_S s;
    u32 t1;
    u32 t2;
    u32 t3;

    fn_1_862D4(arg0->unk_18, &v20);
    fn_1_8636C(arg0->unk_18, (void *)&s);

    t1 = lbl_801A63C0.state * 0x676A4B6B + 0x33CB;
    t2 = t1 * 0x676A4B6B + 0x33CB;
    t3 = t2 * 0x676A4B6B + 0x33CB;
    lbl_801A63C0.state = t1;
    lbl_801A63C0.state = t2;
    lbl_801A63C0.state = t3;

    s.a = (f64)(s32)((t1 >> 1) & 0x7FFF);
    s.b = (f64)(s32)((t2 >> 1) & 0x7FFF);
    s.c = (f64)(s32)((t3 >> 1) & 0x7FFF);

    v8.x = (f32)(pool->d1B8 * ((f32)s.a / pool->f8));
    v8.y = (f32)(pool->d1B8 * ((f32)s.b / pool->f8));
    v8.z = (f32)(pool->d1B8 * ((f32)s.c / pool->f8));
    v14 = v8;

    lbl_8006D5A4(&arg0->unk_94, &v14, &arg0->unk_94, pool->fC);
    lbl_8006DC6C((void *)&s);
    *(f32 *)(0xE0000000 + 0x0C) = v20.x;
    *(f32 *)(0xE0000000 + 0x1C) = v20.y;
    *(f32 *)(0xE0000000 + 0x2C) = v20.z;
    lbl_8006E1B0(&arg0->unk_94, &arg0->unk_3C);
}
