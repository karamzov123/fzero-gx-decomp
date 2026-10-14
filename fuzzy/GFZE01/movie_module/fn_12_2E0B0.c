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

void fn_12_2E0B0(s32 value, FnEntry *entry, s32 *result, s32 *out) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;

    a = entry->field_0c;
    b = entry->field_10;
    c = entry->field_08;
    d = entry->field_18;
    e = entry->field_14;
    *result = (e + (c * 215892 + (a * 3598 + (a / 10) * 2 + b * 60) + d)) * 1000;
    *out = value;
}
