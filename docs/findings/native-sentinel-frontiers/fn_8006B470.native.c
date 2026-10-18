#include "types.h"

/* A packed ten-byte snapshot, matching the public result records. */
typedef struct { u8 bytes[10]; } StreamSnapshot;
typedef struct StreamEntry {
    u8 pad_0[4];
    struct { u8 enabled:1; u8 retiring:1; u8 rest:6; } flags;
    u8 pad_5[3];
    s32 status;
    u8 pad_C[0x38];
    StreamSnapshot snapshot;
    u8 pad_4E[2];
    u8 data[0x1248 - 0x50];
} StreamEntry;
extern StreamEntry lbl_80199670[4];
extern void fn_8006BC50(void *);

#pragma use_lmw_stmw on
#pragma opt_strength_reduction off
#pragma opt_propagation off
s32 fn_8006B470(StreamSnapshot *destination) {
    s32 index;
    StreamEntry *entry;
    s32 entry_offset;
    s32 output_offset;
    s8 *output = (s8 *)destination;

    if (output == 0) return -2;
    index = 0;
    output_offset = 0;
    entry_offset = 0;
    for (; index < 4; index++, entry_offset += 0x1248, output_offset += 10) {
        entry = (StreamEntry *)((u8 *)lbl_80199670 + entry_offset);
        if (entry->flags.retiring) {
            if (entry != 0 && (u32)entry + 0x10000 != 0xffff && entry->flags.enabled) {
                entry->flags.enabled = 0;
                entry->flags.retiring = 0;
                fn_8006BC50(entry->data);
                entry->status = -1;
            }
        }
        if (entry->flags.enabled) {
            *(StreamSnapshot *)(output + output_offset) = entry->snapshot;
        } else {
            output[output_offset + 9] = -1;
        }
    }
    return 0;
}
#pragma opt_propagation reset
#pragma opt_strength_reduction reset
