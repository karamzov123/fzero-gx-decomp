/* Non-matching: best partial attempt (55.69% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

typedef u32 (*Callback)(u32);
typedef struct {
    Callback callback;
    u32 argument;
} CallbackEntry;

u32 fn_80058E44(void) {
    Obj_8018FEB0 *base;
    CallbackEntry *entries;
    Obj_8018FEB0 *state;
    s32 i;
    u32 result;
    base = &lbl_8018FEB0;
    result = 0;
    entries = (CallbackEntry *)((u8 *)base + 0x108);
    state = (Obj_8018FEB0 *)((u8 *)base + 0x288);
    for (i = 0; i < 6; i++) {
        if (entries[i + 12].callback != 0) {
            state->unk_8 = 1;
            result |= entries[i + 12].callback(entries[i + 12].argument);
            state->unk_8 = 0;
        }
    }
    ((Obj_8018FEB0 *)((u8 *)base + 0x2A8))->unk_8++;
    return result;
}
