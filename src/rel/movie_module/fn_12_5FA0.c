#include "types.h"

extern int fn_12_670C(const void *);

#define READ_BITS(value, n) \
    if (bits >= 32-(n)) { \
        bits -= 32-(n); \
        if (bits != 0) { \
            current |= next >> ((n)-bits); \
            value = current >> (32-(n)); \
            current = next << bits; \
        } else { \
            value = current >> (32-(n)); \
            current = next; \
        } \
        next = *words++; \
    } else { \
        value = current >> (32-(n)); \
        current <<= (n); \
        bits += (n); \
    }
#define READ_BIT(value) \
    value = current >> 31; \
    if (bits == 31) { \
        current = next; \
        next = *words++; \
        bits = 0; \
    } else { \
        current <<= 1; \
        bits += 1; \
    }
#define SKIP_BITS(n) \
    bits += (n); \
    if (bits >= 32) { \
        bits -= 32; \
        current = next << bits; \
        next = *words++; \
    } else { \
        current <<= (n); \
    }

void fn_12_5FA0(void *output, const void *data, int *count) {
    int bits;
    u32 current;
    u32 next;
    const u32 *words;
    const u8 *end;
    u32 *out;
    u32 address;

    out = (u32 *)output;
    address = (u32)data + 4;
    words = (const u32 *)(address & ~3);
    bits = (address - (u32)words) * 8;
    current = *words++;
    next = *words++;
    current <<= bits;
    READ_BITS(out[0], 16);
    SKIP_BITS(1);
    READ_BITS(out[1], 22);
    SKIP_BITS(1);
    READ_BITS(out[2], 6);
    READ_BIT(out[4]);
    READ_BIT(out[5]);
    READ_BIT(out[6]);
    READ_BIT(out[7]);
    SKIP_BITS(1);
    READ_BITS(out[3], 5);
    SKIP_BITS(8);
    /* marker bit: skip 24-bit extension blocks while set */
    for (;;) {
        if (!(current >> 31))
            break;
        SKIP_BITS(24);
    }
    end = (const u8 *)(words - 2) + ((bits + 7) >> 3);
    *count = end - (const u8 *)data;
    if (fn_12_670C(end) == 0 && fn_12_670C(end + 1) == 0x40000) {
        (*count)++;
    }
}
