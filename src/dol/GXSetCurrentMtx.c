#include "types.h"

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
