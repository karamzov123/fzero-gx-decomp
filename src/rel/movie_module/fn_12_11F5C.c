#include "types.h"
#pragma use_lmw_stmw on

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
