#include "types.h"

#define GX_FIFO_ADDR ((volatile void*)0xCC008000) // fzgx-allow: A1 hardware FIFO register  /* fzgx-allow: A2 unnamed OS/hardware memory */

typedef struct GXContext {
    u8 pad_0[2];
    u16 field_2;
    u8 pad_4[0x41c];
    u32 field_420;
    f32 field_424;
    f32 field_428;
    f32 field_42c;
    f32 field_430;
    f32 field_434;
    f32 field_438;
} GXContext;

extern GXContext* gx;
extern u32 __cvt_fp2unsigned(f32);

void GXSetProjectionv(f32* values) {
    u32 first = __cvt_fp2unsigned(values[0]);
    GXContext* context = gx;

    context->field_420 = first;
    context->field_424 = values[1];
    context->field_428 = values[2];
    context->field_42c = values[3];
    context->field_430 = values[4];
    context->field_434 = values[5];
    context->field_438 = values[6];

    *(volatile u8*)GX_FIFO_ADDR = 0x10;  /* fzgx-allow: S2 memory-mapped register */
    *(volatile u32*)GX_FIFO_ADDR = 0x00061020;  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->field_424;  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->field_428;  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->field_42c;  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->field_430;  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->field_434;  /* fzgx-allow: S2 memory-mapped register */
    *(volatile f32*)GX_FIFO_ADDR = context->field_438;  /* fzgx-allow: S2 memory-mapped register */
    *(volatile u32*)GX_FIFO_ADDR = context->field_420;  /* fzgx-allow: S2 memory-mapped register */
    context->field_2 = 1;
}
