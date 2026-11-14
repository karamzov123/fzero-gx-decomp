#include "types.h"

extern u32 DummyCommandBlock[];
extern u32 FatalErrorFlag;
extern void __DVDPrintFatalMessage(void);
extern u32 lbl_801A68E0;
extern u32 lbl_801A68E4;
extern void stateReady(void);
extern void stateTimeout(void);

struct Executing {
    u8 pad[40];
    void (*callback)(s32, struct Executing *);
};

extern struct Executing *executing;

void cbForStateError(u32 arg0, u32 arg1) {
    struct Executing *block;

    if (arg0 == 16) {
        block = executing;
        *(s32 *)((u8 *)block + 12) = -1;
        stateTimeout();
    } else {
        __DVDPrintFatalMessage();
        block = executing;
        FatalErrorFlag = 1;
        executing = (struct Executing *)&DummyCommandBlock;
        if (block->callback != 0) {
            block->callback(-1, block);
        }
        if (lbl_801A68E0 != 0) {
            lbl_801A68E0 = 0;
            if (lbl_801A68E4 != 0) {
                ((void (*)(s32, struct Executing *))lbl_801A68E4)(0, block);
            }
        }
        stateReady();
    }
}
