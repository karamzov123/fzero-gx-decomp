/* Non-matching: best partial attempt (66.87% in the project ledger). Scored for the
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

void fn_12_2E128(s32 value, FnEntry *entry, s32 *result, s32 *out) {
    *result = (entry->field_0c * 1798 + (entry->field_0c / 10) * 2 + entry->field_10 * 30
             + entry->field_08 * 107892 + entry->field_18 + entry->field_14) * 1000;
    *out = value;
}
