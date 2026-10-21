#include "types.h"

typedef struct Fn8006B048Flags {
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 rest : 6;
} Fn8006B048Flags;

typedef struct Fn8006B048Entry {
    s32 index;
    Fn8006B048Flags flags;
    u8 pad_5[3];
    s32 value;
    u16 field_c;
    u8 field_e;
    u8 field_f;
    u8 field_10;
    u8 field_11;
    u8 field_12;
    u8 field_13;
    s8 state;
    u8 pad_15[6];
    s8 field_1b;
    u8 field_1c;
    u8 field_1d;
    u8 field_1e;
    u8 field_1f;
    u8 field_20;
    u8 pad_21[4];
    u8 field_25;
    u8 field_26;
    u8 field_27;
    u8 field_28;
    u8 field_29;
    u8 field_2a;
    u8 pad_2b[4];
    u8 field_2f;
    u8 field_30;
    u8 field_31;
    u8 pad_32;
    u8 field_33;
    u8 field_34;
    u8 pad_35[15];
    u8 data_44[1];
} Fn8006B048Entry;

extern void fn_8006AE90(void *, void *, void *);

#pragma opt_common_subs off
#pragma opt_propagation off
#pragma optimize_for_size on
void fn_8006B048(Fn8006B048Entry *arg, s32 index) {
    s32 value;
    Fn8006B048Entry *entry = arg;
    entry->index = index;
    entry->flags.flag7 = 0;
    entry->flags.flag6 = 0;
    entry->value = -1;
    entry->field_c = 0;
    entry->field_e = 0;
    entry->field_f = 0;
    entry->field_10 = 128;
    entry->field_11 = 128;
    entry->field_12 = 128;
    entry->field_13 = 128;
    entry->state = -1;
    entry->field_1b = -64;
    entry->field_1f = 80;
    entry->field_20 = 80;
    entry->field_25 = 64;
    entry->field_29 = 176;
    entry->field_2a = 176;
    entry->field_2f = 6;
    entry->field_33 = 12;
    entry->field_34 = 12;
    entry->field_1c = 80;
    entry->field_1d = 80;
    value = entry->field_1c - entry->field_1d;
    value /= 2;
    if (value < -128) value = -128;
    else if (value > 127) value = 127;
    entry->field_1e = value;
    entry->field_26 = 176;
    entry->field_27 = 176;
    value = entry->field_26 - entry->field_27;
    value /= 2;
    if (value < -128) value = -128;
    else if (value > 127) value = 127;
    entry->field_28 = value;
    entry->field_30 = 10;
    entry->field_31 = 10;
    fn_8006AE90(entry->data_44, &entry->field_c, (u8 *)entry + 0x18);
}
