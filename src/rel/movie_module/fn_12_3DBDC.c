#include "types.h"
#pragma inline_max_size(4096)
#pragma use_lmw_stmw on

/* --- rel/movie_module/fn_12_3DBDC.c --- */
// fn_12_3DBDC: empty in retail (single blr).
void fn_12_3DBDC(void) {
}

/* --- rel/movie_module/fn_12_3DBE0.c --- */
typedef struct MovieSrc {
    u32 *data;
    u8 pad4[8];
    s32 stride;
} MovieSrc;

typedef struct MovieDst {
    u32 pad0;
    u32 *data;
    s32 pitch;
    volatile s32 height;  /* fzgx-allow: S2 volatile keeps the verified access order */
    s32 width;
} MovieDst;

static inline void fn_12_3DBE0_fzgx_rgn0(u32 * palette, u32 i2, u32 i3, s32 top) {
    u32 a;
    u32 b;

    a = *(u32 *)((u8 *)palette + i2);
                b = *(u32 *)((u8 *)palette + i3);
                *(u32 *)(top + 4) = (b & 0xFFFF0000) | (a >> 16);
}

static inline u32 fn_12_3DBE0_merge(u32 a, u32 b) {
    return (a << 16) | (b & 0xFFFF);
}


void fn_12_3DBE0(MovieSrc *source, MovieDst *dest, u32 *palette) {
    s32 width;
    u32 i2;
    s32 x;
    s32 rawHeight;
    u32 a;
    u32 b;
    s32 y;
    register s32 height;
    s32 row;
    s32 src;
    s32 top;
    s32 bottom;
    struct { s32 value; } skip;
    struct { s32 value; } stride;
    struct { s32 value; } stride4;
    u32 packed;
    u32 i0;
    u32 i1;
    u32 i3;
    s32 rawStride;
    s32 rawSkip;
    s32 rawWidth;

    skip.value = 0;
    stride.value = 0;
    stride4.value = 0;

    rawWidth = dest->width;
    b = source->stride;
    height = rawWidth / 4;
    width = height;
    rawSkip = dest->pitch - rawWidth;
    top = (u32)dest->data;
    rawHeight = dest->height;
    src = (u32)source->data;
    rawHeight /= 4;
    dest = (MovieDst *)rawHeight;
    height = (s32)dest;
    bottom = top + 32;
    stride.value = b & ~3;
    stride4.value = (b << 2) & ~15;
    skip.value = rawSkip << 4;

    for (y = 0; y < height;) {
        for (x = 0; x < width;) {
            for (row = 0; row < 4; row++) {
                packed = *(u32 *)src;
                src += stride.value;
                i1 = (packed >> 22) & 1020;
                i0 = (packed >> 14) & 1020;
                i2 = (packed << 2) & 1020;
                i3 = (packed >> 6) & 1020;
                b = *(u32 *)((u8 *)palette + i1);
                a = *(u32 *)((u8 *)palette + i0);
                *(u32 *)(top + 0) = (b & 0xFFFF0000) | (a >> 16);
                fn_12_3DBE0_fzgx_rgn0(palette, i2, i3, top);
                top += 8;
                a = *(u32 *)((u8 *)palette + i1);
                b = *(u32 *)((u8 *)palette + i0);
                *(u32 *)(bottom + 0) = (a << 16) | (b & 0xFFFF);
                a = *(u32 *)((u8 *)palette + i3);
                b = *(volatile u32 *)((u8 *)palette + i2);  /* fzgx-allow: S2 volatile view keeps the verified load order */
                *(u32 *)(bottom + 4) = fn_12_3DBE0_merge(a, b);
                bottom += 8;
            }
            src -= stride4.value;
            x++;
            src += 4;
            top += 32;
            bottom += 32;
        }
        x = src - stride.value;
        top += skip.value;
        bottom += skip.value;
        y++;
        src = x + stride4.value;
    }
}

/* --- rel/movie_module/fn_12_3DCEC.c --- */
// fn_12_3DCEC: empty in retail (single blr).
void fn_12_3DCEC(void) {
}

/* --- rel/movie_module/fn_12_3DCF0.c --- */
/* --- rel/movie_module/fn_12_3DCF0.c --- */
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

