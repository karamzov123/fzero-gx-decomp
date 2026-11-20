#include "types.h"
#include "dolphin/hw_regs.h"


/* --- dol/fn_80037D14.c --- */
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

void fn_80037D14(u8 enable) {
    u32 reg = gx->cmode0;

    SET_REG_FIELD(reg, 1, 2, enable);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->cmode0 = reg;
    gx->bp_sent_not = 0;
}

/* --- dol/fn_80037D40.c --- */
#define SET_REG_FIELD(reg, size, shift, val) \
    (reg = __rlwimi(reg, val, shift, 32 - (shift) - size, 31 - shift))

void fn_80037D40(u8 enable, u8 alpha) {
    u32 reg = gx->cmode1;

    SET_REG_FIELD(reg, 8, 0, alpha);
    SET_REG_FIELD(reg, 1, 8, enable);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->cmode1 = reg;
    gx->bp_sent_not = 0;
}
