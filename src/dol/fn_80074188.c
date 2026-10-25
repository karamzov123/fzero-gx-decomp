#include "types.h"

struct fn_80074188_lbl_801A6D38_T {
    u8 pad_0[0xAE8];
    u32 unk_AE8;
    u32 unk_AEC;
    u32 unk_AF0;
    u32 unk_AF4;
};

extern struct fn_80074188_lbl_801A6D38_T *lbl_801A6D38;
extern u32 GXSetScissor(u32, u32, u32, u32);

u32 fn_80074188(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (lbl_801A6D38->unk_AE8 != arg0 || lbl_801A6D38->unk_AEC != arg1 || lbl_801A6D38->unk_AF0 != arg2 || lbl_801A6D38->unk_AF4 != arg3) {
    v0 = arg0;
    t0 = GXSetScissor(v0, arg1, arg2, arg3);
    v0 = t0;
    v0 = (u32)lbl_801A6D38;
    *(u32 *)((u8 *)v0 + 2792) = arg0;
    v0 = (u32)lbl_801A6D38;
    *(u32 *)((u8 *)v0 + 2796) = arg1;
    v0 = (u32)lbl_801A6D38;
    *(u32 *)((u8 *)v0 + 2800) = arg2;
    v0 = (u32)lbl_801A6D38;
    *(u32 *)((u8 *)v0 + 2804) = arg3;
    }
    return v0;
}
