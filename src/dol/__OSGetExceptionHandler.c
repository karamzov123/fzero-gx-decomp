#include <dolphin/os.h>
#include <dolphin/os/OSContext.h>
#include <dolphin/os/OSError.h>
#pragma peephole off

typedef void (*__OSExceptionHandler)(__OSException exception, OSContext *context);

extern __OSExceptionHandler *OSExceptionTable;

__OSExceptionHandler __OSGetExceptionHandler(__OSException exception) {
    return OSExceptionTable[exception];
}
