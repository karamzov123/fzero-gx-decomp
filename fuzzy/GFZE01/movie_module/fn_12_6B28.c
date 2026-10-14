/* Non-matching: best partial attempt (98.75% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

typedef struct MovieEntry {
    s32 state;
    s32 unk04;
    s32 unk08;
    s32 unk0c;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1c;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2c;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3c;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4c;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5c;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6c;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7c;
    s32 unk80;
    s32 unk84;
    s32 unk88;
    s32 unk8c;
    s32 unk90;
    s32 unk94;
    s32 unk98;
    s32 unk9c;
    s32 unka0;
    s32 unka4;
    s32 unka8;
    s32 unkac;
    s32 unkb0;
    s32 unkb4;
    s32 unkb8;
    s32 unkbc;
} MovieEntry;

typedef struct MovieModule {
    u8 unk00[0xc];
    s32 count;
    MovieEntry entries[1];
} MovieModule;

extern u32 lbl_12_bss_4DB8[2];
extern void fn_12_33428(void *dst, s32 value, u32 size);

#pragma opt_common_subs on
static inline u32 fn_12_6B28_array_read(u32 *array, s32 index) { return array[index]; }
#pragma opt_pointer_analysis off
MovieEntry *fn_12_6B28(void) {
    s32 i;
    MovieModule *module;
    MovieEntry *entry;

    module = (MovieModule *)fn_12_6B28_array_read(lbl_12_bss_4DB8, 0);
    entry = module->entries;
    for (i = 0; i < module->count; i++) {
        if (1 != entry->state) {
            goto found; /* Preserves the retail branch. */
        }
        entry++;
    }
    entry = NULL;
found:
    if (NULL == entry) {
        return NULL;
    }
    fn_12_33428(entry, 0, 0x30);
    entry->state = 2;
    entry->unk04 = 0;
    entry->unk08 = 0;
    entry->unk0c = 0;
    entry->unk10 = 2;
    entry->unk14 = -1;
    entry->unk18 = -1;
    entry->unk1c = -1;
    entry->unk20 = -1;
    entry->unk24 = -1;
    entry->unk28 = -1;
    entry->unk2c = -1;
    entry->unk30 = -1;
    entry->unk34 = -1;
    entry->unk38 = -1;
    entry->unk3c = -1;
    entry->unk40 = -1;
    entry->unk44 = -1;
    entry->unk48 = -1;
    entry->unk4c = -1;
    entry->unk50 = -1;
    entry->unk54 = -1;
    entry->unk58 = -1;
    entry->unk5c = -1;
    entry->unk60 = -1;
    entry->unk64 = -1;
    entry->unk68 = -1;
    entry->unk6c = -1;
    entry->unk70 = -1;
    entry->unk74 = -1;
    entry->unk78 = -1;
    entry->unk7c = -1;
    entry->unk80 = -1;
    entry->unk84 = -1;
    entry->unk88 = -1;
    entry->unk8c = -1;
    entry->unk90 = -1;
    entry->unk94 = -1;
    entry->unk98 = -1;
    entry->unk9c = -1;
    entry->unka0 = -1;
    entry->unka4 = -1;
    entry->unka8 = -1;
    entry->unkac = -1;
    entry->unkb0 = -1;
    entry->unkb4 = -1;
    entry->unkb8 = -1;
    entry->unkbc = -1;
    return entry;
}
#pragma opt_pointer_analysis reset

#pragma opt_common_subs reset

