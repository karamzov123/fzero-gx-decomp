#include "types.h"

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

void __GXFifoLink(u8 value) {
    GXContext* context;
    u32 enabled;
    if (value) {
        enabled = 1;
    } else {
        enabled = 0;
    }
    context = gx;
    context->field_8 = (context->field_8 & ~(1u << 4)) | (enabled << 4);
    __cpReg->value = (u16)context->field_8;
}
