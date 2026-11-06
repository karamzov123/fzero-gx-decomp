#include "types.h"

struct fn_12_7870_Arg2 {
    u32 unk_0;
    s32 unk_4;
};
struct fn_12_7870_Arg3 {
    u8 pad_0[0xC];
    s16 unk_C;
    s16 unk_E;
};

#pragma opt_propagation off
#pragma opt_lifetimes off
static inline u8 fn_12_7870_array_read(s32 index, u8 *array) { return array[index]; }
void fn_12_11204(u32 arg0, u32 arg1, struct fn_12_7870_Arg2 *arg2, struct fn_12_7870_Arg3 *arg3) {
    u8 *entry;
    s16 y;
    s8 a;
    s8 b;
    s32 a8;

    y = arg3->unk_E;
    arg1 <<= 1;
    entry = (u8 *)arg1 + 0x1344;
    entry = (u8 *)arg0 + (u32)entry;
    a = (s8)entry[0];
    b = (s8)entry[1];
    a8 = a << 3;
    arg2->unk_0 = (a8 * arg3->unk_C) + (b << 3);
    arg2->unk_4 = (a << 4) * y + (b << 4);
}
#pragma opt_lifetimes reset
#pragma opt_propagation reset
