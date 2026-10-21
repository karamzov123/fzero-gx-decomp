#include "types.h"

/* CFT_MakeArgb8888ColAdjTbl, from the CC0 MK Deception decomp (cftfx.c) */

typedef float CFTMtx3D[3][3];
typedef unsigned char CFTConvTable[256];

extern void fn_12_3E688(CFTConvTable luma, CFTConvTable chroma_u, CFTConvTable chroma_v);
extern void fn_12_3E500(CFTMtx3D matrix, CFTMtx3D inverse);
extern CFTMtx3D lbl_12_data_EA0;

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
#pragma section code_type ".text"

void fn_12_3D740(void* buffer)
{
    s32 index;

    cft_ptr_y__rgb = (float*)buffer;
    cft_ptr_cb_rgb = (float*)((u8*)buffer + 0x1000);
    cft_ptr_cr_rgb = (float*)((u8*)buffer + 0x2000);
    fn_12_3E688(cft_conv_y_itbl, cft_conv_u_itbl,
                               cft_conv_v_itbl);
    fn_12_3E500(cft_rgb_yuv_coeff, cft_yuv_rgb_coeff);
    for (index = 0; index < 256; index++) {
        cft_ptr_y__rgb[(index << 2) + 1] = cft_yuv_rgb_coeff[0][0] * (float)cft_conv_y_itbl[index];
        cft_ptr_y__rgb[(index << 2) + 2] = cft_yuv_rgb_coeff[1][0] * (float)cft_conv_y_itbl[index];
        cft_ptr_y__rgb[(index << 2) + 3] = cft_yuv_rgb_coeff[2][0] * (float)cft_conv_y_itbl[index];
        cft_ptr_y__rgb[(index << 2) + 0] = 255.0f;
        cft_ptr_cb_rgb[(index << 2) + 1] = cft_yuv_rgb_coeff[0][1] * ((float)cft_conv_u_itbl[index] - 128.0f);
        cft_ptr_cb_rgb[(index << 2) + 2] = cft_yuv_rgb_coeff[1][1] * ((float)cft_conv_u_itbl[index] - 128.0f);
        cft_ptr_cb_rgb[(index << 2) + 3] = cft_yuv_rgb_coeff[2][1] * ((float)cft_conv_u_itbl[index] - 128.0f);
        cft_ptr_cr_rgb[(index << 2) + 1] = cft_yuv_rgb_coeff[0][2] * ((float)cft_conv_v_itbl[index] - 128.0f);
        cft_ptr_cr_rgb[(index << 2) + 2] = cft_yuv_rgb_coeff[1][2] * ((float)cft_conv_v_itbl[index] - 128.0f);
        cft_ptr_cr_rgb[(index << 2) + 3] = cft_yuv_rgb_coeff[2][2] * ((float)cft_conv_v_itbl[index] - 128.0f);
    }
}

