#include "types.h"

struct fn_80073898_lbl_801A6D38_T {
    u8 pad_0[0x840];
    u8 unk_840;
};

extern struct fn_80073898_lbl_801A6D38_T *lbl_801A6D38;
extern u32 GXSetNumIndStages(u32);

void fn_80073898(u32 arg0) {
    u32 v0;
    u8 v1;
    u32 v2;
    u32 t0;
    v0 = (arg0 & 0xFF);
    v1 = lbl_801A6D38->unk_840;
    v2 = arg0;
    if (v1 != v0) {
    t0 = GXSetNumIndStages(v2);
    v2 = t0;
    v2 = (u32)lbl_801A6D38;
    *(u8 *)((u8 *)v2 + 2112) = arg0;
    }
}
