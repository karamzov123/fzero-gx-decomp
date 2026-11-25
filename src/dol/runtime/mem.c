#include "types.h"

/* --- dol/memcmp.c --- */
/* --- dol/memcmp.c --- */
s32 memcmp(u32 arg0, u32 arg1, u32 arg2) {
    u8 *v0;
    u8 *v1;
    u32 v2;

    v0 = (u8 *)arg0 - 1;
    v1 = (u8 *)arg1 - 1;
    v2 = arg2 + 1;
    /* Loop enters at the bottom test in the retail control flow. */
    goto test;
loop:
    if (*++v0 != *++v1) {
        if (*v0 < *v1) {
            return -1;
        }
        return 1;
    }
test:
    if (--v2 != 0) {
        /* Loop back to the body after the retail bottom-test branch. */
        goto loop;
    }
    return 0;
}

/* --- dol/__memrchr.c --- */
s32 __memrchr(u32 arg0, u32 arg1, u32 arg2) {
    u32 v1;

    arg1 = (u8)arg1;
    arg0 += arg2;
    arg2++;
    while (--arg2 != 0) {
        arg0--;
        if (*(u8 *)arg0 == arg1) {
            return arg0;
        }
    }
    return 0;
}

/* --- dol/memchr.c --- */
s32 memchr(u32 arg0, u32 arg1, u32 arg2) {
    u32 unk_1;
    u32 unk_2;
    u32 v2;
    arg1 &= 0xff;
    arg0 -= 1;
    arg2 += 1;
    while (((arg2) -= 1) != 0) {
        arg0 = (u32)((u8 *)arg0 + 1);
        if (*(u8 *)arg0 == arg1) {
            return arg0;
        }
    }
    return 0;
}

/* --- dol/memmove.c --- */
/* --- dol/memmove.c --- */
extern void __copy_longs_unaligned(void *destination, const void *source, size_t count);

extern void __copy_longs_rev_unaligned(void *destination, const void *source, size_t count);

extern void __copy_longs_aligned(void *destination, const void *source, size_t count);

extern void __copy_longs_rev_aligned(void *destination, const void *source, size_t count);

void *memmove(void *destination, const void *source, size_t count) {
    unsigned char *source_byte;
    unsigned char *destination_byte;
    int reverse = (unsigned int)source < (unsigned int)destination;
    if (count >= 32) {
        if (((unsigned int)destination ^ (unsigned int)source) & 3) {
            if (!reverse)
                __copy_longs_unaligned(destination, source, count);
            else
                __copy_longs_rev_unaligned(destination, source, count);
        } else if (!reverse) {
            __copy_longs_aligned(destination, source, count);
        } else {
            __copy_longs_rev_aligned(destination, source, count);
        }
        return destination;
    }
    if (!reverse) {
        source_byte = (unsigned char *)source - 1;
        destination_byte = (unsigned char *)destination - 1;
        ++count;
        while (--count > 0)
            *++destination_byte = *++source_byte;
    } else {
        source_byte = (unsigned char *)source + count;
        destination_byte = (unsigned char *)destination + count;
        ++count;
        while (--count > 0)
            *--destination_byte = *--source_byte;
    }
    return destination;
}
