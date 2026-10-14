/* Non-matching: best partial attempt (94.34% in the project ledger). Scored for the
 * fuzzy match only; never linked. Refresh with tools/fuzzy_report.py export. */
#include "types.h"

extern u32 lbl_80187370[4];
extern void *memset(void *dest, int value, u32 size);

typedef struct AdxtWork {
    u8 active;
    u8 index;
    u8 pad[2];
    u32 field4;
    u32 field8;
    u32 table2;
    u32 table1;
} AdxtWork;

typedef struct AdxtGlobal {
    u32 ref_count;
    u32 initialized;
    u32 table1;
    u32 table2;
    AdxtWork *slots[16];
} AdxtGlobal;

#pragma opt_propagation off
static inline AdxtWork **fn_80053A84_slots(AdxtGlobal *g) { return g->slots; }

AdxtWork *fn_80053A84(AdxtWork *arg0, u32 size) {
    AdxtGlobal *g = (AdxtGlobal *)lbl_80187370;
    s32 index;
    AdxtWork *work;

    {
        AdxtWork **p = (AdxtWork **)((u8 *)g + 0x10);
        for (index = 0; index < 16; index++) {
            if (p[index] == 0) {
                break;
            }
        }
    }

    if (index == 16) {
        return 0;
    }

    memset(arg0, 0, size);
    g->slots[index] = arg0;
    work = fn_80053A84_slots(g)[index];
    work->index = index;
    work->field4 = work->field8 = 0x40;
    work->table1 = g->table1;
    work->table2 = g->table2;
    work->active = 1;
    return work;
}
#pragma opt_propagation reset
