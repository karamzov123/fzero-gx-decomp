#include "types.h"
#include "sfxmc.h"
#include "psvec_quant.h"

/* fzgx:begin fn_12_112D4 noprologue */
#include "types.h"

/* --- rel/movie_module/fn_12_112D4.c --- */
typedef struct Src {
    u8 *base0;
    u8 *base1;
    u8 *base2;
} Src;

typedef struct Dst {
    u8 *base0;
    u8 *base1;
    u8 *base2;
    s16 count0;
    s16 count1;
} Dst;

typedef struct Stride {
    u32 off0;
    u32 off1;
} Stride;

/* One 8x8 block row pair: two 8-byte rows a stride apart, then advance two rows. */
#define ROW2_DCBZ(_n) \
    __dcbz(d, 0); \
    f0 = *(f64 *)s; \
    __dcbz(d, (_n) * 8); \
    f1 = *(f64 *)(s + (_n) * 8); \
    s += (_n) * 16; \
    *(f64 *)d = f0; \
    *(f64 *)(d + (_n) * 8) = f1; \
    d += (_n) * 16

#define ROW2(_n) \
    f0 = *(f64 *)s; \
    f1 = *(f64 *)(s + (_n) * 8); \
    s += (_n) * 16; \
    *(f64 *)d = f0; \
    *(f64 *)(d + (_n) * 8) = f1; \
    d += (_n) * 16

/* One 16-byte row, then advance one row. */
#define ROW16_DCBZ(_n) \
    __dcbz(d, 0); \
    f0 = *(f64 *)s; \
    f1 = *(f64 *)(s + 8); \
    s += (_n) * 8; \
    *(f64 *)d = f0; \
    *(f64 *)(d + 8) = f1; \
    d += (_n) * 8

#define ROW16(_n) \
    f0 = *(f64 *)s; \
    f1 = *(f64 *)(s + 8); \
    s += (_n) * 8; \
    *(f64 *)d = f0; \
    *(f64 *)(d + 8) = f1; \
    d += (_n) * 8

void fn_12_112D4(Stride *stride, Src *src, Dst *dst) {
    s32 n;
    u8 *s;
    u8 *d;
    f64 f0;
    f64 f1;

    n = dst->count0 / 8;
    if ((stride->off0 & 0x1F) == 0) {
        s = src->base0 + stride->off0;
        d = dst->base0 + stride->off0;
        ROW2_DCBZ(n); ROW2_DCBZ(n); ROW2_DCBZ(n); ROW2_DCBZ(n);
        s = src->base1 + stride->off0;
        d = dst->base1 + stride->off0;
        ROW2_DCBZ(n); ROW2_DCBZ(n); ROW2_DCBZ(n); ROW2_DCBZ(n);
    } else {
        s = src->base0 + stride->off0;
        d = dst->base0 + stride->off0;
        ROW2(n); ROW2(n); ROW2(n); ROW2(n);
        s = src->base1 + stride->off0;
        d = dst->base1 + stride->off0;
        ROW2(n); ROW2(n); ROW2(n); ROW2(n);
    }

    n = dst->count1 / 8;
    if ((stride->off1 & 0x1F) == 0) {
        s = src->base2 + stride->off1;
        d = dst->base2 + stride->off1;
        ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n);
        ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n);
        ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n);
        ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n); ROW16_DCBZ(n);
    } else {
        s = src->base2 + stride->off1;
        d = dst->base2 + stride->off1;
        ROW16(n); ROW16(n); ROW16(n); ROW16(n);
        ROW16(n); ROW16(n); ROW16(n); ROW16(n);
        ROW16(n); ROW16(n); ROW16(n); ROW16(n);
        ROW16(n); ROW16(n); ROW16(n); ROW16(n);
    }
}
/* fzgx:end fn_12_112D4 */

/* fzgx:begin fn_12_11860 noprologue */
#include "types.h"
#include "sfxmc.h"
#pragma use_lmw_stmw on

/* --- rel/movie_module/fn_12_11860.c --- */
typedef struct MovieModule MovieModule;
typedef void (*MovieCallback)(MovieModule *, s32, void *, void *);

