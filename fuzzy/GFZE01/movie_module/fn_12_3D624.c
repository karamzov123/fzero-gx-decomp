/* Non-matching: best partial attempt (88.24% in the project ledger). Scored for the
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
    s = 0.0f;
    s = 0.5f;
    s = 2.0169999599456787f;
    s = -0.3919999897480011f;
}
static const u32 fzgx_pool_table5[1] = {0x00000000};  /* fzgx-allow: A1 retail pool bytes */
__declspec(section ".fzgxpool") static void fzgx_pool_keep5(void) { const u32 *volatile cp; cp = fzgx_pool_table5; }  /* fzgx-allow: S2 pool primer sink */
__declspec(section ".fzgxpool") static void fzgx_pool_prime6(void) {
    volatile f32 s; volatile f64 d;  /* fzgx-allow: S2 pool primer sinks */
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
extern u32 lbl_12_data_E98[2];
#pragma optimization_level 4
#pragma opt_unroll_loops off
#pragma opt_propagation on
/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
u8 lbl_12_bss_1CC80;
u8 lbl_12_bss_1CC80__fzgx_offset_1;
u16 lbl_12_bss_1CC80__fzgx_offset_2;
u32 lbl_12_bss_1CC80__fzgx_offset_4[63];
u8 lbl_12_bss_1CC80__fzgx_offset_100;
u8 lbl_12_bss_1CC80__fzgx_offset_101;
u16 lbl_12_bss_1CC80__fzgx_offset_102;
u32 lbl_12_bss_1CC80__fzgx_offset_104[63];
u8 lbl_12_bss_1CC80__fzgx_offset_200;
u8 lbl_12_bss_1CC80__fzgx_offset_201;
u16 lbl_12_bss_1CC80__fzgx_offset_202;
u32 lbl_12_bss_1CC80__fzgx_offset_204[63];
u8 lbl_12_bss_1CC80__fzgx_offset_300;
u8 lbl_12_bss_1CC80__fzgx_offset_301;
u16 lbl_12_bss_1CC80__fzgx_offset_302;
u32 lbl_12_bss_1CC80__fzgx_offset_304[63];
u8 lbl_12_bss_1CC80__fzgx_offset_400;
u8 lbl_12_bss_1CC80__fzgx_offset_401;
u16 lbl_12_bss_1CC80__fzgx_offset_402;
u32 lbl_12_bss_1CC80__fzgx_offset_404[63];
u8 lbl_12_bss_1CC80__fzgx_offset_500;
u8 lbl_12_bss_1CC80__fzgx_offset_501;
u16 lbl_12_bss_1CC80__fzgx_offset_502;
u32 lbl_12_bss_1CC80__fzgx_offset_504[961];
f32 lbl_12_bss_1E088;
u32 lbl_12_bss_1E088__fzgx_offset_4[212];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s;  /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_1CC80;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_1;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_2;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_4;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_100;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_101;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_102;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_104;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_200;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_201;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_202;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_204;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_300;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_301;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_302;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_304;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_400;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_401;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_402;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_404;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_500;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_501;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_502;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_504;
    s = *(u8 *)&lbl_12_bss_1E088;
    s = *(u8 *)&lbl_12_bss_1E088__fzgx_offset_4;
}
#pragma section code_type ".text"

static inline u32 fn_12_3D624_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_dead_assignments off
#pragma opt_lifetimes off
void fn_12_3D624(void) {
    s32 i;
    f32 y;
    f32 *ytable;
    f32 *gutable;
    f32 *butable;
    f32 *rvtable;
    f32 *gvtable;
    *(u32 *)(f32 *)&lbl_12_bss_1CC80__fzgx_offset_500 = fn_12_3D624_array_read(lbl_12_data_E98, 0);
    ytable = (f32 *)&lbl_12_bss_1CC80__fzgx_offset_400;
    gutable = (f32 *)&lbl_12_bss_1CC80__fzgx_offset_300;
    butable = (f32 *)&lbl_12_bss_1CC80__fzgx_offset_200;
    rvtable = (f32 *)&lbl_12_bss_1CC80;
    gvtable = (f32 *)&lbl_12_bss_1CC80__fzgx_offset_100;
    {
    s32 fzgx_loop_i_5464;
for (fzgx_loop_i_5464 = 0; fzgx_loop_i_5464 < 256; fzgx_loop_i_5464++) {
        f32 *yslot = &ytable[fzgx_loop_i_5464];
        y = 1.164f * (f32)(fzgx_loop_i_5464 - 16);
        gutable[fzgx_loop_i_5464] = -0.392f * (f32)(fzgx_loop_i_5464 - 128);
        butable[fzgx_loop_i_5464] = 2.017f * (f32)(fzgx_loop_i_5464 - 128);
        ytable[fzgx_loop_i_5464] = y;
        rvtable[fzgx_loop_i_5464] = 1.596f * (f32)(fzgx_loop_i_5464 - 128);
        gvtable[fzgx_loop_i_5464] = -0.813f * (f32)(fzgx_loop_i_5464 - 128);
    }
    i = fzgx_loop_i_5464;
}
}
#pragma opt_lifetimes reset

#pragma opt_dead_assignments reset

