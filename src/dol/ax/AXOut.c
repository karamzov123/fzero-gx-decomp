#include "types.h"
#include "dolphin/os/OSTime.h"

typedef struct DSPTaskInfo DSPTaskInfo;
typedef void (*DSPCallback)(DSPTaskInfo *task);

struct DSPTaskInfo {
    /* Hardware or OS state can change asynchronously. */
    volatile unsigned long state;
    /* Hardware or OS state can change asynchronously. */
    volatile unsigned long priority;
    /* Hardware or OS state can change asynchronously. */
    volatile unsigned long flags;
    unsigned short *iramMemoryAddress;
    unsigned long iramLength;
    unsigned long iramAddress;
    unsigned short *dramMemoryAddress;
    unsigned long dramLength;
    unsigned long dramAddress;
    unsigned short initVector;
    unsigned short resumeVector;
    DSPCallback initCallback;
    DSPCallback resumeCallback;
    DSPCallback doneCallback;
    DSPCallback requestCallback;
    struct DSPTaskInfo *next;
    struct DSPTaskInfo *previous;
    OSTime contextTime;
    OSTime taskTime;
};

typedef u32 (*fn_80021930_Fn0)(void);

typedef struct fn_80021930_State {
    u8 pad_0[0x47D0];
    OSTime unk_47D0;
    OSTime unk_47D8;
    OSTime unk_47E0;
    OSTime unk_47E8;
    OSTime unk_47F0;
    OSTime unk_47F8;
    u32 unk_4800;
} fn_80021930_State;

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

extern u32 lbl_8015FF00[];
extern u8 lbl_80126240[7968];
extern u32 lbl_80160500[480];
extern u8 lbl_80160C80[16544];
extern u16 lbl_801A64F0[4];
extern u32 lbl_801A6AF8;
extern u32 lbl_801A6AFC;
extern u32 lbl_801A6B04;
extern u32 lbl_801A6B08;
/* AI/DSP interrupt callbacks read and update this AXOut state variable asynchronously. */
extern volatile u32 lbl_801A6B10;
/* AI/DSP interrupt callbacks read and update this AXOut state variable asynchronously. */
extern volatile u32 lbl_801A6B14;
/* AI/DSP interrupt callbacks read and update this AXOut state variable asynchronously. */
extern volatile OSTime lbl_801A6B18;
extern u32 lbl_801A6B20;
/* The DSP callback updates this flag asynchronously while the wait spins. */
extern volatile s32 lbl_801A6B24;
extern u32 lbl_801A6B28;
/* AI/DSP interrupt callbacks update this AXOut state variable asynchronously. */
extern volatile u32 lbl_801A6B2C;
extern u8 lbl_801A6B30[8];

extern OSTime OSGetTime(void);
extern u32 DSPCheckMailToDSP(void);
extern void DSPSendMailToDSP(u32);
extern void AIInitDMA(u32, u32);
extern void AIStartDMA(void);
extern u32 fn_80022BF4(u32);
extern u32 fn_80022028(void);
extern u8 *fn_80021200(void);
extern void fn_80020800(void);
extern u32 fn_80020FA4(void);
extern u32 fn_8002123C(u32, u32);
extern u32 fn_800224E4(void);
extern u32 fn_800235D4(void);
extern void fn_80028E88(void *);
extern u32 OSWakeupThread(u32);
extern void OSInitThreadQueue(void *);
extern s32 fn_80028DD0(void);
extern void DSPInit(void);
extern void DSPAddTask(void *);
extern void DCFlushRange(void *, u32);
extern s32 fn_8001DF00(u32);

void fn_800218EC(void) {
    lbl_801A6B08 = 0;
    lbl_801A6AF8 = 0;
    lbl_801A6AFC = (u32)&lbl_8015FF00;
    lbl_801A6B04 = 1;
}

// fn_80021910: empty in retail (single blr).
void fn_80021910(void) {
}

void fn_80021914(u32 arg0) {
    if (lbl_801A6B08 == arg0) {
        return;
    }
    lbl_801A6B08 = arg0;
}

u32 fn_80021928(void) {
    return lbl_801A6B08;
}

void fn_80021930(u32 arg0) {
    fn_80021930_State *p;
    u8 *ptr;
    u8 *dst;
    u32 v;
    u32 i;

    p = (fn_80021930_State *)lbl_80160500;
    p->unk_47D0 = OSGetTime();
    fn_80022BF4(arg0);
    fn_80022028();
    ptr = fn_80021200();
    DSPSendMailToDSP(0xBABE0180);
    while (DSPCheckMailToDSP())
        ;
    DSPSendMailToDSP((u32)ptr);
    while (DSPCheckMailToDSP())
        ;
    fn_80020800();
    p->unk_47D8 = OSGetTime();
    fn_80020FA4();
    p->unk_47E0 = OSGetTime();
    p->unk_47E8 = OSGetTime();
    if (lbl_801A6B20 != 0) {
        ((fn_80021930_Fn0)lbl_801A6B20)();
    }
    p->unk_47F0 = OSGetTime();
    fn_8002123C((u32)((u8 *)p + 0x500), (u32)((u8 *)p + lbl_801A6B10 * 640));
    v = lbl_801A6B10;
    lbl_801A6B10 = v + 1;
    lbl_801A6B10 &= 1;
    AIInitDMA((u32)((u8 *)p + lbl_801A6B10 * 640), 640);
    p->unk_47F8 = OSGetTime();
    p->unk_4800 = fn_800224E4();
    dst = (u8 *)fn_800235D4();
    if (dst != 0) {
        u8 *s = (u8 *)p + 0x47D0;
        for (i = 0; i < 56; i++) {
            *dst++ = *s++;
        }
    }
}

void fn_80021AB8(void) {
    if (lbl_801A6B14 == 0) {
        lbl_801A6B18 = OSGetTime();
    }

    if (lbl_801A6B14 == 1) {
        lbl_801A6B14 = 0;
        fn_80021930(0);
    } else {
        lbl_801A6B14 = 2;
        fn_80028E88(&lbl_80160C80);
    }
}

void fn_80021B20(void) {
    lbl_801A6B24 = 1;
}

void fn_80021B2C(DSPTaskInfo *task) {
    if (lbl_801A6B14 == 2) {
        lbl_801A6B14 = 0;
        fn_80021930((u32)(OSGetTime() - lbl_801A6B18) / 4);
        return;
    }
    lbl_801A6B14 = 1;
}

void cbForCancelAllSync(void) {
    lbl_801A6B28 = 1;
    OSWakeupThread((u32)&lbl_801A6B30);
}

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
    OSInitThreadQueue(lbl_801A6B30);
    if (!fn_80028DD0()) {
        DSPInit();
    }
    DSPAddTask(&state->unk780);
    while (!lbl_801A6B24) {
    }
}

u32 fzgx_obj_lbl_80160500[2][160];
u32 lbl_80160500__fzgx_offset_500[160];

/* WARNING: compiler-diff device, not original code: this unit builds with -opt nodeadstore (config/GFZE01/units.json) and this pragma turns dead-store elimination back on for fn_80021C7C only. Without the pragma fn_80021C7C frame 32 -> 16 (10 diff lines); without both the flag and the pragma fn_80021930 frame 24 -> 32 (14 diff lines; ++ on the frame counter instead of the v copy is the same) */
#pragma opt_dead_assignments on
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
#pragma opt_dead_assignments reset
