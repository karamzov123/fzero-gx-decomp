#include "types.h"
#include "dolphin/gx.h"
#include "psvec_fifo.h"

struct fn_800356B8_gx_T {
    u8 pad_0[0x2];
    u16 unk_2;
};
extern struct fn_800356B8_gx_T *gx;

void fn_800356B8(void *light_obj, u32 light_id) {
    u32 index;
    u32 addr;

    index = 31 - __cntlzw(light_id);
    addr = (index & 7) * 16 + 0x600;
    GXWGFifo.u8 = 0x10;
    GXWGFifo.u32 = addr | 0xF0000;
    WriteLightObjPS(light_obj, &GXWGFifo);
    gx->unk_2 = 1;
}
