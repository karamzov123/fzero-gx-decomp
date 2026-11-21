#include "types.h"
#include <types.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"


/* --- dol/DVDLowBreak.c --- */
extern u32 StopAtNextInt;
extern u32 lbl_801A6878;

s32 DVDLowBreak(void);

/* --- dol/DVDLowClearCallback.c --- */
typedef void (*DVDLowCallback)(u32 intType);

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

extern DVDLowCallback Callback;

DVDLowCallback DVDLowClearCallback();

/* --- dol/__DVDLowSetWAType.c --- */
extern u32 OSDisableInterrupts(u32, u32);
extern u32 OSRestoreInterrupts(u32);
extern u32 WorkAroundSeekLocation;
extern u32 WorkAroundType;

void __DVDLowSetWAType(u32 arg0, u32 arg1);

/* --- dol/__DVDFSInit.c --- */
extern u32 BootInfo_801A68A0;
extern u32 FstStart;
extern u32 FstStringStart;
extern u32 MaxEntryNum;

void __DVDFSInit(void) {
    BootInfo_801A68A0 = 0x80000000; /* fzgx-allow: A1,A2 unnamed OS memory */
    FstStart = *(u32 *)0x80000038; /* fzgx-allow: A1,A2 unnamed OS memory */
    if (FstStart == 0) {
        return;
    }
    MaxEntryNum = *(u32 *)(FstStart + 0x8);
    FstStringStart = FstStart + MaxEntryNum * 0xc;
}
