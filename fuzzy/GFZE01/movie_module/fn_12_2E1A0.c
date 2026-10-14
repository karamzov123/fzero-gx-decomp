/* Non-matching: best partial attempt (98.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct FnEntry {
    u8 padding[8];
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    s32 field_18;
} FnEntry;

#pragma opt_propagation off
#pragma opt_strength_reduction off
void fn_12_2E1A0(s32 value, FnEntry *entry, s32 *result, s32 *out) {
    s32 seconds;
    s32 extra;
    s32 milliseconds;
    s32 minutes;

    minutes = entry->field_0c;
    seconds = entry->field_10;
    extra = entry->field_18;
    milliseconds = entry->field_14;
    {
        s32 correction = (minutes / 10) * 2;
        s32 a = (entry->field_08) * 86292;
        s32 b = minutes * 1438;
        s32 c = seconds * 24;
        s32 total = ((correction) + (b));
        total += c;
        total = a + total;
        total += extra;
        total = milliseconds + total;
        *result = total * 1000;
    }
    *out = value;
}
#pragma opt_strength_reduction reset

