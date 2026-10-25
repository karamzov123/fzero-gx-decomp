#include "types.h"

typedef struct GXContext {
    u8 pad[0x10];
    // Volatile mirrors hardware-owned context state.
    volatile u32 field_10;
} GXContext;

typedef struct CPReg {
    u8 pad[4];
    // Volatile mirrors the command processor register.
    volatile u16 value;
} CPReg;

extern GXContext* gx;
extern CPReg* __cpReg;

void __GXWriteFifoIntReset(u8 value, u8 mode) {
    GXContext* context = gx;
    context->field_10 = (context->field_10 & ~1u) | value;
    context->field_10 = (context->field_10 & ~2u) | ((u32)mode << 1);
    __cpReg->value = (u16)context->field_10;
}
