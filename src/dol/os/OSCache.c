#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#pragma peephole off

struct OSCacheMessages {
    char padding_0[44];
    char message_2c[24];
    char message_44[27];
    char padding_5f[1];
    char message_60[48];
    char message_90[60];
    char message_cc[55];
    char padding_103[1];
    char message_104[63];
    char padding_143[1];
    char message_144[41];
    char padding_16d[3];
    char message_170[29];
    char padding_18d[3];
    char message_190[25];
    char padding_1a9[3];
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
u32 PPCMfhid2(void);
void PPCMthid2(u32 val);
u32 PPCMfl2cr(void);
void PPCMtl2cr(u32 val);
void PPCHalt(void);
void OSReport(const char *msg, ...);
void DBPrintf(char *format, ...);
OSErrorHandler OSSetErrorHandler(OSError code, OSErrorHandler handler);
asm void DCEnable();
asm void ICEnable();

static inline void L2Disable(void) {
    __sync();
    PPCMtl2cr(PPCMfl2cr() & ~0x80000000);
    __sync();
}

void L2GlobalInvalidate(void) {
    L2Disable();
    PPCMtl2cr(PPCMfl2cr() | 0x00200000);
    while (PPCMfl2cr() & 0x00000001u)
        ;
    PPCMtl2cr(PPCMfl2cr() & ~0x00200000);
    while (PPCMfl2cr() & 0x00000001u) {
        DBPrintf(">>> L2 INVALIDATE : SHOULD NEVER HAPPEN\n");
    }
}

void DMAErrorHandler(OSError error, OSContext *context, ...) {
    struct OSCacheMessages *messages = &OSCacheData;

    u32 hid2 = PPCMfhid2();
    OSReport(messages->message_2c);
    OSReport(messages->message_44, hid2, context->srr1);
    if (!(hid2 & ((1 << (31 - 8)) | (1 << (31 - 9)) | (1 << (31 - 10)) | (1 << (31 - 11)))) ||
        !(context->srr1 & 0x00200000)) {
        OSReport(messages->message_60);
        OSDumpContext(context);
        PPCHalt();
    }
    OSReport(messages->message_90);
    OSReport(messages->message_cc);
    if (hid2 & (1 << (31 - 8))) {
        OSReport(messages->message_104);
    }
    if (hid2 & (1 << (31 - 9))) {
        OSReport(messages->message_144);
    }
    if (hid2 & (1 << (31 - 10))) {
        OSReport(messages->message_170);
    }
    if (hid2 & (1 << (31 - 11))) {
        OSReport(messages->message_190);
    }
    PPCMthid2(hid2);
}

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
