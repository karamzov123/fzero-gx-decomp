#include "dolphin/os/OSCache.h"

void ADXF_Ocbi(void *address, s32 size) {
    DCInvalidateRange(address, size);
}
