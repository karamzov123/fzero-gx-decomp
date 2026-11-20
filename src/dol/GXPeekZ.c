#include "types.h"


/* --- dol/GXPeekZ.c --- */
struct GXPeekZ_Arg2 {
    u32 unk_0;
};

u32 GXPeekZ(u32 arg0, u32 arg1, struct GXPeekZ_Arg2 *arg2) {
    u32 v0;
    v0 = (((((((arg0 & 0xFFFF) << 2) | 0xC8000000) & 0xFFC00FFF) | ((arg1 & 0xFFFF) << 12)) & 0xFF3FFFFF) | 0x400000);
    arg2->unk_0 = *(u32 *)((u8 *)v0 + 0);
    return v0;
}

/* --- dol/fn_80034378.c --- */
extern u32 OSDisableInterrupts(u32);
extern u32 OSRestoreInterrupts(u32);
extern u32 lbl_801A6C10;

u32 fn_80034378(u32 arg0) {
    u32 v0;
    u32 t0;
    v0 = lbl_801A6C10;
    t0 = OSDisableInterrupts(arg0);
    lbl_801A6C10 = arg0;
    OSRestoreInterrupts(t0);
    return v0;
}
