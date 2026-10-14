/* Non-matching: best partial attempt (66.02% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef union {
    f32 f;
    u32 u;
} F32U;

typedef struct {
    F32U x;
    F32U y;
    F32U z;
} Vec3;

typedef struct {
    u8 pad_0[0x8];
    u32 unk_8;
    u8 pad_C[0x4];
    u32 unk_10;
    u8 pad_14[0x4];
    s16 unk_18;
    u8 pad_1A[0x2];
    F32U unk_1C;
    F32U unk_20;
    F32U unk_24;
    F32U unk_28;
    u8 pad_2C[0x10];
    Vec3 unk_3C;
    u8 pad_48[0xC];
    s16 unk_54;
    s16 unk_56;
    s16 unk_58;
    s16 unk_5A;
    s16 unk_5C;
    u8 pad_5E[0x56];
    F32U unk_B4;
} Arg0;

typedef struct {
    u8 unk_0;
    u8 pad_1[0x474];
    s8 unk_475;
} T1;

extern const u32 lbl_1_rodata_2950;

#define PF(off) (*(const f32 *)((const u8 *)pool + (off)))

extern u32 lbl_1_data_1D628;
extern s16 lbl_1_data_2A7E0;

extern u32 fn_1_86514(int);
extern T1 * fn_1_86254(int);
extern void fn_1_862D4(int, Vec3 *);
extern void fn_1_8636C(int, void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(Vec3 *, Vec3 *);
extern int fn_1_6EC0(u8);
extern s16 camera_get_entry_field_0xa4(u32);
extern void mathutil_mtxA_rotate_x(s16);
extern void mathutil_mtxA_rotate_y(s16);

void fn_1_5F654(Arg0 *arg0) {
    const u32 *pool = &lbl_1_rodata_2950;
    T1 *t1;
    Vec3 loc_38;
    u8 loc_44[0x34];
    Vec3 loc_2C;
    Vec3 loc_20;
    if ((fn_1_86514(arg0->unk_18) & 0x08000000) != 0 && (arg0->unk_8 & 0x40000) != 0) {
        arg0->unk_10++;
    } else {
        arg0->unk_5A = (s16)(PF(0x70) * (f64)arg0->unk_5A);
        arg0->unk_5C = (s16)(PF(0x70) * (f64)arg0->unk_5C);
        arg0->unk_8 &= ~0x7000;
    }
    t1 = fn_1_86254(arg0->unk_18);
    fn_1_862D4(arg0->unk_18, &loc_38);
    fn_1_8636C(arg0->unk_18, loc_44);
    lbl_8006DC6C(loc_44);
    *(f32 *)(0xE0000000 + 0x0C) = loc_38.x.f;
    *(f32 *)(0xE0000000 + 0x1C) = loc_38.y.f;
    *(f32 *)(0xE0000000 + 0x2C) = loc_38.z.f;
    if ((s8)t1->unk_475 != -1 && fn_1_6EC0(t1->unk_475) != 0 && camera_get_entry_field_0xa4(t1->unk_475) == 0) {
        Vec3 t;
        t.x.u = ((const u32 *)pool)[0x228 / 4];
        t.y.u = ((const u32 *)pool)[0x22C / 4];
        t.z.u = ((const u32 *)pool)[0x230 / 4];
        t.z.f = PF(0x240);
        loc_20 = t;
        lbl_8006E1B0(&loc_20, &loc_20);
        *(f32 *)(0xE0000000 + 0x0C) = loc_20.x.f;
        *(f32 *)(0xE0000000 + 0x1C) = loc_20.y.f;
        *(f32 *)(0xE0000000 + 0x2C) = loc_20.z.f;
    }
    arg0->unk_54 = (s16)(arg0->unk_54 + arg0->unk_5A);
    arg0->unk_56 = (s16)(arg0->unk_56 + arg0->unk_5C);
    mathutil_mtxA_rotate_y(arg0->unk_56);
    mathutil_mtxA_rotate_x(arg0->unk_54);
    {
        Vec3 t;
        t.x.u = ((const u32 *)pool)[0x234 / 4];
        t.y.u = ((const u32 *)pool)[0x238 / 4];
        t.z.u = ((const u32 *)pool)[0x23C / 4];
        loc_2C = t;
        loc_2C.z.f = PF(0x48) * -(f64)arg0->unk_28.f;
    }
    lbl_8006E1B0(&loc_2C, &arg0->unk_3C);
    {
        u32 v;
        u32 r;
        f32 f;
        arg0->unk_B4.f = PF(0x54) * (f64)arg0->unk_10;
        r = lbl_1_data_1D628 * 0x41C64E6D + 0x3039;
        lbl_1_data_1D628 = r;
        r = (r >> 16) & 0x7FFF;
        f = PF(0x21C) + PF(0x64) * ((f64)r / PF(0x8));
        arg0->unk_1C.f = (PF(0x5C) * (PF(0x54) * (arg0->unk_28.f + f))) / PF(0x5C);
        arg0->unk_20.f = (PF(0x19C) * f) / PF(0x5C);
        arg0->unk_24.f = PF(0x50);
        if (lbl_1_data_2A7E0 == 6) {
            arg0->unk_1C.f = arg0->unk_1C.f * PF(0x64);
            arg0->unk_20.f = arg0->unk_20.f * PF(0x64);
            arg0->unk_24.f = arg0->unk_24.f * PF(0x64);
        }
        v = arg0->unk_10;
        if ((s32)v < 20) {
            f32 sc = arg0->unk_28.f - (arg0->unk_28.f + PF(0x1A0) * (f64)v);
            arg0->unk_1C.f = arg0->unk_1C.f * sc;
            arg0->unk_20.f = arg0->unk_20.f * sc;
            arg0->unk_24.f = arg0->unk_24.f * sc;
        }
    }
}
