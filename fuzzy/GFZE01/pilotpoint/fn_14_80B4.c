/* Non-matching: best partial attempt (97.96% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
typedef struct {
    u8 pad_0[0x340];
    void *unk_340;
    void *unk_344;
    u8 pad_348[0x18];
} Sig_fn_1_14DC68_fn_1_14DC68_StaticDispEntry;
typedef struct {
    s32 active;
    s32 entries[5];
} Sig_fn_1_8F494_Fn1_8F494_Object;
struct fn_14_80B4_lbl_14_data_0 {
    u8 pad_0[0x2F48];
    u32 unk_2F48;
    u8 pad_2F4C[0x64];
    char name[0xD];
};
struct fn_14_80B4_lbl_14_bss_0 {
    u8 pad_0[0x1C];
    u32 unk_1C;
    u32 unk_20;
    u8 pad_24[0x13C];
    s16 unk_160;
    s16 unk_162;
    s16 unk_164;
};
struct fn_14_80B4_lbl_801A6410 { u32 unk_0; };
extern s32 fn_1_12C710(int);
extern s32 fn_1_12CB04(s32);
extern struct fn_14_80B4_lbl_14_bss_0 lbl_14_bss_0;
extern struct fn_14_80B4_lbl_14_data_0 lbl_14_data_0;
extern struct fn_14_80B4_lbl_801A6410 lbl_801A6410;
extern u32 fn_1_426C(u32);
extern void *fn_1_435C(void *);
extern void fn_14_2AFC(void);
extern void fn_1_12C000(void *, s16);
extern void fn_1_14DC68(Sig_fn_1_14DC68_fn_1_14DC68_StaticDispEntry *, s16);
extern void fn_1_46B4(u32, u32, const char *, int);
extern void fn_1_8F494(Sig_fn_1_8F494_Fn1_8F494_Object *);
void fn_14_80B4(u32 arg0) {
    struct fn_14_80B4_lbl_14_data_0 *p_lbl_14_data_0;
    struct fn_14_80B4_lbl_14_bss_0 *p_lbl_14_bss_0;
    u32 v0;
    void *v1;
    struct { s32 value; } v2;
    void *v3;
    u32 v4;
    u32 v5;
    s32 v6;
    s32 v7;
    s32 v8;
    struct { u32 value; } v9;
    s32 v11;
    struct { s32 value; } t7;
    u32 tmp_call1;
    void * lab_t0;
    p_lbl_14_bss_0 = &lbl_14_bss_0;
    p_lbl_14_data_0 = &lbl_14_data_0;
    v0 = (u32)p_lbl_14_bss_0 + 0x10000;
    if ((s32)p_lbl_14_data_0->unk_2F48 != -1) {
        lab_t0 = (void *)p_lbl_14_bss_0->unk_20;
        fn_1_435C(lab_t0);
        tmp_call1 = fn_1_426C(p_lbl_14_data_0->unk_2F48);
        tmp_call1;
        p_lbl_14_data_0->unk_2F48 = -1;
    }
    v1 = (u8 *)p_lbl_14_data_0 + 12108;
    v2.value = 0;
    v3 = v1;
    while ((u32)(s16)v2.value < 6) {
        if ((s32)*(u32 *)v3 != -1) {
            lab_t0 = (void *)p_lbl_14_bss_0->unk_1C;
            fn_1_435C(lab_t0);
            fn_1_426C(*(u32 *)v3);
            *(u32 *)v3 = -1;
        }
        v3 = (u8 *)v3 + 4;
        v2.value++;
    }
    fn_1_14DC68((Sig_fn_1_14DC68_fn_1_14DC68_StaticDispEntry *)*(u32 *)(v0 - 31936), p_lbl_14_bss_0->unk_164);
    fn_1_14DC68((Sig_fn_1_14DC68_fn_1_14DC68_StaticDispEntry *)*(u32 *)(v0 - 31932), p_lbl_14_bss_0->unk_164);
    v4 = v0 - 31916;
    v5 = v4;
    v6 = 0;
    while ((s16)v6 < 3) {
        fn_1_8F494((Sig_fn_1_8F494_Fn1_8F494_Object *)v5);
        v5 += 1248;
        v6++;
    }
{
    s32 fzgx_loop_v7_2398;
    v8 = 0;
    fzgx_loop_v7_2398 = 0;
    while ((s16)v8 < p_lbl_14_bss_0->unk_162) {
        v9.value = *(u32 *)(v0 - 31920) + fzgx_loop_v7_2398;
        t7.value = fn_1_12C710(*(u32 *)(v9.value + 136));
        fn_1_8F494((Sig_fn_1_8F494_Fn1_8F494_Object *)v9.value);
{
    s32 v10;
        v10 = 0;
        v11 = 0;
        while ((s16)v10 < (s16)fn_1_12CB04(t7.value)) {
            fn_1_8F494((Sig_fn_1_8F494_Fn1_8F494_Object *)(((((v11) + (((*(u32 *)(v0 - 31920))) + (fzgx_loop_v7_2398)))) + (1248))));
            v11 += 1248;
            v10++;
}
        }
        fzgx_loop_v7_2398 += 3744;
        v8++;
    }
    v7 = fzgx_loop_v7_2398;
}
    fn_1_12C000((void *)*(u32 *)(v0 - 31928), (s16)(p_lbl_14_bss_0->unk_160 * 3));
    fn_1_12C000((void *)*(u32 *)(v0 - 31924), p_lbl_14_bss_0->unk_162);
    fn_1_12C000((void *)(v0 - 28172), 1);
    fn_1_12C000((void *)(v0 - 28072), 1);
    fn_1_46B4(lbl_801A6410.unk_0, *(u32 *)(v0 - 31920), p_lbl_14_data_0->name, 2316);
    fn_1_46B4(lbl_801A6410.unk_0, *(u32 *)(v0 - 31924), p_lbl_14_data_0->name, 2318);
    fn_1_46B4(lbl_801A6410.unk_0, *(u32 *)(v0 - 31928), p_lbl_14_data_0->name, 2319);
    fn_1_46B4(lbl_801A6410.unk_0, *(u32 *)(v0 - 31936), p_lbl_14_data_0->name, 2320);
    fn_1_46B4(lbl_801A6410.unk_0, *(u32 *)(v0 - 31932), p_lbl_14_data_0->name, 2321);
    fn_14_2AFC();
}
