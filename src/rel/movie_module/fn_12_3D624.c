#include "types.h"

extern u32 lbl_12_data_E98[];

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
f32 lbl_12_bss_1CC80[256];
f32 lbl_12_bss_1CC80__fzgx_offset_400[256];
f32 lbl_12_bss_1CC80__fzgx_offset_800[256];
f32 lbl_12_bss_1CC80__fzgx_offset_C00[256];
f32 lbl_12_bss_1CC80__fzgx_offset_1000[256];
u32 lbl_12_bss_1CC80__fzgx_offset_1400;

const char fzgx_pool_head[0x34] = "\nCRI CFT/GC Ver.1.29 Build:May  9 2003 15:17:25\n";

/* Literal-pool primer: fixes retail's first-use order of the TU's pooled constants.
 * Volatile stores preserve every literal in the pool rather than eliminating overwritten values. */
#pragma section RX ".fzgxpool"
__declspec(section ".fzgxpool") void fzgx_pool_primer(volatile f32 *p, s32 n) { /* volatile: retain literal-pool primer stores. */
    p[0] = 0.5f;
    p[0] = 2.017f;
    p[0] = -0.392f;
    p[0] = 0.0f;
    p[0] = -0.813f;
    p[0] = 1.596f;
    p[0] = 1.164f;
    p[0] = 127.0f;
    p[0] = 278.696f;
    p[0] = 255.0f;
    p[0] = (f32)n;
}

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; /* fzgx-allow: S2 BSS primer ordering */
    s = *(u8 *)&lbl_12_bss_1CC80;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_400;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_800;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_C00;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_1000;
    s = *(u8 *)&lbl_12_bss_1CC80__fzgx_offset_1400;
}
#pragma section code_type ".text"

/* Fills five 256-entry float tables with scaled (i - 16) and (i - 128) values for i = 0..255,
 * after copying the word at lbl_12_data_E98 to the word after them. */
#pragma opt_propagation off
void fn_12_3D624(void) {
    s32 i;
    f32 y;
    f32 *p4;
    f32 *p3;
    f32 *p2;
    f32 *p0;
    f32 *p1;

    lbl_12_bss_1CC80__fzgx_offset_1400 = lbl_12_data_E98[0];
    for (i = 0, p4 = lbl_12_bss_1CC80__fzgx_offset_1000, p3 = lbl_12_bss_1CC80__fzgx_offset_C00,
        p2 = lbl_12_bss_1CC80__fzgx_offset_800, p0 = lbl_12_bss_1CC80, p1 = lbl_12_bss_1CC80__fzgx_offset_400;
         i < 256; i++, p4++, p3++, p2++, p0++, p1++) {
        y = 1.164f * (f32)(i - 16);
        *p4 = y;
        *p3 = -0.392f * (f32)(i - 128);
        *p2 = 2.017f * (f32)(i - 128);
        *p0 = 1.596f * (f32)(i - 128);
        *p1 = -0.813f * (f32)(i - 128);
    }
}
#pragma opt_propagation reset
