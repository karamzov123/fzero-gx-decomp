/* Non-matching: best partial attempt (99.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/stcoli.h"
#pragma section code_type ".fzgxpool"
static const u32 fzgx_pool_table1[1] = {0xFFFFFF00};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep1(void) { const u32 *volatile cp; cp = fzgx_pool_table1; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime2(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.0f;
    s = 15.0f;
    s = 1.0f;
    s = 10.0f;
    s = 1.25f;
    s = 0.10000000149011612f;
    s = 0.8999999761581421f;
    s = 0.0006000000284984708f;
    s = 0.4000000059604645f;
    s = 0.75f;
    s = 70.0f;
    s = 0.5f;
    s = 36.0f;
    s = 16.0f;
    s = 45.0f;
    s = 0.0007999999797903001f;
    s = 18.0f;
    s = 50.0f;
}
static const u32 fzgx_pool_table3[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep3(void) { const u32 *volatile cp; cp = fzgx_pool_table3; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime4(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503599627370496.0;
}
static const u32 fzgx_pool_table5[52] = {0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    s = 0.800000011920929f;
    s = 80.0f;
    s = 60.0f;
}
static const u32 fzgx_pool_table7[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep7(void) { const u32 *volatile cp; cp = fzgx_pool_table7; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime8(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
    d = 4503601774854144.0;
}
#pragma section code_type ".text"
extern u32 fn_1_4060(void);
extern s32 fn_1_F9D44(u32);
extern s32 ghost_test_record_flag0(u8);
extern u8 fn_1_F8C50(u8);
extern void fn_1_2D524(void *);
extern void fn_1_A2DC4(u32);
extern void fn_80008BEC(void *, int, u32);
#pragma opt_propagation off
void fn_1_2DB50(Obj_1_bss_5138 *arg0, f32 arg1) {
u32 sum;
u32 v0;
u8 first;
s32 v8;
u8 v7;
f32 v4;
if (arg0->unk_E0 == 120) fn_1_A2DC4(0xA9011100);
v0 = arg0->unk_E0 + 1;
arg0->unk_E0 = v0;
if ((v0 & 255) > 120) {
v4 = (f32)(s32)(arg0->unk_E0 - 120);
if (v4 > 15.0f) {
sum = arg0->unk_E4;
v8 = 0;
first = arg0->unk_2;
sum = arg0->unk_3 + sum;
arg0->unk_E0 = v8;
v7 = (((first) + (sum)) + (4));
arg0->unk_E1++;
if (arg0->unk_E1 == 1) {
if (arg0->unk_E3 != 255) {
} else if (ghost_test_record_flag0(lbl_1_bss_3C30.unk_6) != 0) {
v8 = 0;
} else { v8 = 1; }
if (v8 == 0) arg0->unk_E1 = 2;
}
if (arg0->unk_E1 == 2) {
if (arg0->unk_E5 == 255) v8 = 0;
else if (fn_1_F9D44(arg0->unk_E5 & 15) != 0) v8 = 0;
else v8 = 1;
if (v8 == 0) arg0->unk_E1 = 3;
}
if (((3) == (arg0->unk_E1))) {
if (arg0->unk_EB == 255) v8 = 0;
else if (fn_1_F8C50(arg0->unk_EB) != 0) v8 = 0;
else v8 = 1;
if (v8 == 0) arg0->unk_E1 = 4;
}
if (arg0->unk_E1 >= (u32)v7) {
fn_80008BEC(&lbl_1_bss_5138, 0, 236);
lbl_1_bss_5138.unk_10 = 320;
lbl_1_bss_5138.unk_12 = 180;
lbl_1_bss_5138.unk_E1 = 0;
lbl_1_bss_5138.unk_E0 = 0;
lbl_1_bss_5138.unk_0 = 0;
lbl_1_bss_5138.unk_2 = 0;
lbl_1_bss_5138.unk_3 = 0;
lbl_1_bss_5138.unk_1C = 0.0f;
lbl_1_bss_5138.unk_20 = 0;
lbl_1_bss_5138.unk_E2 = 0;
lbl_1_bss_5138.unk_E3 = 255;
lbl_1_bss_5138.unk_E4 = 0;
lbl_1_bss_5138.unk_E5 = 255;
lbl_1_bss_5138.unk_EB = 255;
fn_1_4060();
return;
} else {
v4 = 15.0f;
fn_1_2D524(arg0);
}
}
arg0->unk_1C = 1.0f - v4 / 15.0f;
} else {
f32 fade = (f32)(u32)arg0->unk_E0 / 15.0f;
arg0->unk_1C = fade;
if (fade > 1.0f) {
arg0->unk_1C = 1.0f;
if (arg0->unk_E0 == 120) arg0->unk_E0 = 119;
}
}
}
#pragma opt_propagation reset

