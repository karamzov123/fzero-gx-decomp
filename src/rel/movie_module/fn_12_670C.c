#include "types.h"

s32 fn_12_670C(const u8 *data) {
    s32 value = (data[0] << 8) | data[1];

    value <<= 8;
    value |= data[2];
    value <<= 8;
    value |= data[3];

    switch (value - 0x1b9) {
    case 1:
        return 0x10000;
    case 2:
        return 0x20000;
    case 0:
        return 0x80000;
    case 4:
        return 0x40000;
    case 6:
        return 0x40000;
    case 5:
        return 0x40000;
    default:
        if (value >= 0x1c0 && value <= 0x1ef)
            return 0x40000;
        return 0;
    }
}

u32 fn_12_67A4(const u8 *data) {
    s32 value = (data[0] << 8) | data[1];

    value <<= 8;
    value |= data[2];
    value <<= 8;
    value |= data[3];

    switch (value) {
    case 0x1ba:
        return 0x10000;
    case 0x1bb:
        return 0x20000;
    case 0x1b9:
        return 0x80000;
    case 0x1bd:
        return 0x40000;
    case 0x1bf:
        return 0x40000;
    case 0x1be:
        return 0x40000;
    default:
        if (value >= 0x1c0 && value <= 0x1ef)
            return 0x40000;
        return 0;
    }
}
