#include <types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef void (*AISCallback)(u32 count);
typedef void (*AIDCallback)();

vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;
vu32 __AIRegs[8] : FZGX_ADDR___AIRegs;
u32 __OSBusClock : FZGX_ADDR___OSBusClock;

void OSRegisterVersion(const char *id);
__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);
void __AI_SRC_INIT(void);
void __AICallbackStackSwitch(register AIDCallback cb);

extern const char *lbl_801A64D0;
extern AISCallback lbl_801A69A0;
extern AIDCallback lbl_801A69A4;
extern u8 *lbl_801A69A8;
extern volatile s32 lbl_801A69B0; // fzgx-allow: S2 SDK asynchronous state
extern volatile s32 lbl_801A69B4; // fzgx-allow: S2 SDK asynchronous state
extern OSTime lbl_801A69B8;
extern OSTime lbl_801A69C0;
extern OSTime lbl_801A69C8;
extern OSTime lbl_801A69D0;
extern OSTime lbl_801A69D8;

u32 AIGetDSPSampleRate(void);
u32 AIGetStreamPlayState(void);
u32 AIGetStreamSampleRate(void);
void AISetStreamVolLeft(u8 volume);
void AISetStreamVolRight(u8 volume);
u8 AIGetStreamVolLeft(void);
u8 AIGetStreamVolRight(void);
void __AI_set_stream_sample_rate(u32 rate);
void __AISHandler(s16 interrupt, OSContext *context);
void __AIDHandler(s16 interrupt, OSContext *context);

void AIInitDMA(u32 addr, u32 length) {
    s32 oldInts;
    oldInts = OSDisableInterrupts();
    __DSPRegs[24] = (u16)((__DSPRegs[24] & ~0x3FF) | (addr >> 16));
    __DSPRegs[25] = (u16)((__DSPRegs[25] & ~0xFFE0) | (0xffff & addr));
    __DSPRegs[27] = (u16)((__DSPRegs[27] & ~0x7FFF) | (u16)((length >> 5) & 0xFFFF));
    OSRestoreInterrupts(oldInts);
}

void AIStartDMA(void) {
    __DSPRegs[27] |= 0x8000;
}

void AIStopDMA(void) { __DSPRegs[27] &= ~0x8000; }

void AISetStreamPlayState(u32 state) {
    s32 oldInts;
    u8 volRight;
    u8 volLeft;
    if (state == AIGetStreamPlayState()) {
        return;
    }
    if ((AIGetStreamSampleRate() == 0U) && (state == 1)) {
        volRight = AIGetStreamVolRight();
        volLeft = AIGetStreamVolLeft();
        AISetStreamVolRight(0);
        AISetStreamVolLeft(0);
        oldInts = OSDisableInterrupts();
        __AI_SRC_INIT();
        __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
        __AIRegs[0] = (__AIRegs[0] & ~1) | 1;
        OSRestoreInterrupts(oldInts);
        AISetStreamVolLeft(volRight);
        AISetStreamVolRight(volLeft);
    } else {
        __AIRegs[0] = (__AIRegs[0] & ~1) | state;
    }
}

