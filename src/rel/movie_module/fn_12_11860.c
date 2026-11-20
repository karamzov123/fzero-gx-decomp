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
