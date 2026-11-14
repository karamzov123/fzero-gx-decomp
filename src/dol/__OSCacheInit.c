#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#pragma peephole off

struct OSCacheMessages {
    char padding_0[428];
    char message_1ac[25];
    char padding_1c5[3];
    char message_1c8[25];
    char padding_1e1[3];
    char message_1e4[22];
    char padding_1fa[2];
    char message_1fc[46];
};

extern struct OSCacheMessages OSCacheData;

u32 PPCMfmsr(void);

void PPCMtmsr(u32 val);

u32 PPCMfhid0(void);

u32 PPCMfl2cr(void);

void PPCMtl2cr(u32 val);

OSErrorHandler OSSetErrorHandler(OSError code, OSErrorHandler handler);

void DBPrintf(char *format, ...);

asm void DCEnable();

asm void ICEnable();

static inline void L2Disable(void) {
    __sync();
    PPCMtl2cr(PPCMfl2cr() & ~0x80000000);
    __sync();
}

void L2GlobalInvalidate(void);

static inline void L2Init(void) {
    u32 oldMSR;
    oldMSR = PPCMfmsr();
    __sync();
    PPCMtmsr((1 << (31 - 26)) | (1 << (31 - 27)));
    __sync();
    L2Disable();
    L2GlobalInvalidate();
    PPCMtmsr(oldMSR);
}

static inline void L2Enable(void) {
    PPCMtl2cr((PPCMfl2cr() | (1 << (31 - 0))) & ~(1 << (31 - 10)));
}

void DMAErrorHandler(OSError error, OSContext *context, ...);

void __OSCacheInit() {
    struct OSCacheMessages *messages = &OSCacheData;

    if (!(PPCMfhid0() & (1 << (31 - 16)))) {
        ICEnable();
        DBPrintf(messages->message_1ac);
    }
    if (!(PPCMfhid0() & (1 << (31 - 17)))) {
        DCEnable();
        DBPrintf(messages->message_1c8);
    }
    if (!(PPCMfl2cr() & (1 << (31 - 0)))) {
        L2Init();
        L2Enable();
        DBPrintf(messages->message_1e4);
    }
    OSSetErrorHandler(1, DMAErrorHandler);
    DBPrintf(messages->message_1fc);
}
