#include "types.h"
#include "dolphin/gx.h"
#include "psvec_fifo.h"


/* --- dol/GXGetProjectionv.c --- */
typedef struct GXContext {
    u8 pad_0[0x420];
    u32 field_420;
    f32 field_424;
    f32 field_428;
    f32 field_42c;
    f32 field_430;
    f32 field_434;
    f32 field_438;
} GXContext;

extern GXContext* gx;
extern f64 lbl_801A7168;

void GXGetProjectionv(f32* out) {
    GXContext* context = gx;
    out[0] = (f32)context->field_420;
    out[1] = context->field_424;
    out[2] = context->field_428;
    out[3] = context->field_42c;
    out[4] = context->field_430;
    out[5] = context->field_434;
    out[6] = context->field_438;
}

/* --- dol/GXLoadPosMtxImm.c --- */
void GXLoadPosMtxImm(const f32 mtx[3][4], u32 id) {
    u32 reg;
    u32 addr;

    addr = id * 4;
    reg = addr | 0xB0000;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = reg;
    WriteMTXPS4x3(mtx, &GXWGFifo);
}
