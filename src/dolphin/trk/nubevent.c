// MetroTRK nub event-queue functions (0x80088648-0x80088910).
// Semantic reference: melee src/MetroTRK (bytes differ).

#pragma push
#pragma force_active on

typedef struct {
    int eventType;
    int eventID;
    int msgBufID;
} TRKEvent;

typedef struct EventQueue {
    int mutex;
    int fCount;
    int fFirst;
    TRKEvent fEventList[2];
    unsigned int fEventID;
} EventQueue;

extern EventQueue lbl_801A36B8;
#define gTRKEventQueue lbl_801A36B8

int TRKGetNextEvent(TRKEvent*);
extern void TRK_memcpy(void*, const void*, unsigned long);
extern void TRKDestructEvent(void*);
extern void* TRKGetBuffer(int);
extern void TRKDispatchMessage(void*);
extern void TRKTargetInterrupt(void*);
extern void TRKTargetSupportRequest(void);
extern void TRKGetInput(void);
extern int TRKTargetStopped(void);
extern void TRKTargetContinue(void);
extern void TRKReleaseBuffer(void*);
extern void TRKReleaseMutex_stub(void*);
extern void TRKAcquireMutex_stub(void*);
extern unsigned char gTRKInputPendingPtr[9];

// provenance: sms:src/TRK_MINNOW_DOLPHIN/debugger/embedded/MetroTRK/Portable/mainloop.c:22
void TRKNubMainLoop(void)
{
    TRKEvent event;
    int isShutdownRequested = 0;
    int isNewInput = 0;
    while (isShutdownRequested == 0) {
        if (TRKGetNextEvent(&event) != 0) {
            isNewInput = 0;
            switch (event.eventType) {
            case 0:
                break;
            case 2:
                TRKDispatchMessage(TRKGetBuffer(event.msgBufID));
                break;
            case 1:
                isShutdownRequested = 1;
                break;
            case 3:
            case 4:
                TRKTargetInterrupt(&event);
                break;
            case 5:
                TRKTargetSupportRequest();
                break;
            }
            TRKDestructEvent(&event);
        } else {
            if (isNewInput == 0 ||
                **(unsigned char**)(void*)gTRKInputPendingPtr != 0) {
                isNewInput = 1;
                TRKGetInput();
            } else {
                if (TRKTargetStopped() == 0) {
                    TRKTargetContinue();
                }
                isNewInput = 0;
            }
        }
    }
}

// provenance: original
void TRKDestructEvent(void* msg) {
    TRKReleaseBuffer(*(void**)((char*)msg + 8));
}

// provenance: original
void TRKConstructEvent(void* ev, int type) {
    *(int*)ev = type;
    *(int*)((char*)ev + 4) = 0;
    *(int*)((char*)ev + 8) = -1;
}

// provenance: melee:src/MetroTRK/nubevent.c
int TRKPostEvent(TRKEvent* ev)
{
    int ret = 0;
    int evID;

    TRKReleaseMutex_stub(&gTRKEventQueue);

    if (gTRKEventQueue.fCount == 2) {
        ret = 0x100;
    } else {
        evID = (gTRKEventQueue.fFirst + gTRKEventQueue.fCount) % 2;
        TRK_memcpy(&gTRKEventQueue.fEventList[evID], ev, sizeof(TRKEvent));
        gTRKEventQueue.fEventList[evID].eventID = gTRKEventQueue.fEventID;
        gTRKEventQueue.fEventID++;

        if (gTRKEventQueue.fEventID < 0x100) {
            gTRKEventQueue.fEventID = 0x100;
        }

        gTRKEventQueue.fCount++;
    }

    TRKAcquireMutex_stub(&gTRKEventQueue);
    return ret;
}

// provenance: melee:src/MetroTRK/nubevent.c
int TRKGetNextEvent(TRKEvent* ev)
{
    int ret = 0;

    TRKReleaseMutex_stub(&gTRKEventQueue);

    if (gTRKEventQueue.fCount > 0) {
        TRK_memcpy(ev, &gTRKEventQueue.fEventList[gTRKEventQueue.fFirst], sizeof(TRKEvent));
        gTRKEventQueue.fCount--;
        gTRKEventQueue.fFirst++;

        if (gTRKEventQueue.fFirst == 2) {
            gTRKEventQueue.fFirst = 0;
        }

        ret = 1;
    }

    TRKAcquireMutex_stub(&gTRKEventQueue);
    return ret;
}

#pragma pop
