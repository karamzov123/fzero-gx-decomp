#include "types.h"

/* fn_12_3DCF0, from the CC0 MK Deception decomp (cftfx.c) */

typedef struct CFTYcc420Planar {
    const u8 *y;
    const u8 *cb;
    const u8 *cr;
    s32 y_stride;
    s32 cb_stride;
    s32 cr_stride;
} CFTYcc420Planar;
typedef struct CFTArgb8888Output {
    u8 *data;
    s32 width;
    s32 height;
    s32 stride;
} CFTArgb8888Output;
typedef float CFTArgbTable[3][256][4];
void CFT_MakeArgb8888ColAdjTbl(void *table);
void CFT_MakeYcc422ColAdjTbl(void *table);
typedef struct MwsYccPlane {
    void *y;
    void *cb;
    void *cr;
    int y_pitch;
    int cb_pitch;
    int cr_pitch;
} MwsYccPlane;
void mwPlyCalcYccPlane(void *buffer, int width, int height, MwsYccPlane *output);
typedef float CFTMtx3D[3][3];
typedef unsigned char CFTConvTable[256];
extern void CFT_MakeInvConvTableCustom(CFTConvTable luma, CFTConvTable chroma_u,
                                       CFTConvTable chroma_v);
extern void CFT_MakeInverseMtx3D(CFTMtx3D matrix, CFTMtx3D inverse);
extern void CFT_MakeMtx3D(CFTMtx3D left, CFTMtx3D right, CFTMtx3D product);
extern CFTMtx3D cft_rgb_yuv_coeff;
extern CFTMtx3D cft_rgb_yuv_ccir601;
extern CFTConvTable cft_conv_y_itbl;
extern CFTConvTable cft_conv_u_itbl;
extern CFTConvTable cft_conv_v_itbl;
extern float *cft_ptr_y__rgb;
extern float *cft_ptr_cb_rgb;
extern float *cft_ptr_cr_rgb;
extern CFTMtx3D cft_yuv_rgb_coeff;
extern CFTMtx3D cft_basic_ccir601;
extern void cnvStaticYcc420plnToA256V(const CFTYcc420Planar *source,
                                      const CFTArgb8888Output *destination);

u32 fn_12_3DCF0(const CFTYcc420Planar *source, const CFTArgb8888Output *destination,
                 const u8 *table) {
    s32 rewind;
    s32 output_skip;
    const u8 *y = source->y;
    const u8 *row4;
    const u8 *row3;
    s32 block_y;
    s32 block_x;
    s32 width_in_blocks = destination->width / 4;
    s32 height_in_blocks = destination->height / 4;
    s32 y_stride = source->y_stride;
    u32 *output = (u32 *)destination->data;
    const u8 *row2;
    s32 y_skip;
    u32 v0;
    u32 v1;
    rewind = y_stride * 4;
    y_skip = y_stride * 3;
    output_skip = ((destination->stride - destination->width) << 4) & 0xFFFFFFC0;
    for (block_y = 0; block_y < height_in_blocks; block_y++) {
        for (block_x = 0; block_x < width_in_blocks; block_x++) {
            row2 = (u8 *)(y_stride - 4);
            row3 = row2;
            row4 = row2;
            v0 = (((u32)(table)[(y)[0] & 0xFF] & 0xFF) << 24);
            v0 |= (u32)(table)[(y)[1] & 0xFF] << 8;
            v1 = (((u32)(table)[(y)[2] & 0xFF] & 0xFF) << 24);
            v1 |= (u32)(table)[((y) += 4)[-1] & 0xFF] << 8;
            (output)[0] &= v0 | 0x00FF00FF;
            (output)[1] &= v1 | 0x00FF00FF;
            row2 += (u32)(y + 4) - 4;
            v0 = (((u32)(table)[(row2)[0] & 0xFF] & 0xFF) << 24);
            v0 |= (u32)(table)[(row2)[1] & 0xFF] << 8;
            v1 = (((u32)(table)[(row2)[2] & 0xFF] & 0xFF) << 24);
            v1 |= (u32)(table)[((row2) += 4)[-1] & 0xFF] << 8;
            (output + 2)[0] &= v0 | 0x00FF00FF;
            (output + 2)[1] &= v1 | 0x00FF00FF;
            row3 += (u32)(row2 + 4) - 4;
            v0 = (((u32)(table)[(row3)[0] & 0xFF] & 0xFF) << 24);
            v0 |= (u32)(table)[(row3)[1] & 0xFF] << 8;
            v1 = (((u32)(table)[(row3)[2] & 0xFF] & 0xFF) << 24);
            v1 |= (u32)(table)[((row3) += 4)[-1] & 0xFF] << 8;
            (output + 4)[0] &= v0 | 0x00FF00FF;
            (output + 4)[1] &= v1 | 0x00FF00FF;
            row4 += (u32)(row3 + 4) - 4;
            v0 = (((u32)(table)[(row4)[0] & 0xFF] & 0xFF) << 24);
            v0 |= (u32)(table)[(row4)[1] & 0xFF] << 8;
            v1 = (((u32)(table)[(row4)[2] & 0xFF] & 0xFF) << 24);
            v1 |= (u32)(table)[((row4) += 4)[-1] & 0xFF] << 8;
            (output + 6)[0] &= v0 | 0x00FF00FF;
            (output + 6)[1] &= v1 | 0x00FF00FF;
            row3 = (u8 *)(y_stride - 4);
            row3 += (u32)(row4 + 4) - 4;
            y = row3 - rewind + 4;
            output += 16;
        }
        y += y_skip;
        output = (u32 *)((u8 *)output + output_skip);
    }
    return (u32)y_skip;
}
