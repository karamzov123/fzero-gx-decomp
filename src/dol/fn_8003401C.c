#include "types.h"
#include "dolphin/hw_regs.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>
#include <dolphin/os/OSInterrupt.h>
#include <types.h>
#include "sdk_addresses.h"

#define SET_REG_FIELD(reg, size, shift, val) \
    ((reg) = ((reg) & ~(((1 << (size)) - 1) << (shift))) | ((val) << (shift)))
#define GET_REG_FIELD(reg, size, shift) (((reg) >> (shift)) & ((1 << (size)) - 1))

extern void fn_8003458C(void);
extern void fn_80009FF4(void);

static inline void GXFlush(void) {
    if (gx->dirtyState != 0) {
        fn_8003458C();
    }
    GXWGFifo.u32 = 0;
    GXWGFifo.u32 = 0;
    GXWGFifo.u32 = 0;
    GXWGFifo.u32 = 0;
    GXWGFifo.u32 = 0;
    GXWGFifo.u32 = 0;
    GXWGFifo.u32 = 0;
    GXWGFifo.u32 = 0;
    fn_80009FF4();
}

void fn_8003401C(u16 token) {
    s32 enabled;
    u32 reg;

    enabled = OSDisableInterrupts();
    reg = token | 0x48000000;
    GX_WRITE_RAS_REG(reg);
    SET_REG_FIELD(reg, 16, 0, token);
    SET_REG_FIELD(reg, 8, 24, 0x47);
    GX_WRITE_RAS_REG(reg);
    GXFlush();
    OSRestoreInterrupts(enabled);
    gx->bpSentNot = 0;
}

void GXFlush(void);

extern GXBool lbl_801A6C18;

void GXSetDrawDone(void) {
    u8 padding[8];
    BOOL restore = OSDisableInterrupts();
    do {
        GXWGFifo.u8 = (u8)(0x61);
        GXWGFifo.u32 = (u32)(0x45000002);
        ;
    } while (0);
    GXFlush();
    lbl_801A6C18 = 0;
    OSRestoreInterrupts(restore);
}
