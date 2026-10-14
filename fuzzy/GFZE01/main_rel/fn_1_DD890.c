/* Non-matching: best partial attempt (61.13% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_for.h"
struct fn_1_DD890_lbl_1_rodata_6780 {
    u8 pad_0[0x18];
    f64 unk_18;
    f32 unk_20;
    u8 pad_24[4];
    f32 unk_28;
    u8 pad_2C[8];
    f32 unk_34;
    u8 pad_38[4];
    f32 unk_3C;
    f64 unk_40;
};
extern struct fn_1_DD890_lbl_1_rodata_6780 lbl_1_rodata_6780;
extern u32 lbl_801A66A0;
extern void fn_1_DD4DC(void);
extern void fn_1_56298(f32, f32, f32, f32);
extern f32 fn_1_E5734(void *);
extern void lbl_8006DFE8(void *);
extern void lbl_8006DBAC(void *);
extern void lbl_8006DB74(void *);
extern void fn_1_9BBE4(void *, s32, s32, void *);
extern s32 fn_1_54F5C(void *, f32, f32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_z(s32);
extern void fn_80072558(void);
extern void fn_1_55FF0(f32);
extern void fn_1_553C4(void *, s32);
extern void fn_1_556B8(void *);
extern void lbl_8006E15C(f32, f32, f32);
extern void lbl_8006E14C(f32);
extern void lbl_8006D784(void *);
extern f32 lbl_8006D0B4(f32);
extern void fn_8006EE70(void *, s16 *);
extern void fn_1_A8DD4(const char *, ...);
extern void fn_1_E50F0(void *, void *);
extern void fn_1_E5164(void *, void *);
extern void fn_1_E52F8(void *, void *);
extern void _savegpr_27(void);
extern void _restgpr_27(void);

#define U32(o) (*(u32 *)((u8 *)obj + (o)))
#define S16(o) (*(s16 *)((u8 *)obj + (o)))
#define F32(o) (*(f32 *)((u8 *)obj + (o)))
void fn_1_DD890(u32 arg0, f32 arg1) {
    u8 *obj = (u8 *)arg0;
    struct fn_1_DD890_lbl_1_rodata_6780 *pool = &lbl_1_rodata_6780;
    s32 i;
    s32 id;
    u8 *entry;
    f32 f;
    f32 a;
    f32 b;
    f32 c;
    f32 d;
    f32 angle;
    f32 mat[12];
    s16 rot[3];
    if (!obj) return;
    if (((U32(0x138) & 0) | (U32(0x13c) & 1)) != 0) return;
    if ((U32(0x13c) & 0x80) != 0) fn_1_DD4DC();
    if ((U32(0x138) & 0x4000) || (U32(0x13c) & 0x4000)) {
        if (U32(0x13c) & 0x4000)
            fn_1_56298(pool->unk_20, pool->unk_20, pool->unk_28, pool->unk_28);
        if (U32(0x13c) & 0x800)
            fn_1_56298(pool->unk_28, pool->unk_28, pool->unk_20, pool->unk_28);
        if (U32(0x13c) & 0x8000)
            fn_1_56298(pool->unk_20, pool->unk_28, pool->unk_20, pool->unk_28);
        if (U32(0x138) & 1)
            fn_1_56298(pool->unk_20, pool->unk_28, pool->unk_28, pool->unk_28);
    }
    lbl_8006DFE8(obj + 0xc4);
    if (U32(0x13c) & 0x200) {
        id = S16(0xe);
        entry = (u8 *)lbl_1_bss_3BE0->unk_54 + id * 0x40;
        *(u32 *)entry &= 0x7fffffff;
        f = fn_1_E5734(obj);
        *(f32 *)(entry + 0x2c) = pool->unk_28 - f;
        lbl_8006DBAC(obj + 0xc4);
        if (S16(0xa) == 5 || S16(0xa) == 1) {
            u32 x = *(u32 *)&lbl_801A66A0 * 6;
            angle = (f32)(x % 360);
            angle = (s32)((angle - 4503599627370496.0) * pool->unk_3C);
            mathutil_mtxA_rotate_y((s32)angle);
        }
        lbl_8006DB74(mat);
        fn_1_9BBE4((void *)(*(u32 *)((u8 *)lbl_1_bss_3BE0) + 0x54), S16(0xe), S16(0xe), mat);
        *(u32 *)entry |= 0x80000000;
        for (i = 0; i < 4; i++) {
            id = *(s16 *)(obj + 0x10 + i * 2);
            if (id != -1) {
                entry = (u8 *)(*(u32 *)((u8 *)lbl_1_bss_3BE0) + 0x54 + id * 0x40);
                *(u32 *)entry &= 0x7fffffff;
                f = fn_1_E5734(obj);
                *(f32 *)(entry + 0x2c) = pool->unk_28 - f;
                lbl_8006DBAC(obj + 0xc4);
                lbl_8006DB74(mat);
                fn_1_9BBE4((void *)(*(u32 *)((u8 *)lbl_1_bss_3BE0) + 0x54), id, id, mat);
                *(u32 *)entry |= 0x80000000;
            }
        }
    } else {
        U32(0x13c) = 0;
        U32(0x138) |= 4;
        a = F32(0xf4); b = F32(0xf8); c = F32(0xfc);
        f = a > b ? a : b;
        if (f > c) f = a > b ? a : b;
        else f = c;
        if (fn_1_54F5C((u8 *)*(void **)obj + 8, f, a > b ? b : a) && fn_1_E5734(obj) != pool->unk_20) {
            U32(0x13c) = 0;
            U32(0x138) &= ~4;
            fn_80072558(); fn_1_55FF0(F32(4));
            if (*(void **)obj) {
                if (U32(0x13c) & 0x100) fn_1_553C4(obj, 1);
                else fn_1_556B8(obj);
            }
        }
    }
    if (U32(0x13c) & 0x10) {
        lbl_8006DFE8(obj + 0xc4);
        if (S16(0xc) == 1) {
            lbl_8006E15C(F32(0x1a0), F32(0x1a4), F32(0x1a0));
            fn_80072558(); fn_1_55FF0(pool->unk_34);
            fn_1_556B8((u8 *)*(void **)(*(u32 *)lbl_1_bss_38454 + 8) + 0x18);
        } else {
            lbl_8006E14C(F32(0x84));
            fn_80072558(); fn_1_55FF0(pool->unk_34);
            fn_1_556B8((u8 *)*(void **)(*(u32 *)lbl_1_bss_38454 + 8) + 0x20);
        }
    }
    if (U32(0x13c) & 0x40) {
        lbl_8006D784(mat);
        lbl_8006DBAC(obj + 0xc4);
        *(f32 *)((u8 *)0xe0000000 + 0xc) = *(f32 *)((u8 *)0xe0000000 + 0xc);
        *(f32 *)&mat[3] = *(f32 *)((u8 *)0xe0000000 + 0xc);
        *(f32 *)&mat[7] = *(f32 *)((u8 *)0xe0000000 + 0x1c);
        *(f32 *)&mat[11] = *(f32 *)((u8 *)0xe0000000 + 0x2c);
        lbl_8006DFE8(mat);
        fn_1_56298(pool->unk_20, pool->unk_20, pool->unk_28, pool->unk_28);
        f = lbl_8006D0B4((f32)(F32(0x128)*F32(0x128) + F32(0x12c)*F32(0x12c) + F32(0x130)*F32(0x130)));
        if (__fabsf(f) >= pool->unk_18) {
            fn_8006EE70(obj + 0x128, rot);
            mathutil_mtxA_rotate_z(rot[2]); mathutil_mtxA_rotate_y(rot[1]); mathutil_mtxA_rotate_x(rot[0]);
            angle = 5.0f * f;
            if (angle < pool->unk_20) angle = pool->unk_20;
            else if (angle > 5.0f) angle = 5.0f;
            else angle = angle;
            lbl_8006E15C(pool->unk_28, angle, pool->unk_28);
            fn_80072558(); fn_1_55FF0(pool->unk_28);
            fn_1_556B8((u8 *)*(void **)(*(u32 *)lbl_1_bss_38454 + 8) + 0x38);
        }
        fn_1_56298(pool->unk_20, pool->unk_20, pool->unk_20, pool->unk_20);
    }
    if ((U32(0x13c) & 4) || (U32(0x13c) & 2)) fn_1_E50F0(obj, fn_1_A8DD4);
    if (U32(0x13c) & 0x1000) fn_1_E5164(obj, fn_1_A8DD4);
    if (U32(0x13c) & 0x20) fn_1_E52F8(obj, fn_1_A8DD4);
    fn_1_56298(pool->unk_20, pool->unk_20, pool->unk_20, pool->unk_20);
}
