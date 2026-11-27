#include "types.h"
#pragma opt_loop_invariants off

/* --- rel/movie_module/fn_12_57F0.c --- */
extern void *memcpy(void *dst, const void *src, u32 size);

void *fn_12_57F0(void *dst, const void *src, u32 size) {
    return memcpy(dst, src, size);
}

#define READ_BITS(n, dst) \
    if ((s32)v5 >= 32 - (n)) { \
        v5 -= 32 - (n); \
        if (v5 != 0) { \
            v10 |= v7 >> ((n) - v5); \
            (dst) = v10 >> (32 - (n)); \
            v10 = v7 << v5; \
        } else { \
            (dst) = v10 >> (32 - (n)); \
            v10 = v7; \
        } \
        v7 = *(u32 *)v8; \
        v8 += 4; \
    } else { \
        (dst) = v10 >> (32 - (n)); \
        v10 <<= (n); \
        v5 += (n); \
    }
#define SKIP_BITS(n) \
    v5 += (n); \
    if ((s32)v5 >= 32) { \
        v5 -= 32; \
        v10 = v7 << v5; \
        v7 = *(u32 *)v8; \
        v8 += 4; \
    } else { \
        v10 <<= (n); \
    }
#define PEEK_BITS(n, dst) \
    (dst) = v10 >> (32 - (n)); \
    if ((s32)v5 > 32 - (n)) { \
        (dst) |= v7 >> (64 - (n) - v5); \
    }