struct MovieModule {
    u8 unk_000[0x234];
    u8 unk_234[0x10];
    u8 unk_244[0x4c];
    MovieCallback callback;
    u8 unk_294[0x74];
    s32 unk_308;
};

extern void fn_12_112D4(void *, void *, void *);

void fn_12_11860(MovieModule *module, s32 count) {
    u32 local;
    void *first = module->unk_234;
    void *second = (u8 *)first + 0x10;

    while (--count) {
        module->callback(module, module->unk_308 - count, &local, first);
        fn_12_112D4(&local, first, second);
    }
}
/* fzgx:end fn_12_11860 */

/* fzgx:begin fn_12_118E8 noprologue */

/* --- rel/movie_module/fn_12_118E8.c --- */
typedef struct McBiSrc {
    u8 pad_0[4];
    s16 *coef;
    u8 *pred0;
    u8 *pred1;
} McBiSrc;

typedef struct McBlock {
    u8 *dst;
    u32 stride;
} McBlock;

typedef struct McDst {
    u8 pad_0[4];
    McBlock blocks[6];
} McDst;

extern const f32 lbl_12_rodata_9E8[2];

void fn_12_118E8(McBiSrc *src, McDst *out, s32 cbp) {
    u8 *pred1;
    u8 *d;
    u32 stride;
    u8 *pred0;
    s16 *coef;
    McBlock *blk;
    s32 i;
    s32 j;

    coef = src->coef;
    pred0 = src->pred0;
    sfxmc_load_bias(lbl_12_rodata_9E8);
    blk = out->blocks;
    pred1 = src->pred1;
    for (i = 0; i < 6; i++) {
        d = blk->dst;
        stride = blk->stride;
        blk++;
        if (cbp >= 0) {
            if (((u32)d & 0x1F) == 0) {
                coef += 64;
                for (j = 4; j != 0; j--) {
                    __dcbz(d, 0);
                    sfxmc_avg_row0(pred0, pred1, d);
                    d += stride;
                    __dcbz(d, 0);
                    sfxmc_avg_row1(pred0, pred1, d);
                    d += stride;
                    pred0 += 0x10;
                    pred1 += 0x10;
                }
            } else {
                coef += 64;
                for (j = 4; j != 0; j--) {
                    sfxmc_avg_row0(pred0, pred1, d);
                    d += stride;
                    sfxmc_avg_row1(pred0, pred1, d);
                    d += stride;
                    pred0 += 0x10;
                    pred1 += 0x10;
                }
            }
        } else if (((u32)d & 0x1F) == 0) {
            for (j = 4; j != 0; j--) {
                __dcbz(d, 0);
                sfxmc_avg_add_row0(coef, pred0, pred1, d);
                d += stride;
                __dcbz(d, 0);
                sfxmc_avg_add_row1(coef, pred0, pred1, d);
                d += stride;
                pred0 += 0x10;
                pred1 += 0x10;
                coef += 0x10;
            }
        } else {
            for (j = 4; j != 0; j--) {
                sfxmc_avg_add_row0(coef, pred0, pred1, d);
                d += stride;
                sfxmc_avg_add_row1(coef, pred0, pred1, d);
                d += stride;
                pred0 += 0x10;
                pred1 += 0x10;
                coef += 0x10;
            }
        }
        cbp <<= 1;
    }
}
/* fzgx:end fn_12_118E8 */

/* fzgx:begin fn_12_11CE0 noprologue */

/* --- rel/movie_module/fn_12_11CE0.c --- */
typedef struct McSrc {
    u8 pad_0[4];
    s16 *coef;
    u8 *pred;
} McSrc;



/* Six 8x8 blocks: a coded block adds its residual to the prediction, an
 * uncoded one copies the prediction; aligned destinations are zeroed by line
 * first so the stores do not fetch them. */
