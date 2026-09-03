/* Auto-generated exact-asm transcription (scaffolding).
 * Range covered by this unit: see per-function headers. */

typedef int BOOL;
typedef unsigned int u32;
typedef unsigned char u8;

#pragma force_active on

extern unsigned char lbl_80124110[];
extern unsigned char lbl_801A6908[4];
extern void* __OSLockSramEx(void);
extern void __OSUnlockSramEx(int);
extern int __msl_strncmp(const char*, const char*, unsigned long);

#pragma dont_inline on
u8 ErrorCode2Num(u32 errorCode) {
    u32 i;
    u32 *ErrorTable = (u32 *)lbl_80124110;

    for (i = 0; i < 18; i++) {
        if (ErrorTable[i] == errorCode) {
            return (u8)i;
        }
    }

    if ((errorCode >= 0x00100000) && (errorCode <= 0x00100008)) {
        return 17;
    }

    return 29;
}
#pragma dont_inline reset

// provenance: mkdd:libs/dolphin/dvd/dvderror.c
void __DVDStoreErrorCode(u32 error) {
    u8 num;

    if (error == 0x01234567) {
        num = 0xFF;
    } else if (error == 0x01234568) {
        num = 0xFE;
    } else {
        u32 statusCode = error >> 24;
        u8 errorNum = ErrorCode2Num(error & 0x00FFFFFF);
        if (statusCode >= 6) {
            statusCode = 6;
        }
        num = statusCode * 30 + errorNum;
    }

    {
        void* sram = __OSLockSramEx();
        *(u8*)((char*)sram + 0x24) = num;
        __OSUnlockSramEx(1);
    }
}

typedef struct DVDDiskID {
    char gameName[4];
    char company[2];
    u8 diskNumber;
    u8 gameVersion;
} DVDDiskID;

// provenance: original
BOOL fn_8001A1F4(const DVDDiskID* id1, const DVDDiskID* id2) {
    if (id1->gameName[0] && id2->gameName[0]) {
        if (__msl_strncmp(id1->gameName, id2->gameName, 4) != 0) {
            return 0;
        }
    }

    if (!id1->company[0] || !id2->company[0] || __msl_strncmp(id1->company, id2->company, 2) != 0) {
        return 0;
    }

    if (id1->diskNumber != 0xFF && id2->diskNumber != 0xFF && id1->diskNumber != id2->diskNumber) {
        return 0;
    }

    if (id1->gameVersion != 0xFF && id2->gameVersion != 0xFF && id1->gameVersion != id2->gameVersion) {
        return 0;
    }

    return 1;
}

typedef void (*fn_8001A2EC_cb)(void);

// provenance: original (retail asm reconstruction; callback-forwarder shape shared with dolsdk2001:src/dvd/dvdfs.c __DVDReadDoneCallback) fn_8001A2EC
void fn_8001A2EC(void) {
    if (*(fn_8001A2EC_cb *)lbl_801A6908 != 0) {
        (*(fn_8001A2EC_cb *)lbl_801A6908)();
    }
}
