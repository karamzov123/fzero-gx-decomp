#include "types.h"
#include <dolphin/os/OSInterrupt.h>


/* --- dol/fn_800672E4.c --- */
extern u32 lbl_801A6C80;

s32 fn_800672E4(u32 arg0, s32 arg1) {
    u8 *base;
    u32 offset;
    if (arg0 >= 0x10) {
        return -0x80;
    }
    switch (arg1) {
    case (s32)0xA0040000:
        base = (u8 *)lbl_801A6C80;
        offset = arg0 << 4;
        return base[offset + 0x492];
    case (s32)0xA0100000:
        base = (u8 *)lbl_801A6C80;
        offset = arg0 << 4;
        return base[offset + 0x493];
    default:
        return -0x80;
    }
}

/* --- dol/fn_80067344.c --- */
extern u32 lbl_801A6C78;

s32 fn_80067344(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u8 *p;
    s32 ret;
    s32 val;

    val = (0x1F & arg0) + ((((arg1 - 1) & 0xF) << 24));
    val = val + arg2;
    if (arg2 != 0) {
        switch (arg2) {
        case 0xB0780000:
            break;
        case 0xB0270000:
        case 0xB0070000:
        case 0xB00D0000:
        case 0xB00E0000:
        case 0xB02D0000:
        case 0xB02E0000:
            val += (arg3 & 0x7F) << 8;
            break;
        case 0xA0110000:
        case 0xB00A0000:
        case 0xB02A0000:
            val += ((arg3 + 0x40) & 0x7F) << 8;
            break;
        default:
            return -2;
        }
    }
    ret = 0;
    p = (u8 *)lbl_801A6C80;
    if ((s8)p[0x464] != 0) {
        ret = -3;
    } else {
        *(s8 *)(p + 0x464) = -1;
        if ((val & 0x80000000) == 0) {
            ret = -2;
        } else {
            lbl_801A6C78 = OSDisableInterrupts();
            p = (u8 *)lbl_801A6C80;
            if (p[0x441] < 0x40 && ((u32 *)(p + 0x240))[p[0x443]] == 0) {
                ((u32 *)(p + 0x240))[p[0x443]] = val;
                p = (u8 *)lbl_801A6C80;
                p[0x443] = (p[0x443] + 1) & 0x3F;
                p = (u8 *)lbl_801A6C80;
                p[0x441] = p[0x441] + 1;
            } else {
                ret = -1;
            }
            OSRestoreInterrupts(lbl_801A6C78);
        }
        p = (u8 *)lbl_801A6C80;
        p[0x464] = 0;
    }
    return ret;
}
