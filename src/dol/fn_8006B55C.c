#include "types.h"

typedef struct Fn8006B55CFlags {
    u8 flag7:1;
    u8 flag6:1;
    u8 rest:6;
} Fn8006B55CFlags;

typedef struct Fn8006B55CData {
    u8 flags_pad[4];
    Fn8006B55CFlags flags;
    u8 _pad0[3];
    u32 value;
    u8 _pad1[0x44];
    u8 payload[1];
} Fn8006B55CData;

extern void fn_8006BC50(void *value);
extern s32 fn_8006BA74(void *value);

static inline s32 Fn8006B55CClose(void *handle) {
    Fn8006B55CData *data = handle;

    if (data == 0 || (u32)data + 0x10000 == 0xffff) {
        return -2;
    }
    if (data->flags.flag7 == 0) {
        return -2;
    }
    data->flags.flag7 = 0;
    data->flags.flag6 = 0;
    fn_8006BC50(data->payload);
    data->value = -1;
    return 0;
}

s32 fn_8006B55C(Fn8006B55CData *data, u32 arg1, u32 arg2) {
    if (data == 0 || (u32)data + 0x10000 == 0xffff) {
        return -2;
    }
    if (data->flags.flag7 == 0) {
        return -2;
    }
    if (arg1 == 0) {
        return -2;
    }
    if (arg2 == 0) {
        return -2;
    }
    if (data->flags.flag6 != 0) {
        Fn8006B55CClose(data);
        return -2;
    }
    return fn_8006BA74(data->payload);
}
