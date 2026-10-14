/* Non-matching: best partial attempt (97.47% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/hw_regs.h"
#include "types.h"
#include "psvec.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f32 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 52.0f;
    s = 0.0625f;
    s = 45.0f;
    s = 0.0f;
    s = 1.7000000476837158f;
    s = 1.0f;
    s = 0.10000000149011612f;
    s = 0.5f;
    d = 4503599627370496.0;
    s = 40.0f;
    s = 348.0f;
    s = 36.0f;
    s = 4.0f;
    s = 0.6000000238418579f;
    s = 5.0f;
    s = 0.05000000074505806f;
    s = 1000.0f;
    s = 8.0f;
}
static const u32 fzgx_pool_table2[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 216.0;
    d = 2.0;
    s = 0.25f;
    s = 0.07000000029802322f;
    s = 0.20000000298023224f;
}
static const u32 fzgx_pool_table4[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.834999918937683f;
}
static const u32 fzgx_pool_table6[1] = {0xAE147AE1};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 2.0f;
    s = 1.7999999523162842f;
    s = 1.399999976158142f;
    s = 1.5f;
    s = 1.2000000476837158f;
    s = 2.299999952316284f;
    s = 0.4000000059604645f;
    s = 3.200000047683716f;
    s = 0.15000000596046448f;
    s = -0.25f;
    s = 0.1599999964237213f;
    s = 0.11999999731779099f;
    s = 0.07999999821186066f;
    s = 0.44999998807907104f;
    s = 0.699999988079071f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.6000000238418579;
    s = 0.3100000023841858f;
    s = 0.029999999329447746f;
    s = 0.009999999776482582f;
    s = 700.0f;
    s = 1.7674999237060547f;
}
static const u32 fzgx_pool_table10[1] = {0xA3D70A3D};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5699999928474426f;
}
static const u32 fzgx_pool_table12[4] = {0x00000000, 0x00000000, 0x00000000, 0x3F800000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime13(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = -0.10000000149011612f;
    s = 200.0f;
    s = 0.019999999552965164f;
    d = 0.009999999776482582;
    s = 0.03999999910593033f;
    s = 0.800000011920929f;
}
#pragma section code_type ".text"

typedef struct Sig_fn_1_25870_Fn_1_25870 {
    u32 flags;
    unsigned char pad04[0x1f4];
    f32 field1f8;
    f32 field1fc;
    unsigned char pad200[0x24];
    f32 field224;
    unsigned char pad228[0x1c];
    u32 field244;
    unsigned char pad248[0x58];
    u32 field2a0;
    unsigned char pad2a4[0x58];
    u32 field2fc;
    unsigned char pad300[0x58];
    u32 field358;
    unsigned char pad35c[0x11a];
    u8 field476;
    u8 field477;
} Sig_fn_1_25870_Fn_1_25870;

struct Sig_fn_1_207DC_fn_1_207DC_obj {
    u8 pad_0[0x30];
    f32 unk_30;
    f32 unk_34;
    u8 pad_38[4];
    f32 unk_3C;
    u8 pad_40[0x28];
    f32 unk_68;
    f32 unk_6C;
    u8 pad_70[0xC];
    u32 unk_7C;
};

typedef struct {
    f32 pad[43];
    f32 inv_x;
    f32 inv_y;
    f32 inv_z;
} Sig_fn_1_28F08_ScaleInfo;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Sig_fn_1_28F08_Vec3;

typedef struct {
    u32 x;
    u32 y;
    u32 z;
} Sig_U32x3;

typedef struct {
    unsigned char pad000[0x5C];
} Sig_fn_1_236CC_Elem;

extern s32 fn_1_2BF8C(u32);
extern s32 fn_1_27E34(u32);
extern f32 fn_1_253A4(u32);
extern u32 fn_1_25480(u32, void *, f32);
extern u16 fn_1_278B8(u32, void *, f32);
extern u32 fn_1_27DE4(u32);
extern u32 fn_1_28184(u32);
extern u32 fn_1_289B4(u32, void *, void *);
extern u32 fn_1_290E8(u32);
extern u32 fn_1_294D0(u32);
extern u32 fn_1_29800(u32);
extern u32 fn_1_2A214(u32);
extern u32 fn_1_2B524(u32);
extern u32 lbl_8006DB74(u32);
extern void fn_1_25870(Sig_fn_1_25870_Fn_1_25870 *);
extern void fn_1_28F08(Sig_fn_1_28F08_ScaleInfo *, Sig_fn_1_28F08_Vec3 *, f32);
extern void lbl_8006DBAC(struct Sig_fn_1_207DC_fn_1_207DC_obj *);
extern f32 __fabsf(f32);

#pragma opt_common_subs off
#pragma opt_dead_assignments off
static inline f32 fn_1_236CC_operand(f32 left, f32 right) { return left * right; }
#pragma opt_lifetimes off
static inline f32 fn_1_236CC_operand_(f32 left, f32 right) { return left * right; }
#pragma opt_loop_invariants off
void fn_1_236CC(u32 arg0) {
    s32 loc_8;
    Sig_U32x3 loc_18;
    Sig_U32x3 loc_C;
    f32 t_cz;
    f32 t_cy;
    f32 t_cx;
    f32 t_f31;
    f32 t_f30;
    f32 t_f29;
    u32 n;
    s32 i;
    s32 tmp_call3;

    if (fn_1_2BF8C(arg0) != 0) {
        *(u32 *)((u8 *)arg0 + 0x58C) &= 0xFFFFFFF7;
    } else {
        *(u32 *)((u8 *)arg0 + 0x58C) |= 8;
        fn_1_289B4(arg0, &loc_8, &loc_C);
        tmp_call3 = fn_1_27E34(arg0);
        if (tmp_call3 != 0 && loc_8 != 0) {
            *(Sig_U32x3 *)((u8 *)arg0 + 0x1BC) = loc_C;
        }
        loc_18 = *(Sig_U32x3 *)((u8 *)arg0 + 0x94);
        t_f29 = fn_1_253A4(arg0);
        fn_1_25870((Sig_fn_1_25870_Fn_1_25870 *)arg0);
        t_f30 = *(f32 *)((u8 *)arg0 + 0xA4);
        if (*(u8 *)((u8 *)arg0 + 0x481) != 0) {
            for (i = 0; i < 4; i++) {
                fn_1_278B8(arg0,
                           (void *)((u8 *)&((Sig_fn_1_236CC_Elem *)arg0)[i] + 0x244),
                           t_f30);
            }
        }
        if (*(u32 *)((u8 *)arg0 + 0) & 0x4) {
            f32 ta = *(f32 *)((u8 *)arg0 + 0x580);
            *(f32 *)((u8 *)arg0 + 0x580) = fn_1_236CC_operand_((ta), (0.02f));
        }
        if (__fabsf(*(f32 *)((u8 *)arg0 + 0x1F8)) > 0.009999999776482582) {
            f32 tb = *(f32 *)((u8 *)arg0 + 0x580);
            *(f32 *)((u8 *)arg0 + 0x580) = fn_1_236CC_operand((tb), (0.04f));
        }
        fn_1_25480(arg0, &loc_18, t_f29);
        fn_1_2A214(arg0);
        lbl_8006DBAC((struct Sig_fn_1_207DC_fn_1_207DC_obj *)((u8 *)arg0 + 0xEC));
        fn_1_29800(arg0);
        fn_1_290E8(arg0);
        fn_1_294D0(arg0);
        t_f31 = 1.0f / *(f32 *)((u8 *)arg0 + 8);
        psvec_scale_add((void *)((u8 *)arg0 + 0x7C), (void *)((u8 *)arg0 + 0x94),
                        t_f31, (void *)((u8 *)arg0 + 0x7C));
        *(f32 *)((u8 *)arg0 + 0x84) = *(f32 *)((u8 *)arg0 + 0x84)
                                    + ((t_f31) * (*(f32 *)((u8 *)arg0 + 0x9C)));
        fn_1_28184(arg0);
        t_cx = *(f32 *)((u8 *)arg0 + 0x7C);
        t_cy = *(f32 *)((u8 *)arg0 + 0x80);
        t_cz = *(f32 *)((u8 *)arg0 + 0x84);
        *(f32 *)(LC_BASE + 0xC) = t_cx;
        *(f32 *)(LC_BASE + 0x1C) = t_cy;
        *(f32 *)(LC_BASE + 0x2C) = t_cz;
        fn_1_28F08((Sig_fn_1_28F08_ScaleInfo *)arg0,
                   (Sig_fn_1_28F08_Vec3 *)((u8 *)arg0 + 0xA0), 0.0f);
        *(f32 *)(LC_BASE + 0xC) = 0.0f;
        *(f32 *)(LC_BASE + 0x1C) = 0.0f;
        *(f32 *)(LC_BASE + 0x2C) = 0.0f;
        lbl_8006DB74(arg0 + 0xEC);
        if (*(u32 *)((u8 *)arg0 + 0) & 0x40000) {
            *(u32 *)((u8 *)arg0 + 0) |= 0x80000;
        }
        if (*(u32 *)((u8 *)arg0 + 0) & 0x10000) {
            *(u32 *)((u8 *)arg0 + 0) &= 0xFFE7FFFF;
        }
        if (*(u32 *)((u8 *)arg0 + 0) & 0x200000) {
            n = *(u8 *)((u8 *)arg0 + 0x481);
            if (n < 30) {
                if ((s32)n % 6 == 0) {
                    fn_1_2B524(arg0);
                }
            } else if (n < 90) {
                *(f32 *)((u8 *)arg0 + 0xA0) = 0.0f;
                *(f32 *)((u8 *)arg0 + 0xA4) = 0.0f;
                *(f32 *)((u8 *)arg0 + 0xA8) = 0.0f;
            }
        }
        if (*(u8 *)((u8 *)arg0 + 0x216) != 0) {
            *(u8 *)((u8 *)arg0 + 0x216) = *(u8 *)((u8 *)arg0 + 0x216) - 1;
        }
        *(u32 *)((u8 *)arg0 + 0) &= 0xFC7FCFFF;
        *(f32 *)((u8 *)arg0 + 0x208) = 200.0f;
        fn_1_27DE4(arg0);
    }
}
#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

#pragma opt_common_subs reset

