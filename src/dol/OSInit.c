#include <dolphin/os.h>
#include <dolphin/dvd.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"
#pragma peephole off

struct OSMessages {
    char padding_0[68];
    char message_44[13];
    char padding_51[3];
    char message_54[22];
    char padding_6a[2];
    char message_6c[12];
    char message_78[9];
    char padding_81[3];
    char message_84[16];
    char message_94[11];
    char padding_9f[1];
    char message_a0[14];
    char padding_ae[2];
    char message_b0[13];
    char padding_bd[3];
    char message_c0[13];
    char padding_cd[3];
    char message_d0[13];
    char padding_dd[3];
    char message_e0[25];
    char padding_f9[3];
    char message_fc[14];
    char padding_10a[2];
    char message_10c[21];
};

typedef struct DVDDriveInfo {
    u16 revisionLevel;
    u16 deviceCode;
    u32 releaseDate;
    u8 padding[24];
} DVDDriveInfo;

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

extern unsigned char OSDataPool[];

void *OSGetArenaLo(void);

void OSSetArenaHi(void *newHi);

void OSSetArenaLo(void *newLo);

void OSRegisterVersion(const char *id);

void OSReport(const char *msg, ...);

extern BOOL __OSInIPL;

void OSInitAlarm(void);

void *OSGetArenaLo(void);

void OSSetArenaHi(void *addr);

void OSSetArenaLo(void *addr);

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);

extern BOOL __OSIsGcam;

void DVDInit();

BOOL DVDInquiryAsync(DVDCommandBlock *block, DVDDriveInfo *info, DVDCBCallback callback);

extern const char *__OSVersion;

extern char _stack_addr[];

extern char *__OSResetSWInterruptHandler[];

vu16 __OSDeviceCode : FZGX_ADDR___OSDeviceCode;

static DVDDriveInfo DriveInfo_8015BF00;

static DVDCommandBlock __OSDriveBlock__fzgx_offset_0;

extern OSBootInfo *BootInfo_801A6748;

extern u32 *BI2DebugFlag;

extern u32 *BI2DebugFlagHolder;

extern BOOL AreWeInitialized;

extern OSTime __OSStartTime;

extern u8 __ArenaHi[];

extern u8 __ArenaLo[];

extern u32 __DVDLongFileNameFlag;

extern u32 __PADSpec;

void OSExceptionInit(void);

void ClearArena(void);

void InquiryCallback(s32 result, DVDCommandBlock *block);

void OSInit(void) {
    struct OSMessages *messages = (struct OSMessages *)OSDataPool;

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
        OSReport(messages->message_44);
        OSReport(messages->message_54, messages->message_6c, messages->message_78);
        OSReport(messages->message_84);
        if (BootInfo_801A6748 == ((void *)0) ||
            (inputConsoleType = BootInfo_801A6748->consoleType) == 0) {
            inputConsoleType = 0x10000002;
        } else {
            inputConsoleType = BootInfo_801A6748->consoleType;
        }
        switch (inputConsoleType & 0xF0000000) {
        case 0x00000000:
            OSReport(messages->message_94, inputConsoleType);
            break;
        case 0x10000000:
        case 0x20000000:
            switch (inputConsoleType & 0x0FFFFFFF) {
            case 0x10000000:
                OSReport(messages->message_a0);
                break;
            case 0x10000001:
                OSReport(messages->message_b0);
                break;
            case 0x10000002:
                OSReport(messages->message_c0);
                break;
            case 0x10000003:
                OSReport(messages->message_d0);
                break;
            default:
                tdev = (u32)inputConsoleType & 0x0FFFFFFF;
                OSReport(messages->message_e0, tdev - 3, inputConsoleType);
                break;
            }
            break;
        default:
            OSReport("%08x\n", inputConsoleType);
            break;
        }
        OSReport(messages->message_fc, (u32)BootInfo_801A6748->memorySize >> 0x14U);
        OSReport(messages->message_10c, OSGetArenaLo(), OSGetArenaHi());
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
            DCInvalidateRange(&DriveInfo_8015BF00, sizeof(DriveInfo_8015BF00));
            DVDInquiryAsync(&__OSDriveBlock__fzgx_offset_0, &DriveInfo_8015BF00, InquiryCallback);
        }
    }
}
