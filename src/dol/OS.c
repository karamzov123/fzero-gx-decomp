#include <dolphin/os.h>
#include <dolphin/dvd.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma peephole off


typedef void (*__OSExceptionHandler)(__OSException exception, OSContext *context);

typedef struct OSBootInfo {
    DVDDiskID DVDDiskID;
    u32 magic;
    u32 version;
    u32 memorySize;
    u32 consoleType;
    void *arenaLo;
    void *arenaHi;
    void *FSTLocation;
    u32 FSTMaxLength;
} OSBootInfo;

typedef struct DVDDriveInfo {
    u16 revisionLevel;
    u16 deviceCode;
    u32 releaseDate;
    u8 padding[24];
} DVDDriveInfo;

typedef struct BI2Debug {
    s32 debugMonSize;
    s32 simMemSize;
    u32 argOffset;
    u32 debugFlag;
    int trackLocation;
    int trackSize;
    u32 countryCode;
    u8 unk[8];
    u32 padSpec;
} BI2Debug;

void *memcpy(void *dest, const void *src, size_t n);

void OSReport(const char *msg, ...);

void DBPrintf(char *format, ...);

void *OSGetArenaLo(void);

void OSSetArenaHi(void *newHi);

void OSSetArenaLo(void *newLo);

void OSRegisterVersion(const char *id);

void OSInitAlarm(void);

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);

void DVDInit();

BOOL DVDInquiryAsync(DVDCommandBlock *block, DVDDriveInfo *info, DVDCBCallback callback);

extern BOOL __DBIsExceptionMarked(__OSException);

u32 PPCMfhid2(void);

void PPCMthid2(u32 val);

void __OSEVStart(void);

void __OSEVEnd(void);

void __OSEVSetNumber(void);

void __DBVECTOR(void);

void __OSDBINTSTART(void);

void __OSDBINTEND(void);

void __OSDBJUMPEND(void);

__OSExceptionHandler __OSSetExceptionHandler(__OSException exception, __OSExceptionHandler handler);

void OSDefaultExceptionHandler(register __OSException exception, register OSContext *context);

void OSExceptionInit(void);

void ClearArena(void);

void InquiryCallback(s32 result, DVDCommandBlock *block);

extern unsigned char OSDataPool[];

extern OSBootInfo *BootInfo_801A6748;

extern u32 *BI2DebugFlag;

extern u32 *BI2DebugFlagHolder;

extern BOOL __OSIsGcam;

extern BOOL AreWeInitialized;

extern __OSExceptionHandler *OSExceptionTable;

extern void *__OSSavedRegionStart;

extern void *__OSSavedRegionEnd;

extern BOOL __OSInIPL;

extern OSTime __OSStartTime;

extern u8 __ArenaHi[];

extern u8 __ArenaLo[];

extern char _stack_addr[];

extern char *__OSResetSWInterruptHandler[];

extern u32 __DVDLongFileNameFlag;

extern u32 __PADSpec;

extern u32 BOOT_REGION_START : FZGX_ADDR_BOOT_REGION_START;

extern u32 BOOT_REGION_END : FZGX_ADDR_BOOT_REGION_END;

vu16 __OSDeviceCode : FZGX_ADDR___OSDeviceCode;

static DVDDriveInfo DriveInfo;

static DVDCommandBlock __OSDriveBlock;

const char *__OSVersion = "<< Dolphin SDK - OS\trelease build: Mar 17 2003 04:20:41 (0x2301) >>";

u32 OSGetConsoleType() {
    if (BootInfo_801A6748 == ((void *)0) || BootInfo_801A6748->consoleType == 0) {
        return 0x10000002;
    }
    return BootInfo_801A6748->consoleType;
}

