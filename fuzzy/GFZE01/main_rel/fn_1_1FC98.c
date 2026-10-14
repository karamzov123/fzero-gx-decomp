/* Non-matching: best partial attempt (93.21% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

struct fn_1_1FC98_elem {
    u8 pad_0[0xC];
    s16 unk_C;
    s16 unk_E;
    s16 unk_10;
    u8 pad_12[2];
    f32 unk_14;
    f32 unk_18;
    f32 unk_1C;
    s32 unk_20;
};

struct fn_1_1FC98_mgr {
    u8 pad_0[0x94];
    u32 unk_94;
    struct fn_1_1FC98_elem *unk_98;
};

struct fn_1_1FC98_vec {
    f32 x;
    f32 y;
    f32 z;
};

extern struct fn_1_1FC98_mgr *lbl_1_bss_3BE0;
extern void lbl_8006D7DC(void *);
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern s32 mathutil_mtxA_rotate_z(u32);
extern f32 __fabsf(f32);
extern void fn_8006E250(u32, struct fn_1_1FC98_vec *);

#pragma opt_propagation off
#pragma opt_lifetimes off
static inline f32 fn_1_1FC98_read_z(struct fn_1_1FC98_vec * owner) { return owner->z; }
static inline f32 fn_1_1FC98_read_y(struct fn_1_1FC98_vec * owner) { return owner->y; }
#pragma opt_strength_reduction on
u32 fn_1_1FC98(s8 arg0, s16 arg1) {
    u32 v3;
    s32 v2;
    struct fn_1_1FC98_elem *v1;
    s32 v0;
    u32 v5 = arg0;
    struct fn_1_1FC98_vec v4;
    u32 v6 = arg1;
    s16 tmp_ra2;
    struct fn_1_1FC98_mgr *mgr;
    u32 lab_v;

    mgr = lbl_1_bss_3BE0;
    v0 = mgr->unk_94;
    v1 = mgr->unk_98;
    v3 = 0;
    v2 = 0;
    while (v2 < v0) {
        if (v1->unk_20 & v6) {
            lbl_8006D7DC(v1);
    lab_v = v1->unk_10;
            tmp_ra2 = lab_v;
            (void) tmp_ra2;  /* fzgx: keeps the web at its definition */
            if (tmp_ra2 != 0) {
                mathutil_mtxA_rotate_z(lab_v);
            }
            if (v1->unk_E != 0) {
                mathutil_mtxA_rotate_y(v1->unk_E);
            }
            if (v1->unk_C != 0) {
                mathutil_mtxA_rotate_x(v1->unk_C);
            }
            fn_8006E250(arg0, &v4);
            if (__fabsf(v4.x) <= v1->unk_14 * 5.0f) {
                if (__fabsf(fn_1_1FC98_read_y(&v4)) <= v1->unk_18 * 5.0f) {
                    if (__fabsf(fn_1_1FC98_read_z(&v4)) <= v1->unk_1C * 5.0f) {
                        v3 = ((v3) | (v1->unk_20));
                    }
                }
            }
        }
        v2++;
        v1++;
    }
    return v3;
}
#pragma opt_strength_reduction reset
#pragma opt_lifetimes reset
