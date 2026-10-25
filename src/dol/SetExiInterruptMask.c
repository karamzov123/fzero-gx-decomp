#include <dolphin/exi/EXIPriv.h>
#include <dolphin/os/OSInterrupt.h>
#pragma scheduling off

__OSInterruptHandler __OSGetInterruptHandler(__OSInterrupt interrupt);

extern EXIControl Ecb_8015CCB0[3];

void SetExiInterruptMask(s32 chan, EXIControl *exi) {
    EXIControl *exi2;
    exi2 = &Ecb_8015CCB0[2];
    switch (chan) {
    case 0:
        if ((exi->exiCallback == 0 && exi2->exiCallback == 0) || (exi->state & 0x10)) {
            __OSMaskInterrupts((0x80000000u >> (9)) | (0x80000000u >> (15)));
        } else {
            __OSUnmaskInterrupts((0x80000000u >> (9)) | (0x80000000u >> (15)));
        }
        break;
    case 1:
        if (exi->exiCallback == 0 || (exi->state & 0x10)) {
            __OSMaskInterrupts((0x80000000u >> (12)));
        } else {
            __OSUnmaskInterrupts((0x80000000u >> (12)));
        }
        break;
    case 2:
        if (__OSGetInterruptHandler(25) == 0 || (exi->state & 0x10)) {
            __OSMaskInterrupts((0x80000000u >> (25)));
        } else {
            __OSUnmaskInterrupts((0x80000000u >> (25)));
        }
        break;
    }
}