u32 fn_12_11CE0(McSrc *src, McDst *out, s32 cbp) {
    s16 * coef_base;
    u8 *d;
    s16 *coef;
    s16 *next_coef;
    McBlock *blk;
    u8 * q2;
    u8 *pred;
    s32 i;
    s32 j;
    u32 stride;
    u8 *q;
    u32 n;
    f64 f8;
    f64 f9;
    f64 f10;
    f64 f11;

    coef_base = src->coef;
    coef = coef_base;
    blk = out->blocks;
    pred = src->pred;
    for (i = 0; i < 6; i++) {
        d = blk->dst;
        stride = blk->stride;
        blk++;
        if (cbp >= 0) {
            next_coef = coef + 64;
            n = stride / 8;
            if (((u32)d & 0x1F) == 0) {
                __dcbz(d, 0);
                f8 = ((f64 *)pred)[0];
                f9 = ((f64 *)pred)[1];
                f10 = ((f64 *)pred)[2];
                f11 = ((f64 *)pred)[3];
                *(f64 *)d = f8;
                q = d + n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f9;
                q += n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f10;
                q += n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f11;
                q += n * 8;
                __dcbz(q, 0);
                f8 = ((f64 *)pred)[4];
                f9 = ((f64 *)pred)[5];
                f10 = ((f64 *)pred)[6];
                f11 = ((f64 *)pred)[7];
                *(f64 *)q = f8;
                q += n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f9;
                q += n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f10;
                q += n * 8;
                __dcbz(q, 0);
                *(f64 *)q = f11;
            } else {
                f8 = ((f64 *)pred)[0];
                f9 = ((f64 *)pred)[1];
                f10 = ((f64 *)pred)[2];
                f11 = ((f64 *)pred)[3];
                *(f64 *)d = f8;
                q2 = d + n * 8;
                *(f64 *)q2 = f9;
                q2 += n * 8;
                *(f64 *)q2 = f10;
                q2 += n * 8;
                *(f64 *)q2 = f11;
                q2 += n * 8;
                f8 = ((f64 *)pred)[4];
                f9 = ((f64 *)pred)[5];
                f10 = ((f64 *)pred)[6];
                f11 = ((f64 *)pred)[7];
                *(f64 *)q2 = f8;
                q2 += n * 8;
                *(f64 *)q2 = f9;
                q2 += n * 8;
                *(f64 *)q2 = f10;
                *(f64 *)(q2 + n * 8) = f11;
            }
            pred += 0x40;
        } else if (((u32)d & 0x1F) == 0) {
            for (j = 4; j != 0; j--) {
                __dcbz(d, 0);
                sfxmc_add_row0(coef, pred, d);
                d += stride;
                __dcbz(d, 0);
                sfxmc_add_row1(coef, pred, d);
                d += stride;
                pred += 0x10;
                coef += 0x10;
            }
            next_coef = coef;
        } else {
            for (j = 4; j != 0; j--) {
                sfxmc_add_row0(coef, pred, d);
                d += stride;
                sfxmc_add_row1(coef, pred, d);
                d += stride;
                pred += 0x10;
                coef += 0x10;
            }
            next_coef = coef;
        }
        coef = next_coef;
        cbp <<= 1;
    }
    return (u32)pred;
}
/* fzgx:end fn_12_11CE0 */

/* fzgx:begin fn_12_11F5C noprologue */

/* --- rel/movie_module/fn_12_11F5C.c --- */
typedef struct MPVMCContext MPVMCContext;
typedef void (*MPVMCFunction)(MPVMCContext *context);

struct MPVMCContext {
    MPVMCFunction functions08[4];
    u8 field_10[8];
    u8 *destination;
    u32 field_1c;
    s32 reference_stride;
    const u8 *reference0;
    const u8 *reference1;
};

typedef struct MPVPlaneSet {
    u8 *planes[3];
    s16 chroma_stride;
    s16 luma_stride;
} MPVPlaneSet;

typedef struct MPVMotionInfo {
    u8 field_00[0x18];
    s32 horizontal;
    s32 vertical;
} MPVMotionInfo;

typedef struct MPVBlockOffsets {
    s32 chroma;
    s32 luma;
} MPVBlockOffsets;

typedef struct MPVContext MPVContext;
typedef void (*MPVOffsetFunction)(MPVContext *context, s32 arg,
                                  MPVBlockOffsets *offsets,
                                  const MPVPlaneSet *planes);

