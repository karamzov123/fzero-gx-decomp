/* Non-matching: best partial attempt (94.92% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u8 pad[0xF4];
    void *items[64];
} StreamSlots;

#pragma opt_propagation off
#pragma opt_strength_reduction off
s32 fn_8006BC50(StreamSlots *slots) {
    u32 remaining;
    u32 offset;
    void *empty;
    u32 field_offset;

    offset = 0;
    empty = 0;
    for (remaining = 64; remaining != 0; remaining--) {
        field_offset = offset + 0xF4;
        if (*(void **)((u8 *)slots + field_offset) != 0) {
            *(void **)((u8 *)slots + field_offset) = empty;
        }
        offset += 4;
    }
    return 0;
}
#pragma opt_strength_reduction reset
#pragma opt_propagation reset
