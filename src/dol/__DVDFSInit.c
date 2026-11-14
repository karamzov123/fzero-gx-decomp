#include "types.h"

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
