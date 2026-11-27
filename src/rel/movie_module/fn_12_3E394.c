#include "types.h"
/* WARNING: compiler-diff device, not original code: file-level use_lmw_stmw on (stmw/lmw prologues; 21 of 296 movie_module files carry it, possibly the vendor build setting, circumstantial) */
#pragma use_lmw_stmw on

/* --- rel/movie_module/fn_12_3DBDC.c --- */
/* --- rel/movie_module/fn_12_3DBDC.c --- */
// fn_12_3DBDC: empty in retail (single blr).
void fn_12_3DBDC(void);

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
    s32 height;
    s32 width;
} MovieDst;

/* WARNING: compiler-diff device, not original code: region helper whose locals get their own allocation; written inline at its one call site 56 diff lines */
static inline void fn_12_3DBE0_fzgx_rgn0(u32 * palette, u32 i2, u32 i3, s32 top) {
    u32 a;
    u32 b;

    a = *(u32 *)((u8 *)palette + i2);
                b = *(u32 *)((u8 *)palette + i3);
                *(u32 *)(top + 4) = (b & 0xFFFF0000) | (a >> 16);
}


void fn_12_3DBE0(MovieSrc *source, MovieDst *dest, u32 *palette);

/* --- rel/movie_module/fn_12_3DCEC.c --- */
// fn_12_3DCEC: empty in retail (single blr).
void fn_12_3DCEC(void);

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

u32 fn_12_3DCF0(const CFTYcc420Planar *source, const CFTArgb8888Output *destination, const u8 *table);

/* --- rel/movie_module/fn_12_3DF08.c --- */
/* fn_12_3DF08, from the CC0 MK Deception decomp (cftfx.c) */


void fn_12_3DF08(const CFTYcc420Planar *source, const CFTArgb8888Output *destination);

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

void fn_12_3E09C(const void *source, void *destination, s32 width, s32 height);

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

/* --- rel/movie_module/fn_12_3E500.c --- */
void fn_12_3E500(CFTMtx3D matrix, CFTMtx3D inverse);

void fn_12_3E500(CFTMtx3D matrix, CFTMtx3D inverse) {
    float determinant;
    float scale;
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
    float g;
    float h;
    float i;
    a = matrix[0][0];
    b = matrix[0][1];
    c = matrix[0][2];
    d = matrix[1][0];
    e = matrix[1][1];
    f = matrix[1][2];
    g = matrix[2][0];
    h = matrix[2][1];
    i = matrix[2][2];
    scale = 1.0f;
    determinant = (a * e * i + b * f * g + c * d * h) - (a * f * h + b * d * i + c * e * g);
    inverse[0][0] = scale * ((e * i - f * h) / determinant);
    inverse[0][1] = scale * (-(b * i - c * h) / determinant);
    inverse[0][2] = scale * ((b * f - c * e) / determinant);
    inverse[1][0] = scale * (-(d * i - f * g) / determinant);
    inverse[1][1] = scale * ((a * i - c * g) / determinant);
    inverse[1][2] = scale * (-(a * f - c * d) / determinant);
    inverse[2][0] = scale * ((d * h - e * g) / determinant);
    inverse[2][1] = scale * (-(a * h - b * g) / determinant);
    inverse[2][2] = scale * ((a * e - b * d) / determinant);
}

/* --- rel/movie_module/fn_12_3E688.c --- */
void fn_12_3E688(CFTConvTable luma, CFTConvTable chroma_u, CFTConvTable chroma_v);

void fn_12_3E688(CFTConvTable luma, CFTConvTable chroma_u, CFTConvTable chroma_v) {
    int i;
    int j;
    int v;
    int t;
    j = 0;
    v = 0;
    while (j < 0x10) {
        luma[j++] = v++;
        luma[j++] = v;
        v += 2;
    }
    while (j < 0xB0) {
        luma[j] = v;
        luma[j + 1] = v;
        j += 2;
        v++;
    }
    while (j < 0xC0) {
        luma[j] = v;
        v++;
        j++;
    }
    while (j < 0x100) {
        t = 0xFF;
        if (v < 0xFF) {
            t = v;
        }
        luma[j] = t;
        v += 2;
        j++;
    }
    j = 0x80;
    v = j;
    while (j > 0x68) {
        chroma_u[j] = v;
        chroma_v[j] = v;
        chroma_u[j - 1] = v;
        chroma_v[j - 1] = v;
        chroma_u[j - 2] = v;
        chroma_v[j - 2] = v;
        j -= 3;
        v--;
    }
    for (i = j; i >= 0; i--) {
        chroma_u[i] = i * v / j;
        chroma_v[i] = i * v / j;
    }
    v = 0x80;
    t = v;
    while (v < 0x98) {
        chroma_u[v] = t;
        chroma_v[v] = t;
        chroma_u[v + 1] = t;
        chroma_v[v + 1] = t;
        chroma_u[v + 2] = t;
        chroma_v[v + 2] = t;
        v += 3;
        t++;
    }
    i = v;
    for (; v <= 0xFF; v++) {
        chroma_u[v] = t + (0xFF - t) * (v - i) / (0xFF - i);
        chroma_v[v] = t + (0xFF - t) * (v - i) / (0xFF - i);
    }
}
