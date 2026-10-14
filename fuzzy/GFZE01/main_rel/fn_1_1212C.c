/* Non-matching: best partial attempt (73.14% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/live_camera.h"

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Sig_fn_1_862D4_Triple;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Sig_fn_8006FA24_Vec;
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006ED0C_Vec3;

struct fn_1_1212C_Arg0 {
    u8 pad_0[0x6];
    s16 unk_6;
};
struct fn_1_1212C_lbl_1_rodata_4E0 {
    u8 pad_0[0x4C];
    f32 unk_4C;
    u8 pad_50[0x60];
    f64 unk_B0;
    u8 pad_B8[0x20];
    f64 unk_D8;
    f64 unk_E0;
    u8 pad_E8[0x80];
    f32 unk_168;
    u32 unk_16C;
    u32 unk_170;
    u32 unk_174;
    u32 unk_178;
    u32 unk_17C;
    u32 unk_180;
    u32 unk_184;
    u32 unk_188;
    u32 unk_18C;
    u8 pad_190[0xC];
    f32 unk_19C;
    f32 unk_1A0;
    u8 pad_1A4[0x4];
    f64 unk_1A8;
    f64 unk_1B0;
    f64 unk_1B8;
    f64 unk_1C0;
};
struct fn_1_1212C_lbl_1_bss_17F8 {
    u32 unk_0;
};

extern u32 lbl_1_bss_17F8;
extern Obj_1_bss_9F8 lbl_1_bss_9F8;
extern Obj_1_data_4484 lbl_1_data_4484;
extern struct fn_1_1212C_lbl_1_rodata_4E0 lbl_1_rodata_4E0;
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern u8 fn_1_40BB4(void);
extern void fn_1_862D4(int, Sig_fn_1_862D4_Triple *);
extern void fn_1_8636C(int, void *);
extern u32 fn_1_862A8(u32, void *);
extern void *fn_1_20A5C(void *, void *);
extern void fn_8006ED0C(Sig_fn_8006ED0C_Vec3 *, Sig_fn_8006ED0C_Vec3 *, s16 *);
extern void fn_8006FA24(f32, Sig_fn_8006FA24_Vec *, Sig_fn_8006FA24_Vec *, Sig_fn_8006FA24_Vec *);
extern void lbl_8006DC6C(void *);
extern void lbl_8006E1B0(Sig_fn_8006FA24_Vec *, void *);
extern s32 lbl_8006D24C(f32, f32);
extern void lbl_8006DAEC(void);
extern void lbl_8006DB30(void);
extern void fn_1_15578(void *, void *, void *, void *, u32, void *, u32, u32, u32, u32);

void fn_1_1212C(struct fn_1_1212C_Arg0 *arg0) {
    struct fn_1_1212C_lbl_1_rodata_4E0 *p_lbl_1_rodata_4E0;
    void *v0;
    f32 v1;
    f32 v2;
    f32 v3;
    s32 v4;
    s16 v5;
    u32 v6;
    u32 v7;
    f64 v8;
    f64 v9;
    f32 v10;
    u32 v11;
    u32 v12;
    u32 v13;
    f64 v14;
    f32 v15;
    Sig_fn_8006FA24_Vec loc_80;
    f32 loc_74[3];
    f32 loc_68[3];
    f32 loc_5C[3];
    u32 loc_50[6];
    struct { u32 a[9]; } loc_2C;
    s16 loc_18[10];
    p_lbl_1_rodata_4E0 = &lbl_1_rodata_4E0;
    fn_1_862D4(arg0->unk_6, (Sig_fn_1_862D4_Triple *)loc_74);
    fn_1_862D4(lbl_1_bss_17F8, (Sig_fn_1_862D4_Triple *)loc_68);
    fn_1_8636C(lbl_1_bss_17F8, &loc_80);
    v0 = (u8 *)arg0 + 124;
    v1 = loc_74[1] - loc_68[1];
    v2 = loc_74[2] - loc_68[2];
    v3 = (v1 * v1) + ((loc_74[0] - loc_68[0]) * (loc_74[0] - loc_68[0])) + v2 * v2;
    fn_8006FA24(p_lbl_1_rodata_4E0->unk_4C, v0, &loc_80, v0);
    v4 = *(u8 *)arg0;
    if (v4 != 4) {
        if (v4 < 4) {
            if (v4 < 3) {
                if ((s32)v4 >= 0) {
                    if (v3 > p_lbl_1_rodata_4E0->unk_19C) {
                        *(s16 *)((u8 *)arg0 + 18) = 2;
                        *(u32 *)((u8 *)arg0 + 24) = 1;
                    }
                }
            } else {
                if (v4 == 3 && fn_1_40BB4() == 0) {
                    if ((lbl_1_bss_9F8.unk_A >> 1) & 1) {
                        *(s16 *)((u8 *)arg0 + 20) += 1;
                    }
                    if (lbl_1_bss_9F8.unk_A & 1) {
                        *(s16 *)((u8 *)arg0 + 20) -= 1;
                    }
                    if (*(s16 *)((u8 *)arg0 + 20) > 1)
                        *(s16 *)((u8 *)arg0 + 20) = 0;
                    if (*(s16 *)((u8 *)arg0 + 20) < 0)
                        *(s16 *)((u8 *)arg0 + 20) = 1;
                }
                if (v3 > p_lbl_1_rodata_4E0->unk_168) {
                    *(s16 *)((u8 *)arg0 + 18) = 0;
                    *(u32 *)((u8 *)arg0 + 24) = 1;
                }
            }
        } else if (v4 != 6 && v4 < 6) {
            if (v3 > p_lbl_1_rodata_4E0->unk_19C) {
                *(s16 *)((u8 *)arg0 + 18) = 2;
                *(u32 *)((u8 *)arg0 + 24) = 1;
            }
        }
    }
    v5 = *(s16 *)((u8 *)arg0 + 4);
    switch (v5) {
    case 0:
        *(f32 *)0xE000000C = loc_68[0];
        *(f32 *)0xE000001C = loc_68[1];
        *(f32 *)0xE000002C = loc_68[2];
        lbl_8006DC6C(&loc_80);
        loc_50[0] = p_lbl_1_rodata_4E0->unk_16C;
        loc_50[1] = p_lbl_1_rodata_4E0->unk_170;
        loc_50[2] = p_lbl_1_rodata_4E0->unk_174;
        lbl_8006E1B0((Sig_fn_8006FA24_Vec *)loc_50, (u8 *)arg0 + 28);
        *(f32 *)((u8 *)arg0 + 88) = p_lbl_1_rodata_4E0->unk_1A0;
        break;
    case 1:
    case 3:
    case 4:
        *(f32 *)0xE000000C = loc_68[0];
        *(f32 *)0xE000001C = loc_68[1];
        *(f32 *)0xE000002C = loc_68[2];
        lbl_8006DC6C(&loc_80);
        fn_8006ED0C((Sig_fn_8006ED0C_Vec3 *)loc_68, (Sig_fn_8006ED0C_Vec3 *)loc_74, loc_18);
        mathutil_mtxA_rotate_y(loc_18[1]);
        mathutil_mtxA_rotate_x(loc_18[0]);
        v8 = v3 / p_lbl_1_rodata_4E0->unk_1A8;
        v9 = p_lbl_1_rodata_4E0->unk_D8;
        if (v8 < p_lbl_1_rodata_4E0->unk_D8) {
        } else {
            v9 = p_lbl_1_rodata_4E0->unk_B0;
            if (v8 > v9) {
            } else {
                v9 = v8;
            }
        }
        v10 = v9;
        v11 = p_lbl_1_rodata_4E0->unk_178;
        v12 = p_lbl_1_rodata_4E0->unk_180;
        loc_50[0] = v11;
        loc_2C.a[7] = p_lbl_1_rodata_4E0->unk_17C;
        loc_50[2] = v12;
        *(f32 *)((u8 *)&loc_2C + 28) = p_lbl_1_rodata_4E0->unk_1B0 + v10;
        loc_2C.a[6] = v11;
        loc_50[1] = loc_2C.a[7];
        loc_2C.a[8] = v12;
        if (*(s16 *)((u8 *)arg0 + 4) == 3) {
            v13 = p_lbl_1_rodata_4E0->unk_184;
            v14 = v10 * p_lbl_1_rodata_4E0->unk_E0;
            loc_2C.a[4] = p_lbl_1_rodata_4E0->unk_188;
            loc_2C.a[5] = p_lbl_1_rodata_4E0->unk_18C;
            v15 = v14 - p_lbl_1_rodata_4E0->unk_1B8;
            *(f32 *)((u8 *)&loc_2C + 20) = p_lbl_1_rodata_4E0->unk_1C0 + v10;
            *(f32 *)((u8 *)&loc_2C + 16) = v15;
            loc_2C.a[3] = v13;
            loc_50[0] = v13;
            loc_50[1] = loc_2C.a[4];
            loc_50[2] = loc_2C.a[5];
        }
        if (*(s16 *)((u8 *)arg0 + 4) == 4) {
            loc_50[0] = *(u32 *)((u8 *)p_lbl_1_rodata_4E0 + 0x190);
            loc_50[1] = *(u32 *)((u8 *)p_lbl_1_rodata_4E0 + 0x194);
            loc_50[2] = *(u32 *)((u8 *)p_lbl_1_rodata_4E0 + 0x198);
        }
        lbl_8006E1B0((Sig_fn_8006FA24_Vec *)loc_50, (u8 *)arg0 + 28);
        *(f32 *)((u8 *)arg0 + 88) = 55.0f;
        break;
    default:
        lbl_8006D7DC((u32)loc_68);
        *(u32 *)((u8 *)arg0 + 28) = *(u32 *)&loc_68[0];
        *(u32 *)((u8 *)arg0 + 32) = *(u32 *)&loc_68[1];
        *(u32 *)((u8 *)arg0 + 36) = *(u32 *)&loc_68[2];
        *(f32 *)((u8 *)arg0 + 88) = 55.0f;
        break;
    }
    *(u32 *)((u8 *)arg0 + 76) = *(u32 *)&loc_74[0];
    *(u32 *)((u8 *)arg0 + 80) = *(u32 *)&loc_74[1];
    *(u32 *)((u8 *)arg0 + 84) = *(u32 *)&loc_74[2];
    fn_1_862A8(lbl_1_bss_17F8, loc_5C);
    {
        f32 t = (f32)((s32)lbl_1_data_4484.unk_0) * 0.01f;
        f32 x = *(f32 *)((u8 *)arg0 + 112);
        f32 y = *(f32 *)((u8 *)arg0 + 116);
        f32 z = *(f32 *)((u8 *)arg0 + 120);
        *(f32 *)((u8 *)arg0 + 112) = x + t * (loc_5C[0] - x);
        *(f32 *)((u8 *)arg0 + 116) = y + t * (loc_5C[1] - y);
        *(f32 *)((u8 *)arg0 + 120) = z + t * (loc_5C[2] - z);
    }
    *(s16 *)((u8 *)arg0 + 92) = -lbl_8006D24C(*(f32 *)((u8 *)arg0 + 112), *(f32 *)((u8 *)arg0 + 116));
    lbl_8006DAEC();
    fn_1_20A5C((u8 *)arg0 + 28, &loc_18[0]);
    {
        u32 ret = (u32)fn_1_20A5C;
        (void)ret;
    }
    loc_18[2] = 0;
    fn_1_15578((u8 *)arg0 + 28, &loc_2C, &loc_18[0], &loc_18[8], 0x40005, &loc_18[2], 1, 0, 0, 0);
    lbl_8006DB30();
}
