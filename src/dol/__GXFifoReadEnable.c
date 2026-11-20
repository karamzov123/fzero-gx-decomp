#include "types.h"


/* --- dol/__GXFifoReadEnable.c --- */
typedef struct GXContext {
    u8 pad[8];
    // Hardware-owned state must be volatile so the write is emitted.
    volatile u32 field_8;
} GXContext;

typedef struct CPReg {
    u8 pad[2];
    // Hardware register access must be volatile.
    volatile u16 value;
} CPReg;

extern GXContext* gx;
extern CPReg* __cpReg;

void __GXFifoReadEnable(void) {
    GXContext* context = gx;
    u32 value = context->field_8;
    value &= ~1u;
    value |= 1u;
    context->field_8 = value;
    __cpReg->value = (u16)context->field_8;
}

/* --- dol/__GXFifoReadDisable.c --- */
void __GXFifoReadDisable(void) {
    GXContext* context = gx;
    context->field_8 &= ~1u;
    __cpReg->value = (u16)context->field_8;
}
