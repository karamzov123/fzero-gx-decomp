#include "types.h"
#include "dolphin/gx.h"
#include "psvec_fifo.h"

void GXLoadPosMtxImm(const f32 mtx[3][4], u32 id) {
    u32 reg;
    u32 addr;

    addr = id * 4;
    reg = addr | 0xB0000;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = reg;
    WriteMTXPS4x3(mtx, &GXWGFifo);
}
