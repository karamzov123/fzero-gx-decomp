/* Non-matching: best partial attempt (59.33% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

typedef u32 (*Callback58DB4)(u32);
typedef struct {
    Callback58DB4 callback;
    u32 arg;
} CallbackEntry58DB4;
typedef struct {
    u8 pad_0[0xC0];
    CallbackEntry58DB4 entries[6];
} CallbackTable58DB4;
typedef struct {
    u8 pad_0[0x10];
    u32 unk_10;
} State58DB4;

u32 fn_80058DB4(void) {
    u8 *base;
    CallbackTable58DB4 *table;
    State58DB4 *state;
    s32 i;
    u32 result;
    base = (u8 *)&lbl_8018FEB0;
    result = 0;
    table = (CallbackTable58DB4 *)(base + 0x108);
    state = (State58DB4 *)(base + 0x288);
    {
        CallbackEntry58DB4 *entry = table->entries;
        for (i = 0; i < 6; i++, entry++) {
            Callback58DB4 callback = entry->callback;
            if (callback != 0) {
                state->unk_10 = 1;
                result |= callback(entry->arg);
                state->unk_10 = 0;
            }
        }
    }
    {
        State58DB4 *end = (State58DB4 *)(base + 0x2A8);
        end->unk_10++;
    }
    return result;
}
