#include "types.h"


/* --- dol/fn_8008E718.c --- */
extern u32 OSRestoreInterrupts(u32);

struct fn_8008E718_Arg0 {
    u32 unk_0;
};

void fn_8008E718(struct fn_8008E718_Arg0 *arg0) {
    OSRestoreInterrupts(arg0->unk_0);
}

/* --- dol/fn_8008E73C.c --- */
extern u32 OSDisableInterrupts(u32);

void fn_8008E73C(u32 arg0) {
    u32 t0;
    t0 = OSDisableInterrupts(arg0);
    *(u32 *)((u8 *)arg0 + 0) = t0;
}
