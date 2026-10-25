#include "types.h"

struct fn_80074660_lbl_801A6D38_T {
    u8 pad_0[0xC28];
    u8 unk_C28;
};

extern struct fn_80074660_lbl_801A6D38_T *lbl_801A6D38;
extern u32 GXSetNumTexGens(u32);

void fn_80074660(u32 arg0) {
    u32 v0;
    u8 v1;
    u32 v2;
    u32 t0;
    v0 = (arg0 & 0xFF);
    v1 = lbl_801A6D38->unk_C28;
    v2 = arg0;
    if (v1 != v0) {
    t0 = GXSetNumTexGens(v2);
    v2 = t0;
    v2 = (u32)lbl_801A6D38;
    *(u8 *)((u8 *)v2 + 3112) = arg0;
    }
}