struct MPVContext {
    u8 field_000[0xcc];
    MPVMCContext mc;
    u8 field_0f8[0x19c - 0xf8];
    s32 mc_table;
    u8 field_1a0[0x290 - 0x1a0];
    MPVOffsetFunction get_offsets;
    u8 field_294[0x308 - 0x294];
    s32 field_308;
};

extern MPVMCFunction lbl_12_bss_6968[2][2][2];
extern MPVMCFunction lbl_12_bss_6948[2][2][2];

static inline MPVMCFunction *mpvumc_ChromaRow(u32 mc_table, u32 vertical) {
    return lbl_12_bss_6968[mc_table][vertical & 1];
}

void fn_12_11F5C(MPVContext *context, u8 *destination, MPVBlockOffsets *offsets,
                 const MPVPlaneSet *planes, const MPVMotionInfo *motion) {
    s32 horizontal;
    s32 vertical;
    s32 chroma_stride;
    s32 luma_stride;
    s32 chroma_offset;
    s32 luma_offset;
    MPVMCContext *mc;
    MPVMCFunction chroma_function;
    MPVMCFunction luma_function;
    s32 mc_table;
    s32 luma_extra;
    s32 chroma_extra;
    const u8 *reference;

    mc_table = context->mc_table;
    luma_stride = planes->luma_stride;
    chroma_stride = planes->chroma_stride;
    context->get_offsets(context, context->field_308, offsets, planes);
    mc = &context->mc;
    horizontal = motion->horizontal;
    vertical = motion->vertical;
    luma_offset = offsets->luma + (horizontal >> 1) + (vertical >> 1) * luma_stride;
    luma_extra = horizontal & 1;
    luma_function = lbl_12_bss_6948[mc_table][vertical & 1][luma_extra];
    luma_extra &= mc_table;
    chroma_offset = offsets->chroma + ((horizontal / 2) >> 1) + ((vertical / 2) >> 1) * chroma_stride;
    chroma_extra = (horizontal / 2) & 1;
    chroma_function = mpvumc_ChromaRow(mc_table, vertical / 2)[chroma_extra];
    chroma_extra &= mc_table;
    mc->reference_stride = chroma_stride;
    mc->destination = destination;
    reference = planes->planes[0] + chroma_offset;
    mc->reference0 = reference;
    mc->reference1 = reference + chroma_stride + chroma_extra;
    chroma_function(mc);
    mc->destination = destination + 0x40;
    reference = planes->planes[1] + chroma_offset;
    mc->reference0 = reference;
    mc->reference1 = reference + chroma_stride + chroma_extra;
    chroma_function(mc);
    mc->reference_stride = luma_stride;
    mc->destination = destination + 0x80;
    reference = planes->planes[2] + luma_offset;
    mc->reference0 = reference;
    mc->reference1 = luma_stride + luma_extra + reference;
    luma_function(mc);
}
/* fzgx:end fn_12_11F5C */

/* fzgx:begin fn_12_120E4 noprologue */
#include "types.h"

typedef struct MovieHeader MovieHeader;
typedef struct MovieModule MovieModule;

struct MovieHeader {
    u8 unk_00[0xc];
    void *unk_0c;
};

struct MovieModule {
    u8 unk_000[0x110];
    u32 unk_110;
    u32 unk_114;
    void *unk_118;
    void *unk_11c;
    u32 unk_120;
    u32 unk_124;
    u32 unk_128;
    u32 unk_12c;
    u32 unk_130;
    u32 unk_134;
    u32 unk_138;
    u32 unk_13c;
    u32 unk_140;
    u32 unk_144;
    u32 unk_148;
    u32 unk_14c;
    u8 unk_150[0xe4];
    u32 unk_234;
    u8 unk_238[0x2c];
    u32 unk_264;
    u32 unk_268;
    u32 unk_26c;
    u8 unk_270[2];
    s16 unk_272;
    u8 unk_274[0x4c];
    u32 unk_2c0;
    u8 unk_2c4[0x20];
    u32 unk_2e4;
    u8 unk_2e8[0x2c];
    void *unk_314;
};

extern void fn_12_11F5C(void *, void *, void *, void *, void *);
extern void fn_12_118E8(void *, void *, void *);

