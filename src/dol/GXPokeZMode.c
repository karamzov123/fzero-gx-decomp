#include "types.h"

// The PE register is memory-mapped hardware and must not be cached.
extern volatile u16 *__peReg;

void GXPokeZMode(u32 arg0, u32 arg1, u32 arg2) {
    u32 value;
    value = arg0 & 0xFF;
    value = (value & ~(7u << 1)) | (arg1 << 1);
    value = (value & ~(1u << 4)) | ((arg2 & 0xFF) << 4);
    *__peReg = (u16)value;
}
