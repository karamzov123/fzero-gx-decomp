#include "types.h"


/* --- dol/fn_80023568.c --- */
extern u32 OSDisableInterrupts(u32, u32);
extern u32 OSRestoreInterrupts(void);

void fn_80023568(u32 arg0, u32 arg1) {
    s32 v0;
    u32 v2;
    s32 v1;
    v0 = arg1;
    v1 = arg0;
    v2 = (v1 + 492);
    OSDisableInterrupts(arg0, arg1);
    *(u16 *)((u8 *)v2 + 0) = *(u16 *)((u8 *)v0 + 0);
    *(u16 *)((u8 *)v2 + 2) = *(u16 *)((u8 *)v0 + 2);
    *(u16 *)((u8 *)v2 + 4) = *(u16 *)((u8 *)v0 + 4);
    *(u32 *)((u8 *)v1 + 28) = (*(u32 *)((u8 *)v1 + 28) | 0x100000);
    OSRestoreInterrupts();
}
