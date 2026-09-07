#ifndef FZERO_DOLPHIN_CARD_PRIVATE_H
#define FZERO_DOLPHIN_CARD_PRIVATE_H

#include <dolphin/card.h>

/*
 * GFZE01 private CARDControl view. Padding is deliberate: this is the
 * verified ABI slice, not a claim to model the complete SDK object. Retail
 * offsets: sectorSize=0x0C, buffer=0xB4, fileInfo=0xC0, apiCallback=0xD0,
 * diskID=0x10C.
 */
typedef struct CARDControl {
    /* 0x00 */ u8 _padding0[0x0C];
    /* 0x0C */ u32 sectorSize;
    /* 0x10 */ u16 cBlock;
    /* 0x12 */ u8 _padding1[0xA2];
    /* 0xB4 */ void *buffer;
    /* 0xB8 */ u8 _padding2[8];
    /* 0xC0 */ CARDFileInfo *fileInfo;
    /* 0xC4 */ u8 _padding3[0x0C];
    /* 0xD0 */ CARDCallback apiCallback;
    /* 0xD4 */ u8 _padding4[0x38];
    /* 0x10C */ const u8 *diskID;
} CARDControl;

extern CARDControl __CARDBlock[2];

s32 __CARDSeek(CARDFileInfo *fileInfo, s32 length, s32 offset,
               CARDControl **pcard);
CARDDir *__CARDGetDirBlock(CARDControl *card);
s32 __CARDAccess(CARDControl *card, CARDDir *ent);
s32 __CARDPutControlBlock(CARDControl *card, s32 result);
s32 __CARDGetControlBlock(s32 chan, CARDControl **pcard);
u16 *__CARDGetFatBlock(CARDControl *card);
s32 __CARDAllocBlock(s32 chan, u32 blockCount, CARDCallback callback);
s32 __CARDCompareFileName(CARDDir *ent, const char *fileName);
s32 __CARDUpdateDir(s32 chan, CARDCallback callback);
s32 __CARDSync(s32 chan);
s32 __CARDEraseSector(s32 chan, s32 address, void *callback);
s32 __CARDWrite(s32 chan, s32 address, s32 length, void *buffer,
               void *callback);
void __CARDDefaultApiCallback(s32 chan, s32 result);
void __CARDSyncCallback(s32 chan, s32 result);

typedef char CARD_control_is_0x110_bytes[(sizeof(CARDControl) == 0x110) ? 1 : -1];

#endif
