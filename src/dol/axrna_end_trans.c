#include "types.h"

typedef void (*fn_8005ADBC_Fn)(void *obj, u32 slot, void *ptr);

struct fn_8005ADBC_ObjectVtable {
    u8 pad_0[0x20];
    fn_8005ADBC_Fn fn;
};

struct fn_8005ADBC_Object {
    struct fn_8005ADBC_ObjectVtable *vtable;
};

struct fn_8005ADBC_Entry {
    u8 pad_0[0x3];
    s8 unk_3;
    u8 pad_4[0x2C];
    struct fn_8005ADBC_Object *obj_30[2];
    struct fn_8005ADBC_Object *obj_38[2];
    u8 item_40[2][8];
    u8 item_50[2][8];
    s32 unk_60[2];
    u32 unk_68;
    u32 unk_6C;
    u8 pad_70[0x78];
};

struct fn_8005ADBC_Arg0 {
    u8 pad_0[0x4];
    u32 unk_4;
};

extern struct fn_8005ADBC_Entry axrna_obj[];

#pragma opt_propagation off
void axrna_end_trans(struct fn_8005ADBC_Arg0 *arg0) {
    u32 value;
    u32 index_bits;
    u32 sign;
    struct fn_8005ADBC_Entry *entry;
    s32 slot;
    u32 slot4;
    u8 *pair;
    s32 *state;

    value = arg0->unk_4;
    index_bits = value & 0x7FFFFFFF;
    sign = index_bits >> 31;
    entry = &axrna_obj[(s32)(sign + index_bits) >> 1];
    slot = (((value & 1) ^ sign) - sign);
    slot4 = slot << 2;
    state = (s32 *)(slot4 + (u32)((u8 *)entry + 0x60));
    if (*state == 1) {
        pair = (u8 *)entry + (slot << 3);
        entry->obj_30[slot]->vtable->fn(entry->obj_30[slot], 0, pair + 0x40);
        entry->obj_38[slot]->vtable->fn(entry->obj_38[slot], 1, pair + 0x50);
        *state = 0;
        if (slot == entry->unk_3 - 1) {
            entry->unk_6C = entry->unk_6C + entry->unk_68;
        }
    }
}
#pragma opt_propagation reset