#pragma opt_propagation off
void fn_12_120E4(MovieModule *module) {
    u32 local[2];
    void *data = (u8 *)module + 0x234;
    MovieHeader *header = (MovieHeader *)((u8 *)module + 0x110);
    void *end = (u8 *)module + 0x2c0;

    fn_12_11F5C(module, module->unk_118, local, data, end);
    fn_12_11F5C(module, header->unk_0c, local,
                (u8 *)data + 0x10, (u8 *)module + 0x2e4);

    module->unk_124 = module->unk_264 + local[0];
    module->unk_12c = module->unk_268 + local[0];
    module->unk_134 = module->unk_26c + local[1];
    module->unk_13c = module->unk_134 + 8;
    module->unk_144 = module->unk_134 + ((s32)module->unk_272 << 3);
    module->unk_14c = module->unk_144 + 8;

    {
        u8 *p120 = (u8 *)module + 0x120;
        fn_12_118E8(header, p120, module->unk_314);
    }
}
#pragma opt_propagation reset
/* fzgx:end fn_12_120E4 */

/* fzgx:begin fn_12_121BC noprologue */
#include "types.h"

typedef struct MovieModule MovieModule;

struct MovieModule {
    u8 unk_000[0x110];
    u8 unk_110[0x8];
    u8 unk_118[0x8];
    u32 unk_120;
    u32 unk_124;
    u8 unk_128[0x4];
    u32 unk_12c;
    u8 unk_130[0x4];
    u32 unk_134;
    u8 unk_138[0x4];
    u32 unk_13c;
    u8 unk_140[0x4];
    u32 unk_144;
    u8 unk_148[0x4];
    u32 unk_14c;
    u8 unk_150[0xf4];
    u32 unk_244;
    u8 unk_248[0x1c];
    u32 unk_264;
    u32 unk_268;
    u32 unk_26c;
    u8 unk_270[0x2];
    s16 unk_272;
    u8 unk_274[0xa0];
    u32 unk_314;
};

extern void fn_12_11F5C(MovieModule *, u32, u32 *, void *, void *);
extern void fn_12_11CE0(void *, void *, u32);

#pragma opt_propagation off
void fn_12_121BC(MovieModule *module) {
    u32 local[2];
    u8 *base = (u8 *)module + 0x110;

    u8 *p120;
    fn_12_11F5C(module, *(u32 *)((u8 *)module + 0x118), local,
                (u8 *)module + 0x244, (u8 *)module + 0x2e4);
    p120 = (u8 *)module + 0x120;
    module->unk_124 = module->unk_264 + local[0];
    module->unk_12c = module->unk_268 + local[0];
    module->unk_134 = module->unk_26c + local[1];
    module->unk_13c = module->unk_134 + 8;
    module->unk_144 = module->unk_134 + ((s32)module->unk_272 << 3);
    module->unk_14c = module->unk_144 + 8;
    fn_12_11CE0(base, p120, module->unk_314);
}
/* fzgx:end fn_12_121BC */

/* fzgx:begin fn_12_12270 noprologue */
#include "types.h"
#include "psvec_quant.h"

/* --- rel/movie_module/fn_12_12270.c --- */
typedef struct MovieModule_u0 MovieModule_u0;

struct MovieModule_u0 {
    u8 unk_000[0x110];
    u8 unk_110[0x8];
    u32 unk_118;
    u8 unk_11c[0x4];
    u32 unk_120;
    u32 unk_124;
    u8 unk_128[0x4];
    u32 unk_12c;
    u8 unk_130[0x4];
    u32 unk_134;
    u8 unk_138[0x4];
    u32 unk_13c;
    u8 unk_140[0x4];
    u32 unk_144;
    u8 unk_148[0x4];
    u32 unk_14c;
    u8 unk_150[0x114];
    u32 unk_264;
    u32 unk_268;
    u32 unk_26c;
    u8 unk_270[0x2];
    s16 unk_272;
    u8 unk_274[0x4c];
    u8 unk_2c0[0x54];
    u32 unk_314;
};

extern void fn_12_11F5C(MovieModule_u0 *, u32, u32 *, void *, void *);
extern void fn_12_11CE0(void *, void *, u32);

