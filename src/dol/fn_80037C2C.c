#include "types.h"
#include "dolphin/hw_regs.h"

typedef struct GXData {
    u16 unk_000;
    u16 bp_sent_not;
    u8 pad_004[0x11c];
    u32 iref;
    u32 bp_mask;
    u8 pad_128[0xa8];
    u32 cmode0;
    u32 cmode1;
    u32 zmode;
    u32 pe_ctrl;
    u8 pad_1e0[0x24];
    u32 gen_mode;
    u8 pad_208[0x2ec];
    u32 dirty_state;
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
    (reg = ((reg) & ~(((1 << size) - 1) << shift)) | ((val) << shift))
#define GET_REG_FIELD(reg, size, shift) (((reg) >> (shift)) & ((1 << (size)) - 1))
#define GX_WRITE_RAS_REG(reg) \
    do { \
        GXWGFifo.u8 = 0x61; \
        GXWGFifo.u32 = (reg); \
    } while (0)

extern u32 lbl_8012B3E0[8];

void fn_80037C2C(s32 pix_fmt, s32 z_fmt) {
    u32 old_pe_ctrl;
    u8 aa;

    old_pe_ctrl = gx->pe_ctrl;
    SET_REG_FIELD(gx->pe_ctrl, 3, 0, lbl_8012B3E0[pix_fmt]);
    SET_REG_FIELD(gx->pe_ctrl, 3, 3, z_fmt);
    if (old_pe_ctrl != gx->pe_ctrl) {
        GX_WRITE_RAS_REG(gx->pe_ctrl);
        if (pix_fmt == 2) {
            aa = 1;
        } else {
            aa = 0;
        }
        SET_REG_FIELD(gx->gen_mode, 1, 9, aa);
        gx->dirty_state |= 4;
    }
    if (lbl_8012B3E0[pix_fmt] == 4) {
        SET_REG_FIELD(gx->cmode1, 2, 9, (pix_fmt - 4) & 3);
        SET_REG_FIELD(gx->cmode1, 8, 24, 0x42);
        GX_WRITE_RAS_REG(gx->cmode1);
    }
    gx->bp_sent_not = 0;
}
