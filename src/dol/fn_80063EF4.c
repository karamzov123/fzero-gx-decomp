#include "types.h"
#include "dol/globals.h"

s32 fn_80063EF4(u8 index, s8 positive, s8 negative) {
    s32 value;
    s32 factor;
    u8 *base;
    u32 offset;

    base = (u8 *)lbl_801A6C80;
    offset = (index & 0xFF) << 5;
    value = (base + offset)[0x599] - 0x40;
    if (value > 0) {
        value++;
        factor = positive << 8;
    } else if (value < 0) {
        factor = negative << 8;
    }
    return (value * factor) >> 6;
}
