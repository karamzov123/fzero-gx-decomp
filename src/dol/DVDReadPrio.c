
#include "types.h"

typedef struct OSContext {
    u32 gpr[32];
    u32 cr;
    u32 lr;
    u32 ctr;
    u32 xer;
    f64 fpr[32];
    f64 fpscr;
    u32 srr0;
    u32 srr1;
    u16 mode;
    u16 state;
    u32 gqr[8];
    u32 psf_pad;
    f64 psf[32];
} OSContext;

typedef struct OSThread OSThread;

typedef struct OSThreadQueue OSThreadQueue;

typedef struct OSThreadLink OSThreadLink;

typedef struct OSMutex OSMutex;

typedef struct OSMutexQueue OSMutexQueue;

typedef struct OSMutexLink OSMutexLink;

typedef s32 OSPriority;

struct OSThreadQueue {
    OSThread *head;
    OSThread *tail;
};

struct OSThreadLink {
    OSThread *next;
    OSThread *prev;
};

struct OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
};

struct OSMutexLink {
    OSMutex *next;
    OSMutex *prev;
};

struct OSThread {
    OSContext context;
    u16 state;
    u16 attr;
    s32 suspend;
    OSPriority priority;
    OSPriority base;
    void *val;
    OSThreadQueue *queue;
    OSThreadLink link;
    OSThreadQueue queueJoin;
    OSMutex *mutex;
    OSMutexQueue queueMutex;
    OSThreadLink linkActive;
    u8 *stackBase;
    u32 *stackEnd;
    s32 error;
};

typedef struct DVDCommandBlock DVDCommandBlock;

typedef struct DVDFileInfo DVDFileInfo;

typedef void (*DVDCallback)(s32 result, DVDFileInfo *fileInfo);

typedef void (*DVDCBCallback)(s32 result, DVDCommandBlock *block);

typedef struct DVDDiskID {
    char gameName[4];
    char company[2];
    u8 diskNumber;
    u8 gameVersion;
    u8 streaming;
    u8 streamBufSize;
    u8 padding[22];
} DVDDiskID;

struct DVDCommandBlock {
    DVDCommandBlock *next;
    DVDCommandBlock *prev;
    u32 command;
    s32 state;
    u32 offset;
    u32 length;
    void *addr;
    u32 currTransferSize;
    u32 transferredSize;
    DVDDiskID *id;
    DVDCBCallback callback;
    void *userData;
};

struct DVDFileInfo {
    DVDCommandBlock cBlock;
    u32 startAddr;
    u32 length;
    DVDCallback callback;
};

struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    int count;
    OSMutexLink link;
};

s32 DVDReadPrio(DVDFileInfo *fileInfo, void *addr, s32 length, s32 offset, s32 prio);

void OSSleepThread(OSThreadQueue *queue);

BOOL DVDReadAbsAsyncPrio(DVDCommandBlock *block, void *addr, s32 length, s32 offset, DVDCBCallback callback,
                 s32 prio);

extern OSThreadQueue __DVDThreadQueue;

void OSPanic(const char *file, int line, const char *message, ...);

BOOL OSDisableInterrupts();

BOOL OSRestoreInterrupts(BOOL enabled);

void fn_800176D8(s32 result, DVDCommandBlock *block);

s32 DVDReadPrio(DVDFileInfo *fileInfo, void *addr, s32 length, s32 offset, s32 prio) {
    BOOL result;
    DVDCommandBlock *block;
    s32 state;
    BOOL enabled;
    s32 retVal;
    if (!((0 <= offset) && (offset < fileInfo->length))) {
        OSPanic("dvdfs.c", 812, "DVDRead(): specified area is out of the file  ");
    }
    if (!((0 <= offset + length) && (offset + length < fileInfo->length + 32))) {
        OSPanic("dvdfs.c", 818, "DVDRead(): specified area is out of the file  ");
    }
    block = &(fileInfo->cBlock);
    result =
        DVDReadAbsAsyncPrio(block, addr, length, (s32)(fileInfo->startAddr + offset), fn_800176D8, prio);
    if (result == (0)) {
        return -1;
    }
    enabled = OSDisableInterrupts();
    while ((1)) {
// Hardware or OS state can change asynchronously.
        state = ((volatile DVDCommandBlock *)block)->state;
        if (state == 0) {
            retVal = (s32)block->transferredSize;
            break;
        }
        if (state == -1) {
            retVal = -1;
            break;
        }
        if (state == 10) {
            retVal = -3;
            break;
        }
        OSSleepThread(&__DVDThreadQueue);
    }
    OSRestoreInterrupts(enabled);
    return retVal;
}
