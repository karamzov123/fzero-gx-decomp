#include <dolphin/exi/EXIPriv.h>
#include <dolphin/exi.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSRtc.h>
#pragma scheduling off

void OSSetCurrentContext(OSContext *context);

extern EXIControl Ecb[3];

void EXTIntrruptHandler(__OSInterrupt interrupt, OSContext *context) {
    s32 chan;
    EXIControl *exi;
    EXICallback callback;
    chan = (interrupt - 11) / 3;
    __OSMaskInterrupts(((0x80000000u >> (11)) | (0x80000000u >> (9))) >> (3 * chan));
    exi = &Ecb[chan];
    callback = exi->extCallback;
    exi->state &= ~0x08;
    if (callback) {
        OSContext exceptionContext;
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(&exceptionContext);
        exi->extCallback = 0;
        callback(chan, context);
        OSClearContext(&exceptionContext);
        OSSetCurrentContext(context);
    }
}
