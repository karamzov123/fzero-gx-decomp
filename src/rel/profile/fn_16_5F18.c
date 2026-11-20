#include "types.h"

struct fn_16_5F18_lbl_1_bss_8B614 {
    u8 pad_0[0x30];
    s16 unk_30;
};

extern struct fn_16_5F18_lbl_1_bss_8B614 lbl_1_bss_8B614;
extern u32 lbl_801A66A0[];
extern u32 lbl_801A6D00[];
extern u32 fn_1_870BC(void *, u32, void *, u32, u32, f32);
extern u8 lbl_16_bss_220[];
extern u32 lbl_1_data_1E5C0;
extern u32 mathutil_mtxA_rotate_x(u32);
extern u32 mathutil_mtxA_rotate_y(u32);
extern void fn_1_F7870(u32);
extern void fn_8006F038(void *, void *, s16);
extern void fn_80072558(void);
extern void lbl_8006D758(void);
extern void lbl_8006DB74(void *);
extern void lbl_8006DCDC(void);
extern void lbl_8006DFE8(void *);
extern void lbl_8006E14C(f32);

#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 20.0f;
    s = 10.0f;
    s = 0.6000000238418579f;
    s = 456.0f;
    s = 0.125f;
    s = 5.0f;
    s = 1.4444444179534912f;
    s = 1.0f;
    s = 46.0f;
    s = 52.0f;
    s = 0.5f;
    s = 71.0f;
    s = 22.0f;
    s = 98.0f;
    s = 93.38823699951172f;
    s = 0.7686274647712708f;
    s = 0.0f;
    d = 4503601774854144.0;
}
static const u32 fzgx_pool_table3[2] = {0xFFFF0000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 32.0f;
    s = 28.0f;
    s = 69.0f;
    s = 338.0f;
    s = 504.0f;
    s = 24.0f;
    s = 8.0f;
    s = 0.7777777910232544f;
    s = 79.0f;
    s = 343.0f;
    s = 155.0f;
    s = 365.0f;
}
static const u32 fzgx_pool_table5[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 44.0f;
    s = 248.0f;
    s = 6.0f;
}
static const u32 fzgx_pool_table7[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 480.0f;
    s = 142.0f;
    s = 236.0f;
    s = 102.0f;
    s = 107.0f;
    s = 0.625f;
    s = 141.0f;
    s = 7.0f;
    s = 182.04444885253906f;
    s = 180.0f;
    s = 134.0f;
    s = 0.10000000149011612f;
    s = 0.7529411911964417f;
    s = 0.30000001192092896f;
    s = 360.0f;
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table9[1] = {0xFFFF0000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep9(void) { const u32 *volatile cp; cp = fzgx_pool_table9; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime10(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 19.0f;
    s = 17.0f;
    s = 75.0f;
    s = 92.0f;
}
static const u32 fzgx_pool_table11[7] = {0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep11(void) { const u32 *volatile cp; cp = fzgx_pool_table11; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime12(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.75f;
    s = 37.0f;
    s = 74.0f;
    s = 26.0f;
    s = 63.0f;
    s = 70.0f;
}
static const u32 fzgx_pool_table13[6] = {0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00, 0x00FFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 320.0f;
    s = 216.0f;
    s = 122.0f;
    s = 200.0f;
    s = 304.0f;
    s = 40.0f;
    s = 600.0f;
    s = 0.10000002384185791f;
    s = 0.3399999737739563f;
    s = -102.0f;
    s = 0.8999999761581421f;
    s = 0.6600000262260437f;
    s = 0.8888888955116272f;
    s = 95.0f;
    s = 2.0f;
    s = 47.0f;
}
#pragma section code_type ".text"
s32 fn_16_5F18(u32 arg0) {
    void * v6;

    fn_8006F038((void *)(arg0 + 16), (void *)(arg0 + 28), 0);
    lbl_8006DCDC();
    fn_1_F7870((u32)&lbl_1_data_1E5C0);
    lbl_8006D758();
    mathutil_mtxA_rotate_x((s32)(182.04444885253906f * (f32)*(s16 *)((u8 *)arg0 + 40)));
    mathutil_mtxA_rotate_y((s32)(182.04444885253906f * (lbl_801A66A0[0] % 360)));
    lbl_8006E14C(2.0f);
    lbl_8006DB74((void *)(lbl_801A6D00[0] + 96));
    lbl_8006DFE8((void *)(lbl_801A6D00[0] + 96));
    fn_80072558();
    v6 = (void *)((u8 *)&lbl_16_bss_220 + (*(s16 *)((u8 *)arg0 + 12) * 1088));
    fn_1_870BC(v6, 0, v6, 0, lbl_1_bss_8B614.unk_30 & 0xFF, 1.0f);
    return 0;
}
