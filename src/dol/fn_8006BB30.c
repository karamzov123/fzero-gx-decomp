#include "types.h"


/* --- dol/fn_8006BB30.c --- */
typedef struct Fn8006BB30Data {
    u8 _pad[0xf4];
    void *items[64];
} Fn8006BB30Data;

extern s32 fn_8006BE0C(void *value, u32 arg);

s32 fn_8006BB30(Fn8006BB30Data *data, u32 index, u32 arg) {
    s32 result;

    result = -2;
    if (data->items[index & 0x3f] != 0) {
        result = fn_8006BE0C(data->items[index & 0x3f], arg);
    }
    return result;
}

/* --- dol/fn_8006BB74.c --- */
typedef struct Fn8006BB74Data {
    u8 _pad[0xf4];
    void *items[64];
} Fn8006BB74Data;

s32 fn_8006BB74(Fn8006BB74Data *data, u32 index) {
    s32 result;

    result = -2;
    if (data->items[index & 0x3f] != 0) {
        data->items[index & 0x3f] = 0;
        result = 0;
    }
    return result;
}

/* --- dol/fn_8006BB9C.c --- */
typedef struct Fn8006BB9CData {
    u8 _pad[0xf4];
    void *items[64];
} Fn8006BB9CData;

extern s32 fn_8006C134(void *value);

s32 fn_8006BB9C(Fn8006BB9CData *data, u32 index) {
    u32 result;

    result = -2;
    if (data->items[index & 0x3f] != 0) {
        result = fn_8006C134(data->items[index & 0x3f]);
    }
    return result;
}

/* --- dol/fn_8006BBDC.c --- */
typedef struct Fn8006BBDCData {
    u8 _pad[0xf4];
    void *items[64];
} Fn8006BBDCData;

extern s32 fn_8006C17C(void *value);

s32 fn_8006BBDC(Fn8006BBDCData *data, u32 index) {
    u32 result;

    result = -2;
    if (data->items[index & 0x3f] != 0) {
        result = fn_8006C17C(data->items[index & 0x3f]);
    }
    return result;
}
