#include <dolphin/exi/EXIPriv.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma scheduling off

void OSRegisterVersion(const char *id);

extern BOOL __OSInIPL;

s32 EXIGetID(s32 chan, u32 dev, u32 *id);

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);

vu32 __EXIRegs[16] : FZGX_ADDR___EXIRegs;

extern const char *__EXIVersion;

extern EXIControl Ecb[3];

extern u32 IDSerialPort1;

s32 __EXIProbeStartTime[2] : FZGX_ADDR___EXIProbeStartTime;

BOOL __EXIProbe(s32 chan);

void EXIIntrruptHandler(__OSInterrupt interrupt, OSContext *context);

void TCIntrruptHandler(__OSInterrupt interrupt, OSContext *context);

void EXTIntrruptHandler(__OSInterrupt interrupt, OSContext *context);

void EXIInit(void) {
    u32 id;
    while ((((__EXIRegs[((0) * 5) + (3)]) & 0x1) == 1) ||
           (((__EXIRegs[((1) * 5) + (3)]) & 0x1) == 1) ||
           (((__EXIRegs[((2) * 5) + (3)]) & 0x1) == 1)) {
        continue;
    }
    __OSMaskInterrupts((0x80000000u >> (9)) | (0x80000000u >> (10)) | (0x80000000u >> (11)) |
                       (0x80000000u >> (12)) | (0x80000000u >> (13)) | (0x80000000u >> (14)) |
                       (0x80000000u >> (15)) | (0x80000000u >> (16)));
    (__EXIRegs[((0) * 5) + (0)]) = 0;
    (__EXIRegs[((1) * 5) + (0)]) = 0;
    (__EXIRegs[((2) * 5) + (0)]) = 0;
    (__EXIRegs[((0) * 5) + (0)]) = 0x00002000;
    __OSSetInterruptHandler(9, EXIIntrruptHandler);
    __OSSetInterruptHandler(10, TCIntrruptHandler);
    __OSSetInterruptHandler(11, EXTIntrruptHandler);
    __OSSetInterruptHandler(12, EXIIntrruptHandler);
    __OSSetInterruptHandler(13, TCIntrruptHandler);
    __OSSetInterruptHandler(14, EXTIntrruptHandler);
    __OSSetInterruptHandler(15, EXIIntrruptHandler);
    __OSSetInterruptHandler(16, TCIntrruptHandler);
    EXIGetID(0, 2, &IDSerialPort1);
    if (__OSInIPL) {
        __EXIProbeStartTime[0] = __EXIProbeStartTime[1] = 0;
        Ecb[0].idTime = Ecb[1].idTime = 0;
        __EXIProbe(0);
        __EXIProbe(1);
    } else if (EXIGetID(0, 0, &id) && id == 0x07010000) {
        __OSEnableBarnacle(1, 0);
    } else if (EXIGetID(1, 0, &id) && id == 0x07010000) {
        __OSEnableBarnacle(0, 2);
    }
    OSRegisterVersion(__EXIVersion);
}
