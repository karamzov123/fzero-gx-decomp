/* Non-matching: best partial attempt (78.31% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad_0[0xF0];
    void *value;
    void *items[64];
    u8 pad_1F4[0x1000];
    u32 flags;
} StreamSlotState;

#pragma opt_propagation off
#pragma opt_strength_reduction off
s32 fn_8006BC1C(StreamSlotState *state, void *value) {
    struct { u32 fill; u32 offset; } cursor;
    u32 remaining;
    u32 field_offset;

    cursor.fill = 0xFF;
    cursor.offset = 0;
    state->flags = cursor.fill;
    cursor.fill = cursor.offset;
    for (remaining = 64; remaining != 0; remaining--) {
        field_offset = cursor.offset + 0xF4;
        cursor.offset += 4;
        *(u32 *)((u8 *)state + field_offset) = cursor.fill;
    }
    state->value = value;
    return 0;
}
#pragma opt_strength_reduction reset
#pragma opt_propagation reset

