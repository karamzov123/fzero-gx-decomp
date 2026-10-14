/* Non-matching: best partial attempt (95.21% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"

typedef struct Sig_fn_8006EE70_Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_8006EE70_Vec3;

extern double fabs(double);

typedef struct Fn1DD4DC_Pool {
    u8 pad_0[0x18];
    f64 unk_18;
    f32 unk_20;
    f32 unk_24;
    f32 unk_28;
    u8 pad_2C[4];
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
} Fn1DD4DC_Pool;

extern Fn1DD4DC_Pool lbl_1_rodata_6780;

typedef struct Fn1DD4DC_Target2 {
    u8 pad_0[0x20];
    void *unk_20;
    u8 pad_24[4];
    void *unk_28;
    u8 pad_2C[0xC];
    void *unk_38;
} Fn1DD4DC_Target2;

typedef struct Fn1DD4DC_Mtx {
    f32 a[14];
} Fn1DD4DC_Mtx;

typedef struct Fn1DD4DC_Obj {
    u8 pad_0[8];
    s16 unk_8;
    u8 pad_A[0x22];
    Sig_fn_8006EE70_Vec3 unk_2C;
    u8 pad_38[0xC];
    Sig_fn_8006EE70_Vec3 unk_44;
    f32 unk_50;
    u8 pad_54[0x18];
    Sig_fn_8006EE70_Vec3 unk_6C;
    u8 pad_78[0x10];
    u8 unk_88[0x3C];
    u8 unk_C4[0x4C];
    u8 unk_110[4];
} Fn1DD4DC_Obj;

extern void fn_1_E57F4(void *, f32);
extern void fn_1_556B8(void *);
extern void fn_1_56298(f32, f32, f32, f32);
extern void fn_1_55FF0(f32);
extern void fn_1_DCFA4(Fn1DD4DC_Obj *);
extern void fn_8006EE70(const Sig_fn_8006EE70_Vec3 *, s16 *);
extern void fn_80072558(void);
extern void mathutil_mtxA_rotate_x(u32);
extern void mathutil_mtxA_rotate_y(u32);
extern void mathutil_mtxA_rotate_z(u32);
extern void lbl_8006D784(Fn1DD4DC_Mtx *);
extern void lbl_8006D7DC(void *);
extern f32 lbl_8006D0B4(f32);
extern void lbl_8006DB74(Fn1DD4DC_Mtx *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DFE8(void *);
extern void lbl_8006E0A4(void *);
extern void lbl_8006E14C(f32);
extern void lbl_8006E15C(f32, f32, f32);

#pragma opt_propagation off
#pragma opt_common_subs off
static inline f32 fn_1_DD4DC_read_pointer(Sig_fn_8006EE70_Vec3 * owner) { return owner->y; }
#pragma opt_loop_invariants off
#pragma opt_lifetimes off
void fn_1_DD4DC(Fn1DD4DC_Obj *obj) {
    f32 fzgx_live__;
    f32 fzgx_value;
    f32 fzgx_live_;
    f32 fzgx_live;
    Fn1DD4DC_Mtx mtx;
    s16 loc_18[4];
    s16 loc_10[4];
    s16 loc_8[4];
    Fn1DD4DC_Pool *pool;
    Sig_fn_8006EE70_Vec3 tv;
    f32 len;
    f32 sq;
    f32 t;
    struct { f32 value; } c;

    pool = &lbl_1_rodata_6780;
    fn_1_E57F4(obj, pool->unk_20);
    if (obj->unk_8 <= 100) {
        lbl_8006D784(&mtx);
        lbl_8006DBAC(&obj->unk_C4);
        fzgx_value = *(f32 *)(0xE0000000 + 0x0C);
        tv.x = fzgx_value;
        tv.y = *(f32 *)(0xE0000000 + 0x1C);
        tv.z = *(f32 *)(0xE0000000 + 0x2C);
        mtx.a[3] = tv.x;
        mtx.a[7] = fn_1_DD4DC_read_pointer(&tv);
        mtx.a[11] = tv.z;
        lbl_8006DFE8(&mtx);
        len = obj->unk_50;
{
    double tmp_call6;
        tmp_call6 = fabs(len);
        if (tmp_call6 >= pool->unk_18) {
}
            fn_8006EE70(&obj->unk_44, loc_18);
            mathutil_mtxA_rotate_z(loc_18[2]);
            mathutil_mtxA_rotate_y(loc_18[1]);
            mathutil_mtxA_rotate_x((*((loc_18) + (0))));
            t = pool->unk_24 * len;
            if (t < pool->unk_20) {
                c.value = pool->unk_20;
            } else if (t > pool->unk_24) {
                c.value = pool->unk_24;
            } else {
                c.value = t;
            }
            lbl_8006E15C(pool->unk_28, pool->unk_28, c.value);
            fn_80072558();
            fn_1_556B8(((Fn1DD4DC_Target2 *)lbl_1_bss_38454->unk_8)->unk_38);
        }
        fn_1_56298(pool->unk_28, pool->unk_28, pool->unk_20, pool->unk_28);
        lbl_8006DFE8(&mtx);
        sq = obj->unk_2C.x * obj->unk_2C.x;
        sq += obj->unk_2C.y * obj->unk_2C.y;
        sq += obj->unk_2C.z * obj->unk_2C.z;
        len = lbl_8006D0B4(sq);
        if (fabs(len) >= pool->unk_18) {
            fn_8006EE70(&obj->unk_2C, loc_10);
            mathutil_mtxA_rotate_z(loc_10[2]);
            mathutil_mtxA_rotate_y(loc_10[1]);
            mathutil_mtxA_rotate_x(loc_10[0]);
            t = pool->unk_24 * len;
            if (t < pool->unk_20) {
                c.value = pool->unk_20;
            } else if (t > pool->unk_24) {
                c.value = pool->unk_24;
            } else {
                c.value = t;
            }
            lbl_8006E15C(pool->unk_28, pool->unk_28, c.value);
            fn_80072558();
            fn_1_556B8(((Fn1DD4DC_Target2 *)lbl_1_bss_38454->unk_8)->unk_38);
        }
        fn_1_56298(pool->unk_20, pool->unk_20, pool->unk_20, pool->unk_20);
        fn_1_DCFA4(obj);
        lbl_8006D784(&mtx);
        lbl_8006DBAC(&obj->unk_C4);
        tv.x = *(f32 *)(0xE0000000 + 0x0C);
        tv.y = *(f32 *)(0xE0000000 + 0x1C);
        mtx.a[3] = tv.x;
        tv.z = *(f32 *)(0xE0000000 + 0x2C);
        mtx.a[7] = fn_1_DD4DC_read_pointer(&tv);
        mtx.a[11] = tv.z;
        lbl_8006DFE8(&mtx);
        fn_1_56298(pool->unk_20, pool->unk_28, pool->unk_20, pool->unk_20);
        sq = obj->unk_6C.x * obj->unk_6C.x;
        fzgx_live_ = obj->unk_6C.y;
        sq += fzgx_live_ * fzgx_live_;
        fzgx_live = obj->unk_6C.z;
        sq += fzgx_live * fzgx_live;
        len = lbl_8006D0B4(sq);
        if (fabs(len) >= pool->unk_18) {
            fn_8006EE70(&obj->unk_6C, loc_8);
            mathutil_mtxA_rotate_z(loc_8[2]);
            mathutil_mtxA_rotate_y((*((loc_8) + (1))));
            mathutil_mtxA_rotate_x(loc_8[0]);
            t = pool->unk_24 * len;
            if (t < pool->unk_20) {
                c.value = pool->unk_20;
            } else if (t > pool->unk_24) {
                c.value = pool->unk_24;
            } else {
                c.value = t;
            }
            lbl_8006E15C(pool->unk_28, pool->unk_28, c.value);
            fn_80072558();
            fn_1_556B8(((Fn1DD4DC_Target2 *)lbl_1_bss_38454->unk_8)->unk_38);
        }
        fn_1_56298(pool->unk_20, pool->unk_20, pool->unk_20, pool->unk_20);
        lbl_8006DFE8(&obj->unk_C4);
        lbl_8006E0A4(&obj->unk_88);
        lbl_8006E14C(pool->unk_30);
        fn_80072558();
        fn_1_55FF0(pool->unk_34);
        fn_1_56298(pool->unk_28, pool->unk_20, pool->unk_20, pool->unk_20);
        fn_1_556B8(((Fn1DD4DC_Target2 *)lbl_1_bss_38454->unk_8)->unk_20);
        fn_1_56298(pool->unk_20, pool->unk_20, pool->unk_20, pool->unk_20);
        lbl_8006D784(&mtx);
        lbl_8006D7DC(&obj->unk_110);
        lbl_8006DB74(&mtx);
        lbl_8006DFE8(&mtx);
        mathutil_mtxA_rotate_x(0x10000 - 0x4000);
        fzgx_live__ = pool->unk_38;
        lbl_8006E14C(fzgx_live__);
        fn_80072558();
        fn_1_556B8(((Fn1DD4DC_Target2 *)lbl_1_bss_38454->unk_8)->unk_28);
    }
}
#pragma opt_lifetimes reset

#pragma opt_loop_invariants reset

#pragma opt_common_subs reset

#pragma opt_propagation reset

