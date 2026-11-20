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
    (reg = __rlwimi(reg, val, shift, 32 - (shift) - size, 31 - shift))
#define GX_WRITE_RAS_REG(reg) \
    do { \
        GXWGFifo.u8 = 0x61; \
        GXWGFifo.u32 = (reg); \
    } while (0)

void fn_80037190(s32 stage, s32 op, s32 bias, s32 scale, u8 clamp, s32 out_reg) {
    u32 reg = gx->teva[stage];

    SET_REG_FIELD(reg, 1, 18, op & 1);
    if (op <= 1) {
        SET_REG_FIELD(reg, 2, 20, scale);
        SET_REG_FIELD(reg, 2, 16, bias);
    } else {
        SET_REG_FIELD(reg, 2, 20, (op >> 1) & 3);
        SET_REG_FIELD(reg, 2, 16, 3);
    }
    SET_REG_FIELD(reg, 1, 19, clamp);
    SET_REG_FIELD(reg, 2, 22, out_reg);
    GX_WRITE_RAS_REG(reg);
    gx->teva[stage] = reg;
    gx->bp_sent_not = 0;
}
