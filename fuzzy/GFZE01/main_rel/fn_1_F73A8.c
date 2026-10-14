/* Non-matching: best partial attempt (98.17% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"
#include "rel/main_rel/globals.h"
#include "rel/main_rel/spline.h"

void fn_1_F73A8(s32 idx, s32 type, s32 value) {
    Obj_1_bss_7F02C *e;

    if ((lbl_1_bss_7F028 & 1) == 0) {
        return;
    }
    if (type == 0) {
        return;
    }
    if (idx < 0) {
        return;
    }
    if (idx < 4) {
    if (value > 0xB4) {
        return;
    }
    if ((lbl_1_data_3E8F0 & (1 << idx)) == 0) {
        return;
    }
    if (type == 6 || type == 5) {
        value = 0;
    }
    e = (Obj_1_bss_7F02C *)((u8 *)&lbl_1_bss_7F02C + idx * 4);
    switch (e->unk_0) {
    case 6:
        if (type == 5) {
            e->unk_0 = type;
        }
        break;
    case 1:
        if (type >= 5) goto l1a;
        if (type == 1) goto l1s;
        break;
    l1a:
        if (type >= 7) break;
        e->unk_0 = type;
        break;
    l1s:
        if ((s32)e->unk_2 >= value) break;
        e->unk_0 = type;
        e->unk_2 = value;
        break;
    case 2:
        if (type >= 5) goto l2a;
        if (type == 1) goto l2b;
        if (type >= 1) goto l2c;
        break;
    l2a:
        if (type >= 7) break;
        e->unk_0 = type;
        break;
    l2c:
        if ((s32)e->unk_2 < value) break;
    l2b:
        e->unk_0 = type;
        e->unk_2 = value;
        break;
    case 3:
        if (type >= 5) goto l3a;
        if (type >= 3) goto l3c;
        if (type >= 1) goto l3b;
        break;
    l3a:
        if (type >= 7) break;
        e->unk_0 = type;
        break;
    l3c:
        if ((s32)e->unk_2 < value) break;
    l3b:
        e->unk_0 = type;
        e->unk_2 = value;
        break;
    case 4:
        if (type == 4) goto l4c;
        if (type >= 4) goto l4a;
        if (type >= 1) goto l4b;
        break;
    l4a:
        if (type >= 7) break;
        e->unk_0 = type;
        break;
    l4c:
        if ((s32)e->unk_2 < value) break;
    l4b:
        e->unk_0 = type;
        e->unk_2 = value;
        break;
    case 0:
    case 5:
        e->unk_0 = type;
        e->unk_2 = value;
        break;
    }
    }
}
