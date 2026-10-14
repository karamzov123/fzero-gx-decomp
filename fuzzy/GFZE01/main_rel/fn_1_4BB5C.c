/* Non-matching: best partial attempt (92.41% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/font.h"

extern u8 lbl_1_bss_3F60C[];
extern u32 fn_1_48A0C(u32, u32, void *, u32);
extern void fn_1_47F74(s32);

u16 fn_1_4BB5C(void)
{
    Obj_1_bss_4BB30 *state = &lbl_1_bss_4BB30;
    Obj_1_data_1AEA8 * entry_2;
    u8 *base = (u8 *)&lbl_1_data_1AEA8;
    u8 *p = base;
    u32 old = (s8)state->unk_0 * 0x38;
    struct { int value; } i;
    Obj_1_data_1AEA8 *entry;
    s32 selected;
    int index;

    state->unk_1 = 3;
    state->unk_0 = 3;
    state->unk_2 = 0;
    state->unk_3 = 0;
    state->unk_4 = 0;
    state->unk_8 = 0;

    for (i.value = 0; i.value < 44; i.value++) {
        u32 offset = 0;
        u16 *scan;

        entry = (Obj_1_data_1AEA8 *)p;
        ((u32 *)&lbl_1_bss_40BBC)[i.value] = offset;
        if ((s32)entry->unk_0 == -1) {
            scan = (u16 *)entry->unk_2C;
            while (*scan) {
                int id = *(s16 *)((u8 *)entry->unk_30 + offset);
                if (id != -1 && ((s32 *)lbl_1_bss_3F60C)[id] != -1)
                    *(s16 *)((u8 *)entry->unk_30 + offset) = -1;
                offset += 2;
                scan++;
                ((u32 *)&lbl_1_bss_40BBC)[i.value]++;
            }
        }
        p += 0x38;
    }

    if (*(s32 *)(base + old) == -1) {
        selected = (s8)state->unk_0;
        entry_2 = (Obj_1_data_1AEA8 *)((u8 *)&lbl_1_data_1AEA8 + selected * 0x38);
        if ((s32)entry_2->unk_0 == -1) {
            u16 *scan = (u16 *)entry_2->unk_2C;
            u32 offset = 0;
            index = 0;
            while (*scan) {
                if (*(s16 *)((u8 *)entry_2->unk_30 + offset) == -1) {
                    fn_1_48A0C(index, selected, entry_2, 0);
                }
                offset += 2;
                index++;
                scan++;
            }
        }
    } else {
        fn_1_47F74(((*(u32 *)(base + old) >> 8) & 0xFFFF));
    }
    return (u32)entry_2;
}
