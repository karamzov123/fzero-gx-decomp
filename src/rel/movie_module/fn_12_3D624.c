#include "types.h"
static const char version[] = "\nCRI CFT/GC Ver.1.29 Build:May  9 2003 15:17:25\n";
#pragma section code_type ".fzgxpool"
void fzgx_fn_12_3D624_pool_primer(volatile f32 *p) {  /* fzgx-allow: S2 volatile keeps the verified access order */
 p[0] = 0.5f;
 p[1] = 2.017f;
 p[2] = -0.392f;
 p[3] = 0.0f;
 p[4] = -0.813f;
 p[5] = 1.596f;
 p[6] = 1.164f;
 p[7] = 127.0f;
 p[8] = 278.696f;
 p[9] = 255.0f;
}
#pragma section code_type ".text"
extern u32 lbl_12_data_E98[2];
f32 lbl_12_bss_1CC80[256];
f32 lbl_12_bss_1CC80_400[256];
f32 lbl_12_bss_1CC80_800[256];
f32 lbl_12_bss_1CC80_C00[256];
f32 lbl_12_bss_1CC80_1000[256];
u32 lbl_12_bss_1CC80_1400[2];
f32 lbl_12_bss_1E088;
u32 lbl_12_bss_1E088_fill_1E08C[212];

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; /* fzgx-allow: S2 layout primer sink: MWCC emits .bss objects in first-access order */
    s = *(u8 *)&lbl_12_bss_1CC80;
    s = *(u8 *)&lbl_12_bss_1CC80_400;
    s = *(u8 *)&lbl_12_bss_1CC80_800;
    s = *(u8 *)&lbl_12_bss_1CC80_C00;
    s = *(u8 *)&lbl_12_bss_1CC80_1000;
    s = *(u8 *)&lbl_12_bss_1CC80_1400;
    s = *(u8 *)&lbl_12_bss_1E088;
    s = *(u8 *)&lbl_12_bss_1E088_fill_1E08C;
}
#pragma section code_type ".text"

#pragma opt_dead_assignments off
static inline void initialize_tables(f32 scale) {
 u32 i;
 f32 y;
 f32 *a = lbl_12_bss_1CC80_1000;
 f32 *b = lbl_12_bss_1CC80_C00;
 f32 *c = lbl_12_bss_1CC80_800;
 f32 *d = lbl_12_bss_1CC80;
#pragma opt_unroll_loops off
 lbl_12_bss_1CC80_1400[0] = (*((lbl_12_data_E98) + (0)));
 for (i=0;i<256;i++) {
 y = scale * (f32)(s32)(i-16);
 a[i] = y;
 b[i] = -0.392f * (f32)(s32)(i-128);
 c[i] = 2.017f * (f32)(s32)(i-128);
 d[i] = 1.596f * (f32)(s32)(i-128);
{
 f32 *e = lbl_12_bss_1CC80_400;
 e[i] = -0.813f * (f32)(s32)(i-128);
}
 }
}
#pragma opt_dead_assignments reset
#pragma opt_dead_assignments off
void fn_12_3D624(void) {
 initialize_tables(1.164f);
}
#pragma opt_dead_assignments reset


