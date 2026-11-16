#include "types.h"

/* Volatile accesses preserve the retail reload of the cursor and the ordered
 * loads of the values pointer and generation word after the cursor stores. */
typedef struct Fn8006BC84Data {
    u8 _pad[0xf0];
    u32 *volatile values; /* volatile: retail orders this pointer load before the generation load. */
    void *items[64];
} Fn8006BC84Data;

extern volatile u32 lbl_801A6C90; /* volatile: retail reloads the cursor after storing it. */
extern volatile u32 lbl_801A6C94; /* volatile: retail reads generation after the cursor stores. */

#pragma opt_propagation off
u32 fn_8006BC84(Fn8006BC84Data *data) {
    u32 count;
    u32 result;
    u32 i;

    count = lbl_801A6C90;
    result = -1;
    for (i = 0; i < 0x40; i++) {
        u32 index;
        u32 packed;
        u32 *values;

        index = (i + count) & 0x3f;
        if (((index)[data->items]) != 0) {
            continue;
        }
        lbl_801A6C90 = index + 1;
        lbl_801A6C90 &= 0x3f;
        values = data->values;
        packed = (lbl_801A6C94 & 0xff) << 8;
        result = (((index & 0x3f)) | ((((((( *values << 16) & 0xffff0000)) | ((packed & ~0xffff0000)))) & ~0x3f)));
        break;
    }
    return result;
}

#pragma opt_propagation reset

