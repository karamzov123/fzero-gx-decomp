/* Non-matching: best partial attempt (90.83% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/option/globals.h"

extern u32 lbl_4_bss_5628[2];

typedef struct Obj_4_data_2F00_local {
    void (*fn[6])(struct Obj_4_data_2F00_local *);
    s32 unk_18;
    s32 unk_1c;
} Obj_4_data_2F00_local;

typedef struct Obj_4_bss_5628_state {
    u32 unk_0;
    u32 unk_4;
    u8 pad_8[0x48];
    u32 unk_50;
} Obj_4_bss_5628_state;

u32 fn_4_ABB0(void) {
    s32 c;
    Obj_4_bss_5628_state *st = (Obj_4_bss_5628_state *)&lbl_4_bss_5628;
    Obj_4_data_2F00_local *d = (Obj_4_data_2F00_local *)&lbl_4_data_2F00;

    c = d->unk_1c;
    st->unk_50 = 0;
    if (c >= 0 && st->unk_0 == 0) {
        d->unk_18 = c;
        d->unk_1c = -1;
        st->unk_0 = st->unk_4;
        st->unk_4 = 0;
    }

    if (d->unk_18 >= 0) {
        if (st->unk_0 != 0) {
            st->unk_0--;
        }
        d->fn[d->unk_18](d);
    }

    return st->unk_50;
}
