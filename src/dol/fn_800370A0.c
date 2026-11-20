#include "types.h"
#include "dolphin/hw_regs.h"


/* --- dol/fn_800370A0.c --- */
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

extern GXData *const gx;

#define SET_REG_FIELD(reg, size, shift, val) \
    (reg = __rlwimi(reg, val, shift, 32 - (shift) - size, 31 - shift))

void fn_800370A0(s32 stage, s32 a, s32 b, s32 c, s32 d) {
    u32 reg = gx->tevc[stage];

    SET_REG_FIELD(reg, 4, 12, a);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    SET_REG_FIELD(reg, 4, 8, b);
    SET_REG_FIELD(reg, 4, 4, c);
    SET_REG_FIELD(reg, 4, 0, d);
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->tevc[stage] = reg;
    gx->bp_sent_not = 0;
}

/* --- dol/fn_800370E4.c --- */
typedef union PPCWGPipe {
    u8 u8;
    u16 u16;
    u32 u32;
    f32 f32;
} PPCWGPipe;

volatile PPCWGPipe GXWGFifo : GX_FIFO_BASE;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */

#define SET_REG_FIELD(reg, size, shift, val) \
    (reg = __rlwimi(reg, val, shift, 32 - (shift) - size, 31 - shift))
#define GX_WRITE_RAS_REG(reg) \
    do { \
        GXWGFifo.u8 = 0x61; \
        GXWGFifo.u32 = (reg); \
    } while (0)

void fn_800370E4(s32 stage, s32 a, s32 b, s32 c, s32 d) {
    u32 reg = gx->teva[stage];

    SET_REG_FIELD(reg, 3, 13, a);
    SET_REG_FIELD(reg, 3, 10, b);
    SET_REG_FIELD(reg, 3, 7, c);
    SET_REG_FIELD(reg, 3, 4, d);
    GX_WRITE_RAS_REG(reg);
    gx->teva[stage] = reg;
    gx->bp_sent_not = 0;
}
