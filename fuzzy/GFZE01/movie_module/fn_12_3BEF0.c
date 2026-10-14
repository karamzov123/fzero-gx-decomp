/* Non-matching: best partial attempt (96.36% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[8] = {0x0A435249, 0x20434654, 0x2F474320, 0x5665722E, 0x312E3239, 0x20427569, 0x6C643A4D, 0x61792020};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.00015277485363185406f;
}
static const u32 fzgx_pool_table3[2] = {0x30332031, 0x353A3137};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0006798064569011331f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.5f;
    s = 2.0169999599456787f;
    s = -0.3919999897480011f;
    s = 0.0f;
    s = -0.8130000233650208f;
    s = 1.5959999561309814f;
    s = 1.1640000343322754f;
    s = 127.0f;
    s = 278.6960144042969f;
    s = 255.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
#pragma section code_type ".text"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

void fn_12_3BEF0(s32 flag, s32 a, s32 b, Vec4 *p0) {
    s32 j;
    s32 i;
    Vec4 *p2 = (Vec4 *)((u8 *)p0 + 0x2000);
    Vec4 *p1 = (Vec4 *)((u8 *)p0 + 0x1000);
    f32 inv;
    f32 v;

    for (i = 0; i < 0x100; i++) {
        v = (f32)(i - 16) * 1.164f + 0.5f;
        p0[i].w = v;
        p0[i].z = v;
        p0[i].y = v;
        p1[i].w = (f32)(i - 128) * 2.017f + 0.5f;
        p1[i].z = (f32)(i - 128) * -0.392f + 0.5f;
        p1[i].y = 0.0f;
        p1[i].x = 0.0f;
        p2[i].w = 0.0f;
        p2[i].z = (f32)(i - 128) * -0.813f + 0.5f;
        p2[i].y = (f32)(i - 128) * 1.596f + 0.5f;
        p2[i].x = 0.0f;
    }

    inv = 255.0f / (f32)(b - a);

    if (flag == 1) {
        for (i = 0, j = 255; i < 0x100; i++, j--) {
            if (i < a) {
                p0[i].x = 255.0f;
            } else if (i > b) {
                p0[i].x = 0.0f;
            } else {
                p0[i].x = inv * (f32)(b - j);
            }
        }
    } else {
        for (i = 0; i < 0x100; i++) {
            if (i < a) {
                p0[i].x = 0.0f;
            } else if (i > b) {
                p0[i].x = 255.0f;
            } else {
                p0[i].x = inv * (f32)(i - a);
            }
        }
    }
}
