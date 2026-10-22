#include <types.h>
#include "sdk_addresses.h"

typedef enum _GXIndTexMtxID {
    GX_ITM_OFF,
    GX_ITM_0,
    GX_ITM_1,
    GX_ITM_2,
    GX_ITM_S0 = 5,
    GX_ITM_S1,
    GX_ITM_S2,
    GX_ITM_T0 = 9,
    GX_ITM_T1,
    GX_ITM_T2,
} GXIndTexMtxID;

typedef struct _GXData {
    u16 vNumNot;
    u16 bpSentNot;
} GXData;

typedef union {
    u8 u8;
    u16 u16;
    u32 u32;
    u64 u64;
    s8 s8;
    s16 s16;
    s32 s32;
    s64 s64;
    f32 f32;
    f64 f64;
} PPCWGPipe;

extern GXData *const gx;

// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((u32)(val) << (shift)))

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
    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = reg;

    mtx[2] = (s32)(1024.0f * offset[0][1]) & 0x7FF;
    mtx[3] = (s32)(1024.0f * offset[1][1]) & 0x7FF;
    reg = 0;
    SET_REG_FIELD(reg, 11, 0, mtx[2]);
    SET_REG_FIELD(reg, 11, 11, mtx[3]);
    SET_REG_FIELD(reg, 2, 22, (scale_exp >> 2) & 3);
    SET_REG_FIELD(reg, 8, 24, id * 3 + 7);
    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = reg;

    mtx[4] = (s32)(1024.0f * offset[0][2]) & 0x7FF;
    mtx[5] = (s32)(1024.0f * offset[1][2]) & 0x7FF;
    reg = 0;
    SET_REG_FIELD(reg, 11, 0, mtx[4]);
    SET_REG_FIELD(reg, 11, 11, mtx[5]);
    SET_REG_FIELD(reg, 2, 22, (scale_exp >> 4) & 3);
    SET_REG_FIELD(reg, 8, 24, id * 3 + 8);
    GXFIFO.u8 = 0x61;
    GXFIFO.s32 = reg;

    gx->bpSentNot = 0;
}
