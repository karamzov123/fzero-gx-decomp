#include "types.h"

extern void TRK_fill_mem(void *dst, int value, size_t size);

__declspec(section ".init") void *fn_80003590(void *dst, int value, size_t size) {
    TRK_fill_mem(dst, value, size);
    return dst;
}
