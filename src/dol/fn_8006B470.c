#include "types.h"

#pragma use_lmw_stmw on

typedef struct Fn8006B470Pair {
    u32 unk_0;
    u32 unk_4;
} Fn8006B470Pair;

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
    Fn8006B470Pair pair;
    u16 unk_4C;
    u8 pad_4E[2];
    u8 data[1];
} Fn8006B470Data;

typedef struct Fn8006B470Out {
    Fn8006B470Pair pair;
    u16 unk_8;
} Fn8006B470Out;

extern u8 lbl_80199670[18720];
extern void fn_8006BC50(void *data);

#pragma opt_propagation off
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

s32 fn_8006B470(s8 *out) {
    struct { u8 *value; } base;
    s32 i;
    Fn8006B470Data *entry;
    s8 *dst;
    s32 outOff;
    s32 dataOff;

    dst = out;
    if (dst == 0) {
        return -2;
    }
    base.value = lbl_80199670;
    for (i = 0, outOff = 0, dataOff = 0; i < 4; i++) {
        entry = (Fn8006B470Data *)(base.value + dataOff);
        if (entry->flags.flag6) {
            Fn8006B470Close(entry);
        }
        if (entry->flags.flag7) {
            ((Fn8006B470Out *)(dst + outOff))->pair = entry->pair;
            ((Fn8006B470Out *)(dst + outOff))->unk_8 = entry->unk_4C;
        } else {
            out = (s8 *)-1;
            dst[outOff + 9] = (s8)(s32)out;
        }
        outOff += 10;
        dataOff += 0x1248;
    }
    return 0;
}
#pragma opt_propagation reset

