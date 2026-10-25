#include <dolphin/os.h>
#include <dolphin/dvd.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include "sdk_addresses.h"

typedef struct _ApploaderHeader {
    char date[16];
    u32 entry;
    u32 size;
    u32 rebootSize;
    u32 reserved2;
} ApploaderHeader;

void DVDInit();

BOOL fn_8001989C(BOOL autoInval);

void DVDResume();

s32 DVDGetCommandBlockStatus(const DVDCommandBlock *block);

BOOL DVDCancelStreamAsync(DVDCommandBlock *block, DVDCBCallback callback);

DVDDiskID *fn_80019C48();

int DVDCheckDisk();

BOOL DVDReadAbsAsyncPrio(DVDCommandBlock *block, void *addr, s32 length, s32 offset, DVDCBCallback callback,
                 s32 prio);

void __DVDPrepareResetAsync(DVDCBCallback callback);

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

extern BOOL __OSIsGcam;

void AISetStreamPlayState(u32 state);

void AISetStreamVolLeft(u8 vol);

void AISetStreamVolRight(u8 vol);

ApploaderHeader lbl_8015BFA0 __attribute__((aligned(32)));

extern void *lbl_801A67C0;

extern void *lbl_801A67C4;

extern u32 UNK_817FFFF8 : FZGX_ADDR_UNK_817FFFF8;

extern u32 UNK_817FFFFC : FZGX_ADDR_UNK_817FFFFC;

extern u32 BOOT_REGION_START : FZGX_ADDR_BOOT_REGION_START;

extern u32 BOOT_REGION_END : FZGX_ADDR_BOOT_REGION_END;

extern u8 OS_REBOOT_BOOL : FZGX_ADDR_OS_REBOOT_BOOL;

extern BOOL lbl_801A67C8;

void __OSDoHotReset(int);

static inline void ReadApploader(OSTime time1) {
    if (DVDCheckDisk() == 0 || OSGetTime() - time1 > ((u32)__OSBusClock / 4)) {
        __OSDoHotReset(UNK_817FFFFC);
    }
}

void Run();

void fn_8000EB04();

#pragma opt_lifetimes off
static inline BOOL IsStreamEnabled(void) {
    if (fn_80019C48()->streaming) {
        return 1;
    }
    return 0;
}
#pragma opt_lifetimes reset


#pragma peephole off
void __OSReboot(u16 resetCode, u32 bootDol) {
    OSContext exceptionContext;
    OSTime time;
    DVDCommandBlock dvdCmd;
    DVDCommandBlock dvdCmd2;
    u32 numBytes;
    DVDCommandBlock dvdCmd3;
    u32 offset;
    u32 lab_t5;
    OSDisableInterrupts();
    UNK_817FFFFC = 0;
    UNK_817FFFF8 = 0;
    OS_REBOOT_BOOL = 1;
    BOOT_REGION_START = (u32)lbl_801A67C0;
    BOOT_REGION_END = (u32)lbl_801A67C4;
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    DVDInit();
    fn_8001989C(1);
    DVDResume();
    lbl_801A67C8 = 0;
    __DVDPrepareResetAsync(fn_8000EB04);
    __OSMaskInterrupts(~0x1F);
    __OSUnmaskInterrupts(0x400);
    OSEnableInterrupts();
    time = OSGetTime();
    while (lbl_801A67C8 != 1) {
        ReadApploader(time);
    }
    if (!__OSIsGcam && IsStreamEnabled()) {
        AISetStreamVolLeft(0);
        AISetStreamVolRight(0);
        DVDCancelStreamAsync(&dvdCmd, 0);
        time = OSGetTime();
        while (DVDGetCommandBlockStatus(&dvdCmd)) {
            ReadApploader(time);
        }
        AISetStreamPlayState(0);
    }
    lab_t5 = 0;
    DVDReadAbsAsyncPrio(&dvdCmd2, &lbl_8015BFA0, 32, 0x2440, 0, lab_t5);
    time = OSGetTime();
    while (DVDGetCommandBlockStatus(&dvdCmd2)) {
        ReadApploader(time);
    }
    offset = lbl_8015BFA0.size + 0x20;
    numBytes = ((((u32)lbl_8015BFA0.rebootSize + 31) & ~31));
    lab_t5 = 0;
    DVDReadAbsAsyncPrio(&dvdCmd3, (void *)(FZGX_ADDR___OSRebootBuffer), numBytes, offset + 0x2440, 0, lab_t5);
    time = OSGetTime();
    while (DVDGetCommandBlockStatus(&dvdCmd3)) {
        ReadApploader(time);
    }
    ICInvalidateRange((void *)(FZGX_ADDR___OSRebootBuffer), numBytes);
    OSDisableInterrupts();
    ICFlashInvalidate();
    Run((void *)FZGX_ADDR___OSRebootBuffer);
}
#pragma peephole reset

