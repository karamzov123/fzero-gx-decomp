#include "types.h"

typedef struct GXContext {
    u8 pad[8];
    // Hardware-owned state must be volatile so each access is emitted.
    volatile u32 field_8;
} GXContext;

typedef struct CPReg {
    u8 pad[2];
    // Hardware register access must be volatile.
    volatile u16 value;
} CPReg;

extern GXContext* gx;
extern CPReg* __cpReg;

void __GXWriteFifoIntEnable(u32 arg0, u32 arg1) {
    GXContext* context = gx;
    u32 mode = (arg0 & 0xffu) << 2;
    u32 flags = (arg1 & 0xffu) << 3;

    context->field_8 = (context->field_8 & ~4u) | mode;
    context->field_8 = (context->field_8 & ~8u) | flags;
    __cpReg->value = (u16)context->field_8;
}
