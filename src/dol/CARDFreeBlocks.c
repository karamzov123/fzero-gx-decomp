#include <dolphin/card/CARDPriv.h>


/* --- dol/CARDFreeBlocks.c --- */
BOOL OSDisableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL level);

CARDDir *fn_8002C4BC(CARDControl *card);
u16 *fn_8002C0B8(CARDControl *card);

static inline s32 __CARDPutControlBlock(CARDControl *card, s32 result) {
    BOOL enabled;
    enabled = OSDisableInterrupts();
    if (card->attached) {
        card->result = result;
    } else if (card->result == -1) {
        card->result = result;
    }
    OSRestoreInterrupts(enabled);
    return result;
}

s32 CARDFreeBlocks(s32 chan, s32 *byteNotUsed, s32 *filesNotUsed) {
    CARDControl *card;
    s32 result;
    u16 *fat;
    CARDDir *dir;
    CARDDir *ent;
    u16 fileNo;
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    fat = fn_8002C0B8(card);
    dir = fn_8002C4BC(card);
    if (fat == 0 || dir == 0) {
        return __CARDPutControlBlock(card, -6);
    }
    if (byteNotUsed) {
        *byteNotUsed = (s32)(card->sectorSize * fat[0x0003u]);
    }
    if (filesNotUsed) {
        *filesNotUsed = 0;
        for (fileNo = 0; fileNo < 127; fileNo++) {
            ent = &dir[fileNo];
            if (ent->fileName[0] == 0xff) {
                ++*filesNotUsed;
            }
        }
    }
    return __CARDPutControlBlock(card, 0);
}

/* --- dol/__CARDSync.c --- */
BOOL OSDisableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL level);

void OSSleepThread(OSThreadQueue *queue);

extern CARDControl lbl_80177960[2];

static inline s32 CARDGetResultCode(s32 chan) {
    CARDControl *card;
    if (chan < 0 || chan >= 2) {
        return -128;
    }
    card = &lbl_80177960[chan];
    return card->result;
}

s32 __CARDSync(s32 channel) {
    CARDControl *card;
    s32 result;
    BOOL enabled;
    card = &lbl_80177960[channel];
    enabled = OSDisableInterrupts();
    while ((result = CARDGetResultCode(channel)) == -1) {
        OSSleepThread(&card->threadQueue);
    }
    OSRestoreInterrupts(enabled);
    return result;
}
