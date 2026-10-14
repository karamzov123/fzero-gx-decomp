/* Non-matching: best partial attempt (94.27% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#pragma section code_type ".fzgxpool"
__declspec(section ".fzgxpool") static void fzgx_pool_prime1(void) {
    volatile f64 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.0f;
    s = 0.0f;
    s = 0.10000000149011612f;
}
static const u32 fzgx_pool_table2[19] = {0x3F800000, 0x3F800000, 0x00000000, 0x00000000, 0x3F800000, 0x3F800000, 0x00000000, 0x3F800000, 0x00000005, 0x00000000, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep2(void) { const u32 *volatile cp; cp = fzgx_pool_table2; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime3(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 1.0f;
    d = 4503599627370496.0f;
    s = 55.0f;
}
static const u32 fzgx_pool_table4[1] = {0x3DCCCCCD};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep4(void) { const u32 *volatile cp; cp = fzgx_pool_table4; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime5(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 90000.0f;
    s = 480.0f;
    s = 640.0f;
}
static const u32 fzgx_pool_table6[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep6(void) { const u32 *volatile cp; cp = fzgx_pool_table6; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime7(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0f;
    d = 0.5f;
    s = 0.75f;
}
static const u32 fzgx_pool_table8[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep8(void) { const u32 *volatile cp; cp = fzgx_pool_table8; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime9(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 0.002405626f;
    s = 320.0f;
    s = 240.0f;
    s = 255.0f;
    s = 0.5f;
    s = 2.0f;
    s = 4.0f;
}
static const u32 fzgx_pool_table10[31] = {0x00000000, 0x40000000, 0x40000000, 0x00000000, 0x3F800000, 0x3F800000, 0x9B000000, 0x40000000, 0x40000000, 0x9B000000, 0x3F800000, 0x3F800000, 0x0000FF00, 0x40000000, 0x40000000, 0x0000FF00, 0x3F800000, 0x3F800000, 0xFFF20000, 0x3F800000, 0x3F800000, 0xFF800000, 0x3F800000, 0x3F800000, 0x00008000, 0x40000000, 0x40000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep10(void) { const u32 *volatile cp; cp = fzgx_pool_table10; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime11(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.125f;
}
static const u32 fzgx_pool_table12[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep12(void) { const u32 *volatile cp; cp = fzgx_pool_table12; }  /* fzgx-allow: S2 pool primer sink */
static const u32 fzgx_pool_table13[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep13(void) { const u32 *volatile cp; cp = fzgx_pool_table13; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime14(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 65536.0f;
    s = 80.0f;
}
#pragma section code_type ".text"

extern u32 lbl_801A66A0;
extern f32 lbl_8006D188(s16);

static inline const u32 fn_1_53830_array_read(s32 index, const u32 *array) { return array[index]; }
#pragma opt_dead_assignments off
#pragma opt_common_subs off
void fn_1_53830(u32 divisor, u32 mask, f32 t, u8 *out_a, u8 *out_b)
{
    s32 tmp_call2;
    u32 total = lbl_801A66A0;
    u32 rem = total % divisor;

    if (rem < (divisor >> 1)) {
        f32 frac = lbl_8006D188((s16)(65536.0f * (f32)rem / (f32)divisor));
        u32 v = (u8)((f32)(mask & 0xFF) * frac);

        out_a[2] = v;
        out_a[1] = v;
        out_a[0] = v;
        out_a[3] = 0;
        *(u32 *)out_a = fn_1_53830_array_read(0, fzgx_pool_table12);
    } else {
        f32 frac = lbl_8006D188((s16)(65536.0f * (f32)rem / (f32)divisor));
        f32 p = (1.0f - t) * frac;
        u32 v = (u8)(255.0f * (p + 1.0f));

        out_b[2] = v;
        out_b[1] = v;
        out_b[0] = v;
        out_b[3] = 0;
        tmp_call2 = fn_1_53830_array_read(0, fzgx_pool_table13);
        *(u32 *)out_b = tmp_call2;
    }
}
#pragma opt_common_subs reset

#pragma opt_dead_assignments reset

