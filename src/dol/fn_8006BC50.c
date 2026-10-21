#include "types.h"

typedef struct Fn8006BC50Data {
    u8 _pad[0xf4];
    void *items[64];
} Fn8006BC50Data;

#pragma optimize_for_size on
s32 fn_8006BC50(Fn8006BC50Data *data) {
    u32 i;
    for (i = 0; i < 64; i++) {
        if (data->items[i] != 0) {
            data->items[i] = 0;
        }
    }
    return 0;
}
