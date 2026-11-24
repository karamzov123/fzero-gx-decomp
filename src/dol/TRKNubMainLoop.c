#include "types.h"


/* --- dol/fn_800885B8.c --- */
/* --- dol/fn_800885B8.c --- */
extern f64 fn_80088598(void);

f32 fn_800885B8(f32 arg0);

/* --- dol/fn_800885DC.c --- */
extern f64 fn_800884C0(void);

f32 fn_800885DC(void);

/* --- dol/fn_80088600.c --- */
extern f64 fn_800883E8(f32);

f32 fn_80088600(f32 arg0);

/* --- dol/fn_80088624.c --- */
extern f64 fn_80087E80(f32);

f32 fn_80088624(f32 arg0);

/* --- dol/TRKNubMainLoop.c --- */
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

typedef struct TRKBuffer {
    u32 mutex;
    BOOL isInUse;
    u32 length;
    u32 position;
    u8 data[(0x800 + 0x80)];
} TRKBuffer;

typedef struct TRKBuffer TRKBuffer;

typedef u32 NubEventID;

typedef struct TRKEvent {
    NubEventType eventType;
    NubEventID eventID;
    MessageBufferID msgBufID;
} TRKEvent;

void TRKGetInput(void);

extern void *gTRKInputPendingPtr;

void *TRKGetBuffer(int);

void *TRKGetBuffer(int idx);

BOOL TRKDispatchMessage(TRKBuffer *buffer);

DSError TRKTargetContinue(void);

BOOL TRKGetNextEvent(TRKEvent *event);

void TRKDestructEvent(TRKEvent *);

DSError TRKTargetInterrupt(TRKEvent *);

DSError TRKTargetSupportRequest();

BOOL TRKTargetStopped(void);

static inline void TRKHandleRequestEvent(TRKEvent *event) {
    TRKBuffer *buffer = TRKGetBuffer(event->msgBufID);
    TRKDispatchMessage(buffer);
}

static inline void TRKHandleSupportEvent(TRKEvent *event) { TRKTargetSupportRequest(); }

static inline void TRKIdle() {
    if (TRKTargetStopped() == 0) {
        TRKTargetContinue();
    }
}

void TRKNubMainLoop(void) {
    TRKEvent event;
    BOOL isShutdownRequested;
    BOOL isNewInput;
    isShutdownRequested = 0;
    isNewInput = 0;
    while (isShutdownRequested == 0) {
        if (TRKGetNextEvent(&event) != 0) {
            isNewInput = 0;
            switch (event.eventType) {
            case NUBEVENT_Null:
                break;
            case NUBEVENT_Request:
                TRKHandleRequestEvent(&event);
                break;
            case NUBEVENT_Shutdown:
                isShutdownRequested = 1;
                break;
            case NUBEVENT_Breakpoint:
            case NUBEVENT_Exception:
                TRKTargetInterrupt(&event);
                break;
            case NUBEVENT_Support:
                TRKHandleSupportEvent(&event);
                break;
            }
            TRKDestructEvent(&event);
            continue;
        }
        if ((isNewInput == 0) || (*(u8 *)gTRKInputPendingPtr != '\0')) {
            isNewInput = 1;
            TRKGetInput();
            continue;
        }
        TRKIdle();
        isNewInput = 0;
    }
}
