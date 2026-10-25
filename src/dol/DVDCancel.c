#include "types.h"

typedef struct {
    u8 unk0[8];
    u32 state;
    s32 status;
} DVDCommandBlock;

extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern u32 __DVDThreadQueue;
extern u32 OSSleepThread(u32);
extern s32 DVDCancelAsync(u32, void *);
extern void fn_80019C24(void);

s32 DVDCancel(u32 arg0) {
    u32 interrupt_state;
    s32 status;
    u32 state;
    DVDCommandBlock *block;

    block = (DVDCommandBlock *)arg0;
    if (DVDCancelAsync(arg0, (void *)fn_80019C24) == 0) {
        return -1;
    }

    interrupt_state = OSDisableInterrupts();
    for (;;) {
        status = block->status;
        if ((u32)(status + 1) <= 1 || status == 10) {
            break;
        }
        if (status == 3) {
            state = block->state;
            if ((state - 4) <= 1 || state == 13 || state == 15) {
                break;
            }
        }
        OSSleepThread((u32)&__DVDThreadQueue);
    }
    OSRestoreInterrupts(interrupt_state);
    return 0;
}
