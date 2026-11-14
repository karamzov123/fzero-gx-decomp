#include <dolphin/exi/EXIPriv.h>
#include <dolphin/exi.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSRtc.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma scheduling off

void OSSetCurrentContext(OSContext *context);

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

static inline u32 EXIClearInterrupts(s32 chan, BOOL exi, BOOL tc, BOOL ext) {
    u32 cpr;
    u32 prev;
    prev = cpr = (__EXIRegs[((chan) * 5) + (0)]);
    cpr &= 0x7f5;
    if (exi)
        cpr |= 2;
    if (tc)
        cpr |= 8;
    if (ext)
        cpr |= 0x800;
    (__EXIRegs[((chan) * 5) + (0)]) = cpr;
    return prev;
}

void TCIntrruptHandler(__OSInterrupt interrupt, OSContext *context) {
    OSContext exceptionContext;
    s32 chan;
    EXIControl *exi;
    EXICallback callback;
    chan = (interrupt - 10) / 3;
    exi = &Ecb[chan];
    __OSMaskInterrupts((0x80000000u >> (interrupt)));
    EXIClearInterrupts(chan, 0, 1, 0);
    callback = exi->tcCallback;
    if (callback) {
        exi->tcCallback = 0;
        CompleteTransfer(chan);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
