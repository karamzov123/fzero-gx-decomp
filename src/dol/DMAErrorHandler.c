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
};

extern struct OSCacheMessages OSCacheData;

void PPCHalt(void);

u32 PPCMfhid2(void);

void PPCMthid2(u32 val);

void OSReport(const char *msg, ...);

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
