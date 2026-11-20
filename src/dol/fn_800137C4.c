#include "types.h"


/* --- dol/fn_800137C4.c --- */
extern u8 lbl_8015CC10[160];
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern s32 SIIsChanBusy(u32);
extern u32 lbl_801A6834;
extern u32 SIGetStatus(u32);
extern s32 SIGetResponse(u32, void *);
extern u32 SIDisablePolling(u32);

struct SIEntry {
    u8 pad0[0x18];
    s32 status;
    u8 pad1[0xc];
};

struct SIResponse {
    u32 word0;
    u32 word1;
};

struct SIOutput {
    u16 buttons;
    u8 data[6];
    s8 status;
};

u32 fn_800137C4(u32 channel, struct SIOutput *response) {
    u32 interrupts;
    u32 mask;
    struct SIEntry *entry;
    struct SIResponse si_response;
    s32 status;

    interrupts = OSDisableInterrupts();
    entry = (struct SIEntry *)lbl_8015CC10 + channel;
    mask = 0x80000000 >> channel;

    if (SIIsChanBusy(channel) != 0) {
        entry->status = -2;
    } else if ((lbl_801A6834 & mask) == 0) {
        entry->status = -1;
    } else if ((SIGetStatus(channel) & 8) != 0) {
        SIGetResponse(channel, &si_response);
        SIDisablePolling(mask);
        lbl_801A6834 &= ~mask;
        entry->status = -1;
    } else if (SIGetResponse(channel, &si_response) == 0 ||
               (si_response.word0 & 0x80000000) != 0) {
        entry->status = -3;
    } else {
        entry->status = 0;
        if (response != 0) {
            response->buttons = (u16)(si_response.word0 >> 16);
            response->data[0] = (u8)(si_response.word0 >> 8);
            response->data[1] = (u8)si_response.word0 - 0x80;
            response->data[2] = (u8)(si_response.word1 >> 24);
            response->data[3] = (u8)(si_response.word1 >> 16);
            response->data[4] = (u8)(si_response.word1 >> 8);
            response->data[5] = (u8)si_response.word1;
        }
    }

    if (response != 0) {
        response->status = entry->status;
    }
    status = entry->status;
    OSRestoreInterrupts(interrupts);
    return status;
}

/* --- dol/SamplingHandler.c --- */
/* --- dol/SamplingHandler.c --- */
extern u32 lbl_801A6830;
extern void OSClearContext(void *);
extern void OSSetCurrentContext(void *);

void SamplingHandler(u32 unused, void *context) {
    u8 local_context[0x2c8];

    if (lbl_801A6830 != 0) {
        OSClearContext(local_context);
        OSSetCurrentContext(local_context);
        ((void (*)(void))lbl_801A6830)();
        OSClearContext(local_context);
        OSSetCurrentContext(context);
    }
}

/* --- dol/PADSetSamplingCallback.c --- */
/* --- dol/PADSetSamplingCallback.c --- */
extern u32 SIRegisterPollingHandler(u32);
extern u32 SIUnregisterPollingHandler(u32);

u32 PADSetSamplingCallback(u32 arg0) {
    u32 v0;
    v0 = lbl_801A6830;
    lbl_801A6830 = arg0;
    if (arg0 != 0) {
    SIRegisterPollingHandler((u32)SamplingHandler);
    } else {
    SIUnregisterPollingHandler((u32)SamplingHandler);
    }
    return v0;
}

/* --- dol/fn_800139E8.c --- */
extern void SISetCommand(u32 channel, u32 command);
extern void SITransferCommands(void);

void fn_800139E8(u32 channel, u32 command, s32 repeat) {
    u32 state;
    u32 value;
    u32 mask;

    mask = command & 0x600;
    if (repeat <= -0x80) {
        value = 0;
    } else if (repeat >= 0x80) {
        value = 0x100;
    } else {
        value = repeat + 0x80;
    }
    value |= mask;
    value &= 0x7ff;

    state = OSDisableInterrupts();
    if (lbl_801A6834 & (0x80000000u >> channel)) {
        value |= 0x300000;
        SISetCommand(channel, value);
        SITransferCommands();
    }
    OSRestoreInterrupts(state);
}
