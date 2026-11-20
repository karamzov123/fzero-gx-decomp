#include "types.h"


/* --- dol/fn_80021BB0.c --- */
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

/* --- dol/fn_80021C7C.c --- */
u32 fzgx_obj_lbl_80160500[2][160];
u32 lbl_80160500__fzgx_offset_500[160];

/* AI/DSP interrupt callbacks read and update these AXOut state variables asynchronously. */
extern volatile u32 lbl_801A6B10;
/* AI/DSP interrupt callbacks update this AXOut state variable asynchronously. */
extern volatile u32 lbl_801A6B2C;
/* AI/DSP interrupt callbacks update this AXOut state variable asynchronously. */
extern volatile u32 lbl_801A6B14;
extern u32 lbl_801A6B20;

extern void DCFlushRange(void *, u32);
extern void fn_80021AB8(void);
extern s32 fn_8001DF00(u32);
extern u32 fn_8002123C(u32, u32);
extern void AIInitDMA(u32, u32);
extern void AIStartDMA(void);

void fn_80021C7C(void) {
    u32 i;
    u32 *p;

    lbl_801A6B10 = 0;
    lbl_801A6B2C = 0;
    p = (u32 *)fzgx_obj_lbl_80160500;
    for (i = 0; i < 320; i++) {
        *p = 0;
        p++;
    }
    DCFlushRange(fzgx_obj_lbl_80160500, sizeof(fzgx_obj_lbl_80160500));
    p = lbl_80160500__fzgx_offset_500;
    for (i = 0; i < 160; i++) {
        *p = 0;
        p++;
    }
    DCFlushRange(lbl_80160500__fzgx_offset_500, sizeof(lbl_80160500__fzgx_offset_500));
    fn_80021BB0();
    fn_8001DF00((u32)fn_80021AB8);
    fn_8002123C((u32)lbl_80160500__fzgx_offset_500, (u32)&fzgx_obj_lbl_80160500[1][0]);
    lbl_801A6B14 = 1;
    lbl_801A6B20 = 0;
    AIInitDMA((u32)&fzgx_obj_lbl_80160500[lbl_801A6B10][0], sizeof(fzgx_obj_lbl_80160500[0]));
    AIStartDMA();
}