#pragma opt_dead_assignments off
void fn_12_12270(MovieModule_u0 *module) {
    u32 local[2];
    u32 lab_t1;
    u8 *base;

    base = (u8 *)module + 0x110;
    lab_t1 = module->unk_118;
    fn_12_11F5C(module, lab_t1, local, (u8 *)module + 0x234, (u8 *)module + 0x2c0);
    module->unk_124 = module->unk_264 + local[0];
    module->unk_12c = module->unk_268 + local[0];
    module->unk_134 = module->unk_26c + local[1];
    module->unk_13c = module->unk_134 + 8;
    module->unk_144 = module->unk_134 + ((s32)module->unk_272 << 3);
    module->unk_14c = module->unk_144 + 8;
    {
        u8 *p120 = (u8 *)module + 0x120;
        fn_12_11CE0(base, p120, module->unk_314);
    }
}
/* fzgx:end fn_12_12270 */

/* fzgx:begin fn_12_12324 noprologue */
#pragma opt_dead_assignments reset

/* --- rel/movie_module/fn_12_12324.c --- */
void fn_12_12324(u8 *src, u32 *table, void *unused) {
    u32 *q;
    s32 count;
    u32 stride;
    u8 *p;
    s32 i;

    q = table + 1;
    count = 6;
    do {
        p = (u8 *)q[0];
        stride = q[1];
        q += 2;
        if (((u32)p & 0x1F) == 0) {
            for (i = 2; i != 0; i--) {
                __dcbz(p, 0);
                psq3_row(src, p);
                p += stride;
                __dcbz(p, 0);
                psq3_row(src + 0x10, p);
                p += stride;
                __dcbz(p, 0);
                psq3_row(src + 0x20, p);
                p += stride;
                __dcbz(p, 0);
                psq3_row(src + 0x30, p);
                p += stride;
                src += 0x40;
            }
        } else {
            for (i = 2; i != 0; i--) {
                psq3_row(src, p);
                p += stride;
                psq3_row(src + 0x10, p);
                p += stride;
                psq3_row(src + 0x20, p);
                p += stride;
                psq3_row(src + 0x30, p);
                p += stride;
                src += 0x40;
            }
        }
    } while (--count > 0);
}
/* fzgx:end fn_12_12324 */

/* fzgx:begin fn_12_124A0 noprologue */
#include "types.h"

typedef struct MovieModule MovieModule;
typedef void (*MovieCallback)(MovieModule *, s32, void *, void *);

struct MovieModule {
    u8 unk_000[0x40];
    void *unk_040;
    u8 unk_044[0x24c];
    MovieCallback callback;
    u8 unk_294[0x14];
    u8 unk_2a8[0x60];
    s32 unk_308;
    u8 unk_30c[0x34];
    u8 unk_340[0x28];
};

typedef struct MovieData MovieData;
struct MovieData {
    s32 value_0;
    s32 value_4;
    s32 value_8;
    s16 value_c;
    s16 value_e;
};

typedef struct MovieOutput MovieOutput;
struct MovieOutput {
    u8 unk_000[4];
    u32 value_4;
    u8 unk_008[4];
    u32 value_c;
    u8 unk_010[4];
    u32 value_14;
    u8 unk_018[4];
    u32 value_1c;
    u8 unk_020[4];
    u32 value_24;
    u8 unk_028[4];
    u32 value_2c;
};

extern void fn_12_12324(void *, void *, void *);

void fn_12_124A0(MovieModule *module) {
    u32 local[2];
    MovieOutput *output = (MovieOutput *)((u8 *)module + 0x120);
    MovieData *data = (MovieData *)((u8 *)module + 0x264);
    s32 offset;

    module->callback(module, module->unk_308, local, data);
    offset = data->value_e;
    offset = offset << 3;
    output->value_4 = data->value_0 + local[0];
    output->value_c = data->value_4 + local[0];
    output->value_14 = data->value_8 + local[1];
    output->value_1c = output->value_14 + 8;
    output->value_24 = output->value_14 + offset;
    output->value_2c = output->value_24 + 8;
    fn_12_12324((u8 *)module + 0x340, output, module->unk_040);
}
/* fzgx:end fn_12_124A0 */

