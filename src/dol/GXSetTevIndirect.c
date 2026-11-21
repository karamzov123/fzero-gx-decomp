#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <types.h>
#include "sdk_addresses.h"
#include "types.h"

void GXSetTevIndirect(GXTevStageID tevStage, GXIndTexStageID texStage, GXIndTexFormat texFmt,
                 GXIndTexBiasSel biasSel, GXIndTexMtxID mtxID, GXIndTexWrap wrapS,
                 GXIndTexWrap wrapT, u8 addPrev, u8 utcLod, GXIndTexAlphaSel alphaSel) {
    u32 field = 0;
    (field) = (field & ~(((1 << (2)) - 1) << (31 - (30) - (2) + 1))) |
              ((int)(texStage) << (31 - (30) - (2) + 1));
    (field) = (field & ~(((1 << (2)) - 1) << (31 - (28) - (2) + 1))) |
              ((int)(texFmt) << (31 - (28) - (2) + 1));
    (field) = (field & ~(((1 << (3)) - 1) << (31 - (25) - (3) + 1))) |
              ((int)(biasSel) << (31 - (25) - (3) + 1));
    (field) = (field & ~(((1 << (2)) - 1) << (31 - (23) - (2) + 1))) |
              ((int)(alphaSel) << (31 - (23) - (2) + 1));
    (field) = (field & ~(((1 << (4)) - 1) << (31 - (19) - (4) + 1))) |
              ((int)(mtxID) << (31 - (19) - (4) + 1));
    (field) = (field & ~(((1 << (3)) - 1) << (31 - (16) - (3) + 1))) |
              ((int)(wrapS) << (31 - (16) - (3) + 1));
    (field) = (field & ~(((1 << (3)) - 1) << (31 - (13) - (3) + 1))) |
              ((int)(wrapT) << (31 - (13) - (3) + 1));
    (field) = (field & ~(((1 << (1)) - 1) << (31 - (12) - (1) + 1))) |
              ((int)(utcLod) << (31 - (12) - (1) + 1));
    (field) = (field & ~(((1 << (1)) - 1) << (31 - (11) - (1) + 1))) |
              ((int)(addPrev) << (31 - (11) - (1) + 1));
    (field) = (field & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
              ((int)(tevStage + 0x10) << (31 - (0) - (8) + 1));
    GXWGFifo.u8 = 0x61;
    GXWGFifo.s32 = field;
    gx->bpSentNot = 0;
}

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))

void fn_80036AC4(GXIndTexMtxID mtx_id, const f32 offset[2][3], s8 scale_exp) {
    s32 mtx[6];
    u32 reg;
    u32 id;

    switch (mtx_id) {
    case GX_ITM_0:
    case GX_ITM_1:
    case GX_ITM_2:
        id = mtx_id - 1;
        break;
    case GX_ITM_S0:
    case GX_ITM_S1:
    case GX_ITM_S2:
        id = mtx_id - 5;
        break;
    case GX_ITM_T0:
    case GX_ITM_T1:
    case GX_ITM_T2:
        id = mtx_id - 9;
        break;
    default:
        id = 0;
        break;
    }

    mtx[0] = (s32)(1024.0f * offset[0][0]) & 0x7FF;
    mtx[1] = (s32)(1024.0f * offset[1][0]) & 0x7FF;
    scale_exp += 0x11;
    reg = 0;
    SET_REG_FIELD(reg, 11, 0, mtx[0]);
    SET_REG_FIELD(reg, 11, 11, mtx[1]);
    SET_REG_FIELD(reg, 2, 22, scale_exp & 3);
    SET_REG_FIELD(reg, 8, 24, id * 3 + 6);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.s32 = reg;

    mtx[2] = (s32)(1024.0f * offset[0][1]) & 0x7FF;
    mtx[3] = (s32)(1024.0f * offset[1][1]) & 0x7FF;
    reg = 0;
    SET_REG_FIELD(reg, 11, 0, mtx[2]);
    SET_REG_FIELD(reg, 11, 11, mtx[3]);
    SET_REG_FIELD(reg, 2, 22, (scale_exp >> 2) & 3);
    SET_REG_FIELD(reg, 8, 24, id * 3 + 7);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.s32 = reg;

    mtx[4] = (s32)(1024.0f * offset[0][2]) & 0x7FF;
    mtx[5] = (s32)(1024.0f * offset[1][2]) & 0x7FF;
    reg = 0;
    SET_REG_FIELD(reg, 11, 0, mtx[4]);
    SET_REG_FIELD(reg, 11, 11, mtx[5]);
    SET_REG_FIELD(reg, 2, 22, (scale_exp >> 4) & 3);
    SET_REG_FIELD(reg, 8, 24, id * 3 + 8);
    GXWGFifo.u8 = 0x61;
    GXWGFifo.s32 = reg;

    gx->bpSentNot = 0;
}

