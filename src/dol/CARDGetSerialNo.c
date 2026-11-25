#include "dolphin/card/CARDPriv.h"
#include <dolphin/card/CARDPriv.h>


/* --- dol/fn_8003043C.c --- */
typedef struct fn_8003043C_Entry {
    u8 name[4];
    u8 company[2];
    u8 unk_6;
    u8 gameVersion;
    u8 fileName[0x20];
    u32 unk_28;
    u32 unk_2c;
    u16 unk_30;
    u16 unk_32;
    u8 unk_34;
    u8 unk_35;
    u8 pad_36[6];
    u32 unk_3c;
} fn_8003043C_Entry;

extern s32 __CARDGetControlBlock(s32 chan, CARDControl **card);
extern u32 fn_8002C4BC(CARDControl *card);
extern s32 __CARDAccess(CARDControl *card, CARDDir *ent);
extern u32 __CARDPutControlBlock(CARDControl *card, u32 result);
extern s32 memcmp(u32, u32, u32);
extern void *memcpy(void *, const void *, u32);
extern s32 __CARDUpdateDir(s32 chan, CARDCallback callback);

s32 fn_8003043C(s32 chan, s32 fileNo, fn_8003043C_Entry *src, CARDCallback callback);

/* --- dol/CARDNet.c --- */
s32 CARDGetSerialNo(s32 chan, u64 *serialNo) {
    CARDControl *card;
    CARDID *id;
    int i;
    u64 code;
    s32 result;
    if (!(0 <= chan && chan < 2)) {
        return -128;
    }
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    id = (CARDID *)card->workArea;
    for (code = 0, i = 0; i < sizeof(id->serial) / sizeof(u64); ++i) {
        code ^= *(u64 *)&id->serial[sizeof(u64) * i];
    }
    *serialNo = code;
    return __CARDPutControlBlock(card, 0);
}

struct fn_80030754_Local {
    u8 pad_0[0x34];
    u8 unk_34;
    u8 pad_35[0x0B];
};
extern s32 fn_80030380(s32 chan, s32 fileNo, void *stat);

s32 fn_80030754(s32 chan, s32 fileNo, u8 attr, CARDCallback callback) {
    struct fn_80030754_Local local;
    s32 result;
    result = fn_80030380(chan, fileNo, &local);
    if (result < 0) {
        return result;
    }
    local.unk_34 = attr;
    return fn_8003043C(chan, fileNo, (fn_8003043C_Entry *)&local, callback);
}
