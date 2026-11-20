#include "types.h"


/* --- dol/fn_80038EEC.c --- */
extern u32 fn_80038DE8(u32);

u32 fn_80038EEC(void) {
    return fn_80038DE8(1);
}

/* --- dol/fn_80038F10.c --- */
typedef struct GXContext {
    u8 pad_0[0x43c];
    f32 field_43c;
    f32 field_440;
    f32 field_444;
    f32 field_448;
    f32 field_44c;
    f32 field_450;
} GXContext;

extern GXContext* gx;

void fn_80038F10(f32* out) {
    GXContext* context = gx;
    out[0] = context->field_43c;
    out[1] = context->field_440;
    out[2] = context->field_444;
    out[3] = context->field_448;
    out[4] = context->field_44c;
    out[5] = context->field_450;
}
