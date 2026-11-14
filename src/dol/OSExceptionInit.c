#include <dolphin/os.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#pragma peephole off

typedef void (*__OSExceptionHandler)(__OSException exception, OSContext *context);

void *memcpy(void *dest, const void *src, size_t n);

void DBPrintf(char *format, ...);

extern u32 *BI2DebugFlag;

extern __OSExceptionHandler *OSExceptionTable;

void OSDefaultExceptionHandler(__OSException exception, OSContext *context);

extern BOOL __DBIsExceptionMarked(__OSException);

void __OSEVStart(void);

void __OSEVEnd(void);

void __OSEVSetNumber(void);

void __DBVECTOR(void);

void __OSDBINTSTART(void);

void __OSDBINTEND(void);

void __OSDBINTEND(void);

void __OSDBJUMPEND(void);

__OSExceptionHandler __OSSetExceptionHandler(__OSException exception, __OSExceptionHandler handler);

__OSExceptionHandler __OSSetExceptionHandler(__OSException exception, __OSExceptionHandler handler);

void OSDefaultExceptionHandler(register __OSException exception, register OSContext *context);

static unsigned char fzgx_pool_OSDataPool_801225B0[68] = {
    60, 60, 32, 68,  111, 108, 112, 104, 105, 110, 32, 83, 68,  75,  32,  45,  32,
    79, 83, 9,  114, 101, 108, 101, 97,  115, 101, 32, 98, 117, 105, 108, 100, 58,
    32, 77, 97, 114, 32,  49,  55,  32,  50,  48,  48, 51, 32,  48,  52,  58,  50,
    48, 58, 52, 49,  32,  40,  48,  120, 50,  51,  48, 49, 41,  32,  62,  62,  0};

static unsigned char fzgx_pool_gap____data_0_44[224] = {
    10,  68,  111, 108, 112, 104, 105, 110, 32,  79,  83,  10,  0,   0,   0,   0,   75,  101, 114,
    110, 101, 108, 32,  98,  117, 105, 108, 116, 32,  58,  32,  37,  115, 32,  37,  115, 10,  0,
    0,   0,   77,  97,  114, 32,  49,  55,  32,  50,  48,  48,  51,  0,   48,  52,  58,  50,  48,
    58,  52,  49,  0,   0,   0,   0,   67,  111, 110, 115, 111, 108, 101, 32,  84,  121, 112, 101,
    32,  58,  32,  0,   82,  101, 116, 97,  105, 108, 32,  37,  100, 10,  0,   0,   77,  97,  99,
    32,  69,  109, 117, 108, 97,  116, 111, 114, 10,  0,   0,   0,   80,  67,  32,  69,  109, 117,
    108, 97,  116, 111, 114, 10,  0,   0,   0,   0,   69,  80,  80,  67,  32,  65,  114, 116, 104,
    117, 114, 10,  0,   0,   0,   0,   69,  80,  80,  67,  32,  77,  105, 110, 110, 111, 119, 10,
    0,   0,   0,   0,   68,  101, 118, 101, 108, 111, 112, 109, 101, 110, 116, 32,  72,  87,  37,
    100, 32,  40,  37,  48,  56,  120, 41,  10,  0,   0,   0,   0,   77,  101, 109, 111, 114, 121,
    32,  37,  100, 32,  77,  66,  10,  0,   0,   0,   65,  114, 101, 110, 97,  32,  58,  32,  48,
    120, 37,  120, 32,  45,  32,  48,  120, 37,  120, 10,  0,   0,   0,   0};

static u32 fzgx_pool___OSExceptionLocations[] = {
    0x00000100, 0x00000200, 0x00000300, 0x00000400, 0x00000500, 0x00000600, 0x00000700, 0x00000800,
    0x00000900, 0x00000C00, 0x00000D00, 0x00000F00, 0x00001300, 0x00001400, 0x00001700,
};

void OSExceptionInit(void) {
    __OSException exception;
    void *destAddr;
    u32 *opCodeAddr;
    u32 oldOpCode;
    u8 *handlerStart;
    u32 handlerSize;
    opCodeAddr = (u32 *)__OSEVSetNumber;
    oldOpCode = *opCodeAddr;
    handlerStart = (u8 *)__OSEVStart;
    handlerSize = (u32)((u8 *)__OSEVEnd - (u8 *)__OSEVStart);
    destAddr = (void *)((void *)((u32)(0x60) + (0x8000 << 16)));
    if (*(u32 *)destAddr == 0) {
        DBPrintf("Installing OSDBIntegrator\n");
        memcpy(destAddr, (void *)__OSDBINTSTART, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
        DCFlushRangeNoSync(destAddr, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
        __sync();
        ICInvalidateRange(destAddr, (u32)__OSDBINTEND - (u32)__OSDBINTSTART);
    }
    for (exception = 0; exception < (14 + 1); exception++) {
        if (BI2DebugFlag && (*BI2DebugFlag >= 2) &&
            __DBIsExceptionMarked(exception)) {
            DBPrintf(">>> OSINIT: exception %d commandeered by TRK\n", exception);
            continue;
        }
        *opCodeAddr = oldOpCode | exception;
        if (__DBIsExceptionMarked(exception)) {
            DBPrintf(">>> OSINIT: exception %d vectored to debugger\n", exception);
            memcpy((void *)__DBVECTOR, (void *)__OSDBINTEND,
                   (u32)__OSDBJUMPEND - (u32)__OSDBINTEND);
        } else {
            u32 *ops = (u32 *)__DBVECTOR;
            int cb;
            for (cb = 0; cb < (u32)__OSDBJUMPEND - (u32)__OSDBINTEND; cb += sizeof(u32)) {
                *ops++ = 0x60000000;
            }
        }
        destAddr =
            (void *)((void *)((u32)(fzgx_pool___OSExceptionLocations[(u32)exception]) + (0x8000 << 16)));
        memcpy(destAddr, handlerStart, handlerSize);
        DCFlushRangeNoSync(destAddr, handlerSize);
        __sync();
        ICInvalidateRange(destAddr, handlerSize);
    }
    OSExceptionTable = ((void *)((u32)(0x3000) + (0x8000 << 16)));
    for (exception = 0; exception < (14 + 1); exception++) {
        __OSSetExceptionHandler(exception, OSDefaultExceptionHandler);
    }
    *opCodeAddr = oldOpCode;
    DBPrintf("Exceptions initialized...\n");
}
