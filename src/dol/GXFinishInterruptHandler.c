#include "types.h"

// The PE register is memory-mapped hardware and must not be cached.
extern volatile u16 *__peReg;
extern void (*lbl_801A6C14)(void);
extern u8 lbl_801A6C18;
extern void OSClearContext(void *);
extern void OSSetCurrentContext(void *);
extern u32 lbl_801A6C1C;
extern void OSWakeupThread(void *);

void GXFinishInterruptHandler(void *unused, void *context) {
    u16 current;
    u8 os_context[0x2c8];

    current = __peReg[5];
    __peReg[5] = (u16)((current & ~8u) | 8);
    lbl_801A6C18 = 1;

    if (lbl_801A6C14 != 0) {
        OSClearContext(os_context);
        OSSetCurrentContext(os_context);
        lbl_801A6C14();
        OSClearContext(os_context);
        OSSetCurrentContext(context);
    }

    OSWakeupThread(&lbl_801A6C1C);
}