/* --- rel/movie_module/fn_12_3DF08.c --- */
/* fn_12_3DF08, from the CC0 MK Deception decomp (cftfx.c) */


void fn_12_3DF08(const CFTYcc420Planar *source, const CFTArgb8888Output *destination) {
    s32 block_y;
    s32 block_x;
    s32 width_in_blocks = destination->width / 4;
    s32 y_step = source->y_stride / sizeof(u32);
    s32 height_in_blocks = destination->height / 4;
    s32 output_skip = (u32)(destination->stride - destination->width) / 4 * 16;
    u32 *output = (u32 *)destination->data;
    u32 *y = (u32 *)source->y;
    u32 pixels;
    u32 low = 0;
    for (block_y = 0; block_y < height_in_blocks; block_y++) {
        for (block_x = 0; block_x < width_in_blocks; block_x++) {
            pixels = *y;
            y += y_step;
            (low) = (((pixels) << 16) & 0xFF000000) | (((pixels) & 0xFF) << 8);
            (output)[0] &= (((pixels) & 0xFF000000) | (((pixels) >> 8) & 0x0000FF00)) | 0x00FF00FF;
            (output)[1] &= (low) | 0x00FF00FF;
            pixels = *y;
            y += y_step;
            (low) = (((pixels) << 16) & 0xFF000000) | (((pixels) & 0xFF) << 8);
            (output + 2)[0] &=
                (((pixels) & 0xFF000000) | (((pixels) >> 8) & 0x0000FF00)) | 0x00FF00FF;
            (output + 2)[1] &= (low) | 0x00FF00FF;
            pixels = *y;
            y += y_step;
            (low) = (((pixels) << 16) & 0xFF000000) | (((pixels) & 0xFF) << 8);
            (output + 4)[0] &=
                (((pixels) & 0xFF000000) | (((pixels) >> 8) & 0x0000FF00)) | 0x00FF00FF;
            (output + 4)[1] &= (low) | 0x00FF00FF;
            pixels = *y;
            y += y_step;
            (low) = (((pixels) << 16) & 0xFF000000) | (((pixels) & 0xFF) << 8);
            (output + 6)[0] &=
                (((pixels) & 0xFF000000) | (((pixels) >> 8) & 0x0000FF00)) | 0x00FF00FF;
            (output + 6)[1] &= (low) | 0x00FF00FF;
            y -= y_step * 4;
            low = (u32)y + 4;
            y = (u32 *)low;
            low = (u32)output + 64;
            output = (u32 *)low;
        }
        y += y_step * 3;
        output += output_skip;
    }
}

/* --- rel/movie_module/fn_12_3E09C.c --- */
void fn_12_3E09C(const void *source, void *destination, s32 width, s32 height);

void fn_12_339B4(void *buffer, int width, int height, MwsYccPlane *output);

static inline u32 cftPackEvenPixels(u32 luma, u16 chroma) {
    return (luma & 0xFF000000) | ((luma >> 8) & 0x0000FF00) | (((u32)chroma << 8) & 0x00FF0000) |
           ((u32)chroma >> 8);
}

static inline u32 cftPackOddPixels(u32 luma, u16 chroma) {
    return ((luma << 16) & 0xFF000000) | ((luma << 8) & 0x0000FF00) |
           (((u32)chroma << 16) & 0x00FF0000) | ((u32)chroma & 0xFF);
}

static inline void cftStorePixelQuad(u32 *first_output, u32 *second_output, u32 first_luma,
                                     u32 second_luma, u16 first_chroma, u16 second_chroma) {
    first_output[1] = cftPackOddPixels(first_luma, first_chroma);
    second_output[1] = cftPackOddPixels(second_luma, second_chroma);
    first_output[0] = cftPackEvenPixels(first_luma, first_chroma);
    second_output[0] = cftPackEvenPixels(second_luma, second_chroma);
}

