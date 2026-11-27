#ifndef DOLPHIN_CARD_H
#define DOLPHIN_CARD_H

#include <dolphin/types.h>

typedef struct CARDFileInfo {
    s32 chan;
    s32 fileNo;
    s32 offset;
    s32 length;
    u16 iBlock;
    u16 __padding;
} CARDFileInfo;

typedef void (*CARDCallback)(s32 chan, s32 result);

typedef struct CARDStat {
    char fileName[32];
    u32 length;
    u32 time;
    u8 gameName[4];
    u8 company[2];
    u8 bannerFormat;
    u8 __padding;
    u32 iconAddr;
    u16 iconFormat;
    u16 iconSpeed;
    u32 commentAddr;
    u32 offsetBanner;
    u32 offsetBannerTlut;
    u32 offsetIcon[8];
    u32 offsetIconTlut;
    u32 offsetData;
} CARDStat;

#ifdef __cplusplus
extern "C" {
#endif

s32 CARDCheck(s32 channel);
s32 CARDCheckAsync(s32 chan, CARDCallback callback);
s32 CARDCheckExAsync(s32 chan, s32 *xferBytes, CARDCallback callback);
s32 CARDClose(CARDFileInfo *fileInfo);
s32 CARDCreate(s32 channel, const char *fileName, u32 size, CARDFileInfo *fileInfo);
s32 CARDCreateAsync(s32 chan, const char *fileName, u32 size, CARDFileInfo *fileInfo,
                    CARDCallback callback);
s32 CARDDeleteAsync(s32 chan, const char *fileName, CARDCallback callback);
s32 CARDFastDeleteAsync(s32 chan, s32 fileNo, CARDCallback callback);
s32 CARDFreeBlocks(s32 chan, s32 *byteNotUsed, s32 *filesNotUsed);
s32 CARDGetResultCode(s32 chan);
s32 CARDGetSerialNo(s32 chan, u64 *serialNo);
s32 CARDGetStatus(s32 chan, s32 fileNo, CARDStat *stat);
s32 CARDMountAsync(s32 chan, void *workArea, CARDCallback detachCallback,
                   CARDCallback attachCallback);
s32 CARDOpen(s32 chan, const char *fileName, CARDFileInfo *fileInfo);
s32 CARDProbeEx(s32 chan, s32 *memSize, s32 *sectorSize);
s32 CARDReadAsync(CARDFileInfo *fileInfo, void *buf, s32 length, s32 offset, CARDCallback callback);
s32 CARDRenameAsync(s32 chan, const char *oldName, const char *newName, CARDCallback callback);
s32 CARDSetStatusAsync(s32 chan, s32 fileNo, CARDStat *stat, CARDCallback callback);
s32 CARDUnmount(s32 chan);
s32 CARDWriteAsync(CARDFileInfo *fileInfo, const void *buf, s32 length, s32 offset,
                   CARDCallback callback);

#ifdef __cplusplus
}
#endif

#endif
