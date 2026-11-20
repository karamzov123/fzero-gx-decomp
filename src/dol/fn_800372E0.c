#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct GXData {
    u16 unk_000;
    u16 bp_sent_not;
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
    (reg = ((reg) & ~(((1 << size) - 1) << shift)) | (val << shift))
#define GX_WRITE_RAS_REG(reg) \
    do { \
        GXWGFifo.u8 = 0x61; \
        GXWGFifo.u32 = (reg); \
    } while (0)

typedef struct GXColor {
    u8 r, g, b, a;
} GXColor;

void fn_800372E0(s32 id, GXColor color) {
    u32 reg_ra = 0;
    u32 reg_bg = 0;

    SET_REG_FIELD(reg_ra, 8, 0, color.r);
    SET_REG_FIELD(reg_ra, 8, 12, color.a);
    SET_REG_FIELD(reg_ra, 4, 20, 8);
    SET_REG_FIELD(reg_ra, 8, 24, 0xe0 + id * 2);
    SET_REG_FIELD(reg_bg, 8, 0, color.b);
    SET_REG_FIELD(reg_bg, 8, 12, color.g);
    SET_REG_FIELD(reg_bg, 4, 20, 8);
    SET_REG_FIELD(reg_bg, 8, 24, 0xe1 + id * 2);
    GX_WRITE_RAS_REG(reg_ra);
    GX_WRITE_RAS_REG(reg_bg);
    gx->bp_sent_not = 0;
}