void fn_12_3E09C(const void *source, void *destination, s32 width, s32 height) {
    MwsYccPlane planes;
    u8 *y0;
    u8 *y1;
    u16 *cb;
    u16 *cr;
    u32 *output0;
    u32 *output1;
    s32 y_step;
    s32 c_step;
    s32 y_rewind;
    s32 block_y;
    s32 blocks_across;
    s32 blocks_down;
    u16 *chroma_base;
    u16 *cb_next;
    u16 chroma_u;
    u16 chroma_v;
    fn_12_339B4((void *)source, width, height, &planes);
    blocks_across = width / 4;
    y0 = planes.y;
    chroma_base = planes.cb;
    y1 = (u8 *)planes.y + ((((unsigned long)chroma_base - (unsigned long)planes.y) >> 1) & ~3UL);
    cb = chroma_base;
    cr = planes.cr;
    output0 = destination;
    blocks_down = height / 4;
    output1 = output0 + 8;
    y_step = planes.y_pitch & ~3;
    c_step = planes.cb_pitch & ~1;
    y_rewind = y_step * 2;
    for (block_y = 0; block_y < blocks_down; block_y++) {
        u16 *cr_next = (u16 *)(c_step + (u32)cr);
        s32 block_x;
        cb_next = (u16 *)(c_step + (u32)cb);
        for (block_x = 0; block_x < blocks_across; block_x++) {
            if (block_x >= 0 && block_x < blocks_across) {
                u32 first_luma = *(u32 *)y1;
                u32 second_luma = *(u32 *)y0;
                u16 first_chroma = *cb;
                u16 second_chroma = *cr;
                cftStorePixelQuad(output0, output1, first_luma, second_luma, first_chroma,
                                  second_chroma);
                chroma_u = *cb;
                chroma_v = *cr;
                cftStorePixelQuad(output0 + 2, output1 + 2, *(u32 *)y1, *(u32 *)y0, chroma_u,
                                  chroma_v);
            } else {
                output1[0] = output0[0] = 0;
                output1[1] = output0[1] = 0;
                output1[2] = output0[2] = 0;
                output1[3] = output0[3] = 0;
            }
            y0 += y_step;
            y1 += y_step;
            if (block_x >= 0 && block_x < blocks_across) {
                cftStorePixelQuad(output0 + 4, output1 + 4, *(u32 *)y1, *(u32 *)y0, *cb_next,
                                  *cr_next);
                cftStorePixelQuad(output0 + 6, output1 + 6, *(u32 *)y1, *(u32 *)y0, *cb, *cr);
            } else {
                output1[4] = output0[4] = 0;
                output1[5] = output0[5] = 0;
                output1[6] = output0[6] = 0;
                output1[7] = output0[7] = 0;
            }
            y0 += y_step;
            y1 += y_step;
            y0 += 4;
            y1 += 4;
            y0 -= y_rewind;
            output0 += 16;
            output1 += 16;
            cb++;
            cb_next++;
            cr++;
            cr_next++;
            y1 -= y_rewind;
        }
        y0 += y_step;
        y1 += y_step;
        cb = (u16 *)((u8 *)cb + c_step);
        cr = (u16 *)((u8 *)cr + c_step);
    }
}

/* --- rel/movie_module/fn_12_3E394.c --- */
typedef struct Matrix3 {
    f32 m[9];
} Matrix3;

void fn_12_3E394(const Matrix3 *a, const Matrix3 *b, Matrix3 *out) {
    out->m[0] = a->m[0] * b->m[0] + a->m[1] * b->m[3] + a->m[2] * b->m[6];
    out->m[1] = a->m[0] * b->m[1] + a->m[1] * b->m[4] + a->m[2] * b->m[7];
    out->m[2] = a->m[0] * b->m[2] + a->m[1] * b->m[5] + a->m[2] * b->m[8];
    out->m[3] = a->m[3] * b->m[0] + a->m[4] * b->m[3] + a->m[5] * b->m[6];
    out->m[4] = a->m[3] * b->m[1] + a->m[4] * b->m[4] + a->m[5] * b->m[7];
    out->m[5] = a->m[3] * b->m[2] + a->m[4] * b->m[5] + a->m[5] * b->m[8];
    out->m[6] = a->m[6] * b->m[0] + a->m[7] * b->m[3] + a->m[8] * b->m[6];
    out->m[7] = a->m[6] * b->m[1] + a->m[7] * b->m[4] + a->m[8] * b->m[7];
    out->m[8] = a->m[6] * b->m[2] + a->m[7] * b->m[5] + a->m[8] * b->m[8];
}
