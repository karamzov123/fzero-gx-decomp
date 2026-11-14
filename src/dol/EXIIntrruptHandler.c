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

void EXIIntrruptHandler(__OSInterrupt interrupt, OSContext *context) {
    s32 chan;
    EXIControl *exi;
    EXICallback callback;
    chan = (interrupt - 9) / 3;
    exi = &Ecb[chan];
    EXIClearInterrupts(chan, 1, 0, 0);
    callback = exi->exiCallback;
    if (callback) {
        OSContext exceptionContext;
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
