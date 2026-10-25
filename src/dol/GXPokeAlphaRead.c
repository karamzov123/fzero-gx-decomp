#include "types.h"

struct fn_80034200___peReg_T {
    u8 pad_0[0x8];
    u16 unk_8;
};

extern struct fn_80034200___peReg_T *__peReg;

void GXPokeAlphaRead(u32 arg0) {
    u32 v0;
    v0 = (arg0 & 0xFFFFFFFB);
    __peReg->unk_8 = (v0 | 4);
}
