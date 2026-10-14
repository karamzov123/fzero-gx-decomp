/* Non-matching: best partial attempt (88.35% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/customize/emb_paste_editor.h"
typedef struct {
    u8 pad_0[0x340];
    void *unk_340;
    void *unk_344;
    u8 pad_348[0x18];
} Sig_fn_1_14DC68_fn_1_14DC68_StaticDispEntry;
typedef struct Sig_fn_1_7F3AC_CarFn_1_7F3AC {
    u8 pad_390[0x390];
    u32 field_390;
    u8 pad_394[0x10];
    u32 field_3A4;
} Sig_fn_1_7F3AC_CarFn_1_7F3AC;
typedef struct Sig_fn_1_A7728_FnA7728Resource {
    u8 pad_104[0x104];
    void *field_104;
    void *field_108;
} Sig_fn_1_A7728_FnA7728Resource;
typedef struct Sig_fn_1_A7728_FnA7728Object {
    u8 pad_394[0x394];
    Sig_fn_1_A7728_FnA7728Resource *field_394;
} Sig_fn_1_A7728_FnA7728Object;
struct fn_3_12B14_vec { u32 unk_0, unk_4, unk_8; };
extern struct fn_3_12B14_vec lbl_3_rodata_4C8;
extern struct fn_3_12B14_vec lbl_3_rodata_4D4;
extern u32 lbl_801A6410;
extern u32 camera_update_state(void *);
extern void *fn_1_435C(void *);
extern void fn_1_14DC68(Sig_fn_1_14DC68_fn_1_14DC68_StaticDispEntry *, s16);
extern void fn_1_7F3AC(Sig_fn_1_7F3AC_CarFn_1_7F3AC *);
extern void fn_1_426C(u32);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_80F1C(s32, Sig_fn_1_A7728_FnA7728Object *);
extern void fn_1_FC414(void *, void *);
extern void fn_1_FDFF4(void);
#pragma opt_dead_assignments on
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction on
#pragma peephole on
extern void OSReport(const char *, ...);
#pragma section code_type ".fzgxpool"
static void fzgx_string_layout(void) {
    /* fzgx-allow: S2 layout primer: MWCC emits string literals in first-use order; the section is dropped at integration */
    OSReport("emb_paste_editor.c");
}
#pragma section code_type ".text"

