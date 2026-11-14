#include "types.h"

typedef struct MovieDecodeContext {
    u8 *lookup;
    s16 *table;
    u8 *data;
} MovieDecodeContext;

void fn_12_8344(f64 *output, MovieDecodeContext *context, s32 mask) {
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

