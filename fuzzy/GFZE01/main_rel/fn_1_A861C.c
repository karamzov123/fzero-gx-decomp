/* Non-matching: best partial attempt (98.43% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/driver.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = -0.10000000149011612f;
    s = 0.10000000149011612f;
    s = 5.0f;
    s = 0.5f;
    s = 10.0f;
    s = 50.0f;
    s = 57.2957763671875f;
    s = -10.0f;
    s = 0.20000000298023224f;
    s = -30.0f;
    s = 1.8518518209457397f;
    s = -1.8518518209457397f;
    s = 4.166666507720947f;
    s = 25.0f;
    s = 30.0f;
    s = 182.04444885253906f;
    s = 0.46296295523643494f;
}
#pragma section code_type ".text"

#pragma fp_contract off

extern f32 lbl_1_rodata_4A28[];
extern void lbl_8006DBAC(void *arg0);
extern void lbl_8006DB74(void *arg0);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void mathutil_mtxA_rotate_z(s32);

struct Struct29 {
    u8 pad0[0xdc];
    f32 unk_dc;
    f32 unk_e0;
    f32 unk_e4;
    u8 unk_e8;
    u8 unk_e9;
    u8 padEA[0x15c - 0xea];
    u8 unk_15c[1];
};

struct Struct30 {
    u8 pad0[0x8];
    f32 unk_8;
    u8 padC[0xa4 - 0xc];
    f32 unk_a4;
    u8 padA8[0xb0 - 0xa8];
    f32 unk_b0;
    u8 padB4[0xb8 - 0xb4];
    f32 unk_b8;
    u8 padBC[0xc0 - 0xbc];
    f32 unk_c0;
};

#pragma opt_loop_invariants off
void fn_1_A861C(struct Struct29 *arg0, struct Struct30 *arg1) {
    f32 fzgx_live;
    f32 *rodata = lbl_1_rodata_4A28;

    lbl_8006DBAC(arg0);
    if (arg1 == NULL) {
        arg0->unk_e0 = arg0->unk_dc = arg0->unk_e4 = (0.0f);
    } else {
        f32 f6;
        f32 f7;
        f32 t0 = (0.5f) * (arg1->unk_b8 / arg1->unk_8);
        f32 f12 = arg1->unk_c0 / arg1->unk_8;
        f32 t1 = (57.2957763671875f) * (-arg1->unk_a4 / arg1->unk_b0);
        f32 f2;
        s32 flag;
        f32 limit;
        f32 hi;

        f6 = (((((((t0) * ((10.0f)))))) + ((((50.0f) * t1)))));
        f7 = (-10.0f) * (t0 + t1);

        if (f12 < (-1.8518518209457397f)) {
            f2 = -((1.8518518209457397f) + f12);
        } else {
            f2 = (0.0f);
        }

        arg0->unk_e4 += (((f2 / (4.166666507720947f)) * (-30.0f)) - arg0->unk_e4) * (0.20000000298023224f);

        flag = FALSE;
        if (arg0->unk_e9 != 0) {
            if (arg0->unk_e8 == 0x21 || arg0->unk_e8 == 0x2a || arg0->unk_e8 == 0x2b) {
                flag = TRUE;
            }
        }

        if (flag) {
            limit = (0.0f);
        } else {
            limit = (25.0f);
        }

        if (f6 > limit) {
            f6 = limit;
        } else if (f6 < -limit) {
            f6 = -limit;
        }

        hi = (30.0f);

        fzgx_live = arg0->unk_dc;
        arg0->unk_dc += (f6 - fzgx_live) * (0.20000000298023224f);

        if (f7 > hi) {
            f7 = hi;
        } else if (f7 < (-30.0f)) {
            f7 = (-30.0f);
        }

        arg0->unk_e0 += (f7 - arg0->unk_e0) * (0.20000000298023224f);
    }

    mathutil_mtxA_rotate_z((s32)((182.04444885253906f) * arg0->unk_e4));
    fzgx_live = arg0->unk_dc;
    mathutil_mtxA_rotate_y((s32)((182.04444885253906f) * fzgx_live));
    mathutil_mtxA_rotate_x((s32)((182.04444885253906f) * arg0->unk_e0));
    lbl_8006DB74(&arg0->unk_15c);
}
#pragma opt_loop_invariants reset

