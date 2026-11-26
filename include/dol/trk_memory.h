#ifndef DOL_TRK_MEMORY_H
#define DOL_TRK_MEMORY_H

#include "types.h"

/* MetroTRK's .init memory wrappers (TRK_memset and TRK_memcpy). */
void *fn_80003590(void *dst, int value, size_t size);
void *fn_800035C0(void *dst, const void *src, size_t size);
void TRK_fill_mem(void *dst, int value, size_t size);

#endif