void fn_3_12B14(void) {
    s32 v17;
    u8 *p_lbl_3_data_32DC;
    u8 *p_data_copy;
    u32 v0;
    u32 *p_lbl_801A6410;
    s32 v15;
    u32 v4;
    u32 v6;
    u32 v10;
    void *v11;
    struct { s16 value; } v12;
    u32 v13;
    u32 v14;
    struct { u32 value; } v1;
    s32 v16;
    Obj_3_bss_7EDC0 *p_lbl_3_bss_7EDC0;
    u32 v18;
    u32 v19;
    s32 v20;
    s32 v21;
    u32 v22;
    volatile struct fn_3_12B14_vec loc_14, loc_8;
    p_lbl_3_bss_7EDC0 = &lbl_3_bss_7EDC0;
    v0 = (u32)p_lbl_3_bss_7EDC0 + 0x10000;
    v1.value = (u32)p_lbl_3_bss_7EDC0 + 0x20000;
    fn_1_FC414((void *)(v0 + 0x440), (void *)1);
    {
    u32 v2 = lbl_3_rodata_4C8.unk_0;
    u32 v3 = lbl_3_rodata_4C8.unk_4;
    u32 v5 = lbl_3_rodata_4C8.unk_8;
    u16 v7 = lbl_3_rodata_4D4.unk_0;
    u32 v8 = lbl_3_rodata_4D4.unk_4;
    u32 v9 = lbl_3_rodata_4D4.unk_8;
    v4 = v1.value + 0x880;
    v6 = v1.value + 0x8D0;
    *(u32 *)(v1.value + 0x908) = v2;
    *(u32 *)(v1.value + 0x90C) = v3;
    *(u32 *)(v1.value + 0x910) = v5;
    loc_14.unk_0 = v2;
    loc_14.unk_4 = v3;
    loc_14.unk_8 = v5;
    *(u32 *)(v1.value + 0x914) = v7;
    *(u32 *)(v1.value + 0x918) = v8;
    *(u32 *)(v1.value + 0x91C) = v9;
    loc_8.unk_0 = v7;
    loc_8.unk_4 = v8;
    loc_8.unk_8 = v9;
    *(u32 *)(v6 + 4) = v2;
    *(u32 *)(v6 + 8) = v3;
    *(u32 *)(v6 + 12) = v5;
    *(u32 *)(v4 + 4) = v2;
    *(u32 *)(v4 + 8) = v3;
    *(u32 *)(v4 + 12) = v5;
    *(u32 *)(v6 + 16) = v7;
    *(u32 *)(v6 + 20) = v8;
    *(u32 *)(v6 + 24) = v9;
    *(u32 *)(v4 + 16) = v7;
    *(u32 *)(v4 + 20) = v8;
    *(u32 *)(v4 + 24) = v9;
    }
    *(u16 *)(v4 + 32) = 0;
    camera_update_state((void *)v4);
    v10 = *(u32 *)((u8 *)p_lbl_3_bss_7EDC0 + 0xC);
    if ((*(u32 *)(v10 + 0x390) & 0x4000000) != 0) {
        fn_1_14DC68(*(Sig_fn_1_14DC68_fn_1_14DC68_StaticDispEntry **)(v10 + 0x3A0), 1);
        fn_1_7F3AC(*(Sig_fn_1_7F3AC_CarFn_1_7F3AC **)((u8 *)p_lbl_3_bss_7EDC0 + 0xC));
        fn_1_46B4(lbl_801A6410, *(u32 *)(*(u32 *)((u8 *)p_lbl_3_bss_7EDC0 + 0xC) + 0x3A0), (const char *)"emb_paste_editor.c", 0xB46);
        fn_1_46B4(lbl_801A6410, *(u32 *)((u8 *)p_lbl_3_bss_7EDC0 + 0xC), (const char *)"emb_paste_editor.c", 0xB47);
    } else {
        fn_1_7F3AC((Sig_fn_1_7F3AC_CarFn_1_7F3AC *)v10);
        fn_1_80F1C(*(s16 *)((u8 *)p_lbl_3_bss_7EDC0 + 24 + 68), *(Sig_fn_1_A7728_FnA7728Object **)((u8 *)p_lbl_3_bss_7EDC0 + 0xC));
        fn_1_46B4(lbl_801A6410, *(u32 *)((u8 *)p_lbl_3_bss_7EDC0 + 0xC), (const char *)"emb_paste_editor.c", 0xB4D);
    }
    v11 = (u8 *)p_lbl_3_bss_7EDC0 + 24;
    if (*(s16 *)((u8 *)v11 + 10) != -1) {
        fn_1_435C(*(void **)(((4) + ((u8 *)v11))));
        fn_1_426C(*(s16 *)((u8 *)v11 + 10));
        *(s16 *)((u8 *)v11 + 10) = -1;
    }
{
    u32 * fzgx_loop_p_lbl_801A6410_4256;
    u8 * fzgx_loop_p_lbl_3_data_32DC_4256;
    fzgx_loop_p_lbl_801A6410_4256 = &lbl_801A6410;
    fzgx_loop_p_lbl_3_data_32DC_4256 = (u8 *)"emb_paste_editor.c";
    p_data_copy = fzgx_loop_p_lbl_3_data_32DC_4256;
    v12.value = 0;
    while ((u32)(v12.value & 0xFF) < 2) {
        v13 = v0;
        v13 = v13 - 0x7DC0 + (v12.value & 0xFF) * 12;
        v14 = ((4) + (v13));
        fn_1_46B4(*fzgx_loop_p_lbl_801A6410_4256, *(u32 *)(((4) + (v13))), (const char *)fzgx_loop_p_lbl_3_data_32DC_4256, 0xB5A);
        v15 = v13 + 8;
        v16 = 0;
        while ((v16 & 0xFF) < *(u16 *)v13) {
            v17 = (v16 & 0xFF) << 2;
            v18 = *(u32 *)(*(u32 *)v15 + v17);
            if (v18 != 0) {
                fn_1_46B4(*fzgx_loop_p_lbl_801A6410_4256, v18, (const char *)fzgx_loop_p_lbl_3_data_32DC_4256, 0xB5F);
                *(u32 *)(*(u32 *)v15 + v17) = 0;
            }
            v16++;
        }
        fn_1_46B4(*fzgx_loop_p_lbl_801A6410_4256, *(u32 *)v15, (const char *)p_data_copy, 0xB63);
        v12.value = v12.value + 1;
        *(u32 *)v14 = 0;
        *(u32 *)v15 = 0;
    }
    p_lbl_801A6410 = fzgx_loop_p_lbl_801A6410_4256;
    p_lbl_3_data_32DC = fzgx_loop_p_lbl_3_data_32DC_4256;
}
    v19 = v0 - 0x7DC0;
    v20 = 0;
    while ((u32)(v20 & 0xFF) < 238) {
        v21 = (v20 & 0xFF) << 2;
        v22 = *(u32 *)(*(u32 *)(v19 + 32) + v21);
        if (v22 != 0) {
            if (*(u8 *)(*(u32 *)(v19 + 28) + (v20 & 0xFF)) != 0) {
                fn_1_46B4(lbl_801A6410, v22, (const char *)"emb_paste_editor.c", 0xB6C);
            }
        }
        v20++;
        *(u32 *)(*(u32 *)(v19 + 32) + v21) = 0;
    }
    fn_1_46B4(lbl_801A6410, *(u32 *)(v19 + 32), (const char *)"emb_paste_editor.c", 0xB71);
    fn_1_46B4(lbl_801A6410, *(u32 *)(v19 + 28), (const char *)"emb_paste_editor.c", 0xB72);
    *(u32 *)(v19 + 28) = 0;
    *(u32 *)(v19 + 32) = 0;
    *(u32 *)((u8 *)p_lbl_3_bss_7EDC0 + 0xC) = 0;
    p_lbl_3_bss_7EDC0->unk_8 = 0;
    *(u32 *)((u8 *)p_lbl_3_bss_7EDC0 + 0x10) = 0;
    fn_1_FDFF4();
}
#pragma peephole reset

#pragma opt_strength_reduction reset

#pragma opt_common_subs reset

#pragma opt_dead_assignments reset
