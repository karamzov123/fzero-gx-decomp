/* Non-matching: best partial attempt (98.55% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[3] = {0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.10000000149011612f;
    s = 1.0f;
}
static const u32 fzgx_pool_table3[61] = {0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x3DCCCCCD, 0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x04000000, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 0.9583333134651184f;
    s = 23.0f;
    s = 2.0f;
    s = 0.6666666865348816f;
    s = 0.5f;
    s = 0.5833333134651184f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

struct fn_1_1421D8_lbl_1_bss_3C30 {
    u8 pad_0[0x6];
    u8 unk_6;
};
struct fn_1_1421D8_lbl_1_data_2B0D4 {
    u8 unk_0[1];
};
struct fn_1_1421D8_lbl_1_data_2AA24 {
    s32 unk_0[1];
};

extern f32 fn_1_4B068(s32);
extern struct fn_1_1421D8_lbl_1_data_2AA24 lbl_1_data_2AA24;
extern struct fn_1_1421D8_lbl_1_data_2B0D4 lbl_1_data_2B0D4;
extern u32 fn_1_5233C(void *, void *);
extern u32 lbl_1_data_2BD54;
extern u8 lbl_1_data_42478;
extern s16 lbl_1_data_4247C;
extern u32 lbl_801A66B4;
extern void fn_1_13D460(s32, s32, s32, s32);
extern void fn_1_49410(void);
extern void fn_1_494DC(s16);
extern void fn_1_4955C(f32, f32);
extern void fn_1_49590(f32);
extern void fn_1_495B0(u32);
extern void fn_1_495C8(void *);
extern void fn_1_4966C(f32, f32);
extern void fn_1_496FC(f32, f32);
extern void fn_1_49738(void *);
extern void fn_1_49748(f32);
extern void fn_1_4A0D8(const char *);
extern void fn_1_4AE0C(const char *, ...);

#pragma opt_dead_assignments off
#pragma opt_lifetimes off
typedef struct lbl_1_bss_3C30_t {
    u8 pad_0[0x6];
    u8 unk_6;
    u8 pad_7[0x14b5];
} lbl_1_bss_3C30_t;

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
lbl_1_bss_3C30_t lbl_1_bss_3C30;
u32 fzgx_obj_lbl_1_bss_50EC[5];
u32 fzgx_obj_lbl_1_bss_5100;
u32 fzgx_obj_lbl_1_bss_5104[13];
u32 fzgx_obj_lbl_1_bss_5138[65];
u32 lbl_1_bss_523C[8];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_1_bss_3C30;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_50EC;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5100;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5104;
    s = *(u8 *)&fzgx_obj_lbl_1_bss_5138;
    s = *(u8 *)&lbl_1_bss_523C;
}
#pragma section code_type ".text"

#pragma opt_strength_reduction off
#pragma opt_loop_invariants off
s16 fn_1_1421D8(u32 arg0, u32 arg1) {
    s32 v19;
    s32 v14;
    s32 v9;
    u32 v8;
    s32 v3;
    u32 v2;
    u8 * fzgx_live;
    f32 lab_t0;
    s16 lab_t0_;
    fn_1_49410();
    lab_t0_ = 8;
    fn_1_494DC(lab_t0_);
    fn_1_495B0(0x80000000);
    fn_1_49738((void *)fn_1_5233C);
    fn_1_49748(0.0f);
    fn_1_495C8((void *)8);
    fn_1_4955C(0.9583333134651184f, 0.9583333134651184f);
    fn_1_496FC((f32)(s32)arg0, (f32)(s32)arg1);
    fn_1_4AE0C((const char *)(u32)&lbl_1_data_42478);
    
    fzgx_live = lbl_1_data_2B0D4.unk_0;
    v2 = lbl_1_data_2AA24.unk_0[fzgx_live[lbl_1_bss_3C30.unk_6]];
    v3 = (s32)((f32)(s32)arg0 + 23.0f);
    fn_1_4966C(2.0f, 0.0f);
    fn_1_4955C(0.6666666865348816f, 0.6666666865348816f);
    fn_1_496FC((f32)(s32)v3, (f32)(s32)arg1);
    fn_1_495B0(0x80000000);
    lab_t0 = 0.5f;
    fn_1_49590(lab_t0);
    fn_1_4A0D8((const char *)v2);
    v9 = (s32)((f32)(s32)v3 + fn_1_4B068(v2)) + 14;
    v8 = *(u32 *)((u8 *)&lbl_1_data_2BD54 + (lbl_1_bss_3C30.unk_6 * 24) +
        (lbl_801A66B4 << 2));
    fn_1_494DC(42);
    fn_1_4966C(0.0f, 0.0f);
    fn_1_4955C(0.5833333134651184f, 0.5833333134651184f);
    fn_1_496FC((f32)(s32)v9, (f32)(s32)arg1);
    fn_1_495B0(0x80000000);
    lab_t0 = 0.5f;
    fn_1_49590(lab_t0);
    fn_1_4A0D8((const char *)v8);
    v14 = (s32)((f32)(s32)v9 + fn_1_4B068(v8));
    fn_1_494DC(8);
    fn_1_4955C(0.9583333134651184f, 0.9583333134651184f);
    fn_1_496FC((f32)(s32)v14, (f32)(s32)arg1);
    fn_1_4AE0C((const char *)(u32)&lbl_1_data_4247C);
    v19 = (s32)((f32)(s32)v14 + 23.0f);
    fn_1_13D460(v19, (arg1 + 8), (596 - v19), 0);
    return (u32)v19;
}
#pragma opt_loop_invariants reset

#pragma opt_strength_reduction reset

#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

