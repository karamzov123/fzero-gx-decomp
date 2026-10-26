/* Non-matching: best partial attempt (88.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "psvec.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

struct fn_1_DF2A4_lbl_1_rodata_6780 {
    u8 pad_0[0x18];
    f64 unk_18;
    f32 unk_20;
    u8 pad_24[0x10];
    f32 unk_34;
    u8 pad_38[0x40];
    f32 unk_78;
    f32 unk_7C;
    u8 pad_80[0x38];
    f32 unk_B8;
    u8 pad_BC[0x4];
    u32 unk_C0;
    u32 unk_C4;
    u32 unk_C8;
};

typedef struct {
    u32 a[12];
    u32 b[13];
} Big;

extern f32 lbl_8006D534(void *, void *);
extern f64 __fabs(f64);
extern struct fn_1_DF2A4_lbl_1_rodata_6780 lbl_1_rodata_6780;
extern u32 fn_8006E250(void *, void *);
extern u32 fn_8006E2B0(void *, void *);
extern u32 lbl_8006D5F0(void *, void *, f32);
extern u32 lbl_8006D7DC(u32);
extern u32 lbl_8006DBAC(u32);
extern u32 lbl_8006DFC4(void *);
extern u32 lbl_8006E0A4(u8 *);
extern u32 mathutil_mtxA_rotate_x(u32);
extern void * lbl_8006DC34(void *);
extern void fn_80008BEC(u8 *, int, u32);
extern void lbl_8006DB74(void *);
extern void lbl_8006D758(void);
extern s16 fn_1_DEDC4(void *, void *, u32, void *, u8 *, void *, u8 *, f32);

static inline f32 fn_1_DF2A4_read_pointer(Vec3 * owner) { return owner->z; }
#pragma opt_common_subs off
#pragma opt_dead_assignments off
static inline f32 fn_1_DF2A4_read_pointer_(struct fn_1_DF2A4_lbl_1_rodata_6780 * owner) { return owner->unk_B8; }
#pragma opt_propagation off
#pragma opt_loop_invariants off
static inline f32 fn_1_DF2A4_read_pointer__(struct fn_1_DF2A4_lbl_1_rodata_6780 * owner) { return owner->unk_34; }
s16 fn_1_DF2A4(Vec3 *arg0, Vec3 *arg1, u32 arg2, Vec3 *arg3, Vec3 *arg4, void *arg5, Vec3 *arg6, f32 arg7, f32 arg8) {
    f32 fzgx_live___;
    f32 fzgx_live__;
    f32 fzgx_live_;
    f32 fzgx_live;
    struct fn_1_DF2A4_lbl_1_rodata_6780 *p_lbl_1_rodata_6780;
    Big loc_Big;
    u32 loc_80[3];
    u32 loc_74[3];
    Vec3 loc_68;
    Vec3 loc_5C;
    Vec3 loc_50;
    Vec3 loc_44;
    Vec3 loc_38;
    Vec3 loc_2C;
    u32 loc_20[3];
    Vec3 loc_14;
    Vec3 loc_8;
    f32 v0;
    f32 v1;
    f32 v2;
    f32 v3;
    f32 v5;
    f32 v6;
    f32 v7;
    s16 v8;
    s32 v9;

    p_lbl_1_rodata_6780 = (struct fn_1_DF2A4_lbl_1_rodata_6780 *)&lbl_1_rodata_6780;
    loc_80[0] = p_lbl_1_rodata_6780->unk_C0;
    loc_80[1] = p_lbl_1_rodata_6780->unk_C4;
    loc_80[2] = p_lbl_1_rodata_6780->unk_C8;
    lbl_8006DBAC(arg2);
    v1 = (f32)(fn_1_DF2A4_read_pointer(arg1) - arg3->z);
    psvec_sub(&arg1->x, &arg3->x, &loc_14.x);
    loc_14.z = v1;
    fzgx_live = arg4->x;
    v1 = (f32)(loc_14.x * fzgx_live) + loc_14.y * arg4->y + v1 * arg4->z;
    if ((f32)(v1 * v1) > (f32)(arg7 * arg7) + arg8 * arg8) {
        fn_80008BEC((u8 *)arg6, 0, 12);
        return 0;
    }
    fn_8006E2B0(arg4, loc_74);
    v0 = lbl_8006D534(loc_80, loc_74);
    if (__fabs(v0) < p_lbl_1_rodata_6780->unk_18) {
        fn_80008BEC((u8 *)arg6, 0, 12);
        lbl_8006D5F0(arg4, &loc_50, -arg7);
        psvec_add(&arg1->x, &loc_50.x, &loc_68.x);
        v2 = (f32)(fn_1_DF2A4_read_pointer(arg1) + (*(f32 volatile *)&(loc_50.z)) /* Retail reloads this field. */);
        psvec_add(&arg0->x, &loc_50.x, &loc_5C.x);
        v3 = (f32)(arg0->z + loc_50.z);
        loc_68.z = v2;
        loc_5C.z = v3;
        fzgx_live = arg4->x;
        fzgx_live = arg4->x;
        v5 = (f32)(fzgx_live * arg3->x) + arg4->y * arg3->y + arg3->z * arg4->z;
        fzgx_live = arg4->x;
        v6 = (f32)(fzgx_live * loc_5C.x) + arg4->y * loc_5C.y + v3 * arg4->z;
        v7 = -v5;
        fzgx_live__ = loc_68.y;
        fzgx_live___ = loc_68.x;
        v1 = (f32)((v7 + v6) * (v7 + ((((f32)(fzgx_live * fzgx_live___)) + ((arg4->y * fzgx_live__) + (v2 * arg4->z))))));
        if (v1 < p_lbl_1_rodata_6780->unk_78) {
            v8 = -1;
        } else if (v1 > p_lbl_1_rodata_6780->unk_7C) {
            v8 = 1;
        } else {
            v8 = 0;
        }
        if (v8 > 0) {
            return 0;
        }
        psvec_sub(&loc_68.x, &arg3->x, &loc_8.x);
        fzgx_live = arg4->x;
        fzgx_live_ = loc_8.y;
        v1 = (f32)(loc_8.x * fzgx_live) + fzgx_live_ * arg4->y + loc_8.z * arg4->z;
        lbl_8006D5F0(arg4, arg5, fn_1_DF2A4_read_pointer_(p_lbl_1_rodata_6780) * v1);
        fn_8006E250(&loc_68, arg6);
        return 2;
    } else {
        arg8 = fn_1_DF2A4_read_pointer__(p_lbl_1_rodata_6780) * arg8;
        fn_8006E250(arg3, loc_20);
        fn_80008BEC((u8 *)&loc_2C, 0, 12);
        loc_2C.y = arg8;
        if (v0 > p_lbl_1_rodata_6780->unk_20) {
            mathutil_mtxA_rotate_x(-32768);
        }
        lbl_8006E0A4((u8 *)&loc_2C);
        lbl_8006DB74(&loc_Big.b);
        psvec_set(&loc_44.x, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
        lbl_8006DC34((void *)&loc_Big.a);
        lbl_8006D7DC((u32)arg0);
        lbl_8006DFC4(&loc_Big.a);
        lbl_8006E0A4((u8 *)&loc_2C);
        psvec_set(&loc_38.x, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
        v9 = fn_1_DEDC4(&loc_38, &loc_44, (u32)arg3, &loc_Big.b, (u8 *)arg4, arg5, (u8 *)arg6, arg7);
        if (v9 != 0) {
            lbl_8006D758();
            if (v0 > p_lbl_1_rodata_6780->unk_20) {
                mathutil_mtxA_rotate_x(-32768);
            }
            arg6->y = arg8;
            lbl_8006E0A4((u8 *)arg6);
            psvec_set(&arg6->x, *(f32 *)(0xE0000000 + 0x2C), *(f32 *)(0xE0000000 + 0x1C), *(f32 *)(0xE0000000 + 0x0C));
        }
        return v9;
    }
}
#pragma opt_loop_invariants reset

#pragma opt_propagation reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

