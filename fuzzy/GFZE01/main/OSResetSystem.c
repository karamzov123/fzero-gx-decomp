/* Non-matching: best partial attempt (99.59% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "dolphin/types.h"
#include "dolphin/os/OSRtc.h"
#include "dolphin/os/OSThread.h"
#include "sdk_addresses.h"

#pragma peephole off

typedef struct ResetSystemCallback ResetSystemCallback;
struct ResetSystemCallback {
    BOOL (*call)(BOOL final);
    u32 priority;
    ResetSystemCallback *next;
    ResetSystemCallback *previous;
};
extern struct { ResetSystemCallback *head; ResetSystemCallback *tail; } ResetFunctionQueue_801A67D0;
extern void OSDisableScheduler(void);
extern void OSEnableScheduler(void);
extern void __OSStopAudioSystem(void);
extern BOOL OSDisableInterrupts(void);
extern BOOL __PADDisableRecalibration(BOOL);
extern BOOL __OSSyncSram(void);
extern OSSram *__OSLockSram(void);
extern BOOL __OSUnlockSram(BOOL);
extern void LCDisable(void);
extern void ICFlashInvalidate(void);
/* VI registers are volatile MMIO, not ordinary storage. */
extern volatile u32 __VIRegs[];
extern void Reset_8000EEF4(u32);
extern void __OSReboot(u32, BOOL);
extern void OSCancelThread(OSThread *);
extern void *memset(void *, int, u32);

/* The active-thread queue is at physical offset 0xdc in the OS low-memory ABI. */
#define RESET_LOW_MEMORY (FZGX_ADDR_OS_THREAD_QUEUE - 0xDCu)

static BOOL reset_callbacks_ready(BOOL final) {
    ResetSystemCallback *entry;
    BOOL error = FALSE;
    for (entry = ResetFunctionQueue_801A67D0.head;
         entry != 0 && !error; entry = entry->next) {
        error |= !entry->call(final);
    }
    error |= !__OSSyncSram();
    if (error) return FALSE;
    return TRUE;
}

static void cancel_reset_threads(void) {
    OSThread *thread;
    OSThread *next;
    for (thread = ((OSThreadQueue *)FZGX_ADDR_OS_THREAD_QUEUE)->head;
         thread != 0; thread = next) {
        next = thread->linkActive.next;
        switch (thread->state) {
        case 1:
        case 4:
            OSCancelThread(thread);
            break;
        }
    }
}

static void perform_hot_reset(u32 code) {
    OSDisableInterrupts();
    /* The VI reset halfword is an MMIO register, not ordinary storage. */
    ((volatile u16 *)__VIRegs)[1] = 0;
    ICFlashInvalidate();
    Reset_8000EEF4(code << 3);
}

void OSResetSystem(int reset, u32 reset_code, BOOL force_menu) {
    BOOL recalibration;
    OSDisableScheduler();
    __OSStopAudioSystem();
    if (reset == 2) recalibration = __PADDisableRecalibration(TRUE);
    while (!reset_callbacks_ready(FALSE)) {}
    if (reset == 1 && force_menu) {
        OSSram *sram = __OSLockSram();
        sram->flags |= 0x40;
        __OSUnlockSram(TRUE);
        while (!__OSSyncSram()) {}
    }
    OSDisableInterrupts();
    reset_callbacks_ready(TRUE);
    LCDisable();
    if (reset == 1) {
        perform_hot_reset(reset_code);
    } else if (reset == 0) {
        cancel_reset_threads();
        OSEnableScheduler();
        __OSReboot(reset_code, force_menu);
    }
    cancel_reset_threads();
    memset((u8 *)RESET_LOW_MEMORY + 0x40, 0, 0x8C);
    memset((u8 *)RESET_LOW_MEMORY + 0xD4, 0, 0x14);
    memset((u8 *)RESET_LOW_MEMORY + 0xF4, 0, 4);
    memset((u8 *)RESET_LOW_MEMORY + 0x3000, 0, 0xC0);
    memset((u8 *)RESET_LOW_MEMORY + 0x30C8, 0, 0xC);
    memset((u8 *)RESET_LOW_MEMORY + 0x30E2, 0, 1);
    /* Hot reset and reboot do not return; the returning shutdown path initialized this. */
    __PADDisableRecalibration(recalibration);
}
#undef RESET_LOW_MEMORY

#pragma peephole reset
