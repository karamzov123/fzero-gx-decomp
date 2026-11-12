#include <dolphin/exi/EXIPriv.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma scheduling off

u32 OSGetConsoleType();

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

extern EXIControl Ecb[3];

static inline void CompleteTransfer(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    u8 *buf;
    u32 data;
    int i;
    int len;
    if (exi->state & (0x01 | 0x02)) {
        if ((exi->state & 0x02) && (len = exi->immLen)) {
            buf = exi->immBuf;
            data = (__EXIRegs[((chan) * 5) + (4)]);
            for (i = 0; i < len; i++) {
                *buf++ = (u8)((data >> ((3 - i) * 8)) & 0xff);
            }
        }
        exi->state &= ~(0x01 | 0x02);
    }
}

extern u32 __OSGetDIConfig(void);

vu16 __OSDeviceCode : FZGX_ADDR___OSDeviceCode;

BOOL EXISync(s32 chan) {
    EXIControl *exi = &Ecb[chan];
    BOOL rc = 0;
    BOOL enabled;
    while (exi->state & 0x04) {
        if ((((__EXIRegs[((chan) * 5) + (3)]) & 1) >> 0) == 0) {
            enabled = OSDisableInterrupts();
            if (exi->state & 0x04) {
                CompleteTransfer(chan);
                if (__OSGetDIConfig() != 0xff || ((OSGetConsoleType() & 0xf0000000) == 0x20000000) ||
                    exi->immLen != 4 ||
                    ((__EXIRegs[((chan) * 5) + (0)]) & 0x00000070) != (0 << 4) ||
                    ((__EXIRegs[((chan) * 5) + (4)]) != 0x01010000 &&
                     (__EXIRegs[((chan) * 5) + (4)]) != 0x05070000 &&
                     (__EXIRegs[((chan) * 5) + (4)]) != 0x04220001) ||
                    __OSDeviceCode == 0x8200) {
                    rc = 1;
                }
            }
            OSRestoreInterrupts(enabled);
            break;
        }
    }
    return rc;
}
