/* Non-matching: best partial attempt (79.95% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/bg_common.h"

extern s32 fn_1_54E34(void *, f32);
extern void fn_1_F7870(void *);
extern void fn_1_556B8(void *);
extern u32 lbl_1_data_1E5C0[13];
extern void lbl_8006DCA4(void);
extern void lbl_8006E0A4(void *);
extern void mathutil_mtxA_rotate_z(s16);
extern void mathutil_mtxA_rotate_y(s16);
extern void mathutil_mtxA_rotate_x(s16);
extern void lbl_8006E14C(f32);
extern void lbl_8006DFC4(void *);
extern u8 *fn_80083970(u8 *, const u8 *);
extern void fn_80072558(void);

typedef struct {
    u8 unk_0[0x34];
    u8 unk_34[0x768];
    u32 unk_79c[0xC4];
    u32 unk_aac[0x158];
    u8 unk_100c[0xC];
    u8 unk_1018[0x100];
} Data_1_3F510;

typedef struct {
    u8 pad_0[0xA0];
    s16 rot_y;
    s16 rot_x;
    s16 rot_z;
    u8 pad_A6[2];
    u8 unk_A8[0x10];
    f32 unk_B8;
    u8 pad_BC[0x94];
    u32 unk_150;
} Mgr_1;

#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_strength_reduction off
#pragma opt_if_conversion off
void fn_1_107F74(void *arg0, int arg1) {
    u32 d = (u32)lbl_1_data_3F510;
    if (arg0 != 0) {
        u32 i;
        Obj_1_bss_86ED0 *p = &lbl_1_bss_86ED0;
        u8 *t;
        s32 flag;
        for (i = 0; i < 0x46; i++, p = (Obj_1_bss_86ED0 *)((u8 *)p + 0x68)) {
            if (p != 0 && p->unk_C == (u32)arg0) {
                t = (u8 *)(*(u32 *)((u8 *)((Mgr_1 *)arg0)->unk_150 + 8)
                        + ((u32 *)(d + 0xaac))[p->unk_8] * 0x18c);
                lbl_8006DCA4();
                lbl_8006E0A4(((Mgr_1 *)arg0)->unk_A8);
                mathutil_mtxA_rotate_z(((Mgr_1 *)arg0)->rot_z);
                mathutil_mtxA_rotate_y(((Mgr_1 *)arg0)->rot_y);
                mathutil_mtxA_rotate_x(((Mgr_1 *)arg0)->rot_x);
                lbl_8006E14C(((Mgr_1 *)arg0)->unk_B8);
                lbl_8006DFC4(t + 0x88);
                if (fn_1_54E34((u8 *)p->unk_10 + 8,
                        *(f32 *)((u8 *)p->unk_10 + 0x14)) != 0) {
                    flag = 1;
                } else {
                    flag = 0;
                }
                if (arg1 != 0 && !flag) {
                    continue;
                }
                if (p->unk_10 == 0) {
                    continue;
                }
                if (*(s16 *)&lbl_1_bss_960 != 4) {
                    if (fn_80083970((u8 *)((u32 *)(d + 0x79c))[p->unk_8], (u8 *)(d + 0x100c)) != 0) {
                        fn_1_F7870((void *)(d + 0x34));
                    } else if (fn_80083970((u8 *)((u32 *)(d + 0x79c))[p->unk_8], (u8 *)(d + 0x1018)) != 0) {
                        fn_1_F7870((void *)(d + 0));
                    }
                }
                fn_80072558();
                fn_1_556B8((void *)p->unk_10);
                if (*(s16 *)&lbl_1_bss_960 != 4) {
                    if (fn_80083970((u8 *)((u32 *)(d + 0x79c))[p->unk_8], (u8 *)(d + 0x1018)) != 0) {
                        fn_1_F7870(&lbl_1_data_1E5C0[0]);
                    }
                }
            }
        }
    }
}
#pragma opt_common_subs reset
