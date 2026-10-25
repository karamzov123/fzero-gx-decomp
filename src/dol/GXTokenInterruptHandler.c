#include "types.h"

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
