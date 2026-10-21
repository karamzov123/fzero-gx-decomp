#include "dolphin/types.h"
#include "dolphin/os/OSRtc.h"
#include "dolphin/os/OSThread.h"
#include "sdk_addresses.h"
#define RESET_CACHED(offset) ((void *)(FZGX_ADDR_OS_THREAD_QUEUE - 0xdc + (offset)))
#pragma peephole off

typedef u32 (*OSResetSystem_Fn0)(u32);
typedef u32 (*OSResetSystem_Fn1)(u32);
extern BOOL OSDisableInterrupts(void);
extern BOOL __PADDisableRecalibration(BOOL);
extern OSSram *__OSLockSram(void);
extern int OSEnableScheduler(void);
extern u32 LCDisable(void);
extern u32 OSDisableScheduler(void);
extern u32 ResetFunctionQueue_801A67D0;
extern u32 Reset_8000EEF4(u32);
extern BOOL __OSSyncSram(void);
extern void *memset(void *, int, u32);
extern void ICFlashInvalidate(void);
extern void OSCancelThread(OSThread *);
extern void __OSReboot(u32, u32);
extern void __OSStopAudioSystem(void);
extern void __OSUnlockSram(u32);
extern vu32 DAT_800030e2[];
extern vu32 OS_CURRENT_CONTEXT[];
extern vu32 OS_THREAD_QUEUE[];
extern vu32 __OSBI2Pointer[];
extern vu32 __OSModuleInfoList[];
extern vu32 __VIRegs[];

static BOOL CallResetFunctions(BOOL final) {
    u32 v1;
    s32 v2;
    v1 = ResetFunctionQueue_801A67D0;
    v2 = 0;
    while (v1 != 0 && !v2) {
        v2 |= !((OSResetSystem_Fn0)*(u32 *)v1)(final);
        v1 = *(u32 *)((u8 *)v1 + 8);
    }
    v2 |= !__OSSyncSram();
    if (v2) {
        return FALSE;
    }
    return TRUE;
}
static void KillThreads(void) {
    OSThread *v8;
    OSThread *v9;
    v8 = *(OSThread **)RESET_CACHED(0xdc);
    while (v8 != 0) {
        v9 = *(OSThread **)((u8 *)v8 + 764);
        switch (*(u16 *)((u8 *)v8 + 712)) {
        case 1:
        case 4:
            OSCancelThread(v8);
            break;
        }
        v8 = v9;
    }
}
void OSResetSystem(int arg0, u32 arg1, int arg2) {
    /* Preserve the reset routine's reserved stack workspace without accesses. */
    volatile u8 resetWork[16];
    BOOL v0;
    OSSram *t5;
    OSDisableScheduler();
    __OSStopAudioSystem();
    if (arg0 == 2) {
        v0 = __PADDisableRecalibration(1);
    }
    while (!CallResetFunctions(0)) {}
    if (arg0 == 1 && arg2 != 0) {
        t5 = __OSLockSram();
        t5->flags |= 64;
        __OSUnlockSram(1);
        while (!__OSSyncSram()) {}
    }
    OSDisableInterrupts();
    CallResetFunctions(1);
    LCDisable();
    if (arg0 == 1) {
        OSDisableInterrupts();
        ((vu16 *)__VIRegs)[1] = 0;
        ICFlashInvalidate();
        Reset_8000EEF4(arg1 << 3);
    } else if (arg0 == 0) {
        KillThreads();
        OSEnableScheduler();
        __OSReboot(arg1, arg2);
    }
    KillThreads();
    memset(RESET_CACHED(0x40), 0, 140);
    memset(RESET_CACHED(0xd4), 0, 20);
    memset(RESET_CACHED(0xf4), 0, 4);
    memset(RESET_CACHED(0x3000), 0, 192);
    memset(RESET_CACHED(0x30c8), 0, 12);
    memset(RESET_CACHED(0x30e2), 0, 1);
    __PADDisableRecalibration(v0);
}
