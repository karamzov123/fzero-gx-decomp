/* Non-matching: best partial attempt (75.66% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct { f32 x, y, z; } Vec3;
typedef struct { u32 x, y, z; } UVec3;
typedef struct { u32 x, y, z; } Sig_fn_1_862D4_Triple;
typedef union { UVec3 u; Vec3 f; } UVecF;

struct fn_1_635BC_Arg0 {
    u8 pad_0[8];
    u32 unk_8;
    u8 pad_c[4];
    s32 unk_10;
    u8 pad_14[4];
    s16 unk_18;
    f32 unk_1c;
    f32 unk_20;
    f32 unk_24;
    u8 pad_28[20];
    u8 unk_3c[24];
    s16 unk_54;
    s16 unk_56;
    u8 pad_58[2];
    s16 unk_5a;
    s16 unk_5c;
    u8 pad_5e[54];
    Vec3 pos;
    u8 pad_a0[20];
    f32 unk_b4;
    u8 pad_b8[4];
};

extern u32 fn_1_864E8(int);
extern u8 lbl_1_rodata_2950[];
extern u32 lbl_1_data_1D628;
extern void fn_1_862D4(int, Sig_fn_1_862D4_Triple *);
extern void fn_1_8645C(int, void *);
extern void * lbl_8006DC6C(void *);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void lbl_8006E1B0(void *, void *);

void fn_1_635BC(struct fn_1_635BC_Arg0 *arg0) {
    u8 *P = (u8 *)&lbl_1_rodata_2950;   /* fzgx-allow: A2 pool base */
    f32 *hw = (f32 *)0xE0000000;         /* fzgx-allow: A2 current matrix */
    Vec3 v2, v1;
    UVecF tmpB, tmpA;
    u32 r, seed;
    f32 c98, rnd, sc, t, u, w;

    r = fn_1_864E8(arg0->unk_18);
    if ((r & 0x10000000u) != 0 || (r & 0x4000u) != 0) {
        if ((arg0->unk_8 & 0x40000u) != 0) {
            arg0->unk_10++;
        } else {
            c98 = *(f32 *)(P + 0x70);
            t = (f32)arg0->unk_5a;
            arg0->unk_5a = (s16)(s32)(t * c98);
            t = (f32)arg0->unk_5c;
            arg0->unk_5c = (s16)(s32)(t * c98);
            arg0->unk_8 &= 0xE0000u;
        }
    }

    fn_1_862D4(arg0->unk_18, (Sig_fn_1_862D4_Triple *)&v1);
    fn_1_8645C(arg0->unk_18, &v2);
    lbl_8006DC6C(&v2);
    hw[3] = v1.x;
    hw[7] = v1.y;
    hw[11] = v1.z;
    arg0->unk_56 = arg0->unk_56 + arg0->unk_5c;
    arg0->unk_54 = arg0->unk_54 + arg0->unk_5a;
    mathutil_mtxA_rotate_y(arg0->unk_56);
    mathutil_mtxA_rotate_x(arg0->unk_54);

    tmpA.u.x = *(u32 *)(P + 0x304);
    tmpA.u.y = *(u32 *)(P + 0x308);
    tmpA.u.z = *(u32 *)(P + 0x30C);
    tmpA.f.x = arg0->pos.x;
    tmpA.f.y = arg0->pos.y;
    tmpA.f.z = arg0->pos.z;
    tmpB = tmpA;
    lbl_8006E1B0(&tmpB, arg0->unk_3c);

    arg0->unk_b4 = 0.5f * arg0->unk_10;
    seed = lbl_1_data_1D628;
    seed = seed * 0x41C64E6Du + 0x3039u;
    lbl_1_data_1D628 = seed;
    t = (f32)((seed >> 15) & 0x1FFFFu);
    rnd = t / *(f32 *)(P + 0x8);
    rnd = rnd * *(f32 *)(P + 0x64);
    rnd = rnd + *(f32 *)(P + 0x21C);
    u = *(f32 *)(P + 0x28) + rnd;
    u = u * *(f32 *)(P + 0x54);
    w = *(f32 *)(P + 0x5C) * u;
    w = w / *(f32 *)(P + 0x5C);
    sc = *(f32 *)(P + 0x310) * rnd;
    arg0->unk_1c = w;
    arg0->unk_20 = sc / *(f32 *)(P + 0x5C);
    arg0->unk_24 = arg0->unk_20;

    if (arg0->unk_10 < 30) {
        t = (f32)arg0->unk_10;
        t = t * *(f32 *)(P + 0x2C);
        t = t + *(f32 *)(P + 0x28);
        t = *(f32 *)(P + 0x28) - t;
        arg0->unk_1c = arg0->unk_1c * t;
        arg0->unk_20 = arg0->unk_20 * t;
        arg0->unk_24 = arg0->unk_24 * t;
    }
}
