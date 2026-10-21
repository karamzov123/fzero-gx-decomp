#include "types.h"

/* CFT_MakeYcc422ColAdjTbl, from the CC0 MK Deception decomp (cftfx.c) */

typedef float CFTMtx3D[3][3];
typedef unsigned char CFTConvTable[256];

extern void fn_12_3E688(CFTConvTable luma, CFTConvTable chroma_u, CFTConvTable chroma_v);
extern void fn_12_3E500(CFTMtx3D matrix, CFTMtx3D inverse);
extern CFTMtx3D lbl_12_data_EA0;
extern CFTMtx3D lbl_12_data_EC4;
extern void fn_12_3E394(CFTMtx3D left, CFTMtx3D right, CFTMtx3D product);

/* file-scope objects of the retail TU, in retail order: MWCC addresses them off one section base */
CFTMtx3D lbl_12_bss_1E088;
CFTMtx3D lbl_12_bss_1E088__fzgx_offset_24;
float *lbl_12_bss_1E088__fzgx_offset_48;
float *lbl_12_bss_1E088__fzgx_offset_4C;
float *lbl_12_bss_1E088__fzgx_offset_50;
CFTConvTable lbl_12_bss_1E088__fzgx_offset_54;
CFTConvTable lbl_12_bss_1E088__fzgx_offset_154;
CFTConvTable lbl_12_bss_1E088__fzgx_offset_254;

#define cft_rgb_yuv_coeff lbl_12_data_EA0
#define cft_rgb_yuv_ccir601 lbl_12_data_EC4
#define cft_basic_ccir601 lbl_12_bss_1E088
#define cft_yuv_rgb_coeff lbl_12_bss_1E088__fzgx_offset_24
#define cft_ptr_cr_rgb lbl_12_bss_1E088__fzgx_offset_48
#define cft_ptr_cb_rgb lbl_12_bss_1E088__fzgx_offset_4C
#define cft_ptr_y__rgb lbl_12_bss_1E088__fzgx_offset_50
#define cft_conv_v_itbl lbl_12_bss_1E088__fzgx_offset_54
#define cft_conv_u_itbl lbl_12_bss_1E088__fzgx_offset_154
#define cft_conv_y_itbl lbl_12_bss_1E088__fzgx_offset_254

#pragma section code_type ".fzgxpool"
static void fzgx_bss_layout(void) {
    volatile u8 s; /* fzgx-allow: S2 BSS primer ordering */
    s = *(u8 *)&lbl_12_bss_1E088;
    s = *(u8 *)&lbl_12_bss_1E088__fzgx_offset_24;
    s = *(u8 *)&lbl_12_bss_1E088__fzgx_offset_48;
    s = *(u8 *)&lbl_12_bss_1E088__fzgx_offset_4C;
    s = *(u8 *)&lbl_12_bss_1E088__fzgx_offset_50;
    s = *(u8 *)&lbl_12_bss_1E088__fzgx_offset_54;
    s = *(u8 *)&lbl_12_bss_1E088__fzgx_offset_154;
    s = *(u8 *)&lbl_12_bss_1E088__fzgx_offset_254;
}
static void fzgx_pool_layout(void) {
    volatile float s; /* fzgx-allow: S2 pool primer sink: MWCC lays out the TU literal pool in first-use order */
    volatile unsigned char c; /* fzgx-allow: S2 pool primer source */
    s = 255.0f;
    s = 128.0f;
    s = (float)c;
}
#pragma section code_type ".text"

#define CFT_CLIP255(value)    \
    if ((value) < 0.0f) {     \
        (value) = 0.0f;       \
    }                         \
    if ((value) > 255.0f) {   \
        (value) = 255.0f;     \
    }


void fn_12_3D968(void* table)
{
    u32* alpha_high = (u32*)table;
    u32* alpha_low = alpha_high + 0x100;
    u32* chroma_high = alpha_low + 0x100;
    u32* chroma_low = chroma_high + 0x100;
    float value;
    float u_offset;
    float v_offset;
    float y_coefficient;
    float u_coefficient;
    float v_coefficient;
    u32 converted;
    s32 index;

    fn_12_3E688(cft_conv_y_itbl, cft_conv_u_itbl,
                               cft_conv_v_itbl);
    fn_12_3E500(cft_rgb_yuv_coeff, cft_yuv_rgb_coeff);
    fn_12_3E394(cft_rgb_yuv_ccir601, cft_yuv_rgb_coeff,
                  cft_basic_ccir601);
    y_coefficient = cft_basic_ccir601[0][0];
    u_coefficient = cft_basic_ccir601[1][1];
    v_coefficient = cft_basic_ccir601[2][2];
    u_offset = 128.0f * u_coefficient;
    v_offset = 128.0f * v_coefficient;
    for (index = 0; index < 256; index++) {
        value = y_coefficient * (float)cft_conv_y_itbl[index] + 16.5f;
        CFT_CLIP255(value);
        converted = (u32)value;
        alpha_high[index] = converted << 24;
        alpha_low[index] = converted << 8;
        value = 128.5f + (u_coefficient * (float)cft_conv_u_itbl[index] - u_offset);
        CFT_CLIP255(value);
        converted = (u32)value;
        chroma_high[index] = converted << 16;
        value = 128.5f + (v_coefficient * (float)cft_conv_v_itbl[index] - v_offset);
        CFT_CLIP255(value);
        converted = (u32)value;
        chroma_low[index] = converted;
    }
}

