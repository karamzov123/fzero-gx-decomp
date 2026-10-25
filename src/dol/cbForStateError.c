#include "types.h"

extern u32 DummyCommandBlock_8015CE80[];
extern u32 FatalErrorFlag_801A68D8;
extern void __DVDPrintFatalMessage(void);
extern u32 lbl_801A68E0;
extern u32 lbl_801A68E4;
extern void stateReady(void);
extern void stateTimeout(void);

struct Executing {
    u8 pad[40];
    void (*callback)(s32, struct Executing *);
};

extern struct Executing *executing_801A68C0;

void cbForStateError(u32 arg0, u32 arg1) {
    struct Executing *executing;

    if (arg0 == 16) {
        executing = executing_801A68C0;
        *(s32 *)((u8 *)executing + 12) = -1;
        stateTimeout();
    } else {
        __DVDPrintFatalMessage();
        executing = executing_801A68C0;
        FatalErrorFlag_801A68D8 = 1;
        executing_801A68C0 = (struct Executing *)&DummyCommandBlock_8015CE80;
        if (executing->callback != 0) {
            executing->callback(-1, executing);
        }
        if (lbl_801A68E0 != 0) {
            lbl_801A68E0 = 0;
            if (lbl_801A68E4 != 0) {
                ((void (*)(s32, struct Executing *))lbl_801A68E4)(0, executing);
            }
        }
        stateReady();
    }
}
