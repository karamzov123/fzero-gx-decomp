/* Non-matching: best partial attempt (92.38% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u8 lbl_10_bss_55AE4[32];

typedef struct {
    u8 pad_00[0x54];
    f32 value;
} Fn10_19EC8Object;

extern void fn_80074188(s16, s16, s16, s16);

void fn_10_19EC8(Fn10_19EC8Object *obj, u32 unused) {
    s16 *entry;
    f32 raw;
    s16 index = (s16)raw;
    raw = obj->value;
    entry = (s16 *)lbl_10_bss_55AE4 + index * 4;

    fn_80074188(entry[0], entry[1], entry[2], entry[3]);
}
