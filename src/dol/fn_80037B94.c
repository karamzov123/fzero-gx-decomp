#include "types.h"
#include "dolphin/hw_regs.h"


/* --- dol/fn_80037B94.c --- */
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

void fn_80037B94(u8 enable) {
    u32 reg = gx->cmode0;

    SET_REG_FIELD(reg, 1, 4, enable);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->cmode0 = reg;
    gx->bp_sent_not = 0;
}

/* --- dol/fn_80037BC0.c --- */
#define SET_REG_FIELD(reg, size, shift, val) \
    (reg = __rlwimi(reg, val, shift, 32 - (shift) - size, 31 - shift))

void fn_80037BC0(u8 compare_enable, s32 func, u8 update_enable) {
    u32 reg = gx->zmode;

    SET_REG_FIELD(reg, 1, 0, compare_enable);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    SET_REG_FIELD(reg, 3, 1, func);
    SET_REG_FIELD(reg, 1, 4, update_enable);
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->zmode = reg;
    gx->bp_sent_not = 0;
}
