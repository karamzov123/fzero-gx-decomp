#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct GXData {
    u16 unk_000;
    u16 bp_sent_not;
    u8 pad_004[0x1cc];
    u32 cmode0;
} GXData;

extern GXData *const gx;

#define SET_REG_FIELD(reg, size, shift, val) \
    (reg = __rlwimi(reg, val, shift, 32 - (shift) - size, 31 - shift))

void fn_80037B68(u8 enable) {
    u32 reg = gx->cmode0;

    SET_REG_FIELD(reg, 1, 3, enable);
    *(volatile u8 *)GX_FIFO_BASE = 0x61;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    *(volatile u32 *)GX_FIFO_BASE = reg;  /* fzgx-allow: A2,S2 GX write-gather FIFO (hw_regs.h) */
    gx->cmode0 = reg;
    gx->bp_sent_not = 0;
}