/* fzgx:begin fn_12_1258C noprologue */
#include "types.h"


/* --- rel/movie_module/fn_12_1258C.c --- */
// fn_12_1258C: empty in retail (single blr).
void fn_12_1258C(void) {
}
/* fzgx:end fn_12_1258C */

/* fzgx:begin fn_12_12590 noprologue */

/* --- rel/movie_module/fn_12_12590.c --- */
typedef struct {
    u8 pad_00[0x1d0];
    s32 field_1d0;
    s32 field_1d4;
    u8 pad_1d8[0x254 - 0x1d8];
    s32 field_254;
    u8 pad_258[0x264 - 0x258];
    s32 field_264;
    s32 field_268;
    s32 field_26c;
    s16 field_270;
    s16 field_272;
} MovieCtx;

void fn_12_12590(MovieCtx *m, u32 lab_unused0) {
    s16 *fzgx_value;
    s32 w0;
    s32 rows;
    s32 rows16;
    s32 rbit;
    s32 half;
    s32 wide;
    s32 h32;
    s32 w32;
    s32 h0;
    s32 cols;
    u32 c16;
    s32 base;
    w0 = m->field_1d0;
    rows = (w0 + 15) / 16;
    rows16 = rows << 4;
    rbit = (s32)((u32)rows >> 27 & 1u);
    half = (rows16 + 31) / 32;
    wide = (((rbit + rows16) >> 1) + 31) / 32;
    h32 = half << 5;
    w32 = wide << 5;
    h0 = m->field_1d4;
    cols = (h0 + 15) / 16;
    h0 = cols << 4;
    rbit = h0;
    wide = rbit;
    c16 = wide;
    base = m->field_254;

    m->field_272 = (s16)h32;
    fzgx_value = &(m->field_270);
    *fzgx_value = (s16)w32;
    m->field_26c = base;
    m->field_264 = m->field_26c + (((((c16)) * ((h32)))));
    {
        s32 cbit = (s32)((u32)cols >> 27 & 1u);
        s32 csum = (cbit + (s32)c16) >> 1;
        m->field_268 = m->field_264 + (((csum) * (w32)));
    }
}
/* fzgx:end fn_12_12590 */

/* fzgx:begin fn_12_12624 noprologue */

/* --- rel/movie_module/fn_12_12624.c --- */
extern void fn_12_DC78(void);
extern void fn_12_1FADC(void);
extern u32 lbl_12_bss_6968[8];
extern void fn_12_D55C(void);
extern void fn_12_D948(void);
extern void fn_12_D42C(void);
extern void fn_12_1F1AC(void);
extern void fn_12_1F61C(void);
extern void fn_12_1EF80(void);
extern u32 lbl_12_bss_6948[8];

void fn_12_12624(void) {
    lbl_12_bss_6968[0] = (u32)fn_12_DC78;
    lbl_12_bss_6968[1] = (u32)fn_12_D55C;
    lbl_12_bss_6968[2] = (u32)fn_12_D948;
    lbl_12_bss_6968[3] = (u32)fn_12_D42C;
    lbl_12_bss_6968[4] = (u32)fn_12_DC78;
    lbl_12_bss_6968[5] = (u32)fn_12_D55C;
    lbl_12_bss_6968[6] = (u32)fn_12_D948;
    lbl_12_bss_6968[7] = (u32)fn_12_D948;
    lbl_12_bss_6948[0] = (u32)fn_12_1FADC;
    lbl_12_bss_6948[1] = (u32)fn_12_1F1AC;
    lbl_12_bss_6948[2] = (u32)fn_12_1F61C;
    lbl_12_bss_6948[3] = (u32)fn_12_1EF80;
    lbl_12_bss_6948[4] = (u32)fn_12_1FADC;
    lbl_12_bss_6948[5] = (u32)fn_12_1F1AC;
    lbl_12_bss_6948[6] = (u32)fn_12_1F61C;
    lbl_12_bss_6948[7] = (u32)fn_12_1F61C;
}
/* fzgx:end fn_12_12624 */
