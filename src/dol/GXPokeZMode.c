#include "types.h"


/* --- dol/GXPokeZMode.c --- */
// The PE register is memory-mapped hardware and must not be cached.
extern volatile u16 *__peReg;

void GXPokeZMode(u32 arg0, u32 arg1, u32 arg2) {
    u32 value;
    value = arg0 & 0xFF;
    value = (value & ~(7u << 1)) | (arg1 << 1);
    value = (value & ~(1u << 4)) | ((arg2 & 0xFF) << 4);
    *__peReg = (u16)value;
}

/* --- dol/fn_8003432C.c --- */
struct fn_8003432C_Arg2 {
    u32 unk_0;
};

u32 fn_8003432C(u32 arg0, u32 arg1, struct fn_8003432C_Arg2 *arg2) {
    u32 v0;
    v0 = ((((((arg0 & 0xFFFF) << 2) | 0xC8000000) & 0xFFC00FFF) | ((arg1 & 0xFFFF) << 12)) & 0xFF3FFFFF);
    arg2->unk_0 = *(u32 *)((u8 *)v0 + 0);
    return v0;
}

/* --- dol/GXPeekZ.c --- */
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
