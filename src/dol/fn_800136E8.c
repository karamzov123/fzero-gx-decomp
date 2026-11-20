#include "types.h"


/* --- dol/fn_800136E8.c --- */
extern u8 lbl_8015CC10[160];
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern void fn_800135CC(u32, u32);
extern void SIGetTypeAsync(u32, void (*)(u32, u32));

struct SIEntry {
    u8 pad0[12];
    u32 callback;
    u32 type;
    u8 pad18[16];
    u32 value;
};

u32 fn_800136E8(u32 channel, u32 arg1, u32 arg2, u32 arg3) {
    u32 interrupts;
    struct SIEntry *entry;

    entry = (struct SIEntry *)lbl_8015CC10 + channel;
    interrupts = OSDisableInterrupts();
    entry->value = arg3;
    entry->callback = arg1;
    entry->type = arg2;
    SIGetTypeAsync(channel, (void (*)(u32, u32))fn_800135CC);
    OSRestoreInterrupts(interrupts);
    return 0;
}

/* --- dol/fn_8001375C.c --- */
extern u32 lbl_801A6834;
extern void SIGetResponse(u32, void *);
extern void SISetCommand(u32, u32);
extern void SIEnablePolling(u32);

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
