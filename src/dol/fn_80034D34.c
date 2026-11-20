#include "types.h"

typedef struct GXData {
    u8 pad_000[0x1ec];
    u32 word_1ec;
    u8 pad_1f0[0xc];
    u32 word_1fc;
} GXData;

extern GXData *const gx;

#define SET_REG_FIELD(reg, mask, shift, val) \
    (reg = ((reg) & ~(mask << shift)) | (val << shift))

void fn_80034D34(u32 flags) {
    u8 first = (flags & 1) == 1;
    u8 second = (flags & 2) == 2;

    SET_REG_FIELD(gx->word_1ec, 1, 0, first);
    SET_REG_FIELD(gx->word_1ec, 1, 1, second);
    SET_REG_FIELD(gx->word_1fc, 1, 0, first);
    SET_REG_FIELD(gx->word_1fc, 1, 1, second);
}
