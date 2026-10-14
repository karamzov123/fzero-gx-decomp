/* Non-matching: best partial attempt (66.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

struct Arg0 {
    u8 pad0[0x18];
    s16 field18;
};
struct Pool {
    u8 pad0[0x1c]; f32 f1c;
    u8 pad20[4]; f32 f24;
    u8 pad28[0x18]; f64 f40; f32 f48;
    u8 pad4c[0x18]; f32 f64; f64 f68;
    u8 pad70[4]; f32 f74;
    u8 pad78[0x18]; f32 f90; f32 f94;
    u8 pad98[0x20]; f32 fb8;
    u8 padbc[0x14]; f64 fd0; f32 fd8;
    u8 paddc[0x10]; f32 fec;
    u8 padf0[0x18]; f64 f108;
    u8 pad110[0xb0]; f64 f1c0;
    u8 pad1c8[0x38]; f32 f200;
    u8 pad204[4]; f64 f208; f32 f210;
    u8 pad214[4]; f64 f218; f32 f220;
    u8 pad224[4]; f64 f228; f32 f230;
};
extern f32 fn_1_8652C(int);
extern f32 lbl_8006D0B4(f32);
extern s16 fn_1_58F50(const void *);
extern struct Pool lbl_1_rodata_2D70;
extern u32 fn_1_584AC(void);
extern u32 lbl_8006D5F0(void *, void *, f32);
extern u8 *memset(u8 *, int, u32);
extern void lbl_8006DD14(void *, void *);

void fn_1_6CF3C(struct Arg0 *arg0, Vec3 *arg1, f32 arg2, f32 arg3) {
    struct Pool *pool = &lbl_1_rodata_2D70;
    f32 t0;
    f32 t2;
    f32 v2;
    f64 v3, v4, v5, v7, v9, v13;
    f32 v6, v8, v11, v12, v14;
    s16 v10;
    s32 v15;
    f32 v16;
    void *v17;
    u32 t5, t6, t7, t8, t9, t10, t11;
    f64 v22, v23, v24;
    f32 v26, v27, v28;
    u8 work[232];
    f64 *loc_C0 = (f64 *)(work + 0xb8);

    t0 = fn_1_8652C(arg0->field18);
    memset(work, 0, 232);
    v2 = pool->f210 * arg2;
    *(s16 *)(work + 12) = arg0->field18;
    *(u16 *)(work + 6) = 15;
    *(u16 *)(work + 14) = 0xffff;
    v3 = pool->f68;
    v4 = pool->f108;
    v5 = (f64)pool->f208 * (f64)arg2;
    v6 = pool->fec;
    v7 = (f64)pool->f68 + (f64)(pool->f200 * arg2);
    v8 = pool->fd8;
    loc_C0[16] = (f32)((f64)pool->f228 + (f64)(t0 / pool->f230));
    v9 = pool->f40;
    v10 = (s16)(s32)v2;
    v11 = pool->f24;
    v12 = pool->f1c;
    v13 = pool->fd0;
    v14 = pool->f48;
    loc_C0[15] = pool->f220;
    v15 = 2;
    do {
        v16 = *(f32 *)((u8 *)arg0 + 0x4c);
        t2 = lbl_8006D0B4((*(f32 *)((u8 *)arg0 + 0x50) * *(f32 *)((u8 *)arg0 + 0x50)) +
                           (v16 * v16 + *(f32 *)((u8 *)arg0 + 0x48) * *(f32 *)((u8 *)arg0 + 0x48)));
        if (t2 > v6) {
            v17 = (u8 *)arg0 + 0x48;
            lbl_8006D5F0(v17, v17, v6);
        }
        *(u32 *)(work + 60) = *(u32 *)((u8 *)arg0 + 60);
        *(u32 *)(work + 64) = *(u32 *)((u8 *)arg0 + 64);
        *(u32 *)(work + 68) = *(u32 *)((u8 *)arg0 + 68);
        *(u32 *)(work + 72) = *(u32 *)((u8 *)arg0 + 72);
        *(u32 *)(work + 76) = *(u32 *)((u8 *)arg0 + 76);
        *(u32 *)(work + 80) = *(u32 *)((u8 *)arg0 + 80);
        lbl_8006DD14((u8 *)arg0 + 184, loc_C0);
        *(u32 *)(work + 148) = *(u32 *)((u8 *)arg0 + 60);
        *(u32 *)(work + 152) = *(u32 *)((u8 *)arg0 + 64);
        *(u32 *)(work + 156) = *(u32 *)((u8 *)arg0 + 68);
        if (arg2 < v8)
            v16 = v8;
        else if (arg2 > pool->f64)
            v16 = pool->f64;
        else
            v16 = arg2;
        t5 = fn_1_584AC();
        *(s32 *)(work + 16) = (s32)(pool->fb8 * (v12 + v12 * ((f32)(t5 & 0xffff) / v11)) * v16);
        t6 = fn_1_584AC();
        v22 = (f64)arg3 * ((f64)((f32)(t6 & 0xffff) / v11) - v13);
        *(f32 *)(work + 72) = *(f32 *)(work + 72) + (f32)v22;
        t7 = fn_1_584AC();
        v23 = (f64)arg3 * ((f64)((f32)(t7 & 0xffff) / v11) - v13);
        *(f32 *)(work + 76) = *(f32 *)(work + 76) + (f32)v23;
        t8 = fn_1_584AC();
        *(f32 *)(work + 80) = *(f32 *)(work + 80) +
            (f32)((f64)arg3 * ((f64)((f32)(t8 & 0xffff) / v11) - v13));
        if (v7 < v4)
            v24 = v4;
        else if (v7 > pool->f218)
            v24 = pool->f218;
        else
            v24 = v7;
        t9 = lbl_8006D5F0(arg1, arg1, (f32)v24);
        *(f32 *)(work + 72) += arg1->x;
        *(f32 *)(work + 76) += arg1->y;
        *(f32 *)(work + 80) += arg1->z;
        *(f32 *)(work + 60) -= *(f32 *)((u8 *)arg0 + 72);
        *(f32 *)(work + 64) -= *(f32 *)((u8 *)arg0 + 76);
        *(f32 *)(work + 68) -= *(f32 *)((u8 *)arg0 + 80);
        *(f32 *)(work + 160) = (f32)v5;
        if (v10 < 6)
            *(s16 *)(work + 172) = 6;
        else if (v10 > 18)
            *(s16 *)(work + 172) = 18;
        else
            *(s16 *)(work + 172) = v10;
        t10 = fn_1_584AC();
        v26 = *(f32 *)((u8 *)arg0 + 28);
        v27 = pool->f90 + pool->f74 * ((f32)(t10 & 0xffff) / v11);
        *(f32 *)(work + 28) = v26 * (v12 * (pool->f94 + v27)) / v14;
        *(f32 *)(work + 32) = *(f32 *)((u8 *)arg0 + 32) * v27 / v14;
        *(f32 *)(work + 36) = *(f32 *)((u8 *)arg0 + 36) * v27 / v14;
        t11 = fn_1_584AC();
        *(f32 *)(work + 140) = (f32)loc_C0[16];
        v28 = (f32)(t11 & 0xffff) / v11;
        *(f32 *)(work + 136) = (f32)loc_C0[15] * v28;
        fn_1_58F50(work);
        v15--;
    } while (v15 != 0);
}
