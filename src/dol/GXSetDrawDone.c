#include <types.h>
#include <dolphin/os/OSInterrupt.h>
#include "sdk_addresses.h"
#include <dolphin/gx/GXPriv.h>

void GXFlush(void);

void fn_8003458C(void);
// Hardware or OS state can change asynchronously.
volatile PPCWGPipe
    GXFIFO : FZGX_ADDR_GXFIFO; // fzgx-allow: S2 SDK asynchronous state

void fn_80009FF4(void);

static inline void GXFlush(void) {
    if (gx->dirtyState) {
        fn_8003458C();
    }
    GXFIFO.u32 = 0;
    GXFIFO.u32 = 0;
    GXFIFO.u32 = 0;
    GXFIFO.u32 = 0;
    GXFIFO.u32 = 0;
    GXFIFO.u32 = 0;
    GXFIFO.u32 = 0;
    GXFIFO.u32 = 0;
    fn_80009FF4();
}

extern GXBool lbl_801A6C18;

void GXSetDrawDone(void) {
    u8 padding[8];
    BOOL restore = OSDisableInterrupts();
    do {
        GXFIFO.u8 = (u8)(0x61);
        GXFIFO.u32 = (u32)(0x45000002);
        ;
    } while (0);
    GXFlush();
    lbl_801A6C18 = 0;
    OSRestoreInterrupts(restore);
}