void GXSetIndTexCoordScale(GXIndTexStageID texStage, GXIndTexScale scaleS, GXIndTexScale scaleT) {
    GXData *data;
    switch (texStage) {
    case GX_INDTEXSTAGE0:
        data = gx;
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (4)) - 1) << (31 - (28) - (4) + 1))) |
                               ((int)(scaleS) << (31 - (28) - (4) + 1));
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (4)) - 1) << (31 - (24) - (4) + 1))) |
                               ((int)(scaleT) << (31 - (24) - (4) + 1));
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                               ((int)(0x25) << (31 - (0) - (8) + 1));
        GXWGFifo.u8 = 0x61;
        GXWGFifo.s32 = data->IndTexScale0;
        break;
    case GX_INDTEXSTAGE1:
        data = gx;
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (4)) - 1) << (31 - (20) - (4) + 1))) |
                               ((int)(scaleS) << (31 - (20) - (4) + 1));
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (4)) - 1) << (31 - (16) - (4) + 1))) |
                               ((int)(scaleT) << (31 - (16) - (4) + 1));
        (data->IndTexScale0) = (data->IndTexScale0 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                               ((int)(0x25) << (31 - (0) - (8) + 1));
        GXWGFifo.u8 = 0x61;
        GXWGFifo.s32 = data->IndTexScale0;
        break;
    case GX_INDTEXSTAGE2:
        data = gx;
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (4)) - 1) << (31 - (28) - (4) + 1))) |
                               ((int)(scaleS) << (31 - (28) - (4) + 1));
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (4)) - 1) << (31 - (24) - (4) + 1))) |
                               ((int)(scaleT) << (31 - (24) - (4) + 1));
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                               ((int)(0x26) << (31 - (0) - (8) + 1));
        GXWGFifo.u8 = 0x61;
        GXWGFifo.s32 = data->IndTexScale1;
        break;
    case GX_INDTEXSTAGE3:
        data = gx;
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (4)) - 1) << (31 - (20) - (4) + 1))) |
                               ((int)(scaleS) << (31 - (20) - (4) + 1));
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (4)) - 1) << (31 - (16) - (4) + 1))) |
                               ((int)(scaleT) << (31 - (16) - (4) + 1));
        (data->IndTexScale1) = (data->IndTexScale1 & ~(((1 << (8)) - 1) << (31 - (0) - (8) + 1))) |
                               ((int)(0x26) << (31 - (0) - (8) + 1));
        GXWGFifo.u8 = 0x61;
        GXWGFifo.s32 = data->IndTexScale1;
        break;
    }
    gx->bpSentNot = 0;
}

static inline void GXSetWasteFlags() {
    GXData *data = gx;
    data->dirtyState |= GX_DIRTY_SU_TEX | GX_DIRTY_BP_MASK;
    data->bpSentNot = 0;
}

void GXSetIndTexOrder(GXIndTexStageID stage, GXTexCoordID coord, GXTexMapID map) {
    switch (stage) {
    case GX_INDTEXSTAGE0:
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (29) - (3) + 1))) |
                     ((int)(map) << (31 - (29) - (3) + 1));
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (26) - (3) + 1))) |
                     ((int)(coord) << (31 - (26) - (3) + 1));
        break;
    case GX_INDTEXSTAGE1:
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (23) - (3) + 1))) |
                     ((int)(map) << (31 - (23) - (3) + 1));
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (20) - (3) + 1))) |
                     ((int)(coord) << (31 - (20) - (3) + 1));
        break;
    case GX_INDTEXSTAGE2:
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (17) - (3) + 1))) |
                     ((int)(map) << (31 - (17) - (3) + 1));
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (14) - (3) + 1))) |
                     ((int)(coord) << (31 - (14) - (3) + 1));
        break;
    case GX_INDTEXSTAGE3:
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (11) - (3) + 1))) |
                     ((int)(map) << (31 - (11) - (3) + 1));
        (gx->iref) = (gx->iref & ~(((1 << (3)) - 1) << (31 - (8) - (3) + 1))) |
                     ((int)(coord) << (31 - (8) - (3) + 1));
        break;
    }
    GXWGFifo.u8 = 0x61;
    GXWGFifo.s32 = gx->iref;
    GXSetWasteFlags();
}

struct GXState {
    u8 pad_000[0x204];
    u32 state_204;
    u8 pad_208[0x2EC];
    u32 state_4F4;
};

void GXSetNumIndStages(u32 arg0) {
    struct GXState *state = (struct GXState *)gx;
    state->state_204 = (state->state_204 & 0xFFF8FFFF) | ((arg0 & 0xFF) << 16);
    state->state_4F4 |= 6;
}
