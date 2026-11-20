#include "types.h"


/* --- dol/__CARDPutControlBlock.c --- */
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);

typedef struct CARDControlBlock {
    s32 attached;
    s32 callback;
} CARDControlBlock;

u32 __CARDPutControlBlock(CARDControlBlock *block, u32 callback) {
    u32 irq;
    irq = OSDisableInterrupts();
    if (block->attached != 0) {
        block->callback = callback;
    } else if (block->callback == -1) {
        block->callback = callback;
    }
    OSRestoreInterrupts(irq);
    return callback;
}

/* --- dol/CARDGetResultCode.c --- */
extern u32 lbl_80177960[];

u32 CARDGetResultCode(u32 arg0) {
    u32 v0;
    v0 = arg0;
    if ((s32)arg0 < 0 || (s32)arg0 >= 2) {
    v0 = -128;
    return v0;
    }
    v0 = (u32)((u8 *)&lbl_80177960 + (v0 * 272));
    v0 = *(u32 *)((u8 *)v0 + 4);
    return v0;
}
