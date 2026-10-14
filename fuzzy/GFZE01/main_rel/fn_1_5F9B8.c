/* Non-matching: best partial attempt (60.26% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect.h"
#include "psvec.h"

struct Sig_fn_1_867CC_fn_1_867CC_Arg1 {
    u32 unk_0;
    u32 unk_4;
    u32 unk_8;
};

struct fn_1_5F9B8_Arg0 {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1A[0x2];
    f32 unk_1C;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2C[0x28];
    s16 unk_54;
    s16 unk_56;
    u8 pad_58[0x5C];
    f32 unk_B4;
};

struct fn_1_5F9B8_lbl_1_rodata_2950 {
    u8 pad_0[0x4];
    f32 unk_4;
    f32 unk_8;
    u8 pad_C[0x14];
    f64 unk_20;
    f32 unk_28;
    u8 pad_2C[0x28];
    f32 unk_54;
    u8 pad_58[0x4];
    f32 unk_5C;
    u8 pad_60[0x34];
    f32 unk_94;
    u8 pad_98[0xB8];
    f32 unk_150;
};
extern u32 lbl_1_data_1D628;
extern struct fn_1_5F9B8_lbl_1_rodata_2950 lbl_1_rodata_2950;

extern u32 fn_1_867CC(u32, struct Sig_fn_1_867CC_fn_1_867CC_Arg1 *);
extern void *fn_1_868C0(s8);
extern void *fn_1_86254(int);
extern int fn_1_9F914(const void *, const void *);
extern s32 fn_1_54E34(void *, f32);
extern void fn_1_9EA94(void *);
extern u32 lbl_8006D9D8(u32);
extern void lbl_8006D95C(u32);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void *memset(void *, int, u32);
extern u32 lbl_8006DB74(u32);
extern void lbl_8006D7B0(void);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006D848(f32);
extern u32 lbl_8006DFC4(u32);
extern void fn_80074788(u32);
extern void fn_80072864(u32);
extern void fn_800745A4(u32, s32, s32, u32, u32, u32);
extern void fn_800734A8(u32, s32, s32, s32);
extern void fn_80072AB0(s32, s32, s32);
extern void fn_800735C8(s32, s32);
extern void fn_80073620(s32, s32);
extern void fn_80073C6C(s32);
extern void fn_80072C24(s32, s32, s32, s32, s32);
extern void fn_80072D64(s32, s32, s32, s32, u8, s32);
extern void fn_80072CC4(s32, s32, s32, s32, s32);
extern void fn_80072E20(s32, s32, s32, s32, u8, s32);
extern void fn_80073678(u32);
extern void fn_80074660(u32);
extern void fn_80074918(u8, s32, u8);
extern void fn_800720B0(u32);
extern void fn_800728A8(s32, s32, s32, s32);
extern void fn_80073778(void *, s32);

struct fn_1_5F9B8_MatrixData { u32 a, b, c; };
struct fn_1_5F9B8_Info { u8 pad[0xA0]; void *ptr; };
struct fn_1_5F9B8_Ptr { u32 a, b, c; };
struct fn_1_5F9B8_Particle { u32 unk_0, unk_4, unk_8; f32 unk_C; s16 unk_10; u16 unk_12; u32 unk_14; };

void fn_1_5F9B8(struct fn_1_5F9B8_Arg0 *arg0, f32 arg1) {
    struct fn_1_5F9B8_lbl_1_rodata_2950 *pool = &lbl_1_rodata_2950;
    struct Sig_fn_1_867CC_fn_1_867CC_Arg1 mat;
    struct fn_1_5F9B8_MatrixData matrix;
    struct fn_1_5F9B8_Info *info;
    struct fn_1_5F9B8_Ptr *ptr;
    struct fn_1_5F9B8_Particle particle;
    f32 vec[2];
    f32 temp[3];
    f32 f;
    f32 scale, randScale, radius;
    s32 idx;
    u32 seed, rand;
    u8 color[4];

    (void)arg1;
    fn_1_867CC(arg0->unk_18, &mat);
    idx = ((s16 *)fn_1_868C0((s8)arg0->unk_18))[0x3BA / 2];
    if (idx >= 3 && *(s8 *)((u8 *)fn_1_86254(arg0->unk_18) + 0x475) == -1)
        return;

    matrix.a = *(u32 *)((u8 *)arg0 + 0x3C);
    matrix.b = *(u32 *)((u8 *)arg0 + 0x40);
    matrix.c = *(u32 *)((u8 *)arg0 + 0x44);
    fn_1_9F914(&mat, &matrix);
    lbl_8006D9D8((u32)&mat);
    lbl_8006D95C(arg0->unk_56);
    mathutil_mtxA_rotate_x(arg0->unk_54);
    memset(vec, 0, 0x40);
    lbl_8006DB74((u32)temp);

    f = pool->unk_150 * arg0->unk_28;
    vec[0] = f;
    vec[1] = f;
    color[0] = (u8)(s32)(pool->unk_5C * arg0->unk_1C);
    color[1] = (u8)(s32)(pool->unk_5C * arg0->unk_20);
    color[2] = (u8)(s32)(pool->unk_5C * arg0->unk_24);
    color[3] = 255;
    fn_1_9F914(vec, (void *)*(u32 *)((u8 *)lbl_1_bss_38458->unk_8 + 0x120));

    seed = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
    rand = (seed >> 16) & 0x7fff;
    lbl_1_data_1D628 = seed;
    scale = pool->unk_4 * arg0->unk_B4;
    randScale = (f32)rand / pool->unk_8;
    radius = pool->unk_5C * ((pool->unk_94 + pool->unk_54 * scale) * (pool->unk_28 + randScale));
    fn_80074788(0);
    fn_80072864(0);
    fn_800745A4(0, 1, 4, 60, 0, 125);
    fn_800734A8(0, 0, 0, 255);
    fn_80072AB0(0, 0, 0);
    fn_800735C8(0, 12);
    fn_80073620(0, 28);
    fn_80073C6C(0);
    fn_80072C24(0, 15, 15, 15, 14);
    fn_80072D64(0, 0, 0, 0, 1, 0);
    fn_80072CC4(0, 7, 6, 4, 7);
    fn_80072E20(0, 0, 0, 0, 1, 0);
    fn_80073678(1);
    fn_80074660(1);
    fn_80074918(1, 3, 0);
    fn_800720B0(0);
    fn_800728A8(1, 4, 1, 0);
    info = (struct fn_1_5F9B8_Info *)*(u32 *)((u8 *)lbl_1_bss_38458->unk_8 + 0xA0);
    fn_80073778((void *)*(u32 *)((u8 *)info + 0x24), 0);

    memset(&particle, 0, 0x18);
    f = arg0->unk_20;
    /* quantized color values */
    temp[0] = radius * arg0->unk_24;
    temp[1] = radius * f;
    temp[2] = radius * arg0->unk_1C;
    particle.unk_C = radius;
    particle.unk_10 = 0;
    if (fn_1_54E34((u8 *)info + 8, pool->unk_28 + scale)) {
        f32 x = *(f32 *)0xE000000C;
        f32 y = *(f32 *)0xE000001C;
        f32 z = *(f32 *)0xE000002C;
        f32 dist;
        psvec_set(&temp[0], z, y, x);
        *(f32 *)((u8 *)temp + 0x1C) = z;
        dist = lbl_8006D0B4(temp[0] * temp[0] + temp[1] * temp[1] + z * z);
        if (dist > pool->unk_4 + (pool->unk_28 + scale)) {
            lbl_8006DB74((u32)((u8 *)&particle + 0x18));
            lbl_8006D848((dist - (pool->unk_28 + scale)) / dist);
            lbl_8006DFC4((u32)((u8 *)&particle + 0x18));
        }
        particle.unk_8 = *(u32 *)((u8 *)info + 8);
        particle.unk_C = *(f32 *)((u8 *)info + 0xC);
        particle.unk_10 = *(u16 *)((u8 *)info + 0x10);
        particle.unk_C = pool->unk_150 * (pool->unk_28 + scale);
        particle.unk_10 = 0;
        fn_1_9EA94(&particle);
    }
}
