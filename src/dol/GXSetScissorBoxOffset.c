#include "types.h"

typedef struct GXContext {
    u8 pad_0[2];
    u16 field_2;
} GXContext;

extern GXContext* gx;

#pragma opt_propagation off
#pragma opt_common_subs off
u32 GXSetScissorBoxOffset(s32 x, s32 y) {
    u32 temp = ((u32)(x + 0x156) >> 1) & 0xfff003ff;
    GXContext* context = gx;
    u32 value = (temp | (((u32)(y + 0x156) >> 1) << 10)) & 0x00ffffff;
    *(volatile u8 *)((u8 *)0xCC010000 + -32768) = 0x61; /* fzgx-allow: A1,A2 GX FIFO hardware register */
    value |= 0x59000000;
    *(volatile u32 *)((u8 *)0xCC010000 + -32768) = value; /* fzgx-allow: A1,A2 GX FIFO hardware register */
    context->field_2 = 0;
    return (u32)context;
}
#pragma opt_common_subs reset

#pragma opt_propagation reset