u32 AIGetStreamPlayState(void) {
    return (*(u32 *)0xCC006C00 & 0x1);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

static inline u32 AIGetStreamPlayState_inline(void) { return __AIRegs[0] & 1; }

void AISetDSPSampleRate(u32 rate) {
    u32 state;
    s32 oldInts;
    u8 left;
    u8 right;
    u32 sampleRate;
    if (rate == AIGetDSPSampleRate()) {
        return;
    }
    __AIRegs[0] &= ~0x40;
    if (rate == 0) {
        left = AIGetStreamVolLeft();
        right = AIGetStreamVolRight();
        state = AIGetStreamPlayState_inline();
        sampleRate = AIGetStreamSampleRate();
        AISetStreamVolLeft(0);
        AISetStreamVolRight(0);
        oldInts = OSDisableInterrupts();
        __AI_SRC_INIT();
        __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
        __AIRegs[0] = (__AIRegs[0] & ~2) | (sampleRate * 2);
        __AIRegs[0] = (__AIRegs[0] & ~1) | state;
        __AIRegs[0] |= 0x40;
        OSRestoreInterrupts(oldInts);
        AISetStreamVolLeft(left);
        AISetStreamVolRight(right);
    }
}

u32 AIGetDSPSampleRate(void) {
    return (((*(u32 *)0xCC006C00 >> 6) & 0x1) ^ 1);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

void __AI_set_stream_sample_rate(u32 rate) {
    s32 oldInts;
    s32 state;
    u8 left;
    u8 right;
    s32 temp_r26;
    if (rate == AIGetStreamSampleRate()) {
        return;
    }
    state = AIGetStreamPlayState_inline();
    left = AIGetStreamVolLeft();
    right = AIGetStreamVolRight();
    AISetStreamVolRight(0);
    AISetStreamVolLeft(0);
    temp_r26 = __AIRegs[0] & 0x40;
    __AIRegs[0] &= ~0x40;
    oldInts = OSDisableInterrupts();
    __AI_SRC_INIT();
    __AIRegs[0] |= temp_r26;
    __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20;
    __AIRegs[0] = (__AIRegs[0] & ~2) | (rate * 2);
    OSRestoreInterrupts(oldInts);
    AISetStreamPlayState(state);
    AISetStreamVolLeft(left);
    AISetStreamVolRight(right);
}

/* --- dol/AIGetStreamSampleRate.c --- */
u32 AIGetStreamSampleRate(void) {
    return ((*(u32 *)0xCC006C00 >> 1) & 0x1);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/AISetStreamVolLeft.c --- */
void AISetStreamVolLeft(u8 volume) { __AIRegs[1] = (__AIRegs[1] & ~0xFF) | (volume & 0xFF); }

/* --- dol/AIGetStreamVolLeft.c --- */
#define AI_STREAM_VOL_LEFT_ADDR 0xCC006C04 // fzgx-allow: A1 hardware register address

u8 AIGetStreamVolLeft(void) {
    return *(volatile u32 *)AI_STREAM_VOL_LEFT_ADDR; // fzgx-allow: A2 hardware register access
}

/* --- dol/AISetStreamVolRight.c --- */
void AISetStreamVolRight(u8 volume) {
    __AIRegs[1] = (__AIRegs[1] & ~0xFF00) | ((volume & 0xFF) << 8);
}

u8 AIGetStreamVolRight(void) {
    return ((*(u32 *)0xCC006C04 >> 8) & 0xFF);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

static inline void AIResetStreamSampleCount(void) { __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20; }
static inline void AISetStreamTrigger(u32 trigger) { __AIRegs[3] = trigger; }
static inline void AISetStreamVolLeft_inline(u8 volume) { __AIRegs[1] = (__AIRegs[1] & ~0xFF) | (volume & 0xFF); }
static inline void AISetStreamVolRight_inline(u8 volume) { __AIRegs[1] = (__AIRegs[1] & ~0xFF00) | ((volume & 0xFF) << 8); }

void AIInit(u8 *stack) {
    if (lbl_801A69B0 == 1) {
        return;
    }
    OSRegisterVersion(lbl_801A64D0);
    lbl_801A69B8 = (((31524) * (((u32)__OSBusClock / 4) / 125000)) / 8000);
    lbl_801A69C0 = (((42024) * (((u32)__OSBusClock / 4) / 125000)) / 8000);
    lbl_801A69C8 = (((42000) * (((u32)__OSBusClock / 4) / 125000)) / 8000);
    lbl_801A69D0 = (((63000) * (((u32)__OSBusClock / 4) / 125000)) / 8000);
    lbl_801A69D8 = (((3000) * (((u32)__OSBusClock / 4) / 125000)) / 8000);
    AISetStreamVolRight_inline(0);
    AISetStreamVolLeft_inline(0);
    AISetStreamTrigger(0);
    AIResetStreamSampleCount();
    __AI_set_stream_sample_rate(1);
    AISetDSPSampleRate(0);
    lbl_801A69A0 = 0;
    lbl_801A69A4 = 0;
    lbl_801A69A8 = stack;
    __OSSetInterruptHandler(5, __AIDHandler);
    __OSUnmaskInterrupts(0x04000000);
    __OSSetInterruptHandler(8, __AISHandler);
    __OSUnmaskInterrupts(0x800000);
    lbl_801A69B0 = 1;
}
void __AISHandler(s16 interrupt, OSContext *context) {
    OSContext tmpContext;
    __AIRegs[0] |= 8;
    OSClearContext(&tmpContext);
    OSSetCurrentContext(&tmpContext);
    if (lbl_801A69A0 != ((void *)0)) {
        lbl_801A69A0(__AIRegs[2]);
    }
    OSClearContext(&tmpContext);
    OSSetCurrentContext(context);
}
void __AIDHandler(s16 interrupt, OSContext *context) {
    OSContext tempContext;
    u32 temp = __DSPRegs[5];
    __DSPRegs[5] = (temp & ~0xA0) | 8;
    OSClearContext(&tempContext);
    OSSetCurrentContext(&tempContext);
    if (lbl_801A69A4 && !lbl_801A69B4) {
        lbl_801A69B4 = 1;
        if (lbl_801A69A8) {
            __AICallbackStackSwitch(lbl_801A69A4);
        } else {
            lbl_801A69A4();
        }
        lbl_801A69B4 = 0;
    }
    OSClearContext(&tempContext);
    OSSetCurrentContext(context);
}
