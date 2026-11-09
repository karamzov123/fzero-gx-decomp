#include "types.h"
#include "dolphin/gx.h"
#include "psvec_fifo.h"

void GXLoadNrmMtxImm(const f32 mtx[3][4], u32 id) {
    u32 reg;
    u32 addr;

    addr = id * 3 + 0x400;
    reg = addr | 0x80000;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = reg;
    WriteMTXPS3x3from3x4(mtx, &GXWGFifo);
}
