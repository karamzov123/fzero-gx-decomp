#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct GXData {
    u16 unk_000;
    u16 bp_sent_not;
    u8 pad_004[0xf4];
    u32 su_scis0;
    u32 su_scis1;
    u8 pad_100[0x30];
    u32 tevc[16];
    u32 teva[16];
    u8 pad_1b0[0x20];
    u32 cmode0;
    u32 cmode1;
    u32 zmode;
} GXData;

typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} PPCWGPipe;

extern GXData *const gx;
volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = __rlwimi((reg), (val), (shift), 32 - (shift) - (size), 31 - (shift)))
#define GX_WRITE_RAS_REG(reg) \
    do { \
        GXWGFifo.u8 = 0x61; \
        GXWGFifo.u32 = (reg); \
    } while (0)

void GXGetScissor(u32 *left, u32 *top, u32 *width, u32 *height) {
    u32 y0 = gx->su_scis0 & 0x7ff;
    u32 x0 = (gx->su_scis0 & 0x7ff000) >> 12;
    u32 y1 = gx->su_scis1 & 0x7ff;
    u32 x1 = (gx->su_scis1 & 0x7ff000) >> 12;

    *left = x0 - 342;
    *top = y0 - 342;
    *width = x1 - x0 + 1;
    *height = y1 - y0 + 1;
}
