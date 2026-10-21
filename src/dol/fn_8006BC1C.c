#include "types.h"

typedef struct Fn8006BC1CData {
    u8 _pad[0xf0];
    void *value;
    void *items[64];
    u8 _pad1[0x1000];
    u32 flags;
} Fn8006BC1CData;

#pragma optimize_for_size on
s32 fn_8006BC1C(Fn8006BC1CData *data, void *value) {
    u32 i;
    data->flags = 0xff;
    for (i = 0; i < 64; i++) {
        data->items[i] = 0;
    }
    data->value = value;
    return 0;
}
