#include "types.h"
#include "dolphin/hw_regs.h"


/* --- dol/fn_80036EDC.c --- */
extern void GXSetTevIndirect(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4,
                         u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9);

void fn_80036EDC(void *arg0) {
    GXSetTevIndirect(arg0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

/* --- dol/fn_80036F24.c --- */
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
    (reg = ((reg) & ~(((1 << size) - 1) << shift)) | (val << shift))
#define GET_REG_FIELD(reg, size, shift) (((reg) >> (shift)) & ((1 << (size)) - 1))
#define GX_WRITE_RAS_REG(reg) \
    do { \
        GXWGFifo.u8 = 0x61; \
        GXWGFifo.u32 = (reg); \
    } while (0)

void fn_80036F24(void) {
    u32 stage_count;
    u32 i;
    u32 tex_map;
    u32 new_mask;

    new_mask = 0;
    stage_count = GET_REG_FIELD(gx->gen_mode, 3, 16);
    for (i = 0; i < stage_count; i++) {
        switch (i) {
        case 0:
            tex_map = GET_REG_FIELD(gx->iref, 3, 0);
            break;
        case 1:
            tex_map = GET_REG_FIELD(gx->iref, 3, 6);
            break;
        case 2:
            tex_map = GET_REG_FIELD(gx->iref, 3, 12);
            break;
        case 3:
            tex_map = GET_REG_FIELD(gx->iref, 3, 18);
            break;
        }
        new_mask |= 1 << tex_map;
    }
    if ((gx->bp_mask & 0xff) != new_mask) {
        SET_REG_FIELD(gx->bp_mask, 8, 0, new_mask);
        GX_WRITE_RAS_REG(gx->bp_mask);
        gx->bp_sent_not = 0;
    }
}
