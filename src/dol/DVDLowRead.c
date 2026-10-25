#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/os.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
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

void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);

DVDDiskID *fn_80019C48();

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

extern BOOL lbl_801A6468;

// Hardware or OS state can change asynchronously.
extern volatile u32 WorkAroundType_801A687C; // fzgx-allow: S2 SDK asynchronous state

// Hardware or OS state can change asynchronously.
extern volatile OSTime lbl_801A6888; // fzgx-allow: S2 SDK asynchronous state

extern vu32 NextCommandNumber_801A689C;

void Read(void *addr, u32 length, u32 offset, DVDLowCallback callback);

void AlarmHandler_dvdlow(OSAlarm *alarm, OSContext *context);

static DVDCommand CommandList[3];

static unsigned char gap____bss_0_3c[4];

static OSAlarm __DVDLowAlarmForWA__fzgx_offset_0;

static unsigned char fzgx_pool_gap____bss_0_68[80];

static DVDBuffer __DVDLowPrev__fzgx_offset_0;

static DVDBuffer __DVDLowCurr__fzgx_offset_0;

#pragma section code_type ".fzgxpool"
static void layout____bss_0(void) {
// Hardware or OS state can change asynchronously.
    volatile unsigned char sink; // fzgx-allow: S2 SDK asynchronous state
    sink = *(unsigned char *)&CommandList;
    sink = *(unsigned char *)&gap____bss_0_3c;
    sink = *(unsigned char *)&__DVDLowAlarmForWA__fzgx_offset_0;
    sink = *(unsigned char *)&fzgx_pool_gap____bss_0_68;
    sink = *(unsigned char *)&__DVDLowPrev__fzgx_offset_0;
    sink = *(unsigned char *)&__DVDLowCurr__fzgx_offset_0;
}
#pragma section code_type ".text"

static inline BOOL HitCache(DVDBuffer *cur, DVDBuffer *prev) {
    u32 uVar1 = (prev->offset + prev->length - 1) >> 15;
    u32 uVar2 = (cur->offset >> 15);
    u32 iVar3 = (fn_80019C48()->streaming ? 1 : 0) ? 5 : 15;
    if ((uVar2 > uVar1 - 2) || (uVar2 < uVar1 + iVar3 + 3)) {
        return 1;
    }
    return 0;
}

static inline void DoJustRead(void *addr, u32 length, u32 offset, DVDLowCallback callback) {
    CommandList[0].cmd = -1;
    NextCommandNumber_801A689C = 0;
    Read(addr, length, offset, callback);
}

void SeekTwiceBeforeRead(void *addr, u32 length, u32 offset, DVDLowCallback callback);

static inline void WaitBeforeRead(void *addr, u32 length, u32 offset, DVDLowCallback callback,
                                  OSTime timeout) {
    CommandList[0].cmd = 1;
    CommandList[0].addr = addr;
    CommandList[0].length = length;
    CommandList[0].offset = offset;
    CommandList[0].callback = callback;
    CommandList[1].cmd = -1;
    NextCommandNumber_801A689C = 0;
    OSCreateAlarm(&__DVDLowAlarmForWA__fzgx_offset_0);
    OSSetAlarm(&__DVDLowAlarmForWA__fzgx_offset_0, timeout, AlarmHandler_dvdlow);
}

BOOL DVDLowRead(void *addr, u32 length, u32 offset, DVDLowCallback callback) {
    OSTime diff;
    u32 prev;
    __DIRegs[6] = length;
    __DVDLowCurr__fzgx_offset_0.addr = addr;
    __DVDLowCurr__fzgx_offset_0.length = length;
    __DVDLowCurr__fzgx_offset_0.offset = offset;
    if (WorkAroundType_801A687C == 0) {
        DoJustRead(addr, length, offset, callback);
    } else if (WorkAroundType_801A687C == 1) {
        if (lbl_801A6468) {
            SeekTwiceBeforeRead(addr, length, offset, callback);
        } else {
            if (!HitCache(&__DVDLowCurr__fzgx_offset_0, &__DVDLowPrev__fzgx_offset_0)) {
                DoJustRead(addr, length, offset, callback);
            } else {
                prev = (__DVDLowPrev__fzgx_offset_0.offset + __DVDLowPrev__fzgx_offset_0.length - 1) >> 15;
                if (prev == __DVDLowCurr__fzgx_offset_0.offset >> 15 || prev + 1 == __DVDLowCurr__fzgx_offset_0.offset >> 15) {
                    diff = __OSGetSystemTime() - lbl_801A6888;
                    if (((5) * (((u32)__OSBusClock / 4) / 1000)) < diff) {
                        DoJustRead(addr, length, offset, callback);
                    } else {
                        WaitBeforeRead(addr, length, offset, callback,
                                       ((5) * (((u32)__OSBusClock / 4) / 1000)) - diff +
                                           (((500) * (((u32)__OSBusClock / 4) / 125000)) / 8));
                    }
                } else {
                    SeekTwiceBeforeRead(addr, length, offset, callback);
                }
            }
        }
    }
    return 1;
}
