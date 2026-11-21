#include "types.h"
#include "dolphin/hw_regs.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <types.h>
#include "sdk_addresses.h"

extern void GXSetTevIndirect(void *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4,
                         u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9);

void fn_80036EDC(void *arg0) {
    GXSetTevIndirect(arg0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))
#define GET_REG_FIELD(reg, size, shift) (((reg) >> (shift)) & ((1 << (size)) - 1))

void fn_80036F24(void) {
    u32 stage_count;
    u32 i;
    u32 tex_map;
    u32 new_mask;

    new_mask = 0;
    stage_count = GET_REG_FIELD(gx->genMode, 3, 16);
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
    if ((gx->bpMask & 0xff) != new_mask) {
        SET_REG_FIELD(gx->bpMask, 8, 0, new_mask);
        GX_WRITE_RAS_REG(gx->bpMask);
        gx->bpSentNot = 0;
    }
}

void __GXFlushTextureState(void) {
    GXWGFifo.u8 = 0x61;
    GXWGFifo.s32 = gx->bpMask;
    gx->bpSentNot = 0;
}
