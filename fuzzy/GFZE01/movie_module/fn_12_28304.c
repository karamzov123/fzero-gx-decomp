/* Non-matching: best partial attempt (76.72% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    s32 v[6];
} MovieOut;

typedef struct {
    u8 pad_0000[0x10];
    s32 field_10;
    s32 field_14;
    s32 field_18;
    s32 field_1c;
    s32 field_20;
    s32 field_24;
    s32 field_28;
    s32 field_2c;
} MovieEntry;

typedef struct {
    s32 field_08;
    s32 field_0c;
    s32 field_10;
    s32 field_14;
    s32 field_18;
} MovieBase;

typedef struct {
    u8 pad_0000[0xd04];
    s32 flag_d04;
    MovieBase base_d08;
    u8 pad_0d20[0x1be8];
    u32 flag_2908;
} MovieModule;

extern s32 lbl_12_rodata_C10[9];
extern void fn_12_2814C(s32, s32, s32, s32, MovieOut *);

void fn_12_28304(MovieModule *module, MovieEntry *entry, s32 arg2, s32 arg3) {
    MovieOut out;
    MovieBase *base;
    s32 e10;
    s32 e1c;
    s32 e14;
    s32 div;
    s32 total;
    s32 q;
    s32 v;
    s32 w;
    s32 x;
    s32 rem1;
    s32 rem2;
    s32 rem3;

    base = &module->base_d08;
    e10 = entry->field_10;
    e1c = entry->field_1c;
    e14 = entry->field_14;

    if (arg3 != 0 && arg2 >= 0) {
        fn_12_2814C(arg2, e10, e1c, e14, &out);
        entry->field_20 = out.v[2];
        entry->field_24 = out.v[3];
        entry->field_28 = out.v[4];
        entry->field_2c = out.v[5];
    } else if (module->flag_d04 == 0) {
        if (module->flag_2908 == 0) {
            entry->field_1c = 0;
            entry->field_20 = 0;
            entry->field_24 = 0;
            entry->field_28 = 0;
            entry->field_2c = 0;
        }
    } else if (arg3 != 0) {
        div = lbl_12_rodata_C10[e10];
        total = base->field_14 + (base->field_18 + 1);
        q = total / div;
        v = base->field_10 + q;
        w = base->field_0c + v / 60;
        x = base->field_08 + w / 60;
        rem1 = total % div;
        rem2 = v % 60;
        rem3 = w % 60;
        if (e1c != 0 && rem2 == 0 && rem3 % 10 != 0 && (rem1 == 0 || rem1 == 1)) {
            rem1 = 2;
        }
        out.v[2] = x;
        out.v[3] = rem3;
        out.v[4] = rem2;
        out.v[5] = rem1;
        entry->field_20 = out.v[2];
        entry->field_24 = out.v[3];
        entry->field_28 = out.v[4];
        entry->field_2c = out.v[5];
    } else {
        entry->field_20 = base->field_08;
        entry->field_24 = base->field_0c;
        entry->field_28 = base->field_10;
        entry->field_2c = base->field_14;
    }
}
