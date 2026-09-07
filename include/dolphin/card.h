#ifndef FZERO_DOLPHIN_CARD_H
#define FZERO_DOLPHIN_CARD_H

/*
 * GFZE01 CARD ABI pilot. This is deliberately smaller than a wholesale SDK
 * import: each field below is used by a converted unit and is backed by the
 * retail offsets recorded in the CARD dossiers.
 */
typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

#define CARD_FILENAME_MAX 32
#define CARD_MAX_FILE 127
#define CARD_ICON_MAX 8

#define CARD_ATTR_PUBLIC 0x04u

#define CARD_RESULT_READY 0
#define CARD_RESULT_NOFILE (-4)
#define CARD_RESULT_BROKEN (-6)
#define CARD_RESULT_NOPERM (-10)
#define CARD_RESULT_FATAL_ERROR (-128)

typedef void (*CARDCallback)(s32 chan, s32 result);

/* Retail CARD directory entry: 0x40-byte stride, fields verified at 0x28+. */
typedef struct CARDDir {
    /* 0x00 */ u8 gameName[4];
    /* 0x04 */ u8 company[2];
    /* 0x06 */ u8 _padding0;
    /* 0x07 */ u8 bannerFormat;
    /* 0x08 */ u8 fileName[CARD_FILENAME_MAX];
    /* 0x28 */ u32 time;
    /* 0x2C */ u32 iconAddr;
    /* 0x30 */ u16 iconFormat;
    /* 0x32 */ u16 iconSpeed;
    /* 0x34 */ u8 permission;
    /* 0x35 */ u8 copyTimes;
    /* 0x36 */ u16 startBlock;
    /* 0x38 */ u16 length;
    /* 0x3A */ u8 _padding1[2];
    /* 0x3C */ u32 commentAddr;
} CARDDir;

/* Retail file handle fields used by CARDCreate and CARDWrite. */
typedef struct CARDFileInfo {
    /* 0x00 */ s32 chan;
    /* 0x04 */ s32 fileNo;
    /* 0x08 */ u32 offset;
    /* 0x0C */ s32 length;
    /* 0x10 */ u16 iBlock;
} CARDFileInfo;

/* Compile-time target ABI guards; these types are for 32-bit MWCC. */
typedef char CARD_u32_is_4_bytes[(sizeof(u32) == 4) ? 1 : -1];
typedef char CARD_dir_is_0x40_bytes[(sizeof(CARDDir) == 0x40) ? 1 : -1];
typedef char CARD_file_info_is_0x14_bytes[(sizeof(CARDFileInfo) == 0x14) ? 1 : -1];

#endif
