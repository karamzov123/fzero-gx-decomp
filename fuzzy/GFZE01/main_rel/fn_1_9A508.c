/* Non-matching: best partial attempt (74.07% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/burner.h"

extern void fn_1_9AD20(void);
extern void fn_1_9D0EC(u32, u32, void*, void*);

typedef struct {
    u8 pad_0[0x20];
    void *unk_20;
} SelectionEntry;

typedef struct {
    u8 pad_0[0x720];
    s16 unk_720;
    u8 pad_722[0x3CA];
    SelectionEntry unk_AEC[34];
    u8 pad_FB4[8];
    void *unk_FBC[1];
} SelectionState;

void fn_1_9A508(void) {
    SelectionState *base = (SelectionState *)&lbl_1_data_2A0C0;
    s32 index = base->unk_720;
    fn_1_9AD20();
    fn_1_9D0EC(lbl_1_bss_3BE0->unk_54, lbl_1_bss_3BE0->unk_48,
        base->unk_FBC[index],
        base->unk_AEC[index].unk_20);
}
