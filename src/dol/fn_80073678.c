#include "types.h"

struct fn_80073678_lbl_801A6D38_T {
    u8 pad_0[0x6F0];
    u8 unk_6F0;
};

extern struct fn_80073678_lbl_801A6D38_T *lbl_801A6D38;
extern u32 GXSetNumTevStages(u32);

void fn_80073678(u32 arg0) {
    u32 v0;
    u8 v1;
    u32 v2;
    u32 t0;
    v0 = (arg0 & 0xFF);
    v1 = lbl_801A6D38->unk_6F0;
    v2 = arg0;
    if (v1 != v0) {
    t0 = GXSetNumTevStages(v2);
    v2 = t0;
    v2 = (u32)lbl_801A6D38;
    *(u8 *)((u8 *)v2 + 1776) = arg0;
    }
}
