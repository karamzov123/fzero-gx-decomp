#include "types.h"


/* --- rel/movie_module/fn_12_24A88.c --- */
typedef void (*MovieCallback)(void *, s32);

typedef struct MovieObject {
    u8 pad_0000[0x48];
    s32 state;
    u8 pad_004c[0x940];
    MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} MovieObject;

typedef struct MovieGlobal {
    u8 pad_0000[0x19c];
    MovieCallback callback;
    void *callback_context;
    s32 callback_data;
} MovieGlobal;

extern MovieGlobal lbl_12_bss_7C64;

s32 fn_12_24A88(MovieObject *object, s32 value) {
    if (value == 0) {
        return 0;
    }

    if (object == 0) {
        if (lbl_12_bss_7C64.callback_data == 0) {
            lbl_12_bss_7C64.callback_data = value;
        }
        if (value != 0 && lbl_12_bss_7C64.callback != 0) {
            lbl_12_bss_7C64.callback(lbl_12_bss_7C64.callback_context, value);
        }
    } else {
        if (object->callback_data == 0) {
            object->callback_data = value;
        }
        if (value != 0 && object->callback != 0) {
            object->callback(object->callback_context, value);
        }
        if (object->state > 0) {
            object->state = -object->state;
        }
    }

    return value;
}

/* --- rel/movie_module/fn_12_24B64.c --- */
void fn_12_24B64(int *value) {
    value[0] = 0;
    value[1] = 0;
    value[2] = 0;
    value[3] = 0;
    value[4] = 0;
}
