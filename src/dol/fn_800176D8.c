#include "types.h"
#include "dolphin/types.h"
#include "sdk_addresses.h"


/* --- dol/fn_800176D8.c --- */
extern u32 __DVDThreadQueue;
extern u32 OSWakeupThread(u32);

void fn_800176D8(void) {
    OSWakeupThread((u32)&__DVDThreadQueue);
}

/* --- dol/DVDGetTransferredSize.c --- */
vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

typedef struct DVDCommandBlock {
    u8 pad_00[0xC];
    s32 state;
    u8 pad_10[0xC];
    u32 currTransferSize;
    u32 transferredSize;
} DVDCommandBlock;

u32 DVDGetTransferredSize(DVDCommandBlock *block) {
    switch (block->state) {
    case -1:
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
        return block->transferredSize;
    case 2:
        return 0;
    case 1:
        return block->transferredSize + (block->currTransferSize - __DIRegs[6]);
    }
}

/* --- dol/fn_80017768.c --- */
// fn_80017768: empty in retail (single blr).
void fn_80017768(void) {
}
