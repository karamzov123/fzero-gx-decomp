#include "types.h"
#include "dolphin/card.h"
#include "dolphin/card/CARDPriv.h"

typedef struct CARDStatExEntry {
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
} CARDStatExEntry;

extern CARDDir *fn_8002C4BC(CARDControl *card);
extern void *memcpy(void *, const void *, u32);
extern s32 fn_8008023C(u32, u32, u32);

s32 fn_80030380(s32 chan, s32 fileNo, void *out) {
    CARDControl *card;
    s32 result;
    s32 access;
    CARDDir *entry;

    if (fileNo < 0 || fileNo >= 0x7F) {
        return -0x80;
    }
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    entry = fn_8002C4BC(card);
    entry += fileNo;
    access = __CARDAccess(card, entry);
    if (access == -0xA) {
        access = __CARDIsPublic(entry);
    }
    if (access >= 0) {
        memcpy(out, entry, 0x40);
    }
    return __CARDPutControlBlock(card, access);
}

s32 fn_8003043C(s32 chan, s32 fileNo, CARDStatExEntry *src, CARDCallback callback) {
    CARDControl *card;
    CARDStatExEntry *base;
    s32 ret;
    CARDStatExEntry *ent;
    s32 i;
    s32 result;

    if (fileNo < 0 || fileNo >= 0x7f || src->fileName[0] == 0xff || src->fileName[0] == 0) {
        return -0x80;
    }
    result = __CARDGetControlBlock(chan, &card);
    if (result < 0) {
        return result;
    }
    base = (CARDStatExEntry *)fn_8002C4BC(card);
    ent = base + fileNo;
    result = __CARDAccess(card, (CARDDir *)ent);
    if (result < 0) {
        return __CARDPutControlBlock(card, result);
    }
    {
        u8 *p = src->fileName;
        while (p < src->fileName + 0x20) {
            if (*p == 0) {
                while (++p < src->fileName + 0x20) {
                    *p = 0;
                }
                break;
            }
            p++;
        }
    }
    if (fn_8008023C((u32)ent->fileName, (u32)src->fileName, 0x20) != 0 ||
        fn_8008023C((u32)ent->name, (u32)src->name, 4) != 0 ||
        fn_8008023C((u32)ent->company, (u32)src->company, 2) != 0) {
        for (i = 0; i < 0x7f; i++) {
            if (i != fileNo && base->name[0] != 0xff &&
                fn_8008023C((u32)base->name, (u32)src->name, 4) == 0 &&
                fn_8008023C((u32)base->company, (u32)src->company, 2) == 0 &&
                fn_8008023C((u32)base->fileName, (u32)src->fileName, 0x20) == 0) {
                return __CARDPutControlBlock(card, -7);
            }
            base++;
        }
        memcpy(ent->fileName, src->fileName, 0x20);
        memcpy(ent->name, src->name, 4);
        memcpy(ent->company, src->company, 2);
    }
    ent->unk_28 = src->unk_28;
    ent->gameVersion = src->gameVersion;
    ent->unk_2c = src->unk_2c;
    ent->unk_30 = src->unk_30;
    ent->unk_32 = src->unk_32;
    ent->unk_3c = src->unk_3c;
    ent->unk_34 = src->unk_34;
    ent->unk_35 = src->unk_35;
    ret = __CARDUpdateDir(chan, callback);
    if (ret < 0) {
        __CARDPutControlBlock(card, ret);
    }
    return ret;
}
