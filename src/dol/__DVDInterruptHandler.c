#include <types.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSInterrupt.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

typedef void (*DVDLowCallback)(u32 intType);

typedef struct DVDBuffer {
    void *addr;
    u32 length;
    u32 offset;
} DVDBuffer;

typedef struct DVDCommand {
    s32 cmd;
    void *addr;
    u32 length;
    u32 offset;
    DVDLowCallback callback;
} DVDCommand;

void OSCancelAlarm(OSAlarm *alarm);

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

BOOL DVDLowSeek(u32 offset, DVDLowCallback callback);

extern BOOL lbl_801A6468;

// Hardware or OS state can change asynchronously.
extern volatile BOOL StopAtNextInt; // fzgx-allow: S2 SDK asynchronous state

extern DVDLowCallback Callback;

extern DVDLowCallback lbl_801A6864;

// Hardware or OS state can change asynchronously.
extern volatile OSTime LastResetEnd; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile u32 ResetOccurred; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile BOOL WaitingCoverClose; // fzgx-allow: S2 SDK asynchronous state

extern BOOL lbl_801A6878;

// Hardware or OS state can change asynchronously.
extern volatile OSTime lbl_801A6888; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile BOOL lbl_801A6898; // fzgx-allow: S2 SDK asynchronous state

extern vu32 NextCommandNumber;

void Read(void *addr, u32 length, u32 offset, DVDLowCallback callback);

static DVDCommand CommandList_8015CD70[3];

static unsigned char fzgx_pool_gap____bss_0_3c[44];

static OSAlarm AlarmForTimeout;

static unsigned char fzgx_pool_gap____bss_0_90[40];

static DVDBuffer __DVDLowPrev__fzgx_offset_0;

static DVDBuffer __DVDLowCurr__fzgx_offset_0;

#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
// Hardware or OS state can change asynchronously.
    volatile unsigned char sink; // fzgx-allow: S2 SDK asynchronous state
    sink = *(unsigned char *)&CommandList_8015CD70;
    sink = *(unsigned char *)&fzgx_pool_gap____bss_0_3c;
    sink = *(unsigned char *)&AlarmForTimeout;
    sink = *(unsigned char *)&fzgx_pool_gap____bss_0_90;
    sink = *(unsigned char *)&__DVDLowPrev__fzgx_offset_0;
    sink = *(unsigned char *)&__DVDLowCurr__fzgx_offset_0;
}
#pragma section code_type ".text"

static inline BOOL ProcessNextCommand() {
    s32 n = NextCommandNumber;
    ((void)0);
    if (CommandList_8015CD70[n].cmd == 1) {
        ++NextCommandNumber;
        Read(CommandList_8015CD70[n].addr, CommandList_8015CD70[n].length,
                    CommandList_8015CD70[n].offset, CommandList_8015CD70[n].callback);
        return 1;
    } else if (CommandList_8015CD70[n].cmd == 2) {
        ++NextCommandNumber;
        DVDLowSeek(CommandList_8015CD70[n].offset, CommandList_8015CD70[n].callback);
        return 1;
    }
    return 0;
}

void __DVDInterruptHandler(__OSInterrupt interrupt, OSContext *context) {
    DVDLowCallback cb;
    OSContext exceptionContext;
    u32 cause = 0;
    u32 reg;
    u32 intr;
    u32 mask;
    if (lbl_801A6898) {
        lbl_801A6888 = __OSGetSystemTime();
        lbl_801A6468 = 0;
        __DVDLowPrev__fzgx_offset_0.addr = __DVDLowCurr__fzgx_offset_0.addr;
        __DVDLowPrev__fzgx_offset_0.length = __DVDLowCurr__fzgx_offset_0.length;
        __DVDLowPrev__fzgx_offset_0.offset = __DVDLowCurr__fzgx_offset_0.offset;
        if (StopAtNextInt == 1) {
            cause |= 8;
        }
    }
    lbl_801A6898 = 0;
    StopAtNextInt = 0;
    reg = __DIRegs[0];
    mask = reg & 0x2a;
    intr = (reg & 0x54) & (mask << 1);
    if (intr & 0x40) {
        cause |= 8;
    }
    if (intr & 0x10) {
        cause |= 1;
    }
    if (intr & 4) {
        cause |= 2;
    }
    if (cause) {
        ResetOccurred = 0;
        OSCancelAlarm(&AlarmForTimeout);
    }
    __DIRegs[0] = intr | mask;
    if (ResetOccurred && (__OSGetSystemTime() - LastResetEnd) <
                                      ((200) * (((u32)__OSBusClock / 4) / 1000))) {
        reg = __DIRegs[1];
        mask = reg & 0x2;
        intr = (reg & 4) & (mask << 1);
        if (intr & 4) {
            if (lbl_801A6864) {
                lbl_801A6864(4);
            }
            lbl_801A6864 = 0;
        }
        __DIRegs[1] = __DIRegs[1];
    } else if (WaitingCoverClose) {
        reg = __DIRegs[1];
        mask = reg & 2;
        intr = (reg & 4) & (mask << 1);
        if (intr & 4) {
            cause |= 4;
        }
        __DIRegs[1] = intr | mask;
        WaitingCoverClose = 0;
    } else {
        __DIRegs[1] = 0;
    }
    if ((cause & 8) && !lbl_801A6878) {
        cause &= ~8;
    }
    if ((cause & 1)) {
        if (ProcessNextCommand()) {
            return;
        }
    } else {
        CommandList_8015CD70[0].cmd = -1;
        NextCommandNumber = 0;
    }
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(&exceptionContext);
    if (cause) {
        cb = Callback;
        Callback = 0;
        if (cb) {
            cb(cause);
        }
        lbl_801A6878 = 0;
    }
    OSClearContext(&exceptionContext);
    OSSetCurrentContext(context);
}
