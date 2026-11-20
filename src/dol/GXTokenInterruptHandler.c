#include "types.h"


/* --- dol/GXTokenInterruptHandler.c --- */
// The PE register is memory-mapped hardware and must not be cached.
extern volatile u16 *__peReg;
extern void (*lbl_801A6C10)(u16);
extern void OSClearContext(void *);
extern void OSSetCurrentContext(void *);

void GXTokenInterruptHandler(u32 arg0, void *context) {
    u16 current;
    u8 local_context[0x2c8];

    current = __peReg[7];
    if (lbl_801A6C10 != 0) {
        OSClearContext(local_context);
        OSSetCurrentContext(local_context);
        lbl_801A6C10(current);
        OSClearContext(local_context);
        OSSetCurrentContext(context);
    }
    __peReg[5] = (u16)((__peReg[5] & ~4u) | 4);
}

/* --- dol/fn_80034444.c --- */
extern u32 OSDisableInterrupts(u32);
extern u32 OSRestoreInterrupts(u32);
extern u32 lbl_801A6C14;

u32 fn_80034444(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = lbl_801A6C14;
    t0 = OSDisableInterrupts(arg0);
    lbl_801A6C14 = arg0;
    OSRestoreInterrupts(t0);
    return v0;
}
