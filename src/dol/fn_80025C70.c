#include "types.h"

extern u32 OSDisableInterrupts(void);
extern u32 lbl_801A64FC;
extern void OSRestoreInterrupts(u32);

typedef void (*Callback)(u32);

#pragma opt_propagation off
s32 fn_80025C70(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 t0;

    t0 = OSDisableInterrupts();
    v0 = *(u32 *)(arg0 + 48);
    v1 = t0;
    if (v0 != 0) {
        v1 = v0;
        ((Callback)lbl_801A64FC)(v0);
    }
    if (*(u32 *)(arg0 + 52) != 0) {
        ((Callback)lbl_801A64FC)(*(u32 *)(arg0 + 52));
    }
    if (*(u32 *)(arg0 + 56) != 0) {
        ((Callback)lbl_801A64FC)(*(u32 *)(arg0 + 56));
    }
    OSRestoreInterrupts(t0);
    return 1;
}
#pragma opt_propagation reset

