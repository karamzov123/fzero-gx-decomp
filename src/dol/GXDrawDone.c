#include "types.h"
#include <dolphin/gx.h>
#include <dolphin/gx/GXPriv.h>

extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern u32 OSSleepThread(u32);
extern u32 lbl_801A6C1C;
extern u8 lbl_801A6C18;
extern void GXFlush(void);

void GXDrawDone(u32 lab_unused0) {
    u32 t0, t3;
    t0 = OSDisableInterrupts();
    *(u8 *)((u8 *)0xCC010000 + -32768) = 97;  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    *(u32 *)((u8 *)0xCC010000 + -32768) = (0x45000000 + 2);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
    GXFlush();
    lbl_801A6C18 = 0;
    OSRestoreInterrupts(t0);
    t3 = OSDisableInterrupts();
    while (lbl_801A6C18 == 0) {
    OSSleepThread((u32)&lbl_801A6C1C);
    }
    OSRestoreInterrupts(t3);
}

// Hardware register block pointer; accesses must not be cached.
extern volatile u16 *__peReg;

void GXPokeAlphaMode(u32 arg0, u32 arg1) {
    __peReg[3] = (u16)((arg0 << 8) | (arg1 & 0xFF));
}
