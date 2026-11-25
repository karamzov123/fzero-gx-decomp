#include "types.h"
#include <dolphin/os.h>
#include "dolphin/os/OSReset.h"
#include "dolphin/os/OSRtc.h"
#include "dolphin/os/OSThread.h"
#include "sdk_addresses.h"

typedef struct OSResetQueue {
    OSResetFunctionInfo *first;
    OSResetFunctionInfo *last;
} OSResetQueue;

extern OSResetQueue ResetFunctionQueue;

void OSRegisterResetFunction(OSResetFunctionInfo *func) {
    OSResetFunctionInfo *tmp;
    OSResetFunctionInfo *iter;
    for (iter = ResetFunctionQueue.first; iter && iter->priority <= func->priority;
         iter = iter->next)
        ;
    if (iter == ((void *)0)) {
        tmp = ResetFunctionQueue.last;
        if (tmp == ((void *)0)) {
            ResetFunctionQueue.first = func;
        } else {
            tmp->next = func;
        }
        func->prev = tmp;
        func->next = ((void *)0);
        ResetFunctionQueue.last = func;
        return;
    }
    func->next = iter;
    tmp = iter->prev;
    iter->prev = func;
    func->prev = tmp;
    if (tmp == ((void *)0)) {
        ResetFunctionQueue.first = func;
        return;
    }
    tmp->next = func;
}

/* Dolphin SDK os/OSReset.c: Reset is a CodeWarrior asm function in the original. It sets
 * HID0[ICFI] and syncs, waits on the time base, then writes the reset code to the processor
 * interface reset register and spins; the forward branches pull each stage into the
 * instruction cache before it runs. No compiler frame. */
static asm void Reset(register s32 resetCode) {
    nofralloc
    b prefetch_wait
flush:
    mfspr r8, HID0
    ori r8, r8, 0x8
    mtspr HID0, r8
    isync
    sync
    nop
    b wait
prefetch_wait:
    b prefetch_reset
wait:
    mftb r5, 268
wait_loop:
    mftb r6, 268
    subf r7, r5, r6
    cmplwi r7, 0x1124
    blt wait_loop
    nop
    b reset
prefetch_reset:
    b prefetch_spin
reset:
    lis r8, 0xcc00
    ori r8, r8, 0x3000
    li r4, 0x3
    stw r4, 0x24(r8)
    stw resetCode, 0x24(r8)
    nop
    b spin
prefetch_spin:
    b start
spin:
    nop
    b spin
start:
    b flush
}

#pragma peephole off

// The VI reset register is a hardware MMIO halfword.
extern volatile u32 __VIRegs[];
extern void ICFlashInvalidate(void);

void __OSDoHotReset(s32 reset_code) {
    OSDisableInterrupts();
    // Volatile prevents the compiler from removing the MMIO reset write.
    ((volatile u16 *)__VIRegs)[1] = 0;
    ICFlashInvalidate();
    Reset(reset_code << 3);
}

#define RESET_CACHED(offset) ((void *)(FZGX_ADDR_OS_THREAD_QUEUE - 0xdc + (offset)))

extern BOOL __PADDisableRecalibration(BOOL);
extern OSSram *__OSLockSram(void);
extern int OSEnableScheduler(void);
extern u32 LCDisable(void);
extern u32 OSDisableScheduler(void);
extern BOOL __OSSyncSram(void);
extern void *memset(void *, int, u32);
extern void OSCancelThread(OSThread *);
extern void __OSReboot(u32, u32);
extern void __OSStopAudioSystem(void);
extern void __OSUnlockSram(u32);
extern vu32 OS_CURRENT_CONTEXT[];
extern vu32 OS_THREAD_QUEUE[];
extern vu32 __OSBI2Pointer[];
extern vu32 __OSModuleInfoList[];

static inline BOOL CallResetFunctions(BOOL final) {
    OSResetFunctionInfo *info;
    s32 v2;
    info = ResetFunctionQueue.first;
    v2 = 0;
    while (info != 0 && !v2) {
        v2 |= !info->func(final);
        info = info->next;
    }
    v2 |= !__OSSyncSram();
    if (v2) {
        return FALSE;
    }
    return TRUE;
}

static inline void KillThreads(void) {
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
        Reset(arg1 << 3);
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

typedef struct Unk {
    u8 pad[0x24];
    u32 resetCode;
} Unk;

// Hardware or OS state can change asynchronously.
volatile u8
    DAT_800030e2 : FZGX_ADDR_DAT_800030e2; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
volatile Unk
    DAT_cc003000 : FZGX_ADDR_DAT_cc003000; // fzgx-allow: S2 SDK asynchronous state

u32 OSGetResetCode(void) {
    if (DAT_800030e2 != 0) {
        return 0x80000000;
    }
    return ((DAT_cc003000.resetCode & ~7) >> 3);
}
