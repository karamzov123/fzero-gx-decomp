#include "types.h"

struct ReverbStdParam {
    u8 pad_0[0x13C];
    u8 active;
    f32 coloration;
    f32 mix;
    f32 time;
    f32 damping;
    f32 predelay;
};

extern void (*lbl_801A64FC)(u32);
extern u32 OSDisableInterrupts(void);
extern u32 OSRestoreInterrupts(u32);
extern u32 fn_800244C8(u32, f32, f32, f32, f32, f32);
extern u32 fn_800248D4(u32, u32);

#pragma peephole off
void fn_80024C88(u8 *arg0) {
    u8 i;

    for (i = 0; i < 6; i++) {
        lbl_801A64FC(*(u32 *)(arg0 + i * 20 + 12));
    }
    for (i = 0; i < 6; i++) {
        lbl_801A64FC(*(u32 *)(arg0 + i * 20 + 132));
    }
    if (*(s32 *)(arg0 + 288) != 0) {
        for (i = 0; i < 3; i++) {
            lbl_801A64FC(*(u32 *)(arg0 + i * 4 + 292));
        }
    }
}

u32 fn_80024D84(struct ReverbStdParam *arg0) {
    u32 v0;
    u32 t0;

    t0 = OSDisableInterrupts();
    arg0->active = 0;
    v0 = fn_800244C8((u32)arg0, arg0->coloration, arg0->time, arg0->mix, arg0->damping, arg0->predelay);
    OSRestoreInterrupts(t0);
    return v0;
}

u32 fn_80024DF0(u32 arg0) {
    u32 t0;
    t0 = OSDisableInterrupts();
    fn_80024C88((u8 *)arg0);
    OSRestoreInterrupts(t0);
    return 1;
}
#pragma peephole reset

u32 fn_80024E3C(u32 arg0, struct ReverbStdParam *arg1) {
    u32 v0;
    u32 t0;
    v0 = arg0;
    if (arg1->active == 0) {
        v0 = *(u32 *)(v0);
        t0 = fn_800248D4(v0, (u32)arg1);
        v0 = t0;
    }
    return v0;
}
