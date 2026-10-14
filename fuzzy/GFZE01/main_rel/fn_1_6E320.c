/* Non-matching: best partial attempt (97.51% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/effect.h"

struct fn_1_6E320_Arg0 {
    u8 pad_0[0x18];
    s16 unk_18;
};
struct fn_1_6E320_Loc {
    u16 f00[6];
    u16 f0c;
    u16 f0e;
    s32 f10;
    u8 f14[4];
    u16 f18;
    u16 f1a;
    u8 f1c[12];
    f32 f28;
    f32 f2c;
    u8 f30[12];
    f32 f3c;
    f32 f40;
    f32 f44;
    f32 f48;
    f32 f4c;
    f32 f50;
    u8 f54[8];
    f32 f5c;
    f32 f60;
    f32 f64;
    f32 f68;
    f32 f6c;
    f32 f70;
    u8 f74[40];
    f32 f9c;
    u8 fa0[24];
    u32 fb8[12];
};
struct fn_1_6E320_lbl_1_rodata_2D70 {
    f32 unk_0;
    u8 pad_4[0x18];
    f32 unk_1C;
    u8 pad_20[0x4];
    f32 unk_24;
    u8 pad_28[0x8];
    f32 unk_30;
    u8 pad_34[0xC];
    f64 unk_40;
    u8 pad_48[0x2C];
    f32 unk_74;
    f32 unk_78;
    u8 pad_7C[0x18];
    f32 unk_94;
    u8 pad_98[0x20];
    f32 unk_B8;
    u8 pad_BC[0x14];
    f64 unk_D0;
    u8 pad_D8[0x14];
    f32 unk_EC;
    f32 unk_F0;
    f32 unk_F4;
    u8 pad_F8[0x10];
    f64 unk_108;
    u8 pad_110[0x70];
    f32 unk_180;
    u8 pad_184[0x128];
    u32 unk_2AC;
    u32 unk_2B0;
    u32 unk_2B4;
    f32 unk_2B8;
    u8 pad_2BC[0x4];
    f64 unk_2C0;
    f64 unk_2C8;
};

extern f32 fn_1_8652C(int);
extern s16 camera_get_entry_field_0xa4(u32);
extern s32 camera_get_mode(void);
extern s16 fn_1_58F50(const void *);
extern s16 fn_1_59078(Obj_1_bss_6C84C_Target *);
extern struct fn_1_6E320_lbl_1_rodata_2D70 lbl_1_rodata_2D70;
extern u32 fn_1_584AC(void);
extern u32 fn_1_6EC0(u8);
extern u32 lbl_8006DB74(u32);
extern u8 * memset(u8 *, int, u32);
extern u32 fn_1_58C4(void);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006DD14(u32, void *);

#pragma opt_dead_assignments on
static inline f32 fn_1_6E320_read_pointer(struct fn_1_6E320_lbl_1_rodata_2D70 * owner) { return owner->unk_B8; }
#pragma opt_propagation off
#pragma opt_common_subs off
static inline f64 fn_1_6E320_operand(f64 right, f64 left) { left *= right; return left; }
#pragma opt_lifetimes on
static inline f32 fn_1_6E320_read_pointer_(struct fn_1_6E320_lbl_1_rodata_2D70 * owner) { return owner->unk_EC; }
static inline f32 fn_1_6E320_read_pointer__(struct fn_1_6E320_lbl_1_rodata_2D70 * owner) { return owner->unk_94; }
s16 fn_1_6E320(struct fn_1_6E320_Arg0 *arg0, void *arg1, u32 arg2) {
    union { f64 d; u32 w[2]; } cv;
    f32 fzgx_value_;
    f32 fzgx_live__;
    s32 fzgx_value;
    f32 fzgx_live_;
    f32 fzgx_live;
    struct fn_1_6E320_lbl_1_rodata_2D70 *p_lbl_1_rodata_2D70;
    struct fn_1_6E320_Loc loc;
    f32 v0;
    f32 v1;
    f32 v2;
    struct { f32 value; } v3;
    struct { f32 value; } v4;
    f32 v5;
    f32 v6;
    f32 v9;
    f32 v10;
    f32 v11;
    struct { f32 value; } v12;
    u32 v13;
    f32 v14;
    f32 v15;
    f32 v16;
    f64 v17;
    f32 v19;
    f32 t0;
    u32 t2;
    u32 t6;
    s16 t7;
    u32 t8;
    f32 loc_14[3];
    u32 loc_8[3];
    p_lbl_1_rodata_2D70 = &lbl_1_rodata_2D70;
    t0 = fn_1_8652C(arg0->unk_18);
    memset((u8 *)&loc, 0, 232);
    v1 = (f32)(t0 / p_lbl_1_rodata_2D70->unk_180);
    v0 = p_lbl_1_rodata_2D70->unk_2B8;
    loc.f1a = 1;
    loc.f0c = 25;
    loc.f18 = arg0->unk_18;
    v2 = (f32)(v0 - v1);
    v3.value = p_lbl_1_rodata_2D70->unk_74;
    if (v2 < p_lbl_1_rodata_2D70->unk_74) {
        v3.value = p_lbl_1_rodata_2D70->unk_74;
    } else {
        if (v2 > v0) {
            v3.value = v0;
        } else {
            v3.value = v2;
        }
    }
    t2 = fn_1_584AC();
    v4.value = p_lbl_1_rodata_2D70->unk_1C;
    cv.w[0] = 0x43300000;
    cv.w[1] = t2 & 0xFFFF;
    v5 = (f32)(cv.d - p_lbl_1_rodata_2D70->unk_40);
    fzgx_live_ = p_lbl_1_rodata_2D70->unk_24;
    fzgx_value = (s32)(f32)(v4.value * (fn_1_6E320_read_pointer(p_lbl_1_rodata_2D70) * (((v5 / fzgx_live_) + (v4.value)))) * v3.value);
    loc.f10 = fzgx_value;
    loc_14[0] = *(f32 *)((u8 *)arg0 + 60) + *(f32 *)((u8 *)arg1 + 0);
    loc_14[1] = *(f32 *)((u8 *)arg0 + 64) + *(f32 *)((u8 *)arg1 + 4);
    v6 = *(f32 *)((u8 *)arg0 + 68);
    loc_14[2] = v6 + *(f32 *)((u8 *)arg1 + 8);
    if (((1) == ((arg2 & 0xFF)))) {
        loc_8[0] = p_lbl_1_rodata_2D70->unk_2AC;
        loc_8[1] = p_lbl_1_rodata_2D70->unk_2B0;
        loc_8[2] = p_lbl_1_rodata_2D70->unk_2B4;
        fn_8006F1F0((void *)(((60) + ((u32)arg0))), loc_8, loc_14);
        lbl_8006DB74((u32)&loc.fb8);
    } else {
        loc.f50 = p_lbl_1_rodata_2D70->unk_F4;
        lbl_8006DD14(((184) + ((u32)arg0)), &loc.fb8);
        t6 = fn_1_6EC0(0);
        if ((s32)t6 != 0) {
            t7 = camera_get_entry_field_0xa4(0);
            if (((0) == (t7))) {
                loc.f50 = p_lbl_1_rodata_2D70->unk_0;
                fzgx_live = loc.f9c;
                fzgx_value_ = fzgx_live - fn_1_6E320_read_pointer_(p_lbl_1_rodata_2D70);
                loc.f9c = fzgx_value_;
            }
        }
    }
    loc.f3c = loc.f3c - loc.f48;
    loc.f40 = loc.f40 - loc.f4c;
    loc.f44 = loc.f44 - loc.f50;
    loc.f28 = p_lbl_1_rodata_2D70->unk_F0;
    v12.value = p_lbl_1_rodata_2D70->unk_78;
    if (v1 < p_lbl_1_rodata_2D70->unk_78) {
        v12.value = p_lbl_1_rodata_2D70->unk_78;
    } else {
        v12.value = p_lbl_1_rodata_2D70->unk_2B8;
        if (v1 > v12.value) {
            v12.value = p_lbl_1_rodata_2D70->unk_2B8;
        } else {
            v12.value = v1;
        }
    }
    t8 = fn_1_584AC();
    v13 = t8 & 0xFFFF;
    v14 = (f32)(t0 / p_lbl_1_rodata_2D70->unk_30);
    v15 = (f32)(u32)v13;
    v16 = v15;
    v16 = v16 / p_lbl_1_rodata_2D70->unk_24;
    v17 = (f64)(p_lbl_1_rodata_2D70->unk_108 * v16);
    loc.f2c = (f32)(fn_1_6E320_operand(v12.value, p_lbl_1_rodata_2D70->unk_2C0 * ((f64)(((v17) + (p_lbl_1_rodata_2D70->unk_2C8))))));
    if (v14 < p_lbl_1_rodata_2D70->unk_0) {
        v19 = p_lbl_1_rodata_2D70->unk_0;
    } else {
        fzgx_live__ = fn_1_6E320_read_pointer__(p_lbl_1_rodata_2D70);
        v19 = fzgx_live__;
        if (v14 > v19) {
            v19 = fzgx_live__;
        } else {
            v19 = v14;
        }
    }
    *(f32 *)((u8 *)arg0 + 180) = (f32)(p_lbl_1_rodata_2D70->unk_D0 * v19);
    if (*(s16 *)((u8 *)arg0 + 24) == ((s16)(((s16)(camera_get_mode())))) && fn_1_58C4() == 1) {
        return fn_1_59078((Obj_1_bss_6C84C_Target *)&loc);
    }
    return fn_1_58F50((const void *)&loc);
}
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma opt_dead_assignments reset
