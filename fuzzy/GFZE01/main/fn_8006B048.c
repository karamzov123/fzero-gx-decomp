/* Non-matching: best partial attempt (92.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct Fn8006B048Flags {
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 rest : 6;
} Fn8006B048Flags;

typedef struct Fn8006B048Entry {
    s32 index;
    volatile Fn8006B048Flags flags;
    u8 pad_5[3];
    s32 value;
    u16 field_c;
    u8 field_e;
    u8 field_f;
    u8 field_10[4];
    s8 state;
    u8 pad_15[3];
    u8 data_0[3];
    s8 data_3;
    u8 data[0x28];
    u8 output[1];
} Fn8006B048Entry;

extern void fn_8006AE90(void *, void *, void *);

#pragma opt_propagation off
#pragma opt_lifetimes off
static inline u8 * fn_8006B048_read_pointer(Fn8006B048Entry * owner) { return owner->data; }
static inline u8 * fn_8006B048_read_pointer_(Fn8006B048Entry * owner) { return owner->data; }
void fn_8006B048(Fn8006B048Entry *entry, s32 index) {
    entry->index = index;
    entry->flags.flag7 = 0;
    entry->flags.flag6 = 0;
    entry->value = -1;
    entry->field_c = 0;
    entry->field_e = 0;
    entry->field_f = 0;
    entry->field_10[0] = 128;
    entry->field_10[1] = 128;
    entry->field_10[2] = 128;
    entry->field_10[3] = 128;
    entry->state = -1;
    entry->data_3 = -64;
    entry->data[3] = 80;
    entry->data[4] = 80;
    entry->data[9] = 64;
    entry->data[13] = 176;
    entry->data[14] = 176;
    entry->data[19] = 6;
    entry->data[23] = 12;
    fn_8006B048_read_pointer_(entry)[24] = 12;
    entry->data[0] = 80;
    entry->data[1] = 80;
{
    s32 difference;
    difference = ((0)[entry->data] - (1)[entry->data]) / 2;
    if (difference < -128) difference = -128;
    else if (difference > 127) difference = 127;
    entry->data[2] = difference;
    entry->data[10] = 176;
    entry->data[11] = 176;
    difference = ((10)[entry->data] - (11)[fn_8006B048_read_pointer(entry)]) / 2;
    if (difference < -128) difference = -128;
    else if (difference > 127) difference = 127;
    entry->data[12] = difference;
}
    entry->data[20] = 10;
    entry->data[21] = 10;
    fn_8006AE90(entry->output, &entry->field_c, entry->data_0);
}
#pragma opt_lifetimes reset

#pragma opt_propagation reset
