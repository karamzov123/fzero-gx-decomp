#include <types.h>
#include <dolphin/dvd.h>
#include <dolphin/os/OSAlarm.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSTime.h>
#include <dolphin/types.h>
#include "sdk_addresses.h"

struct dvdBss {
    unsigned char padding_0[64];
    DVDCommandBlock DummyCommandBlock;
    OSAlarm ResetAlarm;
};

void OSSetAlarm(OSAlarm *alarm, OSTime tick, OSAlarmHandler handler);

void OSCreateAlarm(OSAlarm *alarm);

void DVDReset();

u32 __OSBusClock : FZGX_ADDR___OSBusClock;

void __DVDClearWaitingQueue();

vu32 __DIRegs[16] : FZGX_ADDR___DIRegs;

extern DVDCommandBlock *executing;

extern vu32 CurrCommand;

void stateReady();

void AlarmHandler(OSAlarm *alarm, OSContext *context);

extern struct dvdBss BB2;

void cbForStateMotorStopped(u32 intType) {
    struct dvdBss *bss = &BB2;
    DVDCommandBlock *finished;

    __DIRegs[1] = 0;
    executing->state = 3;
    switch (CurrCommand) {
    case 5:
    case 4:
    case 13:
    case 15:
        __DVDClearWaitingQueue();
        finished = executing;
        executing = &(bss->DummyCommandBlock);
        if (finished->callback) {
            (finished->callback)(-4, finished);
        }
        stateReady();
        break;
    default:
        DVDReset();
        OSCreateAlarm(&(bss->ResetAlarm));
        OSSetAlarm(&(bss->ResetAlarm),
                   ((1150) * (((u32)__OSBusClock / 4) / 1000)), AlarmHandler);
        break;
    }
}
