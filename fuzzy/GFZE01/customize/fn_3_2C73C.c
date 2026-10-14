/* Non-matching: best partial attempt (74.79% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_0[0x390];
    u32 unk_390;
} Obj3_Inner;

typedef struct {
    Obj3_Inner *unk_0;
} Obj3_Outer;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    f32 unk_8;
} Obj3_Vec3;

typedef struct {
    u32 unk_0;
    u16 unk_4;
} Obj3_A4;

typedef struct {
    u8 pad_0[0x34];
    s16 unk_34;
    f32 unk_38[3];
    u32 unk_44;
    u32 unk_48;
    u32 unk_4c;
    u32 unk_50;
    u16 unk_54;
} Obj3_A2460;
extern Obj3_A2460 lbl_3_bss_A2460;

typedef struct {
    f32 unk_0;
    f32 unk_4;
    u8 pad_8[0x30];
    u8 unk_38;
    u8 pad_39[0x1F];
    u32 unk_58;
} Obj3_241E0;
extern Obj3_241E0 lbl_3_bss_241E0;

typedef struct {
    u8 pad_0[0x188];
    f32 unk_188;
    u8 pad_18C[0x44];
    f32 unk_1d0;
    u8 pad_1D4[0x58];
    f32 unk_22c;
    u8 pad_230[0x348];
    f32 unk_578;
    u8 pad_57C[0x13C];
    u32 unk_6b8;
    u32 unk_6bc;
    u32 unk_6c0;
    f32 unk_6c4;
    f32 unk_6c8;
} Obj3_rodata_768;
extern Obj3_rodata_768 lbl_3_rodata_768;

#define FZ_CLAMP(x, lo, hi) (((x) < (lo)) ? (lo) : (((x) > (hi)) ? (hi) : (x)))

typedef s32 (*Fn3_2C290_cb)(void *);
extern s32 fn_3_2C290(void *);
extern void fn_1_151BDC(void *);
extern void fn_1_8D1EC(Obj3_241E0 *, Fn3_2C290_cb, void *);

void fn_3_2C73C(void *arg0, Obj3_Outer *arg1, Obj3_Vec3 *arg2, Obj3_Vec3 *arg3,
                Obj3_A4 *arg4, f32 arg5, f32 arg6) {
    Obj3_Outer *a1;
    Obj3_A2460 *g;
    Obj3_Inner *p;
    Obj3_rodata_768 *pool;
    f32 *v;
    u32 w0;
    u16 w1;
    f32 t;
    f32 s;
    f32 inv;
    f32 bx;
    f32 by;
    f32 bz;
    f32 ax;
    f32 ay;
    f32 az;
    f32 rx;
    f32 ry;
    f32 rz;
    s32 iv;

    pool = &lbl_3_rodata_768;
    a1 = arg1;
    g = &lbl_3_bss_A2460;
    p = a1->unk_0;
    v = &g->unk_38[0];
    t = FZ_CLAMP(arg5, pool->unk_1d0, arg6);
    s = t / arg6;
    inv = pool->unk_188 - s;
    bx = arg3->unk_0;
    by = arg3->unk_4;
    bz = arg3->unk_8;
    ax = arg2->unk_0;
    ay = arg2->unk_4;
    az = arg2->unk_8;
    rx = (f32)(ax * inv) + (f32)(bx * s);
    ry = (f32)(ay * inv) + (f32)(by * s);
    rz = (f32)(az * inv) + (f32)(bz * s);
    iv = (s32)t;
    w0 = arg4->unk_0;
    w1 = arg4->unk_4;
    g->unk_50 = w0;
    g->unk_54 = w1;
    *v = rx;
    v[1] = ry;
    v[2] = rz;
    g->unk_44 = pool->unk_6b8;
    g->unk_48 = pool->unk_6bc;
    g->unk_4c = pool->unk_6c0;
    g->unk_34 = (s16)iv;
    lbl_3_bss_241E0.unk_38 = 0;
    lbl_3_bss_241E0.unk_58 = 0;
    lbl_3_bss_241E0.unk_0 = pool->unk_578 * FZ_CLAMP(t, pool->unk_1d0, pool->unk_22c);
    lbl_3_bss_241E0.unk_4 = pool->unk_6c4 + (f32)(pool->unk_6c8 * FZ_CLAMP(t, pool->unk_1d0, arg6));
    if (p->unk_390 & 0x4000000) {
        fn_1_151BDC(arg0);
    }
    fn_1_8D1EC(&lbl_3_bss_241E0, fn_3_2C290, a1);
}
