/* Non-matching: best partial attempt (93.20% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u32 field_C;
} Sig_fn_12_E0C8_fn_12_E0C8_struct;

extern void fn_12_E0C8(Sig_fn_12_E0C8_fn_12_E0C8_struct *);
extern void fn_12_2013C(Sig_fn_12_E0C8_fn_12_E0C8_struct *);

typedef struct {
    void *ptr;
    u32 value;
} fn_12_8B4C_Entry;

struct fn_12_8B4C_Arg0 {
    u8 pad_0[0xCC];
    Sig_fn_12_E0C8_fn_12_E0C8_struct field_CC;
    u8 pad_DC[0x78];
    s32 field_154;
    fn_12_8B4C_Entry entries[6];
    u8 pad_188[0x1C];
    s32 field_1A4;
    u8 pad_1A8[0xB18];
    u32 field_CC0;
    u8 pad_CC4[4];
};

void fn_12_8B4C(struct fn_12_8B4C_Arg0 *arg0) {
    s32 value;
    s32 i;
    fn_12_8B4C_Entry *entries;
    void *p;

    fn_12_E0C8(&arg0->field_CC);
    fn_12_2013C(&arg0->field_CC);
    entries = arg0->entries;
    p = &arg0->field_CC0;
    value = 4;
    if (arg0->field_1A4 == 0) {
        value = -1;
    }
    arg0->field_154 = value;
    for (i = 0; i < 6; i++) {
        entries[i].ptr = p;
    }
    for (i = 0; i < 6; i++) {
        entries[i].value = 8;
    }
}
