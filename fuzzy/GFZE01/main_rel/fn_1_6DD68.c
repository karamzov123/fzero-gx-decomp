/* Non-matching: best partial attempt (40.93% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_6DD68_arg0 {
    u8 pad_0[0x18];
    s16 unk_18;
    u8 pad_1A[0x22];
    f32 unk_3C;
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
    f32 unk_4C;
    f32 unk_50;
    u8 pad_54[0x64];
    u8 pad_B8[0x200];
};
struct fn_1_6DD68_at3c {
    u8 pad_0[0x1584];
    u32 unk_1584;
};
struct fn_1_6DD68_lbl_1_data_2A7E0 {
    u8 pad_0[0x3C];
    struct fn_1_6DD68_at3c *unk_3C;
};
struct fn_1_6DD68_lbl_1_rodata_2D70 {
    f32 unk_0;
    u8 pad_4[0x20];
    f32 unk_24;
    u8 pad_28[0x18];
    f64 unk_40;
    u8 pad_48[0x2C];
    f32 unk_74;
    u8 pad_78[0x34];
    f32 unk_AC;
    u8 pad_B0[0x20];
    f64 unk_D0;
    u8 pad_D8[0xC];
    f32 unk_E4;
    u8 pad_E8[0x98];
    f32 unk_180;
    u8 pad_184[0x5C];
    f64 unk_1E0;
    u8 pad_1E8[0x18];
    f32 unk_200;
    u8 pad_204[0x80];
    u32 unk_284;
    u32 unk_288;
    u32 unk_28C;
    f32 unk_290;
    f32 unk_294;
    f32 unk_298;
};

extern f32 fn_1_8652C(int);
extern s16 camera_get_mode(void);
extern struct fn_1_6DD68_lbl_1_data_2A7E0 lbl_1_data_2A7E0;
extern struct fn_1_6DD68_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern u32 fn_1_584AC(void);
extern u32 lbl_801A66A0;
extern u8 * memset(u8 *, int, u32);
extern u8 fn_1_58C4(void);
extern u32 fn_1_58F50(void *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(void *);
extern void fn_8006E2B0(void *, void *);
extern void lbl_8006E1C0(void *, void *);

void fn_1_6DD68(struct fn_1_6DD68_arg0 *arg0, u32 arg1, u8 arg2) {
    struct fn_1_6DD68_lbl_1_rodata_2D70 *p_lbl_1_rodata_2D70;
    struct fn_1_6DD68_lbl_1_data_2A7E0 *p_lbl_1_data_2A7E0;
    struct fn_1_6DD68_arg0 *p_arg0;
    u8 n;
    u32 count;
    f32 v;
    f64 d;
    u32 tmp;
    f32 v0, v1, v2, v3, v4, v5;
    u32 t0, t1, t2, t3;
    f32 f0, f1, f2, f3;
    struct { u16 a[136]; } loc_20;
    u32 loc_14[3];
    u32 loc_10;
    u32 loc_C;
    u32 loc_8;

    p_lbl_1_data_2A7E0 = &lbl_1_data_2A7E0;
    p_arg0 = arg0;
    p_lbl_1_rodata_2D70 = (struct fn_1_6DD68_lbl_1_rodata_2D70 *)&lbl_1_rodata_2D70;
    v = fn_1_8652C(arg0->unk_18);
    if (v != p_lbl_1_rodata_2D70->unk_0) {
        if (v < p_lbl_1_rodata_2D70->unk_AC) {
            if ((fn_1_584AC() & 0xFFFF) % 3 == 0) {
                t3 = 1;
            } else {
                return;
            }
        } else {
            if ((fn_1_584AC() & 0xFFFF) % 4 != 0) {
                return;
            }
        }
        if (fn_1_58C4() >= 2) {
            t3 = 1;
        } else {
            t3 = (u32)(s16)camera_get_mode() != (u32)(s32)arg0->unk_18;
        }
        if (t3) {
            if ((lbl_801A66A0 & 0x7FFFFFFF) != 0) {
                return;
            }
        }
        memset((u8 *)&loc_20, 0, 0xE8);
        loc_20.a[12] = arg0->unk_18;
        loc_20.a[6] = 0x14;
        loc_20.a[13] = 3;
        *(u32 *)((u8 *)&loc_20 + 0x34) = p_lbl_1_data_2A7E0->unk_3C->unk_1584;
        d = (f64)(u32)(fn_1_584AC() & 0xFFFF);
        loc_8 = p_lbl_1_rodata_2D70->unk_284;
        loc_C = p_lbl_1_rodata_2D70->unk_288;
        loc_10 = p_lbl_1_rodata_2D70->unk_28C;
        loc_14[0] = loc_8;
        loc_14[1] = loc_C;
        loc_14[2] = loc_10;
        loc_8 = (f32)((f32)((d - p_lbl_1_rodata_2D70->unk_40) / p_lbl_1_rodata_2D70->unk_24) - p_lbl_1_rodata_2D70->unk_D0);
        loc_14[0] = loc_8;
        lbl_8006DC6C(arg0->pad_B8);
        *(f32 *)(0xE0000000 + 0x0C) = arg0->unk_3C;
        *(f32 *)(0xE0000000 + 0x1C) = arg0->unk_40;
        *(f32 *)(0xE0000000 + 0x2C) = arg0->unk_44;
        lbl_8006E1B0(&loc_14);
        if (v < p_lbl_1_rodata_2D70->unk_E4) {
            n = 1;
        } else {
            if (v >= p_lbl_1_rodata_2D70->unk_E4) {
                if (v < p_lbl_1_rodata_2D70->unk_180) {
                    n = 2;
                } else {
                    n = arg2;
                }
            }
        }
        count = n;
        v0 = v / p_lbl_1_rodata_2D70->unk_298;
        v1 = (f32)(p_lbl_1_rodata_2D70->unk_1E0 + (f64)v0);
        v2 = v / p_lbl_1_rodata_2D70->unk_294;
        v3 = p_lbl_1_rodata_2D70->unk_200;
        v4 = p_lbl_1_rodata_2D70->unk_74;
        v5 = (f32)p_lbl_1_rodata_2D70->unk_40;
        f0 = (f32)p_lbl_1_rodata_2D70->unk_D0;
    f3 = (f32)p_lbl_1_rodata_2D70->unk_D0;
        while (count) {
            loc_14[1] = loc_14[0];
            loc_14[2] = loc_14[1];
            loc_10 = loc_14[2];
            loc_C = loc_14[0];
            loc_8 = arg0->unk_48 * v3;
            loc_C = arg0->unk_4C * v3;
            loc_10 = arg0->unk_50 * v3;
            fn_8006E2B0(&loc_20, loc_14);
            f1 = v4;
            if (v2 < f1) {
                f2 = f1;
            } else {
                f1 = p_lbl_1_rodata_2D70->unk_290;
                if (v2 <= f1) {
                    f2 = v2;
                }
            }
            t0 = fn_1_584AC() & 0xFFFF;
            d = (f64)(u32)t0;
            loc_8 = (f32)((f32)loc_8 + (f32)(f2 * (f32)((f32)((d - v5) / f0) - f3)));
            t1 = fn_1_584AC() & 0xFFFF;
            loc_C = loc_C + v1;
            d = (f64)(u32)t1;
            loc_10 = (f32)((f32)loc_10 + (f32)(f2 * (f32)((f32)((d - v5) / f0) - f3)));
            lbl_8006E1C0(&loc_20, loc_14);
            t2 = loc_14[0];
            t3 = loc_14[1];
            loc_14[0] = (f32)((f32)t2 - loc_8);
            loc_14[1] = (f32)((f32)t3 - loc_C);
            loc_14[2] = (f32)((f32)loc_14[2] - loc_10);
            fn_1_58F50(&loc_20);
            count--;
        }
    }
}
