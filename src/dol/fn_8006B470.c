#include "types.h"

typedef struct PadStatus {
    u16 unk_0;
    u8 unk_2;
    s8 unk_3;
    u8 pad_4[5];
    s8 unk_9;
} PadStatus;

typedef struct Fn8006B470Data {
    u8 pad_0[4];
    struct {
        u8 flag7 : 1;
        u8 flag6 : 1;
        u8 rest : 6;
    } flags;
    u8 pad_5[3];
    u32 unk_8;
    u8 pad_C[0x38];
    PadStatus status;
    u8 pad_4E[2];
    u8 data[0x1248 - 0x50];
} Fn8006B470Data;

extern Fn8006B470Data lbl_80199670[4];
extern void fn_8006BC50(void *data);

/* fn_8006B3F0, defined earlier in this TU; MWCC inlines it here. */
static inline s32 Fn8006B470Close(Fn8006B470Data *data) {
    if (data == 0 || (u32)data + 0x10000 == 0xffff) {
        return -2;
    }
    if (data->flags.flag7 == 0) {
        return -2;
    }
    data->flags.flag7 = 0;
    data->flags.flag6 = 0;
    fn_8006BC50(&data->data[0]);
    data->unk_8 = -1;
    return 0;
}

s32 fn_8006B470(PadStatus *out) {
    s32 i;
    Fn8006B470Data *entry;

    if (out == 0) {
        return -2;
    }
    for (i = 0; i < 4; i++) {
        entry = &lbl_80199670[i];
        if (entry->flags.flag6) {
            Fn8006B470Close(entry);
        }
        if (entry->flags.flag7) {
            out[i] = entry->status;
        } else {
            out[i].unk_9 = -1;
        }
    }
    return 0;
}
