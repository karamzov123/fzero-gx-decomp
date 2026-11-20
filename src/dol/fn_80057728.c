#include "types.h"

struct fn_80057728_lbl_8018AE10 {
    u32 unk_0;
};

extern struct fn_80057728_lbl_8018AE10 lbl_8018AE10[];
extern u32 OSDisableInterrupts(void);
extern u32 lbl_8018AE14[];

u32 fn_80057728(void) {
    u32 v0;
    u32 v1;
    u32 t0;
    if ((s32)lbl_8018AE10[0].unk_0 == 0) {
    t0 = OSDisableInterrupts();
    lbl_8018AE14[0] = t0;
    }
    v0 = (u32)&lbl_8018AE10;
    v1 = *(u32 *)(v0);
    *(u32 *)((u8 *)v0 + 0) = (v1 + 1);
    return v1;
}
