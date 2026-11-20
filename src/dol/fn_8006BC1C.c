#include "types.h"


/* --- dol/fn_8006BC1C.c --- */
typedef struct Fn8006BC1CData {
    u8 _pad[0xf0];
    void *value;
    void *items[64];
    u8 _pad1[0x1000];
    u32 flags;
} Fn8006BC1CData;

s32 fn_8006BC1C(Fn8006BC1CData *data, void *value) {
    u32 i;
    data->flags = 0xff;
    for (i = 0; i < 64; i++) {
        data->items[i] = 0;
    }
    data->value = value;
    return 0;
}

/* --- dol/fn_8006BC50.c --- */
typedef struct Fn8006BC50Data {
    u8 _pad[0xf4];
    void *items[64];
} Fn8006BC50Data;

s32 fn_8006BC50(Fn8006BC50Data *data) {
    u32 i;
    for (i = 0; i < 64; i++) {
        if (data->items[i] != 0) {
            data->items[i] = 0;
        }
    }
    return 0;
}
