#include "types.h"

extern void fn_80021B20(void);
extern u8 lbl_80126240[7968];
extern u32 lbl_80160500[480];
extern void fn_80021B2C(void);
extern u16 lbl_801A64F0[4];
extern void cbForCancelAllSync(void);
extern u8 lbl_801A6B30[8];
/* The DSP callback updates this flag asynchronously while the wait spins. */
extern volatile s32 lbl_801A6B24;
extern u32 lbl_801A6B28;
extern void OSInitThreadQueue(void *);
extern s32 fn_80028DD0(void);
extern void DSPInit(void);
extern void DSPAddTask(void *);

typedef struct {
    u8 unk0[0x780];
    u32 unk780;
    u32 unk784;
    u32 unk788;
    u32 unk78c;
    u32 unk790;
    u32 unk794;
    u32 unk798;
    u32 unk79c;
    u32 unk7a0;
    u16 unk7a4;
    u16 unk7a6;
    u32 unk7a8;
    u32 unk7ac;
    u32 unk7b0;
    u32 unk7b4;
} State;

void fn_80021BB0(void) {
    State *state = (State *)lbl_80160500;

    state->unk78c = (u32)lbl_80126240;
    state->unk790 = lbl_801A64F0[0];
    state->unk794 = 0;
    state->unk798 = (u32)(lbl_80160500 + 0x1f4);
    state->unk79c = 0x2000;
    state->unk7a0 = 0;
    state->unk7a4 = 0x10;
    state->unk7a6 = 0x30;
    state->unk7a8 = (u32)fn_80021B20;
    state->unk7ac = (u32)fn_80021B2C;
    state->unk7b0 = (u32)cbForCancelAllSync;
    state->unk7b4 = 0;
    state->unk784 = 0;

    lbl_801A6B24 = 0;
    lbl_801A6B28 = 0;
    OSInitThreadQueue((void *)lbl_801A6B30);
    if (!fn_80028DD0()) {
        DSPInit();
    }
    DSPAddTask((void *)&state->unk780);
    while (!lbl_801A6B24) {
    }
}
