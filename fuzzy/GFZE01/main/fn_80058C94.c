/* Non-matching: best partial attempt (55.28% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "dol/globals.h"

typedef struct {
    u32 (*callback)(u32);
    u32 arg;
} Callback;

u32 fn_80058C94(void) {
    u8 *base;
    u32 result;
    s32 i;
    Callback *entry;
    u32 *active;
    base = (u8 *)&lbl_8018FEB0;
    result = 0;
    entry = (Callback *)(base + 0x108);
    active = (u32 *)(base + 0x288);
    for (i = 0; i < 6; i++) {
        if (entry[i + 36].callback != 0) {
            active[6] = 1;
            result |= entry[i + 36].callback(entry[i + 36].arg);
            active[6] = 0;
        }
    }
    ((u32 *)(base + 0x2A8))[6]++;
    return result;
}
