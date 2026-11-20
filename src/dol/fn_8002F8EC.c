#include "types.h"
#include "dol/globals.h"


/* --- dol/fn_8002F8EC.c --- */
extern s32 __CARDSync(u32);
extern s32 CARDWriteAsync(void *, void *, void *, s32, void *);
extern void __CARDSyncCallback(void);

s32 fn_8002F8EC(u32 arg0, u32 arg1, u32 arg2, s32 arg3) {
    s32 result;

    result = CARDWriteAsync((void *)arg0, (void *)arg1, (void *)arg2, arg3,
                           (void *)__CARDSyncCallback);
    if (result < 0) {
        return result;
    }
    return __CARDSync(*(u32 *)arg0);
}

/* --- dol/DeleteCallback.c --- */
typedef struct {
    u8 pad_0[0xBE];
    u16 unk_BE;
    u8 pad_C0[0x10];
    void (*unk_D0)(s32, s32);
} DeleteControlBlock;

extern s32 __CARDFreeBlock(s32 index, u16 sector, void (*callback)(s32, s32));
extern void __CARDPutControlBlock(DeleteControlBlock *block, s32 result);

void DeleteCallback(s32 index, s32 result) {
    DeleteControlBlock *block;
    void (*callback)(s32, s32);

    block = (DeleteControlBlock *)((u8 *)&lbl_80177960 + index * 0x110);
    callback = block->unk_D0;
    block->unk_D0 = 0;
    if (result >= 0) {
        result = __CARDFreeBlock(index, block->unk_BE, callback);
        if (result >= 0) {
            return;
        }
    }
    __CARDPutControlBlock(block, result);
    if (callback != 0) {
        callback(index, result);
    }
}
