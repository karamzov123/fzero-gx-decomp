#include "types.h"

extern u32 __OSSetInterruptHandler(u32, u32);
extern u32 OSInitThreadQueue(void *);
extern u32 __OSUnmaskInterrupts(u32);
extern void GXTokenInterruptHandler(void);
extern void GXFinishInterruptHandler(void);
extern u32 lbl_801A6C1C;
// PE register block is memory-mapped hardware and must be accessed volatile.
extern volatile u16 *__peReg;

void __GXPEInit(void) {
    u32 current;

    __OSSetInterruptHandler(0x12, (u32)GXTokenInterruptHandler);
    __OSSetInterruptHandler(0x13, (u32)GXFinishInterruptHandler);
    OSInitThreadQueue(&lbl_801A6C1C);
    __OSUnmaskInterrupts(0x2000);
    __OSUnmaskInterrupts(0x1000);

    current = __peReg[5];
    current = (current & ~0x4u) | 0x4u;
    current = (current & ~0x8u) | 0x8u;
    current = (current & ~0x1u) | 0x1u;
    current = (current & ~0x2u) | 0x2u;
    __peReg[5] = current;
}
