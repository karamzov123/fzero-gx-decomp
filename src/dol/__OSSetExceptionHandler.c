#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/types.h>
#pragma peephole off

typedef void (*__OSExceptionHandler)(__OSException exception, OSContext *context);

extern __OSExceptionHandler *OSExceptionTable;

__OSExceptionHandler __OSSetExceptionHandler(__OSException exception,
                                             __OSExceptionHandler handler) {
    __OSExceptionHandler oldHandler;
    oldHandler = OSExceptionTable[exception];
    OSExceptionTable[exception] = handler;
    return oldHandler;
}

__OSExceptionHandler __OSGetExceptionHandler(__OSException exception) {
    return OSExceptionTable[exception];
}
