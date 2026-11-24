#include "types.h"

extern BOOL OSDisableInterrupts(void);
extern BOOL OSRestoreInterrupts(BOOL level);

extern u32 lbl_801A6B70;
extern u32 lbl_801A6B74;
extern u32 lbl_801A6B78;
extern u32 lbl_801A6B7C;

u32 fn_800235D4(void) {
    u32 result;

    if (lbl_801A6B7C != 0) {
        result = lbl_801A6B70 + lbl_801A6B78++ * 56;
        lbl_801A6B78 %= lbl_801A6B74;
        return result;
    }
    return 0;
}

void fn_8002361C(u32 buffer, u32 count) {
    lbl_801A6B70 = buffer;
    lbl_801A6B74 = count;
    lbl_801A6B78 = 0;
    lbl_801A6B7C = 1;
}

u32 fn_80023638(void) {
    BOOL level = OSDisableInterrupts();
    u32 count = lbl_801A6B78;

    if (lbl_801A6B78 != 0) {
        count--;
    }
    lbl_801A6B78 = 0;
    OSRestoreInterrupts(level);
    return count;
}
