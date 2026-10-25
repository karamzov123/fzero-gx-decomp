#include "types.h"

// The PE register is memory-mapped hardware and must not be cached.
extern volatile u16 *__peReg;

void GXPokeColorUpdate(u8 value) {
    u16 current = __peReg[1];
    __peReg[1] = (u16)((current & ~(1 << 3)) | ((value & 0xFF) << 3));
}
