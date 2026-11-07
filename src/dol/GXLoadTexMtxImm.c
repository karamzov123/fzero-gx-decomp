#include "types.h"
#include "dolphin/gx.h"
#include "psvec_fifo.h"

void GXLoadTexMtxImm(const f32 mtx[3][4], u32 id, s32 type) {
    u32 command;
    u32 count;
    u32 addr;

    if (id >= 64) {
        addr = (id - 64) * 4 + 0x500;
    } else {
        addr = id * 4;
    }
    if (type == 1) {
        count = 8;
    } else {
        count = 12;
    }
    command = (count - 1) << 16;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = addr | command;
    if (type == 0) {
        WriteMTXPS4x3(mtx, &GXWGFifo);
    } else {
        WriteMTXPS4x2(mtx, &GXWGFifo);
    }
}
