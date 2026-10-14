/* Non-matching: best partial attempt (96.39% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/bg_cas.h"
struct fn_1_FD844_Arg1 { u32 unk_0; };
struct fn_1_FD844_lbl_1_rodata_7600 {
    f32 unk_0;
    f32 unk_4;
    u8 pad_8[4];
    f32 unk_C;
    u8 pad_10[0x2C];
    u32 unk_40;
    u32 unk_3C;
    u32 unk_44;
};
typedef struct { u32 a[3]; } FDVec;
typedef struct { u8 pad[0x344]; u32 unk_344[7]; } FDSelection;
extern struct fn_1_FD844_lbl_1_rodata_7600 lbl_1_rodata_7600;
extern u32 fn_1_FC760(void *, void *);
extern void mathutil_mtxA_rotate_x(s32);
extern void mathutil_mtxA_rotate_y(s32);
extern void fn_8006F1F0(void *, void *, void *);
extern void lbl_8006DB74(void *);
extern void GXInitTexObj(void *, void *, u16, u16, int, int, int, u8);
extern void GXInitTexObjLOD(void *, int, int, f32, f32, f32, u8, u8, int);
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
static inline f32 fn_1_FD844_read_pointer(struct fn_1_FD844_lbl_1_rodata_7600 * owner) { return owner->unk_0; }
#pragma opt_dead_assignments off
#pragma opt_common_subs on
#pragma opt_strength_reduction off
s32 fn_1_FD844(s32 arg0, struct fn_1_FD844_Arg1 *arg1, f32 arg2) {
    struct fn_1_FD844_lbl_1_rodata_7600 *p_lbl_1_rodata_7600;
    void *v7;
    u8 v3;
    u16 v5;
    u32 v0;
    void *v13;
    u8 v14;
    void *v15;
    FDVec loc_20;
    FDVec loc_14;
    FDVec loc_8;
    u32 v6;
    v0 = (*(u32 volatile *)&(arg1->unk_0)) /* Retail reloads this field. */;
    p_lbl_1_rodata_7600 = &lbl_1_rodata_7600;
    if (arg0 == 0) return 0;
    if (arg1 == 0) return 0;
    if (v0 == 0) return 0;
    if ((*(u32 *)(v0 + 0x390) & 0x4000000) != 0) {
        for (v3 = 0; v3 < 3; v3++) {
            u32 v4 = *(u32 *)(v0 + 0x3a0);
            if (!v4) return 0;
            if (!((FDSelection *)v4)[v3].unk_344[*(s16 *)(v0 + 0x3ba)]) return 0;
        }
    } else {
        if (!*(u32 *)((((v0)) + (0x338)) + (*(s16 *)(((0x3ba) + (v0))) * 12))) return 0;
    }
    {
    u8 fzgx_loop_v5_1752;
for (fzgx_loop_v5_1752 = 0; fzgx_loop_v5_1752 < *(u8 *)((u8 *)arg1 + 4); fzgx_loop_v5_1752++) {
        v6 = ((fzgx_loop_v5_1752 * 0x2060) + (arg0));
        if (!(*(u32 *)(v6 + 0x24) & 0x80000000)) {
            *(u32 *)((u8 *)arg1 + fzgx_loop_v5_1752 * 0x4100 + 0x4110) = 0;
        } else {
            f32 v8 = fn_1_FD844_read_pointer(p_lbl_1_rodata_7600);
            f32 v2 = (*(f32 volatile *)&(p_lbl_1_rodata_7600->unk_0)) /* Retail reloads this field. */;
            void *v16 = (u8 *)v6 + 0x20;
            v7 = (u8 *)arg1 + fzgx_loop_v5_1752 * 0x4100;
            *(u32 *)((u8 *)v7 + 0x410c) = (*(u32 volatile *)&(arg1->unk_0)) /* Retail reloads this field. */;
            loc_8.a[0] = p_lbl_1_rodata_7600->unk_40;
            loc_8.a[1] = p_lbl_1_rodata_7600->unk_3C;
            loc_8.a[2] = p_lbl_1_rodata_7600->unk_44;
            loc_14 = *(FDVec *)(v6 + 0x48);
            loc_20 = *(FDVec *)(v6 + 0x54);
            lbl_1_bss_850D4 = v2;
            lbl_1_bss_850D8 = v8;
            *(u32 *)(((0x4110) + ((u8 *)v7))) = v6 + 0x20;
            *(u32 *)((u8 *)v7 + 0x4114) = ((0x81a4) + ((arg0) + ((*(s16 *)(v6 + 0x20) << 3))));
            *(f32 *)((u8 *)v7 + 0x4104) = *(f32 *)(*(u32 *)(((0x4110) + ((u8 *)v7))) + 0x40);
            *(f32 *)((u8 *)v7 + 0x4108) = *(f32 *)(*(u32 *)(((0x4110) + ((u8 *)v7))) + 0x44);
            fn_8006F1F0(&loc_14, &loc_8, &loc_20);
            mathutil_mtxA_rotate_x(*(s16 *)(*(u32 *)(((0x4110) + ((u8 *)v7))) + 8));
            mathutil_mtxA_rotate_y(*(s16 *)(*(u32 *)(((0x4110) + ((u8 *)v7))) + 10));
            lbl_8006DB74((u8 *)v7 + 0xc0);
            v13 = (u8 *)v7 + 0x40;
            GXInitTexObj(v13, (void *)(*(u32 *)(((0x4110) + ((u8 *)v7))) + 0x60), 64,64,5,0,0,0);
            GXInitTexObjLOD(v13,1,1,p_lbl_1_rodata_7600->unk_C,p_lbl_1_rodata_7600->unk_C,p_lbl_1_rodata_7600->unk_C,0,0,0);
        }
    }
    v5 = fzgx_loop_v5_1752;
}
    {
    u8 fzgx_loop_v14_3335;
for (fzgx_loop_v14_3335 = 0; fzgx_loop_v14_3335 < *(u8 *)((u8 *)arg1 + 4); fzgx_loop_v14_3335++) {
        u32 v1;
        if (!*(u32 *)((u8 *)arg1 + 0x10428)) break;
        v15 = (u8 *)arg1 + fzgx_loop_v14_3335 * 0x4100;
        v1 = *(u32 *)((u8 *)v15 + 0x4110);
        if (v1 && (*(u32 *)(v1 + 4) & 0x80000000)) {
            if (p_lbl_1_rodata_7600->unk_C == *(f32 *)(v1 + 0x40) || p_lbl_1_rodata_7600->unk_C == *(f32 *)(v1 + 0x44)) {
                *(u32 *)(v1 + 4) &= 0x7fffffff;
            } else fn_1_FC760(arg1, (u8 *)v15 + 0x20);
        }
    }
    v14 = fzgx_loop_v14_3335;
}
    return 1;
}
#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

#pragma opt_loop_invariants reset

#pragma opt_lifetimes reset
