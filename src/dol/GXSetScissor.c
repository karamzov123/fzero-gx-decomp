#include <types.h>
#include "sdk_addresses.h"

typedef u8 GXBool;

typedef enum _GXFifoCmd {
    GX_FIFO_CMD_NOOP = 0x00,
    GX_FIFO_CMD_LOAD_BP_REG = 0x61,
    GX_FIFO_CMD_LOAD_CP_REG = 0x08,
    GX_FIFO_CMD_LOAD_XF_REG = 0x10,
    GX_FIFO_CMD_LOAD_INDX_A = 0x20,
    GX_FIFO_CMD_LOAD_INDX_B = 0x28,
    GX_FIFO_CMD_LOAD_INDX_C = 0x30,
    GX_FIFO_CMD_LOAD_INDX_D = 0x38,
    GX_FIFO_CMD_CALL_DL = 0x40,
    GX_FIFO_CMD_INVAL_VTX = 0x48,
} GXFifoCmd;

typedef enum _GXBPScissorTL {
    GX_BP_SCISSORTL_TOP_ST = 0,
    GX_BP_SCISSORTL_TOP_END = 10,
    GX_BP_SCISSORTL_LEFT_ST = 12,
    GX_BP_SCISSORTL_LEFT_END = 22,
} GXBPScissorTL;

typedef enum _GXBPScissorBR {
    GX_BP_SCISSORBR_BOT_ST = 0,
    GX_BP_SCISSORBR_BOT_END = 10,
    GX_BP_SCISSORBR_RIGHT_ST = 12,
    GX_BP_SCISSORBR_RIGHT_END = 22,
} GXBPScissorBR;

typedef struct _GXData {
    u16 vNumNot;
    u16 bpSentNot;
    u16 vNum;
    u16 vLim;
    u32 cpEnable;
    u32 cpStatus;
    u32 cpClr;
    u32 vcdLo;
    u32 vcdHi;
    u32 vatA[8];
    u32 vatB[8];
    u32 vatC[8];
    u32 lpSize;
    u32 matIdxA;
    u32 matIdxB;
    u32 indexBase[4];
    u32 indexStride[4];
    u32 ambColor[2];
    u32 matColor[2];
    u32 suTs0[8];
    u32 suTs1[8];
    u32 suScis0;
    u32 suScis1;
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

volatile PPCWGPipe GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

#define MASK(bitCount, bitShift) ((u32)(((1 << (bitCount)) - 1) << (bitShift)))

void GXSetScissor(u32 left, u32 top, u32 width, u32 height) {
    u32 y1, x1, y2, x2;

    y1 = top + 342;
    x1 = left + 342;
    y2 = y1 + height - 1;
    x2 = x1 + width - 1;
    (gx->suScis0) = (gx->suScis0 & ~MASK(11, GX_BP_SCISSORTL_TOP_ST)) | y1;
    (gx->suScis0) = (gx->suScis0 & ~MASK(11, GX_BP_SCISSORTL_LEFT_ST)) | (x1 << GX_BP_SCISSORTL_LEFT_ST);
    (gx->suScis1) = (gx->suScis1 & ~MASK(11, GX_BP_SCISSORBR_BOT_ST)) | y2;
    (gx->suScis1) = (gx->suScis1 & ~MASK(11, GX_BP_SCISSORBR_RIGHT_ST)) | (x2 << GX_BP_SCISSORBR_RIGHT_ST);
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (gx->suScis0);
    ;
    GXFIFO.s8 = GX_FIFO_CMD_LOAD_BP_REG;
    GXFIFO.s32 = (gx->suScis1);
    ;
    gx->bpSentNot = 0;
}
