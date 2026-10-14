/* Non-matching: best partial attempt (62.70% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect_car.h"
#include "rel/main_rel/effect.h"

struct fn_1_7099C_Arg0 {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1A[0x1E];
    u32 unk_38;
};
struct fn_1_7099C_lbl_1_rodata_2D70 {
    u8 pad_0[0x1C];
    f32 unk_1C;
    u8 pad_20[4];
    f32 unk_24;
    u8 pad_28[0x18];
    f64 unk_40;
    f32 unk_48;
    u8 pad_4C[0x10];
    f32 unk_5C;
    f32 unk_60;
    f32 unk_64;
    u8 pad_68[0xC];
    f32 unk_74;
    f32 unk_78;
    u8 pad_7C[0x14];
    f32 unk_90;
    f32 unk_94;
    u8 pad_98[0x14];
    f32 unk_AC;
    u8 pad_B0[8];
    f32 unk_B8;
    u8 pad_BC[0x14];
    f64 unk_D0;
    u8 pad_D8[8];
    f32 unk_E0;
    f32 unk_E4;
    u8 pad_E8[0x14];
    f32 unk_FC;
    u8 pad_100[8];
    f64 unk_108;
    u8 pad_110[0x10];
    f64 unk_120;
    f64 unk_128;
    u8 pad_130[0x30];
    f64 unk_160;
    u8 pad_168[0x10];
    f32 unk_178;
    f32 unk_17C;
    f32 unk_180;
    f32 unk_184;
    u8 pad_188[0x50];
    f32 unk_1D8;
    f32 unk_1DC;
    u8 pad_1E4[0xC];
    f64 unk_1F0;
    f64 unk_1F8;
    u8 pad_200[0x48];
    f64 unk_248;
    u8 pad_250[0x4C];
    f32 unk_29C;
    u8 pad_2A0[0x80];
    f32 unk_320;
    u8 pad_324[0x68];
    u32 unk_38C;
    u32 unk_390;
    u32 unk_394;
};
extern f32 fn_1_8652C(int);
extern struct fn_1_7099C_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern u32 fn_1_584AC(void);
extern u8 *memset(u8 *, int, u32);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *);
extern s16 fn_1_59078(Obj_1_bss_6C84C_Target *);
extern s16 fn_1_58F50(const void *);

void fn_1_7099C(struct fn_1_7099C_Arg0 *arg0, u32 arg1, u32 arg2, f32 arg3, f32 arg4) {
    struct fn_1_7099C_lbl_1_rodata_2D70 *pool = &lbl_1_rodata_2D70;
    struct { u8 a[0xE8]; } obj;
    u32 loc8[3];
    u8 *car = (u8 *)arg0;
    u32 outer = arg0->unk_38;
    f32 time = fn_1_8652C(arg0->unk_18);
    u32 i;
    s32 count = 0;
    (void)arg1;
    if (arg2 != 0) {
        if (time < pool->unk_AC) {
            u32 r = fn_1_584AC() & 0xFFFF;
            if (r % 3 != 0)
                return;
        } else {
            u32 r = fn_1_584AC() & 0xFFFF;
            if ((r & 3) == 0)
                return;
        }
    }
    memset((u8 *)&obj + 0x14, 0, 0xE8);
    *(s16 *)((u8 *)&obj + 0x2C) = arg0->unk_18;
    *(u16 *)((u8 *)&obj + 0x20) = 29;
    *(u16 *)((u8 *)&obj + 0x2E) = 0xFFFF;
    loc8[0] = pool->unk_38C;
    loc8[1] = pool->unk_390;
    loc8[2] = pool->unk_394;
    *(u32 *)((u8 *)&obj + 0x48) = *(u32 *)((u8 *)*(u32 *)((u8 *)lbl_1_bss_38458 + 8) + 0x148);
    lbl_8006DC6C(car + 0xB8);
    *(f32 *)(0xE0000000 + 0x0C) = *(f32 *)(car + 0x3C);
    *(f32 *)(0xE0000000 + 0x1C) = *(f32 *)(car + 0x40);
    *(f32 *)(0xE0000000 + 0x2C) = *(f32 *)(car + 0x44);
    lbl_8006E1B0((void *)loc8);
    if (time < pool->unk_E4)
        count = 1;
    if (time >= pool->unk_E4 && time < pool->unk_180)
        count = 2;
    if (time >= pool->unk_180 && time < pool->unk_184)
        count = 3;
    if (time >= pool->unk_184)
        count = 5;
    {
        f32 ptime = time / pool->unk_1D8;
        f32 scale = time / pool->unk_1DC;
        f32 particle = (f32)(pool->unk_1F8 + time / pool->unk_184);
        f64 two52 = pool->unk_40;
        f32 norm = pool->unk_24;
        f64 half = pool->unk_D0;
        f32 random_scale = pool->unk_78;
        f32 fifty = pool->unk_320;
        f64 zero = pool->unk_120;
        f64 tzero = pool->unk_108;
        f32 one = pool->unk_94;
        f64 tiny = pool->unk_1F0;
        f32 max = pool->unk_184;
        f32 cap = pool->unk_180;
        for (i = (u32)count; i != 0; --i) {
            u32 r;
            f32 x, y, z;
            *(u32 *)((u8 *)&obj + 0x50) = loc8[0];
            *(u32 *)((u8 *)&obj + 0x54) = loc8[1];
            *(u32 *)((u8 *)&obj + 0x58) = loc8[2];
            *(u32 *)((u8 *)&obj + 0x5C) = *(u32 *)(car + 0x48);
            *(u32 *)((u8 *)&obj + 0x60) = *(u32 *)(car + 0x4C);
            *(u32 *)((u8 *)&obj + 0x64) = *(u32 *)(car + 0x50);
            if (arg4 > fifty) {
                r = fn_1_584AC() & 0xFFFF;
                *(s32 *)((u8 *)&obj + 0x24) = (s32)(((f32)r / norm * pool->unk_64 + pool->unk_FC) * pool->unk_B8 * pool->unk_5C);
            } else {
                r = fn_1_584AC() & 0xFFFF;
                *(s32 *)((u8 *)&obj + 0x24) = (s32)(((f32)r / norm * pool->unk_64 + pool->unk_FC) * pool->unk_B8);
            }
            r = fn_1_584AC() & 0xFFFF;
            x = (f32)((((f64)r - two52) / norm - half) * random_scale);
            *(f32 *)((u8 *)&obj + 0x5C) += x;
            r = fn_1_584AC() & 0xFFFF;
            y = (f32)((((f64)r - two52) / norm - half) * random_scale);
            *(f32 *)((u8 *)&obj + 0x64) += y;
            x = *(f32 *)((u8 *)&obj + 0x5C) + *(f32 *)arg1 * ptime;
            y = *(f32 *)((u8 *)&obj + 0x60) + *(f32 *)(arg1 + 4) * ptime;
            z = *(f32 *)((u8 *)&obj + 0x64) + *(f32 *)(arg1 + 8) * ptime;
            *(f32 *)((u8 *)&obj + 0x50) -= x - *(f32 *)((u8 *)&obj + 0x5C);
            *(f32 *)((u8 *)&obj + 0x54) -= y - *(f32 *)((u8 *)&obj + 0x60);
            *(f32 *)((u8 *)&obj + 0x58) -= z - *(f32 *)((u8 *)&obj + 0x64);
            *(f32 *)((u8 *)&obj + 0x5C) = x;
            *(f32 *)((u8 *)&obj + 0x60) = y;
            *(f32 *)((u8 *)&obj + 0x64) = z;
            if (time < (f32)zero)
                x = (f32)zero;
            else if (time > (f32)pool->unk_108)
                x = time;
            else
                x = time;
            *(f32 *)((u8 *)&obj + 0x3C) = arg3 + x;
            r = fn_1_584AC() & 0xFFFF;
            if (arg3 < one)
                *(f32 *)((u8 *)&obj + 0x40) = (f32)(pool->unk_128 + pool->unk_160 * ((f32)r / norm));
            else
                *(f32 *)((u8 *)&obj + 0x40) = arg4 + (f32)(pool->unk_248 * ((f32)r / norm));
            r = fn_1_584AC() & 0xFFFF;
            x = (f32)r / norm;
            y = pool->unk_74 * x;
            z = pool->unk_90 + y;
            if (arg3 < one) {
                *(f32 *)((u8 *)&obj + 0x34) = pool->unk_E0 * z / pool->unk_48;
                *(f32 *)((u8 *)&obj + 0x38) = pool->unk_29C * z / pool->unk_48;
                *(f32 *)((u8 *)&obj + 0x30) = pool->unk_1C * (pool->unk_94 + z) * pool->unk_48 / pool->unk_48;
            } else {
                *(f32 *)((u8 *)&obj + 0x34) = pool->unk_E0 * z / pool->unk_48;
                *(f32 *)((u8 *)&obj + 0x38) = pool->unk_29C * z / pool->unk_48;
                *(f32 *)((u8 *)&obj + 0x30) = pool->unk_1C * (pool->unk_94 + pool->unk_1C * z) * pool->unk_48 / pool->unk_48;
            }
            r = fn_1_584AC() & 0xFFFF;
            *(f32 *)((u8 *)&obj + 0x9C) = (f32)((f64)r - two52) / norm * tiny;
            *(f32 *)((u8 *)&obj + 0xA0) = particle;
            *(u16 *)((u8 *)&obj + 0xC0) = 0x16C;
            if (*(s8 *)(outer + 0x475) != -1)
                fn_1_59078((Obj_1_bss_6C84C_Target *)((u8 *)&obj + 0x14));
            else
                fn_1_58F50((const void *)((u8 *)&obj + 0x14));
        }
    }
}