void ClearArena(void) {
    if ((u32)(OSGetResetCode() + 0x80000000) != 0U) {
        __OSSavedRegionStart = 0U;
        __OSSavedRegionEnd = 0U;
        memset(OSGetArenaLo(), 0U, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
        return;
    }
    __OSSavedRegionStart = (void *)BOOT_REGION_START;
    __OSSavedRegionEnd = (void *)BOOT_REGION_END;
    if (BOOT_REGION_START == 0U) {
        memset(OSGetArenaLo(), 0U, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
        return;
    }
    if ((u32)OSGetArenaLo() < (u32)__OSSavedRegionStart) {
        if ((u32)OSGetArenaHi() <= (u32)__OSSavedRegionStart) {
            memset((u32)OSGetArenaLo(), 0U, (u32)OSGetArenaHi() - (u32)OSGetArenaLo());
            return;
        }
        memset(OSGetArenaLo(), 0U, (u32)__OSSavedRegionStart - (u32)OSGetArenaLo());
        if ((u32)OSGetArenaHi() > (u32)__OSSavedRegionEnd) {
            memset((u32)__OSSavedRegionEnd, 0, (u32)OSGetArenaHi() - (u32)__OSSavedRegionEnd);
        }
    }
}

void InquiryCallback(s32 result, DVDCommandBlock *block) {
    switch (block->state) {
    case 0:
        __OSDeviceCode = (u16)(0x8000 | DriveInfo.deviceCode);
        break;
    default:
        __OSDeviceCode = 1;
        break;
    }
}

void OSInit(void) {
    BI2Debug *DebugInfo;
    void *debugArenaLo;
    u32 inputConsoleType;
    u32 tdev;
    if ((BOOL)AreWeInitialized == 0) {
        AreWeInitialized = 1;
        __OSStartTime = __OSGetSystemTime();
        OSDisableInterrupts();
        PPCMtmmcr0(0);
        PPCMtmmcr1(0);
        PPCMtpmc1(0);
        PPCMtpmc2(0);
        PPCMtpmc3(0);
        PPCMtpmc4(0);
        PPCDisableSpeculation();
        PPCSetFpNonIEEEMode();
        BI2DebugFlag = 0;
        BootInfo_801A6748 = (OSBootInfo *)(0x8000 << 16);
        __DVDLongFileNameFlag = (u32)0;
        DebugInfo = (BI2Debug *)*((u32 *)FZGX_ADDR___OSBI2Pointer);
        if (DebugInfo != ((void *)0)) {
            BI2DebugFlag = &DebugInfo->debugFlag;
            __PADSpec = (u32)DebugInfo->padSpec;
            *((u8 *)FZGX_ADDR___OSBI2DebugFlag) = (u8)*BI2DebugFlag;
            *((u8 *)FZGX_ADDR___OSPadSpecByte) = (u8)__PADSpec;
        } else if (BootInfo_801A6748->arenaHi) {
            BI2DebugFlagHolder = (u32 *)*((u8 *)FZGX_ADDR___OSBI2DebugFlag);
            BI2DebugFlag = (u32 *)&BI2DebugFlagHolder;
            __PADSpec = (u32) * ((u8 *)FZGX_ADDR___OSPadSpecByte);
        }
        __DVDLongFileNameFlag = 1;
        OSSetArenaLo((BootInfo_801A6748->arenaLo == ((void *)0)) ? __ArenaLo
                                                                 : BootInfo_801A6748->arenaLo);
        if ((BootInfo_801A6748->arenaLo == ((void *)0)) && (BI2DebugFlag != 0) &&
            (*BI2DebugFlag < 2)) {
            debugArenaLo = (char *)(((u32)_stack_addr + 0x1f) & ~0x1f);
            OSSetArenaLo(debugArenaLo);
        }
        OSSetArenaHi((BootInfo_801A6748->arenaHi == ((void *)0)) ? __ArenaHi
                                                                 : BootInfo_801A6748->arenaHi);
        OSExceptionInit();
        __OSInitSystemCall();
        OSInitAlarm();
        __OSModuleInit();
        __OSInterruptInit();
        __OSSetInterruptHandler(22, (void *)__OSResetSWInterruptHandler);
        __OSContextInit();
        __OSCacheInit();
        EXIInit();
        SIInit();
        __OSInitSram();
        __OSThreadInit();
        __OSInitAudioSystem();
        PPCMthid2(PPCMfhid2() & 0xBFFFFFFF);
        if ((BOOL)__OSInIPL == 0) {
            __OSInitMemoryProtection();
        }
        OSReport("\nDolphin OS\n");
        OSReport("Kernel built : %s %s\n", "Mar 17 2003", "04:20:41");
        OSReport("Console Type : ");
        if (BootInfo_801A6748 == ((void *)0) ||
            (inputConsoleType = BootInfo_801A6748->consoleType) == 0) {
            inputConsoleType = 0x10000002;
        } else {
            inputConsoleType = BootInfo_801A6748->consoleType;
        }
        switch (inputConsoleType & 0xF0000000) {
        case 0x00000000:
            OSReport("Retail %d\n", inputConsoleType);
            break;
        case 0x10000000:
        case 0x20000000:
            switch (inputConsoleType & 0x0FFFFFFF) {
            case 0x10000000:
                OSReport("Mac Emulator\n");
                break;
            case 0x10000001:
                OSReport("PC Emulator\n");
                break;
            case 0x10000002:
                OSReport("EPPC Arthur\n");
                break;
            case 0x10000003:
                OSReport("EPPC Minnow\n");
                break;
            default:
                tdev = (u32)inputConsoleType & 0x0FFFFFFF;
                OSReport("Development HW%d (%08x)\n", tdev - 3, inputConsoleType);
                break;
            }
            break;
        default:
            OSReport("%08x\n", inputConsoleType);
            break;
        }
        OSReport("Memory %d MB\n", (u32)BootInfo_801A6748->memorySize >> 0x14U);
        OSReport("Arena : 0x%x - 0x%x\n", OSGetArenaLo(), OSGetArenaHi());
        OSRegisterVersion(__OSVersion);
        if (BI2DebugFlag && ((*BI2DebugFlag) >= 2)) {
            EnableMetroTRKInterrupts();
        }
        ClearArena();
        OSEnableInterrupts();
        if ((BOOL)__OSInIPL == 0) {
            DVDInit();
            if ((BOOL)__OSIsGcam) {
                __OSDeviceCode = 0x9000;
                return;
            }
            DCInvalidateRange(&DriveInfo, sizeof(DriveInfo));
            DVDInquiryAsync(&__OSDriveBlock, &DriveInfo, InquiryCallback);
        }
    }
}

static u32 __OSExceptionLocations[] = {
    0x00000100, 0x00000200, 0x00000300, 0x00000400, 0x00000500, 0x00000600, 0x00000700, 0x00000800,
    0x00000900, 0x00000C00, 0x00000D00, 0x00000F00, 0x00001300, 0x00001400, 0x00001700,
};

void OSExceptionInit(void) {
    __OSException exception;
    void *destAddr;
    u32 *opCodeAddr;
    u32 oldOpCode;
    u8 *handlerStart;
    u32 handlerSize;
    opCodeAddr = (u32 *)__OSEVSetNumber;
    oldOpCode = *opCodeAddr;
    handlerStart = (u8 *)__OSEVStart;
    handlerSize = (u32)((u8 *)__OSEVEnd - (u8 *)__OSEVStart);
    destAddr = (void *)((void *)((u32)(0x60) + (0x8000 << 16)));
    if (*(u32 *)destAddr == 0) {
        DBPrintf("Installing OSDBIntegrator\n");
        memcpy(destAddr, (void *)__OSDBINTSTART, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
        DCFlushRangeNoSync(destAddr, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
        __sync();
        ICInvalidateRange(destAddr, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
    }
    for (exception = 0; exception < (14 + 1); exception++) {
        if (BI2DebugFlag && (*BI2DebugFlag >= 2) &&
            __DBIsExceptionMarked(exception)) {
            DBPrintf(">>> OSINIT: exception %d commandeered by TRK\n", exception);
            continue;
        }
        *opCodeAddr = oldOpCode | exception;
        if (__DBIsExceptionMarked(exception)) {
            DBPrintf(">>> OSINIT: exception %d vectored to debugger\n", exception);
            memcpy((void *)__DBVECTOR, (void *)__OSDBINTEND,
                   (u32)__OSDBJUMPEND - (u32)__OSDBINTEND);
        } else {
            u32 *ops = (u32 *)__DBVECTOR;
            int cb;
            for (cb = 0; cb < (u32)__OSDBJUMPEND - (u32)__OSDBINTEND; cb += sizeof(u32)) {
                *ops++ = 0x60000000;
            }
        }
        destAddr =
            (void *)((void *)((u32)(__OSExceptionLocations[(u32)exception]) + (0x8000 << 16)));
        memcpy(destAddr, handlerStart, handlerSize);
        DCFlushRangeNoSync(destAddr, handlerSize);
        __sync();
        ICInvalidateRange(destAddr, handlerSize);
    }
    OSExceptionTable = ((void *)((u32)(0x3000) + (0x8000 << 16)));
    for (exception = 0; exception < (14 + 1); exception++) {
        __OSSetExceptionHandler(exception, OSDefaultExceptionHandler);
    }
    *opCodeAddr = oldOpCode;
    DBPrintf("Exceptions initialized...\n");
}
