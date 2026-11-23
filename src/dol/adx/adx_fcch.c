#include "dolphin/os/OSCache.h"

void fn_8004F7F8(void *address, s32 size) {
    DCInvalidateRange(address, size);
}
