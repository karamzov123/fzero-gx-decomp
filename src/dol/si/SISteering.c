#include "types.h"
#include "dolphin/os/OSContext.h"
#include "dolphin/os/OSTime.h"
#include "dolphin/si.h"

typedef struct SISteeringControl {
    u8 output[3];
    u8 input[9];
    u32 outputBytes;
    u32 inputBytes;
    void (*callback)(s32, s32);
    s32 ret;
    u8 pad1C[8];
    void (*proc)(s32);
} SISteeringControl;

extern SISteeringControl lbl_8015CC10[4];
extern s32 lbl_801A6828;
extern u32 lbl_801A6834;

extern OSContext *fn_8000BE5C(void);
extern void OSClearContext(OSContext *);
extern void OSSetCurrentContext(OSContext *);
extern void __OSReschedule(void);
extern void SISetCommand(s32 chan, u32 command);

u32 fn_800136E8(u32 channel, u32 outputBytes, u32 inputBytes, void (*proc)(s32));
void fn_8001375C(u32 channel);

void fn_800133DC(void) {
}

void fn_800133E0(s32 chan) {
    SISteeringControl *entry = &lbl_8015CC10[chan];
    if (entry->ret == 0 && lbl_801A6828 == 0) {
        fn_8001375C(chan);
    }
}

s32 fn_80013428(u32 channel, void (*callback)(s32, s32)) {
    BOOL interrupts;
    u32 unused[2];
    s32 result;
    SISteeringControl *entry;

    entry = &lbl_8015CC10[channel];
    result = callback != 0 ? (s32)callback : (s32)(u32)fn_800133DC;
    interrupts = OSDisableInterrupts();
    if (entry->callback != 0) {
        result = -2;
    } else {
        entry->callback = (void (*)(s32, s32))result;
        result = 0;
    }
    OSRestoreInterrupts(interrupts);
    if (result != 0) {
        return result;
    }
    entry->output[0] = 0xff;
    fn_800136E8(channel, 1, 3, fn_800133E0);
}

void fn_800134DC(s32 arg0, u32 arg1, OSContext *arg2) {
    SISteeringControl *entry;
    u32 unused[2];
    OSContext context;

    entry = &lbl_8015CC10[arg0];
    if (lbl_801A6828 == 0) {
        if ((arg1 & 0x8) != 0) {
            entry->ret = -1;
        } else if ((arg1 & 0x7) != 0) {
            entry->ret = -3;
        } else {
            entry->ret = 0;
        }
        if (entry->proc != 0) {
            void (*proc)(s32) = entry->proc;
            entry->proc = 0;
            proc(arg0);
        }
        if (entry->callback != 0) {
            OSClearContext(&context);
            OSSetCurrentContext(&context);
            {
                void (*cb)(s32, s32) = entry->callback;
                entry->callback = 0;
                cb(arg0, entry->ret);
            }
            OSClearContext(&context);
            OSSetCurrentContext(arg2);
        }
    }
}

void fn_800135CC(s32 chan, u32 type) {
    SISteeringControl *entry;

    entry = &lbl_8015CC10[chan];
    if (lbl_801A6828 != 0) {
        return;
    }
    if ((type & 0xFFFF0000) == 0x08000000) {
        if (SITransfer(chan, entry->output, entry->outputBytes, entry->input, entry->inputBytes,
                       (SICallback)fn_800134DC, 0) != 0) {
            return;
        }
        entry->ret = -2;
    } else {
        entry->ret = -1;
    }
    if (entry->proc != 0) {
        void (*cb)(s32) = entry->proc;
        entry->proc = 0;
        cb(chan);
    }
    if (entry->callback != 0) {
        OSContext *saved = fn_8000BE5C();
        void (*cb2)(s32, s32);
        {
            OSContext context;
            OSClearContext(&context);
            OSSetCurrentContext(&context);
            cb2 = entry->callback;
            entry->callback = 0;
            cb2(chan, entry->ret);
            OSClearContext(&context);
        }
        OSSetCurrentContext(saved);
        __OSReschedule();
    }
}

u32 fn_800136E8(u32 channel, u32 outputBytes, u32 inputBytes, void (*proc)(s32)) {
    BOOL interrupts;
    SISteeringControl *entry;

    entry = &lbl_8015CC10[channel];
    interrupts = OSDisableInterrupts();
    entry->proc = proc;
    entry->outputBytes = outputBytes;
    entry->inputBytes = inputBytes;
    SIGetTypeAsync(channel, (SITypeAndStatusCallback)fn_800135CC);
    OSRestoreInterrupts(interrupts);
    return 0;
}

void fn_8001375C(u32 channel) {
    u32 mask;
    u32 command;
    u32 response;

    mask = ((u32)0x8000 << 16) >> channel;
    if ((lbl_801A6834 & mask) == 0) {
        lbl_801A6834 |= mask;
        SIGetResponse(channel, &response);
        command = 0x300000;
        mask = command + 0x680;
        SISetCommand(channel, mask);
        SIEnablePolling(lbl_801A6834);
    }
}
