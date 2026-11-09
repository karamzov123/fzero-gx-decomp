/* Non-matching: best partial attempt (98.37% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MPVMCContext {
    u8 pad_0[0x18];
    u8 *destination;
    u8 pad_1C[4];
    s32 reference_stride;
    const u8 *reference0;
    const u8 *reference1;
} MPVMCContext;

typedef void (*MPVMCFunction)(MPVMCContext *);

typedef struct MPVContext MPVContext;
struct MPVContext {
    u8 pad_0[0xCC];
    MPVMCContext mc;
    u8 pad_F8[0x19C - 0xF8];
    s32 mc_flag;
    u8 pad_1A0[0x290 - 0x1A0];
    void (*prepare)(MPVContext *, u32);
    u8 pad_294[0x308 - 0x294];
    u32 prepare_arg;
};

typedef struct MPVBlockOffsets {
    s32 chroma;
    s32 luma;
} MPVBlockOffsets;

typedef struct MPVPlaneSet {
    const u8 *planes[3];
    s16 chroma_stride;
    s16 luma_stride;
} MPVPlaneSet;

typedef struct MPVMotionInfo {
    u8 pad_0[0x18];
    s32 horizontal;
    s32 vertical;
} MPVMotionInfo;

extern MPVMCFunction lbl_12_bss_6948[2][2][2];
extern MPVMCFunction lbl_12_bss_6968[2][2][2];

void fn_12_11F5C(MPVContext *context, u8 *destination, MPVBlockOffsets *offsets,
                 MPVPlaneSet *planes, MPVMotionInfo *motion) {
    void (* fzgx_live)(MPVContext *, u32);
    s32 chroma_stride;
    s32 luma_stride;
    s32 chroma_offset;
    s32 luma_offset;
    MPVMCContext *mc;
    MPVMCFunction chroma_function;
    MPVMCFunction luma_function;
    const u8 *reference;
    s32 vertical;
    s32 horizontal;
    MPVMCFunction (*chroma_table)[2];
    MPVMCFunction (*luma_table)[2];
    s32 mc_flag;

    mc_flag = context->mc_flag;
    luma_stride = planes->luma_stride;
    chroma_stride = planes->chroma_stride;
    fzgx_live = context->prepare;
    fzgx_live(context, context->prepare_arg);
    mc = &context->mc;
    luma_table = (*((mc_flag) + (lbl_12_bss_6948)));
    chroma_table = lbl_12_bss_6968[mc_flag];
    horizontal = motion->horizontal;
    vertical = motion->vertical;
    luma_offset = offsets->luma + (horizontal >> 1) + (vertical >> 1) * luma_stride;
{
    s32 luma_extra;
    luma_extra = (u32)horizontal & 1;
    luma_function = luma_table[vertical & 1][horizontal & 1];
    chroma_offset = offsets->chroma + ((horizontal / 2) >> 1) + ((vertical / 2) >> 1) * chroma_stride;
{
    s32 chroma_extra;
    chroma_extra = (u32)(horizontal / 2) & 1;
    chroma_function = chroma_table[(vertical / 2) & 1][(horizontal / 2) & 1];
    chroma_extra &= mc_flag;
    luma_extra &= mc_flag;
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
}
    chroma_function(mc);
    mc->reference_stride = luma_stride;
    mc->destination = destination + 0x80;
    reference = planes->planes[2] + luma_offset;
    mc->reference0 = reference;
    mc->reference1 = luma_stride + luma_extra + reference;
}
    luma_function(mc);
}
