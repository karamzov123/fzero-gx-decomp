#include "dol/trk_memory.h"

enum {
    DS_NoError = 0x0,
    DS_StepError = 0x1,
    DS_ParameterError = 0x2,
    DS_EventQueueFull = 0x100,
    DS_NoMessageBufferAvailable = 0x300,
    DS_MessageBufferOverflow = 0x301,
    DS_MessageBufferReadError = 0x302,
    DS_DispatchError = 0x500,
    DS_InvalidMemory = 0x700,
    DS_InvalidRegister = 0x701,
    DS_CWDSException = 0x702,
    DS_UnsupportedError = 0x703,
    DS_InvalidProcessID = 0x704,
    DS_InvalidThreadID = 0x705,
    DS_OSError = 0x706,
    DS_Error800 = 0x800,
};

typedef int DSError;

typedef enum {
    NUBEVENT_Null = 0,
    NUBEVENT_Shutdown = 1,
    NUBEVENT_Request = 2,
    NUBEVENT_Breakpoint = 3,
    NUBEVENT_Exception = 4,
    NUBEVENT_Support = 5,
} NubEventType;

typedef int MessageBufferID;
typedef u32 NubEventID;

typedef struct TRKEvent {
    NubEventType eventType;
    NubEventID eventID;
    MessageBufferID msgBufID;
} TRKEvent;

typedef struct TRKEventQueue {
    int _00;
    int count;
    int next;
    TRKEvent events[2];
    NubEventID eventID;
} TRKEventQueue;

extern TRKEventQueue lbl_801A36B8;

extern u32 fn_800891B4(u32);
DSError fn_8008AF50(void *);
DSError fn_8008AF48(void *);
DSError fn_8008AF40(void *);

static inline void TRKCopyEvent(TRKEvent *dstEvent, const TRKEvent *srcEvent) {
    fn_800035C0(dstEvent, srcEvent, sizeof(TRKEvent));
}

void TRKDestructEvent(TRKEvent *event) {
    fn_800891B4((u32)event->msgBufID);
}

void fn_80088764(TRKEvent *event, NubEventType type) {
    event->eventType = type;
    event->eventID = 0;
    event->msgBufID = -1;
}

DSError TRKPostEvent(TRKEvent *event) {
    DSError ret = DS_NoError;
    int nextEventID;
    fn_8008AF48(&lbl_801A36B8);
    if (lbl_801A36B8.count == 2) {
        ret = DS_EventQueueFull;
    } else {
        nextEventID = (lbl_801A36B8.next + lbl_801A36B8.count) % 2;
        TRKCopyEvent(&lbl_801A36B8.events[nextEventID], event);
        lbl_801A36B8.events[nextEventID].eventID = lbl_801A36B8.eventID;
        lbl_801A36B8.eventID++;
        if (lbl_801A36B8.eventID < 0x100)
            lbl_801A36B8.eventID = 0x100;
        lbl_801A36B8.count++;
    }
    fn_8008AF40(&lbl_801A36B8);
    return ret;
}

BOOL TRKGetNextEvent(TRKEvent *event) {
    BOOL status = 0;
    fn_8008AF48(&lbl_801A36B8);
    if (0 < lbl_801A36B8.count) {
        TRKCopyEvent(event, &lbl_801A36B8.events[lbl_801A36B8.next]);
        lbl_801A36B8.count--;
        lbl_801A36B8.next++;
        if (lbl_801A36B8.next == 2)
            lbl_801A36B8.next = 0;
        status = 1;
    }
    fn_8008AF40(&lbl_801A36B8);
    return status;
}

DSError TRKInitializeEventQueue(void) {
    fn_8008AF50(&lbl_801A36B8);
    fn_8008AF48(&lbl_801A36B8);
    lbl_801A36B8.count = 0;
    lbl_801A36B8.next = 0;
    lbl_801A36B8.eventID = 0x100;
    fn_8008AF40(&lbl_801A36B8);
    return DS_NoError;
}
