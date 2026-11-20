#include <dolphin/os.h>
#include <dolphin/os/OSRtc.h>


/* --- dol/OSSetProgressiveMode.c --- */
struct OSRtcBss {
    SramControlBlock Scb;
};

extern struct OSRtcBss Scb_8015BFC0;

static inline void *LockSram(u32 offset) {
    BOOL *lockedField;

    struct OSRtcBss *bss = &Scb_8015BFC0;

    BOOL enabled;
    enabled = OSDisableInterrupts();
    lockedField = &(bss->Scb).locked;
    if ((*lockedField) != 0) {
        OSRestoreInterrupts(enabled);
        return ((void *)0);
    }
    (bss->Scb).enabled = enabled;
    (*lockedField) = 1;
    return (bss->Scb).sram + offset;
}

BOOL UnlockSram(BOOL commit, u32 offset);

static inline BOOL __OSUnlockSram(BOOL commit) { return UnlockSram(commit, 0); }

static inline OSSram *__OSLockSramInline() { return LockSram(0); }

void OSSetProgressiveMode(u32 mode) {
    OSSram *sram;
    mode <<= 7;
    mode &= 0x80;
    sram = __OSLockSramInline();
    if (mode == (sram->flags & 0x80)) {
        __OSUnlockSram(0);
        return;
    }
    sram->flags &= ~0x80;
    sram->flags |= mode;
    __OSUnlockSram(1);
}

/* --- dol/OSGetWirelessID.c --- */
OSSramEx *__OSLockSramEx();



static inline OSSramEx *__OSLockSramEx() { return LockSram(sizeof(OSSram)); }

BOOL UnlockSram(BOOL commit, u32 offset);

static inline BOOL __OSUnlockSramEx(BOOL commit) { return UnlockSram(commit, sizeof(OSSram)); }

u16 OSGetWirelessID(s32 channel) {
    OSSramEx *sram;
    u16 id;
    sram = __OSLockSramEx();
    id = sram->wirelessPadID[channel];
    __OSUnlockSramEx(0);
    return id;
}

/* --- dol/OSSetWirelessID.c --- */
OSSramEx *__OSLockSramEx();




BOOL UnlockSram(BOOL commit, u32 offset);


void OSSetWirelessID(s32 channel, u16 id) {
    OSSramEx *sram;
    sram = __OSLockSramEx();
    if (sram->wirelessPadID[channel] != id) {
        sram->wirelessPadID[channel] = id;
        __OSUnlockSramEx(1);
        return;
    }
    __OSUnlockSramEx(0);
}
