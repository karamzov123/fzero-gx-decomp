#include <dolphin/dvd.h>
#include <dolphin/os.h>
#include <dolphin/os/OSRtc.h>

/* retail name of the DVD error-code table (.data) */
extern u32 lbl_80124110[18];
#define ErrorTable lbl_80124110

OSSramEx *__OSLockSramEx(void);
BOOL __OSUnlockSramEx(BOOL commit);

u8 ErrorCode2Num(u32 errorCode) {
    u32 i;

    for (i = 0; i < sizeof(ErrorTable) / sizeof(ErrorTable[0]); i++) {
        if (errorCode == ErrorTable[i]) {
            return (u8)i;
        }
    }
    if (errorCode >= 0x00100000 && errorCode <= 0x00100008) {
        return 17;
    }
    return 29;
}

void __DVDStoreErrorCode(u32 error) {
    OSSramEx *sram;
    u8 num;

    if (error == 0x01234567) {
        num = 255;
    } else if (error == 0x01234568) {
        num = 254;
    } else {
        u32 status = error >> 24;
        u8 code = ErrorCode2Num(error & 0x00FFFFFF);
        if (status >= 6) {
            status = 6;
        }
        num = (u8)(code + status * 30);
    }
    sram = __OSLockSramEx();
    sram->dvdErrorCode = num;
    __OSUnlockSramEx(TRUE);
}
