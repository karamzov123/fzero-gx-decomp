#include "types.h"

typedef void (*CommandCallback)(s32);

typedef struct CommandBlock {
    u8 pad0[0x0c];
    u32 status;
    u8 pad10[0x18];
    CommandCallback callback;
} CommandBlock;

extern CommandBlock *executing_801A68C0;
extern CommandBlock DummyCommandBlock_8015CE80;
extern u32 lbl_801A68F4;
extern void __DVDFSInit(void);
extern void stateReady(void);
extern void stateTimeout(void);
extern void _epilog_rel_sample(void);

void cbForStateReadingFST(u32 arg0) {
    CommandBlock *old;

    if (arg0 == 16) {
        executing_801A68C0->status = (u32)-1;
        stateTimeout();
    } else if ((arg0 & 1) != 0) {
        lbl_801A68F4 = 0;
        __DVDFSInit();
        old = executing_801A68C0;
        executing_801A68C0 = &DummyCommandBlock_8015CE80;
        old->status = 0;
        if (old->callback != 0) {
            old->callback(0);
        }
        stateReady();
    } else {
        _epilog_rel_sample();
    }
}
