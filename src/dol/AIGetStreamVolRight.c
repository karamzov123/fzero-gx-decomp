#include "types.h"
#include <types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"


/* --- dol/AIGetStreamVolRight.c --- */
u32 AIGetStreamVolRight(void) {
    return ((*(u32 *)0xCC006C04 >> 8) & 0xFF);  /* fzgx-allow: A1,A2 unnamed OS/hardware memory */
}

/* --- dol/AIInit.c --- */
/* --- dol/AIInit.c --- */
typedef void (*AISCallback)(u32 count);

typedef void (*AIDCallback)();

void AISetDSPSampleRate(u32 rate);

void AIResetStreamSampleCount();

void AISetStreamTrigger(u32 trigger);

void AISetStreamVolLeft(u8 vol);

void AISetStreamVolRight(u8 vol);

vu32 __AIRegs[8] : FZGX_ADDR___AIRegs;

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

void OSRegisterVersion(const char *id);

__OSInterruptHandler __OSSetInterruptHandler(__OSInterrupt interrupt, __OSInterruptHandler handler);

extern const char *lbl_801A64D0;

extern AISCallback lbl_801A69A0;

extern AIDCallback lbl_801A69A4;

extern u8 *lbl_801A69A8;

// Hardware or OS state can change asynchronously.
extern volatile s32 lbl_801A69B0; // fzgx-allow: S2 SDK asynchronous state

extern OSTime lbl_801A69B8;

extern OSTime lbl_801A69C0;

extern OSTime lbl_801A69C8;

extern OSTime lbl_801A69D0;

extern OSTime lbl_801A69D8;

void __AISHandler(s16 interrupt, OSContext *context);

void __AIDHandler(s16 interrupt, OSContext *context);

static inline void AIResetStreamSampleCount(void) { __AIRegs[0] = (__AIRegs[0] & ~0x20) | 0x20; }

static inline void AISetStreamTrigger(u32 trigger) { __AIRegs[3] = trigger; }

void __AI_set_stream_sample_rate(u32 rate);

static inline void AISetStreamVolLeft(u8 volume) {
    __AIRegs[1] = (__AIRegs[1] & ~0xFF) | (volume & 0xFF);
}

static inline void AISetStreamVolRight(u8 volume) {
    __AIRegs[1] = (__AIRegs[1] & ~0xFF00) | ((volume & 0xFF) << 8);
}

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
    AISetStreamVolRight(0);
    AISetStreamVolLeft(0);
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

/* --- dol/__AISHandler.c --- */
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

/* --- dol/__AIDHandler.c --- */
vu16 __DSPRegs[32] : FZGX_ADDR___DSPRegs;



// Hardware or OS state can change asynchronously.
extern volatile s32 lbl_801A69B4; // fzgx-allow: S2 SDK asynchronous state

void __AICallbackStackSwitch(register AIDCallback cb);

void __AICallbackStackSwitch(register AIDCallback cb);

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
