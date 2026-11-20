#include "types.h"

struct fn_80020ABC_lbl_8015D100 {
    u32 unk_0;    u8 pad_4[0x7C];
};

extern struct fn_80020ABC_lbl_8015D100 lbl_8015D100[];
extern u32 OSDisableInterrupts(u32);
extern u32 OSRestoreInterrupts(u32);
extern u32 fn_80020A28(u32);
extern u32 fn_80022E68(u32);

void fn_80020ABC(u32 arg0) {
    u32 v0;
    u32 v1;
    u32 t0;
    t0 = OSDisableInterrupts(arg0);
    v0 = t0;
    fn_80020A28(arg0);
    if (*(u16 *)(arg0 + 326) == 1) {
    *(u32 *)((u8 *)arg0 + 32) = 1;
    }
    fn_80022E68(arg0);
    v1 = lbl_8015D100[0].unk_0;
    *(u32 *)((u8 *)arg0 + 0) = v1;
    lbl_8015D100[0].unk_0 = arg0;
    *(u32 *)((u8 *)arg0 + 12) = 0;
    OSRestoreInterrupts(v0);
}
