#include "types.h"

struct fn_8001BD84_lbl_8015CF68 {
    u8 pad_0[0x120];
    u32 unk_120;
};

extern struct fn_8001BD84_lbl_8015CF68 lbl_8015CF68;
extern u32 OSDisableInterrupts(u32);
extern u32 OSRestoreInterrupts(u32);
extern u32 setFbbRegs(u32, u32, u32, u32, u32);
extern u32 lbl_801A6970;

void VISetNextFrameBuffer(u32 arg0) {
    struct fn_8001BD84_lbl_8015CF68 *p_lbl_8015CF68;
    u32 v0;
    u32 v1;
    u32 t0;
    p_lbl_8015CF68 = (struct fn_8001BD84_lbl_8015CF68 *)&lbl_8015CF68;
    v0 = (arg0 + 0);
    t0 = OSDisableInterrupts(arg0);
    p_lbl_8015CF68->unk_120 = v0;
    v1 = (t0 + 0);
    lbl_801A6970 = 1;
    setFbbRegs((u32)((u8 *)(u32)p_lbl_8015CF68 + 240), (u32)((u8 *)(u32)p_lbl_8015CF68 + 292), (u32)((u8 *)(u32)p_lbl_8015CF68 + 296), (u32)((u8 *)(u32)p_lbl_8015CF68 + 316), (u32)((u8 *)(u32)p_lbl_8015CF68 + 320));
    OSRestoreInterrupts(v1);
}
