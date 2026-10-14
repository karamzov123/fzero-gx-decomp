/* Non-matching: best partial attempt (98.18% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/memcard.h"

typedef struct {
    u8 unk_00[0x3c];
    u32 unk_3C;
    u32 unk_40;
    u8 unk_44[0x5c];
} CardEntry;

#pragma opt_propagation off
void fn_1_B8E84(s32 card, u8 *out_flags, u32 *out_a, u32 *out_b) {
    u8 *base = (u8 *)&lbl_1_bss_716C0;
    CardEntry *entries = (CardEntry *)(base + 8);
    struct { u32 *value; } table;

    table.value = (u32 *)(base + 0x5c7c);
    card = 1 << card;
    *out_flags = (u8)(card & table.value[base[0x5c79]]);
    *out_a = entries[base[0x5c79]].unk_3C;
    *out_b = entries[base[0x5c79]].unk_40;
}
