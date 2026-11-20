#include "types.h"


/* --- rel/movie_module/fn_12_80BC.c --- */
typedef struct MovieDecodeContext {
    u8 *lookup;
    s16 *table;
    u8 *data;
    u8 *ref;
} MovieDecodeContext;

void fn_12_80BC(f64 *output, MovieDecodeContext *context, s32 mask) {
    u8 *data;
    u8 *ref;
    s16 *table;
    u8 *lookup;
    s32 count;
    s32 i;
    u8 last;

    table = context->table;
    data = context->data;
    ref = context->ref;
    lookup = context->lookup;
    count = 0;
    do {
        if (mask >= 0) {
            table += 0x40;
            for (i = 0; i < 8; i++) {
                data[0] = (data[0] + ref[0] + 1) >> 1;
                data[1] = (data[1] + ref[1] + 1) >> 1;
                data[2] = (data[2] + ref[2] + 1) >> 1;
                data[3] = (data[3] + ref[3] + 1) >> 1;
                data[4] = (data[4] + ref[4] + 1) >> 1;
                data[5] = (data[5] + ref[5] + 1) >> 1;
                data[6] = (data[6] + ref[6] + 1) >> 1;
                last = ref[7];
                data[7] = (data[7] + last + 1) >> 1;
                ref += 8;
                data += 8;
            }
        } else {
            for (i = 0; i < 8; i++) {
                data[0] = lookup[((data[0] + ref[0] + 1) >> 1) + table[0]];
                data[1] = lookup[((data[1] + ref[1] + 1) >> 1) + table[1]];
                data[2] = lookup[((data[2] + ref[2] + 1) >> 1) + table[2]];
                data[3] = lookup[((data[3] + ref[3] + 1) >> 1) + table[3]];
                data[4] = lookup[((data[4] + ref[4] + 1) >> 1) + table[4]];
                data[5] = lookup[((data[5] + ref[5] + 1) >> 1) + table[5]];
                data[6] = lookup[((data[6] + ref[6] + 1) >> 1) + table[6]];
                last = ref[7];
                data[7] = lookup[((data[7] + last + 1) >> 1) + table[7]];
                ref += 8;
                data += 8;
                table += 8;
            }
        }
        {
            s32 j;
            for (j = 0; j < 8; j++) {
                output[j] = ((f64 *)data)[j - 8];
            }
        }
        output += 8;
        mask <<= 1;
        count++;
    } while (count < 6);
}

/* --- rel/movie_module/fn_12_8344.c --- */
typedef struct MovieDecodeContext_u1 {
    u8 *lookup;
    s16 *table;
    u8 *data;
} MovieDecodeContext_u1;

void fn_12_8344(f64 *output, MovieDecodeContext_u1 *context, s32 mask) {
    u8 *data;
    s16 *table;
    s32 i;
    u8 *lookup;
    s32 count;
    u8 *next;

    table = context->table;
    data = context->data;
    lookup = context->lookup;
    count = 0;
    do {
        if (mask >= 0) {
            table += 0x40;
        } else {
            for (i = 0; i < 8; i++) {
                data[0] = lookup[data[0] + table[0]];
                data[1] = lookup[data[1] + table[1]];
                data[2] = lookup[data[2] + table[2]];
                data[3] = lookup[data[3] + table[3]];
                data[4] = lookup[data[4] + table[4]];
                data[5] = lookup[data[5] + table[5]];
                data[6] = lookup[data[6] + table[6]];
                data[7] = lookup[data[7] + table[7]];
                data += 8;
                table += 8;
            }
            data -= 0x40;
        }
        next = data + 0x40;
        for (i = 0; i < 8; i++) {
            output[i] = ((f64 *)data)[i];
        }
        data = next;
        output += 8;
        mask <<= 1;
        count++;
    } while (count < 6);
}
