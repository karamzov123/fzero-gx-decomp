#include "types.h"
#include "dolphin/gx.h"
#include "psvec_fifo.h"


/* --- dol/GXLoadNrmMtxImm.c --- */
void GXLoadNrmMtxImm(const f32 mtx[3][4], u32 id) {
    u32 reg;
    u32 addr;

    addr = id * 3 + 0x400;
    reg = addr | 0x80000;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = reg;
    WriteMTXPS3x3from3x4(mtx, &GXWGFifo);
}

/* --- dol/GXSetCurrentMtx.c --- */
/* --- dol/GXSetCurrentMtx.c --- */
typedef struct GXContext {
    u8 pad_0[0x80];
    u32 field_80;
} GXContext;

extern GXContext* gx;
extern void __GXSetMatrixIndex(u32);

void GXSetCurrentMtx(u32 value) {
    GXContext* context = gx;
    context->field_80 = (context->field_80 & ~0x3fu) | value;
    __GXSetMatrixIndex(0);
}

/* --- dol/GXLoadTexMtxImm.c --- */
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
