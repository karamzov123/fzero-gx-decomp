#include "types.h"
#include "dol/globals.h"

extern s32 fn_80067898(u32);

s32 fn_80063094(s32 arg0, s32 arg1, s32 arg2) {
    u32 v0 = (arg0 & 0xF) << 16;
    u8 *p = (u8 *)(v0 + arg1);
    s32 r;

    switch (arg1) {
    case 0xA5000000:
        r = fn_80067898((u32)((u8 *)(v0 - 0x5A900000) + (arg2 & 0x7F00)));
        if (r != 0)
            return r;
        p = (u8 *)(v0 - 0x5B000000) + ((arg2 & 0x7F) << 8);
        break;
    case 0xA5100000:
        p += (arg2 & 0x7F) << 8;
        break;
    case 0xA5200000:
    case 0xA5300000:
    case 0xA5400000:
    case 0xA5500000:
    case 0xA7000000:
    case 0xA7100000:
        p += ((arg2 + 0x40) & 0x7F) << 8;
        break;
    case 0xA6000000:
        p += ((arg2 & 0x7F) << 8) + ((arg2 << 13) & 0x100000);
        break;
    case 0xA7200000: {
        u8 *q = (u8 *)lbl_801A6C80;
        q += (arg0 & 0xF) << 1;
        *(u16 *)(q + 0x5AF4) = arg2;
        break;
    }
    default:
        return -2;
    }
    return fn_80067898((u32)p);
}


