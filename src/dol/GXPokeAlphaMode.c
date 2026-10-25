#include "types.h"

 // Hardware register block pointer; accesses must not be cached.
extern volatile u16 *__peReg;

void GXPokeAlphaMode(u32 arg0, u32 arg1) {
    __peReg[3] = (u16)((arg0 << 8) | (arg1 & 0xFF));
}
