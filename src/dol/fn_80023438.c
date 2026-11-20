#include "types.h"

extern u32 OSDisableInterrupts(u32, u32);
extern u32 OSRestoreInterrupts(void);

void fn_80023438(u32 arg0, u32 arg1) {
    s32 v0;
    u32 v2;
    s32 v1;
    v0 = arg1;
    v1 = arg0;
    v2 = (v1 + 478);
    OSDisableInterrupts(arg0, arg1);
    *(u16 *)((u8 *)v2 + 0) = *(u16 *)((u8 *)v0 + 0);
    *(u16 *)((u8 *)v2 + 2) = *(u16 *)((u8 *)v0 + 2);
    *(u16 *)((u8 *)v2 + 4) = *(u16 *)((u8 *)v0 + 4);
    *(u16 *)((u8 *)v2 + 6) = *(u16 *)((u8 *)v0 + 6);
    *(u16 *)((u8 *)v2 + 8) = *(u16 *)((u8 *)v0 + 8);
    *(u16 *)((u8 *)v2 + 10) = *(u16 *)((u8 *)v0 + 10);
    *(u16 *)((u8 *)v2 + 12) = *(u16 *)((u8 *)v0 + 12);
    *(u32 *)((u8 *)v1 + 28) = (*(u32 *)((u8 *)v1 + 28) & 0xFFF7FFFF);
    *(u32 *)((u8 *)v1 + 28) = (*(u32 *)((u8 *)v1 + 28) | 0x40000);
    OSRestoreInterrupts();
}
